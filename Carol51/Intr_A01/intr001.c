#include <STC89.H>

void showled(void) interrupt 2 using 2
{
   unsigned int t;

     P0=0x7E;for(t=0;t<8000;t++);
	 P0=0xBD;for(t=0;t<8000;t++);
	 P0=0xDB;for(t=0;t<8000;t++);
	 P0=0xE7;for(t=0;t<8000;t++);
	 P0=0xDB;for(t=0;t<8000;t++);
	 P0=0xBD;for(t=0;t<8000;t++);
	 P0=0x7E;for(t=0;t<8000;t++);
}
void main(void)
{
	EX1=1;
	EA=1;
	
	for(;;);
}