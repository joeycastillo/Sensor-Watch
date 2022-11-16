/**
 * \file
 *
 * \brief SAM SystemControl
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

#ifdef _SAMG55_SystemControl_COMPONENT_
#ifndef _HRI_SystemControl_G55_H_INCLUDED_
#define _HRI_SystemControl_G55_H_INCLUDED_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <hal_atomic.h>

#if defined(ENABLE_SystemControl_CRITICAL_SECTIONS)
#define SystemControl_CRITICAL_SECTION_ENTER() CRITICAL_SECTION_ENTER()
#define SystemControl_CRITICAL_SECTION_LEAVE() CRITICAL_SECTION_LEAVE()
#else
#define SystemControl_CRITICAL_SECTION_ENTER()
#define SystemControl_CRITICAL_SECTION_LEAVE()
#endif

typedef uint32_t hri_systemcontrol_actlr_reg_t;
typedef uint32_t hri_systemcontrol_afsr_reg_t;
typedef uint32_t hri_systemcontrol_aircr_reg_t;
typedef uint32_t hri_systemcontrol_bfar_reg_t;
typedef uint32_t hri_systemcontrol_ccr_reg_t;
typedef uint32_t hri_systemcontrol_cfsr_reg_t;
typedef uint32_t hri_systemcontrol_cpuid_reg_t;
typedef uint32_t hri_systemcontrol_dfsr_reg_t;
typedef uint32_t hri_systemcontrol_hfsr_reg_t;
typedef uint32_t hri_systemcontrol_icsr_reg_t;
typedef uint32_t hri_systemcontrol_mmfar_reg_t;
typedef uint32_t hri_systemcontrol_scr_reg_t;
typedef uint32_t hri_systemcontrol_shcsr_reg_t;
typedef uint32_t hri_systemcontrol_shpr1_reg_t;
typedef uint32_t hri_systemcontrol_shpr2_reg_t;
typedef uint32_t hri_systemcontrol_shpr3_reg_t;
typedef uint32_t hri_systemcontrol_vtor_reg_t;

static inline void hri_systemcontrol_set_ACTLR_DISMCYCINT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ACTLR |= SystemControl_ACTLR_DISMCYCINT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_ACTLR_DISMCYCINT_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->ACTLR;
	tmp = (tmp & SystemControl_ACTLR_DISMCYCINT) >> 0;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_ACTLR_DISMCYCINT_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->ACTLR;
	tmp &= ~SystemControl_ACTLR_DISMCYCINT;
	tmp |= value << 0;
	((Systemcontrol *)hw)->ACTLR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_ACTLR_DISMCYCINT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ACTLR &= ~SystemControl_ACTLR_DISMCYCINT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_ACTLR_DISMCYCINT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ACTLR ^= SystemControl_ACTLR_DISMCYCINT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_ACTLR_DISDEFWBUF_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ACTLR |= SystemControl_ACTLR_DISDEFWBUF;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_ACTLR_DISDEFWBUF_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->ACTLR;
	tmp = (tmp & SystemControl_ACTLR_DISDEFWBUF) >> 1;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_ACTLR_DISDEFWBUF_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->ACTLR;
	tmp &= ~SystemControl_ACTLR_DISDEFWBUF;
	tmp |= value << 1;
	((Systemcontrol *)hw)->ACTLR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_ACTLR_DISDEFWBUF_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ACTLR &= ~SystemControl_ACTLR_DISDEFWBUF;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_ACTLR_DISDEFWBUF_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ACTLR ^= SystemControl_ACTLR_DISDEFWBUF;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_ACTLR_DISFOLD_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ACTLR |= SystemControl_ACTLR_DISFOLD;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_ACTLR_DISFOLD_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->ACTLR;
	tmp = (tmp & SystemControl_ACTLR_DISFOLD) >> 2;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_ACTLR_DISFOLD_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->ACTLR;
	tmp &= ~SystemControl_ACTLR_DISFOLD;
	tmp |= value << 2;
	((Systemcontrol *)hw)->ACTLR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_ACTLR_DISFOLD_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ACTLR &= ~SystemControl_ACTLR_DISFOLD;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_ACTLR_DISFOLD_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ACTLR ^= SystemControl_ACTLR_DISFOLD;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_ACTLR_reg(const void *const hw, hri_systemcontrol_actlr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ACTLR |= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_actlr_reg_t hri_systemcontrol_get_ACTLR_reg(const void *const             hw,
                                                                            hri_systemcontrol_actlr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->ACTLR;
	tmp &= mask;
	return tmp;
}

static inline void hri_systemcontrol_write_ACTLR_reg(const void *const hw, hri_systemcontrol_actlr_reg_t data)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ACTLR = data;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_ACTLR_reg(const void *const hw, hri_systemcontrol_actlr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ACTLR &= ~mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_ACTLR_reg(const void *const hw, hri_systemcontrol_actlr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ACTLR ^= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_actlr_reg_t hri_systemcontrol_read_ACTLR_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->ACTLR;
}

static inline void hri_systemcontrol_set_CPUID_REVISION_bf(const void *const hw, hri_systemcontrol_cpuid_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CPUID |= SystemControl_CPUID_REVISION(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_cpuid_reg_t hri_systemcontrol_get_CPUID_REVISION_bf(const void *const             hw,
                                                                                    hri_systemcontrol_cpuid_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CPUID;
	tmp = (tmp & SystemControl_CPUID_REVISION(mask)) >> 0;
	return tmp;
}

static inline void hri_systemcontrol_write_CPUID_REVISION_bf(const void *const hw, hri_systemcontrol_cpuid_reg_t data)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->CPUID;
	tmp &= ~SystemControl_CPUID_REVISION_Msk;
	tmp |= SystemControl_CPUID_REVISION(data);
	((Systemcontrol *)hw)->CPUID = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_CPUID_REVISION_bf(const void *const hw, hri_systemcontrol_cpuid_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CPUID &= ~SystemControl_CPUID_REVISION(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_CPUID_REVISION_bf(const void *const hw, hri_systemcontrol_cpuid_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CPUID ^= SystemControl_CPUID_REVISION(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_cpuid_reg_t hri_systemcontrol_read_CPUID_REVISION_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CPUID;
	tmp = (tmp & SystemControl_CPUID_REVISION_Msk) >> 0;
	return tmp;
}

static inline void hri_systemcontrol_set_CPUID_PARTNO_bf(const void *const hw, hri_systemcontrol_cpuid_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CPUID |= SystemControl_CPUID_PARTNO(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_cpuid_reg_t hri_systemcontrol_get_CPUID_PARTNO_bf(const void *const             hw,
                                                                                  hri_systemcontrol_cpuid_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CPUID;
	tmp = (tmp & SystemControl_CPUID_PARTNO(mask)) >> 4;
	return tmp;
}

static inline void hri_systemcontrol_write_CPUID_PARTNO_bf(const void *const hw, hri_systemcontrol_cpuid_reg_t data)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->CPUID;
	tmp &= ~SystemControl_CPUID_PARTNO_Msk;
	tmp |= SystemControl_CPUID_PARTNO(data);
	((Systemcontrol *)hw)->CPUID = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_CPUID_PARTNO_bf(const void *const hw, hri_systemcontrol_cpuid_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CPUID &= ~SystemControl_CPUID_PARTNO(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_CPUID_PARTNO_bf(const void *const hw, hri_systemcontrol_cpuid_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CPUID ^= SystemControl_CPUID_PARTNO(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_cpuid_reg_t hri_systemcontrol_read_CPUID_PARTNO_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CPUID;
	tmp = (tmp & SystemControl_CPUID_PARTNO_Msk) >> 4;
	return tmp;
}

static inline void hri_systemcontrol_set_CPUID_VARIANT_bf(const void *const hw, hri_systemcontrol_cpuid_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CPUID |= SystemControl_CPUID_VARIANT(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_cpuid_reg_t hri_systemcontrol_get_CPUID_VARIANT_bf(const void *const             hw,
                                                                                   hri_systemcontrol_cpuid_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CPUID;
	tmp = (tmp & SystemControl_CPUID_VARIANT(mask)) >> 20;
	return tmp;
}

static inline void hri_systemcontrol_write_CPUID_VARIANT_bf(const void *const hw, hri_systemcontrol_cpuid_reg_t data)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->CPUID;
	tmp &= ~SystemControl_CPUID_VARIANT_Msk;
	tmp |= SystemControl_CPUID_VARIANT(data);
	((Systemcontrol *)hw)->CPUID = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_CPUID_VARIANT_bf(const void *const hw, hri_systemcontrol_cpuid_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CPUID &= ~SystemControl_CPUID_VARIANT(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_CPUID_VARIANT_bf(const void *const hw, hri_systemcontrol_cpuid_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CPUID ^= SystemControl_CPUID_VARIANT(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_cpuid_reg_t hri_systemcontrol_read_CPUID_VARIANT_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CPUID;
	tmp = (tmp & SystemControl_CPUID_VARIANT_Msk) >> 20;
	return tmp;
}

static inline void hri_systemcontrol_set_CPUID_IMPLEMENTER_bf(const void *const hw, hri_systemcontrol_cpuid_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CPUID |= SystemControl_CPUID_IMPLEMENTER(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_cpuid_reg_t
hri_systemcontrol_get_CPUID_IMPLEMENTER_bf(const void *const hw, hri_systemcontrol_cpuid_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CPUID;
	tmp = (tmp & SystemControl_CPUID_IMPLEMENTER(mask)) >> 24;
	return tmp;
}

static inline void hri_systemcontrol_write_CPUID_IMPLEMENTER_bf(const void *const             hw,
                                                                hri_systemcontrol_cpuid_reg_t data)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->CPUID;
	tmp &= ~SystemControl_CPUID_IMPLEMENTER_Msk;
	tmp |= SystemControl_CPUID_IMPLEMENTER(data);
	((Systemcontrol *)hw)->CPUID = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_CPUID_IMPLEMENTER_bf(const void *const             hw,
                                                                hri_systemcontrol_cpuid_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CPUID &= ~SystemControl_CPUID_IMPLEMENTER(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_CPUID_IMPLEMENTER_bf(const void *const             hw,
                                                                 hri_systemcontrol_cpuid_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CPUID ^= SystemControl_CPUID_IMPLEMENTER(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_cpuid_reg_t hri_systemcontrol_read_CPUID_IMPLEMENTER_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CPUID;
	tmp = (tmp & SystemControl_CPUID_IMPLEMENTER_Msk) >> 24;
	return tmp;
}

static inline void hri_systemcontrol_set_CPUID_reg(const void *const hw, hri_systemcontrol_cpuid_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CPUID |= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_cpuid_reg_t hri_systemcontrol_get_CPUID_reg(const void *const             hw,
                                                                            hri_systemcontrol_cpuid_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CPUID;
	tmp &= mask;
	return tmp;
}

static inline void hri_systemcontrol_write_CPUID_reg(const void *const hw, hri_systemcontrol_cpuid_reg_t data)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CPUID = data;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_CPUID_reg(const void *const hw, hri_systemcontrol_cpuid_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CPUID &= ~mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_CPUID_reg(const void *const hw, hri_systemcontrol_cpuid_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CPUID ^= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_cpuid_reg_t hri_systemcontrol_read_CPUID_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->CPUID;
}

static inline void hri_systemcontrol_set_ICSR_RETTOBASE_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR |= SystemControl_ICSR_RETTOBASE;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_ICSR_RETTOBASE_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->ICSR;
	tmp = (tmp & SystemControl_ICSR_RETTOBASE) >> 11;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_ICSR_RETTOBASE_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->ICSR;
	tmp &= ~SystemControl_ICSR_RETTOBASE;
	tmp |= value << 11;
	((Systemcontrol *)hw)->ICSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_ICSR_RETTOBASE_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR &= ~SystemControl_ICSR_RETTOBASE;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_ICSR_RETTOBASE_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR ^= SystemControl_ICSR_RETTOBASE;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_ICSR_ISRPENDING_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR |= SystemControl_ICSR_ISRPENDING;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_ICSR_ISRPENDING_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->ICSR;
	tmp = (tmp & SystemControl_ICSR_ISRPENDING) >> 22;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_ICSR_ISRPENDING_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->ICSR;
	tmp &= ~SystemControl_ICSR_ISRPENDING;
	tmp |= value << 22;
	((Systemcontrol *)hw)->ICSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_ICSR_ISRPENDING_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR &= ~SystemControl_ICSR_ISRPENDING;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_ICSR_ISRPENDING_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR ^= SystemControl_ICSR_ISRPENDING;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_ICSR_ISRPREEMPT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR |= SystemControl_ICSR_ISRPREEMPT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_ICSR_ISRPREEMPT_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->ICSR;
	tmp = (tmp & SystemControl_ICSR_ISRPREEMPT) >> 23;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_ICSR_ISRPREEMPT_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->ICSR;
	tmp &= ~SystemControl_ICSR_ISRPREEMPT;
	tmp |= value << 23;
	((Systemcontrol *)hw)->ICSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_ICSR_ISRPREEMPT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR &= ~SystemControl_ICSR_ISRPREEMPT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_ICSR_ISRPREEMPT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR ^= SystemControl_ICSR_ISRPREEMPT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_ICSR_PENDSTCLR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR |= SystemControl_ICSR_PENDSTCLR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_ICSR_PENDSTCLR_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->ICSR;
	tmp = (tmp & SystemControl_ICSR_PENDSTCLR) >> 25;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_ICSR_PENDSTCLR_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->ICSR;
	tmp &= ~SystemControl_ICSR_PENDSTCLR;
	tmp |= value << 25;
	((Systemcontrol *)hw)->ICSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_ICSR_PENDSTCLR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR &= ~SystemControl_ICSR_PENDSTCLR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_ICSR_PENDSTCLR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR ^= SystemControl_ICSR_PENDSTCLR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_ICSR_PENDSTSET_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR |= SystemControl_ICSR_PENDSTSET;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_ICSR_PENDSTSET_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->ICSR;
	tmp = (tmp & SystemControl_ICSR_PENDSTSET) >> 26;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_ICSR_PENDSTSET_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->ICSR;
	tmp &= ~SystemControl_ICSR_PENDSTSET;
	tmp |= value << 26;
	((Systemcontrol *)hw)->ICSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_ICSR_PENDSTSET_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR &= ~SystemControl_ICSR_PENDSTSET;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_ICSR_PENDSTSET_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR ^= SystemControl_ICSR_PENDSTSET;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_ICSR_PENDSVCLR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR |= SystemControl_ICSR_PENDSVCLR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_ICSR_PENDSVCLR_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->ICSR;
	tmp = (tmp & SystemControl_ICSR_PENDSVCLR) >> 27;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_ICSR_PENDSVCLR_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->ICSR;
	tmp &= ~SystemControl_ICSR_PENDSVCLR;
	tmp |= value << 27;
	((Systemcontrol *)hw)->ICSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_ICSR_PENDSVCLR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR &= ~SystemControl_ICSR_PENDSVCLR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_ICSR_PENDSVCLR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR ^= SystemControl_ICSR_PENDSVCLR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_ICSR_PENDSVSET_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR |= SystemControl_ICSR_PENDSVSET;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_ICSR_PENDSVSET_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->ICSR;
	tmp = (tmp & SystemControl_ICSR_PENDSVSET) >> 28;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_ICSR_PENDSVSET_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->ICSR;
	tmp &= ~SystemControl_ICSR_PENDSVSET;
	tmp |= value << 28;
	((Systemcontrol *)hw)->ICSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_ICSR_PENDSVSET_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR &= ~SystemControl_ICSR_PENDSVSET;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_ICSR_PENDSVSET_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR ^= SystemControl_ICSR_PENDSVSET;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_ICSR_NMIPENDSET_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR |= SystemControl_ICSR_NMIPENDSET;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_ICSR_NMIPENDSET_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->ICSR;
	tmp = (tmp & SystemControl_ICSR_NMIPENDSET) >> 31;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_ICSR_NMIPENDSET_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->ICSR;
	tmp &= ~SystemControl_ICSR_NMIPENDSET;
	tmp |= value << 31;
	((Systemcontrol *)hw)->ICSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_ICSR_NMIPENDSET_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR &= ~SystemControl_ICSR_NMIPENDSET;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_ICSR_NMIPENDSET_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR ^= SystemControl_ICSR_NMIPENDSET;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_ICSR_VECTACTIVE_bf(const void *const hw, hri_systemcontrol_icsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR |= SystemControl_ICSR_VECTACTIVE(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_icsr_reg_t hri_systemcontrol_get_ICSR_VECTACTIVE_bf(const void *const            hw,
                                                                                    hri_systemcontrol_icsr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->ICSR;
	tmp = (tmp & SystemControl_ICSR_VECTACTIVE(mask)) >> 0;
	return tmp;
}

static inline void hri_systemcontrol_write_ICSR_VECTACTIVE_bf(const void *const hw, hri_systemcontrol_icsr_reg_t data)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->ICSR;
	tmp &= ~SystemControl_ICSR_VECTACTIVE_Msk;
	tmp |= SystemControl_ICSR_VECTACTIVE(data);
	((Systemcontrol *)hw)->ICSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_ICSR_VECTACTIVE_bf(const void *const hw, hri_systemcontrol_icsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR &= ~SystemControl_ICSR_VECTACTIVE(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_ICSR_VECTACTIVE_bf(const void *const hw, hri_systemcontrol_icsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR ^= SystemControl_ICSR_VECTACTIVE(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_icsr_reg_t hri_systemcontrol_read_ICSR_VECTACTIVE_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->ICSR;
	tmp = (tmp & SystemControl_ICSR_VECTACTIVE_Msk) >> 0;
	return tmp;
}

static inline void hri_systemcontrol_set_ICSR_VECTPENDING_bf(const void *const hw, hri_systemcontrol_icsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR |= SystemControl_ICSR_VECTPENDING(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_icsr_reg_t hri_systemcontrol_get_ICSR_VECTPENDING_bf(const void *const            hw,
                                                                                     hri_systemcontrol_icsr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->ICSR;
	tmp = (tmp & SystemControl_ICSR_VECTPENDING(mask)) >> 12;
	return tmp;
}

static inline void hri_systemcontrol_write_ICSR_VECTPENDING_bf(const void *const hw, hri_systemcontrol_icsr_reg_t data)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->ICSR;
	tmp &= ~SystemControl_ICSR_VECTPENDING_Msk;
	tmp |= SystemControl_ICSR_VECTPENDING(data);
	((Systemcontrol *)hw)->ICSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_ICSR_VECTPENDING_bf(const void *const hw, hri_systemcontrol_icsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR &= ~SystemControl_ICSR_VECTPENDING(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_ICSR_VECTPENDING_bf(const void *const hw, hri_systemcontrol_icsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR ^= SystemControl_ICSR_VECTPENDING(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_icsr_reg_t hri_systemcontrol_read_ICSR_VECTPENDING_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->ICSR;
	tmp = (tmp & SystemControl_ICSR_VECTPENDING_Msk) >> 12;
	return tmp;
}

static inline void hri_systemcontrol_set_ICSR_reg(const void *const hw, hri_systemcontrol_icsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR |= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_icsr_reg_t hri_systemcontrol_get_ICSR_reg(const void *const            hw,
                                                                          hri_systemcontrol_icsr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->ICSR;
	tmp &= mask;
	return tmp;
}

static inline void hri_systemcontrol_write_ICSR_reg(const void *const hw, hri_systemcontrol_icsr_reg_t data)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR = data;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_ICSR_reg(const void *const hw, hri_systemcontrol_icsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR &= ~mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_ICSR_reg(const void *const hw, hri_systemcontrol_icsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR ^= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_icsr_reg_t hri_systemcontrol_read_ICSR_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->ICSR;
}

static inline void hri_systemcontrol_set_VTOR_TBLOFF_bf(const void *const hw, hri_systemcontrol_vtor_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->VTOR |= SystemControl_VTOR_TBLOFF(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_vtor_reg_t hri_systemcontrol_get_VTOR_TBLOFF_bf(const void *const            hw,
                                                                                hri_systemcontrol_vtor_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->VTOR;
	tmp = (tmp & SystemControl_VTOR_TBLOFF(mask)) >> 7;
	return tmp;
}

static inline void hri_systemcontrol_write_VTOR_TBLOFF_bf(const void *const hw, hri_systemcontrol_vtor_reg_t data)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->VTOR;
	tmp &= ~SystemControl_VTOR_TBLOFF_Msk;
	tmp |= SystemControl_VTOR_TBLOFF(data);
	((Systemcontrol *)hw)->VTOR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_VTOR_TBLOFF_bf(const void *const hw, hri_systemcontrol_vtor_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->VTOR &= ~SystemControl_VTOR_TBLOFF(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_VTOR_TBLOFF_bf(const void *const hw, hri_systemcontrol_vtor_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->VTOR ^= SystemControl_VTOR_TBLOFF(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_vtor_reg_t hri_systemcontrol_read_VTOR_TBLOFF_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->VTOR;
	tmp = (tmp & SystemControl_VTOR_TBLOFF_Msk) >> 7;
	return tmp;
}

static inline void hri_systemcontrol_set_VTOR_reg(const void *const hw, hri_systemcontrol_vtor_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->VTOR |= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_vtor_reg_t hri_systemcontrol_get_VTOR_reg(const void *const            hw,
                                                                          hri_systemcontrol_vtor_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->VTOR;
	tmp &= mask;
	return tmp;
}

static inline void hri_systemcontrol_write_VTOR_reg(const void *const hw, hri_systemcontrol_vtor_reg_t data)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->VTOR = data;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_VTOR_reg(const void *const hw, hri_systemcontrol_vtor_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->VTOR &= ~mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_VTOR_reg(const void *const hw, hri_systemcontrol_vtor_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->VTOR ^= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_vtor_reg_t hri_systemcontrol_read_VTOR_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->VTOR;
}

static inline void hri_systemcontrol_set_AIRCR_VECTRESET_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AIRCR |= SystemControl_AIRCR_VECTRESET;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_AIRCR_VECTRESET_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->AIRCR;
	tmp = (tmp & SystemControl_AIRCR_VECTRESET) >> 0;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_AIRCR_VECTRESET_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->AIRCR;
	tmp &= ~SystemControl_AIRCR_VECTRESET;
	tmp |= value << 0;
	((Systemcontrol *)hw)->AIRCR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_AIRCR_VECTRESET_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AIRCR &= ~SystemControl_AIRCR_VECTRESET;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_AIRCR_VECTRESET_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AIRCR ^= SystemControl_AIRCR_VECTRESET;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_AIRCR_VECTCLRACTIVE_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AIRCR |= SystemControl_AIRCR_VECTCLRACTIVE;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_AIRCR_VECTCLRACTIVE_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->AIRCR;
	tmp = (tmp & SystemControl_AIRCR_VECTCLRACTIVE) >> 1;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_AIRCR_VECTCLRACTIVE_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->AIRCR;
	tmp &= ~SystemControl_AIRCR_VECTCLRACTIVE;
	tmp |= value << 1;
	((Systemcontrol *)hw)->AIRCR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_AIRCR_VECTCLRACTIVE_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AIRCR &= ~SystemControl_AIRCR_VECTCLRACTIVE;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_AIRCR_VECTCLRACTIVE_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AIRCR ^= SystemControl_AIRCR_VECTCLRACTIVE;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_AIRCR_SYSRESETREQ_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AIRCR |= SystemControl_AIRCR_SYSRESETREQ;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_AIRCR_SYSRESETREQ_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->AIRCR;
	tmp = (tmp & SystemControl_AIRCR_SYSRESETREQ) >> 2;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_AIRCR_SYSRESETREQ_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->AIRCR;
	tmp &= ~SystemControl_AIRCR_SYSRESETREQ;
	tmp |= value << 2;
	((Systemcontrol *)hw)->AIRCR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_AIRCR_SYSRESETREQ_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AIRCR &= ~SystemControl_AIRCR_SYSRESETREQ;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_AIRCR_SYSRESETREQ_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AIRCR ^= SystemControl_AIRCR_SYSRESETREQ;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_AIRCR_ENDIANNESS_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AIRCR |= SystemControl_AIRCR_ENDIANNESS;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_AIRCR_ENDIANNESS_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->AIRCR;
	tmp = (tmp & SystemControl_AIRCR_ENDIANNESS) >> 15;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_AIRCR_ENDIANNESS_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->AIRCR;
	tmp &= ~SystemControl_AIRCR_ENDIANNESS;
	tmp |= value << 15;
	((Systemcontrol *)hw)->AIRCR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_AIRCR_ENDIANNESS_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AIRCR &= ~SystemControl_AIRCR_ENDIANNESS;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_AIRCR_ENDIANNESS_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AIRCR ^= SystemControl_AIRCR_ENDIANNESS;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_AIRCR_PRIGROUP_bf(const void *const hw, hri_systemcontrol_aircr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AIRCR |= SystemControl_AIRCR_PRIGROUP(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_aircr_reg_t hri_systemcontrol_get_AIRCR_PRIGROUP_bf(const void *const             hw,
                                                                                    hri_systemcontrol_aircr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->AIRCR;
	tmp = (tmp & SystemControl_AIRCR_PRIGROUP(mask)) >> 8;
	return tmp;
}

static inline void hri_systemcontrol_write_AIRCR_PRIGROUP_bf(const void *const hw, hri_systemcontrol_aircr_reg_t data)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->AIRCR;
	tmp &= ~SystemControl_AIRCR_PRIGROUP_Msk;
	tmp |= SystemControl_AIRCR_PRIGROUP(data);
	((Systemcontrol *)hw)->AIRCR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_AIRCR_PRIGROUP_bf(const void *const hw, hri_systemcontrol_aircr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AIRCR &= ~SystemControl_AIRCR_PRIGROUP(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_AIRCR_PRIGROUP_bf(const void *const hw, hri_systemcontrol_aircr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AIRCR ^= SystemControl_AIRCR_PRIGROUP(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_aircr_reg_t hri_systemcontrol_read_AIRCR_PRIGROUP_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->AIRCR;
	tmp = (tmp & SystemControl_AIRCR_PRIGROUP_Msk) >> 8;
	return tmp;
}

static inline void hri_systemcontrol_set_AIRCR_VECTKEY_bf(const void *const hw, hri_systemcontrol_aircr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AIRCR |= SystemControl_AIRCR_VECTKEY(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_aircr_reg_t hri_systemcontrol_get_AIRCR_VECTKEY_bf(const void *const             hw,
                                                                                   hri_systemcontrol_aircr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->AIRCR;
	tmp = (tmp & SystemControl_AIRCR_VECTKEY(mask)) >> 16;
	return tmp;
}

static inline void hri_systemcontrol_write_AIRCR_VECTKEY_bf(const void *const hw, hri_systemcontrol_aircr_reg_t data)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->AIRCR;
	tmp &= ~SystemControl_AIRCR_VECTKEY_Msk;
	tmp |= SystemControl_AIRCR_VECTKEY(data);
	((Systemcontrol *)hw)->AIRCR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_AIRCR_VECTKEY_bf(const void *const hw, hri_systemcontrol_aircr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AIRCR &= ~SystemControl_AIRCR_VECTKEY(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_AIRCR_VECTKEY_bf(const void *const hw, hri_systemcontrol_aircr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AIRCR ^= SystemControl_AIRCR_VECTKEY(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_aircr_reg_t hri_systemcontrol_read_AIRCR_VECTKEY_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->AIRCR;
	tmp = (tmp & SystemControl_AIRCR_VECTKEY_Msk) >> 16;
	return tmp;
}

static inline void hri_systemcontrol_set_AIRCR_reg(const void *const hw, hri_systemcontrol_aircr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AIRCR |= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_aircr_reg_t hri_systemcontrol_get_AIRCR_reg(const void *const             hw,
                                                                            hri_systemcontrol_aircr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->AIRCR;
	tmp &= mask;
	return tmp;
}

static inline void hri_systemcontrol_write_AIRCR_reg(const void *const hw, hri_systemcontrol_aircr_reg_t data)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AIRCR = data;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_AIRCR_reg(const void *const hw, hri_systemcontrol_aircr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AIRCR &= ~mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_AIRCR_reg(const void *const hw, hri_systemcontrol_aircr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AIRCR ^= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_aircr_reg_t hri_systemcontrol_read_AIRCR_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->AIRCR;
}

static inline void hri_systemcontrol_set_SCR_SLEEPONEXIT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SCR |= SystemControl_SCR_SLEEPONEXIT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_SCR_SLEEPONEXIT_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SCR;
	tmp = (tmp & SystemControl_SCR_SLEEPONEXIT) >> 1;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_SCR_SLEEPONEXIT_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->SCR;
	tmp &= ~SystemControl_SCR_SLEEPONEXIT;
	tmp |= value << 1;
	((Systemcontrol *)hw)->SCR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_SCR_SLEEPONEXIT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SCR &= ~SystemControl_SCR_SLEEPONEXIT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_SCR_SLEEPONEXIT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SCR ^= SystemControl_SCR_SLEEPONEXIT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_SCR_SLEEPDEEP_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SCR |= SystemControl_SCR_SLEEPDEEP;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_SCR_SLEEPDEEP_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SCR;
	tmp = (tmp & SystemControl_SCR_SLEEPDEEP) >> 2;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_SCR_SLEEPDEEP_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->SCR;
	tmp &= ~SystemControl_SCR_SLEEPDEEP;
	tmp |= value << 2;
	((Systemcontrol *)hw)->SCR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_SCR_SLEEPDEEP_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SCR &= ~SystemControl_SCR_SLEEPDEEP;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_SCR_SLEEPDEEP_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SCR ^= SystemControl_SCR_SLEEPDEEP;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_SCR_SEVONPEND_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SCR |= SystemControl_SCR_SEVONPEND;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_SCR_SEVONPEND_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SCR;
	tmp = (tmp & SystemControl_SCR_SEVONPEND) >> 4;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_SCR_SEVONPEND_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->SCR;
	tmp &= ~SystemControl_SCR_SEVONPEND;
	tmp |= value << 4;
	((Systemcontrol *)hw)->SCR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_SCR_SEVONPEND_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SCR &= ~SystemControl_SCR_SEVONPEND;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_SCR_SEVONPEND_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SCR ^= SystemControl_SCR_SEVONPEND;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_SCR_reg(const void *const hw, hri_systemcontrol_scr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SCR |= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_scr_reg_t hri_systemcontrol_get_SCR_reg(const void *const           hw,
                                                                        hri_systemcontrol_scr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SCR;
	tmp &= mask;
	return tmp;
}

static inline void hri_systemcontrol_write_SCR_reg(const void *const hw, hri_systemcontrol_scr_reg_t data)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SCR = data;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_SCR_reg(const void *const hw, hri_systemcontrol_scr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SCR &= ~mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_SCR_reg(const void *const hw, hri_systemcontrol_scr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SCR ^= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_scr_reg_t hri_systemcontrol_read_SCR_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->SCR;
}

static inline void hri_systemcontrol_set_CCR_NONBASETHRDENA_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CCR |= SystemControl_CCR_NONBASETHRDENA;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_CCR_NONBASETHRDENA_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CCR;
	tmp = (tmp & SystemControl_CCR_NONBASETHRDENA) >> 0;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_CCR_NONBASETHRDENA_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->CCR;
	tmp &= ~SystemControl_CCR_NONBASETHRDENA;
	tmp |= value << 0;
	((Systemcontrol *)hw)->CCR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_CCR_NONBASETHRDENA_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CCR &= ~SystemControl_CCR_NONBASETHRDENA;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_CCR_NONBASETHRDENA_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CCR ^= SystemControl_CCR_NONBASETHRDENA;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_CCR_USERSETMPEND_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CCR |= SystemControl_CCR_USERSETMPEND;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_CCR_USERSETMPEND_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CCR;
	tmp = (tmp & SystemControl_CCR_USERSETMPEND) >> 1;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_CCR_USERSETMPEND_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->CCR;
	tmp &= ~SystemControl_CCR_USERSETMPEND;
	tmp |= value << 1;
	((Systemcontrol *)hw)->CCR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_CCR_USERSETMPEND_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CCR &= ~SystemControl_CCR_USERSETMPEND;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_CCR_USERSETMPEND_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CCR ^= SystemControl_CCR_USERSETMPEND;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_CCR_UNALIGN_TRP_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CCR |= SystemControl_CCR_UNALIGN_TRP;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_CCR_UNALIGN_TRP_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CCR;
	tmp = (tmp & SystemControl_CCR_UNALIGN_TRP) >> 3;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_CCR_UNALIGN_TRP_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->CCR;
	tmp &= ~SystemControl_CCR_UNALIGN_TRP;
	tmp |= value << 3;
	((Systemcontrol *)hw)->CCR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_CCR_UNALIGN_TRP_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CCR &= ~SystemControl_CCR_UNALIGN_TRP;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_CCR_UNALIGN_TRP_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CCR ^= SystemControl_CCR_UNALIGN_TRP;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_CCR_DIV_0_TRP_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CCR |= SystemControl_CCR_DIV_0_TRP;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_CCR_DIV_0_TRP_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CCR;
	tmp = (tmp & SystemControl_CCR_DIV_0_TRP) >> 4;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_CCR_DIV_0_TRP_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->CCR;
	tmp &= ~SystemControl_CCR_DIV_0_TRP;
	tmp |= value << 4;
	((Systemcontrol *)hw)->CCR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_CCR_DIV_0_TRP_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CCR &= ~SystemControl_CCR_DIV_0_TRP;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_CCR_DIV_0_TRP_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CCR ^= SystemControl_CCR_DIV_0_TRP;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_CCR_BFHFNMIGN_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CCR |= SystemControl_CCR_BFHFNMIGN;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_CCR_BFHFNMIGN_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CCR;
	tmp = (tmp & SystemControl_CCR_BFHFNMIGN) >> 8;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_CCR_BFHFNMIGN_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->CCR;
	tmp &= ~SystemControl_CCR_BFHFNMIGN;
	tmp |= value << 8;
	((Systemcontrol *)hw)->CCR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_CCR_BFHFNMIGN_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CCR &= ~SystemControl_CCR_BFHFNMIGN;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_CCR_BFHFNMIGN_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CCR ^= SystemControl_CCR_BFHFNMIGN;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_CCR_STKALIGN_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CCR |= SystemControl_CCR_STKALIGN;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_CCR_STKALIGN_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CCR;
	tmp = (tmp & SystemControl_CCR_STKALIGN) >> 9;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_CCR_STKALIGN_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->CCR;
	tmp &= ~SystemControl_CCR_STKALIGN;
	tmp |= value << 9;
	((Systemcontrol *)hw)->CCR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_CCR_STKALIGN_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CCR &= ~SystemControl_CCR_STKALIGN;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_CCR_STKALIGN_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CCR ^= SystemControl_CCR_STKALIGN;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_CCR_reg(const void *const hw, hri_systemcontrol_ccr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CCR |= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_ccr_reg_t hri_systemcontrol_get_CCR_reg(const void *const           hw,
                                                                        hri_systemcontrol_ccr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CCR;
	tmp &= mask;
	return tmp;
}

static inline void hri_systemcontrol_write_CCR_reg(const void *const hw, hri_systemcontrol_ccr_reg_t data)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CCR = data;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_CCR_reg(const void *const hw, hri_systemcontrol_ccr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CCR &= ~mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_CCR_reg(const void *const hw, hri_systemcontrol_ccr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CCR ^= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_ccr_reg_t hri_systemcontrol_read_CCR_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->CCR;
}

static inline void hri_systemcontrol_set_SHPR1_PRI_4_bf(const void *const hw, hri_systemcontrol_shpr1_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR1 |= SystemControl_SHPR1_PRI_4(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_shpr1_reg_t hri_systemcontrol_get_SHPR1_PRI_4_bf(const void *const             hw,
                                                                                 hri_systemcontrol_shpr1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SHPR1;
	tmp = (tmp & SystemControl_SHPR1_PRI_4(mask)) >> 0;
	return tmp;
}

static inline void hri_systemcontrol_write_SHPR1_PRI_4_bf(const void *const hw, hri_systemcontrol_shpr1_reg_t data)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->SHPR1;
	tmp &= ~SystemControl_SHPR1_PRI_4_Msk;
	tmp |= SystemControl_SHPR1_PRI_4(data);
	((Systemcontrol *)hw)->SHPR1 = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_SHPR1_PRI_4_bf(const void *const hw, hri_systemcontrol_shpr1_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR1 &= ~SystemControl_SHPR1_PRI_4(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_SHPR1_PRI_4_bf(const void *const hw, hri_systemcontrol_shpr1_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR1 ^= SystemControl_SHPR1_PRI_4(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_shpr1_reg_t hri_systemcontrol_read_SHPR1_PRI_4_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SHPR1;
	tmp = (tmp & SystemControl_SHPR1_PRI_4_Msk) >> 0;
	return tmp;
}

static inline void hri_systemcontrol_set_SHPR1_PRI_5_bf(const void *const hw, hri_systemcontrol_shpr1_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR1 |= SystemControl_SHPR1_PRI_5(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_shpr1_reg_t hri_systemcontrol_get_SHPR1_PRI_5_bf(const void *const             hw,
                                                                                 hri_systemcontrol_shpr1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SHPR1;
	tmp = (tmp & SystemControl_SHPR1_PRI_5(mask)) >> 8;
	return tmp;
}

static inline void hri_systemcontrol_write_SHPR1_PRI_5_bf(const void *const hw, hri_systemcontrol_shpr1_reg_t data)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->SHPR1;
	tmp &= ~SystemControl_SHPR1_PRI_5_Msk;
	tmp |= SystemControl_SHPR1_PRI_5(data);
	((Systemcontrol *)hw)->SHPR1 = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_SHPR1_PRI_5_bf(const void *const hw, hri_systemcontrol_shpr1_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR1 &= ~SystemControl_SHPR1_PRI_5(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_SHPR1_PRI_5_bf(const void *const hw, hri_systemcontrol_shpr1_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR1 ^= SystemControl_SHPR1_PRI_5(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_shpr1_reg_t hri_systemcontrol_read_SHPR1_PRI_5_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SHPR1;
	tmp = (tmp & SystemControl_SHPR1_PRI_5_Msk) >> 8;
	return tmp;
}

static inline void hri_systemcontrol_set_SHPR1_PRI_6_bf(const void *const hw, hri_systemcontrol_shpr1_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR1 |= SystemControl_SHPR1_PRI_6(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_shpr1_reg_t hri_systemcontrol_get_SHPR1_PRI_6_bf(const void *const             hw,
                                                                                 hri_systemcontrol_shpr1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SHPR1;
	tmp = (tmp & SystemControl_SHPR1_PRI_6(mask)) >> 16;
	return tmp;
}

static inline void hri_systemcontrol_write_SHPR1_PRI_6_bf(const void *const hw, hri_systemcontrol_shpr1_reg_t data)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->SHPR1;
	tmp &= ~SystemControl_SHPR1_PRI_6_Msk;
	tmp |= SystemControl_SHPR1_PRI_6(data);
	((Systemcontrol *)hw)->SHPR1 = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_SHPR1_PRI_6_bf(const void *const hw, hri_systemcontrol_shpr1_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR1 &= ~SystemControl_SHPR1_PRI_6(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_SHPR1_PRI_6_bf(const void *const hw, hri_systemcontrol_shpr1_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR1 ^= SystemControl_SHPR1_PRI_6(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_shpr1_reg_t hri_systemcontrol_read_SHPR1_PRI_6_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SHPR1;
	tmp = (tmp & SystemControl_SHPR1_PRI_6_Msk) >> 16;
	return tmp;
}

static inline void hri_systemcontrol_set_SHPR1_reg(const void *const hw, hri_systemcontrol_shpr1_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR1 |= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_shpr1_reg_t hri_systemcontrol_get_SHPR1_reg(const void *const             hw,
                                                                            hri_systemcontrol_shpr1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SHPR1;
	tmp &= mask;
	return tmp;
}

static inline void hri_systemcontrol_write_SHPR1_reg(const void *const hw, hri_systemcontrol_shpr1_reg_t data)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR1 = data;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_SHPR1_reg(const void *const hw, hri_systemcontrol_shpr1_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR1 &= ~mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_SHPR1_reg(const void *const hw, hri_systemcontrol_shpr1_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR1 ^= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_shpr1_reg_t hri_systemcontrol_read_SHPR1_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->SHPR1;
}

static inline void hri_systemcontrol_set_SHPR2_PRI_11_bf(const void *const hw, hri_systemcontrol_shpr2_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR2 |= SystemControl_SHPR2_PRI_11(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_shpr2_reg_t hri_systemcontrol_get_SHPR2_PRI_11_bf(const void *const             hw,
                                                                                  hri_systemcontrol_shpr2_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SHPR2;
	tmp = (tmp & SystemControl_SHPR2_PRI_11(mask)) >> 24;
	return tmp;
}

static inline void hri_systemcontrol_write_SHPR2_PRI_11_bf(const void *const hw, hri_systemcontrol_shpr2_reg_t data)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->SHPR2;
	tmp &= ~SystemControl_SHPR2_PRI_11_Msk;
	tmp |= SystemControl_SHPR2_PRI_11(data);
	((Systemcontrol *)hw)->SHPR2 = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_SHPR2_PRI_11_bf(const void *const hw, hri_systemcontrol_shpr2_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR2 &= ~SystemControl_SHPR2_PRI_11(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_SHPR2_PRI_11_bf(const void *const hw, hri_systemcontrol_shpr2_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR2 ^= SystemControl_SHPR2_PRI_11(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_shpr2_reg_t hri_systemcontrol_read_SHPR2_PRI_11_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SHPR2;
	tmp = (tmp & SystemControl_SHPR2_PRI_11_Msk) >> 24;
	return tmp;
}

static inline void hri_systemcontrol_set_SHPR2_reg(const void *const hw, hri_systemcontrol_shpr2_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR2 |= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_shpr2_reg_t hri_systemcontrol_get_SHPR2_reg(const void *const             hw,
                                                                            hri_systemcontrol_shpr2_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SHPR2;
	tmp &= mask;
	return tmp;
}

static inline void hri_systemcontrol_write_SHPR2_reg(const void *const hw, hri_systemcontrol_shpr2_reg_t data)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR2 = data;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_SHPR2_reg(const void *const hw, hri_systemcontrol_shpr2_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR2 &= ~mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_SHPR2_reg(const void *const hw, hri_systemcontrol_shpr2_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR2 ^= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_shpr2_reg_t hri_systemcontrol_read_SHPR2_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->SHPR2;
}

static inline void hri_systemcontrol_set_SHPR3_PRI_14_bf(const void *const hw, hri_systemcontrol_shpr3_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR3 |= SystemControl_SHPR3_PRI_14(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_shpr3_reg_t hri_systemcontrol_get_SHPR3_PRI_14_bf(const void *const             hw,
                                                                                  hri_systemcontrol_shpr3_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SHPR3;
	tmp = (tmp & SystemControl_SHPR3_PRI_14(mask)) >> 16;
	return tmp;
}

static inline void hri_systemcontrol_write_SHPR3_PRI_14_bf(const void *const hw, hri_systemcontrol_shpr3_reg_t data)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->SHPR3;
	tmp &= ~SystemControl_SHPR3_PRI_14_Msk;
	tmp |= SystemControl_SHPR3_PRI_14(data);
	((Systemcontrol *)hw)->SHPR3 = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_SHPR3_PRI_14_bf(const void *const hw, hri_systemcontrol_shpr3_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR3 &= ~SystemControl_SHPR3_PRI_14(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_SHPR3_PRI_14_bf(const void *const hw, hri_systemcontrol_shpr3_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR3 ^= SystemControl_SHPR3_PRI_14(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_shpr3_reg_t hri_systemcontrol_read_SHPR3_PRI_14_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SHPR3;
	tmp = (tmp & SystemControl_SHPR3_PRI_14_Msk) >> 16;
	return tmp;
}

static inline void hri_systemcontrol_set_SHPR3_PRI_15_bf(const void *const hw, hri_systemcontrol_shpr3_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR3 |= SystemControl_SHPR3_PRI_15(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_shpr3_reg_t hri_systemcontrol_get_SHPR3_PRI_15_bf(const void *const             hw,
                                                                                  hri_systemcontrol_shpr3_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SHPR3;
	tmp = (tmp & SystemControl_SHPR3_PRI_15(mask)) >> 24;
	return tmp;
}

static inline void hri_systemcontrol_write_SHPR3_PRI_15_bf(const void *const hw, hri_systemcontrol_shpr3_reg_t data)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->SHPR3;
	tmp &= ~SystemControl_SHPR3_PRI_15_Msk;
	tmp |= SystemControl_SHPR3_PRI_15(data);
	((Systemcontrol *)hw)->SHPR3 = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_SHPR3_PRI_15_bf(const void *const hw, hri_systemcontrol_shpr3_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR3 &= ~SystemControl_SHPR3_PRI_15(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_SHPR3_PRI_15_bf(const void *const hw, hri_systemcontrol_shpr3_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR3 ^= SystemControl_SHPR3_PRI_15(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_shpr3_reg_t hri_systemcontrol_read_SHPR3_PRI_15_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SHPR3;
	tmp = (tmp & SystemControl_SHPR3_PRI_15_Msk) >> 24;
	return tmp;
}

static inline void hri_systemcontrol_set_SHPR3_reg(const void *const hw, hri_systemcontrol_shpr3_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR3 |= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_shpr3_reg_t hri_systemcontrol_get_SHPR3_reg(const void *const             hw,
                                                                            hri_systemcontrol_shpr3_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SHPR3;
	tmp &= mask;
	return tmp;
}

static inline void hri_systemcontrol_write_SHPR3_reg(const void *const hw, hri_systemcontrol_shpr3_reg_t data)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR3 = data;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_SHPR3_reg(const void *const hw, hri_systemcontrol_shpr3_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR3 &= ~mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_SHPR3_reg(const void *const hw, hri_systemcontrol_shpr3_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR3 ^= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_shpr3_reg_t hri_systemcontrol_read_SHPR3_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->SHPR3;
}

static inline void hri_systemcontrol_set_SHCSR_MEMFAULTACT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR |= SystemControl_SHCSR_MEMFAULTACT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_SHCSR_MEMFAULTACT_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SHCSR;
	tmp = (tmp & SystemControl_SHCSR_MEMFAULTACT) >> 0;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_SHCSR_MEMFAULTACT_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->SHCSR;
	tmp &= ~SystemControl_SHCSR_MEMFAULTACT;
	tmp |= value << 0;
	((Systemcontrol *)hw)->SHCSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_SHCSR_MEMFAULTACT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR &= ~SystemControl_SHCSR_MEMFAULTACT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_SHCSR_MEMFAULTACT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR ^= SystemControl_SHCSR_MEMFAULTACT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_SHCSR_BUSFAULTACT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR |= SystemControl_SHCSR_BUSFAULTACT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_SHCSR_BUSFAULTACT_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SHCSR;
	tmp = (tmp & SystemControl_SHCSR_BUSFAULTACT) >> 1;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_SHCSR_BUSFAULTACT_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->SHCSR;
	tmp &= ~SystemControl_SHCSR_BUSFAULTACT;
	tmp |= value << 1;
	((Systemcontrol *)hw)->SHCSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_SHCSR_BUSFAULTACT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR &= ~SystemControl_SHCSR_BUSFAULTACT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_SHCSR_BUSFAULTACT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR ^= SystemControl_SHCSR_BUSFAULTACT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_SHCSR_USGFAULTACT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR |= SystemControl_SHCSR_USGFAULTACT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_SHCSR_USGFAULTACT_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SHCSR;
	tmp = (tmp & SystemControl_SHCSR_USGFAULTACT) >> 3;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_SHCSR_USGFAULTACT_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->SHCSR;
	tmp &= ~SystemControl_SHCSR_USGFAULTACT;
	tmp |= value << 3;
	((Systemcontrol *)hw)->SHCSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_SHCSR_USGFAULTACT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR &= ~SystemControl_SHCSR_USGFAULTACT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_SHCSR_USGFAULTACT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR ^= SystemControl_SHCSR_USGFAULTACT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_SHCSR_SVCALLACT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR |= SystemControl_SHCSR_SVCALLACT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_SHCSR_SVCALLACT_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SHCSR;
	tmp = (tmp & SystemControl_SHCSR_SVCALLACT) >> 7;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_SHCSR_SVCALLACT_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->SHCSR;
	tmp &= ~SystemControl_SHCSR_SVCALLACT;
	tmp |= value << 7;
	((Systemcontrol *)hw)->SHCSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_SHCSR_SVCALLACT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR &= ~SystemControl_SHCSR_SVCALLACT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_SHCSR_SVCALLACT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR ^= SystemControl_SHCSR_SVCALLACT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_SHCSR_MONITORACT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR |= SystemControl_SHCSR_MONITORACT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_SHCSR_MONITORACT_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SHCSR;
	tmp = (tmp & SystemControl_SHCSR_MONITORACT) >> 8;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_SHCSR_MONITORACT_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->SHCSR;
	tmp &= ~SystemControl_SHCSR_MONITORACT;
	tmp |= value << 8;
	((Systemcontrol *)hw)->SHCSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_SHCSR_MONITORACT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR &= ~SystemControl_SHCSR_MONITORACT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_SHCSR_MONITORACT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR ^= SystemControl_SHCSR_MONITORACT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_SHCSR_PENDSVACT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR |= SystemControl_SHCSR_PENDSVACT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_SHCSR_PENDSVACT_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SHCSR;
	tmp = (tmp & SystemControl_SHCSR_PENDSVACT) >> 10;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_SHCSR_PENDSVACT_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->SHCSR;
	tmp &= ~SystemControl_SHCSR_PENDSVACT;
	tmp |= value << 10;
	((Systemcontrol *)hw)->SHCSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_SHCSR_PENDSVACT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR &= ~SystemControl_SHCSR_PENDSVACT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_SHCSR_PENDSVACT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR ^= SystemControl_SHCSR_PENDSVACT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_SHCSR_SYSTICKACT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR |= SystemControl_SHCSR_SYSTICKACT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_SHCSR_SYSTICKACT_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SHCSR;
	tmp = (tmp & SystemControl_SHCSR_SYSTICKACT) >> 11;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_SHCSR_SYSTICKACT_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->SHCSR;
	tmp &= ~SystemControl_SHCSR_SYSTICKACT;
	tmp |= value << 11;
	((Systemcontrol *)hw)->SHCSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_SHCSR_SYSTICKACT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR &= ~SystemControl_SHCSR_SYSTICKACT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_SHCSR_SYSTICKACT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR ^= SystemControl_SHCSR_SYSTICKACT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_SHCSR_USGFAULTPENDED_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR |= SystemControl_SHCSR_USGFAULTPENDED;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_SHCSR_USGFAULTPENDED_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SHCSR;
	tmp = (tmp & SystemControl_SHCSR_USGFAULTPENDED) >> 12;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_SHCSR_USGFAULTPENDED_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->SHCSR;
	tmp &= ~SystemControl_SHCSR_USGFAULTPENDED;
	tmp |= value << 12;
	((Systemcontrol *)hw)->SHCSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_SHCSR_USGFAULTPENDED_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR &= ~SystemControl_SHCSR_USGFAULTPENDED;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_SHCSR_USGFAULTPENDED_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR ^= SystemControl_SHCSR_USGFAULTPENDED;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_SHCSR_MEMFAULTPENDED_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR |= SystemControl_SHCSR_MEMFAULTPENDED;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_SHCSR_MEMFAULTPENDED_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SHCSR;
	tmp = (tmp & SystemControl_SHCSR_MEMFAULTPENDED) >> 13;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_SHCSR_MEMFAULTPENDED_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->SHCSR;
	tmp &= ~SystemControl_SHCSR_MEMFAULTPENDED;
	tmp |= value << 13;
	((Systemcontrol *)hw)->SHCSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_SHCSR_MEMFAULTPENDED_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR &= ~SystemControl_SHCSR_MEMFAULTPENDED;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_SHCSR_MEMFAULTPENDED_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR ^= SystemControl_SHCSR_MEMFAULTPENDED;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_SHCSR_BUSFAULTPENDED_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR |= SystemControl_SHCSR_BUSFAULTPENDED;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_SHCSR_BUSFAULTPENDED_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SHCSR;
	tmp = (tmp & SystemControl_SHCSR_BUSFAULTPENDED) >> 14;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_SHCSR_BUSFAULTPENDED_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->SHCSR;
	tmp &= ~SystemControl_SHCSR_BUSFAULTPENDED;
	tmp |= value << 14;
	((Systemcontrol *)hw)->SHCSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_SHCSR_BUSFAULTPENDED_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR &= ~SystemControl_SHCSR_BUSFAULTPENDED;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_SHCSR_BUSFAULTPENDED_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR ^= SystemControl_SHCSR_BUSFAULTPENDED;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_SHCSR_SVCALLPENDED_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR |= SystemControl_SHCSR_SVCALLPENDED;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_SHCSR_SVCALLPENDED_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SHCSR;
	tmp = (tmp & SystemControl_SHCSR_SVCALLPENDED) >> 15;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_SHCSR_SVCALLPENDED_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->SHCSR;
	tmp &= ~SystemControl_SHCSR_SVCALLPENDED;
	tmp |= value << 15;
	((Systemcontrol *)hw)->SHCSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_SHCSR_SVCALLPENDED_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR &= ~SystemControl_SHCSR_SVCALLPENDED;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_SHCSR_SVCALLPENDED_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR ^= SystemControl_SHCSR_SVCALLPENDED;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_SHCSR_MEMFAULTENA_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR |= SystemControl_SHCSR_MEMFAULTENA;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_SHCSR_MEMFAULTENA_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SHCSR;
	tmp = (tmp & SystemControl_SHCSR_MEMFAULTENA) >> 16;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_SHCSR_MEMFAULTENA_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->SHCSR;
	tmp &= ~SystemControl_SHCSR_MEMFAULTENA;
	tmp |= value << 16;
	((Systemcontrol *)hw)->SHCSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_SHCSR_MEMFAULTENA_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR &= ~SystemControl_SHCSR_MEMFAULTENA;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_SHCSR_MEMFAULTENA_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR ^= SystemControl_SHCSR_MEMFAULTENA;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_SHCSR_BUSFAULTENA_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR |= SystemControl_SHCSR_BUSFAULTENA;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_SHCSR_BUSFAULTENA_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SHCSR;
	tmp = (tmp & SystemControl_SHCSR_BUSFAULTENA) >> 17;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_SHCSR_BUSFAULTENA_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->SHCSR;
	tmp &= ~SystemControl_SHCSR_BUSFAULTENA;
	tmp |= value << 17;
	((Systemcontrol *)hw)->SHCSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_SHCSR_BUSFAULTENA_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR &= ~SystemControl_SHCSR_BUSFAULTENA;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_SHCSR_BUSFAULTENA_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR ^= SystemControl_SHCSR_BUSFAULTENA;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_SHCSR_USGFAULTENA_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR |= SystemControl_SHCSR_USGFAULTENA;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_SHCSR_USGFAULTENA_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SHCSR;
	tmp = (tmp & SystemControl_SHCSR_USGFAULTENA) >> 18;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_SHCSR_USGFAULTENA_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->SHCSR;
	tmp &= ~SystemControl_SHCSR_USGFAULTENA;
	tmp |= value << 18;
	((Systemcontrol *)hw)->SHCSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_SHCSR_USGFAULTENA_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR &= ~SystemControl_SHCSR_USGFAULTENA;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_SHCSR_USGFAULTENA_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR ^= SystemControl_SHCSR_USGFAULTENA;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_SHCSR_reg(const void *const hw, hri_systemcontrol_shcsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR |= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_shcsr_reg_t hri_systemcontrol_get_SHCSR_reg(const void *const             hw,
                                                                            hri_systemcontrol_shcsr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SHCSR;
	tmp &= mask;
	return tmp;
}

static inline void hri_systemcontrol_write_SHCSR_reg(const void *const hw, hri_systemcontrol_shcsr_reg_t data)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR = data;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_SHCSR_reg(const void *const hw, hri_systemcontrol_shcsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR &= ~mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_SHCSR_reg(const void *const hw, hri_systemcontrol_shcsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR ^= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_shcsr_reg_t hri_systemcontrol_read_SHCSR_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->SHCSR;
}

static inline void hri_systemcontrol_set_CFSR_IACCVIOL_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR |= SystemControl_CFSR_IACCVIOL;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_CFSR_IACCVIOL_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp = (tmp & SystemControl_CFSR_IACCVIOL) >> 0;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_CFSR_IACCVIOL_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp &= ~SystemControl_CFSR_IACCVIOL;
	tmp |= value << 0;
	((Systemcontrol *)hw)->CFSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_CFSR_IACCVIOL_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR &= ~SystemControl_CFSR_IACCVIOL;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_CFSR_IACCVIOL_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR ^= SystemControl_CFSR_IACCVIOL;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_CFSR_DACCVIOL_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR |= SystemControl_CFSR_DACCVIOL;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_CFSR_DACCVIOL_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp = (tmp & SystemControl_CFSR_DACCVIOL) >> 1;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_CFSR_DACCVIOL_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp &= ~SystemControl_CFSR_DACCVIOL;
	tmp |= value << 1;
	((Systemcontrol *)hw)->CFSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_CFSR_DACCVIOL_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR &= ~SystemControl_CFSR_DACCVIOL;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_CFSR_DACCVIOL_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR ^= SystemControl_CFSR_DACCVIOL;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_CFSR_MUNSTKERR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR |= SystemControl_CFSR_MUNSTKERR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_CFSR_MUNSTKERR_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp = (tmp & SystemControl_CFSR_MUNSTKERR) >> 3;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_CFSR_MUNSTKERR_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp &= ~SystemControl_CFSR_MUNSTKERR;
	tmp |= value << 3;
	((Systemcontrol *)hw)->CFSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_CFSR_MUNSTKERR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR &= ~SystemControl_CFSR_MUNSTKERR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_CFSR_MUNSTKERR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR ^= SystemControl_CFSR_MUNSTKERR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_CFSR_MSTKERR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR |= SystemControl_CFSR_MSTKERR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_CFSR_MSTKERR_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp = (tmp & SystemControl_CFSR_MSTKERR) >> 4;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_CFSR_MSTKERR_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp &= ~SystemControl_CFSR_MSTKERR;
	tmp |= value << 4;
	((Systemcontrol *)hw)->CFSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_CFSR_MSTKERR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR &= ~SystemControl_CFSR_MSTKERR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_CFSR_MSTKERR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR ^= SystemControl_CFSR_MSTKERR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_CFSR_MLSPERR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR |= SystemControl_CFSR_MLSPERR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_CFSR_MLSPERR_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp = (tmp & SystemControl_CFSR_MLSPERR) >> 5;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_CFSR_MLSPERR_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp &= ~SystemControl_CFSR_MLSPERR;
	tmp |= value << 5;
	((Systemcontrol *)hw)->CFSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_CFSR_MLSPERR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR &= ~SystemControl_CFSR_MLSPERR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_CFSR_MLSPERR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR ^= SystemControl_CFSR_MLSPERR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_CFSR_MMARVALID_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR |= SystemControl_CFSR_MMARVALID;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_CFSR_MMARVALID_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp = (tmp & SystemControl_CFSR_MMARVALID) >> 7;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_CFSR_MMARVALID_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp &= ~SystemControl_CFSR_MMARVALID;
	tmp |= value << 7;
	((Systemcontrol *)hw)->CFSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_CFSR_MMARVALID_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR &= ~SystemControl_CFSR_MMARVALID;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_CFSR_MMARVALID_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR ^= SystemControl_CFSR_MMARVALID;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_CFSR_IBUSERR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR |= SystemControl_CFSR_IBUSERR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_CFSR_IBUSERR_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp = (tmp & SystemControl_CFSR_IBUSERR) >> 8;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_CFSR_IBUSERR_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp &= ~SystemControl_CFSR_IBUSERR;
	tmp |= value << 8;
	((Systemcontrol *)hw)->CFSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_CFSR_IBUSERR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR &= ~SystemControl_CFSR_IBUSERR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_CFSR_IBUSERR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR ^= SystemControl_CFSR_IBUSERR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_CFSR_PRECISERR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR |= SystemControl_CFSR_PRECISERR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_CFSR_PRECISERR_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp = (tmp & SystemControl_CFSR_PRECISERR) >> 9;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_CFSR_PRECISERR_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp &= ~SystemControl_CFSR_PRECISERR;
	tmp |= value << 9;
	((Systemcontrol *)hw)->CFSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_CFSR_PRECISERR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR &= ~SystemControl_CFSR_PRECISERR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_CFSR_PRECISERR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR ^= SystemControl_CFSR_PRECISERR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_CFSR_IMPRECISERR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR |= SystemControl_CFSR_IMPRECISERR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_CFSR_IMPRECISERR_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp = (tmp & SystemControl_CFSR_IMPRECISERR) >> 10;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_CFSR_IMPRECISERR_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp &= ~SystemControl_CFSR_IMPRECISERR;
	tmp |= value << 10;
	((Systemcontrol *)hw)->CFSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_CFSR_IMPRECISERR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR &= ~SystemControl_CFSR_IMPRECISERR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_CFSR_IMPRECISERR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR ^= SystemControl_CFSR_IMPRECISERR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_CFSR_UNSTKERR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR |= SystemControl_CFSR_UNSTKERR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_CFSR_UNSTKERR_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp = (tmp & SystemControl_CFSR_UNSTKERR) >> 11;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_CFSR_UNSTKERR_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp &= ~SystemControl_CFSR_UNSTKERR;
	tmp |= value << 11;
	((Systemcontrol *)hw)->CFSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_CFSR_UNSTKERR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR &= ~SystemControl_CFSR_UNSTKERR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_CFSR_UNSTKERR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR ^= SystemControl_CFSR_UNSTKERR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_CFSR_STKERR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR |= SystemControl_CFSR_STKERR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_CFSR_STKERR_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp = (tmp & SystemControl_CFSR_STKERR) >> 12;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_CFSR_STKERR_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp &= ~SystemControl_CFSR_STKERR;
	tmp |= value << 12;
	((Systemcontrol *)hw)->CFSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_CFSR_STKERR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR &= ~SystemControl_CFSR_STKERR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_CFSR_STKERR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR ^= SystemControl_CFSR_STKERR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_CFSR_LSPERR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR |= SystemControl_CFSR_LSPERR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_CFSR_LSPERR_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp = (tmp & SystemControl_CFSR_LSPERR) >> 13;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_CFSR_LSPERR_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp &= ~SystemControl_CFSR_LSPERR;
	tmp |= value << 13;
	((Systemcontrol *)hw)->CFSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_CFSR_LSPERR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR &= ~SystemControl_CFSR_LSPERR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_CFSR_LSPERR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR ^= SystemControl_CFSR_LSPERR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_CFSR_BFARVALID_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR |= SystemControl_CFSR_BFARVALID;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_CFSR_BFARVALID_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp = (tmp & SystemControl_CFSR_BFARVALID) >> 15;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_CFSR_BFARVALID_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp &= ~SystemControl_CFSR_BFARVALID;
	tmp |= value << 15;
	((Systemcontrol *)hw)->CFSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_CFSR_BFARVALID_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR &= ~SystemControl_CFSR_BFARVALID;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_CFSR_BFARVALID_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR ^= SystemControl_CFSR_BFARVALID;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_CFSR_UNDEFINSTR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR |= SystemControl_CFSR_UNDEFINSTR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_CFSR_UNDEFINSTR_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp = (tmp & SystemControl_CFSR_UNDEFINSTR) >> 16;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_CFSR_UNDEFINSTR_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp &= ~SystemControl_CFSR_UNDEFINSTR;
	tmp |= value << 16;
	((Systemcontrol *)hw)->CFSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_CFSR_UNDEFINSTR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR &= ~SystemControl_CFSR_UNDEFINSTR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_CFSR_UNDEFINSTR_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR ^= SystemControl_CFSR_UNDEFINSTR;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_CFSR_INVSTATE_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR |= SystemControl_CFSR_INVSTATE;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_CFSR_INVSTATE_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp = (tmp & SystemControl_CFSR_INVSTATE) >> 17;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_CFSR_INVSTATE_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp &= ~SystemControl_CFSR_INVSTATE;
	tmp |= value << 17;
	((Systemcontrol *)hw)->CFSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_CFSR_INVSTATE_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR &= ~SystemControl_CFSR_INVSTATE;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_CFSR_INVSTATE_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR ^= SystemControl_CFSR_INVSTATE;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_CFSR_INVPC_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR |= SystemControl_CFSR_INVPC;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_CFSR_INVPC_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp = (tmp & SystemControl_CFSR_INVPC) >> 18;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_CFSR_INVPC_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp &= ~SystemControl_CFSR_INVPC;
	tmp |= value << 18;
	((Systemcontrol *)hw)->CFSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_CFSR_INVPC_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR &= ~SystemControl_CFSR_INVPC;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_CFSR_INVPC_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR ^= SystemControl_CFSR_INVPC;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_CFSR_NOCP_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR |= SystemControl_CFSR_NOCP;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_CFSR_NOCP_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp = (tmp & SystemControl_CFSR_NOCP) >> 19;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_CFSR_NOCP_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp &= ~SystemControl_CFSR_NOCP;
	tmp |= value << 19;
	((Systemcontrol *)hw)->CFSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_CFSR_NOCP_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR &= ~SystemControl_CFSR_NOCP;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_CFSR_NOCP_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR ^= SystemControl_CFSR_NOCP;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_CFSR_UNALIGNED_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR |= SystemControl_CFSR_UNALIGNED;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_CFSR_UNALIGNED_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp = (tmp & SystemControl_CFSR_UNALIGNED) >> 24;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_CFSR_UNALIGNED_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp &= ~SystemControl_CFSR_UNALIGNED;
	tmp |= value << 24;
	((Systemcontrol *)hw)->CFSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_CFSR_UNALIGNED_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR &= ~SystemControl_CFSR_UNALIGNED;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_CFSR_UNALIGNED_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR ^= SystemControl_CFSR_UNALIGNED;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_CFSR_DIVBYZERO_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR |= SystemControl_CFSR_DIVBYZERO;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_CFSR_DIVBYZERO_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp = (tmp & SystemControl_CFSR_DIVBYZERO) >> 25;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_CFSR_DIVBYZERO_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp &= ~SystemControl_CFSR_DIVBYZERO;
	tmp |= value << 25;
	((Systemcontrol *)hw)->CFSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_CFSR_DIVBYZERO_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR &= ~SystemControl_CFSR_DIVBYZERO;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_CFSR_DIVBYZERO_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR ^= SystemControl_CFSR_DIVBYZERO;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_CFSR_reg(const void *const hw, hri_systemcontrol_cfsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR |= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_cfsr_reg_t hri_systemcontrol_get_CFSR_reg(const void *const            hw,
                                                                          hri_systemcontrol_cfsr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CFSR;
	tmp &= mask;
	return tmp;
}

static inline void hri_systemcontrol_write_CFSR_reg(const void *const hw, hri_systemcontrol_cfsr_reg_t data)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR = data;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_CFSR_reg(const void *const hw, hri_systemcontrol_cfsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR &= ~mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_CFSR_reg(const void *const hw, hri_systemcontrol_cfsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR ^= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_cfsr_reg_t hri_systemcontrol_read_CFSR_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->CFSR;
}

static inline void hri_systemcontrol_set_HFSR_VECTTBL_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->HFSR |= SystemControl_HFSR_VECTTBL;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_HFSR_VECTTBL_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->HFSR;
	tmp = (tmp & SystemControl_HFSR_VECTTBL) >> 1;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_HFSR_VECTTBL_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->HFSR;
	tmp &= ~SystemControl_HFSR_VECTTBL;
	tmp |= value << 1;
	((Systemcontrol *)hw)->HFSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_HFSR_VECTTBL_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->HFSR &= ~SystemControl_HFSR_VECTTBL;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_HFSR_VECTTBL_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->HFSR ^= SystemControl_HFSR_VECTTBL;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_HFSR_FORCED_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->HFSR |= SystemControl_HFSR_FORCED;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_HFSR_FORCED_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->HFSR;
	tmp = (tmp & SystemControl_HFSR_FORCED) >> 30;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_HFSR_FORCED_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->HFSR;
	tmp &= ~SystemControl_HFSR_FORCED;
	tmp |= value << 30;
	((Systemcontrol *)hw)->HFSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_HFSR_FORCED_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->HFSR &= ~SystemControl_HFSR_FORCED;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_HFSR_FORCED_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->HFSR ^= SystemControl_HFSR_FORCED;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_HFSR_DEBUGEVT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->HFSR |= SystemControl_HFSR_DEBUGEVT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_HFSR_DEBUGEVT_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->HFSR;
	tmp = (tmp & SystemControl_HFSR_DEBUGEVT) >> 31;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_HFSR_DEBUGEVT_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->HFSR;
	tmp &= ~SystemControl_HFSR_DEBUGEVT;
	tmp |= value << 31;
	((Systemcontrol *)hw)->HFSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_HFSR_DEBUGEVT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->HFSR &= ~SystemControl_HFSR_DEBUGEVT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_HFSR_DEBUGEVT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->HFSR ^= SystemControl_HFSR_DEBUGEVT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_HFSR_reg(const void *const hw, hri_systemcontrol_hfsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->HFSR |= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_hfsr_reg_t hri_systemcontrol_get_HFSR_reg(const void *const            hw,
                                                                          hri_systemcontrol_hfsr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->HFSR;
	tmp &= mask;
	return tmp;
}

static inline void hri_systemcontrol_write_HFSR_reg(const void *const hw, hri_systemcontrol_hfsr_reg_t data)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->HFSR = data;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_HFSR_reg(const void *const hw, hri_systemcontrol_hfsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->HFSR &= ~mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_HFSR_reg(const void *const hw, hri_systemcontrol_hfsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->HFSR ^= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_hfsr_reg_t hri_systemcontrol_read_HFSR_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->HFSR;
}

static inline void hri_systemcontrol_set_DFSR_HALTED_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->DFSR |= SystemControl_DFSR_HALTED;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_DFSR_HALTED_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->DFSR;
	tmp = (tmp & SystemControl_DFSR_HALTED) >> 0;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_DFSR_HALTED_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->DFSR;
	tmp &= ~SystemControl_DFSR_HALTED;
	tmp |= value << 0;
	((Systemcontrol *)hw)->DFSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_DFSR_HALTED_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->DFSR &= ~SystemControl_DFSR_HALTED;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_DFSR_HALTED_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->DFSR ^= SystemControl_DFSR_HALTED;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_DFSR_BKPT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->DFSR |= SystemControl_DFSR_BKPT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_DFSR_BKPT_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->DFSR;
	tmp = (tmp & SystemControl_DFSR_BKPT) >> 1;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_DFSR_BKPT_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->DFSR;
	tmp &= ~SystemControl_DFSR_BKPT;
	tmp |= value << 1;
	((Systemcontrol *)hw)->DFSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_DFSR_BKPT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->DFSR &= ~SystemControl_DFSR_BKPT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_DFSR_BKPT_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->DFSR ^= SystemControl_DFSR_BKPT;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_DFSR_DWTTRAP_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->DFSR |= SystemControl_DFSR_DWTTRAP;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_DFSR_DWTTRAP_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->DFSR;
	tmp = (tmp & SystemControl_DFSR_DWTTRAP) >> 2;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_DFSR_DWTTRAP_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->DFSR;
	tmp &= ~SystemControl_DFSR_DWTTRAP;
	tmp |= value << 2;
	((Systemcontrol *)hw)->DFSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_DFSR_DWTTRAP_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->DFSR &= ~SystemControl_DFSR_DWTTRAP;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_DFSR_DWTTRAP_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->DFSR ^= SystemControl_DFSR_DWTTRAP;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_DFSR_VCATCH_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->DFSR |= SystemControl_DFSR_VCATCH;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_DFSR_VCATCH_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->DFSR;
	tmp = (tmp & SystemControl_DFSR_VCATCH) >> 3;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_DFSR_VCATCH_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->DFSR;
	tmp &= ~SystemControl_DFSR_VCATCH;
	tmp |= value << 3;
	((Systemcontrol *)hw)->DFSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_DFSR_VCATCH_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->DFSR &= ~SystemControl_DFSR_VCATCH;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_DFSR_VCATCH_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->DFSR ^= SystemControl_DFSR_VCATCH;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_DFSR_EXTERNAL_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->DFSR |= SystemControl_DFSR_EXTERNAL;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_systemcontrol_get_DFSR_EXTERNAL_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->DFSR;
	tmp = (tmp & SystemControl_DFSR_EXTERNAL) >> 4;
	return (bool)tmp;
}

static inline void hri_systemcontrol_write_DFSR_EXTERNAL_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->DFSR;
	tmp &= ~SystemControl_DFSR_EXTERNAL;
	tmp |= value << 4;
	((Systemcontrol *)hw)->DFSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_DFSR_EXTERNAL_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->DFSR &= ~SystemControl_DFSR_EXTERNAL;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_DFSR_EXTERNAL_bit(const void *const hw)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->DFSR ^= SystemControl_DFSR_EXTERNAL;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_set_DFSR_reg(const void *const hw, hri_systemcontrol_dfsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->DFSR |= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_dfsr_reg_t hri_systemcontrol_get_DFSR_reg(const void *const            hw,
                                                                          hri_systemcontrol_dfsr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->DFSR;
	tmp &= mask;
	return tmp;
}

static inline void hri_systemcontrol_write_DFSR_reg(const void *const hw, hri_systemcontrol_dfsr_reg_t data)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->DFSR = data;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_DFSR_reg(const void *const hw, hri_systemcontrol_dfsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->DFSR &= ~mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_DFSR_reg(const void *const hw, hri_systemcontrol_dfsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->DFSR ^= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_dfsr_reg_t hri_systemcontrol_read_DFSR_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->DFSR;
}

static inline void hri_systemcontrol_set_MMFAR_ADDRESS_bf(const void *const hw, hri_systemcontrol_mmfar_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->MMFAR |= SystemControl_MMFAR_ADDRESS(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_mmfar_reg_t hri_systemcontrol_get_MMFAR_ADDRESS_bf(const void *const             hw,
                                                                                   hri_systemcontrol_mmfar_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->MMFAR;
	tmp = (tmp & SystemControl_MMFAR_ADDRESS(mask)) >> 0;
	return tmp;
}

static inline void hri_systemcontrol_write_MMFAR_ADDRESS_bf(const void *const hw, hri_systemcontrol_mmfar_reg_t data)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->MMFAR;
	tmp &= ~SystemControl_MMFAR_ADDRESS_Msk;
	tmp |= SystemControl_MMFAR_ADDRESS(data);
	((Systemcontrol *)hw)->MMFAR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_MMFAR_ADDRESS_bf(const void *const hw, hri_systemcontrol_mmfar_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->MMFAR &= ~SystemControl_MMFAR_ADDRESS(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_MMFAR_ADDRESS_bf(const void *const hw, hri_systemcontrol_mmfar_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->MMFAR ^= SystemControl_MMFAR_ADDRESS(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_mmfar_reg_t hri_systemcontrol_read_MMFAR_ADDRESS_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->MMFAR;
	tmp = (tmp & SystemControl_MMFAR_ADDRESS_Msk) >> 0;
	return tmp;
}

static inline void hri_systemcontrol_set_MMFAR_reg(const void *const hw, hri_systemcontrol_mmfar_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->MMFAR |= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_mmfar_reg_t hri_systemcontrol_get_MMFAR_reg(const void *const             hw,
                                                                            hri_systemcontrol_mmfar_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->MMFAR;
	tmp &= mask;
	return tmp;
}

static inline void hri_systemcontrol_write_MMFAR_reg(const void *const hw, hri_systemcontrol_mmfar_reg_t data)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->MMFAR = data;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_MMFAR_reg(const void *const hw, hri_systemcontrol_mmfar_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->MMFAR &= ~mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_MMFAR_reg(const void *const hw, hri_systemcontrol_mmfar_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->MMFAR ^= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_mmfar_reg_t hri_systemcontrol_read_MMFAR_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->MMFAR;
}

static inline void hri_systemcontrol_set_BFAR_ADDRESS_bf(const void *const hw, hri_systemcontrol_bfar_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->BFAR |= SystemControl_BFAR_ADDRESS(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_bfar_reg_t hri_systemcontrol_get_BFAR_ADDRESS_bf(const void *const            hw,
                                                                                 hri_systemcontrol_bfar_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->BFAR;
	tmp = (tmp & SystemControl_BFAR_ADDRESS(mask)) >> 0;
	return tmp;
}

static inline void hri_systemcontrol_write_BFAR_ADDRESS_bf(const void *const hw, hri_systemcontrol_bfar_reg_t data)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->BFAR;
	tmp &= ~SystemControl_BFAR_ADDRESS_Msk;
	tmp |= SystemControl_BFAR_ADDRESS(data);
	((Systemcontrol *)hw)->BFAR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_BFAR_ADDRESS_bf(const void *const hw, hri_systemcontrol_bfar_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->BFAR &= ~SystemControl_BFAR_ADDRESS(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_BFAR_ADDRESS_bf(const void *const hw, hri_systemcontrol_bfar_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->BFAR ^= SystemControl_BFAR_ADDRESS(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_bfar_reg_t hri_systemcontrol_read_BFAR_ADDRESS_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->BFAR;
	tmp = (tmp & SystemControl_BFAR_ADDRESS_Msk) >> 0;
	return tmp;
}

static inline void hri_systemcontrol_set_BFAR_reg(const void *const hw, hri_systemcontrol_bfar_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->BFAR |= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_bfar_reg_t hri_systemcontrol_get_BFAR_reg(const void *const            hw,
                                                                          hri_systemcontrol_bfar_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->BFAR;
	tmp &= mask;
	return tmp;
}

static inline void hri_systemcontrol_write_BFAR_reg(const void *const hw, hri_systemcontrol_bfar_reg_t data)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->BFAR = data;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_BFAR_reg(const void *const hw, hri_systemcontrol_bfar_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->BFAR &= ~mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_BFAR_reg(const void *const hw, hri_systemcontrol_bfar_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->BFAR ^= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_bfar_reg_t hri_systemcontrol_read_BFAR_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->BFAR;
}

static inline void hri_systemcontrol_set_AFSR_AUXFAULT_bf(const void *const hw, hri_systemcontrol_afsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AFSR |= SystemControl_AFSR_AUXFAULT(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_afsr_reg_t hri_systemcontrol_get_AFSR_AUXFAULT_bf(const void *const            hw,
                                                                                  hri_systemcontrol_afsr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->AFSR;
	tmp = (tmp & SystemControl_AFSR_AUXFAULT(mask)) >> 0;
	return tmp;
}

static inline void hri_systemcontrol_write_AFSR_AUXFAULT_bf(const void *const hw, hri_systemcontrol_afsr_reg_t data)
{
	uint32_t tmp;
	SystemControl_CRITICAL_SECTION_ENTER();
	tmp = ((Systemcontrol *)hw)->AFSR;
	tmp &= ~SystemControl_AFSR_AUXFAULT_Msk;
	tmp |= SystemControl_AFSR_AUXFAULT(data);
	((Systemcontrol *)hw)->AFSR = tmp;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_AFSR_AUXFAULT_bf(const void *const hw, hri_systemcontrol_afsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AFSR &= ~SystemControl_AFSR_AUXFAULT(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_AFSR_AUXFAULT_bf(const void *const hw, hri_systemcontrol_afsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AFSR ^= SystemControl_AFSR_AUXFAULT(mask);
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_afsr_reg_t hri_systemcontrol_read_AFSR_AUXFAULT_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->AFSR;
	tmp = (tmp & SystemControl_AFSR_AUXFAULT_Msk) >> 0;
	return tmp;
}

static inline void hri_systemcontrol_set_AFSR_reg(const void *const hw, hri_systemcontrol_afsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AFSR |= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_afsr_reg_t hri_systemcontrol_get_AFSR_reg(const void *const            hw,
                                                                          hri_systemcontrol_afsr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->AFSR;
	tmp &= mask;
	return tmp;
}

static inline void hri_systemcontrol_write_AFSR_reg(const void *const hw, hri_systemcontrol_afsr_reg_t data)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AFSR = data;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_AFSR_reg(const void *const hw, hri_systemcontrol_afsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AFSR &= ~mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_AFSR_reg(const void *const hw, hri_systemcontrol_afsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AFSR ^= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_afsr_reg_t hri_systemcontrol_read_AFSR_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->AFSR;
}

#ifdef __cplusplus
}
#endif

#endif /* _HRI_SystemControl_G55_H_INCLUDED */
#endif /* _SAMG55_SystemControl_COMPONENT_ */
