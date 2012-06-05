#include <STC89.H>

void delay1ms(void);   //Îó²î -0.651041666667us
void delayms(unsigned int delaytime);
void delay(unsigned int delaytime);

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

	unsigned int a=75;
	unsigned int n,t;

	if (wait == 2000)
	{  
		  for (t=0; t<2; t++)
		  {
				for (n=0; n<100; n++) 	 //Set Beep time
			  {
					P3=0x00;			 // Set Beep freq	  
		    		delay(75);  
		
					P3=0x10; 			// Set Beep  freq
		    		delay(75);
			  }
			  delayms(500);
			 	
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

void delay1ms(void)   //Îó²î -0.651041666667us
{
    unsigned char a,b;
    for(b=102;b>0;b--)
        for(a=3;a>0;a--);
}

void delayms(unsigned int delaytime)
{
	unsigned int t;
	for (t=0;t<delaytime;t++) delay1ms();
}

void delay(unsigned int delaytime)
{
	unsigned int t;
	for (t=0;t<delaytime;t++);
}