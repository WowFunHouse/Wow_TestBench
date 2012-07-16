/****************************************************************************
 LCD Driver Library

 Version:		1.0
 Description:	LCD 1602 Driver

 Created on:		2012-07-09
 Created by:		Cathy

 Hardware:			RichMCU RZ-51V2.0

 Connections:		LCD pins as below-
 					P20 -> RS
 					P21 -> RW
					P22 -> EN
					P0  -> DATAPORT
					P07 -> BF

 Jumpers:			Remove JPSMS - Disble 7-Segment LEDs
 					Romove JPPO  - Disabled LEDs
					Add JPBG     - Enable LCD Back Light

 Jumpers:			JPP0 ���߶˵�����ñ�ε��������1602Һ����ʾ
					JPSMG ����ܿ������߰ε�ʹ�����ֹͣ������
					JPBG Һ���������߲���
					����1602LCDҺ��
 ****************************************************************************/
#include <STC89.H>
#include "lib_uty001.h"
#include "hw_rz51v2.h"
#include "lcd_lib001.h"

#define DELAYSHORT  100

unsigned char lcdCurrentModeFunction;			// Use to memorize the current status of # of Lines & Fonts
unsigned char lcdCurrentModeInput;			// Use to memorize the current status of Input Mode
unsigned char lcdCurrentModeDisplay;		  	// Use to memorize the current status of Display Mode
unsigned char lcdCurrentModeShifting;			// Use to memorize the current stauts of Shifting

unsigned char lcdCheckBusy(void)
{
	unsigned char bf;

	DATAPORT = 0xFF;					// Set port ready for Input
	BF = 1;   							// Set Pin ready for Input

	EN = 0;  							// Ready to create a transition of EN: Low->High
	RS = 0;
	RW = 1;
	EN = 1;
	delay(DELAYSHORT);				    // Wait for the BF to be stable
	bf = BF;
	EN = 0;
	RS = 1;				// Optional to set it to RAM Select
	RW = 1;				// Optional to set it to READ

	return bf;
			
} /* lcdCheckBusy */

void lcdWaitUntilReady(void) 
{
	while (lcdCheckBusy()== 1);

} /* lcdWaitUntilReady */

void lcdWriteCmd(unsigned char cmd)
{
	lcdWaitUntilReady();

    EN = 0;								 // Ready to create a transition of EN: Low->High
	RS = 0;
	RW = 0;
	DATAPORT = cmd;
	delay(DELAYSHORT);					 // Optional - wait for data stable
	EN = 1;
	delay(DELAYSHORT);					 // Wait for LCD to complete the read cycle
	EN = 0;
	RS = 1;
	RW = 1;

} /* lcdWriteCmd */

void lcdWriteData(unsigned char dData)
{
	lcdWaitUntilReady();

	EN = 0;
	RS = 1;
	RW = 0;
	DATAPORT = dData;
	delay(DELAYSHORT);
	EN = 1;
	delay(DELAYSHORT);
	EN = 0;
	RS = 1;
	RW = 1;

} /* lcdWriteData */

void lcdClearScreen(void)
{
	lcdWriteCmd(0x01);
			
} /* lcdClearScreen */

void lcdWriteString(char *str)
{
 	unsigned int n;

	for (n=0; *(str+n)!=0; n++)
	{
		lcdWriteData(*(str+n));
	}
} /* lcdWriteString */

void lcdSelectRow(unsigned char row)  	// Row#1:0, Row#2:1
{
	if(row == 0)
	{
		lcdWriteCmd(0x80 | 0x00);	
	}
	else					   			// Row #1 (!= 0)
	{
		lcdWriteCmd(0x80 | 0x40);		// Row #2 (0xC0)
	}
		
} /* lcdSelectRow */

void lcdClearRow(unsigned char row)
{
	unsigned char n;
	unsigned char currentModeInput;

	currentModeInput = lcdCurrentModeInput;

	lcdSetInputMode(LCD_INPUT_INC | LCD_INPUT_SHIFT_OFF);

	lcdSelectRow(row);  

	for (n=0; n<40; n++)
	{
		lcdWriteData(' ');
	}
	
	lcdSetInputMode(currentModeInput);

	lcdSelectRow(row);

} /* lcdClearRow */

void lcdInit(void)
{
	lcdCurrentModeFunction = LCD_STYLE_2LINES | LCD_STYLE_FONT5X7;	  //8-bit, 2Line, font:5x7  
	lcdWriteCmd(0x30 | lcdCurrentModeFunction);    

} /* lcdInit */

void lcdSetDisplayMode(unsigned char mode)
{
	lcdCurrentModeDisplay = mode;

 	lcdWriteCmd(0x08 | lcdCurrentModeDisplay);
}

void lcdSetInputMode(unsigned char mode)
{
	lcdCurrentModeInput = mode;

	lcdWriteCmd(0x04 | lcdCurrentModeInput);

} /* lcdSetInputMode */

void lcdSetShiftMode(unsigned char mode)
{
	lcdCurrentModeShifting = mode;

	lcdWriteCmd(0x10 | lcdCurrentModeShifting);

} /* lcdSetShiftMode */

/******************************************************
lcdMakeRawFont() - Use thisto create a new font
Input:
	c: chraacter code (0-7)
	row0 - row7: dotmatrix rows from top to bottom 
				 valid bits b0 - b4 from right to left
Output: N/A
 ******************************************************/
void lcdMakeRawFont(unsigned char c, unsigned char row0, 
									 unsigned char row1,
									 unsigned char row2,
									 unsigned char row3,
									 unsigned char row4,
									 unsigned char row5,
									 unsigned char row6,
									 unsigned char row7)
{
	unsigned char cgAddr = 8*c;

	lcdWriteCmd(0x40| cgAddr);
	lcdWriteData(row0);

	lcdWriteCmd(0x40| cgAddr+1);
	lcdWriteData(row1);

	lcdWriteCmd(0x40| cgAddr+2);
	lcdWriteData(row2);

	lcdWriteCmd(0x40| cgAddr+3);
	lcdWriteData(row3);

	lcdWriteCmd(0x40| cgAddr+4);
	lcdWriteData(row4);

	lcdWriteCmd(0x40| cgAddr+5);
	lcdWriteData(row5);

	lcdWriteCmd(0x40| cgAddr+6);
	lcdWriteData(row6);

	lcdWriteCmd(0x40| cgAddr+7);
	lcdWriteData(row7);

} /* lcdMakeRawFont */

/***************************************************
lcdMakeRawFont() - Use thisto create a new font
Input:
	c: chraacter code (0-7)
	*row: dotmatrix rows (8 rows) from top to bottom
		  valid bits b0 - b4 from right to left
Output: N/A
 **************************************************/

void lcdMakeFont(unsigned char c,  char *row)
{
	unsigned char cgAddr;
	unsigned char n;
	
	cgAddr = 8*c;

	for (n=0; n<8; n++)
	{
		lcdWriteCmd(0x40 | cgAddr + n );
		lcdWriteData(row[n]);
	}
} /* lcdMakeFont */


