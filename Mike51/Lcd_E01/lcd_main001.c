/****************************************************************************
 File:			lcd001.c

 LCD Demo

 Version:		0.01
 Description:	LCD Demo

 Created on:	2012-07-18
 Created by:	Michael

 Board:			RichMCU RZ-51V2.0

 Connection:	LCD pins as below -
 				RS - P20
				RW - P21
				EN - P22
				DATAPORT - P0

 Jumpers:		Remove JPSMG - Disable 7-Segment LEDs
 				Remove JPP0  - Disable LEDs
				Add JPBG     - Enable LCD Back Light

				将 JPSMG 数码管控制跳线拔掉使数码管停止工作。
 				将 JPP0 跳线端的跳线帽拔掉以免干扰1602 液晶显示
				插上1602LCD液晶
				将 JPBG 液晶背光跳线插上
****************************************************************************/
#include "lib_uty001.h"
#include "lcd_lib001.h"

#define	DEBUG_USRCHAR
#undef	DEBUG_USRCHAR

void lcdDemoAnimatedChar(void)
{
	char mario[][8]={{0x06, 0x09, 0x09, 0x06, 0x03, 0x1a, 0x05, 0x08},
					 {0x09, 0x09, 0x06, 0x03, 0x1a, 0x05, 0x08, 0x06},
					 {0x09, 0x06, 0x03, 0x1a, 0x05, 0x08, 0x06, 0x09},
					 {0x06, 0x03, 0x1a, 0x05, 0x08, 0x06, 0x09, 0x09},
					 {0x03, 0x1a, 0x05, 0x08, 0x06, 0x09, 0x09, 0x06},
					 {0x1a, 0x05, 0x08, 0x06, 0x09, 0x09, 0x06, 0x03},
					 {0x05, 0x08, 0x06, 0x09, 0x09, 0x06, 0x03, 0x1a},
					 {0x08, 0x06, 0x09, 0x09, 0x06, 0x03, 0x1a, 0x05}};

	char msgA[]="Wow8051";
	char msgB[]="Wow is Great!!!";

	unsigned char currentDisplayMode;
	unsigned char i, n;

	lcdInit();				// Set 2 lines, font:5x7

	lcdSetDisplay(LCD_DISPLAY_ON);

//	lcdMakeRawFont(0, 0x01, 0x02, 0x04, 0x08, 0x10, 0x11, 0x0a, 0x11);
//	lcdMakeRawFont(0, 0x04, 0x0b, 0x04, 0x07, 0x1a, 0x04, 0x08, 0x10);
//	lcdMakeRawFont(1, 0x06, 0x09, 0x09, 0x06, 0x03, 0x1a, 0x05, 0x08);

	/* Setup all 8 self-made special characters */
	for (n=0; n<8; n++)
	{
		lcdMakeFont(n, mario[n]);
	}

	lcdClearScreen();
	lcdSetInput(LCD_INPUT_INC);

#ifdef	DEBUG_USRCHAR
	/* try to show all 8 pre-programmed special characters */
	for (n=0; n<8; n++)
	{
		lcdWriteData(n);
	}
#endif

#ifndef	DEBUG_USRCHAR
	lcdWriteData(' ');
	lcdWriteData(' ');
	lcdWriteString(msgA);

	lcdSelectRow(1);
	lcdWriteString(msgB);
	
	for (n=0; n<8; n++)
	{
		lcdSelectRow(0);
		lcdWriteData(n);
		delay(20000);
	}
#endif

} /* lcdDemoAnimatedChar */

void main(void)
{
	for (;;)
	{
		lcdDemoAnimatedChar();
	}
} /* main */
