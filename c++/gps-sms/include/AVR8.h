#ifndef AVR8_H
#define AVR8_H


class AVR8
{
public:
	typedef volatile unsigned char  Reg8;
	typedef volatile unsigned short Reg16;
	typedef volatile unsigned char  IOReg8;
	Reg8 r0; 
	Reg8 r1; 
	Reg8 r2; 
	Reg8 r3; 
	Reg8 r4; 
	Reg8 r5; 
	Reg8 r6; 
	Reg8 r7; 
	Reg8 r8; 
	Reg8 r9; 
	Reg8 r10; 
	Reg8 r11; 
	Reg8 r12; 
	Reg8 r13; 
	Reg8 r14; 
	Reg8 r15; 
	Reg8 r16; 
	Reg8 r17; 
	Reg8 r18; 
	Reg8 r19; 
	Reg8 r20; 
	Reg8 r21; 
	Reg8 r22; 
	Reg8 r23; 
	Reg8 r24; 
	Reg8 r25; 
	union {
		struct{Reg8 r26; Reg8 r27;};
		Reg16 x;
	};
	union {
		struct{Reg8 r28; Reg8 r29;};
		Reg16 y;
	};
	union {
		struct{Reg8 r30; Reg8 r31;};
		Reg16 z;
	};
};

#endif
