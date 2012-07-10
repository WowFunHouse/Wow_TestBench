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

 Jumpers:		将 JPP0 跳线端的跳线帽拔掉以免干扰1602 液晶显示
				将 JPSMG 数码管控制跳线拔掉使数码管停止工作。
				插上1602LCD液晶
				将 JPBG 液晶背光跳线插上
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











