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

#ifndef HAL_SLCD_SYNC_H_INCLUDED
#define HAL_SLCD_SYNC_H_INCLUDED

#include <hpl_slcd_sync.h>
#include <utils_assert.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \addtogroup doc_driver_hal_slcd_sync
 *
 *@{
 */

struct slcd_sync_descriptor {
	struct _slcd_sync_device dev; /*!< SLCD HPL device descriptor */
};

/**
 * \brief               Initialize SLCD Descriptor
 *
 * \param[in] descr     SLCD descriptor to be initialized
 * \param[in] hw        The pointer to hardware instance
 */
int32_t slcd_sync_init(struct slcd_sync_descriptor *const descr, void *const hw);

/**
 * \brief               Deinitialize SLCD Descriptor
 *
 * \param[in] descr      SLCD descriptor to be deinitialized
 */
int32_t slcd_sync_deinit(struct slcd_sync_descriptor *const descr);

/**
 * \brief               Enable SLCD driver
 *
 * \param[in] descr     SLCD descriptor to be initialized
 */
int32_t slcd_sync_enable(struct slcd_sync_descriptor *const descr);

/**
 * \brief               Disable SLCD driver
 *
 * \param[in] descr     SLCD descriptor to be disabled
 */
int32_t slcd_sync_disable(struct slcd_sync_descriptor *const descr);

/**
 * \brief               Turn on a Segment
 *
 * \param[in] descr     SLCD descriptor to be enabled
 * \param[in] seg       Segment index. The segment index is by the combination
 *                      of common and segment terminal index. The
 *                      SLCD_SEGID(com, seg) macro can generate the index.
 */
int32_t slcd_sync_seg_on(struct slcd_sync_descriptor *const descr, uint32_t seg);

/**
 * \brief               Turn off a Segment
 *
 * \param[in] descr     SLCD descriptor
 * \param[in] seg       Segment index
 *                      value is "(common terminals << 16 | segment terminal)"
 */
int32_t slcd_sync_seg_off(struct slcd_sync_descriptor *const descr, uint32_t seg);

/**
 * \brief               Blink a Segment
 *
 * \param[in] descr     SLCD descriptor
 * \param[in] seg       Segment index
 *                      value is "(common terminals << 16 | segment terminal)"
 * \param[in] period    Blink period, unit is millisecond
 */
int32_t slcd_sync_seg_blink(struct slcd_sync_descriptor *const descr, uint32_t seg, const uint32_t period);

/**
 * \brief               Displays a character
 *
 * \param[in] descr     SLCD descriptor
 * \param[in] character Character to be displayed
 * \param[in] index     Index of the character Mapping Group
 */
int32_t slcd_sync_write_char(struct slcd_sync_descriptor *const descr, const uint8_t character, uint32_t index);

/**
 * \brief               Displays character string string
 *
 * \param[in] descr     SLCD descriptor
 * \param[in] str       String to be displayed, 0 will turn off the
 *                      corresponding char to display
 * \param[in] len       Length of the string array
 * \param[in] index     Index of the character Mapping Group
 */
int32_t slcd_sync_write_string(struct slcd_sync_descriptor *const descr, uint8_t *const str, uint32_t len,
                               uint32_t index);

/**
 * \brief               Start animation play by a segment array
 *
 * \param[in] descr     SLCD descriptor
 * \param[in] segs      Segment array
 * \param[in] len       Length of the segment array
 * \param[in] period    Period (milliseconds) of each segment to animation
 */
int32_t slcd_sync_start_animation(struct slcd_sync_descriptor *const descr, const uint32_t segs[], uint32_t len,
                                  const uint32_t period);

/**
 * \brief               Stop animation play by a segment array
 *
 * \param[in] descr     SLCD descriptor
 * \param[in] segs      Segment array
 * \param[in] len       Length of the segment array
 */
int32_t slcd_sync_stop_animation(struct slcd_sync_descriptor *const descr, const uint32_t segs[], uint32_t len);

/**
 * \brief               Set animation Frequency
 *
 * \param[in] descr     SLCD descriptor
 * \param[in] period    Period (million second) of each segment to animation
 */
int32_t slcd_sync_set_animation_period(struct slcd_sync_descriptor *const descr, const uint32_t period);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
