/******************************************************************
Library of supporting utilities

 Version:      		0.01
 Description:		Supporting function

 Created on:		2012-07-09
 Created by:		Cathy

 ******************************************************************/
#include <STC89.H>
#include "lib_uty001.h"

#define RS 			P20
#define RW 			P21
#define EN 			P22
#define DATAPORT    P0
#define BF 			P07
#define DELAYSHORT  100


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

void lcdClearScreen(void)
{
	lcdWriteCmd(0x01);
			
} /* lcdClearScreen */

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

