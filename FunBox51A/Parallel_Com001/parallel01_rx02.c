/**************************************************************
 Title:			Parallel Communication Test
 
 File:			parallel01_rx02.c

 Version:		0.02
 Description:	Receving peer

 Created on:	2013-10-10
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

void delay(unsigned int delayTime);
unsigned char recvData(void);
void showDataLED(unsigned char dsData);

void main(void)
{
	dataPort = 0xff;				/* Set port as Input to receive data */
	ctrlDR   = 1;					/* Set port pin as input for -DR     */

	ctrlACK  = 0;					/* 0:Data not Rxd  | 1:Data Received OK */

	for(;;)
	{
		showDataLED(recvData());
		delay(20000);
	}
} /* main*/

void delay(unsigned int delayTime)
{
	unsigned int t;

	for (t=0; t<delayTime; t++);

} /* delay */

unsigned char recvData(void)
{
	unsigned char	rxData;

	while (ctrlDR == 1) {};			/* Wait for data ready  |  0:Data Ready    |  1:Data Not Ready  */
	rxData = dataPort;				/* Data now ready to grab */

	ctrlACK = 1;					/* Acknowledge to peer: data received */

	while (ctrlDR == 0) {};			/* Data still valid?    |  0:Data not Rxd  | 1:Data Received OK */
	ctrlACK = 0;					/* Data not valid anymore, clear ACK flag */
	
	return	rxData;					/* Return Data to Desplay */			
} /* recvData */

void showDataLED(unsigned char dsData)
{
	  LED = ~dsData;				/* Show data to LED */
} /* showDataLED */