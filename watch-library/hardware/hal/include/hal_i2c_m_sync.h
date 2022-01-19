/**
 * \file
 *
 * \brief Sync I2C Hardware Abstraction Layer(HAL) declaration.
 *
 * Copyright (c) 2014-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */

#ifndef _HAL_I2C_M_SYNC_H_INCLUDED
#define _HAL_I2C_M_SYNC_H_INCLUDED

#include <hpl_i2c_m_sync.h>
#include <hal_io.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \addtogroup doc_driver_hal_i2c_controller_sync
 *
 * @{
 */

#define I2C_M_MAX_RETRY 1

/**
 * \brief I2C descriptor structure, embed i2c_device & i2c_interface
 */
struct i2c_m_sync_desc {
	struct _i2c_m_sync_device device;
	struct io_descriptor      io;
	uint16_t                  periph_addr;
};

/**
 * \brief Initialize synchronous I2C interface
 *
 * This function initializes the given I/O descriptor to be used as a
 * synchronous I2C interface descriptor.
 * It checks if the given hardware is not initialized and if the given hardware
 * is permitted to be initialized.
 *
 * \param[in] i2c An I2C descriptor, which is used to communicate through I2C
 * \param[in] hw The pointer to hardware instance
 *
 * \return Initialization status.
 * \retval -1 The passed parameters were invalid or the interface is already initialized
 * \retval 0 The initialization is completed successfully
 */
int32_t i2c_m_sync_init(struct i2c_m_sync_desc *i2c, void *hw);

/**
 * \brief Deinitialize I2C interface
 *
 * This function deinitializes the given I/O descriptor.
 * It checks if the given hardware is initialized and if the given hardware is permitted to be deinitialized.
 *
 * \param[in] i2c An I2C descriptor, which is used to communicate through I2C
 *
 * \return Uninitialization status.
 * \retval -1 The passed parameters were invalid or the interface is already deinitialized
 * \retval 0 The de-initialization is completed successfully
 */
int32_t i2c_m_sync_deinit(struct i2c_m_sync_desc *i2c);

/**
 * \brief Set the peripheral device address
 *
 * This function sets the next transfer target peripheral I2C device address.
 * It takes no effect to any already started access.
 *
 * \param[in] i2c An I2C descriptor, which is used to communicate through I2C
 * \param[in] addr The peripheral address to access
 * \param[in] addr_len The peripheral address length, can be I2C_M_TEN or I2C_M_SEVEN
 *
 * \return Masked peripheral address. The mask is a maximum 10-bit address, and 10th
 *         bit is set if a 10-bit address is used
 */
int32_t i2c_m_sync_set_periphaddr(struct i2c_m_sync_desc *i2c, int16_t addr, int32_t addr_len);

/**
 * \brief Set baudrate
 *
 * This function sets the I2C device to the specified baudrate.
 * It only takes effect when the hardware is disabled.
 *
 * \param[in] i2c An I2C descriptor, which is used to communicate through I2C
 * \param[in] clkrate Unused parameter. Should always be 0
 * \param[in] baudrate The baudrate value set to controller
 *
 * \return Whether successfully set the baudrate
 * \retval -1 The passed parameters were invalid or the device is already enabled
 * \retval 0 The baudrate set is completed successfully
 */
int32_t i2c_m_sync_set_baudrate(struct i2c_m_sync_desc *i2c, uint32_t clkrate, uint32_t baudrate);

/**
 * \brief Sync version of enable hardware
 *
 * This function enables the I2C device, and then waits for this enabling operation to be done
 *
 * \param[in] i2c An I2C descriptor, which is used to communicate through I2C
 *
 * \return Whether successfully enable the device
 * \retval -1 The passed parameters were invalid or the device enable failed
 * \retval 0 The hardware enabling is completed successfully
 */
int32_t i2c_m_sync_enable(struct i2c_m_sync_desc *i2c);

/**
 * \brief Sync version of disable hardware
 *
 * This function disables the I2C device and then waits for this disabling operation to be done
 *
 * \param[in] i2c An I2C descriptor, which is used to communicate through I2C
 *
 * \return Whether successfully disable the device
 * \retval -1 The passed parameters were invalid or the device disable failed
 * \retval 0 The hardware disabling is completed successfully
 */
int32_t i2c_m_sync_disable(struct i2c_m_sync_desc *i2c);

/**
 * \brief Sync version of write command to I2C peripheral
 *
 * This function will write the value to a specified register in the I2C peripheral device and
 * then wait for this operation to be done.
 *
 * The sequence of this routine is
 * sta->address(write)->ack->reg address->ack->resta->address(write)->ack->reg value->nack->stt
 *
 * \param[in] i2c An I2C descriptor, which is used to communicate through I2C
 * \param[in] reg The internal address/register of the I2C peripheral device
 * \param[in] buffer The buffer holding data to write to the I2C peripheral device
 * \param[in] length The length (in bytes) to write to the I2C peripheral device
 *
 * \return Whether successfully write to the device
 * \retval <0 The passed parameters were invalid or write fail
 * \retval 0 Writing to register is completed successfully
 */
int32_t i2c_m_sync_cmd_write(struct i2c_m_sync_desc *i2c, uint8_t reg, uint8_t *buffer, uint8_t length);

/**
 * \brief Sync version of read register value from I2C peripheral
 *
 * This function will read a byte value from a specified register in the I2C peripheral device and
 * then wait for this operation to be done.
 *
 * The sequence of this routine is
 * sta->address(write)->ack->reg address->ack->resta->address(read)->ack->reg value->nack->stt
 *
 * \param[in] i2c An I2C descriptor, which is used to communicate through I2C
 * \param[in] reg The internal address/register of the I2C peripheral device
 * \param[in] buffer The buffer to hold the read data from the I2C peripheral device
 * \param[in] length The length (in bytes) to read from the I2C peripheral device
 *
 * \return Whether successfully read from the device
 * \retval <0 The passed parameters were invalid or read fail
 * \retval 0 Reading from register is completed successfully
 */
int32_t i2c_m_sync_cmd_read(struct i2c_m_sync_desc *i2c, uint8_t reg, uint8_t *buffer, uint8_t length);

/**
 * \brief Sync version of transfer message to/from the I2C peripheral
 *
 * This function will transfer a message between the I2C peripheral and the controller. 
 * This function will wait for the operation to be done.
 *
 * \param[in] i2c An I2C descriptor, which is used to communicate through I2C
 * \param[in] msg  An i2c_m_msg struct
 *
 * \return The status of the operation
 * \retval 0 Operation completed successfully
 * \retval <0 Operation failed
 */
int32_t i2c_m_sync_transfer(struct i2c_m_sync_desc *const i2c, struct _i2c_m_msg *msg);

/**
 * \brief Sync version of send stop condition on the i2c bus
 *
 * This function will create a stop condition on the i2c bus to release the bus
 *
 * \param[in] i2c An I2C descriptor, which is used to communicate through I2C
 *
 * \return The status of the operation
 * \retval 0 Operation completed successfully
 * \retval <0 Operation failed
 */
int32_t i2c_m_sync_send_stop(struct i2c_m_sync_desc *const i2c);

/**
 * \brief Return I/O descriptor for this I2C instance
 *
 * This function will return a I/O instance for this I2C driver instance
 *
 * \param[in] i2c_m_sync_desc An I2C descriptor, which is used to communicate through I2C
 * \param[in] io_descriptor A pointer to an I/O descriptor pointer type
 *
 * \return Error code
 * \retval 0 No error detected
 * \retval <0 Error code
 */
int32_t i2c_m_sync_get_io_descriptor(struct i2c_m_sync_desc *const i2c, struct io_descriptor **io);

/**
 * \brief Retrieve the current driver version
 *
 * \return Current driver version.
 */
uint32_t i2c_m_sync_get_version(void);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
