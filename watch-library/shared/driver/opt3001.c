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
#include <math.h>

#include "opt3001.h"
#include "watch_utility.h"

uint16_t opt3001_readManufacturerID(uint8_t devaddr) {
	uint8_t buf[2];
	buf[0] = (uint8_t) OPT3001_MANUFACTURER_ID; 
	watch_i2c_send(devaddr, buf, 1);
	watch_i2c_receive(devaddr, buf, 2);
    return ((uint16_t) buf[0] << 8) | ((uint16_t) buf[1]);
}

uint16_t opt3001_readDeviceID(uint8_t devaddr) {
	uint8_t buf[2];
   	buf[0] = (uint8_t) OPT3001_DEVICE_ID; 
	watch_i2c_send(devaddr, buf, 1);
	watch_i2c_receive(devaddr, buf, 2);
    return ((uint16_t) buf[0] << 8) | ((uint16_t) buf[1]);
}

opt3001_Config_t opt3001_readConfig(uint8_t devaddr) {
	opt3001_Config_t config;
	uint8_t buf[2];
	buf[0] = (uint8_t) OPT3001_CONFIG; 
	watch_i2c_send(devaddr, buf, 1);
	watch_i2c_receive(devaddr, buf, 2);
    config.rawData = ((uint16_t) buf[0] << 8) | ((uint16_t) buf[1]);
	return config;
}

void opt3001_writeConfig(uint8_t devaddr, opt3001_Config_t config) {
    uint8_t buf[3] = {OPT3001_CONFIG, (uint8_t)(config.rawData >> 8), (uint8_t)(config.rawData & 0x00FF)};
    watch_i2c_send(devaddr, buf, 3);
	return;
}

opt3001_t opt3001_readResult(uint8_t devaddr) {
	return opt3001_readRegister(devaddr, OPT3001_RESULT);
}

opt3001_t opt3001_readHighLimit(uint8_t devaddr) {
	return opt3001_readRegister(devaddr, OPT3001_HIGH_LIMIT);
}

opt3001_t opt3001_readLowLimit(uint8_t devaddr) {
	return opt3001_readRegister(devaddr, OPT3001_LOW_LIMIT);
}

opt3001_t opt3001_readRegister(uint8_t devaddr, opt3001_Command_t command) {
    opt3001_t result;
    opt3001_ER_t er;
    uint8_t buf[2]; 
	buf[0] = (uint8_t) command; 
	watch_i2c_send(devaddr, buf, 1);
	watch_i2c_receive(devaddr, buf, 2);
    er.rawData = ((uint16_t) buf[0] << 8) | ((uint16_t) buf[1]);
    result.raw = er;
    result.lux = 0.01*pow(2, er.Exponent)*er.Result;
    return result;
}
