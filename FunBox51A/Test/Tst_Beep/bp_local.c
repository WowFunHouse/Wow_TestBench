#include <STC89.H>
#include "../../include/funbox51a.h"

void main(void)
{
	unsigned int d;

	for(;;)
	{
		beepsnd(1000, 50);

		P3=0x10;
		for (d=1; d<30000; d++);
	}
}
