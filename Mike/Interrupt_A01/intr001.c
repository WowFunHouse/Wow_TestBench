#include <STC89.H>

#define	KEY_ON	0
#define KEY_OFF	1

unsigned char	stop;

void delay1ms(void)   //Îó²î 0us
{
    unsigned char a,b;
    for(b=199;b>0;b--)
        for(a=1;a>0;a--);
}

void delayms(unsigned int time)
{
	unsigned int t;

	for (t=0; t<time; t++) delay1ms();
}

void ledOn(void)
{
	P0=0x00;
}

void ledOff(void)
{
	P0=0xff;
}

void main(void)
{
	unsigned char p;

	P2=0xff;

	stop=0;
	p=0;

	EA=1;
	EX0=1;

	for (;;)
	{
		P0=p++;
		delayms(50);

		for (; stop !=0; );
	}
} /* main */

void blink(void)
{
	P0=0x00;
	delayms(500);
	P0=0xff;
	delayms(500);
}

void waitkey(void) interrupt 0 using 2
{
	EA=0;
	blink();
	blink();
	blink();
/*
	if (stop == 0) stop=1;
	else stop=0;
*/
	EA=1;
}
