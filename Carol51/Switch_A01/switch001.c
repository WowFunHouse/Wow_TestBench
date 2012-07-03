#include <STC89.H>

void ledON(void)
{
      P0=~0x01;
}

void ledOFF(void)
{
	  P0=~0x00;
}

unsigned char sw(void)
{					   
	  P14=1;				// Set P14 ready for Switch K5 input

	  if (P14!=1)			// K5 is pressed (ON)
	  {	 
	     return 1;
	  }
	  else 					// K5 is released (OFF)
	  {
	     return 0;
	  }
} 
void main(void)
{
	unsigned char led_on;		// 1:On   0:Off
	unsigned char lastsw;		// 1:On   0:Off

	ledOFF(); 					// LED is off
	led_on = 0;
	
	lastsw = 0;		    
	for(;;)
	{
		if (lastsw == 0)					// Switch is OFF?
		{
			if (sw()==1)					// Switch Off -> On					
			{
				lastsw = 1; 	
				if (led_on==1)      		// LED ON -> OFF              
				{
					led_on=0;						
					ledON();
				}
				else						// LED OFF -> ON
				{
					led_on=1;                      
					ledOFF(); 
				}
			}
		}
		else								// Last switch is ON
		{
			if (sw() == 0)					// Switch On -> Off
			{
				lastsw = 0;
			}
		}
	}
}
