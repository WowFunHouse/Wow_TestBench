/***************************************************************************
 LCD Testing

 Version:		0.01
 Description:	To Show 2 lines on LCD display

 Creared on:	2012-07-11
 Creared by:	Amanda Li

 Board:			Richmcu RZ-51/AVR 2.0

 Conmnection:	LCD pins as below - 
				RS			P20
				RW			P21
				EN			P22
				DATAPORT	P0

 Jumpers:		Remove JPSMG - Disable 7-Segment LEDs
				Remove JPP0	 - Disable LEDs
				Add JPBG	 - Enable LCD Back Light
 ***************************************************************************/
#include <STC89.H>

#define	RS			P20
#define	RW			P21
#define	EN			P22

#define	BF			P07

#define	DPORT		P0
#define DELAYSHORT	10

void delay(unsigned int delaycount)
{
	unsigned int	t;

	for (t=0; t<delaycount; t++);

} /* delay */

unsigned char lcdCheckBusy(void)
{
	unsigned char	bf;

	EN = 0;									// Sure EN is relady to enable
	RS = 0;									// RS enable to CMD
	RW = 1;									// RW enable to Read
	EN = 1;									// EN enable
	delay(DELAYSHORT);						// Wait to relady input

	bf = BF;

	EN = 0;									// EN disable
	RW = 0;
	RS = 1;

	return	bf;

} /* lcdCheckBusy */

void lcdWaitUntilBusy(void)

void lcdWriteCmd(unsigned char cmd)
{
	EN = 0;									// Sure EN is relady to enable
	RS = 0;									// RS enable to CMD
	RW = 0;									// RW enable to Write
	
	DPORT = cmd;
	delay(DELAYSHORT);						// Wait to enable

	EN = 1;
	delay(DELAYSHORT);						// Wait to data relady

	EN = 0;									// EN disable
	RS = 1;
	RW = 1;

} /* lcdWriteCmd */

void lcdWriteData(unsigned char dData)

void lcdClearScreen(void)
{
} /* lcdClearScreen */

void main(void)
{
	for (;;)
	{
	}

}/* main */