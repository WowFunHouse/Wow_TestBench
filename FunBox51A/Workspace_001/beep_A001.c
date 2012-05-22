#include <STC89.H>
#include "../include/library.h"
#include "../include/devices.h"
#include "../include/funbox51a.h"

void beepsnd(unsigned int freq, unsigned int dur_ms)
{
	beepON();
	delayms(dur_ms);
	beepOFF();						// Turn off the Beeper
} /* beepsnd */