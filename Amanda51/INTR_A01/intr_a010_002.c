/**************************************************************
 Title:			Interrupt testing
 
 File:			intr_a010_002.c

 Version:		0.01
 Description:	Solve problem for key Bounce: 
 				Interrupt0 fist in to disable, and timer interrupt call that enable

 Created on:	2013-08-04
 Created by:	Amanda Li

 Board:			RichMCU RZ-51V2.0

 Connections:	Default

 Jumpers:		All on		
 **************************************************************/
#include <STC89.H>

#define	KEYBOUNCE_DELAY_US	40000

void delay(unsigned int t)
{
	unsigned int x;

	for(x=0; x<t; x++);

} /* delay */

void main(void)
{
	unsigned char	i=0;

	P1 = 0xff;					    // Turn off all LEDs

	IT0  = 1;						// Falling Edge Trigger on INT0
	EX0  = 1;						// Enable Interrupt INT0
	EA   = 1;						// Enable ALL Interrupts

	for(;;)
	{
//		P0 = ~(i++);

		P00 = ~P00;

		delay(20000);
	}

} /* main */

void taskInt0(void)
{
	P1 = ~P1;										// Task to be done

} /* taskInt0 */

void isrInt0(void) interrupt 0 using 2				// INT0 Interrupt Service Routine
{
	EX0 = 0;										// Disable INT0

	taskInt0();

	TR0  = 0;					    				// Stop Timer0
	TMOD = T0_M1;									// Set Timer0 to Mode1
	TH0  = (65536-KEYBOUNCE_DELAY_US) >> 8;						// Delay 20000us (20ms)
	TL0  = (unsigned char)(65536-KEYBOUNCE_DELAY_US) & 0x00ff;
	
	ET0  = 1;										// Timer interrupt anable
	TR0  = 1;										// Start Timer0
} /* isrInt0 */

void isrTimerInt(void) interrupt 1 using 3
{
	EX0  = 1; 
} /* inrTimerInt */