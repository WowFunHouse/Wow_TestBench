/*
	Title:			Mark-Six number generator
	Version:		1.0

	Created on:		2012-06-19
	Created by:		Cathy

	Description:	Will generator random numbers between 1 -> 42
					Press switch S3 to show the random number

	Hardware:		RICHMCU Development board
	Connections:	
					P0: 7-seg LED		0:On,	1:Off
					P2: 7-seg LED (P20 - P27)
					P1:	P14-P17  Switch:	0:On,	1:Off
*/							
#include <STC89.H>
#include "../../Common51/lib51.h"

void main(void)
{
	unsigned char a, b, n;
	unsigned char last;
	unsigned char bcd[]= {}
	

	P14 = 1 ;						    // Set output to high for capture input
	for(;;)
	{
		for(n=1; n<43; n++)
		{
			if (P14 == 0)				// Key On
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
			P0 = bcd[a];				// 1st LED pattern
			P1 = 0xf7;					// 1st digit on
			delayms(100);	 

			P1 = 0xff;				 	// All digits off
			P0 = bcd[b];				// 2nd LED pattern
			P1 = 0xfb;				    // 2nd digit on
			delayms(100);	
		}
	}
}
