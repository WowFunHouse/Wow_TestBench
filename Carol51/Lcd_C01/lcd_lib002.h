/*********************************************************************
 File:         lcd_lib002.h

 LCD Dribver Library Header File

 Version:		0.01
 Description:	Driver of LCD 1602 module

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

void lcdSelectDDRAMAddr(unsigned addr);
void lcdSelectCGRAMAddr(unsigned addr);


void lcdSeleRow(unsigned char row);			   //ROW#:1,ROW#2:0
void lcdSeleRowPosition(unsigned char row,unsigned char pos);
void lcdClearRow(unsigned char row);
void lcdClearCurrentRow(void);
void lcdClearRestOfRow(unsigned char row);
void lcdClearRestOfCurrentRow(void);

void lcdClearScreen(void);

void lcdCursorReset(void);

void lcdSeletRowPosition(unsigned char row);
void lcdSetDisplay(unsigned display_mode);
 
void lcdSetInput(unsigned char mode);
void lcdSetInputShiftOn(void);
void lcdSetInputShiftOff(void);
void lcdSetInputInc(void);
void lcdSetInputDec(void);

void lcdSetShifting(void);
void lcdSetFuntion(unsigned char mode);

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
