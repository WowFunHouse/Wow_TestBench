/****************************************************************************
 Title:			7-Seqment Test
 
 File:			digit001.c

 Version:		0.01
 Description:	7-Seqment Test - Display Five in the 3H of 7-Segment LED 

 Created on:	2013-07-31
 Created by:	

 Board:			RichMCU RZ-51V2.0

 Connections:	P0.0 - P0.7 -> 7-Segment LED segemnt control (0:On 1:Off)
				P2.0 - P2.1 -> Digit selection of 7-Segment LED	(1H to 8H)
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

****************************************************************************/
#include <STC89.H>

void main(void)
{
	for(;;)
	{
		//P0 = 0x92;
		P0 = ~0x6d;

		//P2 = 0xfb;
		P2 = ~0x04;
	}
} /* main */
