/****************************************************************
Toggle the LED with the switches

Created on:		2012-06-28
Created by:		Amanda Li

Description:
	P0:			LED: 	1->ON, 0->OFF
	P14:	K5	Switch: 1->ON, 0->OFF
****************************************************************/
#include <STC89.H>

#define SWITCH_POINT	P14
#define	LED_POINT		P0

#define SWITCH_ON	1
#define SWITCH_OFF	0
#define LED_ON		1
#define LED_OFF		0

unsigned char getSwitch(void)
{
	SWITCH_POINT = SWITCH_ON;

	if (SWITCH_POINT != SWITCH_ON)					// Switch now is ON
	{
		return	SWITCH_ON;	
	}
	else		  							// Switch now is OFF
	{
		return	SWITCH_OFF;
	}
}/* getSwitch */

void ledON(void)
{
	LED_POINT = ~0x01;								// Led now is ON
}/* ledON */

void ledOFF(void)
{
	LED_POINT = ~0x00;								// Led now is OFF
}/* ledOFF */

void main(void)
{
	unsigned char	sw_last, led;
	
	sw_last = getSwitch();

	ledOFF();
	led = LED_OFF;

	for (;;)
	{
		if ((getSwitch() == 1) && (sw_last == 0))
		{
			if (led == 1)							// LED now is ON -> OFF
			{
				ledOFF();
				led = LED_OFF;
			}
			else									// LED now is OFF -> ON
			{
				ledON();
				led = LED_ON;
			}
		}
	}																																																					                                                                                                                                                             
}/* main */