/****************************************************************************
 Title:			7 -segment Test
 
 File:			Digit05_001

 Version:		0.01
 Description:	Digit Scroll "--HELLO--" 

 Created on:	2013-08-16															    
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
void delay ( unsigned int d);
void display (void);

unsigned int d = 120;
unsigned char s;
unsigned char digit[]={0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
						0xbf, 0xbf, 0x89, 0x86, 0xc7, 0xc7, 0xc0, 0xbf, 0xbf,
						0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}; //P0 display "--hello--" 
void main ()
{
		unsigned char t;
	
		P0 = 0xff;			   // Turn	off	 P0
		P2 = 0xff;			   // Turn  off  P2

	   	for(;;)
		{
			for (s=0; s<17; s++)			  // P0 display
			{
			  for (t=0; t<=125; t++)		  // delay 
			  {
				  display();				  // Call " void display (void) "
			  }
		}
	}
} /* main */

void display (void)
{
	unsigned char i;
	unsigned char shift;

	shift = 0x7f;					   //  shift = 0111 1111

	for (i=8; i>0; i--)				   //  
	{
		P2 = 0xff;					   //  Turn	off	 P2
		P0 = 0xff;					   //  Turn	off	 P0

		P2 = shift;					   //  P2 = 0111 1111 
		shift = (shift>>1)|0x80;	   //  P2 shift>>1 or 1000 0000 

		P0 = digit[i+s];			   //	P0 display "--HELLO--"										 

		delay(d);
	}
}/* display */

void delay ( unsigned int d)
{
	unsigned char t;

	for (t=1;	t<=d; t++);

}/* delay */
 

