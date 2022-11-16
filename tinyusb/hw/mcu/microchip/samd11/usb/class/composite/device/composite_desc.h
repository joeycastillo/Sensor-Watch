/**
 * \file
 *
 * \brief USB Device Stack Composite Class Descriptor Setting.
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

#ifndef USBDF_COMPOSITE_DESC_H_
#define USBDF_COMPOSITE_DESC_H_

#include "usb_protocol.h"
#include "usbd_config.h"

#if CONF_USB_COMPOSITE_CDC_ACM_EN == 1
#define CONF_CDC_ACM_IFC_LEN 66
#define CONF_CDC_ACM_IFC_NUM 2
#define CONF_USB_COMPOSITE_CDC_ACM_COMM_BIFCNUM 0
#define CONF_USB_COMPOSITE_CDC_ACM_DATA_BIFCNUM 1
#define CONF_CDC_ACM_IFC_DESC                                                                                          \
	USB_IAD_DESC_BYTES(                                                                                                \
	    CONF_USB_COMPOSITE_CDC_ACM_COMM_BIFCNUM, 0x02, CDC_CLASS_DEVICE, CDC_SUBCLASS_ACM, CDC_PROTOCOL_V25TER, 0x00), \
	    USB_IFACE_DESC_BYTES(CONF_USB_COMPOSITE_CDC_ACM_COMM_BIFCNUM,                                                  \
	                         0x00,                                                                                     \
	                         0x01,                                                                                     \
	                         CDC_CLASS_DEVICE,                                                                         \
	                         CDC_SUBCLASS_ACM,                                                                         \
	                         CDC_PROTOCOL_V25TER,                                                                      \
	                         0x00),                                                                                    \
	    USB_CDC_HDR_DESC_BYTES(0x1001), USB_CDC_CALL_MGMT_DESC_BYTES(0x01, 0x00), USB_CDC_ACM_DESC_BYTES(0x02),        \
	    USB_CDC_UNION_DESC_BYTES(CONF_USB_COMPOSITE_CDC_ACM_COMM_BIFCNUM, 0x01),                                       \
	    USB_ENDP_DESC_BYTES(                                                                                           \
	        CONF_USB_COMPOSITE_CDC_ACM_COMM_INT_EPADDR, 3, CONF_USB_COMPOSITE_CDC_ACM_COMM_INT_MAXPKSZ, 10),           \
	    USB_IFACE_DESC_BYTES(CONF_USB_COMPOSITE_CDC_ACM_DATA_BIFCNUM, 0x00, 2, 0x0A, 0x00, 0x00, 0x00),                \
	    USB_ENDP_DESC_BYTES(                                                                                           \
	        CONF_USB_COMPOSITE_CDC_ACM_DATA_BULKOUT_EPADDR, 2, CONF_USB_COMPOSITE_CDC_ACM_DATA_BULKOUT_MAXPKSZ, 0x00), \
	    USB_ENDP_DESC_BYTES(                                                                                           \
	        CONF_USB_COMPOSITE_CDC_ACM_DATA_BULKIN_EPADDR, 2, CONF_USB_COMPOSITE_CDC_ACM_DATA_BULKIN_MAXPKSZ, 0x00),
#define CONF_CDC_ACM_IFC_DESC_HS                                                                                       \
	USB_IAD_DESC_BYTES(                                                                                                \
	    CONF_USB_COMPOSITE_CDC_ACM_COMM_BIFCNUM, 0x02, CDC_CLASS_DEVICE, CDC_SUBCLASS_ACM, CDC_PROTOCOL_V25TER, 0x00), \
	    USB_IFACE_DESC_BYTES(CONF_USB_COMPOSITE_CDC_ACM_COMM_BIFCNUM,                                                  \
	                         0x00,                                                                                     \
	                         0x01,                                                                                     \
	                         CDC_CLASS_DEVICE,                                                                         \
	                         CDC_SUBCLASS_ACM,                                                                         \
	                         CDC_PROTOCOL_V25TER,                                                                      \
	                         0x00),                                                                                    \
	    USB_CDC_HDR_DESC_BYTES(0x1001), USB_CDC_CALL_MGMT_DESC_BYTES(0x01, 0x00), USB_CDC_ACM_DESC_BYTES(0x02),        \
	    USB_CDC_UNION_DESC_BYTES(CONF_USB_COMPOSITE_CDC_ACM_COMM_BIFCNUM, 0x01),                                       \
	    USB_ENDP_DESC_BYTES(                                                                                           \
	        CONF_USB_COMPOSITE_CDC_ACM_COMM_INT_EPADDR, 3, CONF_USB_COMPOSITE_CDC_ACM_COMM_INT_MAXPKSZ, 10),           \
	    USB_IFACE_DESC_BYTES(CONF_USB_COMPOSITE_CDC_ACM_DATA_BIFCNUM, 0x00, 2, 0x0A, 0x00, 0x00, 0x00),                \
	    USB_ENDP_DESC_BYTES(CONF_USB_COMPOSITE_CDC_ACM_DATA_BULKOUT_EPADDR,                                            \
	                        2,                                                                                         \
	                        CONF_USB_COMPOSITE_CDC_ACM_DATA_BULKOUT_MAXPKSZ_HS,                                        \
	                        0x00),                                                                                     \
	    USB_ENDP_DESC_BYTES(CONF_USB_COMPOSITE_CDC_ACM_DATA_BULKIN_EPADDR,                                             \
	                        2,                                                                                         \
	                        CONF_USB_COMPOSITE_CDC_ACM_DATA_BULKIN_MAXPKSZ_HS,                                         \
	                        0x00),
#else
#define CONF_CDC_ACM_IFC_LEN 0
#define CONF_CDC_ACM_IFC_NUM 0
#define CONF_USB_COMPOSITE_CDC_ACM_COMM_BIFCNUM -2
#define CONF_USB_COMPOSITE_CDC_ACM_DATA_BIFCNUM -1
#define CONF_CDC_ACM_IFC_DESC
#define CONF_CDC_ACM_IFC_DESC_HS
#endif

#if CONF_USB_COMPOSITE_HID_MOUSE_EN == 1
#define CONF_HID_MOUSE_IFC_LEN 25
#define CONF_HID_MOUSE_IFC_NUM 1
#define CONF_USB_COMPOSITE_HID_MOUSE_BIFCNUM (CONF_USB_COMPOSITE_CDC_ACM_DATA_BIFCNUM + 1)
#define CONF_HID_MOUSE_IFC_DESC                                                                                        \
	USB_IFACE_DESC_BYTES(CONF_USB_COMPOSITE_HID_MOUSE_BIFCNUM, 0x00, 0x01, 0x03, 0x01, 0x02, 0x00),                    \
	    USB_HID_DESC_BYTES(0x09, 0x21, 0x01, 0x22, 0x34),                                                              \
	    USB_ENDP_DESC_BYTES(                                                                                           \
	        CONF_USB_COMPOSITE_HID_MOUSE_INTIN_EPADDR, 0x03, CONF_USB_COMPOSITE_HID_MOUSE_INTIN_MAXPKSZ, 10),
#else
#define CONF_HID_MOUSE_IFC_LEN 0
#define CONF_HID_MOUSE_IFC_NUM 0
#define CONF_USB_COMPOSITE_HID_MOUSE_BIFCNUM CONF_USB_COMPOSITE_CDC_ACM_DATA_BIFCNUM
#define CONF_HID_MOUSE_IFC_DESC
#endif

#if CONF_USB_COMPOSITE_HID_KEYBOARD_EN == 1
#define CONF_HID_KEYBOARD_IFC_LEN 32
#define CONF_HID_KEYBOARD_IFC_NUM 1
#define CONF_USB_COMPOSITE_HID_KEYBOARD_BIFCNUM (CONF_USB_COMPOSITE_HID_MOUSE_BIFCNUM + 1)
#define CONF_HID_KEYBOARD_IFC_DESC                                                                                     \
	USB_IFACE_DESC_BYTES(CONF_USB_COMPOSITE_HID_KEYBOARD_BIFCNUM, 0x00, 0x02, 0x03, 0x01, 0x01, 0x00),                 \
	    USB_HID_DESC_BYTES(0x09, 0x21, 0x01, 0x22, 59),                                                                \
	    USB_ENDP_DESC_BYTES(                                                                                           \
	        CONF_USB_COMPOSITE_HID_KEYBOARD_INTIN_EPADDR, 0x03, CONF_USB_COMPOSITE_HID_KEYBOARD_INTIN_MAXPKSZ, 10),    \
	    USB_ENDP_DESC_BYTES(                                                                                           \
	        CONF_USB_COMPOSITE_HID_KEYBOARD_INTOUT_EPADDR, 0x03, CONF_USB_COMPOSITE_HID_KEYBOARD_INTOUT_MAXPKSZ, 10),
#else
#define CONF_HID_KEYBOARD_IFC_LEN 0
#define CONF_HID_KEYBOARD_IFC_NUM 0
#define CONF_USB_COMPOSITE_HID_KEYBOARD_BIFCNUM CONF_USB_COMPOSITE_HID_MOUSE_BIFCNUM
#define CONF_HID_KEYBOARD_IFC_DESC
#endif

#if CONF_USB_COMPOSITE_HID_GENERIC_EN == 1
#define CONF_HID_GENERIC_IFC_LEN 32
#define CONF_HID_GENERIC_IFC_NUM 1
#define CONF_USB_COMPOSITE_HID_GENERIC_BIFCNUM (CONF_USB_COMPOSITE_HID_KEYBOARD_BIFCNUM + 1)
#define CONF_HID_GENERIC_IFC_DESC                                                                                      \
	USB_IFACE_DESC_BYTES(CONF_USB_COMPOSITE_HID_GENERIC_BIFCNUM, 0x00, 0x02, 0x03, 0x00, 0x00, 0x00),                  \
	    USB_HID_DESC_BYTES(0x09, 0x21, 0x01, 0x22, CONF_USB_COMPOSITE_HID_GENERIC_REPORT_LEN),                         \
	    USB_ENDP_DESC_BYTES(                                                                                           \
	        CONF_USB_COMPOSITE_HID_GENERIC_INTIN_EPADDR, 0x03, CONF_USB_COMPOSITE_HID_GENERIC_INTIN_MAXPKSZ, 10),      \
	    USB_ENDP_DESC_BYTES(                                                                                           \
	        CONF_USB_COMPOSITE_HID_GENERIC_INTOUT_EPADDR, 0x03, CONF_USB_COMPOSITE_HID_GENERIC_INTOUT_MAXPKSZ, 10),
#else
#define CONF_HID_GENERIC_IFC_LEN 0
#define CONF_HID_GENERIC_IFC_NUM 0
#define CONF_USB_COMPOSITE_HID_GENERIC_BIFCNUM CONF_USB_COMPOSITE_HID_KEYBOARD_BIFCNUM
#define CONF_HID_GENERIC_IFC_DESC
#endif

#if CONF_USB_COMPOSITE_MSC_EN == 1
#define CONF_MSC_IFC_LEN 23 /* (9 + 7 * 2) */
#define CONF_MSC_IFC_NUM 1
#define CONF_USB_COMPOSITE_MSC_BIFCNUM (CONF_USB_COMPOSITE_HID_GENERIC_BIFCNUM + 1)
#define CONF_MSC_IFC_DESC                                                                                              \
	USB_IFACE_DESC_BYTES(CONF_USB_COMPOSITE_MSC_BIFCNUM, 0x00, 0x02, 0x08, 0x06, 0x50, 0x00),                          \
	    USB_ENDP_DESC_BYTES(CONF_USB_COMPOSITE_MSC_BULKIN_EPADDR, 0x02, CONF_USB_COMPOSITE_MSC_BULK_MAXPKSZ, 0),       \
	    USB_ENDP_DESC_BYTES(CONF_USB_COMPOSITE_MSC_BULKOUT_EPADDR, 0x02, CONF_USB_COMPOSITE_MSC_BULK_MAXPKSZ, 0),
#define CONF_MSC_IFC_DESC_HS                                                                                           \
	USB_IFACE_DESC_BYTES(CONF_USB_COMPOSITE_MSC_BIFCNUM, 0x00, 0x02, 0x08, 0x06, 0x50, 0x00),                          \
	    USB_ENDP_DESC_BYTES(CONF_USB_COMPOSITE_MSC_BULKIN_EPADDR, 0x02, CONF_USB_COMPOSITE_MSC_BULK_MAXPKSZ_HS, 0),    \
	    USB_ENDP_DESC_BYTES(CONF_USB_COMPOSITE_MSC_BULKOUT_EPADDR, 0x02, CONF_USB_COMPOSITE_MSC_BULK_MAXPKSZ_HS, 0),
#else
#define CONF_MSC_IFC_LEN 0
#define CONF_MSC_IFC_NUM 0
#define CONF_USB_COMPOSITE_MSC_BIFCNUM CONF_USB_COMPOSITE_HID_GENERIC_BIFCNUM
#define CONF_MSC_IFC_DESC
#define CONF_MSC_IFC_DESC_HS
#endif

#define CONF_USB_COMPOSITE_TOTAL_LEN                                                                                   \
	(USB_CONFIG_DESC_LEN + CONF_CDC_ACM_IFC_LEN + CONF_HID_MOUSE_IFC_LEN + CONF_HID_KEYBOARD_IFC_LEN                   \
	 + CONF_HID_GENERIC_IFC_LEN + CONF_MSC_IFC_LEN)

#define CONF_USB_COMPOSITE_IFC_NUM                                                                                     \
	(CONF_CDC_ACM_IFC_NUM + CONF_HID_MOUSE_IFC_NUM + CONF_HID_KEYBOARD_IFC_NUM + CONF_HID_GENERIC_IFC_NUM              \
	 + CONF_MSC_IFC_NUM)

#define COMPOSITE_DEV_DESC                                                                                             \
	USB_DEV_DESC_BYTES(CONF_USB_COMPOSITE_BCDUSB,                                                                      \
	                   0xEF,                                                                                           \
	                   0x02,                                                                                           \
	                   0x01,                                                                                           \
	                   CONF_USB_COMPOSITE_BMAXPKSZ0,                                                                   \
	                   CONF_USB_COMPOSITE_IDVENDER,                                                                    \
	                   CONF_USB_COMPOSITE_IDPRODUCT,                                                                   \
	                   CONF_USB_COMPOSITE_BCDDEVICE,                                                                   \
	                   CONF_USB_COMPOSITE_IMANUFACT,                                                                   \
	                   CONF_USB_COMPOSITE_IPRODUCT,                                                                    \
	                   CONF_USB_COMPOSITE_ISERIALNUM,                                                                  \
	                   CONF_USB_COMPOSITE_BNUMCONFIG)

#define COMPOSITE_DEV_QUAL_DESC                                                                                        \
	USB_DEV_QUAL_DESC_BYTES(                                                                                           \
	    CONF_USB_COMPOSITE_BCDUSB, 0xEF, 0x02, 0x01, CONF_USB_COMPOSITE_BMAXPKSZ0, CONF_USB_COMPOSITE_BNUMCONFIG)

#define COMPOSITE_CFG_DESC                                                                                             \
	USB_CONFIG_DESC_BYTES(CONF_USB_COMPOSITE_TOTAL_LEN,                                                                \
	                      CONF_USB_COMPOSITE_IFC_NUM,                                                                  \
	                      CONF_USB_COMPOSITE_BCONFIGVAL,                                                               \
	                      CONF_USB_COMPOSITE_ICONFIG,                                                                  \
	                      CONF_USB_COMPOSITE_BMATTRI,                                                                  \
	                      CONF_USB_COMPOSITE_BMAXPOWER)

#define COMPOSITE_OTH_SPD_CFG_DESC                                                                                     \
	USB_OTH_SPD_CFG_DESC_BYTES(CONF_USB_COMPOSITE_TOTAL_LEN,                                                           \
	                           CONF_USB_COMPOSITE_IFC_NUM,                                                             \
	                           CONF_USB_COMPOSITE_BCONFIGVAL,                                                          \
	                           CONF_USB_COMPOSITE_ICONFIG,                                                             \
	                           CONF_USB_COMPOSITE_BMATTRI,                                                             \
	                           CONF_USB_COMPOSITE_BMAXPOWER)

#define COMPOSITE_IFACE_DESCES                                                                                         \
	CONF_CDC_ACM_IFC_DESC                                                                                              \
	CONF_HID_MOUSE_IFC_DESC                                                                                            \
	CONF_HID_KEYBOARD_IFC_DESC                                                                                         \
	CONF_HID_GENERIC_IFC_DESC                                                                                          \
	CONF_MSC_IFC_DESC

#define COMPOSITE_IFACE_DESCES_HS                                                                                      \
	CONF_CDC_ACM_IFC_DESC_HS                                                                                           \
	CONF_HID_MOUSE_IFC_DESC                                                                                            \
	CONF_HID_KEYBOARD_IFC_DESC                                                                                         \
	CONF_HID_GENERIC_IFC_DESC                                                                                          \
	CONF_MSC_IFC_DESC_HS

#define COMPOSITE_STR_DESCESS                                                                                          \
	CONF_USB_COMPOSITE_LANGID_DESC                                                                                     \
	CONF_USB_COMPOSITE_IMANUFACT_STR_DESC                                                                              \
	CONF_USB_COMPOSITE_IPRODUCT_STR_DESC                                                                               \
	CONF_USB_COMPOSITE_ISERIALNUM_STR_DESC                                                                             \
	CONF_USB_COMPOSITE_ICONFIG_STR_DESC

/** USB Device descriptors and configuration descriptors */
#define COMPOSITE_DESCES_LS_FS COMPOSITE_DEV_DESC, COMPOSITE_CFG_DESC, COMPOSITE_IFACE_DESCES COMPOSITE_STR_DESCESS

#define COMPOSITE_HS_DESCES_LS_FS                                                                                      \
	COMPOSITE_DEV_DESC, COMPOSITE_DEV_QUAL_DESC, COMPOSITE_CFG_DESC,                                                   \
	    COMPOSITE_IFACE_DESCES COMPOSITE_OTH_SPD_CFG_DESC, COMPOSITE_IFACE_DESCES_HS COMPOSITE_STR_DESCESS

#define COMPOSITE_HS_DESCES_HS                                                                                         \
	COMPOSITE_CFG_DESC, COMPOSITE_IFACE_DESCES_HS COMPOSITE_OTH_SPD_CFG_DESC, COMPOSITE_IFACE_DESCES

#endif /* USBDF_COMPOSITE_DESC_H_ */
