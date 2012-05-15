/*
  Title:		Get Switches Status
  Date: 		2012-05-15
  Created By:	Amanda Li
  Description:	Check the status of 4 switches and return 0 if none pressed

  Development Bd:	XT100 Mini 8x51 Development Board

  Port Config:		P2-Pin0 -> S3
  					P2-Pin1 -> S4
					P2-Pin2 -> S5
					P2-Pin3 -> S6

  Input  Value(s):	None
  Output Value(s):	1: S3
  					2: S4
					3: S5
					4: S6
					0: No Switch is pressed

 */

#include <STC89.H>
#include "../include/funbox51a.h"


unsigned char getsw(void)
{
	unsigned char	x, k;

	P2=0xFF;		// Pull Up the Output Pins to check Input

	x=P2;			// Check switch status
	x=x&0x0F;		// Filter out the junks
	
	switch (x)
	{
		 case 0x0E:		k=1;   		// Switch #3 is ON
		 				break;

		 case 0x0D:		k=2;	 	// Switch #4 is ON
		 				break;

		 case 0x0B:		k=3;	 	// Switch #5 is ON
		 				break;

		 case 0x07:		k=4; 		// Switch #6 is ON
		 				break;

		 default:		k=0;  		// No switch is pressed
		 				break;
	}
	return k;  						// Return the Switch status
} /* getsw() */

