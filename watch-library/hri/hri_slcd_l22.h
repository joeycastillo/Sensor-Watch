/**
 * \file
 *
 * \brief SAM SLCD
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
 *
 */

#ifdef _SAML22_SLCD_COMPONENT_
#ifndef _HRI_SLCD_L22_H_INCLUDED_
#define _HRI_SLCD_L22_H_INCLUDED_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <hal_atomic.h>

#if defined(ENABLE_SLCD_CRITICAL_SECTIONS)
#define SLCD_CRITICAL_SECTION_ENTER() CRITICAL_SECTION_ENTER()
#define SLCD_CRITICAL_SECTION_LEAVE() CRITICAL_SECTION_LEAVE()
#else
#define SLCD_CRITICAL_SECTION_ENTER()
#define SLCD_CRITICAL_SECTION_LEAVE()
#endif

typedef uint16_t hri_slcd_cmindex_reg_t;
typedef uint16_t hri_slcd_ctrlb_reg_t;
typedef uint16_t hri_slcd_ctrlc_reg_t;
typedef uint32_t hri_slcd_acmcfg_reg_t;
typedef uint32_t hri_slcd_bcfg_reg_t;
typedef uint32_t hri_slcd_cmdata_reg_t;
typedef uint32_t hri_slcd_cmdmask_reg_t;
typedef uint32_t hri_slcd_csrcfg_reg_t;
typedef uint32_t hri_slcd_ctrla_reg_t;
typedef uint32_t hri_slcd_isdata_reg_t;
typedef uint32_t hri_slcd_lpenh_reg_t;
typedef uint32_t hri_slcd_lpenl_reg_t;
typedef uint32_t hri_slcd_sdatah0_reg_t;
typedef uint32_t hri_slcd_sdatah1_reg_t;
typedef uint32_t hri_slcd_sdatah2_reg_t;
typedef uint32_t hri_slcd_sdatah3_reg_t;
typedef uint32_t hri_slcd_sdatah4_reg_t;
typedef uint32_t hri_slcd_sdatah5_reg_t;
typedef uint32_t hri_slcd_sdatah6_reg_t;
typedef uint32_t hri_slcd_sdatah7_reg_t;
typedef uint32_t hri_slcd_sdatal0_reg_t;
typedef uint32_t hri_slcd_sdatal1_reg_t;
typedef uint32_t hri_slcd_sdatal2_reg_t;
typedef uint32_t hri_slcd_sdatal3_reg_t;
typedef uint32_t hri_slcd_sdatal4_reg_t;
typedef uint32_t hri_slcd_sdatal5_reg_t;
typedef uint32_t hri_slcd_sdatal6_reg_t;
typedef uint32_t hri_slcd_sdatal7_reg_t;
typedef uint32_t hri_slcd_syncbusy_reg_t;
typedef uint8_t  hri_slcd_abmcfg_reg_t;
typedef uint8_t  hri_slcd_cmcfg_reg_t;
typedef uint8_t  hri_slcd_ctrld_reg_t;
typedef uint8_t  hri_slcd_evctrl_reg_t;
typedef uint8_t  hri_slcd_fc0_reg_t;
typedef uint8_t  hri_slcd_fc1_reg_t;
typedef uint8_t  hri_slcd_fc2_reg_t;
typedef uint8_t  hri_slcd_intenset_reg_t;
typedef uint8_t  hri_slcd_intflag_reg_t;
typedef uint8_t  hri_slcd_status_reg_t;

static inline void hri_slcd_wait_for_sync(const void *const hw, hri_slcd_syncbusy_reg_t reg)
{
	while (((Slcd *)hw)->SYNCBUSY.reg & reg) {
	};
}

static inline bool hri_slcd_is_syncing(const void *const hw, hri_slcd_syncbusy_reg_t reg)
{
	return ((Slcd *)hw)->SYNCBUSY.reg & reg;
}

static inline bool hri_slcd_get_INTFLAG_FC0O_bit(const void *const hw)
{
	return (((Slcd *)hw)->INTFLAG.reg & SLCD_INTFLAG_FC0O) >> SLCD_INTFLAG_FC0O_Pos;
}

static inline void hri_slcd_clear_INTFLAG_FC0O_bit(const void *const hw)
{
	((Slcd *)hw)->INTFLAG.reg = SLCD_INTFLAG_FC0O;
}

static inline bool hri_slcd_get_INTFLAG_FC1O_bit(const void *const hw)
{
	return (((Slcd *)hw)->INTFLAG.reg & SLCD_INTFLAG_FC1O) >> SLCD_INTFLAG_FC1O_Pos;
}

static inline void hri_slcd_clear_INTFLAG_FC1O_bit(const void *const hw)
{
	((Slcd *)hw)->INTFLAG.reg = SLCD_INTFLAG_FC1O;
}

static inline bool hri_slcd_get_INTFLAG_FC2O_bit(const void *const hw)
{
	return (((Slcd *)hw)->INTFLAG.reg & SLCD_INTFLAG_FC2O) >> SLCD_INTFLAG_FC2O_Pos;
}

static inline void hri_slcd_clear_INTFLAG_FC2O_bit(const void *const hw)
{
	((Slcd *)hw)->INTFLAG.reg = SLCD_INTFLAG_FC2O;
}

static inline bool hri_slcd_get_INTFLAG_VLCDRT_bit(const void *const hw)
{
	return (((Slcd *)hw)->INTFLAG.reg & SLCD_INTFLAG_VLCDRT) >> SLCD_INTFLAG_VLCDRT_Pos;
}

static inline void hri_slcd_clear_INTFLAG_VLCDRT_bit(const void *const hw)
{
	((Slcd *)hw)->INTFLAG.reg = SLCD_INTFLAG_VLCDRT;
}

static inline bool hri_slcd_get_INTFLAG_VLCDST_bit(const void *const hw)
{
	return (((Slcd *)hw)->INTFLAG.reg & SLCD_INTFLAG_VLCDST) >> SLCD_INTFLAG_VLCDST_Pos;
}

static inline void hri_slcd_clear_INTFLAG_VLCDST_bit(const void *const hw)
{
	((Slcd *)hw)->INTFLAG.reg = SLCD_INTFLAG_VLCDST;
}

static inline bool hri_slcd_get_INTFLAG_PRST_bit(const void *const hw)
{
	return (((Slcd *)hw)->INTFLAG.reg & SLCD_INTFLAG_PRST) >> SLCD_INTFLAG_PRST_Pos;
}

static inline void hri_slcd_clear_INTFLAG_PRST_bit(const void *const hw)
{
	((Slcd *)hw)->INTFLAG.reg = SLCD_INTFLAG_PRST;
}

static inline bool hri_slcd_get_interrupt_FC0O_bit(const void *const hw)
{
	return (((Slcd *)hw)->INTFLAG.reg & SLCD_INTFLAG_FC0O) >> SLCD_INTFLAG_FC0O_Pos;
}

static inline void hri_slcd_clear_interrupt_FC0O_bit(const void *const hw)
{
	((Slcd *)hw)->INTFLAG.reg = SLCD_INTFLAG_FC0O;
}

static inline bool hri_slcd_get_interrupt_FC1O_bit(const void *const hw)
{
	return (((Slcd *)hw)->INTFLAG.reg & SLCD_INTFLAG_FC1O) >> SLCD_INTFLAG_FC1O_Pos;
}

static inline void hri_slcd_clear_interrupt_FC1O_bit(const void *const hw)
{
	((Slcd *)hw)->INTFLAG.reg = SLCD_INTFLAG_FC1O;
}

static inline bool hri_slcd_get_interrupt_FC2O_bit(const void *const hw)
{
	return (((Slcd *)hw)->INTFLAG.reg & SLCD_INTFLAG_FC2O) >> SLCD_INTFLAG_FC2O_Pos;
}

static inline void hri_slcd_clear_interrupt_FC2O_bit(const void *const hw)
{
	((Slcd *)hw)->INTFLAG.reg = SLCD_INTFLAG_FC2O;
}

static inline bool hri_slcd_get_interrupt_VLCDRT_bit(const void *const hw)
{
	return (((Slcd *)hw)->INTFLAG.reg & SLCD_INTFLAG_VLCDRT) >> SLCD_INTFLAG_VLCDRT_Pos;
}

static inline void hri_slcd_clear_interrupt_VLCDRT_bit(const void *const hw)
{
	((Slcd *)hw)->INTFLAG.reg = SLCD_INTFLAG_VLCDRT;
}

static inline bool hri_slcd_get_interrupt_VLCDST_bit(const void *const hw)
{
	return (((Slcd *)hw)->INTFLAG.reg & SLCD_INTFLAG_VLCDST) >> SLCD_INTFLAG_VLCDST_Pos;
}

static inline void hri_slcd_clear_interrupt_VLCDST_bit(const void *const hw)
{
	((Slcd *)hw)->INTFLAG.reg = SLCD_INTFLAG_VLCDST;
}

static inline bool hri_slcd_get_interrupt_PRST_bit(const void *const hw)
{
	return (((Slcd *)hw)->INTFLAG.reg & SLCD_INTFLAG_PRST) >> SLCD_INTFLAG_PRST_Pos;
}

static inline void hri_slcd_clear_interrupt_PRST_bit(const void *const hw)
{
	((Slcd *)hw)->INTFLAG.reg = SLCD_INTFLAG_PRST;
}

static inline hri_slcd_intflag_reg_t hri_slcd_get_INTFLAG_reg(const void *const hw, hri_slcd_intflag_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Slcd *)hw)->INTFLAG.reg;
	tmp &= mask;
	return tmp;
}

static inline hri_slcd_intflag_reg_t hri_slcd_read_INTFLAG_reg(const void *const hw)
{
	return ((Slcd *)hw)->INTFLAG.reg;
}

static inline void hri_slcd_clear_INTFLAG_reg(const void *const hw, hri_slcd_intflag_reg_t mask)
{
	((Slcd *)hw)->INTFLAG.reg = mask;
}

static inline void hri_slcd_set_INTEN_FC0O_bit(const void *const hw)
{
	((Slcd *)hw)->INTENSET.reg = SLCD_INTENSET_FC0O;
}

static inline bool hri_slcd_get_INTEN_FC0O_bit(const void *const hw)
{
	return (((Slcd *)hw)->INTENSET.reg & SLCD_INTENSET_FC0O) >> SLCD_INTENSET_FC0O_Pos;
}

static inline void hri_slcd_write_INTEN_FC0O_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Slcd *)hw)->INTENCLR.reg = SLCD_INTENSET_FC0O;
	} else {
		((Slcd *)hw)->INTENSET.reg = SLCD_INTENSET_FC0O;
	}
}

static inline void hri_slcd_clear_INTEN_FC0O_bit(const void *const hw)
{
	((Slcd *)hw)->INTENCLR.reg = SLCD_INTENSET_FC0O;
}

static inline void hri_slcd_set_INTEN_FC1O_bit(const void *const hw)
{
	((Slcd *)hw)->INTENSET.reg = SLCD_INTENSET_FC1O;
}

static inline bool hri_slcd_get_INTEN_FC1O_bit(const void *const hw)
{
	return (((Slcd *)hw)->INTENSET.reg & SLCD_INTENSET_FC1O) >> SLCD_INTENSET_FC1O_Pos;
}

static inline void hri_slcd_write_INTEN_FC1O_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Slcd *)hw)->INTENCLR.reg = SLCD_INTENSET_FC1O;
	} else {
		((Slcd *)hw)->INTENSET.reg = SLCD_INTENSET_FC1O;
	}
}

static inline void hri_slcd_clear_INTEN_FC1O_bit(const void *const hw)
{
	((Slcd *)hw)->INTENCLR.reg = SLCD_INTENSET_FC1O;
}

static inline void hri_slcd_set_INTEN_FC2O_bit(const void *const hw)
{
	((Slcd *)hw)->INTENSET.reg = SLCD_INTENSET_FC2O;
}

static inline bool hri_slcd_get_INTEN_FC2O_bit(const void *const hw)
{
	return (((Slcd *)hw)->INTENSET.reg & SLCD_INTENSET_FC2O) >> SLCD_INTENSET_FC2O_Pos;
}

static inline void hri_slcd_write_INTEN_FC2O_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Slcd *)hw)->INTENCLR.reg = SLCD_INTENSET_FC2O;
	} else {
		((Slcd *)hw)->INTENSET.reg = SLCD_INTENSET_FC2O;
	}
}

static inline void hri_slcd_clear_INTEN_FC2O_bit(const void *const hw)
{
	((Slcd *)hw)->INTENCLR.reg = SLCD_INTENSET_FC2O;
}

static inline void hri_slcd_set_INTEN_VLCDRT_bit(const void *const hw)
{
	((Slcd *)hw)->INTENSET.reg = SLCD_INTENSET_VLCDRT;
}

static inline bool hri_slcd_get_INTEN_VLCDRT_bit(const void *const hw)
{
	return (((Slcd *)hw)->INTENSET.reg & SLCD_INTENSET_VLCDRT) >> SLCD_INTENSET_VLCDRT_Pos;
}

static inline void hri_slcd_write_INTEN_VLCDRT_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Slcd *)hw)->INTENCLR.reg = SLCD_INTENSET_VLCDRT;
	} else {
		((Slcd *)hw)->INTENSET.reg = SLCD_INTENSET_VLCDRT;
	}
}

static inline void hri_slcd_clear_INTEN_VLCDRT_bit(const void *const hw)
{
	((Slcd *)hw)->INTENCLR.reg = SLCD_INTENSET_VLCDRT;
}

static inline void hri_slcd_set_INTEN_VLCDST_bit(const void *const hw)
{
	((Slcd *)hw)->INTENSET.reg = SLCD_INTENSET_VLCDST;
}

static inline bool hri_slcd_get_INTEN_VLCDST_bit(const void *const hw)
{
	return (((Slcd *)hw)->INTENSET.reg & SLCD_INTENSET_VLCDST) >> SLCD_INTENSET_VLCDST_Pos;
}

static inline void hri_slcd_write_INTEN_VLCDST_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Slcd *)hw)->INTENCLR.reg = SLCD_INTENSET_VLCDST;
	} else {
		((Slcd *)hw)->INTENSET.reg = SLCD_INTENSET_VLCDST;
	}
}

static inline void hri_slcd_clear_INTEN_VLCDST_bit(const void *const hw)
{
	((Slcd *)hw)->INTENCLR.reg = SLCD_INTENSET_VLCDST;
}

static inline void hri_slcd_set_INTEN_PRST_bit(const void *const hw)
{
	((Slcd *)hw)->INTENSET.reg = SLCD_INTENSET_PRST;
}

static inline bool hri_slcd_get_INTEN_PRST_bit(const void *const hw)
{
	return (((Slcd *)hw)->INTENSET.reg & SLCD_INTENSET_PRST) >> SLCD_INTENSET_PRST_Pos;
}

static inline void hri_slcd_write_INTEN_PRST_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Slcd *)hw)->INTENCLR.reg = SLCD_INTENSET_PRST;
	} else {
		((Slcd *)hw)->INTENSET.reg = SLCD_INTENSET_PRST;
	}
}

static inline void hri_slcd_clear_INTEN_PRST_bit(const void *const hw)
{
	((Slcd *)hw)->INTENCLR.reg = SLCD_INTENSET_PRST;
}

static inline void hri_slcd_set_INTEN_reg(const void *const hw, hri_slcd_intenset_reg_t mask)
{
	((Slcd *)hw)->INTENSET.reg = mask;
}

static inline hri_slcd_intenset_reg_t hri_slcd_get_INTEN_reg(const void *const hw, hri_slcd_intenset_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Slcd *)hw)->INTENSET.reg;
	tmp &= mask;
	return tmp;
}

static inline hri_slcd_intenset_reg_t hri_slcd_read_INTEN_reg(const void *const hw)
{
	return ((Slcd *)hw)->INTENSET.reg;
}

static inline void hri_slcd_write_INTEN_reg(const void *const hw, hri_slcd_intenset_reg_t data)
{
	((Slcd *)hw)->INTENSET.reg = data;
	((Slcd *)hw)->INTENCLR.reg = ~data;
}

static inline void hri_slcd_clear_INTEN_reg(const void *const hw, hri_slcd_intenset_reg_t mask)
{
	((Slcd *)hw)->INTENCLR.reg = mask;
}

static inline bool hri_slcd_get_STATUS_VLCDR_bit(const void *const hw)
{
	return (((Slcd *)hw)->STATUS.reg & SLCD_STATUS_VLCDR) >> SLCD_STATUS_VLCDR_Pos;
}

static inline bool hri_slcd_get_STATUS_PRUN_bit(const void *const hw)
{
	return (((Slcd *)hw)->STATUS.reg & SLCD_STATUS_PRUN) >> SLCD_STATUS_PRUN_Pos;
}

static inline bool hri_slcd_get_STATUS_VLCDS_bit(const void *const hw)
{
	return (((Slcd *)hw)->STATUS.reg & SLCD_STATUS_VLCDS) >> SLCD_STATUS_VLCDS_Pos;
}

static inline bool hri_slcd_get_STATUS_CMWRBUSY_bit(const void *const hw)
{
	return (((Slcd *)hw)->STATUS.reg & SLCD_STATUS_CMWRBUSY) >> SLCD_STATUS_CMWRBUSY_Pos;
}

static inline bool hri_slcd_get_STATUS_ACMBUSY_bit(const void *const hw)
{
	return (((Slcd *)hw)->STATUS.reg & SLCD_STATUS_ACMBUSY) >> SLCD_STATUS_ACMBUSY_Pos;
}

static inline bool hri_slcd_get_STATUS_ABMBUSY_bit(const void *const hw)
{
	return (((Slcd *)hw)->STATUS.reg & SLCD_STATUS_ABMBUSY) >> SLCD_STATUS_ABMBUSY_Pos;
}

static inline hri_slcd_status_reg_t hri_slcd_get_STATUS_reg(const void *const hw, hri_slcd_status_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Slcd *)hw)->STATUS.reg;
	tmp &= mask;
	return tmp;
}

static inline hri_slcd_status_reg_t hri_slcd_read_STATUS_reg(const void *const hw)
{
	return ((Slcd *)hw)->STATUS.reg;
}

static inline bool hri_slcd_get_SYNCBUSY_SWRST_bit(const void *const hw)
{
	return (((Slcd *)hw)->SYNCBUSY.reg & SLCD_SYNCBUSY_SWRST) >> SLCD_SYNCBUSY_SWRST_Pos;
}

static inline bool hri_slcd_get_SYNCBUSY_ENABLE_bit(const void *const hw)
{
	return (((Slcd *)hw)->SYNCBUSY.reg & SLCD_SYNCBUSY_ENABLE) >> SLCD_SYNCBUSY_ENABLE_Pos;
}

static inline bool hri_slcd_get_SYNCBUSY_CTRLD_bit(const void *const hw)
{
	return (((Slcd *)hw)->SYNCBUSY.reg & SLCD_SYNCBUSY_CTRLD) >> SLCD_SYNCBUSY_CTRLD_Pos;
}

static inline hri_slcd_syncbusy_reg_t hri_slcd_get_SYNCBUSY_reg(const void *const hw, hri_slcd_syncbusy_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SYNCBUSY.reg;
	tmp &= mask;
	return tmp;
}

static inline hri_slcd_syncbusy_reg_t hri_slcd_read_SYNCBUSY_reg(const void *const hw)
{
	return ((Slcd *)hw)->SYNCBUSY.reg;
}

static inline void hri_slcd_set_CTRLA_SWRST_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg |= SLCD_CTRLA_SWRST;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_SWRST);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_slcd_get_CTRLA_SWRST_bit(const void *const hw)
{
	uint32_t tmp;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_SWRST);
	tmp = ((Slcd *)hw)->CTRLA.reg;
	tmp = (tmp & SLCD_CTRLA_SWRST) >> SLCD_CTRLA_SWRST_Pos;
	return (bool)tmp;
}

static inline void hri_slcd_set_CTRLA_ENABLE_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg |= SLCD_CTRLA_ENABLE;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_SWRST | SLCD_SYNCBUSY_ENABLE);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_slcd_get_CTRLA_ENABLE_bit(const void *const hw)
{
	uint32_t tmp;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_SWRST | SLCD_SYNCBUSY_ENABLE);
	tmp = ((Slcd *)hw)->CTRLA.reg;
	tmp = (tmp & SLCD_CTRLA_ENABLE) >> SLCD_CTRLA_ENABLE_Pos;
	return (bool)tmp;
}

static inline void hri_slcd_write_CTRLA_ENABLE_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CTRLA.reg;
	tmp &= ~SLCD_CTRLA_ENABLE;
	tmp |= value << SLCD_CTRLA_ENABLE_Pos;
	((Slcd *)hw)->CTRLA.reg = tmp;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_SWRST | SLCD_SYNCBUSY_ENABLE);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CTRLA_ENABLE_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg &= ~SLCD_CTRLA_ENABLE;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_SWRST | SLCD_SYNCBUSY_ENABLE);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CTRLA_ENABLE_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg ^= SLCD_CTRLA_ENABLE;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_SWRST | SLCD_SYNCBUSY_ENABLE);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_set_CTRLA_WMOD_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg |= SLCD_CTRLA_WMOD;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_slcd_get_CTRLA_WMOD_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->CTRLA.reg;
	tmp = (tmp & SLCD_CTRLA_WMOD) >> SLCD_CTRLA_WMOD_Pos;
	return (bool)tmp;
}

static inline void hri_slcd_write_CTRLA_WMOD_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CTRLA.reg;
	tmp &= ~SLCD_CTRLA_WMOD;
	tmp |= value << SLCD_CTRLA_WMOD_Pos;
	((Slcd *)hw)->CTRLA.reg = tmp;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CTRLA_WMOD_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg &= ~SLCD_CTRLA_WMOD;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CTRLA_WMOD_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg ^= SLCD_CTRLA_WMOD;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_set_CTRLA_RUNSTDBY_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg |= SLCD_CTRLA_RUNSTDBY;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_slcd_get_CTRLA_RUNSTDBY_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->CTRLA.reg;
	tmp = (tmp & SLCD_CTRLA_RUNSTDBY) >> SLCD_CTRLA_RUNSTDBY_Pos;
	return (bool)tmp;
}

static inline void hri_slcd_write_CTRLA_RUNSTDBY_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CTRLA.reg;
	tmp &= ~SLCD_CTRLA_RUNSTDBY;
	tmp |= value << SLCD_CTRLA_RUNSTDBY_Pos;
	((Slcd *)hw)->CTRLA.reg = tmp;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CTRLA_RUNSTDBY_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg &= ~SLCD_CTRLA_RUNSTDBY;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CTRLA_RUNSTDBY_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg ^= SLCD_CTRLA_RUNSTDBY;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_set_CTRLA_XVLCD_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg |= SLCD_CTRLA_XVLCD;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_slcd_get_CTRLA_XVLCD_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->CTRLA.reg;
	tmp = (tmp & SLCD_CTRLA_XVLCD) >> SLCD_CTRLA_XVLCD_Pos;
	return (bool)tmp;
}

static inline void hri_slcd_write_CTRLA_XVLCD_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CTRLA.reg;
	tmp &= ~SLCD_CTRLA_XVLCD;
	tmp |= value << SLCD_CTRLA_XVLCD_Pos;
	((Slcd *)hw)->CTRLA.reg = tmp;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CTRLA_XVLCD_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg &= ~SLCD_CTRLA_XVLCD;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CTRLA_XVLCD_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg ^= SLCD_CTRLA_XVLCD;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_set_CTRLA_DUTY_bf(const void *const hw, hri_slcd_ctrla_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg |= SLCD_CTRLA_DUTY(mask);
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_ctrla_reg_t hri_slcd_get_CTRLA_DUTY_bf(const void *const hw, hri_slcd_ctrla_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->CTRLA.reg;
	tmp = (tmp & SLCD_CTRLA_DUTY(mask)) >> SLCD_CTRLA_DUTY_Pos;
	return tmp;
}

static inline void hri_slcd_write_CTRLA_DUTY_bf(const void *const hw, hri_slcd_ctrla_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CTRLA.reg;
	tmp &= ~SLCD_CTRLA_DUTY_Msk;
	tmp |= SLCD_CTRLA_DUTY(data);
	((Slcd *)hw)->CTRLA.reg = tmp;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CTRLA_DUTY_bf(const void *const hw, hri_slcd_ctrla_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg &= ~SLCD_CTRLA_DUTY(mask);
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CTRLA_DUTY_bf(const void *const hw, hri_slcd_ctrla_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg ^= SLCD_CTRLA_DUTY(mask);
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_ctrla_reg_t hri_slcd_read_CTRLA_DUTY_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->CTRLA.reg;
	tmp = (tmp & SLCD_CTRLA_DUTY_Msk) >> SLCD_CTRLA_DUTY_Pos;
	return tmp;
}

static inline void hri_slcd_set_CTRLA_PRESC_bf(const void *const hw, hri_slcd_ctrla_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg |= SLCD_CTRLA_PRESC(mask);
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_ctrla_reg_t hri_slcd_get_CTRLA_PRESC_bf(const void *const hw, hri_slcd_ctrla_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->CTRLA.reg;
	tmp = (tmp & SLCD_CTRLA_PRESC(mask)) >> SLCD_CTRLA_PRESC_Pos;
	return tmp;
}

static inline void hri_slcd_write_CTRLA_PRESC_bf(const void *const hw, hri_slcd_ctrla_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CTRLA.reg;
	tmp &= ~SLCD_CTRLA_PRESC_Msk;
	tmp |= SLCD_CTRLA_PRESC(data);
	((Slcd *)hw)->CTRLA.reg = tmp;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CTRLA_PRESC_bf(const void *const hw, hri_slcd_ctrla_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg &= ~SLCD_CTRLA_PRESC(mask);
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CTRLA_PRESC_bf(const void *const hw, hri_slcd_ctrla_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg ^= SLCD_CTRLA_PRESC(mask);
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_ctrla_reg_t hri_slcd_read_CTRLA_PRESC_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->CTRLA.reg;
	tmp = (tmp & SLCD_CTRLA_PRESC_Msk) >> SLCD_CTRLA_PRESC_Pos;
	return tmp;
}

static inline void hri_slcd_set_CTRLA_CKDIV_bf(const void *const hw, hri_slcd_ctrla_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg |= SLCD_CTRLA_CKDIV(mask);
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_ctrla_reg_t hri_slcd_get_CTRLA_CKDIV_bf(const void *const hw, hri_slcd_ctrla_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->CTRLA.reg;
	tmp = (tmp & SLCD_CTRLA_CKDIV(mask)) >> SLCD_CTRLA_CKDIV_Pos;
	return tmp;
}

static inline void hri_slcd_write_CTRLA_CKDIV_bf(const void *const hw, hri_slcd_ctrla_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CTRLA.reg;
	tmp &= ~SLCD_CTRLA_CKDIV_Msk;
	tmp |= SLCD_CTRLA_CKDIV(data);
	((Slcd *)hw)->CTRLA.reg = tmp;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CTRLA_CKDIV_bf(const void *const hw, hri_slcd_ctrla_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg &= ~SLCD_CTRLA_CKDIV(mask);
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CTRLA_CKDIV_bf(const void *const hw, hri_slcd_ctrla_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg ^= SLCD_CTRLA_CKDIV(mask);
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_ctrla_reg_t hri_slcd_read_CTRLA_CKDIV_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->CTRLA.reg;
	tmp = (tmp & SLCD_CTRLA_CKDIV_Msk) >> SLCD_CTRLA_CKDIV_Pos;
	return tmp;
}

static inline void hri_slcd_set_CTRLA_BIAS_bf(const void *const hw, hri_slcd_ctrla_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg |= SLCD_CTRLA_BIAS(mask);
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_ctrla_reg_t hri_slcd_get_CTRLA_BIAS_bf(const void *const hw, hri_slcd_ctrla_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->CTRLA.reg;
	tmp = (tmp & SLCD_CTRLA_BIAS(mask)) >> SLCD_CTRLA_BIAS_Pos;
	return tmp;
}

static inline void hri_slcd_write_CTRLA_BIAS_bf(const void *const hw, hri_slcd_ctrla_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CTRLA.reg;
	tmp &= ~SLCD_CTRLA_BIAS_Msk;
	tmp |= SLCD_CTRLA_BIAS(data);
	((Slcd *)hw)->CTRLA.reg = tmp;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CTRLA_BIAS_bf(const void *const hw, hri_slcd_ctrla_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg &= ~SLCD_CTRLA_BIAS(mask);
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CTRLA_BIAS_bf(const void *const hw, hri_slcd_ctrla_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg ^= SLCD_CTRLA_BIAS(mask);
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_ctrla_reg_t hri_slcd_read_CTRLA_BIAS_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->CTRLA.reg;
	tmp = (tmp & SLCD_CTRLA_BIAS_Msk) >> SLCD_CTRLA_BIAS_Pos;
	return tmp;
}

static inline void hri_slcd_set_CTRLA_PRF_bf(const void *const hw, hri_slcd_ctrla_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg |= SLCD_CTRLA_PRF(mask);
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_ctrla_reg_t hri_slcd_get_CTRLA_PRF_bf(const void *const hw, hri_slcd_ctrla_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->CTRLA.reg;
	tmp = (tmp & SLCD_CTRLA_PRF(mask)) >> SLCD_CTRLA_PRF_Pos;
	return tmp;
}

static inline void hri_slcd_write_CTRLA_PRF_bf(const void *const hw, hri_slcd_ctrla_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CTRLA.reg;
	tmp &= ~SLCD_CTRLA_PRF_Msk;
	tmp |= SLCD_CTRLA_PRF(data);
	((Slcd *)hw)->CTRLA.reg = tmp;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CTRLA_PRF_bf(const void *const hw, hri_slcd_ctrla_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg &= ~SLCD_CTRLA_PRF(mask);
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CTRLA_PRF_bf(const void *const hw, hri_slcd_ctrla_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg ^= SLCD_CTRLA_PRF(mask);
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_ctrla_reg_t hri_slcd_read_CTRLA_PRF_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->CTRLA.reg;
	tmp = (tmp & SLCD_CTRLA_PRF_Msk) >> SLCD_CTRLA_PRF_Pos;
	return tmp;
}

static inline void hri_slcd_set_CTRLA_DMFCS_bf(const void *const hw, hri_slcd_ctrla_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg |= SLCD_CTRLA_DMFCS(mask);
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_ctrla_reg_t hri_slcd_get_CTRLA_DMFCS_bf(const void *const hw, hri_slcd_ctrla_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->CTRLA.reg;
	tmp = (tmp & SLCD_CTRLA_DMFCS(mask)) >> SLCD_CTRLA_DMFCS_Pos;
	return tmp;
}

static inline void hri_slcd_write_CTRLA_DMFCS_bf(const void *const hw, hri_slcd_ctrla_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CTRLA.reg;
	tmp &= ~SLCD_CTRLA_DMFCS_Msk;
	tmp |= SLCD_CTRLA_DMFCS(data);
	((Slcd *)hw)->CTRLA.reg = tmp;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CTRLA_DMFCS_bf(const void *const hw, hri_slcd_ctrla_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg &= ~SLCD_CTRLA_DMFCS(mask);
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CTRLA_DMFCS_bf(const void *const hw, hri_slcd_ctrla_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg ^= SLCD_CTRLA_DMFCS(mask);
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_ctrla_reg_t hri_slcd_read_CTRLA_DMFCS_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->CTRLA.reg;
	tmp = (tmp & SLCD_CTRLA_DMFCS_Msk) >> SLCD_CTRLA_DMFCS_Pos;
	return tmp;
}

static inline void hri_slcd_set_CTRLA_RRF_bf(const void *const hw, hri_slcd_ctrla_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg |= SLCD_CTRLA_RRF(mask);
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_ctrla_reg_t hri_slcd_get_CTRLA_RRF_bf(const void *const hw, hri_slcd_ctrla_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->CTRLA.reg;
	tmp = (tmp & SLCD_CTRLA_RRF(mask)) >> SLCD_CTRLA_RRF_Pos;
	return tmp;
}

static inline void hri_slcd_write_CTRLA_RRF_bf(const void *const hw, hri_slcd_ctrla_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CTRLA.reg;
	tmp &= ~SLCD_CTRLA_RRF_Msk;
	tmp |= SLCD_CTRLA_RRF(data);
	((Slcd *)hw)->CTRLA.reg = tmp;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CTRLA_RRF_bf(const void *const hw, hri_slcd_ctrla_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg &= ~SLCD_CTRLA_RRF(mask);
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CTRLA_RRF_bf(const void *const hw, hri_slcd_ctrla_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg ^= SLCD_CTRLA_RRF(mask);
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_ctrla_reg_t hri_slcd_read_CTRLA_RRF_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->CTRLA.reg;
	tmp = (tmp & SLCD_CTRLA_RRF_Msk) >> SLCD_CTRLA_RRF_Pos;
	return tmp;
}

static inline void hri_slcd_set_CTRLA_reg(const void *const hw, hri_slcd_ctrla_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg |= mask;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_SWRST | SLCD_SYNCBUSY_ENABLE);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_ctrla_reg_t hri_slcd_get_CTRLA_reg(const void *const hw, hri_slcd_ctrla_reg_t mask)
{
	uint32_t tmp;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_SWRST | SLCD_SYNCBUSY_ENABLE);
	tmp = ((Slcd *)hw)->CTRLA.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_slcd_write_CTRLA_reg(const void *const hw, hri_slcd_ctrla_reg_t data)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg = data;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_SWRST | SLCD_SYNCBUSY_ENABLE);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CTRLA_reg(const void *const hw, hri_slcd_ctrla_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg &= ~mask;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_SWRST | SLCD_SYNCBUSY_ENABLE);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CTRLA_reg(const void *const hw, hri_slcd_ctrla_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLA.reg ^= mask;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_SWRST | SLCD_SYNCBUSY_ENABLE);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_ctrla_reg_t hri_slcd_read_CTRLA_reg(const void *const hw)
{
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_SWRST | SLCD_SYNCBUSY_ENABLE);
	return ((Slcd *)hw)->CTRLA.reg;
}

static inline void hri_slcd_set_CTRLB_BBEN_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLB.reg |= SLCD_CTRLB_BBEN;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_slcd_get_CTRLB_BBEN_bit(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Slcd *)hw)->CTRLB.reg;
	tmp = (tmp & SLCD_CTRLB_BBEN) >> SLCD_CTRLB_BBEN_Pos;
	return (bool)tmp;
}

static inline void hri_slcd_write_CTRLB_BBEN_bit(const void *const hw, bool value)
{
	uint16_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CTRLB.reg;
	tmp &= ~SLCD_CTRLB_BBEN;
	tmp |= value << SLCD_CTRLB_BBEN_Pos;
	((Slcd *)hw)->CTRLB.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CTRLB_BBEN_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLB.reg &= ~SLCD_CTRLB_BBEN;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CTRLB_BBEN_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLB.reg ^= SLCD_CTRLB_BBEN;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_set_CTRLB_LREN_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLB.reg |= SLCD_CTRLB_LREN;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_slcd_get_CTRLB_LREN_bit(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Slcd *)hw)->CTRLB.reg;
	tmp = (tmp & SLCD_CTRLB_LREN) >> SLCD_CTRLB_LREN_Pos;
	return (bool)tmp;
}

static inline void hri_slcd_write_CTRLB_LREN_bit(const void *const hw, bool value)
{
	uint16_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CTRLB.reg;
	tmp &= ~SLCD_CTRLB_LREN;
	tmp |= value << SLCD_CTRLB_LREN_Pos;
	((Slcd *)hw)->CTRLB.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CTRLB_LREN_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLB.reg &= ~SLCD_CTRLB_LREN;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CTRLB_LREN_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLB.reg ^= SLCD_CTRLB_LREN;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_set_CTRLB_BBD_bf(const void *const hw, hri_slcd_ctrlb_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLB.reg |= SLCD_CTRLB_BBD(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_ctrlb_reg_t hri_slcd_get_CTRLB_BBD_bf(const void *const hw, hri_slcd_ctrlb_reg_t mask)
{
	uint16_t tmp;
	tmp = ((Slcd *)hw)->CTRLB.reg;
	tmp = (tmp & SLCD_CTRLB_BBD(mask)) >> SLCD_CTRLB_BBD_Pos;
	return tmp;
}

static inline void hri_slcd_write_CTRLB_BBD_bf(const void *const hw, hri_slcd_ctrlb_reg_t data)
{
	uint16_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CTRLB.reg;
	tmp &= ~SLCD_CTRLB_BBD_Msk;
	tmp |= SLCD_CTRLB_BBD(data);
	((Slcd *)hw)->CTRLB.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CTRLB_BBD_bf(const void *const hw, hri_slcd_ctrlb_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLB.reg &= ~SLCD_CTRLB_BBD(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CTRLB_BBD_bf(const void *const hw, hri_slcd_ctrlb_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLB.reg ^= SLCD_CTRLB_BBD(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_ctrlb_reg_t hri_slcd_read_CTRLB_BBD_bf(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Slcd *)hw)->CTRLB.reg;
	tmp = (tmp & SLCD_CTRLB_BBD_Msk) >> SLCD_CTRLB_BBD_Pos;
	return tmp;
}

static inline void hri_slcd_set_CTRLB_LRD_bf(const void *const hw, hri_slcd_ctrlb_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLB.reg |= SLCD_CTRLB_LRD(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_ctrlb_reg_t hri_slcd_get_CTRLB_LRD_bf(const void *const hw, hri_slcd_ctrlb_reg_t mask)
{
	uint16_t tmp;
	tmp = ((Slcd *)hw)->CTRLB.reg;
	tmp = (tmp & SLCD_CTRLB_LRD(mask)) >> SLCD_CTRLB_LRD_Pos;
	return tmp;
}

static inline void hri_slcd_write_CTRLB_LRD_bf(const void *const hw, hri_slcd_ctrlb_reg_t data)
{
	uint16_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CTRLB.reg;
	tmp &= ~SLCD_CTRLB_LRD_Msk;
	tmp |= SLCD_CTRLB_LRD(data);
	((Slcd *)hw)->CTRLB.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CTRLB_LRD_bf(const void *const hw, hri_slcd_ctrlb_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLB.reg &= ~SLCD_CTRLB_LRD(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CTRLB_LRD_bf(const void *const hw, hri_slcd_ctrlb_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLB.reg ^= SLCD_CTRLB_LRD(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_ctrlb_reg_t hri_slcd_read_CTRLB_LRD_bf(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Slcd *)hw)->CTRLB.reg;
	tmp = (tmp & SLCD_CTRLB_LRD_Msk) >> SLCD_CTRLB_LRD_Pos;
	return tmp;
}

static inline void hri_slcd_set_CTRLB_reg(const void *const hw, hri_slcd_ctrlb_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLB.reg |= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_ctrlb_reg_t hri_slcd_get_CTRLB_reg(const void *const hw, hri_slcd_ctrlb_reg_t mask)
{
	uint16_t tmp;
	tmp = ((Slcd *)hw)->CTRLB.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_slcd_write_CTRLB_reg(const void *const hw, hri_slcd_ctrlb_reg_t data)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLB.reg = data;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CTRLB_reg(const void *const hw, hri_slcd_ctrlb_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLB.reg &= ~mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CTRLB_reg(const void *const hw, hri_slcd_ctrlb_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLB.reg ^= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_ctrlb_reg_t hri_slcd_read_CTRLB_reg(const void *const hw)
{
	return ((Slcd *)hw)->CTRLB.reg;
}

static inline void hri_slcd_set_CTRLC_CLEAR_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLC.reg |= SLCD_CTRLC_CLEAR;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_slcd_get_CTRLC_CLEAR_bit(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Slcd *)hw)->CTRLC.reg;
	tmp = (tmp & SLCD_CTRLC_CLEAR) >> SLCD_CTRLC_CLEAR_Pos;
	return (bool)tmp;
}

static inline void hri_slcd_write_CTRLC_CLEAR_bit(const void *const hw, bool value)
{
	uint16_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CTRLC.reg;
	tmp &= ~SLCD_CTRLC_CLEAR;
	tmp |= value << SLCD_CTRLC_CLEAR_Pos;
	((Slcd *)hw)->CTRLC.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CTRLC_CLEAR_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLC.reg &= ~SLCD_CTRLC_CLEAR;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CTRLC_CLEAR_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLC.reg ^= SLCD_CTRLC_CLEAR;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_set_CTRLC_LOCK_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLC.reg |= SLCD_CTRLC_LOCK;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_slcd_get_CTRLC_LOCK_bit(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Slcd *)hw)->CTRLC.reg;
	tmp = (tmp & SLCD_CTRLC_LOCK) >> SLCD_CTRLC_LOCK_Pos;
	return (bool)tmp;
}

static inline void hri_slcd_write_CTRLC_LOCK_bit(const void *const hw, bool value)
{
	uint16_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CTRLC.reg;
	tmp &= ~SLCD_CTRLC_LOCK;
	tmp |= value << SLCD_CTRLC_LOCK_Pos;
	((Slcd *)hw)->CTRLC.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CTRLC_LOCK_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLC.reg &= ~SLCD_CTRLC_LOCK;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CTRLC_LOCK_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLC.reg ^= SLCD_CTRLC_LOCK;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_set_CTRLC_ABMEN_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLC.reg |= SLCD_CTRLC_ABMEN;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_slcd_get_CTRLC_ABMEN_bit(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Slcd *)hw)->CTRLC.reg;
	tmp = (tmp & SLCD_CTRLC_ABMEN) >> SLCD_CTRLC_ABMEN_Pos;
	return (bool)tmp;
}

static inline void hri_slcd_write_CTRLC_ABMEN_bit(const void *const hw, bool value)
{
	uint16_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CTRLC.reg;
	tmp &= ~SLCD_CTRLC_ABMEN;
	tmp |= value << SLCD_CTRLC_ABMEN_Pos;
	((Slcd *)hw)->CTRLC.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CTRLC_ABMEN_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLC.reg &= ~SLCD_CTRLC_ABMEN;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CTRLC_ABMEN_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLC.reg ^= SLCD_CTRLC_ABMEN;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_set_CTRLC_ACMEN_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLC.reg |= SLCD_CTRLC_ACMEN;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_slcd_get_CTRLC_ACMEN_bit(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Slcd *)hw)->CTRLC.reg;
	tmp = (tmp & SLCD_CTRLC_ACMEN) >> SLCD_CTRLC_ACMEN_Pos;
	return (bool)tmp;
}

static inline void hri_slcd_write_CTRLC_ACMEN_bit(const void *const hw, bool value)
{
	uint16_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CTRLC.reg;
	tmp &= ~SLCD_CTRLC_ACMEN;
	tmp |= value << SLCD_CTRLC_ACMEN_Pos;
	((Slcd *)hw)->CTRLC.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CTRLC_ACMEN_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLC.reg &= ~SLCD_CTRLC_ACMEN;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CTRLC_ACMEN_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLC.reg ^= SLCD_CTRLC_ACMEN;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_set_CTRLC_CTST_bf(const void *const hw, hri_slcd_ctrlc_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLC.reg |= SLCD_CTRLC_CTST(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_ctrlc_reg_t hri_slcd_get_CTRLC_CTST_bf(const void *const hw, hri_slcd_ctrlc_reg_t mask)
{
	uint16_t tmp;
	tmp = ((Slcd *)hw)->CTRLC.reg;
	tmp = (tmp & SLCD_CTRLC_CTST(mask)) >> SLCD_CTRLC_CTST_Pos;
	return tmp;
}

static inline void hri_slcd_write_CTRLC_CTST_bf(const void *const hw, hri_slcd_ctrlc_reg_t data)
{
	uint16_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CTRLC.reg;
	tmp &= ~SLCD_CTRLC_CTST_Msk;
	tmp |= SLCD_CTRLC_CTST(data);
	((Slcd *)hw)->CTRLC.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CTRLC_CTST_bf(const void *const hw, hri_slcd_ctrlc_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLC.reg &= ~SLCD_CTRLC_CTST(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CTRLC_CTST_bf(const void *const hw, hri_slcd_ctrlc_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLC.reg ^= SLCD_CTRLC_CTST(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_ctrlc_reg_t hri_slcd_read_CTRLC_CTST_bf(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Slcd *)hw)->CTRLC.reg;
	tmp = (tmp & SLCD_CTRLC_CTST_Msk) >> SLCD_CTRLC_CTST_Pos;
	return tmp;
}

static inline void hri_slcd_set_CTRLC_LPPM_bf(const void *const hw, hri_slcd_ctrlc_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLC.reg |= SLCD_CTRLC_LPPM(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_ctrlc_reg_t hri_slcd_get_CTRLC_LPPM_bf(const void *const hw, hri_slcd_ctrlc_reg_t mask)
{
	uint16_t tmp;
	tmp = ((Slcd *)hw)->CTRLC.reg;
	tmp = (tmp & SLCD_CTRLC_LPPM(mask)) >> SLCD_CTRLC_LPPM_Pos;
	return tmp;
}

static inline void hri_slcd_write_CTRLC_LPPM_bf(const void *const hw, hri_slcd_ctrlc_reg_t data)
{
	uint16_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CTRLC.reg;
	tmp &= ~SLCD_CTRLC_LPPM_Msk;
	tmp |= SLCD_CTRLC_LPPM(data);
	((Slcd *)hw)->CTRLC.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CTRLC_LPPM_bf(const void *const hw, hri_slcd_ctrlc_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLC.reg &= ~SLCD_CTRLC_LPPM(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CTRLC_LPPM_bf(const void *const hw, hri_slcd_ctrlc_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLC.reg ^= SLCD_CTRLC_LPPM(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_ctrlc_reg_t hri_slcd_read_CTRLC_LPPM_bf(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Slcd *)hw)->CTRLC.reg;
	tmp = (tmp & SLCD_CTRLC_LPPM_Msk) >> SLCD_CTRLC_LPPM_Pos;
	return tmp;
}

static inline void hri_slcd_set_CTRLC_reg(const void *const hw, hri_slcd_ctrlc_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLC.reg |= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_ctrlc_reg_t hri_slcd_get_CTRLC_reg(const void *const hw, hri_slcd_ctrlc_reg_t mask)
{
	uint16_t tmp;
	tmp = ((Slcd *)hw)->CTRLC.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_slcd_write_CTRLC_reg(const void *const hw, hri_slcd_ctrlc_reg_t data)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLC.reg = data;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CTRLC_reg(const void *const hw, hri_slcd_ctrlc_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLC.reg &= ~mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CTRLC_reg(const void *const hw, hri_slcd_ctrlc_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLC.reg ^= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_ctrlc_reg_t hri_slcd_read_CTRLC_reg(const void *const hw)
{
	return ((Slcd *)hw)->CTRLC.reg;
}

static inline void hri_slcd_set_CTRLD_BLANK_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLD.reg |= SLCD_CTRLD_BLANK;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_slcd_get_CTRLD_BLANK_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Slcd *)hw)->CTRLD.reg;
	tmp = (tmp & SLCD_CTRLD_BLANK) >> SLCD_CTRLD_BLANK_Pos;
	return (bool)tmp;
}

static inline void hri_slcd_write_CTRLD_BLANK_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CTRLD.reg;
	tmp &= ~SLCD_CTRLD_BLANK;
	tmp |= value << SLCD_CTRLD_BLANK_Pos;
	((Slcd *)hw)->CTRLD.reg = tmp;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CTRLD_BLANK_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLD.reg &= ~SLCD_CTRLD_BLANK;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CTRLD_BLANK_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLD.reg ^= SLCD_CTRLD_BLANK;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_set_CTRLD_BLINK_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLD.reg |= SLCD_CTRLD_BLINK;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_slcd_get_CTRLD_BLINK_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Slcd *)hw)->CTRLD.reg;
	tmp = (tmp & SLCD_CTRLD_BLINK) >> SLCD_CTRLD_BLINK_Pos;
	return (bool)tmp;
}

static inline void hri_slcd_write_CTRLD_BLINK_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CTRLD.reg;
	tmp &= ~SLCD_CTRLD_BLINK;
	tmp |= value << SLCD_CTRLD_BLINK_Pos;
	((Slcd *)hw)->CTRLD.reg = tmp;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CTRLD_BLINK_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLD.reg &= ~SLCD_CTRLD_BLINK;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CTRLD_BLINK_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLD.reg ^= SLCD_CTRLD_BLINK;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_set_CTRLD_CSREN_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLD.reg |= SLCD_CTRLD_CSREN;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_slcd_get_CTRLD_CSREN_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Slcd *)hw)->CTRLD.reg;
	tmp = (tmp & SLCD_CTRLD_CSREN) >> SLCD_CTRLD_CSREN_Pos;
	return (bool)tmp;
}

static inline void hri_slcd_write_CTRLD_CSREN_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CTRLD.reg;
	tmp &= ~SLCD_CTRLD_CSREN;
	tmp |= value << SLCD_CTRLD_CSREN_Pos;
	((Slcd *)hw)->CTRLD.reg = tmp;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CTRLD_CSREN_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLD.reg &= ~SLCD_CTRLD_CSREN;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CTRLD_CSREN_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLD.reg ^= SLCD_CTRLD_CSREN;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_set_CTRLD_FC0EN_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLD.reg |= SLCD_CTRLD_FC0EN;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_slcd_get_CTRLD_FC0EN_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Slcd *)hw)->CTRLD.reg;
	tmp = (tmp & SLCD_CTRLD_FC0EN) >> SLCD_CTRLD_FC0EN_Pos;
	return (bool)tmp;
}

static inline void hri_slcd_write_CTRLD_FC0EN_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CTRLD.reg;
	tmp &= ~SLCD_CTRLD_FC0EN;
	tmp |= value << SLCD_CTRLD_FC0EN_Pos;
	((Slcd *)hw)->CTRLD.reg = tmp;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CTRLD_FC0EN_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLD.reg &= ~SLCD_CTRLD_FC0EN;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CTRLD_FC0EN_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLD.reg ^= SLCD_CTRLD_FC0EN;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_set_CTRLD_FC1EN_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLD.reg |= SLCD_CTRLD_FC1EN;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_slcd_get_CTRLD_FC1EN_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Slcd *)hw)->CTRLD.reg;
	tmp = (tmp & SLCD_CTRLD_FC1EN) >> SLCD_CTRLD_FC1EN_Pos;
	return (bool)tmp;
}

static inline void hri_slcd_write_CTRLD_FC1EN_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CTRLD.reg;
	tmp &= ~SLCD_CTRLD_FC1EN;
	tmp |= value << SLCD_CTRLD_FC1EN_Pos;
	((Slcd *)hw)->CTRLD.reg = tmp;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CTRLD_FC1EN_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLD.reg &= ~SLCD_CTRLD_FC1EN;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CTRLD_FC1EN_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLD.reg ^= SLCD_CTRLD_FC1EN;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_set_CTRLD_FC2EN_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLD.reg |= SLCD_CTRLD_FC2EN;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_slcd_get_CTRLD_FC2EN_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Slcd *)hw)->CTRLD.reg;
	tmp = (tmp & SLCD_CTRLD_FC2EN) >> SLCD_CTRLD_FC2EN_Pos;
	return (bool)tmp;
}

static inline void hri_slcd_write_CTRLD_FC2EN_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CTRLD.reg;
	tmp &= ~SLCD_CTRLD_FC2EN;
	tmp |= value << SLCD_CTRLD_FC2EN_Pos;
	((Slcd *)hw)->CTRLD.reg = tmp;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CTRLD_FC2EN_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLD.reg &= ~SLCD_CTRLD_FC2EN;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CTRLD_FC2EN_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLD.reg ^= SLCD_CTRLD_FC2EN;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_set_CTRLD_DISPEN_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLD.reg |= SLCD_CTRLD_DISPEN;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_slcd_get_CTRLD_DISPEN_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Slcd *)hw)->CTRLD.reg;
	tmp = (tmp & SLCD_CTRLD_DISPEN) >> SLCD_CTRLD_DISPEN_Pos;
	return (bool)tmp;
}

static inline void hri_slcd_write_CTRLD_DISPEN_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CTRLD.reg;
	tmp &= ~SLCD_CTRLD_DISPEN;
	tmp |= value << SLCD_CTRLD_DISPEN_Pos;
	((Slcd *)hw)->CTRLD.reg = tmp;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CTRLD_DISPEN_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLD.reg &= ~SLCD_CTRLD_DISPEN;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CTRLD_DISPEN_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLD.reg ^= SLCD_CTRLD_DISPEN;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_set_CTRLD_reg(const void *const hw, hri_slcd_ctrld_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLD.reg |= mask;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_ctrld_reg_t hri_slcd_get_CTRLD_reg(const void *const hw, hri_slcd_ctrld_reg_t mask)
{
	uint8_t tmp;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	tmp = ((Slcd *)hw)->CTRLD.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_slcd_write_CTRLD_reg(const void *const hw, hri_slcd_ctrld_reg_t data)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLD.reg = data;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CTRLD_reg(const void *const hw, hri_slcd_ctrld_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLD.reg &= ~mask;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CTRLD_reg(const void *const hw, hri_slcd_ctrld_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CTRLD.reg ^= mask;
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_ctrld_reg_t hri_slcd_read_CTRLD_reg(const void *const hw)
{
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_MASK);
	return ((Slcd *)hw)->CTRLD.reg;
}

static inline void hri_slcd_set_EVCTRL_FC0OEO_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->EVCTRL.reg |= SLCD_EVCTRL_FC0OEO;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_slcd_get_EVCTRL_FC0OEO_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Slcd *)hw)->EVCTRL.reg;
	tmp = (tmp & SLCD_EVCTRL_FC0OEO) >> SLCD_EVCTRL_FC0OEO_Pos;
	return (bool)tmp;
}

static inline void hri_slcd_write_EVCTRL_FC0OEO_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->EVCTRL.reg;
	tmp &= ~SLCD_EVCTRL_FC0OEO;
	tmp |= value << SLCD_EVCTRL_FC0OEO_Pos;
	((Slcd *)hw)->EVCTRL.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_EVCTRL_FC0OEO_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->EVCTRL.reg &= ~SLCD_EVCTRL_FC0OEO;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_EVCTRL_FC0OEO_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->EVCTRL.reg ^= SLCD_EVCTRL_FC0OEO;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_set_EVCTRL_FC1OEO_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->EVCTRL.reg |= SLCD_EVCTRL_FC1OEO;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_slcd_get_EVCTRL_FC1OEO_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Slcd *)hw)->EVCTRL.reg;
	tmp = (tmp & SLCD_EVCTRL_FC1OEO) >> SLCD_EVCTRL_FC1OEO_Pos;
	return (bool)tmp;
}

static inline void hri_slcd_write_EVCTRL_FC1OEO_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->EVCTRL.reg;
	tmp &= ~SLCD_EVCTRL_FC1OEO;
	tmp |= value << SLCD_EVCTRL_FC1OEO_Pos;
	((Slcd *)hw)->EVCTRL.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_EVCTRL_FC1OEO_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->EVCTRL.reg &= ~SLCD_EVCTRL_FC1OEO;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_EVCTRL_FC1OEO_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->EVCTRL.reg ^= SLCD_EVCTRL_FC1OEO;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_set_EVCTRL_FC2OEO_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->EVCTRL.reg |= SLCD_EVCTRL_FC2OEO;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_slcd_get_EVCTRL_FC2OEO_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Slcd *)hw)->EVCTRL.reg;
	tmp = (tmp & SLCD_EVCTRL_FC2OEO) >> SLCD_EVCTRL_FC2OEO_Pos;
	return (bool)tmp;
}

static inline void hri_slcd_write_EVCTRL_FC2OEO_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->EVCTRL.reg;
	tmp &= ~SLCD_EVCTRL_FC2OEO;
	tmp |= value << SLCD_EVCTRL_FC2OEO_Pos;
	((Slcd *)hw)->EVCTRL.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_EVCTRL_FC2OEO_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->EVCTRL.reg &= ~SLCD_EVCTRL_FC2OEO;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_EVCTRL_FC2OEO_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->EVCTRL.reg ^= SLCD_EVCTRL_FC2OEO;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_set_EVCTRL_reg(const void *const hw, hri_slcd_evctrl_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->EVCTRL.reg |= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_evctrl_reg_t hri_slcd_get_EVCTRL_reg(const void *const hw, hri_slcd_evctrl_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Slcd *)hw)->EVCTRL.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_slcd_write_EVCTRL_reg(const void *const hw, hri_slcd_evctrl_reg_t data)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->EVCTRL.reg = data;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_EVCTRL_reg(const void *const hw, hri_slcd_evctrl_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->EVCTRL.reg &= ~mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_EVCTRL_reg(const void *const hw, hri_slcd_evctrl_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->EVCTRL.reg ^= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_evctrl_reg_t hri_slcd_read_EVCTRL_reg(const void *const hw)
{
	return ((Slcd *)hw)->EVCTRL.reg;
}

static inline void hri_slcd_set_FC0_PB_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->FC0.reg |= SLCD_FC0_PB;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_slcd_get_FC0_PB_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Slcd *)hw)->FC0.reg;
	tmp = (tmp & SLCD_FC0_PB) >> SLCD_FC0_PB_Pos;
	return (bool)tmp;
}

static inline void hri_slcd_write_FC0_PB_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->FC0.reg;
	tmp &= ~SLCD_FC0_PB;
	tmp |= value << SLCD_FC0_PB_Pos;
	((Slcd *)hw)->FC0.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_FC0_PB_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->FC0.reg &= ~SLCD_FC0_PB;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_FC0_PB_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->FC0.reg ^= SLCD_FC0_PB;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_set_FC0_OVF_bf(const void *const hw, hri_slcd_fc0_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->FC0.reg |= SLCD_FC0_OVF(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_fc0_reg_t hri_slcd_get_FC0_OVF_bf(const void *const hw, hri_slcd_fc0_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Slcd *)hw)->FC0.reg;
	tmp = (tmp & SLCD_FC0_OVF(mask)) >> SLCD_FC0_OVF_Pos;
	return tmp;
}

static inline void hri_slcd_write_FC0_OVF_bf(const void *const hw, hri_slcd_fc0_reg_t data)
{
	uint8_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->FC0.reg;
	tmp &= ~SLCD_FC0_OVF_Msk;
	tmp |= SLCD_FC0_OVF(data);
	((Slcd *)hw)->FC0.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_FC0_OVF_bf(const void *const hw, hri_slcd_fc0_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->FC0.reg &= ~SLCD_FC0_OVF(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_FC0_OVF_bf(const void *const hw, hri_slcd_fc0_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->FC0.reg ^= SLCD_FC0_OVF(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_fc0_reg_t hri_slcd_read_FC0_OVF_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Slcd *)hw)->FC0.reg;
	tmp = (tmp & SLCD_FC0_OVF_Msk) >> SLCD_FC0_OVF_Pos;
	return tmp;
}

static inline void hri_slcd_set_FC0_reg(const void *const hw, hri_slcd_fc0_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->FC0.reg |= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_fc0_reg_t hri_slcd_get_FC0_reg(const void *const hw, hri_slcd_fc0_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Slcd *)hw)->FC0.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_slcd_write_FC0_reg(const void *const hw, hri_slcd_fc0_reg_t data)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->FC0.reg = data;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_FC0_reg(const void *const hw, hri_slcd_fc0_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->FC0.reg &= ~mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_FC0_reg(const void *const hw, hri_slcd_fc0_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->FC0.reg ^= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_fc0_reg_t hri_slcd_read_FC0_reg(const void *const hw)
{
	return ((Slcd *)hw)->FC0.reg;
}

static inline void hri_slcd_set_FC1_PB_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->FC1.reg |= SLCD_FC1_PB;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_slcd_get_FC1_PB_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Slcd *)hw)->FC1.reg;
	tmp = (tmp & SLCD_FC1_PB) >> SLCD_FC1_PB_Pos;
	return (bool)tmp;
}

static inline void hri_slcd_write_FC1_PB_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->FC1.reg;
	tmp &= ~SLCD_FC1_PB;
	tmp |= value << SLCD_FC1_PB_Pos;
	((Slcd *)hw)->FC1.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_FC1_PB_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->FC1.reg &= ~SLCD_FC1_PB;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_FC1_PB_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->FC1.reg ^= SLCD_FC1_PB;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_set_FC1_OVF_bf(const void *const hw, hri_slcd_fc1_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->FC1.reg |= SLCD_FC1_OVF(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_fc1_reg_t hri_slcd_get_FC1_OVF_bf(const void *const hw, hri_slcd_fc1_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Slcd *)hw)->FC1.reg;
	tmp = (tmp & SLCD_FC1_OVF(mask)) >> SLCD_FC1_OVF_Pos;
	return tmp;
}

static inline void hri_slcd_write_FC1_OVF_bf(const void *const hw, hri_slcd_fc1_reg_t data)
{
	uint8_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->FC1.reg;
	tmp &= ~SLCD_FC1_OVF_Msk;
	tmp |= SLCD_FC1_OVF(data);
	((Slcd *)hw)->FC1.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_FC1_OVF_bf(const void *const hw, hri_slcd_fc1_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->FC1.reg &= ~SLCD_FC1_OVF(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_FC1_OVF_bf(const void *const hw, hri_slcd_fc1_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->FC1.reg ^= SLCD_FC1_OVF(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_fc1_reg_t hri_slcd_read_FC1_OVF_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Slcd *)hw)->FC1.reg;
	tmp = (tmp & SLCD_FC1_OVF_Msk) >> SLCD_FC1_OVF_Pos;
	return tmp;
}

static inline void hri_slcd_set_FC1_reg(const void *const hw, hri_slcd_fc1_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->FC1.reg |= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_fc1_reg_t hri_slcd_get_FC1_reg(const void *const hw, hri_slcd_fc1_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Slcd *)hw)->FC1.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_slcd_write_FC1_reg(const void *const hw, hri_slcd_fc1_reg_t data)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->FC1.reg = data;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_FC1_reg(const void *const hw, hri_slcd_fc1_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->FC1.reg &= ~mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_FC1_reg(const void *const hw, hri_slcd_fc1_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->FC1.reg ^= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_fc1_reg_t hri_slcd_read_FC1_reg(const void *const hw)
{
	return ((Slcd *)hw)->FC1.reg;
}

static inline void hri_slcd_set_FC2_PB_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->FC2.reg |= SLCD_FC2_PB;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_slcd_get_FC2_PB_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Slcd *)hw)->FC2.reg;
	tmp = (tmp & SLCD_FC2_PB) >> SLCD_FC2_PB_Pos;
	return (bool)tmp;
}

static inline void hri_slcd_write_FC2_PB_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->FC2.reg;
	tmp &= ~SLCD_FC2_PB;
	tmp |= value << SLCD_FC2_PB_Pos;
	((Slcd *)hw)->FC2.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_FC2_PB_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->FC2.reg &= ~SLCD_FC2_PB;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_FC2_PB_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->FC2.reg ^= SLCD_FC2_PB;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_set_FC2_OVF_bf(const void *const hw, hri_slcd_fc2_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->FC2.reg |= SLCD_FC2_OVF(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_fc2_reg_t hri_slcd_get_FC2_OVF_bf(const void *const hw, hri_slcd_fc2_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Slcd *)hw)->FC2.reg;
	tmp = (tmp & SLCD_FC2_OVF(mask)) >> SLCD_FC2_OVF_Pos;
	return tmp;
}

static inline void hri_slcd_write_FC2_OVF_bf(const void *const hw, hri_slcd_fc2_reg_t data)
{
	uint8_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->FC2.reg;
	tmp &= ~SLCD_FC2_OVF_Msk;
	tmp |= SLCD_FC2_OVF(data);
	((Slcd *)hw)->FC2.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_FC2_OVF_bf(const void *const hw, hri_slcd_fc2_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->FC2.reg &= ~SLCD_FC2_OVF(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_FC2_OVF_bf(const void *const hw, hri_slcd_fc2_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->FC2.reg ^= SLCD_FC2_OVF(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_fc2_reg_t hri_slcd_read_FC2_OVF_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Slcd *)hw)->FC2.reg;
	tmp = (tmp & SLCD_FC2_OVF_Msk) >> SLCD_FC2_OVF_Pos;
	return tmp;
}

static inline void hri_slcd_set_FC2_reg(const void *const hw, hri_slcd_fc2_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->FC2.reg |= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_fc2_reg_t hri_slcd_get_FC2_reg(const void *const hw, hri_slcd_fc2_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Slcd *)hw)->FC2.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_slcd_write_FC2_reg(const void *const hw, hri_slcd_fc2_reg_t data)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->FC2.reg = data;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_FC2_reg(const void *const hw, hri_slcd_fc2_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->FC2.reg &= ~mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_FC2_reg(const void *const hw, hri_slcd_fc2_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->FC2.reg ^= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_fc2_reg_t hri_slcd_read_FC2_reg(const void *const hw)
{
	return ((Slcd *)hw)->FC2.reg;
}

static inline void hri_slcd_set_LPENL_LPEN_bf(const void *const hw, hri_slcd_lpenl_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->LPENL.reg |= SLCD_LPENL_LPEN(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_lpenl_reg_t hri_slcd_get_LPENL_LPEN_bf(const void *const hw, hri_slcd_lpenl_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->LPENL.reg;
	tmp = (tmp & SLCD_LPENL_LPEN(mask)) >> SLCD_LPENL_LPEN_Pos;
	return tmp;
}

static inline void hri_slcd_write_LPENL_LPEN_bf(const void *const hw, hri_slcd_lpenl_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->LPENL.reg;
	tmp &= ~SLCD_LPENL_LPEN_Msk;
	tmp |= SLCD_LPENL_LPEN(data);
	((Slcd *)hw)->LPENL.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_LPENL_LPEN_bf(const void *const hw, hri_slcd_lpenl_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->LPENL.reg &= ~SLCD_LPENL_LPEN(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_LPENL_LPEN_bf(const void *const hw, hri_slcd_lpenl_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->LPENL.reg ^= SLCD_LPENL_LPEN(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_lpenl_reg_t hri_slcd_read_LPENL_LPEN_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->LPENL.reg;
	tmp = (tmp & SLCD_LPENL_LPEN_Msk) >> SLCD_LPENL_LPEN_Pos;
	return tmp;
}

static inline void hri_slcd_set_LPENL_reg(const void *const hw, hri_slcd_lpenl_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->LPENL.reg |= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_lpenl_reg_t hri_slcd_get_LPENL_reg(const void *const hw, hri_slcd_lpenl_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->LPENL.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_slcd_write_LPENL_reg(const void *const hw, hri_slcd_lpenl_reg_t data)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->LPENL.reg = data;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_LPENL_reg(const void *const hw, hri_slcd_lpenl_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->LPENL.reg &= ~mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_LPENL_reg(const void *const hw, hri_slcd_lpenl_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->LPENL.reg ^= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_lpenl_reg_t hri_slcd_read_LPENL_reg(const void *const hw)
{
	return ((Slcd *)hw)->LPENL.reg;
}

static inline void hri_slcd_set_LPENH_LPEN_bf(const void *const hw, hri_slcd_lpenh_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->LPENH.reg |= SLCD_LPENH_LPEN(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_lpenh_reg_t hri_slcd_get_LPENH_LPEN_bf(const void *const hw, hri_slcd_lpenh_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->LPENH.reg;
	tmp = (tmp & SLCD_LPENH_LPEN(mask)) >> SLCD_LPENH_LPEN_Pos;
	return tmp;
}

static inline void hri_slcd_write_LPENH_LPEN_bf(const void *const hw, hri_slcd_lpenh_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->LPENH.reg;
	tmp &= ~SLCD_LPENH_LPEN_Msk;
	tmp |= SLCD_LPENH_LPEN(data);
	((Slcd *)hw)->LPENH.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_LPENH_LPEN_bf(const void *const hw, hri_slcd_lpenh_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->LPENH.reg &= ~SLCD_LPENH_LPEN(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_LPENH_LPEN_bf(const void *const hw, hri_slcd_lpenh_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->LPENH.reg ^= SLCD_LPENH_LPEN(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_lpenh_reg_t hri_slcd_read_LPENH_LPEN_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->LPENH.reg;
	tmp = (tmp & SLCD_LPENH_LPEN_Msk) >> SLCD_LPENH_LPEN_Pos;
	return tmp;
}

static inline void hri_slcd_set_LPENH_reg(const void *const hw, hri_slcd_lpenh_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->LPENH.reg |= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_lpenh_reg_t hri_slcd_get_LPENH_reg(const void *const hw, hri_slcd_lpenh_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->LPENH.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_slcd_write_LPENH_reg(const void *const hw, hri_slcd_lpenh_reg_t data)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->LPENH.reg = data;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_LPENH_reg(const void *const hw, hri_slcd_lpenh_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->LPENH.reg &= ~mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_LPENH_reg(const void *const hw, hri_slcd_lpenh_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->LPENH.reg ^= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_lpenh_reg_t hri_slcd_read_LPENH_reg(const void *const hw)
{
	return ((Slcd *)hw)->LPENH.reg;
}

static inline void hri_slcd_set_SDATAL0_SDATA_bf(const void *const hw, hri_slcd_sdatal0_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL0.reg |= SLCD_SDATAL0_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatal0_reg_t hri_slcd_get_SDATAL0_SDATA_bf(const void *const hw, hri_slcd_sdatal0_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAL0.reg;
	tmp = (tmp & SLCD_SDATAL0_SDATA(mask)) >> SLCD_SDATAL0_SDATA_Pos;
	return tmp;
}

static inline void hri_slcd_write_SDATAL0_SDATA_bf(const void *const hw, hri_slcd_sdatal0_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->SDATAL0.reg;
	tmp &= ~SLCD_SDATAL0_SDATA_Msk;
	tmp |= SLCD_SDATAL0_SDATA(data);
	((Slcd *)hw)->SDATAL0.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_SDATAL0_SDATA_bf(const void *const hw, hri_slcd_sdatal0_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL0.reg &= ~SLCD_SDATAL0_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_SDATAL0_SDATA_bf(const void *const hw, hri_slcd_sdatal0_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL0.reg ^= SLCD_SDATAL0_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatal0_reg_t hri_slcd_read_SDATAL0_SDATA_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAL0.reg;
	tmp = (tmp & SLCD_SDATAL0_SDATA_Msk) >> SLCD_SDATAL0_SDATA_Pos;
	return tmp;
}

static inline void hri_slcd_set_SDATAL0_reg(const void *const hw, hri_slcd_sdatal0_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL0.reg |= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatal0_reg_t hri_slcd_get_SDATAL0_reg(const void *const hw, hri_slcd_sdatal0_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAL0.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_slcd_write_SDATAL0_reg(const void *const hw, hri_slcd_sdatal0_reg_t data)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL0.reg = data;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_SDATAL0_reg(const void *const hw, hri_slcd_sdatal0_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL0.reg &= ~mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_SDATAL0_reg(const void *const hw, hri_slcd_sdatal0_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL0.reg ^= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatal0_reg_t hri_slcd_read_SDATAL0_reg(const void *const hw)
{
	return ((Slcd *)hw)->SDATAL0.reg;
}

static inline void hri_slcd_set_SDATAH0_SDATA_bf(const void *const hw, hri_slcd_sdatah0_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH0.reg |= SLCD_SDATAH0_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatah0_reg_t hri_slcd_get_SDATAH0_SDATA_bf(const void *const hw, hri_slcd_sdatah0_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAH0.reg;
	tmp = (tmp & SLCD_SDATAH0_SDATA(mask)) >> SLCD_SDATAH0_SDATA_Pos;
	return tmp;
}

static inline void hri_slcd_write_SDATAH0_SDATA_bf(const void *const hw, hri_slcd_sdatah0_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->SDATAH0.reg;
	tmp &= ~SLCD_SDATAH0_SDATA_Msk;
	tmp |= SLCD_SDATAH0_SDATA(data);
	((Slcd *)hw)->SDATAH0.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_SDATAH0_SDATA_bf(const void *const hw, hri_slcd_sdatah0_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH0.reg &= ~SLCD_SDATAH0_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_SDATAH0_SDATA_bf(const void *const hw, hri_slcd_sdatah0_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH0.reg ^= SLCD_SDATAH0_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatah0_reg_t hri_slcd_read_SDATAH0_SDATA_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAH0.reg;
	tmp = (tmp & SLCD_SDATAH0_SDATA_Msk) >> SLCD_SDATAH0_SDATA_Pos;
	return tmp;
}

static inline void hri_slcd_set_SDATAH0_reg(const void *const hw, hri_slcd_sdatah0_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH0.reg |= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatah0_reg_t hri_slcd_get_SDATAH0_reg(const void *const hw, hri_slcd_sdatah0_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAH0.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_slcd_write_SDATAH0_reg(const void *const hw, hri_slcd_sdatah0_reg_t data)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH0.reg = data;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_SDATAH0_reg(const void *const hw, hri_slcd_sdatah0_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH0.reg &= ~mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_SDATAH0_reg(const void *const hw, hri_slcd_sdatah0_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH0.reg ^= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatah0_reg_t hri_slcd_read_SDATAH0_reg(const void *const hw)
{
	return ((Slcd *)hw)->SDATAH0.reg;
}

static inline void hri_slcd_set_SDATAL1_SDATA_bf(const void *const hw, hri_slcd_sdatal1_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL1.reg |= SLCD_SDATAL1_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatal1_reg_t hri_slcd_get_SDATAL1_SDATA_bf(const void *const hw, hri_slcd_sdatal1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAL1.reg;
	tmp = (tmp & SLCD_SDATAL1_SDATA(mask)) >> SLCD_SDATAL1_SDATA_Pos;
	return tmp;
}

static inline void hri_slcd_write_SDATAL1_SDATA_bf(const void *const hw, hri_slcd_sdatal1_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->SDATAL1.reg;
	tmp &= ~SLCD_SDATAL1_SDATA_Msk;
	tmp |= SLCD_SDATAL1_SDATA(data);
	((Slcd *)hw)->SDATAL1.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_SDATAL1_SDATA_bf(const void *const hw, hri_slcd_sdatal1_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL1.reg &= ~SLCD_SDATAL1_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_SDATAL1_SDATA_bf(const void *const hw, hri_slcd_sdatal1_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL1.reg ^= SLCD_SDATAL1_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatal1_reg_t hri_slcd_read_SDATAL1_SDATA_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAL1.reg;
	tmp = (tmp & SLCD_SDATAL1_SDATA_Msk) >> SLCD_SDATAL1_SDATA_Pos;
	return tmp;
}

static inline void hri_slcd_set_SDATAL1_reg(const void *const hw, hri_slcd_sdatal1_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL1.reg |= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatal1_reg_t hri_slcd_get_SDATAL1_reg(const void *const hw, hri_slcd_sdatal1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAL1.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_slcd_write_SDATAL1_reg(const void *const hw, hri_slcd_sdatal1_reg_t data)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL1.reg = data;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_SDATAL1_reg(const void *const hw, hri_slcd_sdatal1_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL1.reg &= ~mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_SDATAL1_reg(const void *const hw, hri_slcd_sdatal1_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL1.reg ^= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatal1_reg_t hri_slcd_read_SDATAL1_reg(const void *const hw)
{
	return ((Slcd *)hw)->SDATAL1.reg;
}

static inline void hri_slcd_set_SDATAH1_SDATA_bf(const void *const hw, hri_slcd_sdatah1_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH1.reg |= SLCD_SDATAH1_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatah1_reg_t hri_slcd_get_SDATAH1_SDATA_bf(const void *const hw, hri_slcd_sdatah1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAH1.reg;
	tmp = (tmp & SLCD_SDATAH1_SDATA(mask)) >> SLCD_SDATAH1_SDATA_Pos;
	return tmp;
}

static inline void hri_slcd_write_SDATAH1_SDATA_bf(const void *const hw, hri_slcd_sdatah1_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->SDATAH1.reg;
	tmp &= ~SLCD_SDATAH1_SDATA_Msk;
	tmp |= SLCD_SDATAH1_SDATA(data);
	((Slcd *)hw)->SDATAH1.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_SDATAH1_SDATA_bf(const void *const hw, hri_slcd_sdatah1_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH1.reg &= ~SLCD_SDATAH1_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_SDATAH1_SDATA_bf(const void *const hw, hri_slcd_sdatah1_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH1.reg ^= SLCD_SDATAH1_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatah1_reg_t hri_slcd_read_SDATAH1_SDATA_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAH1.reg;
	tmp = (tmp & SLCD_SDATAH1_SDATA_Msk) >> SLCD_SDATAH1_SDATA_Pos;
	return tmp;
}

static inline void hri_slcd_set_SDATAH1_reg(const void *const hw, hri_slcd_sdatah1_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH1.reg |= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatah1_reg_t hri_slcd_get_SDATAH1_reg(const void *const hw, hri_slcd_sdatah1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAH1.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_slcd_write_SDATAH1_reg(const void *const hw, hri_slcd_sdatah1_reg_t data)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH1.reg = data;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_SDATAH1_reg(const void *const hw, hri_slcd_sdatah1_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH1.reg &= ~mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_SDATAH1_reg(const void *const hw, hri_slcd_sdatah1_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH1.reg ^= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatah1_reg_t hri_slcd_read_SDATAH1_reg(const void *const hw)
{
	return ((Slcd *)hw)->SDATAH1.reg;
}

static inline void hri_slcd_set_SDATAL2_SDATA_bf(const void *const hw, hri_slcd_sdatal2_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL2.reg |= SLCD_SDATAL2_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatal2_reg_t hri_slcd_get_SDATAL2_SDATA_bf(const void *const hw, hri_slcd_sdatal2_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAL2.reg;
	tmp = (tmp & SLCD_SDATAL2_SDATA(mask)) >> SLCD_SDATAL2_SDATA_Pos;
	return tmp;
}

static inline void hri_slcd_write_SDATAL2_SDATA_bf(const void *const hw, hri_slcd_sdatal2_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->SDATAL2.reg;
	tmp &= ~SLCD_SDATAL2_SDATA_Msk;
	tmp |= SLCD_SDATAL2_SDATA(data);
	((Slcd *)hw)->SDATAL2.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_SDATAL2_SDATA_bf(const void *const hw, hri_slcd_sdatal2_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL2.reg &= ~SLCD_SDATAL2_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_SDATAL2_SDATA_bf(const void *const hw, hri_slcd_sdatal2_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL2.reg ^= SLCD_SDATAL2_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatal2_reg_t hri_slcd_read_SDATAL2_SDATA_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAL2.reg;
	tmp = (tmp & SLCD_SDATAL2_SDATA_Msk) >> SLCD_SDATAL2_SDATA_Pos;
	return tmp;
}

static inline void hri_slcd_set_SDATAL2_reg(const void *const hw, hri_slcd_sdatal2_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL2.reg |= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatal2_reg_t hri_slcd_get_SDATAL2_reg(const void *const hw, hri_slcd_sdatal2_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAL2.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_slcd_write_SDATAL2_reg(const void *const hw, hri_slcd_sdatal2_reg_t data)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL2.reg = data;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_SDATAL2_reg(const void *const hw, hri_slcd_sdatal2_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL2.reg &= ~mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_SDATAL2_reg(const void *const hw, hri_slcd_sdatal2_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL2.reg ^= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatal2_reg_t hri_slcd_read_SDATAL2_reg(const void *const hw)
{
	return ((Slcd *)hw)->SDATAL2.reg;
}

static inline void hri_slcd_set_SDATAH2_SDATA_bf(const void *const hw, hri_slcd_sdatah2_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH2.reg |= SLCD_SDATAH2_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatah2_reg_t hri_slcd_get_SDATAH2_SDATA_bf(const void *const hw, hri_slcd_sdatah2_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAH2.reg;
	tmp = (tmp & SLCD_SDATAH2_SDATA(mask)) >> SLCD_SDATAH2_SDATA_Pos;
	return tmp;
}

static inline void hri_slcd_write_SDATAH2_SDATA_bf(const void *const hw, hri_slcd_sdatah2_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->SDATAH2.reg;
	tmp &= ~SLCD_SDATAH2_SDATA_Msk;
	tmp |= SLCD_SDATAH2_SDATA(data);
	((Slcd *)hw)->SDATAH2.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_SDATAH2_SDATA_bf(const void *const hw, hri_slcd_sdatah2_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH2.reg &= ~SLCD_SDATAH2_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_SDATAH2_SDATA_bf(const void *const hw, hri_slcd_sdatah2_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH2.reg ^= SLCD_SDATAH2_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatah2_reg_t hri_slcd_read_SDATAH2_SDATA_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAH2.reg;
	tmp = (tmp & SLCD_SDATAH2_SDATA_Msk) >> SLCD_SDATAH2_SDATA_Pos;
	return tmp;
}

static inline void hri_slcd_set_SDATAH2_reg(const void *const hw, hri_slcd_sdatah2_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH2.reg |= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatah2_reg_t hri_slcd_get_SDATAH2_reg(const void *const hw, hri_slcd_sdatah2_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAH2.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_slcd_write_SDATAH2_reg(const void *const hw, hri_slcd_sdatah2_reg_t data)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH2.reg = data;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_SDATAH2_reg(const void *const hw, hri_slcd_sdatah2_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH2.reg &= ~mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_SDATAH2_reg(const void *const hw, hri_slcd_sdatah2_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH2.reg ^= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatah2_reg_t hri_slcd_read_SDATAH2_reg(const void *const hw)
{
	return ((Slcd *)hw)->SDATAH2.reg;
}

static inline void hri_slcd_set_SDATAL3_SDATA_bf(const void *const hw, hri_slcd_sdatal3_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL3.reg |= SLCD_SDATAL3_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatal3_reg_t hri_slcd_get_SDATAL3_SDATA_bf(const void *const hw, hri_slcd_sdatal3_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAL3.reg;
	tmp = (tmp & SLCD_SDATAL3_SDATA(mask)) >> SLCD_SDATAL3_SDATA_Pos;
	return tmp;
}

static inline void hri_slcd_write_SDATAL3_SDATA_bf(const void *const hw, hri_slcd_sdatal3_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->SDATAL3.reg;
	tmp &= ~SLCD_SDATAL3_SDATA_Msk;
	tmp |= SLCD_SDATAL3_SDATA(data);
	((Slcd *)hw)->SDATAL3.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_SDATAL3_SDATA_bf(const void *const hw, hri_slcd_sdatal3_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL3.reg &= ~SLCD_SDATAL3_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_SDATAL3_SDATA_bf(const void *const hw, hri_slcd_sdatal3_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL3.reg ^= SLCD_SDATAL3_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatal3_reg_t hri_slcd_read_SDATAL3_SDATA_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAL3.reg;
	tmp = (tmp & SLCD_SDATAL3_SDATA_Msk) >> SLCD_SDATAL3_SDATA_Pos;
	return tmp;
}

static inline void hri_slcd_set_SDATAL3_reg(const void *const hw, hri_slcd_sdatal3_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL3.reg |= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatal3_reg_t hri_slcd_get_SDATAL3_reg(const void *const hw, hri_slcd_sdatal3_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAL3.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_slcd_write_SDATAL3_reg(const void *const hw, hri_slcd_sdatal3_reg_t data)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL3.reg = data;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_SDATAL3_reg(const void *const hw, hri_slcd_sdatal3_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL3.reg &= ~mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_SDATAL3_reg(const void *const hw, hri_slcd_sdatal3_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL3.reg ^= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatal3_reg_t hri_slcd_read_SDATAL3_reg(const void *const hw)
{
	return ((Slcd *)hw)->SDATAL3.reg;
}

static inline void hri_slcd_set_SDATAH3_SDATA_bf(const void *const hw, hri_slcd_sdatah3_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH3.reg |= SLCD_SDATAH3_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatah3_reg_t hri_slcd_get_SDATAH3_SDATA_bf(const void *const hw, hri_slcd_sdatah3_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAH3.reg;
	tmp = (tmp & SLCD_SDATAH3_SDATA(mask)) >> SLCD_SDATAH3_SDATA_Pos;
	return tmp;
}

static inline void hri_slcd_write_SDATAH3_SDATA_bf(const void *const hw, hri_slcd_sdatah3_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->SDATAH3.reg;
	tmp &= ~SLCD_SDATAH3_SDATA_Msk;
	tmp |= SLCD_SDATAH3_SDATA(data);
	((Slcd *)hw)->SDATAH3.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_SDATAH3_SDATA_bf(const void *const hw, hri_slcd_sdatah3_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH3.reg &= ~SLCD_SDATAH3_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_SDATAH3_SDATA_bf(const void *const hw, hri_slcd_sdatah3_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH3.reg ^= SLCD_SDATAH3_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatah3_reg_t hri_slcd_read_SDATAH3_SDATA_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAH3.reg;
	tmp = (tmp & SLCD_SDATAH3_SDATA_Msk) >> SLCD_SDATAH3_SDATA_Pos;
	return tmp;
}

static inline void hri_slcd_set_SDATAH3_reg(const void *const hw, hri_slcd_sdatah3_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH3.reg |= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatah3_reg_t hri_slcd_get_SDATAH3_reg(const void *const hw, hri_slcd_sdatah3_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAH3.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_slcd_write_SDATAH3_reg(const void *const hw, hri_slcd_sdatah3_reg_t data)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH3.reg = data;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_SDATAH3_reg(const void *const hw, hri_slcd_sdatah3_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH3.reg &= ~mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_SDATAH3_reg(const void *const hw, hri_slcd_sdatah3_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH3.reg ^= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatah3_reg_t hri_slcd_read_SDATAH3_reg(const void *const hw)
{
	return ((Slcd *)hw)->SDATAH3.reg;
}

static inline void hri_slcd_set_SDATAL4_SDATA_bf(const void *const hw, hri_slcd_sdatal4_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL4.reg |= SLCD_SDATAL4_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatal4_reg_t hri_slcd_get_SDATAL4_SDATA_bf(const void *const hw, hri_slcd_sdatal4_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAL4.reg;
	tmp = (tmp & SLCD_SDATAL4_SDATA(mask)) >> SLCD_SDATAL4_SDATA_Pos;
	return tmp;
}

static inline void hri_slcd_write_SDATAL4_SDATA_bf(const void *const hw, hri_slcd_sdatal4_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->SDATAL4.reg;
	tmp &= ~SLCD_SDATAL4_SDATA_Msk;
	tmp |= SLCD_SDATAL4_SDATA(data);
	((Slcd *)hw)->SDATAL4.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_SDATAL4_SDATA_bf(const void *const hw, hri_slcd_sdatal4_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL4.reg &= ~SLCD_SDATAL4_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_SDATAL4_SDATA_bf(const void *const hw, hri_slcd_sdatal4_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL4.reg ^= SLCD_SDATAL4_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatal4_reg_t hri_slcd_read_SDATAL4_SDATA_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAL4.reg;
	tmp = (tmp & SLCD_SDATAL4_SDATA_Msk) >> SLCD_SDATAL4_SDATA_Pos;
	return tmp;
}

static inline void hri_slcd_set_SDATAL4_reg(const void *const hw, hri_slcd_sdatal4_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL4.reg |= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatal4_reg_t hri_slcd_get_SDATAL4_reg(const void *const hw, hri_slcd_sdatal4_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAL4.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_slcd_write_SDATAL4_reg(const void *const hw, hri_slcd_sdatal4_reg_t data)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL4.reg = data;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_SDATAL4_reg(const void *const hw, hri_slcd_sdatal4_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL4.reg &= ~mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_SDATAL4_reg(const void *const hw, hri_slcd_sdatal4_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL4.reg ^= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatal4_reg_t hri_slcd_read_SDATAL4_reg(const void *const hw)
{
	return ((Slcd *)hw)->SDATAL4.reg;
}

static inline void hri_slcd_set_SDATAH4_SDATA_bf(const void *const hw, hri_slcd_sdatah4_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH4.reg |= SLCD_SDATAH4_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatah4_reg_t hri_slcd_get_SDATAH4_SDATA_bf(const void *const hw, hri_slcd_sdatah4_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAH4.reg;
	tmp = (tmp & SLCD_SDATAH4_SDATA(mask)) >> SLCD_SDATAH4_SDATA_Pos;
	return tmp;
}

static inline void hri_slcd_write_SDATAH4_SDATA_bf(const void *const hw, hri_slcd_sdatah4_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->SDATAH4.reg;
	tmp &= ~SLCD_SDATAH4_SDATA_Msk;
	tmp |= SLCD_SDATAH4_SDATA(data);
	((Slcd *)hw)->SDATAH4.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_SDATAH4_SDATA_bf(const void *const hw, hri_slcd_sdatah4_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH4.reg &= ~SLCD_SDATAH4_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_SDATAH4_SDATA_bf(const void *const hw, hri_slcd_sdatah4_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH4.reg ^= SLCD_SDATAH4_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatah4_reg_t hri_slcd_read_SDATAH4_SDATA_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAH4.reg;
	tmp = (tmp & SLCD_SDATAH4_SDATA_Msk) >> SLCD_SDATAH4_SDATA_Pos;
	return tmp;
}

static inline void hri_slcd_set_SDATAH4_reg(const void *const hw, hri_slcd_sdatah4_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH4.reg |= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatah4_reg_t hri_slcd_get_SDATAH4_reg(const void *const hw, hri_slcd_sdatah4_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAH4.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_slcd_write_SDATAH4_reg(const void *const hw, hri_slcd_sdatah4_reg_t data)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH4.reg = data;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_SDATAH4_reg(const void *const hw, hri_slcd_sdatah4_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH4.reg &= ~mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_SDATAH4_reg(const void *const hw, hri_slcd_sdatah4_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH4.reg ^= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatah4_reg_t hri_slcd_read_SDATAH4_reg(const void *const hw)
{
	return ((Slcd *)hw)->SDATAH4.reg;
}

static inline void hri_slcd_set_SDATAL5_SDATA_bf(const void *const hw, hri_slcd_sdatal5_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL5.reg |= SLCD_SDATAL5_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatal5_reg_t hri_slcd_get_SDATAL5_SDATA_bf(const void *const hw, hri_slcd_sdatal5_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAL5.reg;
	tmp = (tmp & SLCD_SDATAL5_SDATA(mask)) >> SLCD_SDATAL5_SDATA_Pos;
	return tmp;
}

static inline void hri_slcd_write_SDATAL5_SDATA_bf(const void *const hw, hri_slcd_sdatal5_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->SDATAL5.reg;
	tmp &= ~SLCD_SDATAL5_SDATA_Msk;
	tmp |= SLCD_SDATAL5_SDATA(data);
	((Slcd *)hw)->SDATAL5.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_SDATAL5_SDATA_bf(const void *const hw, hri_slcd_sdatal5_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL5.reg &= ~SLCD_SDATAL5_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_SDATAL5_SDATA_bf(const void *const hw, hri_slcd_sdatal5_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL5.reg ^= SLCD_SDATAL5_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatal5_reg_t hri_slcd_read_SDATAL5_SDATA_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAL5.reg;
	tmp = (tmp & SLCD_SDATAL5_SDATA_Msk) >> SLCD_SDATAL5_SDATA_Pos;
	return tmp;
}

static inline void hri_slcd_set_SDATAL5_reg(const void *const hw, hri_slcd_sdatal5_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL5.reg |= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatal5_reg_t hri_slcd_get_SDATAL5_reg(const void *const hw, hri_slcd_sdatal5_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAL5.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_slcd_write_SDATAL5_reg(const void *const hw, hri_slcd_sdatal5_reg_t data)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL5.reg = data;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_SDATAL5_reg(const void *const hw, hri_slcd_sdatal5_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL5.reg &= ~mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_SDATAL5_reg(const void *const hw, hri_slcd_sdatal5_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL5.reg ^= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatal5_reg_t hri_slcd_read_SDATAL5_reg(const void *const hw)
{
	return ((Slcd *)hw)->SDATAL5.reg;
}

static inline void hri_slcd_set_SDATAH5_SDATA_bf(const void *const hw, hri_slcd_sdatah5_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH5.reg |= SLCD_SDATAH5_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatah5_reg_t hri_slcd_get_SDATAH5_SDATA_bf(const void *const hw, hri_slcd_sdatah5_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAH5.reg;
	tmp = (tmp & SLCD_SDATAH5_SDATA(mask)) >> SLCD_SDATAH5_SDATA_Pos;
	return tmp;
}

static inline void hri_slcd_write_SDATAH5_SDATA_bf(const void *const hw, hri_slcd_sdatah5_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->SDATAH5.reg;
	tmp &= ~SLCD_SDATAH5_SDATA_Msk;
	tmp |= SLCD_SDATAH5_SDATA(data);
	((Slcd *)hw)->SDATAH5.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_SDATAH5_SDATA_bf(const void *const hw, hri_slcd_sdatah5_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH5.reg &= ~SLCD_SDATAH5_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_SDATAH5_SDATA_bf(const void *const hw, hri_slcd_sdatah5_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH5.reg ^= SLCD_SDATAH5_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatah5_reg_t hri_slcd_read_SDATAH5_SDATA_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAH5.reg;
	tmp = (tmp & SLCD_SDATAH5_SDATA_Msk) >> SLCD_SDATAH5_SDATA_Pos;
	return tmp;
}

static inline void hri_slcd_set_SDATAH5_reg(const void *const hw, hri_slcd_sdatah5_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH5.reg |= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatah5_reg_t hri_slcd_get_SDATAH5_reg(const void *const hw, hri_slcd_sdatah5_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAH5.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_slcd_write_SDATAH5_reg(const void *const hw, hri_slcd_sdatah5_reg_t data)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH5.reg = data;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_SDATAH5_reg(const void *const hw, hri_slcd_sdatah5_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH5.reg &= ~mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_SDATAH5_reg(const void *const hw, hri_slcd_sdatah5_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH5.reg ^= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatah5_reg_t hri_slcd_read_SDATAH5_reg(const void *const hw)
{
	return ((Slcd *)hw)->SDATAH5.reg;
}

static inline void hri_slcd_set_SDATAL6_SDATA_bf(const void *const hw, hri_slcd_sdatal6_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL6.reg |= SLCD_SDATAL6_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatal6_reg_t hri_slcd_get_SDATAL6_SDATA_bf(const void *const hw, hri_slcd_sdatal6_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAL6.reg;
	tmp = (tmp & SLCD_SDATAL6_SDATA(mask)) >> SLCD_SDATAL6_SDATA_Pos;
	return tmp;
}

static inline void hri_slcd_write_SDATAL6_SDATA_bf(const void *const hw, hri_slcd_sdatal6_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->SDATAL6.reg;
	tmp &= ~SLCD_SDATAL6_SDATA_Msk;
	tmp |= SLCD_SDATAL6_SDATA(data);
	((Slcd *)hw)->SDATAL6.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_SDATAL6_SDATA_bf(const void *const hw, hri_slcd_sdatal6_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL6.reg &= ~SLCD_SDATAL6_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_SDATAL6_SDATA_bf(const void *const hw, hri_slcd_sdatal6_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL6.reg ^= SLCD_SDATAL6_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatal6_reg_t hri_slcd_read_SDATAL6_SDATA_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAL6.reg;
	tmp = (tmp & SLCD_SDATAL6_SDATA_Msk) >> SLCD_SDATAL6_SDATA_Pos;
	return tmp;
}

static inline void hri_slcd_set_SDATAL6_reg(const void *const hw, hri_slcd_sdatal6_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL6.reg |= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatal6_reg_t hri_slcd_get_SDATAL6_reg(const void *const hw, hri_slcd_sdatal6_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAL6.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_slcd_write_SDATAL6_reg(const void *const hw, hri_slcd_sdatal6_reg_t data)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL6.reg = data;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_SDATAL6_reg(const void *const hw, hri_slcd_sdatal6_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL6.reg &= ~mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_SDATAL6_reg(const void *const hw, hri_slcd_sdatal6_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL6.reg ^= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatal6_reg_t hri_slcd_read_SDATAL6_reg(const void *const hw)
{
	return ((Slcd *)hw)->SDATAL6.reg;
}

static inline void hri_slcd_set_SDATAH6_SDATA_bf(const void *const hw, hri_slcd_sdatah6_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH6.reg |= SLCD_SDATAH6_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatah6_reg_t hri_slcd_get_SDATAH6_SDATA_bf(const void *const hw, hri_slcd_sdatah6_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAH6.reg;
	tmp = (tmp & SLCD_SDATAH6_SDATA(mask)) >> SLCD_SDATAH6_SDATA_Pos;
	return tmp;
}

static inline void hri_slcd_write_SDATAH6_SDATA_bf(const void *const hw, hri_slcd_sdatah6_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->SDATAH6.reg;
	tmp &= ~SLCD_SDATAH6_SDATA_Msk;
	tmp |= SLCD_SDATAH6_SDATA(data);
	((Slcd *)hw)->SDATAH6.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_SDATAH6_SDATA_bf(const void *const hw, hri_slcd_sdatah6_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH6.reg &= ~SLCD_SDATAH6_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_SDATAH6_SDATA_bf(const void *const hw, hri_slcd_sdatah6_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH6.reg ^= SLCD_SDATAH6_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatah6_reg_t hri_slcd_read_SDATAH6_SDATA_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAH6.reg;
	tmp = (tmp & SLCD_SDATAH6_SDATA_Msk) >> SLCD_SDATAH6_SDATA_Pos;
	return tmp;
}

static inline void hri_slcd_set_SDATAH6_reg(const void *const hw, hri_slcd_sdatah6_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH6.reg |= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatah6_reg_t hri_slcd_get_SDATAH6_reg(const void *const hw, hri_slcd_sdatah6_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAH6.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_slcd_write_SDATAH6_reg(const void *const hw, hri_slcd_sdatah6_reg_t data)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH6.reg = data;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_SDATAH6_reg(const void *const hw, hri_slcd_sdatah6_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH6.reg &= ~mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_SDATAH6_reg(const void *const hw, hri_slcd_sdatah6_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH6.reg ^= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatah6_reg_t hri_slcd_read_SDATAH6_reg(const void *const hw)
{
	return ((Slcd *)hw)->SDATAH6.reg;
}

static inline void hri_slcd_set_SDATAL7_SDATA_bf(const void *const hw, hri_slcd_sdatal7_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL7.reg |= SLCD_SDATAL7_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatal7_reg_t hri_slcd_get_SDATAL7_SDATA_bf(const void *const hw, hri_slcd_sdatal7_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAL7.reg;
	tmp = (tmp & SLCD_SDATAL7_SDATA(mask)) >> SLCD_SDATAL7_SDATA_Pos;
	return tmp;
}

static inline void hri_slcd_write_SDATAL7_SDATA_bf(const void *const hw, hri_slcd_sdatal7_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->SDATAL7.reg;
	tmp &= ~SLCD_SDATAL7_SDATA_Msk;
	tmp |= SLCD_SDATAL7_SDATA(data);
	((Slcd *)hw)->SDATAL7.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_SDATAL7_SDATA_bf(const void *const hw, hri_slcd_sdatal7_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL7.reg &= ~SLCD_SDATAL7_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_SDATAL7_SDATA_bf(const void *const hw, hri_slcd_sdatal7_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL7.reg ^= SLCD_SDATAL7_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatal7_reg_t hri_slcd_read_SDATAL7_SDATA_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAL7.reg;
	tmp = (tmp & SLCD_SDATAL7_SDATA_Msk) >> SLCD_SDATAL7_SDATA_Pos;
	return tmp;
}

static inline void hri_slcd_set_SDATAL7_reg(const void *const hw, hri_slcd_sdatal7_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL7.reg |= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatal7_reg_t hri_slcd_get_SDATAL7_reg(const void *const hw, hri_slcd_sdatal7_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAL7.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_slcd_write_SDATAL7_reg(const void *const hw, hri_slcd_sdatal7_reg_t data)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL7.reg = data;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_SDATAL7_reg(const void *const hw, hri_slcd_sdatal7_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL7.reg &= ~mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_SDATAL7_reg(const void *const hw, hri_slcd_sdatal7_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAL7.reg ^= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatal7_reg_t hri_slcd_read_SDATAL7_reg(const void *const hw)
{
	return ((Slcd *)hw)->SDATAL7.reg;
}

static inline void hri_slcd_set_SDATAH7_SDATA_bf(const void *const hw, hri_slcd_sdatah7_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH7.reg |= SLCD_SDATAH7_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatah7_reg_t hri_slcd_get_SDATAH7_SDATA_bf(const void *const hw, hri_slcd_sdatah7_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAH7.reg;
	tmp = (tmp & SLCD_SDATAH7_SDATA(mask)) >> SLCD_SDATAH7_SDATA_Pos;
	return tmp;
}

static inline void hri_slcd_write_SDATAH7_SDATA_bf(const void *const hw, hri_slcd_sdatah7_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->SDATAH7.reg;
	tmp &= ~SLCD_SDATAH7_SDATA_Msk;
	tmp |= SLCD_SDATAH7_SDATA(data);
	((Slcd *)hw)->SDATAH7.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_SDATAH7_SDATA_bf(const void *const hw, hri_slcd_sdatah7_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH7.reg &= ~SLCD_SDATAH7_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_SDATAH7_SDATA_bf(const void *const hw, hri_slcd_sdatah7_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH7.reg ^= SLCD_SDATAH7_SDATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatah7_reg_t hri_slcd_read_SDATAH7_SDATA_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAH7.reg;
	tmp = (tmp & SLCD_SDATAH7_SDATA_Msk) >> SLCD_SDATAH7_SDATA_Pos;
	return tmp;
}

static inline void hri_slcd_set_SDATAH7_reg(const void *const hw, hri_slcd_sdatah7_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH7.reg |= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatah7_reg_t hri_slcd_get_SDATAH7_reg(const void *const hw, hri_slcd_sdatah7_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->SDATAH7.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_slcd_write_SDATAH7_reg(const void *const hw, hri_slcd_sdatah7_reg_t data)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH7.reg = data;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_SDATAH7_reg(const void *const hw, hri_slcd_sdatah7_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH7.reg &= ~mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_SDATAH7_reg(const void *const hw, hri_slcd_sdatah7_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->SDATAH7.reg ^= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_sdatah7_reg_t hri_slcd_read_SDATAH7_reg(const void *const hw)
{
	return ((Slcd *)hw)->SDATAH7.reg;
}

static inline void hri_slcd_set_BCFG_MODE_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->BCFG.reg |= SLCD_BCFG_MODE;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_slcd_get_BCFG_MODE_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->BCFG.reg;
	tmp = (tmp & SLCD_BCFG_MODE) >> SLCD_BCFG_MODE_Pos;
	return (bool)tmp;
}

static inline void hri_slcd_write_BCFG_MODE_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->BCFG.reg;
	tmp &= ~SLCD_BCFG_MODE;
	tmp |= value << SLCD_BCFG_MODE_Pos;
	((Slcd *)hw)->BCFG.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_BCFG_MODE_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->BCFG.reg &= ~SLCD_BCFG_MODE;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_BCFG_MODE_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->BCFG.reg ^= SLCD_BCFG_MODE;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_set_BCFG_FCS_bf(const void *const hw, hri_slcd_bcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->BCFG.reg |= SLCD_BCFG_FCS(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_bcfg_reg_t hri_slcd_get_BCFG_FCS_bf(const void *const hw, hri_slcd_bcfg_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->BCFG.reg;
	tmp = (tmp & SLCD_BCFG_FCS(mask)) >> SLCD_BCFG_FCS_Pos;
	return tmp;
}

static inline void hri_slcd_write_BCFG_FCS_bf(const void *const hw, hri_slcd_bcfg_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->BCFG.reg;
	tmp &= ~SLCD_BCFG_FCS_Msk;
	tmp |= SLCD_BCFG_FCS(data);
	((Slcd *)hw)->BCFG.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_BCFG_FCS_bf(const void *const hw, hri_slcd_bcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->BCFG.reg &= ~SLCD_BCFG_FCS(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_BCFG_FCS_bf(const void *const hw, hri_slcd_bcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->BCFG.reg ^= SLCD_BCFG_FCS(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_bcfg_reg_t hri_slcd_read_BCFG_FCS_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->BCFG.reg;
	tmp = (tmp & SLCD_BCFG_FCS_Msk) >> SLCD_BCFG_FCS_Pos;
	return tmp;
}

static inline void hri_slcd_set_BCFG_BSS0_bf(const void *const hw, hri_slcd_bcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->BCFG.reg |= SLCD_BCFG_BSS0(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_bcfg_reg_t hri_slcd_get_BCFG_BSS0_bf(const void *const hw, hri_slcd_bcfg_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->BCFG.reg;
	tmp = (tmp & SLCD_BCFG_BSS0(mask)) >> SLCD_BCFG_BSS0_Pos;
	return tmp;
}

static inline void hri_slcd_write_BCFG_BSS0_bf(const void *const hw, hri_slcd_bcfg_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->BCFG.reg;
	tmp &= ~SLCD_BCFG_BSS0_Msk;
	tmp |= SLCD_BCFG_BSS0(data);
	((Slcd *)hw)->BCFG.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_BCFG_BSS0_bf(const void *const hw, hri_slcd_bcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->BCFG.reg &= ~SLCD_BCFG_BSS0(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_BCFG_BSS0_bf(const void *const hw, hri_slcd_bcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->BCFG.reg ^= SLCD_BCFG_BSS0(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_bcfg_reg_t hri_slcd_read_BCFG_BSS0_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->BCFG.reg;
	tmp = (tmp & SLCD_BCFG_BSS0_Msk) >> SLCD_BCFG_BSS0_Pos;
	return tmp;
}

static inline void hri_slcd_set_BCFG_BSS1_bf(const void *const hw, hri_slcd_bcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->BCFG.reg |= SLCD_BCFG_BSS1(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_bcfg_reg_t hri_slcd_get_BCFG_BSS1_bf(const void *const hw, hri_slcd_bcfg_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->BCFG.reg;
	tmp = (tmp & SLCD_BCFG_BSS1(mask)) >> SLCD_BCFG_BSS1_Pos;
	return tmp;
}

static inline void hri_slcd_write_BCFG_BSS1_bf(const void *const hw, hri_slcd_bcfg_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->BCFG.reg;
	tmp &= ~SLCD_BCFG_BSS1_Msk;
	tmp |= SLCD_BCFG_BSS1(data);
	((Slcd *)hw)->BCFG.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_BCFG_BSS1_bf(const void *const hw, hri_slcd_bcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->BCFG.reg &= ~SLCD_BCFG_BSS1(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_BCFG_BSS1_bf(const void *const hw, hri_slcd_bcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->BCFG.reg ^= SLCD_BCFG_BSS1(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_bcfg_reg_t hri_slcd_read_BCFG_BSS1_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->BCFG.reg;
	tmp = (tmp & SLCD_BCFG_BSS1_Msk) >> SLCD_BCFG_BSS1_Pos;
	return tmp;
}

static inline void hri_slcd_set_BCFG_reg(const void *const hw, hri_slcd_bcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->BCFG.reg |= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_bcfg_reg_t hri_slcd_get_BCFG_reg(const void *const hw, hri_slcd_bcfg_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->BCFG.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_slcd_write_BCFG_reg(const void *const hw, hri_slcd_bcfg_reg_t data)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->BCFG.reg = data;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_BCFG_reg(const void *const hw, hri_slcd_bcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->BCFG.reg &= ~mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_BCFG_reg(const void *const hw, hri_slcd_bcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->BCFG.reg ^= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_bcfg_reg_t hri_slcd_read_BCFG_reg(const void *const hw)
{
	return ((Slcd *)hw)->BCFG.reg;
}

static inline void hri_slcd_set_CSRCFG_DIR_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CSRCFG.reg |= SLCD_CSRCFG_DIR;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_slcd_get_CSRCFG_DIR_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->CSRCFG.reg;
	tmp = (tmp & SLCD_CSRCFG_DIR) >> SLCD_CSRCFG_DIR_Pos;
	return (bool)tmp;
}

static inline void hri_slcd_write_CSRCFG_DIR_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CSRCFG.reg;
	tmp &= ~SLCD_CSRCFG_DIR;
	tmp |= value << SLCD_CSRCFG_DIR_Pos;
	((Slcd *)hw)->CSRCFG.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CSRCFG_DIR_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CSRCFG.reg &= ~SLCD_CSRCFG_DIR;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CSRCFG_DIR_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CSRCFG.reg ^= SLCD_CSRCFG_DIR;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_set_CSRCFG_FCS_bf(const void *const hw, hri_slcd_csrcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CSRCFG.reg |= SLCD_CSRCFG_FCS(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_csrcfg_reg_t hri_slcd_get_CSRCFG_FCS_bf(const void *const hw, hri_slcd_csrcfg_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->CSRCFG.reg;
	tmp = (tmp & SLCD_CSRCFG_FCS(mask)) >> SLCD_CSRCFG_FCS_Pos;
	return tmp;
}

static inline void hri_slcd_write_CSRCFG_FCS_bf(const void *const hw, hri_slcd_csrcfg_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CSRCFG.reg;
	tmp &= ~SLCD_CSRCFG_FCS_Msk;
	tmp |= SLCD_CSRCFG_FCS(data);
	((Slcd *)hw)->CSRCFG.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CSRCFG_FCS_bf(const void *const hw, hri_slcd_csrcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CSRCFG.reg &= ~SLCD_CSRCFG_FCS(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CSRCFG_FCS_bf(const void *const hw, hri_slcd_csrcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CSRCFG.reg ^= SLCD_CSRCFG_FCS(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_csrcfg_reg_t hri_slcd_read_CSRCFG_FCS_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->CSRCFG.reg;
	tmp = (tmp & SLCD_CSRCFG_FCS_Msk) >> SLCD_CSRCFG_FCS_Pos;
	return tmp;
}

static inline void hri_slcd_set_CSRCFG_SIZE_bf(const void *const hw, hri_slcd_csrcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CSRCFG.reg |= SLCD_CSRCFG_SIZE(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_csrcfg_reg_t hri_slcd_get_CSRCFG_SIZE_bf(const void *const hw, hri_slcd_csrcfg_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->CSRCFG.reg;
	tmp = (tmp & SLCD_CSRCFG_SIZE(mask)) >> SLCD_CSRCFG_SIZE_Pos;
	return tmp;
}

static inline void hri_slcd_write_CSRCFG_SIZE_bf(const void *const hw, hri_slcd_csrcfg_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CSRCFG.reg;
	tmp &= ~SLCD_CSRCFG_SIZE_Msk;
	tmp |= SLCD_CSRCFG_SIZE(data);
	((Slcd *)hw)->CSRCFG.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CSRCFG_SIZE_bf(const void *const hw, hri_slcd_csrcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CSRCFG.reg &= ~SLCD_CSRCFG_SIZE(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CSRCFG_SIZE_bf(const void *const hw, hri_slcd_csrcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CSRCFG.reg ^= SLCD_CSRCFG_SIZE(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_csrcfg_reg_t hri_slcd_read_CSRCFG_SIZE_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->CSRCFG.reg;
	tmp = (tmp & SLCD_CSRCFG_SIZE_Msk) >> SLCD_CSRCFG_SIZE_Pos;
	return tmp;
}

static inline void hri_slcd_set_CSRCFG_DATA_bf(const void *const hw, hri_slcd_csrcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CSRCFG.reg |= SLCD_CSRCFG_DATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_csrcfg_reg_t hri_slcd_get_CSRCFG_DATA_bf(const void *const hw, hri_slcd_csrcfg_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->CSRCFG.reg;
	tmp = (tmp & SLCD_CSRCFG_DATA(mask)) >> SLCD_CSRCFG_DATA_Pos;
	return tmp;
}

static inline void hri_slcd_write_CSRCFG_DATA_bf(const void *const hw, hri_slcd_csrcfg_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CSRCFG.reg;
	tmp &= ~SLCD_CSRCFG_DATA_Msk;
	tmp |= SLCD_CSRCFG_DATA(data);
	((Slcd *)hw)->CSRCFG.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CSRCFG_DATA_bf(const void *const hw, hri_slcd_csrcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CSRCFG.reg &= ~SLCD_CSRCFG_DATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CSRCFG_DATA_bf(const void *const hw, hri_slcd_csrcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CSRCFG.reg ^= SLCD_CSRCFG_DATA(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_csrcfg_reg_t hri_slcd_read_CSRCFG_DATA_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->CSRCFG.reg;
	tmp = (tmp & SLCD_CSRCFG_DATA_Msk) >> SLCD_CSRCFG_DATA_Pos;
	return tmp;
}

static inline void hri_slcd_set_CSRCFG_reg(const void *const hw, hri_slcd_csrcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CSRCFG.reg |= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_csrcfg_reg_t hri_slcd_get_CSRCFG_reg(const void *const hw, hri_slcd_csrcfg_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->CSRCFG.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_slcd_write_CSRCFG_reg(const void *const hw, hri_slcd_csrcfg_reg_t data)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CSRCFG.reg = data;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CSRCFG_reg(const void *const hw, hri_slcd_csrcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CSRCFG.reg &= ~mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CSRCFG_reg(const void *const hw, hri_slcd_csrcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CSRCFG.reg ^= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_csrcfg_reg_t hri_slcd_read_CSRCFG_reg(const void *const hw)
{
	return ((Slcd *)hw)->CSRCFG.reg;
}

static inline void hri_slcd_set_CMCFG_DEC_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CMCFG.reg |= SLCD_CMCFG_DEC;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_slcd_get_CMCFG_DEC_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Slcd *)hw)->CMCFG.reg;
	tmp = (tmp & SLCD_CMCFG_DEC) >> SLCD_CMCFG_DEC_Pos;
	return (bool)tmp;
}

static inline void hri_slcd_write_CMCFG_DEC_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CMCFG.reg;
	tmp &= ~SLCD_CMCFG_DEC;
	tmp |= value << SLCD_CMCFG_DEC_Pos;
	((Slcd *)hw)->CMCFG.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CMCFG_DEC_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CMCFG.reg &= ~SLCD_CMCFG_DEC;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CMCFG_DEC_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CMCFG.reg ^= SLCD_CMCFG_DEC;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_set_CMCFG_NSEG_bf(const void *const hw, hri_slcd_cmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CMCFG.reg |= SLCD_CMCFG_NSEG(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_cmcfg_reg_t hri_slcd_get_CMCFG_NSEG_bf(const void *const hw, hri_slcd_cmcfg_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Slcd *)hw)->CMCFG.reg;
	tmp = (tmp & SLCD_CMCFG_NSEG(mask)) >> SLCD_CMCFG_NSEG_Pos;
	return tmp;
}

static inline void hri_slcd_write_CMCFG_NSEG_bf(const void *const hw, hri_slcd_cmcfg_reg_t data)
{
	uint8_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CMCFG.reg;
	tmp &= ~SLCD_CMCFG_NSEG_Msk;
	tmp |= SLCD_CMCFG_NSEG(data);
	((Slcd *)hw)->CMCFG.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CMCFG_NSEG_bf(const void *const hw, hri_slcd_cmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CMCFG.reg &= ~SLCD_CMCFG_NSEG(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CMCFG_NSEG_bf(const void *const hw, hri_slcd_cmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CMCFG.reg ^= SLCD_CMCFG_NSEG(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_cmcfg_reg_t hri_slcd_read_CMCFG_NSEG_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Slcd *)hw)->CMCFG.reg;
	tmp = (tmp & SLCD_CMCFG_NSEG_Msk) >> SLCD_CMCFG_NSEG_Pos;
	return tmp;
}

static inline void hri_slcd_set_CMCFG_reg(const void *const hw, hri_slcd_cmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CMCFG.reg |= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_cmcfg_reg_t hri_slcd_get_CMCFG_reg(const void *const hw, hri_slcd_cmcfg_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Slcd *)hw)->CMCFG.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_slcd_write_CMCFG_reg(const void *const hw, hri_slcd_cmcfg_reg_t data)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CMCFG.reg = data;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CMCFG_reg(const void *const hw, hri_slcd_cmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CMCFG.reg &= ~mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CMCFG_reg(const void *const hw, hri_slcd_cmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CMCFG.reg ^= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_cmcfg_reg_t hri_slcd_read_CMCFG_reg(const void *const hw)
{
	return ((Slcd *)hw)->CMCFG.reg;
}

static inline void hri_slcd_set_ACMCFG_MODE_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ACMCFG.reg |= SLCD_ACMCFG_MODE;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_slcd_get_ACMCFG_MODE_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->ACMCFG.reg;
	tmp = (tmp & SLCD_ACMCFG_MODE) >> SLCD_ACMCFG_MODE_Pos;
	return (bool)tmp;
}

static inline void hri_slcd_write_ACMCFG_MODE_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->ACMCFG.reg;
	tmp &= ~SLCD_ACMCFG_MODE;
	tmp |= value << SLCD_ACMCFG_MODE_Pos;
	((Slcd *)hw)->ACMCFG.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_ACMCFG_MODE_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ACMCFG.reg &= ~SLCD_ACMCFG_MODE;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_ACMCFG_MODE_bit(const void *const hw)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ACMCFG.reg ^= SLCD_ACMCFG_MODE;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_set_ACMCFG_NCOM_bf(const void *const hw, hri_slcd_acmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ACMCFG.reg |= SLCD_ACMCFG_NCOM(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_acmcfg_reg_t hri_slcd_get_ACMCFG_NCOM_bf(const void *const hw, hri_slcd_acmcfg_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->ACMCFG.reg;
	tmp = (tmp & SLCD_ACMCFG_NCOM(mask)) >> SLCD_ACMCFG_NCOM_Pos;
	return tmp;
}

static inline void hri_slcd_write_ACMCFG_NCOM_bf(const void *const hw, hri_slcd_acmcfg_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->ACMCFG.reg;
	tmp &= ~SLCD_ACMCFG_NCOM_Msk;
	tmp |= SLCD_ACMCFG_NCOM(data);
	((Slcd *)hw)->ACMCFG.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_ACMCFG_NCOM_bf(const void *const hw, hri_slcd_acmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ACMCFG.reg &= ~SLCD_ACMCFG_NCOM(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_ACMCFG_NCOM_bf(const void *const hw, hri_slcd_acmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ACMCFG.reg ^= SLCD_ACMCFG_NCOM(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_acmcfg_reg_t hri_slcd_read_ACMCFG_NCOM_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->ACMCFG.reg;
	tmp = (tmp & SLCD_ACMCFG_NCOM_Msk) >> SLCD_ACMCFG_NCOM_Pos;
	return tmp;
}

static inline void hri_slcd_set_ACMCFG_NDIG_bf(const void *const hw, hri_slcd_acmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ACMCFG.reg |= SLCD_ACMCFG_NDIG(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_acmcfg_reg_t hri_slcd_get_ACMCFG_NDIG_bf(const void *const hw, hri_slcd_acmcfg_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->ACMCFG.reg;
	tmp = (tmp & SLCD_ACMCFG_NDIG(mask)) >> SLCD_ACMCFG_NDIG_Pos;
	return tmp;
}

static inline void hri_slcd_write_ACMCFG_NDIG_bf(const void *const hw, hri_slcd_acmcfg_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->ACMCFG.reg;
	tmp &= ~SLCD_ACMCFG_NDIG_Msk;
	tmp |= SLCD_ACMCFG_NDIG(data);
	((Slcd *)hw)->ACMCFG.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_ACMCFG_NDIG_bf(const void *const hw, hri_slcd_acmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ACMCFG.reg &= ~SLCD_ACMCFG_NDIG(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_ACMCFG_NDIG_bf(const void *const hw, hri_slcd_acmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ACMCFG.reg ^= SLCD_ACMCFG_NDIG(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_acmcfg_reg_t hri_slcd_read_ACMCFG_NDIG_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->ACMCFG.reg;
	tmp = (tmp & SLCD_ACMCFG_NDIG_Msk) >> SLCD_ACMCFG_NDIG_Pos;
	return tmp;
}

static inline void hri_slcd_set_ACMCFG_STEPS_bf(const void *const hw, hri_slcd_acmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ACMCFG.reg |= SLCD_ACMCFG_STEPS(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_acmcfg_reg_t hri_slcd_get_ACMCFG_STEPS_bf(const void *const hw, hri_slcd_acmcfg_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->ACMCFG.reg;
	tmp = (tmp & SLCD_ACMCFG_STEPS(mask)) >> SLCD_ACMCFG_STEPS_Pos;
	return tmp;
}

static inline void hri_slcd_write_ACMCFG_STEPS_bf(const void *const hw, hri_slcd_acmcfg_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->ACMCFG.reg;
	tmp &= ~SLCD_ACMCFG_STEPS_Msk;
	tmp |= SLCD_ACMCFG_STEPS(data);
	((Slcd *)hw)->ACMCFG.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_ACMCFG_STEPS_bf(const void *const hw, hri_slcd_acmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ACMCFG.reg &= ~SLCD_ACMCFG_STEPS(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_ACMCFG_STEPS_bf(const void *const hw, hri_slcd_acmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ACMCFG.reg ^= SLCD_ACMCFG_STEPS(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_acmcfg_reg_t hri_slcd_read_ACMCFG_STEPS_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->ACMCFG.reg;
	tmp = (tmp & SLCD_ACMCFG_STEPS_Msk) >> SLCD_ACMCFG_STEPS_Pos;
	return tmp;
}

static inline void hri_slcd_set_ACMCFG_NDROW_bf(const void *const hw, hri_slcd_acmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ACMCFG.reg |= SLCD_ACMCFG_NDROW(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_acmcfg_reg_t hri_slcd_get_ACMCFG_NDROW_bf(const void *const hw, hri_slcd_acmcfg_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->ACMCFG.reg;
	tmp = (tmp & SLCD_ACMCFG_NDROW(mask)) >> SLCD_ACMCFG_NDROW_Pos;
	return tmp;
}

static inline void hri_slcd_write_ACMCFG_NDROW_bf(const void *const hw, hri_slcd_acmcfg_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->ACMCFG.reg;
	tmp &= ~SLCD_ACMCFG_NDROW_Msk;
	tmp |= SLCD_ACMCFG_NDROW(data);
	((Slcd *)hw)->ACMCFG.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_ACMCFG_NDROW_bf(const void *const hw, hri_slcd_acmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ACMCFG.reg &= ~SLCD_ACMCFG_NDROW(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_ACMCFG_NDROW_bf(const void *const hw, hri_slcd_acmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ACMCFG.reg ^= SLCD_ACMCFG_NDROW(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_acmcfg_reg_t hri_slcd_read_ACMCFG_NDROW_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->ACMCFG.reg;
	tmp = (tmp & SLCD_ACMCFG_NDROW_Msk) >> SLCD_ACMCFG_NDROW_Pos;
	return tmp;
}

static inline void hri_slcd_set_ACMCFG_STSEG_bf(const void *const hw, hri_slcd_acmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ACMCFG.reg |= SLCD_ACMCFG_STSEG(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_acmcfg_reg_t hri_slcd_get_ACMCFG_STSEG_bf(const void *const hw, hri_slcd_acmcfg_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->ACMCFG.reg;
	tmp = (tmp & SLCD_ACMCFG_STSEG(mask)) >> SLCD_ACMCFG_STSEG_Pos;
	return tmp;
}

static inline void hri_slcd_write_ACMCFG_STSEG_bf(const void *const hw, hri_slcd_acmcfg_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->ACMCFG.reg;
	tmp &= ~SLCD_ACMCFG_STSEG_Msk;
	tmp |= SLCD_ACMCFG_STSEG(data);
	((Slcd *)hw)->ACMCFG.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_ACMCFG_STSEG_bf(const void *const hw, hri_slcd_acmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ACMCFG.reg &= ~SLCD_ACMCFG_STSEG(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_ACMCFG_STSEG_bf(const void *const hw, hri_slcd_acmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ACMCFG.reg ^= SLCD_ACMCFG_STSEG(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_acmcfg_reg_t hri_slcd_read_ACMCFG_STSEG_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->ACMCFG.reg;
	tmp = (tmp & SLCD_ACMCFG_STSEG_Msk) >> SLCD_ACMCFG_STSEG_Pos;
	return tmp;
}

static inline void hri_slcd_set_ACMCFG_FCS_bf(const void *const hw, hri_slcd_acmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ACMCFG.reg |= SLCD_ACMCFG_FCS(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_acmcfg_reg_t hri_slcd_get_ACMCFG_FCS_bf(const void *const hw, hri_slcd_acmcfg_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->ACMCFG.reg;
	tmp = (tmp & SLCD_ACMCFG_FCS(mask)) >> SLCD_ACMCFG_FCS_Pos;
	return tmp;
}

static inline void hri_slcd_write_ACMCFG_FCS_bf(const void *const hw, hri_slcd_acmcfg_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->ACMCFG.reg;
	tmp &= ~SLCD_ACMCFG_FCS_Msk;
	tmp |= SLCD_ACMCFG_FCS(data);
	((Slcd *)hw)->ACMCFG.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_ACMCFG_FCS_bf(const void *const hw, hri_slcd_acmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ACMCFG.reg &= ~SLCD_ACMCFG_FCS(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_ACMCFG_FCS_bf(const void *const hw, hri_slcd_acmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ACMCFG.reg ^= SLCD_ACMCFG_FCS(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_acmcfg_reg_t hri_slcd_read_ACMCFG_FCS_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->ACMCFG.reg;
	tmp = (tmp & SLCD_ACMCFG_FCS_Msk) >> SLCD_ACMCFG_FCS_Pos;
	return tmp;
}

static inline void hri_slcd_set_ACMCFG_reg(const void *const hw, hri_slcd_acmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ACMCFG.reg |= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_acmcfg_reg_t hri_slcd_get_ACMCFG_reg(const void *const hw, hri_slcd_acmcfg_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->ACMCFG.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_slcd_write_ACMCFG_reg(const void *const hw, hri_slcd_acmcfg_reg_t data)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ACMCFG.reg = data;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_ACMCFG_reg(const void *const hw, hri_slcd_acmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ACMCFG.reg &= ~mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_ACMCFG_reg(const void *const hw, hri_slcd_acmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ACMCFG.reg ^= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_acmcfg_reg_t hri_slcd_read_ACMCFG_reg(const void *const hw)
{
	return ((Slcd *)hw)->ACMCFG.reg;
}

static inline void hri_slcd_set_ABMCFG_FCS_bf(const void *const hw, hri_slcd_abmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ABMCFG.reg |= SLCD_ABMCFG_FCS(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_abmcfg_reg_t hri_slcd_get_ABMCFG_FCS_bf(const void *const hw, hri_slcd_abmcfg_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Slcd *)hw)->ABMCFG.reg;
	tmp = (tmp & SLCD_ABMCFG_FCS(mask)) >> SLCD_ABMCFG_FCS_Pos;
	return tmp;
}

static inline void hri_slcd_write_ABMCFG_FCS_bf(const void *const hw, hri_slcd_abmcfg_reg_t data)
{
	uint8_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->ABMCFG.reg;
	tmp &= ~SLCD_ABMCFG_FCS_Msk;
	tmp |= SLCD_ABMCFG_FCS(data);
	((Slcd *)hw)->ABMCFG.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_ABMCFG_FCS_bf(const void *const hw, hri_slcd_abmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ABMCFG.reg &= ~SLCD_ABMCFG_FCS(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_ABMCFG_FCS_bf(const void *const hw, hri_slcd_abmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ABMCFG.reg ^= SLCD_ABMCFG_FCS(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_abmcfg_reg_t hri_slcd_read_ABMCFG_FCS_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Slcd *)hw)->ABMCFG.reg;
	tmp = (tmp & SLCD_ABMCFG_FCS_Msk) >> SLCD_ABMCFG_FCS_Pos;
	return tmp;
}

static inline void hri_slcd_set_ABMCFG_SIZE_bf(const void *const hw, hri_slcd_abmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ABMCFG.reg |= SLCD_ABMCFG_SIZE(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_abmcfg_reg_t hri_slcd_get_ABMCFG_SIZE_bf(const void *const hw, hri_slcd_abmcfg_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Slcd *)hw)->ABMCFG.reg;
	tmp = (tmp & SLCD_ABMCFG_SIZE(mask)) >> SLCD_ABMCFG_SIZE_Pos;
	return tmp;
}

static inline void hri_slcd_write_ABMCFG_SIZE_bf(const void *const hw, hri_slcd_abmcfg_reg_t data)
{
	uint8_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->ABMCFG.reg;
	tmp &= ~SLCD_ABMCFG_SIZE_Msk;
	tmp |= SLCD_ABMCFG_SIZE(data);
	((Slcd *)hw)->ABMCFG.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_ABMCFG_SIZE_bf(const void *const hw, hri_slcd_abmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ABMCFG.reg &= ~SLCD_ABMCFG_SIZE(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_ABMCFG_SIZE_bf(const void *const hw, hri_slcd_abmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ABMCFG.reg ^= SLCD_ABMCFG_SIZE(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_abmcfg_reg_t hri_slcd_read_ABMCFG_SIZE_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Slcd *)hw)->ABMCFG.reg;
	tmp = (tmp & SLCD_ABMCFG_SIZE_Msk) >> SLCD_ABMCFG_SIZE_Pos;
	return tmp;
}

static inline void hri_slcd_set_ABMCFG_reg(const void *const hw, hri_slcd_abmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ABMCFG.reg |= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_abmcfg_reg_t hri_slcd_get_ABMCFG_reg(const void *const hw, hri_slcd_abmcfg_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Slcd *)hw)->ABMCFG.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_slcd_write_ABMCFG_reg(const void *const hw, hri_slcd_abmcfg_reg_t data)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ABMCFG.reg = data;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_ABMCFG_reg(const void *const hw, hri_slcd_abmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ABMCFG.reg &= ~mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_ABMCFG_reg(const void *const hw, hri_slcd_abmcfg_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ABMCFG.reg ^= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_abmcfg_reg_t hri_slcd_read_ABMCFG_reg(const void *const hw)
{
	return ((Slcd *)hw)->ABMCFG.reg;
}

static inline void hri_slcd_set_CMDMASK_SDMASK_bf(const void *const hw, hri_slcd_cmdmask_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CMDMASK.reg |= SLCD_CMDMASK_SDMASK(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_cmdmask_reg_t hri_slcd_get_CMDMASK_SDMASK_bf(const void *const hw, hri_slcd_cmdmask_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->CMDMASK.reg;
	tmp = (tmp & SLCD_CMDMASK_SDMASK(mask)) >> SLCD_CMDMASK_SDMASK_Pos;
	return tmp;
}

static inline void hri_slcd_write_CMDMASK_SDMASK_bf(const void *const hw, hri_slcd_cmdmask_reg_t data)
{
	uint32_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CMDMASK.reg;
	tmp &= ~SLCD_CMDMASK_SDMASK_Msk;
	tmp |= SLCD_CMDMASK_SDMASK(data);
	((Slcd *)hw)->CMDMASK.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CMDMASK_SDMASK_bf(const void *const hw, hri_slcd_cmdmask_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CMDMASK.reg &= ~SLCD_CMDMASK_SDMASK(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CMDMASK_SDMASK_bf(const void *const hw, hri_slcd_cmdmask_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CMDMASK.reg ^= SLCD_CMDMASK_SDMASK(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_cmdmask_reg_t hri_slcd_read_CMDMASK_SDMASK_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->CMDMASK.reg;
	tmp = (tmp & SLCD_CMDMASK_SDMASK_Msk) >> SLCD_CMDMASK_SDMASK_Pos;
	return tmp;
}

static inline void hri_slcd_set_CMDMASK_reg(const void *const hw, hri_slcd_cmdmask_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CMDMASK.reg |= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_cmdmask_reg_t hri_slcd_get_CMDMASK_reg(const void *const hw, hri_slcd_cmdmask_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Slcd *)hw)->CMDMASK.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_slcd_write_CMDMASK_reg(const void *const hw, hri_slcd_cmdmask_reg_t data)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CMDMASK.reg = data;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CMDMASK_reg(const void *const hw, hri_slcd_cmdmask_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CMDMASK.reg &= ~mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CMDMASK_reg(const void *const hw, hri_slcd_cmdmask_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CMDMASK.reg ^= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_cmdmask_reg_t hri_slcd_read_CMDMASK_reg(const void *const hw)
{
	return ((Slcd *)hw)->CMDMASK.reg;
}

static inline void hri_slcd_set_CMINDEX_SINDEX_bf(const void *const hw, hri_slcd_cmindex_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CMINDEX.reg |= SLCD_CMINDEX_SINDEX(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_cmindex_reg_t hri_slcd_get_CMINDEX_SINDEX_bf(const void *const hw, hri_slcd_cmindex_reg_t mask)
{
	uint16_t tmp;
	tmp = ((Slcd *)hw)->CMINDEX.reg;
	tmp = (tmp & SLCD_CMINDEX_SINDEX(mask)) >> SLCD_CMINDEX_SINDEX_Pos;
	return tmp;
}

static inline void hri_slcd_write_CMINDEX_SINDEX_bf(const void *const hw, hri_slcd_cmindex_reg_t data)
{
	uint16_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CMINDEX.reg;
	tmp &= ~SLCD_CMINDEX_SINDEX_Msk;
	tmp |= SLCD_CMINDEX_SINDEX(data);
	((Slcd *)hw)->CMINDEX.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CMINDEX_SINDEX_bf(const void *const hw, hri_slcd_cmindex_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CMINDEX.reg &= ~SLCD_CMINDEX_SINDEX(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CMINDEX_SINDEX_bf(const void *const hw, hri_slcd_cmindex_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CMINDEX.reg ^= SLCD_CMINDEX_SINDEX(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_cmindex_reg_t hri_slcd_read_CMINDEX_SINDEX_bf(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Slcd *)hw)->CMINDEX.reg;
	tmp = (tmp & SLCD_CMINDEX_SINDEX_Msk) >> SLCD_CMINDEX_SINDEX_Pos;
	return tmp;
}

static inline void hri_slcd_set_CMINDEX_CINDEX_bf(const void *const hw, hri_slcd_cmindex_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CMINDEX.reg |= SLCD_CMINDEX_CINDEX(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_cmindex_reg_t hri_slcd_get_CMINDEX_CINDEX_bf(const void *const hw, hri_slcd_cmindex_reg_t mask)
{
	uint16_t tmp;
	tmp = ((Slcd *)hw)->CMINDEX.reg;
	tmp = (tmp & SLCD_CMINDEX_CINDEX(mask)) >> SLCD_CMINDEX_CINDEX_Pos;
	return tmp;
}

static inline void hri_slcd_write_CMINDEX_CINDEX_bf(const void *const hw, hri_slcd_cmindex_reg_t data)
{
	uint16_t tmp;
	SLCD_CRITICAL_SECTION_ENTER();
	tmp = ((Slcd *)hw)->CMINDEX.reg;
	tmp &= ~SLCD_CMINDEX_CINDEX_Msk;
	tmp |= SLCD_CMINDEX_CINDEX(data);
	((Slcd *)hw)->CMINDEX.reg = tmp;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CMINDEX_CINDEX_bf(const void *const hw, hri_slcd_cmindex_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CMINDEX.reg &= ~SLCD_CMINDEX_CINDEX(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CMINDEX_CINDEX_bf(const void *const hw, hri_slcd_cmindex_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CMINDEX.reg ^= SLCD_CMINDEX_CINDEX(mask);
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_cmindex_reg_t hri_slcd_read_CMINDEX_CINDEX_bf(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Slcd *)hw)->CMINDEX.reg;
	tmp = (tmp & SLCD_CMINDEX_CINDEX_Msk) >> SLCD_CMINDEX_CINDEX_Pos;
	return tmp;
}

static inline void hri_slcd_set_CMINDEX_reg(const void *const hw, hri_slcd_cmindex_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CMINDEX.reg |= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_cmindex_reg_t hri_slcd_get_CMINDEX_reg(const void *const hw, hri_slcd_cmindex_reg_t mask)
{
	uint16_t tmp;
	tmp = ((Slcd *)hw)->CMINDEX.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_slcd_write_CMINDEX_reg(const void *const hw, hri_slcd_cmindex_reg_t data)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CMINDEX.reg = data;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_clear_CMINDEX_reg(const void *const hw, hri_slcd_cmindex_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CMINDEX.reg &= ~mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_toggle_CMINDEX_reg(const void *const hw, hri_slcd_cmindex_reg_t mask)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CMINDEX.reg ^= mask;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline hri_slcd_cmindex_reg_t hri_slcd_read_CMINDEX_reg(const void *const hw)
{
	return ((Slcd *)hw)->CMINDEX.reg;
}

static inline void hri_slcd_write_ISDATA_reg(const void *const hw, hri_slcd_isdata_reg_t data)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->ISDATA.reg = data;
	SLCD_CRITICAL_SECTION_LEAVE();
}

static inline void hri_slcd_write_CMDATA_reg(const void *const hw, hri_slcd_cmdata_reg_t data)
{
	SLCD_CRITICAL_SECTION_ENTER();
	((Slcd *)hw)->CMDATA.reg = data;
	SLCD_CRITICAL_SECTION_LEAVE();
}

#ifdef __cplusplus
}
#endif

#endif /* _HRI_SLCD_L22_H_INCLUDED */
#endif /* _SAML22_SLCD_COMPONENT_ */
