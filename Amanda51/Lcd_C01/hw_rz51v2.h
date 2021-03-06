/**********************************************************************
 RichMCU Rz-51v2.0 Hardware configuration header file

 Version:		0.01
 Description:	RichMCU Rz-51v2.0 Hardware configuration

 Creared on:	2012-07-10
 Creared by:	Amanda Li
 
 Board:			RichMCU RZ-51V2.0

 Conmnection:	LCD pins as below - 
				RS			P20
				RW			P21
				EN			P22
				DATAPORT	P0

 Jumpers:		Remove JPSMG - Disable 7-Segment LEDs
				Remove JPP0	 - Disable LEDs
				Add JPBG	 - Enable LCD Back Light				
 **********************************************************************/
#define	RS			P20
#define	RW			P21
#define	EN			P22
#define BF			P07

#define DATAPORT	P0