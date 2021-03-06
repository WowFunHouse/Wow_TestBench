#include <STC89.H>

#define	PORT_LED	P0

#define	DELAY_COUNT	10000

void delay(unsigned int count)
{
	unsigned int t;

	for(t=0;t<count;t++);
}

unsigned char led(unsigned char pattern)
{
	return ~pattern;
}

void isrLED(void) interrupt 0 using 3  	
{
	unsigned char	ptn[8]={0x01, 0x02, 0x04, 0x08, 
							0x10, 0x20, 0x40, 0x80};
	unsigned char	n;

	for (n=0; n<8; n++)
	{
		PORT_LED=led(ptn[n]);
		delay(DELAY_COUNT);
	}
}

void main(void) 
{
	EX0=1;
	EA=1;

	for(;;);
}