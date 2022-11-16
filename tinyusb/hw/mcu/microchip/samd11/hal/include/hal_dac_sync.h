/**
 * \file
 *
 * \brief DAC functionality declaration.
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

#ifndef HAL_SYNC_DAC_H_INCLUDED
#define HAL_SYNC_DAC_H_INCLUDED

#include <hpl_dac_sync.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \addtogroup doc_driver_hal_dac_sync
 *
 *@{
 */

/**
 * \brief DAC synchronous descriptor.
 *
 * The DAC descriptor forward declaration.
 */
struct dac_sync_descriptor;

/**
 * \brief DAC synchronous channel descriptor.
 *
 */
struct dac_sync_channel {
	/** Pointer to buffer what to be converted */
	uint16_t *buffer;
	/** The length of buffer */
	uint32_t length;
};

/**
 * \brief DAC synchronous descriptor
 */
struct dac_sync_descriptor {
	/** DAC device */
	struct _dac_sync_device device;
	/** DAC selected channel */
	struct dac_sync_channel sel_ch[CHANNEL_NUM];
};

/** \brief Initialize the DAC HAL instance and hardware.
 *  \param[out] descr A DAC descriptor to initialize
 *  \param[in] hw The pointer to hardware instance
 *  \return Operation status.
 */
int32_t dac_sync_init(struct dac_sync_descriptor *const descr, void *const hw);

/** \brief Deinitialize the DAC HAL instance and hardware.
 *  \param[in] descr Pointer to the HAL DAC descriptor
 *  \return Operation status.
 */
int32_t dac_sync_deinit(struct dac_sync_descriptor *const descr);

/** \brief Enable DAC channel.
 *  \param[in] descr Pointer to the HAL DAC descriptor
 *  \param[in] ch  Channel number
 *  \return Operation status.
 */
int32_t dac_sync_enable_channel(struct dac_sync_descriptor *const descr, const uint8_t ch);

/** \brief Disable DAC channel.
 *  \param[in] descr Pointer to the HAL DAC descriptor
 *  \param[in] ch  Channel number
 *  \return Operation status.
 */
int32_t dac_sync_disable_channel(struct dac_sync_descriptor *const descr, const uint8_t ch);

/** \brief DAC converts digital data to analog output.
 *  \param[in] descr   Pointer to the HAL DAC descriptor
 *  \param[in] ch the  Channel selected to output
 *  \param[in] buffer  Pointer to digital data or buffer
 *  \param[in] length  The number of elements in the buffer
 *  \return Operation status.
 */
int32_t dac_sync_write(struct dac_sync_descriptor *const descr, const uint8_t ch, uint16_t *buffer, uint32_t length);

/** \brief Get DAC driver version
 *
 *  \return Current driver version.
 */
uint32_t dac_sync_get_version(void);
/**@}*/

#ifdef __cplusplus
}
#endif

#endif /* HAL_DAC_H_INCLUDED */
