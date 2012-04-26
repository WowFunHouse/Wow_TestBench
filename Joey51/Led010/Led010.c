#include <STC89.H>

#define	ALOOPS	50000
#define	BLOOPS	30000

 unsigned char led(unsigned char n)
 {
	n=~n;
	return n;  	
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
		delaya();
		P0=led(0);
		delayb();
		a++;
	}
}