/*
 Title:		LED related routines
 Created on:	2012-05-22
 Created by:	Joey
 */
#include <STC89.H>
#include "../include/library.h"
#include "../include/funbox51a.h"

#define	DELAY_TIME	500

/*
 Description:	To display different LED patterns accroding to input

 Input:		1, 2, 3, 4
 Output:	None
*/
void ledptn(unsigned char pattern)
{
 	if (pattern == 1)
 	{
  		PORT_LED=0x01; delayms(DELAY_TIME);
		PORT_LED=0x02; delayms(DELAY_TIME);
		PORT_LED=0x04; delayms(DELAY_TIME);
		PORT_LED=0x08; delayms(DELAY_TIME);
		PORT_LED=0x10; delayms(DELAY_TIME);
		PORT_LED=0x20; delayms(DELAY_TIME);
		PORT_LED=0x40; delayms(DELAY_TIME);
		PORT_LED=0x80; delayms(DELAY_TIME);
 	}
 	else if (pattern == 2)
 	{
 		PORT_LED=0x80; delayms(DELAY_TIME);
		PORT_LED=0x20; delayms(DELAY_TIME);
		PORT_LED=0x40; delayms(DELAY_TIME);
		PORT_LED=0x10; delayms(DELAY_TIME);	
		PORT_LED=0x08; delayms(DELAY_TIME);
		PORT_LED=0x04; delayms(DELAY_TIME);
		PORT_LED=0x02; delayms(DELAY_TIME);
	   	PORT_LED=0x01; delayms(DELAY_TIME);
 	}
	else if (pattern == 3)
 	{
		PORT_LED=0x81; delayms(DELAY_TIME);
		PORT_LED=0x42; delayms(DELAY_TIME);
   		PORT_LED=0x24; delayms(DELAY_TIME);
		PORT_LED=0x18; delayms(DELAY_TIME);
 	}
 	else if (pattern == 4)
 	{
		PORT_LED=0x18; delayms(DELAY_TIME);
		PORT_LED=0x24; delayms(DELAY_TIME);
		PORT_LED=0x42; delayms(DELAY_TIME);
		PORT_LED=0x81; delayms(DELAY_TIME);
 	}
} /* ledptn */
