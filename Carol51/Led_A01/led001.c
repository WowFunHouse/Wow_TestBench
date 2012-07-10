#include <STC89.H>

unsigned char showled(unsigned char ptn)
{
	P0=~ptn;

	return ptn+1;
}

void main(void)
{
	unsigned int  t;
	unsigned char n;
	
	n=0;
	for(;;)
	{
		for (t=0; t< 60000; t++);
		n=showled(n);
	}
}