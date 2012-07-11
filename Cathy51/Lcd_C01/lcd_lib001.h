 /******************************************************************
Library of supporting utilities

 Version:      		0.01
 Description:		Supporting function

 Created on:		2012-07-09
 Created by:		Cathy
 ******************************************************************/
#define LCD_DMODE_DISPLAY_OFF			0
#define LCD_DMODE_DISPLAY_ON			0x04	
#define LCD_DMODE_CURSOR_OFF			0
#define LCD_DMODE_CURSOR_ON				0x02
#define	LCD_DMODE_CURSOR_BLINK_OFF		0
#define LCD_DMODE_CURSOR_BLINK_ON		0x01

#define	LCD_STYLE_1LINE					0
#define LCD_STYLE_2LINES				0x08
#define LCD_STYLE_FONT5X7				0
#define	LCD_STYLE_FONT5X10				0x04

#define	LCD_INPUT_DEC		    		0
#define	LCD_INPUT_INC		    		0x02
#define	LCD_INPUT_SHIFT_OFF				0
#define	LCD_INPUT_SHIFT_ON				0x01

#define	LCD_SHIFT_CURSOR				0
#define	LCD_SHIFT_MSG					0x08
#define	LCD_SHIFT_LEFT					0
#define	LCD_SHIFT_RIGHT					0x04
	

//unsigned char lcdCheckBusy(void);
//void lcdWaitUntilReady(void);

//void lcdWriteCmd(unsigned char cmd);
void lcdWriteData(unsigned char dData);
void lcdWriteString(char *str);
 
void lcdSelectRow(unsigned char row);  	// row: 0, 1
void lcdClearRow(unsigned char row);
void lcdClearCurrentRow(void);
void lcdClearRestOfRow(void);

void lcdSetDisplayMode(unsigned char display_mode); 

void lcdSetInputMode(unsigned char input_mode ,unsigned char input_shift);
						
void lcdInit(void);		   //2lines, Font:5x7


void lcdClearScreen(void);