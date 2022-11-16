/**
 * \file
 *
 * \brief SAM CMCC
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

#ifdef _SAMG55_CMCC_COMPONENT_
#ifndef _HRI_CMCC_G55_H_INCLUDED_
#define _HRI_CMCC_G55_H_INCLUDED_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <hal_atomic.h>

#if defined(ENABLE_CMCC_CRITICAL_SECTIONS)
#define CMCC_CRITICAL_SECTION_ENTER() CRITICAL_SECTION_ENTER()
#define CMCC_CRITICAL_SECTION_LEAVE() CRITICAL_SECTION_LEAVE()
#else
#define CMCC_CRITICAL_SECTION_ENTER()
#define CMCC_CRITICAL_SECTION_LEAVE()
#endif

typedef uint32_t hri_cmcc_cfg_reg_t;
typedef uint32_t hri_cmcc_ctrl_reg_t;
typedef uint32_t hri_cmcc_maint0_reg_t;
typedef uint32_t hri_cmcc_maint1_reg_t;
typedef uint32_t hri_cmcc_mcfg_reg_t;
typedef uint32_t hri_cmcc_mctrl_reg_t;
typedef uint32_t hri_cmcc_men_reg_t;
typedef uint32_t hri_cmcc_msr_reg_t;
typedef uint32_t hri_cmcc_sr_reg_t;
typedef uint32_t hri_cmcc_type_reg_t;

static inline void hri_cmcc_write_CTRL_reg(const void *const hw, hri_cmcc_ctrl_reg_t data)
{
	CMCC_CRITICAL_SECTION_ENTER();
	((Cmcc *)hw)->CMCC_CTRL = data;
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_cmcc_write_MAINT0_reg(const void *const hw, hri_cmcc_maint0_reg_t data)
{
	CMCC_CRITICAL_SECTION_ENTER();
	((Cmcc *)hw)->CMCC_MAINT0 = data;
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_cmcc_write_MAINT1_reg(const void *const hw, hri_cmcc_maint1_reg_t data)
{
	CMCC_CRITICAL_SECTION_ENTER();
	((Cmcc *)hw)->CMCC_MAINT1 = data;
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_cmcc_write_MCTRL_reg(const void *const hw, hri_cmcc_mctrl_reg_t data)
{
	CMCC_CRITICAL_SECTION_ENTER();
	((Cmcc *)hw)->CMCC_MCTRL = data;
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_cmcc_set_CFG_GCLKDIS_bit(const void *const hw)
{
	CMCC_CRITICAL_SECTION_ENTER();
	((Cmcc *)hw)->CMCC_CFG |= CMCC_CFG_GCLKDIS;
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_cmcc_get_CFG_GCLKDIS_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Cmcc *)hw)->CMCC_CFG;
	tmp = (tmp & CMCC_CFG_GCLKDIS) >> CMCC_CFG_GCLKDIS_Pos;
	return (bool)tmp;
}

static inline void hri_cmcc_write_CFG_GCLKDIS_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	CMCC_CRITICAL_SECTION_ENTER();
	tmp = ((Cmcc *)hw)->CMCC_CFG;
	tmp &= ~CMCC_CFG_GCLKDIS;
	tmp |= value << CMCC_CFG_GCLKDIS_Pos;
	((Cmcc *)hw)->CMCC_CFG = tmp;
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_cmcc_clear_CFG_GCLKDIS_bit(const void *const hw)
{
	CMCC_CRITICAL_SECTION_ENTER();
	((Cmcc *)hw)->CMCC_CFG &= ~CMCC_CFG_GCLKDIS;
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_cmcc_toggle_CFG_GCLKDIS_bit(const void *const hw)
{
	CMCC_CRITICAL_SECTION_ENTER();
	((Cmcc *)hw)->CMCC_CFG ^= CMCC_CFG_GCLKDIS;
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_cmcc_set_CFG_ICDIS_bit(const void *const hw)
{
	CMCC_CRITICAL_SECTION_ENTER();
	((Cmcc *)hw)->CMCC_CFG |= CMCC_CFG_ICDIS;
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_cmcc_get_CFG_ICDIS_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Cmcc *)hw)->CMCC_CFG;
	tmp = (tmp & CMCC_CFG_ICDIS) >> CMCC_CFG_ICDIS_Pos;
	return (bool)tmp;
}

static inline void hri_cmcc_write_CFG_ICDIS_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	CMCC_CRITICAL_SECTION_ENTER();
	tmp = ((Cmcc *)hw)->CMCC_CFG;
	tmp &= ~CMCC_CFG_ICDIS;
	tmp |= value << CMCC_CFG_ICDIS_Pos;
	((Cmcc *)hw)->CMCC_CFG = tmp;
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_cmcc_clear_CFG_ICDIS_bit(const void *const hw)
{
	CMCC_CRITICAL_SECTION_ENTER();
	((Cmcc *)hw)->CMCC_CFG &= ~CMCC_CFG_ICDIS;
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_cmcc_toggle_CFG_ICDIS_bit(const void *const hw)
{
	CMCC_CRITICAL_SECTION_ENTER();
	((Cmcc *)hw)->CMCC_CFG ^= CMCC_CFG_ICDIS;
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_cmcc_set_CFG_DCDIS_bit(const void *const hw)
{
	CMCC_CRITICAL_SECTION_ENTER();
	((Cmcc *)hw)->CMCC_CFG |= CMCC_CFG_DCDIS;
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_cmcc_get_CFG_DCDIS_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Cmcc *)hw)->CMCC_CFG;
	tmp = (tmp & CMCC_CFG_DCDIS) >> CMCC_CFG_DCDIS_Pos;
	return (bool)tmp;
}

static inline void hri_cmcc_write_CFG_DCDIS_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	CMCC_CRITICAL_SECTION_ENTER();
	tmp = ((Cmcc *)hw)->CMCC_CFG;
	tmp &= ~CMCC_CFG_DCDIS;
	tmp |= value << CMCC_CFG_DCDIS_Pos;
	((Cmcc *)hw)->CMCC_CFG = tmp;
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_cmcc_clear_CFG_DCDIS_bit(const void *const hw)
{
	CMCC_CRITICAL_SECTION_ENTER();
	((Cmcc *)hw)->CMCC_CFG &= ~CMCC_CFG_DCDIS;
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_cmcc_toggle_CFG_DCDIS_bit(const void *const hw)
{
	CMCC_CRITICAL_SECTION_ENTER();
	((Cmcc *)hw)->CMCC_CFG ^= CMCC_CFG_DCDIS;
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_cmcc_set_CFG_PRGCSIZE_bf(const void *const hw, hri_cmcc_cfg_reg_t mask)
{
	CMCC_CRITICAL_SECTION_ENTER();
	((Cmcc *)hw)->CMCC_CFG |= CMCC_CFG_PRGCSIZE(mask);
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline hri_cmcc_cfg_reg_t hri_cmcc_get_CFG_PRGCSIZE_bf(const void *const hw, hri_cmcc_cfg_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Cmcc *)hw)->CMCC_CFG;
	tmp = (tmp & CMCC_CFG_PRGCSIZE(mask)) >> CMCC_CFG_PRGCSIZE_Pos;
	return tmp;
}

static inline void hri_cmcc_write_CFG_PRGCSIZE_bf(const void *const hw, hri_cmcc_cfg_reg_t data)
{
	uint32_t tmp;
	CMCC_CRITICAL_SECTION_ENTER();
	tmp = ((Cmcc *)hw)->CMCC_CFG;
	tmp &= ~CMCC_CFG_PRGCSIZE_Msk;
	tmp |= CMCC_CFG_PRGCSIZE(data);
	((Cmcc *)hw)->CMCC_CFG = tmp;
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_cmcc_clear_CFG_PRGCSIZE_bf(const void *const hw, hri_cmcc_cfg_reg_t mask)
{
	CMCC_CRITICAL_SECTION_ENTER();
	((Cmcc *)hw)->CMCC_CFG &= ~CMCC_CFG_PRGCSIZE(mask);
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_cmcc_toggle_CFG_PRGCSIZE_bf(const void *const hw, hri_cmcc_cfg_reg_t mask)
{
	CMCC_CRITICAL_SECTION_ENTER();
	((Cmcc *)hw)->CMCC_CFG ^= CMCC_CFG_PRGCSIZE(mask);
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline hri_cmcc_cfg_reg_t hri_cmcc_read_CFG_PRGCSIZE_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Cmcc *)hw)->CMCC_CFG;
	tmp = (tmp & CMCC_CFG_PRGCSIZE_Msk) >> CMCC_CFG_PRGCSIZE_Pos;
	return tmp;
}

static inline void hri_cmcc_set_CFG_reg(const void *const hw, hri_cmcc_cfg_reg_t mask)
{
	CMCC_CRITICAL_SECTION_ENTER();
	((Cmcc *)hw)->CMCC_CFG |= mask;
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline hri_cmcc_cfg_reg_t hri_cmcc_get_CFG_reg(const void *const hw, hri_cmcc_cfg_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Cmcc *)hw)->CMCC_CFG;
	tmp &= mask;
	return tmp;
}

static inline void hri_cmcc_write_CFG_reg(const void *const hw, hri_cmcc_cfg_reg_t data)
{
	CMCC_CRITICAL_SECTION_ENTER();
	((Cmcc *)hw)->CMCC_CFG = data;
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_cmcc_clear_CFG_reg(const void *const hw, hri_cmcc_cfg_reg_t mask)
{
	CMCC_CRITICAL_SECTION_ENTER();
	((Cmcc *)hw)->CMCC_CFG &= ~mask;
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_cmcc_toggle_CFG_reg(const void *const hw, hri_cmcc_cfg_reg_t mask)
{
	CMCC_CRITICAL_SECTION_ENTER();
	((Cmcc *)hw)->CMCC_CFG ^= mask;
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline hri_cmcc_cfg_reg_t hri_cmcc_read_CFG_reg(const void *const hw)
{
	return ((Cmcc *)hw)->CMCC_CFG;
}

static inline void hri_cmcc_set_MCFG_MODE_bf(const void *const hw, hri_cmcc_mcfg_reg_t mask)
{
	CMCC_CRITICAL_SECTION_ENTER();
	((Cmcc *)hw)->CMCC_MCFG |= CMCC_MCFG_MODE(mask);
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline hri_cmcc_mcfg_reg_t hri_cmcc_get_MCFG_MODE_bf(const void *const hw, hri_cmcc_mcfg_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Cmcc *)hw)->CMCC_MCFG;
	tmp = (tmp & CMCC_MCFG_MODE(mask)) >> CMCC_MCFG_MODE_Pos;
	return tmp;
}

static inline void hri_cmcc_write_MCFG_MODE_bf(const void *const hw, hri_cmcc_mcfg_reg_t data)
{
	uint32_t tmp;
	CMCC_CRITICAL_SECTION_ENTER();
	tmp = ((Cmcc *)hw)->CMCC_MCFG;
	tmp &= ~CMCC_MCFG_MODE_Msk;
	tmp |= CMCC_MCFG_MODE(data);
	((Cmcc *)hw)->CMCC_MCFG = tmp;
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_cmcc_clear_MCFG_MODE_bf(const void *const hw, hri_cmcc_mcfg_reg_t mask)
{
	CMCC_CRITICAL_SECTION_ENTER();
	((Cmcc *)hw)->CMCC_MCFG &= ~CMCC_MCFG_MODE(mask);
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_cmcc_toggle_MCFG_MODE_bf(const void *const hw, hri_cmcc_mcfg_reg_t mask)
{
	CMCC_CRITICAL_SECTION_ENTER();
	((Cmcc *)hw)->CMCC_MCFG ^= CMCC_MCFG_MODE(mask);
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline hri_cmcc_mcfg_reg_t hri_cmcc_read_MCFG_MODE_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Cmcc *)hw)->CMCC_MCFG;
	tmp = (tmp & CMCC_MCFG_MODE_Msk) >> CMCC_MCFG_MODE_Pos;
	return tmp;
}

static inline void hri_cmcc_set_MCFG_reg(const void *const hw, hri_cmcc_mcfg_reg_t mask)
{
	CMCC_CRITICAL_SECTION_ENTER();
	((Cmcc *)hw)->CMCC_MCFG |= mask;
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline hri_cmcc_mcfg_reg_t hri_cmcc_get_MCFG_reg(const void *const hw, hri_cmcc_mcfg_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Cmcc *)hw)->CMCC_MCFG;
	tmp &= mask;
	return tmp;
}

static inline void hri_cmcc_write_MCFG_reg(const void *const hw, hri_cmcc_mcfg_reg_t data)
{
	CMCC_CRITICAL_SECTION_ENTER();
	((Cmcc *)hw)->CMCC_MCFG = data;
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_cmcc_clear_MCFG_reg(const void *const hw, hri_cmcc_mcfg_reg_t mask)
{
	CMCC_CRITICAL_SECTION_ENTER();
	((Cmcc *)hw)->CMCC_MCFG &= ~mask;
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_cmcc_toggle_MCFG_reg(const void *const hw, hri_cmcc_mcfg_reg_t mask)
{
	CMCC_CRITICAL_SECTION_ENTER();
	((Cmcc *)hw)->CMCC_MCFG ^= mask;
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline hri_cmcc_mcfg_reg_t hri_cmcc_read_MCFG_reg(const void *const hw)
{
	return ((Cmcc *)hw)->CMCC_MCFG;
}

static inline void hri_cmcc_set_MEN_MENABLE_bit(const void *const hw)
{
	CMCC_CRITICAL_SECTION_ENTER();
	((Cmcc *)hw)->CMCC_MEN |= CMCC_MEN_MENABLE;
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_cmcc_get_MEN_MENABLE_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Cmcc *)hw)->CMCC_MEN;
	tmp = (tmp & CMCC_MEN_MENABLE) >> CMCC_MEN_MENABLE_Pos;
	return (bool)tmp;
}

static inline void hri_cmcc_write_MEN_MENABLE_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	CMCC_CRITICAL_SECTION_ENTER();
	tmp = ((Cmcc *)hw)->CMCC_MEN;
	tmp &= ~CMCC_MEN_MENABLE;
	tmp |= value << CMCC_MEN_MENABLE_Pos;
	((Cmcc *)hw)->CMCC_MEN = tmp;
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_cmcc_clear_MEN_MENABLE_bit(const void *const hw)
{
	CMCC_CRITICAL_SECTION_ENTER();
	((Cmcc *)hw)->CMCC_MEN &= ~CMCC_MEN_MENABLE;
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_cmcc_toggle_MEN_MENABLE_bit(const void *const hw)
{
	CMCC_CRITICAL_SECTION_ENTER();
	((Cmcc *)hw)->CMCC_MEN ^= CMCC_MEN_MENABLE;
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_cmcc_set_MEN_reg(const void *const hw, hri_cmcc_men_reg_t mask)
{
	CMCC_CRITICAL_SECTION_ENTER();
	((Cmcc *)hw)->CMCC_MEN |= mask;
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline hri_cmcc_men_reg_t hri_cmcc_get_MEN_reg(const void *const hw, hri_cmcc_men_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Cmcc *)hw)->CMCC_MEN;
	tmp &= mask;
	return tmp;
}

static inline void hri_cmcc_write_MEN_reg(const void *const hw, hri_cmcc_men_reg_t data)
{
	CMCC_CRITICAL_SECTION_ENTER();
	((Cmcc *)hw)->CMCC_MEN = data;
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_cmcc_clear_MEN_reg(const void *const hw, hri_cmcc_men_reg_t mask)
{
	CMCC_CRITICAL_SECTION_ENTER();
	((Cmcc *)hw)->CMCC_MEN &= ~mask;
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_cmcc_toggle_MEN_reg(const void *const hw, hri_cmcc_men_reg_t mask)
{
	CMCC_CRITICAL_SECTION_ENTER();
	((Cmcc *)hw)->CMCC_MEN ^= mask;
	CMCC_CRITICAL_SECTION_LEAVE();
}

static inline hri_cmcc_men_reg_t hri_cmcc_read_MEN_reg(const void *const hw)
{
	return ((Cmcc *)hw)->CMCC_MEN;
}

static inline bool hri_cmcc_get_TYPE_AP_bit(const void *const hw)
{
	return (((Cmcc *)hw)->CMCC_TYPE & CMCC_TYPE_AP) > 0;
}

static inline bool hri_cmcc_get_TYPE_GCLK_bit(const void *const hw)
{
	return (((Cmcc *)hw)->CMCC_TYPE & CMCC_TYPE_GCLK) > 0;
}

static inline bool hri_cmcc_get_TYPE_RANDP_bit(const void *const hw)
{
	return (((Cmcc *)hw)->CMCC_TYPE & CMCC_TYPE_RANDP) > 0;
}

static inline bool hri_cmcc_get_TYPE_LRUP_bit(const void *const hw)
{
	return (((Cmcc *)hw)->CMCC_TYPE & CMCC_TYPE_LRUP) > 0;
}

static inline bool hri_cmcc_get_TYPE_RRP_bit(const void *const hw)
{
	return (((Cmcc *)hw)->CMCC_TYPE & CMCC_TYPE_RRP) > 0;
}

static inline bool hri_cmcc_get_TYPE_LCKDOWN_bit(const void *const hw)
{
	return (((Cmcc *)hw)->CMCC_TYPE & CMCC_TYPE_LCKDOWN) > 0;
}

static inline hri_cmcc_type_reg_t hri_cmcc_get_TYPE_WAYNUM_bf(const void *const hw, hri_cmcc_type_reg_t mask)
{
	return (((Cmcc *)hw)->CMCC_TYPE & CMCC_TYPE_WAYNUM(mask)) >> CMCC_TYPE_WAYNUM_Pos;
}

static inline hri_cmcc_type_reg_t hri_cmcc_read_TYPE_WAYNUM_bf(const void *const hw)
{
	return (((Cmcc *)hw)->CMCC_TYPE & CMCC_TYPE_WAYNUM_Msk) >> CMCC_TYPE_WAYNUM_Pos;
}

static inline hri_cmcc_type_reg_t hri_cmcc_get_TYPE_CSIZE_bf(const void *const hw, hri_cmcc_type_reg_t mask)
{
	return (((Cmcc *)hw)->CMCC_TYPE & CMCC_TYPE_CSIZE(mask)) >> CMCC_TYPE_CSIZE_Pos;
}

static inline hri_cmcc_type_reg_t hri_cmcc_read_TYPE_CSIZE_bf(const void *const hw)
{
	return (((Cmcc *)hw)->CMCC_TYPE & CMCC_TYPE_CSIZE_Msk) >> CMCC_TYPE_CSIZE_Pos;
}

static inline hri_cmcc_type_reg_t hri_cmcc_get_TYPE_CLSIZE_bf(const void *const hw, hri_cmcc_type_reg_t mask)
{
	return (((Cmcc *)hw)->CMCC_TYPE & CMCC_TYPE_CLSIZE(mask)) >> CMCC_TYPE_CLSIZE_Pos;
}

static inline hri_cmcc_type_reg_t hri_cmcc_read_TYPE_CLSIZE_bf(const void *const hw)
{
	return (((Cmcc *)hw)->CMCC_TYPE & CMCC_TYPE_CLSIZE_Msk) >> CMCC_TYPE_CLSIZE_Pos;
}

static inline hri_cmcc_type_reg_t hri_cmcc_get_TYPE_reg(const void *const hw, hri_cmcc_type_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Cmcc *)hw)->CMCC_TYPE;
	tmp &= mask;
	return tmp;
}

static inline hri_cmcc_type_reg_t hri_cmcc_read_TYPE_reg(const void *const hw)
{
	return ((Cmcc *)hw)->CMCC_TYPE;
}

static inline bool hri_cmcc_get_SR_CSTS_bit(const void *const hw)
{
	return (((Cmcc *)hw)->CMCC_SR & CMCC_SR_CSTS) > 0;
}

static inline hri_cmcc_sr_reg_t hri_cmcc_get_SR_reg(const void *const hw, hri_cmcc_sr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Cmcc *)hw)->CMCC_SR;
	tmp &= mask;
	return tmp;
}

static inline hri_cmcc_sr_reg_t hri_cmcc_read_SR_reg(const void *const hw)
{
	return ((Cmcc *)hw)->CMCC_SR;
}

static inline hri_cmcc_msr_reg_t hri_cmcc_get_MSR_EVENT_CNT_bf(const void *const hw, hri_cmcc_msr_reg_t mask)
{
	return (((Cmcc *)hw)->CMCC_MSR & CMCC_MSR_EVENT_CNT(mask)) >> CMCC_MSR_EVENT_CNT_Pos;
}

static inline hri_cmcc_msr_reg_t hri_cmcc_read_MSR_EVENT_CNT_bf(const void *const hw)
{
	return (((Cmcc *)hw)->CMCC_MSR & CMCC_MSR_EVENT_CNT_Msk) >> CMCC_MSR_EVENT_CNT_Pos;
}

static inline hri_cmcc_msr_reg_t hri_cmcc_get_MSR_reg(const void *const hw, hri_cmcc_msr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Cmcc *)hw)->CMCC_MSR;
	tmp &= mask;
	return tmp;
}

static inline hri_cmcc_msr_reg_t hri_cmcc_read_MSR_reg(const void *const hw)
{
	return ((Cmcc *)hw)->CMCC_MSR;
}

#ifdef __cplusplus
}
#endif

#endif /* _HRI_CMCC_G55_H_INCLUDED */
#endif /* _SAMG55_CMCC_COMPONENT_ */
