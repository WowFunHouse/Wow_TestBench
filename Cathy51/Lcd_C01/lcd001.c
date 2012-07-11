/******************************************************************
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

 V3.0				Use array for the LCD messages
 V4.0				Add a string pointer to handle string
 V5.0				Use a function to handle message string
 v6.0				Add Select Row
 ******************************************************************/
#include "lcd_lib001.h"

void main(void)
{
	char msgA[]="I Love 8051";
	char msgB[]="Wow digital post";

	lcdInit();							 //	8-bit, 2lines,5x7 font


//	lcdWriteCmd(0x0F);					//	Display:On Cursor:On Blink:On	lcdWriteCmd(0x38);					//
//	lcdWriteCmd(0x06);					//	Input mode; Increment, Non-shift

	lcdSetDisplayMode (LCD_DMODE_DISPLAY_ON |
					   LCD_DMODE_CURSOR_ON |
					   LCD_DMODE_CURSOR_BLINK_ON);	

	lcdSetInputMode (LCD_INPUT_INC , LCD_INPUT_SHIFT_OFF);

	lcdClearScreen();

	lcdSelectRow(0);
	lcdWriteString(msgA);
	lcdSelectRow(1);					
	lcdWriteString(msgB);
  
	for(;;);


} /* main */


