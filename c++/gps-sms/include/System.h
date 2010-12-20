#ifndef SYSTEM_H
#define SYSTEM_H

#include "Deploy.h"
#include "ATMega128.h"
#include "GSM.h"
#include "GPS.h"


class System
{
private:	
	static ATMega128 *Atmega128;

	static GSM Gsm;
	static GPS Gps;		

public:
	System() {}
	~System() {}

	static void Init();
	static char *MakeSMS(const char *time, const char *latitude, const char ns, const char *longitude, const char ew);

	static void ConfigRegs();

	static void TurnOnLedYellow() { Atmega128->portb = ~0x01; };
	static void TurnOnLedGreen() { Atmega128->portb = ~0x04; };
	static void TurnOnLedBoth() { Atmega128->portb = ~0x05; };
	static void TurnOnLedNone() { Atmega128->portb = ~0x00; };
};

#endif
