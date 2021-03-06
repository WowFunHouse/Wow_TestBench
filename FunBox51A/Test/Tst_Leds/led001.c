/*
 Title:		LED related routines
 Created on:	2012-05-22
 Created by:	Joey
 */
#include <STC89.H>
#include "../../include/funbox51a.h"

/*
 Description:	To display different LED patterns accroding to input

 Input:		1, 2, 3, 4
 Output:	None
*/
void ledptn(unsigned char pattern)
{
 	unsigned int t;

 	if (pattern == 1)
 	{
  		P0 = 0x01;
 		for (t=0; t<10000; t++);
		P0 = 0x02;
 		for (t=0; t<10000; t++);
		P0 = 0x04;
		for (t=0; t<10000; t++);
		P0 = 0x80;
  		for (t=0; t<10000; t++);
 	}
 	else if (pattern == 2)
 	{
 		P0=0x80;
		for (t=0; t<10000; t++);
		P0=0x20;
		for (t=0; t<10000; t++);
		P0=0x40;
		for (t=0; t<10000; t++);
		P0=0x01;
		for (t=0; t<10000; t++);	
 	}
	else if (pattern == 3)
 	{
		P0=0x01;
		for (t=0; t<10000; t++);
		P0=0x42;
		for (t=0; t<10000; t++);
   		P0=0x24;
		for (t=0; t<10000; t++);
		P0=0x18;
		for (t=0; t<10000; t++);
 	}
 	else if (pattern == 4)
 	{
		P0=0x18;
		for (t=0; t<10000; t++);
		P0=0x24;
		for (t=0; t<10000; t++);
		P0=0x42;
		for (t=0; t<10000; t++);
		P0=0x81;
		for (t=0; t<10000; t++);
 	}

} /* ledptn */

