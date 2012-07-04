/****************************************************
 LCD Testing

 Version:		3.0
 Description:	To show a string on LCD display

 Created on:	2012-07-04
 Created by:	Carol

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

 V3.0			Use array for the LCD message
************************************************/
#include <STC89.H>

#define RS 			P20
#define RW 			P21
#define	EN 			P22
#define DATAPORT 	P0
#define BF 			P07
#define DELAYSHORT	500

void delay(unsigned int delaycount)
{
	unsigned int t;
	
	for (t=0; t<delaycount; t++);

} /* delay */

unsigned char lcdCheckBusy(void)			   //1:busy,  0:poady;  
{
	unsigned char bf;
	
	DATAPORT=0xff;				// Set DATAPORT ready for input
	
	RS=0;
	RW=1;
	EN=1;				
	delay(DELAYSHORT);
	bf=BF;
	EN=0;
	RW=0;
	
	return bf;

} /* lcdCheckBusy */

void lcdWaitUntilReady(void)
{
	while (lcdCheckBusy()==1);

} /* lcdWaitUntilReady */

void lcdWriteCmd(unsigned char cmd)
{
	lcdWaitUntilReady();
	
	RS=0;
	RW=0;
	EN=0;
	DATAPORT=cmd;
	delay(DELAYSHORT);
	EN=1;
	delay(DELAYSHORT);
	EN=0;
	RW=1;

} /* lcdWriteCmd */

void lcdWriteData(unsigned char dData)
{
	lcdWaitUntilReady();
	
	RS=1;
	RW=0;
	EN=0;
	DATAPORT=dData;
	delay(DELAYSHORT);
	EN=1;
	delay(DELAYSHORT);
	EN=0;
	RW=1;

} /* lcdWriteData */

void lcdClear(void)
{
	lcdWaitUntilReady();
	lcdWriteCmd(0x01);			   // Clear LCD screen

} /* lcdClear */

void main(void)
{
	char msgA[]={0x49, 0x20, 0x4c, 0x6f, 0x76, 0x65, 0x20, 0x38, 0x30, 0x35, 0x31, 0};
	char msgB[]={'I', ' ', 'L', 'o', 'v', 'e', ' ', '8', '0', '5', '1', 0};
	char msgC[]="I love 8051";
	
	unsigned int n;
	
	lcdClear();
	lcdWriteCmd(0x0F);
	lcdWriteCmd(0x38);			 //8 bit,2 lines, 5x7 font;
	lcdWriteCmd(0x06);

	for (n=0; msgA[n]!=0; n++)
	{
	lcdWriteData(msgA[n]);
	}

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
//	lcdWriteData(0x33);
//	lcdWriteData(0xFA);
//	lcdWriteData(0xFB);
//	
//	lcdWriteData(0x49);
//	lcdWriteData(0x4c);
//	lcdWriteData(0x6f);
//	lcdWriteData(0x76);
//	lcdWriteData(0x65);
//	lcdWriteData(0x20);
//	lcdWriteData(0x38);
//	lcdWriteData(0x30);
//	lcdWriteData(0x35);
//	lcdWriteData(0x31);

	for (;;);

} /* main */











