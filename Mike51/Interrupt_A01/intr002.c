/**************************************************************
 Title:			Interrupt testing		
 
 File:			intr002.c

 Version:		0.01
 Description:	Toggle LEDs on Port-1

 Created on:	2013-08-02
 Created by:	Michael

 Board:			RichMCU RZ-51V2.0

 Connections:	Default

 Jumpers:		All on	
 **************************************************************/
#include <STC89.H>

void delay(void)
{
	int d;

	for (d=0; d<10000; d++);

} /* delay */

void main(void)
{
	char i=0;

	P1=0xff;

	EX0=1;
	EA=1;

	for(;;)
	{
		P0=i++;
		delay();
	}

} /* main */

void isr(void) interrupt 1 using 2
{	
	P1=~P1;

} /* isr */