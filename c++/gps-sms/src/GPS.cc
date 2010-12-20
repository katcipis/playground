#include "GPS.h"


int GPS::GetGGA()
{
	Atmega128UART.Flush();

	while (true)
	{
		//This function return a line like this:
		//$GPGGA,060932.448,2447.0959,N,12100.5204,E,1,08,1.1,108.7,M,,,,0000*0E<CR><LF>
		char *line = Atmega128UART.GetLine();

		int i = 0;

		if ((line[i++] == '$') && (line[i++] == 'G') && (line[i++] == 'P') &&
		    (line[i++] == 'G') && (line[i++] == 'G') && (line[i++] == 'A'))
		{
			i++; //Pula a ,

			for (int j = 0; j < TIME_SIZE; j++)
				Time[j] = line[i++];
			Time[TIME_SIZE] = 0;

			i++; //Pula a ,

			for (int j = 0; j < LATITUDE_SIZE; j++)
				Latitude[j] = line[i++];
			Latitude[LATITUDE_SIZE] = 0;

			i++; //Pula a ,

			NS = line[i++];

			i++; //Pula a ,

			for (int j = 0; j < LONGITUDE_SIZE; j++)
				Longitude[j] = line[i++];
			Longitude[LONGITUDE_SIZE] = 0;

			i++; //Pula a ,

			EW = line[i++];

			return GPS_OK;
		}
	}

	return GPS_ERROR;
}

//---------------------------------------------------
