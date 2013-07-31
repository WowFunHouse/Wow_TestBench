/****************************************************************************
 Title:			7-Segment Test		
 
 File:			digit002.c

 Version:		0.01
 Description:	To rotate a digit on 7-segment LED display

 Created on:	2013-07-31
 Created by:	Michael

 Board:			RichMCU RZ-51V2.0

 Connections:	P0.0 - P0.7 -> 7-Segment LED segemnt control (0:On 1:Off)
				P2.0 - P2.1 -> Digit selection of 7-Segment LED
 			 	P1.4 -> Switch K5 (O:On 1:Off)

				LCD pins as below -
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
 **************************************************************/
#include <STC89.H>

void delay(void)
{
	int d;

	for (d=0; d<20000; d++);

} /* delay */

void main(void)
{
	char p;
	char q;

	P0=~0x6d;  			/* Digit '5' */

	for(;;)
	{
		p=1;
		for (q=0; q<8; q++)
		{
			P2=~p;
			p=p<<1;
			delay();
		}
	}
} /* main */
