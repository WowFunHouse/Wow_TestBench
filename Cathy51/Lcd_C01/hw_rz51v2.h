/******************************************************************
 RichMCU RZ-51

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

 Jumpers:			JPP0 ���߶˵�����ñ�ε��������1602Һ����ʾ
					JPSMG ����ܿ������߰ε�ʹ�����ֹͣ������
					JPBG Һ���������߲���
					����1602LCDҺ��

 ******************************************************************/
#define RS 			P20
#define RW 			P21
#define EN 			P22
#define DATAPORT    P0
#define BF 			P07