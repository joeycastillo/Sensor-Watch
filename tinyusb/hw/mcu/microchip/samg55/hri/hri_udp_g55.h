/**
 * \file
 *
 * \brief SAM UDP
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

#ifdef _SAMG55_UDP_COMPONENT_
#ifndef _HRI_UDP_G55_H_INCLUDED_
#define _HRI_UDP_G55_H_INCLUDED_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <hal_atomic.h>

#if defined(ENABLE_UDP_CRITICAL_SECTIONS)
#define UDP_CRITICAL_SECTION_ENTER() CRITICAL_SECTION_ENTER()
#define UDP_CRITICAL_SECTION_LEAVE() CRITICAL_SECTION_LEAVE()
#else
#define UDP_CRITICAL_SECTION_ENTER()
#define UDP_CRITICAL_SECTION_LEAVE()
#endif

typedef uint32_t hri_udp_csr_reg_t;
typedef uint32_t hri_udp_faddr_reg_t;
typedef uint32_t hri_udp_fdr_reg_t;
typedef uint32_t hri_udp_frm_num_reg_t;
typedef uint32_t hri_udp_glb_stat_reg_t;
typedef uint32_t hri_udp_imr_reg_t;
typedef uint32_t hri_udp_isr_reg_t;
typedef uint32_t hri_udp_rst_ep_reg_t;
typedef uint32_t hri_udp_txvc_reg_t;

static inline void hri_udp_set_IMR_EP0INT_bit(const void *const hw)
{
	((Udp *)hw)->UDP_IER = UDP_IMR_EP0INT;
}

static inline bool hri_udp_get_IMR_EP0INT_bit(const void *const hw)
{
	return (((Udp *)hw)->UDP_IMR & UDP_IMR_EP0INT) >> UDP_IMR_EP0INT_Pos;
}

static inline void hri_udp_write_IMR_EP0INT_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Udp *)hw)->UDP_IDR = UDP_IMR_EP0INT;
	} else {
		((Udp *)hw)->UDP_IER = UDP_IMR_EP0INT;
	}
}

static inline void hri_udp_clear_IMR_EP0INT_bit(const void *const hw)
{
	((Udp *)hw)->UDP_IDR = UDP_IMR_EP0INT;
}

static inline void hri_udp_set_IMR_EP1INT_bit(const void *const hw)
{
	((Udp *)hw)->UDP_IER = UDP_IMR_EP1INT;
}

static inline bool hri_udp_get_IMR_EP1INT_bit(const void *const hw)
{
	return (((Udp *)hw)->UDP_IMR & UDP_IMR_EP1INT) >> UDP_IMR_EP1INT_Pos;
}

static inline void hri_udp_write_IMR_EP1INT_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Udp *)hw)->UDP_IDR = UDP_IMR_EP1INT;
	} else {
		((Udp *)hw)->UDP_IER = UDP_IMR_EP1INT;
	}
}

static inline void hri_udp_clear_IMR_EP1INT_bit(const void *const hw)
{
	((Udp *)hw)->UDP_IDR = UDP_IMR_EP1INT;
}

static inline void hri_udp_set_IMR_EP2INT_bit(const void *const hw)
{
	((Udp *)hw)->UDP_IER = UDP_IMR_EP2INT;
}

static inline bool hri_udp_get_IMR_EP2INT_bit(const void *const hw)
{
	return (((Udp *)hw)->UDP_IMR & UDP_IMR_EP2INT) >> UDP_IMR_EP2INT_Pos;
}

static inline void hri_udp_write_IMR_EP2INT_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Udp *)hw)->UDP_IDR = UDP_IMR_EP2INT;
	} else {
		((Udp *)hw)->UDP_IER = UDP_IMR_EP2INT;
	}
}

static inline void hri_udp_clear_IMR_EP2INT_bit(const void *const hw)
{
	((Udp *)hw)->UDP_IDR = UDP_IMR_EP2INT;
}

static inline void hri_udp_set_IMR_EP3INT_bit(const void *const hw)
{
	((Udp *)hw)->UDP_IER = UDP_IMR_EP3INT;
}

static inline bool hri_udp_get_IMR_EP3INT_bit(const void *const hw)
{
	return (((Udp *)hw)->UDP_IMR & UDP_IMR_EP3INT) >> UDP_IMR_EP3INT_Pos;
}

static inline void hri_udp_write_IMR_EP3INT_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Udp *)hw)->UDP_IDR = UDP_IMR_EP3INT;
	} else {
		((Udp *)hw)->UDP_IER = UDP_IMR_EP3INT;
	}
}

static inline void hri_udp_clear_IMR_EP3INT_bit(const void *const hw)
{
	((Udp *)hw)->UDP_IDR = UDP_IMR_EP3INT;
}

static inline void hri_udp_set_IMR_EP4INT_bit(const void *const hw)
{
	((Udp *)hw)->UDP_IER = UDP_IMR_EP4INT;
}

static inline bool hri_udp_get_IMR_EP4INT_bit(const void *const hw)
{
	return (((Udp *)hw)->UDP_IMR & UDP_IMR_EP4INT) >> UDP_IMR_EP4INT_Pos;
}

static inline void hri_udp_write_IMR_EP4INT_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Udp *)hw)->UDP_IDR = UDP_IMR_EP4INT;
	} else {
		((Udp *)hw)->UDP_IER = UDP_IMR_EP4INT;
	}
}

static inline void hri_udp_clear_IMR_EP4INT_bit(const void *const hw)
{
	((Udp *)hw)->UDP_IDR = UDP_IMR_EP4INT;
}

static inline void hri_udp_set_IMR_EP5INT_bit(const void *const hw)
{
	((Udp *)hw)->UDP_IER = UDP_IMR_EP5INT;
}

static inline bool hri_udp_get_IMR_EP5INT_bit(const void *const hw)
{
	return (((Udp *)hw)->UDP_IMR & UDP_IMR_EP5INT) >> UDP_IMR_EP5INT_Pos;
}

static inline void hri_udp_write_IMR_EP5INT_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Udp *)hw)->UDP_IDR = UDP_IMR_EP5INT;
	} else {
		((Udp *)hw)->UDP_IER = UDP_IMR_EP5INT;
	}
}

static inline void hri_udp_clear_IMR_EP5INT_bit(const void *const hw)
{
	((Udp *)hw)->UDP_IDR = UDP_IMR_EP5INT;
}

static inline void hri_udp_set_IMR_RXSUSP_bit(const void *const hw)
{
	((Udp *)hw)->UDP_IER = UDP_IMR_RXSUSP;
}

static inline bool hri_udp_get_IMR_RXSUSP_bit(const void *const hw)
{
	return (((Udp *)hw)->UDP_IMR & UDP_IMR_RXSUSP) >> UDP_IMR_RXSUSP_Pos;
}

static inline void hri_udp_write_IMR_RXSUSP_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Udp *)hw)->UDP_IDR = UDP_IMR_RXSUSP;
	} else {
		((Udp *)hw)->UDP_IER = UDP_IMR_RXSUSP;
	}
}

static inline void hri_udp_clear_IMR_RXSUSP_bit(const void *const hw)
{
	((Udp *)hw)->UDP_IDR = UDP_IMR_RXSUSP;
}

static inline void hri_udp_set_IMR_RXRSM_bit(const void *const hw)
{
	((Udp *)hw)->UDP_IER = UDP_IMR_RXRSM;
}

static inline bool hri_udp_get_IMR_RXRSM_bit(const void *const hw)
{
	return (((Udp *)hw)->UDP_IMR & UDP_IMR_RXRSM) >> UDP_IMR_RXRSM_Pos;
}

static inline void hri_udp_write_IMR_RXRSM_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Udp *)hw)->UDP_IDR = UDP_IMR_RXRSM;
	} else {
		((Udp *)hw)->UDP_IER = UDP_IMR_RXRSM;
	}
}

static inline void hri_udp_clear_IMR_RXRSM_bit(const void *const hw)
{
	((Udp *)hw)->UDP_IDR = UDP_IMR_RXRSM;
}

static inline void hri_udp_set_IMR_EXTRSM_bit(const void *const hw)
{
	((Udp *)hw)->UDP_IER = UDP_IMR_EXTRSM;
}

static inline bool hri_udp_get_IMR_EXTRSM_bit(const void *const hw)
{
	return (((Udp *)hw)->UDP_IMR & UDP_IMR_EXTRSM) >> UDP_IMR_EXTRSM_Pos;
}

static inline void hri_udp_write_IMR_EXTRSM_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Udp *)hw)->UDP_IDR = UDP_IMR_EXTRSM;
	} else {
		((Udp *)hw)->UDP_IER = UDP_IMR_EXTRSM;
	}
}

static inline void hri_udp_clear_IMR_EXTRSM_bit(const void *const hw)
{
	((Udp *)hw)->UDP_IDR = UDP_IMR_EXTRSM;
}

static inline void hri_udp_set_IMR_SOFINT_bit(const void *const hw)
{
	((Udp *)hw)->UDP_IER = UDP_IMR_SOFINT;
}

static inline bool hri_udp_get_IMR_SOFINT_bit(const void *const hw)
{
	return (((Udp *)hw)->UDP_IMR & UDP_IMR_SOFINT) >> UDP_IMR_SOFINT_Pos;
}

static inline void hri_udp_write_IMR_SOFINT_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Udp *)hw)->UDP_IDR = UDP_IMR_SOFINT;
	} else {
		((Udp *)hw)->UDP_IER = UDP_IMR_SOFINT;
	}
}

static inline void hri_udp_clear_IMR_SOFINT_bit(const void *const hw)
{
	((Udp *)hw)->UDP_IDR = UDP_IMR_SOFINT;
}

static inline bool hri_udp_get_IMR_BIT12_bit(const void *const hw)
{
	return (((Udp *)hw)->UDP_IMR & UDP_IMR_BIT12) >> UDP_IMR_BIT12_Pos;
}

static inline void hri_udp_set_IMR_WAKEUP_bit(const void *const hw)
{
	((Udp *)hw)->UDP_IER = UDP_IMR_WAKEUP;
}

static inline bool hri_udp_get_IMR_WAKEUP_bit(const void *const hw)
{
	return (((Udp *)hw)->UDP_IMR & UDP_IMR_WAKEUP) >> UDP_IMR_WAKEUP_Pos;
}

static inline void hri_udp_write_IMR_WAKEUP_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Udp *)hw)->UDP_IDR = UDP_IMR_WAKEUP;
	} else {
		((Udp *)hw)->UDP_IER = UDP_IMR_WAKEUP;
	}
}

static inline void hri_udp_clear_IMR_WAKEUP_bit(const void *const hw)
{
	((Udp *)hw)->UDP_IDR = UDP_IMR_WAKEUP;
}

static inline void hri_udp_set_IMR_reg(const void *const hw, hri_udp_imr_reg_t mask)
{
	((Udp *)hw)->UDP_IER = mask;
}

static inline hri_udp_imr_reg_t hri_udp_get_IMR_reg(const void *const hw, hri_udp_imr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_IMR;
	tmp &= mask;
	return tmp;
}

static inline hri_udp_imr_reg_t hri_udp_read_IMR_reg(const void *const hw)
{
	return ((Udp *)hw)->UDP_IMR;
}

static inline void hri_udp_write_IMR_reg(const void *const hw, hri_udp_imr_reg_t data)
{
	((Udp *)hw)->UDP_IER = data;
	((Udp *)hw)->UDP_IDR = ~data;
}

static inline void hri_udp_clear_IMR_reg(const void *const hw, hri_udp_imr_reg_t mask)
{
	((Udp *)hw)->UDP_IDR = mask;
}

static inline void hri_udp_write_IDR_reg(const void *const hw, hri_udp_imr_reg_t data)
{
	((Udp *)hw)->UDP_IDR = data;
}

static inline void hri_udp_write_IER_reg(const void *const hw, hri_udp_imr_reg_t data)
{
	((Udp *)hw)->UDP_IER = data;
}

static inline bool hri_udp_get_ISR_EP0INT_bit(const void *const hw)
{
	return (((Udp *)hw)->UDP_ISR & UDP_ISR_EP0INT) >> UDP_ISR_EP0INT_Pos;
}

static inline bool hri_udp_get_ISR_EP1INT_bit(const void *const hw)
{
	return (((Udp *)hw)->UDP_ISR & UDP_ISR_EP1INT) >> UDP_ISR_EP1INT_Pos;
}

static inline bool hri_udp_get_ISR_EP2INT_bit(const void *const hw)
{
	return (((Udp *)hw)->UDP_ISR & UDP_ISR_EP2INT) >> UDP_ISR_EP2INT_Pos;
}

static inline bool hri_udp_get_ISR_EP3INT_bit(const void *const hw)
{
	return (((Udp *)hw)->UDP_ISR & UDP_ISR_EP3INT) >> UDP_ISR_EP3INT_Pos;
}

static inline bool hri_udp_get_ISR_EP4INT_bit(const void *const hw)
{
	return (((Udp *)hw)->UDP_ISR & UDP_ISR_EP4INT) >> UDP_ISR_EP4INT_Pos;
}

static inline bool hri_udp_get_ISR_EP5INT_bit(const void *const hw)
{
	return (((Udp *)hw)->UDP_ISR & UDP_ISR_EP5INT) >> UDP_ISR_EP5INT_Pos;
}

static inline bool hri_udp_get_ISR_RXSUSP_bit(const void *const hw)
{
	return (((Udp *)hw)->UDP_ISR & UDP_ISR_RXSUSP) >> UDP_ISR_RXSUSP_Pos;
}

static inline void hri_udp_clear_ISR_RXSUSP_bit(const void *const hw)
{
	((Udp *)hw)->UDP_ICR = UDP_ISR_RXSUSP;
}

static inline bool hri_udp_get_ISR_RXRSM_bit(const void *const hw)
{
	return (((Udp *)hw)->UDP_ISR & UDP_ISR_RXRSM) >> UDP_ISR_RXRSM_Pos;
}

static inline void hri_udp_clear_ISR_RXRSM_bit(const void *const hw)
{
	((Udp *)hw)->UDP_ICR = UDP_ISR_RXRSM;
}

static inline bool hri_udp_get_ISR_EXTRSM_bit(const void *const hw)
{
	return (((Udp *)hw)->UDP_ISR & UDP_ISR_EXTRSM) >> UDP_ISR_EXTRSM_Pos;
}

static inline void hri_udp_clear_ISR_EXTRSM_bit(const void *const hw)
{
	((Udp *)hw)->UDP_ICR = UDP_ISR_EXTRSM;
}

static inline bool hri_udp_get_ISR_SOFINT_bit(const void *const hw)
{
	return (((Udp *)hw)->UDP_ISR & UDP_ISR_SOFINT) >> UDP_ISR_SOFINT_Pos;
}

static inline void hri_udp_clear_ISR_SOFINT_bit(const void *const hw)
{
	((Udp *)hw)->UDP_ICR = UDP_ISR_SOFINT;
}

static inline bool hri_udp_get_ISR_ENDBUSRES_bit(const void *const hw)
{
	return (((Udp *)hw)->UDP_ISR & UDP_ISR_ENDBUSRES) >> UDP_ISR_ENDBUSRES_Pos;
}

static inline void hri_udp_clear_ISR_ENDBUSRES_bit(const void *const hw)
{
	((Udp *)hw)->UDP_ICR = UDP_ISR_ENDBUSRES;
}

static inline bool hri_udp_get_ISR_WAKEUP_bit(const void *const hw)
{
	return (((Udp *)hw)->UDP_ISR & UDP_ISR_WAKEUP) >> UDP_ISR_WAKEUP_Pos;
}

static inline void hri_udp_clear_ISR_WAKEUP_bit(const void *const hw)
{
	((Udp *)hw)->UDP_ICR = UDP_ISR_WAKEUP;
}

static inline hri_udp_isr_reg_t hri_udp_get_ISR_reg(const void *const hw, hri_udp_isr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_ISR;
	tmp &= mask;
	return tmp;
}

static inline hri_udp_isr_reg_t hri_udp_read_ISR_reg(const void *const hw)
{
	return ((Udp *)hw)->UDP_ISR;
}

static inline void hri_udp_clear_ISR_reg(const void *const hw, hri_udp_isr_reg_t mask)
{
	((Udp *)hw)->UDP_ICR = mask;
}

static inline void hri_udp_write_ICR_reg(const void *const hw, hri_udp_isr_reg_t data)
{
	((Udp *)hw)->UDP_ICR = data;
}

static inline void hri_udp_set_GLB_STAT_FADDEN_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_GLB_STAT |= UDP_GLB_STAT_FADDEN;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_udp_get_GLB_STAT_FADDEN_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_GLB_STAT;
	tmp = (tmp & UDP_GLB_STAT_FADDEN) >> UDP_GLB_STAT_FADDEN_Pos;
	return (bool)tmp;
}

static inline void hri_udp_write_GLB_STAT_FADDEN_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UDP_CRITICAL_SECTION_ENTER();
	tmp = ((Udp *)hw)->UDP_GLB_STAT;
	tmp &= ~UDP_GLB_STAT_FADDEN;
	tmp |= value << UDP_GLB_STAT_FADDEN_Pos;
	((Udp *)hw)->UDP_GLB_STAT = tmp;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_clear_GLB_STAT_FADDEN_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_GLB_STAT &= ~UDP_GLB_STAT_FADDEN;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_toggle_GLB_STAT_FADDEN_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_GLB_STAT ^= UDP_GLB_STAT_FADDEN;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_set_GLB_STAT_CONFG_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_GLB_STAT |= UDP_GLB_STAT_CONFG;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_udp_get_GLB_STAT_CONFG_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_GLB_STAT;
	tmp = (tmp & UDP_GLB_STAT_CONFG) >> UDP_GLB_STAT_CONFG_Pos;
	return (bool)tmp;
}

static inline void hri_udp_write_GLB_STAT_CONFG_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UDP_CRITICAL_SECTION_ENTER();
	tmp = ((Udp *)hw)->UDP_GLB_STAT;
	tmp &= ~UDP_GLB_STAT_CONFG;
	tmp |= value << UDP_GLB_STAT_CONFG_Pos;
	((Udp *)hw)->UDP_GLB_STAT = tmp;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_clear_GLB_STAT_CONFG_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_GLB_STAT &= ~UDP_GLB_STAT_CONFG;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_toggle_GLB_STAT_CONFG_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_GLB_STAT ^= UDP_GLB_STAT_CONFG;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_set_GLB_STAT_ESR_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_GLB_STAT |= UDP_GLB_STAT_ESR;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_udp_get_GLB_STAT_ESR_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_GLB_STAT;
	tmp = (tmp & UDP_GLB_STAT_ESR) >> UDP_GLB_STAT_ESR_Pos;
	return (bool)tmp;
}

static inline void hri_udp_write_GLB_STAT_ESR_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UDP_CRITICAL_SECTION_ENTER();
	tmp = ((Udp *)hw)->UDP_GLB_STAT;
	tmp &= ~UDP_GLB_STAT_ESR;
	tmp |= value << UDP_GLB_STAT_ESR_Pos;
	((Udp *)hw)->UDP_GLB_STAT = tmp;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_clear_GLB_STAT_ESR_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_GLB_STAT &= ~UDP_GLB_STAT_ESR;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_toggle_GLB_STAT_ESR_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_GLB_STAT ^= UDP_GLB_STAT_ESR;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_set_GLB_STAT_RSMINPR_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_GLB_STAT |= UDP_GLB_STAT_RSMINPR;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_udp_get_GLB_STAT_RSMINPR_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_GLB_STAT;
	tmp = (tmp & UDP_GLB_STAT_RSMINPR) >> UDP_GLB_STAT_RSMINPR_Pos;
	return (bool)tmp;
}

static inline void hri_udp_write_GLB_STAT_RSMINPR_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UDP_CRITICAL_SECTION_ENTER();
	tmp = ((Udp *)hw)->UDP_GLB_STAT;
	tmp &= ~UDP_GLB_STAT_RSMINPR;
	tmp |= value << UDP_GLB_STAT_RSMINPR_Pos;
	((Udp *)hw)->UDP_GLB_STAT = tmp;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_clear_GLB_STAT_RSMINPR_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_GLB_STAT &= ~UDP_GLB_STAT_RSMINPR;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_toggle_GLB_STAT_RSMINPR_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_GLB_STAT ^= UDP_GLB_STAT_RSMINPR;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_set_GLB_STAT_RMWUPE_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_GLB_STAT |= UDP_GLB_STAT_RMWUPE;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_udp_get_GLB_STAT_RMWUPE_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_GLB_STAT;
	tmp = (tmp & UDP_GLB_STAT_RMWUPE) >> UDP_GLB_STAT_RMWUPE_Pos;
	return (bool)tmp;
}

static inline void hri_udp_write_GLB_STAT_RMWUPE_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UDP_CRITICAL_SECTION_ENTER();
	tmp = ((Udp *)hw)->UDP_GLB_STAT;
	tmp &= ~UDP_GLB_STAT_RMWUPE;
	tmp |= value << UDP_GLB_STAT_RMWUPE_Pos;
	((Udp *)hw)->UDP_GLB_STAT = tmp;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_clear_GLB_STAT_RMWUPE_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_GLB_STAT &= ~UDP_GLB_STAT_RMWUPE;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_toggle_GLB_STAT_RMWUPE_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_GLB_STAT ^= UDP_GLB_STAT_RMWUPE;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_set_GLB_STAT_reg(const void *const hw, hri_udp_glb_stat_reg_t mask)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_GLB_STAT |= mask;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline hri_udp_glb_stat_reg_t hri_udp_get_GLB_STAT_reg(const void *const hw, hri_udp_glb_stat_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_GLB_STAT;
	tmp &= mask;
	return tmp;
}

static inline void hri_udp_write_GLB_STAT_reg(const void *const hw, hri_udp_glb_stat_reg_t data)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_GLB_STAT = data;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_clear_GLB_STAT_reg(const void *const hw, hri_udp_glb_stat_reg_t mask)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_GLB_STAT &= ~mask;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_toggle_GLB_STAT_reg(const void *const hw, hri_udp_glb_stat_reg_t mask)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_GLB_STAT ^= mask;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline hri_udp_glb_stat_reg_t hri_udp_read_GLB_STAT_reg(const void *const hw)
{
	return ((Udp *)hw)->UDP_GLB_STAT;
}

static inline void hri_udp_set_FADDR_FEN_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_FADDR |= UDP_FADDR_FEN;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_udp_get_FADDR_FEN_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_FADDR;
	tmp = (tmp & UDP_FADDR_FEN) >> UDP_FADDR_FEN_Pos;
	return (bool)tmp;
}

static inline void hri_udp_write_FADDR_FEN_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UDP_CRITICAL_SECTION_ENTER();
	tmp = ((Udp *)hw)->UDP_FADDR;
	tmp &= ~UDP_FADDR_FEN;
	tmp |= value << UDP_FADDR_FEN_Pos;
	((Udp *)hw)->UDP_FADDR = tmp;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_clear_FADDR_FEN_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_FADDR &= ~UDP_FADDR_FEN;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_toggle_FADDR_FEN_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_FADDR ^= UDP_FADDR_FEN;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_set_FADDR_FADD_bf(const void *const hw, hri_udp_faddr_reg_t mask)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_FADDR |= UDP_FADDR_FADD(mask);
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline hri_udp_faddr_reg_t hri_udp_get_FADDR_FADD_bf(const void *const hw, hri_udp_faddr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_FADDR;
	tmp = (tmp & UDP_FADDR_FADD(mask)) >> UDP_FADDR_FADD_Pos;
	return tmp;
}

static inline void hri_udp_write_FADDR_FADD_bf(const void *const hw, hri_udp_faddr_reg_t data)
{
	uint32_t tmp;
	UDP_CRITICAL_SECTION_ENTER();
	tmp = ((Udp *)hw)->UDP_FADDR;
	tmp &= ~UDP_FADDR_FADD_Msk;
	tmp |= UDP_FADDR_FADD(data);
	((Udp *)hw)->UDP_FADDR = tmp;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_clear_FADDR_FADD_bf(const void *const hw, hri_udp_faddr_reg_t mask)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_FADDR &= ~UDP_FADDR_FADD(mask);
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_toggle_FADDR_FADD_bf(const void *const hw, hri_udp_faddr_reg_t mask)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_FADDR ^= UDP_FADDR_FADD(mask);
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline hri_udp_faddr_reg_t hri_udp_read_FADDR_FADD_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_FADDR;
	tmp = (tmp & UDP_FADDR_FADD_Msk) >> UDP_FADDR_FADD_Pos;
	return tmp;
}

static inline void hri_udp_set_FADDR_reg(const void *const hw, hri_udp_faddr_reg_t mask)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_FADDR |= mask;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline hri_udp_faddr_reg_t hri_udp_get_FADDR_reg(const void *const hw, hri_udp_faddr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_FADDR;
	tmp &= mask;
	return tmp;
}

static inline void hri_udp_write_FADDR_reg(const void *const hw, hri_udp_faddr_reg_t data)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_FADDR = data;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_clear_FADDR_reg(const void *const hw, hri_udp_faddr_reg_t mask)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_FADDR &= ~mask;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_toggle_FADDR_reg(const void *const hw, hri_udp_faddr_reg_t mask)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_FADDR ^= mask;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline hri_udp_faddr_reg_t hri_udp_read_FADDR_reg(const void *const hw)
{
	return ((Udp *)hw)->UDP_FADDR;
}

static inline void hri_udp_set_RST_EP_EP0_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_RST_EP |= UDP_RST_EP_EP0;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_udp_get_RST_EP_EP0_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_RST_EP;
	tmp = (tmp & UDP_RST_EP_EP0) >> UDP_RST_EP_EP0_Pos;
	return (bool)tmp;
}

static inline void hri_udp_write_RST_EP_EP0_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UDP_CRITICAL_SECTION_ENTER();
	tmp = ((Udp *)hw)->UDP_RST_EP;
	tmp &= ~UDP_RST_EP_EP0;
	tmp |= value << UDP_RST_EP_EP0_Pos;
	((Udp *)hw)->UDP_RST_EP = tmp;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_clear_RST_EP_EP0_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_RST_EP &= ~UDP_RST_EP_EP0;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_toggle_RST_EP_EP0_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_RST_EP ^= UDP_RST_EP_EP0;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_set_RST_EP_EP1_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_RST_EP |= UDP_RST_EP_EP1;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_udp_get_RST_EP_EP1_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_RST_EP;
	tmp = (tmp & UDP_RST_EP_EP1) >> UDP_RST_EP_EP1_Pos;
	return (bool)tmp;
}

static inline void hri_udp_write_RST_EP_EP1_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UDP_CRITICAL_SECTION_ENTER();
	tmp = ((Udp *)hw)->UDP_RST_EP;
	tmp &= ~UDP_RST_EP_EP1;
	tmp |= value << UDP_RST_EP_EP1_Pos;
	((Udp *)hw)->UDP_RST_EP = tmp;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_clear_RST_EP_EP1_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_RST_EP &= ~UDP_RST_EP_EP1;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_toggle_RST_EP_EP1_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_RST_EP ^= UDP_RST_EP_EP1;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_set_RST_EP_EP2_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_RST_EP |= UDP_RST_EP_EP2;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_udp_get_RST_EP_EP2_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_RST_EP;
	tmp = (tmp & UDP_RST_EP_EP2) >> UDP_RST_EP_EP2_Pos;
	return (bool)tmp;
}

static inline void hri_udp_write_RST_EP_EP2_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UDP_CRITICAL_SECTION_ENTER();
	tmp = ((Udp *)hw)->UDP_RST_EP;
	tmp &= ~UDP_RST_EP_EP2;
	tmp |= value << UDP_RST_EP_EP2_Pos;
	((Udp *)hw)->UDP_RST_EP = tmp;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_clear_RST_EP_EP2_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_RST_EP &= ~UDP_RST_EP_EP2;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_toggle_RST_EP_EP2_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_RST_EP ^= UDP_RST_EP_EP2;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_set_RST_EP_EP3_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_RST_EP |= UDP_RST_EP_EP3;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_udp_get_RST_EP_EP3_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_RST_EP;
	tmp = (tmp & UDP_RST_EP_EP3) >> UDP_RST_EP_EP3_Pos;
	return (bool)tmp;
}

static inline void hri_udp_write_RST_EP_EP3_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UDP_CRITICAL_SECTION_ENTER();
	tmp = ((Udp *)hw)->UDP_RST_EP;
	tmp &= ~UDP_RST_EP_EP3;
	tmp |= value << UDP_RST_EP_EP3_Pos;
	((Udp *)hw)->UDP_RST_EP = tmp;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_clear_RST_EP_EP3_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_RST_EP &= ~UDP_RST_EP_EP3;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_toggle_RST_EP_EP3_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_RST_EP ^= UDP_RST_EP_EP3;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_set_RST_EP_EP4_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_RST_EP |= UDP_RST_EP_EP4;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_udp_get_RST_EP_EP4_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_RST_EP;
	tmp = (tmp & UDP_RST_EP_EP4) >> UDP_RST_EP_EP4_Pos;
	return (bool)tmp;
}

static inline void hri_udp_write_RST_EP_EP4_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UDP_CRITICAL_SECTION_ENTER();
	tmp = ((Udp *)hw)->UDP_RST_EP;
	tmp &= ~UDP_RST_EP_EP4;
	tmp |= value << UDP_RST_EP_EP4_Pos;
	((Udp *)hw)->UDP_RST_EP = tmp;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_clear_RST_EP_EP4_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_RST_EP &= ~UDP_RST_EP_EP4;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_toggle_RST_EP_EP4_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_RST_EP ^= UDP_RST_EP_EP4;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_set_RST_EP_EP5_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_RST_EP |= UDP_RST_EP_EP5;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_udp_get_RST_EP_EP5_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_RST_EP;
	tmp = (tmp & UDP_RST_EP_EP5) >> UDP_RST_EP_EP5_Pos;
	return (bool)tmp;
}

static inline void hri_udp_write_RST_EP_EP5_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UDP_CRITICAL_SECTION_ENTER();
	tmp = ((Udp *)hw)->UDP_RST_EP;
	tmp &= ~UDP_RST_EP_EP5;
	tmp |= value << UDP_RST_EP_EP5_Pos;
	((Udp *)hw)->UDP_RST_EP = tmp;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_clear_RST_EP_EP5_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_RST_EP &= ~UDP_RST_EP_EP5;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_toggle_RST_EP_EP5_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_RST_EP ^= UDP_RST_EP_EP5;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_set_RST_EP_reg(const void *const hw, hri_udp_rst_ep_reg_t mask)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_RST_EP |= mask;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline hri_udp_rst_ep_reg_t hri_udp_get_RST_EP_reg(const void *const hw, hri_udp_rst_ep_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_RST_EP;
	tmp &= mask;
	return tmp;
}

static inline void hri_udp_write_RST_EP_reg(const void *const hw, hri_udp_rst_ep_reg_t data)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_RST_EP = data;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_clear_RST_EP_reg(const void *const hw, hri_udp_rst_ep_reg_t mask)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_RST_EP &= ~mask;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_toggle_RST_EP_reg(const void *const hw, hri_udp_rst_ep_reg_t mask)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_RST_EP ^= mask;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline hri_udp_rst_ep_reg_t hri_udp_read_RST_EP_reg(const void *const hw)
{
	return ((Udp *)hw)->UDP_RST_EP;
}

static inline void hri_udp_set_CSR_TXCOMP_bit(const void *const hw, uint8_t index)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] |= UDP_CSR_TXCOMP;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_udp_get_CSR_TXCOMP_bit(const void *const hw, uint8_t index)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_CSR[index];
	tmp = (tmp & UDP_CSR_TXCOMP) >> UDP_CSR_TXCOMP_Pos;
	return (bool)tmp;
}

static inline void hri_udp_write_CSR_TXCOMP_bit(const void *const hw, uint8_t index, bool value)
{
	uint32_t tmp;
	UDP_CRITICAL_SECTION_ENTER();
	tmp = ((Udp *)hw)->UDP_CSR[index];
	tmp &= ~UDP_CSR_TXCOMP;
	tmp |= value << UDP_CSR_TXCOMP_Pos;
	((Udp *)hw)->UDP_CSR[index] = tmp;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_clear_CSR_TXCOMP_bit(const void *const hw, uint8_t index)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] &= ~UDP_CSR_TXCOMP;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_toggle_CSR_TXCOMP_bit(const void *const hw, uint8_t index)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] ^= UDP_CSR_TXCOMP;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_set_CSR_RX_DATA_BK0_bit(const void *const hw, uint8_t index)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] |= UDP_CSR_RX_DATA_BK0;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_udp_get_CSR_RX_DATA_BK0_bit(const void *const hw, uint8_t index)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_CSR[index];
	tmp = (tmp & UDP_CSR_RX_DATA_BK0) >> UDP_CSR_RX_DATA_BK0_Pos;
	return (bool)tmp;
}

static inline void hri_udp_write_CSR_RX_DATA_BK0_bit(const void *const hw, uint8_t index, bool value)
{
	uint32_t tmp;
	UDP_CRITICAL_SECTION_ENTER();
	tmp = ((Udp *)hw)->UDP_CSR[index];
	tmp &= ~UDP_CSR_RX_DATA_BK0;
	tmp |= value << UDP_CSR_RX_DATA_BK0_Pos;
	((Udp *)hw)->UDP_CSR[index] = tmp;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_clear_CSR_RX_DATA_BK0_bit(const void *const hw, uint8_t index)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] &= ~UDP_CSR_RX_DATA_BK0;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_toggle_CSR_RX_DATA_BK0_bit(const void *const hw, uint8_t index)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] ^= UDP_CSR_RX_DATA_BK0;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_set_CSR_RXSETUP_bit(const void *const hw, uint8_t index)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] |= UDP_CSR_RXSETUP;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_udp_get_CSR_RXSETUP_bit(const void *const hw, uint8_t index)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_CSR[index];
	tmp = (tmp & UDP_CSR_RXSETUP) >> UDP_CSR_RXSETUP_Pos;
	return (bool)tmp;
}

static inline void hri_udp_write_CSR_RXSETUP_bit(const void *const hw, uint8_t index, bool value)
{
	uint32_t tmp;
	UDP_CRITICAL_SECTION_ENTER();
	tmp = ((Udp *)hw)->UDP_CSR[index];
	tmp &= ~UDP_CSR_RXSETUP;
	tmp |= value << UDP_CSR_RXSETUP_Pos;
	((Udp *)hw)->UDP_CSR[index] = tmp;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_clear_CSR_RXSETUP_bit(const void *const hw, uint8_t index)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] &= ~UDP_CSR_RXSETUP;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_toggle_CSR_RXSETUP_bit(const void *const hw, uint8_t index)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] ^= UDP_CSR_RXSETUP;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_set_CSR_STALLSENT_bit(const void *const hw, uint8_t index)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] |= UDP_CSR_STALLSENT;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_udp_get_CSR_STALLSENT_bit(const void *const hw, uint8_t index)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_CSR[index];
	tmp = (tmp & UDP_CSR_STALLSENT) >> UDP_CSR_STALLSENT_Pos;
	return (bool)tmp;
}

static inline void hri_udp_write_CSR_STALLSENT_bit(const void *const hw, uint8_t index, bool value)
{
	uint32_t tmp;
	UDP_CRITICAL_SECTION_ENTER();
	tmp = ((Udp *)hw)->UDP_CSR[index];
	tmp &= ~UDP_CSR_STALLSENT;
	tmp |= value << UDP_CSR_STALLSENT_Pos;
	((Udp *)hw)->UDP_CSR[index] = tmp;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_clear_CSR_STALLSENT_bit(const void *const hw, uint8_t index)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] &= ~UDP_CSR_STALLSENT;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_toggle_CSR_STALLSENT_bit(const void *const hw, uint8_t index)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] ^= UDP_CSR_STALLSENT;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_set_CSR_TXPKTRDY_bit(const void *const hw, uint8_t index)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] |= UDP_CSR_TXPKTRDY;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_udp_get_CSR_TXPKTRDY_bit(const void *const hw, uint8_t index)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_CSR[index];
	tmp = (tmp & UDP_CSR_TXPKTRDY) >> UDP_CSR_TXPKTRDY_Pos;
	return (bool)tmp;
}

static inline void hri_udp_write_CSR_TXPKTRDY_bit(const void *const hw, uint8_t index, bool value)
{
	uint32_t tmp;
	UDP_CRITICAL_SECTION_ENTER();
	tmp = ((Udp *)hw)->UDP_CSR[index];
	tmp &= ~UDP_CSR_TXPKTRDY;
	tmp |= value << UDP_CSR_TXPKTRDY_Pos;
	((Udp *)hw)->UDP_CSR[index] = tmp;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_clear_CSR_TXPKTRDY_bit(const void *const hw, uint8_t index)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] &= ~UDP_CSR_TXPKTRDY;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_toggle_CSR_TXPKTRDY_bit(const void *const hw, uint8_t index)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] ^= UDP_CSR_TXPKTRDY;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_set_CSR_FORCESTALL_bit(const void *const hw, uint8_t index)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] |= UDP_CSR_FORCESTALL;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_udp_get_CSR_FORCESTALL_bit(const void *const hw, uint8_t index)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_CSR[index];
	tmp = (tmp & UDP_CSR_FORCESTALL) >> UDP_CSR_FORCESTALL_Pos;
	return (bool)tmp;
}

static inline void hri_udp_write_CSR_FORCESTALL_bit(const void *const hw, uint8_t index, bool value)
{
	uint32_t tmp;
	UDP_CRITICAL_SECTION_ENTER();
	tmp = ((Udp *)hw)->UDP_CSR[index];
	tmp &= ~UDP_CSR_FORCESTALL;
	tmp |= value << UDP_CSR_FORCESTALL_Pos;
	((Udp *)hw)->UDP_CSR[index] = tmp;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_clear_CSR_FORCESTALL_bit(const void *const hw, uint8_t index)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] &= ~UDP_CSR_FORCESTALL;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_toggle_CSR_FORCESTALL_bit(const void *const hw, uint8_t index)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] ^= UDP_CSR_FORCESTALL;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_set_CSR_RX_DATA_BK1_bit(const void *const hw, uint8_t index)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] |= UDP_CSR_RX_DATA_BK1;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_udp_get_CSR_RX_DATA_BK1_bit(const void *const hw, uint8_t index)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_CSR[index];
	tmp = (tmp & UDP_CSR_RX_DATA_BK1) >> UDP_CSR_RX_DATA_BK1_Pos;
	return (bool)tmp;
}

static inline void hri_udp_write_CSR_RX_DATA_BK1_bit(const void *const hw, uint8_t index, bool value)
{
	uint32_t tmp;
	UDP_CRITICAL_SECTION_ENTER();
	tmp = ((Udp *)hw)->UDP_CSR[index];
	tmp &= ~UDP_CSR_RX_DATA_BK1;
	tmp |= value << UDP_CSR_RX_DATA_BK1_Pos;
	((Udp *)hw)->UDP_CSR[index] = tmp;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_clear_CSR_RX_DATA_BK1_bit(const void *const hw, uint8_t index)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] &= ~UDP_CSR_RX_DATA_BK1;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_toggle_CSR_RX_DATA_BK1_bit(const void *const hw, uint8_t index)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] ^= UDP_CSR_RX_DATA_BK1;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_set_CSR_DIR_bit(const void *const hw, uint8_t index)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] |= UDP_CSR_DIR;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_udp_get_CSR_DIR_bit(const void *const hw, uint8_t index)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_CSR[index];
	tmp = (tmp & UDP_CSR_DIR) >> UDP_CSR_DIR_Pos;
	return (bool)tmp;
}

static inline void hri_udp_write_CSR_DIR_bit(const void *const hw, uint8_t index, bool value)
{
	uint32_t tmp;
	UDP_CRITICAL_SECTION_ENTER();
	tmp = ((Udp *)hw)->UDP_CSR[index];
	tmp &= ~UDP_CSR_DIR;
	tmp |= value << UDP_CSR_DIR_Pos;
	((Udp *)hw)->UDP_CSR[index] = tmp;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_clear_CSR_DIR_bit(const void *const hw, uint8_t index)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] &= ~UDP_CSR_DIR;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_toggle_CSR_DIR_bit(const void *const hw, uint8_t index)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] ^= UDP_CSR_DIR;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_set_CSR_DTGLE_bit(const void *const hw, uint8_t index)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] |= UDP_CSR_DTGLE;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_udp_get_CSR_DTGLE_bit(const void *const hw, uint8_t index)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_CSR[index];
	tmp = (tmp & UDP_CSR_DTGLE) >> UDP_CSR_DTGLE_Pos;
	return (bool)tmp;
}

static inline void hri_udp_write_CSR_DTGLE_bit(const void *const hw, uint8_t index, bool value)
{
	uint32_t tmp;
	UDP_CRITICAL_SECTION_ENTER();
	tmp = ((Udp *)hw)->UDP_CSR[index];
	tmp &= ~UDP_CSR_DTGLE;
	tmp |= value << UDP_CSR_DTGLE_Pos;
	((Udp *)hw)->UDP_CSR[index] = tmp;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_clear_CSR_DTGLE_bit(const void *const hw, uint8_t index)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] &= ~UDP_CSR_DTGLE;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_toggle_CSR_DTGLE_bit(const void *const hw, uint8_t index)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] ^= UDP_CSR_DTGLE;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_set_CSR_EPEDS_bit(const void *const hw, uint8_t index)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] |= UDP_CSR_EPEDS;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_udp_get_CSR_EPEDS_bit(const void *const hw, uint8_t index)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_CSR[index];
	tmp = (tmp & UDP_CSR_EPEDS) >> UDP_CSR_EPEDS_Pos;
	return (bool)tmp;
}

static inline void hri_udp_write_CSR_EPEDS_bit(const void *const hw, uint8_t index, bool value)
{
	uint32_t tmp;
	UDP_CRITICAL_SECTION_ENTER();
	tmp = ((Udp *)hw)->UDP_CSR[index];
	tmp &= ~UDP_CSR_EPEDS;
	tmp |= value << UDP_CSR_EPEDS_Pos;
	((Udp *)hw)->UDP_CSR[index] = tmp;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_clear_CSR_EPEDS_bit(const void *const hw, uint8_t index)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] &= ~UDP_CSR_EPEDS;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_toggle_CSR_EPEDS_bit(const void *const hw, uint8_t index)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] ^= UDP_CSR_EPEDS;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_set_CSR_EPTYPE_bf(const void *const hw, uint8_t index, hri_udp_csr_reg_t mask)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] |= UDP_CSR_EPTYPE(mask);
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline hri_udp_csr_reg_t hri_udp_get_CSR_EPTYPE_bf(const void *const hw, uint8_t index, hri_udp_csr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_CSR[index];
	tmp = (tmp & UDP_CSR_EPTYPE(mask)) >> UDP_CSR_EPTYPE_Pos;
	return tmp;
}

static inline void hri_udp_write_CSR_EPTYPE_bf(const void *const hw, uint8_t index, hri_udp_csr_reg_t data)
{
	uint32_t tmp;
	UDP_CRITICAL_SECTION_ENTER();
	tmp = ((Udp *)hw)->UDP_CSR[index];
	tmp &= ~UDP_CSR_EPTYPE_Msk;
	tmp |= UDP_CSR_EPTYPE(data);
	((Udp *)hw)->UDP_CSR[index] = tmp;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_clear_CSR_EPTYPE_bf(const void *const hw, uint8_t index, hri_udp_csr_reg_t mask)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] &= ~UDP_CSR_EPTYPE(mask);
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_toggle_CSR_EPTYPE_bf(const void *const hw, uint8_t index, hri_udp_csr_reg_t mask)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] ^= UDP_CSR_EPTYPE(mask);
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline hri_udp_csr_reg_t hri_udp_read_CSR_EPTYPE_bf(const void *const hw, uint8_t index)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_CSR[index];
	tmp = (tmp & UDP_CSR_EPTYPE_Msk) >> UDP_CSR_EPTYPE_Pos;
	return tmp;
}

static inline void hri_udp_set_CSR_RXBYTECNT_bf(const void *const hw, uint8_t index, hri_udp_csr_reg_t mask)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] |= UDP_CSR_RXBYTECNT(mask);
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline hri_udp_csr_reg_t hri_udp_get_CSR_RXBYTECNT_bf(const void *const hw, uint8_t index,
                                                             hri_udp_csr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_CSR[index];
	tmp = (tmp & UDP_CSR_RXBYTECNT(mask)) >> UDP_CSR_RXBYTECNT_Pos;
	return tmp;
}

static inline void hri_udp_write_CSR_RXBYTECNT_bf(const void *const hw, uint8_t index, hri_udp_csr_reg_t data)
{
	uint32_t tmp;
	UDP_CRITICAL_SECTION_ENTER();
	tmp = ((Udp *)hw)->UDP_CSR[index];
	tmp &= ~UDP_CSR_RXBYTECNT_Msk;
	tmp |= UDP_CSR_RXBYTECNT(data);
	((Udp *)hw)->UDP_CSR[index] = tmp;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_clear_CSR_RXBYTECNT_bf(const void *const hw, uint8_t index, hri_udp_csr_reg_t mask)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] &= ~UDP_CSR_RXBYTECNT(mask);
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_toggle_CSR_RXBYTECNT_bf(const void *const hw, uint8_t index, hri_udp_csr_reg_t mask)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] ^= UDP_CSR_RXBYTECNT(mask);
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline hri_udp_csr_reg_t hri_udp_read_CSR_RXBYTECNT_bf(const void *const hw, uint8_t index)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_CSR[index];
	tmp = (tmp & UDP_CSR_RXBYTECNT_Msk) >> UDP_CSR_RXBYTECNT_Pos;
	return tmp;
}

static inline void hri_udp_set_CSR_reg(const void *const hw, uint8_t index, hri_udp_csr_reg_t mask)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] |= mask;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline hri_udp_csr_reg_t hri_udp_get_CSR_reg(const void *const hw, uint8_t index, hri_udp_csr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_CSR[index];
	tmp &= mask;
	return tmp;
}

static inline void hri_udp_write_CSR_reg(const void *const hw, uint8_t index, hri_udp_csr_reg_t data)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] = data;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_clear_CSR_reg(const void *const hw, uint8_t index, hri_udp_csr_reg_t mask)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] &= ~mask;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_toggle_CSR_reg(const void *const hw, uint8_t index, hri_udp_csr_reg_t mask)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_CSR[index] ^= mask;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline hri_udp_csr_reg_t hri_udp_read_CSR_reg(const void *const hw, uint8_t index)
{
	return ((Udp *)hw)->UDP_CSR[index];
}

static inline void hri_udp_set_FDR_FIFO_DATA_bf(const void *const hw, uint8_t index, hri_udp_fdr_reg_t mask)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_FDR[index] |= UDP_FDR_FIFO_DATA(mask);
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline hri_udp_fdr_reg_t hri_udp_get_FDR_FIFO_DATA_bf(const void *const hw, uint8_t index,
                                                             hri_udp_fdr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_FDR[index];
	tmp = (tmp & UDP_FDR_FIFO_DATA(mask)) >> UDP_FDR_FIFO_DATA_Pos;
	return tmp;
}

static inline void hri_udp_write_FDR_FIFO_DATA_bf(const void *const hw, uint8_t index, hri_udp_fdr_reg_t data)
{
	uint32_t tmp;
	UDP_CRITICAL_SECTION_ENTER();
	tmp = ((Udp *)hw)->UDP_FDR[index];
	tmp &= ~UDP_FDR_FIFO_DATA_Msk;
	tmp |= UDP_FDR_FIFO_DATA(data);
	((Udp *)hw)->UDP_FDR[index] = tmp;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_clear_FDR_FIFO_DATA_bf(const void *const hw, uint8_t index, hri_udp_fdr_reg_t mask)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_FDR[index] &= ~UDP_FDR_FIFO_DATA(mask);
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_toggle_FDR_FIFO_DATA_bf(const void *const hw, uint8_t index, hri_udp_fdr_reg_t mask)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_FDR[index] ^= UDP_FDR_FIFO_DATA(mask);
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline hri_udp_fdr_reg_t hri_udp_read_FDR_FIFO_DATA_bf(const void *const hw, uint8_t index)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_FDR[index];
	tmp = (tmp & UDP_FDR_FIFO_DATA_Msk) >> UDP_FDR_FIFO_DATA_Pos;
	return tmp;
}

static inline void hri_udp_set_FDR_reg(const void *const hw, uint8_t index, hri_udp_fdr_reg_t mask)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_FDR[index] |= mask;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline hri_udp_fdr_reg_t hri_udp_get_FDR_reg(const void *const hw, uint8_t index, hri_udp_fdr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_FDR[index];
	tmp &= mask;
	return tmp;
}

static inline void hri_udp_write_FDR_reg(const void *const hw, uint8_t index, hri_udp_fdr_reg_t data)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_FDR[index] = data;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_clear_FDR_reg(const void *const hw, uint8_t index, hri_udp_fdr_reg_t mask)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_FDR[index] &= ~mask;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_toggle_FDR_reg(const void *const hw, uint8_t index, hri_udp_fdr_reg_t mask)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_FDR[index] ^= mask;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline hri_udp_fdr_reg_t hri_udp_read_FDR_reg(const void *const hw, uint8_t index)
{
	return ((Udp *)hw)->UDP_FDR[index];
}

static inline void hri_udp_set_TXVC_TXVDIS_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_TXVC |= UDP_TXVC_TXVDIS;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_udp_get_TXVC_TXVDIS_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_TXVC;
	tmp = (tmp & UDP_TXVC_TXVDIS) >> UDP_TXVC_TXVDIS_Pos;
	return (bool)tmp;
}

static inline void hri_udp_write_TXVC_TXVDIS_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UDP_CRITICAL_SECTION_ENTER();
	tmp = ((Udp *)hw)->UDP_TXVC;
	tmp &= ~UDP_TXVC_TXVDIS;
	tmp |= value << UDP_TXVC_TXVDIS_Pos;
	((Udp *)hw)->UDP_TXVC = tmp;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_clear_TXVC_TXVDIS_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_TXVC &= ~UDP_TXVC_TXVDIS;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_toggle_TXVC_TXVDIS_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_TXVC ^= UDP_TXVC_TXVDIS;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_set_TXVC_PUON_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_TXVC |= UDP_TXVC_PUON;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_udp_get_TXVC_PUON_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_TXVC;
	tmp = (tmp & UDP_TXVC_PUON) >> UDP_TXVC_PUON_Pos;
	return (bool)tmp;
}

static inline void hri_udp_write_TXVC_PUON_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UDP_CRITICAL_SECTION_ENTER();
	tmp = ((Udp *)hw)->UDP_TXVC;
	tmp &= ~UDP_TXVC_PUON;
	tmp |= value << UDP_TXVC_PUON_Pos;
	((Udp *)hw)->UDP_TXVC = tmp;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_clear_TXVC_PUON_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_TXVC &= ~UDP_TXVC_PUON;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_toggle_TXVC_PUON_bit(const void *const hw)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_TXVC ^= UDP_TXVC_PUON;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_set_TXVC_reg(const void *const hw, hri_udp_txvc_reg_t mask)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_TXVC |= mask;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline hri_udp_txvc_reg_t hri_udp_get_TXVC_reg(const void *const hw, hri_udp_txvc_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_TXVC;
	tmp &= mask;
	return tmp;
}

static inline void hri_udp_write_TXVC_reg(const void *const hw, hri_udp_txvc_reg_t data)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_TXVC = data;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_clear_TXVC_reg(const void *const hw, hri_udp_txvc_reg_t mask)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_TXVC &= ~mask;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_udp_toggle_TXVC_reg(const void *const hw, hri_udp_txvc_reg_t mask)
{
	UDP_CRITICAL_SECTION_ENTER();
	((Udp *)hw)->UDP_TXVC ^= mask;
	UDP_CRITICAL_SECTION_LEAVE();
}

static inline hri_udp_txvc_reg_t hri_udp_read_TXVC_reg(const void *const hw)
{
	return ((Udp *)hw)->UDP_TXVC;
}

static inline bool hri_udp_get_FRM_NUM_FRM_ERR_bit(const void *const hw)
{
	return (((Udp *)hw)->UDP_FRM_NUM & UDP_FRM_NUM_FRM_ERR) > 0;
}

static inline bool hri_udp_get_FRM_NUM_FRM_OK_bit(const void *const hw)
{
	return (((Udp *)hw)->UDP_FRM_NUM & UDP_FRM_NUM_FRM_OK) > 0;
}

static inline hri_udp_frm_num_reg_t hri_udp_get_FRM_NUM_FRM_NUM_bf(const void *const hw, hri_udp_frm_num_reg_t mask)
{
	return (((Udp *)hw)->UDP_FRM_NUM & UDP_FRM_NUM_FRM_NUM(mask)) >> UDP_FRM_NUM_FRM_NUM_Pos;
}

static inline hri_udp_frm_num_reg_t hri_udp_read_FRM_NUM_FRM_NUM_bf(const void *const hw)
{
	return (((Udp *)hw)->UDP_FRM_NUM & UDP_FRM_NUM_FRM_NUM_Msk) >> UDP_FRM_NUM_FRM_NUM_Pos;
}

static inline hri_udp_frm_num_reg_t hri_udp_get_FRM_NUM_reg(const void *const hw, hri_udp_frm_num_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Udp *)hw)->UDP_FRM_NUM;
	tmp &= mask;
	return tmp;
}

static inline hri_udp_frm_num_reg_t hri_udp_read_FRM_NUM_reg(const void *const hw)
{
	return ((Udp *)hw)->UDP_FRM_NUM;
}

#ifdef __cplusplus
}
#endif

#endif /* _HRI_UDP_G55_H_INCLUDED */
#endif /* _SAMG55_UDP_COMPONENT_ */
