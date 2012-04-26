#include <STC89.H>

#define	ALOOPS	50000
#define	BLOOPS	30000

 unsigned char led(unsigned char n)
 {
	n=~n;
	return n;  	
 }

void delay(unsigned int t)
{
	unsigned int a;
	for (a=0; a<t; a++);
}

void delaya(void)
{
	unsigned int a;

	for (a=0; a< ALOOPS; a++);
}


  void delayb(void)
{
	unsigned int a;

	for (a=0; a< BLOOPS; a++);
}


void main(void)
{
	unsigned char	a;

	a=0;
	for(;;)
	{
		P0=led(a);
		delay(ALOOPS);

		P0=led(0);
		delay(30000);
		P0=led(3);
		delay(15000);
		P0=led(12);
		delay(7500);
		P0=led(48);
		delay(3500);
		P0=led(192);
		delay(1750);
		P0=led(0);
		delay(800);

		a++;
	}
}