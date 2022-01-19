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

#ifdef __cplusplus
extern "C" {
#endif

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

/** \brief Date&Time struct for calendar
 */
struct calendar_date_time {
	struct calendar_time time;
	struct calendar_date date;
};

#ifdef __cplusplus
}
#endif

#endif /* _HPL_RTC_H_INCLUDED */
