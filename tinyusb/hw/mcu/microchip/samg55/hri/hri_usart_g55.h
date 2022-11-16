/**
 * \file
 *
 * \brief SAM USART
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

#ifdef _SAMG55_USART_COMPONENT_
#ifndef _HRI_USART_G55_H_INCLUDED_
#define _HRI_USART_G55_H_INCLUDED_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <hal_atomic.h>

#if defined(ENABLE_USART_CRITICAL_SECTIONS)
#define USART_CRITICAL_SECTION_ENTER() CRITICAL_SECTION_ENTER()
#define USART_CRITICAL_SECTION_LEAVE() CRITICAL_SECTION_LEAVE()
#else
#define USART_CRITICAL_SECTION_ENTER()
#define USART_CRITICAL_SECTION_LEAVE()
#endif

typedef uint32_t hri_usart_us_brgr_reg_t;
typedef uint32_t hri_usart_us_cmpr_reg_t;
typedef uint32_t hri_usart_us_cr_reg_t;
typedef uint32_t hri_usart_us_csr_reg_t;
typedef uint32_t hri_usart_us_fidi_reg_t;
typedef uint32_t hri_usart_us_if_reg_t;
typedef uint32_t hri_usart_us_imr_reg_t;
typedef uint32_t hri_usart_us_linbrr_reg_t;
typedef uint32_t hri_usart_us_linir_reg_t;
typedef uint32_t hri_usart_us_linmr_reg_t;
typedef uint32_t hri_usart_us_mr_reg_t;
typedef uint32_t hri_usart_us_ner_reg_t;
typedef uint32_t hri_usart_us_ptcr_reg_t;
typedef uint32_t hri_usart_us_ptsr_reg_t;
typedef uint32_t hri_usart_us_rcr_reg_t;
typedef uint32_t hri_usart_us_rhr_reg_t;
typedef uint32_t hri_usart_us_rncr_reg_t;
typedef uint32_t hri_usart_us_rnpr_reg_t;
typedef uint32_t hri_usart_us_rpr_reg_t;
typedef uint32_t hri_usart_us_rtor_reg_t;
typedef uint32_t hri_usart_us_tcr_reg_t;
typedef uint32_t hri_usart_us_thr_reg_t;
typedef uint32_t hri_usart_us_tncr_reg_t;
typedef uint32_t hri_usart_us_tnpr_reg_t;
typedef uint32_t hri_usart_us_tpr_reg_t;
typedef uint32_t hri_usart_us_ttgr_reg_t;
typedef uint32_t hri_usart_us_wpmr_reg_t;
typedef uint32_t hri_usart_us_wpsr_reg_t;

static inline void hri_usart_set_US_IMR_RXRDY_bit(const void *const hw)
{
	((Usart *)hw)->US_IER = US_IMR_RXRDY;
}

static inline bool hri_usart_get_US_IMR_RXRDY_bit(const void *const hw)
{
	return (((Usart *)hw)->US_IMR & US_IMR_RXRDY) >> US_IMR_RXRDY_Pos;
}

static inline void hri_usart_write_US_IMR_RXRDY_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Usart *)hw)->US_IDR = US_IMR_RXRDY;
	} else {
		((Usart *)hw)->US_IER = US_IMR_RXRDY;
	}
}

static inline void hri_usart_clear_US_IMR_RXRDY_bit(const void *const hw)
{
	((Usart *)hw)->US_IDR = US_IMR_RXRDY;
}

static inline void hri_usart_set_US_IMR_TXRDY_bit(const void *const hw)
{
	((Usart *)hw)->US_IER = US_IMR_TXRDY;
}

static inline bool hri_usart_get_US_IMR_TXRDY_bit(const void *const hw)
{
	return (((Usart *)hw)->US_IMR & US_IMR_TXRDY) >> US_IMR_TXRDY_Pos;
}

static inline void hri_usart_write_US_IMR_TXRDY_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Usart *)hw)->US_IDR = US_IMR_TXRDY;
	} else {
		((Usart *)hw)->US_IER = US_IMR_TXRDY;
	}
}

static inline void hri_usart_clear_US_IMR_TXRDY_bit(const void *const hw)
{
	((Usart *)hw)->US_IDR = US_IMR_TXRDY;
}

static inline void hri_usart_set_US_IMR_RXBRK_bit(const void *const hw)
{
	((Usart *)hw)->US_IER = US_IMR_RXBRK;
}

static inline bool hri_usart_get_US_IMR_RXBRK_bit(const void *const hw)
{
	return (((Usart *)hw)->US_IMR & US_IMR_RXBRK) >> US_IMR_RXBRK_Pos;
}

static inline void hri_usart_write_US_IMR_RXBRK_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Usart *)hw)->US_IDR = US_IMR_RXBRK;
	} else {
		((Usart *)hw)->US_IER = US_IMR_RXBRK;
	}
}

static inline void hri_usart_clear_US_IMR_RXBRK_bit(const void *const hw)
{
	((Usart *)hw)->US_IDR = US_IMR_RXBRK;
}

static inline void hri_usart_set_US_IMR_ENDRX_bit(const void *const hw)
{
	((Usart *)hw)->US_IER = US_IMR_ENDRX;
}

static inline bool hri_usart_get_US_IMR_ENDRX_bit(const void *const hw)
{
	return (((Usart *)hw)->US_IMR & US_IMR_ENDRX) >> US_IMR_ENDRX_Pos;
}

static inline void hri_usart_write_US_IMR_ENDRX_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Usart *)hw)->US_IDR = US_IMR_ENDRX;
	} else {
		((Usart *)hw)->US_IER = US_IMR_ENDRX;
	}
}

static inline void hri_usart_clear_US_IMR_ENDRX_bit(const void *const hw)
{
	((Usart *)hw)->US_IDR = US_IMR_ENDRX;
}

static inline void hri_usart_set_US_IMR_ENDTX_bit(const void *const hw)
{
	((Usart *)hw)->US_IER = US_IMR_ENDTX;
}

static inline bool hri_usart_get_US_IMR_ENDTX_bit(const void *const hw)
{
	return (((Usart *)hw)->US_IMR & US_IMR_ENDTX) >> US_IMR_ENDTX_Pos;
}

static inline void hri_usart_write_US_IMR_ENDTX_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Usart *)hw)->US_IDR = US_IMR_ENDTX;
	} else {
		((Usart *)hw)->US_IER = US_IMR_ENDTX;
	}
}

static inline void hri_usart_clear_US_IMR_ENDTX_bit(const void *const hw)
{
	((Usart *)hw)->US_IDR = US_IMR_ENDTX;
}

static inline void hri_usart_set_US_IMR_OVRE_bit(const void *const hw)
{
	((Usart *)hw)->US_IER = US_IMR_OVRE;
}

static inline bool hri_usart_get_US_IMR_OVRE_bit(const void *const hw)
{
	return (((Usart *)hw)->US_IMR & US_IMR_OVRE) >> US_IMR_OVRE_Pos;
}

static inline void hri_usart_write_US_IMR_OVRE_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Usart *)hw)->US_IDR = US_IMR_OVRE;
	} else {
		((Usart *)hw)->US_IER = US_IMR_OVRE;
	}
}

static inline void hri_usart_clear_US_IMR_OVRE_bit(const void *const hw)
{
	((Usart *)hw)->US_IDR = US_IMR_OVRE;
}

static inline void hri_usart_set_US_IMR_FRAME_bit(const void *const hw)
{
	((Usart *)hw)->US_IER = US_IMR_FRAME;
}

static inline bool hri_usart_get_US_IMR_FRAME_bit(const void *const hw)
{
	return (((Usart *)hw)->US_IMR & US_IMR_FRAME) >> US_IMR_FRAME_Pos;
}

static inline void hri_usart_write_US_IMR_FRAME_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Usart *)hw)->US_IDR = US_IMR_FRAME;
	} else {
		((Usart *)hw)->US_IER = US_IMR_FRAME;
	}
}

static inline void hri_usart_clear_US_IMR_FRAME_bit(const void *const hw)
{
	((Usart *)hw)->US_IDR = US_IMR_FRAME;
}

static inline void hri_usart_set_US_IMR_PARE_bit(const void *const hw)
{
	((Usart *)hw)->US_IER = US_IMR_PARE;
}

static inline bool hri_usart_get_US_IMR_PARE_bit(const void *const hw)
{
	return (((Usart *)hw)->US_IMR & US_IMR_PARE) >> US_IMR_PARE_Pos;
}

static inline void hri_usart_write_US_IMR_PARE_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Usart *)hw)->US_IDR = US_IMR_PARE;
	} else {
		((Usart *)hw)->US_IER = US_IMR_PARE;
	}
}

static inline void hri_usart_clear_US_IMR_PARE_bit(const void *const hw)
{
	((Usart *)hw)->US_IDR = US_IMR_PARE;
}

static inline void hri_usart_set_US_IMR_TIMEOUT_bit(const void *const hw)
{
	((Usart *)hw)->US_IER = US_IMR_TIMEOUT;
}

static inline bool hri_usart_get_US_IMR_TIMEOUT_bit(const void *const hw)
{
	return (((Usart *)hw)->US_IMR & US_IMR_TIMEOUT) >> US_IMR_TIMEOUT_Pos;
}

static inline void hri_usart_write_US_IMR_TIMEOUT_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Usart *)hw)->US_IDR = US_IMR_TIMEOUT;
	} else {
		((Usart *)hw)->US_IER = US_IMR_TIMEOUT;
	}
}

static inline void hri_usart_clear_US_IMR_TIMEOUT_bit(const void *const hw)
{
	((Usart *)hw)->US_IDR = US_IMR_TIMEOUT;
}

static inline void hri_usart_set_US_IMR_TXEMPTY_bit(const void *const hw)
{
	((Usart *)hw)->US_IER = US_IMR_TXEMPTY;
}

static inline bool hri_usart_get_US_IMR_TXEMPTY_bit(const void *const hw)
{
	return (((Usart *)hw)->US_IMR & US_IMR_TXEMPTY) >> US_IMR_TXEMPTY_Pos;
}

static inline void hri_usart_write_US_IMR_TXEMPTY_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Usart *)hw)->US_IDR = US_IMR_TXEMPTY;
	} else {
		((Usart *)hw)->US_IER = US_IMR_TXEMPTY;
	}
}

static inline void hri_usart_clear_US_IMR_TXEMPTY_bit(const void *const hw)
{
	((Usart *)hw)->US_IDR = US_IMR_TXEMPTY;
}

static inline void hri_usart_set_US_IMR_ITER_bit(const void *const hw)
{
	((Usart *)hw)->US_IER = US_IMR_ITER;
}

static inline bool hri_usart_get_US_IMR_ITER_bit(const void *const hw)
{
	return (((Usart *)hw)->US_IMR & US_IMR_ITER) >> US_IMR_ITER_Pos;
}

static inline void hri_usart_write_US_IMR_ITER_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Usart *)hw)->US_IDR = US_IMR_ITER;
	} else {
		((Usart *)hw)->US_IER = US_IMR_ITER;
	}
}

static inline void hri_usart_clear_US_IMR_ITER_bit(const void *const hw)
{
	((Usart *)hw)->US_IDR = US_IMR_ITER;
}

static inline void hri_usart_set_US_IMR_TXBUFE_bit(const void *const hw)
{
	((Usart *)hw)->US_IER = US_IMR_TXBUFE;
}

static inline bool hri_usart_get_US_IMR_TXBUFE_bit(const void *const hw)
{
	return (((Usart *)hw)->US_IMR & US_IMR_TXBUFE) >> US_IMR_TXBUFE_Pos;
}

static inline void hri_usart_write_US_IMR_TXBUFE_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Usart *)hw)->US_IDR = US_IMR_TXBUFE;
	} else {
		((Usart *)hw)->US_IER = US_IMR_TXBUFE;
	}
}

static inline void hri_usart_clear_US_IMR_TXBUFE_bit(const void *const hw)
{
	((Usart *)hw)->US_IDR = US_IMR_TXBUFE;
}

static inline void hri_usart_set_US_IMR_RXBUFF_bit(const void *const hw)
{
	((Usart *)hw)->US_IER = US_IMR_RXBUFF;
}

static inline bool hri_usart_get_US_IMR_RXBUFF_bit(const void *const hw)
{
	return (((Usart *)hw)->US_IMR & US_IMR_RXBUFF) >> US_IMR_RXBUFF_Pos;
}

static inline void hri_usart_write_US_IMR_RXBUFF_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Usart *)hw)->US_IDR = US_IMR_RXBUFF;
	} else {
		((Usart *)hw)->US_IER = US_IMR_RXBUFF;
	}
}

static inline void hri_usart_clear_US_IMR_RXBUFF_bit(const void *const hw)
{
	((Usart *)hw)->US_IDR = US_IMR_RXBUFF;
}

static inline void hri_usart_set_US_IMR_NACK_bit(const void *const hw)
{
	((Usart *)hw)->US_IER = US_IMR_NACK;
}

static inline bool hri_usart_get_US_IMR_NACK_bit(const void *const hw)
{
	return (((Usart *)hw)->US_IMR & US_IMR_NACK) >> US_IMR_NACK_Pos;
}

static inline void hri_usart_write_US_IMR_NACK_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Usart *)hw)->US_IDR = US_IMR_NACK;
	} else {
		((Usart *)hw)->US_IER = US_IMR_NACK;
	}
}

static inline void hri_usart_clear_US_IMR_NACK_bit(const void *const hw)
{
	((Usart *)hw)->US_IDR = US_IMR_NACK;
}

static inline void hri_usart_set_US_IMR_CTSIC_bit(const void *const hw)
{
	((Usart *)hw)->US_IER = US_IMR_CTSIC;
}

static inline bool hri_usart_get_US_IMR_CTSIC_bit(const void *const hw)
{
	return (((Usart *)hw)->US_IMR & US_IMR_CTSIC) >> US_IMR_CTSIC_Pos;
}

static inline void hri_usart_write_US_IMR_CTSIC_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Usart *)hw)->US_IDR = US_IMR_CTSIC;
	} else {
		((Usart *)hw)->US_IER = US_IMR_CTSIC;
	}
}

static inline void hri_usart_clear_US_IMR_CTSIC_bit(const void *const hw)
{
	((Usart *)hw)->US_IDR = US_IMR_CTSIC;
}

static inline void hri_usart_set_US_IMR_CMP_bit(const void *const hw)
{
	((Usart *)hw)->US_IER = US_IMR_CMP;
}

static inline bool hri_usart_get_US_IMR_CMP_bit(const void *const hw)
{
	return (((Usart *)hw)->US_IMR & US_IMR_CMP) >> US_IMR_CMP_Pos;
}

static inline void hri_usart_write_US_IMR_CMP_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Usart *)hw)->US_IDR = US_IMR_CMP;
	} else {
		((Usart *)hw)->US_IER = US_IMR_CMP;
	}
}

static inline void hri_usart_clear_US_IMR_CMP_bit(const void *const hw)
{
	((Usart *)hw)->US_IDR = US_IMR_CMP;
}

static inline void hri_usart_set_US_IMR_reg(const void *const hw, hri_usart_us_imr_reg_t mask)
{
	((Usart *)hw)->US_IER = mask;
}

static inline hri_usart_us_imr_reg_t hri_usart_get_US_IMR_reg(const void *const hw, hri_usart_us_imr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_IMR;
	tmp &= mask;
	return tmp;
}

static inline hri_usart_us_imr_reg_t hri_usart_read_US_IMR_reg(const void *const hw)
{
	return ((Usart *)hw)->US_IMR;
}

static inline void hri_usart_write_US_IMR_reg(const void *const hw, hri_usart_us_imr_reg_t data)
{
	((Usart *)hw)->US_IER = data;
	((Usart *)hw)->US_IDR = ~data;
}

static inline void hri_usart_clear_US_IMR_reg(const void *const hw, hri_usart_us_imr_reg_t mask)
{
	((Usart *)hw)->US_IDR = mask;
}

static inline void hri_usart_write_US_CR_reg(const void *const hw, hri_usart_us_cr_reg_t data)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_CR = data;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_write_US_THR_reg(const void *const hw, hri_usart_us_thr_reg_t data)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_THR = data;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_write_US_PTCR_reg(const void *const hw, hri_usart_us_ptcr_reg_t data)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_PTCR = data;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_set_US_MR_SYNC_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR |= US_MR_SYNC;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usart_get_US_MR_SYNC_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_MR;
	tmp = (tmp & US_MR_SYNC) >> US_MR_SYNC_Pos;
	return (bool)tmp;
}

static inline void hri_usart_write_US_MR_SYNC_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_MR;
	tmp &= ~US_MR_SYNC;
	tmp |= value << US_MR_SYNC_Pos;
	((Usart *)hw)->US_MR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_MR_SYNC_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR &= ~US_MR_SYNC;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_MR_SYNC_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR ^= US_MR_SYNC;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_set_US_MR_MSBF_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR |= US_MR_MSBF;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usart_get_US_MR_MSBF_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_MR;
	tmp = (tmp & US_MR_MSBF) >> US_MR_MSBF_Pos;
	return (bool)tmp;
}

static inline void hri_usart_write_US_MR_MSBF_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_MR;
	tmp &= ~US_MR_MSBF;
	tmp |= value << US_MR_MSBF_Pos;
	((Usart *)hw)->US_MR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_MR_MSBF_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR &= ~US_MR_MSBF;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_MR_MSBF_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR ^= US_MR_MSBF;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_set_US_MR_MODE9_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR |= US_MR_MODE9;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usart_get_US_MR_MODE9_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_MR;
	tmp = (tmp & US_MR_MODE9) >> US_MR_MODE9_Pos;
	return (bool)tmp;
}

static inline void hri_usart_write_US_MR_MODE9_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_MR;
	tmp &= ~US_MR_MODE9;
	tmp |= value << US_MR_MODE9_Pos;
	((Usart *)hw)->US_MR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_MR_MODE9_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR &= ~US_MR_MODE9;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_MR_MODE9_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR ^= US_MR_MODE9;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_set_US_MR_CLKO_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR |= US_MR_CLKO;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usart_get_US_MR_CLKO_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_MR;
	tmp = (tmp & US_MR_CLKO) >> US_MR_CLKO_Pos;
	return (bool)tmp;
}

static inline void hri_usart_write_US_MR_CLKO_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_MR;
	tmp &= ~US_MR_CLKO;
	tmp |= value << US_MR_CLKO_Pos;
	((Usart *)hw)->US_MR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_MR_CLKO_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR &= ~US_MR_CLKO;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_MR_CLKO_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR ^= US_MR_CLKO;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_set_US_MR_OVER_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR |= US_MR_OVER;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usart_get_US_MR_OVER_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_MR;
	tmp = (tmp & US_MR_OVER) >> US_MR_OVER_Pos;
	return (bool)tmp;
}

static inline void hri_usart_write_US_MR_OVER_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_MR;
	tmp &= ~US_MR_OVER;
	tmp |= value << US_MR_OVER_Pos;
	((Usart *)hw)->US_MR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_MR_OVER_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR &= ~US_MR_OVER;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_MR_OVER_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR ^= US_MR_OVER;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_set_US_MR_INACK_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR |= US_MR_INACK;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usart_get_US_MR_INACK_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_MR;
	tmp = (tmp & US_MR_INACK) >> US_MR_INACK_Pos;
	return (bool)tmp;
}

static inline void hri_usart_write_US_MR_INACK_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_MR;
	tmp &= ~US_MR_INACK;
	tmp |= value << US_MR_INACK_Pos;
	((Usart *)hw)->US_MR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_MR_INACK_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR &= ~US_MR_INACK;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_MR_INACK_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR ^= US_MR_INACK;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_set_US_MR_DSNACK_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR |= US_MR_DSNACK;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usart_get_US_MR_DSNACK_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_MR;
	tmp = (tmp & US_MR_DSNACK) >> US_MR_DSNACK_Pos;
	return (bool)tmp;
}

static inline void hri_usart_write_US_MR_DSNACK_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_MR;
	tmp &= ~US_MR_DSNACK;
	tmp |= value << US_MR_DSNACK_Pos;
	((Usart *)hw)->US_MR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_MR_DSNACK_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR &= ~US_MR_DSNACK;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_MR_DSNACK_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR ^= US_MR_DSNACK;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_set_US_MR_INVDATA_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR |= US_MR_INVDATA;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usart_get_US_MR_INVDATA_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_MR;
	tmp = (tmp & US_MR_INVDATA) >> US_MR_INVDATA_Pos;
	return (bool)tmp;
}

static inline void hri_usart_write_US_MR_INVDATA_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_MR;
	tmp &= ~US_MR_INVDATA;
	tmp |= value << US_MR_INVDATA_Pos;
	((Usart *)hw)->US_MR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_MR_INVDATA_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR &= ~US_MR_INVDATA;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_MR_INVDATA_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR ^= US_MR_INVDATA;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_set_US_MR_FILTER_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR |= US_MR_FILTER;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usart_get_US_MR_FILTER_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_MR;
	tmp = (tmp & US_MR_FILTER) >> US_MR_FILTER_Pos;
	return (bool)tmp;
}

static inline void hri_usart_write_US_MR_FILTER_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_MR;
	tmp &= ~US_MR_FILTER;
	tmp |= value << US_MR_FILTER_Pos;
	((Usart *)hw)->US_MR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_MR_FILTER_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR &= ~US_MR_FILTER;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_MR_FILTER_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR ^= US_MR_FILTER;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_set_US_MR_USART_MODE_bf(const void *const hw, hri_usart_us_mr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR |= US_MR_USART_MODE(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_mr_reg_t hri_usart_get_US_MR_USART_MODE_bf(const void *const hw, hri_usart_us_mr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_MR;
	tmp = (tmp & US_MR_USART_MODE(mask)) >> US_MR_USART_MODE_Pos;
	return tmp;
}

static inline void hri_usart_write_US_MR_USART_MODE_bf(const void *const hw, hri_usart_us_mr_reg_t data)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_MR;
	tmp &= ~US_MR_USART_MODE_Msk;
	tmp |= US_MR_USART_MODE(data);
	((Usart *)hw)->US_MR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_MR_USART_MODE_bf(const void *const hw, hri_usart_us_mr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR &= ~US_MR_USART_MODE(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_MR_USART_MODE_bf(const void *const hw, hri_usart_us_mr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR ^= US_MR_USART_MODE(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_mr_reg_t hri_usart_read_US_MR_USART_MODE_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_MR;
	tmp = (tmp & US_MR_USART_MODE_Msk) >> US_MR_USART_MODE_Pos;
	return tmp;
}

static inline void hri_usart_set_US_MR_USCLKS_bf(const void *const hw, hri_usart_us_mr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR |= US_MR_USCLKS(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_mr_reg_t hri_usart_get_US_MR_USCLKS_bf(const void *const hw, hri_usart_us_mr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_MR;
	tmp = (tmp & US_MR_USCLKS(mask)) >> US_MR_USCLKS_Pos;
	return tmp;
}

static inline void hri_usart_write_US_MR_USCLKS_bf(const void *const hw, hri_usart_us_mr_reg_t data)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_MR;
	tmp &= ~US_MR_USCLKS_Msk;
	tmp |= US_MR_USCLKS(data);
	((Usart *)hw)->US_MR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_MR_USCLKS_bf(const void *const hw, hri_usart_us_mr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR &= ~US_MR_USCLKS(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_MR_USCLKS_bf(const void *const hw, hri_usart_us_mr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR ^= US_MR_USCLKS(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_mr_reg_t hri_usart_read_US_MR_USCLKS_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_MR;
	tmp = (tmp & US_MR_USCLKS_Msk) >> US_MR_USCLKS_Pos;
	return tmp;
}

static inline void hri_usart_set_US_MR_CHRL_bf(const void *const hw, hri_usart_us_mr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR |= US_MR_CHRL(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_mr_reg_t hri_usart_get_US_MR_CHRL_bf(const void *const hw, hri_usart_us_mr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_MR;
	tmp = (tmp & US_MR_CHRL(mask)) >> US_MR_CHRL_Pos;
	return tmp;
}

static inline void hri_usart_write_US_MR_CHRL_bf(const void *const hw, hri_usart_us_mr_reg_t data)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_MR;
	tmp &= ~US_MR_CHRL_Msk;
	tmp |= US_MR_CHRL(data);
	((Usart *)hw)->US_MR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_MR_CHRL_bf(const void *const hw, hri_usart_us_mr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR &= ~US_MR_CHRL(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_MR_CHRL_bf(const void *const hw, hri_usart_us_mr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR ^= US_MR_CHRL(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_mr_reg_t hri_usart_read_US_MR_CHRL_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_MR;
	tmp = (tmp & US_MR_CHRL_Msk) >> US_MR_CHRL_Pos;
	return tmp;
}

static inline void hri_usart_set_US_MR_PAR_bf(const void *const hw, hri_usart_us_mr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR |= US_MR_PAR(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_mr_reg_t hri_usart_get_US_MR_PAR_bf(const void *const hw, hri_usart_us_mr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_MR;
	tmp = (tmp & US_MR_PAR(mask)) >> US_MR_PAR_Pos;
	return tmp;
}

static inline void hri_usart_write_US_MR_PAR_bf(const void *const hw, hri_usart_us_mr_reg_t data)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_MR;
	tmp &= ~US_MR_PAR_Msk;
	tmp |= US_MR_PAR(data);
	((Usart *)hw)->US_MR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_MR_PAR_bf(const void *const hw, hri_usart_us_mr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR &= ~US_MR_PAR(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_MR_PAR_bf(const void *const hw, hri_usart_us_mr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR ^= US_MR_PAR(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_mr_reg_t hri_usart_read_US_MR_PAR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_MR;
	tmp = (tmp & US_MR_PAR_Msk) >> US_MR_PAR_Pos;
	return tmp;
}

static inline void hri_usart_set_US_MR_NBSTOP_bf(const void *const hw, hri_usart_us_mr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR |= US_MR_NBSTOP(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_mr_reg_t hri_usart_get_US_MR_NBSTOP_bf(const void *const hw, hri_usart_us_mr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_MR;
	tmp = (tmp & US_MR_NBSTOP(mask)) >> US_MR_NBSTOP_Pos;
	return tmp;
}

static inline void hri_usart_write_US_MR_NBSTOP_bf(const void *const hw, hri_usart_us_mr_reg_t data)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_MR;
	tmp &= ~US_MR_NBSTOP_Msk;
	tmp |= US_MR_NBSTOP(data);
	((Usart *)hw)->US_MR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_MR_NBSTOP_bf(const void *const hw, hri_usart_us_mr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR &= ~US_MR_NBSTOP(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_MR_NBSTOP_bf(const void *const hw, hri_usart_us_mr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR ^= US_MR_NBSTOP(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_mr_reg_t hri_usart_read_US_MR_NBSTOP_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_MR;
	tmp = (tmp & US_MR_NBSTOP_Msk) >> US_MR_NBSTOP_Pos;
	return tmp;
}

static inline void hri_usart_set_US_MR_CHMODE_bf(const void *const hw, hri_usart_us_mr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR |= US_MR_CHMODE(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_mr_reg_t hri_usart_get_US_MR_CHMODE_bf(const void *const hw, hri_usart_us_mr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_MR;
	tmp = (tmp & US_MR_CHMODE(mask)) >> US_MR_CHMODE_Pos;
	return tmp;
}

static inline void hri_usart_write_US_MR_CHMODE_bf(const void *const hw, hri_usart_us_mr_reg_t data)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_MR;
	tmp &= ~US_MR_CHMODE_Msk;
	tmp |= US_MR_CHMODE(data);
	((Usart *)hw)->US_MR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_MR_CHMODE_bf(const void *const hw, hri_usart_us_mr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR &= ~US_MR_CHMODE(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_MR_CHMODE_bf(const void *const hw, hri_usart_us_mr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR ^= US_MR_CHMODE(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_mr_reg_t hri_usart_read_US_MR_CHMODE_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_MR;
	tmp = (tmp & US_MR_CHMODE_Msk) >> US_MR_CHMODE_Pos;
	return tmp;
}

static inline void hri_usart_set_US_MR_MAX_ITERATION_bf(const void *const hw, hri_usart_us_mr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR |= US_MR_MAX_ITERATION(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_mr_reg_t hri_usart_get_US_MR_MAX_ITERATION_bf(const void *const     hw,
                                                                         hri_usart_us_mr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_MR;
	tmp = (tmp & US_MR_MAX_ITERATION(mask)) >> US_MR_MAX_ITERATION_Pos;
	return tmp;
}

static inline void hri_usart_write_US_MR_MAX_ITERATION_bf(const void *const hw, hri_usart_us_mr_reg_t data)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_MR;
	tmp &= ~US_MR_MAX_ITERATION_Msk;
	tmp |= US_MR_MAX_ITERATION(data);
	((Usart *)hw)->US_MR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_MR_MAX_ITERATION_bf(const void *const hw, hri_usart_us_mr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR &= ~US_MR_MAX_ITERATION(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_MR_MAX_ITERATION_bf(const void *const hw, hri_usart_us_mr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR ^= US_MR_MAX_ITERATION(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_mr_reg_t hri_usart_read_US_MR_MAX_ITERATION_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_MR;
	tmp = (tmp & US_MR_MAX_ITERATION_Msk) >> US_MR_MAX_ITERATION_Pos;
	return tmp;
}

static inline void hri_usart_set_US_MR_reg(const void *const hw, hri_usart_us_mr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR |= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_mr_reg_t hri_usart_get_US_MR_reg(const void *const hw, hri_usart_us_mr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_MR;
	tmp &= mask;
	return tmp;
}

static inline void hri_usart_write_US_MR_reg(const void *const hw, hri_usart_us_mr_reg_t data)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR = data;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_MR_reg(const void *const hw, hri_usart_us_mr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR &= ~mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_MR_reg(const void *const hw, hri_usart_us_mr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_MR ^= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_mr_reg_t hri_usart_read_US_MR_reg(const void *const hw)
{
	return ((Usart *)hw)->US_MR;
}

static inline void hri_usart_set_US_BRGR_CD_bf(const void *const hw, hri_usart_us_brgr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_BRGR |= US_BRGR_CD(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_brgr_reg_t hri_usart_get_US_BRGR_CD_bf(const void *const hw, hri_usart_us_brgr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_BRGR;
	tmp = (tmp & US_BRGR_CD(mask)) >> US_BRGR_CD_Pos;
	return tmp;
}

static inline void hri_usart_write_US_BRGR_CD_bf(const void *const hw, hri_usart_us_brgr_reg_t data)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_BRGR;
	tmp &= ~US_BRGR_CD_Msk;
	tmp |= US_BRGR_CD(data);
	((Usart *)hw)->US_BRGR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_BRGR_CD_bf(const void *const hw, hri_usart_us_brgr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_BRGR &= ~US_BRGR_CD(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_BRGR_CD_bf(const void *const hw, hri_usart_us_brgr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_BRGR ^= US_BRGR_CD(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_brgr_reg_t hri_usart_read_US_BRGR_CD_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_BRGR;
	tmp = (tmp & US_BRGR_CD_Msk) >> US_BRGR_CD_Pos;
	return tmp;
}

static inline void hri_usart_set_US_BRGR_FP_bf(const void *const hw, hri_usart_us_brgr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_BRGR |= US_BRGR_FP(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_brgr_reg_t hri_usart_get_US_BRGR_FP_bf(const void *const hw, hri_usart_us_brgr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_BRGR;
	tmp = (tmp & US_BRGR_FP(mask)) >> US_BRGR_FP_Pos;
	return tmp;
}

static inline void hri_usart_write_US_BRGR_FP_bf(const void *const hw, hri_usart_us_brgr_reg_t data)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_BRGR;
	tmp &= ~US_BRGR_FP_Msk;
	tmp |= US_BRGR_FP(data);
	((Usart *)hw)->US_BRGR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_BRGR_FP_bf(const void *const hw, hri_usart_us_brgr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_BRGR &= ~US_BRGR_FP(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_BRGR_FP_bf(const void *const hw, hri_usart_us_brgr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_BRGR ^= US_BRGR_FP(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_brgr_reg_t hri_usart_read_US_BRGR_FP_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_BRGR;
	tmp = (tmp & US_BRGR_FP_Msk) >> US_BRGR_FP_Pos;
	return tmp;
}

static inline void hri_usart_set_US_BRGR_reg(const void *const hw, hri_usart_us_brgr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_BRGR |= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_brgr_reg_t hri_usart_get_US_BRGR_reg(const void *const hw, hri_usart_us_brgr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_BRGR;
	tmp &= mask;
	return tmp;
}

static inline void hri_usart_write_US_BRGR_reg(const void *const hw, hri_usart_us_brgr_reg_t data)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_BRGR = data;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_BRGR_reg(const void *const hw, hri_usart_us_brgr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_BRGR &= ~mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_BRGR_reg(const void *const hw, hri_usart_us_brgr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_BRGR ^= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_brgr_reg_t hri_usart_read_US_BRGR_reg(const void *const hw)
{
	return ((Usart *)hw)->US_BRGR;
}

static inline void hri_usart_set_US_RTOR_TO_bf(const void *const hw, hri_usart_us_rtor_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_RTOR |= US_RTOR_TO(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_rtor_reg_t hri_usart_get_US_RTOR_TO_bf(const void *const hw, hri_usart_us_rtor_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_RTOR;
	tmp = (tmp & US_RTOR_TO(mask)) >> US_RTOR_TO_Pos;
	return tmp;
}

static inline void hri_usart_write_US_RTOR_TO_bf(const void *const hw, hri_usart_us_rtor_reg_t data)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_RTOR;
	tmp &= ~US_RTOR_TO_Msk;
	tmp |= US_RTOR_TO(data);
	((Usart *)hw)->US_RTOR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_RTOR_TO_bf(const void *const hw, hri_usart_us_rtor_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_RTOR &= ~US_RTOR_TO(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_RTOR_TO_bf(const void *const hw, hri_usart_us_rtor_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_RTOR ^= US_RTOR_TO(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_rtor_reg_t hri_usart_read_US_RTOR_TO_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_RTOR;
	tmp = (tmp & US_RTOR_TO_Msk) >> US_RTOR_TO_Pos;
	return tmp;
}

static inline void hri_usart_set_US_RTOR_reg(const void *const hw, hri_usart_us_rtor_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_RTOR |= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_rtor_reg_t hri_usart_get_US_RTOR_reg(const void *const hw, hri_usart_us_rtor_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_RTOR;
	tmp &= mask;
	return tmp;
}

static inline void hri_usart_write_US_RTOR_reg(const void *const hw, hri_usart_us_rtor_reg_t data)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_RTOR = data;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_RTOR_reg(const void *const hw, hri_usart_us_rtor_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_RTOR &= ~mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_RTOR_reg(const void *const hw, hri_usart_us_rtor_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_RTOR ^= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_rtor_reg_t hri_usart_read_US_RTOR_reg(const void *const hw)
{
	return ((Usart *)hw)->US_RTOR;
}

static inline void hri_usart_set_US_TTGR_TG_bf(const void *const hw, hri_usart_us_ttgr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_TTGR |= US_TTGR_TG(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_ttgr_reg_t hri_usart_get_US_TTGR_TG_bf(const void *const hw, hri_usart_us_ttgr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_TTGR;
	tmp = (tmp & US_TTGR_TG(mask)) >> US_TTGR_TG_Pos;
	return tmp;
}

static inline void hri_usart_write_US_TTGR_TG_bf(const void *const hw, hri_usart_us_ttgr_reg_t data)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_TTGR;
	tmp &= ~US_TTGR_TG_Msk;
	tmp |= US_TTGR_TG(data);
	((Usart *)hw)->US_TTGR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_TTGR_TG_bf(const void *const hw, hri_usart_us_ttgr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_TTGR &= ~US_TTGR_TG(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_TTGR_TG_bf(const void *const hw, hri_usart_us_ttgr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_TTGR ^= US_TTGR_TG(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_ttgr_reg_t hri_usart_read_US_TTGR_TG_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_TTGR;
	tmp = (tmp & US_TTGR_TG_Msk) >> US_TTGR_TG_Pos;
	return tmp;
}

static inline void hri_usart_set_US_TTGR_reg(const void *const hw, hri_usart_us_ttgr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_TTGR |= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_ttgr_reg_t hri_usart_get_US_TTGR_reg(const void *const hw, hri_usart_us_ttgr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_TTGR;
	tmp &= mask;
	return tmp;
}

static inline void hri_usart_write_US_TTGR_reg(const void *const hw, hri_usart_us_ttgr_reg_t data)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_TTGR = data;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_TTGR_reg(const void *const hw, hri_usart_us_ttgr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_TTGR &= ~mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_TTGR_reg(const void *const hw, hri_usart_us_ttgr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_TTGR ^= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_ttgr_reg_t hri_usart_read_US_TTGR_reg(const void *const hw)
{
	return ((Usart *)hw)->US_TTGR;
}

static inline void hri_usart_set_US_FIDI_FI_DI_RATIO_bf(const void *const hw, hri_usart_us_fidi_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_FIDI |= US_FIDI_FI_DI_RATIO(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_fidi_reg_t hri_usart_get_US_FIDI_FI_DI_RATIO_bf(const void *const       hw,
                                                                           hri_usart_us_fidi_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_FIDI;
	tmp = (tmp & US_FIDI_FI_DI_RATIO(mask)) >> US_FIDI_FI_DI_RATIO_Pos;
	return tmp;
}

static inline void hri_usart_write_US_FIDI_FI_DI_RATIO_bf(const void *const hw, hri_usart_us_fidi_reg_t data)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_FIDI;
	tmp &= ~US_FIDI_FI_DI_RATIO_Msk;
	tmp |= US_FIDI_FI_DI_RATIO(data);
	((Usart *)hw)->US_FIDI = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_FIDI_FI_DI_RATIO_bf(const void *const hw, hri_usart_us_fidi_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_FIDI &= ~US_FIDI_FI_DI_RATIO(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_FIDI_FI_DI_RATIO_bf(const void *const hw, hri_usart_us_fidi_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_FIDI ^= US_FIDI_FI_DI_RATIO(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_fidi_reg_t hri_usart_read_US_FIDI_FI_DI_RATIO_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_FIDI;
	tmp = (tmp & US_FIDI_FI_DI_RATIO_Msk) >> US_FIDI_FI_DI_RATIO_Pos;
	return tmp;
}

static inline void hri_usart_set_US_FIDI_reg(const void *const hw, hri_usart_us_fidi_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_FIDI |= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_fidi_reg_t hri_usart_get_US_FIDI_reg(const void *const hw, hri_usart_us_fidi_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_FIDI;
	tmp &= mask;
	return tmp;
}

static inline void hri_usart_write_US_FIDI_reg(const void *const hw, hri_usart_us_fidi_reg_t data)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_FIDI = data;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_FIDI_reg(const void *const hw, hri_usart_us_fidi_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_FIDI &= ~mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_FIDI_reg(const void *const hw, hri_usart_us_fidi_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_FIDI ^= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_fidi_reg_t hri_usart_read_US_FIDI_reg(const void *const hw)
{
	return ((Usart *)hw)->US_FIDI;
}

static inline void hri_usart_set_US_IF_IRDA_FILTER_bf(const void *const hw, hri_usart_us_if_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_IF |= US_IF_IRDA_FILTER(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_if_reg_t hri_usart_get_US_IF_IRDA_FILTER_bf(const void *const hw, hri_usart_us_if_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_IF;
	tmp = (tmp & US_IF_IRDA_FILTER(mask)) >> US_IF_IRDA_FILTER_Pos;
	return tmp;
}

static inline void hri_usart_write_US_IF_IRDA_FILTER_bf(const void *const hw, hri_usart_us_if_reg_t data)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_IF;
	tmp &= ~US_IF_IRDA_FILTER_Msk;
	tmp |= US_IF_IRDA_FILTER(data);
	((Usart *)hw)->US_IF = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_IF_IRDA_FILTER_bf(const void *const hw, hri_usart_us_if_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_IF &= ~US_IF_IRDA_FILTER(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_IF_IRDA_FILTER_bf(const void *const hw, hri_usart_us_if_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_IF ^= US_IF_IRDA_FILTER(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_if_reg_t hri_usart_read_US_IF_IRDA_FILTER_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_IF;
	tmp = (tmp & US_IF_IRDA_FILTER_Msk) >> US_IF_IRDA_FILTER_Pos;
	return tmp;
}

static inline void hri_usart_set_US_IF_reg(const void *const hw, hri_usart_us_if_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_IF |= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_if_reg_t hri_usart_get_US_IF_reg(const void *const hw, hri_usart_us_if_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_IF;
	tmp &= mask;
	return tmp;
}

static inline void hri_usart_write_US_IF_reg(const void *const hw, hri_usart_us_if_reg_t data)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_IF = data;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_IF_reg(const void *const hw, hri_usart_us_if_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_IF &= ~mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_IF_reg(const void *const hw, hri_usart_us_if_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_IF ^= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_if_reg_t hri_usart_read_US_IF_reg(const void *const hw)
{
	return ((Usart *)hw)->US_IF;
}

static inline void hri_usart_set_US_LINMR_PARDIS_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINMR |= US_LINMR_PARDIS;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usart_get_US_LINMR_PARDIS_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_LINMR;
	tmp = (tmp & US_LINMR_PARDIS) >> US_LINMR_PARDIS_Pos;
	return (bool)tmp;
}

static inline void hri_usart_write_US_LINMR_PARDIS_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_LINMR;
	tmp &= ~US_LINMR_PARDIS;
	tmp |= value << US_LINMR_PARDIS_Pos;
	((Usart *)hw)->US_LINMR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_LINMR_PARDIS_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINMR &= ~US_LINMR_PARDIS;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_LINMR_PARDIS_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINMR ^= US_LINMR_PARDIS;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_set_US_LINMR_CHKDIS_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINMR |= US_LINMR_CHKDIS;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usart_get_US_LINMR_CHKDIS_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_LINMR;
	tmp = (tmp & US_LINMR_CHKDIS) >> US_LINMR_CHKDIS_Pos;
	return (bool)tmp;
}

static inline void hri_usart_write_US_LINMR_CHKDIS_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_LINMR;
	tmp &= ~US_LINMR_CHKDIS;
	tmp |= value << US_LINMR_CHKDIS_Pos;
	((Usart *)hw)->US_LINMR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_LINMR_CHKDIS_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINMR &= ~US_LINMR_CHKDIS;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_LINMR_CHKDIS_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINMR ^= US_LINMR_CHKDIS;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_set_US_LINMR_CHKTYP_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINMR |= US_LINMR_CHKTYP;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usart_get_US_LINMR_CHKTYP_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_LINMR;
	tmp = (tmp & US_LINMR_CHKTYP) >> US_LINMR_CHKTYP_Pos;
	return (bool)tmp;
}

static inline void hri_usart_write_US_LINMR_CHKTYP_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_LINMR;
	tmp &= ~US_LINMR_CHKTYP;
	tmp |= value << US_LINMR_CHKTYP_Pos;
	((Usart *)hw)->US_LINMR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_LINMR_CHKTYP_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINMR &= ~US_LINMR_CHKTYP;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_LINMR_CHKTYP_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINMR ^= US_LINMR_CHKTYP;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_set_US_LINMR_DLM_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINMR |= US_LINMR_DLM;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usart_get_US_LINMR_DLM_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_LINMR;
	tmp = (tmp & US_LINMR_DLM) >> US_LINMR_DLM_Pos;
	return (bool)tmp;
}

static inline void hri_usart_write_US_LINMR_DLM_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_LINMR;
	tmp &= ~US_LINMR_DLM;
	tmp |= value << US_LINMR_DLM_Pos;
	((Usart *)hw)->US_LINMR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_LINMR_DLM_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINMR &= ~US_LINMR_DLM;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_LINMR_DLM_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINMR ^= US_LINMR_DLM;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_set_US_LINMR_FSDIS_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINMR |= US_LINMR_FSDIS;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usart_get_US_LINMR_FSDIS_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_LINMR;
	tmp = (tmp & US_LINMR_FSDIS) >> US_LINMR_FSDIS_Pos;
	return (bool)tmp;
}

static inline void hri_usart_write_US_LINMR_FSDIS_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_LINMR;
	tmp &= ~US_LINMR_FSDIS;
	tmp |= value << US_LINMR_FSDIS_Pos;
	((Usart *)hw)->US_LINMR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_LINMR_FSDIS_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINMR &= ~US_LINMR_FSDIS;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_LINMR_FSDIS_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINMR ^= US_LINMR_FSDIS;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_set_US_LINMR_WKUPTYP_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINMR |= US_LINMR_WKUPTYP;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usart_get_US_LINMR_WKUPTYP_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_LINMR;
	tmp = (tmp & US_LINMR_WKUPTYP) >> US_LINMR_WKUPTYP_Pos;
	return (bool)tmp;
}

static inline void hri_usart_write_US_LINMR_WKUPTYP_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_LINMR;
	tmp &= ~US_LINMR_WKUPTYP;
	tmp |= value << US_LINMR_WKUPTYP_Pos;
	((Usart *)hw)->US_LINMR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_LINMR_WKUPTYP_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINMR &= ~US_LINMR_WKUPTYP;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_LINMR_WKUPTYP_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINMR ^= US_LINMR_WKUPTYP;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_set_US_LINMR_PDCM_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINMR |= US_LINMR_PDCM;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usart_get_US_LINMR_PDCM_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_LINMR;
	tmp = (tmp & US_LINMR_PDCM) >> US_LINMR_PDCM_Pos;
	return (bool)tmp;
}

static inline void hri_usart_write_US_LINMR_PDCM_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_LINMR;
	tmp &= ~US_LINMR_PDCM;
	tmp |= value << US_LINMR_PDCM_Pos;
	((Usart *)hw)->US_LINMR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_LINMR_PDCM_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINMR &= ~US_LINMR_PDCM;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_LINMR_PDCM_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINMR ^= US_LINMR_PDCM;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_set_US_LINMR_SYNCDIS_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINMR |= US_LINMR_SYNCDIS;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usart_get_US_LINMR_SYNCDIS_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_LINMR;
	tmp = (tmp & US_LINMR_SYNCDIS) >> US_LINMR_SYNCDIS_Pos;
	return (bool)tmp;
}

static inline void hri_usart_write_US_LINMR_SYNCDIS_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_LINMR;
	tmp &= ~US_LINMR_SYNCDIS;
	tmp |= value << US_LINMR_SYNCDIS_Pos;
	((Usart *)hw)->US_LINMR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_LINMR_SYNCDIS_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINMR &= ~US_LINMR_SYNCDIS;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_LINMR_SYNCDIS_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINMR ^= US_LINMR_SYNCDIS;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_set_US_LINMR_NACT_bf(const void *const hw, hri_usart_us_linmr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINMR |= US_LINMR_NACT(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_linmr_reg_t hri_usart_get_US_LINMR_NACT_bf(const void *const        hw,
                                                                      hri_usart_us_linmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_LINMR;
	tmp = (tmp & US_LINMR_NACT(mask)) >> US_LINMR_NACT_Pos;
	return tmp;
}

static inline void hri_usart_write_US_LINMR_NACT_bf(const void *const hw, hri_usart_us_linmr_reg_t data)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_LINMR;
	tmp &= ~US_LINMR_NACT_Msk;
	tmp |= US_LINMR_NACT(data);
	((Usart *)hw)->US_LINMR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_LINMR_NACT_bf(const void *const hw, hri_usart_us_linmr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINMR &= ~US_LINMR_NACT(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_LINMR_NACT_bf(const void *const hw, hri_usart_us_linmr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINMR ^= US_LINMR_NACT(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_linmr_reg_t hri_usart_read_US_LINMR_NACT_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_LINMR;
	tmp = (tmp & US_LINMR_NACT_Msk) >> US_LINMR_NACT_Pos;
	return tmp;
}

static inline void hri_usart_set_US_LINMR_DLC_bf(const void *const hw, hri_usart_us_linmr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINMR |= US_LINMR_DLC(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_linmr_reg_t hri_usart_get_US_LINMR_DLC_bf(const void *const        hw,
                                                                     hri_usart_us_linmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_LINMR;
	tmp = (tmp & US_LINMR_DLC(mask)) >> US_LINMR_DLC_Pos;
	return tmp;
}

static inline void hri_usart_write_US_LINMR_DLC_bf(const void *const hw, hri_usart_us_linmr_reg_t data)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_LINMR;
	tmp &= ~US_LINMR_DLC_Msk;
	tmp |= US_LINMR_DLC(data);
	((Usart *)hw)->US_LINMR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_LINMR_DLC_bf(const void *const hw, hri_usart_us_linmr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINMR &= ~US_LINMR_DLC(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_LINMR_DLC_bf(const void *const hw, hri_usart_us_linmr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINMR ^= US_LINMR_DLC(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_linmr_reg_t hri_usart_read_US_LINMR_DLC_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_LINMR;
	tmp = (tmp & US_LINMR_DLC_Msk) >> US_LINMR_DLC_Pos;
	return tmp;
}

static inline void hri_usart_set_US_LINMR_reg(const void *const hw, hri_usart_us_linmr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINMR |= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_linmr_reg_t hri_usart_get_US_LINMR_reg(const void *const hw, hri_usart_us_linmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_LINMR;
	tmp &= mask;
	return tmp;
}

static inline void hri_usart_write_US_LINMR_reg(const void *const hw, hri_usart_us_linmr_reg_t data)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINMR = data;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_LINMR_reg(const void *const hw, hri_usart_us_linmr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINMR &= ~mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_LINMR_reg(const void *const hw, hri_usart_us_linmr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINMR ^= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_linmr_reg_t hri_usart_read_US_LINMR_reg(const void *const hw)
{
	return ((Usart *)hw)->US_LINMR;
}

static inline void hri_usart_set_US_LINIR_IDCHR_bf(const void *const hw, hri_usart_us_linir_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINIR |= US_LINIR_IDCHR(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_linir_reg_t hri_usart_get_US_LINIR_IDCHR_bf(const void *const        hw,
                                                                       hri_usart_us_linir_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_LINIR;
	tmp = (tmp & US_LINIR_IDCHR(mask)) >> US_LINIR_IDCHR_Pos;
	return tmp;
}

static inline void hri_usart_write_US_LINIR_IDCHR_bf(const void *const hw, hri_usart_us_linir_reg_t data)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_LINIR;
	tmp &= ~US_LINIR_IDCHR_Msk;
	tmp |= US_LINIR_IDCHR(data);
	((Usart *)hw)->US_LINIR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_LINIR_IDCHR_bf(const void *const hw, hri_usart_us_linir_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINIR &= ~US_LINIR_IDCHR(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_LINIR_IDCHR_bf(const void *const hw, hri_usart_us_linir_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINIR ^= US_LINIR_IDCHR(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_linir_reg_t hri_usart_read_US_LINIR_IDCHR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_LINIR;
	tmp = (tmp & US_LINIR_IDCHR_Msk) >> US_LINIR_IDCHR_Pos;
	return tmp;
}

static inline void hri_usart_set_US_LINIR_reg(const void *const hw, hri_usart_us_linir_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINIR |= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_linir_reg_t hri_usart_get_US_LINIR_reg(const void *const hw, hri_usart_us_linir_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_LINIR;
	tmp &= mask;
	return tmp;
}

static inline void hri_usart_write_US_LINIR_reg(const void *const hw, hri_usart_us_linir_reg_t data)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINIR = data;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_LINIR_reg(const void *const hw, hri_usart_us_linir_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINIR &= ~mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_LINIR_reg(const void *const hw, hri_usart_us_linir_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_LINIR ^= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_linir_reg_t hri_usart_read_US_LINIR_reg(const void *const hw)
{
	return ((Usart *)hw)->US_LINIR;
}

static inline void hri_usart_set_US_CMPR_CMPMODE_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_CMPR |= US_CMPR_CMPMODE;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usart_get_US_CMPR_CMPMODE_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_CMPR;
	tmp = (tmp & US_CMPR_CMPMODE) >> US_CMPR_CMPMODE_Pos;
	return (bool)tmp;
}

static inline void hri_usart_write_US_CMPR_CMPMODE_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_CMPR;
	tmp &= ~US_CMPR_CMPMODE;
	tmp |= value << US_CMPR_CMPMODE_Pos;
	((Usart *)hw)->US_CMPR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_CMPR_CMPMODE_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_CMPR &= ~US_CMPR_CMPMODE;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_CMPR_CMPMODE_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_CMPR ^= US_CMPR_CMPMODE;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_set_US_CMPR_CMPPAR_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_CMPR |= US_CMPR_CMPPAR;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usart_get_US_CMPR_CMPPAR_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_CMPR;
	tmp = (tmp & US_CMPR_CMPPAR) >> US_CMPR_CMPPAR_Pos;
	return (bool)tmp;
}

static inline void hri_usart_write_US_CMPR_CMPPAR_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_CMPR;
	tmp &= ~US_CMPR_CMPPAR;
	tmp |= value << US_CMPR_CMPPAR_Pos;
	((Usart *)hw)->US_CMPR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_CMPR_CMPPAR_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_CMPR &= ~US_CMPR_CMPPAR;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_CMPR_CMPPAR_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_CMPR ^= US_CMPR_CMPPAR;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_set_US_CMPR_VAL1_bf(const void *const hw, hri_usart_us_cmpr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_CMPR |= US_CMPR_VAL1(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_cmpr_reg_t hri_usart_get_US_CMPR_VAL1_bf(const void *const hw, hri_usart_us_cmpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_CMPR;
	tmp = (tmp & US_CMPR_VAL1(mask)) >> US_CMPR_VAL1_Pos;
	return tmp;
}

static inline void hri_usart_write_US_CMPR_VAL1_bf(const void *const hw, hri_usart_us_cmpr_reg_t data)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_CMPR;
	tmp &= ~US_CMPR_VAL1_Msk;
	tmp |= US_CMPR_VAL1(data);
	((Usart *)hw)->US_CMPR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_CMPR_VAL1_bf(const void *const hw, hri_usart_us_cmpr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_CMPR &= ~US_CMPR_VAL1(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_CMPR_VAL1_bf(const void *const hw, hri_usart_us_cmpr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_CMPR ^= US_CMPR_VAL1(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_cmpr_reg_t hri_usart_read_US_CMPR_VAL1_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_CMPR;
	tmp = (tmp & US_CMPR_VAL1_Msk) >> US_CMPR_VAL1_Pos;
	return tmp;
}

static inline void hri_usart_set_US_CMPR_VAL2_bf(const void *const hw, hri_usart_us_cmpr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_CMPR |= US_CMPR_VAL2(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_cmpr_reg_t hri_usart_get_US_CMPR_VAL2_bf(const void *const hw, hri_usart_us_cmpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_CMPR;
	tmp = (tmp & US_CMPR_VAL2(mask)) >> US_CMPR_VAL2_Pos;
	return tmp;
}

static inline void hri_usart_write_US_CMPR_VAL2_bf(const void *const hw, hri_usart_us_cmpr_reg_t data)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_CMPR;
	tmp &= ~US_CMPR_VAL2_Msk;
	tmp |= US_CMPR_VAL2(data);
	((Usart *)hw)->US_CMPR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_CMPR_VAL2_bf(const void *const hw, hri_usart_us_cmpr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_CMPR &= ~US_CMPR_VAL2(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_CMPR_VAL2_bf(const void *const hw, hri_usart_us_cmpr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_CMPR ^= US_CMPR_VAL2(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_cmpr_reg_t hri_usart_read_US_CMPR_VAL2_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_CMPR;
	tmp = (tmp & US_CMPR_VAL2_Msk) >> US_CMPR_VAL2_Pos;
	return tmp;
}

static inline void hri_usart_set_US_CMPR_reg(const void *const hw, hri_usart_us_cmpr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_CMPR |= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_cmpr_reg_t hri_usart_get_US_CMPR_reg(const void *const hw, hri_usart_us_cmpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_CMPR;
	tmp &= mask;
	return tmp;
}

static inline void hri_usart_write_US_CMPR_reg(const void *const hw, hri_usart_us_cmpr_reg_t data)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_CMPR = data;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_CMPR_reg(const void *const hw, hri_usart_us_cmpr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_CMPR &= ~mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_CMPR_reg(const void *const hw, hri_usart_us_cmpr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_CMPR ^= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_cmpr_reg_t hri_usart_read_US_CMPR_reg(const void *const hw)
{
	return ((Usart *)hw)->US_CMPR;
}

static inline void hri_usart_set_US_WPMR_WPEN_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_WPMR |= US_WPMR_WPEN;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usart_get_US_WPMR_WPEN_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_WPMR;
	tmp = (tmp & US_WPMR_WPEN) >> US_WPMR_WPEN_Pos;
	return (bool)tmp;
}

static inline void hri_usart_write_US_WPMR_WPEN_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_WPMR;
	tmp &= ~US_WPMR_WPEN;
	tmp |= value << US_WPMR_WPEN_Pos;
	((Usart *)hw)->US_WPMR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_WPMR_WPEN_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_WPMR &= ~US_WPMR_WPEN;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_WPMR_WPEN_bit(const void *const hw)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_WPMR ^= US_WPMR_WPEN;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_set_US_WPMR_WPKEY_bf(const void *const hw, hri_usart_us_wpmr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_WPMR |= US_WPMR_WPKEY(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_wpmr_reg_t hri_usart_get_US_WPMR_WPKEY_bf(const void *const hw, hri_usart_us_wpmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_WPMR;
	tmp = (tmp & US_WPMR_WPKEY(mask)) >> US_WPMR_WPKEY_Pos;
	return tmp;
}

static inline void hri_usart_write_US_WPMR_WPKEY_bf(const void *const hw, hri_usart_us_wpmr_reg_t data)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_WPMR;
	tmp &= ~US_WPMR_WPKEY_Msk;
	tmp |= US_WPMR_WPKEY(data);
	((Usart *)hw)->US_WPMR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_WPMR_WPKEY_bf(const void *const hw, hri_usart_us_wpmr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_WPMR &= ~US_WPMR_WPKEY(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_WPMR_WPKEY_bf(const void *const hw, hri_usart_us_wpmr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_WPMR ^= US_WPMR_WPKEY(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_wpmr_reg_t hri_usart_read_US_WPMR_WPKEY_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_WPMR;
	tmp = (tmp & US_WPMR_WPKEY_Msk) >> US_WPMR_WPKEY_Pos;
	return tmp;
}

static inline void hri_usart_set_US_WPMR_reg(const void *const hw, hri_usart_us_wpmr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_WPMR |= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_wpmr_reg_t hri_usart_get_US_WPMR_reg(const void *const hw, hri_usart_us_wpmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_WPMR;
	tmp &= mask;
	return tmp;
}

static inline void hri_usart_write_US_WPMR_reg(const void *const hw, hri_usart_us_wpmr_reg_t data)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_WPMR = data;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_WPMR_reg(const void *const hw, hri_usart_us_wpmr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_WPMR &= ~mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_WPMR_reg(const void *const hw, hri_usart_us_wpmr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_WPMR ^= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_wpmr_reg_t hri_usart_read_US_WPMR_reg(const void *const hw)
{
	return ((Usart *)hw)->US_WPMR;
}

static inline void hri_usart_set_US_RPR_RXPTR_bf(const void *const hw, hri_usart_us_rpr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_RPR |= US_RPR_RXPTR(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_rpr_reg_t hri_usart_get_US_RPR_RXPTR_bf(const void *const hw, hri_usart_us_rpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_RPR;
	tmp = (tmp & US_RPR_RXPTR(mask)) >> US_RPR_RXPTR_Pos;
	return tmp;
}

static inline void hri_usart_write_US_RPR_RXPTR_bf(const void *const hw, hri_usart_us_rpr_reg_t data)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_RPR;
	tmp &= ~US_RPR_RXPTR_Msk;
	tmp |= US_RPR_RXPTR(data);
	((Usart *)hw)->US_RPR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_RPR_RXPTR_bf(const void *const hw, hri_usart_us_rpr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_RPR &= ~US_RPR_RXPTR(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_RPR_RXPTR_bf(const void *const hw, hri_usart_us_rpr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_RPR ^= US_RPR_RXPTR(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_rpr_reg_t hri_usart_read_US_RPR_RXPTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_RPR;
	tmp = (tmp & US_RPR_RXPTR_Msk) >> US_RPR_RXPTR_Pos;
	return tmp;
}

static inline void hri_usart_set_US_RPR_reg(const void *const hw, hri_usart_us_rpr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_RPR |= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_rpr_reg_t hri_usart_get_US_RPR_reg(const void *const hw, hri_usart_us_rpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_RPR;
	tmp &= mask;
	return tmp;
}

static inline void hri_usart_write_US_RPR_reg(const void *const hw, hri_usart_us_rpr_reg_t data)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_RPR = data;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_RPR_reg(const void *const hw, hri_usart_us_rpr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_RPR &= ~mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_RPR_reg(const void *const hw, hri_usart_us_rpr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_RPR ^= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_rpr_reg_t hri_usart_read_US_RPR_reg(const void *const hw)
{
	return ((Usart *)hw)->US_RPR;
}

static inline void hri_usart_set_US_RCR_RXCTR_bf(const void *const hw, hri_usart_us_rcr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_RCR |= US_RCR_RXCTR(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_rcr_reg_t hri_usart_get_US_RCR_RXCTR_bf(const void *const hw, hri_usart_us_rcr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_RCR;
	tmp = (tmp & US_RCR_RXCTR(mask)) >> US_RCR_RXCTR_Pos;
	return tmp;
}

static inline void hri_usart_write_US_RCR_RXCTR_bf(const void *const hw, hri_usart_us_rcr_reg_t data)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_RCR;
	tmp &= ~US_RCR_RXCTR_Msk;
	tmp |= US_RCR_RXCTR(data);
	((Usart *)hw)->US_RCR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_RCR_RXCTR_bf(const void *const hw, hri_usart_us_rcr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_RCR &= ~US_RCR_RXCTR(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_RCR_RXCTR_bf(const void *const hw, hri_usart_us_rcr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_RCR ^= US_RCR_RXCTR(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_rcr_reg_t hri_usart_read_US_RCR_RXCTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_RCR;
	tmp = (tmp & US_RCR_RXCTR_Msk) >> US_RCR_RXCTR_Pos;
	return tmp;
}

static inline void hri_usart_set_US_RCR_reg(const void *const hw, hri_usart_us_rcr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_RCR |= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_rcr_reg_t hri_usart_get_US_RCR_reg(const void *const hw, hri_usart_us_rcr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_RCR;
	tmp &= mask;
	return tmp;
}

static inline void hri_usart_write_US_RCR_reg(const void *const hw, hri_usart_us_rcr_reg_t data)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_RCR = data;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_RCR_reg(const void *const hw, hri_usart_us_rcr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_RCR &= ~mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_RCR_reg(const void *const hw, hri_usart_us_rcr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_RCR ^= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_rcr_reg_t hri_usart_read_US_RCR_reg(const void *const hw)
{
	return ((Usart *)hw)->US_RCR;
}

static inline void hri_usart_set_US_TPR_TXPTR_bf(const void *const hw, hri_usart_us_tpr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_TPR |= US_TPR_TXPTR(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_tpr_reg_t hri_usart_get_US_TPR_TXPTR_bf(const void *const hw, hri_usart_us_tpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_TPR;
	tmp = (tmp & US_TPR_TXPTR(mask)) >> US_TPR_TXPTR_Pos;
	return tmp;
}

static inline void hri_usart_write_US_TPR_TXPTR_bf(const void *const hw, hri_usart_us_tpr_reg_t data)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_TPR;
	tmp &= ~US_TPR_TXPTR_Msk;
	tmp |= US_TPR_TXPTR(data);
	((Usart *)hw)->US_TPR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_TPR_TXPTR_bf(const void *const hw, hri_usart_us_tpr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_TPR &= ~US_TPR_TXPTR(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_TPR_TXPTR_bf(const void *const hw, hri_usart_us_tpr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_TPR ^= US_TPR_TXPTR(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_tpr_reg_t hri_usart_read_US_TPR_TXPTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_TPR;
	tmp = (tmp & US_TPR_TXPTR_Msk) >> US_TPR_TXPTR_Pos;
	return tmp;
}

static inline void hri_usart_set_US_TPR_reg(const void *const hw, hri_usart_us_tpr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_TPR |= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_tpr_reg_t hri_usart_get_US_TPR_reg(const void *const hw, hri_usart_us_tpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_TPR;
	tmp &= mask;
	return tmp;
}

static inline void hri_usart_write_US_TPR_reg(const void *const hw, hri_usart_us_tpr_reg_t data)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_TPR = data;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_TPR_reg(const void *const hw, hri_usart_us_tpr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_TPR &= ~mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_TPR_reg(const void *const hw, hri_usart_us_tpr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_TPR ^= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_tpr_reg_t hri_usart_read_US_TPR_reg(const void *const hw)
{
	return ((Usart *)hw)->US_TPR;
}

static inline void hri_usart_set_US_TCR_TXCTR_bf(const void *const hw, hri_usart_us_tcr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_TCR |= US_TCR_TXCTR(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_tcr_reg_t hri_usart_get_US_TCR_TXCTR_bf(const void *const hw, hri_usart_us_tcr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_TCR;
	tmp = (tmp & US_TCR_TXCTR(mask)) >> US_TCR_TXCTR_Pos;
	return tmp;
}

static inline void hri_usart_write_US_TCR_TXCTR_bf(const void *const hw, hri_usart_us_tcr_reg_t data)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_TCR;
	tmp &= ~US_TCR_TXCTR_Msk;
	tmp |= US_TCR_TXCTR(data);
	((Usart *)hw)->US_TCR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_TCR_TXCTR_bf(const void *const hw, hri_usart_us_tcr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_TCR &= ~US_TCR_TXCTR(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_TCR_TXCTR_bf(const void *const hw, hri_usart_us_tcr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_TCR ^= US_TCR_TXCTR(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_tcr_reg_t hri_usart_read_US_TCR_TXCTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_TCR;
	tmp = (tmp & US_TCR_TXCTR_Msk) >> US_TCR_TXCTR_Pos;
	return tmp;
}

static inline void hri_usart_set_US_TCR_reg(const void *const hw, hri_usart_us_tcr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_TCR |= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_tcr_reg_t hri_usart_get_US_TCR_reg(const void *const hw, hri_usart_us_tcr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_TCR;
	tmp &= mask;
	return tmp;
}

static inline void hri_usart_write_US_TCR_reg(const void *const hw, hri_usart_us_tcr_reg_t data)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_TCR = data;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_TCR_reg(const void *const hw, hri_usart_us_tcr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_TCR &= ~mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_TCR_reg(const void *const hw, hri_usart_us_tcr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_TCR ^= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_tcr_reg_t hri_usart_read_US_TCR_reg(const void *const hw)
{
	return ((Usart *)hw)->US_TCR;
}

static inline void hri_usart_set_US_RNPR_RXNPTR_bf(const void *const hw, hri_usart_us_rnpr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_RNPR |= US_RNPR_RXNPTR(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_rnpr_reg_t hri_usart_get_US_RNPR_RXNPTR_bf(const void *const       hw,
                                                                      hri_usart_us_rnpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_RNPR;
	tmp = (tmp & US_RNPR_RXNPTR(mask)) >> US_RNPR_RXNPTR_Pos;
	return tmp;
}

static inline void hri_usart_write_US_RNPR_RXNPTR_bf(const void *const hw, hri_usart_us_rnpr_reg_t data)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_RNPR;
	tmp &= ~US_RNPR_RXNPTR_Msk;
	tmp |= US_RNPR_RXNPTR(data);
	((Usart *)hw)->US_RNPR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_RNPR_RXNPTR_bf(const void *const hw, hri_usart_us_rnpr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_RNPR &= ~US_RNPR_RXNPTR(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_RNPR_RXNPTR_bf(const void *const hw, hri_usart_us_rnpr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_RNPR ^= US_RNPR_RXNPTR(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_rnpr_reg_t hri_usart_read_US_RNPR_RXNPTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_RNPR;
	tmp = (tmp & US_RNPR_RXNPTR_Msk) >> US_RNPR_RXNPTR_Pos;
	return tmp;
}

static inline void hri_usart_set_US_RNPR_reg(const void *const hw, hri_usart_us_rnpr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_RNPR |= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_rnpr_reg_t hri_usart_get_US_RNPR_reg(const void *const hw, hri_usart_us_rnpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_RNPR;
	tmp &= mask;
	return tmp;
}

static inline void hri_usart_write_US_RNPR_reg(const void *const hw, hri_usart_us_rnpr_reg_t data)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_RNPR = data;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_RNPR_reg(const void *const hw, hri_usart_us_rnpr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_RNPR &= ~mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_RNPR_reg(const void *const hw, hri_usart_us_rnpr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_RNPR ^= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_rnpr_reg_t hri_usart_read_US_RNPR_reg(const void *const hw)
{
	return ((Usart *)hw)->US_RNPR;
}

static inline void hri_usart_set_US_RNCR_RXNCTR_bf(const void *const hw, hri_usart_us_rncr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_RNCR |= US_RNCR_RXNCTR(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_rncr_reg_t hri_usart_get_US_RNCR_RXNCTR_bf(const void *const       hw,
                                                                      hri_usart_us_rncr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_RNCR;
	tmp = (tmp & US_RNCR_RXNCTR(mask)) >> US_RNCR_RXNCTR_Pos;
	return tmp;
}

static inline void hri_usart_write_US_RNCR_RXNCTR_bf(const void *const hw, hri_usart_us_rncr_reg_t data)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_RNCR;
	tmp &= ~US_RNCR_RXNCTR_Msk;
	tmp |= US_RNCR_RXNCTR(data);
	((Usart *)hw)->US_RNCR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_RNCR_RXNCTR_bf(const void *const hw, hri_usart_us_rncr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_RNCR &= ~US_RNCR_RXNCTR(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_RNCR_RXNCTR_bf(const void *const hw, hri_usart_us_rncr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_RNCR ^= US_RNCR_RXNCTR(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_rncr_reg_t hri_usart_read_US_RNCR_RXNCTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_RNCR;
	tmp = (tmp & US_RNCR_RXNCTR_Msk) >> US_RNCR_RXNCTR_Pos;
	return tmp;
}

static inline void hri_usart_set_US_RNCR_reg(const void *const hw, hri_usart_us_rncr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_RNCR |= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_rncr_reg_t hri_usart_get_US_RNCR_reg(const void *const hw, hri_usart_us_rncr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_RNCR;
	tmp &= mask;
	return tmp;
}

static inline void hri_usart_write_US_RNCR_reg(const void *const hw, hri_usart_us_rncr_reg_t data)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_RNCR = data;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_RNCR_reg(const void *const hw, hri_usart_us_rncr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_RNCR &= ~mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_RNCR_reg(const void *const hw, hri_usart_us_rncr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_RNCR ^= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_rncr_reg_t hri_usart_read_US_RNCR_reg(const void *const hw)
{
	return ((Usart *)hw)->US_RNCR;
}

static inline void hri_usart_set_US_TNPR_TXNPTR_bf(const void *const hw, hri_usart_us_tnpr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_TNPR |= US_TNPR_TXNPTR(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_tnpr_reg_t hri_usart_get_US_TNPR_TXNPTR_bf(const void *const       hw,
                                                                      hri_usart_us_tnpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_TNPR;
	tmp = (tmp & US_TNPR_TXNPTR(mask)) >> US_TNPR_TXNPTR_Pos;
	return tmp;
}

static inline void hri_usart_write_US_TNPR_TXNPTR_bf(const void *const hw, hri_usart_us_tnpr_reg_t data)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_TNPR;
	tmp &= ~US_TNPR_TXNPTR_Msk;
	tmp |= US_TNPR_TXNPTR(data);
	((Usart *)hw)->US_TNPR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_TNPR_TXNPTR_bf(const void *const hw, hri_usart_us_tnpr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_TNPR &= ~US_TNPR_TXNPTR(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_TNPR_TXNPTR_bf(const void *const hw, hri_usart_us_tnpr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_TNPR ^= US_TNPR_TXNPTR(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_tnpr_reg_t hri_usart_read_US_TNPR_TXNPTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_TNPR;
	tmp = (tmp & US_TNPR_TXNPTR_Msk) >> US_TNPR_TXNPTR_Pos;
	return tmp;
}

static inline void hri_usart_set_US_TNPR_reg(const void *const hw, hri_usart_us_tnpr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_TNPR |= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_tnpr_reg_t hri_usart_get_US_TNPR_reg(const void *const hw, hri_usart_us_tnpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_TNPR;
	tmp &= mask;
	return tmp;
}

static inline void hri_usart_write_US_TNPR_reg(const void *const hw, hri_usart_us_tnpr_reg_t data)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_TNPR = data;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_TNPR_reg(const void *const hw, hri_usart_us_tnpr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_TNPR &= ~mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_TNPR_reg(const void *const hw, hri_usart_us_tnpr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_TNPR ^= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_tnpr_reg_t hri_usart_read_US_TNPR_reg(const void *const hw)
{
	return ((Usart *)hw)->US_TNPR;
}

static inline void hri_usart_set_US_TNCR_TXNCTR_bf(const void *const hw, hri_usart_us_tncr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_TNCR |= US_TNCR_TXNCTR(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_tncr_reg_t hri_usart_get_US_TNCR_TXNCTR_bf(const void *const       hw,
                                                                      hri_usart_us_tncr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_TNCR;
	tmp = (tmp & US_TNCR_TXNCTR(mask)) >> US_TNCR_TXNCTR_Pos;
	return tmp;
}

static inline void hri_usart_write_US_TNCR_TXNCTR_bf(const void *const hw, hri_usart_us_tncr_reg_t data)
{
	uint32_t tmp;
	USART_CRITICAL_SECTION_ENTER();
	tmp = ((Usart *)hw)->US_TNCR;
	tmp &= ~US_TNCR_TXNCTR_Msk;
	tmp |= US_TNCR_TXNCTR(data);
	((Usart *)hw)->US_TNCR = tmp;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_TNCR_TXNCTR_bf(const void *const hw, hri_usart_us_tncr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_TNCR &= ~US_TNCR_TXNCTR(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_TNCR_TXNCTR_bf(const void *const hw, hri_usart_us_tncr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_TNCR ^= US_TNCR_TXNCTR(mask);
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_tncr_reg_t hri_usart_read_US_TNCR_TXNCTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_TNCR;
	tmp = (tmp & US_TNCR_TXNCTR_Msk) >> US_TNCR_TXNCTR_Pos;
	return tmp;
}

static inline void hri_usart_set_US_TNCR_reg(const void *const hw, hri_usart_us_tncr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_TNCR |= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_tncr_reg_t hri_usart_get_US_TNCR_reg(const void *const hw, hri_usart_us_tncr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_TNCR;
	tmp &= mask;
	return tmp;
}

static inline void hri_usart_write_US_TNCR_reg(const void *const hw, hri_usart_us_tncr_reg_t data)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_TNCR = data;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_clear_US_TNCR_reg(const void *const hw, hri_usart_us_tncr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_TNCR &= ~mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usart_toggle_US_TNCR_reg(const void *const hw, hri_usart_us_tncr_reg_t mask)
{
	USART_CRITICAL_SECTION_ENTER();
	((Usart *)hw)->US_TNCR ^= mask;
	USART_CRITICAL_SECTION_LEAVE();
}

static inline hri_usart_us_tncr_reg_t hri_usart_read_US_TNCR_reg(const void *const hw)
{
	return ((Usart *)hw)->US_TNCR;
}

static inline bool hri_usart_get_US_CSR_RXRDY_bit(const void *const hw)
{
	return (((Usart *)hw)->US_CSR & US_CSR_RXRDY) > 0;
}

static inline bool hri_usart_get_US_CSR_TXRDY_bit(const void *const hw)
{
	return (((Usart *)hw)->US_CSR & US_CSR_TXRDY) > 0;
}

static inline bool hri_usart_get_US_CSR_RXBRK_bit(const void *const hw)
{
	return (((Usart *)hw)->US_CSR & US_CSR_RXBRK) > 0;
}

static inline bool hri_usart_get_US_CSR_ENDRX_bit(const void *const hw)
{
	return (((Usart *)hw)->US_CSR & US_CSR_ENDRX) > 0;
}

static inline bool hri_usart_get_US_CSR_ENDTX_bit(const void *const hw)
{
	return (((Usart *)hw)->US_CSR & US_CSR_ENDTX) > 0;
}

static inline bool hri_usart_get_US_CSR_OVRE_bit(const void *const hw)
{
	return (((Usart *)hw)->US_CSR & US_CSR_OVRE) > 0;
}

static inline bool hri_usart_get_US_CSR_FRAME_bit(const void *const hw)
{
	return (((Usart *)hw)->US_CSR & US_CSR_FRAME) > 0;
}

static inline bool hri_usart_get_US_CSR_PARE_bit(const void *const hw)
{
	return (((Usart *)hw)->US_CSR & US_CSR_PARE) > 0;
}

static inline bool hri_usart_get_US_CSR_TIMEOUT_bit(const void *const hw)
{
	return (((Usart *)hw)->US_CSR & US_CSR_TIMEOUT) > 0;
}

static inline bool hri_usart_get_US_CSR_TXEMPTY_bit(const void *const hw)
{
	return (((Usart *)hw)->US_CSR & US_CSR_TXEMPTY) > 0;
}

static inline bool hri_usart_get_US_CSR_ITER_bit(const void *const hw)
{
	return (((Usart *)hw)->US_CSR & US_CSR_ITER) > 0;
}

static inline bool hri_usart_get_US_CSR_TXBUFE_bit(const void *const hw)
{
	return (((Usart *)hw)->US_CSR & US_CSR_TXBUFE) > 0;
}

static inline bool hri_usart_get_US_CSR_RXBUFF_bit(const void *const hw)
{
	return (((Usart *)hw)->US_CSR & US_CSR_RXBUFF) > 0;
}

static inline bool hri_usart_get_US_CSR_NACK_bit(const void *const hw)
{
	return (((Usart *)hw)->US_CSR & US_CSR_NACK) > 0;
}

static inline bool hri_usart_get_US_CSR_CTSIC_bit(const void *const hw)
{
	return (((Usart *)hw)->US_CSR & US_CSR_CTSIC) > 0;
}

static inline bool hri_usart_get_US_CSR_CMP_bit(const void *const hw)
{
	return (((Usart *)hw)->US_CSR & US_CSR_CMP) > 0;
}

static inline bool hri_usart_get_US_CSR_CTS_bit(const void *const hw)
{
	return (((Usart *)hw)->US_CSR & US_CSR_CTS) > 0;
}

static inline hri_usart_us_csr_reg_t hri_usart_get_US_CSR_reg(const void *const hw, hri_usart_us_csr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_CSR;
	tmp &= mask;
	return tmp;
}

static inline hri_usart_us_csr_reg_t hri_usart_read_US_CSR_reg(const void *const hw)
{
	return ((Usart *)hw)->US_CSR;
}

static inline bool hri_usart_get_US_RHR_RXSYNH_bit(const void *const hw)
{
	return (((Usart *)hw)->US_RHR & US_RHR_RXSYNH) > 0;
}

static inline hri_usart_us_rhr_reg_t hri_usart_get_US_RHR_RXCHR_bf(const void *const hw, hri_usart_us_rhr_reg_t mask)
{
	return (((Usart *)hw)->US_RHR & US_RHR_RXCHR(mask)) >> US_RHR_RXCHR_Pos;
}

static inline hri_usart_us_rhr_reg_t hri_usart_read_US_RHR_RXCHR_bf(const void *const hw)
{
	return (((Usart *)hw)->US_RHR & US_RHR_RXCHR_Msk) >> US_RHR_RXCHR_Pos;
}

static inline hri_usart_us_rhr_reg_t hri_usart_get_US_RHR_reg(const void *const hw, hri_usart_us_rhr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_RHR;
	tmp &= mask;
	return tmp;
}

static inline hri_usart_us_rhr_reg_t hri_usart_read_US_RHR_reg(const void *const hw)
{
	return ((Usart *)hw)->US_RHR;
}

static inline hri_usart_us_ner_reg_t hri_usart_get_US_NER_NB_ERRORS_bf(const void *const      hw,
                                                                       hri_usart_us_ner_reg_t mask)
{
	return (((Usart *)hw)->US_NER & US_NER_NB_ERRORS(mask)) >> US_NER_NB_ERRORS_Pos;
}

static inline hri_usart_us_ner_reg_t hri_usart_read_US_NER_NB_ERRORS_bf(const void *const hw)
{
	return (((Usart *)hw)->US_NER & US_NER_NB_ERRORS_Msk) >> US_NER_NB_ERRORS_Pos;
}

static inline hri_usart_us_ner_reg_t hri_usart_get_US_NER_reg(const void *const hw, hri_usart_us_ner_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_NER;
	tmp &= mask;
	return tmp;
}

static inline hri_usart_us_ner_reg_t hri_usart_read_US_NER_reg(const void *const hw)
{
	return ((Usart *)hw)->US_NER;
}

static inline hri_usart_us_linbrr_reg_t hri_usart_get_US_LINBRR_LINCD_bf(const void *const         hw,
                                                                         hri_usart_us_linbrr_reg_t mask)
{
	return (((Usart *)hw)->US_LINBRR & US_LINBRR_LINCD(mask)) >> US_LINBRR_LINCD_Pos;
}

static inline hri_usart_us_linbrr_reg_t hri_usart_read_US_LINBRR_LINCD_bf(const void *const hw)
{
	return (((Usart *)hw)->US_LINBRR & US_LINBRR_LINCD_Msk) >> US_LINBRR_LINCD_Pos;
}

static inline hri_usart_us_linbrr_reg_t hri_usart_get_US_LINBRR_LINFP_bf(const void *const         hw,
                                                                         hri_usart_us_linbrr_reg_t mask)
{
	return (((Usart *)hw)->US_LINBRR & US_LINBRR_LINFP(mask)) >> US_LINBRR_LINFP_Pos;
}

static inline hri_usart_us_linbrr_reg_t hri_usart_read_US_LINBRR_LINFP_bf(const void *const hw)
{
	return (((Usart *)hw)->US_LINBRR & US_LINBRR_LINFP_Msk) >> US_LINBRR_LINFP_Pos;
}

static inline hri_usart_us_linbrr_reg_t hri_usart_get_US_LINBRR_reg(const void *const         hw,
                                                                    hri_usart_us_linbrr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_LINBRR;
	tmp &= mask;
	return tmp;
}

static inline hri_usart_us_linbrr_reg_t hri_usart_read_US_LINBRR_reg(const void *const hw)
{
	return ((Usart *)hw)->US_LINBRR;
}

static inline bool hri_usart_get_US_WPSR_WPVS_bit(const void *const hw)
{
	return (((Usart *)hw)->US_WPSR & US_WPSR_WPVS) > 0;
}

static inline hri_usart_us_wpsr_reg_t hri_usart_get_US_WPSR_WPVSRC_bf(const void *const       hw,
                                                                      hri_usart_us_wpsr_reg_t mask)
{
	return (((Usart *)hw)->US_WPSR & US_WPSR_WPVSRC(mask)) >> US_WPSR_WPVSRC_Pos;
}

static inline hri_usart_us_wpsr_reg_t hri_usart_read_US_WPSR_WPVSRC_bf(const void *const hw)
{
	return (((Usart *)hw)->US_WPSR & US_WPSR_WPVSRC_Msk) >> US_WPSR_WPVSRC_Pos;
}

static inline hri_usart_us_wpsr_reg_t hri_usart_get_US_WPSR_reg(const void *const hw, hri_usart_us_wpsr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_WPSR;
	tmp &= mask;
	return tmp;
}

static inline hri_usart_us_wpsr_reg_t hri_usart_read_US_WPSR_reg(const void *const hw)
{
	return ((Usart *)hw)->US_WPSR;
}

static inline bool hri_usart_get_US_PTSR_RXTEN_bit(const void *const hw)
{
	return (((Usart *)hw)->US_PTSR & US_PTSR_RXTEN) > 0;
}

static inline bool hri_usart_get_US_PTSR_TXTEN_bit(const void *const hw)
{
	return (((Usart *)hw)->US_PTSR & US_PTSR_TXTEN) > 0;
}

static inline bool hri_usart_get_US_PTSR_RXCBEN_bit(const void *const hw)
{
	return (((Usart *)hw)->US_PTSR & US_PTSR_RXCBEN) > 0;
}

static inline bool hri_usart_get_US_PTSR_TXCBEN_bit(const void *const hw)
{
	return (((Usart *)hw)->US_PTSR & US_PTSR_TXCBEN) > 0;
}

static inline bool hri_usart_get_US_PTSR_ERR_bit(const void *const hw)
{
	return (((Usart *)hw)->US_PTSR & US_PTSR_ERR) > 0;
}

static inline hri_usart_us_ptsr_reg_t hri_usart_get_US_PTSR_reg(const void *const hw, hri_usart_us_ptsr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usart *)hw)->US_PTSR;
	tmp &= mask;
	return tmp;
}

static inline hri_usart_us_ptsr_reg_t hri_usart_read_US_PTSR_reg(const void *const hw)
{
	return ((Usart *)hw)->US_PTSR;
}

#ifdef __cplusplus
}
#endif

#endif /* _HRI_USART_G55_H_INCLUDED */
#endif /* _SAMG55_USART_COMPONENT_ */
