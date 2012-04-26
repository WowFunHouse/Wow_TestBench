#include <STC89.H>

#define	LOOPS	30000

 unsigned char led(unsigned char n)
 {
	n=~n;
	return n;  	
 }

void delay(void)
{
	unsigned int a;

	for (a=0; a< LOOPS; a++);
}


void main(void)
{
	unsigned char	a;

	a=0;
	for(;;)
	{
		P0=led(a);
		delay();
		P0=led(0);
		delay();
		a++;
	}
}