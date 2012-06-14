#include <STC89.H>

unsigned char led(unsigned char n);

void main(void)
{
	for(;;)
	{
		P0 = led(0x48);
	}
}

unsigned char led(unsigned char n)
{
	return	~n;
}