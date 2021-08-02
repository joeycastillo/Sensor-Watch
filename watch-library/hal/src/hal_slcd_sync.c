/**
 * \file
 *
 * \brief SLCD Segment Liquid Crystal Display Controller(Sync) functionality
 *        declaration.
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

#include <hal_slcd_sync.h>
#include <utils_assert.h>

/**
 * \brief              Initialize SLCD Descriptor
 */
int32_t slcd_sync_init(struct slcd_sync_descriptor *const descr, void *const hw)
{
	ASSERT(descr && hw);
	return _slcd_sync_init(&descr->dev, hw);
}

/**
 * \brief              Deinitialize SLCD Descriptor
 */
int32_t slcd_sync_deinit(struct slcd_sync_descriptor *const descr)
{
	ASSERT(descr);
	return _slcd_sync_deinit(&descr->dev);
}

/**
 * \brief              Enable SLCD driver
 *
 */
int32_t slcd_sync_enable(struct slcd_sync_descriptor *const descr)
{
	ASSERT(descr);
	return _slcd_sync_enable(&descr->dev);
}
/**
 * \brief              Disable SLCD driver
 *
 */
int32_t slcd_sync_disable(struct slcd_sync_descriptor *const descr)
{
	ASSERT(descr);
	return _slcd_sync_disable(&descr->dev);
}
/**
 * \brief              Turn on a Segment
 */
int32_t slcd_sync_seg_on(struct slcd_sync_descriptor *const descr, uint32_t seg)
{
	ASSERT(descr);
	return _slcd_sync_seg_on(&descr->dev, seg);
}
/**
 * \brief              Turn off a Segment
 */
int32_t slcd_sync_seg_off(struct slcd_sync_descriptor *const descr, uint32_t seg)
{
	ASSERT(descr);
	return _slcd_sync_seg_off(&descr->dev, seg);
}
/**
 * \brief              Blink a Segment
 */
int32_t slcd_sync_seg_blink(struct slcd_sync_descriptor *const descr, uint32_t seg, const uint32_t period)
{
	ASSERT(descr && period);
	return _slcd_sync_seg_blink(&descr->dev, seg, period);
}

/**
 * \brief              Displays a character
 */
int32_t slcd_sync_write_char(struct slcd_sync_descriptor *const descr, const uint8_t character, uint32_t index)
{
	ASSERT(descr);
	return _slcd_sync_write_char(&descr->dev, character, index);
}

/**
 * \brief              Displays character string string
 */
int32_t slcd_sync_write_string(struct slcd_sync_descriptor *const descr, uint8_t *const str, uint32_t len,
                               uint32_t index)
{
	uint32_t i;
	ASSERT(descr && len);

	for (i = 0; i < len; i++) {
		if (_slcd_sync_write_char(&descr->dev, *(str + i), index + i) != ERR_NONE) {
			return ERR_INVALID_ARG;
		}
	}
	return ERR_NONE;
}
/**
 * \brief               Start animation play by a segment array
 */
int32_t slcd_sync_start_animation(struct slcd_sync_descriptor *const descr, const uint32_t segs[], uint32_t len,
                                  const uint32_t period)
{
	ASSERT(descr && segs && len && period);
	return _slcd_sync_start_animation(&descr->dev, segs, len, period);
}

/**
 * \brief               Stop animation play by a segment array
 */
int32_t slcd_sync_stop_animation(struct slcd_sync_descriptor *const descr, const uint32_t segs[], uint32_t len)
{
	ASSERT(descr && segs && len);
	return _slcd_sync_stop_animation(&descr->dev, segs, len);
}

/**
 * \brief               Set animation Frequency
 */
int32_t slcd_sync_set_animation_period(struct slcd_sync_descriptor *const descr, const uint32_t period)
{
	ASSERT(descr && period);
	return _slcd_sync_set_animation_period(&descr->dev, period);
}
