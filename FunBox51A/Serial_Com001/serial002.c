/**************************************************************
 Title:			Serial Communication Test
 
 File:			serial002.c

 Version:		0.01
 Description:	Use polling instead of interrupts

 Created on:	2013-10-15
 Created by:	Michael Sin

 Board:			RichMCU RZ-51V2.0

 Connections:	Default

 Jumpers:		All on		
 **************************************************************/
#include <STC89.H>

#define	LED			P1

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

	SM0 = 0;									/* Set Serial port to Mode 0 */
	SM1 = 0;
	SM2 = 0;

	REN = 1;									/* Enable receiving */

	ES = 0;
	EA = 0;

	i = 123;

	for(;;)
	{
		SBUF = i++;								    /* Send data out */
		TI=0;
		while (TI == 0);							/* Wait data transmitted */

		delay(5000);
	    P0=i;

 		RI=0;
		while (RI == 0);
		P1 = SBUF;
	}
} /* main */
