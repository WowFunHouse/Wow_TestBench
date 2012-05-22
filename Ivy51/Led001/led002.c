#include <STC89.H>

void main(void)
{
	unsigned int	t;

	for (;;)
	{
		P0=0x67;
		for (t=0; t< 20000; t++);

		P0=0xFF;
		for (t=0; t< 20000; t++);
	}
}
					