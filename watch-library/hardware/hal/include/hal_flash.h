/**
 * \file
 *
 * \brief Flash related functionality declaration.
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

#ifndef _HAL_FLASH_H_INCLUDED
#define _HAL_FLASH_H_INCLUDED

#include <hpl_flash.h>

/**
 * \addtogroup doc_driver_hal_flash
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declaration of flash_descriptor. */
struct flash_descriptor;

/** The callback types */
enum flash_cb_type {
	/** Callback type for ready to accept a new command */
	FLASH_CB_READY,
	/** Callback type for error */
	FLASH_CB_ERROR,
	FLASH_CB_N
};

/** \brief Prototype of callback on FLASH
 *
 */
typedef void (*flash_cb_t)(struct flash_descriptor *const descr);

/** \brief FLASH HAL callbacks
 *
 */
struct flash_callbacks {
	/** Callback invoked when ready to accept a new command */
	flash_cb_t cb_ready;
	/** Callback invoked when error occurs */
	flash_cb_t cb_error;
};

/** \brief FLASH HAL driver struct for asynchronous access
 */
struct flash_descriptor {
	/** Pointer to FLASH device instance */
	struct _flash_device dev;
	/** Callbacks for asynchronous transfer */
	struct flash_callbacks callbacks;
};

/** \brief Initialize the FLASH HAL instance and hardware for callback mode
 *
 *  Initialize FLASH HAL with interrupt mode (uses callbacks).
 *
 *  \param[in, out] flash Pointer to the HAL FLASH instance.
 *  \param[in] hw Pointer to the hardware base.
 *  \return Initialize status.
 */
int32_t flash_init(struct flash_descriptor *flash, void *const hw);

/** \brief Deinitialize the FLASH HAL instance
 *
 *  Abort transfer, disable and reset FLASH, and deinitialize software.
 *
 *  \param[in, out] flash Pointer to the HAL FLASH instance.
 *  \return Deinitialze status.
 */
int32_t flash_deinit(struct flash_descriptor *flash);

/** \brief Writes a number of bytes to a page in the internal Flash
 *
 *  \param[in, out] flash Pointer to the HAL FLASH instance.
 *  \param[in]  dst_addr  Destination bytes address to write into flash
 *  \param[in]  buffer    Pointer to a buffer where the content
 *                        will be written to the flash
 *  \param[in]  length    Number of bytes to write
 *  \return Write status.
 */
int32_t flash_write(struct flash_descriptor *flash, uint32_t dst_addr, uint8_t *buffer, uint32_t length);

/** \brief Appends a number of bytes to a page in the internal Flash
 *
 *  This functions never erases the flash before writing.
 *
 *  \param[in, out] flash Pointer to the HAL FLASH instance.
 *  \param[in]  dst_addr  Destination bytes address to write to flash
 *  \param[in]  buffer    Pointer to a buffer with data to write to flash
 *  \param[in]  length    Number of bytes to append
 *  \return Append status.
 */
int32_t flash_append(struct flash_descriptor *flash, uint32_t dst_addr, uint8_t *buffer, uint32_t length);

/** \brief Reads a number of bytes to a page in the internal Flash
 *
 *  \param[in, out] flash Pointer to the HAL FLASH instance.
 *  \param[in]  src_addr  Source bytes address to read from flash
 *  \param[out] buffer    Pointer to a buffer where the content
 *                        of the read pages will be stored
 *  \param[in]  length    Number of bytes to read
 *  \return Read status.
 */
int32_t flash_read(struct flash_descriptor *flash, uint32_t src_addr, uint8_t *buffer, uint32_t length);

/** \brief Register a function as FLASH transfer completion callback
 *
 *  \param[in, out] flash Pointer to the HAL FLASH instance.
 *  \param[in] type Callback type (\ref flash_cb_type).
 *  \param[in] func Pointer to callback function.
 *  \retval 0 Success
 *  \retval -1 Error
 */
int32_t flash_register_callback(struct flash_descriptor *flash, const enum flash_cb_type type, flash_cb_t func);

/** \brief Execute lock in the internal flash
 *
 *  \param[in, out] flash Pointer to the HAL FLASH instance.
 *  \param[in]  dst_addr  Destination bytes address aligned with page
 *                        start to be locked
 *  \param[in]  page_nums Number of pages to be locked
 *
 *  \return Real locked numbers of pages.
 */
int32_t flash_lock(struct flash_descriptor *flash, const uint32_t dst_addr, const uint32_t page_nums);

/** \brief Execute unlock in the internal flash
 *
 *  \param[in, out] flash Pointer to the HAL FLASH instance.
 *  \param[in]  dst_addr  Destination bytes address aligned with page
 *                        start to be unlocked
 *  \param[in]  page_nums Number of pages to be unlocked
 *
 *  \return Real unlocked numbers of pages.
 */
int32_t flash_unlock(struct flash_descriptor *flash, const uint32_t dst_addr, const uint32_t page_nums);

/** \brief Execute erase in the internal flash
 *
 *  \param[in, out] flash Pointer to the HAL FLASH instance.
 *  \param[in]  dst_addr  Destination bytes address aligned with page
 *                        start to be erased
 *  \param[in]  page_nums Number of pages to be erased
 *  \retval 0 Success
 *  \retval -1 Error
 */
int32_t flash_erase(struct flash_descriptor *flash, const uint32_t dst_addr, const uint32_t page_nums);

/**
 * \brief Get the flash page size
 *
 * \param[in, out] flash Pointer to the HAL FLASH instance
 *
 * \return The flash page size
 */
uint32_t flash_get_page_size(struct flash_descriptor *flash);

/**
 * \brief Get the number of flash page
 *
 * \param[in, out] flash Pointer to the HAL FLASH instance.
 *
 * \return The flash total page numbers
 */
uint32_t flash_get_total_pages(struct flash_descriptor *flash);

/** \brief Retrieve the current driver version
 *
 *  \return Current driver version.
 */
uint32_t flash_get_version(void);

#ifdef __cplusplus
}
#endif
/**@}*/
#endif /* ifndef _HAL_FLASH_H_INCLUDED */
