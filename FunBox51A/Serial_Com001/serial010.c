#include <reg52.h>
#include <intrins.h>
unsigned char tmp;
void send_char(unsigned char txd);
main()
{	
	int i;
	unsigned char c;
	
	TMOD = 0x20;			// ��ʱ��1������8λ�Զ�����ģʽ, ���ڲ���������
	TH1=TL1=0xFD;				// ������9600
	
	SCON = 0x50;			// �趨���пڹ�����ʽ1 �������,�൱����������
	//SM0=0;
	//SM1=1;
	//REN=1;
	PCON =0x00;				// �����ʲ�����
	TR1 = 1;				// ������ʱ��1
	while(1)
	{

		P2=0;

		for (i=0; i<1000; i++);

		P2=1;

		for (i=0; i<1000; i++);

//		for (c=32; c<127; c++)
//		{
//			sendoneByte(c);
//		}
//		send_char(0x0d);
//		send_char(0x0a);
//		
//		if(RI==1)						// �Ƿ������ݵ���
//		{
//			RI = 0;
//			tmp = SBUF;				// �ݴ���յ�������
//			P0 = tmp;				// ���ݴ��͵�P0��
//			send_char(tmp);			// �ش����յ�������
//		}		
	}
}
void send_char(unsigned char txd)
// ����һ���ַ�
{
	SBUF = txd;
	while(!TI);				// �������ݴ���
	TI = 0;					// ������ݴ��ͱ�־
}

