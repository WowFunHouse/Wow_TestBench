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

#define	portData	P0
#define	portLED		P1
#define	ctrlDR		P20
#define	ctrlACK		P21

void delay(unsigned int delayTime);
void showDataOnLED(unsigned char ledData);
unsigned char recvData(void);

void main(void)
{
	portData = 0xff;				/* Set port as Input to receive data */
	ctrlDR   = 1;					/* Set port pin as input for -DR     */
	ctrlACK  = 0;					/* 0:Data not Rxd  | 1:Data Received OK */

	for(;;)
	{
		showDataOnLED(recvData());
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

	while (ctrlDR == 1);			/* Data ready? 0:Data Ready  | 1:Data Not Ready  */
	rxData = portData;				/* Data is now ready */

	ctrlACK = 1;					/* Acknowledge to peer: Data received */

	while (ctrlDR == 0);			/* Data still valid?  0:Data not Rxd  | 1:Data Received OK */
	ctrlACK = 0;					/* Data not valid anymore, clear ACK flag */
	
	return	rxData;					/* Return Data */
				
} /* recvData */

void showDataOnLED(unsigned char ledData)
{
	  portLED = ~ledData;				/* Show data on LEDs */

} /* showDataOnLED */