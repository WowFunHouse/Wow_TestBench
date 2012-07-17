/****************************************************************************
 File:		lcd002.c

 LCD Testing

 Version:		1.0
 Description:	Try to show 2 lines with homemade characters

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
#include "lib_uty001.h"
#include "lcd_lib002.h"

void main(void)
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

	lcdSetDisplay(LCD_DISPLAY_ON | 
				  LCD_DISPLAY_CURSOR_ON  |
				  LCD_DISPLAY_CURSOR_BLINK_ON);

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

	/* try to show all 8 pre-programmed special characters */
//	for (n=0; n<8; n++)

//	{
//		lcdWriteData(n);
//	}

	lcdWriteData(' ');
	lcdWriteString(msgA);

	lcdSelectRow(1);
	lcdWriteString(msgB);

	currentDisplayMode = LCD_DISPLAY_ON;

	lcdSetDisplay(currentDisplayMode);
	lcdSetShiftingMsg();
	
	for (n=0;;)
	{
		lcdSelectRow(0);
		lcdWriteData(n);

		if (n>=8)
		{
			n=0;
			for (i=0; i<3; i++)
			{
				lcdSetDisplayOff();
				delay(10000);
				lcdSetDisplay(currentDisplayMode);
				delay(20000);
			}
		}

		delay(40000);

		if (n++ < 4)
		{
			lcdClearRow(0);
			lcdWriteString("  * ");
			lcdWriteString(msgA);
			lcdSetShiftingRight();
			lcdClearRow(1);
			lcdWriteString(msgB);
		}
		else
		{
			lcdClearRow(1);
			lcdWriteString("Come back! Ha! Ha!");
			lcdSetShiftingLeft();
		}
	}

} /* main */
