/***************************************************************************
LCD Testing

Version:		0.01
Description:	

Creared on:		Amanda Li
Creared by:		2012-07-09

Board:			Richmcu RZ-51/AVR 2.0

Conmnection:	LCD pins as below - 
				RS			P20
				RW			P21
				EN			P22
				DATAPORT	P0

Jumpers:		Remove JPSMG - Disable 7-Segment LEDs
				Remove JPP0	 - Disable LEDs
				Add JPBG	 - Enable LCD Back Light				
*****************************************************************************/
#include "lcd_lib001.h"

void main(void)
{	
	char msgA[] = "I Love 8051";
	
	char msgB[] = "Hello World!"; 

	lcdClearScreen();
	
	lcdWriteCmd(0x0F);						// Display: ON, Cursor: ON, Blink: ON
	lcdWriteCmd(0x38);						// 8-bit, 2 lines, 5x7 font
	lcdWriteCmd(0x06);						// Input mode: Increment, Non-shift

	lcdWriteString(msgA);
	lcdSelectRow(1);
	lcdWriteString(msgB);

	for (;;);

}/* main */