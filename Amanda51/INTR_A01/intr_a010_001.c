/**************************************************************
 Title:			Interrupt testing
 
 File:			intr_a010_001.c

 Version:		0.01
 Description:	Solve problem for key Bounce: 
 				Before the interrupt0 in, wait 20ms to next interrupt

 Created on:	2013-08-04
 Created by:	Amanda Li

 Board:			RichMCU RZ-51V2.0

 Connections:	Default

 Jumpers:		All on		
 **************************************************************/
#include <STC89.H>

unsigned char action=0;

void delay(unsigned int t)
{
	unsigned int x;

	for(x=0; x<t; x++);

} /* delay */

void main(void)
{
	unsigned char	i=0;

	P1 = 0xff;					    // Turn off all LEDs

	TR0  = 0;					    // Stop Timer0
	TMOD = T0_M1;					// Set Timer0 to Mode1
	TF0  = 0;						// Clear Timer0 Overflow flag
	TH0  = (65536-20000) >> 8;		// Delay 20000us (20ms)
	TL0  = (unsigned char)(65536-20000) & 0x00ff;

	IT0  = 1;						// Falling Edge Trigger on INT0
	ET0  = 0;					 	// Disable Timer0 Interrupt
	EX0  = 1;						// Enable Interrupt INT0
	EA   = 1;						// Enable ALL Interrupts

	for(;;)
	{
//		P0 = ~(i++);

		P00 = ~P00;
				
		if (TF0 == 0) P05 = 1; else P05 = 0;

		delay(20000);

	}

} /* main */

void taskInt0(void)
{
	P1 = ~P1;						// Task to be done

} /* taskINT0 */

void isrInt0(void) interrupt 0 using 2			// INT0 Interrupt Service Routine
{
	TR0 = 1;									// Start Timer0
	
	if (TF0 == 1)								// Timer0 expired
	{
		taskInt0();	   							// Task in action!

		TR0 = 0;								// Stop Timer0
		TF0 = 0; 								// Clear Timer0 Overflow flag
		TH0 = (65536-20000) >> 8;				// Delay 20000us (20ms)
		TL0 = (unsigned char)(65536-20000) & 0x00ff;

	}
} /* isrInt0 */


//void isrInt0(void) interrupt 0 using 2			// INT0 Interrupt Service Routine
//{
////	static unsigned char action=0;
//
//	if (action == 0)							// 1st Interrrupt INT0 from key					
//	{
//	    taskInt0();	   							// Task in action!
//		action=1;								// Mark task above has been taken
//
//	   	P06	= 1;
//		P07 = 0;
//		delay(50000);
//		delay(50000);
//	}
//
//	TR0 = 1;									// Start Timer0
//	
//	if (TF0 == 1)								// Timer0 expired
//	{
//		TR0 = 0;								// Stop Timer0
//		TF0 = 0; 								// Clear Timer0 Overflow flag
//		TH0 = (65536-20000) >> 8;				// Delay 20000us (20ms)
//		TL0 = (unsigned char)(65536-20000) & 0x00ff;
//				
//		action = 0;
//
//		P06 = 0;
//		P07 = 1;
//
//		delay(50000);
//
//	}
//} /* isrInt0 */

//void isr(void) interrupt 1 using 2
//{
//	P1 = ~P1;
//} /* isr */