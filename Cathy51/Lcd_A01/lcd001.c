/*****************************************************
 LCD Testing
 Version:      		0.1
 Created on:		2012-07-02
 Created by:		Cathy
 Hardware:			RichMCU RZ-51
 Connections:		P20 -> RS
 					P21 -> RW
					P22 -> EN
					P0  -> DATAPORT
					P07 -> BF
 		
 *****************************************************/
#include <STC89.H>

#define RS P20
#define RW P21
#define EN P22
#define DATAPORT    P0
#define BF P07
#define DELAYSHORT  100

void delay(unsigned int delaycount)
{
	unsigned int t;
	for (t = 0; t < delaycount; t++);
}

unsigned char lcdCheckBusy (void)
{
	unsigned char bf;
	DATAPORT = 0xFF;

	RS =0;
	RW =1;
	EN =1;
	delay(DELAYSHORT);
	bf = BF;
	EN = 0;

	return bf;		
} /* lcdCheckBusy */

void lcdWaitUntilReady (void) 
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
} /*lcdWriteCmd*/

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
}/*lcdWriteData	*/

void lcdClear (void)
{
	lcdWriteCmd(0x01);		
}/*	lcdClear*/

void lcdInit (void)
{
	DATAPORT = 0xff;
}/*	lcdInit */

void main (void)
{
	lcdClear();
	lcdWriteCmd(0x0F);				//	Display:On Cursor:On Blink:On
	lcdWriteCmd(0x38);				//	8-bit, 2lines,5x7 font
	lcdWriteCmd(0x06);				//	Input mode; Increment, Non-shift
	lcdWriteData(0x49);				//	'I'
	lcdWriteData(0x20);
	lcdWriteData(0x4C);				//	'L'
	lcdWriteData(0x76);			    //	'v'
	lcdWriteData(0x6F);				//	'o'
	lcdWriteData(0x65);				//	'e'
}/* main */


