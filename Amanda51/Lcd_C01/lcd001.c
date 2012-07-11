/*****************************************************************************
 LCD Testing

 Version:		0.01
 Description:	Show 2 lines to 1602 LCDs

 Creared on:	2012-07-10		
 Creared by:	Amanda Li
 *****************************************************************************/
#include "lcd_lib001.h"

void main(void)
{	
	char msgA[] = "I Love 8051";
	
	char msgB[] = "Hello World!";
	
	lcdInit(); 													// 8-bit, 2 lines, 5x7 font

	lcdInitDisplayMode(	LCD_DMODE_DISPLAY_ON |					// Display: ON, Cursor: ON, Blink: ON 
						LCD_DMODE_CURSOR_ON	 | 
						LCD_DMODE_CUPSOR_BLINK_ON);

	lcdSetInputMode(LCD_INPUT_INC, LCD_INPUT_SHIFT_OFF);	   // Input mode: Imcrement, No-shift

	lcdClearScreen();

	lcdWriteString(msgA);
	lcdSelectRow(1);
	lcdWriteString(msgB);

	for (;;);

}/* main */