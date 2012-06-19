#include <STC89.H>

void main(void)
{	
	unsigned int t;

	P0 = 0xff;
	
	for(;;)
	{
	 	P0 = 0xb7;
		for (t=0; t<10000; t++);	
	}

}