/**
 * \file
 *
 * \brief SAM UHP
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

#ifdef _SAMG55_UHP_COMPONENT_
#ifndef _HRI_UHP_G55_H_INCLUDED_
#define _HRI_UHP_G55_H_INCLUDED_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <hal_atomic.h>

#if defined(ENABLE_UHP_CRITICAL_SECTIONS)
#define UHP_CRITICAL_SECTION_ENTER() CRITICAL_SECTION_ENTER()
#define UHP_CRITICAL_SECTION_LEAVE() CRITICAL_SECTION_LEAVE()
#else
#define UHP_CRITICAL_SECTION_ENTER()
#define UHP_CRITICAL_SECTION_LEAVE()
#endif

typedef uint32_t hri_uhp_hcbulkcurrented_reg_t;
typedef uint32_t hri_uhp_hcbulkheaded_reg_t;
typedef uint32_t hri_uhp_hccommandstatus_reg_t;
typedef uint32_t hri_uhp_hccontrol_reg_t;
typedef uint32_t hri_uhp_hccontrolcurrented_reg_t;
typedef uint32_t hri_uhp_hccontrolheaded_reg_t;
typedef uint32_t hri_uhp_hcdonehead_reg_t;
typedef uint32_t hri_uhp_hcfminterval_reg_t;
typedef uint32_t hri_uhp_hcfmnumber_reg_t;
typedef uint32_t hri_uhp_hcfmremaining_reg_t;
typedef uint32_t hri_uhp_hchcca_reg_t;
typedef uint32_t hri_uhp_hcinterruptdisable_reg_t;
typedef uint32_t hri_uhp_hcinterruptenable_reg_t;
typedef uint32_t hri_uhp_hcinterruptstatus_reg_t;
typedef uint32_t hri_uhp_hclsthreshold_reg_t;
typedef uint32_t hri_uhp_hcperiodcurrented_reg_t;
typedef uint32_t hri_uhp_hcperiodicstart_reg_t;
typedef uint32_t hri_uhp_hcrevision_reg_t;
typedef uint32_t hri_uhp_hcrhdescriptora_reg_t;
typedef uint32_t hri_uhp_hcrhdescriptorb_reg_t;
typedef uint32_t hri_uhp_hcrhportstatus_reg_t;
typedef uint32_t hri_uhp_hcrhstatus_reg_t;

static inline void hri_uhp_set_HCCONTROL_PLE_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROL |= UHP_HCCONTROL_PLE;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCCONTROL_PLE_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCCONTROL;
	tmp = (tmp & UHP_HCCONTROL_PLE) >> UHP_HCCONTROL_PLE_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCCONTROL_PLE_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCCONTROL;
	tmp &= ~UHP_HCCONTROL_PLE;
	tmp |= value << UHP_HCCONTROL_PLE_Pos;
	((Uhp *)hw)->UHP_HCCONTROL = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCCONTROL_PLE_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROL &= ~UHP_HCCONTROL_PLE;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCCONTROL_PLE_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROL ^= UHP_HCCONTROL_PLE;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCCONTROL_IE_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROL |= UHP_HCCONTROL_IE;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCCONTROL_IE_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCCONTROL;
	tmp = (tmp & UHP_HCCONTROL_IE) >> UHP_HCCONTROL_IE_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCCONTROL_IE_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCCONTROL;
	tmp &= ~UHP_HCCONTROL_IE;
	tmp |= value << UHP_HCCONTROL_IE_Pos;
	((Uhp *)hw)->UHP_HCCONTROL = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCCONTROL_IE_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROL &= ~UHP_HCCONTROL_IE;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCCONTROL_IE_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROL ^= UHP_HCCONTROL_IE;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCCONTROL_CLE_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROL |= UHP_HCCONTROL_CLE;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCCONTROL_CLE_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCCONTROL;
	tmp = (tmp & UHP_HCCONTROL_CLE) >> UHP_HCCONTROL_CLE_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCCONTROL_CLE_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCCONTROL;
	tmp &= ~UHP_HCCONTROL_CLE;
	tmp |= value << UHP_HCCONTROL_CLE_Pos;
	((Uhp *)hw)->UHP_HCCONTROL = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCCONTROL_CLE_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROL &= ~UHP_HCCONTROL_CLE;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCCONTROL_CLE_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROL ^= UHP_HCCONTROL_CLE;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCCONTROL_BLE_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROL |= UHP_HCCONTROL_BLE;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCCONTROL_BLE_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCCONTROL;
	tmp = (tmp & UHP_HCCONTROL_BLE) >> UHP_HCCONTROL_BLE_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCCONTROL_BLE_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCCONTROL;
	tmp &= ~UHP_HCCONTROL_BLE;
	tmp |= value << UHP_HCCONTROL_BLE_Pos;
	((Uhp *)hw)->UHP_HCCONTROL = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCCONTROL_BLE_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROL &= ~UHP_HCCONTROL_BLE;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCCONTROL_BLE_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROL ^= UHP_HCCONTROL_BLE;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCCONTROL_IR_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROL |= UHP_HCCONTROL_IR;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCCONTROL_IR_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCCONTROL;
	tmp = (tmp & UHP_HCCONTROL_IR) >> UHP_HCCONTROL_IR_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCCONTROL_IR_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCCONTROL;
	tmp &= ~UHP_HCCONTROL_IR;
	tmp |= value << UHP_HCCONTROL_IR_Pos;
	((Uhp *)hw)->UHP_HCCONTROL = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCCONTROL_IR_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROL &= ~UHP_HCCONTROL_IR;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCCONTROL_IR_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROL ^= UHP_HCCONTROL_IR;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCCONTROL_RWC_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROL |= UHP_HCCONTROL_RWC;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCCONTROL_RWC_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCCONTROL;
	tmp = (tmp & UHP_HCCONTROL_RWC) >> UHP_HCCONTROL_RWC_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCCONTROL_RWC_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCCONTROL;
	tmp &= ~UHP_HCCONTROL_RWC;
	tmp |= value << UHP_HCCONTROL_RWC_Pos;
	((Uhp *)hw)->UHP_HCCONTROL = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCCONTROL_RWC_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROL &= ~UHP_HCCONTROL_RWC;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCCONTROL_RWC_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROL ^= UHP_HCCONTROL_RWC;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCCONTROL_RWE_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROL |= UHP_HCCONTROL_RWE;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCCONTROL_RWE_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCCONTROL;
	tmp = (tmp & UHP_HCCONTROL_RWE) >> UHP_HCCONTROL_RWE_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCCONTROL_RWE_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCCONTROL;
	tmp &= ~UHP_HCCONTROL_RWE;
	tmp |= value << UHP_HCCONTROL_RWE_Pos;
	((Uhp *)hw)->UHP_HCCONTROL = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCCONTROL_RWE_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROL &= ~UHP_HCCONTROL_RWE;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCCONTROL_RWE_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROL ^= UHP_HCCONTROL_RWE;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCCONTROL_CBSR_bf(const void *const hw, hri_uhp_hccontrol_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROL |= UHP_HCCONTROL_CBSR(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hccontrol_reg_t hri_uhp_get_HCCONTROL_CBSR_bf(const void *const hw, hri_uhp_hccontrol_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCCONTROL;
	tmp = (tmp & UHP_HCCONTROL_CBSR(mask)) >> UHP_HCCONTROL_CBSR_Pos;
	return tmp;
}

static inline void hri_uhp_write_HCCONTROL_CBSR_bf(const void *const hw, hri_uhp_hccontrol_reg_t data)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCCONTROL;
	tmp &= ~UHP_HCCONTROL_CBSR_Msk;
	tmp |= UHP_HCCONTROL_CBSR(data);
	((Uhp *)hw)->UHP_HCCONTROL = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCCONTROL_CBSR_bf(const void *const hw, hri_uhp_hccontrol_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROL &= ~UHP_HCCONTROL_CBSR(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCCONTROL_CBSR_bf(const void *const hw, hri_uhp_hccontrol_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROL ^= UHP_HCCONTROL_CBSR(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hccontrol_reg_t hri_uhp_read_HCCONTROL_CBSR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCCONTROL;
	tmp = (tmp & UHP_HCCONTROL_CBSR_Msk) >> UHP_HCCONTROL_CBSR_Pos;
	return tmp;
}

static inline void hri_uhp_set_HCCONTROL_HCFS_bf(const void *const hw, hri_uhp_hccontrol_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROL |= UHP_HCCONTROL_HCFS(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hccontrol_reg_t hri_uhp_get_HCCONTROL_HCFS_bf(const void *const hw, hri_uhp_hccontrol_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCCONTROL;
	tmp = (tmp & UHP_HCCONTROL_HCFS(mask)) >> UHP_HCCONTROL_HCFS_Pos;
	return tmp;
}

static inline void hri_uhp_write_HCCONTROL_HCFS_bf(const void *const hw, hri_uhp_hccontrol_reg_t data)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCCONTROL;
	tmp &= ~UHP_HCCONTROL_HCFS_Msk;
	tmp |= UHP_HCCONTROL_HCFS(data);
	((Uhp *)hw)->UHP_HCCONTROL = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCCONTROL_HCFS_bf(const void *const hw, hri_uhp_hccontrol_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROL &= ~UHP_HCCONTROL_HCFS(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCCONTROL_HCFS_bf(const void *const hw, hri_uhp_hccontrol_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROL ^= UHP_HCCONTROL_HCFS(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hccontrol_reg_t hri_uhp_read_HCCONTROL_HCFS_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCCONTROL;
	tmp = (tmp & UHP_HCCONTROL_HCFS_Msk) >> UHP_HCCONTROL_HCFS_Pos;
	return tmp;
}

static inline void hri_uhp_set_HCCONTROL_reg(const void *const hw, hri_uhp_hccontrol_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROL |= mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hccontrol_reg_t hri_uhp_get_HCCONTROL_reg(const void *const hw, hri_uhp_hccontrol_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCCONTROL;
	tmp &= mask;
	return tmp;
}

static inline void hri_uhp_write_HCCONTROL_reg(const void *const hw, hri_uhp_hccontrol_reg_t data)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROL = data;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCCONTROL_reg(const void *const hw, hri_uhp_hccontrol_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROL &= ~mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCCONTROL_reg(const void *const hw, hri_uhp_hccontrol_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROL ^= mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hccontrol_reg_t hri_uhp_read_HCCONTROL_reg(const void *const hw)
{
	return ((Uhp *)hw)->UHP_HCCONTROL;
}

static inline void hri_uhp_set_HCINTERRUPTENABLE_SO_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE |= UHP_HCINTERRUPTENABLE_SO;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCINTERRUPTENABLE_SO_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTENABLE;
	tmp = (tmp & UHP_HCINTERRUPTENABLE_SO) >> UHP_HCINTERRUPTENABLE_SO_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCINTERRUPTENABLE_SO_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTENABLE;
	tmp &= ~UHP_HCINTERRUPTENABLE_SO;
	tmp |= value << UHP_HCINTERRUPTENABLE_SO_Pos;
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCINTERRUPTENABLE_SO_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE &= ~UHP_HCINTERRUPTENABLE_SO;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCINTERRUPTENABLE_SO_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE ^= UHP_HCINTERRUPTENABLE_SO;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCINTERRUPTENABLE_WDH_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE |= UHP_HCINTERRUPTENABLE_WDH;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCINTERRUPTENABLE_WDH_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTENABLE;
	tmp = (tmp & UHP_HCINTERRUPTENABLE_WDH) >> UHP_HCINTERRUPTENABLE_WDH_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCINTERRUPTENABLE_WDH_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTENABLE;
	tmp &= ~UHP_HCINTERRUPTENABLE_WDH;
	tmp |= value << UHP_HCINTERRUPTENABLE_WDH_Pos;
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCINTERRUPTENABLE_WDH_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE &= ~UHP_HCINTERRUPTENABLE_WDH;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCINTERRUPTENABLE_WDH_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE ^= UHP_HCINTERRUPTENABLE_WDH;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCINTERRUPTENABLE_SF_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE |= UHP_HCINTERRUPTENABLE_SF;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCINTERRUPTENABLE_SF_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTENABLE;
	tmp = (tmp & UHP_HCINTERRUPTENABLE_SF) >> UHP_HCINTERRUPTENABLE_SF_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCINTERRUPTENABLE_SF_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTENABLE;
	tmp &= ~UHP_HCINTERRUPTENABLE_SF;
	tmp |= value << UHP_HCINTERRUPTENABLE_SF_Pos;
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCINTERRUPTENABLE_SF_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE &= ~UHP_HCINTERRUPTENABLE_SF;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCINTERRUPTENABLE_SF_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE ^= UHP_HCINTERRUPTENABLE_SF;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCINTERRUPTENABLE_RD_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE |= UHP_HCINTERRUPTENABLE_RD;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCINTERRUPTENABLE_RD_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTENABLE;
	tmp = (tmp & UHP_HCINTERRUPTENABLE_RD) >> UHP_HCINTERRUPTENABLE_RD_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCINTERRUPTENABLE_RD_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTENABLE;
	tmp &= ~UHP_HCINTERRUPTENABLE_RD;
	tmp |= value << UHP_HCINTERRUPTENABLE_RD_Pos;
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCINTERRUPTENABLE_RD_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE &= ~UHP_HCINTERRUPTENABLE_RD;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCINTERRUPTENABLE_RD_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE ^= UHP_HCINTERRUPTENABLE_RD;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCINTERRUPTENABLE_UE_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE |= UHP_HCINTERRUPTENABLE_UE;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCINTERRUPTENABLE_UE_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTENABLE;
	tmp = (tmp & UHP_HCINTERRUPTENABLE_UE) >> UHP_HCINTERRUPTENABLE_UE_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCINTERRUPTENABLE_UE_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTENABLE;
	tmp &= ~UHP_HCINTERRUPTENABLE_UE;
	tmp |= value << UHP_HCINTERRUPTENABLE_UE_Pos;
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCINTERRUPTENABLE_UE_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE &= ~UHP_HCINTERRUPTENABLE_UE;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCINTERRUPTENABLE_UE_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE ^= UHP_HCINTERRUPTENABLE_UE;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCINTERRUPTENABLE_FNO_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE |= UHP_HCINTERRUPTENABLE_FNO;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCINTERRUPTENABLE_FNO_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTENABLE;
	tmp = (tmp & UHP_HCINTERRUPTENABLE_FNO) >> UHP_HCINTERRUPTENABLE_FNO_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCINTERRUPTENABLE_FNO_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTENABLE;
	tmp &= ~UHP_HCINTERRUPTENABLE_FNO;
	tmp |= value << UHP_HCINTERRUPTENABLE_FNO_Pos;
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCINTERRUPTENABLE_FNO_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE &= ~UHP_HCINTERRUPTENABLE_FNO;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCINTERRUPTENABLE_FNO_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE ^= UHP_HCINTERRUPTENABLE_FNO;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCINTERRUPTENABLE_RHSC_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE |= UHP_HCINTERRUPTENABLE_RHSC;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCINTERRUPTENABLE_RHSC_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTENABLE;
	tmp = (tmp & UHP_HCINTERRUPTENABLE_RHSC) >> UHP_HCINTERRUPTENABLE_RHSC_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCINTERRUPTENABLE_RHSC_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTENABLE;
	tmp &= ~UHP_HCINTERRUPTENABLE_RHSC;
	tmp |= value << UHP_HCINTERRUPTENABLE_RHSC_Pos;
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCINTERRUPTENABLE_RHSC_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE &= ~UHP_HCINTERRUPTENABLE_RHSC;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCINTERRUPTENABLE_RHSC_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE ^= UHP_HCINTERRUPTENABLE_RHSC;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCINTERRUPTENABLE_OC_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE |= UHP_HCINTERRUPTENABLE_OC;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCINTERRUPTENABLE_OC_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTENABLE;
	tmp = (tmp & UHP_HCINTERRUPTENABLE_OC) >> UHP_HCINTERRUPTENABLE_OC_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCINTERRUPTENABLE_OC_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTENABLE;
	tmp &= ~UHP_HCINTERRUPTENABLE_OC;
	tmp |= value << UHP_HCINTERRUPTENABLE_OC_Pos;
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCINTERRUPTENABLE_OC_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE &= ~UHP_HCINTERRUPTENABLE_OC;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCINTERRUPTENABLE_OC_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE ^= UHP_HCINTERRUPTENABLE_OC;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCINTERRUPTENABLE_MIE_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE |= UHP_HCINTERRUPTENABLE_MIE;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCINTERRUPTENABLE_MIE_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTENABLE;
	tmp = (tmp & UHP_HCINTERRUPTENABLE_MIE) >> UHP_HCINTERRUPTENABLE_MIE_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCINTERRUPTENABLE_MIE_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTENABLE;
	tmp &= ~UHP_HCINTERRUPTENABLE_MIE;
	tmp |= value << UHP_HCINTERRUPTENABLE_MIE_Pos;
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCINTERRUPTENABLE_MIE_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE &= ~UHP_HCINTERRUPTENABLE_MIE;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCINTERRUPTENABLE_MIE_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE ^= UHP_HCINTERRUPTENABLE_MIE;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCINTERRUPTENABLE_reg(const void *const hw, hri_uhp_hcinterruptenable_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE |= mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcinterruptenable_reg_t hri_uhp_get_HCINTERRUPTENABLE_reg(const void *const               hw,
                                                                                hri_uhp_hcinterruptenable_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTENABLE;
	tmp &= mask;
	return tmp;
}

static inline void hri_uhp_write_HCINTERRUPTENABLE_reg(const void *const hw, hri_uhp_hcinterruptenable_reg_t data)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE = data;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCINTERRUPTENABLE_reg(const void *const hw, hri_uhp_hcinterruptenable_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE &= ~mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCINTERRUPTENABLE_reg(const void *const hw, hri_uhp_hcinterruptenable_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTENABLE ^= mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcinterruptenable_reg_t hri_uhp_read_HCINTERRUPTENABLE_reg(const void *const hw)
{
	return ((Uhp *)hw)->UHP_HCINTERRUPTENABLE;
}

static inline void hri_uhp_set_HCINTERRUPTDISABLE_SO_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE |= UHP_HCINTERRUPTDISABLE_SO;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCINTERRUPTDISABLE_SO_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTDISABLE;
	tmp = (tmp & UHP_HCINTERRUPTDISABLE_SO) >> UHP_HCINTERRUPTDISABLE_SO_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCINTERRUPTDISABLE_SO_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTDISABLE;
	tmp &= ~UHP_HCINTERRUPTDISABLE_SO;
	tmp |= value << UHP_HCINTERRUPTDISABLE_SO_Pos;
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCINTERRUPTDISABLE_SO_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE &= ~UHP_HCINTERRUPTDISABLE_SO;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCINTERRUPTDISABLE_SO_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE ^= UHP_HCINTERRUPTDISABLE_SO;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCINTERRUPTDISABLE_WDH_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE |= UHP_HCINTERRUPTDISABLE_WDH;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCINTERRUPTDISABLE_WDH_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTDISABLE;
	tmp = (tmp & UHP_HCINTERRUPTDISABLE_WDH) >> UHP_HCINTERRUPTDISABLE_WDH_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCINTERRUPTDISABLE_WDH_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTDISABLE;
	tmp &= ~UHP_HCINTERRUPTDISABLE_WDH;
	tmp |= value << UHP_HCINTERRUPTDISABLE_WDH_Pos;
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCINTERRUPTDISABLE_WDH_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE &= ~UHP_HCINTERRUPTDISABLE_WDH;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCINTERRUPTDISABLE_WDH_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE ^= UHP_HCINTERRUPTDISABLE_WDH;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCINTERRUPTDISABLE_SF_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE |= UHP_HCINTERRUPTDISABLE_SF;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCINTERRUPTDISABLE_SF_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTDISABLE;
	tmp = (tmp & UHP_HCINTERRUPTDISABLE_SF) >> UHP_HCINTERRUPTDISABLE_SF_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCINTERRUPTDISABLE_SF_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTDISABLE;
	tmp &= ~UHP_HCINTERRUPTDISABLE_SF;
	tmp |= value << UHP_HCINTERRUPTDISABLE_SF_Pos;
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCINTERRUPTDISABLE_SF_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE &= ~UHP_HCINTERRUPTDISABLE_SF;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCINTERRUPTDISABLE_SF_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE ^= UHP_HCINTERRUPTDISABLE_SF;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCINTERRUPTDISABLE_RD_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE |= UHP_HCINTERRUPTDISABLE_RD;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCINTERRUPTDISABLE_RD_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTDISABLE;
	tmp = (tmp & UHP_HCINTERRUPTDISABLE_RD) >> UHP_HCINTERRUPTDISABLE_RD_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCINTERRUPTDISABLE_RD_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTDISABLE;
	tmp &= ~UHP_HCINTERRUPTDISABLE_RD;
	tmp |= value << UHP_HCINTERRUPTDISABLE_RD_Pos;
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCINTERRUPTDISABLE_RD_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE &= ~UHP_HCINTERRUPTDISABLE_RD;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCINTERRUPTDISABLE_RD_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE ^= UHP_HCINTERRUPTDISABLE_RD;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCINTERRUPTDISABLE_UE_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE |= UHP_HCINTERRUPTDISABLE_UE;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCINTERRUPTDISABLE_UE_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTDISABLE;
	tmp = (tmp & UHP_HCINTERRUPTDISABLE_UE) >> UHP_HCINTERRUPTDISABLE_UE_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCINTERRUPTDISABLE_UE_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTDISABLE;
	tmp &= ~UHP_HCINTERRUPTDISABLE_UE;
	tmp |= value << UHP_HCINTERRUPTDISABLE_UE_Pos;
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCINTERRUPTDISABLE_UE_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE &= ~UHP_HCINTERRUPTDISABLE_UE;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCINTERRUPTDISABLE_UE_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE ^= UHP_HCINTERRUPTDISABLE_UE;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCINTERRUPTDISABLE_FNO_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE |= UHP_HCINTERRUPTDISABLE_FNO;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCINTERRUPTDISABLE_FNO_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTDISABLE;
	tmp = (tmp & UHP_HCINTERRUPTDISABLE_FNO) >> UHP_HCINTERRUPTDISABLE_FNO_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCINTERRUPTDISABLE_FNO_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTDISABLE;
	tmp &= ~UHP_HCINTERRUPTDISABLE_FNO;
	tmp |= value << UHP_HCINTERRUPTDISABLE_FNO_Pos;
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCINTERRUPTDISABLE_FNO_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE &= ~UHP_HCINTERRUPTDISABLE_FNO;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCINTERRUPTDISABLE_FNO_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE ^= UHP_HCINTERRUPTDISABLE_FNO;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCINTERRUPTDISABLE_RHSC_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE |= UHP_HCINTERRUPTDISABLE_RHSC;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCINTERRUPTDISABLE_RHSC_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTDISABLE;
	tmp = (tmp & UHP_HCINTERRUPTDISABLE_RHSC) >> UHP_HCINTERRUPTDISABLE_RHSC_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCINTERRUPTDISABLE_RHSC_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTDISABLE;
	tmp &= ~UHP_HCINTERRUPTDISABLE_RHSC;
	tmp |= value << UHP_HCINTERRUPTDISABLE_RHSC_Pos;
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCINTERRUPTDISABLE_RHSC_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE &= ~UHP_HCINTERRUPTDISABLE_RHSC;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCINTERRUPTDISABLE_RHSC_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE ^= UHP_HCINTERRUPTDISABLE_RHSC;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCINTERRUPTDISABLE_OC_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE |= UHP_HCINTERRUPTDISABLE_OC;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCINTERRUPTDISABLE_OC_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTDISABLE;
	tmp = (tmp & UHP_HCINTERRUPTDISABLE_OC) >> UHP_HCINTERRUPTDISABLE_OC_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCINTERRUPTDISABLE_OC_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTDISABLE;
	tmp &= ~UHP_HCINTERRUPTDISABLE_OC;
	tmp |= value << UHP_HCINTERRUPTDISABLE_OC_Pos;
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCINTERRUPTDISABLE_OC_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE &= ~UHP_HCINTERRUPTDISABLE_OC;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCINTERRUPTDISABLE_OC_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE ^= UHP_HCINTERRUPTDISABLE_OC;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCINTERRUPTDISABLE_MIE_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE |= UHP_HCINTERRUPTDISABLE_MIE;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCINTERRUPTDISABLE_MIE_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTDISABLE;
	tmp = (tmp & UHP_HCINTERRUPTDISABLE_MIE) >> UHP_HCINTERRUPTDISABLE_MIE_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCINTERRUPTDISABLE_MIE_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTDISABLE;
	tmp &= ~UHP_HCINTERRUPTDISABLE_MIE;
	tmp |= value << UHP_HCINTERRUPTDISABLE_MIE_Pos;
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCINTERRUPTDISABLE_MIE_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE &= ~UHP_HCINTERRUPTDISABLE_MIE;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCINTERRUPTDISABLE_MIE_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE ^= UHP_HCINTERRUPTDISABLE_MIE;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCINTERRUPTDISABLE_reg(const void *const hw, hri_uhp_hcinterruptdisable_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE |= mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcinterruptdisable_reg_t hri_uhp_get_HCINTERRUPTDISABLE_reg(const void *const                hw,
                                                                                  hri_uhp_hcinterruptdisable_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTDISABLE;
	tmp &= mask;
	return tmp;
}

static inline void hri_uhp_write_HCINTERRUPTDISABLE_reg(const void *const hw, hri_uhp_hcinterruptdisable_reg_t data)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE = data;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCINTERRUPTDISABLE_reg(const void *const hw, hri_uhp_hcinterruptdisable_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE &= ~mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCINTERRUPTDISABLE_reg(const void *const hw, hri_uhp_hcinterruptdisable_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTDISABLE ^= mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcinterruptdisable_reg_t hri_uhp_read_HCINTERRUPTDISABLE_reg(const void *const hw)
{
	return ((Uhp *)hw)->UHP_HCINTERRUPTDISABLE;
}

static inline void hri_uhp_set_HCHCCA_HCCA_bf(const void *const hw, hri_uhp_hchcca_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCHCCA |= UHP_HCHCCA_HCCA(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hchcca_reg_t hri_uhp_get_HCHCCA_HCCA_bf(const void *const hw, hri_uhp_hchcca_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCHCCA;
	tmp = (tmp & UHP_HCHCCA_HCCA(mask)) >> UHP_HCHCCA_HCCA_Pos;
	return tmp;
}

static inline void hri_uhp_write_HCHCCA_HCCA_bf(const void *const hw, hri_uhp_hchcca_reg_t data)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCHCCA;
	tmp &= ~UHP_HCHCCA_HCCA_Msk;
	tmp |= UHP_HCHCCA_HCCA(data);
	((Uhp *)hw)->UHP_HCHCCA = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCHCCA_HCCA_bf(const void *const hw, hri_uhp_hchcca_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCHCCA &= ~UHP_HCHCCA_HCCA(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCHCCA_HCCA_bf(const void *const hw, hri_uhp_hchcca_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCHCCA ^= UHP_HCHCCA_HCCA(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hchcca_reg_t hri_uhp_read_HCHCCA_HCCA_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCHCCA;
	tmp = (tmp & UHP_HCHCCA_HCCA_Msk) >> UHP_HCHCCA_HCCA_Pos;
	return tmp;
}

static inline void hri_uhp_set_HCHCCA_reg(const void *const hw, hri_uhp_hchcca_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCHCCA |= mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hchcca_reg_t hri_uhp_get_HCHCCA_reg(const void *const hw, hri_uhp_hchcca_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCHCCA;
	tmp &= mask;
	return tmp;
}

static inline void hri_uhp_write_HCHCCA_reg(const void *const hw, hri_uhp_hchcca_reg_t data)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCHCCA = data;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCHCCA_reg(const void *const hw, hri_uhp_hchcca_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCHCCA &= ~mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCHCCA_reg(const void *const hw, hri_uhp_hchcca_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCHCCA ^= mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hchcca_reg_t hri_uhp_read_HCHCCA_reg(const void *const hw)
{
	return ((Uhp *)hw)->UHP_HCHCCA;
}

static inline void hri_uhp_set_HCCONTROLHEADED_CHED_bf(const void *const hw, hri_uhp_hccontrolheaded_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROLHEADED |= UHP_HCCONTROLHEADED_CHED(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hccontrolheaded_reg_t hri_uhp_get_HCCONTROLHEADED_CHED_bf(const void *const             hw,
                                                                                hri_uhp_hccontrolheaded_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCCONTROLHEADED;
	tmp = (tmp & UHP_HCCONTROLHEADED_CHED(mask)) >> UHP_HCCONTROLHEADED_CHED_Pos;
	return tmp;
}

static inline void hri_uhp_write_HCCONTROLHEADED_CHED_bf(const void *const hw, hri_uhp_hccontrolheaded_reg_t data)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCCONTROLHEADED;
	tmp &= ~UHP_HCCONTROLHEADED_CHED_Msk;
	tmp |= UHP_HCCONTROLHEADED_CHED(data);
	((Uhp *)hw)->UHP_HCCONTROLHEADED = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCCONTROLHEADED_CHED_bf(const void *const hw, hri_uhp_hccontrolheaded_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROLHEADED &= ~UHP_HCCONTROLHEADED_CHED(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCCONTROLHEADED_CHED_bf(const void *const hw, hri_uhp_hccontrolheaded_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROLHEADED ^= UHP_HCCONTROLHEADED_CHED(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hccontrolheaded_reg_t hri_uhp_read_HCCONTROLHEADED_CHED_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCCONTROLHEADED;
	tmp = (tmp & UHP_HCCONTROLHEADED_CHED_Msk) >> UHP_HCCONTROLHEADED_CHED_Pos;
	return tmp;
}

static inline void hri_uhp_set_HCCONTROLHEADED_reg(const void *const hw, hri_uhp_hccontrolheaded_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROLHEADED |= mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hccontrolheaded_reg_t hri_uhp_get_HCCONTROLHEADED_reg(const void *const             hw,
                                                                            hri_uhp_hccontrolheaded_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCCONTROLHEADED;
	tmp &= mask;
	return tmp;
}

static inline void hri_uhp_write_HCCONTROLHEADED_reg(const void *const hw, hri_uhp_hccontrolheaded_reg_t data)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROLHEADED = data;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCCONTROLHEADED_reg(const void *const hw, hri_uhp_hccontrolheaded_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROLHEADED &= ~mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCCONTROLHEADED_reg(const void *const hw, hri_uhp_hccontrolheaded_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROLHEADED ^= mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hccontrolheaded_reg_t hri_uhp_read_HCCONTROLHEADED_reg(const void *const hw)
{
	return ((Uhp *)hw)->UHP_HCCONTROLHEADED;
}

static inline void hri_uhp_set_HCCONTROLCURRENTED_CCED_bf(const void *const hw, hri_uhp_hccontrolcurrented_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROLCURRENTED |= UHP_HCCONTROLCURRENTED_CCED(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hccontrolcurrented_reg_t
hri_uhp_get_HCCONTROLCURRENTED_CCED_bf(const void *const hw, hri_uhp_hccontrolcurrented_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCCONTROLCURRENTED;
	tmp = (tmp & UHP_HCCONTROLCURRENTED_CCED(mask)) >> UHP_HCCONTROLCURRENTED_CCED_Pos;
	return tmp;
}

static inline void hri_uhp_write_HCCONTROLCURRENTED_CCED_bf(const void *const hw, hri_uhp_hccontrolcurrented_reg_t data)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCCONTROLCURRENTED;
	tmp &= ~UHP_HCCONTROLCURRENTED_CCED_Msk;
	tmp |= UHP_HCCONTROLCURRENTED_CCED(data);
	((Uhp *)hw)->UHP_HCCONTROLCURRENTED = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCCONTROLCURRENTED_CCED_bf(const void *const hw, hri_uhp_hccontrolcurrented_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROLCURRENTED &= ~UHP_HCCONTROLCURRENTED_CCED(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCCONTROLCURRENTED_CCED_bf(const void *const                hw,
                                                             hri_uhp_hccontrolcurrented_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROLCURRENTED ^= UHP_HCCONTROLCURRENTED_CCED(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hccontrolcurrented_reg_t hri_uhp_read_HCCONTROLCURRENTED_CCED_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCCONTROLCURRENTED;
	tmp = (tmp & UHP_HCCONTROLCURRENTED_CCED_Msk) >> UHP_HCCONTROLCURRENTED_CCED_Pos;
	return tmp;
}

static inline void hri_uhp_set_HCCONTROLCURRENTED_reg(const void *const hw, hri_uhp_hccontrolcurrented_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROLCURRENTED |= mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hccontrolcurrented_reg_t hri_uhp_get_HCCONTROLCURRENTED_reg(const void *const                hw,
                                                                                  hri_uhp_hccontrolcurrented_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCCONTROLCURRENTED;
	tmp &= mask;
	return tmp;
}

static inline void hri_uhp_write_HCCONTROLCURRENTED_reg(const void *const hw, hri_uhp_hccontrolcurrented_reg_t data)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROLCURRENTED = data;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCCONTROLCURRENTED_reg(const void *const hw, hri_uhp_hccontrolcurrented_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROLCURRENTED &= ~mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCCONTROLCURRENTED_reg(const void *const hw, hri_uhp_hccontrolcurrented_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCONTROLCURRENTED ^= mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hccontrolcurrented_reg_t hri_uhp_read_HCCONTROLCURRENTED_reg(const void *const hw)
{
	return ((Uhp *)hw)->UHP_HCCONTROLCURRENTED;
}

static inline void hri_uhp_set_HCBULKHEADED_BHED_bf(const void *const hw, hri_uhp_hcbulkheaded_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCBULKHEADED |= UHP_HCBULKHEADED_BHED(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcbulkheaded_reg_t hri_uhp_get_HCBULKHEADED_BHED_bf(const void *const          hw,
                                                                          hri_uhp_hcbulkheaded_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCBULKHEADED;
	tmp = (tmp & UHP_HCBULKHEADED_BHED(mask)) >> UHP_HCBULKHEADED_BHED_Pos;
	return tmp;
}

static inline void hri_uhp_write_HCBULKHEADED_BHED_bf(const void *const hw, hri_uhp_hcbulkheaded_reg_t data)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCBULKHEADED;
	tmp &= ~UHP_HCBULKHEADED_BHED_Msk;
	tmp |= UHP_HCBULKHEADED_BHED(data);
	((Uhp *)hw)->UHP_HCBULKHEADED = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCBULKHEADED_BHED_bf(const void *const hw, hri_uhp_hcbulkheaded_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCBULKHEADED &= ~UHP_HCBULKHEADED_BHED(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCBULKHEADED_BHED_bf(const void *const hw, hri_uhp_hcbulkheaded_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCBULKHEADED ^= UHP_HCBULKHEADED_BHED(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcbulkheaded_reg_t hri_uhp_read_HCBULKHEADED_BHED_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCBULKHEADED;
	tmp = (tmp & UHP_HCBULKHEADED_BHED_Msk) >> UHP_HCBULKHEADED_BHED_Pos;
	return tmp;
}

static inline void hri_uhp_set_HCBULKHEADED_reg(const void *const hw, hri_uhp_hcbulkheaded_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCBULKHEADED |= mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcbulkheaded_reg_t hri_uhp_get_HCBULKHEADED_reg(const void *const          hw,
                                                                      hri_uhp_hcbulkheaded_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCBULKHEADED;
	tmp &= mask;
	return tmp;
}

static inline void hri_uhp_write_HCBULKHEADED_reg(const void *const hw, hri_uhp_hcbulkheaded_reg_t data)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCBULKHEADED = data;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCBULKHEADED_reg(const void *const hw, hri_uhp_hcbulkheaded_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCBULKHEADED &= ~mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCBULKHEADED_reg(const void *const hw, hri_uhp_hcbulkheaded_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCBULKHEADED ^= mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcbulkheaded_reg_t hri_uhp_read_HCBULKHEADED_reg(const void *const hw)
{
	return ((Uhp *)hw)->UHP_HCBULKHEADED;
}

static inline void hri_uhp_set_HCBULKCURRENTED_BCED_bf(const void *const hw, hri_uhp_hcbulkcurrented_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCBULKCURRENTED |= UHP_HCBULKCURRENTED_BCED(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcbulkcurrented_reg_t hri_uhp_get_HCBULKCURRENTED_BCED_bf(const void *const             hw,
                                                                                hri_uhp_hcbulkcurrented_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCBULKCURRENTED;
	tmp = (tmp & UHP_HCBULKCURRENTED_BCED(mask)) >> UHP_HCBULKCURRENTED_BCED_Pos;
	return tmp;
}

static inline void hri_uhp_write_HCBULKCURRENTED_BCED_bf(const void *const hw, hri_uhp_hcbulkcurrented_reg_t data)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCBULKCURRENTED;
	tmp &= ~UHP_HCBULKCURRENTED_BCED_Msk;
	tmp |= UHP_HCBULKCURRENTED_BCED(data);
	((Uhp *)hw)->UHP_HCBULKCURRENTED = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCBULKCURRENTED_BCED_bf(const void *const hw, hri_uhp_hcbulkcurrented_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCBULKCURRENTED &= ~UHP_HCBULKCURRENTED_BCED(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCBULKCURRENTED_BCED_bf(const void *const hw, hri_uhp_hcbulkcurrented_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCBULKCURRENTED ^= UHP_HCBULKCURRENTED_BCED(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcbulkcurrented_reg_t hri_uhp_read_HCBULKCURRENTED_BCED_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCBULKCURRENTED;
	tmp = (tmp & UHP_HCBULKCURRENTED_BCED_Msk) >> UHP_HCBULKCURRENTED_BCED_Pos;
	return tmp;
}

static inline void hri_uhp_set_HCBULKCURRENTED_reg(const void *const hw, hri_uhp_hcbulkcurrented_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCBULKCURRENTED |= mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcbulkcurrented_reg_t hri_uhp_get_HCBULKCURRENTED_reg(const void *const             hw,
                                                                            hri_uhp_hcbulkcurrented_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCBULKCURRENTED;
	tmp &= mask;
	return tmp;
}

static inline void hri_uhp_write_HCBULKCURRENTED_reg(const void *const hw, hri_uhp_hcbulkcurrented_reg_t data)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCBULKCURRENTED = data;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCBULKCURRENTED_reg(const void *const hw, hri_uhp_hcbulkcurrented_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCBULKCURRENTED &= ~mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCBULKCURRENTED_reg(const void *const hw, hri_uhp_hcbulkcurrented_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCBULKCURRENTED ^= mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcbulkcurrented_reg_t hri_uhp_read_HCBULKCURRENTED_reg(const void *const hw)
{
	return ((Uhp *)hw)->UHP_HCBULKCURRENTED;
}

static inline void hri_uhp_set_HCFMINTERVAL_FIT_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCFMINTERVAL |= UHP_HCFMINTERVAL_FIT;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCFMINTERVAL_FIT_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCFMINTERVAL;
	tmp = (tmp & UHP_HCFMINTERVAL_FIT) >> UHP_HCFMINTERVAL_FIT_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCFMINTERVAL_FIT_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCFMINTERVAL;
	tmp &= ~UHP_HCFMINTERVAL_FIT;
	tmp |= value << UHP_HCFMINTERVAL_FIT_Pos;
	((Uhp *)hw)->UHP_HCFMINTERVAL = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCFMINTERVAL_FIT_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCFMINTERVAL &= ~UHP_HCFMINTERVAL_FIT;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCFMINTERVAL_FIT_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCFMINTERVAL ^= UHP_HCFMINTERVAL_FIT;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCFMINTERVAL_FRAMEINTERVAL_bf(const void *const hw, hri_uhp_hcfminterval_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCFMINTERVAL |= UHP_HCFMINTERVAL_FRAMEINTERVAL(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcfminterval_reg_t hri_uhp_get_HCFMINTERVAL_FRAMEINTERVAL_bf(const void *const          hw,
                                                                                   hri_uhp_hcfminterval_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCFMINTERVAL;
	tmp = (tmp & UHP_HCFMINTERVAL_FRAMEINTERVAL(mask)) >> UHP_HCFMINTERVAL_FRAMEINTERVAL_Pos;
	return tmp;
}

static inline void hri_uhp_write_HCFMINTERVAL_FRAMEINTERVAL_bf(const void *const hw, hri_uhp_hcfminterval_reg_t data)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCFMINTERVAL;
	tmp &= ~UHP_HCFMINTERVAL_FRAMEINTERVAL_Msk;
	tmp |= UHP_HCFMINTERVAL_FRAMEINTERVAL(data);
	((Uhp *)hw)->UHP_HCFMINTERVAL = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCFMINTERVAL_FRAMEINTERVAL_bf(const void *const hw, hri_uhp_hcfminterval_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCFMINTERVAL &= ~UHP_HCFMINTERVAL_FRAMEINTERVAL(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCFMINTERVAL_FRAMEINTERVAL_bf(const void *const hw, hri_uhp_hcfminterval_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCFMINTERVAL ^= UHP_HCFMINTERVAL_FRAMEINTERVAL(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcfminterval_reg_t hri_uhp_read_HCFMINTERVAL_FRAMEINTERVAL_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCFMINTERVAL;
	tmp = (tmp & UHP_HCFMINTERVAL_FRAMEINTERVAL_Msk) >> UHP_HCFMINTERVAL_FRAMEINTERVAL_Pos;
	return tmp;
}

static inline void hri_uhp_set_HCFMINTERVAL_FSMPS_bf(const void *const hw, hri_uhp_hcfminterval_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCFMINTERVAL |= UHP_HCFMINTERVAL_FSMPS(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcfminterval_reg_t hri_uhp_get_HCFMINTERVAL_FSMPS_bf(const void *const          hw,
                                                                           hri_uhp_hcfminterval_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCFMINTERVAL;
	tmp = (tmp & UHP_HCFMINTERVAL_FSMPS(mask)) >> UHP_HCFMINTERVAL_FSMPS_Pos;
	return tmp;
}

static inline void hri_uhp_write_HCFMINTERVAL_FSMPS_bf(const void *const hw, hri_uhp_hcfminterval_reg_t data)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCFMINTERVAL;
	tmp &= ~UHP_HCFMINTERVAL_FSMPS_Msk;
	tmp |= UHP_HCFMINTERVAL_FSMPS(data);
	((Uhp *)hw)->UHP_HCFMINTERVAL = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCFMINTERVAL_FSMPS_bf(const void *const hw, hri_uhp_hcfminterval_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCFMINTERVAL &= ~UHP_HCFMINTERVAL_FSMPS(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCFMINTERVAL_FSMPS_bf(const void *const hw, hri_uhp_hcfminterval_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCFMINTERVAL ^= UHP_HCFMINTERVAL_FSMPS(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcfminterval_reg_t hri_uhp_read_HCFMINTERVAL_FSMPS_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCFMINTERVAL;
	tmp = (tmp & UHP_HCFMINTERVAL_FSMPS_Msk) >> UHP_HCFMINTERVAL_FSMPS_Pos;
	return tmp;
}

static inline void hri_uhp_set_HCFMINTERVAL_reg(const void *const hw, hri_uhp_hcfminterval_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCFMINTERVAL |= mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcfminterval_reg_t hri_uhp_get_HCFMINTERVAL_reg(const void *const          hw,
                                                                      hri_uhp_hcfminterval_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCFMINTERVAL;
	tmp &= mask;
	return tmp;
}

static inline void hri_uhp_write_HCFMINTERVAL_reg(const void *const hw, hri_uhp_hcfminterval_reg_t data)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCFMINTERVAL = data;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCFMINTERVAL_reg(const void *const hw, hri_uhp_hcfminterval_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCFMINTERVAL &= ~mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCFMINTERVAL_reg(const void *const hw, hri_uhp_hcfminterval_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCFMINTERVAL ^= mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcfminterval_reg_t hri_uhp_read_HCFMINTERVAL_reg(const void *const hw)
{
	return ((Uhp *)hw)->UHP_HCFMINTERVAL;
}

static inline void hri_uhp_set_HCPERIODICSTART_PS_bf(const void *const hw, hri_uhp_hcperiodicstart_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCPERIODICSTART |= UHP_HCPERIODICSTART_PS(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcperiodicstart_reg_t hri_uhp_get_HCPERIODICSTART_PS_bf(const void *const             hw,
                                                                              hri_uhp_hcperiodicstart_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCPERIODICSTART;
	tmp = (tmp & UHP_HCPERIODICSTART_PS(mask)) >> UHP_HCPERIODICSTART_PS_Pos;
	return tmp;
}

static inline void hri_uhp_write_HCPERIODICSTART_PS_bf(const void *const hw, hri_uhp_hcperiodicstart_reg_t data)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCPERIODICSTART;
	tmp &= ~UHP_HCPERIODICSTART_PS_Msk;
	tmp |= UHP_HCPERIODICSTART_PS(data);
	((Uhp *)hw)->UHP_HCPERIODICSTART = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCPERIODICSTART_PS_bf(const void *const hw, hri_uhp_hcperiodicstart_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCPERIODICSTART &= ~UHP_HCPERIODICSTART_PS(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCPERIODICSTART_PS_bf(const void *const hw, hri_uhp_hcperiodicstart_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCPERIODICSTART ^= UHP_HCPERIODICSTART_PS(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcperiodicstart_reg_t hri_uhp_read_HCPERIODICSTART_PS_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCPERIODICSTART;
	tmp = (tmp & UHP_HCPERIODICSTART_PS_Msk) >> UHP_HCPERIODICSTART_PS_Pos;
	return tmp;
}

static inline void hri_uhp_set_HCPERIODICSTART_reg(const void *const hw, hri_uhp_hcperiodicstart_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCPERIODICSTART |= mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcperiodicstart_reg_t hri_uhp_get_HCPERIODICSTART_reg(const void *const             hw,
                                                                            hri_uhp_hcperiodicstart_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCPERIODICSTART;
	tmp &= mask;
	return tmp;
}

static inline void hri_uhp_write_HCPERIODICSTART_reg(const void *const hw, hri_uhp_hcperiodicstart_reg_t data)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCPERIODICSTART = data;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCPERIODICSTART_reg(const void *const hw, hri_uhp_hcperiodicstart_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCPERIODICSTART &= ~mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCPERIODICSTART_reg(const void *const hw, hri_uhp_hcperiodicstart_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCPERIODICSTART ^= mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcperiodicstart_reg_t hri_uhp_read_HCPERIODICSTART_reg(const void *const hw)
{
	return ((Uhp *)hw)->UHP_HCPERIODICSTART;
}

static inline void hri_uhp_set_HCLSTHRESHOLD_LST_bf(const void *const hw, hri_uhp_hclsthreshold_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCLSTHRESHOLD |= UHP_HCLSTHRESHOLD_LST(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hclsthreshold_reg_t hri_uhp_get_HCLSTHRESHOLD_LST_bf(const void *const           hw,
                                                                           hri_uhp_hclsthreshold_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCLSTHRESHOLD;
	tmp = (tmp & UHP_HCLSTHRESHOLD_LST(mask)) >> UHP_HCLSTHRESHOLD_LST_Pos;
	return tmp;
}

static inline void hri_uhp_write_HCLSTHRESHOLD_LST_bf(const void *const hw, hri_uhp_hclsthreshold_reg_t data)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCLSTHRESHOLD;
	tmp &= ~UHP_HCLSTHRESHOLD_LST_Msk;
	tmp |= UHP_HCLSTHRESHOLD_LST(data);
	((Uhp *)hw)->UHP_HCLSTHRESHOLD = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCLSTHRESHOLD_LST_bf(const void *const hw, hri_uhp_hclsthreshold_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCLSTHRESHOLD &= ~UHP_HCLSTHRESHOLD_LST(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCLSTHRESHOLD_LST_bf(const void *const hw, hri_uhp_hclsthreshold_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCLSTHRESHOLD ^= UHP_HCLSTHRESHOLD_LST(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hclsthreshold_reg_t hri_uhp_read_HCLSTHRESHOLD_LST_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCLSTHRESHOLD;
	tmp = (tmp & UHP_HCLSTHRESHOLD_LST_Msk) >> UHP_HCLSTHRESHOLD_LST_Pos;
	return tmp;
}

static inline void hri_uhp_set_HCLSTHRESHOLD_reg(const void *const hw, hri_uhp_hclsthreshold_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCLSTHRESHOLD |= mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hclsthreshold_reg_t hri_uhp_get_HCLSTHRESHOLD_reg(const void *const           hw,
                                                                        hri_uhp_hclsthreshold_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCLSTHRESHOLD;
	tmp &= mask;
	return tmp;
}

static inline void hri_uhp_write_HCLSTHRESHOLD_reg(const void *const hw, hri_uhp_hclsthreshold_reg_t data)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCLSTHRESHOLD = data;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCLSTHRESHOLD_reg(const void *const hw, hri_uhp_hclsthreshold_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCLSTHRESHOLD &= ~mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCLSTHRESHOLD_reg(const void *const hw, hri_uhp_hclsthreshold_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCLSTHRESHOLD ^= mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hclsthreshold_reg_t hri_uhp_read_HCLSTHRESHOLD_reg(const void *const hw)
{
	return ((Uhp *)hw)->UHP_HCLSTHRESHOLD;
}

static inline void hri_uhp_set_HCRHDESCRIPTORA_PSM_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORA |= UHP_HCRHDESCRIPTORA_PSM;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORA_PSM_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORA;
	tmp = (tmp & UHP_HCRHDESCRIPTORA_PSM) >> UHP_HCRHDESCRIPTORA_PSM_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORA_PSM_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORA;
	tmp &= ~UHP_HCRHDESCRIPTORA_PSM;
	tmp |= value << UHP_HCRHDESCRIPTORA_PSM_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORA = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORA_PSM_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORA &= ~UHP_HCRHDESCRIPTORA_PSM;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORA_PSM_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORA ^= UHP_HCRHDESCRIPTORA_PSM;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORA_NPS_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORA |= UHP_HCRHDESCRIPTORA_NPS;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORA_NPS_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORA;
	tmp = (tmp & UHP_HCRHDESCRIPTORA_NPS) >> UHP_HCRHDESCRIPTORA_NPS_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORA_NPS_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORA;
	tmp &= ~UHP_HCRHDESCRIPTORA_NPS;
	tmp |= value << UHP_HCRHDESCRIPTORA_NPS_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORA = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORA_NPS_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORA &= ~UHP_HCRHDESCRIPTORA_NPS;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORA_NPS_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORA ^= UHP_HCRHDESCRIPTORA_NPS;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORA_DT_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORA |= UHP_HCRHDESCRIPTORA_DT;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORA_DT_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORA;
	tmp = (tmp & UHP_HCRHDESCRIPTORA_DT) >> UHP_HCRHDESCRIPTORA_DT_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORA_DT_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORA;
	tmp &= ~UHP_HCRHDESCRIPTORA_DT;
	tmp |= value << UHP_HCRHDESCRIPTORA_DT_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORA = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORA_DT_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORA &= ~UHP_HCRHDESCRIPTORA_DT;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORA_DT_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORA ^= UHP_HCRHDESCRIPTORA_DT;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORA_OCPM_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORA |= UHP_HCRHDESCRIPTORA_OCPM;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORA_OCPM_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORA;
	tmp = (tmp & UHP_HCRHDESCRIPTORA_OCPM) >> UHP_HCRHDESCRIPTORA_OCPM_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORA_OCPM_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORA;
	tmp &= ~UHP_HCRHDESCRIPTORA_OCPM;
	tmp |= value << UHP_HCRHDESCRIPTORA_OCPM_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORA = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORA_OCPM_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORA &= ~UHP_HCRHDESCRIPTORA_OCPM;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORA_OCPM_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORA ^= UHP_HCRHDESCRIPTORA_OCPM;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORA_NOCP_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORA |= UHP_HCRHDESCRIPTORA_NOCP;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORA_NOCP_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORA;
	tmp = (tmp & UHP_HCRHDESCRIPTORA_NOCP) >> UHP_HCRHDESCRIPTORA_NOCP_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORA_NOCP_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORA;
	tmp &= ~UHP_HCRHDESCRIPTORA_NOCP;
	tmp |= value << UHP_HCRHDESCRIPTORA_NOCP_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORA = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORA_NOCP_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORA &= ~UHP_HCRHDESCRIPTORA_NOCP;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORA_NOCP_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORA ^= UHP_HCRHDESCRIPTORA_NOCP;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORA_NDP_bf(const void *const hw, hri_uhp_hcrhdescriptora_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORA |= UHP_HCRHDESCRIPTORA_NDP(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcrhdescriptora_reg_t hri_uhp_get_HCRHDESCRIPTORA_NDP_bf(const void *const             hw,
                                                                               hri_uhp_hcrhdescriptora_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORA;
	tmp = (tmp & UHP_HCRHDESCRIPTORA_NDP(mask)) >> UHP_HCRHDESCRIPTORA_NDP_Pos;
	return tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORA_NDP_bf(const void *const hw, hri_uhp_hcrhdescriptora_reg_t data)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORA;
	tmp &= ~UHP_HCRHDESCRIPTORA_NDP_Msk;
	tmp |= UHP_HCRHDESCRIPTORA_NDP(data);
	((Uhp *)hw)->UHP_HCRHDESCRIPTORA = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORA_NDP_bf(const void *const hw, hri_uhp_hcrhdescriptora_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORA &= ~UHP_HCRHDESCRIPTORA_NDP(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORA_NDP_bf(const void *const hw, hri_uhp_hcrhdescriptora_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORA ^= UHP_HCRHDESCRIPTORA_NDP(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcrhdescriptora_reg_t hri_uhp_read_HCRHDESCRIPTORA_NDP_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORA;
	tmp = (tmp & UHP_HCRHDESCRIPTORA_NDP_Msk) >> UHP_HCRHDESCRIPTORA_NDP_Pos;
	return tmp;
}

static inline void hri_uhp_set_HCRHDESCRIPTORA_POTPG_bf(const void *const hw, hri_uhp_hcrhdescriptora_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORA |= UHP_HCRHDESCRIPTORA_POTPG(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcrhdescriptora_reg_t hri_uhp_get_HCRHDESCRIPTORA_POTPG_bf(const void *const             hw,
                                                                                 hri_uhp_hcrhdescriptora_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORA;
	tmp = (tmp & UHP_HCRHDESCRIPTORA_POTPG(mask)) >> UHP_HCRHDESCRIPTORA_POTPG_Pos;
	return tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORA_POTPG_bf(const void *const hw, hri_uhp_hcrhdescriptora_reg_t data)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORA;
	tmp &= ~UHP_HCRHDESCRIPTORA_POTPG_Msk;
	tmp |= UHP_HCRHDESCRIPTORA_POTPG(data);
	((Uhp *)hw)->UHP_HCRHDESCRIPTORA = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORA_POTPG_bf(const void *const hw, hri_uhp_hcrhdescriptora_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORA &= ~UHP_HCRHDESCRIPTORA_POTPG(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORA_POTPG_bf(const void *const hw, hri_uhp_hcrhdescriptora_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORA ^= UHP_HCRHDESCRIPTORA_POTPG(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcrhdescriptora_reg_t hri_uhp_read_HCRHDESCRIPTORA_POTPG_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORA;
	tmp = (tmp & UHP_HCRHDESCRIPTORA_POTPG_Msk) >> UHP_HCRHDESCRIPTORA_POTPG_Pos;
	return tmp;
}

static inline void hri_uhp_set_HCRHDESCRIPTORA_reg(const void *const hw, hri_uhp_hcrhdescriptora_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORA |= mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcrhdescriptora_reg_t hri_uhp_get_HCRHDESCRIPTORA_reg(const void *const             hw,
                                                                            hri_uhp_hcrhdescriptora_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORA;
	tmp &= mask;
	return tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORA_reg(const void *const hw, hri_uhp_hcrhdescriptora_reg_t data)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORA = data;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORA_reg(const void *const hw, hri_uhp_hcrhdescriptora_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORA &= ~mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORA_reg(const void *const hw, hri_uhp_hcrhdescriptora_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORA ^= mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcrhdescriptora_reg_t hri_uhp_read_HCRHDESCRIPTORA_reg(const void *const hw)
{
	return ((Uhp *)hw)->UHP_HCRHDESCRIPTORA;
}

static inline void hri_uhp_set_HCRHDESCRIPTORB_DR0_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB |= UHP_HCRHDESCRIPTORB_DR0;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORB_DR0_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp = (tmp & UHP_HCRHDESCRIPTORB_DR0) >> UHP_HCRHDESCRIPTORB_DR0_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORB_DR0_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp &= ~UHP_HCRHDESCRIPTORB_DR0;
	tmp |= value << UHP_HCRHDESCRIPTORB_DR0_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORB_DR0_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB &= ~UHP_HCRHDESCRIPTORB_DR0;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORB_DR0_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB ^= UHP_HCRHDESCRIPTORB_DR0;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORB_DR1_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB |= UHP_HCRHDESCRIPTORB_DR1;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORB_DR1_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp = (tmp & UHP_HCRHDESCRIPTORB_DR1) >> UHP_HCRHDESCRIPTORB_DR1_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORB_DR1_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp &= ~UHP_HCRHDESCRIPTORB_DR1;
	tmp |= value << UHP_HCRHDESCRIPTORB_DR1_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORB_DR1_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB &= ~UHP_HCRHDESCRIPTORB_DR1;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORB_DR1_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB ^= UHP_HCRHDESCRIPTORB_DR1;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORB_DR2_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB |= UHP_HCRHDESCRIPTORB_DR2;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORB_DR2_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp = (tmp & UHP_HCRHDESCRIPTORB_DR2) >> UHP_HCRHDESCRIPTORB_DR2_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORB_DR2_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp &= ~UHP_HCRHDESCRIPTORB_DR2;
	tmp |= value << UHP_HCRHDESCRIPTORB_DR2_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORB_DR2_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB &= ~UHP_HCRHDESCRIPTORB_DR2;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORB_DR2_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB ^= UHP_HCRHDESCRIPTORB_DR2;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORB_DR3_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB |= UHP_HCRHDESCRIPTORB_DR3;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORB_DR3_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp = (tmp & UHP_HCRHDESCRIPTORB_DR3) >> UHP_HCRHDESCRIPTORB_DR3_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORB_DR3_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp &= ~UHP_HCRHDESCRIPTORB_DR3;
	tmp |= value << UHP_HCRHDESCRIPTORB_DR3_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORB_DR3_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB &= ~UHP_HCRHDESCRIPTORB_DR3;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORB_DR3_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB ^= UHP_HCRHDESCRIPTORB_DR3;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORB_DR4_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB |= UHP_HCRHDESCRIPTORB_DR4;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORB_DR4_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp = (tmp & UHP_HCRHDESCRIPTORB_DR4) >> UHP_HCRHDESCRIPTORB_DR4_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORB_DR4_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp &= ~UHP_HCRHDESCRIPTORB_DR4;
	tmp |= value << UHP_HCRHDESCRIPTORB_DR4_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORB_DR4_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB &= ~UHP_HCRHDESCRIPTORB_DR4;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORB_DR4_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB ^= UHP_HCRHDESCRIPTORB_DR4;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORB_DR5_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB |= UHP_HCRHDESCRIPTORB_DR5;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORB_DR5_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp = (tmp & UHP_HCRHDESCRIPTORB_DR5) >> UHP_HCRHDESCRIPTORB_DR5_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORB_DR5_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp &= ~UHP_HCRHDESCRIPTORB_DR5;
	tmp |= value << UHP_HCRHDESCRIPTORB_DR5_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORB_DR5_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB &= ~UHP_HCRHDESCRIPTORB_DR5;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORB_DR5_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB ^= UHP_HCRHDESCRIPTORB_DR5;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORB_DR6_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB |= UHP_HCRHDESCRIPTORB_DR6;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORB_DR6_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp = (tmp & UHP_HCRHDESCRIPTORB_DR6) >> UHP_HCRHDESCRIPTORB_DR6_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORB_DR6_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp &= ~UHP_HCRHDESCRIPTORB_DR6;
	tmp |= value << UHP_HCRHDESCRIPTORB_DR6_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORB_DR6_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB &= ~UHP_HCRHDESCRIPTORB_DR6;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORB_DR6_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB ^= UHP_HCRHDESCRIPTORB_DR6;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORB_DR7_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB |= UHP_HCRHDESCRIPTORB_DR7;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORB_DR7_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp = (tmp & UHP_HCRHDESCRIPTORB_DR7) >> UHP_HCRHDESCRIPTORB_DR7_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORB_DR7_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp &= ~UHP_HCRHDESCRIPTORB_DR7;
	tmp |= value << UHP_HCRHDESCRIPTORB_DR7_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORB_DR7_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB &= ~UHP_HCRHDESCRIPTORB_DR7;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORB_DR7_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB ^= UHP_HCRHDESCRIPTORB_DR7;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORB_DR8_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB |= UHP_HCRHDESCRIPTORB_DR8;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORB_DR8_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp = (tmp & UHP_HCRHDESCRIPTORB_DR8) >> UHP_HCRHDESCRIPTORB_DR8_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORB_DR8_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp &= ~UHP_HCRHDESCRIPTORB_DR8;
	tmp |= value << UHP_HCRHDESCRIPTORB_DR8_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORB_DR8_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB &= ~UHP_HCRHDESCRIPTORB_DR8;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORB_DR8_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB ^= UHP_HCRHDESCRIPTORB_DR8;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORB_DR9_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB |= UHP_HCRHDESCRIPTORB_DR9;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORB_DR9_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp = (tmp & UHP_HCRHDESCRIPTORB_DR9) >> UHP_HCRHDESCRIPTORB_DR9_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORB_DR9_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp &= ~UHP_HCRHDESCRIPTORB_DR9;
	tmp |= value << UHP_HCRHDESCRIPTORB_DR9_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORB_DR9_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB &= ~UHP_HCRHDESCRIPTORB_DR9;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORB_DR9_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB ^= UHP_HCRHDESCRIPTORB_DR9;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORB_DR10_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB |= UHP_HCRHDESCRIPTORB_DR10;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORB_DR10_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp = (tmp & UHP_HCRHDESCRIPTORB_DR10) >> UHP_HCRHDESCRIPTORB_DR10_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORB_DR10_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp &= ~UHP_HCRHDESCRIPTORB_DR10;
	tmp |= value << UHP_HCRHDESCRIPTORB_DR10_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORB_DR10_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB &= ~UHP_HCRHDESCRIPTORB_DR10;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORB_DR10_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB ^= UHP_HCRHDESCRIPTORB_DR10;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORB_DR11_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB |= UHP_HCRHDESCRIPTORB_DR11;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORB_DR11_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp = (tmp & UHP_HCRHDESCRIPTORB_DR11) >> UHP_HCRHDESCRIPTORB_DR11_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORB_DR11_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp &= ~UHP_HCRHDESCRIPTORB_DR11;
	tmp |= value << UHP_HCRHDESCRIPTORB_DR11_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORB_DR11_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB &= ~UHP_HCRHDESCRIPTORB_DR11;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORB_DR11_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB ^= UHP_HCRHDESCRIPTORB_DR11;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORB_DR12_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB |= UHP_HCRHDESCRIPTORB_DR12;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORB_DR12_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp = (tmp & UHP_HCRHDESCRIPTORB_DR12) >> UHP_HCRHDESCRIPTORB_DR12_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORB_DR12_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp &= ~UHP_HCRHDESCRIPTORB_DR12;
	tmp |= value << UHP_HCRHDESCRIPTORB_DR12_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORB_DR12_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB &= ~UHP_HCRHDESCRIPTORB_DR12;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORB_DR12_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB ^= UHP_HCRHDESCRIPTORB_DR12;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORB_DR13_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB |= UHP_HCRHDESCRIPTORB_DR13;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORB_DR13_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp = (tmp & UHP_HCRHDESCRIPTORB_DR13) >> UHP_HCRHDESCRIPTORB_DR13_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORB_DR13_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp &= ~UHP_HCRHDESCRIPTORB_DR13;
	tmp |= value << UHP_HCRHDESCRIPTORB_DR13_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORB_DR13_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB &= ~UHP_HCRHDESCRIPTORB_DR13;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORB_DR13_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB ^= UHP_HCRHDESCRIPTORB_DR13;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORB_DR14_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB |= UHP_HCRHDESCRIPTORB_DR14;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORB_DR14_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp = (tmp & UHP_HCRHDESCRIPTORB_DR14) >> UHP_HCRHDESCRIPTORB_DR14_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORB_DR14_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp &= ~UHP_HCRHDESCRIPTORB_DR14;
	tmp |= value << UHP_HCRHDESCRIPTORB_DR14_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORB_DR14_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB &= ~UHP_HCRHDESCRIPTORB_DR14;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORB_DR14_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB ^= UHP_HCRHDESCRIPTORB_DR14;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORB_DR15_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB |= UHP_HCRHDESCRIPTORB_DR15;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORB_DR15_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp = (tmp & UHP_HCRHDESCRIPTORB_DR15) >> UHP_HCRHDESCRIPTORB_DR15_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORB_DR15_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp &= ~UHP_HCRHDESCRIPTORB_DR15;
	tmp |= value << UHP_HCRHDESCRIPTORB_DR15_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORB_DR15_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB &= ~UHP_HCRHDESCRIPTORB_DR15;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORB_DR15_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB ^= UHP_HCRHDESCRIPTORB_DR15;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORB_PPCM0_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB |= UHP_HCRHDESCRIPTORB_PPCM0;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORB_PPCM0_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp = (tmp & UHP_HCRHDESCRIPTORB_PPCM0) >> UHP_HCRHDESCRIPTORB_PPCM0_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORB_PPCM0_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp &= ~UHP_HCRHDESCRIPTORB_PPCM0;
	tmp |= value << UHP_HCRHDESCRIPTORB_PPCM0_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORB_PPCM0_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB &= ~UHP_HCRHDESCRIPTORB_PPCM0;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORB_PPCM0_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB ^= UHP_HCRHDESCRIPTORB_PPCM0;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORB_PPCM1_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB |= UHP_HCRHDESCRIPTORB_PPCM1;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORB_PPCM1_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp = (tmp & UHP_HCRHDESCRIPTORB_PPCM1) >> UHP_HCRHDESCRIPTORB_PPCM1_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORB_PPCM1_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp &= ~UHP_HCRHDESCRIPTORB_PPCM1;
	tmp |= value << UHP_HCRHDESCRIPTORB_PPCM1_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORB_PPCM1_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB &= ~UHP_HCRHDESCRIPTORB_PPCM1;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORB_PPCM1_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB ^= UHP_HCRHDESCRIPTORB_PPCM1;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORB_PPCM2_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB |= UHP_HCRHDESCRIPTORB_PPCM2;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORB_PPCM2_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp = (tmp & UHP_HCRHDESCRIPTORB_PPCM2) >> UHP_HCRHDESCRIPTORB_PPCM2_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORB_PPCM2_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp &= ~UHP_HCRHDESCRIPTORB_PPCM2;
	tmp |= value << UHP_HCRHDESCRIPTORB_PPCM2_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORB_PPCM2_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB &= ~UHP_HCRHDESCRIPTORB_PPCM2;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORB_PPCM2_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB ^= UHP_HCRHDESCRIPTORB_PPCM2;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORB_PPCM3_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB |= UHP_HCRHDESCRIPTORB_PPCM3;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORB_PPCM3_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp = (tmp & UHP_HCRHDESCRIPTORB_PPCM3) >> UHP_HCRHDESCRIPTORB_PPCM3_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORB_PPCM3_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp &= ~UHP_HCRHDESCRIPTORB_PPCM3;
	tmp |= value << UHP_HCRHDESCRIPTORB_PPCM3_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORB_PPCM3_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB &= ~UHP_HCRHDESCRIPTORB_PPCM3;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORB_PPCM3_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB ^= UHP_HCRHDESCRIPTORB_PPCM3;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORB_PPCM4_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB |= UHP_HCRHDESCRIPTORB_PPCM4;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORB_PPCM4_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp = (tmp & UHP_HCRHDESCRIPTORB_PPCM4) >> UHP_HCRHDESCRIPTORB_PPCM4_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORB_PPCM4_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp &= ~UHP_HCRHDESCRIPTORB_PPCM4;
	tmp |= value << UHP_HCRHDESCRIPTORB_PPCM4_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORB_PPCM4_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB &= ~UHP_HCRHDESCRIPTORB_PPCM4;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORB_PPCM4_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB ^= UHP_HCRHDESCRIPTORB_PPCM4;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORB_PPCM5_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB |= UHP_HCRHDESCRIPTORB_PPCM5;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORB_PPCM5_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp = (tmp & UHP_HCRHDESCRIPTORB_PPCM5) >> UHP_HCRHDESCRIPTORB_PPCM5_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORB_PPCM5_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp &= ~UHP_HCRHDESCRIPTORB_PPCM5;
	tmp |= value << UHP_HCRHDESCRIPTORB_PPCM5_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORB_PPCM5_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB &= ~UHP_HCRHDESCRIPTORB_PPCM5;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORB_PPCM5_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB ^= UHP_HCRHDESCRIPTORB_PPCM5;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORB_PPCM6_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB |= UHP_HCRHDESCRIPTORB_PPCM6;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORB_PPCM6_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp = (tmp & UHP_HCRHDESCRIPTORB_PPCM6) >> UHP_HCRHDESCRIPTORB_PPCM6_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORB_PPCM6_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp &= ~UHP_HCRHDESCRIPTORB_PPCM6;
	tmp |= value << UHP_HCRHDESCRIPTORB_PPCM6_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORB_PPCM6_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB &= ~UHP_HCRHDESCRIPTORB_PPCM6;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORB_PPCM6_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB ^= UHP_HCRHDESCRIPTORB_PPCM6;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORB_PPCM7_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB |= UHP_HCRHDESCRIPTORB_PPCM7;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORB_PPCM7_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp = (tmp & UHP_HCRHDESCRIPTORB_PPCM7) >> UHP_HCRHDESCRIPTORB_PPCM7_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORB_PPCM7_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp &= ~UHP_HCRHDESCRIPTORB_PPCM7;
	tmp |= value << UHP_HCRHDESCRIPTORB_PPCM7_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORB_PPCM7_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB &= ~UHP_HCRHDESCRIPTORB_PPCM7;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORB_PPCM7_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB ^= UHP_HCRHDESCRIPTORB_PPCM7;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORB_PPCM8_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB |= UHP_HCRHDESCRIPTORB_PPCM8;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORB_PPCM8_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp = (tmp & UHP_HCRHDESCRIPTORB_PPCM8) >> UHP_HCRHDESCRIPTORB_PPCM8_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORB_PPCM8_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp &= ~UHP_HCRHDESCRIPTORB_PPCM8;
	tmp |= value << UHP_HCRHDESCRIPTORB_PPCM8_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORB_PPCM8_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB &= ~UHP_HCRHDESCRIPTORB_PPCM8;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORB_PPCM8_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB ^= UHP_HCRHDESCRIPTORB_PPCM8;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORB_PPCM9_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB |= UHP_HCRHDESCRIPTORB_PPCM9;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORB_PPCM9_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp = (tmp & UHP_HCRHDESCRIPTORB_PPCM9) >> UHP_HCRHDESCRIPTORB_PPCM9_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORB_PPCM9_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp &= ~UHP_HCRHDESCRIPTORB_PPCM9;
	tmp |= value << UHP_HCRHDESCRIPTORB_PPCM9_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORB_PPCM9_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB &= ~UHP_HCRHDESCRIPTORB_PPCM9;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORB_PPCM9_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB ^= UHP_HCRHDESCRIPTORB_PPCM9;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORB_PPCM10_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB |= UHP_HCRHDESCRIPTORB_PPCM10;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORB_PPCM10_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp = (tmp & UHP_HCRHDESCRIPTORB_PPCM10) >> UHP_HCRHDESCRIPTORB_PPCM10_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORB_PPCM10_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp &= ~UHP_HCRHDESCRIPTORB_PPCM10;
	tmp |= value << UHP_HCRHDESCRIPTORB_PPCM10_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORB_PPCM10_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB &= ~UHP_HCRHDESCRIPTORB_PPCM10;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORB_PPCM10_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB ^= UHP_HCRHDESCRIPTORB_PPCM10;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORB_PPCM11_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB |= UHP_HCRHDESCRIPTORB_PPCM11;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORB_PPCM11_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp = (tmp & UHP_HCRHDESCRIPTORB_PPCM11) >> UHP_HCRHDESCRIPTORB_PPCM11_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORB_PPCM11_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp &= ~UHP_HCRHDESCRIPTORB_PPCM11;
	tmp |= value << UHP_HCRHDESCRIPTORB_PPCM11_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORB_PPCM11_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB &= ~UHP_HCRHDESCRIPTORB_PPCM11;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORB_PPCM11_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB ^= UHP_HCRHDESCRIPTORB_PPCM11;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORB_PPCM12_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB |= UHP_HCRHDESCRIPTORB_PPCM12;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORB_PPCM12_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp = (tmp & UHP_HCRHDESCRIPTORB_PPCM12) >> UHP_HCRHDESCRIPTORB_PPCM12_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORB_PPCM12_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp &= ~UHP_HCRHDESCRIPTORB_PPCM12;
	tmp |= value << UHP_HCRHDESCRIPTORB_PPCM12_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORB_PPCM12_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB &= ~UHP_HCRHDESCRIPTORB_PPCM12;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORB_PPCM12_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB ^= UHP_HCRHDESCRIPTORB_PPCM12;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORB_PPCM13_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB |= UHP_HCRHDESCRIPTORB_PPCM13;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORB_PPCM13_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp = (tmp & UHP_HCRHDESCRIPTORB_PPCM13) >> UHP_HCRHDESCRIPTORB_PPCM13_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORB_PPCM13_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp &= ~UHP_HCRHDESCRIPTORB_PPCM13;
	tmp |= value << UHP_HCRHDESCRIPTORB_PPCM13_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORB_PPCM13_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB &= ~UHP_HCRHDESCRIPTORB_PPCM13;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORB_PPCM13_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB ^= UHP_HCRHDESCRIPTORB_PPCM13;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORB_PPCM14_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB |= UHP_HCRHDESCRIPTORB_PPCM14;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORB_PPCM14_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp = (tmp & UHP_HCRHDESCRIPTORB_PPCM14) >> UHP_HCRHDESCRIPTORB_PPCM14_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORB_PPCM14_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp &= ~UHP_HCRHDESCRIPTORB_PPCM14;
	tmp |= value << UHP_HCRHDESCRIPTORB_PPCM14_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORB_PPCM14_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB &= ~UHP_HCRHDESCRIPTORB_PPCM14;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORB_PPCM14_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB ^= UHP_HCRHDESCRIPTORB_PPCM14;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORB_PPCM15_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB |= UHP_HCRHDESCRIPTORB_PPCM15;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHDESCRIPTORB_PPCM15_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp = (tmp & UHP_HCRHDESCRIPTORB_PPCM15) >> UHP_HCRHDESCRIPTORB_PPCM15_Pos;
	return (bool)tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORB_PPCM15_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	UHP_CRITICAL_SECTION_ENTER();
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp &= ~UHP_HCRHDESCRIPTORB_PPCM15;
	tmp |= value << UHP_HCRHDESCRIPTORB_PPCM15_Pos;
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB = tmp;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORB_PPCM15_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB &= ~UHP_HCRHDESCRIPTORB_PPCM15;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORB_PPCM15_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB ^= UHP_HCRHDESCRIPTORB_PPCM15;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_set_HCRHDESCRIPTORB_reg(const void *const hw, hri_uhp_hcrhdescriptorb_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB |= mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcrhdescriptorb_reg_t hri_uhp_get_HCRHDESCRIPTORB_reg(const void *const             hw,
                                                                            hri_uhp_hcrhdescriptorb_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
	tmp &= mask;
	return tmp;
}

static inline void hri_uhp_write_HCRHDESCRIPTORB_reg(const void *const hw, hri_uhp_hcrhdescriptorb_reg_t data)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB = data;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_clear_HCRHDESCRIPTORB_reg(const void *const hw, hri_uhp_hcrhdescriptorb_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB &= ~mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline void hri_uhp_toggle_HCRHDESCRIPTORB_reg(const void *const hw, hri_uhp_hcrhdescriptorb_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHDESCRIPTORB ^= mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcrhdescriptorb_reg_t hri_uhp_read_HCRHDESCRIPTORB_reg(const void *const hw)
{
	return ((Uhp *)hw)->UHP_HCRHDESCRIPTORB;
}

static inline hri_uhp_hcrevision_reg_t hri_uhp_get_HCREVISION_REV_bf(const void *const        hw,
                                                                     hri_uhp_hcrevision_reg_t mask)
{
	return (((Uhp *)hw)->UHP_HCREVISION & UHP_HCREVISION_REV(mask)) >> UHP_HCREVISION_REV_Pos;
}

static inline hri_uhp_hcrevision_reg_t hri_uhp_read_HCREVISION_REV_bf(const void *const hw)
{
	return (((Uhp *)hw)->UHP_HCREVISION & UHP_HCREVISION_REV_Msk) >> UHP_HCREVISION_REV_Pos;
}

static inline hri_uhp_hcrevision_reg_t hri_uhp_get_HCREVISION_reg(const void *const hw, hri_uhp_hcrevision_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCREVISION;
	tmp &= mask;
	return tmp;
}

static inline hri_uhp_hcrevision_reg_t hri_uhp_read_HCREVISION_reg(const void *const hw)
{
	return ((Uhp *)hw)->UHP_HCREVISION;
}

static inline hri_uhp_hcperiodcurrented_reg_t
hri_uhp_get_HCPERIODCURRENTED_PCED_bf(const void *const hw, hri_uhp_hcperiodcurrented_reg_t mask)
{
	return (((Uhp *)hw)->UHP_HCPERIODCURRENTED & UHP_HCPERIODCURRENTED_PCED(mask)) >> UHP_HCPERIODCURRENTED_PCED_Pos;
}

static inline hri_uhp_hcperiodcurrented_reg_t hri_uhp_read_HCPERIODCURRENTED_PCED_bf(const void *const hw)
{
	return (((Uhp *)hw)->UHP_HCPERIODCURRENTED & UHP_HCPERIODCURRENTED_PCED_Msk) >> UHP_HCPERIODCURRENTED_PCED_Pos;
}

static inline hri_uhp_hcperiodcurrented_reg_t hri_uhp_get_HCPERIODCURRENTED_reg(const void *const               hw,
                                                                                hri_uhp_hcperiodcurrented_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCPERIODCURRENTED;
	tmp &= mask;
	return tmp;
}

static inline hri_uhp_hcperiodcurrented_reg_t hri_uhp_read_HCPERIODCURRENTED_reg(const void *const hw)
{
	return ((Uhp *)hw)->UHP_HCPERIODCURRENTED;
}

static inline hri_uhp_hcdonehead_reg_t hri_uhp_get_HCDONEHEAD_DH_bf(const void *const hw, hri_uhp_hcdonehead_reg_t mask)
{
	return (((Uhp *)hw)->UHP_HCDONEHEAD & UHP_HCDONEHEAD_DH(mask)) >> UHP_HCDONEHEAD_DH_Pos;
}

static inline hri_uhp_hcdonehead_reg_t hri_uhp_read_HCDONEHEAD_DH_bf(const void *const hw)
{
	return (((Uhp *)hw)->UHP_HCDONEHEAD & UHP_HCDONEHEAD_DH_Msk) >> UHP_HCDONEHEAD_DH_Pos;
}

static inline hri_uhp_hcdonehead_reg_t hri_uhp_get_HCDONEHEAD_reg(const void *const hw, hri_uhp_hcdonehead_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCDONEHEAD;
	tmp &= mask;
	return tmp;
}

static inline hri_uhp_hcdonehead_reg_t hri_uhp_read_HCDONEHEAD_reg(const void *const hw)
{
	return ((Uhp *)hw)->UHP_HCDONEHEAD;
}

static inline bool hri_uhp_get_HCFMREMAINING_FRT_bit(const void *const hw)
{
	return (((Uhp *)hw)->UHP_HCFMREMAINING & UHP_HCFMREMAINING_FRT) > 0;
}

static inline hri_uhp_hcfmremaining_reg_t hri_uhp_get_HCFMREMAINING_FR_bf(const void *const           hw,
                                                                          hri_uhp_hcfmremaining_reg_t mask)
{
	return (((Uhp *)hw)->UHP_HCFMREMAINING & UHP_HCFMREMAINING_FR(mask)) >> UHP_HCFMREMAINING_FR_Pos;
}

static inline hri_uhp_hcfmremaining_reg_t hri_uhp_read_HCFMREMAINING_FR_bf(const void *const hw)
{
	return (((Uhp *)hw)->UHP_HCFMREMAINING & UHP_HCFMREMAINING_FR_Msk) >> UHP_HCFMREMAINING_FR_Pos;
}

static inline hri_uhp_hcfmremaining_reg_t hri_uhp_get_HCFMREMAINING_reg(const void *const           hw,
                                                                        hri_uhp_hcfmremaining_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCFMREMAINING;
	tmp &= mask;
	return tmp;
}

static inline hri_uhp_hcfmremaining_reg_t hri_uhp_read_HCFMREMAINING_reg(const void *const hw)
{
	return ((Uhp *)hw)->UHP_HCFMREMAINING;
}

static inline hri_uhp_hcfmnumber_reg_t hri_uhp_get_HCFMNUMBER_FN_bf(const void *const hw, hri_uhp_hcfmnumber_reg_t mask)
{
	return (((Uhp *)hw)->UHP_HCFMNUMBER & UHP_HCFMNUMBER_FN(mask)) >> UHP_HCFMNUMBER_FN_Pos;
}

static inline hri_uhp_hcfmnumber_reg_t hri_uhp_read_HCFMNUMBER_FN_bf(const void *const hw)
{
	return (((Uhp *)hw)->UHP_HCFMNUMBER & UHP_HCFMNUMBER_FN_Msk) >> UHP_HCFMNUMBER_FN_Pos;
}

static inline hri_uhp_hcfmnumber_reg_t hri_uhp_get_HCFMNUMBER_reg(const void *const hw, hri_uhp_hcfmnumber_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCFMNUMBER;
	tmp &= mask;
	return tmp;
}

static inline hri_uhp_hcfmnumber_reg_t hri_uhp_read_HCFMNUMBER_reg(const void *const hw)
{
	return ((Uhp *)hw)->UHP_HCFMNUMBER;
}

static inline bool hri_uhp_get_HCCOMMANDSTATUS_HCR_bit(const void *const hw)
{
	return (((Uhp *)hw)->UHP_HCCOMMANDSTATUS & UHP_HCCOMMANDSTATUS_HCR) >> UHP_HCCOMMANDSTATUS_HCR_Pos;
}

static inline void hri_uhp_clear_HCCOMMANDSTATUS_HCR_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCOMMANDSTATUS = UHP_HCCOMMANDSTATUS_HCR;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCCOMMANDSTATUS_CLF_bit(const void *const hw)
{
	return (((Uhp *)hw)->UHP_HCCOMMANDSTATUS & UHP_HCCOMMANDSTATUS_CLF) >> UHP_HCCOMMANDSTATUS_CLF_Pos;
}

static inline void hri_uhp_clear_HCCOMMANDSTATUS_CLF_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCOMMANDSTATUS = UHP_HCCOMMANDSTATUS_CLF;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCCOMMANDSTATUS_BLF_bit(const void *const hw)
{
	return (((Uhp *)hw)->UHP_HCCOMMANDSTATUS & UHP_HCCOMMANDSTATUS_BLF) >> UHP_HCCOMMANDSTATUS_BLF_Pos;
}

static inline void hri_uhp_clear_HCCOMMANDSTATUS_BLF_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCOMMANDSTATUS = UHP_HCCOMMANDSTATUS_BLF;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCCOMMANDSTATUS_OCR_bit(const void *const hw)
{
	return (((Uhp *)hw)->UHP_HCCOMMANDSTATUS & UHP_HCCOMMANDSTATUS_OCR) >> UHP_HCCOMMANDSTATUS_OCR_Pos;
}

static inline void hri_uhp_clear_HCCOMMANDSTATUS_OCR_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCOMMANDSTATUS = UHP_HCCOMMANDSTATUS_OCR;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hccommandstatus_reg_t hri_uhp_get_HCCOMMANDSTATUS_SOC_bf(const void *const             hw,
                                                                               hri_uhp_hccommandstatus_reg_t mask)
{
	return (((Uhp *)hw)->UHP_HCCOMMANDSTATUS & UHP_HCCOMMANDSTATUS_SOC(mask)) >> UHP_HCCOMMANDSTATUS_SOC_Pos;
}

static inline void hri_uhp_clear_HCCOMMANDSTATUS_SOC_bf(const void *const hw, hri_uhp_hccommandstatus_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCOMMANDSTATUS = UHP_HCCOMMANDSTATUS_SOC(mask);
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hccommandstatus_reg_t hri_uhp_read_HCCOMMANDSTATUS_SOC_bf(const void *const hw)
{
	return (((Uhp *)hw)->UHP_HCCOMMANDSTATUS & UHP_HCCOMMANDSTATUS_SOC_Msk) >> UHP_HCCOMMANDSTATUS_SOC_Pos;
}

static inline hri_uhp_hccommandstatus_reg_t hri_uhp_get_HCCOMMANDSTATUS_reg(const void *const             hw,
                                                                            hri_uhp_hccommandstatus_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCCOMMANDSTATUS;
	tmp &= mask;
	return tmp;
}

static inline void hri_uhp_clear_HCCOMMANDSTATUS_reg(const void *const hw, hri_uhp_hccommandstatus_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCCOMMANDSTATUS = mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hccommandstatus_reg_t hri_uhp_read_HCCOMMANDSTATUS_reg(const void *const hw)
{
	return ((Uhp *)hw)->UHP_HCCOMMANDSTATUS;
}

static inline bool hri_uhp_get_HCINTERRUPTSTATUS_SO_bit(const void *const hw)
{
	return (((Uhp *)hw)->UHP_HCINTERRUPTSTATUS & UHP_HCINTERRUPTSTATUS_SO) >> UHP_HCINTERRUPTSTATUS_SO_Pos;
}

static inline void hri_uhp_clear_HCINTERRUPTSTATUS_SO_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTSTATUS = UHP_HCINTERRUPTSTATUS_SO;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCINTERRUPTSTATUS_WDH_bit(const void *const hw)
{
	return (((Uhp *)hw)->UHP_HCINTERRUPTSTATUS & UHP_HCINTERRUPTSTATUS_WDH) >> UHP_HCINTERRUPTSTATUS_WDH_Pos;
}

static inline void hri_uhp_clear_HCINTERRUPTSTATUS_WDH_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTSTATUS = UHP_HCINTERRUPTSTATUS_WDH;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCINTERRUPTSTATUS_SF_bit(const void *const hw)
{
	return (((Uhp *)hw)->UHP_HCINTERRUPTSTATUS & UHP_HCINTERRUPTSTATUS_SF) >> UHP_HCINTERRUPTSTATUS_SF_Pos;
}

static inline void hri_uhp_clear_HCINTERRUPTSTATUS_SF_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTSTATUS = UHP_HCINTERRUPTSTATUS_SF;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCINTERRUPTSTATUS_RD_bit(const void *const hw)
{
	return (((Uhp *)hw)->UHP_HCINTERRUPTSTATUS & UHP_HCINTERRUPTSTATUS_RD) >> UHP_HCINTERRUPTSTATUS_RD_Pos;
}

static inline void hri_uhp_clear_HCINTERRUPTSTATUS_RD_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTSTATUS = UHP_HCINTERRUPTSTATUS_RD;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCINTERRUPTSTATUS_UE_bit(const void *const hw)
{
	return (((Uhp *)hw)->UHP_HCINTERRUPTSTATUS & UHP_HCINTERRUPTSTATUS_UE) >> UHP_HCINTERRUPTSTATUS_UE_Pos;
}

static inline void hri_uhp_clear_HCINTERRUPTSTATUS_UE_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTSTATUS = UHP_HCINTERRUPTSTATUS_UE;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCINTERRUPTSTATUS_FNO_bit(const void *const hw)
{
	return (((Uhp *)hw)->UHP_HCINTERRUPTSTATUS & UHP_HCINTERRUPTSTATUS_FNO) >> UHP_HCINTERRUPTSTATUS_FNO_Pos;
}

static inline void hri_uhp_clear_HCINTERRUPTSTATUS_FNO_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTSTATUS = UHP_HCINTERRUPTSTATUS_FNO;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCINTERRUPTSTATUS_RHSC_bit(const void *const hw)
{
	return (((Uhp *)hw)->UHP_HCINTERRUPTSTATUS & UHP_HCINTERRUPTSTATUS_RHSC) >> UHP_HCINTERRUPTSTATUS_RHSC_Pos;
}

static inline void hri_uhp_clear_HCINTERRUPTSTATUS_RHSC_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTSTATUS = UHP_HCINTERRUPTSTATUS_RHSC;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCINTERRUPTSTATUS_OC_bit(const void *const hw)
{
	return (((Uhp *)hw)->UHP_HCINTERRUPTSTATUS & UHP_HCINTERRUPTSTATUS_OC) >> UHP_HCINTERRUPTSTATUS_OC_Pos;
}

static inline void hri_uhp_clear_HCINTERRUPTSTATUS_OC_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTSTATUS = UHP_HCINTERRUPTSTATUS_OC;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcinterruptstatus_reg_t hri_uhp_get_HCINTERRUPTSTATUS_reg(const void *const               hw,
                                                                                hri_uhp_hcinterruptstatus_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCINTERRUPTSTATUS;
	tmp &= mask;
	return tmp;
}

static inline void hri_uhp_clear_HCINTERRUPTSTATUS_reg(const void *const hw, hri_uhp_hcinterruptstatus_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCINTERRUPTSTATUS = mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcinterruptstatus_reg_t hri_uhp_read_HCINTERRUPTSTATUS_reg(const void *const hw)
{
	return ((Uhp *)hw)->UHP_HCINTERRUPTSTATUS;
}

static inline bool hri_uhp_get_HCRHSTATUS_LPS_bit(const void *const hw)
{
	return (((Uhp *)hw)->UHP_HCRHSTATUS & UHP_HCRHSTATUS_LPS) >> UHP_HCRHSTATUS_LPS_Pos;
}

static inline void hri_uhp_clear_HCRHSTATUS_LPS_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHSTATUS = UHP_HCRHSTATUS_LPS;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHSTATUS_OCI_bit(const void *const hw)
{
	return (((Uhp *)hw)->UHP_HCRHSTATUS & UHP_HCRHSTATUS_OCI) >> UHP_HCRHSTATUS_OCI_Pos;
}

static inline void hri_uhp_clear_HCRHSTATUS_OCI_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHSTATUS = UHP_HCRHSTATUS_OCI;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHSTATUS_DRWE_bit(const void *const hw)
{
	return (((Uhp *)hw)->UHP_HCRHSTATUS & UHP_HCRHSTATUS_DRWE) >> UHP_HCRHSTATUS_DRWE_Pos;
}

static inline void hri_uhp_clear_HCRHSTATUS_DRWE_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHSTATUS = UHP_HCRHSTATUS_DRWE;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHSTATUS_LPSC_bit(const void *const hw)
{
	return (((Uhp *)hw)->UHP_HCRHSTATUS & UHP_HCRHSTATUS_LPSC) >> UHP_HCRHSTATUS_LPSC_Pos;
}

static inline void hri_uhp_clear_HCRHSTATUS_LPSC_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHSTATUS = UHP_HCRHSTATUS_LPSC;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHSTATUS_OCIC_bit(const void *const hw)
{
	return (((Uhp *)hw)->UHP_HCRHSTATUS & UHP_HCRHSTATUS_OCIC) >> UHP_HCRHSTATUS_OCIC_Pos;
}

static inline void hri_uhp_clear_HCRHSTATUS_OCIC_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHSTATUS = UHP_HCRHSTATUS_OCIC;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHSTATUS_CRWE_bit(const void *const hw)
{
	return (((Uhp *)hw)->UHP_HCRHSTATUS & UHP_HCRHSTATUS_CRWE) >> UHP_HCRHSTATUS_CRWE_Pos;
}

static inline void hri_uhp_clear_HCRHSTATUS_CRWE_bit(const void *const hw)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHSTATUS = UHP_HCRHSTATUS_CRWE;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcrhstatus_reg_t hri_uhp_get_HCRHSTATUS_reg(const void *const hw, hri_uhp_hcrhstatus_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHSTATUS;
	tmp &= mask;
	return tmp;
}

static inline void hri_uhp_clear_HCRHSTATUS_reg(const void *const hw, hri_uhp_hcrhstatus_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHSTATUS = mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcrhstatus_reg_t hri_uhp_read_HCRHSTATUS_reg(const void *const hw)
{
	return ((Uhp *)hw)->UHP_HCRHSTATUS;
}

static inline bool hri_uhp_get_HCRHPORTSTATUS_CCS_CPE_bit(const void *const hw, uint8_t index)
{
	return (((Uhp *)hw)->UHP_HCRHPORTSTATUS[index] & UHP_HCRHPORTSTATUS_CCS_CPE) >> UHP_HCRHPORTSTATUS_CCS_CPE_Pos;
}

static inline void hri_uhp_clear_HCRHPORTSTATUS_CCS_CPE_bit(const void *const hw, uint8_t index)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHPORTSTATUS[index] = UHP_HCRHPORTSTATUS_CCS_CPE;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHPORTSTATUS_PES_SPE_bit(const void *const hw, uint8_t index)
{
	return (((Uhp *)hw)->UHP_HCRHPORTSTATUS[index] & UHP_HCRHPORTSTATUS_PES_SPE) >> UHP_HCRHPORTSTATUS_PES_SPE_Pos;
}

static inline void hri_uhp_clear_HCRHPORTSTATUS_PES_SPE_bit(const void *const hw, uint8_t index)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHPORTSTATUS[index] = UHP_HCRHPORTSTATUS_PES_SPE;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHPORTSTATUS_PSS_SPS_bit(const void *const hw, uint8_t index)
{
	return (((Uhp *)hw)->UHP_HCRHPORTSTATUS[index] & UHP_HCRHPORTSTATUS_PSS_SPS) >> UHP_HCRHPORTSTATUS_PSS_SPS_Pos;
}

static inline void hri_uhp_clear_HCRHPORTSTATUS_PSS_SPS_bit(const void *const hw, uint8_t index)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHPORTSTATUS[index] = UHP_HCRHPORTSTATUS_PSS_SPS;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHPORTSTATUS_POCI_CSS_bit(const void *const hw, uint8_t index)
{
	return (((Uhp *)hw)->UHP_HCRHPORTSTATUS[index] & UHP_HCRHPORTSTATUS_POCI_CSS) >> UHP_HCRHPORTSTATUS_POCI_CSS_Pos;
}

static inline void hri_uhp_clear_HCRHPORTSTATUS_POCI_CSS_bit(const void *const hw, uint8_t index)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHPORTSTATUS[index] = UHP_HCRHPORTSTATUS_POCI_CSS;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHPORTSTATUS_PRS_SPR_bit(const void *const hw, uint8_t index)
{
	return (((Uhp *)hw)->UHP_HCRHPORTSTATUS[index] & UHP_HCRHPORTSTATUS_PRS_SPR) >> UHP_HCRHPORTSTATUS_PRS_SPR_Pos;
}

static inline void hri_uhp_clear_HCRHPORTSTATUS_PRS_SPR_bit(const void *const hw, uint8_t index)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHPORTSTATUS[index] = UHP_HCRHPORTSTATUS_PRS_SPR;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHPORTSTATUS_PPS_SPP_bit(const void *const hw, uint8_t index)
{
	return (((Uhp *)hw)->UHP_HCRHPORTSTATUS[index] & UHP_HCRHPORTSTATUS_PPS_SPP) >> UHP_HCRHPORTSTATUS_PPS_SPP_Pos;
}

static inline void hri_uhp_clear_HCRHPORTSTATUS_PPS_SPP_bit(const void *const hw, uint8_t index)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHPORTSTATUS[index] = UHP_HCRHPORTSTATUS_PPS_SPP;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHPORTSTATUS_LSDA_CPP_bit(const void *const hw, uint8_t index)
{
	return (((Uhp *)hw)->UHP_HCRHPORTSTATUS[index] & UHP_HCRHPORTSTATUS_LSDA_CPP) >> UHP_HCRHPORTSTATUS_LSDA_CPP_Pos;
}

static inline void hri_uhp_clear_HCRHPORTSTATUS_LSDA_CPP_bit(const void *const hw, uint8_t index)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHPORTSTATUS[index] = UHP_HCRHPORTSTATUS_LSDA_CPP;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHPORTSTATUS_CSC_bit(const void *const hw, uint8_t index)
{
	return (((Uhp *)hw)->UHP_HCRHPORTSTATUS[index] & UHP_HCRHPORTSTATUS_CSC) >> UHP_HCRHPORTSTATUS_CSC_Pos;
}

static inline void hri_uhp_clear_HCRHPORTSTATUS_CSC_bit(const void *const hw, uint8_t index)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHPORTSTATUS[index] = UHP_HCRHPORTSTATUS_CSC;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHPORTSTATUS_PESC_bit(const void *const hw, uint8_t index)
{
	return (((Uhp *)hw)->UHP_HCRHPORTSTATUS[index] & UHP_HCRHPORTSTATUS_PESC) >> UHP_HCRHPORTSTATUS_PESC_Pos;
}

static inline void hri_uhp_clear_HCRHPORTSTATUS_PESC_bit(const void *const hw, uint8_t index)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHPORTSTATUS[index] = UHP_HCRHPORTSTATUS_PESC;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHPORTSTATUS_PSSC_bit(const void *const hw, uint8_t index)
{
	return (((Uhp *)hw)->UHP_HCRHPORTSTATUS[index] & UHP_HCRHPORTSTATUS_PSSC) >> UHP_HCRHPORTSTATUS_PSSC_Pos;
}

static inline void hri_uhp_clear_HCRHPORTSTATUS_PSSC_bit(const void *const hw, uint8_t index)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHPORTSTATUS[index] = UHP_HCRHPORTSTATUS_PSSC;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHPORTSTATUS_OCIC_bit(const void *const hw, uint8_t index)
{
	return (((Uhp *)hw)->UHP_HCRHPORTSTATUS[index] & UHP_HCRHPORTSTATUS_OCIC) >> UHP_HCRHPORTSTATUS_OCIC_Pos;
}

static inline void hri_uhp_clear_HCRHPORTSTATUS_OCIC_bit(const void *const hw, uint8_t index)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHPORTSTATUS[index] = UHP_HCRHPORTSTATUS_OCIC;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_uhp_get_HCRHPORTSTATUS_PRSC_bit(const void *const hw, uint8_t index)
{
	return (((Uhp *)hw)->UHP_HCRHPORTSTATUS[index] & UHP_HCRHPORTSTATUS_PRSC) >> UHP_HCRHPORTSTATUS_PRSC_Pos;
}

static inline void hri_uhp_clear_HCRHPORTSTATUS_PRSC_bit(const void *const hw, uint8_t index)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHPORTSTATUS[index] = UHP_HCRHPORTSTATUS_PRSC;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcrhportstatus_reg_t hri_uhp_get_HCRHPORTSTATUS_reg(const void *const hw, uint8_t index,
                                                                          hri_uhp_hcrhportstatus_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Uhp *)hw)->UHP_HCRHPORTSTATUS[index];
	tmp &= mask;
	return tmp;
}

static inline void hri_uhp_clear_HCRHPORTSTATUS_reg(const void *const hw, uint8_t index,
                                                    hri_uhp_hcrhportstatus_reg_t mask)
{
	UHP_CRITICAL_SECTION_ENTER();
	((Uhp *)hw)->UHP_HCRHPORTSTATUS[index] = mask;
	UHP_CRITICAL_SECTION_LEAVE();
}

static inline hri_uhp_hcrhportstatus_reg_t hri_uhp_read_HCRHPORTSTATUS_reg(const void *const hw, uint8_t index)
{
	return ((Uhp *)hw)->UHP_HCRHPORTSTATUS[index];
}

#ifdef __cplusplus
}
#endif

#endif /* _HRI_UHP_G55_H_INCLUDED */
#endif /* _SAMG55_UHP_COMPONENT_ */
