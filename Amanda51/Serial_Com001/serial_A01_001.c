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
void actionSerialRx(unsigned char c);
void serialPutChar(unsigned char c);
unsigned char serialGetChar(void);

void delay(unsigned int delayTime)
{
	unsigned int	t;

	for(t=0; t<delayTime; t++);

} /* delay */

void main(void)
{
	unsigned char	i;

	serialInit();

	i = 0;

	for(;;)
	{
		if (serialTxBusy != 1)
		{
			serialPutChar(i++);
			delay(60000);
			delay(60000);
			delay(60000);
		}
	}
} /* main */


void serialInit(void)
{
	serialTxBusy = 0;							/* Set Busy Flag */
	
	SM0 = 0;									/* Set Serial port to Mode 0 | SM0 = 0 and SM1 = 0 */ 
	SM1 = 0;
	SM2 = 0;

	ES = 1;										/* Enable Serial Interrupt */
	EA = 1;										/* Enable All Interrupts   */
	
	REN = 1;
							 
} /* serialInit */

void ISRserial(void) interrupt 4 using 2 
{
	unsigned char	c;
	
	if (RI == 1)								 /* Data received */	
	{											 
		c = serialGetChar();
		actionSerialRx(c);						 /* Process data */
		RI = 0;									 /* clear RI */
	}

	if (TI == 1)								 /* Data treausmitted */
	{
	 	TI = 0;									/* clear TI */
	 	serialTxBusy = 0;						/* Ready for next treausmitted */
	}

} /* ISRserial */

unsigned char serialGetChar(void)				/* Interrupt ON */
{
	unsigned char	c;

	c = SBUF; 									/* read data */
	
	RI = 0;										/* clear RI */

	return c;

} /* serialGetChar */

void serialPutChar(unsigned char c)
{
	serialTxBusy = 1;							/* UnSet busy flay */

	SBUF = c;									/* Put Data */

} /* serialPutChar */

void actionSerialRx(unsigned char c)
{
	LED = c;									/* Display Data */

} /* actionSerialRx */