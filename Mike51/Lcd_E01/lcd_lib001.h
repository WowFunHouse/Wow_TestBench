/****************************************************************************
 File:		lcd_lib002.h

 LCD Driver Library Header File

 Version:		0.01
 Description:	LCD 1602 Driver Header (Hitachi HD44780 Chip)

 Created on:	2012-07-14
 Created by:	Michael

 Board:			RichMCU RZ-51V2.0

 Connection:	LCD pins as below -
 				RS - P20
				RW - P21
				EN - P22
				DATAPORT - P0

 Jumpers:		Remove JPSMG - Disable 7-Segment LEDs
 				Remove JPP0  - Disable LEDs
				Add JPBG     - Enable LCD Back Light

				�� JPSMG ����ܿ������߰ε�ʹ�����ֹͣ������
 				�� JPP0 ���߶˵�����ñ�ε��������1602 Һ����ʾ
				����1602LCDҺ��
				�� JPBG Һ���������߲���
****************************************************************************/
#define	LCD_INPUT_INC					0x02
#define	LCD_INPUT_SHIFT_ON				0x01

#define	LCD_DISPLAY_ON					0x04
#define	LCD_DISPLAY_CURSOR_ON			0x02
#define	LCD_DISPLAY_CURSOR_BLINK_ON		0x01

#define	LCD_SHIFT_MSG					0x08
#define	LCD_SHIFT_RIGHT					0x04

#define	LCD_FUNC_DL8					0x10
#define LCD_FUNC_2LINES					0x08
#define	LCD_FUNC_FONT5X10				0x04

#define	LCD_CMD_CLEAR_SCREEN			0x01
#define	LCD_CMD_CURSOR_RESET			0x02
#define	LCD_CMD_SET_INPUT				0x04
#define	LCD_CMD_SET_DISPLAY				0x08
#define	LCD_CMD_SET_SHIFTING			0x10
#define	LCD_CMD_SET_FUNCTION			0x20
#define	LCD_CMD_SET_CGRAM				0x40
#define	LCD_CMD_SET_DDRAM				0x80			

// unsigned char lcdCheckBusy(void);
// void lcdWaitUntilReady(void);

// void lcdWriteCmd(unsigned char cmd);
void lcdWriteData(unsigned char dData);
void lcdWriteString(char *str);

unsigned char lcdSelectDDRAMAddr(unsigned addr);	// Rtn: 0:OK 1:Err
unsigned char lcdSelectCGRAMAddr(unsigned addr);	// Rtn: 0:OK 1:Err

unsigned char lcdGetCursorAddress(void);
unsigned char lcdGetCurrentRow(void);
unsigned char lcdGetCursorCurrentPos(void);
 
void lcdPutCharAtPos(unsigned char row, unsigned char pos, char c);

void lcdClearRow(unsigned char row);
void lcdClearCurrentRow(void);
void lcdClearRestOfRow(unsigned char row);
void lcdClearRestOfCurrentRow(void);

void lcdCursorReset(void);

void lcdClearScreen(void);
void lcdSelectRow(unsigned char row);
void lcdSelectRowPosition(unsigned char row, unsigned char pos);
void lcdSelectPosition(unsigned char row, unsigned pos);

//void lcdSetInput(unsigned char mode);
void lcdSetInputShiftOn(void);
void lcdSetInputShiftOff(void);
void lcdSetInputInc(void);
void lcdSetInputDec(void);

void lcdSetDisplay(unsigned char mode);
void lcdSetDisplayOn(void);
void lcdSetDisplayOff(void);
void lcdSetDisplayCursorOn(void);
void lcdSetDisplayCursorOff(void);
void lcdSetDisplayCursorBlinkOn(void);
void lcdSetDisplayCursorBlinkOff(void);

void lcdSetShifting(unsigned char mode);
void lcdSetShiftingMsg(void);
void lcdSetShiftingCursor(void);
void lcdSetShiftingRight(void);
void lcdSetShiftingLeft(void);

void lcdSetFunction(unsigned char mode);
void lcdSetFunction2Lines(void);
void lcdSetFunction1Line(void);
void lcdSetFunctionFont5x7(void);
void lcdSetFunctionFont5x10(void);

/***************************************************
 lcdMakeRawFont() - Use this to create a new font
 Input:
	c: character code (0 - 7)
	row0-row7: dotmatrix rows from top to bottom
			   valid bits b0 - b4 from right to left
 Output: 0:Ok 1:Error
 ***************************************************/
unsigned char lcdMakeRawFont(unsigned char c, unsigned char row0,
									 unsigned char row1, 
									 unsigned char row2, 
									 unsigned char row3, 
									 unsigned char row4,
									 unsigned char row5,
									 unsigned char row6,
									 unsigned char row7);

/*****************************************************
 lcdMakeFont() - Use this to create a new font
 Input:
	c: character code (0 - 7)
	*row: dotmatrix rows (8 rows) from top to bottom
		  valid bits b0 - b4 from right to left
 Output: 0:OK, 1:Error
 *****************************************************/
unsigned char lcdMakeFont(unsigned char c, char *row);
void lcdInit(void);							// 2lines, Font:5x7

void lcdEfxBounce(unsigned char row, char *str, unsigned int speed);
void lcdEfxRoll(unsigned char row, char *str, unsigned char dir, unsigned int speed);
