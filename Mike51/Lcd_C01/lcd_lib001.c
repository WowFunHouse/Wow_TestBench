/****************************************************************************
 LCD Driver Library

 Version:		0.01
 Description:	LCD 1602 Driver


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
#include <STC89.H>
#include "lib_uty001.h"
#include "hw_rz51v2.h"
#include "lcd_lib001.h"

#define DELAYSHORT	10

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

void lcdSelectRow(unsigned char row)	// Row#1:0, Row#2:1
{
	if (row == 0)
	{
		lcdWriteCmd(0x80); 				// Row #1
	}
	else
	{
		lcdWriteCmd(0x80 | 0x40); 		//  Row #2
	}

} /* lcdSelectRow */

void lcdClearScreen(void)
{
	lcdWriteCmd(0x1);			// Clear LCD Screen

} /* lcdClear */

void lcdInit(void)
{
	lcdWriteCmd(0x30 | LCD_STYLE_2LINES | LCD_STYLE_FONT5X7);	// 8-bit, 2lines, font:5x7

} /* lcdInit */

void lcdSetDisplayMode(unsigned display_mode)
{
	lcdWriteCmd(0x08 | display_mode);

} /* lcdSetDisplayMode */

void lcdSetInputMode(unsigned char input_mode, unsigned char input_shift)
{
	lcdWriteCmd(0x04 | input_mode | input_shift);

} /* lcdSetInputMode */
