#ifndef GPS_H
#define GPS_H

#include "Deploy.h"
#include "ATMega128.h"
#include "ATMega128UART.h"


class GPS
{
private:
	ATMega128 *Atmega128;
	ATMega128UART Atmega128UART;
	
	char Time[TIME_SIZE + 1];
	char Latitude[LATITUDE_SIZE + 1];
	char NS;
	char Longitude[LONGITUDE_SIZE + 1];
	char EW;

public:
	GPS(ATMega128 *atmega128) : Atmega128(atmega128), Atmega128UART(atmega128, 0) {};
	~GPS() {};

	int GetGGA();

	char *GetLatitude() { return Latitude; };
	char GetNS() { return NS; };
	char *GetLongitude() { return Longitude; };
	char GetEW() { return EW; };
	char *GetTime() { return Time; };
};

#endif
