/**
 * \file
 *
 * \brief SAM FLEXCOM
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

#ifdef _SAMG55_FLEXCOM_COMPONENT_
#ifndef _HRI_FLEXCOM_G55_H_INCLUDED_
#define _HRI_FLEXCOM_G55_H_INCLUDED_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <hal_atomic.h>

#if defined(ENABLE_FLEXCOM_CRITICAL_SECTIONS)
#define FLEXCOM_CRITICAL_SECTION_ENTER() CRITICAL_SECTION_ENTER()
#define FLEXCOM_CRITICAL_SECTION_LEAVE() CRITICAL_SECTION_LEAVE()
#else
#define FLEXCOM_CRITICAL_SECTION_ENTER()
#define FLEXCOM_CRITICAL_SECTION_LEAVE()
#endif

typedef uint32_t hri_flexcom_mr_reg_t;
typedef uint32_t hri_flexcom_rhr_reg_t;
typedef uint32_t hri_flexcom_thr_reg_t;

static inline void hri_flexcom_set_MR_OPMODE_bf(const void *const hw, hri_flexcom_mr_reg_t mask)
{
	FLEXCOM_CRITICAL_SECTION_ENTER();
	((Flexcom *)hw)->FLEXCOM_MR |= FLEXCOM_MR_OPMODE(mask);
	FLEXCOM_CRITICAL_SECTION_LEAVE();
}

static inline hri_flexcom_mr_reg_t hri_flexcom_get_MR_OPMODE_bf(const void *const hw, hri_flexcom_mr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Flexcom *)hw)->FLEXCOM_MR;
	tmp = (tmp & FLEXCOM_MR_OPMODE(mask)) >> FLEXCOM_MR_OPMODE_Pos;
	return tmp;
}

static inline void hri_flexcom_write_MR_OPMODE_bf(const void *const hw, hri_flexcom_mr_reg_t data)
{
	uint32_t tmp;
	FLEXCOM_CRITICAL_SECTION_ENTER();
	tmp = ((Flexcom *)hw)->FLEXCOM_MR;
	tmp &= ~FLEXCOM_MR_OPMODE_Msk;
	tmp |= FLEXCOM_MR_OPMODE(data);
	((Flexcom *)hw)->FLEXCOM_MR = tmp;
	FLEXCOM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_flexcom_clear_MR_OPMODE_bf(const void *const hw, hri_flexcom_mr_reg_t mask)
{
	FLEXCOM_CRITICAL_SECTION_ENTER();
	((Flexcom *)hw)->FLEXCOM_MR &= ~FLEXCOM_MR_OPMODE(mask);
	FLEXCOM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_flexcom_toggle_MR_OPMODE_bf(const void *const hw, hri_flexcom_mr_reg_t mask)
{
	FLEXCOM_CRITICAL_SECTION_ENTER();
	((Flexcom *)hw)->FLEXCOM_MR ^= FLEXCOM_MR_OPMODE(mask);
	FLEXCOM_CRITICAL_SECTION_LEAVE();
}

static inline hri_flexcom_mr_reg_t hri_flexcom_read_MR_OPMODE_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Flexcom *)hw)->FLEXCOM_MR;
	tmp = (tmp & FLEXCOM_MR_OPMODE_Msk) >> FLEXCOM_MR_OPMODE_Pos;
	return tmp;
}

static inline void hri_flexcom_set_MR_reg(const void *const hw, hri_flexcom_mr_reg_t mask)
{
	FLEXCOM_CRITICAL_SECTION_ENTER();
	((Flexcom *)hw)->FLEXCOM_MR |= mask;
	FLEXCOM_CRITICAL_SECTION_LEAVE();
}

static inline hri_flexcom_mr_reg_t hri_flexcom_get_MR_reg(const void *const hw, hri_flexcom_mr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Flexcom *)hw)->FLEXCOM_MR;
	tmp &= mask;
	return tmp;
}

static inline void hri_flexcom_write_MR_reg(const void *const hw, hri_flexcom_mr_reg_t data)
{
	FLEXCOM_CRITICAL_SECTION_ENTER();
	((Flexcom *)hw)->FLEXCOM_MR = data;
	FLEXCOM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_flexcom_clear_MR_reg(const void *const hw, hri_flexcom_mr_reg_t mask)
{
	FLEXCOM_CRITICAL_SECTION_ENTER();
	((Flexcom *)hw)->FLEXCOM_MR &= ~mask;
	FLEXCOM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_flexcom_toggle_MR_reg(const void *const hw, hri_flexcom_mr_reg_t mask)
{
	FLEXCOM_CRITICAL_SECTION_ENTER();
	((Flexcom *)hw)->FLEXCOM_MR ^= mask;
	FLEXCOM_CRITICAL_SECTION_LEAVE();
}

static inline hri_flexcom_mr_reg_t hri_flexcom_read_MR_reg(const void *const hw)
{
	return ((Flexcom *)hw)->FLEXCOM_MR;
}

static inline void hri_flexcom_set_THR_TXDATA_bf(const void *const hw, hri_flexcom_thr_reg_t mask)
{
	FLEXCOM_CRITICAL_SECTION_ENTER();
	((Flexcom *)hw)->FLEXCOM_THR |= FLEXCOM_THR_TXDATA(mask);
	FLEXCOM_CRITICAL_SECTION_LEAVE();
}

static inline hri_flexcom_thr_reg_t hri_flexcom_get_THR_TXDATA_bf(const void *const hw, hri_flexcom_thr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Flexcom *)hw)->FLEXCOM_THR;
	tmp = (tmp & FLEXCOM_THR_TXDATA(mask)) >> FLEXCOM_THR_TXDATA_Pos;
	return tmp;
}

static inline void hri_flexcom_write_THR_TXDATA_bf(const void *const hw, hri_flexcom_thr_reg_t data)
{
	uint32_t tmp;
	FLEXCOM_CRITICAL_SECTION_ENTER();
	tmp = ((Flexcom *)hw)->FLEXCOM_THR;
	tmp &= ~FLEXCOM_THR_TXDATA_Msk;
	tmp |= FLEXCOM_THR_TXDATA(data);
	((Flexcom *)hw)->FLEXCOM_THR = tmp;
	FLEXCOM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_flexcom_clear_THR_TXDATA_bf(const void *const hw, hri_flexcom_thr_reg_t mask)
{
	FLEXCOM_CRITICAL_SECTION_ENTER();
	((Flexcom *)hw)->FLEXCOM_THR &= ~FLEXCOM_THR_TXDATA(mask);
	FLEXCOM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_flexcom_toggle_THR_TXDATA_bf(const void *const hw, hri_flexcom_thr_reg_t mask)
{
	FLEXCOM_CRITICAL_SECTION_ENTER();
	((Flexcom *)hw)->FLEXCOM_THR ^= FLEXCOM_THR_TXDATA(mask);
	FLEXCOM_CRITICAL_SECTION_LEAVE();
}

static inline hri_flexcom_thr_reg_t hri_flexcom_read_THR_TXDATA_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Flexcom *)hw)->FLEXCOM_THR;
	tmp = (tmp & FLEXCOM_THR_TXDATA_Msk) >> FLEXCOM_THR_TXDATA_Pos;
	return tmp;
}

static inline void hri_flexcom_set_THR_reg(const void *const hw, hri_flexcom_thr_reg_t mask)
{
	FLEXCOM_CRITICAL_SECTION_ENTER();
	((Flexcom *)hw)->FLEXCOM_THR |= mask;
	FLEXCOM_CRITICAL_SECTION_LEAVE();
}

static inline hri_flexcom_thr_reg_t hri_flexcom_get_THR_reg(const void *const hw, hri_flexcom_thr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Flexcom *)hw)->FLEXCOM_THR;
	tmp &= mask;
	return tmp;
}

static inline void hri_flexcom_write_THR_reg(const void *const hw, hri_flexcom_thr_reg_t data)
{
	FLEXCOM_CRITICAL_SECTION_ENTER();
	((Flexcom *)hw)->FLEXCOM_THR = data;
	FLEXCOM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_flexcom_clear_THR_reg(const void *const hw, hri_flexcom_thr_reg_t mask)
{
	FLEXCOM_CRITICAL_SECTION_ENTER();
	((Flexcom *)hw)->FLEXCOM_THR &= ~mask;
	FLEXCOM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_flexcom_toggle_THR_reg(const void *const hw, hri_flexcom_thr_reg_t mask)
{
	FLEXCOM_CRITICAL_SECTION_ENTER();
	((Flexcom *)hw)->FLEXCOM_THR ^= mask;
	FLEXCOM_CRITICAL_SECTION_LEAVE();
}

static inline hri_flexcom_thr_reg_t hri_flexcom_read_THR_reg(const void *const hw)
{
	return ((Flexcom *)hw)->FLEXCOM_THR;
}

static inline hri_flexcom_rhr_reg_t hri_flexcom_get_RHR_RXDATA_bf(const void *const hw, hri_flexcom_rhr_reg_t mask)
{
	return (((Flexcom *)hw)->FLEXCOM_RHR & FLEXCOM_RHR_RXDATA(mask)) >> FLEXCOM_RHR_RXDATA_Pos;
}

static inline hri_flexcom_rhr_reg_t hri_flexcom_read_RHR_RXDATA_bf(const void *const hw)
{
	return (((Flexcom *)hw)->FLEXCOM_RHR & FLEXCOM_RHR_RXDATA_Msk) >> FLEXCOM_RHR_RXDATA_Pos;
}

static inline hri_flexcom_rhr_reg_t hri_flexcom_get_RHR_reg(const void *const hw, hri_flexcom_rhr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Flexcom *)hw)->FLEXCOM_RHR;
	tmp &= mask;
	return tmp;
}

static inline hri_flexcom_rhr_reg_t hri_flexcom_read_RHR_reg(const void *const hw)
{
	return ((Flexcom *)hw)->FLEXCOM_RHR;
}

#ifdef __cplusplus
}
#endif

#endif /* _HRI_FLEXCOM_G55_H_INCLUDED */
#endif /* _SAMG55_FLEXCOM_COMPONENT_ */
