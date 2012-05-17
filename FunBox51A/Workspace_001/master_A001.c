#include <STC89.H>
#include "../include/library.h"
#include "../include/funbox51a.h"

void main(void)
{
	unsigned char sw;

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
