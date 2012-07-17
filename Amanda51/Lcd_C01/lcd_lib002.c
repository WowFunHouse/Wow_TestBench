/****************************************************************************
 File:			lcd_lib002.c
 
 LCD Driver Library

 Version:		0.02
 Description:	LCD 1602 Driver	

 Creared on:	2012-07-16		
 Creared by:	Amanda Li

 Board:			Richmcu RZ-51/AVR 2.0

 Conmnection:	LCD pins as below - 
				RS			P20
				RW			P21
				EN			P22
				DATAPORT	P0

 Jumpers:		Remove JPSMG - Disable 7-Segment LEDs
				Remove JPP0	 - Disable LEDs
				Add JPBG	 - Enable LCD Back Light

 V0.02			Make font in 1602 LCD				
 ****************************************************************************/
#include <STC89.H>
#include "lib_uty001.h"
#include "hw_rz51v2.h"
#include "lcd_lib002.h"

#define DELAYSHORT	10

unsigned char	lcdCurrentModeFunction;			// Use to memorize the current status of # of Lines & Fonts
unsigned char	lcdCurrentModeInput;			// Use to memorize the current status of Input Mode
unsigned char	lcdCurrentModeDisplay;		  	// Use to memorize the current status of Display Mode
unsigned char	lcdCurrentModeShifting;			// Use to memorize the current stauts of Shifting

unsigned char lcdCheckBusy(void)
{
	unsigned char	bf;
	
	BF = 1;										// Set Pin ready for Input

	EN = 0;										// Ready to create a transition of EN: Low -> High
	RS = 0;
	RW = 1;	
	EN = 1;
	delay(DELAYSHORT);							// Wait for the BF to be stable	

	bf = BF;

	EN = 0;
	RW = 0;										// Optional to set it to READ
	RS = 1;										// Optional to set it to RAM Select

	return	bf;

} /* lcdCheckBusy */

void lcdWaitUntilReady(void)
{
	while (lcdCheckBusy() == 1);

} /* lcdWaitUntilReady */

void lcdWriteCmd(unsigned char cmd)
{
	lcdWaitUntilReady();	

	EN = 0;										// Ready to create a transition of EN: Low -> High
	RS = 0;
	RW = 0;

	DATAPORT = cmd;
	delay(DELAYSHORT);							// Optional - wait for data stable

	EN = 1;
	delay(DELAYSHORT);							// Wait for LCD to complete the read cycle

	EN = 0;
	RW = 1;
	RS = 1;

} /* lcdWriteCmd */

void lcdWriteData(unsigned char dData)
{
	lcdWaitUntilReady();	

	EN = 0;										// Ready to create a transition of EN: Low -> High
	RS = 1;
	RW = 0;

	DATAPORT = dData;
	delay(DELAYSHORT);							// Optional - wait for data stable

	EN = 1;
	delay(DELAYSHORT);							// Wait for LCD to complete the read cycle

	EN = 0;
	RW = 1;
	RS = 0;
		
} /* lcdWriteData */

void lcdWriteString(char *str)
{
	unsigned char	n;	

	for (n=0; *(str+n)!=0; n++)
	{
		lcdWriteData( *(str+n) );
	}

} /* lcdWriteString */

void lcdSelectRow(unsigned char row)					// 0: First Line, 1: Senced Line
{
	unsigned char	n;	

	if (row == 1)		n = 0x40;
	else				n = 0x00;

	lcdWriteCmd(0x80 | n);

} /* lcdSelectRow */

void lcdClearScreen(void)
{
	lcdWaitUntilReady();
	lcdWriteCmd(0x01); 							// Clear LCD Screen

} /* lcdClearScreen */

void lcdSetInput(unsigned char mode)
{
	lcdCurrentModeInput = mode;

	lcdWriteCmd(0x04 | lcdCurrentModeInput);

}/* lcdSetInput */

void lcdSetInputShiftOn(void)
{
	lcdCurrentModeInput |= LCD_INPUT_SHIFT_ON;

	lcdWriteCmd(0x04 | lcdCurrentModeInput);

} /* lcdSetInputShiftOn */

void lcdSetInputShiftOff(void)
{
	lcdCurrentModeInput &= ~LCD_INPUT_SHIFT_ON;

	lcdWriteCmd(0x04 | lcdCurrentModeInput);

} /* lcdSetInputShiftOff */

void lcdSetInputInc(void)
{
	lcdCurrentModeInput |= LCD_INPUT_INC;

	lcdWriteCmd(0x04 | lcdCurrentModeInput);

} /* lcdSetInputInc */

void lcdSetInputDec(void)
{
	lcdCurrentModeInput &= ~LCD_INPUT_INC;

	lcdWriteCmd(0x04 | lcdCurrentModeInput);

} /* lcdSetInputDec */

void lcdSetDisplay(unsigned char mode)
{
	lcdCurrentModeDisplay = mode;

	lcdWriteCmd(0x08 | lcdCurrentModeDisplay);

}/* lcdSetDisplay */

void lcdSetDisplayOn(void)
{
	lcdCurrentModeDisplay |= LCD_DISPLAY_ON;

	lcdWriteCmd(0x08 | lcdCurrentModeDisplay);

} /* lcdSetDisplayOn */

void lcdSetDisplayOff(void)
{
	lcdCurrentModeDisplay &= ~LCD_DISPLAY_ON;

	lcdWriteCmd(0x08 | lcdCurrentModeDisplay);

} /* lcdSetDisplayOff */

void lcdSetCursorOn(void)
{
	lcdCurrentModeDisplay |= LCD_DISPLAY_CURSOR_ON;

	lcdWriteCmd(0x08 | lcdCurrentModeDisplay);

} /* lcdSetCursorOn */

void lcdSetCursorOff(void)
{
	lcdCurrentModeDisplay &= ~LCD_DISPLAY_CURSOR_ON;

	lcdWriteCmd(0x08 | lcdCurrentModeDisplay);

} /* lcdSetCursorOff */

void lcdSetCursorBlinkOn(void)
{
	lcdCurrentModeDisplay |= LCD_DISPLAY_CURSOR_BLINK_ON;

	lcdWriteCmd(0x08 | lcdCurrentModeDisplay);

} /* lcdSetCursorBlinkOn */

void lcdSetCursorBlinkOff(void)
{
	lcdCurrentModeDisplay &= ~LCD_DISPLAY_CURSOR_BLINK_ON;

	lcdWriteCmd(0x08 | lcdCurrentModeDisplay);

} /* lcdSetCursorBlinkOff */ 

void lcdSetShifting(unsigned char mode)
{
	lcdCurrentModeShifting = mode;

	lcdWriteCmd(0x10 | lcdCurrentModeShifting);

} /* lcdSetShifting */

void lcdSetShiftingMsg(void)
{
	lcdCurrentModeShifting |= LCD_SHIFT_MSG;

	lcdWriteCmd(0x10 | lcdCurrentModeShifting);

} /* lcdSetShiftingMsg */

void lcdSetShiftingCursor(void)
{
	lcdCurrentModeShifting &= ~LCD_SHIFT_MSG;

	lcdWriteCmd(0x10 | lcdCurrentModeShifting);

} /* lcdSetShiftingCursor */

void lcdSetShiftingRight(void)
{
	lcdCurrentModeShifting |= LCD_SHIFT_RIGHT;

	lcdWriteCmd(0x10 | lcdCurrentModeShifting);

} /* lcdSetShiftingRight */

void lcdSetShiftingLeft(void)
{
	lcdCurrentModeShifting &= ~LCD_SHIFT_RIGHT;

	lcdWriteCmd(0x10 | lcdCurrentModeShifting);

} /* lcdSetShiftingLeft */
	
void lcdSetFunction(unsigned char mode)
{
	lcdCurrentModeFunction = mode;

	lcdWriteCmd(0x30 | lcdCurrentModeFunction);				// 8-bit	

} /* lcdSetFunction */

void lcdSetFunction2Lines(void)
{
	lcdCurrentModeFunction |= LCD_STYLE_2LINES;

	lcdWriteCmd(0x30 | lcdCurrentModeFunction);

} /* lcdSetFunction2Lines */

void lcdSetFunction1Line(void)
{
	lcdCurrentModeFunction &= ~LCD_STYLE_2LINES;

	lcdWriteCmd(0x30 | lcdCurrentModeFunction);

} /* lcdSetFunction1Line */

void lcdSetFunctionFont5x7(void)
{
	lcdCurrentModeFunction &= ~LCD_STYLE_FONT5X10;

	lcdWriteCmd(0x30 | lcdCurrentModeFunction);

} /* lcdSetFunctionFont5x7 */

void lcdSetFunctionFont5x10(void)
{
	lcdCurrentModeFunction |= LCD_STYLE_FONT5X10;

	lcdWriteCmd(0x30 | lcdCurrentModeFunction);

} /* lcdSetFunctionFont5x10 */

void lcdMakeRawFont(unsigned char c, unsigned char row0,
									 unsigned char row1,
									 unsigned char row2,
									 unsigned char row3,
									 unsigned char row4,
									 unsigned char row5,
									 unsigned char row6,
									 unsigned char row7)
{
	unsigned char	cgAddr = 8*c;
	
	lcdWriteCmd(0x40 | cgAddr++);
	lcdWriteData(row0);	
	lcdWriteCmd(0x40 | (cgAddr+1));
	lcdWriteData(row1);	
	lcdWriteCmd(0x40 | (cgAddr+2));
	lcdWriteData(row2);	
	lcdWriteCmd(0x40 | (cgAddr+3));
	lcdWriteData(row3);	
	lcdWriteCmd(0x40 | (cgAddr+4));
	lcdWriteData(row4);
	lcdWriteCmd(0x40 | (cgAddr+5));
	lcdWriteData(row5);	
	lcdWriteCmd(0x40 | (cgAddr+6));
	lcdWriteData(row6);	
	lcdWriteCmd(0x40 | (cgAddr+7));
	lcdWriteData(row7);		

} /* lcdMakeRawFont */

void lcdMakeFont(unsigned char c, unsigned char *row)
{
	unsigned char cgAddr = 8*c;
	unsigned char n;

	for (n=0; n<8; n++)
	{
		lcdWriteCmd(0x40 | (cgAddr + n));
		lcdWriteData( row[n] );
	}

} /* lcdMakeFont */