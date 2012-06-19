#include <STC89.H>

unsigned char english[]={0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x00, 0x77, 0x7C, 0x39};

unsigned char digit[4]={0xFE, 0xFD, 0xFB, 0x07};

void main(void)
{
	unsigned char	digit_shift;

	unsigned char	n; 
	unsigned int	t, a;

	digit_shift = 0;
	for(;;)
	{
		if(digit_shift<7)
		{
			for(a=0; a<500; a++)
			{
				for(n=0; n<4; n++)
				{
					P0 = 0xFF;					// All digit off
		
					P0 = ~english[n + digit_shift];
					P1 = digit[n];
					for(t=0; t<50; t++); 
				}
			}
	
			P0 = 0xFF;
			digit_shift++;
		}
		else
		{
			digit_shift = 0;
		}
	}
}/* main */