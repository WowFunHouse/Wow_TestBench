#include <STC89.H>

void main(void)
{
	unsigned	n, t;

	for(;;)
	{
		for (n=1; n < 10000; n+=1000)
		{

			P3=0x00;
			for(t=0; t<n; t++);

			P3=0x10;
			for(t=0; t<n; t++);
		}
	}
}