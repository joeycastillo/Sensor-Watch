#include "TOTP.h"
#include "sha1.h"
#include "sha256.h"
#include "sha512.h"
#include <stdio.h>

uint8_t* _hmacKey;
uint8_t _keyLength;
uint8_t _timeZoneOffset;
uint32_t _timeStep;
hmac_alg _algorithm;

// Init the library with the private key, its length, the timeStep duration and the algorithm that should be used
void TOTP(uint8_t* hmacKey, uint8_t keyLength, uint32_t timeStep, hmac_alg algorithm) {
    _hmacKey = hmacKey;
    _keyLength = keyLength;
    _timeStep = timeStep;
    _algorithm = algorithm;
}

void setTimezone(uint8_t timezone){
    _timeZoneOffset = timezone;
}

static uint32_t TimeStruct2Timestamp(struct tm time){
    //time.tm_mon -= 1;
    //time.tm_year -= 1900;
    return mktime(&(time)) - (_timeZoneOffset * 3600) - 2208988800;
}

// Generate a code, using the timestamp provided
uint32_t getCodeFromTimestamp(uint32_t timeStamp) {
    uint32_t steps = timeStamp / _timeStep;
    return getCodeFromSteps(steps);
}

// Generate a code, using the timestamp provided
uint32_t getCodeFromTimeStruct(struct tm time) {
    return getCodeFromTimestamp(TimeStruct2Timestamp(time));
}

// Generate a code, using the number of steps provided
uint32_t getCodeFromSteps(uint32_t steps) {
    // STEP 0, map the number of steps in a 8-bytes array (counter value)
    uint8_t _byteArray[8];
    _byteArray[0] = 0x00;
    _byteArray[1] = 0x00;
    _byteArray[2] = 0x00;
    _byteArray[3] = 0x00;
    _byteArray[4] = (uint8_t)((steps >> 24) & 0xFF);
    _byteArray[5] = (uint8_t)((steps >> 16) & 0xFF);
    _byteArray[6] = (uint8_t)((steps >> 8) & 0XFF);
    _byteArray[7] = (uint8_t)((steps & 0XFF));

    switch(_algorithm){
        case SHA1:
            return(TOTP_HMAC_SHA1(_hmacKey, _keyLength, _byteArray, 8));
        case SHA224:
            return(TOTP_HMAC_SHA256(_hmacKey, _keyLength, _byteArray, 8, 1));
        case SHA256:
            return(TOTP_HMAC_SHA256(_hmacKey, _keyLength, _byteArray, 8, 0));
        case SHA384:
            return(TOTP_HMAC_SHA512(_hmacKey, _keyLength, _byteArray, 8, 1));
        case SHA512:
            return(TOTP_HMAC_SHA512(_hmacKey, _keyLength, _byteArray, 8, 0));
        default:
            return(0);
    }
}
