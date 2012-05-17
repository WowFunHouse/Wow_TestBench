void delay1ms(void)   //Îó²î -0.651041666667us
{
    unsigned char a,b;
    for(b=102;b>0;b--)
        for(a=3;a>0;a--);
}

void delayms(unsigned int delaytime) 			// delay time in ms
{
	unsigned int t;

	for (t=0; t < delaytime; t++) delay1ms();
}

void delaysec(unsigned int delaytime)  			// Delay time in seconds
{
	unsigned int t;

	for (t=0; t < delaytime; t++) delayms(1000);
}

void delay(unsigned int delaytime)				
{
	unsigned int d;

	for (d=0; d< delaytime; d++);
}
