/****************************************************************************
 Title:			7 -  segment Test
 
 File:			Digit11_001

 Version:		0.01
 Description:	Rolling display "0-9"

 Created on:	2013-08-18
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
#include "../../Common51/lib51.h"

void delay(unsigned int d);

unsigned char digit01[] = {0xc0, 0xf9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x98};	  // display "0-9"

void main(void)
{
	unsigned char i;
	unsigned int d = 10000;

	P0 = 0xff;			// Turn off P0
 	P2 = 0xff;			// Turn off P2

	P2 =0x7f;			// P2 = 0111 1111

	for(;;)
	{
		for (i=0; i<10; i++)
		{
				P0 = digit01[i];	// Rolling display "0-9" 
				delay(d);
		}
	}
} /* main */

void delay(unsigned int d)
{
	unsigned int t;
	for(t=0; t<=d; t++);

} /* delay */
