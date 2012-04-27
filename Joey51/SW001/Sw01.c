#include <STC89.H>

char led(char g)
{
 return ~g;
}

void main(void)
{
	int x;

	P2=0xFF;
	for(;;)
	{
	 x=P2;
	 x=x&0x0F;

	 if (x==0x0E) P0=led(0x03);
	 else if (x==0x0D) P0=led(0x0C);
	 else if (x==0x0B) P0=led(0x30);
	 else if (x==0x07) P0=led(0xC0);
	 else P0=led(0x00);
	}
}