/**
 * \file
 *
 * \brief USB Device Stack Vendor Function Implementation.
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

#include "vendordf.h"

#define VENDOR_VERSION 0x00000001u

#define VENDOR_TRANS_OUT 0
#define VENDOR_TRANS_IN 1

/** USB Device Vendor Function Specific Data */
struct vendordf_func_data {
	/** Vendor Interface information */
	uint8_t func_iface;
	/** Vendor Isochronous Endpoint */
	uint8_t func_iso_ep[2];
	/** Vendor Bulk Endpoint */
	uint8_t func_bulk_ep[2];
	/** Vendor Interrupt Endpoint */
	uint8_t func_int_ep[2];
	/** Vendor Alternate setting */
	uint8_t func_alt_set;
	/** Vendor Enable Flag */
	bool enabled;
};

/* USB Device Vendor Function Instance */
static struct usbdf_driver _vendordf;

/* USB Device Vendor Function Data Instance */
static struct vendordf_func_data _vendordf_funcd;

/* USB Device Vendor Callback Function Pointer */
static vendor_ctrl_cb_t vendor_ctrl_rd = NULL;
static vendor_ctrl_cb_t vendor_ctrl_wr = NULL;
static FUNC_PTR         vendor_int_rd  = NULL;
static FUNC_PTR         vendor_int_wr  = NULL;
static FUNC_PTR         vendor_bulk_rd = NULL;
static FUNC_PTR         vendor_bulk_wr = NULL;
static FUNC_PTR         vendor_iso_rd  = NULL;
static FUNC_PTR         vendor_iso_wr  = NULL;

/**
 * \brief Enable Vendor Function
 * \param[in] drv Pointer to USB device function driver
 * \param[in] desc Pointer to USB interface descriptor
 * \return Operation status.
 */
static int32_t vendordf_enable(struct usbdf_driver *drv, struct usbd_descriptors *desc)
{
	uint8_t *        ifc, *ep, i;
	usb_iface_desc_t ifc_desc;
	usb_ep_desc_t    ep_desc;
	enum usb_ep_type ep_type;

	struct vendordf_func_data *func_data = (struct vendordf_func_data *)(drv->func_data);

	ifc = desc->sod;
	if (NULL == ifc) {
		return ERR_NOT_FOUND;
	}

	ifc_desc.bInterfaceNumber  = ifc[2];
	ifc_desc.bAlternateSetting = ifc[3];
	ifc_desc.bInterfaceClass   = ifc[5];

	if (VENDOR_CLASS != ifc_desc.bInterfaceClass) {
		return ERR_NOT_FOUND;
	}

	if (func_data->func_iface != 0xFF && func_data->func_iface != ifc_desc.bInterfaceNumber) {
		return ERR_ALREADY_INITIALIZED;
	} else {
		if (func_data->func_iface == 0xFF || func_data->func_alt_set != ifc_desc.bAlternateSetting) {
			/* Install endpoints */
			for (i = 0; i < 6; i++) {
				ep = usb_find_ep_desc(usb_desc_next(desc->sod), desc->eod);
				if (NULL != ep) {
					desc->sod                = ep;
					ep_desc.bEndpointAddress = ep[2];
					ep_desc.bmAttributes     = ep[3];
					ep_desc.wMaxPacketSize   = usb_get_u16(ep + 4);
					ep_type                  = (enum usb_ep_type)(ep_desc.bmAttributes & USB_EP_TYPE_MASK);

					if (usb_d_ep_init(ep_desc.bEndpointAddress, ep_desc.bmAttributes, ep_desc.wMaxPacketSize)) {
						return ERR_NOT_INITIALIZED;
					}

					switch (ep_type) {
					case USB_EP_TYPE_ISOCHRONOUS:
						if (ep_desc.bEndpointAddress & USB_EP_DIR_IN) {
							func_data->func_iso_ep[VENDOR_TRANS_IN] = ep_desc.bEndpointAddress;
							if (NULL != vendor_iso_wr) {
								usb_d_ep_register_callback(
								    func_data->func_iso_ep[VENDOR_TRANS_IN], USB_D_EP_CB_XFER, vendor_iso_wr);
							}
						} else {
							func_data->func_iso_ep[VENDOR_TRANS_OUT] = ep_desc.bEndpointAddress;
							if (NULL != vendor_iso_rd) {
								usb_d_ep_register_callback(
								    func_data->func_iso_ep[VENDOR_TRANS_OUT], USB_D_EP_CB_XFER, vendor_iso_rd);
							}
						}
						usb_d_ep_enable(ep_desc.bEndpointAddress);
						break;
					case USB_EP_TYPE_BULK:
						if (ep_desc.bEndpointAddress & USB_EP_DIR_IN) {
							func_data->func_bulk_ep[VENDOR_TRANS_IN] = ep_desc.bEndpointAddress;
							if (NULL != vendor_bulk_wr) {
								usb_d_ep_register_callback(
								    func_data->func_bulk_ep[VENDOR_TRANS_IN], USB_D_EP_CB_XFER, vendor_bulk_wr);
							}
						} else {
							func_data->func_bulk_ep[VENDOR_TRANS_OUT] = ep_desc.bEndpointAddress;
							if (NULL != vendor_bulk_rd) {
								usb_d_ep_register_callback(
								    func_data->func_bulk_ep[VENDOR_TRANS_OUT], USB_D_EP_CB_XFER, vendor_bulk_rd);
							}
						}
						usb_d_ep_enable(ep_desc.bEndpointAddress);
						break;
					case USB_EP_TYPE_INTERRUPT:
						if (ep_desc.bEndpointAddress & USB_EP_DIR_IN) {
							func_data->func_int_ep[VENDOR_TRANS_IN] = ep_desc.bEndpointAddress;
							if (NULL != vendor_int_wr) {
								usb_d_ep_register_callback(
								    func_data->func_int_ep[VENDOR_TRANS_IN], USB_D_EP_CB_XFER, vendor_int_wr);
							}
						} else {
							func_data->func_int_ep[VENDOR_TRANS_OUT] = ep_desc.bEndpointAddress;
							if (NULL != vendor_int_rd) {
								usb_d_ep_register_callback(
								    func_data->func_int_ep[VENDOR_TRANS_OUT], USB_D_EP_CB_XFER, vendor_int_rd);
							}
						}
						usb_d_ep_enable(ep_desc.bEndpointAddress);
						break;
					default:
						return ERR_INVALID_ARG;
					}
				} else {
					break;
				}
			}
			func_data->func_iface   = ifc_desc.bInterfaceNumber;
			func_data->func_alt_set = ifc_desc.bAlternateSetting;
			func_data->enabled      = (bool)func_data->func_alt_set;
		}
		return ERR_NONE;
	}
}

/**
 * \brief Disable Vendor Function
 * \param[in] drv Pointer to USB device function driver
 * \param[in] desc Pointer to USB device descriptor
 * \return Operation status.
 */
static int32_t vendordf_disable(struct usbdf_driver *drv, struct usbd_descriptors *desc)
{
	struct vendordf_func_data *func_data = (struct vendordf_func_data *)(drv->func_data);

	usb_iface_desc_t ifc_desc;

	if (desc) {
		ifc_desc.bInterfaceClass  = desc->sod[5];
		ifc_desc.bInterfaceNumber = desc->sod[2];
		if (ifc_desc.bInterfaceClass != VENDOR_CLASS) {
			return ERR_NOT_FOUND;
		}
		if (func_data->enabled == true && func_data->func_iface != ifc_desc.bInterfaceNumber) {
			return ERR_NOT_FOUND;
		}
	}
	if (func_data->func_iface != 0xFF) {
		func_data->func_iface   = 0xFF;
		func_data->func_alt_set = 0xFF;
	}
	func_data->enabled = false;

	if (func_data->func_iso_ep[VENDOR_TRANS_OUT] != 0xFF) {
		usb_d_ep_deinit(func_data->func_iso_ep[VENDOR_TRANS_OUT]);
		func_data->func_iso_ep[VENDOR_TRANS_OUT] = 0xFF;
	}

	if (func_data->func_iso_ep[VENDOR_TRANS_IN] != 0xFF) {
		usb_d_ep_deinit(func_data->func_iso_ep[VENDOR_TRANS_IN]);
		func_data->func_iso_ep[VENDOR_TRANS_IN] = 0xFF;
	}

	if (func_data->func_bulk_ep[VENDOR_TRANS_OUT] != 0xFF) {
		usb_d_ep_deinit(func_data->func_bulk_ep[VENDOR_TRANS_OUT]);
		func_data->func_bulk_ep[VENDOR_TRANS_OUT] = 0xFF;
	}

	if (func_data->func_bulk_ep[VENDOR_TRANS_IN] != 0xFF) {
		usb_d_ep_deinit(func_data->func_bulk_ep[VENDOR_TRANS_IN]);
		func_data->func_bulk_ep[VENDOR_TRANS_IN] = 0xFF;
	}

	if (func_data->func_int_ep[VENDOR_TRANS_OUT] != 0xFF) {
		usb_d_ep_deinit(func_data->func_int_ep[VENDOR_TRANS_OUT]);
		func_data->func_int_ep[VENDOR_TRANS_OUT] = 0xFF;
	}

	if (func_data->func_int_ep[VENDOR_TRANS_IN] != 0xFF) {
		usb_d_ep_deinit(func_data->func_int_ep[VENDOR_TRANS_IN]);
		func_data->func_int_ep[VENDOR_TRANS_IN] = 0xFF;
	}

	return ERR_NONE;
}

/**
 * \brief Get Vendor Alternate Setting
 * \param[in] drv Pointer to USB device function driver
 * \param[in] desc Pointer to USB device descriptor
 * \return Currently selected alternate setting.
 */
static int32_t vendordf_get_iface(struct usbdf_driver *drv, struct usb_req *req)
{
	(void)drv;

	if (req->wIndex == _vendordf_funcd.func_iface) {
		return _vendordf_funcd.func_alt_set;
	} else {
		return ERR_NOT_FOUND;
	}
}

/**
 * \brief Vendor Control Function
 * \param[in] drv Pointer to USB device function driver
 * \param[in] ctrl USB device general function control type
 * \param[in] param Parameter pointer
 * \return Operation status.
 */
static int32_t vendordf_ctrl(struct usbdf_driver *drv, enum usbdf_control ctrl, void *param)
{
	switch (ctrl) {
	case USBDF_ENABLE:
		return vendordf_enable(drv, (struct usbd_descriptors *)param);

	case USBDF_DISABLE:
		return vendordf_disable(drv, (struct usbd_descriptors *)param);

	case USBDF_GET_IFACE:
		return vendordf_get_iface(drv, (struct usb_req *)param);

	default:
		return ERR_INVALID_ARG;
	}
}

/**
 * \brief Process the VENDOR class request
 * \param[in] ep Endpoint address.
 * \param[in] req Pointer to the request.
 * \return Operation status.
 */
static int32_t vendordf_req(uint8_t ep, struct usb_req *req, enum usb_ctrl_stage stage)
{
	(void)ep;

	if (0x02 != ((req->bmRequestType >> 5) & 0x03)) { /* vendor request */
		return ERR_NOT_FOUND;
	}

	if (req->wIndex == _vendordf_funcd.func_iface && 0 == req->bRequest) {
		if (USB_EP_DIR_IN == (0x80 & req->bmRequestType)) {
			if (NULL != vendor_ctrl_wr && USB_SETUP_STAGE == stage) {
				vendor_ctrl_wr(req->wLength);
			}
			return ERR_NONE;
		} else {
			if (0 != req->wLength && NULL != vendor_ctrl_rd && USB_SETUP_STAGE == stage) {
				vendor_ctrl_rd(req->wLength);
			}
			return ERR_NONE;
		}
	} else {
		return ERR_NOT_FOUND;
	}
}

/** USB Device Vendor Handler Struct */
static struct usbdc_handler vendordf_req_h = {NULL, (FUNC_PTR)vendordf_req};

/**
 * \brief Initialize the USB Vendor Function Driver
 */
int32_t vendordf_init(void)
{
	if (usbdc_get_state() > USBD_S_POWER) {
		return ERR_DENIED;
	}

	_vendordf.ctrl      = vendordf_ctrl;
	_vendordf.func_data = &_vendordf_funcd;

	usbdc_register_function(&_vendordf);
	usbdc_register_handler(USBDC_HDL_REQ, &vendordf_req_h);

	return ERR_NONE;
}

/**
 * \brief Deinitialize the USB Vendor Function Driver
 */
int32_t vendordf_deinit(void)
{
	if (usbdc_get_state() > USBD_S_POWER) {
		return ERR_DENIED;
	}

	_vendordf.ctrl      = NULL;
	_vendordf.func_data = NULL;

	usbdc_unregister_function(&_vendordf);
	usbdc_unregister_handler(USBDC_HDL_REQ, &vendordf_req_h);
	return ERR_NONE;
}

/**
 * \brief Check whether Vendor Function is enabled
 */
bool vendordf_is_enabled(void)
{
	return _vendordf_funcd.enabled;
}

/**
 * \brief USB Vendor Function Read Data
 */
int32_t vendordf_read(enum usb_ep_type type, uint8_t *buf, uint32_t size)
{
	uint8_t ep;

	if (!vendordf_is_enabled()) {
		return ERR_DENIED;
	}

	switch (type) {
	case USB_EP_TYPE_CONTROL:
		ep = 0;
		break;
	case USB_EP_TYPE_ISOCHRONOUS:
		ep = _vendordf_funcd.func_iso_ep[VENDOR_TRANS_OUT];
		break;
	case USB_EP_TYPE_BULK:
		ep = _vendordf_funcd.func_bulk_ep[VENDOR_TRANS_OUT];
		break;
	case USB_EP_TYPE_INTERRUPT:
		ep = _vendordf_funcd.func_int_ep[VENDOR_TRANS_OUT];
		break;
	default:
		return ERR_INVALID_ARG;
	}

	return usbdc_xfer(ep, buf, size, false);
}

/**
 * \brief USB Vendor Function Write Data
 */
int32_t vendordf_write(enum usb_ep_type type, uint8_t *buf, uint32_t size)
{
	uint8_t ep;

	if (!vendordf_is_enabled()) {
		return ERR_DENIED;
	}

	switch (type) {
	case USB_EP_TYPE_CONTROL:
		ep = 0;
		break;
	case USB_EP_TYPE_ISOCHRONOUS:
		ep = _vendordf_funcd.func_iso_ep[VENDOR_TRANS_IN];
		break;
	case USB_EP_TYPE_BULK:
		ep = _vendordf_funcd.func_bulk_ep[VENDOR_TRANS_IN];
		break;
	case USB_EP_TYPE_INTERRUPT:
		ep = _vendordf_funcd.func_int_ep[VENDOR_TRANS_IN];
		break;
	default:
		return ERR_INVALID_ARG;
	}

	return usbdc_xfer(ep, buf, size, false);
}

/**
 * \brief USB Vendor Function Register Callback
 */
int32_t vendordf_register_callback(enum vendordf_cb_type cb_type, FUNC_PTR func)
{
	switch (cb_type) {
	case VENDORDF_CB_CTRL_READ_REQ:
		vendor_ctrl_rd = (vendor_ctrl_cb_t)func;
		break;
	case VENDORDF_CB_CTRL_WRITE_REQ:
		vendor_ctrl_wr = (vendor_ctrl_cb_t)func;
		break;
	case VENDORDF_CB_ISO_READ:
		vendor_iso_rd = func;
		break;
	case VENDORDF_CB_ISO_WRITE:
		vendor_iso_wr = func;
		break;
	case VENDORDF_CB_BULK_READ:
		vendor_bulk_rd = func;
		break;
	case VENDORDF_CB_BULK_WRITE:
		vendor_bulk_wr = func;
		break;
	case VENDORDF_CB_INT_READ:
		vendor_int_rd = func;
		break;
	case VENDORDF_CB_INT_WRITE:
		vendor_int_wr = func;
		break;
	default:
		return ERR_INVALID_ARG;
	}

	return ERR_NONE;
}

/**
 * \brief Return version
 */
uint32_t vendordf_get_version(void)
{
	return VENDOR_VERSION;
}
