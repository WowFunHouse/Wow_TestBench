#include <STC89.H>
#include "../include/library.h"
#include "../include/funbox51a.h"

void beepsnd(unsigned int freq, unsigned int length)
{
	unsigned int  n;

	P3 = 0x00;

	for (n=1; n<=length; n++)	   // Turn on the Beeper
	{
		delayms(500);
//		for (d=0; d<100; d++);
	}
	P3 = 0x10;			// Turn off the Beeper
}


	


