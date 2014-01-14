/****************************************************************************
 Title:			Parallel Communication Test
 
 File:			parallel011_tx01.c

 Version:		0.01
 Description:	Transmittion peer

 Created on:	2013-10-09
 Created by:	Cathy Du

 Board:			RichMCU RZ-51V2.0

 Connections:	portData - P0

 Jumpers:		
 **************************************************************/
#include <STC89.H>

// #define	DEBUG
// #define	DEBUGSLOW

#define portData	P0	
#define ctrlDR		P20			/* 0:Data Ready    | 1:Data Not Ready */
#define ctrlACK		P21			/* 0:Data Not Rxd  | 1:Data Received by peer */

void delay(unsigned int d);
void sendData(void);

#ifdef	DEBUG
#define	debugStatus()	debug()
void debug(void)
{
	P10=~ctrlDR;
	P11=~ctrlDR;

	P14=~ctrlACK;
	P15=~ctrlACK;
	P16=~ctrlACK;
 	P17=~ctrlACK;

	delay(20000);

#ifdef DEBUGSLOW
	delay(60000);
	delay(60000);
#endif

} /* debug */
#else
#define	debugStatus()
#endif
					
void main(void)
{
	unsigned char i;

	i = 0;	
		
	ctrlACK  = 1;					/* Use port pin as input for ACK */	
	ctrlDR   = 1; 					/* Data Not-Ready */
	debugStatus();					/* Data to be sent */	

	for (;;)
	{	
		portData = ++i;				/* Send data out */
		portData = 123;
		delay(1000);
		portData = 213;
		delay(2000);
		portData = 87;
		delay(1000);
		portData = 0xAA;
		delay(400);
		portData = 0x55;
		delay(1000);
		portData = 123;
		delay(1000);
		portData = 213;
		delay(2000);
		portData = 87;
		delay(1000);
		portData = 0xAA;
		delay(400);
		portData = 0x55;
		delay(1000);

		portData = i;
		debugStatus();
	  }
	sendData();

} /* main */

void delay(unsigned int d)
{
	unsigned int t;

	for (t=0; t<d; t++);

} /* delay */

void sendData(void)
{
	ctrlDR = 0;					/* Data Ready */
	debugStatus(); 

	while (ctrlACK == 0); 		/* Wait for Ack from peer */
	debugStatus();
	ctrlDR = 1;					/* Tell peer data not valid */
	debugStatus();
	
	delay(1000);
	
} /* sendData */	
