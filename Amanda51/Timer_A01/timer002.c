/*****************************************************
Timer Program

Version:		1.0
Description:	Timer wait for 1 secound (9216 x 100 times)
				Timer each time -> The Led run one times
				Led run one times -> Display plus one

Created on:		2012-06-26
Created by:		Amanda Li

Board:			RICHMCU RZ-51/AVR V2.0
*****************************************************/

#include <STC89.H>

void light(unsigned char p);

unsigned char	timeout;
unsigned int	waittime;

void main(void)
{
	unsigned char	a;

	TMOD = T0_M1;				  			// Set Timer0 to Mode 1
	TH0  = (65536 - 9216)>>8;				// Set Timer0 delay time (high byte)
	TL0  = (65536 - 9216)%256;				// Set Timer0 delay time (low byte) 

	ET0  = 1;				 				// Accept Timer0 interrupt
	EA   = 1; 								// Enable all interrupt (accept interrupt)

	a = 0;				  					// Original state for " a "
	timeout = 0;							// Original state for " timeout "
	light(a);								// Original state for LED

	TR0  = 1;								// Start Timer1

	for(;;)
	{
		if(timeout != 0)					// Chect the timer
		{
			light(a);						// Turn on the LED
			a++;
			timeout = 0;
		}
	}
}/* main */

void timer(void) interrupt 1
{
	if(waittime >= 100)						// Wait for 1 secound (9216 x 100)
	{
		timeout = 1;
		waittime = 0;
	}
	else
	{
		waittime++;
	}

	TH0  = (65536 - 9216)>>8;
	TL0  = (65536 - 9216)%256;

}/* timer */

void light(unsigned char p)
{
	P0 = ~p;
}/* light */
