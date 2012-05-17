#include <STC89.H>
#include "../include/library.h"
#include "../include/funbox51a.h"

void main(void)
{
	unsigned char sw;

	last_key  = 0;	  			// Init with key pressed
	flat_stop = 0; 				// Init with status of "non-stopping"

	for (;;)
	{
		sw=getsw();
		if (sw !=0)
		{
			ledptn(sw);
			beepsnd(1000,50);
			delay(10000);
		}
	}
} /* main */
