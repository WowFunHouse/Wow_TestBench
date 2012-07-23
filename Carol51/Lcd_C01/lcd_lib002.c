/*********************************************************************
 File:          Lcd_lib002.c
 LCD Driver Library

 Version:		0.01  
 Description:	LCD 1602 Driver

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
#include <STC89.H>
#include "lib_uty001.h"
#include "hw_rz51v2.h"
#include "lcd_lib002.h"

#define DELAYSHORT	500
												   
unsigned char lcdCurrentModeInput;			    //Use to memorize the current
status of Input Mode						    
unsigned char lcdCurrentModeDisplay;			//Use to memorize the current
status of Display Mode							
unsigned char lcdCurrentModeShifting;			//Use to memorize the current
status of Shifting
unsigned char lcdCurrentModeFunction;			//Use to memorize the current
status of #	of Lines & Fonts 

unsigned char lcdCheckBusy(void)			   //1:busy,  0:poady;  
{
	unsigned char bf;
	
	DATAPORT=0xff;				// Set DATAPORT ready for input
	
	EN=0;
	RS=0;
	RW=1;
	EN=1;				
	delay(DELAYSHORT);
	bf=BF;
	EN=0;
	RW=0;
	
	return bf;

} /* lcdCheckBusy */

void lcdWaitUntilReady(void)
{
	while (lcdCheckBusy()==1);

} /* lcdWaitUntilReady */

void lcdWriteCmd(unsigned char cmd)
{
	lcdWaitUntilReady();
	
	RS=0;
	RW=0;
	EN=0;
	DATAPORT=cmd;
	delay(DELAYSHORT);
	EN=1;
	delay(DELAYSHORT);
	EN=0;
	RW=1;

} /* lcdWriteCmd */

void lcdWriteData(unsigned char dData)
{
	lcdWaitUntilReady();
	
	RS=1;
	RW=0;
	EN=0;
	DATAPORT=dData;
	delay(DELAYSHORT);
	EN=1;
	delay(DELAYSHORT);
	EN=0;
	RW=1;

} /* lcdWriteData */


void lcdWriteString(char *str)
{
	unsigned int n;
	
	for (n=0; *(str+n)!=0; n++)
	{
		lcdWriteData(*(str+n));
	}
} /* lcdWriteString */

void lcdSelectRow(unsigned char row)
{
	if (row == 0)
	{
		lcdWriteCmd(0x80|0x00);
	}
	else if (row == 1)
	{
		lcdWriteCmd(0x80|0x40);
	}
} /* lcdSelectRow */ 

void lcdClearRow(unsigned char row)
{
 	unsigned char n;
	unsigned char currentModeInput;

	currentModeInput=lcdcurrentModeInput;

	lcdSetInput(LCD_INPUT_INC);

	lcdSeletRow(row);

	for (n=0;n<40;n++)
	{
		lcdWriteData(' ');
	}
	lcdInpu(currentModeInput);

	lcdSeletRow(row); 

} /* lcdClearRow */

void lcdClearScreen(void)
{															  
	lcdWriteCmd(0x01);			   // Clear LCD screen

} /* lcdClear */

void lcdInit(void)
{
	lcdCurrenModeFunction=LCD_STYLE_2LINES;
	lcdWriteCmd(0x30 | lcdCurrentModeFunction);	  //8 bit,2 lines, font 5x7
			 
} /* lcdInit */

unsigned char lcdSeletDDRAMAddr(unsigned addr)
{
	unsigned char status=0;

	if ((addr >= 0) && (addr<=0x27)) || ((addr >=0x40) && (addr <= 0x67))
	{
		status=1;
	}

	lcdWriteCmd(x80 | addr);
	
	return status;

} /* lcdSeletDDRAMAddr */

unsigned char lcdSeletCGRAMAddr(unsigned addr);
{ 

} /* lcdSeletCGRAMAddr */

	  
void lcdSetDisplay(unsigned char mode)
{
	lcdCurrentModeDisplay|mode;
	lcdWriteCmd(0x08|lcdCurrentModeDisplay);

} /* lcdSetDisplay */

void lcdSetInput(unsigned char input_mode,unsigned char input_shift)
{		   
	lcdWriteCmd(0x04|input_mode|input_shift);

} /* lcdSetInputMode */

void lcdSetInputShiftOn(void)
{
	lcdCursorModeInput|

} /* lcdSetInputShiftOn */

void lcdSetInputShiftOff(void)
{				
	lcd	

} /* lcdSetInputShiftOff */

void lcdSetInputInc(void)
{

} /* lcdSetInputInc */

void lcdSetInputDec(void)

{

} /* lcdSetInputInc */

void lcdSetShifting(unsigned char mode)
{

} /* lcdSetShifting */
		
/*******************************************
lcdMakeRawFont()
Input:

 *******************************************/
 void lcdMakeRawFont(unsigned char c,unsigned char row0, 
									 unsigned char row1, 
									 unsigned char row2, 
									 unsigned char row3, 
									 unsigned char row4,
									 unsigned char row5,
									 unsigned char row6,
									 unsigned char row7)
{
	unsigned char cgAddr =8*c;

	lcdWriteCmd(0x40| cgAddr);		 
	lcdWriteData(row0);

	lcdWriteCmd(0x40|(cgAddr+1));
	lcdWriteData(row1);

	lcdWriteCmd(0x40|(cgAddr+2));
	lcdWriteData(row2);
	
	lcdWriteCmd(0x40|(cgAddr+3));
	lcdWriteData(row3);

	lcdWriteCmd(0x40|(cgAddr+4));
	lcdWriteData(row4);

	lcdWriteCmd(0x40|(cgAddr+5));
	lcdWriteData(row5);

	lcdWriteCmd(0x40|(cgAddr+6));
	lcdWriteData(row6);

	lcdWriteCmd(0x40|(cgAddr+7));
	lcdWriteData(row7);

} /* lcdMakeRawFont */
