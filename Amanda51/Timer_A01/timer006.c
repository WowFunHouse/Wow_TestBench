/************************************************************
 Shift LEDs 1 light left per second

 Version:		0.2 alpha
 Description:	 

 Created on: 	2012-06-27
 By:		 	Amanda Li

 Hardware:	 	LED: 0->ON, 1->OFF

 Specification / Requirements:
 	LED status as below: 
 	1s  OFF OFF OFF OFF OFF OFF OFF ON
	2s  OFF OFF OFF OFF OFF OFF ON  OFF
	3s  OFF OFF OFF OFF OFF ON  OFF OFF
	4s  OFF OFF OFF OFF ON  OFF OFF OFF
	5s  OFF OFF OFF ON  OFF OFF OFF OFF
	6s  OFF OFF ON  OFF OFF OFF OFF OFF
	7s  OFF ON  OFF OFF OFF OFF OFF OFF
	8s  ON  OFF OFF OFF OFF OFF OFF OFF
	9s  OFF OFF OFF OFF OFF OFF OFF ON
	10s	OFF OFF OFF OFF OFF OFF ON  OFF
	...
 *************************************************************/
#include <STC89.H>

unsigned char	timeout;

void light(unsigned char p);

void main(void)
{	
	unsigned char	pattern;
	unsigned char	shiftcount;

	TMOD = T0_M1;
	TH0  = (65536 - 9216) >> 8;
	TL0  = (65536 - 9216) % 256;

	ET0  = 1;
	EA   = 1; 

	timeout  = 0;

	pattern    = 1;
	shiftcount = 0;

	TR0 = 1;
	
	for (;;)
	{
		if (timeout != 0)						// 1 second reached
		{
			light(pattern << shiftcount++);		// Show pattern

			if (shiftcount == 8)
			{	
				pattern    = 1;
				shiftcount = 0;
			}

			timeout = 0;
		}
	}
}/* main */

void isrTimer(void) interrupt 1
{

	static unsigned char	timercount = 0;

	TH0 = (65536 - 9216) >> 8;
	TL0 = (65536 - 9216) % 256;

	if (timercount >= 100)
	{
		timercount = 0;
		timeout    = 1;
	}
	else
	{
		timercount++;
	}
}/* isrTimer */

void light(unsigned char p)
{
	P0 = ~p;
}/* light */