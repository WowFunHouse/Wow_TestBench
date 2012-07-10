#include <STC89.H>

#define RS			P20
#define	RW			P21
#define	EN			P22
#define BF			P07
#define DATAPORT	P0
#define	DELAYSHORT	500

void delay(unsigned int delaycount)
{
	unsigned int t;
	
	for (t=0; t<delaycount; t++);
} /*delay*/

unsigned char lcdCheakBusy(void)
{
	unsigned char bf;

	DATAPORT=0xFF;

    RS=0;
	RW=1;
	EN=1;
	delay(DELAYSHORT);
	bf=BF;
	EN=0;
    RW=0;
	
    return bf;

} /*lcdCheakBusy*/

void lcdWaiteUntilReady(void)
{
	while (lcdCheakBusy()==1);

} /*lcdUntilReady*/

void lcdWriteCmd(unsigned char cmd)
{
	lcdWaiteUntilReady();
	
	RS=0;
	RW=0;
	EN=0;
	DATAPORT=cmd;
	delay(DELAYSHORT);
    EN=1;
	delay(DELAYSHORT);
	EN=0;
	RW=1;
} /*lcdWriteCmd	*/

void lcdWriteData(unsigned char dData)
{
	lcdWaiteUntilReady();
	
	RS=1;
	RW=0;
	EN=0;
	DATAPORT=dData;
	delay(DELAYSHORT);
	EN=1;	
	delay(DELAYSHORT);
	EN=0;
	RW=1;
} /*lcdWriteData*/

void lcdClear(void)
{
	lcdWriteCmd(0x01);
}/*lcdClear*/

void lcdWriteString(char *str)
{
	unsigned int n;
	
	for (n=0; *(str+n)!=0; n++)
	{
		lcdWriteData(*(str+n));
	}
} /*lcdWriteString*/

void main(void)
{
	char msg[]="My name carol";

	lcdClear();

	lcdWriteCmd(0x0F);
	lcdWriteCmd(0x38);
	lcdWriteCmd(0x06);
	
	lcdWriteString(msg);
	
	for (;;);
} /*main */
