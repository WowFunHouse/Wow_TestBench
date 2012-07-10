/*********************************************************************
 LCD Testing

 Version:		6.0
 Description:	To show a string on LCD display

 Created on:	2012-07-06
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
 V4.0			Use a string fucnction to handle message
 V6.0			Try to show multi-rows of messages
 *********************************************************************/
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
	lcdWriteCmd(0x01);			   // Clear LCD screen

} /* lcdClear */

void lcdWriteString(char *str)
{
	unsigned int n;
	
	for (n=0; *(str+n)!=0; n++)
	{
		lcdWriteData(*(str+n));
	}
} /* lcdWriteString */

void lcdSelectRow(unsigned char row)
{
	if (row == 0)
	{
		lcdWriteCmd(0x80|0x00);
	}
	else if (row == 1)
	{
		lcdWriteCmd(0x80|0x40);
	}
} /* lcdSelectRow */


void main(void)
{
	char msg[]="My name Carol";	

	lcdClear();

	lcdWriteCmd(0x0F);
	lcdWriteCmd(0x38);			 //8 bit,2 lines, 5x7 font;
	lcdWriteCmd(0x06);

	lcdWriteString(msg);
	lcdSelectRow(1);
	lcdWriteString(msg);

	for (;;);

} /* main */











