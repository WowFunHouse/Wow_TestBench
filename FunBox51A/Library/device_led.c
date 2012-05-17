#include <STC89.H>
#include "../include/library.h"
#include "../include/devices.h"
#include "../include/funbox51a.h"

unsigned char led(unsigned char pattern)
{
	return	~pattern;
} /* led */

void ledAllOff(void)
{
	PORT_LED = led(0x00);
} /* ledAllOff */