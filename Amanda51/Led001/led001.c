#include <STC89.H>

main()
{
	int		x;
	char	a;

	a=0;
	for(;;)
	{P0=a;
		for(x=0;x<30000;x++);
		a++;
	}
}