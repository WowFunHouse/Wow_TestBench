/*********************************************************************
 LCD Dribver Library Header File

 Version:		0.01
 Description:	Driver of LCD 1602 module

 Created on:	2012-07-09
 Created by:	Carol
 *********************************************************************/

void lcdWriteCmd(unsigned char cmd);
void lcdWriteData(unsigned char dData);
void lcdWriteString(char *str);

void lcdSelectRow(unsigned char row);

void lcdClearScreen(void);
