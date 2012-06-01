#include <STC89.H>

unsigned int	wait;

void main(void)
{
	wait = 0;

	TH0 = 156;
	TL0 = 156;
	TMOD = T0_M2;
	
	ET0 = 1;
	
	EA = 1;
	TR0 = 1;
	
	for(;;);	
}

void timer(void) interrupt	1 using	3
{
	if(wait == 10000)
	{
		unsigned int	t, n;

		for(n=0; n<100; n++)
		{
		P3=0x00;
		for (t=0; t< 500; t++);

		P3=0x10;
		for (t=0; t< 500; t++);
		}
		wait = 0;
	}
	else
	{
		wait++;
	}
	TH0 = 156;
	TL0 = 156;
	TR0 = 1;
}