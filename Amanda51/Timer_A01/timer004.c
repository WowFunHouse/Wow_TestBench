#include <STC89.H>

void light(unsigned char p);

//void main(void)
//{
//	unsigned char	a, n;
//	unsigned int	t;
//
//	a = 1;
//
//	for(n=0; n<8; n++)
//	{
//		light(a<<1);
//		for(t=0; t<20000; t++);
//	}
//
//}

unsigned char	timeout;
unsigned char	waittime;
unsigned char	ledtime;
unsigned char	a;

void main(void)
{	

	TMOD = T0_M1;
	TH0  = (65536 - 9216)>>8;
	TL0  = (65536 - 9216)%256;

	ET0 = 1;
	EA  = 1;

	a = 1;
	timeout  = 0;
	waittime = 0;
	ledtime  = 0;

	light(a);
	TR0 = 1;
	
	for(;;)
	{
		if(timeout != 0)
		{
			if(ledtime < 8)
			{
				light(a<<1);
				timeout = 0;
			}
			else
			{
				ledtime = 0;
				a = 1;
				light(a);
				timeout = 0;
			}
		}
	}
}/* main */

void timer(void) interrupt 1
{
	TH0  = (65536 - 9216)>>8;
	TL0  = (65536 - 9216)%256;

	if(waittime >= 100)
	{
		timeout  = 1;
		waittime = 0;
		ledtime++;
	}
	else
	{
		waittime++;
	}
}/* timer */

void light(unsigned char p)
{
	P0 = ~p;
}/* light */