/*******************************************************************
 File:			hw_lcd1602.h

 LCD Hardware definitations
 
 Version:		0.01
 Description:	LCD 1602 Hardware definition header file	

 Creared on:	2012-07-18
 Creared by:	Amanda Li

 Board:			1602 LCD Module
 ******************************************************************/
#define	LCD_MAX_LENGTH				40
#define LCD_ADDR_ROW0				0x00
#define LCD_ADDR_ROW1				0x40
#define LCD_CGRAM_ADDR				0x00
#define LCD_USRCHR_SIZE				8		// Size of per character
#define LCD_USRCHR_CNT				8		// Total number of user defined characters

#define	LCD_WINDOW_LENGTH			16
#define	LCD_WINDOW_ROWS				2