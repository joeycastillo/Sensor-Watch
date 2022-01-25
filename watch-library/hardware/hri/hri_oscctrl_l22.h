/**
 * \file
 *
 * \brief SAM OSCCTRL
 *
 * Copyright (c) 2017-2018 Microchip Technology Inc. and its subsidiaries.
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

#ifdef _SAML22_OSCCTRL_COMPONENT_
#ifndef _HRI_OSCCTRL_L22_H_INCLUDED_
#define _HRI_OSCCTRL_L22_H_INCLUDED_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <hal_atomic.h>

#if defined(ENABLE_OSCCTRL_CRITICAL_SECTIONS)
#define OSCCTRL_CRITICAL_SECTION_ENTER() CRITICAL_SECTION_ENTER()
#define OSCCTRL_CRITICAL_SECTION_LEAVE() CRITICAL_SECTION_LEAVE()
#else
#define OSCCTRL_CRITICAL_SECTION_ENTER()
#define OSCCTRL_CRITICAL_SECTION_LEAVE()
#endif

typedef uint16_t hri_oscctrl_dfllctrl_reg_t;
typedef uint16_t hri_oscctrl_xoscctrl_reg_t;
typedef uint32_t hri_oscctrl_dfllmul_reg_t;
typedef uint32_t hri_oscctrl_dfllval_reg_t;
typedef uint32_t hri_oscctrl_dpllctrlb_reg_t;
typedef uint32_t hri_oscctrl_dpllratio_reg_t;
typedef uint32_t hri_oscctrl_intenset_reg_t;
typedef uint32_t hri_oscctrl_intflag_reg_t;
typedef uint32_t hri_oscctrl_status_reg_t;
typedef uint8_t  hri_oscctrl_cfdpresc_reg_t;
typedef uint8_t  hri_oscctrl_dfllsync_reg_t;
typedef uint8_t  hri_oscctrl_dpllctrla_reg_t;
typedef uint8_t  hri_oscctrl_dpllpresc_reg_t;
typedef uint8_t  hri_oscctrl_dpllstatus_reg_t;
typedef uint8_t  hri_oscctrl_dpllsyncbusy_reg_t;
typedef uint8_t  hri_oscctrl_evctrl_reg_t;
typedef uint8_t  hri_oscctrl_osc16mctrl_reg_t;

static inline void hri_oscctrl_wait_for_sync(const void *const hw, hri_oscctrl_dpllsyncbusy_reg_t reg)
{
	while (((Oscctrl *)hw)->DPLLSYNCBUSY.reg & reg) {
	};
}

static inline bool hri_oscctrl_is_syncing(const void *const hw, hri_oscctrl_dpllsyncbusy_reg_t reg)
{
	return ((Oscctrl *)hw)->DPLLSYNCBUSY.reg & reg;
}

static inline bool hri_oscctrl_get_INTFLAG_XOSCRDY_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTFLAG.reg & OSCCTRL_INTFLAG_XOSCRDY) >> OSCCTRL_INTFLAG_XOSCRDY_Pos;
}

static inline void hri_oscctrl_clear_INTFLAG_XOSCRDY_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTFLAG.reg = OSCCTRL_INTFLAG_XOSCRDY;
}

static inline bool hri_oscctrl_get_INTFLAG_XOSCFAIL_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTFLAG.reg & OSCCTRL_INTFLAG_XOSCFAIL) >> OSCCTRL_INTFLAG_XOSCFAIL_Pos;
}

static inline void hri_oscctrl_clear_INTFLAG_XOSCFAIL_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTFLAG.reg = OSCCTRL_INTFLAG_XOSCFAIL;
}

static inline bool hri_oscctrl_get_INTFLAG_OSC16MRDY_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTFLAG.reg & OSCCTRL_INTFLAG_OSC16MRDY) >> OSCCTRL_INTFLAG_OSC16MRDY_Pos;
}

static inline void hri_oscctrl_clear_INTFLAG_OSC16MRDY_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTFLAG.reg = OSCCTRL_INTFLAG_OSC16MRDY;
}

static inline bool hri_oscctrl_get_INTFLAG_DFLLRDY_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTFLAG.reg & OSCCTRL_INTFLAG_DFLLRDY) >> OSCCTRL_INTFLAG_DFLLRDY_Pos;
}

static inline void hri_oscctrl_clear_INTFLAG_DFLLRDY_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTFLAG.reg = OSCCTRL_INTFLAG_DFLLRDY;
}

static inline bool hri_oscctrl_get_INTFLAG_DFLLOOB_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTFLAG.reg & OSCCTRL_INTFLAG_DFLLOOB) >> OSCCTRL_INTFLAG_DFLLOOB_Pos;
}

static inline void hri_oscctrl_clear_INTFLAG_DFLLOOB_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTFLAG.reg = OSCCTRL_INTFLAG_DFLLOOB;
}

static inline bool hri_oscctrl_get_INTFLAG_DFLLLCKF_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTFLAG.reg & OSCCTRL_INTFLAG_DFLLLCKF) >> OSCCTRL_INTFLAG_DFLLLCKF_Pos;
}

static inline void hri_oscctrl_clear_INTFLAG_DFLLLCKF_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTFLAG.reg = OSCCTRL_INTFLAG_DFLLLCKF;
}

static inline bool hri_oscctrl_get_INTFLAG_DFLLLCKC_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTFLAG.reg & OSCCTRL_INTFLAG_DFLLLCKC) >> OSCCTRL_INTFLAG_DFLLLCKC_Pos;
}

static inline void hri_oscctrl_clear_INTFLAG_DFLLLCKC_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTFLAG.reg = OSCCTRL_INTFLAG_DFLLLCKC;
}

static inline bool hri_oscctrl_get_INTFLAG_DFLLRCS_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTFLAG.reg & OSCCTRL_INTFLAG_DFLLRCS) >> OSCCTRL_INTFLAG_DFLLRCS_Pos;
}

static inline void hri_oscctrl_clear_INTFLAG_DFLLRCS_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTFLAG.reg = OSCCTRL_INTFLAG_DFLLRCS;
}

static inline bool hri_oscctrl_get_INTFLAG_DPLLLCKR_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTFLAG.reg & OSCCTRL_INTFLAG_DPLLLCKR) >> OSCCTRL_INTFLAG_DPLLLCKR_Pos;
}

static inline void hri_oscctrl_clear_INTFLAG_DPLLLCKR_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTFLAG.reg = OSCCTRL_INTFLAG_DPLLLCKR;
}

static inline bool hri_oscctrl_get_INTFLAG_DPLLLCKF_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTFLAG.reg & OSCCTRL_INTFLAG_DPLLLCKF) >> OSCCTRL_INTFLAG_DPLLLCKF_Pos;
}

static inline void hri_oscctrl_clear_INTFLAG_DPLLLCKF_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTFLAG.reg = OSCCTRL_INTFLAG_DPLLLCKF;
}

static inline bool hri_oscctrl_get_INTFLAG_DPLLLTO_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTFLAG.reg & OSCCTRL_INTFLAG_DPLLLTO) >> OSCCTRL_INTFLAG_DPLLLTO_Pos;
}

static inline void hri_oscctrl_clear_INTFLAG_DPLLLTO_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTFLAG.reg = OSCCTRL_INTFLAG_DPLLLTO;
}

static inline bool hri_oscctrl_get_INTFLAG_DPLLLDRTO_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTFLAG.reg & OSCCTRL_INTFLAG_DPLLLDRTO) >> OSCCTRL_INTFLAG_DPLLLDRTO_Pos;
}

static inline void hri_oscctrl_clear_INTFLAG_DPLLLDRTO_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTFLAG.reg = OSCCTRL_INTFLAG_DPLLLDRTO;
}

static inline bool hri_oscctrl_get_interrupt_XOSCRDY_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTFLAG.reg & OSCCTRL_INTFLAG_XOSCRDY) >> OSCCTRL_INTFLAG_XOSCRDY_Pos;
}

static inline void hri_oscctrl_clear_interrupt_XOSCRDY_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTFLAG.reg = OSCCTRL_INTFLAG_XOSCRDY;
}

static inline bool hri_oscctrl_get_interrupt_XOSCFAIL_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTFLAG.reg & OSCCTRL_INTFLAG_XOSCFAIL) >> OSCCTRL_INTFLAG_XOSCFAIL_Pos;
}

static inline void hri_oscctrl_clear_interrupt_XOSCFAIL_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTFLAG.reg = OSCCTRL_INTFLAG_XOSCFAIL;
}

static inline bool hri_oscctrl_get_interrupt_OSC16MRDY_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTFLAG.reg & OSCCTRL_INTFLAG_OSC16MRDY) >> OSCCTRL_INTFLAG_OSC16MRDY_Pos;
}

static inline void hri_oscctrl_clear_interrupt_OSC16MRDY_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTFLAG.reg = OSCCTRL_INTFLAG_OSC16MRDY;
}

static inline bool hri_oscctrl_get_interrupt_DFLLRDY_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTFLAG.reg & OSCCTRL_INTFLAG_DFLLRDY) >> OSCCTRL_INTFLAG_DFLLRDY_Pos;
}

static inline void hri_oscctrl_clear_interrupt_DFLLRDY_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTFLAG.reg = OSCCTRL_INTFLAG_DFLLRDY;
}

static inline bool hri_oscctrl_get_interrupt_DFLLOOB_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTFLAG.reg & OSCCTRL_INTFLAG_DFLLOOB) >> OSCCTRL_INTFLAG_DFLLOOB_Pos;
}

static inline void hri_oscctrl_clear_interrupt_DFLLOOB_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTFLAG.reg = OSCCTRL_INTFLAG_DFLLOOB;
}

static inline bool hri_oscctrl_get_interrupt_DFLLLCKF_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTFLAG.reg & OSCCTRL_INTFLAG_DFLLLCKF) >> OSCCTRL_INTFLAG_DFLLLCKF_Pos;
}

static inline void hri_oscctrl_clear_interrupt_DFLLLCKF_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTFLAG.reg = OSCCTRL_INTFLAG_DFLLLCKF;
}

static inline bool hri_oscctrl_get_interrupt_DFLLLCKC_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTFLAG.reg & OSCCTRL_INTFLAG_DFLLLCKC) >> OSCCTRL_INTFLAG_DFLLLCKC_Pos;
}

static inline void hri_oscctrl_clear_interrupt_DFLLLCKC_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTFLAG.reg = OSCCTRL_INTFLAG_DFLLLCKC;
}

static inline bool hri_oscctrl_get_interrupt_DFLLRCS_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTFLAG.reg & OSCCTRL_INTFLAG_DFLLRCS) >> OSCCTRL_INTFLAG_DFLLRCS_Pos;
}

static inline void hri_oscctrl_clear_interrupt_DFLLRCS_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTFLAG.reg = OSCCTRL_INTFLAG_DFLLRCS;
}

static inline bool hri_oscctrl_get_interrupt_DPLLLCKR_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTFLAG.reg & OSCCTRL_INTFLAG_DPLLLCKR) >> OSCCTRL_INTFLAG_DPLLLCKR_Pos;
}

static inline void hri_oscctrl_clear_interrupt_DPLLLCKR_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTFLAG.reg = OSCCTRL_INTFLAG_DPLLLCKR;
}

static inline bool hri_oscctrl_get_interrupt_DPLLLCKF_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTFLAG.reg & OSCCTRL_INTFLAG_DPLLLCKF) >> OSCCTRL_INTFLAG_DPLLLCKF_Pos;
}

static inline void hri_oscctrl_clear_interrupt_DPLLLCKF_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTFLAG.reg = OSCCTRL_INTFLAG_DPLLLCKF;
}

static inline bool hri_oscctrl_get_interrupt_DPLLLTO_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTFLAG.reg & OSCCTRL_INTFLAG_DPLLLTO) >> OSCCTRL_INTFLAG_DPLLLTO_Pos;
}

static inline void hri_oscctrl_clear_interrupt_DPLLLTO_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTFLAG.reg = OSCCTRL_INTFLAG_DPLLLTO;
}

static inline bool hri_oscctrl_get_interrupt_DPLLLDRTO_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTFLAG.reg & OSCCTRL_INTFLAG_DPLLLDRTO) >> OSCCTRL_INTFLAG_DPLLLDRTO_Pos;
}

static inline void hri_oscctrl_clear_interrupt_DPLLLDRTO_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTFLAG.reg = OSCCTRL_INTFLAG_DPLLLDRTO;
}

static inline hri_oscctrl_intflag_reg_t hri_oscctrl_get_INTFLAG_reg(const void *const         hw,
                                                                    hri_oscctrl_intflag_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Oscctrl *)hw)->INTFLAG.reg;
	tmp &= mask;
	return tmp;
}

static inline hri_oscctrl_intflag_reg_t hri_oscctrl_read_INTFLAG_reg(const void *const hw)
{
	return ((Oscctrl *)hw)->INTFLAG.reg;
}

static inline void hri_oscctrl_clear_INTFLAG_reg(const void *const hw, hri_oscctrl_intflag_reg_t mask)
{
	((Oscctrl *)hw)->INTFLAG.reg = mask;
}

static inline void hri_oscctrl_set_INTEN_XOSCRDY_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTENSET.reg = OSCCTRL_INTENSET_XOSCRDY;
}

static inline bool hri_oscctrl_get_INTEN_XOSCRDY_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTENSET.reg & OSCCTRL_INTENSET_XOSCRDY) >> OSCCTRL_INTENSET_XOSCRDY_Pos;
}

static inline void hri_oscctrl_write_INTEN_XOSCRDY_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Oscctrl *)hw)->INTENCLR.reg = OSCCTRL_INTENSET_XOSCRDY;
	} else {
		((Oscctrl *)hw)->INTENSET.reg = OSCCTRL_INTENSET_XOSCRDY;
	}
}

static inline void hri_oscctrl_clear_INTEN_XOSCRDY_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTENCLR.reg = OSCCTRL_INTENSET_XOSCRDY;
}

static inline void hri_oscctrl_set_INTEN_XOSCFAIL_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTENSET.reg = OSCCTRL_INTENSET_XOSCFAIL;
}

static inline bool hri_oscctrl_get_INTEN_XOSCFAIL_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTENSET.reg & OSCCTRL_INTENSET_XOSCFAIL) >> OSCCTRL_INTENSET_XOSCFAIL_Pos;
}

static inline void hri_oscctrl_write_INTEN_XOSCFAIL_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Oscctrl *)hw)->INTENCLR.reg = OSCCTRL_INTENSET_XOSCFAIL;
	} else {
		((Oscctrl *)hw)->INTENSET.reg = OSCCTRL_INTENSET_XOSCFAIL;
	}
}

static inline void hri_oscctrl_clear_INTEN_XOSCFAIL_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTENCLR.reg = OSCCTRL_INTENSET_XOSCFAIL;
}

static inline void hri_oscctrl_set_INTEN_OSC16MRDY_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTENSET.reg = OSCCTRL_INTENSET_OSC16MRDY;
}

static inline bool hri_oscctrl_get_INTEN_OSC16MRDY_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTENSET.reg & OSCCTRL_INTENSET_OSC16MRDY) >> OSCCTRL_INTENSET_OSC16MRDY_Pos;
}

static inline void hri_oscctrl_write_INTEN_OSC16MRDY_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Oscctrl *)hw)->INTENCLR.reg = OSCCTRL_INTENSET_OSC16MRDY;
	} else {
		((Oscctrl *)hw)->INTENSET.reg = OSCCTRL_INTENSET_OSC16MRDY;
	}
}

static inline void hri_oscctrl_clear_INTEN_OSC16MRDY_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTENCLR.reg = OSCCTRL_INTENSET_OSC16MRDY;
}

static inline void hri_oscctrl_set_INTEN_DFLLRDY_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTENSET.reg = OSCCTRL_INTENSET_DFLLRDY;
}

static inline bool hri_oscctrl_get_INTEN_DFLLRDY_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTENSET.reg & OSCCTRL_INTENSET_DFLLRDY) >> OSCCTRL_INTENSET_DFLLRDY_Pos;
}

static inline void hri_oscctrl_write_INTEN_DFLLRDY_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Oscctrl *)hw)->INTENCLR.reg = OSCCTRL_INTENSET_DFLLRDY;
	} else {
		((Oscctrl *)hw)->INTENSET.reg = OSCCTRL_INTENSET_DFLLRDY;
	}
}

static inline void hri_oscctrl_clear_INTEN_DFLLRDY_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTENCLR.reg = OSCCTRL_INTENSET_DFLLRDY;
}

static inline void hri_oscctrl_set_INTEN_DFLLOOB_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTENSET.reg = OSCCTRL_INTENSET_DFLLOOB;
}

static inline bool hri_oscctrl_get_INTEN_DFLLOOB_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTENSET.reg & OSCCTRL_INTENSET_DFLLOOB) >> OSCCTRL_INTENSET_DFLLOOB_Pos;
}

static inline void hri_oscctrl_write_INTEN_DFLLOOB_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Oscctrl *)hw)->INTENCLR.reg = OSCCTRL_INTENSET_DFLLOOB;
	} else {
		((Oscctrl *)hw)->INTENSET.reg = OSCCTRL_INTENSET_DFLLOOB;
	}
}

static inline void hri_oscctrl_clear_INTEN_DFLLOOB_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTENCLR.reg = OSCCTRL_INTENSET_DFLLOOB;
}

static inline void hri_oscctrl_set_INTEN_DFLLLCKF_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTENSET.reg = OSCCTRL_INTENSET_DFLLLCKF;
}

static inline bool hri_oscctrl_get_INTEN_DFLLLCKF_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTENSET.reg & OSCCTRL_INTENSET_DFLLLCKF) >> OSCCTRL_INTENSET_DFLLLCKF_Pos;
}

static inline void hri_oscctrl_write_INTEN_DFLLLCKF_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Oscctrl *)hw)->INTENCLR.reg = OSCCTRL_INTENSET_DFLLLCKF;
	} else {
		((Oscctrl *)hw)->INTENSET.reg = OSCCTRL_INTENSET_DFLLLCKF;
	}
}

static inline void hri_oscctrl_clear_INTEN_DFLLLCKF_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTENCLR.reg = OSCCTRL_INTENSET_DFLLLCKF;
}

static inline void hri_oscctrl_set_INTEN_DFLLLCKC_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTENSET.reg = OSCCTRL_INTENSET_DFLLLCKC;
}

static inline bool hri_oscctrl_get_INTEN_DFLLLCKC_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTENSET.reg & OSCCTRL_INTENSET_DFLLLCKC) >> OSCCTRL_INTENSET_DFLLLCKC_Pos;
}

static inline void hri_oscctrl_write_INTEN_DFLLLCKC_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Oscctrl *)hw)->INTENCLR.reg = OSCCTRL_INTENSET_DFLLLCKC;
	} else {
		((Oscctrl *)hw)->INTENSET.reg = OSCCTRL_INTENSET_DFLLLCKC;
	}
}

static inline void hri_oscctrl_clear_INTEN_DFLLLCKC_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTENCLR.reg = OSCCTRL_INTENSET_DFLLLCKC;
}

static inline void hri_oscctrl_set_INTEN_DFLLRCS_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTENSET.reg = OSCCTRL_INTENSET_DFLLRCS;
}

static inline bool hri_oscctrl_get_INTEN_DFLLRCS_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTENSET.reg & OSCCTRL_INTENSET_DFLLRCS) >> OSCCTRL_INTENSET_DFLLRCS_Pos;
}

static inline void hri_oscctrl_write_INTEN_DFLLRCS_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Oscctrl *)hw)->INTENCLR.reg = OSCCTRL_INTENSET_DFLLRCS;
	} else {
		((Oscctrl *)hw)->INTENSET.reg = OSCCTRL_INTENSET_DFLLRCS;
	}
}

static inline void hri_oscctrl_clear_INTEN_DFLLRCS_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTENCLR.reg = OSCCTRL_INTENSET_DFLLRCS;
}

static inline void hri_oscctrl_set_INTEN_DPLLLCKR_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTENSET.reg = OSCCTRL_INTENSET_DPLLLCKR;
}

static inline bool hri_oscctrl_get_INTEN_DPLLLCKR_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTENSET.reg & OSCCTRL_INTENSET_DPLLLCKR) >> OSCCTRL_INTENSET_DPLLLCKR_Pos;
}

static inline void hri_oscctrl_write_INTEN_DPLLLCKR_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Oscctrl *)hw)->INTENCLR.reg = OSCCTRL_INTENSET_DPLLLCKR;
	} else {
		((Oscctrl *)hw)->INTENSET.reg = OSCCTRL_INTENSET_DPLLLCKR;
	}
}

static inline void hri_oscctrl_clear_INTEN_DPLLLCKR_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTENCLR.reg = OSCCTRL_INTENSET_DPLLLCKR;
}

static inline void hri_oscctrl_set_INTEN_DPLLLCKF_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTENSET.reg = OSCCTRL_INTENSET_DPLLLCKF;
}

static inline bool hri_oscctrl_get_INTEN_DPLLLCKF_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTENSET.reg & OSCCTRL_INTENSET_DPLLLCKF) >> OSCCTRL_INTENSET_DPLLLCKF_Pos;
}

static inline void hri_oscctrl_write_INTEN_DPLLLCKF_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Oscctrl *)hw)->INTENCLR.reg = OSCCTRL_INTENSET_DPLLLCKF;
	} else {
		((Oscctrl *)hw)->INTENSET.reg = OSCCTRL_INTENSET_DPLLLCKF;
	}
}

static inline void hri_oscctrl_clear_INTEN_DPLLLCKF_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTENCLR.reg = OSCCTRL_INTENSET_DPLLLCKF;
}

static inline void hri_oscctrl_set_INTEN_DPLLLTO_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTENSET.reg = OSCCTRL_INTENSET_DPLLLTO;
}

static inline bool hri_oscctrl_get_INTEN_DPLLLTO_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTENSET.reg & OSCCTRL_INTENSET_DPLLLTO) >> OSCCTRL_INTENSET_DPLLLTO_Pos;
}

static inline void hri_oscctrl_write_INTEN_DPLLLTO_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Oscctrl *)hw)->INTENCLR.reg = OSCCTRL_INTENSET_DPLLLTO;
	} else {
		((Oscctrl *)hw)->INTENSET.reg = OSCCTRL_INTENSET_DPLLLTO;
	}
}

static inline void hri_oscctrl_clear_INTEN_DPLLLTO_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTENCLR.reg = OSCCTRL_INTENSET_DPLLLTO;
}

static inline void hri_oscctrl_set_INTEN_DPLLLDRTO_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTENSET.reg = OSCCTRL_INTENSET_DPLLLDRTO;
}

static inline bool hri_oscctrl_get_INTEN_DPLLLDRTO_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->INTENSET.reg & OSCCTRL_INTENSET_DPLLLDRTO) >> OSCCTRL_INTENSET_DPLLLDRTO_Pos;
}

static inline void hri_oscctrl_write_INTEN_DPLLLDRTO_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Oscctrl *)hw)->INTENCLR.reg = OSCCTRL_INTENSET_DPLLLDRTO;
	} else {
		((Oscctrl *)hw)->INTENSET.reg = OSCCTRL_INTENSET_DPLLLDRTO;
	}
}

static inline void hri_oscctrl_clear_INTEN_DPLLLDRTO_bit(const void *const hw)
{
	((Oscctrl *)hw)->INTENCLR.reg = OSCCTRL_INTENSET_DPLLLDRTO;
}

static inline void hri_oscctrl_set_INTEN_reg(const void *const hw, hri_oscctrl_intenset_reg_t mask)
{
	((Oscctrl *)hw)->INTENSET.reg = mask;
}

static inline hri_oscctrl_intenset_reg_t hri_oscctrl_get_INTEN_reg(const void *const          hw,
                                                                   hri_oscctrl_intenset_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Oscctrl *)hw)->INTENSET.reg;
	tmp &= mask;
	return tmp;
}

static inline hri_oscctrl_intenset_reg_t hri_oscctrl_read_INTEN_reg(const void *const hw)
{
	return ((Oscctrl *)hw)->INTENSET.reg;
}

static inline void hri_oscctrl_write_INTEN_reg(const void *const hw, hri_oscctrl_intenset_reg_t data)
{
	((Oscctrl *)hw)->INTENSET.reg = data;
	((Oscctrl *)hw)->INTENCLR.reg = ~data;
}

static inline void hri_oscctrl_clear_INTEN_reg(const void *const hw, hri_oscctrl_intenset_reg_t mask)
{
	((Oscctrl *)hw)->INTENCLR.reg = mask;
}

static inline bool hri_oscctrl_get_STATUS_XOSCRDY_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->STATUS.reg & OSCCTRL_STATUS_XOSCRDY) >> OSCCTRL_STATUS_XOSCRDY_Pos;
}

static inline bool hri_oscctrl_get_STATUS_XOSCFAIL_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->STATUS.reg & OSCCTRL_STATUS_XOSCFAIL) >> OSCCTRL_STATUS_XOSCFAIL_Pos;
}

static inline bool hri_oscctrl_get_STATUS_XOSCCKSW_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->STATUS.reg & OSCCTRL_STATUS_XOSCCKSW) >> OSCCTRL_STATUS_XOSCCKSW_Pos;
}

static inline bool hri_oscctrl_get_STATUS_OSC16MRDY_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->STATUS.reg & OSCCTRL_STATUS_OSC16MRDY) >> OSCCTRL_STATUS_OSC16MRDY_Pos;
}

static inline bool hri_oscctrl_get_STATUS_DFLLRDY_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->STATUS.reg & OSCCTRL_STATUS_DFLLRDY) >> OSCCTRL_STATUS_DFLLRDY_Pos;
}

static inline bool hri_oscctrl_get_STATUS_DFLLOOB_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->STATUS.reg & OSCCTRL_STATUS_DFLLOOB) >> OSCCTRL_STATUS_DFLLOOB_Pos;
}

static inline bool hri_oscctrl_get_STATUS_DFLLLCKF_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->STATUS.reg & OSCCTRL_STATUS_DFLLLCKF) >> OSCCTRL_STATUS_DFLLLCKF_Pos;
}

static inline bool hri_oscctrl_get_STATUS_DFLLLCKC_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->STATUS.reg & OSCCTRL_STATUS_DFLLLCKC) >> OSCCTRL_STATUS_DFLLLCKC_Pos;
}

static inline bool hri_oscctrl_get_STATUS_DFLLRCS_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->STATUS.reg & OSCCTRL_STATUS_DFLLRCS) >> OSCCTRL_STATUS_DFLLRCS_Pos;
}

static inline bool hri_oscctrl_get_STATUS_DPLLLCKR_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->STATUS.reg & OSCCTRL_STATUS_DPLLLCKR) >> OSCCTRL_STATUS_DPLLLCKR_Pos;
}

static inline bool hri_oscctrl_get_STATUS_DPLLLCKF_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->STATUS.reg & OSCCTRL_STATUS_DPLLLCKF) >> OSCCTRL_STATUS_DPLLLCKF_Pos;
}

static inline bool hri_oscctrl_get_STATUS_DPLLTO_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->STATUS.reg & OSCCTRL_STATUS_DPLLTO) >> OSCCTRL_STATUS_DPLLTO_Pos;
}

static inline bool hri_oscctrl_get_STATUS_DPLLLDRTO_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->STATUS.reg & OSCCTRL_STATUS_DPLLLDRTO) >> OSCCTRL_STATUS_DPLLLDRTO_Pos;
}

static inline hri_oscctrl_status_reg_t hri_oscctrl_get_STATUS_reg(const void *const hw, hri_oscctrl_status_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Oscctrl *)hw)->STATUS.reg;
	tmp &= mask;
	return tmp;
}

static inline hri_oscctrl_status_reg_t hri_oscctrl_read_STATUS_reg(const void *const hw)
{
	return ((Oscctrl *)hw)->STATUS.reg;
}

static inline bool hri_oscctrl_get_DPLLSYNCBUSY_ENABLE_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->DPLLSYNCBUSY.reg & OSCCTRL_DPLLSYNCBUSY_ENABLE) >> OSCCTRL_DPLLSYNCBUSY_ENABLE_Pos;
}

static inline bool hri_oscctrl_get_DPLLSYNCBUSY_DPLLRATIO_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->DPLLSYNCBUSY.reg & OSCCTRL_DPLLSYNCBUSY_DPLLRATIO) >> OSCCTRL_DPLLSYNCBUSY_DPLLRATIO_Pos;
}

static inline bool hri_oscctrl_get_DPLLSYNCBUSY_DPLLPRESC_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->DPLLSYNCBUSY.reg & OSCCTRL_DPLLSYNCBUSY_DPLLPRESC) >> OSCCTRL_DPLLSYNCBUSY_DPLLPRESC_Pos;
}

static inline hri_oscctrl_dpllsyncbusy_reg_t hri_oscctrl_get_DPLLSYNCBUSY_reg(const void *const              hw,
                                                                              hri_oscctrl_dpllsyncbusy_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Oscctrl *)hw)->DPLLSYNCBUSY.reg;
	tmp &= mask;
	return tmp;
}

static inline hri_oscctrl_dpllsyncbusy_reg_t hri_oscctrl_read_DPLLSYNCBUSY_reg(const void *const hw)
{
	return ((Oscctrl *)hw)->DPLLSYNCBUSY.reg;
}

static inline bool hri_oscctrl_get_DPLLSTATUS_LOCK_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->DPLLSTATUS.reg & OSCCTRL_DPLLSTATUS_LOCK) >> OSCCTRL_DPLLSTATUS_LOCK_Pos;
}

static inline bool hri_oscctrl_get_DPLLSTATUS_CLKRDY_bit(const void *const hw)
{
	return (((Oscctrl *)hw)->DPLLSTATUS.reg & OSCCTRL_DPLLSTATUS_CLKRDY) >> OSCCTRL_DPLLSTATUS_CLKRDY_Pos;
}

static inline hri_oscctrl_dpllstatus_reg_t hri_oscctrl_get_DPLLSTATUS_reg(const void *const            hw,
                                                                          hri_oscctrl_dpllstatus_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Oscctrl *)hw)->DPLLSTATUS.reg;
	tmp &= mask;
	return tmp;
}

static inline hri_oscctrl_dpllstatus_reg_t hri_oscctrl_read_DPLLSTATUS_reg(const void *const hw)
{
	return ((Oscctrl *)hw)->DPLLSTATUS.reg;
}

static inline void hri_oscctrl_set_XOSCCTRL_ENABLE_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->XOSCCTRL.reg |= OSCCTRL_XOSCCTRL_ENABLE;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_oscctrl_get_XOSCCTRL_ENABLE_bit(const void *const hw)
{
	uint16_t tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	tmp = ((Oscctrl *)hw)->XOSCCTRL.reg;
	tmp = (tmp & OSCCTRL_XOSCCTRL_ENABLE) >> OSCCTRL_XOSCCTRL_ENABLE_Pos;
	return (bool)tmp;
}

static inline void hri_oscctrl_write_XOSCCTRL_ENABLE_bit(const void *const hw, bool value)
{
	uint16_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->XOSCCTRL.reg;
	tmp &= ~OSCCTRL_XOSCCTRL_ENABLE;
	tmp |= value << OSCCTRL_XOSCCTRL_ENABLE_Pos;
	((Oscctrl *)hw)->XOSCCTRL.reg = tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_XOSCCTRL_ENABLE_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->XOSCCTRL.reg &= ~OSCCTRL_XOSCCTRL_ENABLE;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_XOSCCTRL_ENABLE_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->XOSCCTRL.reg ^= OSCCTRL_XOSCCTRL_ENABLE;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_set_XOSCCTRL_XTALEN_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->XOSCCTRL.reg |= OSCCTRL_XOSCCTRL_XTALEN;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_oscctrl_get_XOSCCTRL_XTALEN_bit(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Oscctrl *)hw)->XOSCCTRL.reg;
	tmp = (tmp & OSCCTRL_XOSCCTRL_XTALEN) >> OSCCTRL_XOSCCTRL_XTALEN_Pos;
	return (bool)tmp;
}

static inline void hri_oscctrl_write_XOSCCTRL_XTALEN_bit(const void *const hw, bool value)
{
	uint16_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->XOSCCTRL.reg;
	tmp &= ~OSCCTRL_XOSCCTRL_XTALEN;
	tmp |= value << OSCCTRL_XOSCCTRL_XTALEN_Pos;
	((Oscctrl *)hw)->XOSCCTRL.reg = tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_XOSCCTRL_XTALEN_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->XOSCCTRL.reg &= ~OSCCTRL_XOSCCTRL_XTALEN;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_XOSCCTRL_XTALEN_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->XOSCCTRL.reg ^= OSCCTRL_XOSCCTRL_XTALEN;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_set_XOSCCTRL_CFDEN_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->XOSCCTRL.reg |= OSCCTRL_XOSCCTRL_CFDEN;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_oscctrl_get_XOSCCTRL_CFDEN_bit(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Oscctrl *)hw)->XOSCCTRL.reg;
	tmp = (tmp & OSCCTRL_XOSCCTRL_CFDEN) >> OSCCTRL_XOSCCTRL_CFDEN_Pos;
	return (bool)tmp;
}

static inline void hri_oscctrl_write_XOSCCTRL_CFDEN_bit(const void *const hw, bool value)
{
	uint16_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->XOSCCTRL.reg;
	tmp &= ~OSCCTRL_XOSCCTRL_CFDEN;
	tmp |= value << OSCCTRL_XOSCCTRL_CFDEN_Pos;
	((Oscctrl *)hw)->XOSCCTRL.reg = tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_XOSCCTRL_CFDEN_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->XOSCCTRL.reg &= ~OSCCTRL_XOSCCTRL_CFDEN;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_XOSCCTRL_CFDEN_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->XOSCCTRL.reg ^= OSCCTRL_XOSCCTRL_CFDEN;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_set_XOSCCTRL_SWBEN_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->XOSCCTRL.reg |= OSCCTRL_XOSCCTRL_SWBEN;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_oscctrl_get_XOSCCTRL_SWBEN_bit(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Oscctrl *)hw)->XOSCCTRL.reg;
	tmp = (tmp & OSCCTRL_XOSCCTRL_SWBEN) >> OSCCTRL_XOSCCTRL_SWBEN_Pos;
	return (bool)tmp;
}

static inline void hri_oscctrl_write_XOSCCTRL_SWBEN_bit(const void *const hw, bool value)
{
	uint16_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->XOSCCTRL.reg;
	tmp &= ~OSCCTRL_XOSCCTRL_SWBEN;
	tmp |= value << OSCCTRL_XOSCCTRL_SWBEN_Pos;
	((Oscctrl *)hw)->XOSCCTRL.reg = tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_XOSCCTRL_SWBEN_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->XOSCCTRL.reg &= ~OSCCTRL_XOSCCTRL_SWBEN;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_XOSCCTRL_SWBEN_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->XOSCCTRL.reg ^= OSCCTRL_XOSCCTRL_SWBEN;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_set_XOSCCTRL_RUNSTDBY_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->XOSCCTRL.reg |= OSCCTRL_XOSCCTRL_RUNSTDBY;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_oscctrl_get_XOSCCTRL_RUNSTDBY_bit(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Oscctrl *)hw)->XOSCCTRL.reg;
	tmp = (tmp & OSCCTRL_XOSCCTRL_RUNSTDBY) >> OSCCTRL_XOSCCTRL_RUNSTDBY_Pos;
	return (bool)tmp;
}

static inline void hri_oscctrl_write_XOSCCTRL_RUNSTDBY_bit(const void *const hw, bool value)
{
	uint16_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->XOSCCTRL.reg;
	tmp &= ~OSCCTRL_XOSCCTRL_RUNSTDBY;
	tmp |= value << OSCCTRL_XOSCCTRL_RUNSTDBY_Pos;
	((Oscctrl *)hw)->XOSCCTRL.reg = tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_XOSCCTRL_RUNSTDBY_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->XOSCCTRL.reg &= ~OSCCTRL_XOSCCTRL_RUNSTDBY;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_XOSCCTRL_RUNSTDBY_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->XOSCCTRL.reg ^= OSCCTRL_XOSCCTRL_RUNSTDBY;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_set_XOSCCTRL_ONDEMAND_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->XOSCCTRL.reg |= OSCCTRL_XOSCCTRL_ONDEMAND;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_oscctrl_get_XOSCCTRL_ONDEMAND_bit(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Oscctrl *)hw)->XOSCCTRL.reg;
	tmp = (tmp & OSCCTRL_XOSCCTRL_ONDEMAND) >> OSCCTRL_XOSCCTRL_ONDEMAND_Pos;
	return (bool)tmp;
}

static inline void hri_oscctrl_write_XOSCCTRL_ONDEMAND_bit(const void *const hw, bool value)
{
	uint16_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->XOSCCTRL.reg;
	tmp &= ~OSCCTRL_XOSCCTRL_ONDEMAND;
	tmp |= value << OSCCTRL_XOSCCTRL_ONDEMAND_Pos;
	((Oscctrl *)hw)->XOSCCTRL.reg = tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_XOSCCTRL_ONDEMAND_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->XOSCCTRL.reg &= ~OSCCTRL_XOSCCTRL_ONDEMAND;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_XOSCCTRL_ONDEMAND_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->XOSCCTRL.reg ^= OSCCTRL_XOSCCTRL_ONDEMAND;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_set_XOSCCTRL_AMPGC_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->XOSCCTRL.reg |= OSCCTRL_XOSCCTRL_AMPGC;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_oscctrl_get_XOSCCTRL_AMPGC_bit(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Oscctrl *)hw)->XOSCCTRL.reg;
	tmp = (tmp & OSCCTRL_XOSCCTRL_AMPGC) >> OSCCTRL_XOSCCTRL_AMPGC_Pos;
	return (bool)tmp;
}

static inline void hri_oscctrl_write_XOSCCTRL_AMPGC_bit(const void *const hw, bool value)
{
	uint16_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->XOSCCTRL.reg;
	tmp &= ~OSCCTRL_XOSCCTRL_AMPGC;
	tmp |= value << OSCCTRL_XOSCCTRL_AMPGC_Pos;
	((Oscctrl *)hw)->XOSCCTRL.reg = tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_XOSCCTRL_AMPGC_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->XOSCCTRL.reg &= ~OSCCTRL_XOSCCTRL_AMPGC;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_XOSCCTRL_AMPGC_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->XOSCCTRL.reg ^= OSCCTRL_XOSCCTRL_AMPGC;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_set_XOSCCTRL_GAIN_bf(const void *const hw, hri_oscctrl_xoscctrl_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->XOSCCTRL.reg |= OSCCTRL_XOSCCTRL_GAIN(mask);
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_xoscctrl_reg_t hri_oscctrl_get_XOSCCTRL_GAIN_bf(const void *const          hw,
                                                                          hri_oscctrl_xoscctrl_reg_t mask)
{
	uint16_t tmp;
	tmp = ((Oscctrl *)hw)->XOSCCTRL.reg;
	tmp = (tmp & OSCCTRL_XOSCCTRL_GAIN(mask)) >> OSCCTRL_XOSCCTRL_GAIN_Pos;
	return tmp;
}

static inline void hri_oscctrl_write_XOSCCTRL_GAIN_bf(const void *const hw, hri_oscctrl_xoscctrl_reg_t data)
{
	uint16_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->XOSCCTRL.reg;
	tmp &= ~OSCCTRL_XOSCCTRL_GAIN_Msk;
	tmp |= OSCCTRL_XOSCCTRL_GAIN(data);
	((Oscctrl *)hw)->XOSCCTRL.reg = tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_XOSCCTRL_GAIN_bf(const void *const hw, hri_oscctrl_xoscctrl_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->XOSCCTRL.reg &= ~OSCCTRL_XOSCCTRL_GAIN(mask);
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_XOSCCTRL_GAIN_bf(const void *const hw, hri_oscctrl_xoscctrl_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->XOSCCTRL.reg ^= OSCCTRL_XOSCCTRL_GAIN(mask);
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_xoscctrl_reg_t hri_oscctrl_read_XOSCCTRL_GAIN_bf(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Oscctrl *)hw)->XOSCCTRL.reg;
	tmp = (tmp & OSCCTRL_XOSCCTRL_GAIN_Msk) >> OSCCTRL_XOSCCTRL_GAIN_Pos;
	return tmp;
}

static inline void hri_oscctrl_set_XOSCCTRL_STARTUP_bf(const void *const hw, hri_oscctrl_xoscctrl_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->XOSCCTRL.reg |= OSCCTRL_XOSCCTRL_STARTUP(mask);
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_xoscctrl_reg_t hri_oscctrl_get_XOSCCTRL_STARTUP_bf(const void *const          hw,
                                                                             hri_oscctrl_xoscctrl_reg_t mask)
{
	uint16_t tmp;
	tmp = ((Oscctrl *)hw)->XOSCCTRL.reg;
	tmp = (tmp & OSCCTRL_XOSCCTRL_STARTUP(mask)) >> OSCCTRL_XOSCCTRL_STARTUP_Pos;
	return tmp;
}

static inline void hri_oscctrl_write_XOSCCTRL_STARTUP_bf(const void *const hw, hri_oscctrl_xoscctrl_reg_t data)
{
	uint16_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->XOSCCTRL.reg;
	tmp &= ~OSCCTRL_XOSCCTRL_STARTUP_Msk;
	tmp |= OSCCTRL_XOSCCTRL_STARTUP(data);
	((Oscctrl *)hw)->XOSCCTRL.reg = tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_XOSCCTRL_STARTUP_bf(const void *const hw, hri_oscctrl_xoscctrl_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->XOSCCTRL.reg &= ~OSCCTRL_XOSCCTRL_STARTUP(mask);
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_XOSCCTRL_STARTUP_bf(const void *const hw, hri_oscctrl_xoscctrl_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->XOSCCTRL.reg ^= OSCCTRL_XOSCCTRL_STARTUP(mask);
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_xoscctrl_reg_t hri_oscctrl_read_XOSCCTRL_STARTUP_bf(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Oscctrl *)hw)->XOSCCTRL.reg;
	tmp = (tmp & OSCCTRL_XOSCCTRL_STARTUP_Msk) >> OSCCTRL_XOSCCTRL_STARTUP_Pos;
	return tmp;
}

static inline void hri_oscctrl_set_XOSCCTRL_reg(const void *const hw, hri_oscctrl_xoscctrl_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->XOSCCTRL.reg |= mask;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_xoscctrl_reg_t hri_oscctrl_get_XOSCCTRL_reg(const void *const          hw,
                                                                      hri_oscctrl_xoscctrl_reg_t mask)
{
	uint16_t tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	tmp = ((Oscctrl *)hw)->XOSCCTRL.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_oscctrl_write_XOSCCTRL_reg(const void *const hw, hri_oscctrl_xoscctrl_reg_t data)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->XOSCCTRL.reg = data;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_XOSCCTRL_reg(const void *const hw, hri_oscctrl_xoscctrl_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->XOSCCTRL.reg &= ~mask;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_XOSCCTRL_reg(const void *const hw, hri_oscctrl_xoscctrl_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->XOSCCTRL.reg ^= mask;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_xoscctrl_reg_t hri_oscctrl_read_XOSCCTRL_reg(const void *const hw)
{
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	return ((Oscctrl *)hw)->XOSCCTRL.reg;
}

static inline void hri_oscctrl_set_CFDPRESC_CFDPRESC_bf(const void *const hw, hri_oscctrl_cfdpresc_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->CFDPRESC.reg |= OSCCTRL_CFDPRESC_CFDPRESC(mask);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_cfdpresc_reg_t hri_oscctrl_get_CFDPRESC_CFDPRESC_bf(const void *const          hw,
                                                                              hri_oscctrl_cfdpresc_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Oscctrl *)hw)->CFDPRESC.reg;
	tmp = (tmp & OSCCTRL_CFDPRESC_CFDPRESC(mask)) >> OSCCTRL_CFDPRESC_CFDPRESC_Pos;
	return tmp;
}

static inline void hri_oscctrl_write_CFDPRESC_CFDPRESC_bf(const void *const hw, hri_oscctrl_cfdpresc_reg_t data)
{
	uint8_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->CFDPRESC.reg;
	tmp &= ~OSCCTRL_CFDPRESC_CFDPRESC_Msk;
	tmp |= OSCCTRL_CFDPRESC_CFDPRESC(data);
	((Oscctrl *)hw)->CFDPRESC.reg = tmp;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_CFDPRESC_CFDPRESC_bf(const void *const hw, hri_oscctrl_cfdpresc_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->CFDPRESC.reg &= ~OSCCTRL_CFDPRESC_CFDPRESC(mask);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_CFDPRESC_CFDPRESC_bf(const void *const hw, hri_oscctrl_cfdpresc_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->CFDPRESC.reg ^= OSCCTRL_CFDPRESC_CFDPRESC(mask);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_cfdpresc_reg_t hri_oscctrl_read_CFDPRESC_CFDPRESC_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Oscctrl *)hw)->CFDPRESC.reg;
	tmp = (tmp & OSCCTRL_CFDPRESC_CFDPRESC_Msk) >> OSCCTRL_CFDPRESC_CFDPRESC_Pos;
	return tmp;
}

static inline void hri_oscctrl_set_CFDPRESC_reg(const void *const hw, hri_oscctrl_cfdpresc_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->CFDPRESC.reg |= mask;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_cfdpresc_reg_t hri_oscctrl_get_CFDPRESC_reg(const void *const          hw,
                                                                      hri_oscctrl_cfdpresc_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Oscctrl *)hw)->CFDPRESC.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_oscctrl_write_CFDPRESC_reg(const void *const hw, hri_oscctrl_cfdpresc_reg_t data)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->CFDPRESC.reg = data;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_CFDPRESC_reg(const void *const hw, hri_oscctrl_cfdpresc_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->CFDPRESC.reg &= ~mask;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_CFDPRESC_reg(const void *const hw, hri_oscctrl_cfdpresc_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->CFDPRESC.reg ^= mask;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_cfdpresc_reg_t hri_oscctrl_read_CFDPRESC_reg(const void *const hw)
{
	return ((Oscctrl *)hw)->CFDPRESC.reg;
}

static inline void hri_oscctrl_set_EVCTRL_CFDEO_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->EVCTRL.reg |= OSCCTRL_EVCTRL_CFDEO;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_oscctrl_get_EVCTRL_CFDEO_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Oscctrl *)hw)->EVCTRL.reg;
	tmp = (tmp & OSCCTRL_EVCTRL_CFDEO) >> OSCCTRL_EVCTRL_CFDEO_Pos;
	return (bool)tmp;
}

static inline void hri_oscctrl_write_EVCTRL_CFDEO_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->EVCTRL.reg;
	tmp &= ~OSCCTRL_EVCTRL_CFDEO;
	tmp |= value << OSCCTRL_EVCTRL_CFDEO_Pos;
	((Oscctrl *)hw)->EVCTRL.reg = tmp;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_EVCTRL_CFDEO_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->EVCTRL.reg &= ~OSCCTRL_EVCTRL_CFDEO;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_EVCTRL_CFDEO_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->EVCTRL.reg ^= OSCCTRL_EVCTRL_CFDEO;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_set_EVCTRL_reg(const void *const hw, hri_oscctrl_evctrl_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->EVCTRL.reg |= mask;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_evctrl_reg_t hri_oscctrl_get_EVCTRL_reg(const void *const hw, hri_oscctrl_evctrl_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Oscctrl *)hw)->EVCTRL.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_oscctrl_write_EVCTRL_reg(const void *const hw, hri_oscctrl_evctrl_reg_t data)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->EVCTRL.reg = data;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_EVCTRL_reg(const void *const hw, hri_oscctrl_evctrl_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->EVCTRL.reg &= ~mask;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_EVCTRL_reg(const void *const hw, hri_oscctrl_evctrl_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->EVCTRL.reg ^= mask;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_evctrl_reg_t hri_oscctrl_read_EVCTRL_reg(const void *const hw)
{
	return ((Oscctrl *)hw)->EVCTRL.reg;
}

static inline void hri_oscctrl_set_OSC16MCTRL_ENABLE_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->OSC16MCTRL.reg |= OSCCTRL_OSC16MCTRL_ENABLE;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_oscctrl_get_OSC16MCTRL_ENABLE_bit(const void *const hw)
{
	uint8_t tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	tmp = ((Oscctrl *)hw)->OSC16MCTRL.reg;
	tmp = (tmp & OSCCTRL_OSC16MCTRL_ENABLE) >> OSCCTRL_OSC16MCTRL_ENABLE_Pos;
	return (bool)tmp;
}

static inline void hri_oscctrl_write_OSC16MCTRL_ENABLE_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->OSC16MCTRL.reg;
	tmp &= ~OSCCTRL_OSC16MCTRL_ENABLE;
	tmp |= value << OSCCTRL_OSC16MCTRL_ENABLE_Pos;
	((Oscctrl *)hw)->OSC16MCTRL.reg = tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_OSC16MCTRL_ENABLE_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->OSC16MCTRL.reg &= ~OSCCTRL_OSC16MCTRL_ENABLE;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_OSC16MCTRL_ENABLE_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->OSC16MCTRL.reg ^= OSCCTRL_OSC16MCTRL_ENABLE;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_set_OSC16MCTRL_RUNSTDBY_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->OSC16MCTRL.reg |= OSCCTRL_OSC16MCTRL_RUNSTDBY;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_oscctrl_get_OSC16MCTRL_RUNSTDBY_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Oscctrl *)hw)->OSC16MCTRL.reg;
	tmp = (tmp & OSCCTRL_OSC16MCTRL_RUNSTDBY) >> OSCCTRL_OSC16MCTRL_RUNSTDBY_Pos;
	return (bool)tmp;
}

static inline void hri_oscctrl_write_OSC16MCTRL_RUNSTDBY_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->OSC16MCTRL.reg;
	tmp &= ~OSCCTRL_OSC16MCTRL_RUNSTDBY;
	tmp |= value << OSCCTRL_OSC16MCTRL_RUNSTDBY_Pos;
	((Oscctrl *)hw)->OSC16MCTRL.reg = tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_OSC16MCTRL_RUNSTDBY_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->OSC16MCTRL.reg &= ~OSCCTRL_OSC16MCTRL_RUNSTDBY;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_OSC16MCTRL_RUNSTDBY_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->OSC16MCTRL.reg ^= OSCCTRL_OSC16MCTRL_RUNSTDBY;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_set_OSC16MCTRL_ONDEMAND_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->OSC16MCTRL.reg |= OSCCTRL_OSC16MCTRL_ONDEMAND;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_oscctrl_get_OSC16MCTRL_ONDEMAND_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Oscctrl *)hw)->OSC16MCTRL.reg;
	tmp = (tmp & OSCCTRL_OSC16MCTRL_ONDEMAND) >> OSCCTRL_OSC16MCTRL_ONDEMAND_Pos;
	return (bool)tmp;
}

static inline void hri_oscctrl_write_OSC16MCTRL_ONDEMAND_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->OSC16MCTRL.reg;
	tmp &= ~OSCCTRL_OSC16MCTRL_ONDEMAND;
	tmp |= value << OSCCTRL_OSC16MCTRL_ONDEMAND_Pos;
	((Oscctrl *)hw)->OSC16MCTRL.reg = tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_OSC16MCTRL_ONDEMAND_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->OSC16MCTRL.reg &= ~OSCCTRL_OSC16MCTRL_ONDEMAND;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_OSC16MCTRL_ONDEMAND_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->OSC16MCTRL.reg ^= OSCCTRL_OSC16MCTRL_ONDEMAND;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_set_OSC16MCTRL_FSEL_bf(const void *const hw, hri_oscctrl_osc16mctrl_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->OSC16MCTRL.reg |= OSCCTRL_OSC16MCTRL_FSEL(mask);
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_osc16mctrl_reg_t hri_oscctrl_get_OSC16MCTRL_FSEL_bf(const void *const            hw,
                                                                              hri_oscctrl_osc16mctrl_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Oscctrl *)hw)->OSC16MCTRL.reg;
	tmp = (tmp & OSCCTRL_OSC16MCTRL_FSEL(mask)) >> OSCCTRL_OSC16MCTRL_FSEL_Pos;
	return tmp;
}

static inline void hri_oscctrl_write_OSC16MCTRL_FSEL_bf(const void *const hw, hri_oscctrl_osc16mctrl_reg_t data)
{
	uint8_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->OSC16MCTRL.reg;
	tmp &= ~OSCCTRL_OSC16MCTRL_FSEL_Msk;
	tmp |= OSCCTRL_OSC16MCTRL_FSEL(data);
	((Oscctrl *)hw)->OSC16MCTRL.reg = tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_OSC16MCTRL_FSEL_bf(const void *const hw, hri_oscctrl_osc16mctrl_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->OSC16MCTRL.reg &= ~OSCCTRL_OSC16MCTRL_FSEL(mask);
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_OSC16MCTRL_FSEL_bf(const void *const hw, hri_oscctrl_osc16mctrl_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->OSC16MCTRL.reg ^= OSCCTRL_OSC16MCTRL_FSEL(mask);
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_osc16mctrl_reg_t hri_oscctrl_read_OSC16MCTRL_FSEL_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Oscctrl *)hw)->OSC16MCTRL.reg;
	tmp = (tmp & OSCCTRL_OSC16MCTRL_FSEL_Msk) >> OSCCTRL_OSC16MCTRL_FSEL_Pos;
	return tmp;
}

static inline void hri_oscctrl_set_OSC16MCTRL_reg(const void *const hw, hri_oscctrl_osc16mctrl_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->OSC16MCTRL.reg |= mask;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_osc16mctrl_reg_t hri_oscctrl_get_OSC16MCTRL_reg(const void *const            hw,
                                                                          hri_oscctrl_osc16mctrl_reg_t mask)
{
	uint8_t tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	tmp = ((Oscctrl *)hw)->OSC16MCTRL.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_oscctrl_write_OSC16MCTRL_reg(const void *const hw, hri_oscctrl_osc16mctrl_reg_t data)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->OSC16MCTRL.reg = data;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_OSC16MCTRL_reg(const void *const hw, hri_oscctrl_osc16mctrl_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->OSC16MCTRL.reg &= ~mask;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_OSC16MCTRL_reg(const void *const hw, hri_oscctrl_osc16mctrl_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->OSC16MCTRL.reg ^= mask;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_osc16mctrl_reg_t hri_oscctrl_read_OSC16MCTRL_reg(const void *const hw)
{
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	return ((Oscctrl *)hw)->OSC16MCTRL.reg;
}

static inline void hri_oscctrl_set_DFLLCTRL_ENABLE_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg |= OSCCTRL_DFLLCTRL_ENABLE;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_oscctrl_get_DFLLCTRL_ENABLE_bit(const void *const hw)
{
	uint16_t tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	tmp = ((Oscctrl *)hw)->DFLLCTRL.reg;
	tmp = (tmp & OSCCTRL_DFLLCTRL_ENABLE) >> OSCCTRL_DFLLCTRL_ENABLE_Pos;
	return (bool)tmp;
}

static inline void hri_oscctrl_write_DFLLCTRL_ENABLE_bit(const void *const hw, bool value)
{
	uint16_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->DFLLCTRL.reg;
	tmp &= ~OSCCTRL_DFLLCTRL_ENABLE;
	tmp |= value << OSCCTRL_DFLLCTRL_ENABLE_Pos;
	((Oscctrl *)hw)->DFLLCTRL.reg = tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DFLLCTRL_ENABLE_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg &= ~OSCCTRL_DFLLCTRL_ENABLE;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DFLLCTRL_ENABLE_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg ^= OSCCTRL_DFLLCTRL_ENABLE;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_set_DFLLCTRL_MODE_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg |= OSCCTRL_DFLLCTRL_MODE;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_oscctrl_get_DFLLCTRL_MODE_bit(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Oscctrl *)hw)->DFLLCTRL.reg;
	tmp = (tmp & OSCCTRL_DFLLCTRL_MODE) >> OSCCTRL_DFLLCTRL_MODE_Pos;
	return (bool)tmp;
}

static inline void hri_oscctrl_write_DFLLCTRL_MODE_bit(const void *const hw, bool value)
{
	uint16_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->DFLLCTRL.reg;
	tmp &= ~OSCCTRL_DFLLCTRL_MODE;
	tmp |= value << OSCCTRL_DFLLCTRL_MODE_Pos;
	((Oscctrl *)hw)->DFLLCTRL.reg = tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DFLLCTRL_MODE_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg &= ~OSCCTRL_DFLLCTRL_MODE;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DFLLCTRL_MODE_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg ^= OSCCTRL_DFLLCTRL_MODE;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_set_DFLLCTRL_STABLE_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg |= OSCCTRL_DFLLCTRL_STABLE;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_oscctrl_get_DFLLCTRL_STABLE_bit(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Oscctrl *)hw)->DFLLCTRL.reg;
	tmp = (tmp & OSCCTRL_DFLLCTRL_STABLE) >> OSCCTRL_DFLLCTRL_STABLE_Pos;
	return (bool)tmp;
}

static inline void hri_oscctrl_write_DFLLCTRL_STABLE_bit(const void *const hw, bool value)
{
	uint16_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->DFLLCTRL.reg;
	tmp &= ~OSCCTRL_DFLLCTRL_STABLE;
	tmp |= value << OSCCTRL_DFLLCTRL_STABLE_Pos;
	((Oscctrl *)hw)->DFLLCTRL.reg = tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DFLLCTRL_STABLE_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg &= ~OSCCTRL_DFLLCTRL_STABLE;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DFLLCTRL_STABLE_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg ^= OSCCTRL_DFLLCTRL_STABLE;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_set_DFLLCTRL_LLAW_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg |= OSCCTRL_DFLLCTRL_LLAW;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_oscctrl_get_DFLLCTRL_LLAW_bit(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Oscctrl *)hw)->DFLLCTRL.reg;
	tmp = (tmp & OSCCTRL_DFLLCTRL_LLAW) >> OSCCTRL_DFLLCTRL_LLAW_Pos;
	return (bool)tmp;
}

static inline void hri_oscctrl_write_DFLLCTRL_LLAW_bit(const void *const hw, bool value)
{
	uint16_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->DFLLCTRL.reg;
	tmp &= ~OSCCTRL_DFLLCTRL_LLAW;
	tmp |= value << OSCCTRL_DFLLCTRL_LLAW_Pos;
	((Oscctrl *)hw)->DFLLCTRL.reg = tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DFLLCTRL_LLAW_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg &= ~OSCCTRL_DFLLCTRL_LLAW;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DFLLCTRL_LLAW_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg ^= OSCCTRL_DFLLCTRL_LLAW;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_set_DFLLCTRL_USBCRM_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg |= OSCCTRL_DFLLCTRL_USBCRM;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_oscctrl_get_DFLLCTRL_USBCRM_bit(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Oscctrl *)hw)->DFLLCTRL.reg;
	tmp = (tmp & OSCCTRL_DFLLCTRL_USBCRM) >> OSCCTRL_DFLLCTRL_USBCRM_Pos;
	return (bool)tmp;
}

static inline void hri_oscctrl_write_DFLLCTRL_USBCRM_bit(const void *const hw, bool value)
{
	uint16_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->DFLLCTRL.reg;
	tmp &= ~OSCCTRL_DFLLCTRL_USBCRM;
	tmp |= value << OSCCTRL_DFLLCTRL_USBCRM_Pos;
	((Oscctrl *)hw)->DFLLCTRL.reg = tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DFLLCTRL_USBCRM_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg &= ~OSCCTRL_DFLLCTRL_USBCRM;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DFLLCTRL_USBCRM_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg ^= OSCCTRL_DFLLCTRL_USBCRM;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_set_DFLLCTRL_RUNSTDBY_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg |= OSCCTRL_DFLLCTRL_RUNSTDBY;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_oscctrl_get_DFLLCTRL_RUNSTDBY_bit(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Oscctrl *)hw)->DFLLCTRL.reg;
	tmp = (tmp & OSCCTRL_DFLLCTRL_RUNSTDBY) >> OSCCTRL_DFLLCTRL_RUNSTDBY_Pos;
	return (bool)tmp;
}

static inline void hri_oscctrl_write_DFLLCTRL_RUNSTDBY_bit(const void *const hw, bool value)
{
	uint16_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->DFLLCTRL.reg;
	tmp &= ~OSCCTRL_DFLLCTRL_RUNSTDBY;
	tmp |= value << OSCCTRL_DFLLCTRL_RUNSTDBY_Pos;
	((Oscctrl *)hw)->DFLLCTRL.reg = tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DFLLCTRL_RUNSTDBY_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg &= ~OSCCTRL_DFLLCTRL_RUNSTDBY;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DFLLCTRL_RUNSTDBY_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg ^= OSCCTRL_DFLLCTRL_RUNSTDBY;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_set_DFLLCTRL_ONDEMAND_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg |= OSCCTRL_DFLLCTRL_ONDEMAND;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_oscctrl_get_DFLLCTRL_ONDEMAND_bit(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Oscctrl *)hw)->DFLLCTRL.reg;
	tmp = (tmp & OSCCTRL_DFLLCTRL_ONDEMAND) >> OSCCTRL_DFLLCTRL_ONDEMAND_Pos;
	return (bool)tmp;
}

static inline void hri_oscctrl_write_DFLLCTRL_ONDEMAND_bit(const void *const hw, bool value)
{
	uint16_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->DFLLCTRL.reg;
	tmp &= ~OSCCTRL_DFLLCTRL_ONDEMAND;
	tmp |= value << OSCCTRL_DFLLCTRL_ONDEMAND_Pos;
	((Oscctrl *)hw)->DFLLCTRL.reg = tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DFLLCTRL_ONDEMAND_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg &= ~OSCCTRL_DFLLCTRL_ONDEMAND;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DFLLCTRL_ONDEMAND_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg ^= OSCCTRL_DFLLCTRL_ONDEMAND;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_set_DFLLCTRL_CCDIS_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg |= OSCCTRL_DFLLCTRL_CCDIS;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_oscctrl_get_DFLLCTRL_CCDIS_bit(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Oscctrl *)hw)->DFLLCTRL.reg;
	tmp = (tmp & OSCCTRL_DFLLCTRL_CCDIS) >> OSCCTRL_DFLLCTRL_CCDIS_Pos;
	return (bool)tmp;
}

static inline void hri_oscctrl_write_DFLLCTRL_CCDIS_bit(const void *const hw, bool value)
{
	uint16_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->DFLLCTRL.reg;
	tmp &= ~OSCCTRL_DFLLCTRL_CCDIS;
	tmp |= value << OSCCTRL_DFLLCTRL_CCDIS_Pos;
	((Oscctrl *)hw)->DFLLCTRL.reg = tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DFLLCTRL_CCDIS_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg &= ~OSCCTRL_DFLLCTRL_CCDIS;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DFLLCTRL_CCDIS_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg ^= OSCCTRL_DFLLCTRL_CCDIS;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_set_DFLLCTRL_QLDIS_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg |= OSCCTRL_DFLLCTRL_QLDIS;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_oscctrl_get_DFLLCTRL_QLDIS_bit(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Oscctrl *)hw)->DFLLCTRL.reg;
	tmp = (tmp & OSCCTRL_DFLLCTRL_QLDIS) >> OSCCTRL_DFLLCTRL_QLDIS_Pos;
	return (bool)tmp;
}

static inline void hri_oscctrl_write_DFLLCTRL_QLDIS_bit(const void *const hw, bool value)
{
	uint16_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->DFLLCTRL.reg;
	tmp &= ~OSCCTRL_DFLLCTRL_QLDIS;
	tmp |= value << OSCCTRL_DFLLCTRL_QLDIS_Pos;
	((Oscctrl *)hw)->DFLLCTRL.reg = tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DFLLCTRL_QLDIS_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg &= ~OSCCTRL_DFLLCTRL_QLDIS;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DFLLCTRL_QLDIS_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg ^= OSCCTRL_DFLLCTRL_QLDIS;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_set_DFLLCTRL_BPLCKC_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg |= OSCCTRL_DFLLCTRL_BPLCKC;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_oscctrl_get_DFLLCTRL_BPLCKC_bit(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Oscctrl *)hw)->DFLLCTRL.reg;
	tmp = (tmp & OSCCTRL_DFLLCTRL_BPLCKC) >> OSCCTRL_DFLLCTRL_BPLCKC_Pos;
	return (bool)tmp;
}

static inline void hri_oscctrl_write_DFLLCTRL_BPLCKC_bit(const void *const hw, bool value)
{
	uint16_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->DFLLCTRL.reg;
	tmp &= ~OSCCTRL_DFLLCTRL_BPLCKC;
	tmp |= value << OSCCTRL_DFLLCTRL_BPLCKC_Pos;
	((Oscctrl *)hw)->DFLLCTRL.reg = tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DFLLCTRL_BPLCKC_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg &= ~OSCCTRL_DFLLCTRL_BPLCKC;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DFLLCTRL_BPLCKC_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg ^= OSCCTRL_DFLLCTRL_BPLCKC;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_set_DFLLCTRL_WAITLOCK_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg |= OSCCTRL_DFLLCTRL_WAITLOCK;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_oscctrl_get_DFLLCTRL_WAITLOCK_bit(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Oscctrl *)hw)->DFLLCTRL.reg;
	tmp = (tmp & OSCCTRL_DFLLCTRL_WAITLOCK) >> OSCCTRL_DFLLCTRL_WAITLOCK_Pos;
	return (bool)tmp;
}

static inline void hri_oscctrl_write_DFLLCTRL_WAITLOCK_bit(const void *const hw, bool value)
{
	uint16_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->DFLLCTRL.reg;
	tmp &= ~OSCCTRL_DFLLCTRL_WAITLOCK;
	tmp |= value << OSCCTRL_DFLLCTRL_WAITLOCK_Pos;
	((Oscctrl *)hw)->DFLLCTRL.reg = tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DFLLCTRL_WAITLOCK_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg &= ~OSCCTRL_DFLLCTRL_WAITLOCK;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DFLLCTRL_WAITLOCK_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg ^= OSCCTRL_DFLLCTRL_WAITLOCK;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_set_DFLLCTRL_reg(const void *const hw, hri_oscctrl_dfllctrl_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg |= mask;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dfllctrl_reg_t hri_oscctrl_get_DFLLCTRL_reg(const void *const          hw,
                                                                      hri_oscctrl_dfllctrl_reg_t mask)
{
	uint16_t tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	tmp = ((Oscctrl *)hw)->DFLLCTRL.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_oscctrl_write_DFLLCTRL_reg(const void *const hw, hri_oscctrl_dfllctrl_reg_t data)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg = data;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DFLLCTRL_reg(const void *const hw, hri_oscctrl_dfllctrl_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg &= ~mask;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DFLLCTRL_reg(const void *const hw, hri_oscctrl_dfllctrl_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLCTRL.reg ^= mask;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dfllctrl_reg_t hri_oscctrl_read_DFLLCTRL_reg(const void *const hw)
{
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	return ((Oscctrl *)hw)->DFLLCTRL.reg;
}

static inline void hri_oscctrl_set_DFLLVAL_FINE_bf(const void *const hw, hri_oscctrl_dfllval_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLVAL.reg |= OSCCTRL_DFLLVAL_FINE(mask);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dfllval_reg_t hri_oscctrl_get_DFLLVAL_FINE_bf(const void *const         hw,
                                                                        hri_oscctrl_dfllval_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Oscctrl *)hw)->DFLLVAL.reg;
	tmp = (tmp & OSCCTRL_DFLLVAL_FINE(mask)) >> OSCCTRL_DFLLVAL_FINE_Pos;
	return tmp;
}

static inline void hri_oscctrl_write_DFLLVAL_FINE_bf(const void *const hw, hri_oscctrl_dfllval_reg_t data)
{
	uint32_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->DFLLVAL.reg;
	tmp &= ~OSCCTRL_DFLLVAL_FINE_Msk;
	tmp |= OSCCTRL_DFLLVAL_FINE(data);
	((Oscctrl *)hw)->DFLLVAL.reg = tmp;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DFLLVAL_FINE_bf(const void *const hw, hri_oscctrl_dfllval_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLVAL.reg &= ~OSCCTRL_DFLLVAL_FINE(mask);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DFLLVAL_FINE_bf(const void *const hw, hri_oscctrl_dfllval_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLVAL.reg ^= OSCCTRL_DFLLVAL_FINE(mask);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dfllval_reg_t hri_oscctrl_read_DFLLVAL_FINE_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Oscctrl *)hw)->DFLLVAL.reg;
	tmp = (tmp & OSCCTRL_DFLLVAL_FINE_Msk) >> OSCCTRL_DFLLVAL_FINE_Pos;
	return tmp;
}

static inline void hri_oscctrl_set_DFLLVAL_COARSE_bf(const void *const hw, hri_oscctrl_dfllval_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLVAL.reg |= OSCCTRL_DFLLVAL_COARSE(mask);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dfllval_reg_t hri_oscctrl_get_DFLLVAL_COARSE_bf(const void *const         hw,
                                                                          hri_oscctrl_dfllval_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Oscctrl *)hw)->DFLLVAL.reg;
	tmp = (tmp & OSCCTRL_DFLLVAL_COARSE(mask)) >> OSCCTRL_DFLLVAL_COARSE_Pos;
	return tmp;
}

static inline void hri_oscctrl_write_DFLLVAL_COARSE_bf(const void *const hw, hri_oscctrl_dfllval_reg_t data)
{
	uint32_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->DFLLVAL.reg;
	tmp &= ~OSCCTRL_DFLLVAL_COARSE_Msk;
	tmp |= OSCCTRL_DFLLVAL_COARSE(data);
	((Oscctrl *)hw)->DFLLVAL.reg = tmp;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DFLLVAL_COARSE_bf(const void *const hw, hri_oscctrl_dfllval_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLVAL.reg &= ~OSCCTRL_DFLLVAL_COARSE(mask);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DFLLVAL_COARSE_bf(const void *const hw, hri_oscctrl_dfllval_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLVAL.reg ^= OSCCTRL_DFLLVAL_COARSE(mask);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dfllval_reg_t hri_oscctrl_read_DFLLVAL_COARSE_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Oscctrl *)hw)->DFLLVAL.reg;
	tmp = (tmp & OSCCTRL_DFLLVAL_COARSE_Msk) >> OSCCTRL_DFLLVAL_COARSE_Pos;
	return tmp;
}

static inline void hri_oscctrl_set_DFLLVAL_DIFF_bf(const void *const hw, hri_oscctrl_dfllval_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLVAL.reg |= OSCCTRL_DFLLVAL_DIFF(mask);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dfllval_reg_t hri_oscctrl_get_DFLLVAL_DIFF_bf(const void *const         hw,
                                                                        hri_oscctrl_dfllval_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Oscctrl *)hw)->DFLLVAL.reg;
	tmp = (tmp & OSCCTRL_DFLLVAL_DIFF(mask)) >> OSCCTRL_DFLLVAL_DIFF_Pos;
	return tmp;
}

static inline void hri_oscctrl_write_DFLLVAL_DIFF_bf(const void *const hw, hri_oscctrl_dfllval_reg_t data)
{
	uint32_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->DFLLVAL.reg;
	tmp &= ~OSCCTRL_DFLLVAL_DIFF_Msk;
	tmp |= OSCCTRL_DFLLVAL_DIFF(data);
	((Oscctrl *)hw)->DFLLVAL.reg = tmp;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DFLLVAL_DIFF_bf(const void *const hw, hri_oscctrl_dfllval_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLVAL.reg &= ~OSCCTRL_DFLLVAL_DIFF(mask);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DFLLVAL_DIFF_bf(const void *const hw, hri_oscctrl_dfllval_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLVAL.reg ^= OSCCTRL_DFLLVAL_DIFF(mask);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dfllval_reg_t hri_oscctrl_read_DFLLVAL_DIFF_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Oscctrl *)hw)->DFLLVAL.reg;
	tmp = (tmp & OSCCTRL_DFLLVAL_DIFF_Msk) >> OSCCTRL_DFLLVAL_DIFF_Pos;
	return tmp;
}

static inline void hri_oscctrl_set_DFLLVAL_reg(const void *const hw, hri_oscctrl_dfllval_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLVAL.reg |= mask;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dfllval_reg_t hri_oscctrl_get_DFLLVAL_reg(const void *const         hw,
                                                                    hri_oscctrl_dfllval_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Oscctrl *)hw)->DFLLVAL.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_oscctrl_write_DFLLVAL_reg(const void *const hw, hri_oscctrl_dfllval_reg_t data)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLVAL.reg = data;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DFLLVAL_reg(const void *const hw, hri_oscctrl_dfllval_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLVAL.reg &= ~mask;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DFLLVAL_reg(const void *const hw, hri_oscctrl_dfllval_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLVAL.reg ^= mask;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dfllval_reg_t hri_oscctrl_read_DFLLVAL_reg(const void *const hw)
{
	return ((Oscctrl *)hw)->DFLLVAL.reg;
}

static inline void hri_oscctrl_set_DFLLMUL_MUL_bf(const void *const hw, hri_oscctrl_dfllmul_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLMUL.reg |= OSCCTRL_DFLLMUL_MUL(mask);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dfllmul_reg_t hri_oscctrl_get_DFLLMUL_MUL_bf(const void *const         hw,
                                                                       hri_oscctrl_dfllmul_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Oscctrl *)hw)->DFLLMUL.reg;
	tmp = (tmp & OSCCTRL_DFLLMUL_MUL(mask)) >> OSCCTRL_DFLLMUL_MUL_Pos;
	return tmp;
}

static inline void hri_oscctrl_write_DFLLMUL_MUL_bf(const void *const hw, hri_oscctrl_dfllmul_reg_t data)
{
	uint32_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->DFLLMUL.reg;
	tmp &= ~OSCCTRL_DFLLMUL_MUL_Msk;
	tmp |= OSCCTRL_DFLLMUL_MUL(data);
	((Oscctrl *)hw)->DFLLMUL.reg = tmp;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DFLLMUL_MUL_bf(const void *const hw, hri_oscctrl_dfllmul_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLMUL.reg &= ~OSCCTRL_DFLLMUL_MUL(mask);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DFLLMUL_MUL_bf(const void *const hw, hri_oscctrl_dfllmul_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLMUL.reg ^= OSCCTRL_DFLLMUL_MUL(mask);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dfllmul_reg_t hri_oscctrl_read_DFLLMUL_MUL_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Oscctrl *)hw)->DFLLMUL.reg;
	tmp = (tmp & OSCCTRL_DFLLMUL_MUL_Msk) >> OSCCTRL_DFLLMUL_MUL_Pos;
	return tmp;
}

static inline void hri_oscctrl_set_DFLLMUL_FSTEP_bf(const void *const hw, hri_oscctrl_dfllmul_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLMUL.reg |= OSCCTRL_DFLLMUL_FSTEP(mask);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dfllmul_reg_t hri_oscctrl_get_DFLLMUL_FSTEP_bf(const void *const         hw,
                                                                         hri_oscctrl_dfllmul_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Oscctrl *)hw)->DFLLMUL.reg;
	tmp = (tmp & OSCCTRL_DFLLMUL_FSTEP(mask)) >> OSCCTRL_DFLLMUL_FSTEP_Pos;
	return tmp;
}

static inline void hri_oscctrl_write_DFLLMUL_FSTEP_bf(const void *const hw, hri_oscctrl_dfllmul_reg_t data)
{
	uint32_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->DFLLMUL.reg;
	tmp &= ~OSCCTRL_DFLLMUL_FSTEP_Msk;
	tmp |= OSCCTRL_DFLLMUL_FSTEP(data);
	((Oscctrl *)hw)->DFLLMUL.reg = tmp;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DFLLMUL_FSTEP_bf(const void *const hw, hri_oscctrl_dfllmul_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLMUL.reg &= ~OSCCTRL_DFLLMUL_FSTEP(mask);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DFLLMUL_FSTEP_bf(const void *const hw, hri_oscctrl_dfllmul_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLMUL.reg ^= OSCCTRL_DFLLMUL_FSTEP(mask);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dfllmul_reg_t hri_oscctrl_read_DFLLMUL_FSTEP_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Oscctrl *)hw)->DFLLMUL.reg;
	tmp = (tmp & OSCCTRL_DFLLMUL_FSTEP_Msk) >> OSCCTRL_DFLLMUL_FSTEP_Pos;
	return tmp;
}

static inline void hri_oscctrl_set_DFLLMUL_CSTEP_bf(const void *const hw, hri_oscctrl_dfllmul_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLMUL.reg |= OSCCTRL_DFLLMUL_CSTEP(mask);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dfllmul_reg_t hri_oscctrl_get_DFLLMUL_CSTEP_bf(const void *const         hw,
                                                                         hri_oscctrl_dfllmul_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Oscctrl *)hw)->DFLLMUL.reg;
	tmp = (tmp & OSCCTRL_DFLLMUL_CSTEP(mask)) >> OSCCTRL_DFLLMUL_CSTEP_Pos;
	return tmp;
}

static inline void hri_oscctrl_write_DFLLMUL_CSTEP_bf(const void *const hw, hri_oscctrl_dfllmul_reg_t data)
{
	uint32_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->DFLLMUL.reg;
	tmp &= ~OSCCTRL_DFLLMUL_CSTEP_Msk;
	tmp |= OSCCTRL_DFLLMUL_CSTEP(data);
	((Oscctrl *)hw)->DFLLMUL.reg = tmp;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DFLLMUL_CSTEP_bf(const void *const hw, hri_oscctrl_dfllmul_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLMUL.reg &= ~OSCCTRL_DFLLMUL_CSTEP(mask);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DFLLMUL_CSTEP_bf(const void *const hw, hri_oscctrl_dfllmul_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLMUL.reg ^= OSCCTRL_DFLLMUL_CSTEP(mask);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dfllmul_reg_t hri_oscctrl_read_DFLLMUL_CSTEP_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Oscctrl *)hw)->DFLLMUL.reg;
	tmp = (tmp & OSCCTRL_DFLLMUL_CSTEP_Msk) >> OSCCTRL_DFLLMUL_CSTEP_Pos;
	return tmp;
}

static inline void hri_oscctrl_set_DFLLMUL_reg(const void *const hw, hri_oscctrl_dfllmul_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLMUL.reg |= mask;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dfllmul_reg_t hri_oscctrl_get_DFLLMUL_reg(const void *const         hw,
                                                                    hri_oscctrl_dfllmul_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Oscctrl *)hw)->DFLLMUL.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_oscctrl_write_DFLLMUL_reg(const void *const hw, hri_oscctrl_dfllmul_reg_t data)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLMUL.reg = data;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DFLLMUL_reg(const void *const hw, hri_oscctrl_dfllmul_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLMUL.reg &= ~mask;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DFLLMUL_reg(const void *const hw, hri_oscctrl_dfllmul_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLMUL.reg ^= mask;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dfllmul_reg_t hri_oscctrl_read_DFLLMUL_reg(const void *const hw)
{
	return ((Oscctrl *)hw)->DFLLMUL.reg;
}

static inline void hri_oscctrl_set_DFLLSYNC_READREQ_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLSYNC.reg |= OSCCTRL_DFLLSYNC_READREQ;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_oscctrl_get_DFLLSYNC_READREQ_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Oscctrl *)hw)->DFLLSYNC.reg;
	tmp = (tmp & OSCCTRL_DFLLSYNC_READREQ) >> OSCCTRL_DFLLSYNC_READREQ_Pos;
	return (bool)tmp;
}

static inline void hri_oscctrl_write_DFLLSYNC_READREQ_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->DFLLSYNC.reg;
	tmp &= ~OSCCTRL_DFLLSYNC_READREQ;
	tmp |= value << OSCCTRL_DFLLSYNC_READREQ_Pos;
	((Oscctrl *)hw)->DFLLSYNC.reg = tmp;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DFLLSYNC_READREQ_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLSYNC.reg &= ~OSCCTRL_DFLLSYNC_READREQ;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DFLLSYNC_READREQ_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLSYNC.reg ^= OSCCTRL_DFLLSYNC_READREQ;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_set_DFLLSYNC_reg(const void *const hw, hri_oscctrl_dfllsync_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLSYNC.reg |= mask;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dfllsync_reg_t hri_oscctrl_get_DFLLSYNC_reg(const void *const          hw,
                                                                      hri_oscctrl_dfllsync_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Oscctrl *)hw)->DFLLSYNC.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_oscctrl_write_DFLLSYNC_reg(const void *const hw, hri_oscctrl_dfllsync_reg_t data)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLSYNC.reg = data;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DFLLSYNC_reg(const void *const hw, hri_oscctrl_dfllsync_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLSYNC.reg &= ~mask;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DFLLSYNC_reg(const void *const hw, hri_oscctrl_dfllsync_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DFLLSYNC.reg ^= mask;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dfllsync_reg_t hri_oscctrl_read_DFLLSYNC_reg(const void *const hw)
{
	return ((Oscctrl *)hw)->DFLLSYNC.reg;
}

static inline void hri_oscctrl_set_DPLLCTRLA_ENABLE_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLA.reg |= OSCCTRL_DPLLCTRLA_ENABLE;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_oscctrl_get_DPLLCTRLA_ENABLE_bit(const void *const hw)
{
	uint8_t tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	tmp = ((Oscctrl *)hw)->DPLLCTRLA.reg;
	tmp = (tmp & OSCCTRL_DPLLCTRLA_ENABLE) >> OSCCTRL_DPLLCTRLA_ENABLE_Pos;
	return (bool)tmp;
}

static inline void hri_oscctrl_write_DPLLCTRLA_ENABLE_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->DPLLCTRLA.reg;
	tmp &= ~OSCCTRL_DPLLCTRLA_ENABLE;
	tmp |= value << OSCCTRL_DPLLCTRLA_ENABLE_Pos;
	((Oscctrl *)hw)->DPLLCTRLA.reg = tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DPLLCTRLA_ENABLE_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLA.reg &= ~OSCCTRL_DPLLCTRLA_ENABLE;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DPLLCTRLA_ENABLE_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLA.reg ^= OSCCTRL_DPLLCTRLA_ENABLE;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_set_DPLLCTRLA_RUNSTDBY_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLA.reg |= OSCCTRL_DPLLCTRLA_RUNSTDBY;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_oscctrl_get_DPLLCTRLA_RUNSTDBY_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Oscctrl *)hw)->DPLLCTRLA.reg;
	tmp = (tmp & OSCCTRL_DPLLCTRLA_RUNSTDBY) >> OSCCTRL_DPLLCTRLA_RUNSTDBY_Pos;
	return (bool)tmp;
}

static inline void hri_oscctrl_write_DPLLCTRLA_RUNSTDBY_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->DPLLCTRLA.reg;
	tmp &= ~OSCCTRL_DPLLCTRLA_RUNSTDBY;
	tmp |= value << OSCCTRL_DPLLCTRLA_RUNSTDBY_Pos;
	((Oscctrl *)hw)->DPLLCTRLA.reg = tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DPLLCTRLA_RUNSTDBY_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLA.reg &= ~OSCCTRL_DPLLCTRLA_RUNSTDBY;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DPLLCTRLA_RUNSTDBY_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLA.reg ^= OSCCTRL_DPLLCTRLA_RUNSTDBY;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_set_DPLLCTRLA_ONDEMAND_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLA.reg |= OSCCTRL_DPLLCTRLA_ONDEMAND;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_oscctrl_get_DPLLCTRLA_ONDEMAND_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Oscctrl *)hw)->DPLLCTRLA.reg;
	tmp = (tmp & OSCCTRL_DPLLCTRLA_ONDEMAND) >> OSCCTRL_DPLLCTRLA_ONDEMAND_Pos;
	return (bool)tmp;
}

static inline void hri_oscctrl_write_DPLLCTRLA_ONDEMAND_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->DPLLCTRLA.reg;
	tmp &= ~OSCCTRL_DPLLCTRLA_ONDEMAND;
	tmp |= value << OSCCTRL_DPLLCTRLA_ONDEMAND_Pos;
	((Oscctrl *)hw)->DPLLCTRLA.reg = tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DPLLCTRLA_ONDEMAND_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLA.reg &= ~OSCCTRL_DPLLCTRLA_ONDEMAND;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DPLLCTRLA_ONDEMAND_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLA.reg ^= OSCCTRL_DPLLCTRLA_ONDEMAND;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_set_DPLLCTRLA_reg(const void *const hw, hri_oscctrl_dpllctrla_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLA.reg |= mask;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dpllctrla_reg_t hri_oscctrl_get_DPLLCTRLA_reg(const void *const           hw,
                                                                        hri_oscctrl_dpllctrla_reg_t mask)
{
	uint8_t tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	tmp = ((Oscctrl *)hw)->DPLLCTRLA.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_oscctrl_write_DPLLCTRLA_reg(const void *const hw, hri_oscctrl_dpllctrla_reg_t data)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLA.reg = data;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DPLLCTRLA_reg(const void *const hw, hri_oscctrl_dpllctrla_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLA.reg &= ~mask;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DPLLCTRLA_reg(const void *const hw, hri_oscctrl_dpllctrla_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLA.reg ^= mask;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dpllctrla_reg_t hri_oscctrl_read_DPLLCTRLA_reg(const void *const hw)
{
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_ENABLE);
	return ((Oscctrl *)hw)->DPLLCTRLA.reg;
}

static inline void hri_oscctrl_set_DPLLRATIO_LDR_bf(const void *const hw, hri_oscctrl_dpllratio_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLRATIO.reg |= OSCCTRL_DPLLRATIO_LDR(mask);
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dpllratio_reg_t hri_oscctrl_get_DPLLRATIO_LDR_bf(const void *const           hw,
                                                                           hri_oscctrl_dpllratio_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Oscctrl *)hw)->DPLLRATIO.reg;
	tmp = (tmp & OSCCTRL_DPLLRATIO_LDR(mask)) >> OSCCTRL_DPLLRATIO_LDR_Pos;
	return tmp;
}

static inline void hri_oscctrl_write_DPLLRATIO_LDR_bf(const void *const hw, hri_oscctrl_dpllratio_reg_t data)
{
	uint32_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->DPLLRATIO.reg;
	tmp &= ~OSCCTRL_DPLLRATIO_LDR_Msk;
	tmp |= OSCCTRL_DPLLRATIO_LDR(data);
	((Oscctrl *)hw)->DPLLRATIO.reg = tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DPLLRATIO_LDR_bf(const void *const hw, hri_oscctrl_dpllratio_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLRATIO.reg &= ~OSCCTRL_DPLLRATIO_LDR(mask);
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DPLLRATIO_LDR_bf(const void *const hw, hri_oscctrl_dpllratio_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLRATIO.reg ^= OSCCTRL_DPLLRATIO_LDR(mask);
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dpllratio_reg_t hri_oscctrl_read_DPLLRATIO_LDR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Oscctrl *)hw)->DPLLRATIO.reg;
	tmp = (tmp & OSCCTRL_DPLLRATIO_LDR_Msk) >> OSCCTRL_DPLLRATIO_LDR_Pos;
	return tmp;
}

static inline void hri_oscctrl_set_DPLLRATIO_LDRFRAC_bf(const void *const hw, hri_oscctrl_dpllratio_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLRATIO.reg |= OSCCTRL_DPLLRATIO_LDRFRAC(mask);
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dpllratio_reg_t hri_oscctrl_get_DPLLRATIO_LDRFRAC_bf(const void *const           hw,
                                                                               hri_oscctrl_dpllratio_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Oscctrl *)hw)->DPLLRATIO.reg;
	tmp = (tmp & OSCCTRL_DPLLRATIO_LDRFRAC(mask)) >> OSCCTRL_DPLLRATIO_LDRFRAC_Pos;
	return tmp;
}

static inline void hri_oscctrl_write_DPLLRATIO_LDRFRAC_bf(const void *const hw, hri_oscctrl_dpllratio_reg_t data)
{
	uint32_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->DPLLRATIO.reg;
	tmp &= ~OSCCTRL_DPLLRATIO_LDRFRAC_Msk;
	tmp |= OSCCTRL_DPLLRATIO_LDRFRAC(data);
	((Oscctrl *)hw)->DPLLRATIO.reg = tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DPLLRATIO_LDRFRAC_bf(const void *const hw, hri_oscctrl_dpllratio_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLRATIO.reg &= ~OSCCTRL_DPLLRATIO_LDRFRAC(mask);
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DPLLRATIO_LDRFRAC_bf(const void *const hw, hri_oscctrl_dpllratio_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLRATIO.reg ^= OSCCTRL_DPLLRATIO_LDRFRAC(mask);
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dpllratio_reg_t hri_oscctrl_read_DPLLRATIO_LDRFRAC_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Oscctrl *)hw)->DPLLRATIO.reg;
	tmp = (tmp & OSCCTRL_DPLLRATIO_LDRFRAC_Msk) >> OSCCTRL_DPLLRATIO_LDRFRAC_Pos;
	return tmp;
}

static inline void hri_oscctrl_set_DPLLRATIO_reg(const void *const hw, hri_oscctrl_dpllratio_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLRATIO.reg |= mask;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dpllratio_reg_t hri_oscctrl_get_DPLLRATIO_reg(const void *const           hw,
                                                                        hri_oscctrl_dpllratio_reg_t mask)
{
	uint32_t tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	tmp = ((Oscctrl *)hw)->DPLLRATIO.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_oscctrl_write_DPLLRATIO_reg(const void *const hw, hri_oscctrl_dpllratio_reg_t data)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLRATIO.reg = data;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DPLLRATIO_reg(const void *const hw, hri_oscctrl_dpllratio_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLRATIO.reg &= ~mask;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DPLLRATIO_reg(const void *const hw, hri_oscctrl_dpllratio_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLRATIO.reg ^= mask;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dpllratio_reg_t hri_oscctrl_read_DPLLRATIO_reg(const void *const hw)
{
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	return ((Oscctrl *)hw)->DPLLRATIO.reg;
}

static inline void hri_oscctrl_set_DPLLCTRLB_LPEN_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLB.reg |= OSCCTRL_DPLLCTRLB_LPEN;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_oscctrl_get_DPLLCTRLB_LPEN_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Oscctrl *)hw)->DPLLCTRLB.reg;
	tmp = (tmp & OSCCTRL_DPLLCTRLB_LPEN) >> OSCCTRL_DPLLCTRLB_LPEN_Pos;
	return (bool)tmp;
}

static inline void hri_oscctrl_write_DPLLCTRLB_LPEN_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->DPLLCTRLB.reg;
	tmp &= ~OSCCTRL_DPLLCTRLB_LPEN;
	tmp |= value << OSCCTRL_DPLLCTRLB_LPEN_Pos;
	((Oscctrl *)hw)->DPLLCTRLB.reg = tmp;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DPLLCTRLB_LPEN_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLB.reg &= ~OSCCTRL_DPLLCTRLB_LPEN;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DPLLCTRLB_LPEN_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLB.reg ^= OSCCTRL_DPLLCTRLB_LPEN;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_set_DPLLCTRLB_WUF_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLB.reg |= OSCCTRL_DPLLCTRLB_WUF;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_oscctrl_get_DPLLCTRLB_WUF_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Oscctrl *)hw)->DPLLCTRLB.reg;
	tmp = (tmp & OSCCTRL_DPLLCTRLB_WUF) >> OSCCTRL_DPLLCTRLB_WUF_Pos;
	return (bool)tmp;
}

static inline void hri_oscctrl_write_DPLLCTRLB_WUF_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->DPLLCTRLB.reg;
	tmp &= ~OSCCTRL_DPLLCTRLB_WUF;
	tmp |= value << OSCCTRL_DPLLCTRLB_WUF_Pos;
	((Oscctrl *)hw)->DPLLCTRLB.reg = tmp;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DPLLCTRLB_WUF_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLB.reg &= ~OSCCTRL_DPLLCTRLB_WUF;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DPLLCTRLB_WUF_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLB.reg ^= OSCCTRL_DPLLCTRLB_WUF;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_set_DPLLCTRLB_LBYPASS_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLB.reg |= OSCCTRL_DPLLCTRLB_LBYPASS;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_oscctrl_get_DPLLCTRLB_LBYPASS_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Oscctrl *)hw)->DPLLCTRLB.reg;
	tmp = (tmp & OSCCTRL_DPLLCTRLB_LBYPASS) >> OSCCTRL_DPLLCTRLB_LBYPASS_Pos;
	return (bool)tmp;
}

static inline void hri_oscctrl_write_DPLLCTRLB_LBYPASS_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->DPLLCTRLB.reg;
	tmp &= ~OSCCTRL_DPLLCTRLB_LBYPASS;
	tmp |= value << OSCCTRL_DPLLCTRLB_LBYPASS_Pos;
	((Oscctrl *)hw)->DPLLCTRLB.reg = tmp;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DPLLCTRLB_LBYPASS_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLB.reg &= ~OSCCTRL_DPLLCTRLB_LBYPASS;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DPLLCTRLB_LBYPASS_bit(const void *const hw)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLB.reg ^= OSCCTRL_DPLLCTRLB_LBYPASS;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_set_DPLLCTRLB_FILTER_bf(const void *const hw, hri_oscctrl_dpllctrlb_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLB.reg |= OSCCTRL_DPLLCTRLB_FILTER(mask);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dpllctrlb_reg_t hri_oscctrl_get_DPLLCTRLB_FILTER_bf(const void *const           hw,
                                                                              hri_oscctrl_dpllctrlb_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Oscctrl *)hw)->DPLLCTRLB.reg;
	tmp = (tmp & OSCCTRL_DPLLCTRLB_FILTER(mask)) >> OSCCTRL_DPLLCTRLB_FILTER_Pos;
	return tmp;
}

static inline void hri_oscctrl_write_DPLLCTRLB_FILTER_bf(const void *const hw, hri_oscctrl_dpllctrlb_reg_t data)
{
	uint32_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->DPLLCTRLB.reg;
	tmp &= ~OSCCTRL_DPLLCTRLB_FILTER_Msk;
	tmp |= OSCCTRL_DPLLCTRLB_FILTER(data);
	((Oscctrl *)hw)->DPLLCTRLB.reg = tmp;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DPLLCTRLB_FILTER_bf(const void *const hw, hri_oscctrl_dpllctrlb_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLB.reg &= ~OSCCTRL_DPLLCTRLB_FILTER(mask);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DPLLCTRLB_FILTER_bf(const void *const hw, hri_oscctrl_dpllctrlb_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLB.reg ^= OSCCTRL_DPLLCTRLB_FILTER(mask);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dpllctrlb_reg_t hri_oscctrl_read_DPLLCTRLB_FILTER_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Oscctrl *)hw)->DPLLCTRLB.reg;
	tmp = (tmp & OSCCTRL_DPLLCTRLB_FILTER_Msk) >> OSCCTRL_DPLLCTRLB_FILTER_Pos;
	return tmp;
}

static inline void hri_oscctrl_set_DPLLCTRLB_REFCLK_bf(const void *const hw, hri_oscctrl_dpllctrlb_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLB.reg |= OSCCTRL_DPLLCTRLB_REFCLK(mask);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dpllctrlb_reg_t hri_oscctrl_get_DPLLCTRLB_REFCLK_bf(const void *const           hw,
                                                                              hri_oscctrl_dpllctrlb_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Oscctrl *)hw)->DPLLCTRLB.reg;
	tmp = (tmp & OSCCTRL_DPLLCTRLB_REFCLK(mask)) >> OSCCTRL_DPLLCTRLB_REFCLK_Pos;
	return tmp;
}

static inline void hri_oscctrl_write_DPLLCTRLB_REFCLK_bf(const void *const hw, hri_oscctrl_dpllctrlb_reg_t data)
{
	uint32_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->DPLLCTRLB.reg;
	tmp &= ~OSCCTRL_DPLLCTRLB_REFCLK_Msk;
	tmp |= OSCCTRL_DPLLCTRLB_REFCLK(data);
	((Oscctrl *)hw)->DPLLCTRLB.reg = tmp;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DPLLCTRLB_REFCLK_bf(const void *const hw, hri_oscctrl_dpllctrlb_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLB.reg &= ~OSCCTRL_DPLLCTRLB_REFCLK(mask);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DPLLCTRLB_REFCLK_bf(const void *const hw, hri_oscctrl_dpllctrlb_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLB.reg ^= OSCCTRL_DPLLCTRLB_REFCLK(mask);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dpllctrlb_reg_t hri_oscctrl_read_DPLLCTRLB_REFCLK_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Oscctrl *)hw)->DPLLCTRLB.reg;
	tmp = (tmp & OSCCTRL_DPLLCTRLB_REFCLK_Msk) >> OSCCTRL_DPLLCTRLB_REFCLK_Pos;
	return tmp;
}

static inline void hri_oscctrl_set_DPLLCTRLB_LTIME_bf(const void *const hw, hri_oscctrl_dpllctrlb_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLB.reg |= OSCCTRL_DPLLCTRLB_LTIME(mask);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dpllctrlb_reg_t hri_oscctrl_get_DPLLCTRLB_LTIME_bf(const void *const           hw,
                                                                             hri_oscctrl_dpllctrlb_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Oscctrl *)hw)->DPLLCTRLB.reg;
	tmp = (tmp & OSCCTRL_DPLLCTRLB_LTIME(mask)) >> OSCCTRL_DPLLCTRLB_LTIME_Pos;
	return tmp;
}

static inline void hri_oscctrl_write_DPLLCTRLB_LTIME_bf(const void *const hw, hri_oscctrl_dpllctrlb_reg_t data)
{
	uint32_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->DPLLCTRLB.reg;
	tmp &= ~OSCCTRL_DPLLCTRLB_LTIME_Msk;
	tmp |= OSCCTRL_DPLLCTRLB_LTIME(data);
	((Oscctrl *)hw)->DPLLCTRLB.reg = tmp;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DPLLCTRLB_LTIME_bf(const void *const hw, hri_oscctrl_dpllctrlb_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLB.reg &= ~OSCCTRL_DPLLCTRLB_LTIME(mask);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DPLLCTRLB_LTIME_bf(const void *const hw, hri_oscctrl_dpllctrlb_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLB.reg ^= OSCCTRL_DPLLCTRLB_LTIME(mask);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dpllctrlb_reg_t hri_oscctrl_read_DPLLCTRLB_LTIME_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Oscctrl *)hw)->DPLLCTRLB.reg;
	tmp = (tmp & OSCCTRL_DPLLCTRLB_LTIME_Msk) >> OSCCTRL_DPLLCTRLB_LTIME_Pos;
	return tmp;
}

static inline void hri_oscctrl_set_DPLLCTRLB_DIV_bf(const void *const hw, hri_oscctrl_dpllctrlb_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLB.reg |= OSCCTRL_DPLLCTRLB_DIV(mask);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dpllctrlb_reg_t hri_oscctrl_get_DPLLCTRLB_DIV_bf(const void *const           hw,
                                                                           hri_oscctrl_dpllctrlb_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Oscctrl *)hw)->DPLLCTRLB.reg;
	tmp = (tmp & OSCCTRL_DPLLCTRLB_DIV(mask)) >> OSCCTRL_DPLLCTRLB_DIV_Pos;
	return tmp;
}

static inline void hri_oscctrl_write_DPLLCTRLB_DIV_bf(const void *const hw, hri_oscctrl_dpllctrlb_reg_t data)
{
	uint32_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->DPLLCTRLB.reg;
	tmp &= ~OSCCTRL_DPLLCTRLB_DIV_Msk;
	tmp |= OSCCTRL_DPLLCTRLB_DIV(data);
	((Oscctrl *)hw)->DPLLCTRLB.reg = tmp;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DPLLCTRLB_DIV_bf(const void *const hw, hri_oscctrl_dpllctrlb_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLB.reg &= ~OSCCTRL_DPLLCTRLB_DIV(mask);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DPLLCTRLB_DIV_bf(const void *const hw, hri_oscctrl_dpllctrlb_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLB.reg ^= OSCCTRL_DPLLCTRLB_DIV(mask);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dpllctrlb_reg_t hri_oscctrl_read_DPLLCTRLB_DIV_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Oscctrl *)hw)->DPLLCTRLB.reg;
	tmp = (tmp & OSCCTRL_DPLLCTRLB_DIV_Msk) >> OSCCTRL_DPLLCTRLB_DIV_Pos;
	return tmp;
}

static inline void hri_oscctrl_set_DPLLCTRLB_reg(const void *const hw, hri_oscctrl_dpllctrlb_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLB.reg |= mask;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dpllctrlb_reg_t hri_oscctrl_get_DPLLCTRLB_reg(const void *const           hw,
                                                                        hri_oscctrl_dpllctrlb_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Oscctrl *)hw)->DPLLCTRLB.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_oscctrl_write_DPLLCTRLB_reg(const void *const hw, hri_oscctrl_dpllctrlb_reg_t data)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLB.reg = data;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DPLLCTRLB_reg(const void *const hw, hri_oscctrl_dpllctrlb_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLB.reg &= ~mask;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DPLLCTRLB_reg(const void *const hw, hri_oscctrl_dpllctrlb_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLCTRLB.reg ^= mask;
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dpllctrlb_reg_t hri_oscctrl_read_DPLLCTRLB_reg(const void *const hw)
{
	return ((Oscctrl *)hw)->DPLLCTRLB.reg;
}

static inline void hri_oscctrl_set_DPLLPRESC_PRESC_bf(const void *const hw, hri_oscctrl_dpllpresc_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLPRESC.reg |= OSCCTRL_DPLLPRESC_PRESC(mask);
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dpllpresc_reg_t hri_oscctrl_get_DPLLPRESC_PRESC_bf(const void *const           hw,
                                                                             hri_oscctrl_dpllpresc_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Oscctrl *)hw)->DPLLPRESC.reg;
	tmp = (tmp & OSCCTRL_DPLLPRESC_PRESC(mask)) >> OSCCTRL_DPLLPRESC_PRESC_Pos;
	return tmp;
}

static inline void hri_oscctrl_write_DPLLPRESC_PRESC_bf(const void *const hw, hri_oscctrl_dpllpresc_reg_t data)
{
	uint8_t tmp;
	OSCCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Oscctrl *)hw)->DPLLPRESC.reg;
	tmp &= ~OSCCTRL_DPLLPRESC_PRESC_Msk;
	tmp |= OSCCTRL_DPLLPRESC_PRESC(data);
	((Oscctrl *)hw)->DPLLPRESC.reg = tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DPLLPRESC_PRESC_bf(const void *const hw, hri_oscctrl_dpllpresc_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLPRESC.reg &= ~OSCCTRL_DPLLPRESC_PRESC(mask);
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DPLLPRESC_PRESC_bf(const void *const hw, hri_oscctrl_dpllpresc_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLPRESC.reg ^= OSCCTRL_DPLLPRESC_PRESC(mask);
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dpllpresc_reg_t hri_oscctrl_read_DPLLPRESC_PRESC_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Oscctrl *)hw)->DPLLPRESC.reg;
	tmp = (tmp & OSCCTRL_DPLLPRESC_PRESC_Msk) >> OSCCTRL_DPLLPRESC_PRESC_Pos;
	return tmp;
}

static inline void hri_oscctrl_set_DPLLPRESC_reg(const void *const hw, hri_oscctrl_dpllpresc_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLPRESC.reg |= mask;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dpllpresc_reg_t hri_oscctrl_get_DPLLPRESC_reg(const void *const           hw,
                                                                        hri_oscctrl_dpllpresc_reg_t mask)
{
	uint8_t tmp;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	tmp = ((Oscctrl *)hw)->DPLLPRESC.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_oscctrl_write_DPLLPRESC_reg(const void *const hw, hri_oscctrl_dpllpresc_reg_t data)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLPRESC.reg = data;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_clear_DPLLPRESC_reg(const void *const hw, hri_oscctrl_dpllpresc_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLPRESC.reg &= ~mask;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_oscctrl_toggle_DPLLPRESC_reg(const void *const hw, hri_oscctrl_dpllpresc_reg_t mask)
{
	OSCCTRL_CRITICAL_SECTION_ENTER();
	((Oscctrl *)hw)->DPLLPRESC.reg ^= mask;
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	OSCCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_oscctrl_dpllpresc_reg_t hri_oscctrl_read_DPLLPRESC_reg(const void *const hw)
{
	hri_oscctrl_wait_for_sync(hw, OSCCTRL_DPLLSYNCBUSY_MASK);
	return ((Oscctrl *)hw)->DPLLPRESC.reg;
}

#ifdef __cplusplus
}
#endif

#endif /* _HRI_OSCCTRL_L22_H_INCLUDED */
#endif /* _SAML22_OSCCTRL_COMPONENT_ */
