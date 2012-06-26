/**********************************************************
 Hardware:	X'tal=11.0592MHz
 			Timer click = 11.0592MHz / 12 = 921600Hz
			i.e. 1 second: 921,600 timer click (9216 x 100)
 **********************************************************/
#include <STC89.H>

unsigned char timeout;

void light(unsigned char p);

void main (void)
{
	unsigned char a;

	TH0=(65536 - 9216) / 256;	
	TL0=(65536 - 9216) % 256;
			
	TMOD=T0_M1;		

	ET0=1;			

	EA=1;
	
	a=0;
	timeout = 0;			
	TR0=1;			

	for(;;)
	{
		if (timeout == 1)
		{
			light(a);
			a++;
			timeout = 0;
		}
	}
}

void light(unsigned char p)		 //Set LED 
{
	P0 = ~p; 
}									

void isrTimer(void) interrupt 1		// 9216 counts passed, timer stopped TH=0, TL=0, TF=1, Interrupt triggered	
{
	static unsigned char timercount=0;

	timercount++;

	if (timercount >= 100) 			// timer wake up 100 times (100 x 9216): 1 second
	{
		timercount = 0;				// 100 times rearched, reset it for next second
		timeout    = 1;				// Tell outside 1 second reached
	}

	TH0=(65536 - 9216) / 256;		// Restart timer for next 9216 clicks	
	TL0=(65536 - 9216) % 256;
}

