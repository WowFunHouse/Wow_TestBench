#include <STC89.H>

void main(void)
{
	unsigned int	x;
	unsigned char	a;

	a=0;
	for(;;)
	{
		P0=a;
		for(x=0; x<10000; x++);
		a++;
	}
}