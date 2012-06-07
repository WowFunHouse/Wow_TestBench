#include <STC89.H>

unsigned char wait;

void main(void)
{
	wait = 0;

	P0=0xAA;		// Set LED pattern

	TH1=0x00;		// Set Timer1 delay time (high byte)
	TL1=0x01;		// Set Timer1 delay time (low byte)
	TMOD=T1_M1;		// Set Timer1 to Mode 1

	ET1=1;			// Accept Timer1 interrupt

	EA=1;			// Enable all interrupt (accept interrupt)
	TR1=1;			// Start Timer1

	for(;;);
}

void timer(void) interrupt 3 using 3
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

	TH1=0x00;
	TL1=0x01;
	TR1=1;
}


