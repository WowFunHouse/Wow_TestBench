#include <STC89.H>

void main(void)
{
	unsigned int	t;

	for (;;)
	{
		P0=0x7F;
		for (t=0; t< 10000; t++);

		P0=0xBF;
		for (t=0; t< 10000; t++);

		P0=0xDF;
		for (t=0; t< 10000; t++);

		P0=0xEF;
		for (t=0; t< 10000; t++);

		P0=0xF7;
		for (t=0; t< 10000; t++);

		P0=0xFB;
		for (t=0; t< 10000; t++);

		P0=0xFD;
		for (t=0; t< 10000; t++);

		P0=0xFE;
		for (t=0; t< 10000; t++);

		P0=0xFD;
		for (t=0; t< 10000; t++);

		P0=0xFB;
		for (t=0; t< 10000; t++);

		P0=0xF7;
		for (t=0; t< 10000; t++);

		P0=0xEF;
		for (t=0; t< 10000; t++);

		P0=0xDF;
		for (t=0; t< 10000; t++);

		P0=0xBF;
		for (t=0; t< 10000; t++);
	}
}
