#include <STC89.H>

/* Ha Ha! ;-D 
	***
	***
	* 
	*
*/
void main(void)		// Very Good! ;P
{
	unsigned char a;
	unsigned char digit;

    a=0x77;			// To show the 'A'
	digit=0xFB;		// on 2nd digit

	for(;;)
	{ 
	  P0=~a;
	  P1=digit;
	}
} /* main */


