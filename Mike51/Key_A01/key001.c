#include <STC89.H>

#define	KEY_ON	0
#define	KEY_OFF	1

#define	LED_ON	0
#define LED_OFF	1

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
						// Key is now Off
	}
}	
	
