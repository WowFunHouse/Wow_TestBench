/****************************************************************************
 RichMCU RZ-51V2.0 Hardware configuration header file

 Version:		0.01
 Description:	RichMCU RZ-51V2.0 Hardware configuration


 Created on:	2012-07-10
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

#define	RS			P20
#define	RW			P21
#define	EN			P22
#define BF			P07

#define DATAPORT	P0