#include <STC89.H>
#include "../include/library.h"
#include "../include/devices.h"
#include "../include/funbox51a.h"

void beepsnd(unsigned int freq, unsigned int dur_ms)
{
	PORT_BEEP = 0x00;
	delayms(dur_ms);
	PORT_BEEP = 0x10;						// Turn off the Beeper
} /* beepsnd */