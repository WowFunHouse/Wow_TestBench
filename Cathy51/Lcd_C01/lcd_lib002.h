 /******************************************************************
File: lcd_lib002.h

Library of supporting utilities

 Version:      		0.01
 Description:		Supporting function

 Created on:		2012-07-09
 Created by:		Cathy
 ******************************************************************/
#define	LCD_INPUT_INC		    		0x02
#define	LCD_INPUT_SHIFT_ON				0x01

#define LCD_DISPLAY_ON					0x04	
#define LCD_CURSOR_ON					0x02
#define LCD_CURSOR_BLINK_ON				0x01

#define	LCD_SHIFT_MSG					0x08
#define	LCD_SHIFT_RIGHT					0x04

#define LCD_STYLE_2LINES				0x08
#define	LCD_STYLE_FONT5X10				0x04

//unsigned char lcdCheckBusy(void);
//void lcdWaitUntilReady(void);

//void lcdWriteCmd(unsigned char cmd);
void lcdWriteData(unsigned char dData);
void lcdWriteString(char *str);
 
void lcdSelectRow(unsigned char row);  		// Row#1:0, Row#2:1	Cursor on 1st position of row
void lcdSelectCurrentRowPosition(unsigned char row, unsigned char pos);
void lcdClearRow(unsigned char row);
void lcdClearCurrentRow(void);
void lcdClearRestOfRow(unsigned char row);
void lcdClearRestOfCurrentRow(void);

void lcdClearScreen(void);

void lcdCursorReset(void);

void lcdSetInput(unsigned char mode);
void lcdSetInputShiftOn(void);
void lcdSetInputShiftOff(void);
void lcdSetInputInc(void);
void lcdSetInputDec(void);

void lcdSetDisplay(unsigned char mode); 
void lcdSetDisplayOn(void);
void lcdSetDisplayOff(void);
void lcdSetDisplayCursorOn(void);
void lcdSetDisplayCursorOff(void);
void lcdSetDisplayCursorBlinkOn(void);
void lcdSetDisplayCursorBlinkOff(void);

void lcdSetShifting(unsigned char mode);
void lcdSetShiftingMsg(void);
void lcdSetShiftingCursor(void);
void lcdSetShiftingRight(void);
void lcdSetShiftingLeft(void);

void lcdSetFunction(unsigned char mode);
void lcdSetFunction2Lines(void);
void lcdSetFunction1Line(void);
void lcdSetFunctionFont5x7(void);
void lcdSetFunctionFont5x10(void);

void lcdSetPosition(unsigned char row, unsigned char pos);
void lcdPutChar(unsigned char row, unsigned char pos, char c);
unsigned char lcdGetCursorPos(void);

/**************************************************************
lcdMakeRawFont() - Use thisto create a new font
Input:
	c: chraacter code (0-7)
	row0 - row7: dotmatrix rows from top to bottom
				 valid bits b0 - b4 from right to left
Output: N/A
 **************************************************************/

void lcdMakeRawFont(unsigned char c, unsigned char row0, 
									 unsigned char row1,
									 unsigned char row2,
									 unsigned char row3,
									 unsigned char row4,
									 unsigned char row5,
									 unsigned char row6,
									 unsigned char row7);

/**************************************************************
lcdMakeRawFont() - Use thisto create a new font
Input:
	c: chraacter code (0-7)
	*row0: dotmatrix rows(8 rows) from top to bottom
		   valid bits b0 - b4 from right to left
Output: N/A
 **************************************************************/
void lcdMakeFont(unsigned char c, char *row);						
void lcdInit(void);		   	//2lines, Font:5x7


void lcdEfxBounce(unsigned char row, char *str, unsigned int speed);
void lcdEfxRoll(unsigned char row, char *str, unsigned char dir, unsigned int speed);

