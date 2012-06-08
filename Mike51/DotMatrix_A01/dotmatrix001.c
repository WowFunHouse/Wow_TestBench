#include <STC89.H>

void main(void)
{
	unsigned char n;
	unsigned char ptn;
	int t;

	ptn=1;
	P0=0x01;			// 1st row
	for (n=0; n<8; n++)
	{
		P2=~ptn;
		ptn = ptn >> 1;
		for (t=0; t< 10000; t++);
	}

}
