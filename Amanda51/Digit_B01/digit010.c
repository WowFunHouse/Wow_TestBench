#include <STC89.H>

//#define LETTER		5
//#define DIGIT_POIN	0 

unsigned char seven[6][4]={{0x77, 0x7C, 0x39, 0x5E},
						{0x7C, 0x39, 0x5E, 0x79},
						{0x39, 0x5E, 0x79, 0x71},
						{0x5E, 0x79, 0x71, 0x77},
						{0x79, 0x71, 0x77, 0x7C},
						{0x71, 0x77, 0x7C, 0x39}};

unsigned char digit[4]={0xFE, 0xFD, 0xFB, 0x07};

void main(void)
{

	unsigned char	a, b; 
	unsigned int	t;

	for(;;)
	{
		for(a=0; a<6; a++)
		{
			for(b=0; b<4; b++)
			{
				P1 = 0xFF;					// All digit off

				P0 = ~seven[a][b];
				P1 = digit[b];
				for(t=0; t<1000; t++);
			}	 
		}
	}
}/* main */