#include <STC89.H>

#define	DIGIT_OFF	0xFF
#define	DIGIT_1		0xFE
#define DIGIT_2		0xFD
#define DIGIT_3		0xFB
#define DIGIT_4		0xF7


void delay(unsigned int t);

void main(void)
{
 	unsigned char digit[]={0xC0,0xF9,0xA4,0xB0,0x99,
						   0x92,0x82,0xF8,0x80,0x98};
   {
	for(;;)
	P1=DIGIT_OFF;
	P0=digit[1];
	P1=DIGIT_1;
	delay(50);

	P1=DIGIT_OFF;
	P0=digit[2];
	P1=DIGIT_2;
	delay(50);

	P1=DIGIT_OFF;
	P0=digit[3];
	P1=DIGIT_3;
	delay(50);

	P1=DIGIT_OFF;
	P0=digit[4];
	P1=DIGIT_4;
	delay(50);
 	}
 }

void delay(unsigned int t)
{
	unsigned int x;
	for (x=0; x<t; x++);
}