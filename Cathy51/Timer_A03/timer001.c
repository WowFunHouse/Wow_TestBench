 /****************************************************************************
 Title:			Interrupt testing
 
 File:			 intr002.c

 Version:		0.01
 Description:	Toggle LEDs on Port-1

 Created on:	2013-08-2
 Created by:	

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
	unsigned int time_cnt; 
	char i=0;

	P1=0xff;

//	TMOD=0x01;		  // T0: Mode1 T1:Mode0
//	TMOD=T0_M1;		  // T0: Mode1 T1:Mode0
//	TMOD=0x11;		  // T0: Mode1 T1:Mode1

	TMOD = T0_M1 |T1_M1;		// Gate=0; C/T=0:Timer; Mode 1

	time_cnt = 65536 - 40000;	// Delay 40000us (40ms, 0.04s)

	TH0 = time_cnt >>8;
	TL0 =(unsigned char) (time_cnt & 0x00ff);

	ET0=1;				// Enable Timer0 interrupt
	EA=1;				// Enable ALL interrupts

	TF0=0;				// Clear Timer0 overflow flag
	TR0=1;				// Start Timer0

	for (;;)
	{
	  	P0=i++;
		delay();
	}
} /* main */

void isrTimer0(void) interrupt 1 using 2	// Timer0 Interrupt using Bank 2 registers
{
	static unsigned char count=0;

	ET0=0;					// Timer0 Interrrupt off
	TR0=0;					// Stop Timer0
	TF0=0;					// Reset Timer0 overflow flag

	count++;

	if (count>=25)				// 25 * 40ms (0.04s) = 1s			
	{
		P1=~P1; 
		count=0;			// Reset multiplier
	}

	time_cnt = 65536 - 40000;	// Delay 40000us (40ms, 0.04s)

	TH0 = time_cnt >>8;
	TL0 =(unsigned char) (time_cnt & 0x00ff);

	ET0=1;					// Enable Timer0 Interrrupt
	TR0=1;				// Start Timer0 again (40ms)

} /* isrTimer0 */ 