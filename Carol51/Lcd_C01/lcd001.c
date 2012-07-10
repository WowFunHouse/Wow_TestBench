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

	lcdClearScreen();

	lcdWriteCmd(0x0F);
	lcdWriteCmd(0x38);			 //8 bit,2 lines, 5x7 font;
	lcdWriteCmd(0x06);

	lcdWriteString(msgA);
	lcdSelectRow(1);
	lcdWriteString(msgB);

	for (;;);

} /* main */











