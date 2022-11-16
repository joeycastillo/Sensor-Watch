/**
 * \file
 *
 * \brief SAM NVIC
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

#ifdef _SAME51_NVIC_COMPONENT_
#ifndef _HRI_NVIC_E51_H_INCLUDED_
#define _HRI_NVIC_E51_H_INCLUDED_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <hal_atomic.h>

#if defined(ENABLE_NVIC_CRITICAL_SECTIONS)
#define NVIC_CRITICAL_SECTION_ENTER() CRITICAL_SECTION_ENTER()
#define NVIC_CRITICAL_SECTION_LEAVE() CRITICAL_SECTION_LEAVE()
#else
#define NVIC_CRITICAL_SECTION_ENTER()
#define NVIC_CRITICAL_SECTION_LEAVE()
#endif

typedef uint32_t hri_nvic_iabr_reg_t;
typedef uint32_t hri_nvic_icer_reg_t;
typedef uint32_t hri_nvic_icpr_reg_t;
typedef uint32_t hri_nvic_iser_reg_t;
typedef uint32_t hri_nvic_ispr_reg_t;
typedef uint32_t hri_nvic_stir_reg_t;
typedef uint8_t  hri_nvic_ip_reg_t;

static inline void hri_nvic_set_ISER_reg(const void *const hw, uint8_t index, hri_nvic_iser_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->ISER[index].reg |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_iser_reg_t hri_nvic_get_ISER_reg(const void *const hw, uint8_t index, hri_nvic_iser_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->ISER[index].reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_ISER_reg(const void *const hw, uint8_t index, hri_nvic_iser_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->ISER[index].reg = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_ISER_reg(const void *const hw, uint8_t index, hri_nvic_iser_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->ISER[index].reg &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_ISER_reg(const void *const hw, uint8_t index, hri_nvic_iser_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->ISER[index].reg ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_iser_reg_t hri_nvic_read_ISER_reg(const void *const hw, uint8_t index)
{
	return ((Nvic *)hw)->ISER[index].reg;
}

static inline void hri_nvic_set_ICER_reg(const void *const hw, uint8_t index, hri_nvic_icer_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->ICER[index].reg |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_icer_reg_t hri_nvic_get_ICER_reg(const void *const hw, uint8_t index, hri_nvic_icer_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->ICER[index].reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_ICER_reg(const void *const hw, uint8_t index, hri_nvic_icer_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->ICER[index].reg = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_ICER_reg(const void *const hw, uint8_t index, hri_nvic_icer_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->ICER[index].reg &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_ICER_reg(const void *const hw, uint8_t index, hri_nvic_icer_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->ICER[index].reg ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_icer_reg_t hri_nvic_read_ICER_reg(const void *const hw, uint8_t index)
{
	return ((Nvic *)hw)->ICER[index].reg;
}

static inline void hri_nvic_set_ISPR_reg(const void *const hw, uint8_t index, hri_nvic_ispr_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->ISPR[index].reg |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_ispr_reg_t hri_nvic_get_ISPR_reg(const void *const hw, uint8_t index, hri_nvic_ispr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->ISPR[index].reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_ISPR_reg(const void *const hw, uint8_t index, hri_nvic_ispr_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->ISPR[index].reg = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_ISPR_reg(const void *const hw, uint8_t index, hri_nvic_ispr_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->ISPR[index].reg &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_ISPR_reg(const void *const hw, uint8_t index, hri_nvic_ispr_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->ISPR[index].reg ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_ispr_reg_t hri_nvic_read_ISPR_reg(const void *const hw, uint8_t index)
{
	return ((Nvic *)hw)->ISPR[index].reg;
}

static inline void hri_nvic_set_ICPR_reg(const void *const hw, uint8_t index, hri_nvic_icpr_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->ICPR[index].reg |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_icpr_reg_t hri_nvic_get_ICPR_reg(const void *const hw, uint8_t index, hri_nvic_icpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->ICPR[index].reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_ICPR_reg(const void *const hw, uint8_t index, hri_nvic_icpr_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->ICPR[index].reg = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_ICPR_reg(const void *const hw, uint8_t index, hri_nvic_icpr_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->ICPR[index].reg &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_ICPR_reg(const void *const hw, uint8_t index, hri_nvic_icpr_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->ICPR[index].reg ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_icpr_reg_t hri_nvic_read_ICPR_reg(const void *const hw, uint8_t index)
{
	return ((Nvic *)hw)->ICPR[index].reg;
}

static inline void hri_nvic_set_IABR_reg(const void *const hw, uint8_t index, hri_nvic_iabr_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->IABR[index].reg |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_iabr_reg_t hri_nvic_get_IABR_reg(const void *const hw, uint8_t index, hri_nvic_iabr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->IABR[index].reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_IABR_reg(const void *const hw, uint8_t index, hri_nvic_iabr_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->IABR[index].reg = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_IABR_reg(const void *const hw, uint8_t index, hri_nvic_iabr_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->IABR[index].reg &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_IABR_reg(const void *const hw, uint8_t index, hri_nvic_iabr_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->IABR[index].reg ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_iabr_reg_t hri_nvic_read_IABR_reg(const void *const hw, uint8_t index)
{
	return ((Nvic *)hw)->IABR[index].reg;
}

static inline void hri_nvic_set_IP_reg(const void *const hw, uint8_t index, hri_nvic_ip_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->IP[index].reg |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_ip_reg_t hri_nvic_get_IP_reg(const void *const hw, uint8_t index, hri_nvic_ip_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->IP[index].reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_IP_reg(const void *const hw, uint8_t index, hri_nvic_ip_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->IP[index].reg = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_IP_reg(const void *const hw, uint8_t index, hri_nvic_ip_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->IP[index].reg &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_IP_reg(const void *const hw, uint8_t index, hri_nvic_ip_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->IP[index].reg ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_ip_reg_t hri_nvic_read_IP_reg(const void *const hw, uint8_t index)
{
	return ((Nvic *)hw)->IP[index].reg;
}

static inline void hri_nvic_write_STIR_reg(const void *const hw, hri_nvic_stir_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->STIR.reg = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

#ifdef __cplusplus
}
#endif

#endif /* _HRI_NVIC_E51_H_INCLUDED */
#endif /* _SAME51_NVIC_COMPONENT_ */
