#include <stc89.h>

void uartInit9600(void)
{
	// X'tal: 11.0495MHz
	// 9600 Baud, 8 Bit Data, No Parity, 1 Stop Bit

    TMOD = 0x20;
    SCON = 0x40;
    TH1 = 0xFD;
    TL1 = TH1;
    PCON = 0x00;
    TR1 = 1;

} /* uartInit9600 */

void uartInit38400(void)
{
	// X'tal: 14.7456MHz
	// 38400 Baud, 8 Bit Data, No Parity, 1 Stop Bit

    TMOD = 0x20;
    SCON = 0x40;
    TH1 = 0xFF;
    TL1 = TH1;
    PCON = 0x00;
	EA  = 1;			// Enable Interrupt
	ES  = 1;		    // Enable Serial Port Interrupt
    TR1 = 1;			// Start Timer1 as baud rate generator

} /* uartInit38400 */

void sendOneByte(unsigned char c)
{
    SBUF = c;
    while(!TI);

    TI = 0;
} /* sendOneByte */

void delayms(unsigned int t)   // 1ms delay: Îó²î -0.651041666667us
{
    unsigned int d;
	unsigned char a,b;

	for (d=0; d<t; d++)
	{
	    for(b=245;b>0;b--)
	        for(a=1;a>0;a--);
	}
} /* delayms */


void main(void)
{
	unsigned char c;

    uartInit38400();

	for (;;)
	{
		P10 = 0;
		P20 = 0;

		delayms(500);

		for (c=32; c<127; c++)
			sendOneByte(c);

		P10 = 1;
		P20 = 1;

		delayms(250);
	}		
} /* main */

