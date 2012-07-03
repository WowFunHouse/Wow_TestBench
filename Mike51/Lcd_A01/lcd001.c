/****************************************************
 LCD Testing

 Version:		1.0
 Description:	To show a string on LCD display

 Created on:	2012-07-02
 Created by:	Michael

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
************************************************/
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

	RS = 0;
	RW = 1;
	EN = 0;					// Ready to create a transition of EN: Low->High
	EN = 1;	
	delay(DELAYSHORT);		// Wait for the BF to be stable
	bf = BF;
	EN = 0;
	RS = 1;

	return bf;
} /* lcdCheckBusy */

void lcdWaitUntilReady(void)
{
	while (lcdCheckBusy() == 1);

} /* lcdWaitUntilReady */

void lcdWriteCmd(unsigned char cmd)
{
	lcdWaitUntilReady();
	RS = 0;
	RW = 0;
	EN = 0;					// Ready to create a transition of EN: Low->High
	DATAPORT = cmd;
	delay(DELAYSHORT);
	EN = 1;
	delay(DELAYSHORT);		// Wait for LCD to complete the read cycle		
	EN = 0;
	RW = 1;

} /* lcdWriteCmd */

void lcdWriteData(unsigned char dData)
{
	lcdWaitUntilReady();
	RS = 1;
	RW = 0;
	EN = 0;					// Ready to create a transition of EN: Low->High
	DATAPORT = dData;
	EN = 1;
	delay(DELAYSHORT);		// Wait for LCD to complete the read cycle	
	EN = 0;
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
	lcdWriteData(0x49);		// 'I'
	lcdWriteData(0x20);		// ' '
	lcdWriteData(0x4c);		// 'L'
	lcdWriteData(0x6f);		// 'o'
	lcdWriteData(0x76);		// 'v'
	lcdWriteData(0x65);		// 'e'
	lcdWriteData(0x20);		// ' '
	lcdWriteData(0x38);		// '8'
	lcdWriteData(0x30);		// '0'
	lcdWriteData(0x35);		// '5'
	lcdWriteData(0x31);		// '1'

	for (;;);
} /* main */
