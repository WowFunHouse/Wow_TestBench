#include <STC89.H>
#include "../../Common51/lib51.h"

void main(void)
{
	unsigned char	n, a, b;
	unsigned int	t;
	
	P20 = 1;
	for(;;)
	{
		for(n=1; n<43; n++)
		{
			a = n%10;
			b = n/10;

			P1 = 0xFF;
			P0 = ~hex[a];
			P1 = 0x07;
			for(t=0; t<50; t++);

			P1 = 0xFF;
			P0 = ~hex[b];
			P1 = 0x0B;
			for(t=0; t<50; t++);

			while(P20==0);
		}
	}
}