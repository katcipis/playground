/* I/O PORT A, DATA DIRECTION REGISTER (0 -> in, 1 -> out) */
#define DDRA    (*(volatile unsigned char *)(0x1A + 0x20))

/* I/O PORT A, DATA REGISTER */
#define PORTA   (*(volatile unsigned char *)(0x1B + 0x20))

int main(void)
{
    int i;

    /* Set the whole port (all bits) to "output" */
    DDRA = 0xff;

    while(1)
    {
	/* Turn on all leds connected to port A */
        PORTA = 0x00;

	/* Delay */
        for (i = 0; i < 0xffff; i++);

	/* Turn on all leds connected to port A */
        PORTA = 0xff;

	/* Delay */
        for (i = 0; i < 0xffff; i++);
    }

    return 0;
}
