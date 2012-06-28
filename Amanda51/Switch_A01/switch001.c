/****************************************************************
Toggle the LED with the switches

Created on:		2012-06-28
Created by:		Amanda Li

Description:
	P0:			LED: 0:OFF, 1:ON
	P14:	K5	Switch: 0:OFF, 1:ON
****************************************************************/
#include <STC89.H>

unsigned char getSwitch(void)
{
	P14 = 1;

	if (P14 != 1)							// Switch now is ON
	{
		return	1;	
	}
	else		  							// Switch now is OFF
	{
		return	0;
	}
}/* getSwitch */

void ledON(void)
{
	P0 = ~0x01;								// Led now is ON
}/* ledON */

void ledOFF(void)
{
	P0 = ~0x00;								// Led now is OFF
}/* ledOFF */

void main(void)
{
	unsigned char	sw_last, led;
	
	sw_last = getSwitch();

	ledOFF();
	led = 0;

	for (;;)
	{
		if ((getSwitch() == 1) && (sw_last == 0))
		{
			if (led == 1)							// LED now is ON -> OFF
			{
				ledOFF();
				led = 0;
			}
			else									// LED now is OFF -> ON
			{
				ledON();
				led = 1;
			}
		}
	}																																																					                                                                                                                                                             
}/* main */