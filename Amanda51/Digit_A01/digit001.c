#include <STC89.H>

#define	DIGIT_OFF	0xFF
#define	DIGIT_1		0xFE
#define DIGIT_2		0xFD
#define DIGIT_3		0xFB
#define DIGIT_4		0xF7

#define	DELAY_COUNT	50

void delay(unsigned int cnt);

void main(void)
{
 	unsigned char	digit[]={0xc0, 0xf9, 0xa4, 0xb0, 0x99,
							0x92, 0x82, 0xf8, 0x80, 0x98};

	/* to show digit: 1 2 3 4 */

	for (;;)
	{
		P1 = DIGIT_OFF;		// All digit off
		P0 = digit[1];
		P1 = DIGIT_1;
		delay(DELAY_COUNT);
		
		P1 = DIGIT_OFF;
		P0 = digit[2];
		P1 = DIGIT_2;
		delay(DELAY_COUNT);
	
		P1 = DIGIT_OFF;
		P0 = digit[3];
		P1 = DIGIT_3;
		delay(DELAY_COUNT);
	
		P1 = DIGIT_OFF;
		P0 = digit[4];
		P1 = DIGIT_4;
		delay(DELAY_COUNT);
	}
	
} /* main */

void delay(unsigned int cnt)
{
	unsigned int t;

	for (t=0; t<cnt; t++);
} /* delay */