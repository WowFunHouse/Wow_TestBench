/*****************************************************
 Digital progressive LEDs 1 light left per second

 Version:		1.0
 Description:	Timer wait for 1 secound (9216 x 100 times)
				Timer each time -> The Led run one times
				Led run one times -> Display plus one

 Created on:	2012-06-26
 Created by:	Amanda Li

 Board:			RICHMCU RZ-51/AVR V2.0
 Hardware:		LED: 0->ON, 1->OFF

 Specification / Requirements:
 	LED status as below: 
 	1s  OFF OFF OFF OFF OFF OFF OFF OFF		->	0x00
	2s  OFF OFF OFF OFF OFF OFF OFF ON		->	0x01
	3s  OFF OFF OFF OFF OFF OFF ON  OFF		->	0x02
	4s  OFF OFF OFF OFF OFF OFF ON  ON		->	0x03
	5s  OFF OFF OFF OFF OFF ON  OFF OFF		->	0x04
	6s  OFF OFF OFF OFF OFF ON  OFF ON		->	0x05
	7s  OFF OFF OFF OFF OFF ON  ON  OFF		->	0x06
	8s  OFF OFF OFF OFF OFF ON  ON  ON		->	0x07
	9s  OFF OFF OFF OFF ON  OFF OFF OFF		->	0x08
	10s	OFF OFF OFF OFF ON  OFF OFF ON		->	0x09
*****************************************************/

#include <STC89.H>

void light(unsigned char p);

unsigned char	timeout;

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
		if(timeout != 0)					// 1 second reached
		{
			light(a);						// Turn on the LED
			a++;
			timeout = 0;
		}
	}
}/* main */

void isrTimer(void) interrupt 1				// Timer stopped, TH=0, TL=0, TF=1, timer interrrupt triggered
{

	static unsigned char	timercount = 0;	

	TH0  = (65536 - 9216)>>8;
	TL0  = (65536 - 9216)%256;

	if(timercount >= 100)						// Wait for 1 secound (9216 x 100)
	{
		timeout = 1;
		timercount = 0;
	}
	else
	{
		timercount++;
	}
}/* isrTimer */

void light(unsigned char p)
{
	P0 = ~p;
}/* light */
