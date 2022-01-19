/**
 * \file
 *
 * \brief SPI related functionality declaration.
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

#ifndef _HAL_SPI_M_SYNC_H_INCLUDED
#define _HAL_SPI_M_SYNC_H_INCLUDED

#include <hal_io.h>
#include <hpl_spi_m_sync.h>

/**
 * \addtogroup doc_driver_hal_spi_master_sync
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** \brief SPI HAL driver struct for polling mode
 *
 */
struct spi_m_sync_descriptor {
	struct _spi_m_sync_hpl_interface *func;
	/** SPI device instance */
	struct _spi_sync_dev dev;
	/** I/O read/write */
	struct io_descriptor io;
	/** Flags for HAL driver */
	uint16_t flags;
};

/** \brief Set the SPI HAL instance function pointer for HPL APIs.
 *
 *  Set SPI HAL instance function pointer for HPL APIs.
 *
 *  \param[in] spi Pointer to the HAL SPI instance.
 *  \param[in] func Pointer to the HPL api structure.
 *
 */
void spi_m_sync_set_func_ptr(struct spi_m_sync_descriptor *spi, void *const func);

/** \brief Initialize SPI HAL instance and hardware for polling mode
 *
 *  Initialize SPI HAL with polling mode.
 *
 *  \param[in] spi Pointer to the HAL SPI instance.
 *  \param[in] hw Pointer to the hardware base.
 *
 *  \return Operation status.
 *  \retval ERR_NONE Success.
 *  \retval ERR_INVALID_DATA Error, initialized.
 */
int32_t spi_m_sync_init(struct spi_m_sync_descriptor *spi, void *const hw);

/** \brief Deinitialize the SPI HAL instance and hardware
 *
 *  Abort transfer, disable and reset SPI, deinit software.
 *
 *  \param[in] spi Pointer to the HAL SPI instance.
 *
 *  \return Operation status.
 *  \retval ERR_NONE Success.
 *  \retval <0 Error code.
 */
void spi_m_sync_deinit(struct spi_m_sync_descriptor *spi);

/** \brief Enable SPI
 *
 *  \param[in] spi Pointer to the HAL SPI instance.
 *
 *  \return Operation status.
 *  \retval ERR_NONE Success.
 *  \retval <0 Error code.
 */
void spi_m_sync_enable(struct spi_m_sync_descriptor *spi);

/** \brief Disable SPI
 *
 *  \param[in] spi Pointer to the HAL SPI instance.
 *
 *  \return Operation status.
 *  \retval ERR_NONE Success.
 *  \retval <0 Error code.
 */
void spi_m_sync_disable(struct spi_m_sync_descriptor *spi);

/** \brief Set SPI baudrate
 *
 *  Works if SPI is initialized as master, it sets the baudrate.
 *
 *  \param[in] spi Pointer to the HAL SPI instance.
 *  \param[in] baud_val The target baudrate value
 *                  (see "baudrate calculation" for calculating the value).
 *
 *  \return Operation status.
 *  \retval ERR_NONE Success.
 *  \retval ERR_BUSY Busy
 *  \retval ERR_INVALID_ARG The baudrate is not supported.
 */
int32_t spi_m_sync_set_baudrate(struct spi_m_sync_descriptor *spi, const uint32_t baud_val);

/** \brief Set SPI mode
 *
 *  Set the SPI transfer mode (\ref spi_transfer_mode),
 *  which controls the clock polarity and clock phase:
 *  - Mode 0: leading edge is rising edge, data sample on leading edge.
 *  - Mode 1: leading edge is rising edge, data sample on trailing edge.
 *  - Mode 2: leading edge is falling edge, data sample on leading edge.
 *  - Mode 3: leading edge is falling edge, data sample on trailing edge.
 *
 *  \param[in] spi Pointer to the HAL SPI instance.
 *  \param[in] mode The mode (0~3).
 *
 *  \return Operation status.
 *  \retval ERR_NONE Success.
 *  \retval ERR_BUSY Busy
 *  \retval ERR_INVALID_ARG The mode is not supported.
 */
int32_t spi_m_sync_set_mode(struct spi_m_sync_descriptor *spi, const enum spi_transfer_mode mode);

/** \brief Set SPI transfer character size in number of bits
 *
 *  The character size (\ref spi_char_size) influence the way the data is
 *  sent/received.
 *  For char size <= 8-bit, data is stored byte by byte.
 *  For char size between 9-bit ~ 16-bit, data is stored in 2-byte length.
 *  Note that the default and recommended char size is 8-bit since it's
 *  supported by all system.
 *
 *  \param[in] spi Pointer to the HAL SPI instance.
 *  \param[in] char_size The char size (~16, recommended 8).
 *
 *  \return Operation status.
 *  \retval ERR_NONE Success.
 *  \retval ERR_BUSY Busy
 *  \retval ERR_INVALID_ARG The char size is not supported.
 */
int32_t spi_m_sync_set_char_size(struct spi_m_sync_descriptor *spi, const enum spi_char_size char_size);

/** \brief Set SPI transfer data order
 *
 *  \param[in] spi Pointer to the HAL SPI instance.
 *  \param[in] dord The data order: send LSB/MSB first.
 *
 *  \return Operation status.
 *  \retval ERR_NONE Success.
 *  \retval ERR_BUSY Busy
 *  \retval ERR_INVALID_ARG The data order is not supported.
 */
int32_t spi_m_sync_set_data_order(struct spi_m_sync_descriptor *spi, const enum spi_data_order dord);

/** \brief Perform the SPI data transfer (TX and RX) in polling way
 *
 *  Activate CS, do TX and RX and deactivate CS. It blocks.
 *
 *  \param[in, out] spi Pointer to the HAL SPI instance.
 *  \param[in] xfer Pointer to the transfer information (\ref spi_xfer).
 *
 *  \retval size Success.
 *  \retval >=0 Timeout, with number of characters transferred.
 *  \retval ERR_BUSY SPI is busy
 */
int32_t spi_m_sync_transfer(struct spi_m_sync_descriptor *spi, const struct spi_xfer *xfer);

/**
 * \brief Return the I/O descriptor for this SPI instance
 *
 * This function will return an I/O instance for this SPI driver instance.
 *
 * \param[in] spi An SPI master descriptor, which is used to communicate through
 *                SPI
 * \param[in, out] io A pointer to an I/O descriptor pointer type
 *
 * \retval ERR_NONE
 */
int32_t spi_m_sync_get_io_descriptor(struct spi_m_sync_descriptor *const spi, struct io_descriptor **io);

/** \brief Retrieve the current driver version
 *
 *  \return Current driver version.
 */
uint32_t spi_m_sync_get_version(void);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif /* ifndef _HAL_SPI_M_SYNC_H_INCLUDED */
