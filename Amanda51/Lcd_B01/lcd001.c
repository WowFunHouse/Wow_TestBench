/**********************************************************
LCD Testing

Version:		0.1
Description:	To show a string on LCD display	

Created on:		Amanda Li
Created by:		2012-07-05

Hardware:		RichMCU RZ-51

Jumpers:		Remove JPSMG - Disable 7-Segment LEDs
				Remove JPP0	 - Disable LEDs
				Add JPBG	 - Enable LCD Back Light

Connection:		RS			->	P20		" 0 " -> 指令, " 1 " -> 数据
				RW			->	P21		" 0 " -> 写入, " 1 " -> 读出
				EN			->	P22		使能信号
				BF			->	P07		Busy Flag
				Data Poit	->	P0		数据线地址
**********************************************************/
#include <STC89.H>

#define RS			P20
#define RW			P21
#define EN			P22
#define BF			P07
#define DATAPOINT	P0

#define DELAYSHORT	100

void delay(unsigned int DELAYTIME)
{
	unsigned int	t;

	for (t=0; t<DELAYTIME; t++);

}/* delay */

unsigned char lcdCheckBusy(void) 					// 1: Busy, 0: Free
{
	unsigned char	bf;

	BF = 1;											// Busy flay ready to input

	EN = 0;											// Sure enable ready to input
	RS = 0;
	RW = 1;
	EN = 1;
	delay(DELAYSHORT);							   // Wait for ready

	bf = BF;

	EN = 0;
	RW = 0;
	RS = 1;

	return	bf;

}/* lcdCheckBusy */

void lcdUntilReady(void)
{
	for (; lcdCheckBusy() == 1; );				// Until busy flag free

}/* lcdUntilReady */

void lcdWriteCmd(unsigned char cmd)
{
	lcdUntilReady();
	
	EN = 0;											// Sure enable ready to input
	RS = 0;
	RW = 0;

	DATAPOINT = cmd;
	delay(DELAYSHORT);							   // Wait for ready

	EN = 1;
	delay(DELAYSHORT);							   // Wait for ready

	EN = 0;
	RW = 1;
	RS = 0;

}/* lcdWriteCmd */

void lcdWriteData(unsigned char dData)
{
	lcdUntilReady();
	
	EN = 0;											// Sure enable ready to input
	RS = 1;
	RW = 0;

	DATAPOINT = dData;
	delay(DELAYSHORT);							   // Wait for ready

	EN = 1;
	delay(DELAYSHORT);							   // Wait for ready

	EN = 0;
	RW = 1;
	RS = 0;

}/* lcdWriteData */

void lcdCleanScreen(void)
{
	lcdUntilReady();
	lcdWriteCmd(0x01);

}/* lcdCleanScreen */

void main(void)
{
	lcdCleanScreen();
	
	lcdWriteCmd(0x38);
	lcdWriteCmd(0x0F);	
	lcdWriteCmd(0x06);

	lcdWriteData('H');
	lcdWriteData('e');
	lcdWriteData('l');
	lcdWriteData('l');
	lcdWriteData('o');
	lcdWriteData(' ');
	lcdWriteData('W');
	lcdWriteData('o');
	lcdWriteData('r');
	lcdWriteData('l');
	lcdWriteData('d');
	lcdWriteData('!');

	for (;;);

}/* main */