#include "reg51.h"	
sbit L0=0x94;
sbit L1=0x95;
sbit L2=0x96;
sbit L3=0x97;
char one=0;
char zero=0;
unsigned char KeyTemp=0xff;
unsigned char KeyData=0xff;
unsigned char key;

void delay();

void delay()
{
	int t;

	for (t=0; t<30000; t++);

} /* delay */

main()
{ 

  unsigned char c=0;

  IE=0x90;
  TMOD=0x20;
  TH1=250;
  PCON&=0x7f;
  SCON=0x50;
  TR1=1;

  while(1)
    {		c=~c;
			P0=c;
			P1=c;
			P2=c;
			SBUF=c;
			delay();
    }  
} /* main */

void SCON_int(void) interrupt 4	
{
  if(TI==1)
      TI=0;
  else
    {
      RI=0;
      key=SBUF;
	  if(key==0x01)
	  	L0=~L0;
	  else if(key==0x02)
	  	L1=~L1;
	  else if(key==0x04)
	  	L2=~L2;
	  else if(key==0x08)
	  	L3=~L3;
	  key=0xff;
    } 	
} /* SCON_int */	

    
  
