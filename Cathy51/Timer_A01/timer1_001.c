#include <STC89.H>

unsigned int wait;

void main(void)
{
	wait = 0;

	TH1=0xd8;	// Set Timer1 delay time (high byte)
	TL1=0xf0;		// Set Timer1 delay time (low byte)
	TMOD=T0_M1;		// Set Timer1 to Mode 1

	ET1=1;			// Accept Timer1 interrupt

	EA=1;			// Enable all interrupt (accept interrupt)
	TR1=1;			// Start Timer1

	for(;;);
}

void timer(void) interrupt 3 using 3
{	
	unsigned char a,b,t;
	int n,h;

	if (wait == 2000)
	{  
		  for (t=0; t<2; t++)
		  {
				for (n=0; n<100; n++) //Set Beep time
			  {
					P3=0x00;		// Set Beep freq	  
		    		for(b=1;b>0;b--) for(a=227;a>0;a--);
		
					P3=0x10; // Set Beep  freq
		    		for(b=1;b>0;b--) for(a=227;a>0;a--);
			  }
			  	for(h=0; h<6000; h++);
			 	
			}
		wait=0;
	}
	else
	{
		wait++;
	}  

	TH1=0xd8;
	TL1=0xf0;
	TR1=1;
}

