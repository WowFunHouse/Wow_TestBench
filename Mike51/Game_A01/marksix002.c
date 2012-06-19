/**************************************************************
 Title:			Mark-Six Number Generator
 Version:		2.0

 Description:	To generate random numbers between 1 -> 42
 				Press key to show the random number generated

 Created on:	2012-06-19
 Created by:	Michael

 Hardware:		RichMCU RZ-51
					   
 Connections:	P0.0 - P0.7 -> 7-Segment LED segemnt control (0:On 1:Off)
				P2.0 - P2.1 -> Digit selection of 7-Segment LED
 			 	P1.4 -> Switch K5 (O:On 1:Off)	
				
 **************************************************************/
#include <STC89.H>
#include "../../Common51/lib51.h"

void main(void)
{
	unsigned char	digit[8]={0x7f, 0xbf, 0xdf, 0xef, 0xf7, 0xfb, 0xfd, 0xfe};
	unsigned char	a,b,n;
	unsigned char	last;

   	P14=1;
	for(;;)
	{
		last = 1;
		for (n=1; n<43; n++)
		{
			if (P14==0)
			{
				n = last;
			}
			else
			{
				last = n;
			}

			a=n%10;
			b=n/10;

			P2=0xFF;
			P0=led(hex[a]);
			P2=digit[0];
			delayms(10);

			P2=0xFF;
		   	if (b != 0)
			{
				P0=led(hex[b]);
				P2=digit[1];
				delayms(10);
			}
		}
	}
}

