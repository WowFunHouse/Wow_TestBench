/*
 Title:		LED related routines
 Created on:	2012-05-22
 Created by:	Joey
 */
#include <STC89.H>
#include "../include/library.h"
#include "../include/devices.h"
#include "../include/funbox51a.h"

#define	DELAY_TIME	500

/*
 Descrition:	To display different LED patterns accroding to input

 Inut:		1, 2, 3, 4
 Outut:	None
*/
void ledptn(unsigned char pattern)
{
 	if (pattern == 1)
 	{
		setFlag();
		if (chkFlag() == 0) { PORT_LED=led(0x01); delayms(DELAY_TIME);}
		setFlag();
		if (chkFlag() == 0) { PORT_LED=led(0x02); delayms(DELAY_TIME);}
		setFlag();
		if (chkFlag() == 0) { PORT_LED=led(0x04); delayms(DELAY_TIME);}
		setFlag();
		if (chkFlag() == 0) { PORT_LED=led(0x08); delayms(DELAY_TIME);}
		setFlag();
		if (chkFlag() == 0) { PORT_LED=led(0x10); delayms(DELAY_TIME);}
		setFlag();
		if (chkFlag() == 0) { PORT_LED=led(0x20); delayms(DELAY_TIME);}
		setFlag();
		if (chkFlag() == 0) { PORT_LED=led(0x40); delayms(DELAY_TIME);}
		setFlag();
		if (chkFlag() == 0) { PORT_LED=led(0x80); delayms(DELAY_TIME);}
 	}
 	else if (pattern == 2)
 	{
		setFlag();
 		if (chkFlag() == 0) { PORT_LED=led(0x80); delayms(DELAY_TIME);}
		setFlag();
		if (chkFlag() == 0) { PORT_LED=led(0x40); delayms(DELAY_TIME);}
		setFlag();
		if (chkFlag() == 0) { PORT_LED=led(0x20); delayms(DELAY_TIME);}
		setFlag();
		if (chkFlag() == 0) { PORT_LED=led(0x10); delayms(DELAY_TIME);}	
		setFlag();
		if (chkFlag() == 0) { PORT_LED=led(0x08); delayms(DELAY_TIME);}
		setFlag();
		if (chkFlag() == 0) { PORT_LED=led(0x04); delayms(DELAY_TIME);}
		setFlag();
		if (chkFlag() == 0) { PORT_LED=led(0x02); delayms(DELAY_TIME);}
		setFlag();
	   	if (chkFlag() == 0) { PORT_LED=led(0x01); delayms(DELAY_TIME);}
 	}
	else if (pattern == 3)
 	{
		setFlag();
		if (chkFlag() == 0) { PORT_LED=led(0x81); delayms(DELAY_TIME);}
		setFlag();
		if (chkFlag() == 0) { PORT_LED=led(0x42); delayms(DELAY_TIME);}
		setFlag();
   		if (chkFlag() == 0) { PORT_LED=led(0x24); delayms(DELAY_TIME);}
		setFlag();
		if (chkFlag() == 0) { PORT_LED=led(0x18); delayms(DELAY_TIME);}
		setFlag();
 	}
 	else if (pattern == 4)
 	{
		setFlag();
		if (chkFlag() == 0) { PORT_LED=led(0x18); delayms(DELAY_TIME);}
		setFlag();
		if (chkFlag() == 0) { PORT_LED=led(0x24); delayms(DELAY_TIME);}
		setFlag();
		if (chkFlag() == 0) { PORT_LED=led(0x42); delayms(DELAY_TIME);}
		setFlag();
		if (chkFlag() == 0) { PORT_LED=led(0x81); delayms(DELAY_TIME);}
		setFlag();
 	}
} /* ledptn */
