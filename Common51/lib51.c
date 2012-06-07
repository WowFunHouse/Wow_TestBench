/*********************************************
 Common functions
 *********************************************/

unsigned char led(unsigned char ptn)
{
	return ~ptn;
} /* led */

void delay10us(void)   // X'tal=11.0925Mhz Îó²î -0.234375us
{
    unsigned char a;

    for(a=2; a>0; a--);
} /* delay10us */

void delay1ms(void)   // X'tal=11.0925Mhz Îó²î -0.651041666667us
{
    unsigned char a, b;

    for(b=4; b>0; b--)
	{
        for(a=113; a>0; a--);
	}	
} /* delay1ms */

void delayms(unsigned int time)
{
    unsigned int t;

	for (t=0; t< time; t++)
	{
		delay1ms();
	}
} /* delayms */
