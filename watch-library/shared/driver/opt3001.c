/*

Arduino library for Texas Instruments opt3001_t Digital Ambient Light Sensor
Written by AA for ClosedCube
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
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

*/

#include "opt3001.h"

uint16_t opt3001_readManufacturerID() {
    return watch_i2c_read16(opt3001_address, OPT3001_MANUFACTURER_ID);
}

uint16_t opt3001_readDeviceID() {
    return watch_i2c_read16(opt3001_address, OPT3001_DEVICE_ID);
}

opt3001_Config_t opt3001_readConfig() {
	opt3001_Config_t config;
    config.rawData = watch_i2c_read16(opt3001_address, OPT3001_CONFIG);
	return config;
}

void opt3001_writeConfig(opt3001_Config_t config) {
    watch_i2c_write8(opt3001_address, OPT3001_CONFIG, (uint8_t)(config.rawData >> 8));
    watch_i2c_write8(opt3001_address, OPT3001_CONFIG+1, (uint8_t)(config.rawData & 0x00FF));
	return;
}

opt3001_t opt3001_readResult() {
	return opt3001_readRegister(OPT3001_RESULT);
}

opt3001_t opt3001_readHighLimit() {
	return opt3001_readRegister(OPT3001_HIGH_LIMIT);
}

opt3001_t opt3001_readLowLimit() {
	return opt3001_readRegister(OPT3001_LOW_LIMIT);
}

opt3001_t opt3001_readRegister(opt3001_Command_t command) {
	opt3001_ER_t er;
	er.rawData = watch_i2c_read16(opt3001_address, command);
	opt3001_t result;
	result.raw = er;
	result.lux = 0.01*pow(2, er.Exponent)*er.Result;
	return result;
}
