#include <STC89.H>

void beep(unsigned length)
{
	unsigned	int n, t;

	for(n=1; n<=length; n++)
	{
		P3=0x00
		for(t=0; t< 50; t++);
		
		P3=0x10
		for(t=0; t< 50; t++);
	}
}

void main(void)
{
	unsigned int d;

	for (;;)
	{
		beep(100);
		for (d=0; d<30000; d++);
		for (d=0; d<30000; d++);
		for (d=0; d<30000; d++);
		for (d=0; d<30000; d++);
	}
}
