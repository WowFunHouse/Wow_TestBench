#include <STC89.H>

/*********************************************
 For XT100 Development Board

 7-Segment LEDs are common Cathod type on P0

 Digit arrangements (on P1):
 bit-0: left most
 bit-1: 2nd left
 bit-2: 2nd right
 bit-3: right most
**********************************************/

unsigned char hex[]={0x3F, 0x06, 0x5B, 0x4F, 0x66,
		     		 0x6D, 0x7D, 0x07, 0x7F, 0x67,
					 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};

unsigned char digit[4]={0xFE, 0xFD, 0xFB, 0x07};	// LED digit selection from Left->Right

void main(void)
{
	unsigned char n;
	unsigned int  t;

	for (;;)
	{
		for (n=0; n< 16; n++)
		{
			P0=~hex[n];
			P1=digit[2];
			for (t=0; t<32000; t++);
		}
	}
	
} /* main */