/**
 * \file
 *
 * \brief SAM CRCCU
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

#ifdef _SAMG55_CRCCU_COMPONENT_
#ifndef _HRI_CRCCU_G55_H_INCLUDED_
#define _HRI_CRCCU_G55_H_INCLUDED_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <hal_atomic.h>

#if defined(ENABLE_CRCCU_CRITICAL_SECTIONS)
#define CRCCU_CRITICAL_SECTION_ENTER() CRITICAL_SECTION_ENTER()
#define CRCCU_CRITICAL_SECTION_LEAVE() CRITICAL_SECTION_LEAVE()
#else
#define CRCCU_CRITICAL_SECTION_ENTER()
#define CRCCU_CRITICAL_SECTION_LEAVE()
#endif

typedef uint32_t hri_crccu_cr_reg_t;
typedef uint32_t hri_crccu_dma_dis_reg_t;
typedef uint32_t hri_crccu_dma_en_reg_t;
typedef uint32_t hri_crccu_dma_imr_reg_t;
typedef uint32_t hri_crccu_dma_isr_reg_t;
typedef uint32_t hri_crccu_dma_sr_reg_t;
typedef uint32_t hri_crccu_dscr_reg_t;
typedef uint32_t hri_crccu_imr_reg_t;
typedef uint32_t hri_crccu_isr_reg_t;
typedef uint32_t hri_crccu_mr_reg_t;
typedef uint32_t hri_crccu_sr_reg_t;

static inline void hri_crccu_set_DMA_IMR_DMAIMR_bit(const void *const hw)
{
	((Crccu *)hw)->CRCCU_DMA_IER = CRCCU_DMA_IMR_DMAIMR;
}

static inline bool hri_crccu_get_DMA_IMR_DMAIMR_bit(const void *const hw)
{
	return (((Crccu *)hw)->CRCCU_DMA_IMR & CRCCU_DMA_IMR_DMAIMR) >> CRCCU_DMA_IMR_DMAIMR_Pos;
}

static inline void hri_crccu_write_DMA_IMR_DMAIMR_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Crccu *)hw)->CRCCU_DMA_IDR = CRCCU_DMA_IMR_DMAIMR;
	} else {
		((Crccu *)hw)->CRCCU_DMA_IER = CRCCU_DMA_IMR_DMAIMR;
	}
}

static inline void hri_crccu_clear_DMA_IMR_DMAIMR_bit(const void *const hw)
{
	((Crccu *)hw)->CRCCU_DMA_IDR = CRCCU_DMA_IMR_DMAIMR;
}

static inline void hri_crccu_set_DMA_IMR_reg(const void *const hw, hri_crccu_dma_imr_reg_t mask)
{
	((Crccu *)hw)->CRCCU_DMA_IER = mask;
}

static inline hri_crccu_dma_imr_reg_t hri_crccu_get_DMA_IMR_reg(const void *const hw, hri_crccu_dma_imr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Crccu *)hw)->CRCCU_DMA_IMR;
	tmp &= mask;
	return tmp;
}

static inline hri_crccu_dma_imr_reg_t hri_crccu_read_DMA_IMR_reg(const void *const hw)
{
	return ((Crccu *)hw)->CRCCU_DMA_IMR;
}

static inline void hri_crccu_write_DMA_IMR_reg(const void *const hw, hri_crccu_dma_imr_reg_t data)
{
	((Crccu *)hw)->CRCCU_DMA_IER = data;
	((Crccu *)hw)->CRCCU_DMA_IDR = ~data;
}

static inline void hri_crccu_clear_DMA_IMR_reg(const void *const hw, hri_crccu_dma_imr_reg_t mask)
{
	((Crccu *)hw)->CRCCU_DMA_IDR = mask;
}

static inline void hri_crccu_set_IMR_ERRIMR_bit(const void *const hw)
{
	((Crccu *)hw)->CRCCU_IER = CRCCU_IMR_ERRIMR;
}

static inline bool hri_crccu_get_IMR_ERRIMR_bit(const void *const hw)
{
	return (((Crccu *)hw)->CRCCU_IMR & CRCCU_IMR_ERRIMR) >> CRCCU_IMR_ERRIMR_Pos;
}

static inline void hri_crccu_write_IMR_ERRIMR_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Crccu *)hw)->CRCCU_IDR = CRCCU_IMR_ERRIMR;
	} else {
		((Crccu *)hw)->CRCCU_IER = CRCCU_IMR_ERRIMR;
	}
}

static inline void hri_crccu_clear_IMR_ERRIMR_bit(const void *const hw)
{
	((Crccu *)hw)->CRCCU_IDR = CRCCU_IMR_ERRIMR;
}

static inline void hri_crccu_set_IMR_reg(const void *const hw, hri_crccu_imr_reg_t mask)
{
	((Crccu *)hw)->CRCCU_IER = mask;
}

static inline hri_crccu_imr_reg_t hri_crccu_get_IMR_reg(const void *const hw, hri_crccu_imr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Crccu *)hw)->CRCCU_IMR;
	tmp &= mask;
	return tmp;
}

static inline hri_crccu_imr_reg_t hri_crccu_read_IMR_reg(const void *const hw)
{
	return ((Crccu *)hw)->CRCCU_IMR;
}

static inline void hri_crccu_write_IMR_reg(const void *const hw, hri_crccu_imr_reg_t data)
{
	((Crccu *)hw)->CRCCU_IER = data;
	((Crccu *)hw)->CRCCU_IDR = ~data;
}

static inline void hri_crccu_clear_IMR_reg(const void *const hw, hri_crccu_imr_reg_t mask)
{
	((Crccu *)hw)->CRCCU_IDR = mask;
}

static inline bool hri_crccu_get_DMA_ISR_DMAISR_bit(const void *const hw)
{
	return (((Crccu *)hw)->CRCCU_DMA_ISR & CRCCU_DMA_ISR_DMAISR) >> CRCCU_DMA_ISR_DMAISR_Pos;
}

static inline hri_crccu_dma_isr_reg_t hri_crccu_get_DMA_ISR_reg(const void *const hw, hri_crccu_dma_isr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Crccu *)hw)->CRCCU_DMA_ISR;
	tmp &= mask;
	return tmp;
}

static inline hri_crccu_dma_isr_reg_t hri_crccu_read_DMA_ISR_reg(const void *const hw)
{
	return ((Crccu *)hw)->CRCCU_DMA_ISR;
}

static inline bool hri_crccu_get_ISR_ERRISR_bit(const void *const hw)
{
	return (((Crccu *)hw)->CRCCU_ISR & CRCCU_ISR_ERRISR) >> CRCCU_ISR_ERRISR_Pos;
}

static inline hri_crccu_isr_reg_t hri_crccu_get_ISR_reg(const void *const hw, hri_crccu_isr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Crccu *)hw)->CRCCU_ISR;
	tmp &= mask;
	return tmp;
}

static inline hri_crccu_isr_reg_t hri_crccu_read_ISR_reg(const void *const hw)
{
	return ((Crccu *)hw)->CRCCU_ISR;
}

static inline void hri_crccu_write_DMA_EN_reg(const void *const hw, hri_crccu_dma_en_reg_t data)
{
	CRCCU_CRITICAL_SECTION_ENTER();
	((Crccu *)hw)->CRCCU_DMA_EN = data;
	CRCCU_CRITICAL_SECTION_LEAVE();
}

static inline void hri_crccu_write_DMA_DIS_reg(const void *const hw, hri_crccu_dma_dis_reg_t data)
{
	CRCCU_CRITICAL_SECTION_ENTER();
	((Crccu *)hw)->CRCCU_DMA_DIS = data;
	CRCCU_CRITICAL_SECTION_LEAVE();
}

static inline void hri_crccu_write_CR_reg(const void *const hw, hri_crccu_cr_reg_t data)
{
	CRCCU_CRITICAL_SECTION_ENTER();
	((Crccu *)hw)->CRCCU_CR = data;
	CRCCU_CRITICAL_SECTION_LEAVE();
}

static inline void hri_crccu_set_DSCR_DSCR_bf(const void *const hw, hri_crccu_dscr_reg_t mask)
{
	CRCCU_CRITICAL_SECTION_ENTER();
	((Crccu *)hw)->CRCCU_DSCR |= CRCCU_DSCR_DSCR(mask);
	CRCCU_CRITICAL_SECTION_LEAVE();
}

static inline hri_crccu_dscr_reg_t hri_crccu_get_DSCR_DSCR_bf(const void *const hw, hri_crccu_dscr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Crccu *)hw)->CRCCU_DSCR;
	tmp = (tmp & CRCCU_DSCR_DSCR(mask)) >> CRCCU_DSCR_DSCR_Pos;
	return tmp;
}

static inline void hri_crccu_write_DSCR_DSCR_bf(const void *const hw, hri_crccu_dscr_reg_t data)
{
	uint32_t tmp;
	CRCCU_CRITICAL_SECTION_ENTER();
	tmp = ((Crccu *)hw)->CRCCU_DSCR;
	tmp &= ~CRCCU_DSCR_DSCR_Msk;
	tmp |= CRCCU_DSCR_DSCR(data);
	((Crccu *)hw)->CRCCU_DSCR = tmp;
	CRCCU_CRITICAL_SECTION_LEAVE();
}

static inline void hri_crccu_clear_DSCR_DSCR_bf(const void *const hw, hri_crccu_dscr_reg_t mask)
{
	CRCCU_CRITICAL_SECTION_ENTER();
	((Crccu *)hw)->CRCCU_DSCR &= ~CRCCU_DSCR_DSCR(mask);
	CRCCU_CRITICAL_SECTION_LEAVE();
}

static inline void hri_crccu_toggle_DSCR_DSCR_bf(const void *const hw, hri_crccu_dscr_reg_t mask)
{
	CRCCU_CRITICAL_SECTION_ENTER();
	((Crccu *)hw)->CRCCU_DSCR ^= CRCCU_DSCR_DSCR(mask);
	CRCCU_CRITICAL_SECTION_LEAVE();
}

static inline hri_crccu_dscr_reg_t hri_crccu_read_DSCR_DSCR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Crccu *)hw)->CRCCU_DSCR;
	tmp = (tmp & CRCCU_DSCR_DSCR_Msk) >> CRCCU_DSCR_DSCR_Pos;
	return tmp;
}

static inline void hri_crccu_set_DSCR_reg(const void *const hw, hri_crccu_dscr_reg_t mask)
{
	CRCCU_CRITICAL_SECTION_ENTER();
	((Crccu *)hw)->CRCCU_DSCR |= mask;
	CRCCU_CRITICAL_SECTION_LEAVE();
}

static inline hri_crccu_dscr_reg_t hri_crccu_get_DSCR_reg(const void *const hw, hri_crccu_dscr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Crccu *)hw)->CRCCU_DSCR;
	tmp &= mask;
	return tmp;
}

static inline void hri_crccu_write_DSCR_reg(const void *const hw, hri_crccu_dscr_reg_t data)
{
	CRCCU_CRITICAL_SECTION_ENTER();
	((Crccu *)hw)->CRCCU_DSCR = data;
	CRCCU_CRITICAL_SECTION_LEAVE();
}

static inline void hri_crccu_clear_DSCR_reg(const void *const hw, hri_crccu_dscr_reg_t mask)
{
	CRCCU_CRITICAL_SECTION_ENTER();
	((Crccu *)hw)->CRCCU_DSCR &= ~mask;
	CRCCU_CRITICAL_SECTION_LEAVE();
}

static inline void hri_crccu_toggle_DSCR_reg(const void *const hw, hri_crccu_dscr_reg_t mask)
{
	CRCCU_CRITICAL_SECTION_ENTER();
	((Crccu *)hw)->CRCCU_DSCR ^= mask;
	CRCCU_CRITICAL_SECTION_LEAVE();
}

static inline hri_crccu_dscr_reg_t hri_crccu_read_DSCR_reg(const void *const hw)
{
	return ((Crccu *)hw)->CRCCU_DSCR;
}

static inline void hri_crccu_set_MR_ENABLE_bit(const void *const hw)
{
	CRCCU_CRITICAL_SECTION_ENTER();
	((Crccu *)hw)->CRCCU_MR |= CRCCU_MR_ENABLE;
	CRCCU_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_crccu_get_MR_ENABLE_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Crccu *)hw)->CRCCU_MR;
	tmp = (tmp & CRCCU_MR_ENABLE) >> CRCCU_MR_ENABLE_Pos;
	return (bool)tmp;
}

static inline void hri_crccu_write_MR_ENABLE_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	CRCCU_CRITICAL_SECTION_ENTER();
	tmp = ((Crccu *)hw)->CRCCU_MR;
	tmp &= ~CRCCU_MR_ENABLE;
	tmp |= value << CRCCU_MR_ENABLE_Pos;
	((Crccu *)hw)->CRCCU_MR = tmp;
	CRCCU_CRITICAL_SECTION_LEAVE();
}

static inline void hri_crccu_clear_MR_ENABLE_bit(const void *const hw)
{
	CRCCU_CRITICAL_SECTION_ENTER();
	((Crccu *)hw)->CRCCU_MR &= ~CRCCU_MR_ENABLE;
	CRCCU_CRITICAL_SECTION_LEAVE();
}

static inline void hri_crccu_toggle_MR_ENABLE_bit(const void *const hw)
{
	CRCCU_CRITICAL_SECTION_ENTER();
	((Crccu *)hw)->CRCCU_MR ^= CRCCU_MR_ENABLE;
	CRCCU_CRITICAL_SECTION_LEAVE();
}

static inline void hri_crccu_set_MR_COMPARE_bit(const void *const hw)
{
	CRCCU_CRITICAL_SECTION_ENTER();
	((Crccu *)hw)->CRCCU_MR |= CRCCU_MR_COMPARE;
	CRCCU_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_crccu_get_MR_COMPARE_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Crccu *)hw)->CRCCU_MR;
	tmp = (tmp & CRCCU_MR_COMPARE) >> CRCCU_MR_COMPARE_Pos;
	return (bool)tmp;
}

static inline void hri_crccu_write_MR_COMPARE_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	CRCCU_CRITICAL_SECTION_ENTER();
	tmp = ((Crccu *)hw)->CRCCU_MR;
	tmp &= ~CRCCU_MR_COMPARE;
	tmp |= value << CRCCU_MR_COMPARE_Pos;
	((Crccu *)hw)->CRCCU_MR = tmp;
	CRCCU_CRITICAL_SECTION_LEAVE();
}

static inline void hri_crccu_clear_MR_COMPARE_bit(const void *const hw)
{
	CRCCU_CRITICAL_SECTION_ENTER();
	((Crccu *)hw)->CRCCU_MR &= ~CRCCU_MR_COMPARE;
	CRCCU_CRITICAL_SECTION_LEAVE();
}

static inline void hri_crccu_toggle_MR_COMPARE_bit(const void *const hw)
{
	CRCCU_CRITICAL_SECTION_ENTER();
	((Crccu *)hw)->CRCCU_MR ^= CRCCU_MR_COMPARE;
	CRCCU_CRITICAL_SECTION_LEAVE();
}

static inline void hri_crccu_set_MR_BITORDER_bit(const void *const hw)
{
	CRCCU_CRITICAL_SECTION_ENTER();
	((Crccu *)hw)->CRCCU_MR |= CRCCU_MR_BITORDER;
	CRCCU_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_crccu_get_MR_BITORDER_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Crccu *)hw)->CRCCU_MR;
	tmp = (tmp & CRCCU_MR_BITORDER) >> CRCCU_MR_BITORDER_Pos;
	return (bool)tmp;
}

static inline void hri_crccu_write_MR_BITORDER_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	CRCCU_CRITICAL_SECTION_ENTER();
	tmp = ((Crccu *)hw)->CRCCU_MR;
	tmp &= ~CRCCU_MR_BITORDER;
	tmp |= value << CRCCU_MR_BITORDER_Pos;
	((Crccu *)hw)->CRCCU_MR = tmp;
	CRCCU_CRITICAL_SECTION_LEAVE();
}

static inline void hri_crccu_clear_MR_BITORDER_bit(const void *const hw)
{
	CRCCU_CRITICAL_SECTION_ENTER();
	((Crccu *)hw)->CRCCU_MR &= ~CRCCU_MR_BITORDER;
	CRCCU_CRITICAL_SECTION_LEAVE();
}

static inline void hri_crccu_toggle_MR_BITORDER_bit(const void *const hw)
{
	CRCCU_CRITICAL_SECTION_ENTER();
	((Crccu *)hw)->CRCCU_MR ^= CRCCU_MR_BITORDER;
	CRCCU_CRITICAL_SECTION_LEAVE();
}

static inline void hri_crccu_set_MR_PTYPE_bf(const void *const hw, hri_crccu_mr_reg_t mask)
{
	CRCCU_CRITICAL_SECTION_ENTER();
	((Crccu *)hw)->CRCCU_MR |= CRCCU_MR_PTYPE(mask);
	CRCCU_CRITICAL_SECTION_LEAVE();
}

static inline hri_crccu_mr_reg_t hri_crccu_get_MR_PTYPE_bf(const void *const hw, hri_crccu_mr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Crccu *)hw)->CRCCU_MR;
	tmp = (tmp & CRCCU_MR_PTYPE(mask)) >> CRCCU_MR_PTYPE_Pos;
	return tmp;
}

static inline void hri_crccu_write_MR_PTYPE_bf(const void *const hw, hri_crccu_mr_reg_t data)
{
	uint32_t tmp;
	CRCCU_CRITICAL_SECTION_ENTER();
	tmp = ((Crccu *)hw)->CRCCU_MR;
	tmp &= ~CRCCU_MR_PTYPE_Msk;
	tmp |= CRCCU_MR_PTYPE(data);
	((Crccu *)hw)->CRCCU_MR = tmp;
	CRCCU_CRITICAL_SECTION_LEAVE();
}

static inline void hri_crccu_clear_MR_PTYPE_bf(const void *const hw, hri_crccu_mr_reg_t mask)
{
	CRCCU_CRITICAL_SECTION_ENTER();
	((Crccu *)hw)->CRCCU_MR &= ~CRCCU_MR_PTYPE(mask);
	CRCCU_CRITICAL_SECTION_LEAVE();
}

static inline void hri_crccu_toggle_MR_PTYPE_bf(const void *const hw, hri_crccu_mr_reg_t mask)
{
	CRCCU_CRITICAL_SECTION_ENTER();
	((Crccu *)hw)->CRCCU_MR ^= CRCCU_MR_PTYPE(mask);
	CRCCU_CRITICAL_SECTION_LEAVE();
}

static inline hri_crccu_mr_reg_t hri_crccu_read_MR_PTYPE_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Crccu *)hw)->CRCCU_MR;
	tmp = (tmp & CRCCU_MR_PTYPE_Msk) >> CRCCU_MR_PTYPE_Pos;
	return tmp;
}

static inline void hri_crccu_set_MR_DIVIDER_bf(const void *const hw, hri_crccu_mr_reg_t mask)
{
	CRCCU_CRITICAL_SECTION_ENTER();
	((Crccu *)hw)->CRCCU_MR |= CRCCU_MR_DIVIDER(mask);
	CRCCU_CRITICAL_SECTION_LEAVE();
}

static inline hri_crccu_mr_reg_t hri_crccu_get_MR_DIVIDER_bf(const void *const hw, hri_crccu_mr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Crccu *)hw)->CRCCU_MR;
	tmp = (tmp & CRCCU_MR_DIVIDER(mask)) >> CRCCU_MR_DIVIDER_Pos;
	return tmp;
}

static inline void hri_crccu_write_MR_DIVIDER_bf(const void *const hw, hri_crccu_mr_reg_t data)
{
	uint32_t tmp;
	CRCCU_CRITICAL_SECTION_ENTER();
	tmp = ((Crccu *)hw)->CRCCU_MR;
	tmp &= ~CRCCU_MR_DIVIDER_Msk;
	tmp |= CRCCU_MR_DIVIDER(data);
	((Crccu *)hw)->CRCCU_MR = tmp;
	CRCCU_CRITICAL_SECTION_LEAVE();
}

static inline void hri_crccu_clear_MR_DIVIDER_bf(const void *const hw, hri_crccu_mr_reg_t mask)
{
	CRCCU_CRITICAL_SECTION_ENTER();
	((Crccu *)hw)->CRCCU_MR &= ~CRCCU_MR_DIVIDER(mask);
	CRCCU_CRITICAL_SECTION_LEAVE();
}

static inline void hri_crccu_toggle_MR_DIVIDER_bf(const void *const hw, hri_crccu_mr_reg_t mask)
{
	CRCCU_CRITICAL_SECTION_ENTER();
	((Crccu *)hw)->CRCCU_MR ^= CRCCU_MR_DIVIDER(mask);
	CRCCU_CRITICAL_SECTION_LEAVE();
}

static inline hri_crccu_mr_reg_t hri_crccu_read_MR_DIVIDER_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Crccu *)hw)->CRCCU_MR;
	tmp = (tmp & CRCCU_MR_DIVIDER_Msk) >> CRCCU_MR_DIVIDER_Pos;
	return tmp;
}

static inline void hri_crccu_set_MR_reg(const void *const hw, hri_crccu_mr_reg_t mask)
{
	CRCCU_CRITICAL_SECTION_ENTER();
	((Crccu *)hw)->CRCCU_MR |= mask;
	CRCCU_CRITICAL_SECTION_LEAVE();
}

static inline hri_crccu_mr_reg_t hri_crccu_get_MR_reg(const void *const hw, hri_crccu_mr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Crccu *)hw)->CRCCU_MR;
	tmp &= mask;
	return tmp;
}

static inline void hri_crccu_write_MR_reg(const void *const hw, hri_crccu_mr_reg_t data)
{
	CRCCU_CRITICAL_SECTION_ENTER();
	((Crccu *)hw)->CRCCU_MR = data;
	CRCCU_CRITICAL_SECTION_LEAVE();
}

static inline void hri_crccu_clear_MR_reg(const void *const hw, hri_crccu_mr_reg_t mask)
{
	CRCCU_CRITICAL_SECTION_ENTER();
	((Crccu *)hw)->CRCCU_MR &= ~mask;
	CRCCU_CRITICAL_SECTION_LEAVE();
}

static inline void hri_crccu_toggle_MR_reg(const void *const hw, hri_crccu_mr_reg_t mask)
{
	CRCCU_CRITICAL_SECTION_ENTER();
	((Crccu *)hw)->CRCCU_MR ^= mask;
	CRCCU_CRITICAL_SECTION_LEAVE();
}

static inline hri_crccu_mr_reg_t hri_crccu_read_MR_reg(const void *const hw)
{
	return ((Crccu *)hw)->CRCCU_MR;
}

static inline bool hri_crccu_get_DMA_SR_DMASR_bit(const void *const hw)
{
	return (((Crccu *)hw)->CRCCU_DMA_SR & CRCCU_DMA_SR_DMASR) > 0;
}

static inline hri_crccu_dma_sr_reg_t hri_crccu_get_DMA_SR_reg(const void *const hw, hri_crccu_dma_sr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Crccu *)hw)->CRCCU_DMA_SR;
	tmp &= mask;
	return tmp;
}

static inline hri_crccu_dma_sr_reg_t hri_crccu_read_DMA_SR_reg(const void *const hw)
{
	return ((Crccu *)hw)->CRCCU_DMA_SR;
}

static inline hri_crccu_sr_reg_t hri_crccu_get_SR_CRC_bf(const void *const hw, hri_crccu_sr_reg_t mask)
{
	return (((Crccu *)hw)->CRCCU_SR & CRCCU_SR_CRC(mask)) >> CRCCU_SR_CRC_Pos;
}

static inline hri_crccu_sr_reg_t hri_crccu_read_SR_CRC_bf(const void *const hw)
{
	return (((Crccu *)hw)->CRCCU_SR & CRCCU_SR_CRC_Msk) >> CRCCU_SR_CRC_Pos;
}

static inline hri_crccu_sr_reg_t hri_crccu_get_SR_reg(const void *const hw, hri_crccu_sr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Crccu *)hw)->CRCCU_SR;
	tmp &= mask;
	return tmp;
}

static inline hri_crccu_sr_reg_t hri_crccu_read_SR_reg(const void *const hw)
{
	return ((Crccu *)hw)->CRCCU_SR;
}

#ifdef __cplusplus
}
#endif

#endif /* _HRI_CRCCU_G55_H_INCLUDED */
#endif /* _SAMG55_CRCCU_COMPONENT_ */
