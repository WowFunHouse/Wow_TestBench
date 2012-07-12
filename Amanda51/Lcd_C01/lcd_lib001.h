/***************************************************************************
 LCD Driver Library Heade

 Version:		0.02
 Description:	LCD 1602 Driver Header	

 Creared on:	2012-07-12
 Creared by:	Amanda Li

 Board:			Richmcu RZ-51/AVR 2.0				
 ***************************************************************************/
#include "lib_uty001.h"
#include "hw_rz51v2.h"

#define LCD_DMODE_DISPLAY_OFF			0
#define LCD_DMODE_DISPLAY_ON			0x04
#define LCD_DMODE_CURSOR_OFF			0
#define LCD_DMODE_CURSOR_ON				0x02
#define LCD_DMODE_CUPSOR_BLINK_OFF		0
#define LCD_DMODE_CUPSOR_BLINK_ON		0x01

#define LCD_STYLE_1LINES				0
#define LCD_STYLE_2LINES				0x08
#define LCD_STYLE_FONT5x7				0
#define LCD_STYLE_FONT5x10				0x04

#define LCD_INPUT_DEC					0
#define LCD_INPUT_INC					0x02
#define LCD_INPUT_SHIFT_OFF				0
#define LCD_INPUT_SHIFT_ON				0x01

#define LCD_SHIFT_CUSOR					0
#define LCD_SHIFT_MSG					0x08
#define LCD_SHIFT_LEFT					0
#define LCD_SHIFT_RIGHT					0x04

//unsigned char lcdCheckBusy(void);
//void lcdWaitUntilReady(void);

//void lcdWriteCmd(unsigned char cmd);
void lcdWriteData(unsigned char dData);
void lcdWriteString(char *str);

void lcdSelectRow(unsigned char row);

void lcdInitDisplayMode(unsigned char display_mode);

void lcdSetInputMode(unsigned char input_mode, unsigned char input_shift);

void lcdInit(void);																	// 8-bit, 2 lines, 5x7 font

void lcdClearScreen(void);

void lcdMakeRawFont(unsigned char c, unsigned char row0,
									 unsigned char row1,
									 unsigned char row2,
									 unsigned char row3,
									 unsigned char row4,
									 unsigned char row5,
									 unsigned char row6,
									 unsigned char row7);

void lcdMakeFont(unsigned char c, unsigned char *row);