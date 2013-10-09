/**************************************************************
 Title:			Parallel Communication Test
 
 File:			parallel01_rx01.c

 Version:		0.01
 Description:	Receving peer

 Created on:	2013-10-09
 Created by:	Amanda Li

 Board:			RichMCU RZ-51V2.0

 Connections:	Default

 Jumpers:		All on		
 **************************************************************/
#include <STC89.H>

#define	dataPort	P0
#define	LED			P1
#define	ctrlDR		P20
#define	ctrlACK		P21



void recvData(void);

void main(void)
{
	recvData();
} /* main*/

void delay(void)
{
	unsigned int t;

	for (t=0; t<4000; t++);

} /* delay */

void recvData(void)
{
	unsigned char	rxData;

	dataPort = 0xff;				/* Set port as Input to receive data */
	ctrlDR   = 1;					/* Set port pin as input for -DR     */

	ctrlACK  = 0;					/* 0:Data not Rxd  | 1:Data Received OK */

	for (;;)
	{
	  while (ctrlDR == 1) {};		/* Wait for data ready */
	  rxData = dataPort;			/* Data now ready to grab */

	  LED = rxData;					/* Show data */

	  delay();
	  ctrlACK = 1;					/* Acknowledge to peer: data received */

	  while (ctrlDR == 0);			/* Data still valid? */
	  ctrlACK = 0;					/* Data not valid anymore, clear ACK flag */
	}			
} /* recvData */