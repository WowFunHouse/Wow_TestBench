/****************************************************************************
 Title:			60 seconds electronic clock
 
 File:			Digit02_001

 Version:		0.01
 Description:	

 Created on:	2013-08-16
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

void display(unsigned char i);
void delay(unsigned int d);

unsigned char count;
unsigned char second;

unsigned char digit[] = {0xc0, 0xf9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x98};	  // display "0-9"

void main(void)
{
	TMOD = 0x01;
	TH0 =  (65536-45170)/256;	// 45170 x 11.0692Mhz = 50000微妙 =50ms
	TL0 =  (65536-45170)%256;	// Low bit 

	EA = 1;
	ET0 = 1;

	TR0 = 1;

	count = 0;
	second = 0;
	
	for(;;)
	{
		display(second);
	}
} /* main */

void isrTimer0(void) interrupt 1 using 2  //Timer0 Interrupt using Bank 2 registers
{
	TR0 = 0;

	count++;

	if (count == 20)
	{
		second++;
		 count = 0;
	
		if (second == 110) 		 // why???  0-100 0k , 0-110 Bad
		second = 0;
	}

  	TH0 =  (65536-45170)/256;	// 45170 x 11.0692Mhz = 50000微妙 =50ms
	TL0 =  (65536-45170)%256;	// Low bit 

	TR0 = 1;
}

void display(unsigned char i)
{	
	unsigned int d = 300;

	P0 = 0xff;			// Turn off P0
 	P2 = 0xff;			// Turn off P2
	delay(d);

	P2 = 0x7f;			// P2 = 0111 1111
	P0 = digit[i%10];	// Rolling display "0-9" 
	delay(d);

	P2 = 0xbf;
	P0 = digit[i/10];
	delay(d);

	P2 = 0xdf;
	P0 = digit[i/100];
	delay(d);
}

void delay(unsigned int d)
{
	unsigned int t;
	for(t=0; t<=d; t++);

} /* delay */
