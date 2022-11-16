/**
 * \file
 *
 * \brief SAM TWI
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

#ifdef _SAMG55_TWI_COMPONENT_
#ifndef _HRI_TWI_G55_H_INCLUDED_
#define _HRI_TWI_G55_H_INCLUDED_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <hal_atomic.h>

#if defined(ENABLE_TWI_CRITICAL_SECTIONS)
#define TWI_CRITICAL_SECTION_ENTER() CRITICAL_SECTION_ENTER()
#define TWI_CRITICAL_SECTION_LEAVE() CRITICAL_SECTION_LEAVE()
#else
#define TWI_CRITICAL_SECTION_ENTER()
#define TWI_CRITICAL_SECTION_LEAVE()
#endif

typedef uint32_t hri_twi_acr_reg_t;
typedef uint32_t hri_twi_cr_reg_t;
typedef uint32_t hri_twi_cwgr_reg_t;
typedef uint32_t hri_twi_filtr_reg_t;
typedef uint32_t hri_twi_iadr_reg_t;
typedef uint32_t hri_twi_imr_reg_t;
typedef uint32_t hri_twi_mmr_reg_t;
typedef uint32_t hri_twi_ptcr_reg_t;
typedef uint32_t hri_twi_ptsr_reg_t;
typedef uint32_t hri_twi_rcr_reg_t;
typedef uint32_t hri_twi_rhr_reg_t;
typedef uint32_t hri_twi_rncr_reg_t;
typedef uint32_t hri_twi_rnpr_reg_t;
typedef uint32_t hri_twi_rpr_reg_t;
typedef uint32_t hri_twi_smbtr_reg_t;
typedef uint32_t hri_twi_smr_reg_t;
typedef uint32_t hri_twi_sr_reg_t;
typedef uint32_t hri_twi_swmr_reg_t;
typedef uint32_t hri_twi_tcr_reg_t;
typedef uint32_t hri_twi_thr_reg_t;
typedef uint32_t hri_twi_tncr_reg_t;
typedef uint32_t hri_twi_tnpr_reg_t;
typedef uint32_t hri_twi_tpr_reg_t;
typedef uint32_t hri_twi_wpmr_reg_t;
typedef uint32_t hri_twi_wpsr_reg_t;

static inline void hri_twi_set_IMR_TXCOMP_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IER = TWI_IMR_TXCOMP;
}

static inline bool hri_twi_get_IMR_TXCOMP_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_IMR & TWI_IMR_TXCOMP) >> TWI_IMR_TXCOMP_Pos;
}

static inline void hri_twi_write_IMR_TXCOMP_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Twi *)hw)->TWI_IDR = TWI_IMR_TXCOMP;
	} else {
		((Twi *)hw)->TWI_IER = TWI_IMR_TXCOMP;
	}
}

static inline void hri_twi_clear_IMR_TXCOMP_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IDR = TWI_IMR_TXCOMP;
}

static inline void hri_twi_set_IMR_RXRDY_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IER = TWI_IMR_RXRDY;
}

static inline bool hri_twi_get_IMR_RXRDY_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_IMR & TWI_IMR_RXRDY) >> TWI_IMR_RXRDY_Pos;
}

static inline void hri_twi_write_IMR_RXRDY_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Twi *)hw)->TWI_IDR = TWI_IMR_RXRDY;
	} else {
		((Twi *)hw)->TWI_IER = TWI_IMR_RXRDY;
	}
}

static inline void hri_twi_clear_IMR_RXRDY_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IDR = TWI_IMR_RXRDY;
}

static inline void hri_twi_set_IMR_TXRDY_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IER = TWI_IMR_TXRDY;
}

static inline bool hri_twi_get_IMR_TXRDY_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_IMR & TWI_IMR_TXRDY) >> TWI_IMR_TXRDY_Pos;
}

static inline void hri_twi_write_IMR_TXRDY_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Twi *)hw)->TWI_IDR = TWI_IMR_TXRDY;
	} else {
		((Twi *)hw)->TWI_IER = TWI_IMR_TXRDY;
	}
}

static inline void hri_twi_clear_IMR_TXRDY_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IDR = TWI_IMR_TXRDY;
}

static inline void hri_twi_set_IMR_SVACC_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IER = TWI_IMR_SVACC;
}

static inline bool hri_twi_get_IMR_SVACC_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_IMR & TWI_IMR_SVACC) >> TWI_IMR_SVACC_Pos;
}

static inline void hri_twi_write_IMR_SVACC_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Twi *)hw)->TWI_IDR = TWI_IMR_SVACC;
	} else {
		((Twi *)hw)->TWI_IER = TWI_IMR_SVACC;
	}
}

static inline void hri_twi_clear_IMR_SVACC_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IDR = TWI_IMR_SVACC;
}

static inline void hri_twi_set_IMR_GACC_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IER = TWI_IMR_GACC;
}

static inline bool hri_twi_get_IMR_GACC_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_IMR & TWI_IMR_GACC) >> TWI_IMR_GACC_Pos;
}

static inline void hri_twi_write_IMR_GACC_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Twi *)hw)->TWI_IDR = TWI_IMR_GACC;
	} else {
		((Twi *)hw)->TWI_IER = TWI_IMR_GACC;
	}
}

static inline void hri_twi_clear_IMR_GACC_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IDR = TWI_IMR_GACC;
}

static inline void hri_twi_set_IMR_OVRE_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IER = TWI_IMR_OVRE;
}

static inline bool hri_twi_get_IMR_OVRE_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_IMR & TWI_IMR_OVRE) >> TWI_IMR_OVRE_Pos;
}

static inline void hri_twi_write_IMR_OVRE_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Twi *)hw)->TWI_IDR = TWI_IMR_OVRE;
	} else {
		((Twi *)hw)->TWI_IER = TWI_IMR_OVRE;
	}
}

static inline void hri_twi_clear_IMR_OVRE_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IDR = TWI_IMR_OVRE;
}

static inline void hri_twi_set_IMR_UNRE_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IER = TWI_IMR_UNRE;
}

static inline bool hri_twi_get_IMR_UNRE_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_IMR & TWI_IMR_UNRE) >> TWI_IMR_UNRE_Pos;
}

static inline void hri_twi_write_IMR_UNRE_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Twi *)hw)->TWI_IDR = TWI_IMR_UNRE;
	} else {
		((Twi *)hw)->TWI_IER = TWI_IMR_UNRE;
	}
}

static inline void hri_twi_clear_IMR_UNRE_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IDR = TWI_IMR_UNRE;
}

static inline void hri_twi_set_IMR_NACK_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IER = TWI_IMR_NACK;
}

static inline bool hri_twi_get_IMR_NACK_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_IMR & TWI_IMR_NACK) >> TWI_IMR_NACK_Pos;
}

static inline void hri_twi_write_IMR_NACK_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Twi *)hw)->TWI_IDR = TWI_IMR_NACK;
	} else {
		((Twi *)hw)->TWI_IER = TWI_IMR_NACK;
	}
}

static inline void hri_twi_clear_IMR_NACK_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IDR = TWI_IMR_NACK;
}

static inline void hri_twi_set_IMR_ARBLST_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IER = TWI_IMR_ARBLST;
}

static inline bool hri_twi_get_IMR_ARBLST_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_IMR & TWI_IMR_ARBLST) >> TWI_IMR_ARBLST_Pos;
}

static inline void hri_twi_write_IMR_ARBLST_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Twi *)hw)->TWI_IDR = TWI_IMR_ARBLST;
	} else {
		((Twi *)hw)->TWI_IER = TWI_IMR_ARBLST;
	}
}

static inline void hri_twi_clear_IMR_ARBLST_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IDR = TWI_IMR_ARBLST;
}

static inline void hri_twi_set_IMR_SCL_WS_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IER = TWI_IMR_SCL_WS;
}

static inline bool hri_twi_get_IMR_SCL_WS_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_IMR & TWI_IMR_SCL_WS) >> TWI_IMR_SCL_WS_Pos;
}

static inline void hri_twi_write_IMR_SCL_WS_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Twi *)hw)->TWI_IDR = TWI_IMR_SCL_WS;
	} else {
		((Twi *)hw)->TWI_IER = TWI_IMR_SCL_WS;
	}
}

static inline void hri_twi_clear_IMR_SCL_WS_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IDR = TWI_IMR_SCL_WS;
}

static inline void hri_twi_set_IMR_EOSACC_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IER = TWI_IMR_EOSACC;
}

static inline bool hri_twi_get_IMR_EOSACC_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_IMR & TWI_IMR_EOSACC) >> TWI_IMR_EOSACC_Pos;
}

static inline void hri_twi_write_IMR_EOSACC_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Twi *)hw)->TWI_IDR = TWI_IMR_EOSACC;
	} else {
		((Twi *)hw)->TWI_IER = TWI_IMR_EOSACC;
	}
}

static inline void hri_twi_clear_IMR_EOSACC_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IDR = TWI_IMR_EOSACC;
}

static inline void hri_twi_set_IMR_ENDRX_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IER = TWI_IMR_ENDRX;
}

static inline bool hri_twi_get_IMR_ENDRX_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_IMR & TWI_IMR_ENDRX) >> TWI_IMR_ENDRX_Pos;
}

static inline void hri_twi_write_IMR_ENDRX_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Twi *)hw)->TWI_IDR = TWI_IMR_ENDRX;
	} else {
		((Twi *)hw)->TWI_IER = TWI_IMR_ENDRX;
	}
}

static inline void hri_twi_clear_IMR_ENDRX_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IDR = TWI_IMR_ENDRX;
}

static inline void hri_twi_set_IMR_ENDTX_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IER = TWI_IMR_ENDTX;
}

static inline bool hri_twi_get_IMR_ENDTX_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_IMR & TWI_IMR_ENDTX) >> TWI_IMR_ENDTX_Pos;
}

static inline void hri_twi_write_IMR_ENDTX_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Twi *)hw)->TWI_IDR = TWI_IMR_ENDTX;
	} else {
		((Twi *)hw)->TWI_IER = TWI_IMR_ENDTX;
	}
}

static inline void hri_twi_clear_IMR_ENDTX_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IDR = TWI_IMR_ENDTX;
}

static inline void hri_twi_set_IMR_RXBUFF_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IER = TWI_IMR_RXBUFF;
}

static inline bool hri_twi_get_IMR_RXBUFF_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_IMR & TWI_IMR_RXBUFF) >> TWI_IMR_RXBUFF_Pos;
}

static inline void hri_twi_write_IMR_RXBUFF_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Twi *)hw)->TWI_IDR = TWI_IMR_RXBUFF;
	} else {
		((Twi *)hw)->TWI_IER = TWI_IMR_RXBUFF;
	}
}

static inline void hri_twi_clear_IMR_RXBUFF_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IDR = TWI_IMR_RXBUFF;
}

static inline void hri_twi_set_IMR_TXBUFE_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IER = TWI_IMR_TXBUFE;
}

static inline bool hri_twi_get_IMR_TXBUFE_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_IMR & TWI_IMR_TXBUFE) >> TWI_IMR_TXBUFE_Pos;
}

static inline void hri_twi_write_IMR_TXBUFE_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Twi *)hw)->TWI_IDR = TWI_IMR_TXBUFE;
	} else {
		((Twi *)hw)->TWI_IER = TWI_IMR_TXBUFE;
	}
}

static inline void hri_twi_clear_IMR_TXBUFE_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IDR = TWI_IMR_TXBUFE;
}

static inline void hri_twi_set_IMR_MCACK_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IER = TWI_IMR_MCACK;
}

static inline bool hri_twi_get_IMR_MCACK_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_IMR & TWI_IMR_MCACK) >> TWI_IMR_MCACK_Pos;
}

static inline void hri_twi_write_IMR_MCACK_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Twi *)hw)->TWI_IDR = TWI_IMR_MCACK;
	} else {
		((Twi *)hw)->TWI_IER = TWI_IMR_MCACK;
	}
}

static inline void hri_twi_clear_IMR_MCACK_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IDR = TWI_IMR_MCACK;
}

static inline void hri_twi_set_IMR_TOUT_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IER = TWI_IMR_TOUT;
}

static inline bool hri_twi_get_IMR_TOUT_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_IMR & TWI_IMR_TOUT) >> TWI_IMR_TOUT_Pos;
}

static inline void hri_twi_write_IMR_TOUT_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Twi *)hw)->TWI_IDR = TWI_IMR_TOUT;
	} else {
		((Twi *)hw)->TWI_IER = TWI_IMR_TOUT;
	}
}

static inline void hri_twi_clear_IMR_TOUT_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IDR = TWI_IMR_TOUT;
}

static inline void hri_twi_set_IMR_PECERR_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IER = TWI_IMR_PECERR;
}

static inline bool hri_twi_get_IMR_PECERR_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_IMR & TWI_IMR_PECERR) >> TWI_IMR_PECERR_Pos;
}

static inline void hri_twi_write_IMR_PECERR_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Twi *)hw)->TWI_IDR = TWI_IMR_PECERR;
	} else {
		((Twi *)hw)->TWI_IER = TWI_IMR_PECERR;
	}
}

static inline void hri_twi_clear_IMR_PECERR_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IDR = TWI_IMR_PECERR;
}

static inline void hri_twi_set_IMR_SMBDAM_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IER = TWI_IMR_SMBDAM;
}

static inline bool hri_twi_get_IMR_SMBDAM_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_IMR & TWI_IMR_SMBDAM) >> TWI_IMR_SMBDAM_Pos;
}

static inline void hri_twi_write_IMR_SMBDAM_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Twi *)hw)->TWI_IDR = TWI_IMR_SMBDAM;
	} else {
		((Twi *)hw)->TWI_IER = TWI_IMR_SMBDAM;
	}
}

static inline void hri_twi_clear_IMR_SMBDAM_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IDR = TWI_IMR_SMBDAM;
}

static inline void hri_twi_set_IMR_SMBHHM_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IER = TWI_IMR_SMBHHM;
}

static inline bool hri_twi_get_IMR_SMBHHM_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_IMR & TWI_IMR_SMBHHM) >> TWI_IMR_SMBHHM_Pos;
}

static inline void hri_twi_write_IMR_SMBHHM_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Twi *)hw)->TWI_IDR = TWI_IMR_SMBHHM;
	} else {
		((Twi *)hw)->TWI_IER = TWI_IMR_SMBHHM;
	}
}

static inline void hri_twi_clear_IMR_SMBHHM_bit(const void *const hw)
{
	((Twi *)hw)->TWI_IDR = TWI_IMR_SMBHHM;
}

static inline void hri_twi_set_IMR_reg(const void *const hw, hri_twi_imr_reg_t mask)
{
	((Twi *)hw)->TWI_IER = mask;
}

static inline hri_twi_imr_reg_t hri_twi_get_IMR_reg(const void *const hw, hri_twi_imr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_IMR;
	tmp &= mask;
	return tmp;
}

static inline hri_twi_imr_reg_t hri_twi_read_IMR_reg(const void *const hw)
{
	return ((Twi *)hw)->TWI_IMR;
}

static inline void hri_twi_write_IMR_reg(const void *const hw, hri_twi_imr_reg_t data)
{
	((Twi *)hw)->TWI_IER = data;
	((Twi *)hw)->TWI_IDR = ~data;
}

static inline void hri_twi_clear_IMR_reg(const void *const hw, hri_twi_imr_reg_t mask)
{
	((Twi *)hw)->TWI_IDR = mask;
}

static inline void hri_twi_write_CR_reg(const void *const hw, hri_twi_cr_reg_t data)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_CR = data;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_write_THR_reg(const void *const hw, hri_twi_thr_reg_t data)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_THR = data;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_write_PTCR_reg(const void *const hw, hri_twi_ptcr_reg_t data)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_PTCR = data;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_set_MMR_MREAD_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_MMR |= TWI_MMR_MREAD;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_twi_get_MMR_MREAD_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_MMR;
	tmp = (tmp & TWI_MMR_MREAD) >> TWI_MMR_MREAD_Pos;
	return (bool)tmp;
}

static inline void hri_twi_write_MMR_MREAD_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_MMR;
	tmp &= ~TWI_MMR_MREAD;
	tmp |= value << TWI_MMR_MREAD_Pos;
	((Twi *)hw)->TWI_MMR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_MMR_MREAD_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_MMR &= ~TWI_MMR_MREAD;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_MMR_MREAD_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_MMR ^= TWI_MMR_MREAD;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_set_MMR_IADRSZ_bf(const void *const hw, hri_twi_mmr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_MMR |= TWI_MMR_IADRSZ(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_mmr_reg_t hri_twi_get_MMR_IADRSZ_bf(const void *const hw, hri_twi_mmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_MMR;
	tmp = (tmp & TWI_MMR_IADRSZ(mask)) >> TWI_MMR_IADRSZ_Pos;
	return tmp;
}

static inline void hri_twi_write_MMR_IADRSZ_bf(const void *const hw, hri_twi_mmr_reg_t data)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_MMR;
	tmp &= ~TWI_MMR_IADRSZ_Msk;
	tmp |= TWI_MMR_IADRSZ(data);
	((Twi *)hw)->TWI_MMR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_MMR_IADRSZ_bf(const void *const hw, hri_twi_mmr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_MMR &= ~TWI_MMR_IADRSZ(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_MMR_IADRSZ_bf(const void *const hw, hri_twi_mmr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_MMR ^= TWI_MMR_IADRSZ(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_mmr_reg_t hri_twi_read_MMR_IADRSZ_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_MMR;
	tmp = (tmp & TWI_MMR_IADRSZ_Msk) >> TWI_MMR_IADRSZ_Pos;
	return tmp;
}

static inline void hri_twi_set_MMR_DADR_bf(const void *const hw, hri_twi_mmr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_MMR |= TWI_MMR_DADR(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_mmr_reg_t hri_twi_get_MMR_DADR_bf(const void *const hw, hri_twi_mmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_MMR;
	tmp = (tmp & TWI_MMR_DADR(mask)) >> TWI_MMR_DADR_Pos;
	return tmp;
}

static inline void hri_twi_write_MMR_DADR_bf(const void *const hw, hri_twi_mmr_reg_t data)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_MMR;
	tmp &= ~TWI_MMR_DADR_Msk;
	tmp |= TWI_MMR_DADR(data);
	((Twi *)hw)->TWI_MMR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_MMR_DADR_bf(const void *const hw, hri_twi_mmr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_MMR &= ~TWI_MMR_DADR(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_MMR_DADR_bf(const void *const hw, hri_twi_mmr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_MMR ^= TWI_MMR_DADR(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_mmr_reg_t hri_twi_read_MMR_DADR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_MMR;
	tmp = (tmp & TWI_MMR_DADR_Msk) >> TWI_MMR_DADR_Pos;
	return tmp;
}

static inline void hri_twi_set_MMR_reg(const void *const hw, hri_twi_mmr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_MMR |= mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_mmr_reg_t hri_twi_get_MMR_reg(const void *const hw, hri_twi_mmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_MMR;
	tmp &= mask;
	return tmp;
}

static inline void hri_twi_write_MMR_reg(const void *const hw, hri_twi_mmr_reg_t data)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_MMR = data;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_MMR_reg(const void *const hw, hri_twi_mmr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_MMR &= ~mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_MMR_reg(const void *const hw, hri_twi_mmr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_MMR ^= mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_mmr_reg_t hri_twi_read_MMR_reg(const void *const hw)
{
	return ((Twi *)hw)->TWI_MMR;
}

static inline void hri_twi_set_SMR_NACKEN_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMR |= TWI_SMR_NACKEN;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_twi_get_SMR_NACKEN_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_SMR;
	tmp = (tmp & TWI_SMR_NACKEN) >> TWI_SMR_NACKEN_Pos;
	return (bool)tmp;
}

static inline void hri_twi_write_SMR_NACKEN_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_SMR;
	tmp &= ~TWI_SMR_NACKEN;
	tmp |= value << TWI_SMR_NACKEN_Pos;
	((Twi *)hw)->TWI_SMR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_SMR_NACKEN_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMR &= ~TWI_SMR_NACKEN;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_SMR_NACKEN_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMR ^= TWI_SMR_NACKEN;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_set_SMR_SMDA_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMR |= TWI_SMR_SMDA;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_twi_get_SMR_SMDA_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_SMR;
	tmp = (tmp & TWI_SMR_SMDA) >> TWI_SMR_SMDA_Pos;
	return (bool)tmp;
}

static inline void hri_twi_write_SMR_SMDA_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_SMR;
	tmp &= ~TWI_SMR_SMDA;
	tmp |= value << TWI_SMR_SMDA_Pos;
	((Twi *)hw)->TWI_SMR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_SMR_SMDA_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMR &= ~TWI_SMR_SMDA;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_SMR_SMDA_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMR ^= TWI_SMR_SMDA;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_set_SMR_SMHH_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMR |= TWI_SMR_SMHH;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_twi_get_SMR_SMHH_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_SMR;
	tmp = (tmp & TWI_SMR_SMHH) >> TWI_SMR_SMHH_Pos;
	return (bool)tmp;
}

static inline void hri_twi_write_SMR_SMHH_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_SMR;
	tmp &= ~TWI_SMR_SMHH;
	tmp |= value << TWI_SMR_SMHH_Pos;
	((Twi *)hw)->TWI_SMR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_SMR_SMHH_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMR &= ~TWI_SMR_SMHH;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_SMR_SMHH_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMR ^= TWI_SMR_SMHH;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_set_SMR_SCLWSDIS_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMR |= TWI_SMR_SCLWSDIS;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_twi_get_SMR_SCLWSDIS_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_SMR;
	tmp = (tmp & TWI_SMR_SCLWSDIS) >> TWI_SMR_SCLWSDIS_Pos;
	return (bool)tmp;
}

static inline void hri_twi_write_SMR_SCLWSDIS_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_SMR;
	tmp &= ~TWI_SMR_SCLWSDIS;
	tmp |= value << TWI_SMR_SCLWSDIS_Pos;
	((Twi *)hw)->TWI_SMR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_SMR_SCLWSDIS_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMR &= ~TWI_SMR_SCLWSDIS;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_SMR_SCLWSDIS_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMR ^= TWI_SMR_SCLWSDIS;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_set_SMR_SADR1EN_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMR |= TWI_SMR_SADR1EN;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_twi_get_SMR_SADR1EN_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_SMR;
	tmp = (tmp & TWI_SMR_SADR1EN) >> TWI_SMR_SADR1EN_Pos;
	return (bool)tmp;
}

static inline void hri_twi_write_SMR_SADR1EN_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_SMR;
	tmp &= ~TWI_SMR_SADR1EN;
	tmp |= value << TWI_SMR_SADR1EN_Pos;
	((Twi *)hw)->TWI_SMR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_SMR_SADR1EN_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMR &= ~TWI_SMR_SADR1EN;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_SMR_SADR1EN_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMR ^= TWI_SMR_SADR1EN;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_set_SMR_SADR2EN_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMR |= TWI_SMR_SADR2EN;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_twi_get_SMR_SADR2EN_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_SMR;
	tmp = (tmp & TWI_SMR_SADR2EN) >> TWI_SMR_SADR2EN_Pos;
	return (bool)tmp;
}

static inline void hri_twi_write_SMR_SADR2EN_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_SMR;
	tmp &= ~TWI_SMR_SADR2EN;
	tmp |= value << TWI_SMR_SADR2EN_Pos;
	((Twi *)hw)->TWI_SMR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_SMR_SADR2EN_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMR &= ~TWI_SMR_SADR2EN;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_SMR_SADR2EN_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMR ^= TWI_SMR_SADR2EN;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_set_SMR_SADR3EN_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMR |= TWI_SMR_SADR3EN;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_twi_get_SMR_SADR3EN_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_SMR;
	tmp = (tmp & TWI_SMR_SADR3EN) >> TWI_SMR_SADR3EN_Pos;
	return (bool)tmp;
}

static inline void hri_twi_write_SMR_SADR3EN_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_SMR;
	tmp &= ~TWI_SMR_SADR3EN;
	tmp |= value << TWI_SMR_SADR3EN_Pos;
	((Twi *)hw)->TWI_SMR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_SMR_SADR3EN_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMR &= ~TWI_SMR_SADR3EN;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_SMR_SADR3EN_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMR ^= TWI_SMR_SADR3EN;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_set_SMR_DATAMEN_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMR |= TWI_SMR_DATAMEN;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_twi_get_SMR_DATAMEN_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_SMR;
	tmp = (tmp & TWI_SMR_DATAMEN) >> TWI_SMR_DATAMEN_Pos;
	return (bool)tmp;
}

static inline void hri_twi_write_SMR_DATAMEN_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_SMR;
	tmp &= ~TWI_SMR_DATAMEN;
	tmp |= value << TWI_SMR_DATAMEN_Pos;
	((Twi *)hw)->TWI_SMR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_SMR_DATAMEN_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMR &= ~TWI_SMR_DATAMEN;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_SMR_DATAMEN_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMR ^= TWI_SMR_DATAMEN;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_set_SMR_MASK_bf(const void *const hw, hri_twi_smr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMR |= TWI_SMR_MASK(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_smr_reg_t hri_twi_get_SMR_MASK_bf(const void *const hw, hri_twi_smr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_SMR;
	tmp = (tmp & TWI_SMR_MASK(mask)) >> TWI_SMR_MASK_Pos;
	return tmp;
}

static inline void hri_twi_write_SMR_MASK_bf(const void *const hw, hri_twi_smr_reg_t data)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_SMR;
	tmp &= ~TWI_SMR_MASK_Msk;
	tmp |= TWI_SMR_MASK(data);
	((Twi *)hw)->TWI_SMR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_SMR_MASK_bf(const void *const hw, hri_twi_smr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMR &= ~TWI_SMR_MASK(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_SMR_MASK_bf(const void *const hw, hri_twi_smr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMR ^= TWI_SMR_MASK(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_smr_reg_t hri_twi_read_SMR_MASK_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_SMR;
	tmp = (tmp & TWI_SMR_MASK_Msk) >> TWI_SMR_MASK_Pos;
	return tmp;
}

static inline void hri_twi_set_SMR_SADR_bf(const void *const hw, hri_twi_smr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMR |= TWI_SMR_SADR(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_smr_reg_t hri_twi_get_SMR_SADR_bf(const void *const hw, hri_twi_smr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_SMR;
	tmp = (tmp & TWI_SMR_SADR(mask)) >> TWI_SMR_SADR_Pos;
	return tmp;
}

static inline void hri_twi_write_SMR_SADR_bf(const void *const hw, hri_twi_smr_reg_t data)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_SMR;
	tmp &= ~TWI_SMR_SADR_Msk;
	tmp |= TWI_SMR_SADR(data);
	((Twi *)hw)->TWI_SMR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_SMR_SADR_bf(const void *const hw, hri_twi_smr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMR &= ~TWI_SMR_SADR(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_SMR_SADR_bf(const void *const hw, hri_twi_smr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMR ^= TWI_SMR_SADR(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_smr_reg_t hri_twi_read_SMR_SADR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_SMR;
	tmp = (tmp & TWI_SMR_SADR_Msk) >> TWI_SMR_SADR_Pos;
	return tmp;
}

static inline void hri_twi_set_SMR_reg(const void *const hw, hri_twi_smr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMR |= mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_smr_reg_t hri_twi_get_SMR_reg(const void *const hw, hri_twi_smr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_SMR;
	tmp &= mask;
	return tmp;
}

static inline void hri_twi_write_SMR_reg(const void *const hw, hri_twi_smr_reg_t data)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMR = data;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_SMR_reg(const void *const hw, hri_twi_smr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMR &= ~mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_SMR_reg(const void *const hw, hri_twi_smr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMR ^= mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_smr_reg_t hri_twi_read_SMR_reg(const void *const hw)
{
	return ((Twi *)hw)->TWI_SMR;
}

static inline void hri_twi_set_IADR_IADR_bf(const void *const hw, hri_twi_iadr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_IADR |= TWI_IADR_IADR(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_iadr_reg_t hri_twi_get_IADR_IADR_bf(const void *const hw, hri_twi_iadr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_IADR;
	tmp = (tmp & TWI_IADR_IADR(mask)) >> TWI_IADR_IADR_Pos;
	return tmp;
}

static inline void hri_twi_write_IADR_IADR_bf(const void *const hw, hri_twi_iadr_reg_t data)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_IADR;
	tmp &= ~TWI_IADR_IADR_Msk;
	tmp |= TWI_IADR_IADR(data);
	((Twi *)hw)->TWI_IADR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_IADR_IADR_bf(const void *const hw, hri_twi_iadr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_IADR &= ~TWI_IADR_IADR(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_IADR_IADR_bf(const void *const hw, hri_twi_iadr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_IADR ^= TWI_IADR_IADR(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_iadr_reg_t hri_twi_read_IADR_IADR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_IADR;
	tmp = (tmp & TWI_IADR_IADR_Msk) >> TWI_IADR_IADR_Pos;
	return tmp;
}

static inline void hri_twi_set_IADR_reg(const void *const hw, hri_twi_iadr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_IADR |= mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_iadr_reg_t hri_twi_get_IADR_reg(const void *const hw, hri_twi_iadr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_IADR;
	tmp &= mask;
	return tmp;
}

static inline void hri_twi_write_IADR_reg(const void *const hw, hri_twi_iadr_reg_t data)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_IADR = data;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_IADR_reg(const void *const hw, hri_twi_iadr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_IADR &= ~mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_IADR_reg(const void *const hw, hri_twi_iadr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_IADR ^= mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_iadr_reg_t hri_twi_read_IADR_reg(const void *const hw)
{
	return ((Twi *)hw)->TWI_IADR;
}

static inline void hri_twi_set_CWGR_BRSRCCLK_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_CWGR |= TWI_CWGR_BRSRCCLK;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_twi_get_CWGR_BRSRCCLK_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_CWGR;
	tmp = (tmp & TWI_CWGR_BRSRCCLK) >> TWI_CWGR_BRSRCCLK_Pos;
	return (bool)tmp;
}

static inline void hri_twi_write_CWGR_BRSRCCLK_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_CWGR;
	tmp &= ~TWI_CWGR_BRSRCCLK;
	tmp |= value << TWI_CWGR_BRSRCCLK_Pos;
	((Twi *)hw)->TWI_CWGR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_CWGR_BRSRCCLK_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_CWGR &= ~TWI_CWGR_BRSRCCLK;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_CWGR_BRSRCCLK_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_CWGR ^= TWI_CWGR_BRSRCCLK;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_set_CWGR_CLDIV_bf(const void *const hw, hri_twi_cwgr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_CWGR |= TWI_CWGR_CLDIV(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_cwgr_reg_t hri_twi_get_CWGR_CLDIV_bf(const void *const hw, hri_twi_cwgr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_CWGR;
	tmp = (tmp & TWI_CWGR_CLDIV(mask)) >> TWI_CWGR_CLDIV_Pos;
	return tmp;
}

static inline void hri_twi_write_CWGR_CLDIV_bf(const void *const hw, hri_twi_cwgr_reg_t data)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_CWGR;
	tmp &= ~TWI_CWGR_CLDIV_Msk;
	tmp |= TWI_CWGR_CLDIV(data);
	((Twi *)hw)->TWI_CWGR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_CWGR_CLDIV_bf(const void *const hw, hri_twi_cwgr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_CWGR &= ~TWI_CWGR_CLDIV(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_CWGR_CLDIV_bf(const void *const hw, hri_twi_cwgr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_CWGR ^= TWI_CWGR_CLDIV(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_cwgr_reg_t hri_twi_read_CWGR_CLDIV_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_CWGR;
	tmp = (tmp & TWI_CWGR_CLDIV_Msk) >> TWI_CWGR_CLDIV_Pos;
	return tmp;
}

static inline void hri_twi_set_CWGR_CHDIV_bf(const void *const hw, hri_twi_cwgr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_CWGR |= TWI_CWGR_CHDIV(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_cwgr_reg_t hri_twi_get_CWGR_CHDIV_bf(const void *const hw, hri_twi_cwgr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_CWGR;
	tmp = (tmp & TWI_CWGR_CHDIV(mask)) >> TWI_CWGR_CHDIV_Pos;
	return tmp;
}

static inline void hri_twi_write_CWGR_CHDIV_bf(const void *const hw, hri_twi_cwgr_reg_t data)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_CWGR;
	tmp &= ~TWI_CWGR_CHDIV_Msk;
	tmp |= TWI_CWGR_CHDIV(data);
	((Twi *)hw)->TWI_CWGR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_CWGR_CHDIV_bf(const void *const hw, hri_twi_cwgr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_CWGR &= ~TWI_CWGR_CHDIV(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_CWGR_CHDIV_bf(const void *const hw, hri_twi_cwgr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_CWGR ^= TWI_CWGR_CHDIV(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_cwgr_reg_t hri_twi_read_CWGR_CHDIV_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_CWGR;
	tmp = (tmp & TWI_CWGR_CHDIV_Msk) >> TWI_CWGR_CHDIV_Pos;
	return tmp;
}

static inline void hri_twi_set_CWGR_CKDIV_bf(const void *const hw, hri_twi_cwgr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_CWGR |= TWI_CWGR_CKDIV(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_cwgr_reg_t hri_twi_get_CWGR_CKDIV_bf(const void *const hw, hri_twi_cwgr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_CWGR;
	tmp = (tmp & TWI_CWGR_CKDIV(mask)) >> TWI_CWGR_CKDIV_Pos;
	return tmp;
}

static inline void hri_twi_write_CWGR_CKDIV_bf(const void *const hw, hri_twi_cwgr_reg_t data)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_CWGR;
	tmp &= ~TWI_CWGR_CKDIV_Msk;
	tmp |= TWI_CWGR_CKDIV(data);
	((Twi *)hw)->TWI_CWGR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_CWGR_CKDIV_bf(const void *const hw, hri_twi_cwgr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_CWGR &= ~TWI_CWGR_CKDIV(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_CWGR_CKDIV_bf(const void *const hw, hri_twi_cwgr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_CWGR ^= TWI_CWGR_CKDIV(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_cwgr_reg_t hri_twi_read_CWGR_CKDIV_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_CWGR;
	tmp = (tmp & TWI_CWGR_CKDIV_Msk) >> TWI_CWGR_CKDIV_Pos;
	return tmp;
}

static inline void hri_twi_set_CWGR_HOLD_bf(const void *const hw, hri_twi_cwgr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_CWGR |= TWI_CWGR_HOLD(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_cwgr_reg_t hri_twi_get_CWGR_HOLD_bf(const void *const hw, hri_twi_cwgr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_CWGR;
	tmp = (tmp & TWI_CWGR_HOLD(mask)) >> TWI_CWGR_HOLD_Pos;
	return tmp;
}

static inline void hri_twi_write_CWGR_HOLD_bf(const void *const hw, hri_twi_cwgr_reg_t data)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_CWGR;
	tmp &= ~TWI_CWGR_HOLD_Msk;
	tmp |= TWI_CWGR_HOLD(data);
	((Twi *)hw)->TWI_CWGR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_CWGR_HOLD_bf(const void *const hw, hri_twi_cwgr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_CWGR &= ~TWI_CWGR_HOLD(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_CWGR_HOLD_bf(const void *const hw, hri_twi_cwgr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_CWGR ^= TWI_CWGR_HOLD(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_cwgr_reg_t hri_twi_read_CWGR_HOLD_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_CWGR;
	tmp = (tmp & TWI_CWGR_HOLD_Msk) >> TWI_CWGR_HOLD_Pos;
	return tmp;
}

static inline void hri_twi_set_CWGR_reg(const void *const hw, hri_twi_cwgr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_CWGR |= mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_cwgr_reg_t hri_twi_get_CWGR_reg(const void *const hw, hri_twi_cwgr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_CWGR;
	tmp &= mask;
	return tmp;
}

static inline void hri_twi_write_CWGR_reg(const void *const hw, hri_twi_cwgr_reg_t data)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_CWGR = data;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_CWGR_reg(const void *const hw, hri_twi_cwgr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_CWGR &= ~mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_CWGR_reg(const void *const hw, hri_twi_cwgr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_CWGR ^= mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_cwgr_reg_t hri_twi_read_CWGR_reg(const void *const hw)
{
	return ((Twi *)hw)->TWI_CWGR;
}

static inline void hri_twi_set_SMBTR_PRESC_bf(const void *const hw, hri_twi_smbtr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMBTR |= TWI_SMBTR_PRESC(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_smbtr_reg_t hri_twi_get_SMBTR_PRESC_bf(const void *const hw, hri_twi_smbtr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_SMBTR;
	tmp = (tmp & TWI_SMBTR_PRESC(mask)) >> TWI_SMBTR_PRESC_Pos;
	return tmp;
}

static inline void hri_twi_write_SMBTR_PRESC_bf(const void *const hw, hri_twi_smbtr_reg_t data)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_SMBTR;
	tmp &= ~TWI_SMBTR_PRESC_Msk;
	tmp |= TWI_SMBTR_PRESC(data);
	((Twi *)hw)->TWI_SMBTR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_SMBTR_PRESC_bf(const void *const hw, hri_twi_smbtr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMBTR &= ~TWI_SMBTR_PRESC(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_SMBTR_PRESC_bf(const void *const hw, hri_twi_smbtr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMBTR ^= TWI_SMBTR_PRESC(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_smbtr_reg_t hri_twi_read_SMBTR_PRESC_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_SMBTR;
	tmp = (tmp & TWI_SMBTR_PRESC_Msk) >> TWI_SMBTR_PRESC_Pos;
	return tmp;
}

static inline void hri_twi_set_SMBTR_TLOWS_bf(const void *const hw, hri_twi_smbtr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMBTR |= TWI_SMBTR_TLOWS(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_smbtr_reg_t hri_twi_get_SMBTR_TLOWS_bf(const void *const hw, hri_twi_smbtr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_SMBTR;
	tmp = (tmp & TWI_SMBTR_TLOWS(mask)) >> TWI_SMBTR_TLOWS_Pos;
	return tmp;
}

static inline void hri_twi_write_SMBTR_TLOWS_bf(const void *const hw, hri_twi_smbtr_reg_t data)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_SMBTR;
	tmp &= ~TWI_SMBTR_TLOWS_Msk;
	tmp |= TWI_SMBTR_TLOWS(data);
	((Twi *)hw)->TWI_SMBTR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_SMBTR_TLOWS_bf(const void *const hw, hri_twi_smbtr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMBTR &= ~TWI_SMBTR_TLOWS(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_SMBTR_TLOWS_bf(const void *const hw, hri_twi_smbtr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMBTR ^= TWI_SMBTR_TLOWS(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_smbtr_reg_t hri_twi_read_SMBTR_TLOWS_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_SMBTR;
	tmp = (tmp & TWI_SMBTR_TLOWS_Msk) >> TWI_SMBTR_TLOWS_Pos;
	return tmp;
}

static inline void hri_twi_set_SMBTR_TLOWM_bf(const void *const hw, hri_twi_smbtr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMBTR |= TWI_SMBTR_TLOWM(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_smbtr_reg_t hri_twi_get_SMBTR_TLOWM_bf(const void *const hw, hri_twi_smbtr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_SMBTR;
	tmp = (tmp & TWI_SMBTR_TLOWM(mask)) >> TWI_SMBTR_TLOWM_Pos;
	return tmp;
}

static inline void hri_twi_write_SMBTR_TLOWM_bf(const void *const hw, hri_twi_smbtr_reg_t data)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_SMBTR;
	tmp &= ~TWI_SMBTR_TLOWM_Msk;
	tmp |= TWI_SMBTR_TLOWM(data);
	((Twi *)hw)->TWI_SMBTR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_SMBTR_TLOWM_bf(const void *const hw, hri_twi_smbtr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMBTR &= ~TWI_SMBTR_TLOWM(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_SMBTR_TLOWM_bf(const void *const hw, hri_twi_smbtr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMBTR ^= TWI_SMBTR_TLOWM(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_smbtr_reg_t hri_twi_read_SMBTR_TLOWM_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_SMBTR;
	tmp = (tmp & TWI_SMBTR_TLOWM_Msk) >> TWI_SMBTR_TLOWM_Pos;
	return tmp;
}

static inline void hri_twi_set_SMBTR_THMAX_bf(const void *const hw, hri_twi_smbtr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMBTR |= TWI_SMBTR_THMAX(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_smbtr_reg_t hri_twi_get_SMBTR_THMAX_bf(const void *const hw, hri_twi_smbtr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_SMBTR;
	tmp = (tmp & TWI_SMBTR_THMAX(mask)) >> TWI_SMBTR_THMAX_Pos;
	return tmp;
}

static inline void hri_twi_write_SMBTR_THMAX_bf(const void *const hw, hri_twi_smbtr_reg_t data)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_SMBTR;
	tmp &= ~TWI_SMBTR_THMAX_Msk;
	tmp |= TWI_SMBTR_THMAX(data);
	((Twi *)hw)->TWI_SMBTR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_SMBTR_THMAX_bf(const void *const hw, hri_twi_smbtr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMBTR &= ~TWI_SMBTR_THMAX(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_SMBTR_THMAX_bf(const void *const hw, hri_twi_smbtr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMBTR ^= TWI_SMBTR_THMAX(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_smbtr_reg_t hri_twi_read_SMBTR_THMAX_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_SMBTR;
	tmp = (tmp & TWI_SMBTR_THMAX_Msk) >> TWI_SMBTR_THMAX_Pos;
	return tmp;
}

static inline void hri_twi_set_SMBTR_reg(const void *const hw, hri_twi_smbtr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMBTR |= mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_smbtr_reg_t hri_twi_get_SMBTR_reg(const void *const hw, hri_twi_smbtr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_SMBTR;
	tmp &= mask;
	return tmp;
}

static inline void hri_twi_write_SMBTR_reg(const void *const hw, hri_twi_smbtr_reg_t data)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMBTR = data;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_SMBTR_reg(const void *const hw, hri_twi_smbtr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMBTR &= ~mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_SMBTR_reg(const void *const hw, hri_twi_smbtr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SMBTR ^= mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_smbtr_reg_t hri_twi_read_SMBTR_reg(const void *const hw)
{
	return ((Twi *)hw)->TWI_SMBTR;
}

static inline void hri_twi_set_ACR_DIR_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_ACR |= TWI_ACR_DIR;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_twi_get_ACR_DIR_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_ACR;
	tmp = (tmp & TWI_ACR_DIR) >> TWI_ACR_DIR_Pos;
	return (bool)tmp;
}

static inline void hri_twi_write_ACR_DIR_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_ACR;
	tmp &= ~TWI_ACR_DIR;
	tmp |= value << TWI_ACR_DIR_Pos;
	((Twi *)hw)->TWI_ACR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_ACR_DIR_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_ACR &= ~TWI_ACR_DIR;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_ACR_DIR_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_ACR ^= TWI_ACR_DIR;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_set_ACR_PEC_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_ACR |= TWI_ACR_PEC;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_twi_get_ACR_PEC_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_ACR;
	tmp = (tmp & TWI_ACR_PEC) >> TWI_ACR_PEC_Pos;
	return (bool)tmp;
}

static inline void hri_twi_write_ACR_PEC_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_ACR;
	tmp &= ~TWI_ACR_PEC;
	tmp |= value << TWI_ACR_PEC_Pos;
	((Twi *)hw)->TWI_ACR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_ACR_PEC_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_ACR &= ~TWI_ACR_PEC;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_ACR_PEC_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_ACR ^= TWI_ACR_PEC;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_set_ACR_NDIR_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_ACR |= TWI_ACR_NDIR;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_twi_get_ACR_NDIR_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_ACR;
	tmp = (tmp & TWI_ACR_NDIR) >> TWI_ACR_NDIR_Pos;
	return (bool)tmp;
}

static inline void hri_twi_write_ACR_NDIR_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_ACR;
	tmp &= ~TWI_ACR_NDIR;
	tmp |= value << TWI_ACR_NDIR_Pos;
	((Twi *)hw)->TWI_ACR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_ACR_NDIR_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_ACR &= ~TWI_ACR_NDIR;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_ACR_NDIR_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_ACR ^= TWI_ACR_NDIR;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_set_ACR_NPEC_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_ACR |= TWI_ACR_NPEC;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_twi_get_ACR_NPEC_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_ACR;
	tmp = (tmp & TWI_ACR_NPEC) >> TWI_ACR_NPEC_Pos;
	return (bool)tmp;
}

static inline void hri_twi_write_ACR_NPEC_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_ACR;
	tmp &= ~TWI_ACR_NPEC;
	tmp |= value << TWI_ACR_NPEC_Pos;
	((Twi *)hw)->TWI_ACR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_ACR_NPEC_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_ACR &= ~TWI_ACR_NPEC;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_ACR_NPEC_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_ACR ^= TWI_ACR_NPEC;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_set_ACR_DATAL_bf(const void *const hw, hri_twi_acr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_ACR |= TWI_ACR_DATAL(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_acr_reg_t hri_twi_get_ACR_DATAL_bf(const void *const hw, hri_twi_acr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_ACR;
	tmp = (tmp & TWI_ACR_DATAL(mask)) >> TWI_ACR_DATAL_Pos;
	return tmp;
}

static inline void hri_twi_write_ACR_DATAL_bf(const void *const hw, hri_twi_acr_reg_t data)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_ACR;
	tmp &= ~TWI_ACR_DATAL_Msk;
	tmp |= TWI_ACR_DATAL(data);
	((Twi *)hw)->TWI_ACR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_ACR_DATAL_bf(const void *const hw, hri_twi_acr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_ACR &= ~TWI_ACR_DATAL(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_ACR_DATAL_bf(const void *const hw, hri_twi_acr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_ACR ^= TWI_ACR_DATAL(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_acr_reg_t hri_twi_read_ACR_DATAL_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_ACR;
	tmp = (tmp & TWI_ACR_DATAL_Msk) >> TWI_ACR_DATAL_Pos;
	return tmp;
}

static inline void hri_twi_set_ACR_NDATAL_bf(const void *const hw, hri_twi_acr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_ACR |= TWI_ACR_NDATAL(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_acr_reg_t hri_twi_get_ACR_NDATAL_bf(const void *const hw, hri_twi_acr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_ACR;
	tmp = (tmp & TWI_ACR_NDATAL(mask)) >> TWI_ACR_NDATAL_Pos;
	return tmp;
}

static inline void hri_twi_write_ACR_NDATAL_bf(const void *const hw, hri_twi_acr_reg_t data)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_ACR;
	tmp &= ~TWI_ACR_NDATAL_Msk;
	tmp |= TWI_ACR_NDATAL(data);
	((Twi *)hw)->TWI_ACR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_ACR_NDATAL_bf(const void *const hw, hri_twi_acr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_ACR &= ~TWI_ACR_NDATAL(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_ACR_NDATAL_bf(const void *const hw, hri_twi_acr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_ACR ^= TWI_ACR_NDATAL(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_acr_reg_t hri_twi_read_ACR_NDATAL_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_ACR;
	tmp = (tmp & TWI_ACR_NDATAL_Msk) >> TWI_ACR_NDATAL_Pos;
	return tmp;
}

static inline void hri_twi_set_ACR_reg(const void *const hw, hri_twi_acr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_ACR |= mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_acr_reg_t hri_twi_get_ACR_reg(const void *const hw, hri_twi_acr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_ACR;
	tmp &= mask;
	return tmp;
}

static inline void hri_twi_write_ACR_reg(const void *const hw, hri_twi_acr_reg_t data)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_ACR = data;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_ACR_reg(const void *const hw, hri_twi_acr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_ACR &= ~mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_ACR_reg(const void *const hw, hri_twi_acr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_ACR ^= mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_acr_reg_t hri_twi_read_ACR_reg(const void *const hw)
{
	return ((Twi *)hw)->TWI_ACR;
}

static inline void hri_twi_set_FILTR_FILT_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_FILTR |= TWI_FILTR_FILT;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_twi_get_FILTR_FILT_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_FILTR;
	tmp = (tmp & TWI_FILTR_FILT) >> TWI_FILTR_FILT_Pos;
	return (bool)tmp;
}

static inline void hri_twi_write_FILTR_FILT_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_FILTR;
	tmp &= ~TWI_FILTR_FILT;
	tmp |= value << TWI_FILTR_FILT_Pos;
	((Twi *)hw)->TWI_FILTR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_FILTR_FILT_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_FILTR &= ~TWI_FILTR_FILT;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_FILTR_FILT_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_FILTR ^= TWI_FILTR_FILT;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_set_FILTR_PADFEN_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_FILTR |= TWI_FILTR_PADFEN;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_twi_get_FILTR_PADFEN_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_FILTR;
	tmp = (tmp & TWI_FILTR_PADFEN) >> TWI_FILTR_PADFEN_Pos;
	return (bool)tmp;
}

static inline void hri_twi_write_FILTR_PADFEN_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_FILTR;
	tmp &= ~TWI_FILTR_PADFEN;
	tmp |= value << TWI_FILTR_PADFEN_Pos;
	((Twi *)hw)->TWI_FILTR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_FILTR_PADFEN_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_FILTR &= ~TWI_FILTR_PADFEN;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_FILTR_PADFEN_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_FILTR ^= TWI_FILTR_PADFEN;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_set_FILTR_PADFCFG_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_FILTR |= TWI_FILTR_PADFCFG;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_twi_get_FILTR_PADFCFG_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_FILTR;
	tmp = (tmp & TWI_FILTR_PADFCFG) >> TWI_FILTR_PADFCFG_Pos;
	return (bool)tmp;
}

static inline void hri_twi_write_FILTR_PADFCFG_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_FILTR;
	tmp &= ~TWI_FILTR_PADFCFG;
	tmp |= value << TWI_FILTR_PADFCFG_Pos;
	((Twi *)hw)->TWI_FILTR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_FILTR_PADFCFG_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_FILTR &= ~TWI_FILTR_PADFCFG;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_FILTR_PADFCFG_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_FILTR ^= TWI_FILTR_PADFCFG;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_set_FILTR_THRES_bf(const void *const hw, hri_twi_filtr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_FILTR |= TWI_FILTR_THRES(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_filtr_reg_t hri_twi_get_FILTR_THRES_bf(const void *const hw, hri_twi_filtr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_FILTR;
	tmp = (tmp & TWI_FILTR_THRES(mask)) >> TWI_FILTR_THRES_Pos;
	return tmp;
}

static inline void hri_twi_write_FILTR_THRES_bf(const void *const hw, hri_twi_filtr_reg_t data)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_FILTR;
	tmp &= ~TWI_FILTR_THRES_Msk;
	tmp |= TWI_FILTR_THRES(data);
	((Twi *)hw)->TWI_FILTR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_FILTR_THRES_bf(const void *const hw, hri_twi_filtr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_FILTR &= ~TWI_FILTR_THRES(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_FILTR_THRES_bf(const void *const hw, hri_twi_filtr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_FILTR ^= TWI_FILTR_THRES(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_filtr_reg_t hri_twi_read_FILTR_THRES_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_FILTR;
	tmp = (tmp & TWI_FILTR_THRES_Msk) >> TWI_FILTR_THRES_Pos;
	return tmp;
}

static inline void hri_twi_set_FILTR_reg(const void *const hw, hri_twi_filtr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_FILTR |= mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_filtr_reg_t hri_twi_get_FILTR_reg(const void *const hw, hri_twi_filtr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_FILTR;
	tmp &= mask;
	return tmp;
}

static inline void hri_twi_write_FILTR_reg(const void *const hw, hri_twi_filtr_reg_t data)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_FILTR = data;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_FILTR_reg(const void *const hw, hri_twi_filtr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_FILTR &= ~mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_FILTR_reg(const void *const hw, hri_twi_filtr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_FILTR ^= mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_filtr_reg_t hri_twi_read_FILTR_reg(const void *const hw)
{
	return ((Twi *)hw)->TWI_FILTR;
}

static inline void hri_twi_set_SWMR_SADR1_bf(const void *const hw, hri_twi_swmr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SWMR |= TWI_SWMR_SADR1(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_swmr_reg_t hri_twi_get_SWMR_SADR1_bf(const void *const hw, hri_twi_swmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_SWMR;
	tmp = (tmp & TWI_SWMR_SADR1(mask)) >> TWI_SWMR_SADR1_Pos;
	return tmp;
}

static inline void hri_twi_write_SWMR_SADR1_bf(const void *const hw, hri_twi_swmr_reg_t data)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_SWMR;
	tmp &= ~TWI_SWMR_SADR1_Msk;
	tmp |= TWI_SWMR_SADR1(data);
	((Twi *)hw)->TWI_SWMR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_SWMR_SADR1_bf(const void *const hw, hri_twi_swmr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SWMR &= ~TWI_SWMR_SADR1(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_SWMR_SADR1_bf(const void *const hw, hri_twi_swmr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SWMR ^= TWI_SWMR_SADR1(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_swmr_reg_t hri_twi_read_SWMR_SADR1_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_SWMR;
	tmp = (tmp & TWI_SWMR_SADR1_Msk) >> TWI_SWMR_SADR1_Pos;
	return tmp;
}

static inline void hri_twi_set_SWMR_SADR2_bf(const void *const hw, hri_twi_swmr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SWMR |= TWI_SWMR_SADR2(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_swmr_reg_t hri_twi_get_SWMR_SADR2_bf(const void *const hw, hri_twi_swmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_SWMR;
	tmp = (tmp & TWI_SWMR_SADR2(mask)) >> TWI_SWMR_SADR2_Pos;
	return tmp;
}

static inline void hri_twi_write_SWMR_SADR2_bf(const void *const hw, hri_twi_swmr_reg_t data)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_SWMR;
	tmp &= ~TWI_SWMR_SADR2_Msk;
	tmp |= TWI_SWMR_SADR2(data);
	((Twi *)hw)->TWI_SWMR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_SWMR_SADR2_bf(const void *const hw, hri_twi_swmr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SWMR &= ~TWI_SWMR_SADR2(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_SWMR_SADR2_bf(const void *const hw, hri_twi_swmr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SWMR ^= TWI_SWMR_SADR2(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_swmr_reg_t hri_twi_read_SWMR_SADR2_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_SWMR;
	tmp = (tmp & TWI_SWMR_SADR2_Msk) >> TWI_SWMR_SADR2_Pos;
	return tmp;
}

static inline void hri_twi_set_SWMR_SADR3_bf(const void *const hw, hri_twi_swmr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SWMR |= TWI_SWMR_SADR3(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_swmr_reg_t hri_twi_get_SWMR_SADR3_bf(const void *const hw, hri_twi_swmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_SWMR;
	tmp = (tmp & TWI_SWMR_SADR3(mask)) >> TWI_SWMR_SADR3_Pos;
	return tmp;
}

static inline void hri_twi_write_SWMR_SADR3_bf(const void *const hw, hri_twi_swmr_reg_t data)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_SWMR;
	tmp &= ~TWI_SWMR_SADR3_Msk;
	tmp |= TWI_SWMR_SADR3(data);
	((Twi *)hw)->TWI_SWMR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_SWMR_SADR3_bf(const void *const hw, hri_twi_swmr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SWMR &= ~TWI_SWMR_SADR3(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_SWMR_SADR3_bf(const void *const hw, hri_twi_swmr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SWMR ^= TWI_SWMR_SADR3(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_swmr_reg_t hri_twi_read_SWMR_SADR3_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_SWMR;
	tmp = (tmp & TWI_SWMR_SADR3_Msk) >> TWI_SWMR_SADR3_Pos;
	return tmp;
}

static inline void hri_twi_set_SWMR_DATAM_bf(const void *const hw, hri_twi_swmr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SWMR |= TWI_SWMR_DATAM(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_swmr_reg_t hri_twi_get_SWMR_DATAM_bf(const void *const hw, hri_twi_swmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_SWMR;
	tmp = (tmp & TWI_SWMR_DATAM(mask)) >> TWI_SWMR_DATAM_Pos;
	return tmp;
}

static inline void hri_twi_write_SWMR_DATAM_bf(const void *const hw, hri_twi_swmr_reg_t data)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_SWMR;
	tmp &= ~TWI_SWMR_DATAM_Msk;
	tmp |= TWI_SWMR_DATAM(data);
	((Twi *)hw)->TWI_SWMR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_SWMR_DATAM_bf(const void *const hw, hri_twi_swmr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SWMR &= ~TWI_SWMR_DATAM(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_SWMR_DATAM_bf(const void *const hw, hri_twi_swmr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SWMR ^= TWI_SWMR_DATAM(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_swmr_reg_t hri_twi_read_SWMR_DATAM_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_SWMR;
	tmp = (tmp & TWI_SWMR_DATAM_Msk) >> TWI_SWMR_DATAM_Pos;
	return tmp;
}

static inline void hri_twi_set_SWMR_reg(const void *const hw, hri_twi_swmr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SWMR |= mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_swmr_reg_t hri_twi_get_SWMR_reg(const void *const hw, hri_twi_swmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_SWMR;
	tmp &= mask;
	return tmp;
}

static inline void hri_twi_write_SWMR_reg(const void *const hw, hri_twi_swmr_reg_t data)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SWMR = data;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_SWMR_reg(const void *const hw, hri_twi_swmr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SWMR &= ~mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_SWMR_reg(const void *const hw, hri_twi_swmr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_SWMR ^= mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_swmr_reg_t hri_twi_read_SWMR_reg(const void *const hw)
{
	return ((Twi *)hw)->TWI_SWMR;
}

static inline void hri_twi_set_WPMR_WPEN_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_WPMR |= TWI_WPMR_WPEN;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_twi_get_WPMR_WPEN_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_WPMR;
	tmp = (tmp & TWI_WPMR_WPEN) >> TWI_WPMR_WPEN_Pos;
	return (bool)tmp;
}

static inline void hri_twi_write_WPMR_WPEN_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_WPMR;
	tmp &= ~TWI_WPMR_WPEN;
	tmp |= value << TWI_WPMR_WPEN_Pos;
	((Twi *)hw)->TWI_WPMR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_WPMR_WPEN_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_WPMR &= ~TWI_WPMR_WPEN;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_WPMR_WPEN_bit(const void *const hw)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_WPMR ^= TWI_WPMR_WPEN;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_set_WPMR_WPKEY_bf(const void *const hw, hri_twi_wpmr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_WPMR |= TWI_WPMR_WPKEY(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_wpmr_reg_t hri_twi_get_WPMR_WPKEY_bf(const void *const hw, hri_twi_wpmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_WPMR;
	tmp = (tmp & TWI_WPMR_WPKEY(mask)) >> TWI_WPMR_WPKEY_Pos;
	return tmp;
}

static inline void hri_twi_write_WPMR_WPKEY_bf(const void *const hw, hri_twi_wpmr_reg_t data)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_WPMR;
	tmp &= ~TWI_WPMR_WPKEY_Msk;
	tmp |= TWI_WPMR_WPKEY(data);
	((Twi *)hw)->TWI_WPMR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_WPMR_WPKEY_bf(const void *const hw, hri_twi_wpmr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_WPMR &= ~TWI_WPMR_WPKEY(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_WPMR_WPKEY_bf(const void *const hw, hri_twi_wpmr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_WPMR ^= TWI_WPMR_WPKEY(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_wpmr_reg_t hri_twi_read_WPMR_WPKEY_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_WPMR;
	tmp = (tmp & TWI_WPMR_WPKEY_Msk) >> TWI_WPMR_WPKEY_Pos;
	return tmp;
}

static inline void hri_twi_set_WPMR_reg(const void *const hw, hri_twi_wpmr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_WPMR |= mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_wpmr_reg_t hri_twi_get_WPMR_reg(const void *const hw, hri_twi_wpmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_WPMR;
	tmp &= mask;
	return tmp;
}

static inline void hri_twi_write_WPMR_reg(const void *const hw, hri_twi_wpmr_reg_t data)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_WPMR = data;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_WPMR_reg(const void *const hw, hri_twi_wpmr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_WPMR &= ~mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_WPMR_reg(const void *const hw, hri_twi_wpmr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_WPMR ^= mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_wpmr_reg_t hri_twi_read_WPMR_reg(const void *const hw)
{
	return ((Twi *)hw)->TWI_WPMR;
}

static inline void hri_twi_set_RPR_RXPTR_bf(const void *const hw, hri_twi_rpr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_RPR |= TWI_RPR_RXPTR(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_rpr_reg_t hri_twi_get_RPR_RXPTR_bf(const void *const hw, hri_twi_rpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_RPR;
	tmp = (tmp & TWI_RPR_RXPTR(mask)) >> TWI_RPR_RXPTR_Pos;
	return tmp;
}

static inline void hri_twi_write_RPR_RXPTR_bf(const void *const hw, hri_twi_rpr_reg_t data)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_RPR;
	tmp &= ~TWI_RPR_RXPTR_Msk;
	tmp |= TWI_RPR_RXPTR(data);
	((Twi *)hw)->TWI_RPR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_RPR_RXPTR_bf(const void *const hw, hri_twi_rpr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_RPR &= ~TWI_RPR_RXPTR(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_RPR_RXPTR_bf(const void *const hw, hri_twi_rpr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_RPR ^= TWI_RPR_RXPTR(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_rpr_reg_t hri_twi_read_RPR_RXPTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_RPR;
	tmp = (tmp & TWI_RPR_RXPTR_Msk) >> TWI_RPR_RXPTR_Pos;
	return tmp;
}

static inline void hri_twi_set_RPR_reg(const void *const hw, hri_twi_rpr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_RPR |= mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_rpr_reg_t hri_twi_get_RPR_reg(const void *const hw, hri_twi_rpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_RPR;
	tmp &= mask;
	return tmp;
}

static inline void hri_twi_write_RPR_reg(const void *const hw, hri_twi_rpr_reg_t data)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_RPR = data;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_RPR_reg(const void *const hw, hri_twi_rpr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_RPR &= ~mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_RPR_reg(const void *const hw, hri_twi_rpr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_RPR ^= mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_rpr_reg_t hri_twi_read_RPR_reg(const void *const hw)
{
	return ((Twi *)hw)->TWI_RPR;
}

static inline void hri_twi_set_RCR_RXCTR_bf(const void *const hw, hri_twi_rcr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_RCR |= TWI_RCR_RXCTR(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_rcr_reg_t hri_twi_get_RCR_RXCTR_bf(const void *const hw, hri_twi_rcr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_RCR;
	tmp = (tmp & TWI_RCR_RXCTR(mask)) >> TWI_RCR_RXCTR_Pos;
	return tmp;
}

static inline void hri_twi_write_RCR_RXCTR_bf(const void *const hw, hri_twi_rcr_reg_t data)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_RCR;
	tmp &= ~TWI_RCR_RXCTR_Msk;
	tmp |= TWI_RCR_RXCTR(data);
	((Twi *)hw)->TWI_RCR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_RCR_RXCTR_bf(const void *const hw, hri_twi_rcr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_RCR &= ~TWI_RCR_RXCTR(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_RCR_RXCTR_bf(const void *const hw, hri_twi_rcr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_RCR ^= TWI_RCR_RXCTR(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_rcr_reg_t hri_twi_read_RCR_RXCTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_RCR;
	tmp = (tmp & TWI_RCR_RXCTR_Msk) >> TWI_RCR_RXCTR_Pos;
	return tmp;
}

static inline void hri_twi_set_RCR_reg(const void *const hw, hri_twi_rcr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_RCR |= mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_rcr_reg_t hri_twi_get_RCR_reg(const void *const hw, hri_twi_rcr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_RCR;
	tmp &= mask;
	return tmp;
}

static inline void hri_twi_write_RCR_reg(const void *const hw, hri_twi_rcr_reg_t data)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_RCR = data;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_RCR_reg(const void *const hw, hri_twi_rcr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_RCR &= ~mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_RCR_reg(const void *const hw, hri_twi_rcr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_RCR ^= mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_rcr_reg_t hri_twi_read_RCR_reg(const void *const hw)
{
	return ((Twi *)hw)->TWI_RCR;
}

static inline void hri_twi_set_TPR_TXPTR_bf(const void *const hw, hri_twi_tpr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_TPR |= TWI_TPR_TXPTR(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_tpr_reg_t hri_twi_get_TPR_TXPTR_bf(const void *const hw, hri_twi_tpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_TPR;
	tmp = (tmp & TWI_TPR_TXPTR(mask)) >> TWI_TPR_TXPTR_Pos;
	return tmp;
}

static inline void hri_twi_write_TPR_TXPTR_bf(const void *const hw, hri_twi_tpr_reg_t data)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_TPR;
	tmp &= ~TWI_TPR_TXPTR_Msk;
	tmp |= TWI_TPR_TXPTR(data);
	((Twi *)hw)->TWI_TPR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_TPR_TXPTR_bf(const void *const hw, hri_twi_tpr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_TPR &= ~TWI_TPR_TXPTR(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_TPR_TXPTR_bf(const void *const hw, hri_twi_tpr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_TPR ^= TWI_TPR_TXPTR(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_tpr_reg_t hri_twi_read_TPR_TXPTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_TPR;
	tmp = (tmp & TWI_TPR_TXPTR_Msk) >> TWI_TPR_TXPTR_Pos;
	return tmp;
}

static inline void hri_twi_set_TPR_reg(const void *const hw, hri_twi_tpr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_TPR |= mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_tpr_reg_t hri_twi_get_TPR_reg(const void *const hw, hri_twi_tpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_TPR;
	tmp &= mask;
	return tmp;
}

static inline void hri_twi_write_TPR_reg(const void *const hw, hri_twi_tpr_reg_t data)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_TPR = data;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_TPR_reg(const void *const hw, hri_twi_tpr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_TPR &= ~mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_TPR_reg(const void *const hw, hri_twi_tpr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_TPR ^= mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_tpr_reg_t hri_twi_read_TPR_reg(const void *const hw)
{
	return ((Twi *)hw)->TWI_TPR;
}

static inline void hri_twi_set_TCR_TXCTR_bf(const void *const hw, hri_twi_tcr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_TCR |= TWI_TCR_TXCTR(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_tcr_reg_t hri_twi_get_TCR_TXCTR_bf(const void *const hw, hri_twi_tcr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_TCR;
	tmp = (tmp & TWI_TCR_TXCTR(mask)) >> TWI_TCR_TXCTR_Pos;
	return tmp;
}

static inline void hri_twi_write_TCR_TXCTR_bf(const void *const hw, hri_twi_tcr_reg_t data)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_TCR;
	tmp &= ~TWI_TCR_TXCTR_Msk;
	tmp |= TWI_TCR_TXCTR(data);
	((Twi *)hw)->TWI_TCR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_TCR_TXCTR_bf(const void *const hw, hri_twi_tcr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_TCR &= ~TWI_TCR_TXCTR(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_TCR_TXCTR_bf(const void *const hw, hri_twi_tcr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_TCR ^= TWI_TCR_TXCTR(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_tcr_reg_t hri_twi_read_TCR_TXCTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_TCR;
	tmp = (tmp & TWI_TCR_TXCTR_Msk) >> TWI_TCR_TXCTR_Pos;
	return tmp;
}

static inline void hri_twi_set_TCR_reg(const void *const hw, hri_twi_tcr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_TCR |= mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_tcr_reg_t hri_twi_get_TCR_reg(const void *const hw, hri_twi_tcr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_TCR;
	tmp &= mask;
	return tmp;
}

static inline void hri_twi_write_TCR_reg(const void *const hw, hri_twi_tcr_reg_t data)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_TCR = data;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_TCR_reg(const void *const hw, hri_twi_tcr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_TCR &= ~mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_TCR_reg(const void *const hw, hri_twi_tcr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_TCR ^= mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_tcr_reg_t hri_twi_read_TCR_reg(const void *const hw)
{
	return ((Twi *)hw)->TWI_TCR;
}

static inline void hri_twi_set_RNPR_RXNPTR_bf(const void *const hw, hri_twi_rnpr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_RNPR |= TWI_RNPR_RXNPTR(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_rnpr_reg_t hri_twi_get_RNPR_RXNPTR_bf(const void *const hw, hri_twi_rnpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_RNPR;
	tmp = (tmp & TWI_RNPR_RXNPTR(mask)) >> TWI_RNPR_RXNPTR_Pos;
	return tmp;
}

static inline void hri_twi_write_RNPR_RXNPTR_bf(const void *const hw, hri_twi_rnpr_reg_t data)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_RNPR;
	tmp &= ~TWI_RNPR_RXNPTR_Msk;
	tmp |= TWI_RNPR_RXNPTR(data);
	((Twi *)hw)->TWI_RNPR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_RNPR_RXNPTR_bf(const void *const hw, hri_twi_rnpr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_RNPR &= ~TWI_RNPR_RXNPTR(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_RNPR_RXNPTR_bf(const void *const hw, hri_twi_rnpr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_RNPR ^= TWI_RNPR_RXNPTR(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_rnpr_reg_t hri_twi_read_RNPR_RXNPTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_RNPR;
	tmp = (tmp & TWI_RNPR_RXNPTR_Msk) >> TWI_RNPR_RXNPTR_Pos;
	return tmp;
}

static inline void hri_twi_set_RNPR_reg(const void *const hw, hri_twi_rnpr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_RNPR |= mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_rnpr_reg_t hri_twi_get_RNPR_reg(const void *const hw, hri_twi_rnpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_RNPR;
	tmp &= mask;
	return tmp;
}

static inline void hri_twi_write_RNPR_reg(const void *const hw, hri_twi_rnpr_reg_t data)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_RNPR = data;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_RNPR_reg(const void *const hw, hri_twi_rnpr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_RNPR &= ~mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_RNPR_reg(const void *const hw, hri_twi_rnpr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_RNPR ^= mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_rnpr_reg_t hri_twi_read_RNPR_reg(const void *const hw)
{
	return ((Twi *)hw)->TWI_RNPR;
}

static inline void hri_twi_set_RNCR_RXNCTR_bf(const void *const hw, hri_twi_rncr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_RNCR |= TWI_RNCR_RXNCTR(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_rncr_reg_t hri_twi_get_RNCR_RXNCTR_bf(const void *const hw, hri_twi_rncr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_RNCR;
	tmp = (tmp & TWI_RNCR_RXNCTR(mask)) >> TWI_RNCR_RXNCTR_Pos;
	return tmp;
}

static inline void hri_twi_write_RNCR_RXNCTR_bf(const void *const hw, hri_twi_rncr_reg_t data)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_RNCR;
	tmp &= ~TWI_RNCR_RXNCTR_Msk;
	tmp |= TWI_RNCR_RXNCTR(data);
	((Twi *)hw)->TWI_RNCR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_RNCR_RXNCTR_bf(const void *const hw, hri_twi_rncr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_RNCR &= ~TWI_RNCR_RXNCTR(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_RNCR_RXNCTR_bf(const void *const hw, hri_twi_rncr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_RNCR ^= TWI_RNCR_RXNCTR(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_rncr_reg_t hri_twi_read_RNCR_RXNCTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_RNCR;
	tmp = (tmp & TWI_RNCR_RXNCTR_Msk) >> TWI_RNCR_RXNCTR_Pos;
	return tmp;
}

static inline void hri_twi_set_RNCR_reg(const void *const hw, hri_twi_rncr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_RNCR |= mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_rncr_reg_t hri_twi_get_RNCR_reg(const void *const hw, hri_twi_rncr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_RNCR;
	tmp &= mask;
	return tmp;
}

static inline void hri_twi_write_RNCR_reg(const void *const hw, hri_twi_rncr_reg_t data)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_RNCR = data;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_RNCR_reg(const void *const hw, hri_twi_rncr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_RNCR &= ~mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_RNCR_reg(const void *const hw, hri_twi_rncr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_RNCR ^= mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_rncr_reg_t hri_twi_read_RNCR_reg(const void *const hw)
{
	return ((Twi *)hw)->TWI_RNCR;
}

static inline void hri_twi_set_TNPR_TXNPTR_bf(const void *const hw, hri_twi_tnpr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_TNPR |= TWI_TNPR_TXNPTR(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_tnpr_reg_t hri_twi_get_TNPR_TXNPTR_bf(const void *const hw, hri_twi_tnpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_TNPR;
	tmp = (tmp & TWI_TNPR_TXNPTR(mask)) >> TWI_TNPR_TXNPTR_Pos;
	return tmp;
}

static inline void hri_twi_write_TNPR_TXNPTR_bf(const void *const hw, hri_twi_tnpr_reg_t data)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_TNPR;
	tmp &= ~TWI_TNPR_TXNPTR_Msk;
	tmp |= TWI_TNPR_TXNPTR(data);
	((Twi *)hw)->TWI_TNPR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_TNPR_TXNPTR_bf(const void *const hw, hri_twi_tnpr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_TNPR &= ~TWI_TNPR_TXNPTR(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_TNPR_TXNPTR_bf(const void *const hw, hri_twi_tnpr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_TNPR ^= TWI_TNPR_TXNPTR(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_tnpr_reg_t hri_twi_read_TNPR_TXNPTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_TNPR;
	tmp = (tmp & TWI_TNPR_TXNPTR_Msk) >> TWI_TNPR_TXNPTR_Pos;
	return tmp;
}

static inline void hri_twi_set_TNPR_reg(const void *const hw, hri_twi_tnpr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_TNPR |= mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_tnpr_reg_t hri_twi_get_TNPR_reg(const void *const hw, hri_twi_tnpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_TNPR;
	tmp &= mask;
	return tmp;
}

static inline void hri_twi_write_TNPR_reg(const void *const hw, hri_twi_tnpr_reg_t data)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_TNPR = data;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_TNPR_reg(const void *const hw, hri_twi_tnpr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_TNPR &= ~mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_TNPR_reg(const void *const hw, hri_twi_tnpr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_TNPR ^= mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_tnpr_reg_t hri_twi_read_TNPR_reg(const void *const hw)
{
	return ((Twi *)hw)->TWI_TNPR;
}

static inline void hri_twi_set_TNCR_TXNCTR_bf(const void *const hw, hri_twi_tncr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_TNCR |= TWI_TNCR_TXNCTR(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_tncr_reg_t hri_twi_get_TNCR_TXNCTR_bf(const void *const hw, hri_twi_tncr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_TNCR;
	tmp = (tmp & TWI_TNCR_TXNCTR(mask)) >> TWI_TNCR_TXNCTR_Pos;
	return tmp;
}

static inline void hri_twi_write_TNCR_TXNCTR_bf(const void *const hw, hri_twi_tncr_reg_t data)
{
	uint32_t tmp;
	TWI_CRITICAL_SECTION_ENTER();
	tmp = ((Twi *)hw)->TWI_TNCR;
	tmp &= ~TWI_TNCR_TXNCTR_Msk;
	tmp |= TWI_TNCR_TXNCTR(data);
	((Twi *)hw)->TWI_TNCR = tmp;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_TNCR_TXNCTR_bf(const void *const hw, hri_twi_tncr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_TNCR &= ~TWI_TNCR_TXNCTR(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_TNCR_TXNCTR_bf(const void *const hw, hri_twi_tncr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_TNCR ^= TWI_TNCR_TXNCTR(mask);
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_tncr_reg_t hri_twi_read_TNCR_TXNCTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_TNCR;
	tmp = (tmp & TWI_TNCR_TXNCTR_Msk) >> TWI_TNCR_TXNCTR_Pos;
	return tmp;
}

static inline void hri_twi_set_TNCR_reg(const void *const hw, hri_twi_tncr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_TNCR |= mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_tncr_reg_t hri_twi_get_TNCR_reg(const void *const hw, hri_twi_tncr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_TNCR;
	tmp &= mask;
	return tmp;
}

static inline void hri_twi_write_TNCR_reg(const void *const hw, hri_twi_tncr_reg_t data)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_TNCR = data;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_clear_TNCR_reg(const void *const hw, hri_twi_tncr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_TNCR &= ~mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline void hri_twi_toggle_TNCR_reg(const void *const hw, hri_twi_tncr_reg_t mask)
{
	TWI_CRITICAL_SECTION_ENTER();
	((Twi *)hw)->TWI_TNCR ^= mask;
	TWI_CRITICAL_SECTION_LEAVE();
}

static inline hri_twi_tncr_reg_t hri_twi_read_TNCR_reg(const void *const hw)
{
	return ((Twi *)hw)->TWI_TNCR;
}

static inline bool hri_twi_get_SR_TXCOMP_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_SR & TWI_SR_TXCOMP) > 0;
}

static inline bool hri_twi_get_SR_RXRDY_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_SR & TWI_SR_RXRDY) > 0;
}

static inline bool hri_twi_get_SR_TXRDY_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_SR & TWI_SR_TXRDY) > 0;
}

static inline bool hri_twi_get_SR_SVREAD_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_SR & TWI_SR_SVREAD) > 0;
}

static inline bool hri_twi_get_SR_SVACC_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_SR & TWI_SR_SVACC) > 0;
}

static inline bool hri_twi_get_SR_GACC_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_SR & TWI_SR_GACC) > 0;
}

static inline bool hri_twi_get_SR_OVRE_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_SR & TWI_SR_OVRE) > 0;
}

static inline bool hri_twi_get_SR_UNRE_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_SR & TWI_SR_UNRE) > 0;
}

static inline bool hri_twi_get_SR_NACK_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_SR & TWI_SR_NACK) > 0;
}

static inline bool hri_twi_get_SR_ARBLST_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_SR & TWI_SR_ARBLST) > 0;
}

static inline bool hri_twi_get_SR_SCLWS_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_SR & TWI_SR_SCLWS) > 0;
}

static inline bool hri_twi_get_SR_EOSACC_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_SR & TWI_SR_EOSACC) > 0;
}

static inline bool hri_twi_get_SR_ENDRX_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_SR & TWI_SR_ENDRX) > 0;
}

static inline bool hri_twi_get_SR_ENDTX_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_SR & TWI_SR_ENDTX) > 0;
}

static inline bool hri_twi_get_SR_RXBUFF_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_SR & TWI_SR_RXBUFF) > 0;
}

static inline bool hri_twi_get_SR_TXBUFE_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_SR & TWI_SR_TXBUFE) > 0;
}

static inline bool hri_twi_get_SR_MCACK_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_SR & TWI_SR_MCACK) > 0;
}

static inline bool hri_twi_get_SR_TOUT_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_SR & TWI_SR_TOUT) > 0;
}

static inline bool hri_twi_get_SR_PECERR_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_SR & TWI_SR_PECERR) > 0;
}

static inline bool hri_twi_get_SR_SMBDAM_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_SR & TWI_SR_SMBDAM) > 0;
}

static inline bool hri_twi_get_SR_SMBHHM_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_SR & TWI_SR_SMBHHM) > 0;
}

static inline bool hri_twi_get_SR_LOCK_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_SR & TWI_SR_LOCK) > 0;
}

static inline bool hri_twi_get_SR_SCL_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_SR & TWI_SR_SCL) > 0;
}

static inline bool hri_twi_get_SR_SDA_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_SR & TWI_SR_SDA) > 0;
}

static inline hri_twi_sr_reg_t hri_twi_get_SR_reg(const void *const hw, hri_twi_sr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_SR;
	tmp &= mask;
	return tmp;
}

static inline hri_twi_sr_reg_t hri_twi_read_SR_reg(const void *const hw)
{
	return ((Twi *)hw)->TWI_SR;
}

static inline hri_twi_rhr_reg_t hri_twi_get_RHR_RXDATA_bf(const void *const hw, hri_twi_rhr_reg_t mask)
{
	return (((Twi *)hw)->TWI_RHR & TWI_RHR_RXDATA(mask)) >> TWI_RHR_RXDATA_Pos;
}

static inline hri_twi_rhr_reg_t hri_twi_read_RHR_RXDATA_bf(const void *const hw)
{
	return (((Twi *)hw)->TWI_RHR & TWI_RHR_RXDATA_Msk) >> TWI_RHR_RXDATA_Pos;
}

static inline hri_twi_rhr_reg_t hri_twi_get_RHR_reg(const void *const hw, hri_twi_rhr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_RHR;
	tmp &= mask;
	return tmp;
}

static inline hri_twi_rhr_reg_t hri_twi_read_RHR_reg(const void *const hw)
{
	return ((Twi *)hw)->TWI_RHR;
}

static inline bool hri_twi_get_WPSR_WPVS_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_WPSR & TWI_WPSR_WPVS) > 0;
}

static inline hri_twi_wpsr_reg_t hri_twi_get_WPSR_WPVSRC_bf(const void *const hw, hri_twi_wpsr_reg_t mask)
{
	return (((Twi *)hw)->TWI_WPSR & TWI_WPSR_WPVSRC(mask)) >> TWI_WPSR_WPVSRC_Pos;
}

static inline hri_twi_wpsr_reg_t hri_twi_read_WPSR_WPVSRC_bf(const void *const hw)
{
	return (((Twi *)hw)->TWI_WPSR & TWI_WPSR_WPVSRC_Msk) >> TWI_WPSR_WPVSRC_Pos;
}

static inline hri_twi_wpsr_reg_t hri_twi_get_WPSR_reg(const void *const hw, hri_twi_wpsr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_WPSR;
	tmp &= mask;
	return tmp;
}

static inline hri_twi_wpsr_reg_t hri_twi_read_WPSR_reg(const void *const hw)
{
	return ((Twi *)hw)->TWI_WPSR;
}

static inline bool hri_twi_get_PTSR_RXTEN_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_PTSR & TWI_PTSR_RXTEN) > 0;
}

static inline bool hri_twi_get_PTSR_TXTEN_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_PTSR & TWI_PTSR_TXTEN) > 0;
}

static inline bool hri_twi_get_PTSR_RXCBEN_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_PTSR & TWI_PTSR_RXCBEN) > 0;
}

static inline bool hri_twi_get_PTSR_TXCBEN_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_PTSR & TWI_PTSR_TXCBEN) > 0;
}

static inline bool hri_twi_get_PTSR_ERR_bit(const void *const hw)
{
	return (((Twi *)hw)->TWI_PTSR & TWI_PTSR_ERR) > 0;
}

static inline hri_twi_ptsr_reg_t hri_twi_get_PTSR_reg(const void *const hw, hri_twi_ptsr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Twi *)hw)->TWI_PTSR;
	tmp &= mask;
	return tmp;
}

static inline hri_twi_ptsr_reg_t hri_twi_read_PTSR_reg(const void *const hw)
{
	return ((Twi *)hw)->TWI_PTSR;
}

#ifdef __cplusplus
}
#endif

#endif /* _HRI_TWI_G55_H_INCLUDED */
#endif /* _SAMG55_TWI_COMPONENT_ */
