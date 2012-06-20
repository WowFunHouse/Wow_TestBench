#include <STC89.H>
#include "../../Common51/lib51.h"

void main(void)
{
	unsigned char	a,b,n;
	unsigned char	last;

   	P20=1;
	for(;;)
	{
		last = 1;
		for (n=1; n<43; n++)
		{
			if (P20==0)
			{
				n = last;
			}
			else
			{
				last = n;
			}

			a=n%10;
			b=n/10;

			P1=0xFF;
			P0=led(hex[a]);
			P1=0x07;
			delayms(10);

			P1=0xFF;
		   	if (b != 0)
			{
				P0=led(hex[b]);
				P1=0x0b;
				delayms(10);
			}
		}
	}
}

