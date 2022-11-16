/**
 * \file
 *
 * \brief DAC functionality implementation.
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

#include "hal_dac_sync.h"
#include <utils_assert.h>

/**
 * \brief Driver version
 */
#define DRIVER_VERSION 0x00000001u

/**
 * \brief Initialize the DAC HAL instance and hardware.
 */
int32_t dac_sync_init(struct dac_sync_descriptor *const descr, void *const hw)
{
	uint8_t i;
	int32_t rc;

	ASSERT(descr && hw);

	rc = _dac_sync_init(&descr->device, hw);
	if (rc) {
		return rc;
	}

	for (i = 0; i < CHANNEL_NUM; i++) {
		descr->sel_ch[i].buffer = NULL;
		descr->sel_ch[i].length = 0;
	}

	return ERR_NONE;
}

/**
 * \brief Deinitialize the DAC HAL instance and hardware
 */
int32_t dac_sync_deinit(struct dac_sync_descriptor *const descr)
{
	ASSERT(descr);

	_dac_sync_deinit(&descr->device);

	return ERR_NONE;
}

/**
 * \brief Enable DAC channel
 */
int32_t dac_sync_enable_channel(struct dac_sync_descriptor *const descr, const uint8_t ch)
{
	ASSERT(descr && (ch < CHANNEL_NUM));

	_dac_sync_enable_channel(&descr->device, ch);

	return ERR_NONE;
}

/**
 * \brief Disable DAC channel
 */
int32_t dac_sync_disable_channel(struct dac_sync_descriptor *const descr, const uint8_t ch)
{
	ASSERT(descr && (ch < CHANNEL_NUM));

	_dac_sync_disable_channel(&descr->device, ch);

	return ERR_NONE;
}

/**
 * \brief DAC convert digital data to analog output
 */
int32_t dac_sync_write(struct dac_sync_descriptor *descr, const uint8_t ch, uint16_t *buffer, uint32_t length)
{
	ASSERT(descr && (ch < CHANNEL_NUM) && buffer && length);

	/* check whether channel is enable */
	if (!_dac_sync_is_channel_enable(&descr->device, ch)) {
		return ERR_NOT_READY;
	}

	descr->sel_ch[ch].buffer = buffer;
	descr->sel_ch[ch].length = length;

	while (descr->sel_ch[ch].length) {
		_dac_sync_write_data(&descr->device, *(descr->sel_ch[ch].buffer), ch);
		descr->sel_ch[ch].buffer++;
		descr->sel_ch[ch].length--;
	}

	return ERR_NONE;
}

/**
 * \brief Get DAC driver version
 */
uint32_t dac_sync_get_version(void)
{
	return DRIVER_VERSION;
}
