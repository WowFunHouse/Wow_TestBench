/******************************************************************
File: lcd002.c

 LCD Testing

 Version:      		0.01
 Description:

 Created on:		2012-07-09
 Created by:		Cathy

 Hardware:			RichMCU RZ-51
 Connections:		P20 -> RS
 					P21 -> RW
					P22 -> EN
					P0  -> DATAPORT
					P07 -> BF

 Jumpers:			Remove JPSMS - Disble 7-Segment LEDs
 					Romove JPPO  - Disabled LEDs
					Add JPBG     - Enable LCD Back Light

 Jumpers:			JPP0 跳线端的跳线帽拔掉以免干扰1602液晶显示
					JPSMG 数码管控制跳线拔掉使数码管停止工作。
					JPBG 液晶背光跳线插上
					插上1602LCD液晶
 ******************************************************************/
#include "lcd_lib002.h"
#include "lib_uty001.h"

void main(void)
{
//	char font[]= {0x06, 0x09, 0x09, 0x06, 0x03, 0x1a, 0x05, 0x08};
	char mario[][8] = {{0x06, 0x09, 0x09, 0x06, 0x03, 0x1a, 0x05, 0x08},		
					   {0x09, 0x09, 0x06, 0x03, 0x1a, 0x05, 0x08, 0x06},
					   {0x09, 0x06, 0x03, 0x1a, 0x05, 0x08, 0x06, 0x09},
					   {0x06, 0x03, 0x1a, 0x05, 0x08, 0x06, 0x09, 0x09},
					   {0x03, 0x1a, 0x05, 0x08, 0x06, 0x09, 0x09, 0x06},
					   {0x1a, 0x05, 0x08, 0x06, 0x09, 0x09, 0x06, 0x03},
					   {0x05, 0x08, 0x06, 0x09, 0x09, 0x06, 0x03, 0x1a},
					   {0x08, 0x06, 0x09, 0x09, 0x06, 0x03, 0x1a, 0x05}};

	char msgA[12]="I Love 8051";
	char msgB[]="Wow digital post";

	unsigned char currentDisplayMode;
	unsigned char i, n;

	lcdInit();							 //	8-bit, 2lines,5x7 font


//	lcdWriteCmd(0x0F);					//	Display:On Cursor:On Blink:On	lcdWriteCmd(0x38);					//
//	lcdWriteCmd(0x06);					//	Input mode; Increment, Non-shift

	lcdSetDisplay (LCD_DMODE_DISPLAY_ON |
					LCD_DMODE_CURSOR_ON |
					LCD_DMODE_CURSOR_BLINK_ON);	

//	lcdMakeRawFont(0,font);
	for (n=0; n<8; n++)
	{
		lcdMakeFont(n, mario[n]);
	}

	lcdClearScreen();
	lcdSetInput(LCD_INPUT_INC | LCD_INPUT_SHIFT_OFF);

	lcdWriteData(' ');
	lcdWriteString(msgA);

	lcdSelectRow(1);					
	lcdWriteString(msgB);

	currentDisplayMode = LCD_DMODE_DISPLAY_ON | 
						 LCD_DMODE_CURSOR_OFF |
					 	 LCD_DMODE_CURSOR_BLINK_OFF;
	
	lcdSetDisplay(currentDisplayMode);
  
	for(n=0;;)
	{
		lcdSelectRow(0);
		lcdWriteData(n);

		if (n>=8)
		{
			n=0;
			for (i=0; i<3; i++)
			{
				lcdSetDisplay(LCD_DMODE_DISPLAY_OFF);
				delay(10000);
				lcdSetDisplay(currentDisplayMode);
				delay(20000);
			}
		}
			delay(40000);

			if (n++ <4)
			{
				lcdClearRow(0);
				lcdWriteString(" * ");
				lcdWriteString(msgA);
				lcdSetShifting(LCD_SHIFT_MSG | LCD_SHIFT_RIGHT);
				lcdClearRow(1);
				lcdWriteString(msgB);
			}
			else
			{
				lcdClearRow(1);
				lcdWriteString("Come back! Ha! Ha!");
				lcdSetShifting(LCD_SHIFT_MSG | LCD_SHIFT_LEFT);
			}
		}
	
} /* main */
