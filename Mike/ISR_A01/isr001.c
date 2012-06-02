#include <STC89.H>

#define	DELAY_BEEPHEARTBEAT		5000
#define	DELAY_BEEPDOUBLE		15000
#define	DELAY_LED				10000

#define	DELAY_BEEPHEARTBEAT_TMR	100			// 100us
#define	DELAY_BEEPDOUBLE_TMR	1000		// 1000us (1ms)

unsigned int	isrHeartbeatCnt;
unsigned int	isrBeepDoubleCnt;

void delayloop(unsigned int dloop);
unsigned char led(unsigned char ptn);

void main(void)
{
	P2 = 0xFF;							// Pull P2 high for switch polling

	isrHeartbeatCnt		= 0;
	isrBeepDoubleCnt	= 0;

	TMOD=T0_M2 | T1_M1;

	TH0=256-DELAY_BEEPHEARTBEAT_TMR;
	TL0=256-DELAY_BEEPHEARTBEAT_TMR;

	TL1=(65536 - DELAY_BEEPDOUBLE_TMR) & 0xFF;
	TH1=(65536 - DELAY_BEEPDOUBLE_TMR) >> 8;

	EX0=1;						// Enable Interrupt #0
	EX1=1;						// Enable Interrupt #1
	ET0=1;						// Enable Interrupt of Timer #0	(Mode 2)
	ET1=1;						// Enable Interrupt of Timer #1	(Mode 1)

	PT1=0;						// Timer #1 Interrupt: High Priority (Double Beep)

	EA=1;						// Enable Interrupts
	TR0=1;						// Start Timer #0
	TR1=1;						// Start Timer #1

	for (;;);

} /* main */

void isr0LedPtnFlow(void) interrupt 0 using 1
{
	unsigned char i, ptn;

	ptn=1;
	for (i=0; i<8; i++)
	{
		P0  = led(ptn);
		delayloop(DELAY_LED);
		ptn = ptn << 1;
	}
	P0=led(0);

} /* isr0LedPtnFlow */

void isr2LedPtnBounce(void) interrupt 2 using 1
{
	unsigned char	ptn[]={0x81,0xC3, 0x66, 0x3c, 0x18};
	unsigned char	n;

	for (n=0; n<5; n++)
	{
		P0=led(ptn[n]);
		delayloop(DELAY_LED);
	}

	for (n=5; n>0; n--)
	{
		P0=led(ptn[n-1]);
		delayloop(DELAY_LED);
	}
	P0=led(0);
} /* isr2LedPtnBounce */

void isr3BeepHeartbeat(void) interrupt 1 using 1
{
	if (isrBeepDoubleCnt == 10000)
	{
		P34=0;
		delayloop(DELAY_BEEPHEARTBEAT);
		P34=1;
		isrBeepDoubleCnt=0;
	}
	else
	{
		isrBeepDoubleCnt++;
	}
} /* isr3BeepHeartbeat */

void isr1BeepDouble(void) interrupt 3 using 3
{
	if (isrBeepDoubleCnt == 10000)
	{
		P34=0;
		delayloop(DELAY_BEEPDOUBLE);
		P34=1;
		delayloop(DELAY_BEEPDOUBLE);
		P34=0;
		delayloop(DELAY_BEEPDOUBLE);
		P34=1;
		isrBeepDoubleCnt = 0;
	}
	else
	{
		isrBeepDoubleCnt++;
	}
	
	TL1=(65536-DELAY_BEEPDOUBLE_TMR) & 0xFF;		// Reset Timer#1 delay time again
	TH1=(65536-DELAY_BEEPDOUBLE_TMR) >> 8;

	TR1=1;							// Re-start Timer #1
} /* sr1BeepDouble */

void delayloop(unsigned int dloop)
{
	unsigned int t;

	for (t=0; t<dloop; t++);
} /* delayloop */

unsigned char led(unsigned char ptn)
{
	return ~ptn;
}