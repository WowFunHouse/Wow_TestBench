/****************************************************************************
 Title:			Keyboard Scan
 
 File:			device_scankey.c	

 Version:		0.01
 Description:	

 Created on:	2013-10-14
 Created by:	Cathy

 Board:			RichMCU RZ-51V2.0

 Connections:	P1.0 -> P1.7 Keyboard S-0 -> S-F (0:On 1:Off)
		
 **************************************************************/
#include <STC89.H>
#include "lib_uty001.h"

unsigned char scankey(void)
{
	unsigned char cross, column,  key;

	P1 = 0xf0;											 //	 Set P1 -> 1111 0000

	cross = P1;											 //  Scanning cross
	if((cross & 0xf0)!=0xf0)
	{
		delay(4000);										// 	 Mask keyBounce

		cross = P1;										//	 Cross second scanning  
		if ((cross & 0xf0)!=0xf0)
		{
			P1 = 0x0f;
			column = P1;

			if ((column & 0x0f)!=0x0f)				   //	Scanning column
			{
				 key = cross | column ;		   //	Cross or Column
			}
			return (key);
		}
	}
}





