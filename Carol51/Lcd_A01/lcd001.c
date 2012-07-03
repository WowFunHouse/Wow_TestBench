#include <STC89.H>

#define RS P20
#define RW P21
#define	EN P22
#define DATAPORT P0
#define BF P07
#define DELAYSHORT	500

void delay(unsigned int delaycount)
{
	   unsigned int t;
	   for(t=0;t<delaycount;t++);
}
unsigned char lcdCheckBusy(void)			   //1:busy,  0:poady;  
{
	   unsigned char bf;
	   DATAPORT=0xff;
	   RS=0;
	   RW=1;
	   EN=1;				
	   delay(DELAYSHORT);
	   bf=BF;
	   EN=0;
	   RW=0;

	   return bf;
}

void lcdWaitUntilReady(void)
{
       while (lcdCheckBusy()==1);
}

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
}

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
}

void lcdClear(void)
{
	 lcdWaitUntilReady();
	 lcdWriteCmd(0x01);			   //clear Lcd screen;
}

 void main(void)
 {
	 lcdClear();
	 lcdWriteCmd(0x0F);
	 lcdWriteCmd(0x38);			 //8 bit,2 lines, 5x7 font;
	 lcdWriteCmd(0x06);
	 lcdWriteData(0x46);
	 lcdWriteData(0x4c);
	 lcdWriteData(0x6f);
	 lcdWriteData(0x76);
	 lcdWriteData(0x65);
	 lcdWriteData(0x20);
	 lcdWriteData(0x38);
	 lcdWriteData(0x30);
	 lcdWriteData(0x35);
	 lcdWriteData(0x31);

	 for (;;);
 }








