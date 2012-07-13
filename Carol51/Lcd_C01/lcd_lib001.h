/*********************************************************************
 LCD Dribver Library Header File

 Version:		0.01
 Description:	Driver of LCD 1602 module

 Created on:	2012-07-09
 Created by:	Carol
 *********************************************************************/
#define LCD_DMODE_DISPLAY_OFF					  0
#define LCD_DMODE_DISPLAY_ON					  0x04
#define	LCD_DMODE_CURSOR_OFF					  0
#define	LCD_DMODE_CURSOR_ON					      0x02
#define	LCD_DMODE_CURSOR_BLING_OFF			      0
#define	LCD_DMODE_CURSOR_BLING_ON			  	  0x01

#define	LCD_STYLE_1LINE						      0
#define	LCD_STYLE_2LINES						  0X08
#define	LCD_STYLE_FONT5X7						  0
#define	LCD_STYLE_FONT5X10					      1X04

#define	LCD_INPUT_DEC							  0
#define	LCD_INPUT_INC					          0X02
#define	LCD_INPUT_SHIFT_OFF						  0 
#define	LCD_INPUT_NOSHIFT						  0X01

#define	LCD_SHIFT_CURSOR						  0
#define	LCD_SHIFT_MSG							  0X08
#define	LCD_SHIFT_LEFT							  0
#define	LCD_SHIFT_RIGHT 						  0X04

//void lcdWriteCmd(unsigned char cmd);
void lcdWriteData(unsigned char dData);
void lcdWriteString(char *str);

void lcdSelectRow(unsigned char row);			   //ROW#:1,ROW#2:0
void lcdClearRow(unsigned char row);
void lcdClearCurrentRow(void);
void lcdClearRestOfRow(unsigned char row);
void lcdClearRestOfCurrentRow(void);

void lcdSetDisplayMode(unsigned display_mode);
 
void lcdSetInputMode(unsigned char input_mode,unsigned char input_shift);
void lcdSetInputShiftOn(void);
void lcdSetInputShiftOff(void);
void lcdSetInputInc(void);
void lcdSetInputDec(void);

void lcdSetPosition(unsigned char row,unsigned char pos);
void lcdPutChar(unsigned char row,unsigned char pos,char c);
unsigned char lcdGetCursorPost(void);

/********************************************************************
lcdMakeF
Input:

 ********************************************************************/
void lcdMadeRawFont(unsigned char c,unsigned char row0,		
									unsigned char row1,
									unsigned char row2,
									unsigned char row3,
									unsigned char row4,
									unsigned char row5,
									unsigned char row6,
									unsigned char row7);

/********************************************************************
lcdMakeFont()
Input:

 ********************************************************************/
void lcdMadeFont(unsigned char c,unsigned char row);


void lcdInit(void);					        //2 lines,Fones 5x7
void lcdClearScreen(void);

void lcdEfxBounce(unsigned char row,char *str,unsigned int speed);
void lcdEfxRoll(unsigned char row,char *str,unsigned char dir,unsigned int speed); 
