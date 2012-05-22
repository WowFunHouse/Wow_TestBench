#include <STC89.H>

unsigned char led(unsigned char n)
{
	return	~n;
}

unsigned char main(void)
{
	unsigned char	b, x;

	b = 0x00;

	P2 = 0xFF;
	x = P2;
	x = x&0x0F;
	
	if(x == 0x0E)	return ~b;
	else			return b;

	P0 = led(b);
}