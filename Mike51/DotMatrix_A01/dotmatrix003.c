#include <STC89.H>

void main(void)
{
	unsigned char i, j;
	unsigned char row, col;
	unsigned int t;

	for (;;)
	{
		row=1;
		for (i=0; i<8; i++)
		{
			P0=row;

			col=1;
			for (j=0; j<8; j++)
			{
				P2=~col;
				col = col << 1;
				for (t=0; t< 10000; t++);
			}
			row = row << 1;
		}
  	}
}
