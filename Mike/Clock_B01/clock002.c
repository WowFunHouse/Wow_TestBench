#include <STC89.H>
 
unsigned char hour, minute, second;		// Real clock values
unsigned char clock[6];					// Buffer of the clock digits

unsigned char bcd[]={0x3F, 0x06, 0x5B, 0x4F, 0x66,
		     		 0x6D, 0x7D, 0x07, 0x7F, 0x67};

unsigned char digit[4]={0xFE, 0xFD, 0xFB, 0x07};	// LED digit selection from Left->Right

unsigned int  click; 					// 10ms click counter

void time2BCD(void);					// Prototype to convert time value to 2=digit BCD

void main(void)
{
	click = 0;

	hour   = 0;	 						// Start time
	minute = 0;
	second = 0;
	
	TMOD = T0_M1;						// Set Timer0 to mode 1
	TH0  = (65536 - 10000) >> 8;		// 10ms heartbeat (12MHz X'tal)
	TL0  = (65536 - 10000) % 256;

	ET0  = 1;		// Enable Timer0
	EA   = 1;		// Enable all interrupts

	TR0  = 1;		// Enable Timer0

	for (;;)
	{
	   	time2BCD();

		P0 = 0xFF;				// Turn off the digit
		P0 = ~bcd[ clock[2] ];	// Set the segments of LED
		P1 = digit[0];			// Turn on the digit

		P0 = 0xFF;				// Turn off the digit
		P0 = ~bcd[ clock[3] ];	// Set the segments of LED
		P1 = digit[1];			// Turn on the digit

		P0 = 0xFF;				// Turn off the digit
		P0 = ~bcd[ clock[4] ];	// Set the segments of LED
		P1 = digit[2];			// Turn on the digit

		P0 = 0xFF;				// Turn off the digit
		P0 = ~bcd[ clock[5] ];	// Set the segments of LED
		P1 = digit[3];			// Turn on the digit

		P0 = 0xFF;			// Turn off the digit	
	}
} /* main */

void isrTimer0(void) interrupt 1
{
	if (++click >= 10)	// wait for 1 secound (100 x 10ms)
	{
		click = 0;
		if (++second > 59)
		{
			second = 0;
			minute++;
		}
		
		if (minute > 59)
		{
			minute = 0;
			hour++;
		}
	
		if (hour > 23)
		{
			hour = 0;
			minute = 0;		// For protection of illegal values
			second = 0;
		}
	}
	TH0  = (65536 - 10000) >> 8;	// 10ms heartbeat (12MHz X'tal)
	TL0  = (65536 - 10000) % 256;
} /* isrTimer0 */

void bin2BCD(unsigned char i, unsigned char *p)
{
	*p     = i / 10;
	*(p+1) = i % 10;
} /* bin2BCD */

void time2BCD(void)
{
	bin2BCD(hour, clock);
	bin2BCD(minute, clock+2);
	bin2BCD(second, clock+4);
} /* time2BCD */