/*

Arduino library for Texas Instruments OPT3001 Digital Ambient Light Sensor
Adapted to Sensor-Watch interface by CC
---

The MIT License (MIT)

Copyright (c) 2015 ClosedCube Limited

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY	 CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

*/

#ifndef OPT3001_
#define OPT3001_
#include <stdint.h>

typedef enum {
	OPT3001_RESULT		= 0x00,
	OPT3001_CONFIG		= 0x01,
	OPT3001_LOW_LIMIT	= 0x02,
	OPT3001_HIGH_LIMIT	= 0x03,

	OPT3001_MANUFACTURER_ID = 0x7E,
	OPT3001_DEVICE_ID		= 0x7F,
} opt3001_Command_t;

typedef union {
	uint16_t rawData;
	struct {
		uint16_t Result : 12;
		uint8_t Exponent : 4;
	};
} opt3001_ER_t;


typedef union {
	struct {
		uint8_t FaultCount : 2;
		uint8_t MaskExponent : 1;
		uint8_t Polarity : 1;
		uint8_t Latch : 1;
		uint8_t FlagLow : 1;
		uint8_t FlagHigh : 1;
		uint8_t ConversionReady : 1;
		uint8_t OverflowFlag : 1;
		uint8_t ModeOfConversionOperation : 2;
		uint8_t ConversionTime : 1;
		uint8_t RangeNumber : 4;		
	};
	uint16_t rawData;
} opt3001_Config_t;

typedef struct {
	float lux;
	opt3001_ER_t raw;
} opt3001_t;

uint16_t opt3001_readManufacturerID(uint8_t devaddr);
uint16_t opt3001_readDeviceID(uint8_t devaddr);

opt3001_t opt3001_readResult(uint8_t devaddr);
opt3001_t opt3001_readHighLimit(uint8_t devaddr);
opt3001_t opt3001_readLowLimit(uint8_t devaddr);

opt3001_Config_t opt3001_readConfig(uint8_t devaddr);
void opt3001_writeConfig(uint8_t devaddr, opt3001_Config_t config);
opt3001_t opt3001_readRegister(uint8_t devaddr, opt3001_Command_t command);

#endif // OPT3001_
