#include <STC89.H>

void main(void)
{
	unsigned int n;   			// 0 - 255
	
	for (;;)
	{	
	 	P0=~0x02;

	 	for (n=0; n < 10000; n++)
	 	{
	 	}

		P0=~0x060;
	}
}