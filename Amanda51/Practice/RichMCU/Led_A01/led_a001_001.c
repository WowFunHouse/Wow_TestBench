/**************************************************************
 Title:			Practice for RichMCU 
 
 File:			led_a001_001.c

 Version:		0.01
 Description:	Practice for led: ex6 and ex7 
 				ex6 -> 单盏灯亮，在 P0.0 至 P0.7 间循环
 				ex7 -> 单盏灯亮，在 P1.0 至 P1.7 间循环

 Created on:	2013-08-06
 Created by:	Amanda Li

 Board:			RichMCU RZ-51V2.0

 Connections:	Default

 Jumpers:		All on		
 **************************************************************/
#include <STC89.H>

#define		LED_INPUT_POINT		P1				// Position control to LED lights: P0 -> ex6; P1 -> wx7

void delay(unsigned int t)
{
	unsigned int x;

	for(x=0; x<t; x++);

} /* delay */

void main(void)
{
	unsigned char	a, b;
	
	for (a=1, b=1; a<=8; a++, b=b*2 )			// Loop eight times -> 1, 2, 4, 8, 16, 32, 64, 128
	{
		LED_INPUT_POINT = ~b;
		delay(20000);
	}
} /* main */