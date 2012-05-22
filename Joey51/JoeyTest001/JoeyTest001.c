#include <STC89.H>
char led (char g)
{
return ~g;
}
void  main (void)
{
	int x;
	P2=0xFF;
	for(; ;)
	{
	x=P2;
	x=x&0xFF;
	if (x==0x0D) P0=led(0x01);
	else if (x==0x0E) P0=led(0x02);
	else if (x==0x07) P0=led(0x04);
	else if (x==0xFC) P0=led(0x80);
	else P0=led (0x00);
	}
}
