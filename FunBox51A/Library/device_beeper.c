#include <STC89.H>
#include "../include/devices.h"

void beepOFF(void)
{
	PORT_BEEP = 0x10;
}

void beepON(void)
{
	PORT_BEEP = 0x00;
}
