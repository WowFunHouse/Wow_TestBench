#include <STC89.H>

void light(unsigned char p);

unsigned char	timeout;
unsigned int	waittime;

void main(void)
{
	unsigned char	a;

	TMOD = T0_M1;
	TH0  = (65536 - 9216)>>8;
	TL0  = (65536 - 9216)%256; 

	ET0  = 1;
	EA   = 1;

	a = 0;
	timeout = 0;
	light(a);

	TR0  = 1;

	for(;;)
	{
		if(timeout != 0)
		{
			light(a);
			a++;
			timeout = 0;
		}
	}
}/* main */

void timer(void) interrupt 1
{
	if(waittime >= 100)
	{
		timeout = 1;
		waittime = 0;
	}
	else
	{
		waittime++;
	}

	TH0  = (65536 - 9216)>>8;
	TL0  = (65536 - 9216)%256;

}/* timer */

void light(unsigned char p)
{
	P0 = ~p;
}/* light */
