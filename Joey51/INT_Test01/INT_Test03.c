#include <STC89.H>

void delay(void)
{
	unsigned int t;

	for(t=0;t<10000;t++);
}

void led(void) interrupt 0 using 3  	
{
	P0=0x01; delay();
	P0=0x02; delay();		
	P0=0x04; delay();
	P0=0x08; delay();
	P0=0x10; delay();
	P0=0x20; delay();
	P0=0x40; delay();
	P0=0x80; delay();
}

void main(void) 
{
	EX0=1;
	EA=1;

	for(;;);
}