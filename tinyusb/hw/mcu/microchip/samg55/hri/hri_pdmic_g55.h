/**
 * \file
 *
 * \brief SAM PDMIC
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

#ifdef _SAMG55_PDMIC_COMPONENT_
#ifndef _HRI_PDMIC_G55_H_INCLUDED_
#define _HRI_PDMIC_G55_H_INCLUDED_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <hal_atomic.h>

#if defined(ENABLE_PDMIC_CRITICAL_SECTIONS)
#define PDMIC_CRITICAL_SECTION_ENTER() CRITICAL_SECTION_ENTER()
#define PDMIC_CRITICAL_SECTION_LEAVE() CRITICAL_SECTION_LEAVE()
#else
#define PDMIC_CRITICAL_SECTION_ENTER()
#define PDMIC_CRITICAL_SECTION_LEAVE()
#endif

typedef uint32_t hri_pdmic_cdr_reg_t;
typedef uint32_t hri_pdmic_cr_reg_t;
typedef uint32_t hri_pdmic_dspr0_reg_t;
typedef uint32_t hri_pdmic_dspr1_reg_t;
typedef uint32_t hri_pdmic_imr_reg_t;
typedef uint32_t hri_pdmic_isr_reg_t;
typedef uint32_t hri_pdmic_mr_reg_t;
typedef uint32_t hri_pdmic_ptcr_reg_t;
typedef uint32_t hri_pdmic_ptsr_reg_t;
typedef uint32_t hri_pdmic_rcr_reg_t;
typedef uint32_t hri_pdmic_rncr_reg_t;
typedef uint32_t hri_pdmic_rnpr_reg_t;
typedef uint32_t hri_pdmic_rpr_reg_t;
typedef uint32_t hri_pdmic_wpmr_reg_t;
typedef uint32_t hri_pdmic_wpsr_reg_t;

static inline void hri_pdmic_set_IMR_DRDY_bit(const void *const hw)
{
	((Pdmic *)hw)->PDMIC_IER = PDMIC_IMR_DRDY;
}

static inline bool hri_pdmic_get_IMR_DRDY_bit(const void *const hw)
{
	return (((Pdmic *)hw)->PDMIC_IMR & PDMIC_IMR_DRDY) >> PDMIC_IMR_DRDY_Pos;
}

static inline void hri_pdmic_write_IMR_DRDY_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Pdmic *)hw)->PDMIC_IDR = PDMIC_IMR_DRDY;
	} else {
		((Pdmic *)hw)->PDMIC_IER = PDMIC_IMR_DRDY;
	}
}

static inline void hri_pdmic_clear_IMR_DRDY_bit(const void *const hw)
{
	((Pdmic *)hw)->PDMIC_IDR = PDMIC_IMR_DRDY;
}

static inline void hri_pdmic_set_IMR_OVRE_bit(const void *const hw)
{
	((Pdmic *)hw)->PDMIC_IER = PDMIC_IMR_OVRE;
}

static inline bool hri_pdmic_get_IMR_OVRE_bit(const void *const hw)
{
	return (((Pdmic *)hw)->PDMIC_IMR & PDMIC_IMR_OVRE) >> PDMIC_IMR_OVRE_Pos;
}

static inline void hri_pdmic_write_IMR_OVRE_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Pdmic *)hw)->PDMIC_IDR = PDMIC_IMR_OVRE;
	} else {
		((Pdmic *)hw)->PDMIC_IER = PDMIC_IMR_OVRE;
	}
}

static inline void hri_pdmic_clear_IMR_OVRE_bit(const void *const hw)
{
	((Pdmic *)hw)->PDMIC_IDR = PDMIC_IMR_OVRE;
}

static inline void hri_pdmic_set_IMR_ENDRX_bit(const void *const hw)
{
	((Pdmic *)hw)->PDMIC_IER = PDMIC_IMR_ENDRX;
}

static inline bool hri_pdmic_get_IMR_ENDRX_bit(const void *const hw)
{
	return (((Pdmic *)hw)->PDMIC_IMR & PDMIC_IMR_ENDRX) >> PDMIC_IMR_ENDRX_Pos;
}

static inline void hri_pdmic_write_IMR_ENDRX_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Pdmic *)hw)->PDMIC_IDR = PDMIC_IMR_ENDRX;
	} else {
		((Pdmic *)hw)->PDMIC_IER = PDMIC_IMR_ENDRX;
	}
}

static inline void hri_pdmic_clear_IMR_ENDRX_bit(const void *const hw)
{
	((Pdmic *)hw)->PDMIC_IDR = PDMIC_IMR_ENDRX;
}

static inline void hri_pdmic_set_IMR_RXBUFF_bit(const void *const hw)
{
	((Pdmic *)hw)->PDMIC_IER = PDMIC_IMR_RXBUFF;
}

static inline bool hri_pdmic_get_IMR_RXBUFF_bit(const void *const hw)
{
	return (((Pdmic *)hw)->PDMIC_IMR & PDMIC_IMR_RXBUFF) >> PDMIC_IMR_RXBUFF_Pos;
}

static inline void hri_pdmic_write_IMR_RXBUFF_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Pdmic *)hw)->PDMIC_IDR = PDMIC_IMR_RXBUFF;
	} else {
		((Pdmic *)hw)->PDMIC_IER = PDMIC_IMR_RXBUFF;
	}
}

static inline void hri_pdmic_clear_IMR_RXBUFF_bit(const void *const hw)
{
	((Pdmic *)hw)->PDMIC_IDR = PDMIC_IMR_RXBUFF;
}

static inline void hri_pdmic_set_IMR_reg(const void *const hw, hri_pdmic_imr_reg_t mask)
{
	((Pdmic *)hw)->PDMIC_IER = mask;
}

static inline hri_pdmic_imr_reg_t hri_pdmic_get_IMR_reg(const void *const hw, hri_pdmic_imr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_IMR;
	tmp &= mask;
	return tmp;
}

static inline hri_pdmic_imr_reg_t hri_pdmic_read_IMR_reg(const void *const hw)
{
	return ((Pdmic *)hw)->PDMIC_IMR;
}

static inline void hri_pdmic_write_IMR_reg(const void *const hw, hri_pdmic_imr_reg_t data)
{
	((Pdmic *)hw)->PDMIC_IER = data;
	((Pdmic *)hw)->PDMIC_IDR = ~data;
}

static inline void hri_pdmic_clear_IMR_reg(const void *const hw, hri_pdmic_imr_reg_t mask)
{
	((Pdmic *)hw)->PDMIC_IDR = mask;
}

static inline bool hri_pdmic_get_ISR_DRDY_bit(const void *const hw)
{
	return (((Pdmic *)hw)->PDMIC_ISR & PDMIC_ISR_DRDY) >> PDMIC_ISR_DRDY_Pos;
}

static inline bool hri_pdmic_get_ISR_OVRE_bit(const void *const hw)
{
	return (((Pdmic *)hw)->PDMIC_ISR & PDMIC_ISR_OVRE) >> PDMIC_ISR_OVRE_Pos;
}

static inline bool hri_pdmic_get_ISR_ENDRX_bit(const void *const hw)
{
	return (((Pdmic *)hw)->PDMIC_ISR & PDMIC_ISR_ENDRX) >> PDMIC_ISR_ENDRX_Pos;
}

static inline bool hri_pdmic_get_ISR_RXBUFF_bit(const void *const hw)
{
	return (((Pdmic *)hw)->PDMIC_ISR & PDMIC_ISR_RXBUFF) >> PDMIC_ISR_RXBUFF_Pos;
}

static inline hri_pdmic_isr_reg_t hri_pdmic_get_ISR_reg(const void *const hw, hri_pdmic_isr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_ISR;
	tmp &= mask;
	return tmp;
}

static inline hri_pdmic_isr_reg_t hri_pdmic_read_ISR_reg(const void *const hw)
{
	return ((Pdmic *)hw)->PDMIC_ISR;
}

static inline void hri_pdmic_write_PTCR_reg(const void *const hw, hri_pdmic_ptcr_reg_t data)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_PTCR = data;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_set_CR_SWRST_bit(const void *const hw)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_CR |= PDMIC_CR_SWRST;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_pdmic_get_CR_SWRST_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_CR;
	tmp = (tmp & PDMIC_CR_SWRST) >> PDMIC_CR_SWRST_Pos;
	return (bool)tmp;
}

static inline void hri_pdmic_set_CR_ENPDM_bit(const void *const hw)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_CR |= PDMIC_CR_ENPDM;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_pdmic_get_CR_ENPDM_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_CR;
	tmp = (tmp & PDMIC_CR_ENPDM) >> PDMIC_CR_ENPDM_Pos;
	return (bool)tmp;
}

static inline void hri_pdmic_write_CR_ENPDM_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	PDMIC_CRITICAL_SECTION_ENTER();
	tmp = ((Pdmic *)hw)->PDMIC_CR;
	tmp &= ~PDMIC_CR_ENPDM;
	tmp |= value << PDMIC_CR_ENPDM_Pos;
	((Pdmic *)hw)->PDMIC_CR = tmp;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_clear_CR_ENPDM_bit(const void *const hw)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_CR &= ~PDMIC_CR_ENPDM;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_toggle_CR_ENPDM_bit(const void *const hw)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_CR ^= PDMIC_CR_ENPDM;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_set_CR_reg(const void *const hw, hri_pdmic_cr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_CR |= mask;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_cr_reg_t hri_pdmic_get_CR_reg(const void *const hw, hri_pdmic_cr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_CR;
	tmp &= mask;
	return tmp;
}

static inline void hri_pdmic_write_CR_reg(const void *const hw, hri_pdmic_cr_reg_t data)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_CR = data;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_clear_CR_reg(const void *const hw, hri_pdmic_cr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_CR &= ~mask;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_toggle_CR_reg(const void *const hw, hri_pdmic_cr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_CR ^= mask;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_cr_reg_t hri_pdmic_read_CR_reg(const void *const hw)
{
	return ((Pdmic *)hw)->PDMIC_CR;
}

static inline void hri_pdmic_set_MR_CLKS_bit(const void *const hw)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_MR |= PDMIC_MR_CLKS;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_pdmic_get_MR_CLKS_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_MR;
	tmp = (tmp & PDMIC_MR_CLKS) >> PDMIC_MR_CLKS_Pos;
	return (bool)tmp;
}

static inline void hri_pdmic_write_MR_CLKS_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	PDMIC_CRITICAL_SECTION_ENTER();
	tmp = ((Pdmic *)hw)->PDMIC_MR;
	tmp &= ~PDMIC_MR_CLKS;
	tmp |= value << PDMIC_MR_CLKS_Pos;
	((Pdmic *)hw)->PDMIC_MR = tmp;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_clear_MR_CLKS_bit(const void *const hw)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_MR &= ~PDMIC_MR_CLKS;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_toggle_MR_CLKS_bit(const void *const hw)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_MR ^= PDMIC_MR_CLKS;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_set_MR_PRESCAL_bf(const void *const hw, hri_pdmic_mr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_MR |= PDMIC_MR_PRESCAL(mask);
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_mr_reg_t hri_pdmic_get_MR_PRESCAL_bf(const void *const hw, hri_pdmic_mr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_MR;
	tmp = (tmp & PDMIC_MR_PRESCAL(mask)) >> PDMIC_MR_PRESCAL_Pos;
	return tmp;
}

static inline void hri_pdmic_write_MR_PRESCAL_bf(const void *const hw, hri_pdmic_mr_reg_t data)
{
	uint32_t tmp;
	PDMIC_CRITICAL_SECTION_ENTER();
	tmp = ((Pdmic *)hw)->PDMIC_MR;
	tmp &= ~PDMIC_MR_PRESCAL_Msk;
	tmp |= PDMIC_MR_PRESCAL(data);
	((Pdmic *)hw)->PDMIC_MR = tmp;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_clear_MR_PRESCAL_bf(const void *const hw, hri_pdmic_mr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_MR &= ~PDMIC_MR_PRESCAL(mask);
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_toggle_MR_PRESCAL_bf(const void *const hw, hri_pdmic_mr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_MR ^= PDMIC_MR_PRESCAL(mask);
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_mr_reg_t hri_pdmic_read_MR_PRESCAL_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_MR;
	tmp = (tmp & PDMIC_MR_PRESCAL_Msk) >> PDMIC_MR_PRESCAL_Pos;
	return tmp;
}

static inline void hri_pdmic_set_MR_reg(const void *const hw, hri_pdmic_mr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_MR |= mask;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_mr_reg_t hri_pdmic_get_MR_reg(const void *const hw, hri_pdmic_mr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_MR;
	tmp &= mask;
	return tmp;
}

static inline void hri_pdmic_write_MR_reg(const void *const hw, hri_pdmic_mr_reg_t data)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_MR = data;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_clear_MR_reg(const void *const hw, hri_pdmic_mr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_MR &= ~mask;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_toggle_MR_reg(const void *const hw, hri_pdmic_mr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_MR ^= mask;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_mr_reg_t hri_pdmic_read_MR_reg(const void *const hw)
{
	return ((Pdmic *)hw)->PDMIC_MR;
}

static inline void hri_pdmic_set_DSPR0_HPFBYP_bit(const void *const hw)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_DSPR0 |= PDMIC_DSPR0_HPFBYP;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_pdmic_get_DSPR0_HPFBYP_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_DSPR0;
	tmp = (tmp & PDMIC_DSPR0_HPFBYP) >> PDMIC_DSPR0_HPFBYP_Pos;
	return (bool)tmp;
}

static inline void hri_pdmic_write_DSPR0_HPFBYP_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	PDMIC_CRITICAL_SECTION_ENTER();
	tmp = ((Pdmic *)hw)->PDMIC_DSPR0;
	tmp &= ~PDMIC_DSPR0_HPFBYP;
	tmp |= value << PDMIC_DSPR0_HPFBYP_Pos;
	((Pdmic *)hw)->PDMIC_DSPR0 = tmp;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_clear_DSPR0_HPFBYP_bit(const void *const hw)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_DSPR0 &= ~PDMIC_DSPR0_HPFBYP;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_toggle_DSPR0_HPFBYP_bit(const void *const hw)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_DSPR0 ^= PDMIC_DSPR0_HPFBYP;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_set_DSPR0_SINBYP_bit(const void *const hw)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_DSPR0 |= PDMIC_DSPR0_SINBYP;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_pdmic_get_DSPR0_SINBYP_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_DSPR0;
	tmp = (tmp & PDMIC_DSPR0_SINBYP) >> PDMIC_DSPR0_SINBYP_Pos;
	return (bool)tmp;
}

static inline void hri_pdmic_write_DSPR0_SINBYP_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	PDMIC_CRITICAL_SECTION_ENTER();
	tmp = ((Pdmic *)hw)->PDMIC_DSPR0;
	tmp &= ~PDMIC_DSPR0_SINBYP;
	tmp |= value << PDMIC_DSPR0_SINBYP_Pos;
	((Pdmic *)hw)->PDMIC_DSPR0 = tmp;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_clear_DSPR0_SINBYP_bit(const void *const hw)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_DSPR0 &= ~PDMIC_DSPR0_SINBYP;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_toggle_DSPR0_SINBYP_bit(const void *const hw)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_DSPR0 ^= PDMIC_DSPR0_SINBYP;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_set_DSPR0_SIZE_bit(const void *const hw)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_DSPR0 |= PDMIC_DSPR0_SIZE;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_pdmic_get_DSPR0_SIZE_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_DSPR0;
	tmp = (tmp & PDMIC_DSPR0_SIZE) >> PDMIC_DSPR0_SIZE_Pos;
	return (bool)tmp;
}

static inline void hri_pdmic_write_DSPR0_SIZE_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	PDMIC_CRITICAL_SECTION_ENTER();
	tmp = ((Pdmic *)hw)->PDMIC_DSPR0;
	tmp &= ~PDMIC_DSPR0_SIZE;
	tmp |= value << PDMIC_DSPR0_SIZE_Pos;
	((Pdmic *)hw)->PDMIC_DSPR0 = tmp;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_clear_DSPR0_SIZE_bit(const void *const hw)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_DSPR0 &= ~PDMIC_DSPR0_SIZE;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_toggle_DSPR0_SIZE_bit(const void *const hw)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_DSPR0 ^= PDMIC_DSPR0_SIZE;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_set_DSPR0_OSR_bf(const void *const hw, hri_pdmic_dspr0_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_DSPR0 |= PDMIC_DSPR0_OSR(mask);
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_dspr0_reg_t hri_pdmic_get_DSPR0_OSR_bf(const void *const hw, hri_pdmic_dspr0_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_DSPR0;
	tmp = (tmp & PDMIC_DSPR0_OSR(mask)) >> PDMIC_DSPR0_OSR_Pos;
	return tmp;
}

static inline void hri_pdmic_write_DSPR0_OSR_bf(const void *const hw, hri_pdmic_dspr0_reg_t data)
{
	uint32_t tmp;
	PDMIC_CRITICAL_SECTION_ENTER();
	tmp = ((Pdmic *)hw)->PDMIC_DSPR0;
	tmp &= ~PDMIC_DSPR0_OSR_Msk;
	tmp |= PDMIC_DSPR0_OSR(data);
	((Pdmic *)hw)->PDMIC_DSPR0 = tmp;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_clear_DSPR0_OSR_bf(const void *const hw, hri_pdmic_dspr0_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_DSPR0 &= ~PDMIC_DSPR0_OSR(mask);
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_toggle_DSPR0_OSR_bf(const void *const hw, hri_pdmic_dspr0_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_DSPR0 ^= PDMIC_DSPR0_OSR(mask);
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_dspr0_reg_t hri_pdmic_read_DSPR0_OSR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_DSPR0;
	tmp = (tmp & PDMIC_DSPR0_OSR_Msk) >> PDMIC_DSPR0_OSR_Pos;
	return tmp;
}

static inline void hri_pdmic_set_DSPR0_SCALE_bf(const void *const hw, hri_pdmic_dspr0_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_DSPR0 |= PDMIC_DSPR0_SCALE(mask);
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_dspr0_reg_t hri_pdmic_get_DSPR0_SCALE_bf(const void *const hw, hri_pdmic_dspr0_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_DSPR0;
	tmp = (tmp & PDMIC_DSPR0_SCALE(mask)) >> PDMIC_DSPR0_SCALE_Pos;
	return tmp;
}

static inline void hri_pdmic_write_DSPR0_SCALE_bf(const void *const hw, hri_pdmic_dspr0_reg_t data)
{
	uint32_t tmp;
	PDMIC_CRITICAL_SECTION_ENTER();
	tmp = ((Pdmic *)hw)->PDMIC_DSPR0;
	tmp &= ~PDMIC_DSPR0_SCALE_Msk;
	tmp |= PDMIC_DSPR0_SCALE(data);
	((Pdmic *)hw)->PDMIC_DSPR0 = tmp;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_clear_DSPR0_SCALE_bf(const void *const hw, hri_pdmic_dspr0_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_DSPR0 &= ~PDMIC_DSPR0_SCALE(mask);
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_toggle_DSPR0_SCALE_bf(const void *const hw, hri_pdmic_dspr0_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_DSPR0 ^= PDMIC_DSPR0_SCALE(mask);
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_dspr0_reg_t hri_pdmic_read_DSPR0_SCALE_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_DSPR0;
	tmp = (tmp & PDMIC_DSPR0_SCALE_Msk) >> PDMIC_DSPR0_SCALE_Pos;
	return tmp;
}

static inline void hri_pdmic_set_DSPR0_SHIFT_bf(const void *const hw, hri_pdmic_dspr0_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_DSPR0 |= PDMIC_DSPR0_SHIFT(mask);
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_dspr0_reg_t hri_pdmic_get_DSPR0_SHIFT_bf(const void *const hw, hri_pdmic_dspr0_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_DSPR0;
	tmp = (tmp & PDMIC_DSPR0_SHIFT(mask)) >> PDMIC_DSPR0_SHIFT_Pos;
	return tmp;
}

static inline void hri_pdmic_write_DSPR0_SHIFT_bf(const void *const hw, hri_pdmic_dspr0_reg_t data)
{
	uint32_t tmp;
	PDMIC_CRITICAL_SECTION_ENTER();
	tmp = ((Pdmic *)hw)->PDMIC_DSPR0;
	tmp &= ~PDMIC_DSPR0_SHIFT_Msk;
	tmp |= PDMIC_DSPR0_SHIFT(data);
	((Pdmic *)hw)->PDMIC_DSPR0 = tmp;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_clear_DSPR0_SHIFT_bf(const void *const hw, hri_pdmic_dspr0_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_DSPR0 &= ~PDMIC_DSPR0_SHIFT(mask);
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_toggle_DSPR0_SHIFT_bf(const void *const hw, hri_pdmic_dspr0_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_DSPR0 ^= PDMIC_DSPR0_SHIFT(mask);
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_dspr0_reg_t hri_pdmic_read_DSPR0_SHIFT_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_DSPR0;
	tmp = (tmp & PDMIC_DSPR0_SHIFT_Msk) >> PDMIC_DSPR0_SHIFT_Pos;
	return tmp;
}

static inline void hri_pdmic_set_DSPR0_reg(const void *const hw, hri_pdmic_dspr0_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_DSPR0 |= mask;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_dspr0_reg_t hri_pdmic_get_DSPR0_reg(const void *const hw, hri_pdmic_dspr0_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_DSPR0;
	tmp &= mask;
	return tmp;
}

static inline void hri_pdmic_write_DSPR0_reg(const void *const hw, hri_pdmic_dspr0_reg_t data)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_DSPR0 = data;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_clear_DSPR0_reg(const void *const hw, hri_pdmic_dspr0_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_DSPR0 &= ~mask;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_toggle_DSPR0_reg(const void *const hw, hri_pdmic_dspr0_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_DSPR0 ^= mask;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_dspr0_reg_t hri_pdmic_read_DSPR0_reg(const void *const hw)
{
	return ((Pdmic *)hw)->PDMIC_DSPR0;
}

static inline void hri_pdmic_set_DSPR1_DGAIN_bf(const void *const hw, hri_pdmic_dspr1_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_DSPR1 |= PDMIC_DSPR1_DGAIN(mask);
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_dspr1_reg_t hri_pdmic_get_DSPR1_DGAIN_bf(const void *const hw, hri_pdmic_dspr1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_DSPR1;
	tmp = (tmp & PDMIC_DSPR1_DGAIN(mask)) >> PDMIC_DSPR1_DGAIN_Pos;
	return tmp;
}

static inline void hri_pdmic_write_DSPR1_DGAIN_bf(const void *const hw, hri_pdmic_dspr1_reg_t data)
{
	uint32_t tmp;
	PDMIC_CRITICAL_SECTION_ENTER();
	tmp = ((Pdmic *)hw)->PDMIC_DSPR1;
	tmp &= ~PDMIC_DSPR1_DGAIN_Msk;
	tmp |= PDMIC_DSPR1_DGAIN(data);
	((Pdmic *)hw)->PDMIC_DSPR1 = tmp;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_clear_DSPR1_DGAIN_bf(const void *const hw, hri_pdmic_dspr1_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_DSPR1 &= ~PDMIC_DSPR1_DGAIN(mask);
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_toggle_DSPR1_DGAIN_bf(const void *const hw, hri_pdmic_dspr1_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_DSPR1 ^= PDMIC_DSPR1_DGAIN(mask);
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_dspr1_reg_t hri_pdmic_read_DSPR1_DGAIN_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_DSPR1;
	tmp = (tmp & PDMIC_DSPR1_DGAIN_Msk) >> PDMIC_DSPR1_DGAIN_Pos;
	return tmp;
}

static inline void hri_pdmic_set_DSPR1_OFST_bf(const void *const hw, hri_pdmic_dspr1_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_DSPR1 |= PDMIC_DSPR1_OFST(mask);
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_dspr1_reg_t hri_pdmic_get_DSPR1_OFST_bf(const void *const hw, hri_pdmic_dspr1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_DSPR1;
	tmp = (tmp & PDMIC_DSPR1_OFST(mask)) >> PDMIC_DSPR1_OFST_Pos;
	return tmp;
}

static inline void hri_pdmic_write_DSPR1_OFST_bf(const void *const hw, hri_pdmic_dspr1_reg_t data)
{
	uint32_t tmp;
	PDMIC_CRITICAL_SECTION_ENTER();
	tmp = ((Pdmic *)hw)->PDMIC_DSPR1;
	tmp &= ~PDMIC_DSPR1_OFST_Msk;
	tmp |= PDMIC_DSPR1_OFST(data);
	((Pdmic *)hw)->PDMIC_DSPR1 = tmp;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_clear_DSPR1_OFST_bf(const void *const hw, hri_pdmic_dspr1_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_DSPR1 &= ~PDMIC_DSPR1_OFST(mask);
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_toggle_DSPR1_OFST_bf(const void *const hw, hri_pdmic_dspr1_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_DSPR1 ^= PDMIC_DSPR1_OFST(mask);
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_dspr1_reg_t hri_pdmic_read_DSPR1_OFST_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_DSPR1;
	tmp = (tmp & PDMIC_DSPR1_OFST_Msk) >> PDMIC_DSPR1_OFST_Pos;
	return tmp;
}

static inline void hri_pdmic_set_DSPR1_reg(const void *const hw, hri_pdmic_dspr1_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_DSPR1 |= mask;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_dspr1_reg_t hri_pdmic_get_DSPR1_reg(const void *const hw, hri_pdmic_dspr1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_DSPR1;
	tmp &= mask;
	return tmp;
}

static inline void hri_pdmic_write_DSPR1_reg(const void *const hw, hri_pdmic_dspr1_reg_t data)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_DSPR1 = data;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_clear_DSPR1_reg(const void *const hw, hri_pdmic_dspr1_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_DSPR1 &= ~mask;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_toggle_DSPR1_reg(const void *const hw, hri_pdmic_dspr1_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_DSPR1 ^= mask;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_dspr1_reg_t hri_pdmic_read_DSPR1_reg(const void *const hw)
{
	return ((Pdmic *)hw)->PDMIC_DSPR1;
}

static inline void hri_pdmic_set_WPMR_WPEN_bit(const void *const hw)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_WPMR |= PDMIC_WPMR_WPEN;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_pdmic_get_WPMR_WPEN_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_WPMR;
	tmp = (tmp & PDMIC_WPMR_WPEN) >> PDMIC_WPMR_WPEN_Pos;
	return (bool)tmp;
}

static inline void hri_pdmic_write_WPMR_WPEN_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	PDMIC_CRITICAL_SECTION_ENTER();
	tmp = ((Pdmic *)hw)->PDMIC_WPMR;
	tmp &= ~PDMIC_WPMR_WPEN;
	tmp |= value << PDMIC_WPMR_WPEN_Pos;
	((Pdmic *)hw)->PDMIC_WPMR = tmp;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_clear_WPMR_WPEN_bit(const void *const hw)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_WPMR &= ~PDMIC_WPMR_WPEN;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_toggle_WPMR_WPEN_bit(const void *const hw)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_WPMR ^= PDMIC_WPMR_WPEN;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_set_WPMR_WPKEY_bf(const void *const hw, hri_pdmic_wpmr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_WPMR |= PDMIC_WPMR_WPKEY(mask);
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_wpmr_reg_t hri_pdmic_get_WPMR_WPKEY_bf(const void *const hw, hri_pdmic_wpmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_WPMR;
	tmp = (tmp & PDMIC_WPMR_WPKEY(mask)) >> PDMIC_WPMR_WPKEY_Pos;
	return tmp;
}

static inline void hri_pdmic_write_WPMR_WPKEY_bf(const void *const hw, hri_pdmic_wpmr_reg_t data)
{
	uint32_t tmp;
	PDMIC_CRITICAL_SECTION_ENTER();
	tmp = ((Pdmic *)hw)->PDMIC_WPMR;
	tmp &= ~PDMIC_WPMR_WPKEY_Msk;
	tmp |= PDMIC_WPMR_WPKEY(data);
	((Pdmic *)hw)->PDMIC_WPMR = tmp;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_clear_WPMR_WPKEY_bf(const void *const hw, hri_pdmic_wpmr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_WPMR &= ~PDMIC_WPMR_WPKEY(mask);
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_toggle_WPMR_WPKEY_bf(const void *const hw, hri_pdmic_wpmr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_WPMR ^= PDMIC_WPMR_WPKEY(mask);
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_wpmr_reg_t hri_pdmic_read_WPMR_WPKEY_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_WPMR;
	tmp = (tmp & PDMIC_WPMR_WPKEY_Msk) >> PDMIC_WPMR_WPKEY_Pos;
	return tmp;
}

static inline void hri_pdmic_set_WPMR_reg(const void *const hw, hri_pdmic_wpmr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_WPMR |= mask;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_wpmr_reg_t hri_pdmic_get_WPMR_reg(const void *const hw, hri_pdmic_wpmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_WPMR;
	tmp &= mask;
	return tmp;
}

static inline void hri_pdmic_write_WPMR_reg(const void *const hw, hri_pdmic_wpmr_reg_t data)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_WPMR = data;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_clear_WPMR_reg(const void *const hw, hri_pdmic_wpmr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_WPMR &= ~mask;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_toggle_WPMR_reg(const void *const hw, hri_pdmic_wpmr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_WPMR ^= mask;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_wpmr_reg_t hri_pdmic_read_WPMR_reg(const void *const hw)
{
	return ((Pdmic *)hw)->PDMIC_WPMR;
}

static inline void hri_pdmic_set_RPR_RXPTR_bf(const void *const hw, hri_pdmic_rpr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_RPR |= PDMIC_RPR_RXPTR(mask);
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_rpr_reg_t hri_pdmic_get_RPR_RXPTR_bf(const void *const hw, hri_pdmic_rpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_RPR;
	tmp = (tmp & PDMIC_RPR_RXPTR(mask)) >> PDMIC_RPR_RXPTR_Pos;
	return tmp;
}

static inline void hri_pdmic_write_RPR_RXPTR_bf(const void *const hw, hri_pdmic_rpr_reg_t data)
{
	uint32_t tmp;
	PDMIC_CRITICAL_SECTION_ENTER();
	tmp = ((Pdmic *)hw)->PDMIC_RPR;
	tmp &= ~PDMIC_RPR_RXPTR_Msk;
	tmp |= PDMIC_RPR_RXPTR(data);
	((Pdmic *)hw)->PDMIC_RPR = tmp;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_clear_RPR_RXPTR_bf(const void *const hw, hri_pdmic_rpr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_RPR &= ~PDMIC_RPR_RXPTR(mask);
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_toggle_RPR_RXPTR_bf(const void *const hw, hri_pdmic_rpr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_RPR ^= PDMIC_RPR_RXPTR(mask);
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_rpr_reg_t hri_pdmic_read_RPR_RXPTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_RPR;
	tmp = (tmp & PDMIC_RPR_RXPTR_Msk) >> PDMIC_RPR_RXPTR_Pos;
	return tmp;
}

static inline void hri_pdmic_set_RPR_reg(const void *const hw, hri_pdmic_rpr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_RPR |= mask;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_rpr_reg_t hri_pdmic_get_RPR_reg(const void *const hw, hri_pdmic_rpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_RPR;
	tmp &= mask;
	return tmp;
}

static inline void hri_pdmic_write_RPR_reg(const void *const hw, hri_pdmic_rpr_reg_t data)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_RPR = data;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_clear_RPR_reg(const void *const hw, hri_pdmic_rpr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_RPR &= ~mask;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_toggle_RPR_reg(const void *const hw, hri_pdmic_rpr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_RPR ^= mask;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_rpr_reg_t hri_pdmic_read_RPR_reg(const void *const hw)
{
	return ((Pdmic *)hw)->PDMIC_RPR;
}

static inline void hri_pdmic_set_RCR_RXCTR_bf(const void *const hw, hri_pdmic_rcr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_RCR |= PDMIC_RCR_RXCTR(mask);
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_rcr_reg_t hri_pdmic_get_RCR_RXCTR_bf(const void *const hw, hri_pdmic_rcr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_RCR;
	tmp = (tmp & PDMIC_RCR_RXCTR(mask)) >> PDMIC_RCR_RXCTR_Pos;
	return tmp;
}

static inline void hri_pdmic_write_RCR_RXCTR_bf(const void *const hw, hri_pdmic_rcr_reg_t data)
{
	uint32_t tmp;
	PDMIC_CRITICAL_SECTION_ENTER();
	tmp = ((Pdmic *)hw)->PDMIC_RCR;
	tmp &= ~PDMIC_RCR_RXCTR_Msk;
	tmp |= PDMIC_RCR_RXCTR(data);
	((Pdmic *)hw)->PDMIC_RCR = tmp;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_clear_RCR_RXCTR_bf(const void *const hw, hri_pdmic_rcr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_RCR &= ~PDMIC_RCR_RXCTR(mask);
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_toggle_RCR_RXCTR_bf(const void *const hw, hri_pdmic_rcr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_RCR ^= PDMIC_RCR_RXCTR(mask);
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_rcr_reg_t hri_pdmic_read_RCR_RXCTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_RCR;
	tmp = (tmp & PDMIC_RCR_RXCTR_Msk) >> PDMIC_RCR_RXCTR_Pos;
	return tmp;
}

static inline void hri_pdmic_set_RCR_reg(const void *const hw, hri_pdmic_rcr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_RCR |= mask;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_rcr_reg_t hri_pdmic_get_RCR_reg(const void *const hw, hri_pdmic_rcr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_RCR;
	tmp &= mask;
	return tmp;
}

static inline void hri_pdmic_write_RCR_reg(const void *const hw, hri_pdmic_rcr_reg_t data)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_RCR = data;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_clear_RCR_reg(const void *const hw, hri_pdmic_rcr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_RCR &= ~mask;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_toggle_RCR_reg(const void *const hw, hri_pdmic_rcr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_RCR ^= mask;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_rcr_reg_t hri_pdmic_read_RCR_reg(const void *const hw)
{
	return ((Pdmic *)hw)->PDMIC_RCR;
}

static inline void hri_pdmic_set_RNPR_RXNPTR_bf(const void *const hw, hri_pdmic_rnpr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_RNPR |= PDMIC_RNPR_RXNPTR(mask);
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_rnpr_reg_t hri_pdmic_get_RNPR_RXNPTR_bf(const void *const hw, hri_pdmic_rnpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_RNPR;
	tmp = (tmp & PDMIC_RNPR_RXNPTR(mask)) >> PDMIC_RNPR_RXNPTR_Pos;
	return tmp;
}

static inline void hri_pdmic_write_RNPR_RXNPTR_bf(const void *const hw, hri_pdmic_rnpr_reg_t data)
{
	uint32_t tmp;
	PDMIC_CRITICAL_SECTION_ENTER();
	tmp = ((Pdmic *)hw)->PDMIC_RNPR;
	tmp &= ~PDMIC_RNPR_RXNPTR_Msk;
	tmp |= PDMIC_RNPR_RXNPTR(data);
	((Pdmic *)hw)->PDMIC_RNPR = tmp;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_clear_RNPR_RXNPTR_bf(const void *const hw, hri_pdmic_rnpr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_RNPR &= ~PDMIC_RNPR_RXNPTR(mask);
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_toggle_RNPR_RXNPTR_bf(const void *const hw, hri_pdmic_rnpr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_RNPR ^= PDMIC_RNPR_RXNPTR(mask);
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_rnpr_reg_t hri_pdmic_read_RNPR_RXNPTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_RNPR;
	tmp = (tmp & PDMIC_RNPR_RXNPTR_Msk) >> PDMIC_RNPR_RXNPTR_Pos;
	return tmp;
}

static inline void hri_pdmic_set_RNPR_reg(const void *const hw, hri_pdmic_rnpr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_RNPR |= mask;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_rnpr_reg_t hri_pdmic_get_RNPR_reg(const void *const hw, hri_pdmic_rnpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_RNPR;
	tmp &= mask;
	return tmp;
}

static inline void hri_pdmic_write_RNPR_reg(const void *const hw, hri_pdmic_rnpr_reg_t data)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_RNPR = data;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_clear_RNPR_reg(const void *const hw, hri_pdmic_rnpr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_RNPR &= ~mask;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_toggle_RNPR_reg(const void *const hw, hri_pdmic_rnpr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_RNPR ^= mask;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_rnpr_reg_t hri_pdmic_read_RNPR_reg(const void *const hw)
{
	return ((Pdmic *)hw)->PDMIC_RNPR;
}

static inline void hri_pdmic_set_RNCR_RXNCTR_bf(const void *const hw, hri_pdmic_rncr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_RNCR |= PDMIC_RNCR_RXNCTR(mask);
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_rncr_reg_t hri_pdmic_get_RNCR_RXNCTR_bf(const void *const hw, hri_pdmic_rncr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_RNCR;
	tmp = (tmp & PDMIC_RNCR_RXNCTR(mask)) >> PDMIC_RNCR_RXNCTR_Pos;
	return tmp;
}

static inline void hri_pdmic_write_RNCR_RXNCTR_bf(const void *const hw, hri_pdmic_rncr_reg_t data)
{
	uint32_t tmp;
	PDMIC_CRITICAL_SECTION_ENTER();
	tmp = ((Pdmic *)hw)->PDMIC_RNCR;
	tmp &= ~PDMIC_RNCR_RXNCTR_Msk;
	tmp |= PDMIC_RNCR_RXNCTR(data);
	((Pdmic *)hw)->PDMIC_RNCR = tmp;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_clear_RNCR_RXNCTR_bf(const void *const hw, hri_pdmic_rncr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_RNCR &= ~PDMIC_RNCR_RXNCTR(mask);
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_toggle_RNCR_RXNCTR_bf(const void *const hw, hri_pdmic_rncr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_RNCR ^= PDMIC_RNCR_RXNCTR(mask);
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_rncr_reg_t hri_pdmic_read_RNCR_RXNCTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_RNCR;
	tmp = (tmp & PDMIC_RNCR_RXNCTR_Msk) >> PDMIC_RNCR_RXNCTR_Pos;
	return tmp;
}

static inline void hri_pdmic_set_RNCR_reg(const void *const hw, hri_pdmic_rncr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_RNCR |= mask;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_rncr_reg_t hri_pdmic_get_RNCR_reg(const void *const hw, hri_pdmic_rncr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_RNCR;
	tmp &= mask;
	return tmp;
}

static inline void hri_pdmic_write_RNCR_reg(const void *const hw, hri_pdmic_rncr_reg_t data)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_RNCR = data;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_clear_RNCR_reg(const void *const hw, hri_pdmic_rncr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_RNCR &= ~mask;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdmic_toggle_RNCR_reg(const void *const hw, hri_pdmic_rncr_reg_t mask)
{
	PDMIC_CRITICAL_SECTION_ENTER();
	((Pdmic *)hw)->PDMIC_RNCR ^= mask;
	PDMIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdmic_rncr_reg_t hri_pdmic_read_RNCR_reg(const void *const hw)
{
	return ((Pdmic *)hw)->PDMIC_RNCR;
}

static inline hri_pdmic_cdr_reg_t hri_pdmic_get_CDR_DATA_bf(const void *const hw, hri_pdmic_cdr_reg_t mask)
{
	return (((Pdmic *)hw)->PDMIC_CDR & PDMIC_CDR_DATA(mask)) >> PDMIC_CDR_DATA_Pos;
}

static inline hri_pdmic_cdr_reg_t hri_pdmic_read_CDR_DATA_bf(const void *const hw)
{
	return (((Pdmic *)hw)->PDMIC_CDR & PDMIC_CDR_DATA_Msk) >> PDMIC_CDR_DATA_Pos;
}

static inline hri_pdmic_cdr_reg_t hri_pdmic_get_CDR_reg(const void *const hw, hri_pdmic_cdr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_CDR;
	tmp &= mask;
	return tmp;
}

static inline hri_pdmic_cdr_reg_t hri_pdmic_read_CDR_reg(const void *const hw)
{
	return ((Pdmic *)hw)->PDMIC_CDR;
}

static inline bool hri_pdmic_get_WPSR_WPVS_bit(const void *const hw)
{
	return (((Pdmic *)hw)->PDMIC_WPSR & PDMIC_WPSR_WPVS) > 0;
}

static inline hri_pdmic_wpsr_reg_t hri_pdmic_get_WPSR_WPVSRC_bf(const void *const hw, hri_pdmic_wpsr_reg_t mask)
{
	return (((Pdmic *)hw)->PDMIC_WPSR & PDMIC_WPSR_WPVSRC(mask)) >> PDMIC_WPSR_WPVSRC_Pos;
}

static inline hri_pdmic_wpsr_reg_t hri_pdmic_read_WPSR_WPVSRC_bf(const void *const hw)
{
	return (((Pdmic *)hw)->PDMIC_WPSR & PDMIC_WPSR_WPVSRC_Msk) >> PDMIC_WPSR_WPVSRC_Pos;
}

static inline hri_pdmic_wpsr_reg_t hri_pdmic_get_WPSR_reg(const void *const hw, hri_pdmic_wpsr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_WPSR;
	tmp &= mask;
	return tmp;
}

static inline hri_pdmic_wpsr_reg_t hri_pdmic_read_WPSR_reg(const void *const hw)
{
	return ((Pdmic *)hw)->PDMIC_WPSR;
}

static inline bool hri_pdmic_get_PTSR_RXTEN_bit(const void *const hw)
{
	return (((Pdmic *)hw)->PDMIC_PTSR & PDMIC_PTSR_RXTEN) > 0;
}

static inline bool hri_pdmic_get_PTSR_TXTEN_bit(const void *const hw)
{
	return (((Pdmic *)hw)->PDMIC_PTSR & PDMIC_PTSR_TXTEN) > 0;
}

static inline bool hri_pdmic_get_PTSR_RXCBEN_bit(const void *const hw)
{
	return (((Pdmic *)hw)->PDMIC_PTSR & PDMIC_PTSR_RXCBEN) > 0;
}

static inline bool hri_pdmic_get_PTSR_TXCBEN_bit(const void *const hw)
{
	return (((Pdmic *)hw)->PDMIC_PTSR & PDMIC_PTSR_TXCBEN) > 0;
}

static inline bool hri_pdmic_get_PTSR_ERR_bit(const void *const hw)
{
	return (((Pdmic *)hw)->PDMIC_PTSR & PDMIC_PTSR_ERR) > 0;
}

static inline hri_pdmic_ptsr_reg_t hri_pdmic_get_PTSR_reg(const void *const hw, hri_pdmic_ptsr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdmic *)hw)->PDMIC_PTSR;
	tmp &= mask;
	return tmp;
}

static inline hri_pdmic_ptsr_reg_t hri_pdmic_read_PTSR_reg(const void *const hw)
{
	return ((Pdmic *)hw)->PDMIC_PTSR;
}

#ifdef __cplusplus
}
#endif

#endif /* _HRI_PDMIC_G55_H_INCLUDED */
#endif /* _SAMG55_PDMIC_COMPONENT_ */
