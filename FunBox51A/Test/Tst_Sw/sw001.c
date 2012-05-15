#include <STC89.H>

#include "../include/funbox51a.h"

unsigned char getsw(void)
{
	unsigned char	x;

	P2=0xFF;
//	for(;;)
//	{
		x=P2;
		x=x&0x0F;

		if(x==0x0E)			return 1;
		else if(x==0x0D)	return 2;
		else if(x==0x0B)	return 3;
		else if(x==0x07)	return 4;
		else				return 0;
//	}
}