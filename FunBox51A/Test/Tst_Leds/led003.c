/*
 Title:		LED related routines
 Created on:	2012-05-22
 Created by:	Joey
 */
#include <STC89.H>
#include "../../include/funbox51a.h"

#define	DELAY_TIME	500
#define	DELAY_ME	delayms(DELAY_TIME);

#define	CHECK_PTN1	if (pattern == 1)

/*
 Description:	To display different LED patterns accroding to input

 Input:		1, 2, 3, 4
 Output:	None
*/
void ledptn(unsigned char pattern)
{
 	unsigned int t;

	CHECK_PTN1
 	{
  		P0 = 0x01;
 		DELAY_ME
		P0 = 0x02;
 		DELAY_ME
		P0 = 0x04;
		DELAY_ME
		P0 = 0x80;
  		DELAY_ME
 	}
 	else if (pattern == 2)
 	{
 		P0=0x80;
		DELAY_ME
		P0=0x20;
		DELAY_ME
		P0=0x40;
		DELAY_ME
		P0=0x01;
		DELAY_ME	
 	}
	else if (pattern == 3)
 	{
		P0=0x01;
		DELAY_ME
		P0=0x42;
		DELAY_ME
   		P0=0x24;
		DELAY_ME
		P0=0x18;
		DELAY_ME
 	}
 	else if (pattern == 4)
 	{
		P0=0x18;
		DELAY_ME
		P0=0x24;
		DELAY_ME
		P0=0x42;
		DELAY_ME
		P0=0x81;
		DELAY_ME
 	}

} /* ledptn */

