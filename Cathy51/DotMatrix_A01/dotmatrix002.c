#include <STC89.H>

void delay (void);

void main (void)
{	
	unsigned char ptn;
	unsigned char t;

	P0 = 0x01;					  //1st P0 open
	for(;;)
	{	
		ptn = 1;				  //P2 turn off
		for (t=0; t<8; t++)
		{
			P2 = ~ptn;
			ptn = ptn << 1;		  //P2 move
			delay();	
		}
	}
}

void delay(void)
{
	unsigned int t;
	for (t=0; t<20000; t++);
}