#include <STC89.H>
#include "../include/library.h"
#include "../include/funbox51a.h"

void main(void)
{
	unsigned char sw;

	LastKey  = 0;	  		// Init with key pressed
	FlagStop = 0; 			// Init with status of "non-stopping"

	for (;;)
	{
		sw=getsw();
		if (sw !=0)
		{
			ledptn(sw);
			beepsnd(1000,100);
		}
	}
} /* main */
