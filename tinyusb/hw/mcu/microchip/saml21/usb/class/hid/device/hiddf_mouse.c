/**
 * \file
 *
 * \brief USB Device Stack HID Mouse Function Implementation.
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

#include "hiddf_mouse.h"

#define HIDDF_MOUSE_VERSION 0x00000001u

#define MOUSE_REPORT_DESC_LEN 52

/** USB Device HID Mouse Function Specific Data */
struct hiddf_mouse_func_data {
	/* HID descriptor */
	uint8_t *hid_desc;
	/* HID Device Mouse Report */
	union {
		/** Interpreted by bytes. */
		struct {
			/** Button Status. */
			uint8_t button_state;
			/** X Axis Variant.*/
			uint8_t x_axis_var;
			/** Y Axis Variant.*/
			uint8_t y_axis_var;
			/** Scroll Variant.*/
			uint8_t scroll_var;
		} bytes;
		uint32_t u32;
	} mouse_report;
	/** HID Device Mouse Interface information */
	uint8_t func_iface;
	/** HID Device Mouse IN Endpoint */
	uint8_t func_ep_in;
	/** HID Device Mouse protocol */
	uint8_t protocol;
	/** HID Device Mouse Enable Flag */
	bool enabled;
};

/* HID report descriptor for standard HID mouse */
const uint8_t mouse_report_desc[MOUSE_REPORT_DESC_LEN] = {
    0x05, 0x01, /*  Usage Page (Generic Desktop),    */
    0x09, 0x02, /*  Usage (Mouse),                   */
    0xA1, 0x01, /*  Collection (Application),        */
    0x09, 0x01, /*  Usage (Pointer),                 */
    0xA1, 0x00, /*  Collection (Physical),           */
    0x05, 0x09, /*  Usage Page (Buttons),            */
    0x19, 0x01, /*  Usage Minimum (01),              */
    0x29, 0x03, /*  Usage Maximum (03),              */
    0x15, 0x00, /*  Logical Minimum (0),             */
    0x25, 0x01, /*  Logical Maximum (1),             */
    0x75, 0x01, /*  Report Size (1),                 */
    0x95, 0x03, /*  Report Count (3),                */
    0x81, 0x02, /*  Input (Data, Variable, Absolute) */
    0x75, 0x05, /*  Report Size (5),                 */
    0x95, 0x01, /*  Report Count (1),                */
    0x81, 0x01, /*  Input (Constant),                */
    0x05, 0x01, /*  Usage Page (Generic Desktop),    */
    0x09, 0x30, /*  Usage (X),                       */
    0x09, 0x31, /*  Usage (Y),                       */
    0x09, 0x38, /*  Usage (Scroll),                  */
    0x15, 0x81, /*  Logical Minimum (-127),          */
    0x25, 0x7F, /*  Logical Maximum (127),           */
    0x75, 0x08, /*  Report Size (8),                 */
    0x95, 0x03, /*  Report Count (3),                */
    0x81, 0x06, /*  Input (Data, Variable, Relative) */
    0xC0,       /*  End Collection,                  */
    0xC0,       /*  End Collection                   */
};

/* USB Device HID Mouse Function Instance */
static struct usbdf_driver _hiddf_mouse;

/* USB Device HID Mouse Function Data Instance */
static struct hiddf_mouse_func_data _hiddf_mouse_funcd;

/**
 * \brief Enable HID Mouse Function
 * \param[in] drv Pointer to USB device function driver
 * \param[in] desc Pointer to USB interface descriptor
 * \return Operation status.
 */
static int32_t hid_mouse_enable(struct usbdf_driver *drv, struct usbd_descriptors *desc)
{
	uint8_t *        ifc, *ep;
	usb_iface_desc_t ifc_desc;
	usb_ep_desc_t    ep_desc;

	struct hiddf_mouse_func_data *func_data = (struct hiddf_mouse_func_data *)(drv->func_data);

	ifc = desc->sod;
	if (NULL == ifc) {
		return ERR_NOT_FOUND;
	}

	ifc_desc.bInterfaceNumber = ifc[2];
	ifc_desc.bInterfaceClass  = ifc[5];

	if (HID_CLASS == ifc_desc.bInterfaceClass) {
		if (func_data->func_iface == ifc_desc.bInterfaceNumber) { // Initialized
			return ERR_ALREADY_INITIALIZED;
		} else if (func_data->func_iface != 0xFF) { // Occupied
			return ERR_NO_RESOURCE;
		} else {
			func_data->func_iface = ifc_desc.bInterfaceNumber;
		}
	} else { // Not supported by this function driver
		return ERR_NOT_FOUND;
	}

	// Install HID descriptor
	_hiddf_mouse_funcd.hid_desc = usb_find_desc(usb_desc_next(desc->sod), desc->eod, USB_DT_HID);

	// Install endpoints
	ep        = usb_find_ep_desc(usb_desc_next(desc->sod), desc->eod);
	desc->sod = ep;
	if (NULL != ep) {
		ep_desc.bEndpointAddress = ep[2];
		ep_desc.bmAttributes     = ep[3];
		ep_desc.wMaxPacketSize   = usb_get_u16(ep + 4);
		if (usb_d_ep_init(ep_desc.bEndpointAddress, ep_desc.bmAttributes, ep_desc.wMaxPacketSize)) {
			return ERR_NOT_INITIALIZED;
		}
		if (ep_desc.bEndpointAddress & USB_EP_DIR_IN) {
			func_data->func_ep_in = ep_desc.bEndpointAddress;
			usb_d_ep_enable(func_data->func_ep_in);
		} else {
			return ERR_INVALID_DATA;
		}
	} else {
		return ERR_NOT_FOUND;
	}
	// Installed
	_hiddf_mouse_funcd.protocol = 1;
	_hiddf_mouse_funcd.enabled  = true;
	return ERR_NONE;
}

/**
 * \brief Disable HID Mouse Function
 * \param[in] drv Pointer to USB device function driver
 * \param[in] desc Pointer to USB device descriptor
 * \return Operation status.
 */
static int32_t hid_mouse_disable(struct usbdf_driver *drv, struct usbd_descriptors *desc)
{
	struct hiddf_mouse_func_data *func_data = (struct hiddf_mouse_func_data *)(drv->func_data);

	usb_iface_desc_t ifc_desc;

	if (desc) {
		ifc_desc.bInterfaceClass = desc->sod[5];
		if (ifc_desc.bInterfaceClass != HID_CLASS) {
			return ERR_NOT_FOUND;
		}
	}

	if (func_data->func_iface != 0xFF) {
		func_data->func_iface = 0xFF;
	}

	if (func_data->func_ep_in != 0xFF) {
		usb_d_ep_deinit(func_data->func_ep_in);
		func_data->func_ep_in = 0xFF;
	}

	_hiddf_mouse_funcd.enabled = false;
	return ERR_NONE;
}

/**
 * \brief HID Mouse Control Function
 * \param[in] drv Pointer to USB device function driver
 * \param[in] ctrl USB device general function control type
 * \param[in] param Parameter pointer
 * \return Operation status.
 */
static int32_t hid_mouse_ctrl(struct usbdf_driver *drv, enum usbdf_control ctrl, void *param)
{
	switch (ctrl) {
	case USBDF_ENABLE:
		return hid_mouse_enable(drv, (struct usbd_descriptors *)param);

	case USBDF_DISABLE:
		return hid_mouse_disable(drv, (struct usbd_descriptors *)param);

	case USBDF_GET_IFACE:
		return ERR_UNSUPPORTED_OP;

	default:
		return ERR_INVALID_ARG;
	}
}

/**
 * \brief Process the HID class get descriptor
 * \param[in] ep Endpoint address.
 * \param[in] req Pointer to the request.
 * \return Operation status.
 */
static int32_t hid_mouse_get_desc(uint8_t ep, struct usb_req *req)
{
	switch (req->wValue >> 8) {
	case USB_DT_HID:
		return usbdc_xfer(ep, _hiddf_mouse_funcd.hid_desc, _hiddf_mouse_funcd.hid_desc[0], false);
	case USB_DT_HID_REPORT:
		return usbdc_xfer(ep, (uint8_t *)mouse_report_desc, MOUSE_REPORT_DESC_LEN, false);
	default:
		return ERR_INVALID_ARG;
	}
}

/**
 * \brief Process the HID class request
 * \param[in] ep Endpoint address.
 * \param[in] req Pointer to the request.
 * \return Operation status.
 */
static int32_t hid_mouse_req(uint8_t ep, struct usb_req *req, enum usb_ctrl_stage stage)
{
	if ((0x81 == req->bmRequestType) && (0x06 == req->bRequest) && (req->wIndex == _hiddf_mouse_funcd.func_iface)) {
		return hid_mouse_get_desc(ep, req);
	} else {
		if (0x01 != ((req->bmRequestType >> 5) & 0x03)) { // class request
			return ERR_NOT_FOUND;
		}
		if (req->wIndex == _hiddf_mouse_funcd.func_iface) {
			switch (req->bRequest) {
			case 0x03: /* Get Protocol */
				return usbdc_xfer(ep, &_hiddf_mouse_funcd.protocol, 1, 0);
			case 0x0B: /* Set Protocol */
				_hiddf_mouse_funcd.protocol = req->wValue;
				return usbdc_xfer(ep, NULL, 0, 0);
			default:
				return ERR_INVALID_ARG;
			}
		} else {
			return ERR_NOT_FOUND;
		}
	}
	(void)stage;
}

/** USB Device HID Mouse Handler Struct */
static struct usbdc_handler hid_mouse_req_h = {NULL, (FUNC_PTR)hid_mouse_req};

/**
 * \brief Initialize the USB HID Mouse Function Driver
 */
int32_t hiddf_mouse_init(void)
{
	if (usbdc_get_state() > USBD_S_POWER) {
		return ERR_DENIED;
	}

	_hiddf_mouse.ctrl      = hid_mouse_ctrl;
	_hiddf_mouse.func_data = &_hiddf_mouse_funcd;

	usbdc_register_function(&_hiddf_mouse);
	usbdc_register_handler(USBDC_HDL_REQ, &hid_mouse_req_h);
	return ERR_NONE;
}

/**
 * \brief Deinitialize the USB HID Mouse Function Driver
 */
int32_t hiddf_mouse_deinit(void)
{
	if (usbdc_get_state() > USBD_S_POWER) {
		return ERR_DENIED;
	}

	_hiddf_mouse.ctrl      = NULL;
	_hiddf_mouse.func_data = NULL;

	usbdc_unregister_function(&_hiddf_mouse);
	usbdc_unregister_handler(USBDC_HDL_REQ, &hid_mouse_req_h);
	return ERR_NONE;
}

/**
 * \brief Check whether HID Mouse Function is enabled
 */
bool hiddf_mouse_is_enabled(void)
{
	return _hiddf_mouse_funcd.enabled;
}

/**
 * \brief Move the mouse pointer
 * \param pos     Signed value to move
 * \param type    HID mouse class pointer move type
 * \return Operation status.
 */
int32_t hiddf_mouse_move(int8_t pos, enum hiddf_mouse_move_type type)
{

	_hiddf_mouse_funcd.mouse_report.u32 = 0;

	if (type == HID_MOUSE_X_AXIS_MV) {
		_hiddf_mouse_funcd.mouse_report.bytes.x_axis_var = pos;
	} else if (type == HID_MOUSE_Y_AXIS_MV) {
		_hiddf_mouse_funcd.mouse_report.bytes.y_axis_var = pos;
	} else if (type == HID_MOUSE_SCROLL_MV) {
		_hiddf_mouse_funcd.mouse_report.bytes.scroll_var = pos;
	} else {
		return ERR_INVALID_ARG;
	}

	return usbdc_xfer(_hiddf_mouse_funcd.func_ep_in, &_hiddf_mouse_funcd.mouse_report.bytes.button_state, 4, false);
}

/**
 * \brief Changes button state
 * \param b_state    New button state
 * \param type       Button type
 * \return Operation status.
 */
int32_t hiddf_mouse_button_change(enum hiddf_mouse_button_state b_state, enum hiddf_mouse_button_type type)
{
	_hiddf_mouse_funcd.mouse_report.u32 = 0;

	if (b_state == HID_MOUSE_BTN_DOWN) {
		_hiddf_mouse_funcd.mouse_report.bytes.button_state = type;
	} else {
		_hiddf_mouse_funcd.mouse_report.bytes.button_state = 0x00;
	}

	return usbdc_xfer(_hiddf_mouse_funcd.func_ep_in, &_hiddf_mouse_funcd.mouse_report.bytes.button_state, 4, false);
}

/**
 * \brief Return version
 */
uint32_t hiddf_mouse_get_version(void)
{
	return HIDDF_MOUSE_VERSION;
}
