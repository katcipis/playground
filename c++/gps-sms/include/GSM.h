#ifndef GSM_H
#define GSM_H

#include "Deploy.h"
#include "ATMega128.h"
#include "ATMega128UART.h"


class GSM
{
private:
	ATMega128 *Atmega128;
	ATMega128UART Atmega128UART;
	ATMega128UART Debug_uart;
	
	char response_buffer[GSM_RESPONSE_BUFFER_LEN];
	char cel_number[GSM_CEL_NUMBER_LEN];

	//Returns the size of a NULL terminated string
	int GetStringSize(const char *msg);

	//Check if two msgs are equal, the char* must be NULL terminated 
	int CheckIfTheMsgIsEqual(const char *msg, const char *other_msg);

	//Configure the modem to send SMS in text mode and verify if the modem is ready to send SMS, 1 if suceeds, 0 otherwise.
	int ConfigSMS();

	//Initializes the SIM card, if the SIM card is ready return 1, 0 otherwise.
	int InitSIMCard();

	//Sends a command to the modem, does not checks for the response. buf must be NULL terminated.
	void SendCommand(const char *buf);

	//Gets an answer from the modem, the string will be null terminated.
	//If the answer is bigger than the response_buffer BUFFER_OVERFLOW is returned.
	//Caution, every time this method is called the contents of the response_buffer are changed.
	const char *GetResponse();

public:
	GSM(ATMega128 *atmega128) : Atmega128(atmega128), Atmega128UART(atmega128, 1), Debug_uart(atmega128, 0) {};
	~GSM() {};

	//Initializes the gsm modem to send and receive sms
	//Returns GSM_OK if it initializes well, or an error code.
	int Init();

	//Returns GSM_OK if it received some sms, or an error code.
	//GSM_ERROR for some internal error.
	//GSM_NO_MSG if there was no msg to be received.
	int ReceiveSMS();

	//Send SMS to the last number that have requested the position of the device.
	//@param text: The text to be sent, the text must be NULL ended, where NULL = "\0"
	//Returns GSM_OK if it was able to send the sms, or an error code. 
	//GSM_ERROR for some internal error.
	int SendSMS(const char *text);

        //Returns 1 if there is a cel_number buffered to send SMS, 0 otherwise.
	int CanSendSMS();
};

#endif
