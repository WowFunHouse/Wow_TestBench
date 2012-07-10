``#include <STC89.H>

void main(void)
{
	unsigned int t;
	unsigned     n;

    for(n=0;n<3;n++)
	{
	   P0=~0x48;
	   for(t=0;t<3000;t++);

	   P0=~0x00;
	   for(t=0;t<3000;t++);
	}
	  
	   if (n=3)
	   {
	     P0=~0x00;
	     for(t=0;t<40000;t++);
	   }
	    if(n=5)
	   {
	     P0=~0x00;
	     for(t=0;t<40000;t++);
		    }
}