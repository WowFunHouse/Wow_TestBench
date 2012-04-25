#include <STC89.H>

main()
{
	unsigned int x;
	unsigned char a;

	a=0;
	for(;;)
	{
		P0=a;
		for(x=0;x<65535;x++);
		a++;
	}
}