#include <STC89.H>
#include "../include/library.h"
#include "../include/funbox51a.h"

unsigned char	flag_stop;			// 0: continue	!0: stop
unsigned char	last_key;		 	// last switch pressed

/* Check if the key pressed has been changed
	0: Continue (no changes)
	1: Key status changes - update the last_key with new key value
*/
void setflag(void)
{
	unsigned char	sw;

	sw = getsw();

	flag_stop = 0;					// Continue

	if (sw != last_key)	
	{
		flag_stop = 1;	// Flag up for stopping
		last_key  = sw;	// remember the changes
	} 
} /* setflag */

unsigned char chkflag(void)
{
	if (flag_stop != 0) return 1;
	else return 0;
}