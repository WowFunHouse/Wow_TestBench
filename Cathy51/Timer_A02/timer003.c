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
	unsigned char  n;
	unsigned char ledmove[8]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};		  // LED Pattern

	TH0=(65536 - 9216) / 256;	
	TL0=(65536 - 9216) % 256;
			
	TMOD=T0_M1;		

	ET0=1;			
	EA =1;

	timeout = 0;			
	TR0=1;			

	n = 0;							// LED began to "ledmove[0]"
	for(;;)
	{
		if (timeout == 1)			// Interrupt triggered
		{
			light(ledmove[n++]);	// n=0 -> 7
		
			if (n >= 8) n = 0;		
								
			timeout = 0;
		}
	}
}

void light(unsigned char p)		     //Set LED 
{
	P0 = ~p; 
}									

void isrTimer(void) interrupt 1		// 9216 counts passed, timer stopped TH=0, TL=0, TF=1, Interrupt triggered	
{
	static unsigned char timercount=0;

	timercount++;

	TH0=(65536 - 9216) / 256;		// Restart timer for next 9216 clicks	
	TL0=(65536 - 9216) % 256;

	if (timercount >= 100) 			// timer wake up 100 times (100 x 9216): 1 second
	{
		timercount = 0;				// 100 times rearched, reset it for next second
		timeout    = 1;				// Tell outside 1 second reached
	}
}

