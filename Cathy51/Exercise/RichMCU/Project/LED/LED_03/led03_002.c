/****************************************************************************
 Title:			LED	&  Keyboard Testing
 
 File:			led03_001.c

 Version:		0.02
 Description:	Touch keyboard	LED one by one on

 Created on:	2013-08-7
 Created by:	

 Board:			RichMCU RZ-51V2.0

 Connections:	Default

 Jumpers:		Remove JPP1  - Disable LEDs on Port-2		
 **************************************************************/
#include <STC89.H>

#define	KEYON  1
#define KEYOFF 0

void delay(void)
{
	unsigned int d;

	for (d=0; d<25000; d++);

}/* delay */

unsigned char getkey(void)
{
	P1 = 0xff;			    //Turn off Keyboard 

	if (P14!= 1)			// get Keyboard on/off
	{
		return KEYON;
	}
	else
	{
		return KEYOFF;
	}
}/* getkey */

void main(void)
{  
	unsigned char LED[]={0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf,	0x7f};
	static unsigned char count=0;
	unsigned char led;
	unsigned char lastkey;

	P0 = 0xff;					// Turn off LEDs
	lastkey = getkey();			
	
	for(;;)
	{	
		if ((getkey() == KEYON) && (lastkey == KEYOFF))		   // Keyboard on and last Touch keyboard off
		{
			count++;				// Touch number of records

			if (count == 8)			// Touch eight times  return  zero
			{
				count = 0;
			}

			delay();			   // Interrupt mask
			P0 = LED[led];   	   // LED on
			led++;

			if (led == 8)		   // eight lignt return the first time
			{
				led = 0;
			}

			delay();			  
			P0 = 0xff;			   // Turn off LEDs
		}
	}
}

