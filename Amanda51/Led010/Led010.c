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

void main(void)
{
	unsigned char	a;

	a=0;
	for(;;)
	{
		P0=led(a);
		delay01();

		P0=led(0);
		delay02();
		P0=led(3);
		delay02();
		P0=led(12);
		delay02();
		P0=led(48);
		delay02();
		P0=led(192);
		delay02();

		a++;
	}
}