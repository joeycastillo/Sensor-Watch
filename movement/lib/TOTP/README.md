TOTP Pure C Library
====================

Library to generate Time-based One-Time Passwords.

Implements the Time-based One-Time Password algorithm specified in [RFC 6238](https://tools.ietf.org/html/rfc6238). 

Supports different time steps and is compatible with tokens that use the same standard (including software ones, like the Google Authenticator app).

The code is made of :

- [TOTP-MCU](https://github.com/Netthaw/TOTP-MCU) for `TimeStruct2Timestamp`, `getCodeFromTimestamp`, `getCodeFromTimeStruct`, part of `getCodeFromSteps` and `TOTP_HMAC_SHA*` functions
- [mbedtls](https://github.com/Mbed-TLS/mbedtls) for SHA1/SHA224/SHA256/SHA384/SHA512 implementations
- [this project](https://github.com/mygityf/cipher/blob/master/cipher/hmac.c) as an inspiration for writing the code to compute the TOTP using the key and the text to hash



Supported algorithms are SHA1/SHA224/SHA256/SHA384/SHA512.



Installation & usage:
--------------------
First include header to your file
```c
#include "TOTP.h"
```
After included, define key ex. Key is ```MyLegoDoor```
- Note: The format of hmacKey is array of hexadecimal bytes.
- Most websites provide the key encoded in base32 - RFC3548/RFC4648, either upper or lower case. You can use [this site](https://cryptii.com/pipes/base32-to-hex) to convert the base32 string to hex (make sure you upcase it first if it's lowercase and remove all whitespaces).
```c
uint8_t hmacKey[] = {0x4d, 0x79, 0x4c, 0x65, 0x67, 0x6f, 0x44, 0x6f, 0x6f, 0x72};               // Secret key
```
Instantiate the TOTP class by providing the secret hmacKey, the length of the hmacKey, the Timestep between codes and the algorithm used (most of the time, `SHA1`).
```c
TOTP(hmacKey, 10, 30, SHA1);                                     // Secret key, Secret key length, Timestep (30s), Algorithm
```
Use the ```getCodeFromTimestamp()``` function to get a TOTP from a unix epoch timestamp
```c
uint32_t newCode = getCodeFromTimestamp(1557414000);       // Current timestamp since Unix epoch in seconds
```
Or ```getCodeFromTimeStruct()``` if you want to get a TOTP from a tm struct (Time Struct in C), 
```c
struct tm datetime;
datetime.tm_hour = 9;
datetime.tm_min = 0;
datetime.tm_sec = 0;
datetime.tm_mday = 13;
datetime.tm_mon = 5;
datetime.tm_year = 2019;
uint32_t newCode = getCodeFromTimeStruct(datetime);
```

If the provided unix timestamp isn't in UTC±0, use ```setTimezone()``` before ```getCodeFromTimestamp()``` or ```getCodeFromTimeStruct()``` to offset the time.

```c
setTimezone(9);                                            // Set timezone +9 Japan
```

You can see an example in example.c (compile it with `gcc -o example example.c sha1.c sha256.c sha512.c TOTP.c -I.`)

Thanks to:
----------

* Netthaw, https://github.com/Netthaw/TOTP-MCU
* Mbed-TLS, https://github.com/Mbed-TLS/mbedtls
* mygityf, https://github.com/mygityf/cipher/blob/master/cipher/hmac.c
* susam, https://github.com/susam/mintotp
