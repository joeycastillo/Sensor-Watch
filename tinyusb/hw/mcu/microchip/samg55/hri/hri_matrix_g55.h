/**
 * \file
 *
 * \brief SAM MATRIX
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

#ifdef _SAMG55_MATRIX_COMPONENT_
#ifndef _HRI_MATRIX_G55_H_INCLUDED_
#define _HRI_MATRIX_G55_H_INCLUDED_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <hal_atomic.h>

#if defined(ENABLE_MATRIX_CRITICAL_SECTIONS)
#define MATRIX_CRITICAL_SECTION_ENTER() CRITICAL_SECTION_ENTER()
#define MATRIX_CRITICAL_SECTION_LEAVE() CRITICAL_SECTION_LEAVE()
#else
#define MATRIX_CRITICAL_SECTION_ENTER()
#define MATRIX_CRITICAL_SECTION_LEAVE()
#endif

typedef uint32_t hri_matrix_ccfg_dynckg_reg_t;
typedef uint32_t hri_matrix_ccfg_i2sclksel_reg_t;
typedef uint32_t hri_matrix_ccfg_sysio_reg_t;
typedef uint32_t hri_matrix_ccfg_usbmr_reg_t;
typedef uint32_t hri_matrix_mcfg_reg_t;
typedef uint32_t hri_matrix_pras0_reg_t;
typedef uint32_t hri_matrix_pras1_reg_t;
typedef uint32_t hri_matrix_pras2_reg_t;
typedef uint32_t hri_matrix_pras3_reg_t;
typedef uint32_t hri_matrix_scfg_reg_t;
typedef uint32_t hri_matrix_wpmr_reg_t;
typedef uint32_t hri_matrix_wpsr_reg_t;

static inline void hri_matrix_set_MCFG_ULBT_bf(const void *const hw, uint8_t index, hri_matrix_mcfg_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_MCFG[index] |= MATRIX_MCFG_ULBT(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_mcfg_reg_t hri_matrix_get_MCFG_ULBT_bf(const void *const hw, uint8_t index,
                                                                hri_matrix_mcfg_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_MCFG[index];
	tmp = (tmp & MATRIX_MCFG_ULBT(mask)) >> MATRIX_MCFG_ULBT_Pos;
	return tmp;
}

static inline void hri_matrix_write_MCFG_ULBT_bf(const void *const hw, uint8_t index, hri_matrix_mcfg_reg_t data)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->MATRIX_MCFG[index];
	tmp &= ~MATRIX_MCFG_ULBT_Msk;
	tmp |= MATRIX_MCFG_ULBT(data);
	((Matrix *)hw)->MATRIX_MCFG[index] = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_MCFG_ULBT_bf(const void *const hw, uint8_t index, hri_matrix_mcfg_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_MCFG[index] &= ~MATRIX_MCFG_ULBT(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_MCFG_ULBT_bf(const void *const hw, uint8_t index, hri_matrix_mcfg_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_MCFG[index] ^= MATRIX_MCFG_ULBT(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_mcfg_reg_t hri_matrix_read_MCFG_ULBT_bf(const void *const hw, uint8_t index)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_MCFG[index];
	tmp = (tmp & MATRIX_MCFG_ULBT_Msk) >> MATRIX_MCFG_ULBT_Pos;
	return tmp;
}

static inline void hri_matrix_set_MCFG_reg(const void *const hw, uint8_t index, hri_matrix_mcfg_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_MCFG[index] |= mask;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_mcfg_reg_t hri_matrix_get_MCFG_reg(const void *const hw, uint8_t index,
                                                            hri_matrix_mcfg_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_MCFG[index];
	tmp &= mask;
	return tmp;
}

static inline void hri_matrix_write_MCFG_reg(const void *const hw, uint8_t index, hri_matrix_mcfg_reg_t data)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_MCFG[index] = data;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_MCFG_reg(const void *const hw, uint8_t index, hri_matrix_mcfg_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_MCFG[index] &= ~mask;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_MCFG_reg(const void *const hw, uint8_t index, hri_matrix_mcfg_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_MCFG[index] ^= mask;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_mcfg_reg_t hri_matrix_read_MCFG_reg(const void *const hw, uint8_t index)
{
	return ((Matrix *)hw)->MATRIX_MCFG[index];
}

static inline void hri_matrix_set_SCFG_SLOT_CYCLE_bf(const void *const hw, uint8_t index, hri_matrix_scfg_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_SCFG[index] |= MATRIX_SCFG_SLOT_CYCLE(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_scfg_reg_t hri_matrix_get_SCFG_SLOT_CYCLE_bf(const void *const hw, uint8_t index,
                                                                      hri_matrix_scfg_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_SCFG[index];
	tmp = (tmp & MATRIX_SCFG_SLOT_CYCLE(mask)) >> MATRIX_SCFG_SLOT_CYCLE_Pos;
	return tmp;
}

static inline void hri_matrix_write_SCFG_SLOT_CYCLE_bf(const void *const hw, uint8_t index, hri_matrix_scfg_reg_t data)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->MATRIX_SCFG[index];
	tmp &= ~MATRIX_SCFG_SLOT_CYCLE_Msk;
	tmp |= MATRIX_SCFG_SLOT_CYCLE(data);
	((Matrix *)hw)->MATRIX_SCFG[index] = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_SCFG_SLOT_CYCLE_bf(const void *const hw, uint8_t index, hri_matrix_scfg_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_SCFG[index] &= ~MATRIX_SCFG_SLOT_CYCLE(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_SCFG_SLOT_CYCLE_bf(const void *const hw, uint8_t index, hri_matrix_scfg_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_SCFG[index] ^= MATRIX_SCFG_SLOT_CYCLE(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_scfg_reg_t hri_matrix_read_SCFG_SLOT_CYCLE_bf(const void *const hw, uint8_t index)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_SCFG[index];
	tmp = (tmp & MATRIX_SCFG_SLOT_CYCLE_Msk) >> MATRIX_SCFG_SLOT_CYCLE_Pos;
	return tmp;
}

static inline void hri_matrix_set_SCFG_DEFMSTR_TYPE_bf(const void *const hw, uint8_t index, hri_matrix_scfg_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_SCFG[index] |= MATRIX_SCFG_DEFMSTR_TYPE(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_scfg_reg_t hri_matrix_get_SCFG_DEFMSTR_TYPE_bf(const void *const hw, uint8_t index,
                                                                        hri_matrix_scfg_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_SCFG[index];
	tmp = (tmp & MATRIX_SCFG_DEFMSTR_TYPE(mask)) >> MATRIX_SCFG_DEFMSTR_TYPE_Pos;
	return tmp;
}

static inline void hri_matrix_write_SCFG_DEFMSTR_TYPE_bf(const void *const hw, uint8_t index,
                                                         hri_matrix_scfg_reg_t data)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->MATRIX_SCFG[index];
	tmp &= ~MATRIX_SCFG_DEFMSTR_TYPE_Msk;
	tmp |= MATRIX_SCFG_DEFMSTR_TYPE(data);
	((Matrix *)hw)->MATRIX_SCFG[index] = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_SCFG_DEFMSTR_TYPE_bf(const void *const hw, uint8_t index,
                                                         hri_matrix_scfg_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_SCFG[index] &= ~MATRIX_SCFG_DEFMSTR_TYPE(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_SCFG_DEFMSTR_TYPE_bf(const void *const hw, uint8_t index,
                                                          hri_matrix_scfg_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_SCFG[index] ^= MATRIX_SCFG_DEFMSTR_TYPE(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_scfg_reg_t hri_matrix_read_SCFG_DEFMSTR_TYPE_bf(const void *const hw, uint8_t index)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_SCFG[index];
	tmp = (tmp & MATRIX_SCFG_DEFMSTR_TYPE_Msk) >> MATRIX_SCFG_DEFMSTR_TYPE_Pos;
	return tmp;
}

static inline void hri_matrix_set_SCFG_FIXED_DEFMSTR_bf(const void *const hw, uint8_t index, hri_matrix_scfg_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_SCFG[index] |= MATRIX_SCFG_FIXED_DEFMSTR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_scfg_reg_t hri_matrix_get_SCFG_FIXED_DEFMSTR_bf(const void *const hw, uint8_t index,
                                                                         hri_matrix_scfg_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_SCFG[index];
	tmp = (tmp & MATRIX_SCFG_FIXED_DEFMSTR(mask)) >> MATRIX_SCFG_FIXED_DEFMSTR_Pos;
	return tmp;
}

static inline void hri_matrix_write_SCFG_FIXED_DEFMSTR_bf(const void *const hw, uint8_t index,
                                                          hri_matrix_scfg_reg_t data)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->MATRIX_SCFG[index];
	tmp &= ~MATRIX_SCFG_FIXED_DEFMSTR_Msk;
	tmp |= MATRIX_SCFG_FIXED_DEFMSTR(data);
	((Matrix *)hw)->MATRIX_SCFG[index] = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_SCFG_FIXED_DEFMSTR_bf(const void *const hw, uint8_t index,
                                                          hri_matrix_scfg_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_SCFG[index] &= ~MATRIX_SCFG_FIXED_DEFMSTR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_SCFG_FIXED_DEFMSTR_bf(const void *const hw, uint8_t index,
                                                           hri_matrix_scfg_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_SCFG[index] ^= MATRIX_SCFG_FIXED_DEFMSTR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_scfg_reg_t hri_matrix_read_SCFG_FIXED_DEFMSTR_bf(const void *const hw, uint8_t index)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_SCFG[index];
	tmp = (tmp & MATRIX_SCFG_FIXED_DEFMSTR_Msk) >> MATRIX_SCFG_FIXED_DEFMSTR_Pos;
	return tmp;
}

static inline void hri_matrix_set_SCFG_reg(const void *const hw, uint8_t index, hri_matrix_scfg_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_SCFG[index] |= mask;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_scfg_reg_t hri_matrix_get_SCFG_reg(const void *const hw, uint8_t index,
                                                            hri_matrix_scfg_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_SCFG[index];
	tmp &= mask;
	return tmp;
}

static inline void hri_matrix_write_SCFG_reg(const void *const hw, uint8_t index, hri_matrix_scfg_reg_t data)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_SCFG[index] = data;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_SCFG_reg(const void *const hw, uint8_t index, hri_matrix_scfg_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_SCFG[index] &= ~mask;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_SCFG_reg(const void *const hw, uint8_t index, hri_matrix_scfg_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_SCFG[index] ^= mask;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_scfg_reg_t hri_matrix_read_SCFG_reg(const void *const hw, uint8_t index)
{
	return ((Matrix *)hw)->MATRIX_SCFG[index];
}

static inline void hri_matrix_set_PRAS0_M0PR_bf(const void *const hw, hri_matrix_pras0_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS0 |= MATRIX_PRAS0_M0PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras0_reg_t hri_matrix_get_PRAS0_M0PR_bf(const void *const hw, hri_matrix_pras0_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS0;
	tmp = (tmp & MATRIX_PRAS0_M0PR(mask)) >> MATRIX_PRAS0_M0PR_Pos;
	return tmp;
}

static inline void hri_matrix_write_PRAS0_M0PR_bf(const void *const hw, hri_matrix_pras0_reg_t data)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->MATRIX_PRAS0;
	tmp &= ~MATRIX_PRAS0_M0PR_Msk;
	tmp |= MATRIX_PRAS0_M0PR(data);
	((Matrix *)hw)->MATRIX_PRAS0 = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_PRAS0_M0PR_bf(const void *const hw, hri_matrix_pras0_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS0 &= ~MATRIX_PRAS0_M0PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_PRAS0_M0PR_bf(const void *const hw, hri_matrix_pras0_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS0 ^= MATRIX_PRAS0_M0PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras0_reg_t hri_matrix_read_PRAS0_M0PR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS0;
	tmp = (tmp & MATRIX_PRAS0_M0PR_Msk) >> MATRIX_PRAS0_M0PR_Pos;
	return tmp;
}

static inline void hri_matrix_set_PRAS0_M1PR_bf(const void *const hw, hri_matrix_pras0_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS0 |= MATRIX_PRAS0_M1PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras0_reg_t hri_matrix_get_PRAS0_M1PR_bf(const void *const hw, hri_matrix_pras0_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS0;
	tmp = (tmp & MATRIX_PRAS0_M1PR(mask)) >> MATRIX_PRAS0_M1PR_Pos;
	return tmp;
}

static inline void hri_matrix_write_PRAS0_M1PR_bf(const void *const hw, hri_matrix_pras0_reg_t data)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->MATRIX_PRAS0;
	tmp &= ~MATRIX_PRAS0_M1PR_Msk;
	tmp |= MATRIX_PRAS0_M1PR(data);
	((Matrix *)hw)->MATRIX_PRAS0 = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_PRAS0_M1PR_bf(const void *const hw, hri_matrix_pras0_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS0 &= ~MATRIX_PRAS0_M1PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_PRAS0_M1PR_bf(const void *const hw, hri_matrix_pras0_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS0 ^= MATRIX_PRAS0_M1PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras0_reg_t hri_matrix_read_PRAS0_M1PR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS0;
	tmp = (tmp & MATRIX_PRAS0_M1PR_Msk) >> MATRIX_PRAS0_M1PR_Pos;
	return tmp;
}

static inline void hri_matrix_set_PRAS0_M2PR_bf(const void *const hw, hri_matrix_pras0_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS0 |= MATRIX_PRAS0_M2PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras0_reg_t hri_matrix_get_PRAS0_M2PR_bf(const void *const hw, hri_matrix_pras0_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS0;
	tmp = (tmp & MATRIX_PRAS0_M2PR(mask)) >> MATRIX_PRAS0_M2PR_Pos;
	return tmp;
}

static inline void hri_matrix_write_PRAS0_M2PR_bf(const void *const hw, hri_matrix_pras0_reg_t data)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->MATRIX_PRAS0;
	tmp &= ~MATRIX_PRAS0_M2PR_Msk;
	tmp |= MATRIX_PRAS0_M2PR(data);
	((Matrix *)hw)->MATRIX_PRAS0 = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_PRAS0_M2PR_bf(const void *const hw, hri_matrix_pras0_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS0 &= ~MATRIX_PRAS0_M2PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_PRAS0_M2PR_bf(const void *const hw, hri_matrix_pras0_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS0 ^= MATRIX_PRAS0_M2PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras0_reg_t hri_matrix_read_PRAS0_M2PR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS0;
	tmp = (tmp & MATRIX_PRAS0_M2PR_Msk) >> MATRIX_PRAS0_M2PR_Pos;
	return tmp;
}

static inline void hri_matrix_set_PRAS0_M3PR_bf(const void *const hw, hri_matrix_pras0_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS0 |= MATRIX_PRAS0_M3PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras0_reg_t hri_matrix_get_PRAS0_M3PR_bf(const void *const hw, hri_matrix_pras0_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS0;
	tmp = (tmp & MATRIX_PRAS0_M3PR(mask)) >> MATRIX_PRAS0_M3PR_Pos;
	return tmp;
}

static inline void hri_matrix_write_PRAS0_M3PR_bf(const void *const hw, hri_matrix_pras0_reg_t data)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->MATRIX_PRAS0;
	tmp &= ~MATRIX_PRAS0_M3PR_Msk;
	tmp |= MATRIX_PRAS0_M3PR(data);
	((Matrix *)hw)->MATRIX_PRAS0 = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_PRAS0_M3PR_bf(const void *const hw, hri_matrix_pras0_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS0 &= ~MATRIX_PRAS0_M3PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_PRAS0_M3PR_bf(const void *const hw, hri_matrix_pras0_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS0 ^= MATRIX_PRAS0_M3PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras0_reg_t hri_matrix_read_PRAS0_M3PR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS0;
	tmp = (tmp & MATRIX_PRAS0_M3PR_Msk) >> MATRIX_PRAS0_M3PR_Pos;
	return tmp;
}

static inline void hri_matrix_set_PRAS0_reg(const void *const hw, hri_matrix_pras0_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS0 |= mask;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras0_reg_t hri_matrix_get_PRAS0_reg(const void *const hw, hri_matrix_pras0_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS0;
	tmp &= mask;
	return tmp;
}

static inline void hri_matrix_write_PRAS0_reg(const void *const hw, hri_matrix_pras0_reg_t data)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS0 = data;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_PRAS0_reg(const void *const hw, hri_matrix_pras0_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS0 &= ~mask;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_PRAS0_reg(const void *const hw, hri_matrix_pras0_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS0 ^= mask;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras0_reg_t hri_matrix_read_PRAS0_reg(const void *const hw)
{
	return ((Matrix *)hw)->MATRIX_PRAS0;
}

static inline void hri_matrix_set_PRAS1_M0PR_bf(const void *const hw, hri_matrix_pras1_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS1 |= MATRIX_PRAS1_M0PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras1_reg_t hri_matrix_get_PRAS1_M0PR_bf(const void *const hw, hri_matrix_pras1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS1;
	tmp = (tmp & MATRIX_PRAS1_M0PR(mask)) >> MATRIX_PRAS1_M0PR_Pos;
	return tmp;
}

static inline void hri_matrix_write_PRAS1_M0PR_bf(const void *const hw, hri_matrix_pras1_reg_t data)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->MATRIX_PRAS1;
	tmp &= ~MATRIX_PRAS1_M0PR_Msk;
	tmp |= MATRIX_PRAS1_M0PR(data);
	((Matrix *)hw)->MATRIX_PRAS1 = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_PRAS1_M0PR_bf(const void *const hw, hri_matrix_pras1_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS1 &= ~MATRIX_PRAS1_M0PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_PRAS1_M0PR_bf(const void *const hw, hri_matrix_pras1_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS1 ^= MATRIX_PRAS1_M0PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras1_reg_t hri_matrix_read_PRAS1_M0PR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS1;
	tmp = (tmp & MATRIX_PRAS1_M0PR_Msk) >> MATRIX_PRAS1_M0PR_Pos;
	return tmp;
}

static inline void hri_matrix_set_PRAS1_M1PR_bf(const void *const hw, hri_matrix_pras1_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS1 |= MATRIX_PRAS1_M1PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras1_reg_t hri_matrix_get_PRAS1_M1PR_bf(const void *const hw, hri_matrix_pras1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS1;
	tmp = (tmp & MATRIX_PRAS1_M1PR(mask)) >> MATRIX_PRAS1_M1PR_Pos;
	return tmp;
}

static inline void hri_matrix_write_PRAS1_M1PR_bf(const void *const hw, hri_matrix_pras1_reg_t data)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->MATRIX_PRAS1;
	tmp &= ~MATRIX_PRAS1_M1PR_Msk;
	tmp |= MATRIX_PRAS1_M1PR(data);
	((Matrix *)hw)->MATRIX_PRAS1 = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_PRAS1_M1PR_bf(const void *const hw, hri_matrix_pras1_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS1 &= ~MATRIX_PRAS1_M1PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_PRAS1_M1PR_bf(const void *const hw, hri_matrix_pras1_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS1 ^= MATRIX_PRAS1_M1PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras1_reg_t hri_matrix_read_PRAS1_M1PR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS1;
	tmp = (tmp & MATRIX_PRAS1_M1PR_Msk) >> MATRIX_PRAS1_M1PR_Pos;
	return tmp;
}

static inline void hri_matrix_set_PRAS1_M2PR_bf(const void *const hw, hri_matrix_pras1_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS1 |= MATRIX_PRAS1_M2PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras1_reg_t hri_matrix_get_PRAS1_M2PR_bf(const void *const hw, hri_matrix_pras1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS1;
	tmp = (tmp & MATRIX_PRAS1_M2PR(mask)) >> MATRIX_PRAS1_M2PR_Pos;
	return tmp;
}

static inline void hri_matrix_write_PRAS1_M2PR_bf(const void *const hw, hri_matrix_pras1_reg_t data)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->MATRIX_PRAS1;
	tmp &= ~MATRIX_PRAS1_M2PR_Msk;
	tmp |= MATRIX_PRAS1_M2PR(data);
	((Matrix *)hw)->MATRIX_PRAS1 = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_PRAS1_M2PR_bf(const void *const hw, hri_matrix_pras1_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS1 &= ~MATRIX_PRAS1_M2PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_PRAS1_M2PR_bf(const void *const hw, hri_matrix_pras1_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS1 ^= MATRIX_PRAS1_M2PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras1_reg_t hri_matrix_read_PRAS1_M2PR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS1;
	tmp = (tmp & MATRIX_PRAS1_M2PR_Msk) >> MATRIX_PRAS1_M2PR_Pos;
	return tmp;
}

static inline void hri_matrix_set_PRAS1_M3PR_bf(const void *const hw, hri_matrix_pras1_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS1 |= MATRIX_PRAS1_M3PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras1_reg_t hri_matrix_get_PRAS1_M3PR_bf(const void *const hw, hri_matrix_pras1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS1;
	tmp = (tmp & MATRIX_PRAS1_M3PR(mask)) >> MATRIX_PRAS1_M3PR_Pos;
	return tmp;
}

static inline void hri_matrix_write_PRAS1_M3PR_bf(const void *const hw, hri_matrix_pras1_reg_t data)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->MATRIX_PRAS1;
	tmp &= ~MATRIX_PRAS1_M3PR_Msk;
	tmp |= MATRIX_PRAS1_M3PR(data);
	((Matrix *)hw)->MATRIX_PRAS1 = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_PRAS1_M3PR_bf(const void *const hw, hri_matrix_pras1_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS1 &= ~MATRIX_PRAS1_M3PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_PRAS1_M3PR_bf(const void *const hw, hri_matrix_pras1_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS1 ^= MATRIX_PRAS1_M3PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras1_reg_t hri_matrix_read_PRAS1_M3PR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS1;
	tmp = (tmp & MATRIX_PRAS1_M3PR_Msk) >> MATRIX_PRAS1_M3PR_Pos;
	return tmp;
}

static inline void hri_matrix_set_PRAS1_reg(const void *const hw, hri_matrix_pras1_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS1 |= mask;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras1_reg_t hri_matrix_get_PRAS1_reg(const void *const hw, hri_matrix_pras1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS1;
	tmp &= mask;
	return tmp;
}

static inline void hri_matrix_write_PRAS1_reg(const void *const hw, hri_matrix_pras1_reg_t data)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS1 = data;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_PRAS1_reg(const void *const hw, hri_matrix_pras1_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS1 &= ~mask;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_PRAS1_reg(const void *const hw, hri_matrix_pras1_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS1 ^= mask;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras1_reg_t hri_matrix_read_PRAS1_reg(const void *const hw)
{
	return ((Matrix *)hw)->MATRIX_PRAS1;
}

static inline void hri_matrix_set_PRAS2_M0PR_bf(const void *const hw, hri_matrix_pras2_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS2 |= MATRIX_PRAS2_M0PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras2_reg_t hri_matrix_get_PRAS2_M0PR_bf(const void *const hw, hri_matrix_pras2_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS2;
	tmp = (tmp & MATRIX_PRAS2_M0PR(mask)) >> MATRIX_PRAS2_M0PR_Pos;
	return tmp;
}

static inline void hri_matrix_write_PRAS2_M0PR_bf(const void *const hw, hri_matrix_pras2_reg_t data)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->MATRIX_PRAS2;
	tmp &= ~MATRIX_PRAS2_M0PR_Msk;
	tmp |= MATRIX_PRAS2_M0PR(data);
	((Matrix *)hw)->MATRIX_PRAS2 = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_PRAS2_M0PR_bf(const void *const hw, hri_matrix_pras2_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS2 &= ~MATRIX_PRAS2_M0PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_PRAS2_M0PR_bf(const void *const hw, hri_matrix_pras2_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS2 ^= MATRIX_PRAS2_M0PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras2_reg_t hri_matrix_read_PRAS2_M0PR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS2;
	tmp = (tmp & MATRIX_PRAS2_M0PR_Msk) >> MATRIX_PRAS2_M0PR_Pos;
	return tmp;
}

static inline void hri_matrix_set_PRAS2_M1PR_bf(const void *const hw, hri_matrix_pras2_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS2 |= MATRIX_PRAS2_M1PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras2_reg_t hri_matrix_get_PRAS2_M1PR_bf(const void *const hw, hri_matrix_pras2_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS2;
	tmp = (tmp & MATRIX_PRAS2_M1PR(mask)) >> MATRIX_PRAS2_M1PR_Pos;
	return tmp;
}

static inline void hri_matrix_write_PRAS2_M1PR_bf(const void *const hw, hri_matrix_pras2_reg_t data)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->MATRIX_PRAS2;
	tmp &= ~MATRIX_PRAS2_M1PR_Msk;
	tmp |= MATRIX_PRAS2_M1PR(data);
	((Matrix *)hw)->MATRIX_PRAS2 = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_PRAS2_M1PR_bf(const void *const hw, hri_matrix_pras2_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS2 &= ~MATRIX_PRAS2_M1PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_PRAS2_M1PR_bf(const void *const hw, hri_matrix_pras2_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS2 ^= MATRIX_PRAS2_M1PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras2_reg_t hri_matrix_read_PRAS2_M1PR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS2;
	tmp = (tmp & MATRIX_PRAS2_M1PR_Msk) >> MATRIX_PRAS2_M1PR_Pos;
	return tmp;
}

static inline void hri_matrix_set_PRAS2_M2PR_bf(const void *const hw, hri_matrix_pras2_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS2 |= MATRIX_PRAS2_M2PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras2_reg_t hri_matrix_get_PRAS2_M2PR_bf(const void *const hw, hri_matrix_pras2_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS2;
	tmp = (tmp & MATRIX_PRAS2_M2PR(mask)) >> MATRIX_PRAS2_M2PR_Pos;
	return tmp;
}

static inline void hri_matrix_write_PRAS2_M2PR_bf(const void *const hw, hri_matrix_pras2_reg_t data)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->MATRIX_PRAS2;
	tmp &= ~MATRIX_PRAS2_M2PR_Msk;
	tmp |= MATRIX_PRAS2_M2PR(data);
	((Matrix *)hw)->MATRIX_PRAS2 = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_PRAS2_M2PR_bf(const void *const hw, hri_matrix_pras2_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS2 &= ~MATRIX_PRAS2_M2PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_PRAS2_M2PR_bf(const void *const hw, hri_matrix_pras2_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS2 ^= MATRIX_PRAS2_M2PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras2_reg_t hri_matrix_read_PRAS2_M2PR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS2;
	tmp = (tmp & MATRIX_PRAS2_M2PR_Msk) >> MATRIX_PRAS2_M2PR_Pos;
	return tmp;
}

static inline void hri_matrix_set_PRAS2_M3PR_bf(const void *const hw, hri_matrix_pras2_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS2 |= MATRIX_PRAS2_M3PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras2_reg_t hri_matrix_get_PRAS2_M3PR_bf(const void *const hw, hri_matrix_pras2_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS2;
	tmp = (tmp & MATRIX_PRAS2_M3PR(mask)) >> MATRIX_PRAS2_M3PR_Pos;
	return tmp;
}

static inline void hri_matrix_write_PRAS2_M3PR_bf(const void *const hw, hri_matrix_pras2_reg_t data)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->MATRIX_PRAS2;
	tmp &= ~MATRIX_PRAS2_M3PR_Msk;
	tmp |= MATRIX_PRAS2_M3PR(data);
	((Matrix *)hw)->MATRIX_PRAS2 = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_PRAS2_M3PR_bf(const void *const hw, hri_matrix_pras2_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS2 &= ~MATRIX_PRAS2_M3PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_PRAS2_M3PR_bf(const void *const hw, hri_matrix_pras2_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS2 ^= MATRIX_PRAS2_M3PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras2_reg_t hri_matrix_read_PRAS2_M3PR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS2;
	tmp = (tmp & MATRIX_PRAS2_M3PR_Msk) >> MATRIX_PRAS2_M3PR_Pos;
	return tmp;
}

static inline void hri_matrix_set_PRAS2_reg(const void *const hw, hri_matrix_pras2_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS2 |= mask;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras2_reg_t hri_matrix_get_PRAS2_reg(const void *const hw, hri_matrix_pras2_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS2;
	tmp &= mask;
	return tmp;
}

static inline void hri_matrix_write_PRAS2_reg(const void *const hw, hri_matrix_pras2_reg_t data)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS2 = data;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_PRAS2_reg(const void *const hw, hri_matrix_pras2_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS2 &= ~mask;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_PRAS2_reg(const void *const hw, hri_matrix_pras2_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS2 ^= mask;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras2_reg_t hri_matrix_read_PRAS2_reg(const void *const hw)
{
	return ((Matrix *)hw)->MATRIX_PRAS2;
}

static inline void hri_matrix_set_PRAS3_M0PR_bf(const void *const hw, hri_matrix_pras3_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS3 |= MATRIX_PRAS3_M0PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras3_reg_t hri_matrix_get_PRAS3_M0PR_bf(const void *const hw, hri_matrix_pras3_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS3;
	tmp = (tmp & MATRIX_PRAS3_M0PR(mask)) >> MATRIX_PRAS3_M0PR_Pos;
	return tmp;
}

static inline void hri_matrix_write_PRAS3_M0PR_bf(const void *const hw, hri_matrix_pras3_reg_t data)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->MATRIX_PRAS3;
	tmp &= ~MATRIX_PRAS3_M0PR_Msk;
	tmp |= MATRIX_PRAS3_M0PR(data);
	((Matrix *)hw)->MATRIX_PRAS3 = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_PRAS3_M0PR_bf(const void *const hw, hri_matrix_pras3_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS3 &= ~MATRIX_PRAS3_M0PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_PRAS3_M0PR_bf(const void *const hw, hri_matrix_pras3_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS3 ^= MATRIX_PRAS3_M0PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras3_reg_t hri_matrix_read_PRAS3_M0PR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS3;
	tmp = (tmp & MATRIX_PRAS3_M0PR_Msk) >> MATRIX_PRAS3_M0PR_Pos;
	return tmp;
}

static inline void hri_matrix_set_PRAS3_M1PR_bf(const void *const hw, hri_matrix_pras3_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS3 |= MATRIX_PRAS3_M1PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras3_reg_t hri_matrix_get_PRAS3_M1PR_bf(const void *const hw, hri_matrix_pras3_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS3;
	tmp = (tmp & MATRIX_PRAS3_M1PR(mask)) >> MATRIX_PRAS3_M1PR_Pos;
	return tmp;
}

static inline void hri_matrix_write_PRAS3_M1PR_bf(const void *const hw, hri_matrix_pras3_reg_t data)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->MATRIX_PRAS3;
	tmp &= ~MATRIX_PRAS3_M1PR_Msk;
	tmp |= MATRIX_PRAS3_M1PR(data);
	((Matrix *)hw)->MATRIX_PRAS3 = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_PRAS3_M1PR_bf(const void *const hw, hri_matrix_pras3_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS3 &= ~MATRIX_PRAS3_M1PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_PRAS3_M1PR_bf(const void *const hw, hri_matrix_pras3_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS3 ^= MATRIX_PRAS3_M1PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras3_reg_t hri_matrix_read_PRAS3_M1PR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS3;
	tmp = (tmp & MATRIX_PRAS3_M1PR_Msk) >> MATRIX_PRAS3_M1PR_Pos;
	return tmp;
}

static inline void hri_matrix_set_PRAS3_M2PR_bf(const void *const hw, hri_matrix_pras3_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS3 |= MATRIX_PRAS3_M2PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras3_reg_t hri_matrix_get_PRAS3_M2PR_bf(const void *const hw, hri_matrix_pras3_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS3;
	tmp = (tmp & MATRIX_PRAS3_M2PR(mask)) >> MATRIX_PRAS3_M2PR_Pos;
	return tmp;
}

static inline void hri_matrix_write_PRAS3_M2PR_bf(const void *const hw, hri_matrix_pras3_reg_t data)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->MATRIX_PRAS3;
	tmp &= ~MATRIX_PRAS3_M2PR_Msk;
	tmp |= MATRIX_PRAS3_M2PR(data);
	((Matrix *)hw)->MATRIX_PRAS3 = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_PRAS3_M2PR_bf(const void *const hw, hri_matrix_pras3_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS3 &= ~MATRIX_PRAS3_M2PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_PRAS3_M2PR_bf(const void *const hw, hri_matrix_pras3_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS3 ^= MATRIX_PRAS3_M2PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras3_reg_t hri_matrix_read_PRAS3_M2PR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS3;
	tmp = (tmp & MATRIX_PRAS3_M2PR_Msk) >> MATRIX_PRAS3_M2PR_Pos;
	return tmp;
}

static inline void hri_matrix_set_PRAS3_M3PR_bf(const void *const hw, hri_matrix_pras3_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS3 |= MATRIX_PRAS3_M3PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras3_reg_t hri_matrix_get_PRAS3_M3PR_bf(const void *const hw, hri_matrix_pras3_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS3;
	tmp = (tmp & MATRIX_PRAS3_M3PR(mask)) >> MATRIX_PRAS3_M3PR_Pos;
	return tmp;
}

static inline void hri_matrix_write_PRAS3_M3PR_bf(const void *const hw, hri_matrix_pras3_reg_t data)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->MATRIX_PRAS3;
	tmp &= ~MATRIX_PRAS3_M3PR_Msk;
	tmp |= MATRIX_PRAS3_M3PR(data);
	((Matrix *)hw)->MATRIX_PRAS3 = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_PRAS3_M3PR_bf(const void *const hw, hri_matrix_pras3_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS3 &= ~MATRIX_PRAS3_M3PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_PRAS3_M3PR_bf(const void *const hw, hri_matrix_pras3_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS3 ^= MATRIX_PRAS3_M3PR(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras3_reg_t hri_matrix_read_PRAS3_M3PR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS3;
	tmp = (tmp & MATRIX_PRAS3_M3PR_Msk) >> MATRIX_PRAS3_M3PR_Pos;
	return tmp;
}

static inline void hri_matrix_set_PRAS3_reg(const void *const hw, hri_matrix_pras3_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS3 |= mask;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras3_reg_t hri_matrix_get_PRAS3_reg(const void *const hw, hri_matrix_pras3_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_PRAS3;
	tmp &= mask;
	return tmp;
}

static inline void hri_matrix_write_PRAS3_reg(const void *const hw, hri_matrix_pras3_reg_t data)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS3 = data;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_PRAS3_reg(const void *const hw, hri_matrix_pras3_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS3 &= ~mask;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_PRAS3_reg(const void *const hw, hri_matrix_pras3_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_PRAS3 ^= mask;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_pras3_reg_t hri_matrix_read_PRAS3_reg(const void *const hw)
{
	return ((Matrix *)hw)->MATRIX_PRAS3;
}

static inline void hri_matrix_set_CCFG_SYSIO_SYSIO4_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_SYSIO |= CCFG_SYSIO_SYSIO4;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_matrix_get_CCFG_SYSIO_SYSIO4_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->CCFG_SYSIO;
	tmp = (tmp & CCFG_SYSIO_SYSIO4) >> CCFG_SYSIO_SYSIO4_Pos;
	return (bool)tmp;
}

static inline void hri_matrix_write_CCFG_SYSIO_SYSIO4_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->CCFG_SYSIO;
	tmp &= ~CCFG_SYSIO_SYSIO4;
	tmp |= value << CCFG_SYSIO_SYSIO4_Pos;
	((Matrix *)hw)->CCFG_SYSIO = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_CCFG_SYSIO_SYSIO4_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_SYSIO &= ~CCFG_SYSIO_SYSIO4;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_CCFG_SYSIO_SYSIO4_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_SYSIO ^= CCFG_SYSIO_SYSIO4;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_set_CCFG_SYSIO_SYSIO5_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_SYSIO |= CCFG_SYSIO_SYSIO5;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_matrix_get_CCFG_SYSIO_SYSIO5_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->CCFG_SYSIO;
	tmp = (tmp & CCFG_SYSIO_SYSIO5) >> CCFG_SYSIO_SYSIO5_Pos;
	return (bool)tmp;
}

static inline void hri_matrix_write_CCFG_SYSIO_SYSIO5_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->CCFG_SYSIO;
	tmp &= ~CCFG_SYSIO_SYSIO5;
	tmp |= value << CCFG_SYSIO_SYSIO5_Pos;
	((Matrix *)hw)->CCFG_SYSIO = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_CCFG_SYSIO_SYSIO5_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_SYSIO &= ~CCFG_SYSIO_SYSIO5;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_CCFG_SYSIO_SYSIO5_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_SYSIO ^= CCFG_SYSIO_SYSIO5;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_set_CCFG_SYSIO_SYSIO6_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_SYSIO |= CCFG_SYSIO_SYSIO6;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_matrix_get_CCFG_SYSIO_SYSIO6_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->CCFG_SYSIO;
	tmp = (tmp & CCFG_SYSIO_SYSIO6) >> CCFG_SYSIO_SYSIO6_Pos;
	return (bool)tmp;
}

static inline void hri_matrix_write_CCFG_SYSIO_SYSIO6_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->CCFG_SYSIO;
	tmp &= ~CCFG_SYSIO_SYSIO6;
	tmp |= value << CCFG_SYSIO_SYSIO6_Pos;
	((Matrix *)hw)->CCFG_SYSIO = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_CCFG_SYSIO_SYSIO6_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_SYSIO &= ~CCFG_SYSIO_SYSIO6;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_CCFG_SYSIO_SYSIO6_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_SYSIO ^= CCFG_SYSIO_SYSIO6;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_set_CCFG_SYSIO_SYSIO7_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_SYSIO |= CCFG_SYSIO_SYSIO7;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_matrix_get_CCFG_SYSIO_SYSIO7_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->CCFG_SYSIO;
	tmp = (tmp & CCFG_SYSIO_SYSIO7) >> CCFG_SYSIO_SYSIO7_Pos;
	return (bool)tmp;
}

static inline void hri_matrix_write_CCFG_SYSIO_SYSIO7_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->CCFG_SYSIO;
	tmp &= ~CCFG_SYSIO_SYSIO7;
	tmp |= value << CCFG_SYSIO_SYSIO7_Pos;
	((Matrix *)hw)->CCFG_SYSIO = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_CCFG_SYSIO_SYSIO7_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_SYSIO &= ~CCFG_SYSIO_SYSIO7;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_CCFG_SYSIO_SYSIO7_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_SYSIO ^= CCFG_SYSIO_SYSIO7;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_set_CCFG_SYSIO_SYSIO10_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_SYSIO |= CCFG_SYSIO_SYSIO10;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_matrix_get_CCFG_SYSIO_SYSIO10_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->CCFG_SYSIO;
	tmp = (tmp & CCFG_SYSIO_SYSIO10) >> CCFG_SYSIO_SYSIO10_Pos;
	return (bool)tmp;
}

static inline void hri_matrix_write_CCFG_SYSIO_SYSIO10_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->CCFG_SYSIO;
	tmp &= ~CCFG_SYSIO_SYSIO10;
	tmp |= value << CCFG_SYSIO_SYSIO10_Pos;
	((Matrix *)hw)->CCFG_SYSIO = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_CCFG_SYSIO_SYSIO10_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_SYSIO &= ~CCFG_SYSIO_SYSIO10;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_CCFG_SYSIO_SYSIO10_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_SYSIO ^= CCFG_SYSIO_SYSIO10;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_set_CCFG_SYSIO_SYSIO11_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_SYSIO |= CCFG_SYSIO_SYSIO11;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_matrix_get_CCFG_SYSIO_SYSIO11_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->CCFG_SYSIO;
	tmp = (tmp & CCFG_SYSIO_SYSIO11) >> CCFG_SYSIO_SYSIO11_Pos;
	return (bool)tmp;
}

static inline void hri_matrix_write_CCFG_SYSIO_SYSIO11_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->CCFG_SYSIO;
	tmp &= ~CCFG_SYSIO_SYSIO11;
	tmp |= value << CCFG_SYSIO_SYSIO11_Pos;
	((Matrix *)hw)->CCFG_SYSIO = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_CCFG_SYSIO_SYSIO11_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_SYSIO &= ~CCFG_SYSIO_SYSIO11;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_CCFG_SYSIO_SYSIO11_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_SYSIO ^= CCFG_SYSIO_SYSIO11;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_set_CCFG_SYSIO_SYSIO12_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_SYSIO |= CCFG_SYSIO_SYSIO12;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_matrix_get_CCFG_SYSIO_SYSIO12_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->CCFG_SYSIO;
	tmp = (tmp & CCFG_SYSIO_SYSIO12) >> CCFG_SYSIO_SYSIO12_Pos;
	return (bool)tmp;
}

static inline void hri_matrix_write_CCFG_SYSIO_SYSIO12_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->CCFG_SYSIO;
	tmp &= ~CCFG_SYSIO_SYSIO12;
	tmp |= value << CCFG_SYSIO_SYSIO12_Pos;
	((Matrix *)hw)->CCFG_SYSIO = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_CCFG_SYSIO_SYSIO12_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_SYSIO &= ~CCFG_SYSIO_SYSIO12;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_CCFG_SYSIO_SYSIO12_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_SYSIO ^= CCFG_SYSIO_SYSIO12;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_set_CCFG_SYSIO_reg(const void *const hw, hri_matrix_ccfg_sysio_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_SYSIO |= mask;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_ccfg_sysio_reg_t hri_matrix_get_CCFG_SYSIO_reg(const void *const           hw,
                                                                        hri_matrix_ccfg_sysio_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->CCFG_SYSIO;
	tmp &= mask;
	return tmp;
}

static inline void hri_matrix_write_CCFG_SYSIO_reg(const void *const hw, hri_matrix_ccfg_sysio_reg_t data)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_SYSIO = data;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_CCFG_SYSIO_reg(const void *const hw, hri_matrix_ccfg_sysio_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_SYSIO &= ~mask;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_CCFG_SYSIO_reg(const void *const hw, hri_matrix_ccfg_sysio_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_SYSIO ^= mask;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_ccfg_sysio_reg_t hri_matrix_read_CCFG_SYSIO_reg(const void *const hw)
{
	return ((Matrix *)hw)->CCFG_SYSIO;
}

static inline void hri_matrix_set_CCFG_DYNCKG_MATCKG_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_DYNCKG |= CCFG_DYNCKG_MATCKG;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_matrix_get_CCFG_DYNCKG_MATCKG_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->CCFG_DYNCKG;
	tmp = (tmp & CCFG_DYNCKG_MATCKG) >> CCFG_DYNCKG_MATCKG_Pos;
	return (bool)tmp;
}

static inline void hri_matrix_write_CCFG_DYNCKG_MATCKG_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->CCFG_DYNCKG;
	tmp &= ~CCFG_DYNCKG_MATCKG;
	tmp |= value << CCFG_DYNCKG_MATCKG_Pos;
	((Matrix *)hw)->CCFG_DYNCKG = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_CCFG_DYNCKG_MATCKG_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_DYNCKG &= ~CCFG_DYNCKG_MATCKG;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_CCFG_DYNCKG_MATCKG_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_DYNCKG ^= CCFG_DYNCKG_MATCKG;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_set_CCFG_DYNCKG_BRIDCKG_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_DYNCKG |= CCFG_DYNCKG_BRIDCKG;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_matrix_get_CCFG_DYNCKG_BRIDCKG_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->CCFG_DYNCKG;
	tmp = (tmp & CCFG_DYNCKG_BRIDCKG) >> CCFG_DYNCKG_BRIDCKG_Pos;
	return (bool)tmp;
}

static inline void hri_matrix_write_CCFG_DYNCKG_BRIDCKG_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->CCFG_DYNCKG;
	tmp &= ~CCFG_DYNCKG_BRIDCKG;
	tmp |= value << CCFG_DYNCKG_BRIDCKG_Pos;
	((Matrix *)hw)->CCFG_DYNCKG = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_CCFG_DYNCKG_BRIDCKG_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_DYNCKG &= ~CCFG_DYNCKG_BRIDCKG;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_CCFG_DYNCKG_BRIDCKG_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_DYNCKG ^= CCFG_DYNCKG_BRIDCKG;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_set_CCFG_DYNCKG_EFCCKG_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_DYNCKG |= CCFG_DYNCKG_EFCCKG;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_matrix_get_CCFG_DYNCKG_EFCCKG_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->CCFG_DYNCKG;
	tmp = (tmp & CCFG_DYNCKG_EFCCKG) >> CCFG_DYNCKG_EFCCKG_Pos;
	return (bool)tmp;
}

static inline void hri_matrix_write_CCFG_DYNCKG_EFCCKG_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->CCFG_DYNCKG;
	tmp &= ~CCFG_DYNCKG_EFCCKG;
	tmp |= value << CCFG_DYNCKG_EFCCKG_Pos;
	((Matrix *)hw)->CCFG_DYNCKG = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_CCFG_DYNCKG_EFCCKG_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_DYNCKG &= ~CCFG_DYNCKG_EFCCKG;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_CCFG_DYNCKG_EFCCKG_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_DYNCKG ^= CCFG_DYNCKG_EFCCKG;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_set_CCFG_DYNCKG_reg(const void *const hw, hri_matrix_ccfg_dynckg_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_DYNCKG |= mask;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_ccfg_dynckg_reg_t hri_matrix_get_CCFG_DYNCKG_reg(const void *const            hw,
                                                                          hri_matrix_ccfg_dynckg_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->CCFG_DYNCKG;
	tmp &= mask;
	return tmp;
}

static inline void hri_matrix_write_CCFG_DYNCKG_reg(const void *const hw, hri_matrix_ccfg_dynckg_reg_t data)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_DYNCKG = data;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_CCFG_DYNCKG_reg(const void *const hw, hri_matrix_ccfg_dynckg_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_DYNCKG &= ~mask;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_CCFG_DYNCKG_reg(const void *const hw, hri_matrix_ccfg_dynckg_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_DYNCKG ^= mask;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_ccfg_dynckg_reg_t hri_matrix_read_CCFG_DYNCKG_reg(const void *const hw)
{
	return ((Matrix *)hw)->CCFG_DYNCKG;
}

static inline void hri_matrix_set_CCFG_I2SCLKSEL_CLKSEL0_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_I2SCLKSEL |= CCFG_I2SCLKSEL_CLKSEL0;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_matrix_get_CCFG_I2SCLKSEL_CLKSEL0_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->CCFG_I2SCLKSEL;
	tmp = (tmp & CCFG_I2SCLKSEL_CLKSEL0) >> CCFG_I2SCLKSEL_CLKSEL0_Pos;
	return (bool)tmp;
}

static inline void hri_matrix_write_CCFG_I2SCLKSEL_CLKSEL0_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->CCFG_I2SCLKSEL;
	tmp &= ~CCFG_I2SCLKSEL_CLKSEL0;
	tmp |= value << CCFG_I2SCLKSEL_CLKSEL0_Pos;
	((Matrix *)hw)->CCFG_I2SCLKSEL = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_CCFG_I2SCLKSEL_CLKSEL0_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_I2SCLKSEL &= ~CCFG_I2SCLKSEL_CLKSEL0;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_CCFG_I2SCLKSEL_CLKSEL0_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_I2SCLKSEL ^= CCFG_I2SCLKSEL_CLKSEL0;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_set_CCFG_I2SCLKSEL_CLKSEL1_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_I2SCLKSEL |= CCFG_I2SCLKSEL_CLKSEL1;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_matrix_get_CCFG_I2SCLKSEL_CLKSEL1_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->CCFG_I2SCLKSEL;
	tmp = (tmp & CCFG_I2SCLKSEL_CLKSEL1) >> CCFG_I2SCLKSEL_CLKSEL1_Pos;
	return (bool)tmp;
}

static inline void hri_matrix_write_CCFG_I2SCLKSEL_CLKSEL1_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->CCFG_I2SCLKSEL;
	tmp &= ~CCFG_I2SCLKSEL_CLKSEL1;
	tmp |= value << CCFG_I2SCLKSEL_CLKSEL1_Pos;
	((Matrix *)hw)->CCFG_I2SCLKSEL = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_CCFG_I2SCLKSEL_CLKSEL1_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_I2SCLKSEL &= ~CCFG_I2SCLKSEL_CLKSEL1;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_CCFG_I2SCLKSEL_CLKSEL1_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_I2SCLKSEL ^= CCFG_I2SCLKSEL_CLKSEL1;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_set_CCFG_I2SCLKSEL_reg(const void *const hw, hri_matrix_ccfg_i2sclksel_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_I2SCLKSEL |= mask;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_ccfg_i2sclksel_reg_t hri_matrix_get_CCFG_I2SCLKSEL_reg(const void *const               hw,
                                                                                hri_matrix_ccfg_i2sclksel_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->CCFG_I2SCLKSEL;
	tmp &= mask;
	return tmp;
}

static inline void hri_matrix_write_CCFG_I2SCLKSEL_reg(const void *const hw, hri_matrix_ccfg_i2sclksel_reg_t data)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_I2SCLKSEL = data;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_CCFG_I2SCLKSEL_reg(const void *const hw, hri_matrix_ccfg_i2sclksel_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_I2SCLKSEL &= ~mask;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_CCFG_I2SCLKSEL_reg(const void *const hw, hri_matrix_ccfg_i2sclksel_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_I2SCLKSEL ^= mask;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_ccfg_i2sclksel_reg_t hri_matrix_read_CCFG_I2SCLKSEL_reg(const void *const hw)
{
	return ((Matrix *)hw)->CCFG_I2SCLKSEL;
}

static inline void hri_matrix_set_CCFG_USBMR_USBMODE_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_USBMR |= CCFG_USBMR_USBMODE;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_matrix_get_CCFG_USBMR_USBMODE_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->CCFG_USBMR;
	tmp = (tmp & CCFG_USBMR_USBMODE) >> CCFG_USBMR_USBMODE_Pos;
	return (bool)tmp;
}

static inline void hri_matrix_write_CCFG_USBMR_USBMODE_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->CCFG_USBMR;
	tmp &= ~CCFG_USBMR_USBMODE;
	tmp |= value << CCFG_USBMR_USBMODE_Pos;
	((Matrix *)hw)->CCFG_USBMR = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_CCFG_USBMR_USBMODE_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_USBMR &= ~CCFG_USBMR_USBMODE;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_CCFG_USBMR_USBMODE_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_USBMR ^= CCFG_USBMR_USBMODE;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_set_CCFG_USBMR_USBHTSSC_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_USBMR |= CCFG_USBMR_USBHTSSC;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_matrix_get_CCFG_USBMR_USBHTSSC_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->CCFG_USBMR;
	tmp = (tmp & CCFG_USBMR_USBHTSSC) >> CCFG_USBMR_USBHTSSC_Pos;
	return (bool)tmp;
}

static inline void hri_matrix_write_CCFG_USBMR_USBHTSSC_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->CCFG_USBMR;
	tmp &= ~CCFG_USBMR_USBHTSSC;
	tmp |= value << CCFG_USBMR_USBHTSSC_Pos;
	((Matrix *)hw)->CCFG_USBMR = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_CCFG_USBMR_USBHTSSC_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_USBMR &= ~CCFG_USBMR_USBHTSSC;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_CCFG_USBMR_USBHTSSC_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_USBMR ^= CCFG_USBMR_USBHTSSC;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_set_CCFG_USBMR_USBHTSC_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_USBMR |= CCFG_USBMR_USBHTSC;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_matrix_get_CCFG_USBMR_USBHTSC_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->CCFG_USBMR;
	tmp = (tmp & CCFG_USBMR_USBHTSC) >> CCFG_USBMR_USBHTSC_Pos;
	return (bool)tmp;
}

static inline void hri_matrix_write_CCFG_USBMR_USBHTSC_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->CCFG_USBMR;
	tmp &= ~CCFG_USBMR_USBHTSC;
	tmp |= value << CCFG_USBMR_USBHTSC_Pos;
	((Matrix *)hw)->CCFG_USBMR = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_CCFG_USBMR_USBHTSC_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_USBMR &= ~CCFG_USBMR_USBHTSC;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_CCFG_USBMR_USBHTSC_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_USBMR ^= CCFG_USBMR_USBHTSC;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_set_CCFG_USBMR_reg(const void *const hw, hri_matrix_ccfg_usbmr_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_USBMR |= mask;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_ccfg_usbmr_reg_t hri_matrix_get_CCFG_USBMR_reg(const void *const           hw,
                                                                        hri_matrix_ccfg_usbmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->CCFG_USBMR;
	tmp &= mask;
	return tmp;
}

static inline void hri_matrix_write_CCFG_USBMR_reg(const void *const hw, hri_matrix_ccfg_usbmr_reg_t data)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_USBMR = data;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_CCFG_USBMR_reg(const void *const hw, hri_matrix_ccfg_usbmr_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_USBMR &= ~mask;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_CCFG_USBMR_reg(const void *const hw, hri_matrix_ccfg_usbmr_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->CCFG_USBMR ^= mask;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_ccfg_usbmr_reg_t hri_matrix_read_CCFG_USBMR_reg(const void *const hw)
{
	return ((Matrix *)hw)->CCFG_USBMR;
}

static inline void hri_matrix_set_WPMR_WPEN_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_WPMR |= MATRIX_WPMR_WPEN;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_matrix_get_WPMR_WPEN_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_WPMR;
	tmp = (tmp & MATRIX_WPMR_WPEN) >> MATRIX_WPMR_WPEN_Pos;
	return (bool)tmp;
}

static inline void hri_matrix_write_WPMR_WPEN_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->MATRIX_WPMR;
	tmp &= ~MATRIX_WPMR_WPEN;
	tmp |= value << MATRIX_WPMR_WPEN_Pos;
	((Matrix *)hw)->MATRIX_WPMR = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_WPMR_WPEN_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_WPMR &= ~MATRIX_WPMR_WPEN;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_WPMR_WPEN_bit(const void *const hw)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_WPMR ^= MATRIX_WPMR_WPEN;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_set_WPMR_WPKEY_bf(const void *const hw, hri_matrix_wpmr_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_WPMR |= MATRIX_WPMR_WPKEY(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_wpmr_reg_t hri_matrix_get_WPMR_WPKEY_bf(const void *const hw, hri_matrix_wpmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_WPMR;
	tmp = (tmp & MATRIX_WPMR_WPKEY(mask)) >> MATRIX_WPMR_WPKEY_Pos;
	return tmp;
}

static inline void hri_matrix_write_WPMR_WPKEY_bf(const void *const hw, hri_matrix_wpmr_reg_t data)
{
	uint32_t tmp;
	MATRIX_CRITICAL_SECTION_ENTER();
	tmp = ((Matrix *)hw)->MATRIX_WPMR;
	tmp &= ~MATRIX_WPMR_WPKEY_Msk;
	tmp |= MATRIX_WPMR_WPKEY(data);
	((Matrix *)hw)->MATRIX_WPMR = tmp;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_WPMR_WPKEY_bf(const void *const hw, hri_matrix_wpmr_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_WPMR &= ~MATRIX_WPMR_WPKEY(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_WPMR_WPKEY_bf(const void *const hw, hri_matrix_wpmr_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_WPMR ^= MATRIX_WPMR_WPKEY(mask);
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_wpmr_reg_t hri_matrix_read_WPMR_WPKEY_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_WPMR;
	tmp = (tmp & MATRIX_WPMR_WPKEY_Msk) >> MATRIX_WPMR_WPKEY_Pos;
	return tmp;
}

static inline void hri_matrix_set_WPMR_reg(const void *const hw, hri_matrix_wpmr_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_WPMR |= mask;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_wpmr_reg_t hri_matrix_get_WPMR_reg(const void *const hw, hri_matrix_wpmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_WPMR;
	tmp &= mask;
	return tmp;
}

static inline void hri_matrix_write_WPMR_reg(const void *const hw, hri_matrix_wpmr_reg_t data)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_WPMR = data;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_clear_WPMR_reg(const void *const hw, hri_matrix_wpmr_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_WPMR &= ~mask;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline void hri_matrix_toggle_WPMR_reg(const void *const hw, hri_matrix_wpmr_reg_t mask)
{
	MATRIX_CRITICAL_SECTION_ENTER();
	((Matrix *)hw)->MATRIX_WPMR ^= mask;
	MATRIX_CRITICAL_SECTION_LEAVE();
}

static inline hri_matrix_wpmr_reg_t hri_matrix_read_WPMR_reg(const void *const hw)
{
	return ((Matrix *)hw)->MATRIX_WPMR;
}

static inline bool hri_matrix_get_WPSR_WPVS_bit(const void *const hw)
{
	return (((Matrix *)hw)->MATRIX_WPSR & MATRIX_WPSR_WPVS) > 0;
}

static inline hri_matrix_wpsr_reg_t hri_matrix_get_WPSR_WPVSRC_bf(const void *const hw, hri_matrix_wpsr_reg_t mask)
{
	return (((Matrix *)hw)->MATRIX_WPSR & MATRIX_WPSR_WPVSRC(mask)) >> MATRIX_WPSR_WPVSRC_Pos;
}

static inline hri_matrix_wpsr_reg_t hri_matrix_read_WPSR_WPVSRC_bf(const void *const hw)
{
	return (((Matrix *)hw)->MATRIX_WPSR & MATRIX_WPSR_WPVSRC_Msk) >> MATRIX_WPSR_WPVSRC_Pos;
}

static inline hri_matrix_wpsr_reg_t hri_matrix_get_WPSR_reg(const void *const hw, hri_matrix_wpsr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Matrix *)hw)->MATRIX_WPSR;
	tmp &= mask;
	return tmp;
}

static inline hri_matrix_wpsr_reg_t hri_matrix_read_WPSR_reg(const void *const hw)
{
	return ((Matrix *)hw)->MATRIX_WPSR;
}

#ifdef __cplusplus
}
#endif

#endif /* _HRI_MATRIX_G55_H_INCLUDED */
#endif /* _SAMG55_MATRIX_COMPONENT_ */
