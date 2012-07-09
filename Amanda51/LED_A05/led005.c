#include <STC89.H>

char led(char n)
{
	return	~n;
}

void delay(unsigned int t)
{
	int	a;

	for(a=1; a<t; a++);
}
						
void swicha(void)
{
	int 	a;
	int		n;

	a=0x01;

	for(n=0; n<=7; n++)
	{
		P0=led(a<<n);
		delay(20000);
	}
}

void mian(void)
{
	int		x;

	P2=0xFF;

	x=P2;
	x=x&0x0F;

	if(x==0x0E)		swicha();
}