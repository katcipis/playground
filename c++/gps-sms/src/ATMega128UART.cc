#include "ATMega128UART.h"


ATMega128UART::ATMega128UART(ATMega128 *atmega128, unsigned int unit, unsigned int baud, 
				unsigned int data_bits, unsigned int parity, 
				unsigned int stop_bits) : Atmega128(atmega128), Unit(unit)
{
	Config(baud, data_bits, parity, stop_bits);
}

//---------------------------------------------------

ATMega128UART::~ATMega128UART()
{
	ubrrhl(0);
	ucsrb(0);
}

//---------------------------------------------------
//---------------------------------------------------

void ATMega128UART::Config(unsigned int baud, unsigned int data_bits, 
			unsigned int parity, unsigned int stop_bits)
{
	//Set baud rate - 51: 9600 bauds
	ubrrhl(51); //((BASE_CLOCK / (baud >> 5)) - 1);

	//Enable receiver and transmitter
	ucsrb((1 << TXEN) | (1 << RXEN));

	//Set frame format: ex.: 8 data bits, 0 parity, 1 stop bit
	ucsrc(((data_bits - 5) << UCSZ0) | ((stop_bits - 1) << USBS) | ((parity) ? ((parity + 1) << UPM0) : 0));

	ucsra(0);
}

//---------------------------------------------------

char ATMega128UART::Get()
{
	while (!(ucsra() & (1 << RXC))); //Wait for data to be received
	return udr(); //Get and return received data from buffer
}

//---------------------------------------------------

char *ATMega128UART::GetLine()
{
	char line[LINE_SIZE];
	char c;
	int i = 0;

	while (((c = Get()) != '\n') && (i < (LINE_SIZE - 1)))
		line[i++] = c;
	line[i] = 0;

	return line;
}

//---------------------------------------------------

void ATMega128UART::Put(const char c)
{
	while (!(ucsra() & (1 << UDRE))); //Wait for empty transmit buffer
	udr(c); //Put data into buffer, sends the data
}

//---------------------------------------------------

void ATMega128UART::PutLine(const char *c)
{
	int i = 0;

	while (c[i] != 0)
		Put(c[i++]);
}

//---------------------------------------------------

void ATMega128UART::Flush()
{
	unsigned char dummy;
	while (ucsra() & (1 << RXC))
		dummy = udr();
}

//---------------------------------------------------
//---------------------------------------------------

Reg16 ATMega128UART::ubrrhl()
{ 
	Reg16 value = ubrrl();
	value |= ((Reg16) ubrrh()) << 8;
	return value;
}

//---------------------------------------------------

void ATMega128UART::ubrrhl(Reg16 value)
{ 
	ubrrh((Reg8) (value >> 8)); 
	ubrrl((Reg8) value); 
}

//---------------------------------------------------
