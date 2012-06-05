#include <STC89.H>

#define	DELAY_COUNT	10000

void delay(unsigned int count)
{
	unsigned int t;

	for(t=0;t<count;t++);
}

void led(void) interrupt 0 using 3  	
{
	P0=0x01; delay(DELAY_COUNT);
	P0=0x02; delay(DELAY_COUNT);		
	P0=0x04; delay(DELAY_COUNT);
	P0=0x08; delay(DELAY_COUNT);
	P0=0x10; delay(DELAY_COUNT);
	P0=0x20; delay(DELAY_COUNT);
	P0=0x40; delay(DELAY_COUNT);
	P0=0x80; delay(DELAY_COUNT);
}

void main(void) 
{
	EX0=1;
	EA=1;

	for(;;);
}