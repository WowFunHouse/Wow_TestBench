/**************************************************************
 Title:			Timer testing		
 
 File:			timer003.c

 Version:		0.01
 Description:	Toggle LEDs on Port-1

 Created on:	2013-08-02
 Created by:	Michael

 Board:			RichMCU RZ-51V2.0

 Connections:	Default

 Jumpers:		All on	
 **************************************************************/
#include <STC89.H>

void delay(void)
{
	int d;

	for (d=0; d<10000; d++);

} /* delay */

void main(void)
{
	unsigned int timer_cnt;

	char i=0;

	P1=0xff;

	// TMOD=0x1;		   	// T0: Mode1 T1:Mode0
	// TMOD = T0_M1;		// T0: Mode1 T1:Mode0

	// TMOD=0x11;			// T0: Mode1 T1:Mode1
	TMOD = T0_M1 | T1_M1;

	timer_cnt = 65536 - 50000;

	TH0 = timer_cnt >> 8;
	TL0 = (unsigned char)(timer_cnt & 0x00ff);

	ET0=1;
	EA=1;

	TR0=1;

	for(;;)
	{
		P0=i++;
		delay();
	}

} /* main */


void isr(void) interrupt 1 using 2
{
    static unsigned char count=0;
	unsigned int timer_cnt;

	count++;
	
	if (count==10)
	{	
		P1=~P1;
		count=0;
	}

	timer_cnt = 65536 - 50000;

	TR0 = 0;
	TH0 = timer_cnt >> 8;
	TL0 = (unsigned char)(timer_cnt & 0x00ff);
	TR0 = 1;

} /* isr */