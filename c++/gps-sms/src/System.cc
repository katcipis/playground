#include "System.h"
//#include <stdlib.h>

ATMega128 *System::Atmega128 = reinterpret_cast<ATMega128 *>(0x00);
GSM System::Gsm(System::Atmega128);
GPS System::Gps(System::Atmega128);


void System::Init()
{
	ConfigRegs();

	int ret;
	ret = Gsm.Init();
	if (ret != GSM_OK)
	{
		TurnOnLedBoth();
		return;
	}

	while (true)
	{
		//Waiting sms
		TurnOnLedGreen();

		ret = Gsm.ReceiveSMS();
		if (ret != GSM_OK)
			continue;

		//Working
		TurnOnLedYellow();

		ret = Gps.GetGGA();
		if (ret != GPS_OK)
			continue;

		char *text = MakeSMS(Gps.GetTime(), Gps.GetLatitude(), Gps.GetNS(), Gps.GetLongitude(), Gps.GetEW());

		Gsm.SendSMS(text);
	}
}

//---------------------------------------------------

char *System::MakeSMS(const char *time, const char *latitude, const char ns, const char *longitude, const char ew)
{
	char text[GSM_SMS_BUFFER_LEN];
	int i = 0;

	/*text[i++] = 'S'; text[i++] = 'M'; text[i++] = 'S'; text[i++] = ' ';
	text[i++] = 'T'; text[i++] = 'r'; text[i++] = 'a'; text[i++] = 'c';
	text[i++] = 'k'; text[i++] = 'i'; text[i++] = 'n'; text[i++] = 'g';
	text[i++] = ' '; text[i++] = 'S'; text[i++] = 'y'; text[i++] = 's';
	text[i++] = 't'; text[i++] = 'e'; text[i++] = 'm'; text[i++] = ' ';*/ //Tam = 20

	text[i++] = 'L'; text[i++] = 'a'; text[i++] = 't'; text[i++] = '=';
	for (int j = 0; j < LATITUDE_SIZE; j++)
		text[i++] = latitude[j];
	text[i++] = ','; text[i++] = ' '; //Tam=15

	text[i++] = 'N'; text[i++] = '/'; text[i++] = 'S'; text[i++] = '=';
	text[i++] = ns;
	text[i++] = ','; text[i++] = ' '; //Tam=7

	text[i++] = 'L'; text[i++] = 'o'; text[i++] = 'n'; text[i++] = 'g';
	text[i++] = '=';
	for (int j = 0; j < LONGITUDE_SIZE; j++)
		text[i++] = longitude[j];
	text[i++] = ','; text[i++] = ' '; //Tam=17

	text[i++] = 'E'; text[i++] = '/'; text[i++] = 'W'; text[i++] = '=';
	text[i++] = ew;
	text[i++] = ','; text[i++] = ' '; //Tam=7

	text[i++] = 'T'; text[i++] = 'i'; text[i++] = 'm'; text[i++] = 'e';
	text[i++] = '=';
	for (int j = 0; j < TIME_SIZE; j++)
		text[i++] = time[j];
	text[i] = 0; //Tam=15 + 1 (0) //text[81] = 0 //i=81

	return text;
}

//---------------------------------------------------

void System::ConfigRegs()
{
	//Configures modem interface pins (RST, ANT...)
	Atmega128->ddrc = 0x24;
	Atmega128->portc = 0x24;

	//Configures modem serial interface, disables DTR and RTS
	Atmega128->ddrd = 0x98;
	Atmega128->portd = 0x00;

	//Configure PortB as an output pin (PortB = leds)
	Atmega128->ddrb = 0xff;
	TurnOnLedNone();

	//Waits modem RST, be operational
	while (!(Atmega128->pinc && (1 << 3)));

	//Waits CTS on modem UART
	while (!(Atmega128->pind && (1 << 5)));


	//Only a delay
	for (int i = 0; i < 10; i++)
	{
		for (long int i = 0; i < 0x2ffff; i++);
			TurnOnLedYellow();
		for (long int i = 0; i < 0x2ffff; i++);
			TurnOnLedGreen();
	}

	TurnOnLedNone();
}

//---------------------------------------------------
