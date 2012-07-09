#include <STC89.H>
#include "../Common51/c:n51.h"


void main(void)
{
   unsigned char hex[]={0xBF,0x06,0x5B,0xCF,0x66,0xED,0xFD,0x07,0xFF,0xE7};
   unsigned char n,a,b;
   unsigned char last;
	  
   P20=1;							  
   
   for (;;)
   {
	   for (n=1; n<43; n++);
	   {
		    if (P20==0)
			{
		       n=last;
			 }
		    else 
			 { 
			    last=n;
             }
                a=n%10;
                b=n/10;

                P1=0xFF;
                P0=hex[a];
                P1=0x07;
				delayms(10);			

                P1=0xFF;
                P0=hex[b];
                P1=0x0b;
				delayms(10);			    
	   }
   }
}