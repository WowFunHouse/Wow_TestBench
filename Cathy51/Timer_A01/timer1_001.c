#include <STC89.H>

unsigned char wait;

void main(void)
{
	wait = 0;

	P3=0x00;		// Set LED pattern

	TH1=0x96;		// Set Timer1 delay time (high byte)
	TL1=0x80;		// Set Timer1 delay time (low byte)
	TMOD=T0_M1;		// Set Timer1 to Mode 1

	ET1=1;			// Accept Timer1 interrupt

	EA=1;			// Enable all interrupt (accept interrupt)
	TR1=1;			// Start Timer1

	for(;;);
}

void timer(void) interrupt 3 using 3
{
	if (wait == 152)
	{
		unsigned char a,b;
		int n;

	
	  	for (n=0; n<100; n++)
	  	{
			P3=0x00;
    		for(b=1;b>0;b--) for(a=227;a>0;a--);

			P3=0x10;
    		for(b=1;b>0;b--) for(a=227;a>0;a--);
	 	 }
	  	for (n=0; n<100; n++)
	  	{
    		for(b=1;b>0;b--) for(a=227;a>0;a--);

			for(b=1;b>0;b--) for(a=227;a>0;a--);
      	}

		wait = 0;
	}

	else
	{
		wait++;
	}

	TH1=0x96;
	TL1=0x80;
	TR1=1;
}

