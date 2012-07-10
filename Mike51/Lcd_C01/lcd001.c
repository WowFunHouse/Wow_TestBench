/****************************************************************************
 LCD Testing

 Version:		0.01
 Description:	

 Created on:	2012-07-09
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
#include "lcd_lib001.h"

void main(void)
{
	char msgA[]="I Love 8051";
	char msgB[]="Wow is Great!!!";

	lcdInit();				// Set 2 lines, font:5x7

	lcdSetDisplayMode(LCD_DMODE_DISPLAY_ON | 
					  LCD_DMODE_CURSOR_ON  |
					  LCD_DMODE_CURSOR_BLINK_ON);

	lcdClearScreen();
	lcdSetInputMode(LCD_INPUT_INC, LCD_INPUT_SHIFT_OFF);

	lcdWriteString(msgA);
	lcdSelectRow(1);
	lcdWriteString(msgB);

	for (;;);

} /* main */
