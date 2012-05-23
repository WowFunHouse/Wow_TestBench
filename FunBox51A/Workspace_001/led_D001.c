#include <STC89.H>
#include "../include/library.h"
#include "../include/devices.h"
#include "../include/funbox51a.h"

#define	DELAY_TIME	500

unsigned char ptn[][8]={{0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01}
			{0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80}
			{0x81, 0x81, 0x42, 0x42, 0x24, 0x24, 0x18, 0x18}
			{0x18, 0x18, 0x24, 0x24, 0x42, 0x42, 0x81, 0x81}};

void ledptn(unsigned char pattern)
{
	unsigned char	p, n;
	unsigned char	*ppp[];
	
	ppp = ptn;

	setFlag();
	if ((chkFlag() == 0) && (pattern >=1) && (pattern <= 4))
 	{
		p = pattern - 1; 
		for (n=0; n<8; n++)
		{
			setFlag();
			if (chkFlag() == 0)
			{
				PORT_LED = led(ppp[p][n]);
				delayms(DELAY_TIME);
			}
		}
 	}
} /* ledptn	*/
