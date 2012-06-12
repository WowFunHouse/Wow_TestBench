#include <STC89.H>

void main(void)
{
	unsigned char	row[]={	0x99, 0x5A, 0x3C, 0xFF,
							0xFF, 0x3C, 0x5A, 0x99};

	unsigned char	column, n;

	unsigned int	t;

	for(;;)
	{
		column = 1;
		for(n=0; n<8; n++)
		{
			P0 = column;
			column = column << 1;
			P2 = ~row[n];
			for(t=0; t<100; t++);
			P2 = 0xFF;
//			for(t=0; t<60000; t++);
		}
	}
}