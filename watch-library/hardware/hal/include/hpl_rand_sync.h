/**
 * \file
 *
 * \brief Random Number Generator (RAND) related functionality declaration.
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

#ifndef _HPL_RAND_SYNC_H_INCLUDED
#define _HPL_RAND_SYNC_H_INCLUDED

#include <compiler.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Random Number Generator polling device. */
struct _rand_sync_dev {
	/** Pointer to private data or hardware base */
	void *prvt;
	/** Number of bits generated for each read operation */
	uint8_t n_bits;
};

/**
 *  \brief Initialize the Random Number Generator Driver
 *  \param[out] dev Pointer to the device instance struct
 *  \param[in, out] hw Pointer to the hardware for device instance
 *  \return Initialization operation result status, 0 for OK.
 */
int32_t _rand_sync_init(struct _rand_sync_dev *const dev, void *const hw);

/**
 *  \brief Deinitialize the Random Number Generator Driver
 *  \param[in, out] dev Pointer to the device instance struct
 */
void _rand_sync_deinit(struct _rand_sync_dev *const dev);

/**
 *  \brief Enable the Random Number Generator Driver
 *  \param[out] dev Pointer to the device instance struct
 *  \return Enable operation result status, 0 for OK.
 */
int32_t _rand_sync_enable(struct _rand_sync_dev *const dev);

/**
 *  \brief Disable the Random Number Generator Driver
 *  \param[out] dev Pointer to the device instance struct
 */
void _rand_sync_disable(struct _rand_sync_dev *const dev);

/**
 *  \brief Set seed for the Random Number Generator Driver
 *  \param[out] dev Pointer to the device instance struct
 *  \param[in] seed The seed to set
 *  \return Operation result
 *  \retval ERR_NONE Operation complete success
 *  \retval ERR_UNSUPPORTED_OP Seed not supported
 */
int32_t _rand_sync_set_seed(struct _rand_sync_dev *const dev, const uint32_t seed);

/**
 *  \brief Polling random number until it's read back
 *  \param[in] dev Pointer to the device instance struct
 *  \return The random number value
 */
uint32_t _rand_sync_read_one(const struct _rand_sync_dev *const dev);

#ifdef __cplusplus
}
#endif
/**@}*/
#endif /* _HPL_RAND_SYNC_H_INCLUDED */
