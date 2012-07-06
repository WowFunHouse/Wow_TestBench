/***************************************************************************
LCD Testing

Version:		7.0
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

void lcdWriteString(char *str)
{
	unsigned char	n;	

	for (n=0; *(str+n)!=0; n++)
	{
		lcdWriteData( *(str+n) );
	}

}/* lcdWriteString */

//void zlcdSelectRow(unsigned char row)					// 0: First Line, 1: Senced Line
//{
//	if (row == 0)
//	{
//		lcdWriteCmd(0x80 | 0x00);
//	}
//	else
//	{
//		lcdWriteCmd(0x80 | 0x40);
//	}
//
//}/* lcdSelectRow */
//
//void zzlcdSelectRow(unsigned char row)					// 0: First Line, 1: Senced Line
//{
//	switch (row)
//	{
//		case 0:		lcdWriteCmd(0x80 | 0x00);
//					break;
//
//		case 1:		lcdWriteCmd(0x80 | 0x40);
//					break;
//	}		
//}/* lcdSelectRow */
//
//void zzzlcdSelectRow(unsigned char row)					// 0: First Line, 1: Senced Line
//{
//	unsigned char	n;
//
//	switch (row)
//	{
//		case 0:		n = 0x00;
//					break;
//
//		case 1:		n = 0x40;
//					break;
//
//		default:	n = 0x00;
//					break;
//	}
//	lcdWriteCmd(0x80 | n);
//			
//}/* lcdSelectRow */

void lcdSelectRow(unsigned char row)					// 0: First Line, 1: Senced Line
{
	unsigned char	n;	

	if (row == 1)		n = 0x40;
	else				n = 0x00;

	lcdWriteCmd(0x80 | n);

}/* lcdSelectRow */

void lcdClearRow(unsigned char row)			// 0: Clear first line, 1: Clear senced line	
{
	unsigned char	n, t; 

	if (row == 1)		n = 0x40;
	else				n = 0x00;

	lcdWriteCmd(0x80 | n);					// Set the cursor the beginning of line

	for (t=0; t<40; t++)
	{	
		lcdWriteData(' ');					// Fill whole line with Spaces
	}

	lcdWriteCmd(0x80 | n);					// Move cursor back to beginning of line

}/* lcdClearRow */

void main(void)
{
//	char msgA[] = {0x49, 0x20, 0x4C, 0x6F, 0x76, 0x65, 0x20, 0x38, 0x30, 0x35, 0x31, 0};
//	
//	char msgB[] = {'I', ' ', 'L', 'o', 'v', 'e', ' ', '8', '0', '5', '1', 0};
//	
	char msgA[] = "I Love 8051 Wow! Wow!";
	
	char msgB[] = "Hello World!"; 

	lcdClear();
	
	lcdWriteCmd(0x0C);						// Display: ON, Cursor: OFF, Blink: OFF
	lcdWriteCmd(0x38);						// 8-bit, 2 lines, 5x7 font
	lcdWriteCmd(0x06);						// Input mode: Increment, No-shift

// 	lcdWriteString(msgA);
//	for (;;)
//	{
//		lcdWriteCmd(0x1C); 						// Shift mode: Display shift, left shift
//		delay(50000);
//		lcdWriteCmd(0x1C); 						// Shift mode: Display shift, left shift
//		delay(50000);
//		lcdWriteCmd(0x1C); 						// Shift mode: Display shift, left shift
//		delay(50000);
//
//		lcdWriteCmd(0x18); 						// Shift mode: Display shift, right shift
//		delay(50000);
//		lcdWriteCmd(0x18); 						// Shift mode: Display shift, right shift
//		delay(50000);
//		lcdWriteCmd(0x18); 						// Shift mode: Display shift, right shift
//		delay(50000);
//	}

	lcdWriteString(msgA);
	lcdSelectRow(1);
	lcdWriteString(msgB);
	delay(60000);

	for (;;)
	{
		lcdClearRow(0);
		lcdWriteString(msgB);

		lcdClearRow(1);
		lcdWriteString(msgA);
		delay(60000);

		lcdClearRow(0);
		lcdWriteString(msgA);

		lcdClearRow(1);
		lcdWriteString(msgB);
		delay(60000);
	}

//	lcdWriteCmd(0x80 | 0x40);

//	for (n=0; *(msgD+n)!=0; n++)
//	{
//		lcdWriteData( *(msgD+n) );
//	}

//	for (n=0; msgD[n]!=0; n++)
//	{
//		lcdWriteData( msgD[n] );
//	}

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

//	for (;;);
}/* main */