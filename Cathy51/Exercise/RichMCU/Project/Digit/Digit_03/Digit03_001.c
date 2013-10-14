/****************************************************************************
 Title:			
 
 File:			

 Version:		0.01
 Description:	

 Created on:	YYYY-MM-DD
 Created by:	

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
//#include <STC89.H>
//
//void main(void)
//{
//	for(;;)
//	{
//
//	}
//} /* main */

#include <reg52.h>
#include <intrins.h>

unsigned char data dis_digit;
unsigned char key_s, key_v;

unsigned char code dis_code[11]={0xc0,0xf9,0xa4,0xb0, // 0, 1, 2, 3
   								 0x99,0x92,0x82,0xf8,0x80,0x90, 0xff};// 4, 5, 6, 7, 8, 9, off 
unsigned char data dis_buf[8];
unsigned char data dis_index;
unsigned char hour,min,sec;
unsigned char sec100; 

sbit K1 = P3^2;
sbit K2 = P3^3;

bit scan_key();

void proc_key();
void inc_sec();
void inc_min();
void inc_hour();
void display();
void delayms(unsigned char ms);

void main(void)
{
	P0 = 0xff;
	P2 = 0xff;
	TMOD = 0x11;  // ��ʱ��0, 1����ģʽ1, 16λ��ʱ��ʽ
	TH1 = 0xdc;
	TL1 = 0;
	
	TH0 = 0xFC;
	TL0 = 0x17;
	 
	hour = 12;
	min = 00;
	sec = 00;
	
	sec100 = 0;
	 
	dis_buf[0] = dis_code[hour / 10];  // ʱʮλ
	dis_buf[1] = dis_code[hour % 10];  // ʱ��λ
	dis_buf[3] = dis_code[min / 10];  // ��ʮλ
	dis_buf[4] = dis_code[min % 10];  // �ָ�λ
	dis_buf[6] = dis_code[sec / 10];  // ��ʮλ
	dis_buf[7] = dis_code[sec % 10];  // ���λ
	dis_buf[2] = 0xbf;      // ��ʾ"-"
	dis_buf[5] = 0xbf;      // ��ʾ"-"
	   
	dis_digit = 0xfe;
	dis_index = 0;
	 
	TCON = 0x01;
	IE = 0x8a;    // ʹ��timer0,1 �ж�
	 
	TR0 = 1;
	TR1 = 1;
	
	key_v = 0x03;

	 while(1)
	{
	  if(scan_key())
	  {
		  delayms(10);
		  if(scan_key())
		  {
			   key_v = key_s;
			   proc_key();
		  }
	 }
 	}
}

bit scan_key()
{
	key_s = 0x00;
	key_s |= K2;
	key_s <<= 1;
	key_s |= K1;
	return(key_s ^ key_v); 
}

void proc_key()
{
	EA = 0;
	if((key_v & 0x01) == 0)  // K1
	{
		  inc_hour();  // JJ=1;
	}
	else if((key_v & 0x02) == 0) // K2
	{
		  min++;    // JJ=0;
		
		  if(min > 59)
		  {
		   min = 0;
		  }
		  dis_buf[3] = dis_code[min / 10];  // ��ʮλ
		  dis_buf[4] = dis_code[min % 10];  // �ָ�λ
	}
 	EA = 1;
}

void timer0() interrupt 1
								// ��ʱ��0�жϷ������, ��������ܵĶ�̬ɨ��
								// dis_index --- ��ʾ����, ���ڱ�ʶ��ǰ��ʾ������ܺͻ�������ƫ����
								// dis_digit --- λѡֵͨ, ���͵�P2������ѡͨ��ǰ����ܵ���ֵ, �����0xfeʱ,
								//    ѡͨP2.0�������
								// dis_buf   --- ���ڻ������ط 
{
 TH0 = 0xFC;
 TL0 = 0x17;
 
 P2 = 0xff;       					// �ȹر����������
 P0 = dis_buf[dis_index];  			 // ��ʾ���봫�͵�P0��
 P2= dis_digit;     		

 dis_digit = _crol_(dis_digit,1); 	// λѡֵͨ����, �´��ж�ʱѡͨ��һλ�����
 dis_index++;     			
     
 dis_index &= 0x07;   				// 8�������ȫ��ɨ����һ��֮���ٻص���һ����ʼ��һ��ɨ��
} 

void timer1() interrupt 3
{
 TH1 = 0xdc;
 
 sec100++;
 
 if(sec100 >= 100)
 {
  sec100 = 0;
  inc_sec();
 }
}

void inc_sec()
{
	sec++;
	if(sec > 59)
	{
		sec = 0;
		inc_min();
	}
 dis_buf[6] = dis_code[sec / 10];  // ��ʮλ
 dis_buf[7] = dis_code[sec % 10];  // ���λ 
}

void inc_min()
{
 min++;

 if(min > 59)
 {
  	min = 0;
  	inc_hour();
 }
 dis_buf[3] = dis_code[min / 10];  	// ��ʮλ
 dis_buf[4] = dis_code[min % 10];  	// �ָ�λ
}

void inc_hour()
{
	hour++;

	if(hour > 23)
	{
	  	hour = 0;
	}
	if(hour > 9)
		dis_buf[0] = dis_code[hour / 10];  	// ʱʮλ
	else
		dis_buf[0] = 0xff;     				// ��Сʱ��ʮλΪ0ʱ����ʾ
		dis_buf[1] = dis_code[hour % 10];  	// ʱ��λ
}

void delayms(unsigned char ms) 	  			// ��ʱ�ӳ���
{      
	unsigned char i;

	while(ms--)
	{
	  for(i = 0; i < 120; i++);
	}
}



