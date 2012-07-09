#include <STC89.H>

void main(void)
{
    unsigned int t;
	unsigned   n;

    for(;;)
	{	
       for(n=0;n<6;n++)
	    { 
	     P0=~0x48;
		 for(t=0;t<30000;t++);

		 P0=~0x00;
		 for(t=0;t<30000;t++);
	    } 
	     
		
		 P0=~0x48;
		 for(t=0;t<50000;t++);
	
		 P0=~0x00;
	}
	  
}