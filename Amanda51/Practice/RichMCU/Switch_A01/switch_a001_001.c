/**************************************************************
 Title:			Funtion for switch matrix 
 
 File:			switch_a001_001.c

 Version:		0.01
 Description:	Return the switch key and switch is on

 Created on:	2013-09-04
 Created by:	Amanda Li

 Board:			RichMCU RZ-51V2.0

 Connections:	Default

 Jumpers:		All on		
 **************************************************************/
#include <STC89.H>
								  
unsigned char checkSwitchMatrix(void)
{
	unsigned char	SWITCH_ON = 0;

	P1 = 0x7F;
	if		(P1 == 0x77)	SWITCH_ON = 1;	
	else if	(P1 == 0x7B)	SWITCH_ON = 2;
	else if	(P1 == 0x7D)	SWITCH_ON = 3;
	else if	(P1 == 0x7E)	SWITCH_ON = 4;
	P1 = 0xBF;
	if		(P1 == 0xB7)	SWITCH_ON = 5;
	else if	(P1 == 0xBB)	SWITCH_ON = 6;
	else if	(P1 == 0xBD)	SWITCH_ON = 7;
	else if	(P1 == 0xBE)	SWITCH_ON = 8;
	P1 = 0xDF;	
	if		(P1 == 0xD7)	SWITCH_ON = 9;
	else if	(P1 == 0xDB)	SWITCH_ON = 10;
	else if	(P1 == 0xDD)	SWITCH_ON = 11;
	else if	(P1 == 0xDE)	SWITCH_ON = 12;
	P1 = 0xEF;
	if		(P1 == 0xE7)	SWITCH_ON = 13;
	else if	(P1 == 0xEB)	SWITCH_ON = 14;
	else if	(P1 == 0xED)	SWITCH_ON = 15;
	else if	(P1 == 0xEE)	SWITCH_ON = 16;

	return	SWITCH_ON;

}/* checkSwitchMatrix */

void main(void)
{
	P0 = ~0xFF;

	for(;;)
	{	
		if		(checkSwitchMatrix() == 0)		P0 = 0xFF;
		else if	(checkSwitchMatrix() == 1)		P0 = 0xFE;	
		else if	(checkSwitchMatrix() == 2)		P0 = 0xFD;
		else if	(checkSwitchMatrix() == 3)		P0 = 0xFB;
		else if	(checkSwitchMatrix() == 4)		P0 = 0xF7;
		else if	(checkSwitchMatrix() == 5)		P0 = 0xEF;
		else if	(checkSwitchMatrix() == 6)		P0 = 0xDF;
		else if	(checkSwitchMatrix() == 7)		P0 = 0xBF;
		else if	(checkSwitchMatrix() == 8)		P0 = 0x7F;
		else if	(checkSwitchMatrix() == 9)		P0 = 0xFC;
		else if	(checkSwitchMatrix() == 10)		P0 = 0xF3;
		else if	(checkSwitchMatrix() == 11)		P0 = 0xCF;
		else if	(checkSwitchMatrix() == 12)		P0 = 0x3F;
		else if	(checkSwitchMatrix() == 13)		P0 = 0xF8;
		else if	(checkSwitchMatrix() == 14)		P0 = 0xE3;
		else if	(checkSwitchMatrix() == 15)		P0 = 0x1F;
		else if	(checkSwitchMatrix() == 16)		P0 = 0;
 	}
}/* main */