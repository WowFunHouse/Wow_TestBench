#include <STC89.H>
#include "../include/library.h"
#include "../include/devices.h"
#include "../include/funbox51a.h"

#define	DELAY_TIME	500

void ledptn(unsigned char pattern)
{
	if (pattern == 1)
 	{
		PORT_LED = led(0x80); delayms(DELAY_TIME);
		if(flag_stop != 0)	return;

  		PORT_LED = led(0x40); delayms(DELAY_TIME);
  		PORT_LED = led(0x20); delayms(DELAY_TIME);
  		PORT_LED = led(0x10); delayms(DELAY_TIME);
  		PORT_LED = led(0x08); delayms(DELAY_TIME);
  		PORT_LED = led(0x04); delayms(DELAY_TIME);
  		PORT_LED = led(0x02); delayms(DELAY_TIME);
  		PORT_LED = led(0x01); delayms(DELAY_TIME);
 	}
 	else if (pattern == 2)
 	{
		PORT_LED = led(0x01); delayms(DELAY_TIME);
  		PORT_LED = led(0x02); delayms(DELAY_TIME);
  		PORT_LED = led(0x04); delayms(DELAY_TIME);
  		PORT_LED = led(0x08); delayms(DELAY_TIME);
  		PORT_LED = led(0x10); delayms(DELAY_TIME);
  		PORT_LED = led(0x20); delayms(DELAY_TIME);
  		PORT_LED = led(0x40); delayms(DELAY_TIME);
  		PORT_LED = led(0x80); delayms(DELAY_TIME);
	}
	else if (pattern == 3)
 	{
		PORT_LED = led(0x81); delayms(DELAY_TIME);
  		PORT_LED = led(0x42); delayms(DELAY_TIME);
  		PORT_LED = led(0x24); delayms(DELAY_TIME);
  		PORT_LED = led(0x18); delayms(DELAY_TIME);
 	}
	else if (pattern == 4)
	{
		PORT_LED = led(0x18); delayms(DELAY_TIME);
  		PORT_LED = led(0x24); delayms(DELAY_TIME);
  		PORT_LED = led(0x42); delayms(DELAY_TIME);
  		PORT_LED = led(0x81); delayms(DELAY_TIME);
	}
} /* ledptn	*/