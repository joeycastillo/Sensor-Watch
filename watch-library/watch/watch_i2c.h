/*
 * MIT License
 *
 * Copyright (c) 2020 Joey Castillo
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
////< @file watch_i2c.h

/** @addtogroup i2c I2C Controller Driver
  * @brief This section covers functions related to the SAM L22's built-I2C driver, including
  *        configuring the I2C bus, putting values directly on the bus and reading data from
  *        registers on I2C devices.
  */
/// @{
/** @brief Enables the I2C peripheral. Call this before attempting to interface with I2C devices.
  */
void watch_enable_i2c();

/** @brief Disables the I2C peripheral.
  */
void watch_disable_i2c();

/** @brief Sends a series of values to a device on the I2C bus.
  * @param addr The address of the device you wish to talk to.
  * @param buf A series of unsigned bytes; the data you wish to transmit.
  * @param length The number of bytes in buf that you wish to send.
  */
void watch_i2c_send(int16_t addr, uint8_t *buf, uint16_t length);

/** @brief Receives a series of values from a device on the I2C bus.
  * @param addr The address of the device you wish to hear from.
  * @param buf Storage for the incoming bytes; on return, it will contain the received data.
  * @param length The number of bytes that you wish to receive.
  */
void watch_i2c_receive(int16_t addr, uint8_t *buf, uint16_t length);

/** @brief Writes a byte to a register in an I2C device.
  * @param addr The address of the device you wish to address.
  * @param reg The register on the device that you wish to set.
  * @param data The value that you wish to set the register to.
  */
void watch_i2c_write8(int16_t addr, uint8_t reg, uint8_t data);

/** @brief Reads a byte from a register in an I2C device.
  * @param addr The address of the device you wish to address.
  * @param reg The register on the device that you wish to read.
  * @return An unsigned byte representing the value of the register that was read.
  */
uint8_t watch_i2c_read8(int16_t addr, uint8_t reg);

/** @brief Reads an unsigned little-endian word from a register in an I2C device.
  * @param addr The address of the device you wish to address.
  * @param reg The register on the device that you wish to read.
  * @return An unsigned word representing the value of the register that was read.
  * @note This reads two bytes into the word in bus order. If the device returns
          the LSB first and then the MSB, you can use this value as returned.
          If the device returns the data in big-endian order or uses some other
          kind of fancy bit packing, you may need to shuffle some bits around.
  */
uint16_t watch_i2c_read16(int16_t addr, uint8_t reg);

/** @brief Reads three bytes as an unsigned little-endian int from a register in an I2C device.
  * @param addr The address of the device you wish to address.
  * @param reg The register on the device that you wish to read.
  * @return An unsigned word representing the value of the register that was read.
  * @note This reads three bytes into the word in bus order. If the device returns
          these bytes LSB first, you can use this value as returned. If there is a
          sign bit, the device returns the data in big-endian order, or it uses some
          other kind of fancy bit packing, you may need to shuffle some bits around.
  */
uint32_t watch_i2c_read24(int16_t addr, uint8_t reg);


/** @brief Reads an unsigned little-endian int from a register in an I2C device.
  * @param addr The address of the device you wish to address.
  * @param reg The register on the device that you wish to read.
  * @return An unsigned word representing the value of the register that was read.
  * @note This reads three bytes into the word in bus order. If the device returns
          these bytes LSB first, you can use this value as returned. If the device
          returns the data in big-endian order, or it uses some other kind of fancy
          bit packing, you may need to shuffle some bits around.
  */
uint32_t watch_i2c_read32(int16_t addr, uint8_t reg);
/// @}
