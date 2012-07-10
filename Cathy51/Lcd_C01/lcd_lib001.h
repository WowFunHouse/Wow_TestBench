 /******************************************************************
Library of supporting utilities

 Version:      		0.01
 Description:		Supporting function

 Created on:		2012-07-09
 Created by:		Cathy
 ******************************************************************/

//unsigned char lcdCheckBusy(void);
//void lcdWaitUntilReady(void);

void lcdWriteCmd(unsigned char cmd);
void lcdWriteData(unsigned char dData);
void lcdWriteString(char *str);
 
void lcdSelectRow(unsigned char row);  	// row: 0, 1

void lcdClearScreen(void);