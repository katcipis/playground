#ifndef ATMEGA128UART_H
#define ATMEGA128UART_H

#include "Deploy.h"
#include "ATMega128.h"

typedef unsigned char Reg8;
typedef unsigned short Reg16;


class ATMega128UART
{
private:
	ATMega128 *Atmega128;

	int Unit;
	//static const unsigned long long CLOCK = 7372800;
	//static const unsigned int BASE_CLOCK = CLOCK / 512;

	//UART IO Register Bit Offsets
	enum
	{
		//UCSRA
		RXC	= 7,
		TXC 	= 6,
		UDRE	= 5,
		FE	= 4,
		DOR	= 3,
		UPE	= 2,
		U2X	= 1,
		MPCM	= 0,
		//UCSRB
		RXCIE	= 7,
		TXCIE	= 6,
		UDRIE	= 5,
		RXEN	= 4,
		TXEN	= 3,
		UCS2Z	= 2,
		RXB8	= 1,
		TXB8	= 0,
		//UCSRC
		URSEL	= 7,
		UMSEL	= 6,
		UPM1	= 5,
		UPM0	= 4,
		USBS	= 3,
		UCSZ1	= 2,
		UCSZ0	= 1,
		UCPOL	= 0,
	};

public:
	ATMega128UART(ATMega128 *atmega128, unsigned int unit = 0, unsigned int baud = 9600, unsigned int data_bits = 8,
			unsigned int parity = 0, unsigned int stop_bits = 1);
	~ATMega128UART();


	void Config(unsigned int baud, unsigned int data_bits, unsigned int parity, unsigned int stop_bits);
	char Get();
	char *GetLine();
	void Put(const char c);
	void PutLine(const char *c);
	void Flush();

private:
	Reg8 udr() { return (Unit == 0) ? Atmega128->udr0 : Atmega128->udr1; }
	void udr(Reg8 value) { ((Unit == 0) ? Atmega128->udr0 : Atmega128->udr1) = value; }
	Reg8 ucsra() { return (Unit == 0) ? Atmega128->ucsr0a : Atmega128->ucsr1a; }
	void ucsra(Reg8 value) { ((Unit == 0) ? Atmega128->ucsr0a : Atmega128->ucsr1a) = value; } 
	Reg8 ucsrb() { return (Unit == 0) ? Atmega128->ucsr0b : Atmega128->ucsr1b; }
	void ucsrb(Reg8 value) { ((Unit == 0) ? Atmega128->ucsr0b : Atmega128->ucsr1b) = value; } 
	Reg8 ucsrc() { return (Unit == 0) ? Atmega128->ucsr0c : Atmega128->ucsr1c; }
	void ucsrc(Reg8 value) { ((Unit == 0) ? Atmega128->ucsr0c : Atmega128->ucsr1c) = (value | 1 << URSEL); }
	Reg8 ubrrl() { return (Unit == 0) ? Atmega128->ubrr0l : Atmega128->ubrr1l; }
	void ubrrl(Reg8 value) { ((Unit == 0) ? Atmega128->ubrr0l : Atmega128->ubrr1l) = value; } 
	Reg8 ubrrh() { return (Unit == 0) ? Atmega128->ubrr0h : Atmega128->ubrr1h; }
	void ubrrh(Reg8 value) { ((Unit == 0) ? Atmega128->ubrr0h : Atmega128->ubrr1h) = value; } 
	Reg16 ubrrhl();
	void ubrrhl(Reg16 value);
};

#endif
