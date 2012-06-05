/*	Title:			7-segment scanning display showcase
	Created on:		2012-05-29
	Created by:		Cathy
	Description:	Put the digit pattern in array digit[] and show it out with scanning		
*/
#include <STC89.H>

#define DIGIT_OFF		0xff
#define DIGIT_1			0xfe
#define DIGIT_2			0xfd
#define DIGIT_3			0xfb
#define DIGIT_4			0xf7
#define DELAY_Count 	50

void delay(unsigned int t);

void main(void)
{
	unsigned int digit[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x98};
	for(;;)
	{
		P1=DIGIT_OFF;
		P0=digit[2];
		P1=DIGIT_1;
		delay(DELAY_Count);

		P1=DIGIT_OFF;
		P0=digit[8];
		P1=DIGIT_2;
		delay(DELAY_Count);

		P1=DIGIT_OFF;
		P0=digit[3];
		P1=DIGIT_3;
		delay(DELAY_Count);

		P1=DIGIT_OFF;
		P0=digit[4];
		P1=DIGIT_4;
		delay(DELAY_Count);
	}
}
void delay(unsigned int t)
{
	unsigned int a;
	for(a=0;a<t;a++);
}  /*delay*/

