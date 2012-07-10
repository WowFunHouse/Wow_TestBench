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

				�� JPSMG ����ܿ������߰ε�ʹ�����ֹͣ������
 				�� JPP0 ���߶˵�����ñ�ε��������1602 Һ����ʾ
				����1602LCDҺ��
				�� JPBG Һ���������߲���
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
