#include <STC89.H>

void main (void)
{
	unsigned int t, n;

	for (;;)
	{
		for (n=1000; n > 1; n--)
		{
			P3=0x00;
			for (t=0;t<n;t++);

			P3=0x10;
			for (t=0;t<n;t++);
		}
	}
}