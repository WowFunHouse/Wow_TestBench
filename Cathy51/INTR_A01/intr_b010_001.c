 /****************************************************************************
 Title:			Interrupt testing
 
 File:			intr002.c

 Version:		0.01
 Description:	Toggle LEDs on Port-1

 Created on:	2013-08-2
 Created by:	

 Board:			RichMCU RZ-51V2.0

 Connections:	Default

 Jumpers:		All on		
 **************************************************************/
#include <STC89.H>

#define	KEYBOUNCE_MASK_US	6000

void delay(void)
{
	unsigned int d;

	for (d=0; d<10000; d++);

}/* delay */

void main(void)
{
	unsigned char i=0;

	P1 = 0xff;					// Turn off LEDs

	IT0 = 1;						// Int0 Trigger: Edge
	EX0 = 1;						// Int0: On

	ET0 = 0;					// Timer0 Interrupt: Off
	TR0 = 0;					// Timer0: Off

	EA  = 1;					// Enable ALL Interrupts

	for(;;)
	{
	  	P0=~(i++);
		delay();
	}
} /* main */

void isrKeyboard(void) interrupt 0			// Keyboard Interrupt Service Routine
{
	EX0 = 0;								// Int0: Off

	P1 = ~P1;

	TMOD = T0_M1;							// Timer0: Mode1

	TH0  = (65536 - KEYBOUNCE_MASK_US) >>8; // Timer0 delay time
	TL0  = (unsigned char)((65536 - KEYBOUNCE_MASK_US) & 0x00ff);

	ET0  = 1;								// Timer0 Interrupt: On
	TR0	 = 1;								// Timer0: Start now...
	
} /* isrKeyboard */

void isrTimer0(void) interrupt 1			// Timer0 Interrupt Service Routine 
{
	ET0 = 0;								// Timer0 Interrupt: Off

	TR0 = 0;								// Timer0: Off
	EX0 = 1;								// Int0: On
} /* isrTimer0 */
