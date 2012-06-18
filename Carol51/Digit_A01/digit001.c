#include <STC89.H>

unsigned char a[4]={0x77,0x7C,0x39,0x5E};                   
unsigned char digit[4]={0xFE,0xFD,0xFB,0x07};

void main (void)
{ 
   unsigned int t;	   
   unsigned b ;

   for(;;)
 
    {
	   
		P0=~a[0];
		P1=digit[0];
		for (t=0;t<30000;t++);
	
        P0=~a[1];
	    P1=digit[1];
        for(t=0;t<30000;t++);

        P0=~a[2];
        P1=digit[2];

		P0=~a[3];
		P1=digit[3];

	 }
  
   for(b=0;b<4;b++); 
}
