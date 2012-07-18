/****************************************************************************
 File:			lcd_lib001.c

 LCD Driver Library

 Version:		0.01
 Description:	LCD 1602 Driver


 Created on:	2012-07-18
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

				�� JPSMG ����ܿ������߰ε�ʹ�����ֹͣ������
 				�� JPP0 ���߶˵�����ñ�ε��������1602 Һ����ʾ
				����1602LCDҺ��
				�� JPBG Һ���������߲���
****************************************************************************/
#include <STC89.H>
#include "lib_uty001.h"
#include "hw_rz51v2.h"
#include "hw_lcd1602.h"
#include "lcd_lib001.h"

#define DELAYSHORT	10

unsigned char	lcdCurrentModeInput;			// Use to memorize the current status of Input Mode
unsigned char	lcdCurrentModeDisplay;		  	// Use to memorize the current status of Display Mode
unsigned char	lcdCurrentModeShifting;			// Use to memorize the current stauts of Shifting
unsigned char	lcdCurrentModeFunction;			// Use to memorize the current status of # of Lines & Fonts

unsigned char lcdCheckBusy(void)
{
	unsigned char bf;

	BF = 1;					// Set Pin ready for Input

	EN = 0;					// Ready to create a transition of EN: Low->High
	RS = 0;
	RW = 1;
	EN = 1;	
	delay(DELAYSHORT);		// Wait for the BF to be stable
	bf = BF;
	EN = 0;
	RS = 1;				// Optional to set it to RAM Select
	RW = 1;				// Optional to set it to READ

	return bf;

} /* lcdCheckBusy */

void lcdWaitUntilReady(void)
{
	while (lcdCheckBusy() == 1);

} /* lcdWaitUntilReady */

void lcdWriteCmd(unsigned char cmd)
{
	lcdWaitUntilReady();
	
	EN = 0;					// Ready to create a transition of EN: Low->High
	RS = 0;
	RW = 0;
	DATAPORT = cmd;
	delay(DELAYSHORT);		// Optional - wait for data stable
	EN = 1;
	delay(DELAYSHORT);		// Wait for LCD to complete the read cycle		
	EN = 0;
	RS = 1;
	RW = 1;

} /* lcdWriteCmd */

void lcdWriteData(unsigned char dData)
{
	lcdWaitUntilReady();

	EN = 0;					// Ready to create a transition of EN: Low->High
	RS = 1;
	RW = 0;
	DATAPORT = dData;
	delay(DELAYSHORT);		// Optional - wait for data stable
	EN = 1;
	delay(DELAYSHORT);		// Wait for LCD to complete the read cycle	
	EN = 0;
	RS = 1;
	RW = 1;
	
} /* lcdWriteData */

void lcdWriteString(char *str)
{
	unsigned int n;

	for (n=0; *(str+n)!=0; n++)
	{
		lcdWriteData(*(str+n));
	}

} /* lcdWriteString */

void lcdSetDisplay(unsigned char mode)
{
	lcdCurrentModeDisplay = mode;

	lcdWriteCmd(LCD_CMD_SET_DISPLAY | lcdCurrentModeDisplay);

} /* lcdSetDisplay */
	
void lcdSetInput(unsigned char mode)
{
	lcdCurrentModeInput = mode;

	lcdWriteCmd(LCD_CMD_SET_INPUT | lcdCurrentModeInput);

} /* lcdSetInput */

void lcdSelectRow(unsigned char row)	// Row#1:0, Row#2:1
{
	if (row == 0)
	{
		lcdWriteCmd(LCD_CMD_SET_DDRAM); 			// Row #1
	}
	else
	{
		lcdWriteCmd(LCD_CMD_SET_DDRAM | 0x40); 		//  Row #2
	}

} /* lcdSelectRow */

void lcdClearRow(unsigned char row)
{
	unsigned char n;
	unsigned char currentModeInput;
	
	currentModeInput = lcdCurrentModeInput;

	lcdSetInputInc();

	lcdSelectRow(row);

	for (n=0; n<40; n++)
	{
		lcdWriteData(' ');
	}

	lcdSetInput(currentModeInput);

	lcdSelectRow(row);

} /* lcdClearRow */

void lcdClearScreen(void)
{
	lcdWriteCmd(LCD_CMD_CLEAR_SCREEN);			// Clear LCD Screen

} /* lcdClear */

void lcdInit(void)
{
	lcdCurrentModeFunction = LCD_FUNC_2LINES;		// 8-bit, 2lines, font:5x7

	lcdWriteCmd(LCD_CMD_SET_FUNCTION | LCD_FUNC_DL8 | 
				lcdCurrentModeFunction);

} /* lcdInit */

void lcdSetInputShiftOn(void)
{
	lcdCurrentModeInput |= LCD_INPUT_SHIFT_ON;

	lcdWriteCmd(LCD_CMD_SET_INPUT | lcdCurrentModeInput);

} /* lcdSetInputShiftOn */

void lcdSetInputShiftOff(void)
{
	lcdCurrentModeInput &= ~LCD_INPUT_SHIFT_ON;

	lcdWriteCmd(LCD_CMD_SET_INPUT | lcdCurrentModeInput);
		
} /* lcdSetInputShiftOff */

void lcdSetInputInc(void)
{
	lcdCurrentModeInput |= LCD_INPUT_INC;

	lcdWriteCmd(LCD_CMD_SET_INPUT | lcdCurrentModeInput);

} /* lcdSetInputInc */

void lcdSetInputDec(void)
{	
	lcdCurrentModeInput &= ~LCD_INPUT_INC;

	lcdWriteCmd(LCD_CMD_SET_INPUT | lcdCurrentModeInput);

} /*  lcdSetInputDec */

/***************************************************
 lcdMakeRawFont() - Use this to create a new font
 Input:
	c: character code (0 - 7)
	row0-row7: dotmatrix rows from top to bottom
			   valid bits b0 - b4 from right to left
 Output: 0:Ok 1:Error
 ***************************************************/
unsigned char lcdMakeRawFont(unsigned char c, unsigned char row0,
									 unsigned char row1, 
									 unsigned char row2, 
									 unsigned char row3, 
									 unsigned char row4,
									 unsigned char row5,
									 unsigned char row6,
									 unsigned char row7)
{																 
	unsigned char	cgAddr;
	unsigned char	error;
	
	if (c > LCD_USRCHAR_CNT)
	{
		error = 1;
	}
	else
	{
		cgAddr = c * LCD_USRCHAR_SIZE;							   
	
		lcdWriteCmd(LCD_CMD_SET_CGRAM |  cgAddr);
		lcdWriteData(row0);
	
		lcdWriteCmd(LCD_CMD_SET_CGRAM | (cgAddr+1));
		lcdWriteData(row1);
	
		lcdWriteCmd(LCD_CMD_SET_CGRAM | (cgAddr+2));
		lcdWriteData(row2);
	
		lcdWriteCmd(LCD_CMD_SET_CGRAM | (cgAddr+3));
		lcdWriteData(row3);
	
		lcdWriteCmd(LCD_CMD_SET_CGRAM | (cgAddr+4));
		lcdWriteData(row4);
	
		lcdWriteCmd(LCD_CMD_SET_CGRAM | (cgAddr+5));
		lcdWriteData(row5);
	
		lcdWriteCmd(LCD_CMD_SET_CGRAM | (cgAddr+6));
		lcdWriteData(row6);
	
		lcdWriteCmd(LCD_CMD_SET_CGRAM | (cgAddr+7));
		lcdWriteData(row7);

		error = 0;
	}


	return error;

} /* lcdMakeRawFont */

/*****************************************************
 lcdMakeFont() - Use this to create a new font
 Input:
	c: character code (0 - 7)
	*row: dotmatrix rows (8 rows) from top to bottom
		  valid bits b0 - b4 from right to left
 Output: status - 1:OK, 0: fail
 *****************************************************/
unsigned char lcdMakeFont(unsigned char c, char *row)
{
	unsigned char	cgAddr;
	unsigned char	error;
	unsigned char	n;

	if (c > LCD_USRCHAR_CNT)
	{
		error = 1;
	}
	else
	{
		cgAddr = c * LCD_USRCHAR_SIZE;
	
		for (n=0; n<LCD_USRCHAR_SIZE; n++)
		{
			lcdWriteCmd(LCD_CMD_SET_CGRAM | cgAddr + n);
			lcdWriteData(row[n]);
		}
		error = 0;
	}
	return error;
	
} /* lcdMakeFont */
															 


