#include <STC89.H>

#define LOOPSA 40000
#define LOOPSB 20000

unsigned char led(unsigned char n)
{
	n=~n;
	return n;
}

void delay01(void)
{
	unsigned int	a;

	for(a=0; a<LOOPSA; a++);
}

void delay02(void)
{
	unsigned int	a;

	for(a=0; a<LOOPSB; a++);
}

void delay(unsigned int t)
{
	unsigned int	a;

	for(a=0; a<t; a++);
}

void main(void)
{
	unsigned char	a;

	a=0;
	for(;;)
	{
		P0=led(a);
		delay(LOOPSA);

		P0=led(0);
		delay(30000);
		P0=led(3);
		delay(15000);
		P0=led(12);
		delay(7500);
		P0=led(48);
		delay(3500);
		P0=led(192);
		delay(1750);
		P0=led(0);
		delay(800);

		a++;
	}
}