#include "TOTP.h"
#include <stdio.h>

/**
 * example.c
 */
void main(void)
{
	uint8_t hmacKey[] = {0x4d, 0x79, 0x4c, 0x65, 0x67, 0x6f, 0x44, 0x6f, 0x6f, 0x72};               // Secret key
	TOTP(hmacKey, 10, 7200, SHA1);                                                                        // Secret key, Key length, Timestep (7200s - 2hours)

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

	printf("Code : %06u\n",newCode);
}
