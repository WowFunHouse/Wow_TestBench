/**********************************
 Dofly LY-51S

 Stepping motor test

 P10 -> J42-6 -> Stepping Motor:2
 P11 -> J42-5 -> Stepping Motor:3
 P12 -> J42-4 -> Stepping Motor:4
 P12 -> J42-3 -> Stepping Motor:5

 **********************************/

#include <STC89.H>

void main(void)
{
	unsigned char motorphase[]={0x01, 0x02, 0x04, 0x08};
	
	unsigned char n;
	unsigned int  t;
		
	for (;;)
	{
		for (n=0; n<4; n++)
		{
			P1=motorphase[n];
			for (t=0; t<1000; t++);
		}
	}
}
