/**
 * \file
 *
 * \brief DAC related functionality declaration.
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
#ifndef _HPL_DAC_H_INCLUDED
#define _HPL_DAC_H_INCLUDED

/**
 * \addtogroup hpl__dac__group DAC HPL APIs
 * See interface description here: \ref hpl__dac__doc
 *
 */

/**@{*/

#include <compiler.h>
#include "hpl_irq.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * DAC hardware Channel Number
 */

#ifndef CHANNEL_NUM
#define CHANNEL_NUM 1
#endif

/**
 * \brief DAC callback types
 */
enum _dac_callback_type { DAC_DEVICE_CONVERSION_DONE_CB, DAC_DEVICE_ERROR_CB };

/**
 * \brief DAC device structure
 *
 * The DAC device structure forward declaration.
 */
struct _dac_async_device;

/**
 * \brief DAC interrupt handlers structure
 */
struct _dac_callback {
	/** Transmit ready(Data Buffer empty) handler */
	void (*tx_ready_cb)(struct _dac_async_device *device, const uint8_t ch);
	/** Error handler */
	void (*tx_error_cb)(struct _dac_async_device *device, const uint8_t ch);
};

/**
 * \brief DAC descriptor device structure.
 */
struct _dac_async_device {
	struct _dac_callback   dac_cb; /*!< Interrupt handers  */
	struct _irq_descriptor irq;    /*!< Interrupt descriptor */
	void *                 hw;     /*!< Hardware module instance handler */
};

/**
 * \brief Initialize asynchronous DAC.
 *
 * This function does low level DAC configuration.
 *
 * \param[in] device The pointer to DAC device instance
 * \param[in] hw The pointer to hardware instance
 *
 * \return Initialization status
 */
int32_t _dac_async_init(struct _dac_async_device *const device, void *const hw);

/**
 * \brief Deinitialize DAC.
 *
 * \param[in] device The pointer to DAC device instance
 */
void _dac_async_deinit(struct _dac_async_device *const device);

/**
 * \brief Enable DAC Channel.
 *
 * \param[in] device The pointer to DAC device instance
 * \param[in] ch  channel number
 */
void _dac_async_enable_channel(struct _dac_async_device *const device, const uint8_t ch);

/**
 * \brief Disable DAC Channel.
 *
 * \param[in] device The pointer to DAC device instance
 * \param[in] ch  channel number
 */
void _dac_async_disable_channel(struct _dac_async_device *const device, const uint8_t ch);

/**
 * \brief Checks if DAC channel is enabled
 *
 * \param[in] device The pointer to DAC device instance
 * \param[in] ch  channel number
 *
 * \return true channel is enabled, false otherwise
 */
bool _dac_async_is_channel_enable(struct _dac_async_device *const device, const uint8_t ch);

/**
 * \brief Write DAC data for output.
 *
 * \param[in] device The pointer to DAC device instance
 * \param[in] data Digital data which to be converted
 * \param[in] ch The channel selected to output
 */
void _dac_async_write_data(struct _dac_async_device *const device, const uint16_t data, const uint8_t ch);

/**
 * \brief Enable/disable DAC interrupt
 *
 * param[in] device The pointer to DAC device instance
 * param[in] type The type of interrupt to disable/enable if applicable
 * param[in] state Enable or disable
 */
void _dac_async_set_irq_state(struct _dac_async_device *const device, const enum _dac_callback_type type,
                              const bool state);

#ifdef __cplusplus
}
#endif

/**@}*/

/**
 * \page hpl__dac__doc DAC HPL Interface Driver
 *
 * \section hpl__dac__desc DAC HPL Description
 *
 * The following device can use this HPL driver
 * - Atmel | SMART SAM D21
 *
 * \section hpl__dac__imple DAC HPL Implements
 * - \subpage hpl__dac__hw_module1__doc
 */

#endif /* _HPL_DAC_H_INCLUDED */
