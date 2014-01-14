/****************************************************************************
 Title:			Serial Communication Test
 
 File:			serial01_001.c

 Version:		0.01
 Description:	Transmittion peer

 Created on:	2013-10-15
 Created by:	Cathy Du

 Board:			RichMCU RZ-51V2.0

 Connections:	DATAPORT - P0

 Jumpers:		
 **************************************************************/
#include <STC89.H>

#define	pordData	P0

void serialInit(void);
void serialPutChar(unsigned c);
unsigned char serialGetChar(void);
void actionSerialRx(unsigned char c);
void delay(unsigned int t);

unsigned char serialTxBusy;			/* 1=Busy; 0=ready */

void main(void)
{
	unsigned char i;

	serialInit();

	i=0;

	for(;;)
	{
		if (serialTxBusy != 1)
		{
			serialPutChar(i++);
			delay(50000);
		}
	}
}

void SerialInit(void)
{
	serialTxBusy = 0;

//	init serial port:
	
//	Set Serial port to Mode 0
	SM0 = 0;
	SM1 = 0;
	SM2 = 0;
	REN = 1;
//	Enable Serial Interrupt
	ES = 1;

//	Enable All Interrupts
	EA = 1;
							 
}

void ISRserial(void) interrupt 4
{
	unsigned char c;

	if (RI == 1)
	{
		c = serialGetChar();
		actionSerialRx(c);
		RI = 0;
	}

	if (TI == 1)
	{
	 TI = 0;
	 serialTxBusy = 0;
	}
}

void serialputChar(unsigned c)
{
	serialTxBusy = 1;
	SBUF = c;
}

unsigned char serialGetChar(void)
{
	unsigned char c;

	REN = 1;

	c = SBUF; /* read data */

//	clear RI;
	RI = 0;

	return c;
}

void actionSerialRx(unsigned char c)
{
	pordData = c;
}
		
void delay(unsigned int t)				
{
	unsigned int d;

	for (d=0; d< t; d++);
}
