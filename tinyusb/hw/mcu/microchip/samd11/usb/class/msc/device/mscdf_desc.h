/**
 * \file
 *
 * \brief USB Device Stack MSC Function Descriptor Setting.
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

#ifndef USBDF_MSC_DESC_H_
#define USBDF_MSC_DESC_H_

#include "usb_protocol.h"
#include "usb_protocol_msc.h"
#include "usbd_config.h"

#define MSC_DEV_DESC                                                                                                   \
	USB_DEV_DESC_BYTES(CONF_USB_MSC_BCDUSB,                                                                            \
	                   0x00,                                                                                           \
	                   0x00,                                                                                           \
	                   0x00,                                                                                           \
	                   CONF_USB_MSC_BMAXPKSZ0,                                                                         \
	                   CONF_USB_MSC_IDVENDER,                                                                          \
	                   CONF_USB_MSC_IDPRODUCT,                                                                         \
	                   CONF_USB_MSC_BCDDEVICE,                                                                         \
	                   CONF_USB_MSC_IMANUFACT,                                                                         \
	                   CONF_USB_MSC_IPRODUCT,                                                                          \
	                   CONF_USB_MSC_ISERIALNUM,                                                                        \
	                   0x01)

#define MSC_DEV_QUAL_DESC USB_DEV_QUAL_DESC_BYTES(CONF_USB_MSC_BCDUSB, 0x00, 0x00, 0x00, CONF_USB_MSC_BMAXPKSZ0, 0x01)

#define MSC_CFG_DESC                                                                                                   \
	USB_CONFIG_DESC_BYTES(32, 1, 0x01, CONF_USB_MSC_ICONFIG, CONF_USB_MSC_BMATTRI, CONF_USB_MSC_BMAXPOWER)

#define MSC_OTH_SPD_CFG_DESC                                                                                           \
	USB_OTH_SPD_CFG_DESC_BYTES(32, 1, 0x01, CONF_USB_MSC_ICONFIG, CONF_USB_MSC_BMATTRI, CONF_USB_MSC_BMAXPOWER)

#define MSC_IFACE_DESCES                                                                                               \
	USB_IFACE_DESC_BYTES(CONF_USB_MSC_BIFCNUM, 0x00, 2, 0x08, 0x06, 0x50, CONF_USB_MSC_IIFC),                          \
	    USB_ENDP_DESC_BYTES(CONF_USB_MSC_BULKOUT_EPADDR, 2, CONF_USB_MSC_BULKOUT_MAXPKSZ, 0),                          \
	    USB_ENDP_DESC_BYTES(CONF_USB_MSC_BULKIN_EPADDR, 2, CONF_USB_MSC_BULKIN_MAXPKSZ, 0)

#define MSC_IFACE_DESCES_HS                                                                                            \
	USB_IFACE_DESC_BYTES(CONF_USB_MSC_BIFCNUM, 0x00, 2, 0x08, 0x06, 0x50, CONF_USB_MSC_IIFC),                          \
	    USB_ENDP_DESC_BYTES(CONF_USB_MSC_BULKOUT_EPADDR, 2, CONF_USB_MSC_BULKOUT_MAXPKSZ_HS, 0),                       \
	    USB_ENDP_DESC_BYTES(CONF_USB_MSC_BULKIN_EPADDR, 2, CONF_USB_MSC_BULKIN_MAXPKSZ_HS, 0)

#define MSC_STR_DESCES                                                                                                 \
	CONF_USB_MSC_LANGID_DESC                                                                                           \
	CONF_USB_MSC_IMANUFACT_STR_DESC                                                                                    \
	CONF_USB_MSC_IPRODUCT_STR_DESC                                                                                     \
	CONF_USB_MSC_ISERIALNUM_STR_DESC                                                                                   \
	CONF_USB_MSC_ICONFIG_STR_DESC

/** USB Device descriptors and configuration descriptors */
#define MSC_DESCES_LS_FS MSC_DEV_DESC, MSC_CFG_DESC, MSC_IFACE_DESCES, MSC_STR_DESCES

#define MSC_HS_DESCES_LS_FS                                                                                            \
	MSC_DEV_DESC, MSC_DEV_QUAL_DESC, MSC_CFG_DESC, MSC_IFACE_DESCES, MSC_OTH_SPD_CFG_DESC, MSC_IFACE_DESCES_HS,        \
	    MSC_STR_DESCES

#define MSC_HS_DESCES_HS MSC_CFG_DESC, MSC_IFACE_DESCES_HS, MSC_OTH_SPD_CFG_DESC, MSC_IFACE_DESCES

#endif /* USBDF_MSC_DESC_H_ */
