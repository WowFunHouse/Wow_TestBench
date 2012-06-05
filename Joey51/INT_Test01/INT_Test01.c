#include <STC89.H>

void led(void) interrupt 0 using 3  	
{
	unsigned int t;

	P0=0x01; for(t=0;t<10000;t++);
	P0=0x02; for(t=0;t<10000;t++);		
	P0=0x04; for(t=0;t<10000;t++);
	P0=0x08; for(t=0;t<10000;t++);
	P0=0x10; for(t=0;t<10000;t++);
	P0=0x20; for(t=0;t<10000;t++);
	P0=0x40; for(t=0;t<10000;t++);
	P0=0x80; for(t=0;t<10000;t++);
	
}

void main(void) 
{
	EX0=1;
	EA=1;

	for(;;);
}