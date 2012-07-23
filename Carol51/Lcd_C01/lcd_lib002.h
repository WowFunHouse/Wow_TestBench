/*********************************************************************
 File:         lcd_lib002.h

 LCD Dribver Library Header File

 Version:		0.01
 Description:	LCD 1602 Driver Header

 Created on:	2012-07-16
 Created by:	Carol

 Board:			RichMCU RZ-51V2.0

 Connection:	LCD pins as below -
 				RS - P20
				RW - P21
				EN - P22
				DATAPORT - P0

 Jumpers:		将 JPP0 跳线端的跳线帽拔掉以免干扰1602 液晶显示
				将 JPSMG 数码管控制跳线拔掉使数码管停止工作。
				插上1602LCD液晶
				将 JPBG 液晶背光跳线插上
 
 *********************************************************************/
#define	LCD_INPUT_INC					          0x02
#define	LCD_INPUT_SHIFT_ON						  0x01

#define LCD_DISPLAY_ON					          0x04
#define	LCD_DMODE_CURSOR_ON					      0x02
#define	LCD_DMODE_CURSOR_BLING_ON			  	  0x01

#define	LCD_SHIFT_MSG							  0X08
#define	LCD_SHIFT_RIGHT 						  0X04

#define	LCD_STYLE_2LINES						  0x08
#define	LCD_STYLE_FONT5X10					      0x04

//unsigned char lcdCheckBusy(void);
//void lcdWaitUntilReady(void);

//void lcdWriteCmd(unsigned char cmd);
void lcdWriteData(unsigned char dData);
void lcdWriteString(char *str);

//addr:0x00 - 0x27, 0x40 - 0x67
unsigned char lcdSeletDDRAMAddr(unsigned addr);
unsigned char lcdSeletCGRAMAddr(unsigned addr);

unsigned char lcdGetCursorPos(void);
void lcdPutCharAtPos(unsigned char row,unsigned char pos,char c);

void lcdCursorReset(void);

void lcdClearRowScreen(void);
void lcdClearRow(unsigned char row);
voie lcdClearCurrentRow(void);
void lcdClearRestOfRow(unsigned char row);
void lcdClearRestOfCurrentRow(void);

//row: 0 - 1
void lcdSeleRow(unsigned char row);			   //ROW#1:0,ROW#2:1 Cursor on 1status
void lcdSeleRowPosition(unsigned char row,unsigned char pos);
void lcdSelectPosition(unsigned char row,unsigned pos);

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

void lcdSetFuntion(unsigned char mode);
void lcdSetFunction2Lines(void);
void lcdSetFunction1Lines(void);
void lcdSetFunctionFont5x7(void);
void lcdSetFunctionFont5x10(void);

/********************************************************************
lcdMakeRawFont() - Use this to creata a new font
Input:
	c:

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
void lcdMadeFont(unsigned char c,char *row);
void lcdInit(void);					        //2 lines,Fones: 5x7

void lcdEfxBounce(unsigned char row,char *str,unsigned int speed);
void lcdEfxRoll(unsigned char row,char *str,unsigned char dir,unsigned int speed); 
