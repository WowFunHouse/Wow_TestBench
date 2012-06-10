#include <STC89.H>

void delay(void);

void main(void)
{	
	unsigned int t;
	unsigned char col,row;
	
	for (;;)
	{
		col = 0xfe;				//1st P0 open
		row = 0x01; 			//1st P2 open
		delay();

		for(t=0; t<8; t++)
		{	
			P2 = col;
			P0 = row;
					
			row = row << 1;		//P2 move
			col = col << 1;		//P0 move 
			delay();
		}
	}
}

void delay(void)
{
	unsigned int t;
	for (t=0; t<30000; t++);
}

//void main (void)		 //test P2 and P0
//
//{
//	unsigned char t[2]={0x01,0x02};
//	unsigned char n;
//	unsigned int s;
//
//	for(;;)
//	{
//		for (n=0; n<2; n++)
//		{
//			P2 = 0xfc;
//			P0 = t[n];
//			for (s=0; s<30000; s++);
//		}
//	}
//}