#include <STC89.H>

void delay(void)
{
     unsigned int t;

     for (t=0;t<30000;t++);
 }

void main(void)
{
     unsigned char n;
	   
	 for (n=0;n<13;n++)
	 {
	   P0=~0x48;
	   delay();

	   P0=~0x00;
	   delay();
	 					
	 if((n==2)||(n==4)||(n==8)||(n==13))
	 {
	    delay();
	    delay();
	    delay();
	    delay();
		delay();
	 }
	 }
}

