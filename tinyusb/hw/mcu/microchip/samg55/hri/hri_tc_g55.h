/**
 * \file
 *
 * \brief SAM TC
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

#ifdef _SAMG55_TC_COMPONENT_
#ifndef _HRI_TC_G55_H_INCLUDED_
#define _HRI_TC_G55_H_INCLUDED_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <hal_atomic.h>

#if defined(ENABLE_TC_CRITICAL_SECTIONS)
#define TC_CRITICAL_SECTION_ENTER() CRITICAL_SECTION_ENTER()
#define TC_CRITICAL_SECTION_LEAVE() CRITICAL_SECTION_LEAVE()
#else
#define TC_CRITICAL_SECTION_ENTER()
#define TC_CRITICAL_SECTION_LEAVE()
#endif

typedef uint32_t hri_tc_bcr_reg_t;
typedef uint32_t hri_tc_bmr_reg_t;
typedef uint32_t hri_tc_ccr_reg_t;
typedef uint32_t hri_tc_cmr_reg_t;
typedef uint32_t hri_tc_cv_reg_t;
typedef uint32_t hri_tc_imr_reg_t;
typedef uint32_t hri_tc_ptcr0_reg_t;
typedef uint32_t hri_tc_ptsr0_reg_t;
typedef uint32_t hri_tc_ra_reg_t;
typedef uint32_t hri_tc_rab_reg_t;
typedef uint32_t hri_tc_rb_reg_t;
typedef uint32_t hri_tc_rc_reg_t;
typedef uint32_t hri_tc_rncr0_reg_t;
typedef uint32_t hri_tc_rnpr0_reg_t;
typedef uint32_t hri_tc_rpr0_reg_t;
typedef uint32_t hri_tc_smmr_reg_t;
typedef uint32_t hri_tc_sr_reg_t;
typedef uint32_t hri_tc_wpmr_reg_t;

static inline void hri_tcchannel_set_IMR_COVFS_bit(const void *const hw)
{
	((TcChannel *)hw)->TC_IER = TC_IMR_COVFS;
}

static inline bool hri_tcchannel_get_IMR_COVFS_bit(const void *const hw)
{
	return (((TcChannel *)hw)->TC_IMR & TC_IMR_COVFS) >> TC_IMR_COVFS_Pos;
}

static inline void hri_tcchannel_write_IMR_COVFS_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((TcChannel *)hw)->TC_IDR = TC_IMR_COVFS;
	} else {
		((TcChannel *)hw)->TC_IER = TC_IMR_COVFS;
	}
}

static inline void hri_tcchannel_clear_IMR_COVFS_bit(const void *const hw)
{
	((TcChannel *)hw)->TC_IDR = TC_IMR_COVFS;
}

static inline void hri_tcchannel_set_IMR_LOVRS_bit(const void *const hw)
{
	((TcChannel *)hw)->TC_IER = TC_IMR_LOVRS;
}

static inline bool hri_tcchannel_get_IMR_LOVRS_bit(const void *const hw)
{
	return (((TcChannel *)hw)->TC_IMR & TC_IMR_LOVRS) >> TC_IMR_LOVRS_Pos;
}

static inline void hri_tcchannel_write_IMR_LOVRS_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((TcChannel *)hw)->TC_IDR = TC_IMR_LOVRS;
	} else {
		((TcChannel *)hw)->TC_IER = TC_IMR_LOVRS;
	}
}

static inline void hri_tcchannel_clear_IMR_LOVRS_bit(const void *const hw)
{
	((TcChannel *)hw)->TC_IDR = TC_IMR_LOVRS;
}

static inline void hri_tcchannel_set_IMR_CPAS_bit(const void *const hw)
{
	((TcChannel *)hw)->TC_IER = TC_IMR_CPAS;
}

static inline bool hri_tcchannel_get_IMR_CPAS_bit(const void *const hw)
{
	return (((TcChannel *)hw)->TC_IMR & TC_IMR_CPAS) >> TC_IMR_CPAS_Pos;
}

static inline void hri_tcchannel_write_IMR_CPAS_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((TcChannel *)hw)->TC_IDR = TC_IMR_CPAS;
	} else {
		((TcChannel *)hw)->TC_IER = TC_IMR_CPAS;
	}
}

static inline void hri_tcchannel_clear_IMR_CPAS_bit(const void *const hw)
{
	((TcChannel *)hw)->TC_IDR = TC_IMR_CPAS;
}

static inline void hri_tcchannel_set_IMR_CPBS_bit(const void *const hw)
{
	((TcChannel *)hw)->TC_IER = TC_IMR_CPBS;
}

static inline bool hri_tcchannel_get_IMR_CPBS_bit(const void *const hw)
{
	return (((TcChannel *)hw)->TC_IMR & TC_IMR_CPBS) >> TC_IMR_CPBS_Pos;
}

static inline void hri_tcchannel_write_IMR_CPBS_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((TcChannel *)hw)->TC_IDR = TC_IMR_CPBS;
	} else {
		((TcChannel *)hw)->TC_IER = TC_IMR_CPBS;
	}
}

static inline void hri_tcchannel_clear_IMR_CPBS_bit(const void *const hw)
{
	((TcChannel *)hw)->TC_IDR = TC_IMR_CPBS;
}

static inline void hri_tcchannel_set_IMR_CPCS_bit(const void *const hw)
{
	((TcChannel *)hw)->TC_IER = TC_IMR_CPCS;
}

static inline bool hri_tcchannel_get_IMR_CPCS_bit(const void *const hw)
{
	return (((TcChannel *)hw)->TC_IMR & TC_IMR_CPCS) >> TC_IMR_CPCS_Pos;
}

static inline void hri_tcchannel_write_IMR_CPCS_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((TcChannel *)hw)->TC_IDR = TC_IMR_CPCS;
	} else {
		((TcChannel *)hw)->TC_IER = TC_IMR_CPCS;
	}
}

static inline void hri_tcchannel_clear_IMR_CPCS_bit(const void *const hw)
{
	((TcChannel *)hw)->TC_IDR = TC_IMR_CPCS;
}

static inline void hri_tcchannel_set_IMR_LDRAS_bit(const void *const hw)
{
	((TcChannel *)hw)->TC_IER = TC_IMR_LDRAS;
}

static inline bool hri_tcchannel_get_IMR_LDRAS_bit(const void *const hw)
{
	return (((TcChannel *)hw)->TC_IMR & TC_IMR_LDRAS) >> TC_IMR_LDRAS_Pos;
}

static inline void hri_tcchannel_write_IMR_LDRAS_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((TcChannel *)hw)->TC_IDR = TC_IMR_LDRAS;
	} else {
		((TcChannel *)hw)->TC_IER = TC_IMR_LDRAS;
	}
}

static inline void hri_tcchannel_clear_IMR_LDRAS_bit(const void *const hw)
{
	((TcChannel *)hw)->TC_IDR = TC_IMR_LDRAS;
}

static inline void hri_tcchannel_set_IMR_LDRBS_bit(const void *const hw)
{
	((TcChannel *)hw)->TC_IER = TC_IMR_LDRBS;
}

static inline bool hri_tcchannel_get_IMR_LDRBS_bit(const void *const hw)
{
	return (((TcChannel *)hw)->TC_IMR & TC_IMR_LDRBS) >> TC_IMR_LDRBS_Pos;
}

static inline void hri_tcchannel_write_IMR_LDRBS_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((TcChannel *)hw)->TC_IDR = TC_IMR_LDRBS;
	} else {
		((TcChannel *)hw)->TC_IER = TC_IMR_LDRBS;
	}
}

static inline void hri_tcchannel_clear_IMR_LDRBS_bit(const void *const hw)
{
	((TcChannel *)hw)->TC_IDR = TC_IMR_LDRBS;
}

static inline void hri_tcchannel_set_IMR_ETRGS_bit(const void *const hw)
{
	((TcChannel *)hw)->TC_IER = TC_IMR_ETRGS;
}

static inline bool hri_tcchannel_get_IMR_ETRGS_bit(const void *const hw)
{
	return (((TcChannel *)hw)->TC_IMR & TC_IMR_ETRGS) >> TC_IMR_ETRGS_Pos;
}

static inline void hri_tcchannel_write_IMR_ETRGS_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((TcChannel *)hw)->TC_IDR = TC_IMR_ETRGS;
	} else {
		((TcChannel *)hw)->TC_IER = TC_IMR_ETRGS;
	}
}

static inline void hri_tcchannel_clear_IMR_ETRGS_bit(const void *const hw)
{
	((TcChannel *)hw)->TC_IDR = TC_IMR_ETRGS;
}

static inline void hri_tcchannel_set_IMR_ENDRX_bit(const void *const hw)
{
	((TcChannel *)hw)->TC_IER = TC_IMR_ENDRX;
}

static inline bool hri_tcchannel_get_IMR_ENDRX_bit(const void *const hw)
{
	return (((TcChannel *)hw)->TC_IMR & TC_IMR_ENDRX) >> TC_IMR_ENDRX_Pos;
}

static inline void hri_tcchannel_write_IMR_ENDRX_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((TcChannel *)hw)->TC_IDR = TC_IMR_ENDRX;
	} else {
		((TcChannel *)hw)->TC_IER = TC_IMR_ENDRX;
	}
}

static inline void hri_tcchannel_clear_IMR_ENDRX_bit(const void *const hw)
{
	((TcChannel *)hw)->TC_IDR = TC_IMR_ENDRX;
}

static inline void hri_tcchannel_set_IMR_RXBUFF_bit(const void *const hw)
{
	((TcChannel *)hw)->TC_IER = TC_IMR_RXBUFF;
}

static inline bool hri_tcchannel_get_IMR_RXBUFF_bit(const void *const hw)
{
	return (((TcChannel *)hw)->TC_IMR & TC_IMR_RXBUFF) >> TC_IMR_RXBUFF_Pos;
}

static inline void hri_tcchannel_write_IMR_RXBUFF_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((TcChannel *)hw)->TC_IDR = TC_IMR_RXBUFF;
	} else {
		((TcChannel *)hw)->TC_IER = TC_IMR_RXBUFF;
	}
}

static inline void hri_tcchannel_clear_IMR_RXBUFF_bit(const void *const hw)
{
	((TcChannel *)hw)->TC_IDR = TC_IMR_RXBUFF;
}

static inline void hri_tcchannel_set_IMR_reg(const void *const hw, hri_tc_imr_reg_t mask)
{
	((TcChannel *)hw)->TC_IER = mask;
}

static inline hri_tc_imr_reg_t hri_tcchannel_get_IMR_reg(const void *const hw, hri_tc_imr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((TcChannel *)hw)->TC_IMR;
	tmp &= mask;
	return tmp;
}

static inline hri_tc_imr_reg_t hri_tcchannel_read_IMR_reg(const void *const hw)
{
	return ((TcChannel *)hw)->TC_IMR;
}

static inline void hri_tcchannel_write_IMR_reg(const void *const hw, hri_tc_imr_reg_t data)
{
	((TcChannel *)hw)->TC_IER = data;
	((TcChannel *)hw)->TC_IDR = ~data;
}

static inline void hri_tcchannel_clear_IMR_reg(const void *const hw, hri_tc_imr_reg_t mask)
{
	((TcChannel *)hw)->TC_IDR = mask;
}

static inline void hri_tcchannel_write_CCR_reg(const void *const hw, hri_tc_ccr_reg_t data)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CCR = data;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_set_CMR_CLKI_bit(const void *const hw)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR |= TC_CMR_CLKI;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_tcchannel_get_CMR_CLKI_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((TcChannel *)hw)->TC_CMR;
	tmp = (tmp & TC_CMR_CLKI) >> TC_CMR_CLKI_Pos;
	return (bool)tmp;
}

static inline void hri_tcchannel_write_CMR_CLKI_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((TcChannel *)hw)->TC_CMR;
	tmp &= ~TC_CMR_CLKI;
	tmp |= value << TC_CMR_CLKI_Pos;
	((TcChannel *)hw)->TC_CMR = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_clear_CMR_CLKI_bit(const void *const hw)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR &= ~TC_CMR_CLKI;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_toggle_CMR_CLKI_bit(const void *const hw)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR ^= TC_CMR_CLKI;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_set_CMR_LDBSTOP_bit(const void *const hw)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR |= TC_CMR_LDBSTOP;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_tcchannel_get_CMR_LDBSTOP_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((TcChannel *)hw)->TC_CMR;
	tmp = (tmp & TC_CMR_LDBSTOP) >> TC_CMR_LDBSTOP_Pos;
	return (bool)tmp;
}

static inline void hri_tcchannel_write_CMR_LDBSTOP_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((TcChannel *)hw)->TC_CMR;
	tmp &= ~TC_CMR_LDBSTOP;
	tmp |= value << TC_CMR_LDBSTOP_Pos;
	((TcChannel *)hw)->TC_CMR = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_clear_CMR_LDBSTOP_bit(const void *const hw)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR &= ~TC_CMR_LDBSTOP;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_toggle_CMR_LDBSTOP_bit(const void *const hw)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR ^= TC_CMR_LDBSTOP;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_set_CMR_LDBDIS_bit(const void *const hw)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR |= TC_CMR_LDBDIS;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_tcchannel_get_CMR_LDBDIS_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((TcChannel *)hw)->TC_CMR;
	tmp = (tmp & TC_CMR_LDBDIS) >> TC_CMR_LDBDIS_Pos;
	return (bool)tmp;
}

static inline void hri_tcchannel_write_CMR_LDBDIS_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((TcChannel *)hw)->TC_CMR;
	tmp &= ~TC_CMR_LDBDIS;
	tmp |= value << TC_CMR_LDBDIS_Pos;
	((TcChannel *)hw)->TC_CMR = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_clear_CMR_LDBDIS_bit(const void *const hw)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR &= ~TC_CMR_LDBDIS;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_toggle_CMR_LDBDIS_bit(const void *const hw)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR ^= TC_CMR_LDBDIS;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_set_CMR_ABETRG_bit(const void *const hw)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR |= TC_CMR_ABETRG;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_tcchannel_get_CMR_ABETRG_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((TcChannel *)hw)->TC_CMR;
	tmp = (tmp & TC_CMR_ABETRG) >> TC_CMR_ABETRG_Pos;
	return (bool)tmp;
}

static inline void hri_tcchannel_write_CMR_ABETRG_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((TcChannel *)hw)->TC_CMR;
	tmp &= ~TC_CMR_ABETRG;
	tmp |= value << TC_CMR_ABETRG_Pos;
	((TcChannel *)hw)->TC_CMR = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_clear_CMR_ABETRG_bit(const void *const hw)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR &= ~TC_CMR_ABETRG;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_toggle_CMR_ABETRG_bit(const void *const hw)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR ^= TC_CMR_ABETRG;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_set_CMR_CPCTRG_bit(const void *const hw)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR |= TC_CMR_CPCTRG;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_tcchannel_get_CMR_CPCTRG_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((TcChannel *)hw)->TC_CMR;
	tmp = (tmp & TC_CMR_CPCTRG) >> TC_CMR_CPCTRG_Pos;
	return (bool)tmp;
}

static inline void hri_tcchannel_write_CMR_CPCTRG_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((TcChannel *)hw)->TC_CMR;
	tmp &= ~TC_CMR_CPCTRG;
	tmp |= value << TC_CMR_CPCTRG_Pos;
	((TcChannel *)hw)->TC_CMR = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_clear_CMR_CPCTRG_bit(const void *const hw)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR &= ~TC_CMR_CPCTRG;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_toggle_CMR_CPCTRG_bit(const void *const hw)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR ^= TC_CMR_CPCTRG;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_set_CMR_WAVE_bit(const void *const hw)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR |= TC_CMR_WAVE;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_tcchannel_get_CMR_WAVE_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((TcChannel *)hw)->TC_CMR;
	tmp = (tmp & TC_CMR_WAVE) >> TC_CMR_WAVE_Pos;
	return (bool)tmp;
}

static inline void hri_tcchannel_write_CMR_WAVE_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((TcChannel *)hw)->TC_CMR;
	tmp &= ~TC_CMR_WAVE;
	tmp |= value << TC_CMR_WAVE_Pos;
	((TcChannel *)hw)->TC_CMR = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_clear_CMR_WAVE_bit(const void *const hw)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR &= ~TC_CMR_WAVE;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_toggle_CMR_WAVE_bit(const void *const hw)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR ^= TC_CMR_WAVE;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_set_CMR_TCCLKS_bf(const void *const hw, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR |= TC_CMR_TCCLKS(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_cmr_reg_t hri_tcchannel_get_CMR_TCCLKS_bf(const void *const hw, hri_tc_cmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((TcChannel *)hw)->TC_CMR;
	tmp = (tmp & TC_CMR_TCCLKS(mask)) >> TC_CMR_TCCLKS_Pos;
	return tmp;
}

static inline void hri_tcchannel_write_CMR_TCCLKS_bf(const void *const hw, hri_tc_cmr_reg_t data)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((TcChannel *)hw)->TC_CMR;
	tmp &= ~TC_CMR_TCCLKS_Msk;
	tmp |= TC_CMR_TCCLKS(data);
	((TcChannel *)hw)->TC_CMR = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_clear_CMR_TCCLKS_bf(const void *const hw, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR &= ~TC_CMR_TCCLKS(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_toggle_CMR_TCCLKS_bf(const void *const hw, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR ^= TC_CMR_TCCLKS(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_cmr_reg_t hri_tcchannel_read_CMR_TCCLKS_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((TcChannel *)hw)->TC_CMR;
	tmp = (tmp & TC_CMR_TCCLKS_Msk) >> TC_CMR_TCCLKS_Pos;
	return tmp;
}

static inline void hri_tcchannel_set_CMR_BURST_bf(const void *const hw, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR |= TC_CMR_BURST(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_cmr_reg_t hri_tcchannel_get_CMR_BURST_bf(const void *const hw, hri_tc_cmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((TcChannel *)hw)->TC_CMR;
	tmp = (tmp & TC_CMR_BURST(mask)) >> TC_CMR_BURST_Pos;
	return tmp;
}

static inline void hri_tcchannel_write_CMR_BURST_bf(const void *const hw, hri_tc_cmr_reg_t data)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((TcChannel *)hw)->TC_CMR;
	tmp &= ~TC_CMR_BURST_Msk;
	tmp |= TC_CMR_BURST(data);
	((TcChannel *)hw)->TC_CMR = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_clear_CMR_BURST_bf(const void *const hw, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR &= ~TC_CMR_BURST(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_toggle_CMR_BURST_bf(const void *const hw, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR ^= TC_CMR_BURST(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_cmr_reg_t hri_tcchannel_read_CMR_BURST_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((TcChannel *)hw)->TC_CMR;
	tmp = (tmp & TC_CMR_BURST_Msk) >> TC_CMR_BURST_Pos;
	return tmp;
}

static inline void hri_tcchannel_set_CMR_ETRGEDG_bf(const void *const hw, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR |= TC_CMR_ETRGEDG(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_cmr_reg_t hri_tcchannel_get_CMR_ETRGEDG_bf(const void *const hw, hri_tc_cmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((TcChannel *)hw)->TC_CMR;
	tmp = (tmp & TC_CMR_ETRGEDG(mask)) >> TC_CMR_ETRGEDG_Pos;
	return tmp;
}

static inline void hri_tcchannel_write_CMR_ETRGEDG_bf(const void *const hw, hri_tc_cmr_reg_t data)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((TcChannel *)hw)->TC_CMR;
	tmp &= ~TC_CMR_ETRGEDG_Msk;
	tmp |= TC_CMR_ETRGEDG(data);
	((TcChannel *)hw)->TC_CMR = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_clear_CMR_ETRGEDG_bf(const void *const hw, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR &= ~TC_CMR_ETRGEDG(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_toggle_CMR_ETRGEDG_bf(const void *const hw, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR ^= TC_CMR_ETRGEDG(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_cmr_reg_t hri_tcchannel_read_CMR_ETRGEDG_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((TcChannel *)hw)->TC_CMR;
	tmp = (tmp & TC_CMR_ETRGEDG_Msk) >> TC_CMR_ETRGEDG_Pos;
	return tmp;
}

static inline void hri_tcchannel_set_CMR_LDRA_bf(const void *const hw, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR |= TC_CMR_LDRA(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_cmr_reg_t hri_tcchannel_get_CMR_LDRA_bf(const void *const hw, hri_tc_cmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((TcChannel *)hw)->TC_CMR;
	tmp = (tmp & TC_CMR_LDRA(mask)) >> TC_CMR_LDRA_Pos;
	return tmp;
}

static inline void hri_tcchannel_write_CMR_LDRA_bf(const void *const hw, hri_tc_cmr_reg_t data)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((TcChannel *)hw)->TC_CMR;
	tmp &= ~TC_CMR_LDRA_Msk;
	tmp |= TC_CMR_LDRA(data);
	((TcChannel *)hw)->TC_CMR = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_clear_CMR_LDRA_bf(const void *const hw, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR &= ~TC_CMR_LDRA(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_toggle_CMR_LDRA_bf(const void *const hw, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR ^= TC_CMR_LDRA(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_cmr_reg_t hri_tcchannel_read_CMR_LDRA_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((TcChannel *)hw)->TC_CMR;
	tmp = (tmp & TC_CMR_LDRA_Msk) >> TC_CMR_LDRA_Pos;
	return tmp;
}

static inline void hri_tcchannel_set_CMR_LDRB_bf(const void *const hw, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR |= TC_CMR_LDRB(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_cmr_reg_t hri_tcchannel_get_CMR_LDRB_bf(const void *const hw, hri_tc_cmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((TcChannel *)hw)->TC_CMR;
	tmp = (tmp & TC_CMR_LDRB(mask)) >> TC_CMR_LDRB_Pos;
	return tmp;
}

static inline void hri_tcchannel_write_CMR_LDRB_bf(const void *const hw, hri_tc_cmr_reg_t data)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((TcChannel *)hw)->TC_CMR;
	tmp &= ~TC_CMR_LDRB_Msk;
	tmp |= TC_CMR_LDRB(data);
	((TcChannel *)hw)->TC_CMR = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_clear_CMR_LDRB_bf(const void *const hw, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR &= ~TC_CMR_LDRB(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_toggle_CMR_LDRB_bf(const void *const hw, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR ^= TC_CMR_LDRB(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_cmr_reg_t hri_tcchannel_read_CMR_LDRB_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((TcChannel *)hw)->TC_CMR;
	tmp = (tmp & TC_CMR_LDRB_Msk) >> TC_CMR_LDRB_Pos;
	return tmp;
}

static inline void hri_tcchannel_set_CMR_SBSMPLR_bf(const void *const hw, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR |= TC_CMR_SBSMPLR(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_cmr_reg_t hri_tcchannel_get_CMR_SBSMPLR_bf(const void *const hw, hri_tc_cmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((TcChannel *)hw)->TC_CMR;
	tmp = (tmp & TC_CMR_SBSMPLR(mask)) >> TC_CMR_SBSMPLR_Pos;
	return tmp;
}

static inline void hri_tcchannel_write_CMR_SBSMPLR_bf(const void *const hw, hri_tc_cmr_reg_t data)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((TcChannel *)hw)->TC_CMR;
	tmp &= ~TC_CMR_SBSMPLR_Msk;
	tmp |= TC_CMR_SBSMPLR(data);
	((TcChannel *)hw)->TC_CMR = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_clear_CMR_SBSMPLR_bf(const void *const hw, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR &= ~TC_CMR_SBSMPLR(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_toggle_CMR_SBSMPLR_bf(const void *const hw, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR ^= TC_CMR_SBSMPLR(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_cmr_reg_t hri_tcchannel_read_CMR_SBSMPLR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((TcChannel *)hw)->TC_CMR;
	tmp = (tmp & TC_CMR_SBSMPLR_Msk) >> TC_CMR_SBSMPLR_Pos;
	return tmp;
}

static inline void hri_tcchannel_set_CMR_reg(const void *const hw, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR |= mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_cmr_reg_t hri_tcchannel_get_CMR_reg(const void *const hw, hri_tc_cmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((TcChannel *)hw)->TC_CMR;
	tmp &= mask;
	return tmp;
}

static inline void hri_tcchannel_write_CMR_reg(const void *const hw, hri_tc_cmr_reg_t data)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR = data;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_clear_CMR_reg(const void *const hw, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR &= ~mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_toggle_CMR_reg(const void *const hw, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_CMR ^= mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_cmr_reg_t hri_tcchannel_read_CMR_reg(const void *const hw)
{
	return ((TcChannel *)hw)->TC_CMR;
}

static inline void hri_tcchannel_set_SMMR_GCEN_bit(const void *const hw)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_SMMR |= TC_SMMR_GCEN;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_tcchannel_get_SMMR_GCEN_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((TcChannel *)hw)->TC_SMMR;
	tmp = (tmp & TC_SMMR_GCEN) >> TC_SMMR_GCEN_Pos;
	return (bool)tmp;
}

static inline void hri_tcchannel_write_SMMR_GCEN_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((TcChannel *)hw)->TC_SMMR;
	tmp &= ~TC_SMMR_GCEN;
	tmp |= value << TC_SMMR_GCEN_Pos;
	((TcChannel *)hw)->TC_SMMR = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_clear_SMMR_GCEN_bit(const void *const hw)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_SMMR &= ~TC_SMMR_GCEN;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_toggle_SMMR_GCEN_bit(const void *const hw)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_SMMR ^= TC_SMMR_GCEN;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_set_SMMR_DOWN_bit(const void *const hw)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_SMMR |= TC_SMMR_DOWN;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_tcchannel_get_SMMR_DOWN_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((TcChannel *)hw)->TC_SMMR;
	tmp = (tmp & TC_SMMR_DOWN) >> TC_SMMR_DOWN_Pos;
	return (bool)tmp;
}

static inline void hri_tcchannel_write_SMMR_DOWN_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((TcChannel *)hw)->TC_SMMR;
	tmp &= ~TC_SMMR_DOWN;
	tmp |= value << TC_SMMR_DOWN_Pos;
	((TcChannel *)hw)->TC_SMMR = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_clear_SMMR_DOWN_bit(const void *const hw)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_SMMR &= ~TC_SMMR_DOWN;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_toggle_SMMR_DOWN_bit(const void *const hw)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_SMMR ^= TC_SMMR_DOWN;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_set_SMMR_reg(const void *const hw, hri_tc_smmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_SMMR |= mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_smmr_reg_t hri_tcchannel_get_SMMR_reg(const void *const hw, hri_tc_smmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((TcChannel *)hw)->TC_SMMR;
	tmp &= mask;
	return tmp;
}

static inline void hri_tcchannel_write_SMMR_reg(const void *const hw, hri_tc_smmr_reg_t data)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_SMMR = data;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_clear_SMMR_reg(const void *const hw, hri_tc_smmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_SMMR &= ~mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_toggle_SMMR_reg(const void *const hw, hri_tc_smmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_SMMR ^= mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_smmr_reg_t hri_tcchannel_read_SMMR_reg(const void *const hw)
{
	return ((TcChannel *)hw)->TC_SMMR;
}

static inline void hri_tcchannel_set_RA_RA_bf(const void *const hw, hri_tc_ra_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_RA |= TC_RA_RA(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_ra_reg_t hri_tcchannel_get_RA_RA_bf(const void *const hw, hri_tc_ra_reg_t mask)
{
	uint32_t tmp;
	tmp = ((TcChannel *)hw)->TC_RA;
	tmp = (tmp & TC_RA_RA(mask)) >> TC_RA_RA_Pos;
	return tmp;
}

static inline void hri_tcchannel_write_RA_RA_bf(const void *const hw, hri_tc_ra_reg_t data)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((TcChannel *)hw)->TC_RA;
	tmp &= ~TC_RA_RA_Msk;
	tmp |= TC_RA_RA(data);
	((TcChannel *)hw)->TC_RA = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_clear_RA_RA_bf(const void *const hw, hri_tc_ra_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_RA &= ~TC_RA_RA(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_toggle_RA_RA_bf(const void *const hw, hri_tc_ra_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_RA ^= TC_RA_RA(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_ra_reg_t hri_tcchannel_read_RA_RA_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((TcChannel *)hw)->TC_RA;
	tmp = (tmp & TC_RA_RA_Msk) >> TC_RA_RA_Pos;
	return tmp;
}

static inline void hri_tcchannel_set_RA_reg(const void *const hw, hri_tc_ra_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_RA |= mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_ra_reg_t hri_tcchannel_get_RA_reg(const void *const hw, hri_tc_ra_reg_t mask)
{
	uint32_t tmp;
	tmp = ((TcChannel *)hw)->TC_RA;
	tmp &= mask;
	return tmp;
}

static inline void hri_tcchannel_write_RA_reg(const void *const hw, hri_tc_ra_reg_t data)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_RA = data;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_clear_RA_reg(const void *const hw, hri_tc_ra_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_RA &= ~mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_toggle_RA_reg(const void *const hw, hri_tc_ra_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_RA ^= mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_ra_reg_t hri_tcchannel_read_RA_reg(const void *const hw)
{
	return ((TcChannel *)hw)->TC_RA;
}

static inline void hri_tcchannel_set_RB_RB_bf(const void *const hw, hri_tc_rb_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_RB |= TC_RB_RB(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_rb_reg_t hri_tcchannel_get_RB_RB_bf(const void *const hw, hri_tc_rb_reg_t mask)
{
	uint32_t tmp;
	tmp = ((TcChannel *)hw)->TC_RB;
	tmp = (tmp & TC_RB_RB(mask)) >> TC_RB_RB_Pos;
	return tmp;
}

static inline void hri_tcchannel_write_RB_RB_bf(const void *const hw, hri_tc_rb_reg_t data)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((TcChannel *)hw)->TC_RB;
	tmp &= ~TC_RB_RB_Msk;
	tmp |= TC_RB_RB(data);
	((TcChannel *)hw)->TC_RB = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_clear_RB_RB_bf(const void *const hw, hri_tc_rb_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_RB &= ~TC_RB_RB(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_toggle_RB_RB_bf(const void *const hw, hri_tc_rb_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_RB ^= TC_RB_RB(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_rb_reg_t hri_tcchannel_read_RB_RB_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((TcChannel *)hw)->TC_RB;
	tmp = (tmp & TC_RB_RB_Msk) >> TC_RB_RB_Pos;
	return tmp;
}

static inline void hri_tcchannel_set_RB_reg(const void *const hw, hri_tc_rb_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_RB |= mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_rb_reg_t hri_tcchannel_get_RB_reg(const void *const hw, hri_tc_rb_reg_t mask)
{
	uint32_t tmp;
	tmp = ((TcChannel *)hw)->TC_RB;
	tmp &= mask;
	return tmp;
}

static inline void hri_tcchannel_write_RB_reg(const void *const hw, hri_tc_rb_reg_t data)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_RB = data;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_clear_RB_reg(const void *const hw, hri_tc_rb_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_RB &= ~mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_toggle_RB_reg(const void *const hw, hri_tc_rb_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_RB ^= mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_rb_reg_t hri_tcchannel_read_RB_reg(const void *const hw)
{
	return ((TcChannel *)hw)->TC_RB;
}

static inline void hri_tcchannel_set_RC_RC_bf(const void *const hw, hri_tc_rc_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_RC |= TC_RC_RC(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_rc_reg_t hri_tcchannel_get_RC_RC_bf(const void *const hw, hri_tc_rc_reg_t mask)
{
	uint32_t tmp;
	tmp = ((TcChannel *)hw)->TC_RC;
	tmp = (tmp & TC_RC_RC(mask)) >> TC_RC_RC_Pos;
	return tmp;
}

static inline void hri_tcchannel_write_RC_RC_bf(const void *const hw, hri_tc_rc_reg_t data)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((TcChannel *)hw)->TC_RC;
	tmp &= ~TC_RC_RC_Msk;
	tmp |= TC_RC_RC(data);
	((TcChannel *)hw)->TC_RC = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_clear_RC_RC_bf(const void *const hw, hri_tc_rc_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_RC &= ~TC_RC_RC(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_toggle_RC_RC_bf(const void *const hw, hri_tc_rc_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_RC ^= TC_RC_RC(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_rc_reg_t hri_tcchannel_read_RC_RC_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((TcChannel *)hw)->TC_RC;
	tmp = (tmp & TC_RC_RC_Msk) >> TC_RC_RC_Pos;
	return tmp;
}

static inline void hri_tcchannel_set_RC_reg(const void *const hw, hri_tc_rc_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_RC |= mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_rc_reg_t hri_tcchannel_get_RC_reg(const void *const hw, hri_tc_rc_reg_t mask)
{
	uint32_t tmp;
	tmp = ((TcChannel *)hw)->TC_RC;
	tmp &= mask;
	return tmp;
}

static inline void hri_tcchannel_write_RC_reg(const void *const hw, hri_tc_rc_reg_t data)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_RC = data;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_clear_RC_reg(const void *const hw, hri_tc_rc_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_RC &= ~mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tcchannel_toggle_RC_reg(const void *const hw, hri_tc_rc_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((TcChannel *)hw)->TC_RC ^= mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_rc_reg_t hri_tcchannel_read_RC_reg(const void *const hw)
{
	return ((TcChannel *)hw)->TC_RC;
}

static inline hri_tc_rab_reg_t hri_tcchannel_get_RAB_RAB_bf(const void *const hw, hri_tc_rab_reg_t mask)
{
	return (((TcChannel *)hw)->TC_RAB & TC_RAB_RAB(mask)) >> TC_RAB_RAB_Pos;
}

static inline hri_tc_rab_reg_t hri_tcchannel_read_RAB_RAB_bf(const void *const hw)
{
	return (((TcChannel *)hw)->TC_RAB & TC_RAB_RAB_Msk) >> TC_RAB_RAB_Pos;
}

static inline hri_tc_rab_reg_t hri_tcchannel_get_RAB_reg(const void *const hw, hri_tc_rab_reg_t mask)
{
	uint32_t tmp;
	tmp = ((TcChannel *)hw)->TC_RAB;
	tmp &= mask;
	return tmp;
}

static inline hri_tc_rab_reg_t hri_tcchannel_read_RAB_reg(const void *const hw)
{
	return ((TcChannel *)hw)->TC_RAB;
}

static inline hri_tc_cv_reg_t hri_tcchannel_get_CV_CV_bf(const void *const hw, hri_tc_cv_reg_t mask)
{
	return (((TcChannel *)hw)->TC_CV & TC_CV_CV(mask)) >> TC_CV_CV_Pos;
}

static inline hri_tc_cv_reg_t hri_tcchannel_read_CV_CV_bf(const void *const hw)
{
	return (((TcChannel *)hw)->TC_CV & TC_CV_CV_Msk) >> TC_CV_CV_Pos;
}

static inline hri_tc_cv_reg_t hri_tcchannel_get_CV_reg(const void *const hw, hri_tc_cv_reg_t mask)
{
	uint32_t tmp;
	tmp = ((TcChannel *)hw)->TC_CV;
	tmp &= mask;
	return tmp;
}

static inline hri_tc_cv_reg_t hri_tcchannel_read_CV_reg(const void *const hw)
{
	return ((TcChannel *)hw)->TC_CV;
}

static inline bool hri_tcchannel_get_SR_COVFS_bit(const void *const hw)
{
	return (((TcChannel *)hw)->TC_SR & TC_SR_COVFS) > 0;
}

static inline bool hri_tcchannel_get_SR_LOVRS_bit(const void *const hw)
{
	return (((TcChannel *)hw)->TC_SR & TC_SR_LOVRS) > 0;
}

static inline bool hri_tcchannel_get_SR_CPAS_bit(const void *const hw)
{
	return (((TcChannel *)hw)->TC_SR & TC_SR_CPAS) > 0;
}

static inline bool hri_tcchannel_get_SR_CPBS_bit(const void *const hw)
{
	return (((TcChannel *)hw)->TC_SR & TC_SR_CPBS) > 0;
}

static inline bool hri_tcchannel_get_SR_CPCS_bit(const void *const hw)
{
	return (((TcChannel *)hw)->TC_SR & TC_SR_CPCS) > 0;
}

static inline bool hri_tcchannel_get_SR_LDRAS_bit(const void *const hw)
{
	return (((TcChannel *)hw)->TC_SR & TC_SR_LDRAS) > 0;
}

static inline bool hri_tcchannel_get_SR_LDRBS_bit(const void *const hw)
{
	return (((TcChannel *)hw)->TC_SR & TC_SR_LDRBS) > 0;
}

static inline bool hri_tcchannel_get_SR_ETRGS_bit(const void *const hw)
{
	return (((TcChannel *)hw)->TC_SR & TC_SR_ETRGS) > 0;
}

static inline bool hri_tcchannel_get_SR_ENDRX_bit(const void *const hw)
{
	return (((TcChannel *)hw)->TC_SR & TC_SR_ENDRX) > 0;
}

static inline bool hri_tcchannel_get_SR_RXBUFF_bit(const void *const hw)
{
	return (((TcChannel *)hw)->TC_SR & TC_SR_RXBUFF) > 0;
}

static inline bool hri_tcchannel_get_SR_CLKSTA_bit(const void *const hw)
{
	return (((TcChannel *)hw)->TC_SR & TC_SR_CLKSTA) > 0;
}

static inline bool hri_tcchannel_get_SR_MTIOA_bit(const void *const hw)
{
	return (((TcChannel *)hw)->TC_SR & TC_SR_MTIOA) > 0;
}

static inline bool hri_tcchannel_get_SR_MTIOB_bit(const void *const hw)
{
	return (((TcChannel *)hw)->TC_SR & TC_SR_MTIOB) > 0;
}

static inline hri_tc_sr_reg_t hri_tcchannel_get_SR_reg(const void *const hw, hri_tc_sr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((TcChannel *)hw)->TC_SR;
	tmp &= mask;
	return tmp;
}

static inline hri_tc_sr_reg_t hri_tcchannel_read_SR_reg(const void *const hw)
{
	return ((TcChannel *)hw)->TC_SR;
}

static inline void hri_tc_set_IMR_COVFS_bit(const void *const hw, uint8_t submodule_index)
{
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IER = TC_IMR_COVFS;
}

static inline bool hri_tc_get_IMR_COVFS_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IMR & TC_IMR_COVFS) >> TC_IMR_COVFS_Pos;
}

static inline void hri_tc_write_IMR_COVFS_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IDR = TC_IMR_COVFS;
	} else {
		((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IER = TC_IMR_COVFS;
	}
}

static inline void hri_tc_clear_IMR_COVFS_bit(const void *const hw, uint8_t submodule_index)
{
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IDR = TC_IMR_COVFS;
}

static inline void hri_tc_set_IMR_LOVRS_bit(const void *const hw, uint8_t submodule_index)
{
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IER = TC_IMR_LOVRS;
}

static inline bool hri_tc_get_IMR_LOVRS_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IMR & TC_IMR_LOVRS) >> TC_IMR_LOVRS_Pos;
}

static inline void hri_tc_write_IMR_LOVRS_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IDR = TC_IMR_LOVRS;
	} else {
		((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IER = TC_IMR_LOVRS;
	}
}

static inline void hri_tc_clear_IMR_LOVRS_bit(const void *const hw, uint8_t submodule_index)
{
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IDR = TC_IMR_LOVRS;
}

static inline void hri_tc_set_IMR_CPAS_bit(const void *const hw, uint8_t submodule_index)
{
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IER = TC_IMR_CPAS;
}

static inline bool hri_tc_get_IMR_CPAS_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IMR & TC_IMR_CPAS) >> TC_IMR_CPAS_Pos;
}

static inline void hri_tc_write_IMR_CPAS_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IDR = TC_IMR_CPAS;
	} else {
		((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IER = TC_IMR_CPAS;
	}
}

static inline void hri_tc_clear_IMR_CPAS_bit(const void *const hw, uint8_t submodule_index)
{
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IDR = TC_IMR_CPAS;
}

static inline void hri_tc_set_IMR_CPBS_bit(const void *const hw, uint8_t submodule_index)
{
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IER = TC_IMR_CPBS;
}

static inline bool hri_tc_get_IMR_CPBS_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IMR & TC_IMR_CPBS) >> TC_IMR_CPBS_Pos;
}

static inline void hri_tc_write_IMR_CPBS_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IDR = TC_IMR_CPBS;
	} else {
		((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IER = TC_IMR_CPBS;
	}
}

static inline void hri_tc_clear_IMR_CPBS_bit(const void *const hw, uint8_t submodule_index)
{
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IDR = TC_IMR_CPBS;
}

static inline void hri_tc_set_IMR_CPCS_bit(const void *const hw, uint8_t submodule_index)
{
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IER = TC_IMR_CPCS;
}

static inline bool hri_tc_get_IMR_CPCS_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IMR & TC_IMR_CPCS) >> TC_IMR_CPCS_Pos;
}

static inline void hri_tc_write_IMR_CPCS_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IDR = TC_IMR_CPCS;
	} else {
		((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IER = TC_IMR_CPCS;
	}
}

static inline void hri_tc_clear_IMR_CPCS_bit(const void *const hw, uint8_t submodule_index)
{
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IDR = TC_IMR_CPCS;
}

static inline void hri_tc_set_IMR_LDRAS_bit(const void *const hw, uint8_t submodule_index)
{
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IER = TC_IMR_LDRAS;
}

static inline bool hri_tc_get_IMR_LDRAS_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IMR & TC_IMR_LDRAS) >> TC_IMR_LDRAS_Pos;
}

static inline void hri_tc_write_IMR_LDRAS_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IDR = TC_IMR_LDRAS;
	} else {
		((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IER = TC_IMR_LDRAS;
	}
}

static inline void hri_tc_clear_IMR_LDRAS_bit(const void *const hw, uint8_t submodule_index)
{
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IDR = TC_IMR_LDRAS;
}

static inline void hri_tc_set_IMR_LDRBS_bit(const void *const hw, uint8_t submodule_index)
{
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IER = TC_IMR_LDRBS;
}

static inline bool hri_tc_get_IMR_LDRBS_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IMR & TC_IMR_LDRBS) >> TC_IMR_LDRBS_Pos;
}

static inline void hri_tc_write_IMR_LDRBS_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IDR = TC_IMR_LDRBS;
	} else {
		((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IER = TC_IMR_LDRBS;
	}
}

static inline void hri_tc_clear_IMR_LDRBS_bit(const void *const hw, uint8_t submodule_index)
{
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IDR = TC_IMR_LDRBS;
}

static inline void hri_tc_set_IMR_ETRGS_bit(const void *const hw, uint8_t submodule_index)
{
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IER = TC_IMR_ETRGS;
}

static inline bool hri_tc_get_IMR_ETRGS_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IMR & TC_IMR_ETRGS) >> TC_IMR_ETRGS_Pos;
}

static inline void hri_tc_write_IMR_ETRGS_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IDR = TC_IMR_ETRGS;
	} else {
		((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IER = TC_IMR_ETRGS;
	}
}

static inline void hri_tc_clear_IMR_ETRGS_bit(const void *const hw, uint8_t submodule_index)
{
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IDR = TC_IMR_ETRGS;
}

static inline void hri_tc_set_IMR_ENDRX_bit(const void *const hw, uint8_t submodule_index)
{
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IER = TC_IMR_ENDRX;
}

static inline bool hri_tc_get_IMR_ENDRX_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IMR & TC_IMR_ENDRX) >> TC_IMR_ENDRX_Pos;
}

static inline void hri_tc_write_IMR_ENDRX_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IDR = TC_IMR_ENDRX;
	} else {
		((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IER = TC_IMR_ENDRX;
	}
}

static inline void hri_tc_clear_IMR_ENDRX_bit(const void *const hw, uint8_t submodule_index)
{
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IDR = TC_IMR_ENDRX;
}

static inline void hri_tc_set_IMR_RXBUFF_bit(const void *const hw, uint8_t submodule_index)
{
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IER = TC_IMR_RXBUFF;
}

static inline bool hri_tc_get_IMR_RXBUFF_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IMR & TC_IMR_RXBUFF) >> TC_IMR_RXBUFF_Pos;
}

static inline void hri_tc_write_IMR_RXBUFF_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IDR = TC_IMR_RXBUFF;
	} else {
		((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IER = TC_IMR_RXBUFF;
	}
}

static inline void hri_tc_clear_IMR_RXBUFF_bit(const void *const hw, uint8_t submodule_index)
{
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IDR = TC_IMR_RXBUFF;
}

static inline void hri_tc_set_IMR_reg(const void *const hw, uint8_t submodule_index, hri_tc_imr_reg_t mask)
{
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IER = mask;
}

static inline hri_tc_imr_reg_t hri_tc_get_IMR_reg(const void *const hw, uint8_t submodule_index, hri_tc_imr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IMR;
	tmp &= mask;
	return tmp;
}

static inline hri_tc_imr_reg_t hri_tc_read_IMR_reg(const void *const hw, uint8_t submodule_index)
{
	return ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IMR;
}

static inline void hri_tc_write_IMR_reg(const void *const hw, uint8_t submodule_index, hri_tc_imr_reg_t data)
{
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IER = data;
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IDR = ~data;
}

static inline void hri_tc_clear_IMR_reg(const void *const hw, uint8_t submodule_index, hri_tc_imr_reg_t mask)
{
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_IDR = mask;
}

static inline void hri_tc_write_CCR_reg(const void *const hw, uint8_t submodule_index, hri_tc_ccr_reg_t data)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CCR = data;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_set_CMR_CLKI_bit(const void *const hw, uint8_t submodule_index)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR |= TC_CMR_CLKI;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_tc_get_CMR_CLKI_bit(const void *const hw, uint8_t submodule_index)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR;
	tmp = (tmp & TC_CMR_CLKI) >> TC_CMR_CLKI_Pos;
	return (bool)tmp;
}

static inline void hri_tc_write_CMR_CLKI_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR;
	tmp &= ~TC_CMR_CLKI;
	tmp |= value << TC_CMR_CLKI_Pos;
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_clear_CMR_CLKI_bit(const void *const hw, uint8_t submodule_index)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR &= ~TC_CMR_CLKI;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_toggle_CMR_CLKI_bit(const void *const hw, uint8_t submodule_index)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR ^= TC_CMR_CLKI;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_set_CMR_LDBSTOP_bit(const void *const hw, uint8_t submodule_index)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR |= TC_CMR_LDBSTOP;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_tc_get_CMR_LDBSTOP_bit(const void *const hw, uint8_t submodule_index)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR;
	tmp = (tmp & TC_CMR_LDBSTOP) >> TC_CMR_LDBSTOP_Pos;
	return (bool)tmp;
}

static inline void hri_tc_write_CMR_LDBSTOP_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR;
	tmp &= ~TC_CMR_LDBSTOP;
	tmp |= value << TC_CMR_LDBSTOP_Pos;
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_clear_CMR_LDBSTOP_bit(const void *const hw, uint8_t submodule_index)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR &= ~TC_CMR_LDBSTOP;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_toggle_CMR_LDBSTOP_bit(const void *const hw, uint8_t submodule_index)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR ^= TC_CMR_LDBSTOP;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_set_CMR_LDBDIS_bit(const void *const hw, uint8_t submodule_index)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR |= TC_CMR_LDBDIS;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_tc_get_CMR_LDBDIS_bit(const void *const hw, uint8_t submodule_index)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR;
	tmp = (tmp & TC_CMR_LDBDIS) >> TC_CMR_LDBDIS_Pos;
	return (bool)tmp;
}

static inline void hri_tc_write_CMR_LDBDIS_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR;
	tmp &= ~TC_CMR_LDBDIS;
	tmp |= value << TC_CMR_LDBDIS_Pos;
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_clear_CMR_LDBDIS_bit(const void *const hw, uint8_t submodule_index)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR &= ~TC_CMR_LDBDIS;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_toggle_CMR_LDBDIS_bit(const void *const hw, uint8_t submodule_index)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR ^= TC_CMR_LDBDIS;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_set_CMR_ABETRG_bit(const void *const hw, uint8_t submodule_index)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR |= TC_CMR_ABETRG;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_tc_get_CMR_ABETRG_bit(const void *const hw, uint8_t submodule_index)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR;
	tmp = (tmp & TC_CMR_ABETRG) >> TC_CMR_ABETRG_Pos;
	return (bool)tmp;
}

static inline void hri_tc_write_CMR_ABETRG_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR;
	tmp &= ~TC_CMR_ABETRG;
	tmp |= value << TC_CMR_ABETRG_Pos;
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_clear_CMR_ABETRG_bit(const void *const hw, uint8_t submodule_index)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR &= ~TC_CMR_ABETRG;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_toggle_CMR_ABETRG_bit(const void *const hw, uint8_t submodule_index)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR ^= TC_CMR_ABETRG;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_set_CMR_CPCTRG_bit(const void *const hw, uint8_t submodule_index)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR |= TC_CMR_CPCTRG;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_tc_get_CMR_CPCTRG_bit(const void *const hw, uint8_t submodule_index)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR;
	tmp = (tmp & TC_CMR_CPCTRG) >> TC_CMR_CPCTRG_Pos;
	return (bool)tmp;
}

static inline void hri_tc_write_CMR_CPCTRG_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR;
	tmp &= ~TC_CMR_CPCTRG;
	tmp |= value << TC_CMR_CPCTRG_Pos;
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_clear_CMR_CPCTRG_bit(const void *const hw, uint8_t submodule_index)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR &= ~TC_CMR_CPCTRG;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_toggle_CMR_CPCTRG_bit(const void *const hw, uint8_t submodule_index)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR ^= TC_CMR_CPCTRG;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_set_CMR_WAVE_bit(const void *const hw, uint8_t submodule_index)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR |= TC_CMR_WAVE;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_tc_get_CMR_WAVE_bit(const void *const hw, uint8_t submodule_index)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR;
	tmp = (tmp & TC_CMR_WAVE) >> TC_CMR_WAVE_Pos;
	return (bool)tmp;
}

static inline void hri_tc_write_CMR_WAVE_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR;
	tmp &= ~TC_CMR_WAVE;
	tmp |= value << TC_CMR_WAVE_Pos;
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_clear_CMR_WAVE_bit(const void *const hw, uint8_t submodule_index)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR &= ~TC_CMR_WAVE;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_toggle_CMR_WAVE_bit(const void *const hw, uint8_t submodule_index)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR ^= TC_CMR_WAVE;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_set_CMR_TCCLKS_bf(const void *const hw, uint8_t submodule_index, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR |= TC_CMR_TCCLKS(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_cmr_reg_t hri_tc_get_CMR_TCCLKS_bf(const void *const hw, uint8_t submodule_index,
                                                        hri_tc_cmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR;
	tmp = (tmp & TC_CMR_TCCLKS(mask)) >> TC_CMR_TCCLKS_Pos;
	return tmp;
}

static inline void hri_tc_write_CMR_TCCLKS_bf(const void *const hw, uint8_t submodule_index, hri_tc_cmr_reg_t data)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR;
	tmp &= ~TC_CMR_TCCLKS_Msk;
	tmp |= TC_CMR_TCCLKS(data);
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_clear_CMR_TCCLKS_bf(const void *const hw, uint8_t submodule_index, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR &= ~TC_CMR_TCCLKS(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_toggle_CMR_TCCLKS_bf(const void *const hw, uint8_t submodule_index, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR ^= TC_CMR_TCCLKS(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_cmr_reg_t hri_tc_read_CMR_TCCLKS_bf(const void *const hw, uint8_t submodule_index)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR;
	tmp = (tmp & TC_CMR_TCCLKS_Msk) >> TC_CMR_TCCLKS_Pos;
	return tmp;
}

static inline void hri_tc_set_CMR_BURST_bf(const void *const hw, uint8_t submodule_index, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR |= TC_CMR_BURST(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_cmr_reg_t hri_tc_get_CMR_BURST_bf(const void *const hw, uint8_t submodule_index,
                                                       hri_tc_cmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR;
	tmp = (tmp & TC_CMR_BURST(mask)) >> TC_CMR_BURST_Pos;
	return tmp;
}

static inline void hri_tc_write_CMR_BURST_bf(const void *const hw, uint8_t submodule_index, hri_tc_cmr_reg_t data)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR;
	tmp &= ~TC_CMR_BURST_Msk;
	tmp |= TC_CMR_BURST(data);
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_clear_CMR_BURST_bf(const void *const hw, uint8_t submodule_index, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR &= ~TC_CMR_BURST(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_toggle_CMR_BURST_bf(const void *const hw, uint8_t submodule_index, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR ^= TC_CMR_BURST(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_cmr_reg_t hri_tc_read_CMR_BURST_bf(const void *const hw, uint8_t submodule_index)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR;
	tmp = (tmp & TC_CMR_BURST_Msk) >> TC_CMR_BURST_Pos;
	return tmp;
}

static inline void hri_tc_set_CMR_ETRGEDG_bf(const void *const hw, uint8_t submodule_index, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR |= TC_CMR_ETRGEDG(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_cmr_reg_t hri_tc_get_CMR_ETRGEDG_bf(const void *const hw, uint8_t submodule_index,
                                                         hri_tc_cmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR;
	tmp = (tmp & TC_CMR_ETRGEDG(mask)) >> TC_CMR_ETRGEDG_Pos;
	return tmp;
}

static inline void hri_tc_write_CMR_ETRGEDG_bf(const void *const hw, uint8_t submodule_index, hri_tc_cmr_reg_t data)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR;
	tmp &= ~TC_CMR_ETRGEDG_Msk;
	tmp |= TC_CMR_ETRGEDG(data);
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_clear_CMR_ETRGEDG_bf(const void *const hw, uint8_t submodule_index, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR &= ~TC_CMR_ETRGEDG(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_toggle_CMR_ETRGEDG_bf(const void *const hw, uint8_t submodule_index, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR ^= TC_CMR_ETRGEDG(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_cmr_reg_t hri_tc_read_CMR_ETRGEDG_bf(const void *const hw, uint8_t submodule_index)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR;
	tmp = (tmp & TC_CMR_ETRGEDG_Msk) >> TC_CMR_ETRGEDG_Pos;
	return tmp;
}

static inline void hri_tc_set_CMR_LDRA_bf(const void *const hw, uint8_t submodule_index, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR |= TC_CMR_LDRA(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_cmr_reg_t hri_tc_get_CMR_LDRA_bf(const void *const hw, uint8_t submodule_index,
                                                      hri_tc_cmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR;
	tmp = (tmp & TC_CMR_LDRA(mask)) >> TC_CMR_LDRA_Pos;
	return tmp;
}

static inline void hri_tc_write_CMR_LDRA_bf(const void *const hw, uint8_t submodule_index, hri_tc_cmr_reg_t data)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR;
	tmp &= ~TC_CMR_LDRA_Msk;
	tmp |= TC_CMR_LDRA(data);
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_clear_CMR_LDRA_bf(const void *const hw, uint8_t submodule_index, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR &= ~TC_CMR_LDRA(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_toggle_CMR_LDRA_bf(const void *const hw, uint8_t submodule_index, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR ^= TC_CMR_LDRA(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_cmr_reg_t hri_tc_read_CMR_LDRA_bf(const void *const hw, uint8_t submodule_index)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR;
	tmp = (tmp & TC_CMR_LDRA_Msk) >> TC_CMR_LDRA_Pos;
	return tmp;
}

static inline void hri_tc_set_CMR_LDRB_bf(const void *const hw, uint8_t submodule_index, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR |= TC_CMR_LDRB(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_cmr_reg_t hri_tc_get_CMR_LDRB_bf(const void *const hw, uint8_t submodule_index,
                                                      hri_tc_cmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR;
	tmp = (tmp & TC_CMR_LDRB(mask)) >> TC_CMR_LDRB_Pos;
	return tmp;
}

static inline void hri_tc_write_CMR_LDRB_bf(const void *const hw, uint8_t submodule_index, hri_tc_cmr_reg_t data)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR;
	tmp &= ~TC_CMR_LDRB_Msk;
	tmp |= TC_CMR_LDRB(data);
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_clear_CMR_LDRB_bf(const void *const hw, uint8_t submodule_index, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR &= ~TC_CMR_LDRB(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_toggle_CMR_LDRB_bf(const void *const hw, uint8_t submodule_index, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR ^= TC_CMR_LDRB(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_cmr_reg_t hri_tc_read_CMR_LDRB_bf(const void *const hw, uint8_t submodule_index)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR;
	tmp = (tmp & TC_CMR_LDRB_Msk) >> TC_CMR_LDRB_Pos;
	return tmp;
}

static inline void hri_tc_set_CMR_SBSMPLR_bf(const void *const hw, uint8_t submodule_index, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR |= TC_CMR_SBSMPLR(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_cmr_reg_t hri_tc_get_CMR_SBSMPLR_bf(const void *const hw, uint8_t submodule_index,
                                                         hri_tc_cmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR;
	tmp = (tmp & TC_CMR_SBSMPLR(mask)) >> TC_CMR_SBSMPLR_Pos;
	return tmp;
}

static inline void hri_tc_write_CMR_SBSMPLR_bf(const void *const hw, uint8_t submodule_index, hri_tc_cmr_reg_t data)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR;
	tmp &= ~TC_CMR_SBSMPLR_Msk;
	tmp |= TC_CMR_SBSMPLR(data);
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_clear_CMR_SBSMPLR_bf(const void *const hw, uint8_t submodule_index, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR &= ~TC_CMR_SBSMPLR(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_toggle_CMR_SBSMPLR_bf(const void *const hw, uint8_t submodule_index, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR ^= TC_CMR_SBSMPLR(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_cmr_reg_t hri_tc_read_CMR_SBSMPLR_bf(const void *const hw, uint8_t submodule_index)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR;
	tmp = (tmp & TC_CMR_SBSMPLR_Msk) >> TC_CMR_SBSMPLR_Pos;
	return tmp;
}

static inline void hri_tc_set_CMR_reg(const void *const hw, uint8_t submodule_index, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR |= mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_cmr_reg_t hri_tc_get_CMR_reg(const void *const hw, uint8_t submodule_index, hri_tc_cmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR;
	tmp &= mask;
	return tmp;
}

static inline void hri_tc_write_CMR_reg(const void *const hw, uint8_t submodule_index, hri_tc_cmr_reg_t data)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR = data;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_clear_CMR_reg(const void *const hw, uint8_t submodule_index, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR &= ~mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_toggle_CMR_reg(const void *const hw, uint8_t submodule_index, hri_tc_cmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR ^= mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_cmr_reg_t hri_tc_read_CMR_reg(const void *const hw, uint8_t submodule_index)
{
	return ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CMR;
}

static inline void hri_tc_set_SMMR_GCEN_bit(const void *const hw, uint8_t submodule_index)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_SMMR |= TC_SMMR_GCEN;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_tc_get_SMMR_GCEN_bit(const void *const hw, uint8_t submodule_index)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_SMMR;
	tmp = (tmp & TC_SMMR_GCEN) >> TC_SMMR_GCEN_Pos;
	return (bool)tmp;
}

static inline void hri_tc_write_SMMR_GCEN_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_SMMR;
	tmp &= ~TC_SMMR_GCEN;
	tmp |= value << TC_SMMR_GCEN_Pos;
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_SMMR = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_clear_SMMR_GCEN_bit(const void *const hw, uint8_t submodule_index)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_SMMR &= ~TC_SMMR_GCEN;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_toggle_SMMR_GCEN_bit(const void *const hw, uint8_t submodule_index)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_SMMR ^= TC_SMMR_GCEN;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_set_SMMR_DOWN_bit(const void *const hw, uint8_t submodule_index)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_SMMR |= TC_SMMR_DOWN;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_tc_get_SMMR_DOWN_bit(const void *const hw, uint8_t submodule_index)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_SMMR;
	tmp = (tmp & TC_SMMR_DOWN) >> TC_SMMR_DOWN_Pos;
	return (bool)tmp;
}

static inline void hri_tc_write_SMMR_DOWN_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_SMMR;
	tmp &= ~TC_SMMR_DOWN;
	tmp |= value << TC_SMMR_DOWN_Pos;
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_SMMR = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_clear_SMMR_DOWN_bit(const void *const hw, uint8_t submodule_index)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_SMMR &= ~TC_SMMR_DOWN;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_toggle_SMMR_DOWN_bit(const void *const hw, uint8_t submodule_index)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_SMMR ^= TC_SMMR_DOWN;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_set_SMMR_reg(const void *const hw, uint8_t submodule_index, hri_tc_smmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_SMMR |= mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_smmr_reg_t hri_tc_get_SMMR_reg(const void *const hw, uint8_t submodule_index,
                                                    hri_tc_smmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_SMMR;
	tmp &= mask;
	return tmp;
}

static inline void hri_tc_write_SMMR_reg(const void *const hw, uint8_t submodule_index, hri_tc_smmr_reg_t data)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_SMMR = data;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_clear_SMMR_reg(const void *const hw, uint8_t submodule_index, hri_tc_smmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_SMMR &= ~mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_toggle_SMMR_reg(const void *const hw, uint8_t submodule_index, hri_tc_smmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_SMMR ^= mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_smmr_reg_t hri_tc_read_SMMR_reg(const void *const hw, uint8_t submodule_index)
{
	return ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_SMMR;
}

static inline void hri_tc_set_RA_RA_bf(const void *const hw, uint8_t submodule_index, hri_tc_ra_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RA |= TC_RA_RA(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_ra_reg_t hri_tc_get_RA_RA_bf(const void *const hw, uint8_t submodule_index, hri_tc_ra_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RA;
	tmp = (tmp & TC_RA_RA(mask)) >> TC_RA_RA_Pos;
	return tmp;
}

static inline void hri_tc_write_RA_RA_bf(const void *const hw, uint8_t submodule_index, hri_tc_ra_reg_t data)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RA;
	tmp &= ~TC_RA_RA_Msk;
	tmp |= TC_RA_RA(data);
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RA = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_clear_RA_RA_bf(const void *const hw, uint8_t submodule_index, hri_tc_ra_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RA &= ~TC_RA_RA(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_toggle_RA_RA_bf(const void *const hw, uint8_t submodule_index, hri_tc_ra_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RA ^= TC_RA_RA(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_ra_reg_t hri_tc_read_RA_RA_bf(const void *const hw, uint8_t submodule_index)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RA;
	tmp = (tmp & TC_RA_RA_Msk) >> TC_RA_RA_Pos;
	return tmp;
}

static inline void hri_tc_set_RA_reg(const void *const hw, uint8_t submodule_index, hri_tc_ra_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RA |= mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_ra_reg_t hri_tc_get_RA_reg(const void *const hw, uint8_t submodule_index, hri_tc_ra_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RA;
	tmp &= mask;
	return tmp;
}

static inline void hri_tc_write_RA_reg(const void *const hw, uint8_t submodule_index, hri_tc_ra_reg_t data)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RA = data;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_clear_RA_reg(const void *const hw, uint8_t submodule_index, hri_tc_ra_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RA &= ~mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_toggle_RA_reg(const void *const hw, uint8_t submodule_index, hri_tc_ra_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RA ^= mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_ra_reg_t hri_tc_read_RA_reg(const void *const hw, uint8_t submodule_index)
{
	return ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RA;
}

static inline void hri_tc_set_RB_RB_bf(const void *const hw, uint8_t submodule_index, hri_tc_rb_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RB |= TC_RB_RB(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_rb_reg_t hri_tc_get_RB_RB_bf(const void *const hw, uint8_t submodule_index, hri_tc_rb_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RB;
	tmp = (tmp & TC_RB_RB(mask)) >> TC_RB_RB_Pos;
	return tmp;
}

static inline void hri_tc_write_RB_RB_bf(const void *const hw, uint8_t submodule_index, hri_tc_rb_reg_t data)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RB;
	tmp &= ~TC_RB_RB_Msk;
	tmp |= TC_RB_RB(data);
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RB = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_clear_RB_RB_bf(const void *const hw, uint8_t submodule_index, hri_tc_rb_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RB &= ~TC_RB_RB(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_toggle_RB_RB_bf(const void *const hw, uint8_t submodule_index, hri_tc_rb_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RB ^= TC_RB_RB(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_rb_reg_t hri_tc_read_RB_RB_bf(const void *const hw, uint8_t submodule_index)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RB;
	tmp = (tmp & TC_RB_RB_Msk) >> TC_RB_RB_Pos;
	return tmp;
}

static inline void hri_tc_set_RB_reg(const void *const hw, uint8_t submodule_index, hri_tc_rb_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RB |= mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_rb_reg_t hri_tc_get_RB_reg(const void *const hw, uint8_t submodule_index, hri_tc_rb_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RB;
	tmp &= mask;
	return tmp;
}

static inline void hri_tc_write_RB_reg(const void *const hw, uint8_t submodule_index, hri_tc_rb_reg_t data)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RB = data;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_clear_RB_reg(const void *const hw, uint8_t submodule_index, hri_tc_rb_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RB &= ~mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_toggle_RB_reg(const void *const hw, uint8_t submodule_index, hri_tc_rb_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RB ^= mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_rb_reg_t hri_tc_read_RB_reg(const void *const hw, uint8_t submodule_index)
{
	return ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RB;
}

static inline void hri_tc_set_RC_RC_bf(const void *const hw, uint8_t submodule_index, hri_tc_rc_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RC |= TC_RC_RC(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_rc_reg_t hri_tc_get_RC_RC_bf(const void *const hw, uint8_t submodule_index, hri_tc_rc_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RC;
	tmp = (tmp & TC_RC_RC(mask)) >> TC_RC_RC_Pos;
	return tmp;
}

static inline void hri_tc_write_RC_RC_bf(const void *const hw, uint8_t submodule_index, hri_tc_rc_reg_t data)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RC;
	tmp &= ~TC_RC_RC_Msk;
	tmp |= TC_RC_RC(data);
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RC = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_clear_RC_RC_bf(const void *const hw, uint8_t submodule_index, hri_tc_rc_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RC &= ~TC_RC_RC(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_toggle_RC_RC_bf(const void *const hw, uint8_t submodule_index, hri_tc_rc_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RC ^= TC_RC_RC(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_rc_reg_t hri_tc_read_RC_RC_bf(const void *const hw, uint8_t submodule_index)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RC;
	tmp = (tmp & TC_RC_RC_Msk) >> TC_RC_RC_Pos;
	return tmp;
}

static inline void hri_tc_set_RC_reg(const void *const hw, uint8_t submodule_index, hri_tc_rc_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RC |= mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_rc_reg_t hri_tc_get_RC_reg(const void *const hw, uint8_t submodule_index, hri_tc_rc_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RC;
	tmp &= mask;
	return tmp;
}

static inline void hri_tc_write_RC_reg(const void *const hw, uint8_t submodule_index, hri_tc_rc_reg_t data)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RC = data;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_clear_RC_reg(const void *const hw, uint8_t submodule_index, hri_tc_rc_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RC &= ~mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_toggle_RC_reg(const void *const hw, uint8_t submodule_index, hri_tc_rc_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RC ^= mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_rc_reg_t hri_tc_read_RC_reg(const void *const hw, uint8_t submodule_index)
{
	return ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RC;
}

static inline hri_tc_rab_reg_t hri_tc_get_RAB_RAB_bf(const void *const hw, uint8_t submodule_index,
                                                     hri_tc_rab_reg_t mask)
{
	return (((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RAB & TC_RAB_RAB(mask)) >> TC_RAB_RAB_Pos;
}

static inline hri_tc_rab_reg_t hri_tc_read_RAB_RAB_bf(const void *const hw, uint8_t submodule_index)
{
	return (((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RAB & TC_RAB_RAB_Msk) >> TC_RAB_RAB_Pos;
}

static inline hri_tc_rab_reg_t hri_tc_get_RAB_reg(const void *const hw, uint8_t submodule_index, hri_tc_rab_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RAB;
	tmp &= mask;
	return tmp;
}

static inline hri_tc_rab_reg_t hri_tc_read_RAB_reg(const void *const hw, uint8_t submodule_index)
{
	return ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_RAB;
}

static inline hri_tc_cv_reg_t hri_tc_get_CV_CV_bf(const void *const hw, uint8_t submodule_index, hri_tc_cv_reg_t mask)
{
	return (((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CV & TC_CV_CV(mask)) >> TC_CV_CV_Pos;
}

static inline hri_tc_cv_reg_t hri_tc_read_CV_CV_bf(const void *const hw, uint8_t submodule_index)
{
	return (((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CV & TC_CV_CV_Msk) >> TC_CV_CV_Pos;
}

static inline hri_tc_cv_reg_t hri_tc_get_CV_reg(const void *const hw, uint8_t submodule_index, hri_tc_cv_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CV;
	tmp &= mask;
	return tmp;
}

static inline hri_tc_cv_reg_t hri_tc_read_CV_reg(const void *const hw, uint8_t submodule_index)
{
	return ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_CV;
}

static inline bool hri_tc_get_SR_COVFS_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Tc *)hw)->TC_CHANNEL[submodule_index].TC_SR & TC_SR_COVFS) > 0;
}

static inline bool hri_tc_get_SR_LOVRS_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Tc *)hw)->TC_CHANNEL[submodule_index].TC_SR & TC_SR_LOVRS) > 0;
}

static inline bool hri_tc_get_SR_CPAS_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Tc *)hw)->TC_CHANNEL[submodule_index].TC_SR & TC_SR_CPAS) > 0;
}

static inline bool hri_tc_get_SR_CPBS_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Tc *)hw)->TC_CHANNEL[submodule_index].TC_SR & TC_SR_CPBS) > 0;
}

static inline bool hri_tc_get_SR_CPCS_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Tc *)hw)->TC_CHANNEL[submodule_index].TC_SR & TC_SR_CPCS) > 0;
}

static inline bool hri_tc_get_SR_LDRAS_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Tc *)hw)->TC_CHANNEL[submodule_index].TC_SR & TC_SR_LDRAS) > 0;
}

static inline bool hri_tc_get_SR_LDRBS_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Tc *)hw)->TC_CHANNEL[submodule_index].TC_SR & TC_SR_LDRBS) > 0;
}

static inline bool hri_tc_get_SR_ETRGS_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Tc *)hw)->TC_CHANNEL[submodule_index].TC_SR & TC_SR_ETRGS) > 0;
}

static inline bool hri_tc_get_SR_ENDRX_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Tc *)hw)->TC_CHANNEL[submodule_index].TC_SR & TC_SR_ENDRX) > 0;
}

static inline bool hri_tc_get_SR_RXBUFF_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Tc *)hw)->TC_CHANNEL[submodule_index].TC_SR & TC_SR_RXBUFF) > 0;
}

static inline bool hri_tc_get_SR_CLKSTA_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Tc *)hw)->TC_CHANNEL[submodule_index].TC_SR & TC_SR_CLKSTA) > 0;
}

static inline bool hri_tc_get_SR_MTIOA_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Tc *)hw)->TC_CHANNEL[submodule_index].TC_SR & TC_SR_MTIOA) > 0;
}

static inline bool hri_tc_get_SR_MTIOB_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Tc *)hw)->TC_CHANNEL[submodule_index].TC_SR & TC_SR_MTIOB) > 0;
}

static inline hri_tc_sr_reg_t hri_tc_get_SR_reg(const void *const hw, uint8_t submodule_index, hri_tc_sr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_SR;
	tmp &= mask;
	return tmp;
}

static inline hri_tc_sr_reg_t hri_tc_read_SR_reg(const void *const hw, uint8_t submodule_index)
{
	return ((Tc *)hw)->TC_CHANNEL[submodule_index].TC_SR;
}

static inline void hri_tc_write_BCR_reg(const void *const hw, hri_tc_bcr_reg_t data)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_BCR = data;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_write_PTCR0_reg(const void *const hw, hri_tc_ptcr0_reg_t data)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_PTCR0 = data;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_set_BMR_TC0XC0S_bf(const void *const hw, hri_tc_bmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_BMR |= TC_BMR_TC0XC0S(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_bmr_reg_t hri_tc_get_BMR_TC0XC0S_bf(const void *const hw, hri_tc_bmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_BMR;
	tmp = (tmp & TC_BMR_TC0XC0S(mask)) >> TC_BMR_TC0XC0S_Pos;
	return tmp;
}

static inline void hri_tc_write_BMR_TC0XC0S_bf(const void *const hw, hri_tc_bmr_reg_t data)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((Tc *)hw)->TC_BMR;
	tmp &= ~TC_BMR_TC0XC0S_Msk;
	tmp |= TC_BMR_TC0XC0S(data);
	((Tc *)hw)->TC_BMR = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_clear_BMR_TC0XC0S_bf(const void *const hw, hri_tc_bmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_BMR &= ~TC_BMR_TC0XC0S(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_toggle_BMR_TC0XC0S_bf(const void *const hw, hri_tc_bmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_BMR ^= TC_BMR_TC0XC0S(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_bmr_reg_t hri_tc_read_BMR_TC0XC0S_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_BMR;
	tmp = (tmp & TC_BMR_TC0XC0S_Msk) >> TC_BMR_TC0XC0S_Pos;
	return tmp;
}

static inline void hri_tc_set_BMR_TC1XC1S_bf(const void *const hw, hri_tc_bmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_BMR |= TC_BMR_TC1XC1S(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_bmr_reg_t hri_tc_get_BMR_TC1XC1S_bf(const void *const hw, hri_tc_bmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_BMR;
	tmp = (tmp & TC_BMR_TC1XC1S(mask)) >> TC_BMR_TC1XC1S_Pos;
	return tmp;
}

static inline void hri_tc_write_BMR_TC1XC1S_bf(const void *const hw, hri_tc_bmr_reg_t data)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((Tc *)hw)->TC_BMR;
	tmp &= ~TC_BMR_TC1XC1S_Msk;
	tmp |= TC_BMR_TC1XC1S(data);
	((Tc *)hw)->TC_BMR = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_clear_BMR_TC1XC1S_bf(const void *const hw, hri_tc_bmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_BMR &= ~TC_BMR_TC1XC1S(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_toggle_BMR_TC1XC1S_bf(const void *const hw, hri_tc_bmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_BMR ^= TC_BMR_TC1XC1S(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_bmr_reg_t hri_tc_read_BMR_TC1XC1S_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_BMR;
	tmp = (tmp & TC_BMR_TC1XC1S_Msk) >> TC_BMR_TC1XC1S_Pos;
	return tmp;
}

static inline void hri_tc_set_BMR_TC2XC2S_bf(const void *const hw, hri_tc_bmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_BMR |= TC_BMR_TC2XC2S(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_bmr_reg_t hri_tc_get_BMR_TC2XC2S_bf(const void *const hw, hri_tc_bmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_BMR;
	tmp = (tmp & TC_BMR_TC2XC2S(mask)) >> TC_BMR_TC2XC2S_Pos;
	return tmp;
}

static inline void hri_tc_write_BMR_TC2XC2S_bf(const void *const hw, hri_tc_bmr_reg_t data)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((Tc *)hw)->TC_BMR;
	tmp &= ~TC_BMR_TC2XC2S_Msk;
	tmp |= TC_BMR_TC2XC2S(data);
	((Tc *)hw)->TC_BMR = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_clear_BMR_TC2XC2S_bf(const void *const hw, hri_tc_bmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_BMR &= ~TC_BMR_TC2XC2S(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_toggle_BMR_TC2XC2S_bf(const void *const hw, hri_tc_bmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_BMR ^= TC_BMR_TC2XC2S(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_bmr_reg_t hri_tc_read_BMR_TC2XC2S_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_BMR;
	tmp = (tmp & TC_BMR_TC2XC2S_Msk) >> TC_BMR_TC2XC2S_Pos;
	return tmp;
}

static inline void hri_tc_set_BMR_reg(const void *const hw, hri_tc_bmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_BMR |= mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_bmr_reg_t hri_tc_get_BMR_reg(const void *const hw, hri_tc_bmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_BMR;
	tmp &= mask;
	return tmp;
}

static inline void hri_tc_write_BMR_reg(const void *const hw, hri_tc_bmr_reg_t data)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_BMR = data;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_clear_BMR_reg(const void *const hw, hri_tc_bmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_BMR &= ~mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_toggle_BMR_reg(const void *const hw, hri_tc_bmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_BMR ^= mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_bmr_reg_t hri_tc_read_BMR_reg(const void *const hw)
{
	return ((Tc *)hw)->TC_BMR;
}

static inline void hri_tc_set_WPMR_WPEN_bit(const void *const hw)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_WPMR |= TC_WPMR_WPEN;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_tc_get_WPMR_WPEN_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_WPMR;
	tmp = (tmp & TC_WPMR_WPEN) >> TC_WPMR_WPEN_Pos;
	return (bool)tmp;
}

static inline void hri_tc_write_WPMR_WPEN_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((Tc *)hw)->TC_WPMR;
	tmp &= ~TC_WPMR_WPEN;
	tmp |= value << TC_WPMR_WPEN_Pos;
	((Tc *)hw)->TC_WPMR = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_clear_WPMR_WPEN_bit(const void *const hw)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_WPMR &= ~TC_WPMR_WPEN;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_toggle_WPMR_WPEN_bit(const void *const hw)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_WPMR ^= TC_WPMR_WPEN;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_set_WPMR_WPKEY_bf(const void *const hw, hri_tc_wpmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_WPMR |= TC_WPMR_WPKEY(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_wpmr_reg_t hri_tc_get_WPMR_WPKEY_bf(const void *const hw, hri_tc_wpmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_WPMR;
	tmp = (tmp & TC_WPMR_WPKEY(mask)) >> TC_WPMR_WPKEY_Pos;
	return tmp;
}

static inline void hri_tc_write_WPMR_WPKEY_bf(const void *const hw, hri_tc_wpmr_reg_t data)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((Tc *)hw)->TC_WPMR;
	tmp &= ~TC_WPMR_WPKEY_Msk;
	tmp |= TC_WPMR_WPKEY(data);
	((Tc *)hw)->TC_WPMR = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_clear_WPMR_WPKEY_bf(const void *const hw, hri_tc_wpmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_WPMR &= ~TC_WPMR_WPKEY(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_toggle_WPMR_WPKEY_bf(const void *const hw, hri_tc_wpmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_WPMR ^= TC_WPMR_WPKEY(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_wpmr_reg_t hri_tc_read_WPMR_WPKEY_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_WPMR;
	tmp = (tmp & TC_WPMR_WPKEY_Msk) >> TC_WPMR_WPKEY_Pos;
	return tmp;
}

static inline void hri_tc_set_WPMR_reg(const void *const hw, hri_tc_wpmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_WPMR |= mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_wpmr_reg_t hri_tc_get_WPMR_reg(const void *const hw, hri_tc_wpmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_WPMR;
	tmp &= mask;
	return tmp;
}

static inline void hri_tc_write_WPMR_reg(const void *const hw, hri_tc_wpmr_reg_t data)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_WPMR = data;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_clear_WPMR_reg(const void *const hw, hri_tc_wpmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_WPMR &= ~mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_toggle_WPMR_reg(const void *const hw, hri_tc_wpmr_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_WPMR ^= mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_wpmr_reg_t hri_tc_read_WPMR_reg(const void *const hw)
{
	return ((Tc *)hw)->TC_WPMR;
}

static inline void hri_tc_set_RPR0_RXPTR_bf(const void *const hw, hri_tc_rpr0_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_RPR0 |= TC_RPR0_RXPTR(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_rpr0_reg_t hri_tc_get_RPR0_RXPTR_bf(const void *const hw, hri_tc_rpr0_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_RPR0;
	tmp = (tmp & TC_RPR0_RXPTR(mask)) >> TC_RPR0_RXPTR_Pos;
	return tmp;
}

static inline void hri_tc_write_RPR0_RXPTR_bf(const void *const hw, hri_tc_rpr0_reg_t data)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((Tc *)hw)->TC_RPR0;
	tmp &= ~TC_RPR0_RXPTR_Msk;
	tmp |= TC_RPR0_RXPTR(data);
	((Tc *)hw)->TC_RPR0 = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_clear_RPR0_RXPTR_bf(const void *const hw, hri_tc_rpr0_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_RPR0 &= ~TC_RPR0_RXPTR(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_toggle_RPR0_RXPTR_bf(const void *const hw, hri_tc_rpr0_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_RPR0 ^= TC_RPR0_RXPTR(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_rpr0_reg_t hri_tc_read_RPR0_RXPTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_RPR0;
	tmp = (tmp & TC_RPR0_RXPTR_Msk) >> TC_RPR0_RXPTR_Pos;
	return tmp;
}

static inline void hri_tc_set_RPR0_reg(const void *const hw, hri_tc_rpr0_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_RPR0 |= mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_rpr0_reg_t hri_tc_get_RPR0_reg(const void *const hw, hri_tc_rpr0_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_RPR0;
	tmp &= mask;
	return tmp;
}

static inline void hri_tc_write_RPR0_reg(const void *const hw, hri_tc_rpr0_reg_t data)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_RPR0 = data;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_clear_RPR0_reg(const void *const hw, hri_tc_rpr0_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_RPR0 &= ~mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_toggle_RPR0_reg(const void *const hw, hri_tc_rpr0_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_RPR0 ^= mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_rpr0_reg_t hri_tc_read_RPR0_reg(const void *const hw)
{
	return ((Tc *)hw)->TC_RPR0;
}

static inline void hri_tc_set_RNPR0_RXNPTR_bf(const void *const hw, hri_tc_rnpr0_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_RNPR0 |= TC_RNPR0_RXNPTR(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_rnpr0_reg_t hri_tc_get_RNPR0_RXNPTR_bf(const void *const hw, hri_tc_rnpr0_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_RNPR0;
	tmp = (tmp & TC_RNPR0_RXNPTR(mask)) >> TC_RNPR0_RXNPTR_Pos;
	return tmp;
}

static inline void hri_tc_write_RNPR0_RXNPTR_bf(const void *const hw, hri_tc_rnpr0_reg_t data)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((Tc *)hw)->TC_RNPR0;
	tmp &= ~TC_RNPR0_RXNPTR_Msk;
	tmp |= TC_RNPR0_RXNPTR(data);
	((Tc *)hw)->TC_RNPR0 = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_clear_RNPR0_RXNPTR_bf(const void *const hw, hri_tc_rnpr0_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_RNPR0 &= ~TC_RNPR0_RXNPTR(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_toggle_RNPR0_RXNPTR_bf(const void *const hw, hri_tc_rnpr0_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_RNPR0 ^= TC_RNPR0_RXNPTR(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_rnpr0_reg_t hri_tc_read_RNPR0_RXNPTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_RNPR0;
	tmp = (tmp & TC_RNPR0_RXNPTR_Msk) >> TC_RNPR0_RXNPTR_Pos;
	return tmp;
}

static inline void hri_tc_set_RNPR0_reg(const void *const hw, hri_tc_rnpr0_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_RNPR0 |= mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_rnpr0_reg_t hri_tc_get_RNPR0_reg(const void *const hw, hri_tc_rnpr0_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_RNPR0;
	tmp &= mask;
	return tmp;
}

static inline void hri_tc_write_RNPR0_reg(const void *const hw, hri_tc_rnpr0_reg_t data)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_RNPR0 = data;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_clear_RNPR0_reg(const void *const hw, hri_tc_rnpr0_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_RNPR0 &= ~mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_toggle_RNPR0_reg(const void *const hw, hri_tc_rnpr0_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_RNPR0 ^= mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_rnpr0_reg_t hri_tc_read_RNPR0_reg(const void *const hw)
{
	return ((Tc *)hw)->TC_RNPR0;
}

static inline void hri_tc_set_RNCR0_RXNCTR_bf(const void *const hw, hri_tc_rncr0_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_RNCR0 |= TC_RNCR0_RXNCTR(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_rncr0_reg_t hri_tc_get_RNCR0_RXNCTR_bf(const void *const hw, hri_tc_rncr0_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_RNCR0;
	tmp = (tmp & TC_RNCR0_RXNCTR(mask)) >> TC_RNCR0_RXNCTR_Pos;
	return tmp;
}

static inline void hri_tc_write_RNCR0_RXNCTR_bf(const void *const hw, hri_tc_rncr0_reg_t data)
{
	uint32_t tmp;
	TC_CRITICAL_SECTION_ENTER();
	tmp = ((Tc *)hw)->TC_RNCR0;
	tmp &= ~TC_RNCR0_RXNCTR_Msk;
	tmp |= TC_RNCR0_RXNCTR(data);
	((Tc *)hw)->TC_RNCR0 = tmp;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_clear_RNCR0_RXNCTR_bf(const void *const hw, hri_tc_rncr0_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_RNCR0 &= ~TC_RNCR0_RXNCTR(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_toggle_RNCR0_RXNCTR_bf(const void *const hw, hri_tc_rncr0_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_RNCR0 ^= TC_RNCR0_RXNCTR(mask);
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_rncr0_reg_t hri_tc_read_RNCR0_RXNCTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_RNCR0;
	tmp = (tmp & TC_RNCR0_RXNCTR_Msk) >> TC_RNCR0_RXNCTR_Pos;
	return tmp;
}

static inline void hri_tc_set_RNCR0_reg(const void *const hw, hri_tc_rncr0_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_RNCR0 |= mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_rncr0_reg_t hri_tc_get_RNCR0_reg(const void *const hw, hri_tc_rncr0_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_RNCR0;
	tmp &= mask;
	return tmp;
}

static inline void hri_tc_write_RNCR0_reg(const void *const hw, hri_tc_rncr0_reg_t data)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_RNCR0 = data;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_clear_RNCR0_reg(const void *const hw, hri_tc_rncr0_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_RNCR0 &= ~mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tc_toggle_RNCR0_reg(const void *const hw, hri_tc_rncr0_reg_t mask)
{
	TC_CRITICAL_SECTION_ENTER();
	((Tc *)hw)->TC_RNCR0 ^= mask;
	TC_CRITICAL_SECTION_LEAVE();
}

static inline hri_tc_rncr0_reg_t hri_tc_read_RNCR0_reg(const void *const hw)
{
	return ((Tc *)hw)->TC_RNCR0;
}

static inline bool hri_tc_get_PTSR0_RXTEN_bit(const void *const hw)
{
	return (((Tc *)hw)->TC_PTSR0 & TC_PTSR0_RXTEN) > 0;
}

static inline bool hri_tc_get_PTSR0_TXTEN_bit(const void *const hw)
{
	return (((Tc *)hw)->TC_PTSR0 & TC_PTSR0_TXTEN) > 0;
}

static inline bool hri_tc_get_PTSR0_RXCBEN_bit(const void *const hw)
{
	return (((Tc *)hw)->TC_PTSR0 & TC_PTSR0_RXCBEN) > 0;
}

static inline bool hri_tc_get_PTSR0_TXCBEN_bit(const void *const hw)
{
	return (((Tc *)hw)->TC_PTSR0 & TC_PTSR0_TXCBEN) > 0;
}

static inline bool hri_tc_get_PTSR0_ERR_bit(const void *const hw)
{
	return (((Tc *)hw)->TC_PTSR0 & TC_PTSR0_ERR) > 0;
}

static inline hri_tc_ptsr0_reg_t hri_tc_get_PTSR0_reg(const void *const hw, hri_tc_ptsr0_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Tc *)hw)->TC_PTSR0;
	tmp &= mask;
	return tmp;
}

static inline hri_tc_ptsr0_reg_t hri_tc_read_PTSR0_reg(const void *const hw)
{
	return ((Tc *)hw)->TC_PTSR0;
}

#ifdef __cplusplus
}
#endif

#endif /* _HRI_TC_G55_H_INCLUDED */
#endif /* _SAMG55_TC_COMPONENT_ */
