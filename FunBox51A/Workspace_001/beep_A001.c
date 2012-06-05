#include <STC89.H>
#include "../include/library.h"
#include "../include/devices.h"
#include "../include/funbox51a.h"

void beepsnd(unsigned int freq, unsigned int dur_ms)
{	unsigned int a,b;
	for(a=0;a<dur_ms;a++)
	{
		beepON();
		for(b=0;b<freq;b++);
		beepOFF();
		for(b=0;b<freq;b++);
	}
} /* beepsnd */