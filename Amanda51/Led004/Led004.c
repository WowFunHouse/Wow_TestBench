#include <STC89.H>

char led(char n)
{
	return ~n;
}

void delay(int t)
{
	int		x;

	for(x=1; x<t; x++);
}


void main(void)
{
	char	a;
	char	n;

	a=1;
	for(;;)
	{
		P0=led(a++);
		delay(40000);

		P0=led(0);
		delay(20000);

		for(n=3; n<=6; n>>2)
		{
			P0=led(n);
			delay(20000);
		}

		P0=led(0);
		delay(20000);
	}
}