#include <STC89.H>

unsigned char wait;

void main(void)
{
	wait = 0;

	P0=0xAA;

	TH0=0x00;		// Set Timer0 delay time (high byte)
	TL0=0x01;		// Set Timer0 delay time (low byte)
	TMOD=T0_M1;		// Set Timer0 to Mode 1
	ET0=1;			// Accept Timer0 interrupt

	EA=1;			// Enable all interrupt (accept interrupt)
	TR0=1;			// Start Timer0

	for(;;);
}

void timer(void) interrupt 1 using 3
{
	if (wait == 5)
	{
		P0=~P0;
		wait = 0;
	}
	else
	{
		wait++;
	}

	TH0=0x00;
	TL0=0x01;
	TR0=1;
}


