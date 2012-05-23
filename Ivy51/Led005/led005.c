#include <STC89.H>

void main(void)
{
	unsigned int	t;

	for (;;)
	{
		P0=0x3F;
		for (t=0; t< 10000; t++);

		P0=0xCF;
		for (t=0; t< 10000; t++);

		P0=0xF3;
		for (t=0; t< 10000; t++);

		P0=0xFC;
		for (t=0; t< 10000; t++);
	}
}
