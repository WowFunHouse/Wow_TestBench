#include <STC89.H>

void main(void)
{
	unsigned	int t;

	for(;;)
	{
		P3=0x00;
		for(t=0; t< 50; t++);
		
		P3=0x10;
		for(t=0; t< 50; t++);
	}
}