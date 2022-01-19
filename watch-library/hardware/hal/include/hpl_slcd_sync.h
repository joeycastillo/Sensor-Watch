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

#ifndef HPL_SLCD_SYNC_H_INCLUDED
#define HPL_SLCD_SYNC_H_INCLUDED

#include <hpl_slcd.h>
#include <utils_assert.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief SLCD sync device structure
 *
 * The SLCD device structure forward declaration.
 */
struct _slcd_sync_device;

struct _slcd_sync_device {
	void *hw; /*!< Hardware module instance handler */
};

/**
 * \brief              Initialize SLCD Device Descriptor
 *
 * \param[in] desc     SLCD descriptor to be initialized
 * \param[in] hw       The pointer to hardware instance
 */
int32_t _slcd_sync_init(struct _slcd_sync_device *const dev, void *const hw);

/**
 * \brief              Deinitialize SLCD Device Descriptor
 *
 * \param[in] desc     SLCD device descriptor to be deinitialized
 */
int32_t _slcd_sync_deinit(struct _slcd_sync_device *const dev);

/**
 * \brief              Enable SLCD driver
 *
 * \param[in] dev      SLCD device descriptor to be enabled
 */
int32_t _slcd_sync_enable(struct _slcd_sync_device *const dev);

/**
 * \brief              Disable SLCD driver
 *
 * \param[in] dev      SLCD Device descriptor to be disabled
 */
int32_t _slcd_sync_disable(struct _slcd_sync_device *const dev);

/**
 * \brief               Turn on a Segment
 *
 * \param[in] dev       SLCD Device descriptor
 * \param[in] seg       Segment id
 *                      value is (common terminals << 16 | segment terminal)
 */
int32_t _slcd_sync_seg_on(struct _slcd_sync_device *const dev, uint32_t seg);

/**
 * \brief               Turn off a Segment
 *
 * \param[in] dev       SLCD Device descriptor
 * \param[in] seg       Segment id
 *                      value is (common terminals << 16 | segment terminal)
 */
int32_t _slcd_sync_seg_off(struct _slcd_sync_device *const dev, uint32_t seg);

/**
 * \brief               Blink a Segment
 *
 * \param[in] dev       SLCD Device descriptor
 * \param[in] seg       Segment index
 *                      value is (common terminals << 16 | segment terminal)
 * \param[in] period  Blink period, unit is million second
 */
int32_t _slcd_sync_seg_blink(struct _slcd_sync_device *const dev, uint32_t seg, const uint32_t period);

/**
 * \brief              Displays a character
 *
 * \param[in] dev       SLCD Device descriptor
 * \param[in] character Character to be displayed
 * \param[in] index     Index of Character Mapping Group
 */
int32_t _slcd_sync_write_char(struct _slcd_sync_device *const dev, const uint8_t character, uint32_t index);

/**
 * \brief               Start animation play by a segment array
 *
 * \param[in] dev       SLCD Device descriptor
 * \param[in] segs      Segment array
 * \param[in] len       Length of the segment array
 * \param[in] period    Period(milliseconds) of the each segment to animation
 */
int32_t _slcd_sync_start_animation(struct _slcd_sync_device *const dev, const uint32_t segs[], uint32_t len,
                                   const uint32_t period);

/**
 * \brief               Stop animation play by a segment array
 *
 * \param[in] dev       SLCD device descriptor
 * \param[in] segs      Segment array
 * \param[in] len       Length of the segment array
 */
int32_t _slcd_sync_stop_animation(struct _slcd_sync_device *const dev, const uint32_t segs[], uint32_t len);

/**
 * \brief               Set animation Frequency
 *
 * \param[in] dev       SLCD Device descriptor
 * \param[in] period    Period(million second) of the each segment to animation
 */
int32_t _slcd_sync_set_animation_period(struct _slcd_sync_device *const dev, const uint32_t period);

#ifdef __cplusplus
}
#endif

#endif
