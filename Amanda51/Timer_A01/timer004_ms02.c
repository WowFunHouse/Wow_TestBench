/************************************************************
 Shift LEDs 1 light left per second

 Version:	 0.1 alpha

 Created on: 2012-06-27
 By:		 Amanda Li

 Hardware:	 LED: 0->ON, 1->OFF

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
unsigned char	timercount;

void light(unsigned char p);

void main(void)
{	
	unsigned char	a;
	unsigned char	led_next_position;

	TMOD = T0_M1;
	TH0  = (65536 - 9216) >> 8;
	TL0  = (65536 - 9216) % 256;

	ET0  = 1;
	EA   = 1;

	a = 1; 

	timeout  = 0;
	timercount = 0;
	led_next_position  = 1;

	light(a);
	TR0 = 1;
	
	for (;;)
	{
		if (timeout != 0)					// 1 second reached
		{
			if (led_next_position < 8)
			{
				a = 1 << led_next_position;
			}
			else
			{
				led_next_position = 0;
				a = 1;
			}
			light(a);
			led_next_position++;
			timeout = 0;
		}
	}
}/* main */

void isrTimer(void) interrupt 1
{
	TH0 = (65536 - 9216) >> 8;
	TL0 = (65536 - 9216) % 256;

	if (timercount >= 100)
	{
		timercount = 0;
		timeout  = 1;
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