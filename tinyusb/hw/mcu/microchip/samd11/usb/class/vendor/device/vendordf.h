/**
 * \file
 *
 * \brief USB Device Stack Vendor Function Definition.
 *
 * Copyright (c) 2016-2018 Microchip Technology Inc. and its subsidiaries.
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

#ifndef USBDF_VENDOR_H_
#define USBDF_VENDOR_H_

#include "usbdc.h"
#include "usb_protocol_vendor.h"

/** Vendor Callback Type */
enum vendordf_cb_type {
	/* Ctrl Endpoint Type Transfer */
	VENDORDF_CB_CTRL_READ_REQ,
	VENDORDF_CB_CTRL_WRITE_REQ,
	/* Isochronous Endpoint Type Transfer */
	VENDORDF_CB_ISO_READ,
	VENDORDF_CB_ISO_WRITE,
	/* Bulk Endpoint Type Transfer */
	VENDORDF_CB_BULK_READ,
	VENDORDF_CB_BULK_WRITE,
	/* Interrupt Endpoint Type Transfer */
	VENDORDF_CB_INT_READ,
	VENDORDF_CB_INT_WRITE
};

/* USB Device Vendor Ctrl Endpoint Transfer Callback */
typedef void (*vendor_ctrl_cb_t)(uint16_t);

/**
 * \brief Initialize the USB Vendor Function Driver
 * \return Operation status.
 */
int32_t vendordf_init(void);

/**
 * \brief Deinitialize the USB Vendor Function Driver
 * \return Operation status.
 */
int32_t vendordf_deinit(void);

/**
 * \brief Check whether Vendor Function is enabled
 * \return Operation status.
 * \return true Vendor Function is enabled
 * \return false Vendor Function is disabled
 */
bool vendordf_is_enabled(void);

/**
 * \brief USB Vendor Function Read Data
 * \param[in] type Endpoint transfer types
 * \param[in] buf Pointer to the buffer which receives data
 * \param[in] size the size of data to be received
 * \return Operation status.
 */
int32_t vendordf_read(enum usb_ep_type type, uint8_t *buf, uint32_t size);

/**
 * \brief USB Vendor Function Write Data
 * \param[in] type Endpoint transfer types
 * \param[in] buf Pointer to the buffer which stores data
 * \param[in] size the size of data to be sent
 * \return Operation status.
 */
int32_t vendordf_write(enum usb_ep_type type, uint8_t *buf, uint32_t size);

/**
 * \brief USB Vendor Function Register Callback
 * \param[in] cb_type Callback type of Vendor Function
 * \param[in] func Pointer to callback function
 * \return Operation status.
 */
int32_t vendordf_register_callback(enum vendordf_cb_type cb_type, FUNC_PTR func);

/**
 * \brief Return version
 */
uint32_t vendordf_get_version(void);

#endif /* USBDF_VENDOR_H_ */
