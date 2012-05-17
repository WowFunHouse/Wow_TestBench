/*
 Date: 		2012-05-15
 Created By:	Michael

 Subject:	Prototypes
 */

// Get switch status of switches
unsigned char getsw(void);

// Display different patterns on LEDs
void ledptn(unsigned char pattern);

// Make different sounds from Beeper
void beepsnd(unsigned int freq, unsigned int dur_ms);

void setflag(void);
unsigned char chkflag(void);

static unsigned char	flat_stop;
static unsigned char	last_key;
