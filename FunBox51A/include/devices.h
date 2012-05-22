#define	PORT_LED		P0
#define	PORT_SWITCH		P2
#define	PORT_BEEP		P3
#define	PORT_BEEP_PIN	4

unsigned char led(unsigned char pattern);
void ledAllOff(void);

void beepOFF(void);
void beepON(void);

