/****************************************************
 Digital Clcok

 Version:		7.0
 Description:	Add a dot to indicate the 0.5 second
 				Can shift the dispaly with switch S6
 Created on:	2012-06-12
 Created by:	Michael

 Board:			XT100

 Bug:			Cannot switch display mode easily
 Fix:			Add checking of the last status
 				of switch S6
 ****************************************************/

#include <STC89.H>

#define	CLOCK_START_HR		0			// Start time of the clock
#define	CLOCK_START_MIN		0
#define	CLOCK_START_SEC		0

#define	CLICK_TIMER_DELAY	9216		// X'tal 11.0692Mhz (921,600 timer count = 1sec)
#define	CLICK_COUNT			100			// Total timer delay 1sec = CLICK_TIMER_DELAY x CLICK_COUNT = 9216 x 100 = 921600
 
unsigned char hour, minute, second;		// Real clock values
unsigned char clock[6];					// Buffer of the clock digits

unsigned char bcd[]={0x3F, 0x06, 0x5B, 0x4F, 0x66,
		     		 0x6D, 0x7D, 0x07, 0x7F, 0x67};

unsigned char digit[4]={0xFE, 0xFD, 0xFB, 0x07};	// LED digit selection from Left->Right

unsigned int  click; 					// 10ms click counter
unsigned char dot;						// 'Second' indicator dot
unsigned char clock_mode;				// 0->hr:min  1->min:sec

void delay(void);
void time2BCD(void);					// Prototype to convert time value to 2=digit BCD

void main(void)
{
	unsigned char	digit_shift=0;
	unsigned char	s6_pressed=0;

	unsigned char 	n;

	click  = 0;
	dot    = 0;										// Off the dot

	clock_mode = 0;									// show hr:min

	hour   = CLOCK_START_HR;	 					// Start time
	minute = CLOCK_START_MIN;
	second = CLOCK_START_SEC;
	
	TMOD = T0_M1;									// Set Timer0 to mode 1
	TH0  = (65536 - CLICK_TIMER_DELAY) >> 8;		// 10ms heartbeat (11.0592Hz x'tal)
	TL0  = (65536 - CLICK_TIMER_DELAY) % 256;

	ET0  = 1;		// Enable Timer0
	EA   = 1;		// Enable all interrupts

	TR0  = 1;		// Enable Timer0

	P23	 = 1;		// Prepare switch S6 on P2-3

	for (;;)
	{
		if (P23 != 0)								// S6 not pressed
		{
			s6_pressed = 0;							// Memorize S6 is off
		}
		else										// P23 == 0 (key pressed)
		{
			if (s6_pressed == 0)					// switch S6 is just pressed
			{
				s6_pressed = 1;						// Memorize S6 if on

				if (clock_mode == 0) clock_mode = 1;
				else 				 clock_mode = 0;
			}
		}
		
		if (clock_mode == 1)
		{
			digit_shift=2;

		}
		else
		{
			digit_shift=0;
		}
		 
	   	time2BCD();

		for (n=0; n< 4; n++)
		{
			P0 = 0xFF;					// Turn off the digit

			if ((n==3) && (dot!=0))
			{
				P0 = ~(bcd[ clock[n + digit_shift] ] | 0x80);	// Set the segments of LED
			}
			else
			{
				P0 = ~bcd[ clock[n + digit_shift] ];			// Set the segments of LED
			}

			P1 = digit[n];			// Turn on the digit
			delay();
		}
		P0 = 0xFF;					// Turn off the digit	
	}
} /* main */

void isrTimer0(void) interrupt 1
{
	TH0  = (65536 - CLICK_TIMER_DELAY) >> 8;	// Do not wait for this ISR to finish
	TL0  = (65536 - CLICK_TIMER_DELAY) % 256;

	if (click == CLICK_COUNT / 2)	// 0.5 second
	{
		dot = ~dot;
	}

	if (++click >= CLICK_COUNT)	// wait for 1 secound (100 x 10ms)
	{
		dot = ~dot;				// Reach here for exact 1 secound
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

void delay(void)
{
	unsigned int t;

	for (t=0; t< 1000; t++);
}
