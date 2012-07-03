/****************************************************************************
 LCD Testing

 Version:		2.0
 Description:	To show a string on LCD display

 Created on:	2012-07-02
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

 V2.0:			Use string array instead of individual characters for output
****************************************************************************/
#include <STC89.H>

#define	RS			P20
#define	RW			P21
#define	EN			P22
#define BF			P07
#define DATAPORT	P0
#define DELAYSHORT	10

void delay(unsigned int delaycount)
{
	unsigned int t;

	for (t=0; t<delaycount; t++);

} /* delay */

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

void lcdClear(void)
{
	lcdWriteCmd(0x1);			// Clear LCD Screen

} /* lcdClear */

void main(void)
{
	lcdClear();

	lcdWriteCmd(0x0f);		// Display:On, Cursor:On, Blink:On
	lcdWriteCmd(0x38);		// 8-bit, 2 lines, 5x7 font
	lcdWriteCmd(0x06);		// Input mode: Increment, Non-shift

	lcdWriteData('I');
	lcdWriteData(' ');
	lcdWriteData('L');
	lcdWriteData('o');
	lcdWriteData('v');
	lcdWriteData('e');
	lcdWriteData(' ');
	lcdWriteData('8');
	lcdWriteData('0');
	lcdWriteData('5');
	lcdWriteData('1');
	lcdWriteData(0x7e);
	lcdWriteData(0xf6);
	lcdWriteData('3');
	lcdWriteData(0xfa);
	lcdWriteData(0xfb);

//	lcdWriteData(0x49);		// 'I'
//	lcdWriteData(0x20);		// ' '
//	lcdWriteData(0x4c);		// 'L'
//	lcdWriteData(0x6f);		// 'o'
//	lcdWriteData(0x76);		// 'v'
//	lcdWriteData(0x65);		// 'e'
//	lcdWriteData(0x20);		// ' '
//	lcdWriteData(0x38);		// '8'
//	lcdWriteData(0x30);		// '0'
//	lcdWriteData(0x35);		// '5'
//	lcdWriteData(0x31);		// '1'

	for (;;);

} /* main */
