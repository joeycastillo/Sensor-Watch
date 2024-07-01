#ifndef TOTP_H_
#define TOTP_H_

#include <inttypes.h>
#include "time.h"

typedef enum __attribute__ ((__packed__)) {
    SHA1,
    SHA224,
    SHA256,
    SHA384,
    SHA512
} hmac_alg;

void TOTP(uint8_t* hmacKey, uint8_t keyLength, uint32_t timeStep, hmac_alg algorithm);
void setTimezone(uint8_t timezone);
uint32_t getCodeFromTimestamp(uint32_t timeStamp);
uint32_t getCodeFromTimeStruct(struct tm time);
uint32_t getCodeFromSteps(uint32_t steps);

#endif // TOTP_H_
