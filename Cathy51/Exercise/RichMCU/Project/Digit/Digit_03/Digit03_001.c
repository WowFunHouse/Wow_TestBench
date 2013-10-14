/****************************************************************************
 Title:			
 
 File:			

 Version:		0.01
 Description:	

 Created on:	YYYY-MM-DD
 Created by:	

 Board:			RichMCU RZ-51V2.0

 Connections:	P0.0 - P0.7 -> 7-Segment LED segemnt control (0:On 1:Off)
				P2.0 - P2.1 -> Digit selection of 7-Segment LED
 			 	P1.4 -> Switch K5 (O:On 1:Off)

				LCD pins as below -
 				RS - P20
				RW - P21
				EN - P22
				DATAPORT - P0

 Jumpers:		Remove JPSMG - Disable 7-Segment LEDs
 				Remove JPP0  - Disable LEDs
				Add JPBG     - Enable LCD Back Light

				½« JPSMG ÊıÂë¹Ü¿ØÖÆÌøÏß°ÎµôÊ¹ÊıÂë¹ÜÍ£Ö¹¹¤×÷¡£
 				½« JPP0 ÌøÏß¶ËµÄÌøÏßÃ±°ÎµôÒÔÃâ¸ÉÈÅ1602 Òº¾§ÏÔÊ¾
				²åÉÏ1602LCDÒº¾§
				½« JPBG Òº¾§±³¹âÌøÏß²åÉÏ		
 **************************************************************/
//#include <STC89.H>
//
//void main(void)
//{
//	for(;;)
//	{
//
//	}
//} /* main */

#include <reg52.h>
#include <intrins.h>

unsigned char data dis_digit;
unsigned char key_s, key_v;

unsigned char code dis_code[11]={0xc0,0xf9,0xa4,0xb0, // 0, 1, 2, 3
   								 0x99,0x92,0x82,0xf8,0x80,0x90, 0xff};// 4, 5, 6, 7, 8, 9, off 
unsigned char data dis_buf[8];
unsigned char data dis_index;
unsigned char hour,min,sec;
unsigned char sec100; 

sbit K1 = P3^2;
sbit K2 = P3^3;

bit scan_key();

void proc_key();
void inc_sec();
void inc_min();
void inc_hour();
void display();
void delayms(unsigned char ms);

void main(void)
{
	P0 = 0xff;
	P2 = 0xff;
	TMOD = 0x11;  // ¶¨Ê±Æ÷0, 1¹¤×÷Ä£Ê½1, 16Î»¶¨Ê±·½Ê½
	TH1 = 0xdc;
	TL1 = 0;
	
	TH0 = 0xFC;
	TL0 = 0x17;
	 
	hour = 12;
	min = 00;
	sec = 00;
	
	sec100 = 0;
	 
	dis_buf[0] = dis_code[hour / 10];  // Ê±Ê®Î»
	dis_buf[1] = dis_code[hour % 10];  // Ê±¸öÎ»
	dis_buf[3] = dis_code[min / 10];  // ·ÖÊ®Î»
	dis_buf[4] = dis_code[min % 10];  // ·Ö¸öÎ»
	dis_buf[6] = dis_code[sec / 10];  // ÃëÊ®Î»
	dis_buf[7] = dis_code[sec % 10];  // Ãë¸öÎ»
	dis_buf[2] = 0xbf;      // ÏÔÊ¾"-"
	dis_buf[5] = 0xbf;      // ÏÔÊ¾"-"
	   
	dis_digit = 0xfe;
	dis_index = 0;
	 
	TCON = 0x01;
	IE = 0x8a;    // Ê¹ÄÜtimer0,1 ÖĞ¶Ï
	 
	TR0 = 1;
	TR1 = 1;
	
	key_v = 0x03;

	 while(1)
	{
	  if(scan_key())
	  {
		  delayms(10);
		  if(scan_key())
		  {
			   key_v = key_s;
			   proc_key();
		  }
	 }
 	}
}

bit scan_key()
{
	key_s = 0x00;
	key_s |= K2;
	key_s <<= 1;
	key_s |= K1;
	return(key_s ^ key_v); 
}

void proc_key()
{
	EA = 0;
	if((key_v & 0x01) == 0)  // K1
	{
		  inc_hour();  // JJ=1;
	}
	else if((key_v & 0x02) == 0) // K2
	{
		  min++;    // JJ=0;
		
		  if(min > 59)
		  {
		   min = 0;
		  }
		  dis_buf[3] = dis_code[min / 10];  // ·ÖÊ®Î»
		  dis_buf[4] = dis_code[min % 10];  // ·Ö¸öÎ»
	}
 	EA = 1;
}

void timer0() interrupt 1
								// ¶¨Ê±Æ÷0ÖĞ¶Ï·şÎñ³ÌĞò, ÓÃÓÚÊıÂë¹ÜµÄ¶¯Ì¬É¨Ãè
								// dis_index --- ÏÔÊ¾Ë÷Òı, ÓÃÓÚ±êÊ¶µ±Ç°ÏÔÊ¾µÄÊıÂë¹ÜºÍ»º³åÇøµÄÆ«ÒÆÁ¿
								// dis_digit --- Î»Ñ¡Í¨Öµ, ´«ËÍµ½P2¿ÚÓÃÓÚÑ¡Í¨µ±Ç°ÊıÂë¹ÜµÄÊıÖµ, ÈçµÈÓÚ0xfeÊ±,
								//    Ñ¡Í¨P2.0¿ÚÊıÂë¹Ü
								// dis_buf   --- ÏÔÓÚ»º³åÇøùØ· 
{
 TH0 = 0xFC;
 TL0 = 0x17;
 
 P2 = 0xff;       					// ÏÈ¹Ø±ÕËùÓĞÊıÂë¹Ü
 P0 = dis_buf[dis_index];  			 // ÏÔÊ¾´úÂë´«ËÍµ½P0¿Ú
 P2= dis_digit;     		

 dis_digit = _crol_(dis_digit,1); 	// Î»Ñ¡Í¨Öµ×óÒÆ, ÏÂ´ÎÖĞ¶ÏÊ±Ñ¡Í¨ÏÂÒ»Î»ÊıÂë¹Ü
 dis_index++;     			
     
 dis_index &= 0x07;   				// 8¸öÊıÂë¹ÜÈ«²¿É¨ÃèÍêÒ»±éÖ®ºó£¬ÔÙ»Øµ½µÚÒ»¸ö¿ªÊ¼ÏÂÒ»´ÎÉ¨Ãè
} 

void timer1() interrupt 3
{
 TH1 = 0xdc;
 
 sec100++;
 
 if(sec100 >= 100)
 {
  sec100 = 0;
  inc_sec();
 }
}

void inc_sec()
{
	sec++;
	if(sec > 59)
	{
		sec = 0;
		inc_min();
	}
 dis_buf[6] = dis_code[sec / 10];  // ÃëÊ®Î»
 dis_buf[7] = dis_code[sec % 10];  // Ãë¸öÎ» 
}

void inc_min()
{
 min++;

 if(min > 59)
 {
  	min = 0;
  	inc_hour();
 }
 dis_buf[3] = dis_code[min / 10];  	// ·ÖÊ®Î»
 dis_buf[4] = dis_code[min % 10];  	// ·Ö¸öÎ»
}

void inc_hour()
{
	hour++;

	if(hour > 23)
	{
	  	hour = 0;
	}
	if(hour > 9)
		dis_buf[0] = dis_code[hour / 10];  	// Ê±Ê®Î»
	else
		dis_buf[0] = 0xff;     				// µ±Ğ¡Ê±µÄÊ®Î»Îª0Ê±²»ÏÔÊ¾
		dis_buf[1] = dis_code[hour % 10];  	// Ê±¸öÎ»
}

void delayms(unsigned char ms) 	  			// ÑÓÊ±×Ó³ÌĞò
{      
	unsigned char i;

	while(ms--)
	{
	  for(i = 0; i < 120; i++);
	}
}



