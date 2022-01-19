/**
 * \file
 *
 * \brief Generic Random Number Generator (RAND) functionality declaration.
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

#ifndef _HAL_RAND_SYNC_H_INCLUDED
#define _HAL_RAND_SYNC_H_INCLUDED

#include <hpl_rand_sync.h>

#include <utils_assert.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \addtogroup doc_driver_hal_rand_sync
 *
 *@{
 */

/** Random Number Generator polling device. */
struct rand_sync_desc {
	struct _rand_sync_dev dev;
};

/**
 *  \brief Initialize the Random Number Generator Driver
 *  \param[out] desc Pointer to the device descriptor instance struct
 *  \param[in, out] hw Pointer to the hardware for device instance
 *  \return Initialization operation result status, ERR_NONE (0) for OK.
 */
int32_t rand_sync_init(struct rand_sync_desc *const desc, void *const hw);

/**
 *  \brief Deinitialize the Random Number Generator Driver
 *  \param[out] desc Pointer to the device descriptor instance struct
 */
void rand_sync_deinit(struct rand_sync_desc *const desc);

/**
 *  \brief Enable the Random Number Generator Driver
 *  \param[out] desc Pointer to the device descriptor instance struct
 *  \return Enable operation result status, ERR_NONE (0) for OK.
 */
int32_t rand_sync_enable(struct rand_sync_desc *const desc);

/**
 *  \brief Disable the Random Number Generator Driver
 *  \param[out] desc Pointer to the device descriptor instance struct
 */
void rand_sync_disable(struct rand_sync_desc *const desc);

/**
 *  \brief Set seed for the Random Number Generator Driver
 *  \param[out] desc Pointer to the device descriptor instance struct
 */
int32_t rand_sync_set_seed(struct rand_sync_desc *const desc, const uint32_t seed);

/**
 *  \brief Read the 8-bit Random Number
 *  \param[in] desc Pointer to the device descriptor instance struct
 *  \return The random number generated
 */
uint8_t rand_sync_read8(const struct rand_sync_desc *const desc);

/**
 *  \brief Read the 32-bit Random Number
 *  \param[in] desc Pointer to the device descriptor instance struct
 *  \return The random number generated
 */
uint32_t rand_sync_read32(const struct rand_sync_desc *const desc);

/**
 *  \brief Read the 8-bit Random Number Sequence into a buffer
 *  \param[in] desc Pointer to the device descriptor instance struct
 *  \param[out] buf Pointer to the buffer to fill an array of generated numbers
 *  \param[in] len Number of random numbers to read
 */
void rand_sync_read_buf8(const struct rand_sync_desc *const desc, uint8_t *buf, uint32_t len);

/**
 *  \brief Read the 32-bit Random Number Sequence into a buffer
 *  \param[in] desc Pointer to the device descriptor instance struct
 *  \param[out] buf Pointer to the buffer to fill an array of generated numbers
 *  \param[in] len Number of random numbers to read
 */
void rand_sync_read_buf32(const struct rand_sync_desc *const desc, uint32_t *buf, uint32_t len);

/**
 * \brief Retrieve the current driver version
 *
 * \return Current driver version.
 */
uint32_t rand_sync_get_version(void);

/* I/O read will be used to get random data. */

/**@}*/

#ifdef __cplusplus
}
#endif

#endif /* _HAL_RAND_SYNC_H_INCLUDED */
