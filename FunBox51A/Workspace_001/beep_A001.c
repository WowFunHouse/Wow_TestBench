#include <STC89.H>
#include "../include/library.h"
#include "../include/funbox51a.h"

void beepsnd(unsigned int freq, unsigned int dur_ms)
{
	P3 = 0x00;
	delayms(dur_ms);
	P3 = 0x10;						// Turn off the Beeper
}


	


