#include <STC89.H>

 unsigned char bcd[6]={0x77,0x7C,0x39,0x5E,0x79,0x71};
 unsigned char digit[4]={0xFE,0xFD,0xFB,0x07};
 
 void main(void)
{
  
  unsigned  t;

  for(;;)
  {
	    
	
		P0=~bcd;
		P1=digit[0];
		for (t=0;t<8000;t++);
	
		P0=0xFF;
	
		P0=~bcd;
		P1=digit[1];
		for (t=0;t<8000;t++);

		P0=0xFF;

		P0=~bcd;
		P1=digit[2];
		for (t=0;t<8000;t++);
	
		P0=0xFF;
	
		P0=~bcd;
		P1=digit[3];
		for (t=0;t<8000;t++);
	}
}