#include <STC89.H>

//#define LETTER		5
//#define DIGIT_POIN	0 

unsigned char bcd[]={0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};			// Show english letter " A "

unsigned char digit[4]={0xFE, 0xFD, 0xFB, 0x07};

void main(void)
{

	unsigned char	n; 
	unsigned int	t;

	for(;;)
	{
		for(n=0; n<6; n++)
		{
			P1 = 0xFF;					// All digit off

			P0 = ~bcd[n];
			for(t=0; t<32500; t++);

			P1 = digit[0];
			for(t=0; t<32500; t++); 
		}
	}
}/* main */