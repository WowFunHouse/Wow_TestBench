/*****************************************************
 LCD Testing
 Version:      		2.0
 Created on:		2012-07-02
 Created by:		Cathy
 Hardware:			RichMCU RZ-51
 Connections:		P20 -> RS
 					P21 -> RW
					P22 -> EN
					P0  -> DATAPORT
					P07 -> BF

 Jumpers:			Remove JPSMS - Disble 7-Segment LEDs
 					Romove JPPO  - Disabled LEDs
					Add JPBG     - Enable LCD Back Light

 Jumpers:			JPP0 跳线端的跳线帽拔掉以免干扰1602液晶显示
					JPSMG 数码管控制跳线拔掉使数码管停止工作。
					JPBG 液晶背光跳线插上
					插上1602LCD液晶
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

}/*delay*/

unsigned char lcdCheckBusy (void)
{
	unsigned char bf;
	DATAPORT = 0xFF;
	BF = 1;   							//Set Pin ready for Input
	EN = 0;  						
	RS = 0;
	RW = 1;
	EN = 1;
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

void main (void)
{
	lcdClear();

	lcdWriteCmd(0x0F);				//	Display:On Cursor:On Blink:On
	lcdWriteCmd(0x38);				//	8-bit, 2lines,5x7 font
	lcdWriteCmd(0x06);				//	Input mode; Increment, Non-shift
	lcdWriteData('I');				//	'I'
	lcdWriteData(' ');				//	' '
	lcdWriteData('L');				//	'L'
	lcdWriteData('v');			    //	'v'
	lcdWriteData('o');				//	'o'
	lcdWriteData('e');				//	'e'
	lcdWriteData(' ');				//	' '
	lcdWriteData('8');			   	//	'8'
	lcdWriteData('0');			    //	'0'
	lcdWriteData('5');				//	'5'
	lcdWriteData('1');				//	'1'
	lcdWriteData(0x7e);				//	'->'
	lcdWriteData(0xf6);				//	'F6'
	lcdWriteData('3');				//	'3'
	lcdWriteData(0xfa);				//	'千'
	lcdWriteData(0xfb);				//	'万'


//	lcdWriteCmd(0x0F);				//	Display:On Cursor:On Blink:On
//	lcdWriteCmd(0x38);				//	8-bit, 2lines,5x7 font
//	lcdWriteCmd(0x06);				//	Input mode; Increment, Non-shift
//	lcdWriteData(0x49);				//	'I'
//	lcdWriteData(0x20);				//	' '
//	lcdWriteData(0x4C);				//	'L'
//	lcdWriteData(0x76);			    //	'v'
//	lcdWriteData(0x6F);				//	'o'
//	lcdWriteData(0x65);				//	'e'
//	lcdWriteData(0x20);				//	' '
//	lcdWriteData(0x38);			   	//	'8'
//	lcdWriteData(0x30);			    //	'0'
//	lcdWriteData(0x35);				//	'5'
//	lcdWriteData(0x31);				//	'1'
	for(;;);

}/* main */


