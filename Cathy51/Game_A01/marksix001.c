/*
	Title:			Mark-Six number generator
	Version:		1.0

	Created on:		2012-06-19
	Created by:		Cathy

	Description:	Will generator random numbers between 1 -> 42
					Press switch S3 to show the random number

	Hardware:		XT-100 8x51 Development board
	Connections:	
					P0: 7-seg LED		0:On,	1:Off
					P1: 7-seg LED (P10 - P13)
					P2:	P20-P23 Switch:	0:On,	1:Off
*/

#include <STC89.H>
#include "../../Common51/lib51.h"

void main(void)
{
	unsigned char a, b;
	unsigned char last;
	

	P20 = 1 ;
	for(;;)
	{
		unsigned char n;

		for(n=1; n<43; n++)
		{
			if (P20 == 0)				// Key On
			{
				n = last;
			}
			else					 	// Key Off
			{	
				last = n;
			}
					
			a = n % 10;
			b = n /10 ;

			P1 = 0xff;					// All digits off
			P0 = led(bcd[a]);			// 1st LED pattern
			P1 = 0xf7;					// 1st digit on
			delayms(100);	 

			P1 = 0xff;				 	// All digits off
			P0 = led(bcd[b]);				// 2nd LED pattern
			P1 = 0xfb;				    // 2nd digit on
			delayms(100);	
		}
	}
}




