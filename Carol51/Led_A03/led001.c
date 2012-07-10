#include <STC89.H>

void main(void)
{
   unsigned char n;
   unsigned int t;	 

   for(;;)
   {
         for (n=0;n<5;n++)
       {
           P0=~0x48;
	       for(t=0;t<20000;t++);
	       P0=~0x00;
           for(t=0;t<20000;t++);
	   }
	       P0=~0x48;
	       for(t=0;t<50000;t++);

	       P0=~0x00;
           for(t=0;t<20000;t++);
	   }

}