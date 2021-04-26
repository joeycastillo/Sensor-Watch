/**
 * \file
 *
 * \brief Generic CALENDAR functionality declaration.
 *
 * Copyright (c) 2014-2018 Microchip Technology Inc. and its subsidiaries.
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
#ifndef _HPL_CALENDER_H_INCLUDED
#define _HPL_CALENDER_H_INCLUDED

#include <compiler.h>
#include <utils_list.h>
#include "hpl_irq.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Calendar structure
 *
 * The Calendar structure forward declaration.
 */
struct calendar_dev;

/**
 * \brief Available mask options for alarms.
 *
 * Available mask options for alarms.
 */
enum calendar_alarm_option {
	/** Alarm disabled. */
	CALENDAR_ALARM_MATCH_DISABLED = 0,
	/** Alarm match on second. */
	CALENDAR_ALARM_MATCH_SEC,
	/** Alarm match on second and minute. */
	CALENDAR_ALARM_MATCH_MIN,
	/** Alarm match on second, minute, and hour. */
	CALENDAR_ALARM_MATCH_HOUR,
	/** Alarm match on second, minute, hour, and day. */
	CALENDAR_ALARM_MATCH_DAY,
	/** Alarm match on second, minute, hour, day, and month. */
	CALENDAR_ALARM_MATCH_MONTH,
	/** Alarm match on second, minute, hour, day, month and year. */
	CALENDAR_ALARM_MATCH_YEAR
};

/**
 * \brief Available mode for alarms.
 */
enum calendar_alarm_mode { ONESHOT = 1, REPEAT };
/**
 * \brief Prototype of callback on alarm match
 */
typedef void (*calendar_drv_cb_alarm_t)(struct calendar_dev *const dev);

/**
 * \brief Prototype of callback on tamper detect
 */
typedef void (*tamper_drv_cb_t)(struct calendar_dev *const dev);

/**
 * \brief Structure of Calendar instance
 */
struct calendar_dev {
	/** Pointer to the hardware base */
	void *hw;
	/** Alarm match callback */
	calendar_drv_cb_alarm_t callback;
	/** Tamper callback */
	tamper_drv_cb_t callback_tamper;
	/** IRQ struct */
	struct _irq_descriptor irq;
};
/**
 * \brief Time struct for calendar
 */
struct calendar_time {
	/*range from 0 to 59*/
	uint8_t sec;
	/*range from 0 to 59*/
	uint8_t min;
	/*range from 0 to 23*/
	uint8_t hour;
};

/**
 * \brief Time struct for calendar
 */
struct calendar_date {
	/*range from 1 to 28/29/30/31*/
	uint8_t day;
	/*range from 1 to 12*/
	uint8_t month;
	/*absolute year>= 1970(such as 2000)*/
	uint16_t year;
};

/** \brief Calendar driver struct
 *
 */
struct calendar_descriptor {
	struct calendar_dev    device;
	struct list_descriptor alarms;
	/*base date/time = base_year/1/1/0/0/0(year/month/day/hour/min/sec)*/
	uint32_t base_year;
	uint8_t  flags;
};

/** \brief Date&Time struct for calendar
 */
struct calendar_date_time {
	struct calendar_time time;
	struct calendar_date date;
};

/** \brief struct for alarm time
 */
struct _calendar_alarm {
	struct calendar_date_time  datetime;
	uint32_t                   timestamp;
	enum calendar_alarm_option option;
	enum calendar_alarm_mode   mode;
};

/** \enum for tamper detection mode
 */
enum tamper_detection_mode { TAMPER_MODE_OFF = 0U, TAMPER_MODE_WAKE, TAMPER_MODE_CAPTURE, TAMPER_MODE_ACTL };

/** \enum for tamper detection mode
 */
enum tamper_id { TAMPID0 = 0U, TAMPID1, TAMPID2, TAMPID3, TAMPID4 };
/**
 * \brief Initialize Calendar instance
 *
 * \param[in] dev The pointer to calendar device struct
 *
 * \return ERR_NONE on success, or an error code on failure.
 */
int32_t _calendar_init(struct calendar_dev *const dev);

/**
 * \brief Deinitialize Calendar instance
 *
 * \param[in] dev The pointer to calendar device struct
 *
 * \return ERR_NONE on success, or an error code on failure.
 */
int32_t _calendar_deinit(struct calendar_dev *const dev);

/**
 * \brief Enable Calendar instance
 *
 * \param[in] dev The pointer to calendar device struct
 *
 * \return ERR_NONE on success, or an error code on failure.
 */
int32_t _calendar_enable(struct calendar_dev *const dev);

/**
 * \brief Disable Calendar instance
 *
 * \param[in] dev The pointer to calendar device struct
 *
 * \return ERR_NONE on success, or an error code on failure.
 */
int32_t _calendar_disable(struct calendar_dev *const dev);
/**
 * \brief Set counter for calendar
 *
 * \param[in] dev The pointer to calendar device struct
 * \param[in] counter The counter for set
 *
 * \return ERR_NONE on success, or an error code on failure.
 */
int32_t _calendar_set_counter(struct calendar_dev *const dev, const uint32_t counter);

/**
 * \brief Get counter for calendar
 *
 * \param[in] dev The pointer to calendar device struct
 *
 * \return return current counter value
 */
uint32_t _calendar_get_counter(struct calendar_dev *const dev);

/**
 * \brief Set compare value for calendar
 *
 * \param[in] dev The pointer to calendar device struct
 * \param[in] comp The compare value for set
 *
 * \return ERR_NONE on success, or an error code on failure.
 */
int32_t _calendar_set_comp(struct calendar_dev *const dev, const uint32_t comp);

/**
 * \brief Get compare value for calendar
 *
 * \param[in] dev The pointer to calendar device struct
 *
 * \return return current compare value
 */
uint32_t _calendar_get_comp(struct calendar_dev *const dev);

/**
 * \brief Register callback for calendar alarm
 *
 * \param[in] dev The pointer to calendar device struct
 * \param[in] callback The pointer to callback function
 *
 * \return ERR_NONE on success, or an error code on failure.
 */
int32_t _calendar_register_callback(struct calendar_dev *const dev, calendar_drv_cb_alarm_t callback);

/**
 * \brief Set calendar IRQ
 *
 * \param[in] dev The pointer to calendar device struct
 */
void _calendar_set_irq(struct calendar_dev *const dev);

/**
 * \brief Register callback for tamper detection
 *
 * \param[in] dev The pointer to calendar device struct
 * \param[in] callback The pointer to callback function
 *
 * \return ERR_NONE on success, or an error code on failure.
 */
int32_t _tamper_register_callback(struct calendar_dev *const dev, tamper_drv_cb_t callback_tamper);

/**
 * \brief Find tamper is detected on specified pin
 *
 * \param[in] dev The pointer to calendar device struct
 * \param[in] enum Tamper ID number
 *
 * \return true on detection success and false on failure.
 */
bool _is_tamper_detected(struct calendar_dev *const dev, enum tamper_id tamper_id_pin);

/**
 * \brief brief Clear the Tamper ID flag
 *
 * \param[in] dev The pointer to calendar device struct
 * \param[in] enum Tamper ID number
 *
 * \return ERR_NONE
 */
int32_t _tamper_clear_tampid_flag(struct calendar_dev *const dev, enum tamper_id tamper_id_pin);

/**
 * \brief Enable Debounce Asynchronous Feature
 *
 * \param[in] dev The pointer to calendar device struct
 *
 * \return ERR_NONE on success, or an error code on failure.
 */
int32_t _tamper_enable_debounce_asynchronous(struct calendar_dev *const dev);

/**
 * \brief Disable Tamper Debounce Asynchronous Feature
 *
 * \param[in] dev The pointer to calendar device struct
 *
 * \return ERR_NONE on success, or an error code on failure.
 */
int32_t _tamper_disable_debounce_asynchronous(struct calendar_dev *const dev);

/**
 * \brief Enable Tamper Debounce Majority Feature
 *
 * \param[in] dev The pointer to calendar device struct
 *
 * \return ERR_NONE on success, or an error code on failure.
 */
int32_t _tamper_enable_debounce_majority(struct calendar_dev *const dev);

/**
 * \brief Enable Tamper Debounce Majority Feature
 *
 * \param[in] dev The pointer to calendar device struct
 *
 * \return ERR_NONE on success, or an error code on failure.
 */
int32_t _tamper_disable_debounce_majority(struct calendar_dev *const dev);

#ifdef __cplusplus
}
#endif

#endif /* _HPL_RTC_H_INCLUDED */
