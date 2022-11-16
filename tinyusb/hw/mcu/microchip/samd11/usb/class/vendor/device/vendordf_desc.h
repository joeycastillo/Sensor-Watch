/**
 * \file
 *
 * \brief USB Device Stack Vendor Function Descriptor Setting.
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

#ifndef USBDF_VENDOR_DESC_H_
#define USBDF_VENDOR_DESC_H_

#include "usb_protocol.h"
#include "usb_protocol_vendor.h"
#include "usbd_config.h"

#define VENDOR_DEV_DESC                                                                                                \
	USB_DEV_DESC_BYTES(CONF_USB_VENDOR_BCDUSB,                                                                         \
	                   0x00,                                                                                           \
	                   0x00,                                                                                           \
	                   0x00,                                                                                           \
	                   CONF_USB_VENDOR_BMAXPKSZ0,                                                                      \
	                   CONF_USB_VENDOR_IDVENDER,                                                                       \
	                   CONF_USB_VENDOR_IDPRODUCT,                                                                      \
	                   CONF_USB_VENDOR_BCDDEVICE,                                                                      \
	                   CONF_USB_VENDOR_IMANUFACT,                                                                      \
	                   CONF_USB_VENDOR_IPRODUCT,                                                                       \
	                   CONF_USB_VENDOR_ISERIALNUM,                                                                     \
	                   0x01)

#define VENDOR_CFG_DESC                                                                                                \
	USB_CONFIG_DESC_BYTES(69, 1, 0x01, CONF_USB_VENDOR_ICONFIG, CONF_USB_VENDOR_BMATTRI, CONF_USB_VENDOR_BMAXPOWER)

#define VENDOR_IFC_DESC                                                                                                \
	USB_IFACE_DESC_BYTES(CONF_USB_VENDOR_BIFCNUM, 0x00, 0x00, 0xFF, 0xFF, 0xFF, CONF_USB_VENDOR_IIFC),                 \
	    USB_IFACE_DESC_BYTES(CONF_USB_VENDOR_BIFCNUM, 0x01, 0x06, 0xFF, 0xFF, 0xFF, CONF_USB_VENDOR_IIFC),             \
	    USB_ENDP_DESC_BYTES(CONF_USB_VENDOR_INTIN_EPADDR, 0x03, CONF_USB_VENDOR_INTIN_MAXPKSZ, 1),                     \
	    USB_ENDP_DESC_BYTES(CONF_USB_VENDOR_INTOUT_EPADDR, 0x03, CONF_USB_VENDOR_INTOUT_MAXPKSZ, 1),                   \
	    USB_ENDP_DESC_BYTES(CONF_USB_VENDOR_BULKIN_EPADDR, 0x02, CONF_USB_VENDOR_BULKIN_MAXPKSZ, 0),                   \
	    USB_ENDP_DESC_BYTES(CONF_USB_VENDOR_BULKOUT_EPADDR, 0x02, CONF_USB_VENDOR_BULKOUT_MAXPKSZ, 0),                 \
	    USB_ENDP_DESC_BYTES(CONF_USB_VENDOR_ISOIN_EPADDR, 0x01, CONF_USB_VENDOR_ISOIN_MAXPKSZ, 1),                     \
	    USB_ENDP_DESC_BYTES(CONF_USB_VENDOR_ISOOUT_EPADDR, 0x01, CONF_USB_VENDOR_ISOOUT_MAXPKSZ, 1)

#define VENDOR_STR_DESCES                                                                                              \
	CONF_USB_VENDOR_LANGID_DESC                                                                                        \
	CONF_USB_VENDOR_IMANUFACT_STR_DESC                                                                                 \
	CONF_USB_VENDOR_IPRODUCT_STR_DESC                                                                                  \
	CONF_USB_VENDOR_ISERIALNUM_STR_DESC                                                                                \
	CONF_USB_VENDOR_ICONFIG_STR_DESC

/** USB Device descriptors and configuration descriptors */
#define VENDOR_DESCES_LS_FS VENDOR_DEV_DESC, VENDOR_CFG_DESC, VENDOR_IFC_DESC, VENDOR_STR_DESCES

#endif /* USBDF_VENDOR_DESC_H_ */
