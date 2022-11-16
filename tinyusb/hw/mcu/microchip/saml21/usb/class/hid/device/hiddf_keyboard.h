/**
 * \file
 *
 * \brief USB Device Stack HID Keyboard Function Definition.
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

#ifndef USBDF_HID_KEYBOARD_H_
#define USBDF_HID_KEYBOARD_H_

#include "usbdc.h"
#include "usb_protocol_hid.h"

/** HID Keyboard Class Key State Type */
enum hiddf_kb_key_state { HID_KB_KEY_UP, HID_KB_KEY_DOWN };

/** Describes the USB HID Keyboard Key descriptors. */
struct hiddf_kb_key_descriptors {
	/* HID Key Value, defined in usb_protocol_hid.h */
	uint8_t key_id;
	/* Flag whether it is a modifier key */
	bool b_modifier;
	/* Key State */
	enum hiddf_kb_key_state state;
};

/**
 * \brief Initialize the USB HID Keyboard Function Driver
 * \return Operation status.
 */
int32_t hiddf_keyboard_init(void);

/**
 * \brief Deinitialize the USB HID Keyboard Function Driver
 * \return Operation status.
 */
int32_t hiddf_keyboard_deinit(void);

/**
 * \brief Check whether HID Keyboard Function is enabled
 * \return Operation status.
 * \return true HID Keyboard Function is enabled
 * \return false HID Keyboard Function is disabled
 */
bool hiddf_keyboard_is_enabled(void);

/**
 * \brief Process the HID Keyboard key state change request
 * \param keys_desc[]  keys_descriptor array for state changing
 * \param keys_count   total keys amount for state changing
 * \return Operation status.
 */
int32_t hiddf_keyboard_keys_state_change(struct hiddf_kb_key_descriptors keys_desc[], uint8_t keys_count);

/**
 * \brief Return version
 */
uint32_t hiddf_keyboard_get_version(void);

#endif /* USBDF_HID_KEYBOARD_H_ */
