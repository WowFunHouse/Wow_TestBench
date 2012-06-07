/* 
   Title: 		Toggle the LED with the switches
   Created on: 	2012-05-30
   Created by:	Mike

	P0: LED		0:On, 1:Off
	P2: P20-P23	Switch: 0:On, 1:Off
*/

#include <STC89.H>

#define	KEY_ON	0
#define	KEY_OFF	1

#define	LED_ON	0
#define LED_OFF	1

void delay1ms(void)   //Îó²î 0us
{
    unsigned char a,b;
    for(b=199;b>0;b--)
        for(a=1;a>0;a--);
}

void delayms(unsigned int time)
{
	unsigned int t;

	for (t=0; t<time; t++) delay1ms();
}

void ledOn(void)
{
	P0=0x00;
}

void ledOff(void)
{
	P0=0xff;
}

unsigned char	getKey(void)
{
	P2 = 0xff;			// Set output to high for capture input
	
	if ((P2 & 0x0f) != 0x0f)
	{
		return KEY_ON;
	}
	else
	{
		return KEY_OFF;
	}
} /* getKey */

void main(void)
{
	unsigned char led;

	ledOff();
	led=LED_OFF;

	for(;;)
	{
		for(;getKey()==KEY_OFF;);	// Key is now off
		delayms(10);
	
		if (led == LED_OFF)		// Key is now On
		{
			led=LED_ON;
			ledOn();
		}
		else
		{
			led=LED_OFF;
			ledOff();
		}
		for (;getKey()==KEY_ON;);	// Key is now On
		delayms(10);	   			// Key is now Off							
	}
}	
	
