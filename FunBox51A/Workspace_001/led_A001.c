#include <STC89.H>
#include "../include/library.h"
#include "../include/funbox51a.h"

void ledptn(unsigned char pattern)
{
 unsigned int t;

 if (pattern == 1)
 {
  	P0 = 0x80;
	for (t=0; t<10000; t++);
	P0 = 0x40;
 	for (t=0; t<10000; t++);
	P0 = 0x20;
	for (t=0; t<10000; t++);
	P0 = 0x10;
  	for (t=0; t<10000; t++);
 }
 else if (pattern == 2)
 {
 }
 else if (pattern == 3)
 {
 }
 else if (pattern == 4)
 {
 }

}

