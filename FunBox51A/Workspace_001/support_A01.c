#include <STC89.H>
#include "../include/library.h"
#include "../include/funbox51a.h"

unsigned char	FlagStop;			// 0: continue	!0: stop
unsigned char	LastKey;		 	// last switch pressed

/* Check if the key pressed has been changed
	0: Continue (no changes)
	1: Key status changes - update the last_key with new key value
*/
void setFlag(void)
{
	unsigned char	sw;

	sw = getsw();

	if (sw == 0)				// No key pressed
	{
		FlagStop = 1;			// Flag up for stopping
	} 
	else
	{
		FlagStop = 0;			// Continue
	}
	LastKey = sw;				// remember the changes
} /* setFlag */

unsigned char chkFlag(void)
{
	if (FlagStop != 0) return 1;
	else return 0;
} /* chkFlag */
