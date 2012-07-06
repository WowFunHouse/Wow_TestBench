/******************************************************************
 LCD Testing

 Version:      		6.0
 Created on:		2012-07-05
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
 V5.0				Use a function to handle message string
 v6.0				Add Select Row
 ******************************************************************/
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

} /* lcdWriteCmd */

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

} /* lcdWriteData */

void lcdClear(void)
{
	lcdWriteCmd(0x01);
			
} /* lcdClear */

void lcdWriteString(char *str)
{
 	unsigned int n;

	for (n=0; *(str+n)!=0; n++)
	{
		lcdWriteData(*(str+n));
	}
} /* lcdWriteString */

void lcdSelectRow(unsigned char row)  	// row: 0, 1
{
	if(row == 0)
	{
		lcdWriteCmd(0x80 | 0x00);	
	}
	else					   			// row != 0
	{
		lcdWriteCmd(0x80 | 0x40);		//	0xC0
	}	
} /* lcdSelectRow */

void main(void)
{
	char msgA[]="I Love 8051";
	char msgB[]="Wow digital post";
		
	lcdClear();

	lcdWriteCmd(0x0F);					//	Display:On Cursor:On Blink:On
	lcdWriteCmd(0x38);					//	8-bit, 2lines,5x7 font
	lcdWriteCmd(0x06);					//	Input mode; Increment, Non-shift

	lcdSelectRow(0);
	lcdWriteString(msgA);
	lcdSelectRow(1);					
	lcdWriteString(msgB);
  
	for(;;);

} /* main */


