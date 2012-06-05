/*
	Title:			Timer of every one second beep on one times
	Created on:		2012-06-02
	Created by:		Amanda Li

	TMOD:			Timer0 to Mode 2(8-bit Auto-Reload)
	P3: P34-P37		Beep: 0: On, 1: Off
*/

#include <STC89.H>

#define TIMER_INTERVAL	100	 			// Timer interval requests number
#define PAUSE_LENGTH	10000			// Timer pause length
#define BEEP_FREQ		10 				// Beep freq
#define BEEP_LENGTH		100				// Beep length

unsigned int	pause;

void main(void)
{
	pause = 0;							// Set Interrupt pause initial value

	TH0	 = 256 - TIMER_INTERVAL;		// Set Timer0 delay time (high byte = total number - requests number)
	TL0	 = 256 - TIMER_INTERVAL;		// Set Timer0 delay time (low byte = total number - requests number)
	TMOD = T0_M2;						// Set Timer0 to Mode 2(8-bit Auto-Reload)
	
	ET0	= 1;							// Accept Timer0 interrupt
	
	EA  = 1;							// Enable all interrupt (accept interrupt)
	TR0 = 1;							// Start Timer0
	
	for(;;);	
}/* main */

void beeptimer(void) interrupt	1	using	3
{
	unsigned int	t, n;

	if(pause == PAUSE_LENGTH)
	{
		for(n=0; n<BEEP_FREQ; n++)
		{
			P3 = 0x00;
			for (t=0; t<BEEP_LENGTH; t++);

			P3 = 0x10;
			for (t=0; t<BEEP_LENGTH; t++);
		}
		pause = 0;
	}
	else
	{
		pause++;
	}
}/* beeptimer */