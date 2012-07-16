/*
	Title:			Toolg Switch
	Version:		1.2

	Created on:		2012-07-01
	Created by:		Cathy

	Description:	Click the led bright click the led put out

	Hardware:		RICHMCU Development board	
	Connections:	
					P0: 7-seg LED		0:On,	1:Off
					P2: 7-seg LED (P20 - P27)
					P1:	P14-P17  Switch:	0:On,	1:Off
*/	
		
#include <STC89.H>

#include "../../Common51/lib51.h"

#define	KEYON  1
#define KEYOFF 0
#define	LIGHTON  1
#define LIGHTOFF 0

unsigned char getKey (void)
{
	P1 = 0xFF;						   

	if (P14!= 1)
	{
		return KEYON;				
	}
	else
	{
		return KEYOFF;
	} 
}/* getKey*/
	 
void ledOn (void)				       // Led On
{
	P0 = ~0x01;
}

void ledOff (void)					   // Led Off
{
	P0 = ~0x00;
}

/*unsigned char led(unsigned char n)
{
		return ~n ;
}*/

void main (void)
{
	unsigned char lastsw, led ;

	P1 =0xFF;
	ledOff();

	lastsw = getKey();
	
	for(;;)
	{
		if (( getKey() == KEYON ) && ( lastsw == KEYOFF) )
		{
			 if (led == 1)
			 {
			 	led = LIGHTOFF;
				ledOff();
				
			 }
			 else
			 {
			  	led = LIGHTON;
				ledOn();
			 }
		 }
	}
}
