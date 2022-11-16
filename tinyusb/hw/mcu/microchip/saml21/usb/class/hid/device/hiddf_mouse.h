/**
 * \file
 *
 * \brief USB Device Stack HID Mouse Function Definition.
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

#ifndef USBDF_HID_MOUSE_H_
#define USBDF_HID_MOUSE_H_

#include "usbdc.h"
#include "usb_protocol_hid.h"

/** HID Mouse Class Button State Type */
enum hiddf_mouse_button_state { HID_MOUSE_BTN_UP, HID_MOUSE_BTN_DOWN };

/* HID Mosue Class Button Type */
enum hiddf_mouse_button_type { HID_MOUSE_LEFT_BTN = 0x01, HID_MOUSE_RIGHT_BTN = 0x02, HID_MOUSE_MIDDLE_BTN = 0x04 };

/* HID Mouse Class Pointer Move Type */
enum hiddf_mouse_move_type { HID_MOUSE_X_AXIS_MV = 0x01, HID_MOUSE_Y_AXIS_MV = 0x02, HID_MOUSE_SCROLL_MV = 0x03 };

/**
 * \brief Initialize the USB HID Mouse Function Driver
 * \return Operation status.
 */
int32_t hiddf_mouse_init(void);

/**
 * \brief Deinitialize the USB HID Mouse Function Driver
 * \return Operation status.
 */
int32_t hiddf_mouse_deinit(void);

/**
 * \brief Check whether HID Mouse Function is enabled
 * \return Operation status.
 * \return true HID Mouse Function is enabled
 * \return false HID Mouse Function is disabled
 */
bool hiddf_mouse_is_enabled(void);

/**
 * \brief Move the mouse pointer
 * \param pos     Signed value to move
 * \param type    HID mouse class pointer move type
 * \return Operation status.
 */
int32_t hiddf_mouse_move(int8_t pos, enum hiddf_mouse_move_type type);

/**
 * \brief Changes button state
 * \param b_state    New button state
 * \param type       Button type
 * \return Operation status.
 */
int32_t hiddf_mouse_button_change(enum hiddf_mouse_button_state b_state, enum hiddf_mouse_button_type type);

/**
 * \brief Return version
 */
uint32_t hiddf_mouse_get_version(void);

#endif /* USBDF_CDC_ACM_SER_H_ */
