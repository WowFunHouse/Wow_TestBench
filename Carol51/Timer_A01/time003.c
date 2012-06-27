#include <STC89.H>

unsigned char timeout;

void light(unsigned char p)
{
     P0=~p;
}

void main(void)
{
    unsigned char pattern;

	TH0 = (65536 - 9216) >> 8;
	TL0 = (65536 - 9216) % 256;

	timeout=0;
		
	TMOD=T0_M1;

	ET0 = 1;
	EA  = 1;

	TR0 = 1;
	
	pattern=1;
	
	for (;;)
	{
		if (timeout != 0)		// Now, it is 1 second!!!
		{
			timeout = 0;
			light(pattern);

			pattern = pattern << 1;		// pattern <<= 1
			if (pattern == 0) pattern = 1;
		}
	}    
}

void isrTimer(void)interrupt 1
{	
	static unsigned char timercount=0;

	TH0 = (65536-9216) >> 8;
	TL0 = (65536-9216) % 256;

    timercount++ ;

	if (timercount>=100)
	{
		 timeout=1;			 	// Tell outside 1 second reached
		 timercount=0;
	}	 
}