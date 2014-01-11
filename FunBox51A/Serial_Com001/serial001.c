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

#define	LED			P1

unsigned char	serialTxBusy;							/* 1=Busy; 0=ready */

void serialInit(void);
void serialPutChar(unsigned char c);
void actionSerialRx(unsigned char c);
unsigned char serialGetChar(void);

void delay(unsigned int d)
{
	unsigned int t;

	for (t=0; t<d; t++);

} /* delay */

void main(void)
{
	unsigned char	i;

	serialInit();

	i = 123;

	for(;;)
	{
		if (serialTxBusy != 1)					/* Transmittion not busy */
		{
			serialPutChar(++i);
			delay(500);
		    P0=i;
		}
	}
} /* main */


void serialInit(void)
{
	serialTxBusy = 0;							/* Unset Busy Flag */

	SM0 = 0;									/* Set Serial port to Mode 0 */
	SM1 = 0;
	SM2 = 0;

	ES = 1;										/* Enable Serial Interrupt */
	EA = 1;										/* Enable All Interrupts   */

	REN = 1;									/* Enable receiving */
								 
} /* serialInit */

void ISRserial(void) interrupt 4 using 2 
{
	unsigned char	c;

	ES = 0;
		
	if (RI == 1)								/* Data received */
	{
		c = serialGetChar();
		actionSerialRx(c);						/* Process data */
		RI = 0;									/* Clear RI */
	}

	if (TI == 1)								/* Data transmitted */
	{
	 	TI = 0;									/* Clear TI */
	 	serialTxBusy = 0;						/* Ready for next transmittion */
	}
	
	ES = 1;

} /* ISRserial */

void serialPutChar(unsigned char c)
{
	serialTxBusy = 1;							/* Transmittion is busy */
	SBUF = c;								    /* Send data out */
	
} /* serialPutChar */

unsigned char serialGetChar(void)
{
	unsigned char	c;

	c = SBUF;									/* read data */
	
	RI = 0;										/* clear RI */

	return c;

} /* serialGetChar */

void actionSerialRx(unsigned char c)
{
	LED = c;

} /* actionSerialRx */