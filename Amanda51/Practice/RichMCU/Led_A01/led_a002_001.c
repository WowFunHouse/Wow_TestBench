/**************************************************************
 Title:			Practice for RichMCU 
 
 File:			led_a002_001.c

 Version:		0.01
 Description:	Practice for led: ex20 
 				K5 to control Led0 lights and move

 Created on:	2013-08-09
 Created by:	Amanda Li

 Board:			RichMCU RZ-51V2.0

 Connections:	Default

 Jumpers:		All on		
 **************************************************************/
#include <STC89.H>

unsigned char getSwitch(void)
{
	P14 = 1;

	if (P14 != 1)					// Switch now is ON
	{
		return	1;	
	}
	else		  					// Switch now is OFF
	{
		return	0;
	}
}/* getSwitch */

void delay(unsigned int t)
{
	unsigned int x;

	for(x=0; x<t; x++);

} /* delay */

void main(void)
{
	unsigned char	sw_status;
	
	unsigned char	a=1;

	sw_status = getSwitch();

	P0 = ~0;

	for (;;)
	{
		if ((getSwitch() == 1) && (sw_status == 0))			// Switch ON -> OFF 
		{
			P0 = ~a;
			delay(20000);

			if (a < 128)			a = a*2;
			else if (a >= 128)		a = 1;
		}
	}
}/* main */