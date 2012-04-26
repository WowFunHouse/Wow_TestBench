#include <STC89.H>

 unsigned char led(unsigned char n)
 {
	n=~n;
	return n;  	
 }

void delay(void)
{
	unsigned int a;

	for (a=0; a< 60000; a++);
}


void main(void)
{
	unsigned char	a;

	a=0;
	for(;;)
	{
		P0=led(a);
		delay();
		a++;
	}
}