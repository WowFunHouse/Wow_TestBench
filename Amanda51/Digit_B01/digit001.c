#include <STC89.H>

//#define LETTER		5
//#define DIGIT_POIN	1 

unsigned char bcd[]={0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};			// Show english letter " A "

unsigned char digit[4]={0xFE, 0xFD, 0xFB, 0x07};

void main(void)
{

	unsigned char	t;

	for(;;)
	{
		P1 = 0xFF;					// All digit off
		P0 = ~bcd[0];
		P1 = digit[0];
		for(t=0; t<50; t++);

		P1 = 0xFF;					// All digit off
		P0 = ~bcd[1];
		P1 = digit[1];
		for(t=0; t<50; t++);

		P1 = 0xFF;					// All digit off
		P0 = ~bcd[2];
		P1 = digit[2];
		for(t=0; t<50; t++);

		P1 = 0xFF;					// All digit off
		P0 = ~bcd[3];
		P1 = digit[3];
		for(t=0; t<50; t++);
	}
}/* main */