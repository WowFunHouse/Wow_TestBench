/***************************************************************************
LCD Testing

Version:		7.1
Description:	To Show a string on LCD display

Creared on:		Amanda Li
Creared by:		2012-07-06

Board:			Richmcu RZ-51/AVR 2.0

Conmnection:	LCD pins as below - 
				RS			P20
				RW			P21
				EN			P22
				DATAPORT	P0

Jumpers:		Remove JPSMG - Disable 7-Segment LEDs
				Remove JPP0	 - Disable LEDs
				Add JPBG	 - Enable LCD Back Light

V3.0			Use array instead of individual characters for output
V4.0			Add a string pointer to handle string
V5.0			Use a string function to handle strings
V6.0			Use a funtion to select row
V7.0			Flashing the messages alternately between lines
V7.1			Clean up the test program hidden and optimization program			
*****************************************************************************/
#include <STC89.H>

#define RS			P20
#define RW			P21
#define EN			P22

#define DATAPORT	P0
#define BF			P07

#define LINE_FIRST	0
#define LINE_SECOND	1

#define DELAYSHORT	10
#define DELAYLONG	60000

void delay(unsigned int delaycount)
{
	unsigned int	t;

	for (t=0; t<delaycount; t++);
}/* delay */

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

void lcdClear(void)
{
	lcdWaitUntilReady();
	lcdWriteCmd(0x01); 							// Clear LCD Screen

}/* lcdClear */

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

	if (row == LINE_SECOND)		n = 0x40;
	else						n = 0x00;

	lcdWriteCmd(0x80 | n);

}/* lcdSelectRow */

void lcdClearRow(unsigned char row)			// 0: Clear first line, 1: Clear senced line	
{
	unsigned char	n, t; 

	if (row == LINE_SECOND)		n = 0x40;
	else						n = 0x00;

	lcdWriteCmd(0x80 | n);					// Set the cursor the beginning of line

	for (t=0; t<40; t++)
	{	
		lcdWriteData(' ');					// Fill whole line with Spaces
	}

	lcdWriteCmd(0x80 | n);					// Move cursor back to beginning of line

}/* lcdClearRow */

void main(void)
{
	char msgA[] = "I Love 8051 Wow! Wow!";
	
	char msgB[] = "Hello World!"; 

	lcdClear();
	
	lcdWriteCmd(0x0C);						// Display: ON, Cursor: OFF, Blink: OFF
	lcdWriteCmd(0x38);						// 8-bit, 2 lines, 5x7 font
	lcdWriteCmd(0x06);						// Input mode: Increment, No-shift

	lcdWriteString(msgA);
	lcdSelectRow(LINE_SECOND);
	lcdWriteString(msgB);
	delay(DELAYLONG);

	for (;;)
	{
		lcdClearRow(LINE_FIRST);
		lcdWriteString(msgB);

		lcdClearRow(LINE_SECOND);
		lcdWriteString(msgA);
		delay(DELAYLONG);

		lcdClearRow(LINE_FIRST);
		lcdWriteString(msgA);

		lcdClearRow(LINE_SECOND);
		lcdWriteString(msgB);
		delay(DELAYLONG);
	}
}/* main */