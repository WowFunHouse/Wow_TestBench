#include <STC89.H>

void main(void)
{
	unsigned char n;
	unsigned char ptn;
	unsigned int t;

	P0=0x01;			// 1st row
	for (;;)
	{
		ptn=1;
		for (n=0; n<8; n++)
		{
			P2=~ptn;
			ptn = ptn << 1;
			for (t=0; t< 10000; t++);
		}
  	}
}
