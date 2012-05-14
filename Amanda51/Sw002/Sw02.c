#include <STC89.H>

<<<<<<< HEAD
int led(int x)
=======
char led(char x)        // Ms: You define the parameter as char type here
>>>>>>> ce849c292f3360223c03ce84613c641d2215eac7
{
	return	~x;
}

void delay(int t)
{
	int		x;

	for(x=1; x<t; x++);
}

void swicha(void)
{
	char	a;
	int		n;

	a=0x01;

	//for(;;){
		for(n=0; n<=8; n++)
		{
			P0=led(a<<n);
			delay(20000);
		}
	//}
}

void swichb(void)
{
<<<<<<< HEAD
	char	a;
=======
	int 	a;      // Ms: Should use char type, instead of int
>>>>>>> ce849c292f3360223c03ce84613c641d2215eac7
	int		n;

	a=0x80;

	//for(;;){
		for(n=0; n<=8; n++)
		{
			P0=led(a>>n);
			delay(20000);
		}
	//}
}

void swichc(void)
{
	//for(;;){
		P0=led(0x81);
		delay(20000);
		P0=led(0x42);
		delay(20000);
		P0=led(0x24);
		delay(20000);
		P0=led(0x18);
		delay(20000);
	//}
}

void swichd(void)
{
	//for(;;){
		P0=led(0x18);
		delay(20000);
		P0=led(0x24);
		delay(20000);
		P0=led(0x42);
		delay(20000);
		P0=led(0x81);
		delay(20000);
	//}
}

void main(void)
{
<<<<<<< HEAD
	char	x;

=======
	int		x;          /* Ms: Should use char type (1-byte) instead of int (2-byte) */
    
>>>>>>> ce849c292f3360223c03ce84613c641d2215eac7
	P2=0xFF;

	for(;;)
	{
		x=P2;
		x=x&0x0F;

		if		(x==0x0E)		swicha();
		else if	(x==0x0D)		swichb();
		else if	(x==0x0B)		swichc();
		else if	(x==0x07)		swichd();

		else 					P0=led(0x00);
	}
}