/**
 * \file
 *
 * \brief Generic CALENDAR functionality declaration.
 *
 * Copyright (C) 2014 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

#ifndef _HAL_CALENDER_H_INCLUDED
#define _HAL_CALENDER_H_INCLUDED

#include "hpl_calendar.h"
#include <utils_list.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \addtogroup doc_driver_hal_calendar_async
 *
 *@{
 */

/** \brief Prototype of callback on alarm match
 *  \param calendar Pointer to the HAL Calendar instance.
 */
typedef void (*calendar_cb_alarm_t)(struct calendar_descriptor *const calendar);

/** \brief Struct for alarm time
 */
struct calendar_alarm {
	struct list_element    elem;
	struct _calendar_alarm cal_alarm;
	calendar_cb_alarm_t    callback;
};

/** \brief Initialize the Calendar HAL instance and hardware
 *
 *  \param calendar Pointer to the HAL Calendar instance.
 *  \param hw       Pointer to the hardware instance.
 *  \return Operation status of init
 *  \retval 0       Completed successfully.
 */
int32_t calendar_init(struct calendar_descriptor *const calendar, const void *hw);

/** \brief Reset the Calendar HAL instance and hardware
 *
 *  Reset Calendar instance to hardware defaults.
 *
 *  \param calendar Pointer to the HAL Calendar instance.
 *  \return Operation status of reset.
 *  \retval 0       Completed successfully.
 */
int32_t calendar_deinit(struct calendar_descriptor *const calendar);

/** \brief Enable the Calendar HAL instance and hardware
 *
 *  \param calendar Pointer to the HAL Calendar instance.
 *  \return Operation status of init
 *  \retval 0       Completed successfully.
 */
int32_t calendar_enable(struct calendar_descriptor *const calendar);

/** \brief Disable the Calendar HAL instance and hardware
 *
 *  Disable Calendar instance to hardware defaults.
 *
 *  \param calendar Pointer to the HAL Calendar instance.
 *  \return Operation status of reset.
 *  \retval 0       Completed successfully.
 */
int32_t calendar_disable(struct calendar_descriptor *const calendar);

/** \brief Configure the base year for calendar HAL instance and hardware
 *
 *  \param calendar Pointer to the HAL Calendar instance.
 *  \param p_base_year The desired base year.
 *  \retval 0       Completed successfully.
 */
int32_t calendar_set_baseyear(struct calendar_descriptor *const calendar, const uint32_t p_base_year);

/** \brief Configure the time for calendar HAL instance and hardware
 *
 *  \param calendar Pointer to the HAL Calendar instance.
 *  \param p_calendar_time Pointer to the time configuration.
 *  \retval 0       Completed successfully.
 */
int32_t calendar_set_time(struct calendar_descriptor *const calendar, struct calendar_time *const p_calendar_time);

/** \brief Configure the date for calendar HAL instance and hardware
 *
 *  \param calendar Pointer to the HAL Calendar instance.
 *  \param p_calendar_date Pointer to the date configuration.
 *  \return Operation status of time set.
 *  \retval 0       Completed successfully.
 */
int32_t calendar_set_date(struct calendar_descriptor *const calendar, struct calendar_date *const p_calendar_date);

/** \brief Get the time for calendar HAL instance and hardware
 *
 *  \param calendar Pointer to the HAL Calendar instance.
 *  \param date_time Pointer to the value that will be filled with the current time.
 *  \return Operation status of time retrieve.
 *  \retval 0       Completed successfully.
 */
int32_t calendar_get_date_time(struct calendar_descriptor *const calendar, struct calendar_date_time *const date_time);

/** \brief Config the alarm time for calendar HAL instance and hardware
 *
 *  Set the alarm time to calendar instance. If the callback is NULL, remove
 *  the alarm if the alarm is already added, otherwise, ignore the alarm.
 *
 *  \param calendar Pointer to the HAL Calendar instance.
 *  \param alarm Pointer to the configuration.
 *  \param callback Pointer to the callback function.
 *  \return Operation status of alarm time set.
 *  \retval 0       Completed successfully.
 */
int32_t calendar_set_alarm(struct calendar_descriptor *const calendar, struct calendar_alarm *const alarm,
                           calendar_cb_alarm_t callback);

/** \brief Retrieve the current driver version
 *  \return Current driver version.
 */
uint32_t calendar_get_version(void);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif /* _HAL_CALENDER_H_INCLUDED */
