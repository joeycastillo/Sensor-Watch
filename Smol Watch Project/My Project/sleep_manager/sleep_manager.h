/**
 * \file
 *
 * \brief Sleep manager declaration.
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

#ifndef _SLEEP_MANAGER_H_INCLUDED
#define _SLEEP_MANAGER_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <utils_event.h>

/**
 * \brief Wake up sources.
 */
enum sleepmgr_wakeup_source { SM_WAKEUP_SOURCE_EXT_IRQ, SM_WAKEUP_SOURCE_IRQ };

struct sleepmgr_ready_to_sleep;

/**
 * \brief The type of a callback called before going to sleep
 */
typedef void (*sleepmgr_ready_to_sleep_callback_t)(struct sleepmgr_ready_to_sleep *const ready);

/**
 * \brief The type of a callback called right before going to sleep
 */
typedef void (*sleepmgr_prepare_to_sleep_callback_t)(const uint8_t mode);

/**
 * \brief The type of a callback called after waking up
 */
typedef void (*sleepmgr_wake_up_callback_t)(const enum sleepmgr_wakeup_source source);

/**
 * \brief The is ready to sleep callback structure
 */
struct sleepmgr_ready_to_sleep_cb {
	struct is_ready_to_sleep_service {
		struct list_element elem; /*! The pointer to next callback */
	} service;                    /*! For internal use only */
	/*! The callback to be called to ask modules about thier active status */
	sleepmgr_ready_to_sleep_callback_t cb;
};

/**
 * \brief The prepare to sleep callback structure
 */
struct sleepmgr_prepare_to_sleep_cb {
	struct prepare_to_sleep_service {
		struct list_element elem; /*! The pointer to next callback */
	} service;                    /*! For internal use only */
	/*! The callback to be called right before going to sleep */
	sleepmgr_prepare_to_sleep_callback_t cb;
};

/**
 * \brief The wake up callback structure
 */
struct sleepmgr_wake_up_cb {
	struct wake_up_service {
		struct list_element elem; /*! The pointer to next callback */
	} service;                    /*! For internal use only */
	/*! The callback to be called after waking up */
	sleepmgr_wake_up_callback_t cb;
};

/**
 * \brief The structure used in ready to sleep callback
 */
struct sleepmgr_ready_to_sleep {
	bool    ready; /*! Ready to sleep flag */
	uint8_t mode;  /*! The sleep mode to be used */
};

/**
 * \brief Initialize sleep manager
 */
void sleepmgr_init(void);

/**
 * \brief Register is ready to sleep callback
 *
 * \param[in] cb Callback to register
 */
void sleepmgr_register_ready_to_sleep_callback(struct sleepmgr_ready_to_sleep_cb *const cb);

/**
 * \brief Register wake up callback
 *
 * \param[in] cb Callback to register
 */
void sleepmgr_register_prepare_to_sleep_callback(struct sleepmgr_prepare_to_sleep_cb *const cb);

/**
 * \brief Register wake up callback
 *
 * \param[in] cb Callback to register
 */
void sleepmgr_register_wake_up_callback(struct sleepmgr_wake_up_cb *const cb);

/**
 * \brief Go to sleep
 *
 * \param[in] mode Sleep mode to use
 */
void sleepmgr_sleep(const uint8_t mode);

/**
 * \brief Send wake-up notification
 */
void sleepmgr_wakeup(const enum sleepmgr_wakeup_source source);

/**
 * \brief Check if device is ready to sleep
 *
 * \param[in] mode Sleep mode to use
 *
 * \return True if device is ready to sleep, false otherwise
 */
bool sleepmgr_is_ready_to_sleep(const uint8_t mode);

#ifdef __cplusplus
}
#endif

#endif /* _SLEEP_MANAGER_H_INCLUDED */
