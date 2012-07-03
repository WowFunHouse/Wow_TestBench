#include <STC89.H>

#define	DIGIT0	P13
#define	DIGIT1	P12
#define DIGIT2	P11
#define DIGIT3	P10

unsigned char led(unsigned char ptn)
{
	return ~ptn;
}

void delayTimerMs(unsigned int time)
{
	unsigned int	t;

	TMOD = T0_M1;

	for (t=0; t<time; t++)
	{
		TH0  = (65536 - 1000) >> 8;			// Delay 1ms
		TL0  = (65536 - 1000) % 256;

		TR0	 = 1;
		
		while (TF0 == 0);					// wait 1ms
		TF0 = 0;
	}
}

void main(void)
{
	unsigned char ledBCDSegment[]={0x3F, 0x06, 0x5B, 0x4F, 0x66,
					 				0x6D, 0x7D, 0x07, 0x7F, 0x6F};

	unsigned int n=0;

	DIGIT0 = 0;
	for (;;)
	{
		P0=led(ledBCDSegment[n++]);
		if (n>9) n=0;
		delayTimerMs(1000);		// Delay 1sec
	}
}

