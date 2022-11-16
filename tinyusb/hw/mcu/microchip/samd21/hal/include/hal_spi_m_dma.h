/**
 * \file
 *
 * \brief SPI DMA related functionality declaration.
 *
 * Copyright (C) 2016 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

#ifndef _HAL_SPI_M_DMA_H_INCLUDED
#define _HAL_SPI_M_DMA_H_INCLUDED

#include <hal_io.h>
#include <hpl_spi_m_dma.h>

/**
 * \addtogroup doc_driver_hal_spi_master_dma
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declaration of spi_descriptor. */
struct spi_m_dma_descriptor;

/** The callback types */
enum spi_m_dma_cb_type {
	/** Callback type for DMA transfer buffer done */
	SPI_M_DMA_CB_TX_DONE,
	/** Callback type for DMA receive buffer done */
	SPI_M_DMA_CB_RX_DONE,
	/** Callback type for DMA errors */
	SPI_M_DMA_CB_ERROR,
	SPI_M_DMA_CB_N
};

/**
 * \brief SPI Master DMA callback type
 */
typedef void (*spi_m_dma_cb_t)(struct _dma_resource *resource);

/** \brief SPI HAL driver struct for DMA access
 */
struct spi_m_dma_descriptor {
	/** Pointer to SPI device instance */
	struct _spi_m_dma_dev dev;
	/** I/O read/write */
	struct io_descriptor io;
	/** DMA resource */
	struct _dma_resource *resource;
};

/** \brief Initialize the SPI HAL instance and hardware for DMA mode
 *
 *  Initialize SPI HAL with dma mode.
 *
 *  \param[in] spi Pointer to the HAL SPI instance.
 *  \param[in] hw Pointer to the hardware base.
 *
 *  \return Operation status.
 *  \retval ERR_NONE Success.
 *  \retval ERR_INVALID_DATA Error, initialized.
 */
int32_t spi_m_dma_init(struct spi_m_dma_descriptor *spi, void *const hw);

/** \brief Deinitialize the SPI HAL instance
 *
 *  Abort transfer, disable and reset SPI, de-init software.
 *
 *  \param[in] spi Pointer to the HAL SPI instance.
 *
 *  \return Operation status.
 *  \retval ERR_NONE Success.
 *  \retval <0 Error code.
 */
void spi_m_dma_deinit(struct spi_m_dma_descriptor *spi);

/** \brief Enable SPI
 *
 *  \param[in] spi Pointer to the HAL SPI instance.
 *
 *  \return Operation status.
 *  \retval ERR_NONE Success.
 *  \retval <0 Error code.
 */
void spi_m_dma_enable(struct spi_m_dma_descriptor *spi);

/** \brief Disable SPI
 *
 *  \param[in] spi Pointer to the HAL SPI instance.
 *
 *  \return Operation status.
 *  \retval ERR_NONE Success.
 *  \retval <0 Error code.
 */
void spi_m_dma_disable(struct spi_m_dma_descriptor *spi);

/** \brief Set SPI baudrate
 *
 *  Works if SPI is initialized as master.
 *  In the function a sanity check is used to confirm it's called in the correct mode.
 *
 *  \param[in] spi Pointer to the HAL SPI instance.
 *  \param[in] baud_val The target baudrate value
 *                  (See "baudrate calculation" for calculating the value).
 *
 *  \return Operation status.
 *  \retval ERR_NONE Success.
 *  \retval ERR_BUSY Busy.
 */
int32_t spi_m_dma_set_baudrate(struct spi_m_dma_descriptor *spi, const uint32_t baud_val);

/** \brief Set SPI mode
 *
 *  Set SPI transfer mode (\ref spi_transfer_mode),
 * which controls clock polarity and clock phase:
 *  - Mode 0: leading edge is rising edge, data sample on leading edge.
 *  - Mode 1: leading edge is rising edge, data sample on trailing edge.
 *  - Mode 2: leading edge is falling edge, data sample on leading edge.
 *  - Mode 3: leading edge is falling edge, data sample on trailing edge.
 *
 *  \param[in] spi Pointer to the HAL SPI instance.
 *  \param[in] mode The mode (\ref spi_transfer_mode).
 *
 *  \return Operation status.
 *  \retval ERR_NONE Success.
 *  \retval ERR_BUSY Busy, CS activated.
 */
int32_t spi_m_dma_set_mode(struct spi_m_dma_descriptor *spi, const enum spi_transfer_mode mode);

/** \brief Set the SPI transfer character size in number of bits
 *
 *  The character size (\ref spi_char_size) influence the way the data is
 *  sent/received.
 *  For char size <= 8-bit, data is stored byte by byte.
 *  For char size between 9-bit ~ 16-bit, data is stored in 2-byte length.
 *  Note that the default and recommended char size is 8-bit since it's
 *  supported by all system.
 *
 *  \param[in] spi Pointer to the HAL SPI instance.
 *  \param[in] char_size The char size (\ref spi_char_size).
 *
 *  \return Operation status.
 *  \retval ERR_NONE Success.
 *  \retval ERR_BUSY Busy, CS activated.
 *  \retval ERR_INVALID_ARG The char size is not supported.
 */
int32_t spi_m_dma_set_char_size(struct spi_m_dma_descriptor *spi, const enum spi_char_size char_size);

/** \brief Set SPI transfer data order
 *
 *  \param[in] spi Pointer to the HAL SPI instance.
 *  \param[in] dord The data order: send LSB/MSB first.
 *
 *  \return Operation status.
 *  \retval ERR_NONE Success.
 *  \retval ERR_BUSY Busy, CS activated.
 *  \retval ERR_INVALID The data order is not supported.
 */
int32_t spi_m_dma_set_data_order(struct spi_m_dma_descriptor *spi, const enum spi_data_order dord);

/** \brief Perform the SPI data transfer (TX and RX) with the DMA
 *
 *  \param[in] spi Pointer to the HAL SPI instance.
 *  \param[in] txbuf Pointer to the transfer information.
 *  \param[out] rxbuf Pointer to the receiver information.
 *  \param[in] length SPI transfer data length.
 *
 *  \return Operation status.
 *  \retval ERR_NONE Success.
 *  \retval ERR_BUSY Busy.
 */
int32_t spi_m_dma_transfer(struct spi_m_dma_descriptor *spi, uint8_t const *txbuf, uint8_t *const rxbuf,
                           const uint16_t length);

/** \brief Register a function as an SPI transfer completion callback
 *
 *  Register a callback function specified by its \c type.
 *  - SPI_CB_COMPLETE: set the function that will be called on the SPI transfer
 *    completion including deactivating the CS.
 *  - SPI_CB_XFER: set the function that will be called on the SPI buffer transfer
 *    completion.
 *  Register a NULL function to not use the callback.
 *
 *  \param[in] spi Pointer to the HAL SPI instance.
 *  \param[in] type Callback type (\ref spi_m_dma_cb_type).
 *  \param[in] func Pointer to callback function.
 */
void spi_m_dma_register_callback(struct spi_m_dma_descriptor *spi, const enum spi_m_dma_cb_type type,
                                 spi_m_dma_cb_t func);

/**
 * \brief Return I/O descriptor for this SPI instance
 *
 * This function will return an I/O instance for this SPI driver instance
 *
 * \param[in] spi An SPI master descriptor, which is used to communicate through
 *                SPI
 * \param[in, out] io A pointer to an I/O descriptor pointer type
 *
 * \retval ERR_NONE
 */
int32_t spi_m_dma_get_io_descriptor(struct spi_m_dma_descriptor *const spi, struct io_descriptor **io);

/** \brief Retrieve the current driver version
 *
 *  \return Current driver version.
 */
uint32_t spi_m_dma_get_version(void);

#ifdef __cplusplus
}
#endif
/**@}*/
#endif /* ifndef _HAL_SPI_M_DMA_H_INCLUDED */
