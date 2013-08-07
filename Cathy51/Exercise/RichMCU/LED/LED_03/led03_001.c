/****************************************************************************
 Title:			LED	&  Keyboard Testing
 
 File:			led03_001.c

 Version:		0.01
 Description:	Touch keyboard	LED one by one on

 Created on:	2013-08-6
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
	unsigned char lastkey;

	P0 = 0xff;					// Turn off LEDs
	lastkey = getkey();			
	
	for(;;)
	{
		static 	unsigned char count=0;

		if ((getkey() == KEYON) && (lastkey == KEYOFF))		   //Keyboard on and last Touch keyboard off
		{
			count++;			   //  Touch number of records

			if (count == 9)
			 {
			 	count=0;
			 }

			if (count == 1)
			{
				delay();			// Keybounce mask
				P0 = 0xfe;			// LED 1111 1110 on
				delay();			// keybounce mask
				P0 = 0xff;			// LED all off
			}
			if (count == 2)
			{
				delay();
				P0 = 0xfd;			// LED 1111 1101 on
				delay();
				P0 =0xff;
			}
			if (count == 3)
			{
				delay();
				P0 = 0xfb;			// LED 1111 1011 on
				delay();
				P0 =0xff;
			}
			if (count == 4)
			{
				delay();
				P0 = 0xf7;			// LED 1111 0111 on
				delay();
				P0 =0xff;
			}
			if (count == 5)
			{
				delay();
				P0 = 0xef;			// LED 1110 1111 on
				delay();
				P0 =0xff;
			}
			if (count == 6)
			{
				delay();
				P0 = 0xdf;			// LED 1101 1111 on
				delay();
				P0 =0xff;
			}
			if (count == 7)
			{
				delay();
				P0 = 0xbf;			// LED 1011 1111 on
				delay();
				P0 =0xff;
			}
			if (count == 8)
			{
				delay();
				P0 = 0x7f;			// LED 0111 1111 on
				delay();
				P0 =0xff;
			}
		}
	}
}
