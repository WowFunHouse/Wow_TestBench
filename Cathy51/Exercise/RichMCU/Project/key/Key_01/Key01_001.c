/****************************************************************************
 Title:			Keyboard Control Digit Display "0-9,A,B,C,D,E,F" 
 
 File:			Key01_001.c	

 Version:		0.01
 Description:	

 Created on:	2013-09-10
 Created by:	

 Board:			RichMCU RZ-51V2.0

 Connections:	P0.0 - P0.7 -> 7-Segment LED segemnt control (0:On 1:Off)
				P2.0 - P2.1 -> Digit selection of 7-Segment LED
 			 	P1.4 -> Switch K5 (O:On 1:Off)

				LCD pins as below -
 				RS - P20
				RW - P21
				EN - P22
				DATAPORT - P0

 Jumpers:		Remove JPSMG - Disable 7-Segment LEDs
 				Remove JPP0  - Disable LEDs
				Add JPBG     - Enable LCD Back Light

				将 JPSMG 数码管控制跳线拔掉使数码管停止工作。
 				将 JPP0 跳线端的跳线帽拔掉以免干扰1602 液晶显示
				插上1602LCD液晶
				将 JPBG 液晶背光跳线插上		
 **************************************************************/
#include <STC89.H>

void delay(void);
unsigned char scankey(void);

unsigned char key;

unsigned char digit[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,
              			0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e,0xbf};

unsigned char keycode[]={0xee,0xde,0xbe,0x7e,0xed,0xdd,0xbd,0x7d, 
             			 0xeb,0xdb,0xbb,0x7b,0xe7,0xd7,0xb7,0x77 };


void main (void)
{
	P0 = 0xbf;					//	Digit display " - "
	P2 = 0x7f;					//	P2 0111 1111
	P1 = 0xff;					//	Turn off keyboard	1111 1111

	for(;;)																				 
	{
		P1 = 0xf0;			    // Scanning keyboard
		if ((P1& 0xf0)!=0xf0 )
		{
			scankey();			// Run scankey() function
			P0 =  digit[key];	// Display digit[]
		}
	}
}

void delay(void)			    
{
	unsigned int d;					  
										
	for (d=0; d<4000; d++);

}/* delay */


unsigned char scankey(void)
{
	unsigned char cross, column,  key_digital,  j;

	P1 = 0xf0;											 //	 Set P1 -> 1111 0000

	cross = P1;											 //  Scanning cross
	if((cross & 0xf0)!=0xf0)
	{
		delay();										// 	 Mask keyBounce

		cross = P1;										//	 Cross second scanning  
		if ((cross & 0xf0)!=0xf0)
		{
			P1 = 0x0f;
			column = P1;

			if ((column & 0x0f)!=0x0f)				   //	Scanning column
			{
				 key_digital = cross | column ;		   //	Cross or Column
			}

			for (j=0; j<=15; j++)					   //	Look for keycode[]
			{
				if ( key_digital ==  keycode[j])
				{
					key = j;
					return (key);
				}
			}
		}
	}
	else P1 = 0xff;
}





