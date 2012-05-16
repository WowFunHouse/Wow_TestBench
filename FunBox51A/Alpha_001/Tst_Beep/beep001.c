#include <STC89.H>

#include "../../include/funbox51a.h"

void beepsnd(unsigned int freq, unsigned int length)
{
	unsigned int d, n;

	P3 = 0x00;						// Turn on the Beeper		
	for (n=1; n<=length; n++)
	{
		for (d=0; d<100; d++);
	}
	P3 = 0x10;						// Turn off the Beeper
}


	


