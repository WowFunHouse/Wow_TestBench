/****************************************************************************
 Title:			7 - segment Test			
 
 File:			Digit04_001

 Version:		0.01
 Description:	Display	 " 12345678 "  Number

 Created on:	2013-08-18
 Created by:	Cathy

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

unsigned char digit01[] = { 0xf9, 0xA4, 0xB0, 0x99, 0x92, 0x83, 0xf8, 0x80};   // Number " 1,2,3,4,5,6,7,8 "
unsigned char digit02[] = { 0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f};   // Display Bit
					
void main(void)
{
	unsigned int i;
	unsigned int d = 125;

	P0 = 0xff;				//	Turn off P0
	P2 = 0xff;				//	Turn off P2

	for(;;)
	{
		for (i=0; i<8; i++)		
		{
			P0 = digit01[i];	// get eight times
			P2 = digit02[i];	// get eight times 

			delay(d);

//			P0 = 0xff;			//	Turn off P0
//			P2 = 0xff;			//	Turn off P2
		}
	}
} /* main */

void delay(unsigned int d)
{
	unsigned int t;

	for (t=0; t<d; t++);
}  /* delay */
