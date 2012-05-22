#include <STC89.H>

void main(void)
{
 long int a;

 a = 0x38;
 P0 = a;
 a = a - 5;
 P0 = a;
}

