#include <STC89.H>

#include "../include/funbox51a.h"

void main()
{
 unsigned int n, t;

 n = 0;
 for (;;)
 {
	if (getsw() != 0) n++;	  // Count how many times key pressed
	P0 = ~n;
	for (t=0; t < 10000; t++);
 }
}
