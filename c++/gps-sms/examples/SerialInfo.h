char get() { while(!rxd_full()); return rxd(); }
void put(char c) { while(!txd_empty()); txd(c); }

bool rxd_full() { return (ucsra() & (1 << RXC)); }
bool txd_empty() { return (ucsra() & (1 << UDRE)); }

    Reg8 rxd() { return udr(); }
    void txd(Reg8 c) { udr(c); }


Reg8 udr(){ return AVR8::in8((_unit == 0) ? IO::UDR0 : IO::UDR1); }
void udr(Reg8 value){ AVR8::out8(((_unit == 0) ? IO::UDR0 : IO::UDR1),value); }   

    static Reg8 in8(const unsigned char port) {
	return (*(volatile unsigned char *)(port + 0x20));
    }
    static void out8(unsigned char port, Reg8 value) {
        (*(volatile unsigned char *)(port + 0x20)) = value;
    }

