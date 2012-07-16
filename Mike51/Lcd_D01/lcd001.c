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
#include <STC89.H>

#define	RS		P20
#define	RW		P21
#define	EN		P22
#define	BF		P07
#define	DPORT	P0

unsinged char lcdCheckBusy(void)
{
	unsigned char bf;

	EN = 0;
	RS = 0;
	RW = 1;
	EN = 1;
	delay();
	bf=BF;
	EN=0;

	return bf;

} /* lcdCheckBusy */

void lcdWriteCmd(unsigned char cmd)
{
	RS = 0;
	RW = 0;
	DPORT = cmd;
	EN = 0;

} /* lcdWriteCmd */

void lcdWriteData(unsigned dData); 
void lcdClearScreen(void);

void main(void)
{
	for (;;)
	{
	}

} /* main */