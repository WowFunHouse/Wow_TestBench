/**************************************************************
 Title:			Interrupt testing
 
 File:			intr001.c

 Version:		0.01
 Description:	Toggle LEDs on Port-1

 Created on:	2013-08-02
 Created by:	Amanda Li

 Board:			RichMCU RZ-51V2.0

 Connections:	Default

 Jumpers:		All on		
 **************************************************************/
#include <STC89.H>

void delay(unsigned int t)
{
	unsigned	x;

	for(x=0; x<t; x++);
} /* delay */

void main(void)
{
	char	i;

	P1 = 0xff;

	EX0 = 1;
	EA = 1;

	for(;;)
	{
		P0 = i++;
		delay(2000);
	}
} /* main */

void isr(void) interrupt 1 using 2
{
	P1 = ~P1;
} /* ist */