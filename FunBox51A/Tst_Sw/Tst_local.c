#include <STC89.H>

#include "../include/funbox51a.h"

void main()
{
	P0 = ~getsw();
}