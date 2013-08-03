/****************************************************************************
 Title:			7 -segment Test
 
 File:			DigitC_01

 Version:		0.01
 Description:	To show a digit on 7 - segment LED display

 Created on:	2013-07-31
 Created by:	Cathy

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
void delay ( unsigned int d);

void main()
{
	unsigned int a;

	for(;;)
	{
		signed int t;
		a = 1;

		//P0 = 0x92;
		P0 = ~0x6d;

		//P2 = 0xfb;
		
		
		for (t=1; t<=8; t++)
		{	
			P2 = ~a;
			delay(6000);
			a = a*2;
		}

	 }
}  /* main */

void delay ( unsigned int d)
{
	unsigned int t;

	for (t=1;	t<=d; t++);

}
 /* delay */

