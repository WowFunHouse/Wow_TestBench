#include <STC89.H>

void delay(void);

void main (void)
{
	unsigned char t,n;
	unsigned char row, col;

	for (;;)
	{
		row = 0x01;						//P0 1st open
		for (n=0; n<8; n++)	  		
		{
			P0 = row;
			row = row << 1;				//P0 move
		
			col = 1;					//P2 turn off
			for (t=0; t<8; t++)	   	
			{
				P2 = ~col;				//P2 open
				col = col << 1;		 	//P2 move
				delay();
			}			
		}
	}	
}

void delay(void)
{
	unsigned int t;
	for (t=0; t<20000; t++);
}