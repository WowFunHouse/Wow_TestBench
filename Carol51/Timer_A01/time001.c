/******************************************************
一秒闪灯
时间：2012-06-25
作者：Carol

 Hardware: 	X'tal = 11.0592Mhz
 			Timer frequency = 11.0592 / 12 = 961,200Hz
			i.e. timer click = 961,200 per second

 ******************************************************/
#include <STC89.H>

unsigned char	timercount;
unsigned char	timeout;

void light(unsigned char p)
{
  	 P0=~p;					// LED 0:On 1:off
} /* light */

void main(void)
{
    unsigned char a;
	
	TH0 = (65536 - 9216) >> 8;		// Delay time for the timer (16-bit)
	TL0 = (65536 - 9216) % 256;

	TMOD = T0_M1;			// Timer0 set to Mode-1

	ET0 = 1;				// Enable Timer0 Interrupt
	EA	= 1;				// Enable all interrupts

	timeout    = 0;			// Ready to start the timer
	timercount = 0;			// count 100 times (9216 x 100 = 921,600: 1sec)

	TR0	= 1;				// Start the timer
			  
    a=0;
    for (;;)
    {
	   light(a);

	   if (timeout==1)	   	// Ok, it is 1 second passed
	   {
	    	light(a);
	    	a++;
			timeout = 0;  	// Start the time again...
	   }
	 }
} /* main */

void isrTimer(void) interrupt 1		// Reach here: Timer stopped, TH=0, TL=0, TF=1, timer interrupt triggered
{
	timercount++;					// 9216 clicks come here 

	if (timercount >= 100) 			// 100 x 9216 --> 1 second
	{
		timeout    = 1;
		timercount = 0;
	}
	
	TH0 = (65536 - 9216) >> 8;		// Delay time for the timer (16-bit)
	TL0 = (65536 - 9216) % 256;	
} /* isrTimer */




