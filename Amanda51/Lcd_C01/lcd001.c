/*****************************************************************************
 LCD Testing

 Version:		0.02
 Description:	Show 2 lines to 1602 LCDs

 Creared on:	2012-07-12		
 Creared by:	Amanda Li

 V0.02			Make font in 1602 LCD
 *****************************************************************************/
#include "lcd_lib001.h"

void main(void)
{	
	char font0[] = {0x04, 0x0B, 0x04, 0x07, 0x1A, 0x04, 0x08, 0x10};
	char font1[] = (0x06, 0x09, 0x0A, 0x04, 0x03, 0x1A, 0x05, 0x08);
	
	char msgA[] = "I Love 8051";
	char msgB[] = "Hello World!";
	
	lcdInit(); 													// 8-bit, 2 lines, 5x7 font

	lcdInitDisplayMode(	LCD_DMODE_DISPLAY_ON |					// Display: ON, Cursor: ON, Blink: ON 
						LCD_DMODE_CURSOR_ON	 | 
						LCD_DMODE_CUPSOR_BLINK_ON);

//	lcdMakeRawFont(0, 0x01, 0x02, 0x04, 0x08, 0x10, 0x11, 0x0A, 0x11);

//	lcdMakeRawFont(0, 0x04, 0x0B, 0x04, 0x07, 0x1A, 0x04, 0x08, 0x10);
//	lcdMakeRawFont(1, 0x06, 0x09, 0x0A, 0x04, 0x03, 0x1A, 0x05, 0x08);

	lcdMakeFont(0, font0);

	lcdClearScreen();
	lcdSetInputMode(LCD_INPUT_INC, LCD_INPUT_SHIFT_OFF);	   // Input mode: Imcrement, No-shift

	lcdWriteData(0);
	lcdWriteData(' ');
	lcdWriteData(1);
	lcdWriteData(' ');
	lcdWriteString(msgA);
	lcdSelectRow(1);
	lcdWriteString(msgB);

	for (;;);

}/* main */