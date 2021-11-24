#include <msp430.h>				
#include <totp.h>
#include <stdint.h>

/**
 * blink.c
 */
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;		// stop watchdog timer
	P1DIR |= 0x01;					// configure P1.0 as output

	uint8_t hmacKey[] = {0x4d, 0x79, 0x4c, 0x65, 0x67, 0x6f, 0x44, 0x6f, 0x6f, 0x72};               // Secret key
	TOTP(hmacKey, 10, 7200);                                                                        // Secret key, Key length, Timestep (7200s - 2hours)

	setTimezone(9);                                                                                 // Set timezone
	uint32_t newCode = getCodeFromTimestamp(1557414000);                                            // Timestamp Now

	///////////////// For struct tm //////////////////
    //	struct tm datetime;
    //	datetime.tm_hour = 9;
    //	datetime.tm_min = 0;
    //	datetime.tm_sec = 0;
    //	datetime.tm_mday = 13;
    //	datetime.tm_mon = 5;
    //	datetime.tm_year = 2019;
	//  uint32_t newCode = getCodeFromTimeStruct(datetime);
	///////////////////////////////////////////////////

	volatile unsigned int i;		// volatile to prevent optimization

	while(1)
	{
	    if (newCode == 0){          // 0 = INPUT HERE
	        P1OUT ^= 0x01;          // toggle P1.0
	    }
		for(i=10000; i>0; i--);     // delay
	}
}
