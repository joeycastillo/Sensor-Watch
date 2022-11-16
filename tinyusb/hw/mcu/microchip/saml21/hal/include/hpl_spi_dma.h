/**
 * \file
 *
 * \brief Common SPI DMA related functionality declaration.
 *
 * Copyright (c) 2016-2018 Microchip Technology Inc. and its subsidiaries.
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

#ifndef _HPL_SPI_DMA_H_INCLUDED
#define _HPL_SPI_DMA_H_INCLUDED

#include <hpl_irq.h>
#include <hpl_dma.h>

#ifdef __cplusplus
extern "C" {
#endif

/** The callback types */
enum _spi_dma_dev_cb_type {
	/** Callback type for DMA transmit. */
	SPI_DEV_CB_DMA_TX,
	/** Callback type for DMA receive. */
	SPI_DEV_CB_DMA_RX,
	/** Callback type for DMA error. */
	SPI_DEV_CB_DMA_ERROR,
	/** Number of callbacks. */
	SPI_DEV_CB_DMA_N
};

struct _spi_dma_dev;

/**
 *  \brief The prototype for callback on SPI DMA.
 */
typedef void (*_spi_dma_cb_t)(struct _dma_resource *resource);

/**
 *  \brief The callbacks offered by SPI driver
 */
struct _spi_dma_dev_callbacks {
	_spi_dma_cb_t tx;
	_spi_dma_cb_t rx;
	_spi_dma_cb_t error;
};

/** SPI driver to support DMA HAL */
struct _spi_dma_dev {
	/** Pointer to the hardware base or private data for special device. */
	void *prvt;
	/** Pointer to callback functions */
	struct _spi_dma_dev_callbacks callbacks;
	/** IRQ instance for SPI device. */
	struct _irq_descriptor irq;
	/** DMA resource */
	struct _dma_resource *resource;
};

#ifdef __cplusplus
}
#endif

#endif /* ifndef _HPL_SPI_DMA_H_INCLUDED */
