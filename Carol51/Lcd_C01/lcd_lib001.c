/*********************************************************************
 LCD Driver Library

 Version:		0.01  
 Description:	Lcd 1602 Driver

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
#include <STC89.H>
#include "lib_uty001.h"
#include "hw_rz51v2.h"

#define DELAYSHORT	500

unsigned char lcdCheckBusy(void)			   //1:busy,  0:poady;  
{
	unsigned char bf;
	
	DATAPORT=0xff;				// Set DATAPORT ready for input
	
	RS=0;
	RW=1;
	EN=1;				
	delay(DELAYSHORT);
	bf=BF;
	EN=0;
	RW=0;
	
	return bf;

} /* lcdCheckBusy */

void lcdWaitUntilReady(void)
{
	while (lcdCheckBusy()==1);

} /* lcdWaitUntilReady */

void lcdWriteCmd(unsigned char cmd)
{
	lcdWaitUntilReady();
	
	RS=0;
	RW=0;
	EN=0;
	DATAPORT=cmd;
	delay(DELAYSHORT);
	EN=1;
	delay(DELAYSHORT);
	EN=0;
	RW=1;

} /* lcdWriteCmd */

void lcdWriteData(unsigned char dData)
{
	lcdWaitUntilReady();
	
	RS=1;
	RW=0;
	EN=0;
	DATAPORT=dData;
	delay(DELAYSHORT);
	EN=1;
	delay(DELAYSHORT);
	EN=0;
	RW=1;

} /* lcdWriteData */


void lcdWriteString(char *str)
{
	unsigned int n;
	
	for (n=0; *(str+n)!=0; n++)
	{
		lcdWriteData(*(str+n));
	}
} /* lcdWriteString */

void lcdSelectRow(unsigned char row)
{
	if (row == 0)
	{
		lcdWriteCmd(0x80|0x00);
	}
	else if (row == 1)
	{
		lcdWriteCmd(0x80|0x40);
	}
} /* lcdSelectRow */

void lcdClearScreen(void)
{
	lcdWriteCmd(0x01);			   // Clear LCD screen

} /* lcdClear */










