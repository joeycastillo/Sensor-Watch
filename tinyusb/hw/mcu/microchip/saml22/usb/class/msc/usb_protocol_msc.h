/**
 * \file
 *
 * \brief USB Mass Storage Class (MSC) protocol definitions.
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
 *
 */

#ifndef _USB_PROTOCOL_MSC_H_
#define _USB_PROTOCOL_MSC_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \ingroup usb_protocol_group
 * \defgroup usb_msc_protocol USB Mass Storage Class (MSC) protocol definitions
 *
 * @{
 */

/**
 * \name Possible Class value
 */
//@{
#define MSC_CLASS 0x08
//@}

/**
 * \name Possible SubClass value
 * \note In practice, most devices should use
 * #MSC_SUBCLASS_TRANSPARENT and specify the actual command set in
 * the standard INQUIRY data block, even if the MSC spec indicates
 * otherwise. In particular, RBC is not supported by certain major
 * operating systems like Windows XP.
 */
//@{
#define MSC_SUBCLASS_RBC 0x01         /**< Reduced Block Commands */
#define MSC_SUBCLASS_ATAPI 0x02       /**< CD/DVD devices */
#define MSC_SUBCLASS_QIC_157 0x03     /**< Tape devices */
#define MSC_SUBCLASS_UFI 0x04         /**< Floppy disk drives */
#define MSC_SUBCLASS_SFF_8070I 0x05   /**< Floppy disk drives */
#define MSC_SUBCLASS_TRANSPARENT 0x06 /**< Determined by INQUIRY */
//@}

/**
 * \name Possible protocol value
 * \note Only the BULK protocol should be used in new designs.
 */
//@{
#define MSC_PROTOCOL_CBI 0x00     /**< Command/Bulk/Interrupt */
#define MSC_PROTOCOL_CBI_ALT 0x01 /**< W/o command completion */
#define MSC_PROTOCOL_BULK 0x50    /**< Bulk-only */
//@}

/**
 * \brief MSC USB requests (bRequest)
 */

#define USB_REQ_MSC_BULK_RESET 0xFF  /**< Mass Storage Reset */
#define USB_REQ_MSC_GET_MAX_LUN 0xFE /**< Get Max LUN */

COMPILER_PACK_SET(1)

/**
 * \name A Command Block Wrapper (CBW)
 * \note Fields are LSB first (LE)
 */
//@{
struct usb_msc_cbw {
	le32_t  dCBWSignature;          /**< Must contain 'USBC' (0x43425355, LE32) */
	le32_t  dCBWTag;                /**< Unique command ID (LE32) */
	le32_t  dCBWDataTransferLength; /**< Number of bytes to transfer (LE32) */
	uint8_t bmCBWFlags;             /**< Direction in bit 7 */
	uint8_t bCBWLUN;                /**< Logical Unit Number */
	uint8_t bCBWCBLength;           /**< Number of valid CDB bytes */
	uint8_t CDB[16];                /**< SCSI Command Descriptor Block */
};

#define USB_CBW_SIGNATURE 0x43425355   /**< dCBWSignature value */
#define USB_CBW_DIRECTION_IN (1 << 7)  /**< Data from device to host */
#define USB_CBW_DIRECTION_OUT (0 << 7) /**< Data from host to device */
#define USB_CBW_LUN_MASK 0x0F          /**< Valid bits in bCBWLUN */
#define USB_CBW_LEN_MASK 0x1F          /**< Valid bits in bCBWCBLength */
//@}

/**
 * \name A Command Status Wrapper (CSW)
 * \note Fields are LSB first (LE)
 */
//@{
struct usb_msc_csw {
	le32_t  dCSWSignature;   /**< Must contain 'USBS' */
	le32_t  dCSWTag;         /**< Same as dCBWTag */
	le32_t  dCSWDataResidue; /**< Number of bytes not transfered */
	uint8_t bCSWStatus;      /**< Status code */
};

#define USB_CSW_SIGNATURE 0x53425355 /**< dCSWSignature value */
#define USB_CSW_STATUS_PASS 0x00     /**< Command Passed */
#define USB_CSW_STATUS_FAIL 0x01     /**< Command Failed */
#define USB_CSW_STATUS_PE 0x02       /**< Phase Error */
//@}

COMPILER_PACK_RESET()

//@}

/**
 * \brief Fill a Bulk-Only Mass Storage Reset request
 * \param[out] req   Pointer to the request to fill
 * \param[in]  iface Interface Number
 */
static inline void usb_fill_BOMSReset_req(struct usb_req *req, uint8_t iface)
{
	req->bmRequestType = 0x21;
	req->bRequest      = USB_REQ_MSC_BULK_RESET;
	req->wValue        = 0;
	req->wIndex        = iface;
	req->wLength       = 0;
}

/**
 * \brief Fill a GetMaxLUN request
 * \param[out] req   Pointer to the request to fill
 * \param[in]  iface Interface Number
 */
static inline void usb_fill_GetMaxLUN_req(struct usb_req *req, uint8_t iface)
{
	req->bmRequestType = 0xA1;
	req->bRequest      = USB_REQ_MSC_GET_MAX_LUN;
	req->wValue        = 0;
	req->wIndex        = iface;
	req->wLength       = 1;
}

#ifdef __cplusplus
}
#endif

#endif // _USB_PROTOCOL_MSC_H_
