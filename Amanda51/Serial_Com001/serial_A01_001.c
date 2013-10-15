/**************************************************************
 Title:			Serial Communication Test
 
 File:			serial_A01_001.c

 Version:		0.01
 Description:	

 Created on:	2013-10-15
 Created by:	Amanda Li

 Board:			RichMCU RZ-51V2.0

 Connections:	Default

 Jumpers:		All on		
 **************************************************************/
#include <STC89.H>

#define	sbuf		P0
#define	LED			P1

unsigned char	serialTxBusy;							/* 1=Busy; 0=ready */

void serialInit(void);
void actionSerialRx(unsigned char c);
unsigned char serialGetChar(void);

void main(void)
{
	unsigned char	i;

	serialInit();

	i = 0;

	for(;;)
	{
		if (serialTxBusy != 1)
		{
			serialTxBusy = 1;
			serialTx(i++);
		}
	}
} /* main */


void serialInit(void)
{
	serialTxBusy = 0;							/* Set Busy Flag */

	init serial port:
	
	SM0 = 0;									/* Set Serial port to Mode 0 | SM0 = 0 and SM1 = 0 */ 
	SM1 = 0;

	ES = 1;										/* Enable Serial Interrupt */
	EA = 1;										/* Enable All Interrupts   */
							 
} /* serialInit */

void ISRserial(void) interrupt 0 using 2 
{
	unsigned char	c;
	
	if (RI == 1)
	{
		c = serialGetChar();
		actionSerialRx(c);
		RI = 0;									 /* clear RI */
	}

	if (TI == 1)
	{
	 	TI = 0;
	 	serialTxBusy = 0;
	}
} /* ISRserial */

unsigned char serialGetChar(void)
{
	unsigned char	c;

	c = sbuf; 									/* read data */
	
	RI = 0;										/* clear RI */

	return c;

} /* serialGetChar */

void actionSerialRx(unsigned char c)
{
	LED = c;

} /* actionSerialRx */