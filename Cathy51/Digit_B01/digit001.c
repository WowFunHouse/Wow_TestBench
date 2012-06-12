#include <STC89.H>

void main(void)
{
	unsigned char led[]={0x3F, 0x06, 0x5B, 0x4F, 0x66,
		     			 0x6D, 0x7D, 0x07, 0x7F, 0x67,0x77};
	unsigned char digit[4]={0xFE, 0xFD, 0xFB, 0x07};

	for (;;)
	{
		unsigned int t;
		unsigned char n;
				
	  	P0 = 0xFF;					// Turn off the LED
									
		for (n=0; n<11; n++)
		{									
			P0 = ~led[n];			 	
			P1 = digit[2];
			for (t=0; t<10000; t++);	
		}
	}
}


