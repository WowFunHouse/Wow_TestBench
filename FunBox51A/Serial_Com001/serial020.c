#include <reg51.h>

void InitUART(void)
{
	// 9600 Baud, 8 Bit Data, No Parity, 1 Stop Bit

    TMOD = 0x20;
    SCON = 0x40;
    TH1 = 0xFD;
    TL1 = TH1;
    PCON = 0x00;
    TR1 = 1;
}

void SendOneByte(unsigned char c)
{
    SBUF = c;
    while(!TI);
    TI = 0;
}

void main(void)
{
	unsigned char c;

    InitUART();

	for (;;)
	{
		for (c=32; c<127; c++)
		{
			sendoneByte(c);
		}
		sendoneByte(0x0d);
		sendoneByte(0x0a);
	}		
}

