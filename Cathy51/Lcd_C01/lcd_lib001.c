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


unsigned char lcdCheckBusy(void)
{
	unsigned char bf;

	DATAPORT = 0xFF;					// Set port ready for Input

	BF = 1;   							// Set Pin ready for Input
	EN = 0;  						
	RS = 0;
	RW = 1;
	EN = 1;
	delay(DELAYSHORT);
	bf = BF;
	EN = 0;

	return bf;
			
} /* lcdCheckBusy */

void lcdWaitUntilReady(void) 
{
	while(lcdCheckBusy()== 1);

} /* lcdWaitUntilReady */

void lcdWriteCmd(unsigned char cmd)
{
	lcdWaitUntilReady();

	RS = 0;
	RW = 0;
	DATAPORT = cmd;
	delay(DELAYSHORT);
	EN = 1;
	delay(DELAYSHORT);
	EN = 0;
	RW = 1;

} /* lcdWriteCmd */

void lcdWriteData(unsigned char dData)
{
	lcdWaitUntilReady();

	RS = 1;
	RW = 0;
	EN = 0;
	DATAPORT = dData;
	delay(DELAYSHORT);
	EN = 1;
	delay(DELAYSHORT);
	EN = 0;
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

void lcdSelectRow(unsigned char row)  	// row: 0, 1
{
	if(row == 0)
	{
		lcdWriteCmd(0x80 | 0x00);	
	}
	else					   			// row != 0
	{
		lcdWriteCmd(0x80 | 0x40);		//	0xC0
	}
		
} /* lcdSelectRow */

void lcdInit(void)
{
	lcdWriteCmd(0x30 | LCD_STYLE_2LINES |LCD_STYLE_FONT5X7);    //8-bit,2Line, 5x7

}/* lcdInit */

void lcdSetDisplayMode(unsigned char display_mode)
{
 	lcdWriteCmd(0x08 | display_mode);
}

void lcdSetInputMode(unsigned char input_mode ,unsigned char input_shift)
{
	lcdWriteCmd(0x04 | input_mode |input_shift);
}


/***************************************************************************
lcdMakeRawFont() - Use thisto create a new font
Input:
	c: chraacter code (0-7)
	row0 - row7: dotmatrix colums from
****************************************************************************/
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
}

/***************************************************************************
lcdMakeRawFont() - Use thisto create a new font
Input:
	c: chraacter code (0-7)
	row0 - row7: dotmatrix colums from top to bottom
				 valid bits b0 - b4 from right to left
Output: N/A
****************************************************************************/

//void lcdMakeFont(unsigned char *row)
//{
//	for (n=0, n<8, n++)
//	{
//		lcdWritecmd(0x40|*row)
//
//	}
//}


