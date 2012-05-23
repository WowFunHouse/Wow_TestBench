#include <STC89.H>

void main(void)
{
	unsigned int	t;

	for (;;)
	{
		P0=0x7E;
		for (t=0; t< 10000; t++);

		P0=0xBD;
		for (t=0; t< 10000; t++);

		P0=0xDB;
		for (t=0; t< 10000; t++);

		P0=0xE7;
		for (t=0; t< 10000; t++);

		P0=0xDB;
		for (t=0; t< 10000; t++);

		P0=0xBD;
		for (t=0; t< 10000; t++);
	}
}
