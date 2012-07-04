/***************************************************************************
LCD Testing

Version:		3.0
Description:	To Show a string on LCD display

Creared on:		Amanda Li
Creared by:		2012-07-04

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
*****************************************************************************/
#include <STC89.H>

#define RS			P20
#define RW			P21
#define EN			P22

#define DATAPORT	P0
#define BF			P07

#define DELAYSHORT	10

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

void main(void)
{
	char msgA[] = {0x49, 0x20, 0x4C, 0x6F, 0x76, 0x65, 0x20, 0x38, 0x30, 0x35, 0x31, 0};
	
	char msgB[] = {'I', ' ', 'L', 'o', 'v', 'e', ' ', '8', '0', '5', '1', 0};
	
	char msgC[] = "I Love 8051";
	
	char msgD[] = "Hello World!"; 

	unsigned char	n;

	lcdClear();
	
	lcdWriteCmd(0x0F);						// Display: ON, Cursor: ON, Blink: ON
	lcdWriteCmd(0x38);						// 8-bit, 2 lines, 5x7 font
	lcdWriteCmd(0x06);						// Input mode: Increment, Non-shift

	for (n=0; msgD[n]!=0; n++)
	{
		lcdWriteData( msgD[n] );
	}

//	for (n=0; n<11; n++)
//	{
//		lcdWriteData( msgB[n] );
//	}

//	lcdWriteData('I');
//	lcdWriteData(' ');
//	lcdWriteData('L');
//	lcdWriteData('o');
//	lcdWriteData('v');
//	lcdWriteData('e');
//	lcdWriteData(' ');
//	lcdWriteData('8');
//	lcdWriteData('0');
//	lcdWriteData('5');
//	lcdWriteData('1');
//
//	lcdWriteData(0x7E);
//	lcdWriteData(0xF6);
//	lcdWriteData('3');
//	lcdWriteData(0xFA);
//	lcdWriteData(0xFB);

//	lcdWriteData(0x49);						// " I "
//	lcdWriteData(0x20);						// "   "
//	lcdWriteData(0x4C);						// " L "
//	lcdWriteData(0x6F);						// " o "
//	lcdWriteData(0x76);						// " v "
//	lcdWriteData(0x65);						// " e "
//	lcdWriteData(0x20);						// "   "
//	lcdWriteData(0x38);						// " 8 "
//	lcdWriteData(0x30);						// " 0 "
//	lcdWriteData(0x35);						// " 5 "
//	lcdWriteData(0x31);						// " 1 "

	for (;;);
}/* main */