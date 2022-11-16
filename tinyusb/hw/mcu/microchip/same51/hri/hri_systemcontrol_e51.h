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
 *
 */

#ifdef _SAME51_SystemControl_COMPONENT_
#ifndef _HRI_SystemControl_E51_H_INCLUDED_
#define _HRI_SystemControl_E51_H_INCLUDED_

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
typedef uint32_t hri_systemcontrol_adr_reg_t;
typedef uint32_t hri_systemcontrol_afsr_reg_t;
typedef uint32_t hri_systemcontrol_aircr_reg_t;
typedef uint32_t hri_systemcontrol_bfar_reg_t;
typedef uint32_t hri_systemcontrol_ccr_reg_t;
typedef uint32_t hri_systemcontrol_cfsr_reg_t;
typedef uint32_t hri_systemcontrol_cpacr_reg_t;
typedef uint32_t hri_systemcontrol_cpuid_reg_t;
typedef uint32_t hri_systemcontrol_dfr_reg_t;
typedef uint32_t hri_systemcontrol_dfsr_reg_t;
typedef uint32_t hri_systemcontrol_hfsr_reg_t;
typedef uint32_t hri_systemcontrol_icsr_reg_t;
typedef uint32_t hri_systemcontrol_ictr_reg_t;
typedef uint32_t hri_systemcontrol_isar_reg_t;
typedef uint32_t hri_systemcontrol_mmfar_reg_t;
typedef uint32_t hri_systemcontrol_mmfr_reg_t;
typedef uint32_t hri_systemcontrol_pfr_reg_t;
typedef uint32_t hri_systemcontrol_scr_reg_t;
typedef uint32_t hri_systemcontrol_shcsr_reg_t;
typedef uint32_t hri_systemcontrol_shpr1_reg_t;
typedef uint32_t hri_systemcontrol_shpr2_reg_t;
typedef uint32_t hri_systemcontrol_shpr3_reg_t;
typedef uint32_t hri_systemcontrol_vtor_reg_t;

static inline hri_systemcontrol_ictr_reg_t hri_systemcontrol_get_ICTR_INTLINESNUM_bf(const void *const            hw,
                                                                                     hri_systemcontrol_ictr_reg_t mask)
{
	return (((Systemcontrol *)hw)->ICTR.reg & SystemControl_ICTR_INTLINESNUM(mask)) >> 0;
}

static inline hri_systemcontrol_ictr_reg_t hri_systemcontrol_read_ICTR_INTLINESNUM_bf(const void *const hw)
{
	return (((Systemcontrol *)hw)->ICTR.reg & SystemControl_ICTR_INTLINESNUM_Msk) >> 0;
}

static inline hri_systemcontrol_ictr_reg_t hri_systemcontrol_get_ICTR_reg(const void *const            hw,
                                                                          hri_systemcontrol_ictr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->ICTR.reg;
	tmp &= mask;
	return tmp;
}

static inline hri_systemcontrol_ictr_reg_t hri_systemcontrol_read_ICTR_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->ICTR.reg;
}

static inline hri_systemcontrol_cpuid_reg_t hri_systemcontrol_get_CPUID_REVISION_bf(const void *const             hw,
                                                                                    hri_systemcontrol_cpuid_reg_t mask)
{
	return (((Systemcontrol *)hw)->CPUID.reg & SystemControl_CPUID_REVISION(mask)) >> 0;
}

static inline hri_systemcontrol_cpuid_reg_t hri_systemcontrol_read_CPUID_REVISION_bf(const void *const hw)
{
	return (((Systemcontrol *)hw)->CPUID.reg & SystemControl_CPUID_REVISION_Msk) >> 0;
}

static inline hri_systemcontrol_cpuid_reg_t hri_systemcontrol_get_CPUID_PARTNO_bf(const void *const             hw,
                                                                                  hri_systemcontrol_cpuid_reg_t mask)
{
	return (((Systemcontrol *)hw)->CPUID.reg & SystemControl_CPUID_PARTNO(mask)) >> 4;
}

static inline hri_systemcontrol_cpuid_reg_t hri_systemcontrol_read_CPUID_PARTNO_bf(const void *const hw)
{
	return (((Systemcontrol *)hw)->CPUID.reg & SystemControl_CPUID_PARTNO_Msk) >> 4;
}

static inline hri_systemcontrol_cpuid_reg_t hri_systemcontrol_get_CPUID_CONSTANT_bf(const void *const             hw,
                                                                                    hri_systemcontrol_cpuid_reg_t mask)
{
	return (((Systemcontrol *)hw)->CPUID.reg & SystemControl_CPUID_CONSTANT(mask)) >> 16;
}

static inline hri_systemcontrol_cpuid_reg_t hri_systemcontrol_read_CPUID_CONSTANT_bf(const void *const hw)
{
	return (((Systemcontrol *)hw)->CPUID.reg & SystemControl_CPUID_CONSTANT_Msk) >> 16;
}

static inline hri_systemcontrol_cpuid_reg_t hri_systemcontrol_get_CPUID_VARIANT_bf(const void *const             hw,
                                                                                   hri_systemcontrol_cpuid_reg_t mask)
{
	return (((Systemcontrol *)hw)->CPUID.reg & SystemControl_CPUID_VARIANT(mask)) >> 20;
}

static inline hri_systemcontrol_cpuid_reg_t hri_systemcontrol_read_CPUID_VARIANT_bf(const void *const hw)
{
	return (((Systemcontrol *)hw)->CPUID.reg & SystemControl_CPUID_VARIANT_Msk) >> 20;
}

static inline hri_systemcontrol_cpuid_reg_t
hri_systemcontrol_get_CPUID_IMPLEMENTER_bf(const void *const hw, hri_systemcontrol_cpuid_reg_t mask)
{
	return (((Systemcontrol *)hw)->CPUID.reg & SystemControl_CPUID_IMPLEMENTER(mask)) >> 24;
}

static inline hri_systemcontrol_cpuid_reg_t hri_systemcontrol_read_CPUID_IMPLEMENTER_bf(const void *const hw)
{
	return (((Systemcontrol *)hw)->CPUID.reg & SystemControl_CPUID_IMPLEMENTER_Msk) >> 24;
}

static inline hri_systemcontrol_cpuid_reg_t hri_systemcontrol_get_CPUID_reg(const void *const             hw,
                                                                            hri_systemcontrol_cpuid_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CPUID.reg;
	tmp &= mask;
	return tmp;
}

static inline hri_systemcontrol_cpuid_reg_t hri_systemcontrol_read_CPUID_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->CPUID.reg;
}

static inline hri_systemcontrol_dfr_reg_t hri_systemcontrol_get_DFR_reg(const void *const           hw,
                                                                        hri_systemcontrol_dfr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->DFR.reg;
	tmp &= mask;
	return tmp;
}

static inline hri_systemcontrol_dfr_reg_t hri_systemcontrol_read_DFR_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->DFR.reg;
}

static inline hri_systemcontrol_adr_reg_t hri_systemcontrol_get_ADR_reg(const void *const           hw,
                                                                        hri_systemcontrol_adr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->ADR.reg;
	tmp &= mask;
	return tmp;
}

static inline hri_systemcontrol_adr_reg_t hri_systemcontrol_read_ADR_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->ADR.reg;
}

static inline hri_systemcontrol_mmfr_reg_t hri_systemcontrol_get_MMFR_reg(const void *const hw, uint8_t index,
                                                                          hri_systemcontrol_mmfr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->MMFR[index].reg;
	tmp &= mask;
	return tmp;
}

static inline hri_systemcontrol_mmfr_reg_t hri_systemcontrol_read_MMFR_reg(const void *const hw, uint8_t index)
{
	return ((Systemcontrol *)hw)->MMFR[index].reg;
}

static inline hri_systemcontrol_isar_reg_t hri_systemcontrol_get_ISAR_reg(const void *const hw, uint8_t index,
                                                                          hri_systemcontrol_isar_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->ISAR[index].reg;
	tmp &= mask;
	return tmp;
}

static inline hri_systemcontrol_isar_reg_t hri_systemcontrol_read_ISAR_reg(const void *const hw, uint8_t index)
{
	return ((Systemcontrol *)hw)->ISAR[index].reg;
}

static inline void hri_systemcontrol_set_ACTLR_reg(const void *const hw, hri_systemcontrol_actlr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ACTLR.reg |= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_actlr_reg_t hri_systemcontrol_get_ACTLR_reg(const void *const             hw,
                                                                            hri_systemcontrol_actlr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->ACTLR.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_systemcontrol_write_ACTLR_reg(const void *const hw, hri_systemcontrol_actlr_reg_t data)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ACTLR.reg = data;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_ACTLR_reg(const void *const hw, hri_systemcontrol_actlr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ACTLR.reg &= ~mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_ACTLR_reg(const void *const hw, hri_systemcontrol_actlr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ACTLR.reg ^= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_actlr_reg_t hri_systemcontrol_read_ACTLR_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->ACTLR.reg;
}

static inline void hri_systemcontrol_set_ICSR_reg(const void *const hw, hri_systemcontrol_icsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR.reg |= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_icsr_reg_t hri_systemcontrol_get_ICSR_reg(const void *const            hw,
                                                                          hri_systemcontrol_icsr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->ICSR.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_systemcontrol_write_ICSR_reg(const void *const hw, hri_systemcontrol_icsr_reg_t data)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR.reg = data;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_ICSR_reg(const void *const hw, hri_systemcontrol_icsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR.reg &= ~mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_ICSR_reg(const void *const hw, hri_systemcontrol_icsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->ICSR.reg ^= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_icsr_reg_t hri_systemcontrol_read_ICSR_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->ICSR.reg;
}

static inline void hri_systemcontrol_set_VTOR_reg(const void *const hw, hri_systemcontrol_vtor_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->VTOR.reg |= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_vtor_reg_t hri_systemcontrol_get_VTOR_reg(const void *const            hw,
                                                                          hri_systemcontrol_vtor_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->VTOR.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_systemcontrol_write_VTOR_reg(const void *const hw, hri_systemcontrol_vtor_reg_t data)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->VTOR.reg = data;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_VTOR_reg(const void *const hw, hri_systemcontrol_vtor_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->VTOR.reg &= ~mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_VTOR_reg(const void *const hw, hri_systemcontrol_vtor_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->VTOR.reg ^= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_vtor_reg_t hri_systemcontrol_read_VTOR_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->VTOR.reg;
}

static inline void hri_systemcontrol_set_AIRCR_reg(const void *const hw, hri_systemcontrol_aircr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AIRCR.reg |= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_aircr_reg_t hri_systemcontrol_get_AIRCR_reg(const void *const             hw,
                                                                            hri_systemcontrol_aircr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->AIRCR.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_systemcontrol_write_AIRCR_reg(const void *const hw, hri_systemcontrol_aircr_reg_t data)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AIRCR.reg = data;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_AIRCR_reg(const void *const hw, hri_systemcontrol_aircr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AIRCR.reg &= ~mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_AIRCR_reg(const void *const hw, hri_systemcontrol_aircr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AIRCR.reg ^= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_aircr_reg_t hri_systemcontrol_read_AIRCR_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->AIRCR.reg;
}

static inline void hri_systemcontrol_set_SCR_reg(const void *const hw, hri_systemcontrol_scr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SCR.reg |= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_scr_reg_t hri_systemcontrol_get_SCR_reg(const void *const           hw,
                                                                        hri_systemcontrol_scr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SCR.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_systemcontrol_write_SCR_reg(const void *const hw, hri_systemcontrol_scr_reg_t data)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SCR.reg = data;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_SCR_reg(const void *const hw, hri_systemcontrol_scr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SCR.reg &= ~mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_SCR_reg(const void *const hw, hri_systemcontrol_scr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SCR.reg ^= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_scr_reg_t hri_systemcontrol_read_SCR_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->SCR.reg;
}

static inline void hri_systemcontrol_set_CCR_reg(const void *const hw, hri_systemcontrol_ccr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CCR.reg |= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_ccr_reg_t hri_systemcontrol_get_CCR_reg(const void *const           hw,
                                                                        hri_systemcontrol_ccr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CCR.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_systemcontrol_write_CCR_reg(const void *const hw, hri_systemcontrol_ccr_reg_t data)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CCR.reg = data;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_CCR_reg(const void *const hw, hri_systemcontrol_ccr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CCR.reg &= ~mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_CCR_reg(const void *const hw, hri_systemcontrol_ccr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CCR.reg ^= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_ccr_reg_t hri_systemcontrol_read_CCR_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->CCR.reg;
}

static inline void hri_systemcontrol_set_SHPR1_reg(const void *const hw, hri_systemcontrol_shpr1_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR1.reg |= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_shpr1_reg_t hri_systemcontrol_get_SHPR1_reg(const void *const             hw,
                                                                            hri_systemcontrol_shpr1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SHPR1.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_systemcontrol_write_SHPR1_reg(const void *const hw, hri_systemcontrol_shpr1_reg_t data)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR1.reg = data;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_SHPR1_reg(const void *const hw, hri_systemcontrol_shpr1_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR1.reg &= ~mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_SHPR1_reg(const void *const hw, hri_systemcontrol_shpr1_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR1.reg ^= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_shpr1_reg_t hri_systemcontrol_read_SHPR1_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->SHPR1.reg;
}

static inline void hri_systemcontrol_set_SHPR2_reg(const void *const hw, hri_systemcontrol_shpr2_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR2.reg |= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_shpr2_reg_t hri_systemcontrol_get_SHPR2_reg(const void *const             hw,
                                                                            hri_systemcontrol_shpr2_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SHPR2.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_systemcontrol_write_SHPR2_reg(const void *const hw, hri_systemcontrol_shpr2_reg_t data)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR2.reg = data;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_SHPR2_reg(const void *const hw, hri_systemcontrol_shpr2_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR2.reg &= ~mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_SHPR2_reg(const void *const hw, hri_systemcontrol_shpr2_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR2.reg ^= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_shpr2_reg_t hri_systemcontrol_read_SHPR2_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->SHPR2.reg;
}

static inline void hri_systemcontrol_set_SHPR3_reg(const void *const hw, hri_systemcontrol_shpr3_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR3.reg |= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_shpr3_reg_t hri_systemcontrol_get_SHPR3_reg(const void *const             hw,
                                                                            hri_systemcontrol_shpr3_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SHPR3.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_systemcontrol_write_SHPR3_reg(const void *const hw, hri_systemcontrol_shpr3_reg_t data)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR3.reg = data;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_SHPR3_reg(const void *const hw, hri_systemcontrol_shpr3_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR3.reg &= ~mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_SHPR3_reg(const void *const hw, hri_systemcontrol_shpr3_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHPR3.reg ^= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_shpr3_reg_t hri_systemcontrol_read_SHPR3_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->SHPR3.reg;
}

static inline void hri_systemcontrol_set_SHCSR_reg(const void *const hw, hri_systemcontrol_shcsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR.reg |= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_shcsr_reg_t hri_systemcontrol_get_SHCSR_reg(const void *const             hw,
                                                                            hri_systemcontrol_shcsr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->SHCSR.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_systemcontrol_write_SHCSR_reg(const void *const hw, hri_systemcontrol_shcsr_reg_t data)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR.reg = data;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_SHCSR_reg(const void *const hw, hri_systemcontrol_shcsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR.reg &= ~mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_SHCSR_reg(const void *const hw, hri_systemcontrol_shcsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->SHCSR.reg ^= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_shcsr_reg_t hri_systemcontrol_read_SHCSR_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->SHCSR.reg;
}

static inline void hri_systemcontrol_set_CFSR_reg(const void *const hw, hri_systemcontrol_cfsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR.reg |= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_cfsr_reg_t hri_systemcontrol_get_CFSR_reg(const void *const            hw,
                                                                          hri_systemcontrol_cfsr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CFSR.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_systemcontrol_write_CFSR_reg(const void *const hw, hri_systemcontrol_cfsr_reg_t data)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR.reg = data;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_CFSR_reg(const void *const hw, hri_systemcontrol_cfsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR.reg &= ~mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_CFSR_reg(const void *const hw, hri_systemcontrol_cfsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CFSR.reg ^= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_cfsr_reg_t hri_systemcontrol_read_CFSR_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->CFSR.reg;
}

static inline void hri_systemcontrol_set_HFSR_reg(const void *const hw, hri_systemcontrol_hfsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->HFSR.reg |= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_hfsr_reg_t hri_systemcontrol_get_HFSR_reg(const void *const            hw,
                                                                          hri_systemcontrol_hfsr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->HFSR.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_systemcontrol_write_HFSR_reg(const void *const hw, hri_systemcontrol_hfsr_reg_t data)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->HFSR.reg = data;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_HFSR_reg(const void *const hw, hri_systemcontrol_hfsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->HFSR.reg &= ~mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_HFSR_reg(const void *const hw, hri_systemcontrol_hfsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->HFSR.reg ^= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_hfsr_reg_t hri_systemcontrol_read_HFSR_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->HFSR.reg;
}

static inline void hri_systemcontrol_set_DFSR_reg(const void *const hw, hri_systemcontrol_dfsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->DFSR.reg |= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_dfsr_reg_t hri_systemcontrol_get_DFSR_reg(const void *const            hw,
                                                                          hri_systemcontrol_dfsr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->DFSR.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_systemcontrol_write_DFSR_reg(const void *const hw, hri_systemcontrol_dfsr_reg_t data)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->DFSR.reg = data;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_DFSR_reg(const void *const hw, hri_systemcontrol_dfsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->DFSR.reg &= ~mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_DFSR_reg(const void *const hw, hri_systemcontrol_dfsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->DFSR.reg ^= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_dfsr_reg_t hri_systemcontrol_read_DFSR_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->DFSR.reg;
}

static inline void hri_systemcontrol_set_MMFAR_reg(const void *const hw, hri_systemcontrol_mmfar_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->MMFAR.reg |= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_mmfar_reg_t hri_systemcontrol_get_MMFAR_reg(const void *const             hw,
                                                                            hri_systemcontrol_mmfar_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->MMFAR.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_systemcontrol_write_MMFAR_reg(const void *const hw, hri_systemcontrol_mmfar_reg_t data)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->MMFAR.reg = data;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_MMFAR_reg(const void *const hw, hri_systemcontrol_mmfar_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->MMFAR.reg &= ~mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_MMFAR_reg(const void *const hw, hri_systemcontrol_mmfar_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->MMFAR.reg ^= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_mmfar_reg_t hri_systemcontrol_read_MMFAR_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->MMFAR.reg;
}

static inline void hri_systemcontrol_set_BFAR_reg(const void *const hw, hri_systemcontrol_bfar_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->BFAR.reg |= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_bfar_reg_t hri_systemcontrol_get_BFAR_reg(const void *const            hw,
                                                                          hri_systemcontrol_bfar_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->BFAR.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_systemcontrol_write_BFAR_reg(const void *const hw, hri_systemcontrol_bfar_reg_t data)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->BFAR.reg = data;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_BFAR_reg(const void *const hw, hri_systemcontrol_bfar_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->BFAR.reg &= ~mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_BFAR_reg(const void *const hw, hri_systemcontrol_bfar_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->BFAR.reg ^= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_bfar_reg_t hri_systemcontrol_read_BFAR_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->BFAR.reg;
}

static inline void hri_systemcontrol_set_AFSR_reg(const void *const hw, hri_systemcontrol_afsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AFSR.reg |= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_afsr_reg_t hri_systemcontrol_get_AFSR_reg(const void *const            hw,
                                                                          hri_systemcontrol_afsr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->AFSR.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_systemcontrol_write_AFSR_reg(const void *const hw, hri_systemcontrol_afsr_reg_t data)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AFSR.reg = data;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_AFSR_reg(const void *const hw, hri_systemcontrol_afsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AFSR.reg &= ~mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_AFSR_reg(const void *const hw, hri_systemcontrol_afsr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->AFSR.reg ^= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_afsr_reg_t hri_systemcontrol_read_AFSR_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->AFSR.reg;
}

static inline void hri_systemcontrol_set_PFR_reg(const void *const hw, uint8_t index, hri_systemcontrol_pfr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->PFR[index].reg |= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_pfr_reg_t hri_systemcontrol_get_PFR_reg(const void *const hw, uint8_t index,
                                                                        hri_systemcontrol_pfr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->PFR[index].reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_systemcontrol_write_PFR_reg(const void *const hw, uint8_t index,
                                                   hri_systemcontrol_pfr_reg_t data)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->PFR[index].reg = data;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_PFR_reg(const void *const hw, uint8_t index,
                                                   hri_systemcontrol_pfr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->PFR[index].reg &= ~mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_PFR_reg(const void *const hw, uint8_t index,
                                                    hri_systemcontrol_pfr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->PFR[index].reg ^= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_pfr_reg_t hri_systemcontrol_read_PFR_reg(const void *const hw, uint8_t index)
{
	return ((Systemcontrol *)hw)->PFR[index].reg;
}

static inline void hri_systemcontrol_set_CPACR_reg(const void *const hw, hri_systemcontrol_cpacr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CPACR.reg |= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_cpacr_reg_t hri_systemcontrol_get_CPACR_reg(const void *const             hw,
                                                                            hri_systemcontrol_cpacr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Systemcontrol *)hw)->CPACR.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_systemcontrol_write_CPACR_reg(const void *const hw, hri_systemcontrol_cpacr_reg_t data)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CPACR.reg = data;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_clear_CPACR_reg(const void *const hw, hri_systemcontrol_cpacr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CPACR.reg &= ~mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline void hri_systemcontrol_toggle_CPACR_reg(const void *const hw, hri_systemcontrol_cpacr_reg_t mask)
{
	SystemControl_CRITICAL_SECTION_ENTER();
	((Systemcontrol *)hw)->CPACR.reg ^= mask;
	SystemControl_CRITICAL_SECTION_LEAVE();
}

static inline hri_systemcontrol_cpacr_reg_t hri_systemcontrol_read_CPACR_reg(const void *const hw)
{
	return ((Systemcontrol *)hw)->CPACR.reg;
}

#ifdef __cplusplus
}
#endif

#endif /* _HRI_SystemControl_E51_H_INCLUDED */
#endif /* _SAME51_SystemControl_COMPONENT_ */
