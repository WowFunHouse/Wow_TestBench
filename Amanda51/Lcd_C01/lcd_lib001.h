/***************************************************************************
LCD Driver Library Heade

Version:		0.01
Description:	LCD 1602 Driver Header	

Creared on:		Amanda Li
Creared by:		2012-07-09

Board:			Richmcu RZ-51/AVR 2.0

Conmnection:	LCD pins as below - 
				RS			P20
				RW			P21
				EN			P22
				DATAPORT	P0

Jumpers:		Remove JPSMG - Disable 7-Segment LEDs
				Remove JPP0	 - Disable LEDs
				Add JPBG	 - Enable LCD Back Light				
*****************************************************************************/

//unsigned char lcdCheckBusy(void);
//void lcdWaitUntilReady(void);

void lcdWriteCmd(unsigned char cmd);
void lcdWriteData(unsigned char dData);
void lcdWriteString(char *str);

void lcdSelectRow(unsigned char row);

void lcdClearScreen(void);