/****************************************************************************
 LCD Driver Library Header File

 Version:		0.01
 Description:	LCD 1602 Driver Header

 Created on:	2012-07-09
 Created by:	Michael

 Board:			RichMCU RZ-51V2.0

 Connection:	LCD pins as below -
 				RS - P20
				RW - P21
				EN - P22
				DATAPORT - P0

 Jumpers:		Remove JPSMG - Disable 7-Segment LEDs
 				Remove JPP0  - Disable LEDs
				Add JPBG     - Enable LCD Back Light

				将 JPSMG 数码管控制跳线拔掉使数码管停止工作。
 				将 JPP0 跳线端的跳线帽拔掉以免干扰1602 液晶显示
				插上1602LCD液晶
				将 JPBG 液晶背光跳线插上
****************************************************************************/

#define	LCD_DMODE_DISPLAY_OFF			0
#define	LCD_DMODE_DISPLAY_ON			0x04
#define	LCD_DMODE_CURSOR_OFF			0
#define	LCD_DMODE_CURSOR_ON				0x02
#define	LCD_DMODE_CURSOR_BLINK_OFF		0
#define	LCD_DMODE_CURSOR_BLINK_ON		0x01

#define	LCD_STYLE_1LINE					0
#define LCD_STYLE_2LINES				0x08
#define	LCD_STYLE_FONT5X7				0
#define	LCD_STYLE_FONT5X10				0x04

#define	LCD_INPUT_DEC					0
#define	LCD_INPUT_INC					0x02
#define	LCD_INPUT_SHIFT_OFF				0
#define	LCD_INPUT_SHIFT_ON				0x01

#define	LCD_SHIFT_CURSOR				0
#define	LCD_SHIFT_MSG					0x08
#define	LCD_SHIFT_LEFT					0
#define	LCD_SHIFT_RIGHT					0x04

// unsigned char lcdCheckBusy(void);
// void lcdWaitUntilReady(void);

// void lcdWriteCmd(unsigned char cmd);
void lcdWriteData(unsigned char dData);
void lcdWriteString(char *str);

void lcdSelectRow(unsigned char row);	// Row#1:0, Row#2:1
void lcdClearRow(unsigned char row);
void lcdClearCurrentRow(void);
void lcdClearRestOfRow(unsigned char row);
void lcdClearRestOfCurrentRow(void);

void lcdSetDisplayMode(unsigned display_mode);

void lcdSetInputMode(unsigned char input_mode, unsigned char input_shift);
void lcdSetInputShiftOn(void);
void lcdSetInputShiftOff(void);
void lcdSetInputInc(void);
void lcdSetInputDec(void);

void lcdSetPosition(unsigned char row, unsigned char pos);
void lcdPutChar(unsigned char row, unsigned char pos, char c);
unsigned char lcdGetCursorPost(void);

/***************************************************
 lcdMakeRawFont() - Use this to create a new font
 Input:
	c: character code (0 - 7)
	row0-row7: dotmatrix rows from top to bottom
			   valid bits b0 - b4 from right to left
 Output: N/A
 ***************************************************/
void lcdMakeRawFont(unsigned char c, unsigned char row0,
									 unsigned char row1, 
									 unsigned char row2, 
									 unsigned char row3, 
									 unsigned char row4,
									 unsigned char row5,
									 unsigned char row6,
									 unsigned char row7);

/*****************************************************
 lcdMakeFont() - Use this to create a new font
 Input:
	c: character code (0 - 7)
	*row: dotmatrix rows (8 rows) from top to bottom
		  valid bits b0 - b4 from right to left
 Output: N/A
 *****************************************************/
void lcdMakeFont(unsigned char c, char *row);
void lcdInit(void);							// 2lines, Font:5x7

void lcdClearScreen(void);

void lcdEfxBounce(unsigned char row, char *str, unsigned int speed);
void lcdEfxRoll(unsigned char row, char *str, unsigned char dir, unsigned int speed);




