#include <STC89.H>

void delay(void)
{
	unsigned int a;

	for (a=0; a< 10000; a++);
}


void main(void)
{
	unsigned char	a;

	a=0;
	for(;;)
	{
		P0=a;
		delay();
		a++;
	}
}