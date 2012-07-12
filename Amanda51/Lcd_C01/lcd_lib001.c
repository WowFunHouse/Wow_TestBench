/****************************************************************************
 LCD Driver Library Header Files

 Version:		0.02
 Description:	LCD 1602 Driver Header	

 Creared on:	2012-07-12		
 Creared by:	Amanda Li

 Board:			Richmcu RZ-51/AVR 2.0

 Conmnection:	LCD pins as below - 
				RS			P20
				RW			P21
				EN			P22
				DATAPORT	P0

 Jumpers:		Remove JPSMG - Disable 7-Segment LEDs
				Remove JPP0	 - Disable LEDs
				Add JPBG	 - Enable LCD Back Light

 V0.02			Make font in 1602 LCD				
 ****************************************************************************/
#include "lcd_lib001.h"

#define DELAYSHORT	10

unsigned char lcdCheckBusy(void)
{
	unsigned char	bf;
	
	BF = 1;										// Set Pin ready for Input

	EN = 0;										// Ready to create a transition of EN: Low -> High
	RS = 0;
	RW = 1;	
	EN = 1;
	delay(DELAYSHORT);							// Wait for the BF to be stable	

	bf = BF;

	EN = 0;
	RW = 0;										// Optional to set it to READ
	RS = 1;										// Optional to set it to RAM Select

	return	bf;

}/* lcdCheckBusy */

void lcdWaitUntilReady(void)
{
	while (lcdCheckBusy() == 1);

}/* lcdWaitUntilReady */

void lcdWriteCmd(unsigned char cmd)
{
	lcdWaitUntilReady();	

	EN = 0;										// Ready to create a transition of EN: Low -> High
	RS = 0;
	RW = 0;

	DATAPORT = cmd;
	delay(DELAYSHORT);							// Optional - wait for data stable

	EN = 1;
	delay(DELAYSHORT);							// Wait for LCD to complete the read cycle

	EN = 0;
	RW = 1;
	RS = 1;

}/* lcdWriteCmd */

void lcdWriteData(unsigned char dData)
{
	lcdWaitUntilReady();	

	EN = 0;										// Ready to create a transition of EN: Low -> High
	RS = 1;
	RW = 0;

	DATAPORT = dData;
	delay(DELAYSHORT);							// Optional - wait for data stable

	EN = 1;
	delay(DELAYSHORT);							// Wait for LCD to complete the read cycle

	EN = 0;
	RW = 1;
	RS = 0;
		
}/* lcdWriteData */

void lcdWriteString(char *str)
{
	unsigned char	n;	

	for (n=0; *(str+n)!=0; n++)
	{

		lcdWriteData( *(str+n) );
	}

}/* lcdWriteString */

void lcdSelectRow(unsigned char row)					// 0: First Line, 1: Senced Line
{
	unsigned char	n;	

	if (row == 1)		n = 0x40;
	else				n = 0x00;

	lcdWriteCmd(0x80 | n);

}/* lcdSelectRow */

void lcdClearScreen(void)
{
	lcdWaitUntilReady();
	lcdWriteCmd(0x01); 							// Clear LCD Screen

}/* lcdClearScreen */

void lcdInit(void)
{
	lcdWriteCmd(0x30 | LCD_STYLE_2LINES | LCD_STYLE_FONT5x7);				// 8-bit, 2 lines, 5x7 font

}/* lcdInit */

void lcdInitDisplayMode(unsigned char display_mode)
{
	lcdWriteCmd(0x08 | display_mode);

}/* lcdInitDisplayMode */ 

void lcdSetInputMode(unsigned char input_mode, unsigned char input_shift)
{
	 lcdWriteCmd(0x04 | input_mode | input_shift);

}/* lcdSetInputMode */

void lcdMakeRawFont(unsigned char c, unsigned char row0,
									 unsigned char row1,
									 unsigned char row2,
									 unsigned char row3,
									 unsigned char row4,
									 unsigned char row5,
									 unsigned char row6,
									 unsigned char row7)
{
	unsigned char	cgAddr = 8*c;
	
	lcdWriteCmd(0x40 | cgAddr++);
	lcdWriteData(row0);	
	lcdWriteCmd(0x40 | (cgAddr+1));
	lcdWriteData(row1);	
	lcdWriteCmd(0x40 | (cgAddr+2));
	lcdWriteData(row2);	
	lcdWriteCmd(0x40 | (cgAddr+3));
	lcdWriteData(row3);	
	lcdWriteCmd(0x40 | (cgAddr+4));
	lcdWriteData(row4);
	lcdWriteCmd(0x40 | (cgAddr+5));
	lcdWriteData(row5);	
	lcdWriteCmd(0x40 | (cgAddr+6));
	lcdWriteData(row6);	
	lcdWriteCmd(0x40 | (cgAddr+7));
	lcdWriteData(row7);		

} /* lcdMakeRawFont */

void lcdMakeFont(unsigned char c, unsigned char *row)
{
	unsigned char cgAddr = 8*c;
	unsigned char n;

	for (n=0; n<8; n++)
	{
		lcdWriteCmd(0x40 | (cgAddr + n));
		lcdWriteData( row[n] );
	}

} /* lcdMakeFont */