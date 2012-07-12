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
 ******************************************************************/
#include "lcd_lib001.h"

void main(void)
{
	char msgA[12]="I Love 8051";
	char msgB[]="Wow digital post";

	lcdInit();							 //	8-bit, 2lines,5x7 font


//	lcdWriteCmd(0x0F);					//	Display:On Cursor:On Blink:On	lcdWriteCmd(0x38);					//
//	lcdWriteCmd(0x06);					//	Input mode; Increment, Non-shift

	lcdSetDisplayMode (LCD_DMODE_DISPLAY_ON |
					   LCD_DMODE_CURSOR_ON |
					   LCD_DMODE_CURSOR_BLINK_ON);	

	lcdMakeRawFont(0, 0x06, 0x09, 0x09, 0x06, 0x03, 0x1a, 0x05, 0x08);

	lcdClearScreen();
	lcdSetInputMode (LCD_INPUT_INC , LCD_INPUT_SHIFT_OFF);


	lcdWriteData(0);
	lcdWriteData(' ');
	lcdSelectRow(0);
	lcdWriteString(msgA);
	lcdSelectRow(1);					
	lcdWriteString(msgB);
  
	for(;;);

} /* main */


