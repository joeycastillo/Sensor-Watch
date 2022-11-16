/**
 * \file
 *
 * \brief USB Device Stack HID Generic Function Definition.
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
 */

#ifndef USBDF_HID_GENERIC_H_
#define USBDF_HID_GENERIC_H_

#include "usbdc.h"
#include "usb_protocol_hid.h"

/** HID Generic Callback Type */
enum hiddf_generic_cb_type { HIDDF_GENERIC_CB_READ, HIDDF_GENERIC_CB_WRITE, HIDDF_GENERIC_CB_SET_REPORT };

/** HID Generic Set Report Callback. */
typedef bool (*hiddf_generic_set_report_t)(uint8_t *, uint16_t);

/**
 * \brief Initialize the USB HID Generic Function Driver
 * \param[in] report_desc Point to usr HID Report Descriptor
 * \param[in] len length of usr HID Report Descriptor
 * \return Operation status.
 */
int32_t hiddf_generic_init(const uint8_t *report_desc, uint32_t len);

/**
 * \brief Deinitialize the USB HID Generic Function Driver
 * \return Operation status.
 */
int32_t hiddf_generic_deinit(void);

/**
 * \brief Check whether HID Generic Function is enabled
 * \return Operation status.
 * \return true HID Generic Function is enabled
 * \return false HID Generic Function is disabled
 */
bool hiddf_generic_is_enabled(void);

/**
 * \brief USB HID Generic Function Read Data
 * \param[in] buf Pointer to the buffer which receives data
 * \param[in] size the size of data to be received
 * \return Operation status.
 */
int32_t hiddf_generic_read(uint8_t *buf, uint32_t size);

/**
 * \brief USB HID Generic Function Write Data
 * \param[in] buf Pointer to the buffer which stores data
 * \param[in] size the size of data to be sent
 * \return Operation status.
 */
int32_t hiddf_generic_write(uint8_t *buf, uint32_t size);

/**
 * \brief USB HID Generic Function Register Callback
 * \param[in] cb_type Callback type of HID Generic Function
 * \param[in] func Pointer to callback function
 * \return Operation status.
 */
int32_t hiddf_generic_register_callback(enum hiddf_generic_cb_type cb_type, FUNC_PTR func);

/**
 * \brief Return version
 */
uint32_t hiddf_generic_get_version(void);

#endif /* USBDF_HID_GENERIC_H_ */
