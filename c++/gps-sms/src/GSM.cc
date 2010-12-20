#include "GSM.h"


int GSM::GetStringSize(const char *msg)
{
	int i = 0;
	int msg_len = 0;

	while (msg[i++] != NULL)
		msg_len++;

	return msg_len;
}

//---------------------------------------------------

int GSM::CheckIfTheMsgIsEqual(const char *msg, const char *other_msg)
{
	int msg_len = GetStringSize(msg);
	int other_msg_len = GetStringSize(other_msg);

	if (msg_len != other_msg_len)
            return 0;

	for (int i = 0; i < other_msg_len; i++)
	{
		if (msg[i] != other_msg[i])
			return 0;
	}

	return 1;
}

//---------------------------------------------------

int GSM::ConfigSMS()
{
	/* Each AT command has the "AT" prefix string
	   Each AT command has the suffix <CR>
	   Message format:
		0 PDU mode (default)
		1 Text mode

	   Example of AT+CMGF:
		AT+CMGF=1
		OK */

	const char *ret;
	char set_text_mode_cmd[] = "AT+CMGF=1\0";
	char set_incoming_msg_cmd[] = "AT+CNMI=,2\0";

        //Setting SMS to Text Mode
	SendCommand(set_text_mode_cmd);
        SendCommand(COMMAND_TERMINATOR);
	ret = GetResponse();
	if (!CheckIfTheMsgIsEqual(ret, OK_RESPONSE_MSG))
            return 0;

	//To have new incoming messages displayed on the terminal we use +CNMI
	SendCommand(set_incoming_msg_cmd);
        SendCommand(COMMAND_TERMINATOR);
	ret = GetResponse();
	if (!CheckIfTheMsgIsEqual(ret, OK_RESPONSE_MSG))
            return 0;

	return 1;
}

//---------------------------------------------------

int GSM::InitSIMCard()
{
	/* The following steps are part of the SIM card status step:
	   1. Check SIM security: AT+CPIN?
	   2. Confirm that the result is +CPIN: READY
	   3. If the SIM PIN is required, then the following response appears: +CPIN: SIM PIN.
	   4. Unlock the SIM, if needed: AT+CPIN="XXXX".
	   Note: XXXX is the PIN password (4-8 digits long).
	   5. If the SIM PUK/PUK2 is required, then the following response appears: +CPIN: SIM PUK/PUK2.
	   6. Unblock the SIM, if needed: AT+CPIN="YYYYYYYY", "ZZZZ".
	      Note: YYYYYYYY is the PUK/PUK2 password (4-8 digits long).
	            ZZZZ is the new defined PIN/PIN2 password (4-8 digits long).

	   To make things simpler our system will only work with SIM cards that do not require PIN or PUK/PUK2. */

	const char *ret;

	SendCommand("AT+CPIN?\0");
	SendCommand(COMMAND_TERMINATOR);
	ret = GetResponse();
	if (!CheckIfTheMsgIsEqual(ret, "\r\n+CPIN: READY\r\n\0"))
		return 0;

	ret = GetResponse();
	if (!CheckIfTheMsgIsEqual(ret, OK_RESPONSE_MSG))
		return 0;

	return 1;
}

//---------------------------------------------------

void GSM::SendCommand(const char *buf)
{
	Atmega128UART.PutLine(buf);
}

//---------------------------------------------------

const char *GSM::GetResponse()
{
	//The results code prefix and suffix is <CR><LF>.
	//The OK result code is <CR><LF>OK<CR><LF>

	short line_feed_count = 0;

	//Getting the data byte by byte
	for (int i = 0; i < GSM_RESPONSE_BUFFER_LEN; i++)
	{
		response_buffer[i] = Atmega128UART.Get();
		if (response_buffer[i] == LF_CHARACTER)
			line_feed_count++;

		if ((line_feed_count == 2) && ((i + 1) < GSM_RESPONSE_BUFFER_LEN))
		{
			response_buffer[i + 1] = NULL;
			return response_buffer;
		}
	}

	return BUFFER_OVERFLOW;
}

//---------------------------------------------------
//---------------------------------------------------

int GSM::Init()
{
	/* To execute the command line, send the <CR> ASCII character (Hexadecimal = 0D).
	   AT is sent to the GSM/GPRS modem to test the connection.

	   Then AT+CPAS is sent to see if the modem is ready to receive comands, 
		0: Ready - The G24 allows commands from the terminal
		2: Unknown - The G24 is not guaranteed to respond to instructions */

	const char *ret;
        cel_number[0] = NULL; //Initialize the cel_number, if the first char of the number is NULL it means there is no number.

	//Disable echo
	SendCommand("ATE0\0");
        SendCommand(COMMAND_TERMINATOR);
	ret = GetResponse();

	//If returned the echo, it skip the first five characters
	if ((ret[0] == 'A') && (ret[1] == 'T') && (ret[2] == 'E') && (ret[3] == '0') && (ret[4] == '\r'))
		ret += 5;

	if (!CheckIfTheMsgIsEqual(ret, OK_RESPONSE_MSG))
		return GSM_ERROR;

	if (!InitSIMCard())
		return GSM_ERROR_INIT_SIM;

	if (!ConfigSMS())
		return GSM_ERROR_CONFIG_SMS;

	return GSM_OK;
}

//---------------------------------------------------

int GSM::ReceiveSMS()
{
	/* Setting the CNMI Notification Indication

	   EXAMPLE:
	   AT+CNMI=,2		//To have new incoming MT messages displayed on the terminal, the
				second parameter of +CNMI should be set to 2
	   OK
	   +CMT: "+97254565132","03/3/24,15:38:55"
	   <message contents>	//When a new MT message is received, the unsolicited response
				  +CMT is displayed along with the message
	   AT+CNMA		//To acknowledge receipt of a message, use the AT+CNMA command
				  within 60 seconds of the +CMT unsolicited response
	   OK

	   The acknowledged message is not saved in the database. If the +CMT unsolicited response is not
	   acknowledged within 60 seconds, the new message is saved in database. */

	const char *response;
	int pos = 2;

	cel_number[0] = NULL; //Erase the last message.

	Debug_uart.PutLine("\r\nWaiting");

	//Now wait for modem response
	response = GetResponse();

	Debug_uart.PutLine("\r\nReceived:");
	Debug_uart.PutLine(response);

	if (CheckIfTheMsgIsEqual(response, BUFFER_OVERFLOW))
		return GSM_BUFFER_OVERFLOW;

	if (GetStringSize(response) < 6)
		return GSM_ERROR_RECEIVING_SMS;

	//Check if it is not error. Then, check if the answer doesn't start with \r\n+CMT
	if (!((response[pos++] == '+') && (response[pos++] == 'C') && (response[pos++] == 'M') && 
	      (response[pos++] == 'T')))
		return GSM_ERROR_RECEIVING_SMS;

	//Now parse the response to get the number of the original/destination address.
	for (int j = 0, separator_count = 0; response[pos] != NULL; pos++)
	{
		if (response[pos] == RESPONSE_SEPARATOR)
			separator_count++;

		if (separator_count > 0)
		{
			//Now we get the original/destination address.
			//+CMT: "+97254565132","03/3/24,15:38:55"
			//             ^
			if (j < GSM_CEL_NUMBER_LEN)
				cel_number[j++] = response[pos];
			else
			{
				//The cel number has caused overflow, useless to stay on the loop.
				//Set to NO_NUMBER so the user can know that the cel_number hasn't been got.
				cel_number[0] = NULL;
				break;
			}

			if (separator_count == 2)
			{
				//NULL termination on the cel_number, if it not caused overflow.
				if (j < GSM_CEL_NUMBER_LEN)
					cel_number[j] = NULL;

				//The number has already been got, don't need to stay on the loop. 
				break;
			}
		}
	}
	Debug_uart.PutLine("\r\nCel Number:");
	Debug_uart.PutLine(cel_number);

	//Ignore the text of the msgs returned by the modem
	while (Atmega128->ucsr1a & (1 << 7))
	{
		Atmega128UART.Get();
		for (int k = 0; k < 0xfff; k++); //Only a delay
	}

	//It acknowledges receipt of message
	SendCommand("AT+CNMA\0");
        SendCommand(COMMAND_TERMINATOR);
	response = GetResponse();
	if (!CheckIfTheMsgIsEqual(response, OK_RESPONSE_MSG))
		return GSM_ERROR_RECEIVING_SMS;

	//Check if it was able to get a cel number.
	if (cel_number[0] == NULL)
		return GSM_ERROR_RECEIVING_SMS;

	Debug_uart.PutLine("\r\nReceived OK!");
	return GSM_OK;
}

//---------------------------------------------------

int GSM::SendSMS(const char *text)
{
	/* The cel_number must be NULL terminated and must be double quoted. Ex: "+554899898578"
	   The text must be NULL terminated.

	   SEND:
	   If text mode (+CMGF=1):
	   AT+CMGS=<da>[,<toda>]<CR>
	   text is entered<ctrl-Z/ESC>

	   RESPONSE:
	   +CMGS: <mr>
	   +CMS ERROR: <err>

	   <mr>  = Sent message reference number.
	   <err> = Error msg.
	   <da>  = Destination address in quoted string. This field contains a single MIN number.
	   <toda> = Type of DA. Value between 128-255 (according to GSM 03.40, 9.1.2.5). If this field is
		    not given and first character of <da> is '+' , <toda> will be 145, otherwise 129.

	   <CTRL+Z> ends the prompt text mode and returns to regular AT command mode. */

	const char *response;
	char control_z[2];

	control_z[0] = 26; //CTRL+Z = 26 in decimal ASCII CODE.
	control_z[1] = 0;  //NULL termination.

	//Before sending the SMS we must be sure that exists a cel_number.
	if (!CanSendSMS())
		return GSM_ERROR_SENDING_SMS;

	//Sending AT+CMGS=cel_number<CR>text<CTRL-Z>
	SendCommand("AT+CMGS=\0");
	SendCommand(cel_number);
	SendCommand(COMMAND_TERMINATOR);
	SendCommand(text);
	SendCommand((const char *) control_z);

	//Now wait for modem response
	response = GetResponse(); //response retorna \r\n> \r\n e ER

	if (CheckIfTheMsgIsEqual(response, "\r\n> \r\n"))
		response = Atmega128UART.GetLine();
	else if ((response[0] == '\r') && (response[1] == '\n'))
		response += 2; //Skip these two characters

	if (CheckIfTheMsgIsEqual(response, BUFFER_OVERFLOW))
		return GSM_BUFFER_OVERFLOW;

	cel_number[0] = NULL; //Since the msg has been sent, reset the cel_number.

	//Now check if the answer starts with +CMG. If starts with +CMG
	//it indicates that the message has been sent, S: <mr> is ignored.
	int response_len = GetStringSize(response);

	if (response_len < 4)
		return GSM_ERROR_SENDING_SMS;

	if ((response[0] == '+') && (response[1] == 'C') && 
	    (response[2] == 'M') && (response[3] == 'G'))
		return GSM_OK;

	return GSM_ERROR_SENDING_SMS;
}

//---------------------------------------------------

int GSM::CanSendSMS()
{
	return cel_number[0] != NULL;
}

//---------------------------------------------------
