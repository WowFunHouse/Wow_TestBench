/*****************************************************************************
 File:			lcd002.c
 
 LCD Testing

 Version:		0.02
 Description:	Show 2 lines to 1602 LCDs

 Creared on:	2012-07-12		
 Creared by:	Amanda Li

 V0.02			Make font in 1602 LCD
 *****************************************************************************/
#include "lib_uty001.h"
#include "lcd_lib002.h"

void main(void)
{	
//	char font0[] = {0x06, 0x09, 0x09, 0x06, 0x03, 0x1a, 0x05, 0x08};

	char msgA[]  = "I Love 8051!Wow!Wow!";
	char msgB[]  = "Hello World!";

	lcdSetFunction2Lines();							// Set 2 lines, font:5x7
	lcdSetFunctionFont5x7();															

	lcdSetDisplayOn();	   							// Set Display On, Cursor On, Blink On
	lcdSetDisplayCursorOn();
	lcdSetDisplayCursorBlinkOn();

//	lcdMakeRawFont(0, 0x01, 0x02, 0x04, 0x08, 0x10, 0x11, 0x0a, 0x11);
//	lcdMakeRawFont(0, 0x04, 0x0b, 0x04, 0x07, 0x1a, 0x04, 0x08, 0x10);
//	lcdMakeRawFont(1, 0x06, 0x09, 0x09, 0x06, 0x03, 0x1a, 0x05, 0x08);
//	lcdMakeFont(0, font0);

	lcdClearScreen();
	lcdSetInputShiftOff();
	lcdSetInputInc();

//	lcdWriteData(0);
//	lcdWriteData(1);
//	lcdWriteData(' ');
//	lcdWriteString(msgA);
//	lcdWriteData(' ');
//	lcdWriteData(1);
//	lcdWriteData(0);

	lcdWriteString(msgA);
	lcdSelectRow(1);
	lcdWriteString(msgB);

	for (;;);

} /* main */