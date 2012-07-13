/*********************************************************************
 LCD Testing

 Version:		0.01
 Description:	Show 2 lines of messages on 1602 LCD module

 Created on:	2012-07-09
 Created by:	Carol

 Board:			RichMCU RZ-51V2.0

 Connection:	LCD pins as below -
 				RS - P20
				RW - P21
				EN - P22
				DATAPORT - P0

 Jumpers:		�� JPP0 ���߶˵�����ñ�ε��������1602 Һ����ʾ
				�� JPSMG ����ܿ������߰ε�ʹ�����ֹͣ������
				����1602LCDҺ��
				�� JPBG Һ���������߲���
 *********************************************************************/
#include "lcd_lib001.h" 

void main(void)
{
	char msgA[]="My name Carol";
	char msgB[]="Good Day!";	

	lcdInit();								            //set 2 lines,font 5x7
	lcdSetDisplayMode(LCD_DMODE_DISPLAY_ON|
	                   LCD_DMODE_CURSOR_ON|
					   LCD_DMODE_CURSOR_BLINK_ON);

//	lcdMakeFont(0,0x01,0x02,0x04,0x08,0x10,0x11,0x0a,0x11);
//	lcdMakeFont(0,0x04,0x0b,0x04,0x08,0x10,0x11,0x0a,0x11);
//	lcdMakeFont(0,0x06,0x02,0x04,0x08,0x10,0x11,0x0a,0x11);

	lcdMakeFont(0,font0);
							  
	lcdClearScreen();
	lcdSetInputMode(LCD_INPUT_INC,LCD_INPUT_SHIFT_OFF);

	lcdWriteData(0);
	lcdWriteData(' ');
	lcdWriteData(0);
	lcdWriteData(' ');
	lcdWriteString(msgA);
	lcdWriteData(' ');
	lcdWriteData(0);
	lcdWriteData(' ');
	lcdWriteData(0);

	lcdSelectRow(1);
	lcdWriteString(msgB);

	for (;;);

} /* main */











