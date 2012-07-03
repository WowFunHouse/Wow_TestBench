#include <STC89.H>

#define RS P20
#define RW P21
#define	EN P22
#define DATAPORT P0
#define BF P07
#define DELAYSHORT=50;

void delay(unsigned int delaycount)
{
	   unsigned int t;
	   for(t=0;delaycount;t++)
}
unsigned char LcdCheckBusy(void)
{
	   unsigned char bf;
	   DATAPORT=0xff;
	   RS=0;
	   RW=1;
	   EN=1;				
	   delay();
	   bf=BF;
	   EN=0;
	   return bf;
}

void LcdWaitUntillReady(void)
{
       While(LcdcheakBusy()==1);
}

void LcdWrite Cmd(unsigned char cmd)
{
   	 LcdWaitUntillReay();
	 RS=0;
	 Rw=0;
	 DATAPORT=cmd;
	 delay(delaySHORT);
	 EN=1;
	 delay(delaySHORT);
	 EN=0;
	 RW=1;
}

void LcdWrite Data(unsigned char data)
{
     LcdWaitUntilReady();
	 RS=1;
	 RW=0;
	 DATAPORT=data;
	 delay(delaySHORT);
	 EN=0;
	 delay(delaySHORT);
	 EN=0;
	 RW=1
}

void LcdClear(void)
{
	 lcdWaitForReady();
	 lcdWriteCmd(0x1);
}

 void main(void)
 {
	 lcdClear()
	 lcdWriteData(0x49);
	 lcdWriteData(0x4c);
	 lcdWriteData(0x4f);
	 lcdWriteData(0x56);
	 lcdWriteData(0x45);
 }








