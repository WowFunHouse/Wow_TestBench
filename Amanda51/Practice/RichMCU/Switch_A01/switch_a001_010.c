/**************************************************************
 Title:			Funtion for switch matrix 
 
 File:			switch_a001_001.c

 Version:		0.01
 Description:	Return the switch key and switch is on

 Created on:	2013-09-04
 Created by:	Amanda Li

 Board:			RichMCU RZ-51V2.0

 Connections:	Default

 Jumpers:		All on		
 **************************************************************/
#include <STC89.H>
								  
void delay(unsigned int t)
{
	unsigned	x;

	for(x=0; x<t; x++);

} /* delay */

unsigned char LCD_DISPLAY[]={0xff,0xfe,0xfd,0xfb,
							 0xf7,0xef,0xdf,0xbf,
							 0x7f,0xfc,0xf3,0xcf,
							 0x3f,0xf8,0xe3,0x1f,0xff};

unsigned char SWITCH_KEY[]={0xee,0xde,0xbe,0x7e,
							0xed,0xdd,0xbd,0x7d, 
							0xeb,0xdb,0xbb,0x7b,
							0xe7,0xd7,0xb7,0x77 };


unsigned char checkSwitchMatrix(void)
{
   unsigned char	switch_Code01, switch_Code02, keycode, key, a;

   P1 = 0xf0;
   switch_Code01 = P1;

   if((switch_Code01&0xf0) != 0xf0)
   {
     delay(2000);
     switch_Code01 = P1;

     if((switch_Code01&0xf0) != 0xf0)
     {
        P1 = 0x0f;
        switch_Code02 = P1;
        keycode = switch_Code01|switch_Code02;

        for(a=0;a<=15;a++)
        {
           if(keycode == SWITCH_KEY[a])
           {
              key = a;
              return(key);
           }
        } 
     }
   }
   else  P1 = 0xff;

   return (16);
}/* checkSwitchMatrix */

void main(void)
{
	P0 = 0xFF;

	for(;;)
	{
		P0 = LCD_DISPLAY[checkSwitchMatrix()]; 
	}
}/* main */ 