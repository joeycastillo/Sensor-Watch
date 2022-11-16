/**
 * \file
 *
 * \brief SAM ADC
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

#ifdef _SAMG55_ADC_COMPONENT_
#ifndef _HRI_ADC_G55_H_INCLUDED_
#define _HRI_ADC_G55_H_INCLUDED_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <hal_atomic.h>

#if defined(ENABLE_ADC_CRITICAL_SECTIONS)
#define ADC_CRITICAL_SECTION_ENTER() CRITICAL_SECTION_ENTER()
#define ADC_CRITICAL_SECTION_LEAVE() CRITICAL_SECTION_LEAVE()
#else
#define ADC_CRITICAL_SECTION_ENTER()
#define ADC_CRITICAL_SECTION_LEAVE()
#endif

typedef uint32_t hri_adc_acr_reg_t;
typedef uint32_t hri_adc_cdr_reg_t;
typedef uint32_t hri_adc_chsr_reg_t;
typedef uint32_t hri_adc_cor_reg_t;
typedef uint32_t hri_adc_cr_reg_t;
typedef uint32_t hri_adc_cwr_reg_t;
typedef uint32_t hri_adc_emr_reg_t;
typedef uint32_t hri_adc_imr_reg_t;
typedef uint32_t hri_adc_isr_reg_t;
typedef uint32_t hri_adc_lccwr_reg_t;
typedef uint32_t hri_adc_lcdr_reg_t;
typedef uint32_t hri_adc_lctmr_reg_t;
typedef uint32_t hri_adc_mr_reg_t;
typedef uint32_t hri_adc_over_reg_t;
typedef uint32_t hri_adc_ptcr_reg_t;
typedef uint32_t hri_adc_ptsr_reg_t;
typedef uint32_t hri_adc_rcr_reg_t;
typedef uint32_t hri_adc_rncr_reg_t;
typedef uint32_t hri_adc_rnpr_reg_t;
typedef uint32_t hri_adc_rpr_reg_t;
typedef uint32_t hri_adc_seqr1_reg_t;
typedef uint32_t hri_adc_wpmr_reg_t;
typedef uint32_t hri_adc_wpsr_reg_t;

static inline void hri_adc_set_CHSR_CH0_bit(const void *const hw)
{
	((Adc *)hw)->ADC_CHER = ADC_CHSR_CH0;
}

static inline bool hri_adc_get_CHSR_CH0_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_CHSR & ADC_CHSR_CH0) >> ADC_CHSR_CH0_Pos;
}

static inline void hri_adc_write_CHSR_CH0_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Adc *)hw)->ADC_CHDR = ADC_CHSR_CH0;
	} else {
		((Adc *)hw)->ADC_CHER = ADC_CHSR_CH0;
	}
}

static inline void hri_adc_clear_CHSR_CH0_bit(const void *const hw)
{
	((Adc *)hw)->ADC_CHDR = ADC_CHSR_CH0;
}

static inline void hri_adc_set_CHSR_CH1_bit(const void *const hw)
{
	((Adc *)hw)->ADC_CHER = ADC_CHSR_CH1;
}

static inline bool hri_adc_get_CHSR_CH1_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_CHSR & ADC_CHSR_CH1) >> ADC_CHSR_CH1_Pos;
}

static inline void hri_adc_write_CHSR_CH1_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Adc *)hw)->ADC_CHDR = ADC_CHSR_CH1;
	} else {
		((Adc *)hw)->ADC_CHER = ADC_CHSR_CH1;
	}
}

static inline void hri_adc_clear_CHSR_CH1_bit(const void *const hw)
{
	((Adc *)hw)->ADC_CHDR = ADC_CHSR_CH1;
}

static inline void hri_adc_set_CHSR_CH2_bit(const void *const hw)
{
	((Adc *)hw)->ADC_CHER = ADC_CHSR_CH2;
}

static inline bool hri_adc_get_CHSR_CH2_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_CHSR & ADC_CHSR_CH2) >> ADC_CHSR_CH2_Pos;
}

static inline void hri_adc_write_CHSR_CH2_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Adc *)hw)->ADC_CHDR = ADC_CHSR_CH2;
	} else {
		((Adc *)hw)->ADC_CHER = ADC_CHSR_CH2;
	}
}

static inline void hri_adc_clear_CHSR_CH2_bit(const void *const hw)
{
	((Adc *)hw)->ADC_CHDR = ADC_CHSR_CH2;
}

static inline void hri_adc_set_CHSR_CH3_bit(const void *const hw)
{
	((Adc *)hw)->ADC_CHER = ADC_CHSR_CH3;
}

static inline bool hri_adc_get_CHSR_CH3_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_CHSR & ADC_CHSR_CH3) >> ADC_CHSR_CH3_Pos;
}

static inline void hri_adc_write_CHSR_CH3_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Adc *)hw)->ADC_CHDR = ADC_CHSR_CH3;
	} else {
		((Adc *)hw)->ADC_CHER = ADC_CHSR_CH3;
	}
}

static inline void hri_adc_clear_CHSR_CH3_bit(const void *const hw)
{
	((Adc *)hw)->ADC_CHDR = ADC_CHSR_CH3;
}

static inline void hri_adc_set_CHSR_CH4_bit(const void *const hw)
{
	((Adc *)hw)->ADC_CHER = ADC_CHSR_CH4;
}

static inline bool hri_adc_get_CHSR_CH4_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_CHSR & ADC_CHSR_CH4) >> ADC_CHSR_CH4_Pos;
}

static inline void hri_adc_write_CHSR_CH4_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Adc *)hw)->ADC_CHDR = ADC_CHSR_CH4;
	} else {
		((Adc *)hw)->ADC_CHER = ADC_CHSR_CH4;
	}
}

static inline void hri_adc_clear_CHSR_CH4_bit(const void *const hw)
{
	((Adc *)hw)->ADC_CHDR = ADC_CHSR_CH4;
}

static inline void hri_adc_set_CHSR_CH5_bit(const void *const hw)
{
	((Adc *)hw)->ADC_CHER = ADC_CHSR_CH5;
}

static inline bool hri_adc_get_CHSR_CH5_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_CHSR & ADC_CHSR_CH5) >> ADC_CHSR_CH5_Pos;
}

static inline void hri_adc_write_CHSR_CH5_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Adc *)hw)->ADC_CHDR = ADC_CHSR_CH5;
	} else {
		((Adc *)hw)->ADC_CHER = ADC_CHSR_CH5;
	}
}

static inline void hri_adc_clear_CHSR_CH5_bit(const void *const hw)
{
	((Adc *)hw)->ADC_CHDR = ADC_CHSR_CH5;
}

static inline void hri_adc_set_CHSR_CH6_bit(const void *const hw)
{
	((Adc *)hw)->ADC_CHER = ADC_CHSR_CH6;
}

static inline bool hri_adc_get_CHSR_CH6_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_CHSR & ADC_CHSR_CH6) >> ADC_CHSR_CH6_Pos;
}

static inline void hri_adc_write_CHSR_CH6_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Adc *)hw)->ADC_CHDR = ADC_CHSR_CH6;
	} else {
		((Adc *)hw)->ADC_CHER = ADC_CHSR_CH6;
	}
}

static inline void hri_adc_clear_CHSR_CH6_bit(const void *const hw)
{
	((Adc *)hw)->ADC_CHDR = ADC_CHSR_CH6;
}

static inline void hri_adc_set_CHSR_CH7_bit(const void *const hw)
{
	((Adc *)hw)->ADC_CHER = ADC_CHSR_CH7;
}

static inline bool hri_adc_get_CHSR_CH7_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_CHSR & ADC_CHSR_CH7) >> ADC_CHSR_CH7_Pos;
}

static inline void hri_adc_write_CHSR_CH7_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Adc *)hw)->ADC_CHDR = ADC_CHSR_CH7;
	} else {
		((Adc *)hw)->ADC_CHER = ADC_CHSR_CH7;
	}
}

static inline void hri_adc_clear_CHSR_CH7_bit(const void *const hw)
{
	((Adc *)hw)->ADC_CHDR = ADC_CHSR_CH7;
}

static inline void hri_adc_set_CHSR_reg(const void *const hw, hri_adc_chsr_reg_t mask)
{
	((Adc *)hw)->ADC_CHER = mask;
}

static inline hri_adc_chsr_reg_t hri_adc_get_CHSR_reg(const void *const hw, hri_adc_chsr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_CHSR;
	tmp &= mask;
	return tmp;
}

static inline hri_adc_chsr_reg_t hri_adc_read_CHSR_reg(const void *const hw)
{
	return ((Adc *)hw)->ADC_CHSR;
}

static inline void hri_adc_write_CHSR_reg(const void *const hw, hri_adc_chsr_reg_t data)
{
	((Adc *)hw)->ADC_CHER = data;
	((Adc *)hw)->ADC_CHDR = ~data;
}

static inline void hri_adc_clear_CHSR_reg(const void *const hw, hri_adc_chsr_reg_t mask)
{
	((Adc *)hw)->ADC_CHDR = mask;
}

static inline void hri_adc_set_IMR_EOC0_bit(const void *const hw)
{
	((Adc *)hw)->ADC_IER = ADC_IMR_EOC0;
}

static inline bool hri_adc_get_IMR_EOC0_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_IMR & ADC_IMR_EOC0) >> ADC_IMR_EOC0_Pos;
}

static inline void hri_adc_write_IMR_EOC0_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Adc *)hw)->ADC_IDR = ADC_IMR_EOC0;
	} else {
		((Adc *)hw)->ADC_IER = ADC_IMR_EOC0;
	}
}

static inline void hri_adc_clear_IMR_EOC0_bit(const void *const hw)
{
	((Adc *)hw)->ADC_IDR = ADC_IMR_EOC0;
}

static inline void hri_adc_set_IMR_EOC1_bit(const void *const hw)
{
	((Adc *)hw)->ADC_IER = ADC_IMR_EOC1;
}

static inline bool hri_adc_get_IMR_EOC1_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_IMR & ADC_IMR_EOC1) >> ADC_IMR_EOC1_Pos;
}

static inline void hri_adc_write_IMR_EOC1_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Adc *)hw)->ADC_IDR = ADC_IMR_EOC1;
	} else {
		((Adc *)hw)->ADC_IER = ADC_IMR_EOC1;
	}
}

static inline void hri_adc_clear_IMR_EOC1_bit(const void *const hw)
{
	((Adc *)hw)->ADC_IDR = ADC_IMR_EOC1;
}

static inline void hri_adc_set_IMR_EOC2_bit(const void *const hw)
{
	((Adc *)hw)->ADC_IER = ADC_IMR_EOC2;
}

static inline bool hri_adc_get_IMR_EOC2_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_IMR & ADC_IMR_EOC2) >> ADC_IMR_EOC2_Pos;
}

static inline void hri_adc_write_IMR_EOC2_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Adc *)hw)->ADC_IDR = ADC_IMR_EOC2;
	} else {
		((Adc *)hw)->ADC_IER = ADC_IMR_EOC2;
	}
}

static inline void hri_adc_clear_IMR_EOC2_bit(const void *const hw)
{
	((Adc *)hw)->ADC_IDR = ADC_IMR_EOC2;
}

static inline void hri_adc_set_IMR_EOC3_bit(const void *const hw)
{
	((Adc *)hw)->ADC_IER = ADC_IMR_EOC3;
}

static inline bool hri_adc_get_IMR_EOC3_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_IMR & ADC_IMR_EOC3) >> ADC_IMR_EOC3_Pos;
}

static inline void hri_adc_write_IMR_EOC3_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Adc *)hw)->ADC_IDR = ADC_IMR_EOC3;
	} else {
		((Adc *)hw)->ADC_IER = ADC_IMR_EOC3;
	}
}

static inline void hri_adc_clear_IMR_EOC3_bit(const void *const hw)
{
	((Adc *)hw)->ADC_IDR = ADC_IMR_EOC3;
}

static inline void hri_adc_set_IMR_EOC4_bit(const void *const hw)
{
	((Adc *)hw)->ADC_IER = ADC_IMR_EOC4;
}

static inline bool hri_adc_get_IMR_EOC4_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_IMR & ADC_IMR_EOC4) >> ADC_IMR_EOC4_Pos;
}

static inline void hri_adc_write_IMR_EOC4_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Adc *)hw)->ADC_IDR = ADC_IMR_EOC4;
	} else {
		((Adc *)hw)->ADC_IER = ADC_IMR_EOC4;
	}
}

static inline void hri_adc_clear_IMR_EOC4_bit(const void *const hw)
{
	((Adc *)hw)->ADC_IDR = ADC_IMR_EOC4;
}

static inline void hri_adc_set_IMR_EOC5_bit(const void *const hw)
{
	((Adc *)hw)->ADC_IER = ADC_IMR_EOC5;
}

static inline bool hri_adc_get_IMR_EOC5_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_IMR & ADC_IMR_EOC5) >> ADC_IMR_EOC5_Pos;
}

static inline void hri_adc_write_IMR_EOC5_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Adc *)hw)->ADC_IDR = ADC_IMR_EOC5;
	} else {
		((Adc *)hw)->ADC_IER = ADC_IMR_EOC5;
	}
}

static inline void hri_adc_clear_IMR_EOC5_bit(const void *const hw)
{
	((Adc *)hw)->ADC_IDR = ADC_IMR_EOC5;
}

static inline void hri_adc_set_IMR_EOC6_bit(const void *const hw)
{
	((Adc *)hw)->ADC_IER = ADC_IMR_EOC6;
}

static inline bool hri_adc_get_IMR_EOC6_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_IMR & ADC_IMR_EOC6) >> ADC_IMR_EOC6_Pos;
}

static inline void hri_adc_write_IMR_EOC6_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Adc *)hw)->ADC_IDR = ADC_IMR_EOC6;
	} else {
		((Adc *)hw)->ADC_IER = ADC_IMR_EOC6;
	}
}

static inline void hri_adc_clear_IMR_EOC6_bit(const void *const hw)
{
	((Adc *)hw)->ADC_IDR = ADC_IMR_EOC6;
}

static inline void hri_adc_set_IMR_EOC7_bit(const void *const hw)
{
	((Adc *)hw)->ADC_IER = ADC_IMR_EOC7;
}

static inline bool hri_adc_get_IMR_EOC7_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_IMR & ADC_IMR_EOC7) >> ADC_IMR_EOC7_Pos;
}

static inline void hri_adc_write_IMR_EOC7_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Adc *)hw)->ADC_IDR = ADC_IMR_EOC7;
	} else {
		((Adc *)hw)->ADC_IER = ADC_IMR_EOC7;
	}
}

static inline void hri_adc_clear_IMR_EOC7_bit(const void *const hw)
{
	((Adc *)hw)->ADC_IDR = ADC_IMR_EOC7;
}

static inline void hri_adc_set_IMR_LCCHG_bit(const void *const hw)
{
	((Adc *)hw)->ADC_IER = ADC_IMR_LCCHG;
}

static inline bool hri_adc_get_IMR_LCCHG_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_IMR & ADC_IMR_LCCHG) >> ADC_IMR_LCCHG_Pos;
}

static inline void hri_adc_write_IMR_LCCHG_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Adc *)hw)->ADC_IDR = ADC_IMR_LCCHG;
	} else {
		((Adc *)hw)->ADC_IER = ADC_IMR_LCCHG;
	}
}

static inline void hri_adc_clear_IMR_LCCHG_bit(const void *const hw)
{
	((Adc *)hw)->ADC_IDR = ADC_IMR_LCCHG;
}

static inline void hri_adc_set_IMR_DRDY_bit(const void *const hw)
{
	((Adc *)hw)->ADC_IER = ADC_IMR_DRDY;
}

static inline bool hri_adc_get_IMR_DRDY_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_IMR & ADC_IMR_DRDY) >> ADC_IMR_DRDY_Pos;
}

static inline void hri_adc_write_IMR_DRDY_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Adc *)hw)->ADC_IDR = ADC_IMR_DRDY;
	} else {
		((Adc *)hw)->ADC_IER = ADC_IMR_DRDY;
	}
}

static inline void hri_adc_clear_IMR_DRDY_bit(const void *const hw)
{
	((Adc *)hw)->ADC_IDR = ADC_IMR_DRDY;
}

static inline void hri_adc_set_IMR_GOVRE_bit(const void *const hw)
{
	((Adc *)hw)->ADC_IER = ADC_IMR_GOVRE;
}

static inline bool hri_adc_get_IMR_GOVRE_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_IMR & ADC_IMR_GOVRE) >> ADC_IMR_GOVRE_Pos;
}

static inline void hri_adc_write_IMR_GOVRE_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Adc *)hw)->ADC_IDR = ADC_IMR_GOVRE;
	} else {
		((Adc *)hw)->ADC_IER = ADC_IMR_GOVRE;
	}
}

static inline void hri_adc_clear_IMR_GOVRE_bit(const void *const hw)
{
	((Adc *)hw)->ADC_IDR = ADC_IMR_GOVRE;
}

static inline void hri_adc_set_IMR_COMPE_bit(const void *const hw)
{
	((Adc *)hw)->ADC_IER = ADC_IMR_COMPE;
}

static inline bool hri_adc_get_IMR_COMPE_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_IMR & ADC_IMR_COMPE) >> ADC_IMR_COMPE_Pos;
}

static inline void hri_adc_write_IMR_COMPE_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Adc *)hw)->ADC_IDR = ADC_IMR_COMPE;
	} else {
		((Adc *)hw)->ADC_IER = ADC_IMR_COMPE;
	}
}

static inline void hri_adc_clear_IMR_COMPE_bit(const void *const hw)
{
	((Adc *)hw)->ADC_IDR = ADC_IMR_COMPE;
}

static inline void hri_adc_set_IMR_ENDRX_bit(const void *const hw)
{
	((Adc *)hw)->ADC_IER = ADC_IMR_ENDRX;
}

static inline bool hri_adc_get_IMR_ENDRX_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_IMR & ADC_IMR_ENDRX) >> ADC_IMR_ENDRX_Pos;
}

static inline void hri_adc_write_IMR_ENDRX_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Adc *)hw)->ADC_IDR = ADC_IMR_ENDRX;
	} else {
		((Adc *)hw)->ADC_IER = ADC_IMR_ENDRX;
	}
}

static inline void hri_adc_clear_IMR_ENDRX_bit(const void *const hw)
{
	((Adc *)hw)->ADC_IDR = ADC_IMR_ENDRX;
}

static inline void hri_adc_set_IMR_RXBUFF_bit(const void *const hw)
{
	((Adc *)hw)->ADC_IER = ADC_IMR_RXBUFF;
}

static inline bool hri_adc_get_IMR_RXBUFF_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_IMR & ADC_IMR_RXBUFF) >> ADC_IMR_RXBUFF_Pos;
}

static inline void hri_adc_write_IMR_RXBUFF_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Adc *)hw)->ADC_IDR = ADC_IMR_RXBUFF;
	} else {
		((Adc *)hw)->ADC_IER = ADC_IMR_RXBUFF;
	}
}

static inline void hri_adc_clear_IMR_RXBUFF_bit(const void *const hw)
{
	((Adc *)hw)->ADC_IDR = ADC_IMR_RXBUFF;
}

static inline void hri_adc_set_IMR_reg(const void *const hw, hri_adc_imr_reg_t mask)
{
	((Adc *)hw)->ADC_IER = mask;
}

static inline hri_adc_imr_reg_t hri_adc_get_IMR_reg(const void *const hw, hri_adc_imr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_IMR;
	tmp &= mask;
	return tmp;
}

static inline hri_adc_imr_reg_t hri_adc_read_IMR_reg(const void *const hw)
{
	return ((Adc *)hw)->ADC_IMR;
}

static inline void hri_adc_write_IMR_reg(const void *const hw, hri_adc_imr_reg_t data)
{
	((Adc *)hw)->ADC_IER = data;
	((Adc *)hw)->ADC_IDR = ~data;
}

static inline void hri_adc_clear_IMR_reg(const void *const hw, hri_adc_imr_reg_t mask)
{
	((Adc *)hw)->ADC_IDR = mask;
}

static inline bool hri_adc_get_ISR_EOC0_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_ISR & ADC_ISR_EOC0) >> ADC_ISR_EOC0_Pos;
}

static inline bool hri_adc_get_ISR_EOC1_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_ISR & ADC_ISR_EOC1) >> ADC_ISR_EOC1_Pos;
}

static inline bool hri_adc_get_ISR_EOC2_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_ISR & ADC_ISR_EOC2) >> ADC_ISR_EOC2_Pos;
}

static inline bool hri_adc_get_ISR_EOC3_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_ISR & ADC_ISR_EOC3) >> ADC_ISR_EOC3_Pos;
}

static inline bool hri_adc_get_ISR_EOC4_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_ISR & ADC_ISR_EOC4) >> ADC_ISR_EOC4_Pos;
}

static inline bool hri_adc_get_ISR_EOC5_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_ISR & ADC_ISR_EOC5) >> ADC_ISR_EOC5_Pos;
}

static inline bool hri_adc_get_ISR_EOC6_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_ISR & ADC_ISR_EOC6) >> ADC_ISR_EOC6_Pos;
}

static inline bool hri_adc_get_ISR_EOC7_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_ISR & ADC_ISR_EOC7) >> ADC_ISR_EOC7_Pos;
}

static inline bool hri_adc_get_ISR_LCCHG_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_ISR & ADC_ISR_LCCHG) >> ADC_ISR_LCCHG_Pos;
}

static inline bool hri_adc_get_ISR_DRDY_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_ISR & ADC_ISR_DRDY) >> ADC_ISR_DRDY_Pos;
}

static inline bool hri_adc_get_ISR_GOVRE_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_ISR & ADC_ISR_GOVRE) >> ADC_ISR_GOVRE_Pos;
}

static inline bool hri_adc_get_ISR_COMPE_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_ISR & ADC_ISR_COMPE) >> ADC_ISR_COMPE_Pos;
}

static inline bool hri_adc_get_ISR_ENDRX_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_ISR & ADC_ISR_ENDRX) >> ADC_ISR_ENDRX_Pos;
}

static inline bool hri_adc_get_ISR_RXBUFF_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_ISR & ADC_ISR_RXBUFF) >> ADC_ISR_RXBUFF_Pos;
}

static inline hri_adc_isr_reg_t hri_adc_get_ISR_reg(const void *const hw, hri_adc_isr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_ISR;
	tmp &= mask;
	return tmp;
}

static inline hri_adc_isr_reg_t hri_adc_read_ISR_reg(const void *const hw)
{
	return ((Adc *)hw)->ADC_ISR;
}

static inline void hri_adc_write_CR_reg(const void *const hw, hri_adc_cr_reg_t data)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_CR = data;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_write_PTCR_reg(const void *const hw, hri_adc_ptcr_reg_t data)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_PTCR = data;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_set_MR_TRGEN_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR |= ADC_MR_TRGEN;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_adc_get_MR_TRGEN_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_MR;
	tmp = (tmp & ADC_MR_TRGEN) >> ADC_MR_TRGEN_Pos;
	return (bool)tmp;
}

static inline void hri_adc_write_MR_TRGEN_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_MR;
	tmp &= ~ADC_MR_TRGEN;
	tmp |= value << ADC_MR_TRGEN_Pos;
	((Adc *)hw)->ADC_MR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_MR_TRGEN_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR &= ~ADC_MR_TRGEN;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_MR_TRGEN_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR ^= ADC_MR_TRGEN;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_set_MR_SLEEP_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR |= ADC_MR_SLEEP;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_adc_get_MR_SLEEP_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_MR;
	tmp = (tmp & ADC_MR_SLEEP) >> ADC_MR_SLEEP_Pos;
	return (bool)tmp;
}

static inline void hri_adc_write_MR_SLEEP_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_MR;
	tmp &= ~ADC_MR_SLEEP;
	tmp |= value << ADC_MR_SLEEP_Pos;
	((Adc *)hw)->ADC_MR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_MR_SLEEP_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR &= ~ADC_MR_SLEEP;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_MR_SLEEP_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR ^= ADC_MR_SLEEP;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_set_MR_FWUP_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR |= ADC_MR_FWUP;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_adc_get_MR_FWUP_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_MR;
	tmp = (tmp & ADC_MR_FWUP) >> ADC_MR_FWUP_Pos;
	return (bool)tmp;
}

static inline void hri_adc_write_MR_FWUP_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_MR;
	tmp &= ~ADC_MR_FWUP;
	tmp |= value << ADC_MR_FWUP_Pos;
	((Adc *)hw)->ADC_MR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_MR_FWUP_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR &= ~ADC_MR_FWUP;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_MR_FWUP_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR ^= ADC_MR_FWUP;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_set_MR_FREERUN_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR |= ADC_MR_FREERUN;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_adc_get_MR_FREERUN_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_MR;
	tmp = (tmp & ADC_MR_FREERUN) >> ADC_MR_FREERUN_Pos;
	return (bool)tmp;
}

static inline void hri_adc_write_MR_FREERUN_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_MR;
	tmp &= ~ADC_MR_FREERUN;
	tmp |= value << ADC_MR_FREERUN_Pos;
	((Adc *)hw)->ADC_MR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_MR_FREERUN_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR &= ~ADC_MR_FREERUN;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_MR_FREERUN_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR ^= ADC_MR_FREERUN;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_set_MR_ANACH_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR |= ADC_MR_ANACH;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_adc_get_MR_ANACH_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_MR;
	tmp = (tmp & ADC_MR_ANACH) >> ADC_MR_ANACH_Pos;
	return (bool)tmp;
}

static inline void hri_adc_write_MR_ANACH_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_MR;
	tmp &= ~ADC_MR_ANACH;
	tmp |= value << ADC_MR_ANACH_Pos;
	((Adc *)hw)->ADC_MR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_MR_ANACH_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR &= ~ADC_MR_ANACH;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_MR_ANACH_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR ^= ADC_MR_ANACH;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_set_MR_USEQ_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR |= ADC_MR_USEQ;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_adc_get_MR_USEQ_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_MR;
	tmp = (tmp & ADC_MR_USEQ) >> ADC_MR_USEQ_Pos;
	return (bool)tmp;
}

static inline void hri_adc_write_MR_USEQ_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_MR;
	tmp &= ~ADC_MR_USEQ;
	tmp |= value << ADC_MR_USEQ_Pos;
	((Adc *)hw)->ADC_MR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_MR_USEQ_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR &= ~ADC_MR_USEQ;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_MR_USEQ_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR ^= ADC_MR_USEQ;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_set_MR_TRGSEL_bf(const void *const hw, hri_adc_mr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR |= ADC_MR_TRGSEL(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_mr_reg_t hri_adc_get_MR_TRGSEL_bf(const void *const hw, hri_adc_mr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_MR;
	tmp = (tmp & ADC_MR_TRGSEL(mask)) >> ADC_MR_TRGSEL_Pos;
	return tmp;
}

static inline void hri_adc_write_MR_TRGSEL_bf(const void *const hw, hri_adc_mr_reg_t data)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_MR;
	tmp &= ~ADC_MR_TRGSEL_Msk;
	tmp |= ADC_MR_TRGSEL(data);
	((Adc *)hw)->ADC_MR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_MR_TRGSEL_bf(const void *const hw, hri_adc_mr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR &= ~ADC_MR_TRGSEL(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_MR_TRGSEL_bf(const void *const hw, hri_adc_mr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR ^= ADC_MR_TRGSEL(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_mr_reg_t hri_adc_read_MR_TRGSEL_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_MR;
	tmp = (tmp & ADC_MR_TRGSEL_Msk) >> ADC_MR_TRGSEL_Pos;
	return tmp;
}

static inline void hri_adc_set_MR_PRESCAL_bf(const void *const hw, hri_adc_mr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR |= ADC_MR_PRESCAL(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_mr_reg_t hri_adc_get_MR_PRESCAL_bf(const void *const hw, hri_adc_mr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_MR;
	tmp = (tmp & ADC_MR_PRESCAL(mask)) >> ADC_MR_PRESCAL_Pos;
	return tmp;
}

static inline void hri_adc_write_MR_PRESCAL_bf(const void *const hw, hri_adc_mr_reg_t data)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_MR;
	tmp &= ~ADC_MR_PRESCAL_Msk;
	tmp |= ADC_MR_PRESCAL(data);
	((Adc *)hw)->ADC_MR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_MR_PRESCAL_bf(const void *const hw, hri_adc_mr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR &= ~ADC_MR_PRESCAL(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_MR_PRESCAL_bf(const void *const hw, hri_adc_mr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR ^= ADC_MR_PRESCAL(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_mr_reg_t hri_adc_read_MR_PRESCAL_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_MR;
	tmp = (tmp & ADC_MR_PRESCAL_Msk) >> ADC_MR_PRESCAL_Pos;
	return tmp;
}

static inline void hri_adc_set_MR_STARTUP_bf(const void *const hw, hri_adc_mr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR |= ADC_MR_STARTUP(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_mr_reg_t hri_adc_get_MR_STARTUP_bf(const void *const hw, hri_adc_mr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_MR;
	tmp = (tmp & ADC_MR_STARTUP(mask)) >> ADC_MR_STARTUP_Pos;
	return tmp;
}

static inline void hri_adc_write_MR_STARTUP_bf(const void *const hw, hri_adc_mr_reg_t data)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_MR;
	tmp &= ~ADC_MR_STARTUP_Msk;
	tmp |= ADC_MR_STARTUP(data);
	((Adc *)hw)->ADC_MR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_MR_STARTUP_bf(const void *const hw, hri_adc_mr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR &= ~ADC_MR_STARTUP(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_MR_STARTUP_bf(const void *const hw, hri_adc_mr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR ^= ADC_MR_STARTUP(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_mr_reg_t hri_adc_read_MR_STARTUP_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_MR;
	tmp = (tmp & ADC_MR_STARTUP_Msk) >> ADC_MR_STARTUP_Pos;
	return tmp;
}

static inline void hri_adc_set_MR_SETTLING_bf(const void *const hw, hri_adc_mr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR |= ADC_MR_SETTLING(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_mr_reg_t hri_adc_get_MR_SETTLING_bf(const void *const hw, hri_adc_mr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_MR;
	tmp = (tmp & ADC_MR_SETTLING(mask)) >> ADC_MR_SETTLING_Pos;
	return tmp;
}

static inline void hri_adc_write_MR_SETTLING_bf(const void *const hw, hri_adc_mr_reg_t data)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_MR;
	tmp &= ~ADC_MR_SETTLING_Msk;
	tmp |= ADC_MR_SETTLING(data);
	((Adc *)hw)->ADC_MR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_MR_SETTLING_bf(const void *const hw, hri_adc_mr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR &= ~ADC_MR_SETTLING(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_MR_SETTLING_bf(const void *const hw, hri_adc_mr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR ^= ADC_MR_SETTLING(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_mr_reg_t hri_adc_read_MR_SETTLING_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_MR;
	tmp = (tmp & ADC_MR_SETTLING_Msk) >> ADC_MR_SETTLING_Pos;
	return tmp;
}

static inline void hri_adc_set_MR_TRACKTIM_bf(const void *const hw, hri_adc_mr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR |= ADC_MR_TRACKTIM(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_mr_reg_t hri_adc_get_MR_TRACKTIM_bf(const void *const hw, hri_adc_mr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_MR;
	tmp = (tmp & ADC_MR_TRACKTIM(mask)) >> ADC_MR_TRACKTIM_Pos;
	return tmp;
}

static inline void hri_adc_write_MR_TRACKTIM_bf(const void *const hw, hri_adc_mr_reg_t data)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_MR;
	tmp &= ~ADC_MR_TRACKTIM_Msk;
	tmp |= ADC_MR_TRACKTIM(data);
	((Adc *)hw)->ADC_MR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_MR_TRACKTIM_bf(const void *const hw, hri_adc_mr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR &= ~ADC_MR_TRACKTIM(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_MR_TRACKTIM_bf(const void *const hw, hri_adc_mr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR ^= ADC_MR_TRACKTIM(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_mr_reg_t hri_adc_read_MR_TRACKTIM_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_MR;
	tmp = (tmp & ADC_MR_TRACKTIM_Msk) >> ADC_MR_TRACKTIM_Pos;
	return tmp;
}

static inline void hri_adc_set_MR_TRANSFER_bf(const void *const hw, hri_adc_mr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR |= ADC_MR_TRANSFER(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_mr_reg_t hri_adc_get_MR_TRANSFER_bf(const void *const hw, hri_adc_mr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_MR;
	tmp = (tmp & ADC_MR_TRANSFER(mask)) >> ADC_MR_TRANSFER_Pos;
	return tmp;
}

static inline void hri_adc_write_MR_TRANSFER_bf(const void *const hw, hri_adc_mr_reg_t data)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_MR;
	tmp &= ~ADC_MR_TRANSFER_Msk;
	tmp |= ADC_MR_TRANSFER(data);
	((Adc *)hw)->ADC_MR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_MR_TRANSFER_bf(const void *const hw, hri_adc_mr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR &= ~ADC_MR_TRANSFER(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_MR_TRANSFER_bf(const void *const hw, hri_adc_mr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR ^= ADC_MR_TRANSFER(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_mr_reg_t hri_adc_read_MR_TRANSFER_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_MR;
	tmp = (tmp & ADC_MR_TRANSFER_Msk) >> ADC_MR_TRANSFER_Pos;
	return tmp;
}

static inline void hri_adc_set_MR_reg(const void *const hw, hri_adc_mr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR |= mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_mr_reg_t hri_adc_get_MR_reg(const void *const hw, hri_adc_mr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_MR;
	tmp &= mask;
	return tmp;
}

static inline void hri_adc_write_MR_reg(const void *const hw, hri_adc_mr_reg_t data)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR = data;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_MR_reg(const void *const hw, hri_adc_mr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR &= ~mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_MR_reg(const void *const hw, hri_adc_mr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_MR ^= mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_mr_reg_t hri_adc_read_MR_reg(const void *const hw)
{
	return ((Adc *)hw)->ADC_MR;
}

static inline void hri_adc_set_SEQR1_USCH1_bf(const void *const hw, hri_adc_seqr1_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_SEQR1 |= ADC_SEQR1_USCH1(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_seqr1_reg_t hri_adc_get_SEQR1_USCH1_bf(const void *const hw, hri_adc_seqr1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_SEQR1;
	tmp = (tmp & ADC_SEQR1_USCH1(mask)) >> ADC_SEQR1_USCH1_Pos;
	return tmp;
}

static inline void hri_adc_write_SEQR1_USCH1_bf(const void *const hw, hri_adc_seqr1_reg_t data)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_SEQR1;
	tmp &= ~ADC_SEQR1_USCH1_Msk;
	tmp |= ADC_SEQR1_USCH1(data);
	((Adc *)hw)->ADC_SEQR1 = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_SEQR1_USCH1_bf(const void *const hw, hri_adc_seqr1_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_SEQR1 &= ~ADC_SEQR1_USCH1(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_SEQR1_USCH1_bf(const void *const hw, hri_adc_seqr1_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_SEQR1 ^= ADC_SEQR1_USCH1(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_seqr1_reg_t hri_adc_read_SEQR1_USCH1_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_SEQR1;
	tmp = (tmp & ADC_SEQR1_USCH1_Msk) >> ADC_SEQR1_USCH1_Pos;
	return tmp;
}

static inline void hri_adc_set_SEQR1_USCH2_bf(const void *const hw, hri_adc_seqr1_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_SEQR1 |= ADC_SEQR1_USCH2(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_seqr1_reg_t hri_adc_get_SEQR1_USCH2_bf(const void *const hw, hri_adc_seqr1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_SEQR1;
	tmp = (tmp & ADC_SEQR1_USCH2(mask)) >> ADC_SEQR1_USCH2_Pos;
	return tmp;
}

static inline void hri_adc_write_SEQR1_USCH2_bf(const void *const hw, hri_adc_seqr1_reg_t data)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_SEQR1;
	tmp &= ~ADC_SEQR1_USCH2_Msk;
	tmp |= ADC_SEQR1_USCH2(data);
	((Adc *)hw)->ADC_SEQR1 = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_SEQR1_USCH2_bf(const void *const hw, hri_adc_seqr1_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_SEQR1 &= ~ADC_SEQR1_USCH2(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_SEQR1_USCH2_bf(const void *const hw, hri_adc_seqr1_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_SEQR1 ^= ADC_SEQR1_USCH2(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_seqr1_reg_t hri_adc_read_SEQR1_USCH2_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_SEQR1;
	tmp = (tmp & ADC_SEQR1_USCH2_Msk) >> ADC_SEQR1_USCH2_Pos;
	return tmp;
}

static inline void hri_adc_set_SEQR1_USCH3_bf(const void *const hw, hri_adc_seqr1_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_SEQR1 |= ADC_SEQR1_USCH3(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_seqr1_reg_t hri_adc_get_SEQR1_USCH3_bf(const void *const hw, hri_adc_seqr1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_SEQR1;
	tmp = (tmp & ADC_SEQR1_USCH3(mask)) >> ADC_SEQR1_USCH3_Pos;
	return tmp;
}

static inline void hri_adc_write_SEQR1_USCH3_bf(const void *const hw, hri_adc_seqr1_reg_t data)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_SEQR1;
	tmp &= ~ADC_SEQR1_USCH3_Msk;
	tmp |= ADC_SEQR1_USCH3(data);
	((Adc *)hw)->ADC_SEQR1 = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_SEQR1_USCH3_bf(const void *const hw, hri_adc_seqr1_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_SEQR1 &= ~ADC_SEQR1_USCH3(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_SEQR1_USCH3_bf(const void *const hw, hri_adc_seqr1_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_SEQR1 ^= ADC_SEQR1_USCH3(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_seqr1_reg_t hri_adc_read_SEQR1_USCH3_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_SEQR1;
	tmp = (tmp & ADC_SEQR1_USCH3_Msk) >> ADC_SEQR1_USCH3_Pos;
	return tmp;
}

static inline void hri_adc_set_SEQR1_USCH4_bf(const void *const hw, hri_adc_seqr1_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_SEQR1 |= ADC_SEQR1_USCH4(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_seqr1_reg_t hri_adc_get_SEQR1_USCH4_bf(const void *const hw, hri_adc_seqr1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_SEQR1;
	tmp = (tmp & ADC_SEQR1_USCH4(mask)) >> ADC_SEQR1_USCH4_Pos;
	return tmp;
}

static inline void hri_adc_write_SEQR1_USCH4_bf(const void *const hw, hri_adc_seqr1_reg_t data)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_SEQR1;
	tmp &= ~ADC_SEQR1_USCH4_Msk;
	tmp |= ADC_SEQR1_USCH4(data);
	((Adc *)hw)->ADC_SEQR1 = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_SEQR1_USCH4_bf(const void *const hw, hri_adc_seqr1_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_SEQR1 &= ~ADC_SEQR1_USCH4(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_SEQR1_USCH4_bf(const void *const hw, hri_adc_seqr1_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_SEQR1 ^= ADC_SEQR1_USCH4(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_seqr1_reg_t hri_adc_read_SEQR1_USCH4_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_SEQR1;
	tmp = (tmp & ADC_SEQR1_USCH4_Msk) >> ADC_SEQR1_USCH4_Pos;
	return tmp;
}

static inline void hri_adc_set_SEQR1_USCH5_bf(const void *const hw, hri_adc_seqr1_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_SEQR1 |= ADC_SEQR1_USCH5(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_seqr1_reg_t hri_adc_get_SEQR1_USCH5_bf(const void *const hw, hri_adc_seqr1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_SEQR1;
	tmp = (tmp & ADC_SEQR1_USCH5(mask)) >> ADC_SEQR1_USCH5_Pos;
	return tmp;
}

static inline void hri_adc_write_SEQR1_USCH5_bf(const void *const hw, hri_adc_seqr1_reg_t data)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_SEQR1;
	tmp &= ~ADC_SEQR1_USCH5_Msk;
	tmp |= ADC_SEQR1_USCH5(data);
	((Adc *)hw)->ADC_SEQR1 = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_SEQR1_USCH5_bf(const void *const hw, hri_adc_seqr1_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_SEQR1 &= ~ADC_SEQR1_USCH5(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_SEQR1_USCH5_bf(const void *const hw, hri_adc_seqr1_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_SEQR1 ^= ADC_SEQR1_USCH5(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_seqr1_reg_t hri_adc_read_SEQR1_USCH5_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_SEQR1;
	tmp = (tmp & ADC_SEQR1_USCH5_Msk) >> ADC_SEQR1_USCH5_Pos;
	return tmp;
}

static inline void hri_adc_set_SEQR1_USCH6_bf(const void *const hw, hri_adc_seqr1_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_SEQR1 |= ADC_SEQR1_USCH6(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_seqr1_reg_t hri_adc_get_SEQR1_USCH6_bf(const void *const hw, hri_adc_seqr1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_SEQR1;
	tmp = (tmp & ADC_SEQR1_USCH6(mask)) >> ADC_SEQR1_USCH6_Pos;
	return tmp;
}

static inline void hri_adc_write_SEQR1_USCH6_bf(const void *const hw, hri_adc_seqr1_reg_t data)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_SEQR1;
	tmp &= ~ADC_SEQR1_USCH6_Msk;
	tmp |= ADC_SEQR1_USCH6(data);
	((Adc *)hw)->ADC_SEQR1 = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_SEQR1_USCH6_bf(const void *const hw, hri_adc_seqr1_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_SEQR1 &= ~ADC_SEQR1_USCH6(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_SEQR1_USCH6_bf(const void *const hw, hri_adc_seqr1_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_SEQR1 ^= ADC_SEQR1_USCH6(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_seqr1_reg_t hri_adc_read_SEQR1_USCH6_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_SEQR1;
	tmp = (tmp & ADC_SEQR1_USCH6_Msk) >> ADC_SEQR1_USCH6_Pos;
	return tmp;
}

static inline void hri_adc_set_SEQR1_USCH7_bf(const void *const hw, hri_adc_seqr1_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_SEQR1 |= ADC_SEQR1_USCH7(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_seqr1_reg_t hri_adc_get_SEQR1_USCH7_bf(const void *const hw, hri_adc_seqr1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_SEQR1;
	tmp = (tmp & ADC_SEQR1_USCH7(mask)) >> ADC_SEQR1_USCH7_Pos;
	return tmp;
}

static inline void hri_adc_write_SEQR1_USCH7_bf(const void *const hw, hri_adc_seqr1_reg_t data)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_SEQR1;
	tmp &= ~ADC_SEQR1_USCH7_Msk;
	tmp |= ADC_SEQR1_USCH7(data);
	((Adc *)hw)->ADC_SEQR1 = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_SEQR1_USCH7_bf(const void *const hw, hri_adc_seqr1_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_SEQR1 &= ~ADC_SEQR1_USCH7(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_SEQR1_USCH7_bf(const void *const hw, hri_adc_seqr1_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_SEQR1 ^= ADC_SEQR1_USCH7(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_seqr1_reg_t hri_adc_read_SEQR1_USCH7_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_SEQR1;
	tmp = (tmp & ADC_SEQR1_USCH7_Msk) >> ADC_SEQR1_USCH7_Pos;
	return tmp;
}

static inline void hri_adc_set_SEQR1_reg(const void *const hw, hri_adc_seqr1_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_SEQR1 |= mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_seqr1_reg_t hri_adc_get_SEQR1_reg(const void *const hw, hri_adc_seqr1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_SEQR1;
	tmp &= mask;
	return tmp;
}

static inline void hri_adc_write_SEQR1_reg(const void *const hw, hri_adc_seqr1_reg_t data)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_SEQR1 = data;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_SEQR1_reg(const void *const hw, hri_adc_seqr1_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_SEQR1 &= ~mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_SEQR1_reg(const void *const hw, hri_adc_seqr1_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_SEQR1 ^= mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_seqr1_reg_t hri_adc_read_SEQR1_reg(const void *const hw)
{
	return ((Adc *)hw)->ADC_SEQR1;
}

static inline void hri_adc_set_LCTMR_DUALTRIG_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_LCTMR |= ADC_LCTMR_DUALTRIG;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_adc_get_LCTMR_DUALTRIG_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_LCTMR;
	tmp = (tmp & ADC_LCTMR_DUALTRIG) >> ADC_LCTMR_DUALTRIG_Pos;
	return (bool)tmp;
}

static inline void hri_adc_write_LCTMR_DUALTRIG_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_LCTMR;
	tmp &= ~ADC_LCTMR_DUALTRIG;
	tmp |= value << ADC_LCTMR_DUALTRIG_Pos;
	((Adc *)hw)->ADC_LCTMR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_LCTMR_DUALTRIG_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_LCTMR &= ~ADC_LCTMR_DUALTRIG;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_LCTMR_DUALTRIG_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_LCTMR ^= ADC_LCTMR_DUALTRIG;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_set_LCTMR_CMPMOD_bf(const void *const hw, hri_adc_lctmr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_LCTMR |= ADC_LCTMR_CMPMOD(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_lctmr_reg_t hri_adc_get_LCTMR_CMPMOD_bf(const void *const hw, hri_adc_lctmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_LCTMR;
	tmp = (tmp & ADC_LCTMR_CMPMOD(mask)) >> ADC_LCTMR_CMPMOD_Pos;
	return tmp;
}

static inline void hri_adc_write_LCTMR_CMPMOD_bf(const void *const hw, hri_adc_lctmr_reg_t data)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_LCTMR;
	tmp &= ~ADC_LCTMR_CMPMOD_Msk;
	tmp |= ADC_LCTMR_CMPMOD(data);
	((Adc *)hw)->ADC_LCTMR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_LCTMR_CMPMOD_bf(const void *const hw, hri_adc_lctmr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_LCTMR &= ~ADC_LCTMR_CMPMOD(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_LCTMR_CMPMOD_bf(const void *const hw, hri_adc_lctmr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_LCTMR ^= ADC_LCTMR_CMPMOD(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_lctmr_reg_t hri_adc_read_LCTMR_CMPMOD_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_LCTMR;
	tmp = (tmp & ADC_LCTMR_CMPMOD_Msk) >> ADC_LCTMR_CMPMOD_Pos;
	return tmp;
}

static inline void hri_adc_set_LCTMR_reg(const void *const hw, hri_adc_lctmr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_LCTMR |= mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_lctmr_reg_t hri_adc_get_LCTMR_reg(const void *const hw, hri_adc_lctmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_LCTMR;
	tmp &= mask;
	return tmp;
}

static inline void hri_adc_write_LCTMR_reg(const void *const hw, hri_adc_lctmr_reg_t data)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_LCTMR = data;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_LCTMR_reg(const void *const hw, hri_adc_lctmr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_LCTMR &= ~mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_LCTMR_reg(const void *const hw, hri_adc_lctmr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_LCTMR ^= mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_lctmr_reg_t hri_adc_read_LCTMR_reg(const void *const hw)
{
	return ((Adc *)hw)->ADC_LCTMR;
}

static inline void hri_adc_set_LCCWR_LOWTHRES_bf(const void *const hw, hri_adc_lccwr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_LCCWR |= ADC_LCCWR_LOWTHRES(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_lccwr_reg_t hri_adc_get_LCCWR_LOWTHRES_bf(const void *const hw, hri_adc_lccwr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_LCCWR;
	tmp = (tmp & ADC_LCCWR_LOWTHRES(mask)) >> ADC_LCCWR_LOWTHRES_Pos;
	return tmp;
}

static inline void hri_adc_write_LCCWR_LOWTHRES_bf(const void *const hw, hri_adc_lccwr_reg_t data)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_LCCWR;
	tmp &= ~ADC_LCCWR_LOWTHRES_Msk;
	tmp |= ADC_LCCWR_LOWTHRES(data);
	((Adc *)hw)->ADC_LCCWR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_LCCWR_LOWTHRES_bf(const void *const hw, hri_adc_lccwr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_LCCWR &= ~ADC_LCCWR_LOWTHRES(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_LCCWR_LOWTHRES_bf(const void *const hw, hri_adc_lccwr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_LCCWR ^= ADC_LCCWR_LOWTHRES(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_lccwr_reg_t hri_adc_read_LCCWR_LOWTHRES_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_LCCWR;
	tmp = (tmp & ADC_LCCWR_LOWTHRES_Msk) >> ADC_LCCWR_LOWTHRES_Pos;
	return tmp;
}

static inline void hri_adc_set_LCCWR_HIGHTHRES_bf(const void *const hw, hri_adc_lccwr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_LCCWR |= ADC_LCCWR_HIGHTHRES(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_lccwr_reg_t hri_adc_get_LCCWR_HIGHTHRES_bf(const void *const hw, hri_adc_lccwr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_LCCWR;
	tmp = (tmp & ADC_LCCWR_HIGHTHRES(mask)) >> ADC_LCCWR_HIGHTHRES_Pos;
	return tmp;
}

static inline void hri_adc_write_LCCWR_HIGHTHRES_bf(const void *const hw, hri_adc_lccwr_reg_t data)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_LCCWR;
	tmp &= ~ADC_LCCWR_HIGHTHRES_Msk;
	tmp |= ADC_LCCWR_HIGHTHRES(data);
	((Adc *)hw)->ADC_LCCWR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_LCCWR_HIGHTHRES_bf(const void *const hw, hri_adc_lccwr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_LCCWR &= ~ADC_LCCWR_HIGHTHRES(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_LCCWR_HIGHTHRES_bf(const void *const hw, hri_adc_lccwr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_LCCWR ^= ADC_LCCWR_HIGHTHRES(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_lccwr_reg_t hri_adc_read_LCCWR_HIGHTHRES_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_LCCWR;
	tmp = (tmp & ADC_LCCWR_HIGHTHRES_Msk) >> ADC_LCCWR_HIGHTHRES_Pos;
	return tmp;
}

static inline void hri_adc_set_LCCWR_reg(const void *const hw, hri_adc_lccwr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_LCCWR |= mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_lccwr_reg_t hri_adc_get_LCCWR_reg(const void *const hw, hri_adc_lccwr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_LCCWR;
	tmp &= mask;
	return tmp;
}

static inline void hri_adc_write_LCCWR_reg(const void *const hw, hri_adc_lccwr_reg_t data)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_LCCWR = data;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_LCCWR_reg(const void *const hw, hri_adc_lccwr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_LCCWR &= ~mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_LCCWR_reg(const void *const hw, hri_adc_lccwr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_LCCWR ^= mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_lccwr_reg_t hri_adc_read_LCCWR_reg(const void *const hw)
{
	return ((Adc *)hw)->ADC_LCCWR;
}

static inline void hri_adc_set_EMR_CMPTYPE_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_EMR |= ADC_EMR_CMPTYPE;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_adc_get_EMR_CMPTYPE_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_EMR;
	tmp = (tmp & ADC_EMR_CMPTYPE) >> ADC_EMR_CMPTYPE_Pos;
	return (bool)tmp;
}

static inline void hri_adc_write_EMR_CMPTYPE_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_EMR;
	tmp &= ~ADC_EMR_CMPTYPE;
	tmp |= value << ADC_EMR_CMPTYPE_Pos;
	((Adc *)hw)->ADC_EMR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_EMR_CMPTYPE_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_EMR &= ~ADC_EMR_CMPTYPE;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_EMR_CMPTYPE_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_EMR ^= ADC_EMR_CMPTYPE;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_set_EMR_CMPALL_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_EMR |= ADC_EMR_CMPALL;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_adc_get_EMR_CMPALL_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_EMR;
	tmp = (tmp & ADC_EMR_CMPALL) >> ADC_EMR_CMPALL_Pos;
	return (bool)tmp;
}

static inline void hri_adc_write_EMR_CMPALL_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_EMR;
	tmp &= ~ADC_EMR_CMPALL;
	tmp |= value << ADC_EMR_CMPALL_Pos;
	((Adc *)hw)->ADC_EMR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_EMR_CMPALL_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_EMR &= ~ADC_EMR_CMPALL;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_EMR_CMPALL_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_EMR ^= ADC_EMR_CMPALL;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_set_EMR_ASTE_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_EMR |= ADC_EMR_ASTE;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_adc_get_EMR_ASTE_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_EMR;
	tmp = (tmp & ADC_EMR_ASTE) >> ADC_EMR_ASTE_Pos;
	return (bool)tmp;
}

static inline void hri_adc_write_EMR_ASTE_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_EMR;
	tmp &= ~ADC_EMR_ASTE;
	tmp |= value << ADC_EMR_ASTE_Pos;
	((Adc *)hw)->ADC_EMR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_EMR_ASTE_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_EMR &= ~ADC_EMR_ASTE;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_EMR_ASTE_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_EMR ^= ADC_EMR_ASTE;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_set_EMR_SRCCLK_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_EMR |= ADC_EMR_SRCCLK;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_adc_get_EMR_SRCCLK_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_EMR;
	tmp = (tmp & ADC_EMR_SRCCLK) >> ADC_EMR_SRCCLK_Pos;
	return (bool)tmp;
}

static inline void hri_adc_write_EMR_SRCCLK_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_EMR;
	tmp &= ~ADC_EMR_SRCCLK;
	tmp |= value << ADC_EMR_SRCCLK_Pos;
	((Adc *)hw)->ADC_EMR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_EMR_SRCCLK_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_EMR &= ~ADC_EMR_SRCCLK;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_EMR_SRCCLK_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_EMR ^= ADC_EMR_SRCCLK;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_set_EMR_TAG_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_EMR |= ADC_EMR_TAG;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_adc_get_EMR_TAG_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_EMR;
	tmp = (tmp & ADC_EMR_TAG) >> ADC_EMR_TAG_Pos;
	return (bool)tmp;
}

static inline void hri_adc_write_EMR_TAG_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_EMR;
	tmp &= ~ADC_EMR_TAG;
	tmp |= value << ADC_EMR_TAG_Pos;
	((Adc *)hw)->ADC_EMR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_EMR_TAG_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_EMR &= ~ADC_EMR_TAG;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_EMR_TAG_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_EMR ^= ADC_EMR_TAG;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_set_EMR_CMPMODE_bf(const void *const hw, hri_adc_emr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_EMR |= ADC_EMR_CMPMODE(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_emr_reg_t hri_adc_get_EMR_CMPMODE_bf(const void *const hw, hri_adc_emr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_EMR;
	tmp = (tmp & ADC_EMR_CMPMODE(mask)) >> ADC_EMR_CMPMODE_Pos;
	return tmp;
}

static inline void hri_adc_write_EMR_CMPMODE_bf(const void *const hw, hri_adc_emr_reg_t data)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_EMR;
	tmp &= ~ADC_EMR_CMPMODE_Msk;
	tmp |= ADC_EMR_CMPMODE(data);
	((Adc *)hw)->ADC_EMR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_EMR_CMPMODE_bf(const void *const hw, hri_adc_emr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_EMR &= ~ADC_EMR_CMPMODE(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_EMR_CMPMODE_bf(const void *const hw, hri_adc_emr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_EMR ^= ADC_EMR_CMPMODE(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_emr_reg_t hri_adc_read_EMR_CMPMODE_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_EMR;
	tmp = (tmp & ADC_EMR_CMPMODE_Msk) >> ADC_EMR_CMPMODE_Pos;
	return tmp;
}

static inline void hri_adc_set_EMR_CMPSEL_bf(const void *const hw, hri_adc_emr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_EMR |= ADC_EMR_CMPSEL(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_emr_reg_t hri_adc_get_EMR_CMPSEL_bf(const void *const hw, hri_adc_emr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_EMR;
	tmp = (tmp & ADC_EMR_CMPSEL(mask)) >> ADC_EMR_CMPSEL_Pos;
	return tmp;
}

static inline void hri_adc_write_EMR_CMPSEL_bf(const void *const hw, hri_adc_emr_reg_t data)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_EMR;
	tmp &= ~ADC_EMR_CMPSEL_Msk;
	tmp |= ADC_EMR_CMPSEL(data);
	((Adc *)hw)->ADC_EMR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_EMR_CMPSEL_bf(const void *const hw, hri_adc_emr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_EMR &= ~ADC_EMR_CMPSEL(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_EMR_CMPSEL_bf(const void *const hw, hri_adc_emr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_EMR ^= ADC_EMR_CMPSEL(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_emr_reg_t hri_adc_read_EMR_CMPSEL_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_EMR;
	tmp = (tmp & ADC_EMR_CMPSEL_Msk) >> ADC_EMR_CMPSEL_Pos;
	return tmp;
}

static inline void hri_adc_set_EMR_CMPFILTER_bf(const void *const hw, hri_adc_emr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_EMR |= ADC_EMR_CMPFILTER(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_emr_reg_t hri_adc_get_EMR_CMPFILTER_bf(const void *const hw, hri_adc_emr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_EMR;
	tmp = (tmp & ADC_EMR_CMPFILTER(mask)) >> ADC_EMR_CMPFILTER_Pos;
	return tmp;
}

static inline void hri_adc_write_EMR_CMPFILTER_bf(const void *const hw, hri_adc_emr_reg_t data)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_EMR;
	tmp &= ~ADC_EMR_CMPFILTER_Msk;
	tmp |= ADC_EMR_CMPFILTER(data);
	((Adc *)hw)->ADC_EMR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_EMR_CMPFILTER_bf(const void *const hw, hri_adc_emr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_EMR &= ~ADC_EMR_CMPFILTER(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_EMR_CMPFILTER_bf(const void *const hw, hri_adc_emr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_EMR ^= ADC_EMR_CMPFILTER(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_emr_reg_t hri_adc_read_EMR_CMPFILTER_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_EMR;
	tmp = (tmp & ADC_EMR_CMPFILTER_Msk) >> ADC_EMR_CMPFILTER_Pos;
	return tmp;
}

static inline void hri_adc_set_EMR_OSR_bf(const void *const hw, hri_adc_emr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_EMR |= ADC_EMR_OSR(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_emr_reg_t hri_adc_get_EMR_OSR_bf(const void *const hw, hri_adc_emr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_EMR;
	tmp = (tmp & ADC_EMR_OSR(mask)) >> ADC_EMR_OSR_Pos;
	return tmp;
}

static inline void hri_adc_write_EMR_OSR_bf(const void *const hw, hri_adc_emr_reg_t data)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_EMR;
	tmp &= ~ADC_EMR_OSR_Msk;
	tmp |= ADC_EMR_OSR(data);
	((Adc *)hw)->ADC_EMR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_EMR_OSR_bf(const void *const hw, hri_adc_emr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_EMR &= ~ADC_EMR_OSR(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_EMR_OSR_bf(const void *const hw, hri_adc_emr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_EMR ^= ADC_EMR_OSR(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_emr_reg_t hri_adc_read_EMR_OSR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_EMR;
	tmp = (tmp & ADC_EMR_OSR_Msk) >> ADC_EMR_OSR_Pos;
	return tmp;
}

static inline void hri_adc_set_EMR_reg(const void *const hw, hri_adc_emr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_EMR |= mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_emr_reg_t hri_adc_get_EMR_reg(const void *const hw, hri_adc_emr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_EMR;
	tmp &= mask;
	return tmp;
}

static inline void hri_adc_write_EMR_reg(const void *const hw, hri_adc_emr_reg_t data)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_EMR = data;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_EMR_reg(const void *const hw, hri_adc_emr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_EMR &= ~mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_EMR_reg(const void *const hw, hri_adc_emr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_EMR ^= mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_emr_reg_t hri_adc_read_EMR_reg(const void *const hw)
{
	return ((Adc *)hw)->ADC_EMR;
}

static inline void hri_adc_set_CWR_LOWTHRES_bf(const void *const hw, hri_adc_cwr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_CWR |= ADC_CWR_LOWTHRES(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_cwr_reg_t hri_adc_get_CWR_LOWTHRES_bf(const void *const hw, hri_adc_cwr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_CWR;
	tmp = (tmp & ADC_CWR_LOWTHRES(mask)) >> ADC_CWR_LOWTHRES_Pos;
	return tmp;
}

static inline void hri_adc_write_CWR_LOWTHRES_bf(const void *const hw, hri_adc_cwr_reg_t data)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_CWR;
	tmp &= ~ADC_CWR_LOWTHRES_Msk;
	tmp |= ADC_CWR_LOWTHRES(data);
	((Adc *)hw)->ADC_CWR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_CWR_LOWTHRES_bf(const void *const hw, hri_adc_cwr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_CWR &= ~ADC_CWR_LOWTHRES(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_CWR_LOWTHRES_bf(const void *const hw, hri_adc_cwr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_CWR ^= ADC_CWR_LOWTHRES(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_cwr_reg_t hri_adc_read_CWR_LOWTHRES_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_CWR;
	tmp = (tmp & ADC_CWR_LOWTHRES_Msk) >> ADC_CWR_LOWTHRES_Pos;
	return tmp;
}

static inline void hri_adc_set_CWR_HIGHTHRES_bf(const void *const hw, hri_adc_cwr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_CWR |= ADC_CWR_HIGHTHRES(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_cwr_reg_t hri_adc_get_CWR_HIGHTHRES_bf(const void *const hw, hri_adc_cwr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_CWR;
	tmp = (tmp & ADC_CWR_HIGHTHRES(mask)) >> ADC_CWR_HIGHTHRES_Pos;
	return tmp;
}

static inline void hri_adc_write_CWR_HIGHTHRES_bf(const void *const hw, hri_adc_cwr_reg_t data)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_CWR;
	tmp &= ~ADC_CWR_HIGHTHRES_Msk;
	tmp |= ADC_CWR_HIGHTHRES(data);
	((Adc *)hw)->ADC_CWR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_CWR_HIGHTHRES_bf(const void *const hw, hri_adc_cwr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_CWR &= ~ADC_CWR_HIGHTHRES(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_CWR_HIGHTHRES_bf(const void *const hw, hri_adc_cwr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_CWR ^= ADC_CWR_HIGHTHRES(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_cwr_reg_t hri_adc_read_CWR_HIGHTHRES_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_CWR;
	tmp = (tmp & ADC_CWR_HIGHTHRES_Msk) >> ADC_CWR_HIGHTHRES_Pos;
	return tmp;
}

static inline void hri_adc_set_CWR_reg(const void *const hw, hri_adc_cwr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_CWR |= mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_cwr_reg_t hri_adc_get_CWR_reg(const void *const hw, hri_adc_cwr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_CWR;
	tmp &= mask;
	return tmp;
}

static inline void hri_adc_write_CWR_reg(const void *const hw, hri_adc_cwr_reg_t data)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_CWR = data;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_CWR_reg(const void *const hw, hri_adc_cwr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_CWR &= ~mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_CWR_reg(const void *const hw, hri_adc_cwr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_CWR ^= mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_cwr_reg_t hri_adc_read_CWR_reg(const void *const hw)
{
	return ((Adc *)hw)->ADC_CWR;
}

static inline void hri_adc_set_COR_OFF0_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR |= ADC_COR_OFF0;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_adc_get_COR_OFF0_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_COR;
	tmp = (tmp & ADC_COR_OFF0) >> ADC_COR_OFF0_Pos;
	return (bool)tmp;
}

static inline void hri_adc_write_COR_OFF0_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_COR;
	tmp &= ~ADC_COR_OFF0;
	tmp |= value << ADC_COR_OFF0_Pos;
	((Adc *)hw)->ADC_COR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_COR_OFF0_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR &= ~ADC_COR_OFF0;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_COR_OFF0_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR ^= ADC_COR_OFF0;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_set_COR_OFF1_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR |= ADC_COR_OFF1;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_adc_get_COR_OFF1_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_COR;
	tmp = (tmp & ADC_COR_OFF1) >> ADC_COR_OFF1_Pos;
	return (bool)tmp;
}

static inline void hri_adc_write_COR_OFF1_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_COR;
	tmp &= ~ADC_COR_OFF1;
	tmp |= value << ADC_COR_OFF1_Pos;
	((Adc *)hw)->ADC_COR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_COR_OFF1_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR &= ~ADC_COR_OFF1;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_COR_OFF1_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR ^= ADC_COR_OFF1;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_set_COR_OFF2_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR |= ADC_COR_OFF2;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_adc_get_COR_OFF2_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_COR;
	tmp = (tmp & ADC_COR_OFF2) >> ADC_COR_OFF2_Pos;
	return (bool)tmp;
}

static inline void hri_adc_write_COR_OFF2_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_COR;
	tmp &= ~ADC_COR_OFF2;
	tmp |= value << ADC_COR_OFF2_Pos;
	((Adc *)hw)->ADC_COR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_COR_OFF2_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR &= ~ADC_COR_OFF2;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_COR_OFF2_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR ^= ADC_COR_OFF2;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_set_COR_OFF3_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR |= ADC_COR_OFF3;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_adc_get_COR_OFF3_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_COR;
	tmp = (tmp & ADC_COR_OFF3) >> ADC_COR_OFF3_Pos;
	return (bool)tmp;
}

static inline void hri_adc_write_COR_OFF3_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_COR;
	tmp &= ~ADC_COR_OFF3;
	tmp |= value << ADC_COR_OFF3_Pos;
	((Adc *)hw)->ADC_COR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_COR_OFF3_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR &= ~ADC_COR_OFF3;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_COR_OFF3_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR ^= ADC_COR_OFF3;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_set_COR_OFF4_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR |= ADC_COR_OFF4;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_adc_get_COR_OFF4_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_COR;
	tmp = (tmp & ADC_COR_OFF4) >> ADC_COR_OFF4_Pos;
	return (bool)tmp;
}

static inline void hri_adc_write_COR_OFF4_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_COR;
	tmp &= ~ADC_COR_OFF4;
	tmp |= value << ADC_COR_OFF4_Pos;
	((Adc *)hw)->ADC_COR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_COR_OFF4_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR &= ~ADC_COR_OFF4;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_COR_OFF4_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR ^= ADC_COR_OFF4;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_set_COR_OFF5_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR |= ADC_COR_OFF5;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_adc_get_COR_OFF5_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_COR;
	tmp = (tmp & ADC_COR_OFF5) >> ADC_COR_OFF5_Pos;
	return (bool)tmp;
}

static inline void hri_adc_write_COR_OFF5_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_COR;
	tmp &= ~ADC_COR_OFF5;
	tmp |= value << ADC_COR_OFF5_Pos;
	((Adc *)hw)->ADC_COR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_COR_OFF5_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR &= ~ADC_COR_OFF5;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_COR_OFF5_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR ^= ADC_COR_OFF5;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_set_COR_OFF6_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR |= ADC_COR_OFF6;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_adc_get_COR_OFF6_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_COR;
	tmp = (tmp & ADC_COR_OFF6) >> ADC_COR_OFF6_Pos;
	return (bool)tmp;
}

static inline void hri_adc_write_COR_OFF6_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_COR;
	tmp &= ~ADC_COR_OFF6;
	tmp |= value << ADC_COR_OFF6_Pos;
	((Adc *)hw)->ADC_COR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_COR_OFF6_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR &= ~ADC_COR_OFF6;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_COR_OFF6_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR ^= ADC_COR_OFF6;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_set_COR_OFF7_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR |= ADC_COR_OFF7;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_adc_get_COR_OFF7_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_COR;
	tmp = (tmp & ADC_COR_OFF7) >> ADC_COR_OFF7_Pos;
	return (bool)tmp;
}

static inline void hri_adc_write_COR_OFF7_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_COR;
	tmp &= ~ADC_COR_OFF7;
	tmp |= value << ADC_COR_OFF7_Pos;
	((Adc *)hw)->ADC_COR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_COR_OFF7_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR &= ~ADC_COR_OFF7;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_COR_OFF7_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR ^= ADC_COR_OFF7;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_set_COR_DIFF0_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR |= ADC_COR_DIFF0;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_adc_get_COR_DIFF0_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_COR;
	tmp = (tmp & ADC_COR_DIFF0) >> ADC_COR_DIFF0_Pos;
	return (bool)tmp;
}

static inline void hri_adc_write_COR_DIFF0_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_COR;
	tmp &= ~ADC_COR_DIFF0;
	tmp |= value << ADC_COR_DIFF0_Pos;
	((Adc *)hw)->ADC_COR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_COR_DIFF0_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR &= ~ADC_COR_DIFF0;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_COR_DIFF0_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR ^= ADC_COR_DIFF0;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_set_COR_DIFF1_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR |= ADC_COR_DIFF1;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_adc_get_COR_DIFF1_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_COR;
	tmp = (tmp & ADC_COR_DIFF1) >> ADC_COR_DIFF1_Pos;
	return (bool)tmp;
}

static inline void hri_adc_write_COR_DIFF1_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_COR;
	tmp &= ~ADC_COR_DIFF1;
	tmp |= value << ADC_COR_DIFF1_Pos;
	((Adc *)hw)->ADC_COR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_COR_DIFF1_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR &= ~ADC_COR_DIFF1;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_COR_DIFF1_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR ^= ADC_COR_DIFF1;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_set_COR_DIFF2_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR |= ADC_COR_DIFF2;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_adc_get_COR_DIFF2_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_COR;
	tmp = (tmp & ADC_COR_DIFF2) >> ADC_COR_DIFF2_Pos;
	return (bool)tmp;
}

static inline void hri_adc_write_COR_DIFF2_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_COR;
	tmp &= ~ADC_COR_DIFF2;
	tmp |= value << ADC_COR_DIFF2_Pos;
	((Adc *)hw)->ADC_COR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_COR_DIFF2_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR &= ~ADC_COR_DIFF2;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_COR_DIFF2_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR ^= ADC_COR_DIFF2;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_set_COR_DIFF3_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR |= ADC_COR_DIFF3;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_adc_get_COR_DIFF3_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_COR;
	tmp = (tmp & ADC_COR_DIFF3) >> ADC_COR_DIFF3_Pos;
	return (bool)tmp;
}

static inline void hri_adc_write_COR_DIFF3_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_COR;
	tmp &= ~ADC_COR_DIFF3;
	tmp |= value << ADC_COR_DIFF3_Pos;
	((Adc *)hw)->ADC_COR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_COR_DIFF3_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR &= ~ADC_COR_DIFF3;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_COR_DIFF3_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR ^= ADC_COR_DIFF3;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_set_COR_DIFF4_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR |= ADC_COR_DIFF4;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_adc_get_COR_DIFF4_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_COR;
	tmp = (tmp & ADC_COR_DIFF4) >> ADC_COR_DIFF4_Pos;
	return (bool)tmp;
}

static inline void hri_adc_write_COR_DIFF4_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_COR;
	tmp &= ~ADC_COR_DIFF4;
	tmp |= value << ADC_COR_DIFF4_Pos;
	((Adc *)hw)->ADC_COR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_COR_DIFF4_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR &= ~ADC_COR_DIFF4;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_COR_DIFF4_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR ^= ADC_COR_DIFF4;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_set_COR_DIFF5_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR |= ADC_COR_DIFF5;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_adc_get_COR_DIFF5_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_COR;
	tmp = (tmp & ADC_COR_DIFF5) >> ADC_COR_DIFF5_Pos;
	return (bool)tmp;
}

static inline void hri_adc_write_COR_DIFF5_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_COR;
	tmp &= ~ADC_COR_DIFF5;
	tmp |= value << ADC_COR_DIFF5_Pos;
	((Adc *)hw)->ADC_COR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_COR_DIFF5_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR &= ~ADC_COR_DIFF5;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_COR_DIFF5_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR ^= ADC_COR_DIFF5;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_set_COR_DIFF6_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR |= ADC_COR_DIFF6;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_adc_get_COR_DIFF6_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_COR;
	tmp = (tmp & ADC_COR_DIFF6) >> ADC_COR_DIFF6_Pos;
	return (bool)tmp;
}

static inline void hri_adc_write_COR_DIFF6_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_COR;
	tmp &= ~ADC_COR_DIFF6;
	tmp |= value << ADC_COR_DIFF6_Pos;
	((Adc *)hw)->ADC_COR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_COR_DIFF6_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR &= ~ADC_COR_DIFF6;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_COR_DIFF6_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR ^= ADC_COR_DIFF6;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_set_COR_DIFF7_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR |= ADC_COR_DIFF7;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_adc_get_COR_DIFF7_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_COR;
	tmp = (tmp & ADC_COR_DIFF7) >> ADC_COR_DIFF7_Pos;
	return (bool)tmp;
}

static inline void hri_adc_write_COR_DIFF7_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_COR;
	tmp &= ~ADC_COR_DIFF7;
	tmp |= value << ADC_COR_DIFF7_Pos;
	((Adc *)hw)->ADC_COR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_COR_DIFF7_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR &= ~ADC_COR_DIFF7;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_COR_DIFF7_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR ^= ADC_COR_DIFF7;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_set_COR_reg(const void *const hw, hri_adc_cor_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR |= mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_cor_reg_t hri_adc_get_COR_reg(const void *const hw, hri_adc_cor_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_COR;
	tmp &= mask;
	return tmp;
}

static inline void hri_adc_write_COR_reg(const void *const hw, hri_adc_cor_reg_t data)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR = data;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_COR_reg(const void *const hw, hri_adc_cor_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR &= ~mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_COR_reg(const void *const hw, hri_adc_cor_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_COR ^= mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_cor_reg_t hri_adc_read_COR_reg(const void *const hw)
{
	return ((Adc *)hw)->ADC_COR;
}

static inline void hri_adc_set_ACR_AUTOTEST_bf(const void *const hw, hri_adc_acr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_ACR |= ADC_ACR_AUTOTEST(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_acr_reg_t hri_adc_get_ACR_AUTOTEST_bf(const void *const hw, hri_adc_acr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_ACR;
	tmp = (tmp & ADC_ACR_AUTOTEST(mask)) >> ADC_ACR_AUTOTEST_Pos;
	return tmp;
}

static inline void hri_adc_write_ACR_AUTOTEST_bf(const void *const hw, hri_adc_acr_reg_t data)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_ACR;
	tmp &= ~ADC_ACR_AUTOTEST_Msk;
	tmp |= ADC_ACR_AUTOTEST(data);
	((Adc *)hw)->ADC_ACR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_ACR_AUTOTEST_bf(const void *const hw, hri_adc_acr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_ACR &= ~ADC_ACR_AUTOTEST(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_ACR_AUTOTEST_bf(const void *const hw, hri_adc_acr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_ACR ^= ADC_ACR_AUTOTEST(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_acr_reg_t hri_adc_read_ACR_AUTOTEST_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_ACR;
	tmp = (tmp & ADC_ACR_AUTOTEST_Msk) >> ADC_ACR_AUTOTEST_Pos;
	return tmp;
}

static inline void hri_adc_set_ACR_reg(const void *const hw, hri_adc_acr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_ACR |= mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_acr_reg_t hri_adc_get_ACR_reg(const void *const hw, hri_adc_acr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_ACR;
	tmp &= mask;
	return tmp;
}

static inline void hri_adc_write_ACR_reg(const void *const hw, hri_adc_acr_reg_t data)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_ACR = data;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_ACR_reg(const void *const hw, hri_adc_acr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_ACR &= ~mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_ACR_reg(const void *const hw, hri_adc_acr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_ACR ^= mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_acr_reg_t hri_adc_read_ACR_reg(const void *const hw)
{
	return ((Adc *)hw)->ADC_ACR;
}

static inline void hri_adc_set_WPMR_WPEN_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_WPMR |= ADC_WPMR_WPEN;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_adc_get_WPMR_WPEN_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_WPMR;
	tmp = (tmp & ADC_WPMR_WPEN) >> ADC_WPMR_WPEN_Pos;
	return (bool)tmp;
}

static inline void hri_adc_write_WPMR_WPEN_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_WPMR;
	tmp &= ~ADC_WPMR_WPEN;
	tmp |= value << ADC_WPMR_WPEN_Pos;
	((Adc *)hw)->ADC_WPMR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_WPMR_WPEN_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_WPMR &= ~ADC_WPMR_WPEN;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_WPMR_WPEN_bit(const void *const hw)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_WPMR ^= ADC_WPMR_WPEN;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_set_WPMR_WPKEY_bf(const void *const hw, hri_adc_wpmr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_WPMR |= ADC_WPMR_WPKEY(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_wpmr_reg_t hri_adc_get_WPMR_WPKEY_bf(const void *const hw, hri_adc_wpmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_WPMR;
	tmp = (tmp & ADC_WPMR_WPKEY(mask)) >> ADC_WPMR_WPKEY_Pos;
	return tmp;
}

static inline void hri_adc_write_WPMR_WPKEY_bf(const void *const hw, hri_adc_wpmr_reg_t data)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_WPMR;
	tmp &= ~ADC_WPMR_WPKEY_Msk;
	tmp |= ADC_WPMR_WPKEY(data);
	((Adc *)hw)->ADC_WPMR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_WPMR_WPKEY_bf(const void *const hw, hri_adc_wpmr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_WPMR &= ~ADC_WPMR_WPKEY(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_WPMR_WPKEY_bf(const void *const hw, hri_adc_wpmr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_WPMR ^= ADC_WPMR_WPKEY(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_wpmr_reg_t hri_adc_read_WPMR_WPKEY_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_WPMR;
	tmp = (tmp & ADC_WPMR_WPKEY_Msk) >> ADC_WPMR_WPKEY_Pos;
	return tmp;
}

static inline void hri_adc_set_WPMR_reg(const void *const hw, hri_adc_wpmr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_WPMR |= mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_wpmr_reg_t hri_adc_get_WPMR_reg(const void *const hw, hri_adc_wpmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_WPMR;
	tmp &= mask;
	return tmp;
}

static inline void hri_adc_write_WPMR_reg(const void *const hw, hri_adc_wpmr_reg_t data)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_WPMR = data;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_WPMR_reg(const void *const hw, hri_adc_wpmr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_WPMR &= ~mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_WPMR_reg(const void *const hw, hri_adc_wpmr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_WPMR ^= mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_wpmr_reg_t hri_adc_read_WPMR_reg(const void *const hw)
{
	return ((Adc *)hw)->ADC_WPMR;
}

static inline void hri_adc_set_RPR_RXPTR_bf(const void *const hw, hri_adc_rpr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_RPR |= ADC_RPR_RXPTR(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_rpr_reg_t hri_adc_get_RPR_RXPTR_bf(const void *const hw, hri_adc_rpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_RPR;
	tmp = (tmp & ADC_RPR_RXPTR(mask)) >> ADC_RPR_RXPTR_Pos;
	return tmp;
}

static inline void hri_adc_write_RPR_RXPTR_bf(const void *const hw, hri_adc_rpr_reg_t data)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_RPR;
	tmp &= ~ADC_RPR_RXPTR_Msk;
	tmp |= ADC_RPR_RXPTR(data);
	((Adc *)hw)->ADC_RPR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_RPR_RXPTR_bf(const void *const hw, hri_adc_rpr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_RPR &= ~ADC_RPR_RXPTR(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_RPR_RXPTR_bf(const void *const hw, hri_adc_rpr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_RPR ^= ADC_RPR_RXPTR(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_rpr_reg_t hri_adc_read_RPR_RXPTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_RPR;
	tmp = (tmp & ADC_RPR_RXPTR_Msk) >> ADC_RPR_RXPTR_Pos;
	return tmp;
}

static inline void hri_adc_set_RPR_reg(const void *const hw, hri_adc_rpr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_RPR |= mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_rpr_reg_t hri_adc_get_RPR_reg(const void *const hw, hri_adc_rpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_RPR;
	tmp &= mask;
	return tmp;
}

static inline void hri_adc_write_RPR_reg(const void *const hw, hri_adc_rpr_reg_t data)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_RPR = data;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_RPR_reg(const void *const hw, hri_adc_rpr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_RPR &= ~mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_RPR_reg(const void *const hw, hri_adc_rpr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_RPR ^= mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_rpr_reg_t hri_adc_read_RPR_reg(const void *const hw)
{
	return ((Adc *)hw)->ADC_RPR;
}

static inline void hri_adc_set_RCR_RXCTR_bf(const void *const hw, hri_adc_rcr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_RCR |= ADC_RCR_RXCTR(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_rcr_reg_t hri_adc_get_RCR_RXCTR_bf(const void *const hw, hri_adc_rcr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_RCR;
	tmp = (tmp & ADC_RCR_RXCTR(mask)) >> ADC_RCR_RXCTR_Pos;
	return tmp;
}

static inline void hri_adc_write_RCR_RXCTR_bf(const void *const hw, hri_adc_rcr_reg_t data)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_RCR;
	tmp &= ~ADC_RCR_RXCTR_Msk;
	tmp |= ADC_RCR_RXCTR(data);
	((Adc *)hw)->ADC_RCR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_RCR_RXCTR_bf(const void *const hw, hri_adc_rcr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_RCR &= ~ADC_RCR_RXCTR(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_RCR_RXCTR_bf(const void *const hw, hri_adc_rcr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_RCR ^= ADC_RCR_RXCTR(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_rcr_reg_t hri_adc_read_RCR_RXCTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_RCR;
	tmp = (tmp & ADC_RCR_RXCTR_Msk) >> ADC_RCR_RXCTR_Pos;
	return tmp;
}

static inline void hri_adc_set_RCR_reg(const void *const hw, hri_adc_rcr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_RCR |= mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_rcr_reg_t hri_adc_get_RCR_reg(const void *const hw, hri_adc_rcr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_RCR;
	tmp &= mask;
	return tmp;
}

static inline void hri_adc_write_RCR_reg(const void *const hw, hri_adc_rcr_reg_t data)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_RCR = data;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_RCR_reg(const void *const hw, hri_adc_rcr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_RCR &= ~mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_RCR_reg(const void *const hw, hri_adc_rcr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_RCR ^= mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_rcr_reg_t hri_adc_read_RCR_reg(const void *const hw)
{
	return ((Adc *)hw)->ADC_RCR;
}

static inline void hri_adc_set_RNPR_RXNPTR_bf(const void *const hw, hri_adc_rnpr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_RNPR |= ADC_RNPR_RXNPTR(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_rnpr_reg_t hri_adc_get_RNPR_RXNPTR_bf(const void *const hw, hri_adc_rnpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_RNPR;
	tmp = (tmp & ADC_RNPR_RXNPTR(mask)) >> ADC_RNPR_RXNPTR_Pos;
	return tmp;
}

static inline void hri_adc_write_RNPR_RXNPTR_bf(const void *const hw, hri_adc_rnpr_reg_t data)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_RNPR;
	tmp &= ~ADC_RNPR_RXNPTR_Msk;
	tmp |= ADC_RNPR_RXNPTR(data);
	((Adc *)hw)->ADC_RNPR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_RNPR_RXNPTR_bf(const void *const hw, hri_adc_rnpr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_RNPR &= ~ADC_RNPR_RXNPTR(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_RNPR_RXNPTR_bf(const void *const hw, hri_adc_rnpr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_RNPR ^= ADC_RNPR_RXNPTR(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_rnpr_reg_t hri_adc_read_RNPR_RXNPTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_RNPR;
	tmp = (tmp & ADC_RNPR_RXNPTR_Msk) >> ADC_RNPR_RXNPTR_Pos;
	return tmp;
}

static inline void hri_adc_set_RNPR_reg(const void *const hw, hri_adc_rnpr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_RNPR |= mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_rnpr_reg_t hri_adc_get_RNPR_reg(const void *const hw, hri_adc_rnpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_RNPR;
	tmp &= mask;
	return tmp;
}

static inline void hri_adc_write_RNPR_reg(const void *const hw, hri_adc_rnpr_reg_t data)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_RNPR = data;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_RNPR_reg(const void *const hw, hri_adc_rnpr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_RNPR &= ~mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_RNPR_reg(const void *const hw, hri_adc_rnpr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_RNPR ^= mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_rnpr_reg_t hri_adc_read_RNPR_reg(const void *const hw)
{
	return ((Adc *)hw)->ADC_RNPR;
}

static inline void hri_adc_set_RNCR_RXNCTR_bf(const void *const hw, hri_adc_rncr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_RNCR |= ADC_RNCR_RXNCTR(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_rncr_reg_t hri_adc_get_RNCR_RXNCTR_bf(const void *const hw, hri_adc_rncr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_RNCR;
	tmp = (tmp & ADC_RNCR_RXNCTR(mask)) >> ADC_RNCR_RXNCTR_Pos;
	return tmp;
}

static inline void hri_adc_write_RNCR_RXNCTR_bf(const void *const hw, hri_adc_rncr_reg_t data)
{
	uint32_t tmp;
	ADC_CRITICAL_SECTION_ENTER();
	tmp = ((Adc *)hw)->ADC_RNCR;
	tmp &= ~ADC_RNCR_RXNCTR_Msk;
	tmp |= ADC_RNCR_RXNCTR(data);
	((Adc *)hw)->ADC_RNCR = tmp;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_RNCR_RXNCTR_bf(const void *const hw, hri_adc_rncr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_RNCR &= ~ADC_RNCR_RXNCTR(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_RNCR_RXNCTR_bf(const void *const hw, hri_adc_rncr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_RNCR ^= ADC_RNCR_RXNCTR(mask);
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_rncr_reg_t hri_adc_read_RNCR_RXNCTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_RNCR;
	tmp = (tmp & ADC_RNCR_RXNCTR_Msk) >> ADC_RNCR_RXNCTR_Pos;
	return tmp;
}

static inline void hri_adc_set_RNCR_reg(const void *const hw, hri_adc_rncr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_RNCR |= mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_rncr_reg_t hri_adc_get_RNCR_reg(const void *const hw, hri_adc_rncr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_RNCR;
	tmp &= mask;
	return tmp;
}

static inline void hri_adc_write_RNCR_reg(const void *const hw, hri_adc_rncr_reg_t data)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_RNCR = data;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_clear_RNCR_reg(const void *const hw, hri_adc_rncr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_RNCR &= ~mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_adc_toggle_RNCR_reg(const void *const hw, hri_adc_rncr_reg_t mask)
{
	ADC_CRITICAL_SECTION_ENTER();
	((Adc *)hw)->ADC_RNCR ^= mask;
	ADC_CRITICAL_SECTION_LEAVE();
}

static inline hri_adc_rncr_reg_t hri_adc_read_RNCR_reg(const void *const hw)
{
	return ((Adc *)hw)->ADC_RNCR;
}

static inline hri_adc_lcdr_reg_t hri_adc_get_LCDR_LDATA_bf(const void *const hw, hri_adc_lcdr_reg_t mask)
{
	return (((Adc *)hw)->ADC_LCDR & ADC_LCDR_LDATA(mask)) >> ADC_LCDR_LDATA_Pos;
}

static inline hri_adc_lcdr_reg_t hri_adc_read_LCDR_LDATA_bf(const void *const hw)
{
	return (((Adc *)hw)->ADC_LCDR & ADC_LCDR_LDATA_Msk) >> ADC_LCDR_LDATA_Pos;
}

static inline hri_adc_lcdr_reg_t hri_adc_get_LCDR_CHNBOSR_bf(const void *const hw, hri_adc_lcdr_reg_t mask)
{
	return (((Adc *)hw)->ADC_LCDR & ADC_LCDR_CHNBOSR(mask)) >> ADC_LCDR_CHNBOSR_Pos;
}

static inline hri_adc_lcdr_reg_t hri_adc_read_LCDR_CHNBOSR_bf(const void *const hw)
{
	return (((Adc *)hw)->ADC_LCDR & ADC_LCDR_CHNBOSR_Msk) >> ADC_LCDR_CHNBOSR_Pos;
}

static inline hri_adc_lcdr_reg_t hri_adc_get_LCDR_reg(const void *const hw, hri_adc_lcdr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_LCDR;
	tmp &= mask;
	return tmp;
}

static inline hri_adc_lcdr_reg_t hri_adc_read_LCDR_reg(const void *const hw)
{
	return ((Adc *)hw)->ADC_LCDR;
}

static inline bool hri_adc_get_OVER_OVRE0_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_OVER & ADC_OVER_OVRE0) > 0;
}

static inline bool hri_adc_get_OVER_OVRE1_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_OVER & ADC_OVER_OVRE1) > 0;
}

static inline bool hri_adc_get_OVER_OVRE2_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_OVER & ADC_OVER_OVRE2) > 0;
}

static inline bool hri_adc_get_OVER_OVRE3_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_OVER & ADC_OVER_OVRE3) > 0;
}

static inline bool hri_adc_get_OVER_OVRE4_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_OVER & ADC_OVER_OVRE4) > 0;
}

static inline bool hri_adc_get_OVER_OVRE5_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_OVER & ADC_OVER_OVRE5) > 0;
}

static inline bool hri_adc_get_OVER_OVRE6_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_OVER & ADC_OVER_OVRE6) > 0;
}

static inline bool hri_adc_get_OVER_OVRE7_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_OVER & ADC_OVER_OVRE7) > 0;
}

static inline hri_adc_over_reg_t hri_adc_get_OVER_reg(const void *const hw, hri_adc_over_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_OVER;
	tmp &= mask;
	return tmp;
}

static inline hri_adc_over_reg_t hri_adc_read_OVER_reg(const void *const hw)
{
	return ((Adc *)hw)->ADC_OVER;
}

static inline hri_adc_cdr_reg_t hri_adc_get_CDR_DATA_bf(const void *const hw, uint8_t index, hri_adc_cdr_reg_t mask)
{
	return (((Adc *)hw)->ADC_CDR[index] & ADC_CDR_DATA(mask)) >> ADC_CDR_DATA_Pos;
}

static inline hri_adc_cdr_reg_t hri_adc_read_CDR_DATA_bf(const void *const hw, uint8_t index)
{
	return (((Adc *)hw)->ADC_CDR[index] & ADC_CDR_DATA_Msk) >> ADC_CDR_DATA_Pos;
}

static inline hri_adc_cdr_reg_t hri_adc_get_CDR_reg(const void *const hw, uint8_t index, hri_adc_cdr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_CDR[index];
	tmp &= mask;
	return tmp;
}

static inline hri_adc_cdr_reg_t hri_adc_read_CDR_reg(const void *const hw, uint8_t index)
{
	return ((Adc *)hw)->ADC_CDR[index];
}

static inline bool hri_adc_get_WPSR_WPVS_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_WPSR & ADC_WPSR_WPVS) > 0;
}

static inline hri_adc_wpsr_reg_t hri_adc_get_WPSR_WPVSRC_bf(const void *const hw, hri_adc_wpsr_reg_t mask)
{
	return (((Adc *)hw)->ADC_WPSR & ADC_WPSR_WPVSRC(mask)) >> ADC_WPSR_WPVSRC_Pos;
}

static inline hri_adc_wpsr_reg_t hri_adc_read_WPSR_WPVSRC_bf(const void *const hw)
{
	return (((Adc *)hw)->ADC_WPSR & ADC_WPSR_WPVSRC_Msk) >> ADC_WPSR_WPVSRC_Pos;
}

static inline hri_adc_wpsr_reg_t hri_adc_get_WPSR_reg(const void *const hw, hri_adc_wpsr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_WPSR;
	tmp &= mask;
	return tmp;
}

static inline hri_adc_wpsr_reg_t hri_adc_read_WPSR_reg(const void *const hw)
{
	return ((Adc *)hw)->ADC_WPSR;
}

static inline bool hri_adc_get_PTSR_RXTEN_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_PTSR & ADC_PTSR_RXTEN) > 0;
}

static inline bool hri_adc_get_PTSR_TXTEN_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_PTSR & ADC_PTSR_TXTEN) > 0;
}

static inline bool hri_adc_get_PTSR_RXCBEN_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_PTSR & ADC_PTSR_RXCBEN) > 0;
}

static inline bool hri_adc_get_PTSR_TXCBEN_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_PTSR & ADC_PTSR_TXCBEN) > 0;
}

static inline bool hri_adc_get_PTSR_ERR_bit(const void *const hw)
{
	return (((Adc *)hw)->ADC_PTSR & ADC_PTSR_ERR) > 0;
}

static inline hri_adc_ptsr_reg_t hri_adc_get_PTSR_reg(const void *const hw, hri_adc_ptsr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Adc *)hw)->ADC_PTSR;
	tmp &= mask;
	return tmp;
}

static inline hri_adc_ptsr_reg_t hri_adc_read_PTSR_reg(const void *const hw)
{
	return ((Adc *)hw)->ADC_PTSR;
}

#ifdef __cplusplus
}
#endif

#endif /* _HRI_ADC_G55_H_INCLUDED */
#endif /* _SAMG55_ADC_COMPONENT_ */
