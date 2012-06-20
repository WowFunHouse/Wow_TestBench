/*
	Title:			Toggle the LED with the switches
	Created on:		2012-06-18
	Created by:		Cathy

	P0: LED		0:On,	1:Off
	P2:	P20-P23 Switch:	0:On,	1:Off
*/

#include <STC89.H>

#define KEY_ON  0
#define KEY_OFF	1

#define LED_ON	0
#define LED_OFF 1

void delay1ms(void)   //Îó²î -0.651041666667us
{
    unsigned char a,b;
    for(b=102;b>0;b--)
        for(a=3;a>0;a--);
}

void delayms(unsigned int t)			   //delay milliseconds
{
	unsigned int n;

	for (n=0; n<t; n++) delay1ms();

} /*Delay*/

void ledOn(void)						  //Set Led light
{
	P0 = 0x00;
}

void ledOff(void)						 //Set Led  shut
{
	P0 = 0xff;
} /*Led On Off*/

unsigned char getkey(void)				// get key	return 0 and 1
{
	P2 = 0xff;							// Set output to high  for capture input

	if ((P2 & 0x0f)!= 0x0f)
	{
		return KEY_ON;
	} 
	else
	{	
		return KEY_OFF;
	}
} /*getkey*/

void main (void)
{
	unsigned char led ;
													
	ledOff();							 // Set led off
	led = LED_OFF;
		
	for	(;;)
	{
		for (;getkey() == KEY_OFF;);	// Key is now off
		delayms(10);

		if (led == LED_OFF)				// key is now on
		{
			led = LED_ON;
			ledOn();
		}
		else
		{
			led = LED_OFF;
			ledOff();
		}
		for (;getkey() == KEY_ON;);		// key is now on
		delayms(10);					// key is now off

	}
}