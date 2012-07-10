/*********************************************************************
 RichMCU RZ-51V2.0 Hardware Configuration header file

 Version:		0.01
 Description:	RichMCU RZ-51V2.0 Hardware Configuration

 Created on:	2012-07-09
 Created by:	Carol

 Board:			RichMCU RZ-51V2.0

 Connection:	LCD pins as below -
 				RS - P20
				RW - P21
				EN - P22
				DATAPORT - P0

 Jumpers:		将 JPP0 跳线端的跳线帽拔掉以免干扰1602 液晶显示
				将 JPSMG 数码管控制跳线拔掉使数码管停止工作。
				插上1602LCD液晶
				将 JPBG 液晶背光跳线插上
 *********************************************************************/

#define RS 			P20
#define RW 			P21
#define	EN 			P22

#define BF 			P07

#define DATAPORT 	P0