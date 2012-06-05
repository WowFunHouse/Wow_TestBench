#include <STC89.H>

unsigned char clock[4]={0, 1, 5, 8};

unsigned int timerCount;

void delay(void)
{
//	unsigned int	t;
//
//	for (t=0; t<100; t++);
}

void main(void)
{
	unsigned char bcd[]={0x3F, 0x06, 0x5B, 0x4F, 0x66,
						 0x6D, 0x7D, 0x07, 0x7F, 0x67};

	unsigned char digit[4]={0xFE, 0xFD, 0xFB, 0x07};

	unsigned char 	d;

	timerCount=0;

	TMOD=T0_M1;
	TH0=(65536-1000)>>8;
	TL0=(65536-1000)%256;
	
	ET0=1;
	EA=1;

	TR0=1;

	for (;;)
	{
		for (d=0; d<4; d++)
		{
	
			P1=0xFF;

			P0=~bcd[ clock[d] ];
			delay();

			P1=digit[d];
			delay();
		}
	}
}

void timer(void) interrupt 1 using 3
{
	unsigned char n;

	if (++timerCount > 1000)
	{
		for (n=0; n<4; n++)
		{
			if (++clock[n] > 9)
			{
				clock[n]=0;
			}
		}
		timerCount=0;
	 }

	TH0=(65536-1000)>>8;
	TL0=(65536-1000)%256;
	TR0=1;
}
