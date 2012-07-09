#include <STC89.H>

unsigned char led(unsigned char n)
{
	return	~n;
} /* led() */

unsigned char getsw(void)
{
	unsigned char	x, k;

	P2 = 0xFF;				// Pull Up the Output Pins to check Input

	x = P2;					// Check switch status
	x = x&0x0F;				// Filter out the junks
	
	switch (x) {
		 case 0x0E:		k=1;   		// Switch #1 is ON
		 				break;

		 case 0x0D:		k=2;	 	// Switch #2 is ON
		 				break;

		 case 0x0B:		k=3;	 	// Switch #3 is ON
		 				break;

		 case 0x07:		k=4; 		// Switch #4 is ON
		 				break;

		 default:		k=0;  		// No switch is pressed
		 				break;
	}
	return k;  						// Return the Switch status
} /* getsw() */

void main(void)
{
	unsigned char	a, b, l;

	l = 0;
	b = 0x00;

	for(;;)
	{
		a = getsw();

		if((a != 0) && (a != l))	b=~b;

		l = a;
		P0 = led(b);
	}
}