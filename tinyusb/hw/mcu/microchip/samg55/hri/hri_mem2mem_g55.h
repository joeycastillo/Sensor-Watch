/**
 * \file
 *
 * \brief SAM MEM2MEM
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

#ifdef _SAMG55_MEM2MEM_COMPONENT_
#ifndef _HRI_MEM2MEM_G55_H_INCLUDED_
#define _HRI_MEM2MEM_G55_H_INCLUDED_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <hal_atomic.h>

#if defined(ENABLE_MEM2MEM_CRITICAL_SECTIONS)
#define MEM2MEM_CRITICAL_SECTION_ENTER() CRITICAL_SECTION_ENTER()
#define MEM2MEM_CRITICAL_SECTION_LEAVE() CRITICAL_SECTION_LEAVE()
#else
#define MEM2MEM_CRITICAL_SECTION_ENTER()
#define MEM2MEM_CRITICAL_SECTION_LEAVE()
#endif

typedef uint32_t hri_mem2mem_imr_reg_t;
typedef uint32_t hri_mem2mem_isr_reg_t;
typedef uint32_t hri_mem2mem_mr_reg_t;
typedef uint32_t hri_mem2mem_ptcr_reg_t;
typedef uint32_t hri_mem2mem_ptsr_reg_t;
typedef uint32_t hri_mem2mem_rcr_reg_t;
typedef uint32_t hri_mem2mem_rncr_reg_t;
typedef uint32_t hri_mem2mem_rnpr_reg_t;
typedef uint32_t hri_mem2mem_rpr_reg_t;
typedef uint32_t hri_mem2mem_tcr_reg_t;
typedef uint32_t hri_mem2mem_thr_reg_t;
typedef uint32_t hri_mem2mem_tncr_reg_t;
typedef uint32_t hri_mem2mem_tnpr_reg_t;
typedef uint32_t hri_mem2mem_tpr_reg_t;

static inline void hri_mem2mem_set_IMR_RXEND_bit(const void *const hw)
{
	((Mem2mem *)hw)->MEM2MEM_IER = MEM2MEM_IMR_RXEND;
}

static inline bool hri_mem2mem_get_IMR_RXEND_bit(const void *const hw)
{
	return (((Mem2mem *)hw)->MEM2MEM_IMR & MEM2MEM_IMR_RXEND) >> MEM2MEM_IMR_RXEND_Pos;
}

static inline void hri_mem2mem_write_IMR_RXEND_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Mem2mem *)hw)->MEM2MEM_IDR = MEM2MEM_IMR_RXEND;
	} else {
		((Mem2mem *)hw)->MEM2MEM_IER = MEM2MEM_IMR_RXEND;
	}
}

static inline void hri_mem2mem_clear_IMR_RXEND_bit(const void *const hw)
{
	((Mem2mem *)hw)->MEM2MEM_IDR = MEM2MEM_IMR_RXEND;
}

static inline void hri_mem2mem_set_IMR_RXBUFF_bit(const void *const hw)
{
	((Mem2mem *)hw)->MEM2MEM_IER = MEM2MEM_IMR_RXBUFF;
}

static inline bool hri_mem2mem_get_IMR_RXBUFF_bit(const void *const hw)
{
	return (((Mem2mem *)hw)->MEM2MEM_IMR & MEM2MEM_IMR_RXBUFF) >> MEM2MEM_IMR_RXBUFF_Pos;
}

static inline void hri_mem2mem_write_IMR_RXBUFF_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Mem2mem *)hw)->MEM2MEM_IDR = MEM2MEM_IMR_RXBUFF;
	} else {
		((Mem2mem *)hw)->MEM2MEM_IER = MEM2MEM_IMR_RXBUFF;
	}
}

static inline void hri_mem2mem_clear_IMR_RXBUFF_bit(const void *const hw)
{
	((Mem2mem *)hw)->MEM2MEM_IDR = MEM2MEM_IMR_RXBUFF;
}

static inline void hri_mem2mem_set_IMR_reg(const void *const hw, hri_mem2mem_imr_reg_t mask)
{
	((Mem2mem *)hw)->MEM2MEM_IER = mask;
}

static inline hri_mem2mem_imr_reg_t hri_mem2mem_get_IMR_reg(const void *const hw, hri_mem2mem_imr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Mem2mem *)hw)->MEM2MEM_IMR;
	tmp &= mask;
	return tmp;
}

static inline hri_mem2mem_imr_reg_t hri_mem2mem_read_IMR_reg(const void *const hw)
{
	return ((Mem2mem *)hw)->MEM2MEM_IMR;
}

static inline void hri_mem2mem_write_IMR_reg(const void *const hw, hri_mem2mem_imr_reg_t data)
{
	((Mem2mem *)hw)->MEM2MEM_IER = data;
	((Mem2mem *)hw)->MEM2MEM_IDR = ~data;
}

static inline void hri_mem2mem_clear_IMR_reg(const void *const hw, hri_mem2mem_imr_reg_t mask)
{
	((Mem2mem *)hw)->MEM2MEM_IDR = mask;
}

static inline bool hri_mem2mem_get_ISR_RXEND_bit(const void *const hw)
{
	return (((Mem2mem *)hw)->MEM2MEM_ISR & MEM2MEM_ISR_RXEND) >> MEM2MEM_ISR_RXEND_Pos;
}

static inline bool hri_mem2mem_get_ISR_RXBUFF_bit(const void *const hw)
{
	return (((Mem2mem *)hw)->MEM2MEM_ISR & MEM2MEM_ISR_RXBUFF) >> MEM2MEM_ISR_RXBUFF_Pos;
}

static inline hri_mem2mem_isr_reg_t hri_mem2mem_get_ISR_reg(const void *const hw, hri_mem2mem_isr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Mem2mem *)hw)->MEM2MEM_ISR;
	tmp &= mask;
	return tmp;
}

static inline hri_mem2mem_isr_reg_t hri_mem2mem_read_ISR_reg(const void *const hw)
{
	return ((Mem2mem *)hw)->MEM2MEM_ISR;
}

static inline void hri_mem2mem_write_PTCR_reg(const void *const hw, hri_mem2mem_ptcr_reg_t data)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_PTCR = data;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_set_THR_THDATA_bf(const void *const hw, hri_mem2mem_thr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_THR |= MEM2MEM_THR_THDATA(mask);
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_thr_reg_t hri_mem2mem_get_THR_THDATA_bf(const void *const hw, hri_mem2mem_thr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Mem2mem *)hw)->MEM2MEM_THR;
	tmp = (tmp & MEM2MEM_THR_THDATA(mask)) >> MEM2MEM_THR_THDATA_Pos;
	return tmp;
}

static inline void hri_mem2mem_write_THR_THDATA_bf(const void *const hw, hri_mem2mem_thr_reg_t data)
{
	uint32_t tmp;
	MEM2MEM_CRITICAL_SECTION_ENTER();
	tmp = ((Mem2mem *)hw)->MEM2MEM_THR;
	tmp &= ~MEM2MEM_THR_THDATA_Msk;
	tmp |= MEM2MEM_THR_THDATA(data);
	((Mem2mem *)hw)->MEM2MEM_THR = tmp;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_clear_THR_THDATA_bf(const void *const hw, hri_mem2mem_thr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_THR &= ~MEM2MEM_THR_THDATA(mask);
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_toggle_THR_THDATA_bf(const void *const hw, hri_mem2mem_thr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_THR ^= MEM2MEM_THR_THDATA(mask);
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_thr_reg_t hri_mem2mem_read_THR_THDATA_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Mem2mem *)hw)->MEM2MEM_THR;
	tmp = (tmp & MEM2MEM_THR_THDATA_Msk) >> MEM2MEM_THR_THDATA_Pos;
	return tmp;
}

static inline void hri_mem2mem_set_THR_reg(const void *const hw, hri_mem2mem_thr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_THR |= mask;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_thr_reg_t hri_mem2mem_get_THR_reg(const void *const hw, hri_mem2mem_thr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Mem2mem *)hw)->MEM2MEM_THR;
	tmp &= mask;
	return tmp;
}

static inline void hri_mem2mem_write_THR_reg(const void *const hw, hri_mem2mem_thr_reg_t data)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_THR = data;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_clear_THR_reg(const void *const hw, hri_mem2mem_thr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_THR &= ~mask;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_toggle_THR_reg(const void *const hw, hri_mem2mem_thr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_THR ^= mask;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_thr_reg_t hri_mem2mem_read_THR_reg(const void *const hw)
{
	return ((Mem2mem *)hw)->MEM2MEM_THR;
}

static inline void hri_mem2mem_set_MR_TSIZE_bf(const void *const hw, hri_mem2mem_mr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_MR |= MEM2MEM_MR_TSIZE(mask);
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_mr_reg_t hri_mem2mem_get_MR_TSIZE_bf(const void *const hw, hri_mem2mem_mr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Mem2mem *)hw)->MEM2MEM_MR;
	tmp = (tmp & MEM2MEM_MR_TSIZE(mask)) >> MEM2MEM_MR_TSIZE_Pos;
	return tmp;
}

static inline void hri_mem2mem_write_MR_TSIZE_bf(const void *const hw, hri_mem2mem_mr_reg_t data)
{
	uint32_t tmp;
	MEM2MEM_CRITICAL_SECTION_ENTER();
	tmp = ((Mem2mem *)hw)->MEM2MEM_MR;
	tmp &= ~MEM2MEM_MR_TSIZE_Msk;
	tmp |= MEM2MEM_MR_TSIZE(data);
	((Mem2mem *)hw)->MEM2MEM_MR = tmp;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_clear_MR_TSIZE_bf(const void *const hw, hri_mem2mem_mr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_MR &= ~MEM2MEM_MR_TSIZE(mask);
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_toggle_MR_TSIZE_bf(const void *const hw, hri_mem2mem_mr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_MR ^= MEM2MEM_MR_TSIZE(mask);
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_mr_reg_t hri_mem2mem_read_MR_TSIZE_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Mem2mem *)hw)->MEM2MEM_MR;
	tmp = (tmp & MEM2MEM_MR_TSIZE_Msk) >> MEM2MEM_MR_TSIZE_Pos;
	return tmp;
}

static inline void hri_mem2mem_set_MR_reg(const void *const hw, hri_mem2mem_mr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_MR |= mask;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_mr_reg_t hri_mem2mem_get_MR_reg(const void *const hw, hri_mem2mem_mr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Mem2mem *)hw)->MEM2MEM_MR;
	tmp &= mask;
	return tmp;
}

static inline void hri_mem2mem_write_MR_reg(const void *const hw, hri_mem2mem_mr_reg_t data)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_MR = data;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_clear_MR_reg(const void *const hw, hri_mem2mem_mr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_MR &= ~mask;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_toggle_MR_reg(const void *const hw, hri_mem2mem_mr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_MR ^= mask;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_mr_reg_t hri_mem2mem_read_MR_reg(const void *const hw)
{
	return ((Mem2mem *)hw)->MEM2MEM_MR;
}

static inline void hri_mem2mem_set_RPR_RXPTR_bf(const void *const hw, hri_mem2mem_rpr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_RPR |= MEM2MEM_RPR_RXPTR(mask);
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_rpr_reg_t hri_mem2mem_get_RPR_RXPTR_bf(const void *const hw, hri_mem2mem_rpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Mem2mem *)hw)->MEM2MEM_RPR;
	tmp = (tmp & MEM2MEM_RPR_RXPTR(mask)) >> MEM2MEM_RPR_RXPTR_Pos;
	return tmp;
}

static inline void hri_mem2mem_write_RPR_RXPTR_bf(const void *const hw, hri_mem2mem_rpr_reg_t data)
{
	uint32_t tmp;
	MEM2MEM_CRITICAL_SECTION_ENTER();
	tmp = ((Mem2mem *)hw)->MEM2MEM_RPR;
	tmp &= ~MEM2MEM_RPR_RXPTR_Msk;
	tmp |= MEM2MEM_RPR_RXPTR(data);
	((Mem2mem *)hw)->MEM2MEM_RPR = tmp;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_clear_RPR_RXPTR_bf(const void *const hw, hri_mem2mem_rpr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_RPR &= ~MEM2MEM_RPR_RXPTR(mask);
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_toggle_RPR_RXPTR_bf(const void *const hw, hri_mem2mem_rpr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_RPR ^= MEM2MEM_RPR_RXPTR(mask);
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_rpr_reg_t hri_mem2mem_read_RPR_RXPTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Mem2mem *)hw)->MEM2MEM_RPR;
	tmp = (tmp & MEM2MEM_RPR_RXPTR_Msk) >> MEM2MEM_RPR_RXPTR_Pos;
	return tmp;
}

static inline void hri_mem2mem_set_RPR_reg(const void *const hw, hri_mem2mem_rpr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_RPR |= mask;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_rpr_reg_t hri_mem2mem_get_RPR_reg(const void *const hw, hri_mem2mem_rpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Mem2mem *)hw)->MEM2MEM_RPR;
	tmp &= mask;
	return tmp;
}

static inline void hri_mem2mem_write_RPR_reg(const void *const hw, hri_mem2mem_rpr_reg_t data)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_RPR = data;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_clear_RPR_reg(const void *const hw, hri_mem2mem_rpr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_RPR &= ~mask;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_toggle_RPR_reg(const void *const hw, hri_mem2mem_rpr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_RPR ^= mask;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_rpr_reg_t hri_mem2mem_read_RPR_reg(const void *const hw)
{
	return ((Mem2mem *)hw)->MEM2MEM_RPR;
}

static inline void hri_mem2mem_set_RCR_RXCTR_bf(const void *const hw, hri_mem2mem_rcr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_RCR |= MEM2MEM_RCR_RXCTR(mask);
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_rcr_reg_t hri_mem2mem_get_RCR_RXCTR_bf(const void *const hw, hri_mem2mem_rcr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Mem2mem *)hw)->MEM2MEM_RCR;
	tmp = (tmp & MEM2MEM_RCR_RXCTR(mask)) >> MEM2MEM_RCR_RXCTR_Pos;
	return tmp;
}

static inline void hri_mem2mem_write_RCR_RXCTR_bf(const void *const hw, hri_mem2mem_rcr_reg_t data)
{
	uint32_t tmp;
	MEM2MEM_CRITICAL_SECTION_ENTER();
	tmp = ((Mem2mem *)hw)->MEM2MEM_RCR;
	tmp &= ~MEM2MEM_RCR_RXCTR_Msk;
	tmp |= MEM2MEM_RCR_RXCTR(data);
	((Mem2mem *)hw)->MEM2MEM_RCR = tmp;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_clear_RCR_RXCTR_bf(const void *const hw, hri_mem2mem_rcr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_RCR &= ~MEM2MEM_RCR_RXCTR(mask);
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_toggle_RCR_RXCTR_bf(const void *const hw, hri_mem2mem_rcr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_RCR ^= MEM2MEM_RCR_RXCTR(mask);
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_rcr_reg_t hri_mem2mem_read_RCR_RXCTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Mem2mem *)hw)->MEM2MEM_RCR;
	tmp = (tmp & MEM2MEM_RCR_RXCTR_Msk) >> MEM2MEM_RCR_RXCTR_Pos;
	return tmp;
}

static inline void hri_mem2mem_set_RCR_reg(const void *const hw, hri_mem2mem_rcr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_RCR |= mask;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_rcr_reg_t hri_mem2mem_get_RCR_reg(const void *const hw, hri_mem2mem_rcr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Mem2mem *)hw)->MEM2MEM_RCR;
	tmp &= mask;
	return tmp;
}

static inline void hri_mem2mem_write_RCR_reg(const void *const hw, hri_mem2mem_rcr_reg_t data)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_RCR = data;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_clear_RCR_reg(const void *const hw, hri_mem2mem_rcr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_RCR &= ~mask;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_toggle_RCR_reg(const void *const hw, hri_mem2mem_rcr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_RCR ^= mask;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_rcr_reg_t hri_mem2mem_read_RCR_reg(const void *const hw)
{
	return ((Mem2mem *)hw)->MEM2MEM_RCR;
}

static inline void hri_mem2mem_set_TPR_TXPTR_bf(const void *const hw, hri_mem2mem_tpr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_TPR |= MEM2MEM_TPR_TXPTR(mask);
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_tpr_reg_t hri_mem2mem_get_TPR_TXPTR_bf(const void *const hw, hri_mem2mem_tpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Mem2mem *)hw)->MEM2MEM_TPR;
	tmp = (tmp & MEM2MEM_TPR_TXPTR(mask)) >> MEM2MEM_TPR_TXPTR_Pos;
	return tmp;
}

static inline void hri_mem2mem_write_TPR_TXPTR_bf(const void *const hw, hri_mem2mem_tpr_reg_t data)
{
	uint32_t tmp;
	MEM2MEM_CRITICAL_SECTION_ENTER();
	tmp = ((Mem2mem *)hw)->MEM2MEM_TPR;
	tmp &= ~MEM2MEM_TPR_TXPTR_Msk;
	tmp |= MEM2MEM_TPR_TXPTR(data);
	((Mem2mem *)hw)->MEM2MEM_TPR = tmp;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_clear_TPR_TXPTR_bf(const void *const hw, hri_mem2mem_tpr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_TPR &= ~MEM2MEM_TPR_TXPTR(mask);
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_toggle_TPR_TXPTR_bf(const void *const hw, hri_mem2mem_tpr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_TPR ^= MEM2MEM_TPR_TXPTR(mask);
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_tpr_reg_t hri_mem2mem_read_TPR_TXPTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Mem2mem *)hw)->MEM2MEM_TPR;
	tmp = (tmp & MEM2MEM_TPR_TXPTR_Msk) >> MEM2MEM_TPR_TXPTR_Pos;
	return tmp;
}

static inline void hri_mem2mem_set_TPR_reg(const void *const hw, hri_mem2mem_tpr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_TPR |= mask;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_tpr_reg_t hri_mem2mem_get_TPR_reg(const void *const hw, hri_mem2mem_tpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Mem2mem *)hw)->MEM2MEM_TPR;
	tmp &= mask;
	return tmp;
}

static inline void hri_mem2mem_write_TPR_reg(const void *const hw, hri_mem2mem_tpr_reg_t data)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_TPR = data;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_clear_TPR_reg(const void *const hw, hri_mem2mem_tpr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_TPR &= ~mask;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_toggle_TPR_reg(const void *const hw, hri_mem2mem_tpr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_TPR ^= mask;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_tpr_reg_t hri_mem2mem_read_TPR_reg(const void *const hw)
{
	return ((Mem2mem *)hw)->MEM2MEM_TPR;
}

static inline void hri_mem2mem_set_TCR_TXCTR_bf(const void *const hw, hri_mem2mem_tcr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_TCR |= MEM2MEM_TCR_TXCTR(mask);
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_tcr_reg_t hri_mem2mem_get_TCR_TXCTR_bf(const void *const hw, hri_mem2mem_tcr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Mem2mem *)hw)->MEM2MEM_TCR;
	tmp = (tmp & MEM2MEM_TCR_TXCTR(mask)) >> MEM2MEM_TCR_TXCTR_Pos;
	return tmp;
}

static inline void hri_mem2mem_write_TCR_TXCTR_bf(const void *const hw, hri_mem2mem_tcr_reg_t data)
{
	uint32_t tmp;
	MEM2MEM_CRITICAL_SECTION_ENTER();
	tmp = ((Mem2mem *)hw)->MEM2MEM_TCR;
	tmp &= ~MEM2MEM_TCR_TXCTR_Msk;
	tmp |= MEM2MEM_TCR_TXCTR(data);
	((Mem2mem *)hw)->MEM2MEM_TCR = tmp;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_clear_TCR_TXCTR_bf(const void *const hw, hri_mem2mem_tcr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_TCR &= ~MEM2MEM_TCR_TXCTR(mask);
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_toggle_TCR_TXCTR_bf(const void *const hw, hri_mem2mem_tcr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_TCR ^= MEM2MEM_TCR_TXCTR(mask);
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_tcr_reg_t hri_mem2mem_read_TCR_TXCTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Mem2mem *)hw)->MEM2MEM_TCR;
	tmp = (tmp & MEM2MEM_TCR_TXCTR_Msk) >> MEM2MEM_TCR_TXCTR_Pos;
	return tmp;
}

static inline void hri_mem2mem_set_TCR_reg(const void *const hw, hri_mem2mem_tcr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_TCR |= mask;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_tcr_reg_t hri_mem2mem_get_TCR_reg(const void *const hw, hri_mem2mem_tcr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Mem2mem *)hw)->MEM2MEM_TCR;
	tmp &= mask;
	return tmp;
}

static inline void hri_mem2mem_write_TCR_reg(const void *const hw, hri_mem2mem_tcr_reg_t data)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_TCR = data;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_clear_TCR_reg(const void *const hw, hri_mem2mem_tcr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_TCR &= ~mask;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_toggle_TCR_reg(const void *const hw, hri_mem2mem_tcr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_TCR ^= mask;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_tcr_reg_t hri_mem2mem_read_TCR_reg(const void *const hw)
{
	return ((Mem2mem *)hw)->MEM2MEM_TCR;
}

static inline void hri_mem2mem_set_RNPR_RXNPTR_bf(const void *const hw, hri_mem2mem_rnpr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_RNPR |= MEM2MEM_RNPR_RXNPTR(mask);
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_rnpr_reg_t hri_mem2mem_get_RNPR_RXNPTR_bf(const void *const hw, hri_mem2mem_rnpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Mem2mem *)hw)->MEM2MEM_RNPR;
	tmp = (tmp & MEM2MEM_RNPR_RXNPTR(mask)) >> MEM2MEM_RNPR_RXNPTR_Pos;
	return tmp;
}

static inline void hri_mem2mem_write_RNPR_RXNPTR_bf(const void *const hw, hri_mem2mem_rnpr_reg_t data)
{
	uint32_t tmp;
	MEM2MEM_CRITICAL_SECTION_ENTER();
	tmp = ((Mem2mem *)hw)->MEM2MEM_RNPR;
	tmp &= ~MEM2MEM_RNPR_RXNPTR_Msk;
	tmp |= MEM2MEM_RNPR_RXNPTR(data);
	((Mem2mem *)hw)->MEM2MEM_RNPR = tmp;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_clear_RNPR_RXNPTR_bf(const void *const hw, hri_mem2mem_rnpr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_RNPR &= ~MEM2MEM_RNPR_RXNPTR(mask);
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_toggle_RNPR_RXNPTR_bf(const void *const hw, hri_mem2mem_rnpr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_RNPR ^= MEM2MEM_RNPR_RXNPTR(mask);
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_rnpr_reg_t hri_mem2mem_read_RNPR_RXNPTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Mem2mem *)hw)->MEM2MEM_RNPR;
	tmp = (tmp & MEM2MEM_RNPR_RXNPTR_Msk) >> MEM2MEM_RNPR_RXNPTR_Pos;
	return tmp;
}

static inline void hri_mem2mem_set_RNPR_reg(const void *const hw, hri_mem2mem_rnpr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_RNPR |= mask;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_rnpr_reg_t hri_mem2mem_get_RNPR_reg(const void *const hw, hri_mem2mem_rnpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Mem2mem *)hw)->MEM2MEM_RNPR;
	tmp &= mask;
	return tmp;
}

static inline void hri_mem2mem_write_RNPR_reg(const void *const hw, hri_mem2mem_rnpr_reg_t data)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_RNPR = data;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_clear_RNPR_reg(const void *const hw, hri_mem2mem_rnpr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_RNPR &= ~mask;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_toggle_RNPR_reg(const void *const hw, hri_mem2mem_rnpr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_RNPR ^= mask;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_rnpr_reg_t hri_mem2mem_read_RNPR_reg(const void *const hw)
{
	return ((Mem2mem *)hw)->MEM2MEM_RNPR;
}

static inline void hri_mem2mem_set_RNCR_RXNCTR_bf(const void *const hw, hri_mem2mem_rncr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_RNCR |= MEM2MEM_RNCR_RXNCTR(mask);
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_rncr_reg_t hri_mem2mem_get_RNCR_RXNCTR_bf(const void *const hw, hri_mem2mem_rncr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Mem2mem *)hw)->MEM2MEM_RNCR;
	tmp = (tmp & MEM2MEM_RNCR_RXNCTR(mask)) >> MEM2MEM_RNCR_RXNCTR_Pos;
	return tmp;
}

static inline void hri_mem2mem_write_RNCR_RXNCTR_bf(const void *const hw, hri_mem2mem_rncr_reg_t data)
{
	uint32_t tmp;
	MEM2MEM_CRITICAL_SECTION_ENTER();
	tmp = ((Mem2mem *)hw)->MEM2MEM_RNCR;
	tmp &= ~MEM2MEM_RNCR_RXNCTR_Msk;
	tmp |= MEM2MEM_RNCR_RXNCTR(data);
	((Mem2mem *)hw)->MEM2MEM_RNCR = tmp;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_clear_RNCR_RXNCTR_bf(const void *const hw, hri_mem2mem_rncr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_RNCR &= ~MEM2MEM_RNCR_RXNCTR(mask);
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_toggle_RNCR_RXNCTR_bf(const void *const hw, hri_mem2mem_rncr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_RNCR ^= MEM2MEM_RNCR_RXNCTR(mask);
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_rncr_reg_t hri_mem2mem_read_RNCR_RXNCTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Mem2mem *)hw)->MEM2MEM_RNCR;
	tmp = (tmp & MEM2MEM_RNCR_RXNCTR_Msk) >> MEM2MEM_RNCR_RXNCTR_Pos;
	return tmp;
}

static inline void hri_mem2mem_set_RNCR_reg(const void *const hw, hri_mem2mem_rncr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_RNCR |= mask;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_rncr_reg_t hri_mem2mem_get_RNCR_reg(const void *const hw, hri_mem2mem_rncr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Mem2mem *)hw)->MEM2MEM_RNCR;
	tmp &= mask;
	return tmp;
}

static inline void hri_mem2mem_write_RNCR_reg(const void *const hw, hri_mem2mem_rncr_reg_t data)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_RNCR = data;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_clear_RNCR_reg(const void *const hw, hri_mem2mem_rncr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_RNCR &= ~mask;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_toggle_RNCR_reg(const void *const hw, hri_mem2mem_rncr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_RNCR ^= mask;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_rncr_reg_t hri_mem2mem_read_RNCR_reg(const void *const hw)
{
	return ((Mem2mem *)hw)->MEM2MEM_RNCR;
}

static inline void hri_mem2mem_set_TNPR_TXNPTR_bf(const void *const hw, hri_mem2mem_tnpr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_TNPR |= MEM2MEM_TNPR_TXNPTR(mask);
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_tnpr_reg_t hri_mem2mem_get_TNPR_TXNPTR_bf(const void *const hw, hri_mem2mem_tnpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Mem2mem *)hw)->MEM2MEM_TNPR;
	tmp = (tmp & MEM2MEM_TNPR_TXNPTR(mask)) >> MEM2MEM_TNPR_TXNPTR_Pos;
	return tmp;
}

static inline void hri_mem2mem_write_TNPR_TXNPTR_bf(const void *const hw, hri_mem2mem_tnpr_reg_t data)
{
	uint32_t tmp;
	MEM2MEM_CRITICAL_SECTION_ENTER();
	tmp = ((Mem2mem *)hw)->MEM2MEM_TNPR;
	tmp &= ~MEM2MEM_TNPR_TXNPTR_Msk;
	tmp |= MEM2MEM_TNPR_TXNPTR(data);
	((Mem2mem *)hw)->MEM2MEM_TNPR = tmp;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_clear_TNPR_TXNPTR_bf(const void *const hw, hri_mem2mem_tnpr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_TNPR &= ~MEM2MEM_TNPR_TXNPTR(mask);
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_toggle_TNPR_TXNPTR_bf(const void *const hw, hri_mem2mem_tnpr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_TNPR ^= MEM2MEM_TNPR_TXNPTR(mask);
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_tnpr_reg_t hri_mem2mem_read_TNPR_TXNPTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Mem2mem *)hw)->MEM2MEM_TNPR;
	tmp = (tmp & MEM2MEM_TNPR_TXNPTR_Msk) >> MEM2MEM_TNPR_TXNPTR_Pos;
	return tmp;
}

static inline void hri_mem2mem_set_TNPR_reg(const void *const hw, hri_mem2mem_tnpr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_TNPR |= mask;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_tnpr_reg_t hri_mem2mem_get_TNPR_reg(const void *const hw, hri_mem2mem_tnpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Mem2mem *)hw)->MEM2MEM_TNPR;
	tmp &= mask;
	return tmp;
}

static inline void hri_mem2mem_write_TNPR_reg(const void *const hw, hri_mem2mem_tnpr_reg_t data)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_TNPR = data;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_clear_TNPR_reg(const void *const hw, hri_mem2mem_tnpr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_TNPR &= ~mask;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_toggle_TNPR_reg(const void *const hw, hri_mem2mem_tnpr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_TNPR ^= mask;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_tnpr_reg_t hri_mem2mem_read_TNPR_reg(const void *const hw)
{
	return ((Mem2mem *)hw)->MEM2MEM_TNPR;
}

static inline void hri_mem2mem_set_TNCR_TXNCTR_bf(const void *const hw, hri_mem2mem_tncr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_TNCR |= MEM2MEM_TNCR_TXNCTR(mask);
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_tncr_reg_t hri_mem2mem_get_TNCR_TXNCTR_bf(const void *const hw, hri_mem2mem_tncr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Mem2mem *)hw)->MEM2MEM_TNCR;
	tmp = (tmp & MEM2MEM_TNCR_TXNCTR(mask)) >> MEM2MEM_TNCR_TXNCTR_Pos;
	return tmp;
}

static inline void hri_mem2mem_write_TNCR_TXNCTR_bf(const void *const hw, hri_mem2mem_tncr_reg_t data)
{
	uint32_t tmp;
	MEM2MEM_CRITICAL_SECTION_ENTER();
	tmp = ((Mem2mem *)hw)->MEM2MEM_TNCR;
	tmp &= ~MEM2MEM_TNCR_TXNCTR_Msk;
	tmp |= MEM2MEM_TNCR_TXNCTR(data);
	((Mem2mem *)hw)->MEM2MEM_TNCR = tmp;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_clear_TNCR_TXNCTR_bf(const void *const hw, hri_mem2mem_tncr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_TNCR &= ~MEM2MEM_TNCR_TXNCTR(mask);
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_toggle_TNCR_TXNCTR_bf(const void *const hw, hri_mem2mem_tncr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_TNCR ^= MEM2MEM_TNCR_TXNCTR(mask);
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_tncr_reg_t hri_mem2mem_read_TNCR_TXNCTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Mem2mem *)hw)->MEM2MEM_TNCR;
	tmp = (tmp & MEM2MEM_TNCR_TXNCTR_Msk) >> MEM2MEM_TNCR_TXNCTR_Pos;
	return tmp;
}

static inline void hri_mem2mem_set_TNCR_reg(const void *const hw, hri_mem2mem_tncr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_TNCR |= mask;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_tncr_reg_t hri_mem2mem_get_TNCR_reg(const void *const hw, hri_mem2mem_tncr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Mem2mem *)hw)->MEM2MEM_TNCR;
	tmp &= mask;
	return tmp;
}

static inline void hri_mem2mem_write_TNCR_reg(const void *const hw, hri_mem2mem_tncr_reg_t data)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_TNCR = data;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_clear_TNCR_reg(const void *const hw, hri_mem2mem_tncr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_TNCR &= ~mask;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_mem2mem_toggle_TNCR_reg(const void *const hw, hri_mem2mem_tncr_reg_t mask)
{
	MEM2MEM_CRITICAL_SECTION_ENTER();
	((Mem2mem *)hw)->MEM2MEM_TNCR ^= mask;
	MEM2MEM_CRITICAL_SECTION_LEAVE();
}

static inline hri_mem2mem_tncr_reg_t hri_mem2mem_read_TNCR_reg(const void *const hw)
{
	return ((Mem2mem *)hw)->MEM2MEM_TNCR;
}

static inline bool hri_mem2mem_get_PTSR_RXTEN_bit(const void *const hw)
{
	return (((Mem2mem *)hw)->MEM2MEM_PTSR & MEM2MEM_PTSR_RXTEN) > 0;
}

static inline bool hri_mem2mem_get_PTSR_TXTEN_bit(const void *const hw)
{
	return (((Mem2mem *)hw)->MEM2MEM_PTSR & MEM2MEM_PTSR_TXTEN) > 0;
}

static inline bool hri_mem2mem_get_PTSR_RXCBEN_bit(const void *const hw)
{
	return (((Mem2mem *)hw)->MEM2MEM_PTSR & MEM2MEM_PTSR_RXCBEN) > 0;
}

static inline bool hri_mem2mem_get_PTSR_TXCBEN_bit(const void *const hw)
{
	return (((Mem2mem *)hw)->MEM2MEM_PTSR & MEM2MEM_PTSR_TXCBEN) > 0;
}

static inline bool hri_mem2mem_get_PTSR_ERR_bit(const void *const hw)
{
	return (((Mem2mem *)hw)->MEM2MEM_PTSR & MEM2MEM_PTSR_ERR) > 0;
}

static inline hri_mem2mem_ptsr_reg_t hri_mem2mem_get_PTSR_reg(const void *const hw, hri_mem2mem_ptsr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Mem2mem *)hw)->MEM2MEM_PTSR;
	tmp &= mask;
	return tmp;
}

static inline hri_mem2mem_ptsr_reg_t hri_mem2mem_read_PTSR_reg(const void *const hw)
{
	return ((Mem2mem *)hw)->MEM2MEM_PTSR;
}

#ifdef __cplusplus
}
#endif

#endif /* _HRI_MEM2MEM_G55_H_INCLUDED */
#endif /* _SAMG55_MEM2MEM_COMPONENT_ */
