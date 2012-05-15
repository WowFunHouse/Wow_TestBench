#include <STC89.H>

#include "../include/funbox51a.h"

void main()
{
 for (;;)
 {
	P0 = ~getsw();
 }
}
