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
 * \brief Structure of Calendar instance
 */
struct calendar_dev {
	/** Pointer to the hardware base */
	void *hw;
	/** Alarm match callback */
	calendar_drv_cb_alarm_t callback;
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
 * \brief Set time for calendar
 *
 * \param[in] dev The pointer to calendar device struct
 * \param[in] p_calendar_time Pointer to the time configuration
 *
 * \return ERR_NONE on success, or an error code on failure.
 */
int32_t _calendar_set_time(struct calendar_dev *const dev, struct calendar_time *const p_calendar_time);

/**
 * \brief Set date for calendar
 *
 * \param[in] dev The pointer to calendar device struct
 * \param[in] p_calendar_date Pointer to the date configuration
 *
 * \return ERR_NONE on success, or an error code on failure.
 */
int32_t _calendar_set_date(struct calendar_dev *const dev, struct calendar_date *const p_calendar_date);

/**
 * \brief Get the time for calendar HAL instance and hardware
 *  Retrieve the time from calendar instance.
 *
 * \param[in] dev The pointer to calendar device struct
 * \param[in] date_time Pointer to value that will be filled with current time
 *
 * \return Return current counter value
 */
uint32_t _calendar_get_date_time(struct calendar_dev *const dev, struct calendar_date_time *const date_time);

/**
 * \brief Set compare value for calendar
 *
 * \param[in] dev The pointer to calendar device struct
 * \param[in] alarm Pointer to the configuration
 *
 * \return ERR_NONE on success, or an error code on failure.
 */
int32_t _calendar_set_alarm(struct calendar_dev *const dev, struct _calendar_alarm *const alarm);

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

#ifdef __cplusplus
}
#endif

#endif /* _HPL_RTC_H_INCLUDED */
