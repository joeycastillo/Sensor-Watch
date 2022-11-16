/**
 * \file
 *
 * \brief SAM LOCKBIT
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
 */

#ifdef _SAMG55_LOCKBIT_COMPONENT_
#ifndef _HRI_LOCKBIT_G55_H_INCLUDED_
#define _HRI_LOCKBIT_G55_H_INCLUDED_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <hal_atomic.h>

#if defined(ENABLE_LOCKBIT_CRITICAL_SECTIONS)
#define LOCKBIT_CRITICAL_SECTION_ENTER() CRITICAL_SECTION_ENTER()
#define LOCKBIT_CRITICAL_SECTION_LEAVE() CRITICAL_SECTION_LEAVE()
#else
#define LOCKBIT_CRITICAL_SECTION_ENTER()
#define LOCKBIT_CRITICAL_SECTION_LEAVE()
#endif

typedef uint32_t hri_lockbit_word0_reg_t;
typedef uint32_t hri_lockbit_word1_reg_t;

static inline void hri_lockbit_set_WORD0_LOCK_REGION_0_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 |= LOCKBIT_WORD0_LOCK_REGION_0;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD0_LOCK_REGION_0_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD0;
	tmp = (tmp & LOCKBIT_WORD0_LOCK_REGION_0) >> 0;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD0_LOCK_REGION_0_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD0;
	tmp &= ~LOCKBIT_WORD0_LOCK_REGION_0;
	tmp |= value << 0;
	((Lockbit *)hw)->WORD0 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD0_LOCK_REGION_0_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 &= ~LOCKBIT_WORD0_LOCK_REGION_0;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD0_LOCK_REGION_0_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 ^= LOCKBIT_WORD0_LOCK_REGION_0;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD0_LOCK_REGION_1_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 |= LOCKBIT_WORD0_LOCK_REGION_1;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD0_LOCK_REGION_1_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD0;
	tmp = (tmp & LOCKBIT_WORD0_LOCK_REGION_1) >> 1;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD0_LOCK_REGION_1_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD0;
	tmp &= ~LOCKBIT_WORD0_LOCK_REGION_1;
	tmp |= value << 1;
	((Lockbit *)hw)->WORD0 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD0_LOCK_REGION_1_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 &= ~LOCKBIT_WORD0_LOCK_REGION_1;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD0_LOCK_REGION_1_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 ^= LOCKBIT_WORD0_LOCK_REGION_1;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD0_LOCK_REGION_2_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 |= LOCKBIT_WORD0_LOCK_REGION_2;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD0_LOCK_REGION_2_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD0;
	tmp = (tmp & LOCKBIT_WORD0_LOCK_REGION_2) >> 2;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD0_LOCK_REGION_2_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD0;
	tmp &= ~LOCKBIT_WORD0_LOCK_REGION_2;
	tmp |= value << 2;
	((Lockbit *)hw)->WORD0 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD0_LOCK_REGION_2_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 &= ~LOCKBIT_WORD0_LOCK_REGION_2;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD0_LOCK_REGION_2_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 ^= LOCKBIT_WORD0_LOCK_REGION_2;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD0_LOCK_REGION_3_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 |= LOCKBIT_WORD0_LOCK_REGION_3;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD0_LOCK_REGION_3_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD0;
	tmp = (tmp & LOCKBIT_WORD0_LOCK_REGION_3) >> 3;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD0_LOCK_REGION_3_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD0;
	tmp &= ~LOCKBIT_WORD0_LOCK_REGION_3;
	tmp |= value << 3;
	((Lockbit *)hw)->WORD0 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD0_LOCK_REGION_3_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 &= ~LOCKBIT_WORD0_LOCK_REGION_3;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD0_LOCK_REGION_3_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 ^= LOCKBIT_WORD0_LOCK_REGION_3;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD0_LOCK_REGION_4_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 |= LOCKBIT_WORD0_LOCK_REGION_4;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD0_LOCK_REGION_4_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD0;
	tmp = (tmp & LOCKBIT_WORD0_LOCK_REGION_4) >> 4;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD0_LOCK_REGION_4_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD0;
	tmp &= ~LOCKBIT_WORD0_LOCK_REGION_4;
	tmp |= value << 4;
	((Lockbit *)hw)->WORD0 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD0_LOCK_REGION_4_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 &= ~LOCKBIT_WORD0_LOCK_REGION_4;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD0_LOCK_REGION_4_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 ^= LOCKBIT_WORD0_LOCK_REGION_4;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD0_LOCK_REGION_5_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 |= LOCKBIT_WORD0_LOCK_REGION_5;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD0_LOCK_REGION_5_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD0;
	tmp = (tmp & LOCKBIT_WORD0_LOCK_REGION_5) >> 5;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD0_LOCK_REGION_5_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD0;
	tmp &= ~LOCKBIT_WORD0_LOCK_REGION_5;
	tmp |= value << 5;
	((Lockbit *)hw)->WORD0 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD0_LOCK_REGION_5_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 &= ~LOCKBIT_WORD0_LOCK_REGION_5;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD0_LOCK_REGION_5_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 ^= LOCKBIT_WORD0_LOCK_REGION_5;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD0_LOCK_REGION_6_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 |= LOCKBIT_WORD0_LOCK_REGION_6;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD0_LOCK_REGION_6_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD0;
	tmp = (tmp & LOCKBIT_WORD0_LOCK_REGION_6) >> 6;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD0_LOCK_REGION_6_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD0;
	tmp &= ~LOCKBIT_WORD0_LOCK_REGION_6;
	tmp |= value << 6;
	((Lockbit *)hw)->WORD0 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD0_LOCK_REGION_6_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 &= ~LOCKBIT_WORD0_LOCK_REGION_6;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD0_LOCK_REGION_6_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 ^= LOCKBIT_WORD0_LOCK_REGION_6;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD0_LOCK_REGION_7_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 |= LOCKBIT_WORD0_LOCK_REGION_7;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD0_LOCK_REGION_7_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD0;
	tmp = (tmp & LOCKBIT_WORD0_LOCK_REGION_7) >> 7;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD0_LOCK_REGION_7_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD0;
	tmp &= ~LOCKBIT_WORD0_LOCK_REGION_7;
	tmp |= value << 7;
	((Lockbit *)hw)->WORD0 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD0_LOCK_REGION_7_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 &= ~LOCKBIT_WORD0_LOCK_REGION_7;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD0_LOCK_REGION_7_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 ^= LOCKBIT_WORD0_LOCK_REGION_7;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD0_LOCK_REGION_8_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 |= LOCKBIT_WORD0_LOCK_REGION_8;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD0_LOCK_REGION_8_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD0;
	tmp = (tmp & LOCKBIT_WORD0_LOCK_REGION_8) >> 8;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD0_LOCK_REGION_8_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD0;
	tmp &= ~LOCKBIT_WORD0_LOCK_REGION_8;
	tmp |= value << 8;
	((Lockbit *)hw)->WORD0 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD0_LOCK_REGION_8_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 &= ~LOCKBIT_WORD0_LOCK_REGION_8;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD0_LOCK_REGION_8_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 ^= LOCKBIT_WORD0_LOCK_REGION_8;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD0_LOCK_REGION_9_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 |= LOCKBIT_WORD0_LOCK_REGION_9;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD0_LOCK_REGION_9_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD0;
	tmp = (tmp & LOCKBIT_WORD0_LOCK_REGION_9) >> 9;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD0_LOCK_REGION_9_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD0;
	tmp &= ~LOCKBIT_WORD0_LOCK_REGION_9;
	tmp |= value << 9;
	((Lockbit *)hw)->WORD0 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD0_LOCK_REGION_9_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 &= ~LOCKBIT_WORD0_LOCK_REGION_9;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD0_LOCK_REGION_9_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 ^= LOCKBIT_WORD0_LOCK_REGION_9;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD0_LOCK_REGION_10_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 |= LOCKBIT_WORD0_LOCK_REGION_10;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD0_LOCK_REGION_10_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD0;
	tmp = (tmp & LOCKBIT_WORD0_LOCK_REGION_10) >> 10;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD0_LOCK_REGION_10_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD0;
	tmp &= ~LOCKBIT_WORD0_LOCK_REGION_10;
	tmp |= value << 10;
	((Lockbit *)hw)->WORD0 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD0_LOCK_REGION_10_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 &= ~LOCKBIT_WORD0_LOCK_REGION_10;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD0_LOCK_REGION_10_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 ^= LOCKBIT_WORD0_LOCK_REGION_10;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD0_LOCK_REGION_11_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 |= LOCKBIT_WORD0_LOCK_REGION_11;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD0_LOCK_REGION_11_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD0;
	tmp = (tmp & LOCKBIT_WORD0_LOCK_REGION_11) >> 11;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD0_LOCK_REGION_11_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD0;
	tmp &= ~LOCKBIT_WORD0_LOCK_REGION_11;
	tmp |= value << 11;
	((Lockbit *)hw)->WORD0 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD0_LOCK_REGION_11_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 &= ~LOCKBIT_WORD0_LOCK_REGION_11;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD0_LOCK_REGION_11_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 ^= LOCKBIT_WORD0_LOCK_REGION_11;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD0_LOCK_REGION_12_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 |= LOCKBIT_WORD0_LOCK_REGION_12;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD0_LOCK_REGION_12_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD0;
	tmp = (tmp & LOCKBIT_WORD0_LOCK_REGION_12) >> 12;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD0_LOCK_REGION_12_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD0;
	tmp &= ~LOCKBIT_WORD0_LOCK_REGION_12;
	tmp |= value << 12;
	((Lockbit *)hw)->WORD0 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD0_LOCK_REGION_12_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 &= ~LOCKBIT_WORD0_LOCK_REGION_12;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD0_LOCK_REGION_12_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 ^= LOCKBIT_WORD0_LOCK_REGION_12;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD0_LOCK_REGION_13_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 |= LOCKBIT_WORD0_LOCK_REGION_13;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD0_LOCK_REGION_13_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD0;
	tmp = (tmp & LOCKBIT_WORD0_LOCK_REGION_13) >> 13;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD0_LOCK_REGION_13_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD0;
	tmp &= ~LOCKBIT_WORD0_LOCK_REGION_13;
	tmp |= value << 13;
	((Lockbit *)hw)->WORD0 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD0_LOCK_REGION_13_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 &= ~LOCKBIT_WORD0_LOCK_REGION_13;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD0_LOCK_REGION_13_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 ^= LOCKBIT_WORD0_LOCK_REGION_13;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD0_LOCK_REGION_14_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 |= LOCKBIT_WORD0_LOCK_REGION_14;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD0_LOCK_REGION_14_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD0;
	tmp = (tmp & LOCKBIT_WORD0_LOCK_REGION_14) >> 14;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD0_LOCK_REGION_14_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD0;
	tmp &= ~LOCKBIT_WORD0_LOCK_REGION_14;
	tmp |= value << 14;
	((Lockbit *)hw)->WORD0 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD0_LOCK_REGION_14_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 &= ~LOCKBIT_WORD0_LOCK_REGION_14;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD0_LOCK_REGION_14_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 ^= LOCKBIT_WORD0_LOCK_REGION_14;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD0_LOCK_REGION_15_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 |= LOCKBIT_WORD0_LOCK_REGION_15;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD0_LOCK_REGION_15_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD0;
	tmp = (tmp & LOCKBIT_WORD0_LOCK_REGION_15) >> 15;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD0_LOCK_REGION_15_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD0;
	tmp &= ~LOCKBIT_WORD0_LOCK_REGION_15;
	tmp |= value << 15;
	((Lockbit *)hw)->WORD0 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD0_LOCK_REGION_15_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 &= ~LOCKBIT_WORD0_LOCK_REGION_15;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD0_LOCK_REGION_15_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 ^= LOCKBIT_WORD0_LOCK_REGION_15;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD0_LOCK_REGION_16_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 |= LOCKBIT_WORD0_LOCK_REGION_16;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD0_LOCK_REGION_16_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD0;
	tmp = (tmp & LOCKBIT_WORD0_LOCK_REGION_16) >> 16;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD0_LOCK_REGION_16_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD0;
	tmp &= ~LOCKBIT_WORD0_LOCK_REGION_16;
	tmp |= value << 16;
	((Lockbit *)hw)->WORD0 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD0_LOCK_REGION_16_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 &= ~LOCKBIT_WORD0_LOCK_REGION_16;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD0_LOCK_REGION_16_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 ^= LOCKBIT_WORD0_LOCK_REGION_16;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD0_LOCK_REGION_17_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 |= LOCKBIT_WORD0_LOCK_REGION_17;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD0_LOCK_REGION_17_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD0;
	tmp = (tmp & LOCKBIT_WORD0_LOCK_REGION_17) >> 17;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD0_LOCK_REGION_17_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD0;
	tmp &= ~LOCKBIT_WORD0_LOCK_REGION_17;
	tmp |= value << 17;
	((Lockbit *)hw)->WORD0 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD0_LOCK_REGION_17_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 &= ~LOCKBIT_WORD0_LOCK_REGION_17;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD0_LOCK_REGION_17_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 ^= LOCKBIT_WORD0_LOCK_REGION_17;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD0_LOCK_REGION_18_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 |= LOCKBIT_WORD0_LOCK_REGION_18;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD0_LOCK_REGION_18_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD0;
	tmp = (tmp & LOCKBIT_WORD0_LOCK_REGION_18) >> 18;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD0_LOCK_REGION_18_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD0;
	tmp &= ~LOCKBIT_WORD0_LOCK_REGION_18;
	tmp |= value << 18;
	((Lockbit *)hw)->WORD0 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD0_LOCK_REGION_18_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 &= ~LOCKBIT_WORD0_LOCK_REGION_18;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD0_LOCK_REGION_18_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 ^= LOCKBIT_WORD0_LOCK_REGION_18;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD0_LOCK_REGION_19_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 |= LOCKBIT_WORD0_LOCK_REGION_19;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD0_LOCK_REGION_19_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD0;
	tmp = (tmp & LOCKBIT_WORD0_LOCK_REGION_19) >> 19;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD0_LOCK_REGION_19_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD0;
	tmp &= ~LOCKBIT_WORD0_LOCK_REGION_19;
	tmp |= value << 19;
	((Lockbit *)hw)->WORD0 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD0_LOCK_REGION_19_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 &= ~LOCKBIT_WORD0_LOCK_REGION_19;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD0_LOCK_REGION_19_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 ^= LOCKBIT_WORD0_LOCK_REGION_19;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD0_LOCK_REGION_20_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 |= LOCKBIT_WORD0_LOCK_REGION_20;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD0_LOCK_REGION_20_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD0;
	tmp = (tmp & LOCKBIT_WORD0_LOCK_REGION_20) >> 20;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD0_LOCK_REGION_20_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD0;
	tmp &= ~LOCKBIT_WORD0_LOCK_REGION_20;
	tmp |= value << 20;
	((Lockbit *)hw)->WORD0 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD0_LOCK_REGION_20_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 &= ~LOCKBIT_WORD0_LOCK_REGION_20;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD0_LOCK_REGION_20_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 ^= LOCKBIT_WORD0_LOCK_REGION_20;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD0_LOCK_REGION_21_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 |= LOCKBIT_WORD0_LOCK_REGION_21;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD0_LOCK_REGION_21_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD0;
	tmp = (tmp & LOCKBIT_WORD0_LOCK_REGION_21) >> 21;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD0_LOCK_REGION_21_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD0;
	tmp &= ~LOCKBIT_WORD0_LOCK_REGION_21;
	tmp |= value << 21;
	((Lockbit *)hw)->WORD0 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD0_LOCK_REGION_21_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 &= ~LOCKBIT_WORD0_LOCK_REGION_21;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD0_LOCK_REGION_21_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 ^= LOCKBIT_WORD0_LOCK_REGION_21;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD0_LOCK_REGION_22_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 |= LOCKBIT_WORD0_LOCK_REGION_22;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD0_LOCK_REGION_22_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD0;
	tmp = (tmp & LOCKBIT_WORD0_LOCK_REGION_22) >> 22;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD0_LOCK_REGION_22_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD0;
	tmp &= ~LOCKBIT_WORD0_LOCK_REGION_22;
	tmp |= value << 22;
	((Lockbit *)hw)->WORD0 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD0_LOCK_REGION_22_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 &= ~LOCKBIT_WORD0_LOCK_REGION_22;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD0_LOCK_REGION_22_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 ^= LOCKBIT_WORD0_LOCK_REGION_22;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD0_LOCK_REGION_23_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 |= LOCKBIT_WORD0_LOCK_REGION_23;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD0_LOCK_REGION_23_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD0;
	tmp = (tmp & LOCKBIT_WORD0_LOCK_REGION_23) >> 23;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD0_LOCK_REGION_23_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD0;
	tmp &= ~LOCKBIT_WORD0_LOCK_REGION_23;
	tmp |= value << 23;
	((Lockbit *)hw)->WORD0 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD0_LOCK_REGION_23_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 &= ~LOCKBIT_WORD0_LOCK_REGION_23;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD0_LOCK_REGION_23_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 ^= LOCKBIT_WORD0_LOCK_REGION_23;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD0_LOCK_REGION_24_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 |= LOCKBIT_WORD0_LOCK_REGION_24;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD0_LOCK_REGION_24_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD0;
	tmp = (tmp & LOCKBIT_WORD0_LOCK_REGION_24) >> 24;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD0_LOCK_REGION_24_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD0;
	tmp &= ~LOCKBIT_WORD0_LOCK_REGION_24;
	tmp |= value << 24;
	((Lockbit *)hw)->WORD0 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD0_LOCK_REGION_24_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 &= ~LOCKBIT_WORD0_LOCK_REGION_24;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD0_LOCK_REGION_24_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 ^= LOCKBIT_WORD0_LOCK_REGION_24;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD0_LOCK_REGION_25_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 |= LOCKBIT_WORD0_LOCK_REGION_25;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD0_LOCK_REGION_25_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD0;
	tmp = (tmp & LOCKBIT_WORD0_LOCK_REGION_25) >> 25;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD0_LOCK_REGION_25_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD0;
	tmp &= ~LOCKBIT_WORD0_LOCK_REGION_25;
	tmp |= value << 25;
	((Lockbit *)hw)->WORD0 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD0_LOCK_REGION_25_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 &= ~LOCKBIT_WORD0_LOCK_REGION_25;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD0_LOCK_REGION_25_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 ^= LOCKBIT_WORD0_LOCK_REGION_25;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD0_LOCK_REGION_26_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 |= LOCKBIT_WORD0_LOCK_REGION_26;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD0_LOCK_REGION_26_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD0;
	tmp = (tmp & LOCKBIT_WORD0_LOCK_REGION_26) >> 26;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD0_LOCK_REGION_26_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD0;
	tmp &= ~LOCKBIT_WORD0_LOCK_REGION_26;
	tmp |= value << 26;
	((Lockbit *)hw)->WORD0 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD0_LOCK_REGION_26_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 &= ~LOCKBIT_WORD0_LOCK_REGION_26;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD0_LOCK_REGION_26_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 ^= LOCKBIT_WORD0_LOCK_REGION_26;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD0_LOCK_REGION_27_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 |= LOCKBIT_WORD0_LOCK_REGION_27;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD0_LOCK_REGION_27_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD0;
	tmp = (tmp & LOCKBIT_WORD0_LOCK_REGION_27) >> 27;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD0_LOCK_REGION_27_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD0;
	tmp &= ~LOCKBIT_WORD0_LOCK_REGION_27;
	tmp |= value << 27;
	((Lockbit *)hw)->WORD0 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD0_LOCK_REGION_27_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 &= ~LOCKBIT_WORD0_LOCK_REGION_27;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD0_LOCK_REGION_27_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 ^= LOCKBIT_WORD0_LOCK_REGION_27;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD0_LOCK_REGION_28_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 |= LOCKBIT_WORD0_LOCK_REGION_28;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD0_LOCK_REGION_28_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD0;
	tmp = (tmp & LOCKBIT_WORD0_LOCK_REGION_28) >> 28;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD0_LOCK_REGION_28_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD0;
	tmp &= ~LOCKBIT_WORD0_LOCK_REGION_28;
	tmp |= value << 28;
	((Lockbit *)hw)->WORD0 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD0_LOCK_REGION_28_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 &= ~LOCKBIT_WORD0_LOCK_REGION_28;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD0_LOCK_REGION_28_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 ^= LOCKBIT_WORD0_LOCK_REGION_28;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD0_LOCK_REGION_29_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 |= LOCKBIT_WORD0_LOCK_REGION_29;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD0_LOCK_REGION_29_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD0;
	tmp = (tmp & LOCKBIT_WORD0_LOCK_REGION_29) >> 29;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD0_LOCK_REGION_29_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD0;
	tmp &= ~LOCKBIT_WORD0_LOCK_REGION_29;
	tmp |= value << 29;
	((Lockbit *)hw)->WORD0 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD0_LOCK_REGION_29_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 &= ~LOCKBIT_WORD0_LOCK_REGION_29;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD0_LOCK_REGION_29_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 ^= LOCKBIT_WORD0_LOCK_REGION_29;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD0_LOCK_REGION_30_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 |= LOCKBIT_WORD0_LOCK_REGION_30;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD0_LOCK_REGION_30_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD0;
	tmp = (tmp & LOCKBIT_WORD0_LOCK_REGION_30) >> 30;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD0_LOCK_REGION_30_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD0;
	tmp &= ~LOCKBIT_WORD0_LOCK_REGION_30;
	tmp |= value << 30;
	((Lockbit *)hw)->WORD0 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD0_LOCK_REGION_30_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 &= ~LOCKBIT_WORD0_LOCK_REGION_30;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD0_LOCK_REGION_30_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 ^= LOCKBIT_WORD0_LOCK_REGION_30;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD0_LOCK_REGION_31_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 |= LOCKBIT_WORD0_LOCK_REGION_31;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD0_LOCK_REGION_31_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD0;
	tmp = (tmp & LOCKBIT_WORD0_LOCK_REGION_31) >> 31;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD0_LOCK_REGION_31_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD0;
	tmp &= ~LOCKBIT_WORD0_LOCK_REGION_31;
	tmp |= value << 31;
	((Lockbit *)hw)->WORD0 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD0_LOCK_REGION_31_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 &= ~LOCKBIT_WORD0_LOCK_REGION_31;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD0_LOCK_REGION_31_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 ^= LOCKBIT_WORD0_LOCK_REGION_31;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD0_reg(const void *const hw, hri_lockbit_word0_reg_t mask)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 |= mask;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline hri_lockbit_word0_reg_t hri_lockbit_get_WORD0_reg(const void *const hw, hri_lockbit_word0_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD0;
	tmp &= mask;
	return tmp;
}

static inline void hri_lockbit_write_WORD0_reg(const void *const hw, hri_lockbit_word0_reg_t data)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 = data;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD0_reg(const void *const hw, hri_lockbit_word0_reg_t mask)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 &= ~mask;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD0_reg(const void *const hw, hri_lockbit_word0_reg_t mask)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD0 ^= mask;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline hri_lockbit_word0_reg_t hri_lockbit_read_WORD0_reg(const void *const hw)
{
	return ((Lockbit *)hw)->WORD0;
}

static inline void hri_lockbit_set_WORD1_LOCK_REGION_32_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 |= LOCKBIT_WORD1_LOCK_REGION_32;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD1_LOCK_REGION_32_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD1;
	tmp = (tmp & LOCKBIT_WORD1_LOCK_REGION_32) >> 0;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD1_LOCK_REGION_32_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD1;
	tmp &= ~LOCKBIT_WORD1_LOCK_REGION_32;
	tmp |= value << 0;
	((Lockbit *)hw)->WORD1 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD1_LOCK_REGION_32_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 &= ~LOCKBIT_WORD1_LOCK_REGION_32;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD1_LOCK_REGION_32_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 ^= LOCKBIT_WORD1_LOCK_REGION_32;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD1_LOCK_REGION_33_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 |= LOCKBIT_WORD1_LOCK_REGION_33;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD1_LOCK_REGION_33_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD1;
	tmp = (tmp & LOCKBIT_WORD1_LOCK_REGION_33) >> 1;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD1_LOCK_REGION_33_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD1;
	tmp &= ~LOCKBIT_WORD1_LOCK_REGION_33;
	tmp |= value << 1;
	((Lockbit *)hw)->WORD1 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD1_LOCK_REGION_33_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 &= ~LOCKBIT_WORD1_LOCK_REGION_33;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD1_LOCK_REGION_33_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 ^= LOCKBIT_WORD1_LOCK_REGION_33;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD1_LOCK_REGION_34_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 |= LOCKBIT_WORD1_LOCK_REGION_34;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD1_LOCK_REGION_34_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD1;
	tmp = (tmp & LOCKBIT_WORD1_LOCK_REGION_34) >> 2;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD1_LOCK_REGION_34_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD1;
	tmp &= ~LOCKBIT_WORD1_LOCK_REGION_34;
	tmp |= value << 2;
	((Lockbit *)hw)->WORD1 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD1_LOCK_REGION_34_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 &= ~LOCKBIT_WORD1_LOCK_REGION_34;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD1_LOCK_REGION_34_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 ^= LOCKBIT_WORD1_LOCK_REGION_34;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD1_LOCK_REGION_35_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 |= LOCKBIT_WORD1_LOCK_REGION_35;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD1_LOCK_REGION_35_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD1;
	tmp = (tmp & LOCKBIT_WORD1_LOCK_REGION_35) >> 3;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD1_LOCK_REGION_35_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD1;
	tmp &= ~LOCKBIT_WORD1_LOCK_REGION_35;
	tmp |= value << 3;
	((Lockbit *)hw)->WORD1 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD1_LOCK_REGION_35_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 &= ~LOCKBIT_WORD1_LOCK_REGION_35;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD1_LOCK_REGION_35_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 ^= LOCKBIT_WORD1_LOCK_REGION_35;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD1_LOCK_REGION_36_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 |= LOCKBIT_WORD1_LOCK_REGION_36;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD1_LOCK_REGION_36_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD1;
	tmp = (tmp & LOCKBIT_WORD1_LOCK_REGION_36) >> 4;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD1_LOCK_REGION_36_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD1;
	tmp &= ~LOCKBIT_WORD1_LOCK_REGION_36;
	tmp |= value << 4;
	((Lockbit *)hw)->WORD1 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD1_LOCK_REGION_36_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 &= ~LOCKBIT_WORD1_LOCK_REGION_36;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD1_LOCK_REGION_36_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 ^= LOCKBIT_WORD1_LOCK_REGION_36;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD1_LOCK_REGION_37_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 |= LOCKBIT_WORD1_LOCK_REGION_37;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD1_LOCK_REGION_37_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD1;
	tmp = (tmp & LOCKBIT_WORD1_LOCK_REGION_37) >> 5;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD1_LOCK_REGION_37_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD1;
	tmp &= ~LOCKBIT_WORD1_LOCK_REGION_37;
	tmp |= value << 5;
	((Lockbit *)hw)->WORD1 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD1_LOCK_REGION_37_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 &= ~LOCKBIT_WORD1_LOCK_REGION_37;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD1_LOCK_REGION_37_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 ^= LOCKBIT_WORD1_LOCK_REGION_37;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD1_LOCK_REGION_38_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 |= LOCKBIT_WORD1_LOCK_REGION_38;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD1_LOCK_REGION_38_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD1;
	tmp = (tmp & LOCKBIT_WORD1_LOCK_REGION_38) >> 6;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD1_LOCK_REGION_38_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD1;
	tmp &= ~LOCKBIT_WORD1_LOCK_REGION_38;
	tmp |= value << 6;
	((Lockbit *)hw)->WORD1 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD1_LOCK_REGION_38_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 &= ~LOCKBIT_WORD1_LOCK_REGION_38;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD1_LOCK_REGION_38_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 ^= LOCKBIT_WORD1_LOCK_REGION_38;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD1_LOCK_REGION_39_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 |= LOCKBIT_WORD1_LOCK_REGION_39;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD1_LOCK_REGION_39_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD1;
	tmp = (tmp & LOCKBIT_WORD1_LOCK_REGION_39) >> 7;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD1_LOCK_REGION_39_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD1;
	tmp &= ~LOCKBIT_WORD1_LOCK_REGION_39;
	tmp |= value << 7;
	((Lockbit *)hw)->WORD1 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD1_LOCK_REGION_39_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 &= ~LOCKBIT_WORD1_LOCK_REGION_39;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD1_LOCK_REGION_39_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 ^= LOCKBIT_WORD1_LOCK_REGION_39;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD1_LOCK_REGION_40_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 |= LOCKBIT_WORD1_LOCK_REGION_40;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD1_LOCK_REGION_40_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD1;
	tmp = (tmp & LOCKBIT_WORD1_LOCK_REGION_40) >> 8;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD1_LOCK_REGION_40_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD1;
	tmp &= ~LOCKBIT_WORD1_LOCK_REGION_40;
	tmp |= value << 8;
	((Lockbit *)hw)->WORD1 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD1_LOCK_REGION_40_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 &= ~LOCKBIT_WORD1_LOCK_REGION_40;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD1_LOCK_REGION_40_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 ^= LOCKBIT_WORD1_LOCK_REGION_40;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD1_LOCK_REGION_41_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 |= LOCKBIT_WORD1_LOCK_REGION_41;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD1_LOCK_REGION_41_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD1;
	tmp = (tmp & LOCKBIT_WORD1_LOCK_REGION_41) >> 9;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD1_LOCK_REGION_41_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD1;
	tmp &= ~LOCKBIT_WORD1_LOCK_REGION_41;
	tmp |= value << 9;
	((Lockbit *)hw)->WORD1 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD1_LOCK_REGION_41_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 &= ~LOCKBIT_WORD1_LOCK_REGION_41;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD1_LOCK_REGION_41_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 ^= LOCKBIT_WORD1_LOCK_REGION_41;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD1_LOCK_REGION_42_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 |= LOCKBIT_WORD1_LOCK_REGION_42;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD1_LOCK_REGION_42_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD1;
	tmp = (tmp & LOCKBIT_WORD1_LOCK_REGION_42) >> 10;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD1_LOCK_REGION_42_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD1;
	tmp &= ~LOCKBIT_WORD1_LOCK_REGION_42;
	tmp |= value << 10;
	((Lockbit *)hw)->WORD1 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD1_LOCK_REGION_42_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 &= ~LOCKBIT_WORD1_LOCK_REGION_42;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD1_LOCK_REGION_42_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 ^= LOCKBIT_WORD1_LOCK_REGION_42;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD1_LOCK_REGION_43_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 |= LOCKBIT_WORD1_LOCK_REGION_43;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD1_LOCK_REGION_43_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD1;
	tmp = (tmp & LOCKBIT_WORD1_LOCK_REGION_43) >> 11;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD1_LOCK_REGION_43_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD1;
	tmp &= ~LOCKBIT_WORD1_LOCK_REGION_43;
	tmp |= value << 11;
	((Lockbit *)hw)->WORD1 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD1_LOCK_REGION_43_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 &= ~LOCKBIT_WORD1_LOCK_REGION_43;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD1_LOCK_REGION_43_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 ^= LOCKBIT_WORD1_LOCK_REGION_43;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD1_LOCK_REGION_44_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 |= LOCKBIT_WORD1_LOCK_REGION_44;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD1_LOCK_REGION_44_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD1;
	tmp = (tmp & LOCKBIT_WORD1_LOCK_REGION_44) >> 12;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD1_LOCK_REGION_44_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD1;
	tmp &= ~LOCKBIT_WORD1_LOCK_REGION_44;
	tmp |= value << 12;
	((Lockbit *)hw)->WORD1 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD1_LOCK_REGION_44_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 &= ~LOCKBIT_WORD1_LOCK_REGION_44;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD1_LOCK_REGION_44_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 ^= LOCKBIT_WORD1_LOCK_REGION_44;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD1_LOCK_REGION_45_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 |= LOCKBIT_WORD1_LOCK_REGION_45;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD1_LOCK_REGION_45_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD1;
	tmp = (tmp & LOCKBIT_WORD1_LOCK_REGION_45) >> 13;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD1_LOCK_REGION_45_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD1;
	tmp &= ~LOCKBIT_WORD1_LOCK_REGION_45;
	tmp |= value << 13;
	((Lockbit *)hw)->WORD1 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD1_LOCK_REGION_45_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 &= ~LOCKBIT_WORD1_LOCK_REGION_45;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD1_LOCK_REGION_45_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 ^= LOCKBIT_WORD1_LOCK_REGION_45;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD1_LOCK_REGION_46_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 |= LOCKBIT_WORD1_LOCK_REGION_46;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD1_LOCK_REGION_46_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD1;
	tmp = (tmp & LOCKBIT_WORD1_LOCK_REGION_46) >> 14;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD1_LOCK_REGION_46_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD1;
	tmp &= ~LOCKBIT_WORD1_LOCK_REGION_46;
	tmp |= value << 14;
	((Lockbit *)hw)->WORD1 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD1_LOCK_REGION_46_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 &= ~LOCKBIT_WORD1_LOCK_REGION_46;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD1_LOCK_REGION_46_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 ^= LOCKBIT_WORD1_LOCK_REGION_46;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD1_LOCK_REGION_47_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 |= LOCKBIT_WORD1_LOCK_REGION_47;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD1_LOCK_REGION_47_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD1;
	tmp = (tmp & LOCKBIT_WORD1_LOCK_REGION_47) >> 15;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD1_LOCK_REGION_47_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD1;
	tmp &= ~LOCKBIT_WORD1_LOCK_REGION_47;
	tmp |= value << 15;
	((Lockbit *)hw)->WORD1 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD1_LOCK_REGION_47_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 &= ~LOCKBIT_WORD1_LOCK_REGION_47;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD1_LOCK_REGION_47_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 ^= LOCKBIT_WORD1_LOCK_REGION_47;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD1_LOCK_REGION_48_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 |= LOCKBIT_WORD1_LOCK_REGION_48;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD1_LOCK_REGION_48_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD1;
	tmp = (tmp & LOCKBIT_WORD1_LOCK_REGION_48) >> 16;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD1_LOCK_REGION_48_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD1;
	tmp &= ~LOCKBIT_WORD1_LOCK_REGION_48;
	tmp |= value << 16;
	((Lockbit *)hw)->WORD1 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD1_LOCK_REGION_48_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 &= ~LOCKBIT_WORD1_LOCK_REGION_48;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD1_LOCK_REGION_48_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 ^= LOCKBIT_WORD1_LOCK_REGION_48;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD1_LOCK_REGION_49_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 |= LOCKBIT_WORD1_LOCK_REGION_49;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD1_LOCK_REGION_49_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD1;
	tmp = (tmp & LOCKBIT_WORD1_LOCK_REGION_49) >> 17;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD1_LOCK_REGION_49_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD1;
	tmp &= ~LOCKBIT_WORD1_LOCK_REGION_49;
	tmp |= value << 17;
	((Lockbit *)hw)->WORD1 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD1_LOCK_REGION_49_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 &= ~LOCKBIT_WORD1_LOCK_REGION_49;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD1_LOCK_REGION_49_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 ^= LOCKBIT_WORD1_LOCK_REGION_49;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD1_LOCK_REGION_50_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 |= LOCKBIT_WORD1_LOCK_REGION_50;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD1_LOCK_REGION_50_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD1;
	tmp = (tmp & LOCKBIT_WORD1_LOCK_REGION_50) >> 18;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD1_LOCK_REGION_50_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD1;
	tmp &= ~LOCKBIT_WORD1_LOCK_REGION_50;
	tmp |= value << 18;
	((Lockbit *)hw)->WORD1 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD1_LOCK_REGION_50_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 &= ~LOCKBIT_WORD1_LOCK_REGION_50;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD1_LOCK_REGION_50_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 ^= LOCKBIT_WORD1_LOCK_REGION_50;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD1_LOCK_REGION_51_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 |= LOCKBIT_WORD1_LOCK_REGION_51;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD1_LOCK_REGION_51_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD1;
	tmp = (tmp & LOCKBIT_WORD1_LOCK_REGION_51) >> 19;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD1_LOCK_REGION_51_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD1;
	tmp &= ~LOCKBIT_WORD1_LOCK_REGION_51;
	tmp |= value << 19;
	((Lockbit *)hw)->WORD1 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD1_LOCK_REGION_51_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 &= ~LOCKBIT_WORD1_LOCK_REGION_51;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD1_LOCK_REGION_51_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 ^= LOCKBIT_WORD1_LOCK_REGION_51;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD1_LOCK_REGION_52_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 |= LOCKBIT_WORD1_LOCK_REGION_52;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD1_LOCK_REGION_52_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD1;
	tmp = (tmp & LOCKBIT_WORD1_LOCK_REGION_52) >> 20;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD1_LOCK_REGION_52_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD1;
	tmp &= ~LOCKBIT_WORD1_LOCK_REGION_52;
	tmp |= value << 20;
	((Lockbit *)hw)->WORD1 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD1_LOCK_REGION_52_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 &= ~LOCKBIT_WORD1_LOCK_REGION_52;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD1_LOCK_REGION_52_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 ^= LOCKBIT_WORD1_LOCK_REGION_52;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD1_LOCK_REGION_53_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 |= LOCKBIT_WORD1_LOCK_REGION_53;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD1_LOCK_REGION_53_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD1;
	tmp = (tmp & LOCKBIT_WORD1_LOCK_REGION_53) >> 21;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD1_LOCK_REGION_53_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD1;
	tmp &= ~LOCKBIT_WORD1_LOCK_REGION_53;
	tmp |= value << 21;
	((Lockbit *)hw)->WORD1 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD1_LOCK_REGION_53_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 &= ~LOCKBIT_WORD1_LOCK_REGION_53;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD1_LOCK_REGION_53_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 ^= LOCKBIT_WORD1_LOCK_REGION_53;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD1_LOCK_REGION_54_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 |= LOCKBIT_WORD1_LOCK_REGION_54;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD1_LOCK_REGION_54_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD1;
	tmp = (tmp & LOCKBIT_WORD1_LOCK_REGION_54) >> 22;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD1_LOCK_REGION_54_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD1;
	tmp &= ~LOCKBIT_WORD1_LOCK_REGION_54;
	tmp |= value << 22;
	((Lockbit *)hw)->WORD1 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD1_LOCK_REGION_54_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 &= ~LOCKBIT_WORD1_LOCK_REGION_54;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD1_LOCK_REGION_54_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 ^= LOCKBIT_WORD1_LOCK_REGION_54;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD1_LOCK_REGION_55_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 |= LOCKBIT_WORD1_LOCK_REGION_55;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD1_LOCK_REGION_55_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD1;
	tmp = (tmp & LOCKBIT_WORD1_LOCK_REGION_55) >> 23;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD1_LOCK_REGION_55_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD1;
	tmp &= ~LOCKBIT_WORD1_LOCK_REGION_55;
	tmp |= value << 23;
	((Lockbit *)hw)->WORD1 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD1_LOCK_REGION_55_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 &= ~LOCKBIT_WORD1_LOCK_REGION_55;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD1_LOCK_REGION_55_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 ^= LOCKBIT_WORD1_LOCK_REGION_55;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD1_LOCK_REGION_56_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 |= LOCKBIT_WORD1_LOCK_REGION_56;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD1_LOCK_REGION_56_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD1;
	tmp = (tmp & LOCKBIT_WORD1_LOCK_REGION_56) >> 24;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD1_LOCK_REGION_56_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD1;
	tmp &= ~LOCKBIT_WORD1_LOCK_REGION_56;
	tmp |= value << 24;
	((Lockbit *)hw)->WORD1 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD1_LOCK_REGION_56_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 &= ~LOCKBIT_WORD1_LOCK_REGION_56;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD1_LOCK_REGION_56_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 ^= LOCKBIT_WORD1_LOCK_REGION_56;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD1_LOCK_REGION_57_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 |= LOCKBIT_WORD1_LOCK_REGION_57;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD1_LOCK_REGION_57_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD1;
	tmp = (tmp & LOCKBIT_WORD1_LOCK_REGION_57) >> 25;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD1_LOCK_REGION_57_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD1;
	tmp &= ~LOCKBIT_WORD1_LOCK_REGION_57;
	tmp |= value << 25;
	((Lockbit *)hw)->WORD1 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD1_LOCK_REGION_57_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 &= ~LOCKBIT_WORD1_LOCK_REGION_57;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD1_LOCK_REGION_57_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 ^= LOCKBIT_WORD1_LOCK_REGION_57;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD1_LOCK_REGION_58_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 |= LOCKBIT_WORD1_LOCK_REGION_58;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD1_LOCK_REGION_58_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD1;
	tmp = (tmp & LOCKBIT_WORD1_LOCK_REGION_58) >> 26;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD1_LOCK_REGION_58_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD1;
	tmp &= ~LOCKBIT_WORD1_LOCK_REGION_58;
	tmp |= value << 26;
	((Lockbit *)hw)->WORD1 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD1_LOCK_REGION_58_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 &= ~LOCKBIT_WORD1_LOCK_REGION_58;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD1_LOCK_REGION_58_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 ^= LOCKBIT_WORD1_LOCK_REGION_58;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD1_LOCK_REGION_59_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 |= LOCKBIT_WORD1_LOCK_REGION_59;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD1_LOCK_REGION_59_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD1;
	tmp = (tmp & LOCKBIT_WORD1_LOCK_REGION_59) >> 27;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD1_LOCK_REGION_59_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD1;
	tmp &= ~LOCKBIT_WORD1_LOCK_REGION_59;
	tmp |= value << 27;
	((Lockbit *)hw)->WORD1 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD1_LOCK_REGION_59_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 &= ~LOCKBIT_WORD1_LOCK_REGION_59;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD1_LOCK_REGION_59_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 ^= LOCKBIT_WORD1_LOCK_REGION_59;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD1_LOCK_REGION_60_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 |= LOCKBIT_WORD1_LOCK_REGION_60;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD1_LOCK_REGION_60_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD1;
	tmp = (tmp & LOCKBIT_WORD1_LOCK_REGION_60) >> 28;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD1_LOCK_REGION_60_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD1;
	tmp &= ~LOCKBIT_WORD1_LOCK_REGION_60;
	tmp |= value << 28;
	((Lockbit *)hw)->WORD1 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD1_LOCK_REGION_60_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 &= ~LOCKBIT_WORD1_LOCK_REGION_60;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD1_LOCK_REGION_60_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 ^= LOCKBIT_WORD1_LOCK_REGION_60;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD1_LOCK_REGION_61_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 |= LOCKBIT_WORD1_LOCK_REGION_61;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD1_LOCK_REGION_61_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD1;
	tmp = (tmp & LOCKBIT_WORD1_LOCK_REGION_61) >> 29;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD1_LOCK_REGION_61_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD1;
	tmp &= ~LOCKBIT_WORD1_LOCK_REGION_61;
	tmp |= value << 29;
	((Lockbit *)hw)->WORD1 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD1_LOCK_REGION_61_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 &= ~LOCKBIT_WORD1_LOCK_REGION_61;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD1_LOCK_REGION_61_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 ^= LOCKBIT_WORD1_LOCK_REGION_61;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD1_LOCK_REGION_62_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 |= LOCKBIT_WORD1_LOCK_REGION_62;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD1_LOCK_REGION_62_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD1;
	tmp = (tmp & LOCKBIT_WORD1_LOCK_REGION_62) >> 30;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD1_LOCK_REGION_62_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD1;
	tmp &= ~LOCKBIT_WORD1_LOCK_REGION_62;
	tmp |= value << 30;
	((Lockbit *)hw)->WORD1 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD1_LOCK_REGION_62_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 &= ~LOCKBIT_WORD1_LOCK_REGION_62;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD1_LOCK_REGION_62_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 ^= LOCKBIT_WORD1_LOCK_REGION_62;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD1_LOCK_REGION_63_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 |= LOCKBIT_WORD1_LOCK_REGION_63;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_lockbit_get_WORD1_LOCK_REGION_63_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD1;
	tmp = (tmp & LOCKBIT_WORD1_LOCK_REGION_63) >> 31;
	return (bool)tmp;
}

static inline void hri_lockbit_write_WORD1_LOCK_REGION_63_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	LOCKBIT_CRITICAL_SECTION_ENTER();
	tmp = ((Lockbit *)hw)->WORD1;
	tmp &= ~LOCKBIT_WORD1_LOCK_REGION_63;
	tmp |= value << 31;
	((Lockbit *)hw)->WORD1 = tmp;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD1_LOCK_REGION_63_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 &= ~LOCKBIT_WORD1_LOCK_REGION_63;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD1_LOCK_REGION_63_bit(const void *const hw)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 ^= LOCKBIT_WORD1_LOCK_REGION_63;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_set_WORD1_reg(const void *const hw, hri_lockbit_word1_reg_t mask)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 |= mask;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline hri_lockbit_word1_reg_t hri_lockbit_get_WORD1_reg(const void *const hw, hri_lockbit_word1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Lockbit *)hw)->WORD1;
	tmp &= mask;
	return tmp;
}

static inline void hri_lockbit_write_WORD1_reg(const void *const hw, hri_lockbit_word1_reg_t data)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 = data;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_clear_WORD1_reg(const void *const hw, hri_lockbit_word1_reg_t mask)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 &= ~mask;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline void hri_lockbit_toggle_WORD1_reg(const void *const hw, hri_lockbit_word1_reg_t mask)
{
	LOCKBIT_CRITICAL_SECTION_ENTER();
	((Lockbit *)hw)->WORD1 ^= mask;
	LOCKBIT_CRITICAL_SECTION_LEAVE();
}

static inline hri_lockbit_word1_reg_t hri_lockbit_read_WORD1_reg(const void *const hw)
{
	return ((Lockbit *)hw)->WORD1;
}

#ifdef __cplusplus
}
#endif

#endif /* _HRI_LOCKBIT_G55_H_INCLUDED */
#endif /* _SAMG55_LOCKBIT_COMPONENT_ */
