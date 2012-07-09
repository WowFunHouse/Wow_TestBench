/*****************************************************
 LCD Testing

 Version:      		4.0
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

 V3.0				Use array for the LCD messages
 V4.0				Add a string pointer to handle string
 *****************************************************/
#include <STC89.H>

#define RS 			P20
#define RW 			P21
#define EN 			P22
#define DATAPORT    P0
#define BF 			P07
#define DELAYSHORT  100

void delay(unsigned int delaycount)
{
	unsigned int t;

	for (t = 0; t < delaycount; t++);

}/*delay*/

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

void lcdClear(void)
{
	lcdWriteCmd(0x01);
			
}/*	lcdClear*/

void main(void)
{
	char msgA[]={0x49, 0x20, 0x4C, 0x6F, 0x76, 0x65, 0x20, 0x38, 0x30, 0x35, 0x31, 0};
	char msgB[]={'I', ' ', 'L', 'o', 'v', 'e', ' ', '8', '0', '5', '1', 0};
	char msgC[]="I Love 8051";
	char msgD[]="Wow digital post";
			
	unsigned int n;

	lcdClear();

	lcdWriteCmd(0x0F);				//	Display:On Cursor:On Blink:On
	lcdWriteCmd(0x38);				//	8-bit, 2lines,5x7 font
	lcdWriteCmd(0x06);				//	Input mode; Increment, Non-shift
	
	for (n=0; *(msgD+n)!=0; n++)
	{
		lcdWriteData(*(msgD+n));
	}

//	lcdWriteCmd(0x0F);				//	Display:On Cursor:On Blink:On
//	lcdWriteCmd(0x38);				//	8-bit, 2lines,5x7 font
//	lcdWriteCmd(0x06);				//	Input mode; Increment, Non-shift
//	lcdWriteData(0x49);				//	'I'
//	lcdWriteData(0x20);				//	' '
//	lcdWriteData(0x4C);				//	'L'
//	lcdWriteData(0x6F);			    //	'o'
//	lcdWriteData(0x76);				//	'v'
//	lcdWriteData(0x65);				//	'e'
//	lcdWriteData(0x20);				//	' '
//	lcdWriteData(0x38);			   	//	'8'
//	lcdWriteData(0x30);			    //	'0'
//	lcdWriteData(0x35);				//	'5'
//	lcdWriteData(0x31);				//	'1'

	for(;;);

} /* main */


