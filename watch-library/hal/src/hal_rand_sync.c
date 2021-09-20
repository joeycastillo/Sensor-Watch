/**
 * \file
 *
 * \brief Generic Random Number Generator (RNG) functionality declaration.
 *
 * Copyright (c) 2015-2018 Microchip Technology Inc. and its subsidiaries.
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

#include <utils.h>
#include "hal_rand_sync.h"

#define HAL_RNG_SYNC_VERSION 0x00000001u

int32_t rand_sync_init(struct rand_sync_desc *const desc, void *const hw)
{
	ASSERT(desc);

	return _rand_sync_init(&desc->dev, hw);
}

void rand_sync_deinit(struct rand_sync_desc *const desc)
{
	ASSERT(desc);
	_rand_sync_deinit(&desc->dev);
}

int32_t rand_sync_enable(struct rand_sync_desc *const desc)
{
	ASSERT(desc);
	return _rand_sync_enable(&desc->dev);
}

void rand_sync_disable(struct rand_sync_desc *const desc)
{
	ASSERT(desc);
	_rand_sync_disable(&desc->dev);
}

int32_t rand_sync_set_seed(struct rand_sync_desc *const desc, const uint32_t seed)
{
	ASSERT(desc);
	return _rand_sync_set_seed(&desc->dev, seed);
}

/**
 * \brief Read data bits
 */
static uint32_t _rand_sync_read_data(const struct _rand_sync_dev *dev, const uint8_t n_bits)
{
	uint8_t r_bits = (dev->n_bits < 1) ? 32 : dev->n_bits;
	if (r_bits < n_bits) {
		uint8_t  i;
		uint32_t d = 0;
		/* Join read bits */
		for (i = 0; i < n_bits; i += r_bits) {
			d |= (uint32_t)(_rand_sync_read_one(dev) << i);
		}
		return d;
	} else {
		return _rand_sync_read_one(dev);
	}
}

uint8_t rand_sync_read8(const struct rand_sync_desc *const desc)
{
	ASSERT(desc);
	return (uint8_t)_rand_sync_read_data(&desc->dev, 8);
}

uint32_t rand_sync_read32(const struct rand_sync_desc *const desc)
{
	ASSERT(desc);
	return (uint32_t)_rand_sync_read_data(&desc->dev, 32);
}

void rand_sync_read_buf8(const struct rand_sync_desc *const desc, uint8_t *buf, uint32_t len)
{
	uint32_t i;
	ASSERT(desc && (buf && len));
	for (i = 0; i < len; i++) {
		buf[i] = (uint8_t)_rand_sync_read_data(&desc->dev, 8);
	}
}

void rand_sync_read_buf32(const struct rand_sync_desc *const desc, uint32_t *buf, uint32_t len)
{
	uint32_t i;
	ASSERT(desc && (buf && len));
	for (i = 0; i < len; i++) {
		buf[i] = (uint32_t)_rand_sync_read_data(&desc->dev, 32);
	}
}

uint32_t rand_sync_get_version(void)
{
	return HAL_RNG_SYNC_VERSION;
}
