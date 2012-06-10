   #include <STC89.H>
unsigned char hour, minute, second;
unsigned int click;
unsigned char clock[6];
unsigned char bcd[]={0x3F, 0x06, 0x5B, 0x4F, 0x66,
		     		 0x6D, 0x7D, 0x07, 0x7F, 0x67};
unsigned char digit[4] = {0xFE, 0xFD, 0xFB, 0x07};

void time2BCD(void);
void bin2BCD(unsigned char i, unsigned char *p);
void delay(void);

void main(void)
{
	click = 0;

	hour = 3;
	minute = 19;
	second = 40;

	TMOD = T0_M1;
	TH0 = (65536 - 9216) >> 8;
	TL0 = (65536 - 9216) % 256;

	ET0 = 1;
	EA = 1;
	TR0 = 1;
	   	
	for (;;)
	{
		time2BCD();

		P0 = 0xFF;
		P0 = ~bcd[ clock[2] ];
		P1 = digit[0];
		delay();
	
		P0 = 0xFF;
		P0 = ~bcd[ clock[3] ];
		P1 = digit[1];
		delay();

		P0 = 0xFF;
		P0 = ~bcd[ clock[4] ];
		P1 = digit[2];
		delay();

		P0 = 0xFF;
		P0 = ~bcd[ clock[5] ];
		P1 = digit[3];
		delay();

		P0 = 0xFF;
	}
}

void timer0(void) interrupt 1
{
	if (++click >= 100)
	{
		click = 0;
		if ( ++second > 59)
		{
			second = 0;
			minute++;
		}
		if ( minute >59)
		{
			minute = 0;
			hour++;
		}
		if (hour > 59)
		{
			hour = 0;
			minute = 0;
			second = 0;
		}
	}
	TH0 = (65536 - 9216) >> 8;
	TL0 = (65536 - 9216) % 256;
}

void bin2BCD(unsigned char i, unsigned char *p)
{	
	*p     = i / 10;
	*(p+1) = i % 10;
}
	 
void time2BCD(void)
{
	bin2BCD(hour, clock);
	bin2BCD(minute, clock+2);
	bin2BCD(second, clock+4);
}

void delay(void)
{
	unsigned int t;
	for (t=0; t<1000; t++);
}
