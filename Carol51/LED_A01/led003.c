#include <STC89.H>

void main(void)
{
	unsigned int t;

	for(;;)
	{
		P0=~0x48;
		for(t=0;t<20000;t++);

		P0=~0x00;
		for(t=0;t<20000;t++);
	}  
}