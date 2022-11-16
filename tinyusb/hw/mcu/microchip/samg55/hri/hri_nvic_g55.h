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
 */

#ifdef _SAMG55_NVIC_COMPONENT_
#ifndef _HRI_NVIC_G55_H_INCLUDED_
#define _HRI_NVIC_G55_H_INCLUDED_

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

typedef uint32_t hri_nvic_nviciabr0_reg_t;
typedef uint32_t hri_nvic_nviciabr1_reg_t;
typedef uint32_t hri_nvic_nviciabr2_reg_t;
typedef uint32_t hri_nvic_nviciabr3_reg_t;
typedef uint32_t hri_nvic_nvicicer0_reg_t;
typedef uint32_t hri_nvic_nvicicer1_reg_t;
typedef uint32_t hri_nvic_nvicicer2_reg_t;
typedef uint32_t hri_nvic_nvicicer3_reg_t;
typedef uint32_t hri_nvic_nvicicpr0_reg_t;
typedef uint32_t hri_nvic_nvicicpr1_reg_t;
typedef uint32_t hri_nvic_nvicicpr2_reg_t;
typedef uint32_t hri_nvic_nvicicpr3_reg_t;
typedef uint32_t hri_nvic_nviciser0_reg_t;
typedef uint32_t hri_nvic_nviciser1_reg_t;
typedef uint32_t hri_nvic_nviciser2_reg_t;
typedef uint32_t hri_nvic_nviciser3_reg_t;
typedef uint32_t hri_nvic_nvicispr0_reg_t;
typedef uint32_t hri_nvic_nvicispr1_reg_t;
typedef uint32_t hri_nvic_nvicispr2_reg_t;
typedef uint32_t hri_nvic_nvicispr3_reg_t;
typedef uint32_t hri_nvic_nvicstir_reg_t;
typedef uint8_t  hri_nvic_nvicip0_reg_t;
typedef uint8_t  hri_nvic_nvicip100_reg_t;
typedef uint8_t  hri_nvic_nvicip101_reg_t;
typedef uint8_t  hri_nvic_nvicip102_reg_t;
typedef uint8_t  hri_nvic_nvicip103_reg_t;
typedef uint8_t  hri_nvic_nvicip104_reg_t;
typedef uint8_t  hri_nvic_nvicip105_reg_t;
typedef uint8_t  hri_nvic_nvicip10_reg_t;
typedef uint8_t  hri_nvic_nvicip11_reg_t;
typedef uint8_t  hri_nvic_nvicip12_reg_t;
typedef uint8_t  hri_nvic_nvicip13_reg_t;
typedef uint8_t  hri_nvic_nvicip14_reg_t;
typedef uint8_t  hri_nvic_nvicip15_reg_t;
typedef uint8_t  hri_nvic_nvicip16_reg_t;
typedef uint8_t  hri_nvic_nvicip17_reg_t;
typedef uint8_t  hri_nvic_nvicip18_reg_t;
typedef uint8_t  hri_nvic_nvicip19_reg_t;
typedef uint8_t  hri_nvic_nvicip1_reg_t;
typedef uint8_t  hri_nvic_nvicip20_reg_t;
typedef uint8_t  hri_nvic_nvicip21_reg_t;
typedef uint8_t  hri_nvic_nvicip22_reg_t;
typedef uint8_t  hri_nvic_nvicip23_reg_t;
typedef uint8_t  hri_nvic_nvicip24_reg_t;
typedef uint8_t  hri_nvic_nvicip25_reg_t;
typedef uint8_t  hri_nvic_nvicip26_reg_t;
typedef uint8_t  hri_nvic_nvicip27_reg_t;
typedef uint8_t  hri_nvic_nvicip28_reg_t;
typedef uint8_t  hri_nvic_nvicip29_reg_t;
typedef uint8_t  hri_nvic_nvicip2_reg_t;
typedef uint8_t  hri_nvic_nvicip30_reg_t;
typedef uint8_t  hri_nvic_nvicip31_reg_t;
typedef uint8_t  hri_nvic_nvicip32_reg_t;
typedef uint8_t  hri_nvic_nvicip33_reg_t;
typedef uint8_t  hri_nvic_nvicip34_reg_t;
typedef uint8_t  hri_nvic_nvicip35_reg_t;
typedef uint8_t  hri_nvic_nvicip36_reg_t;
typedef uint8_t  hri_nvic_nvicip37_reg_t;
typedef uint8_t  hri_nvic_nvicip38_reg_t;
typedef uint8_t  hri_nvic_nvicip39_reg_t;
typedef uint8_t  hri_nvic_nvicip3_reg_t;
typedef uint8_t  hri_nvic_nvicip40_reg_t;
typedef uint8_t  hri_nvic_nvicip41_reg_t;
typedef uint8_t  hri_nvic_nvicip42_reg_t;
typedef uint8_t  hri_nvic_nvicip43_reg_t;
typedef uint8_t  hri_nvic_nvicip44_reg_t;
typedef uint8_t  hri_nvic_nvicip45_reg_t;
typedef uint8_t  hri_nvic_nvicip46_reg_t;
typedef uint8_t  hri_nvic_nvicip47_reg_t;
typedef uint8_t  hri_nvic_nvicip48_reg_t;
typedef uint8_t  hri_nvic_nvicip49_reg_t;
typedef uint8_t  hri_nvic_nvicip4_reg_t;
typedef uint8_t  hri_nvic_nvicip50_reg_t;
typedef uint8_t  hri_nvic_nvicip51_reg_t;
typedef uint8_t  hri_nvic_nvicip52_reg_t;
typedef uint8_t  hri_nvic_nvicip53_reg_t;
typedef uint8_t  hri_nvic_nvicip54_reg_t;
typedef uint8_t  hri_nvic_nvicip55_reg_t;
typedef uint8_t  hri_nvic_nvicip56_reg_t;
typedef uint8_t  hri_nvic_nvicip57_reg_t;
typedef uint8_t  hri_nvic_nvicip58_reg_t;
typedef uint8_t  hri_nvic_nvicip59_reg_t;
typedef uint8_t  hri_nvic_nvicip5_reg_t;
typedef uint8_t  hri_nvic_nvicip60_reg_t;
typedef uint8_t  hri_nvic_nvicip61_reg_t;
typedef uint8_t  hri_nvic_nvicip62_reg_t;
typedef uint8_t  hri_nvic_nvicip63_reg_t;
typedef uint8_t  hri_nvic_nvicip64_reg_t;
typedef uint8_t  hri_nvic_nvicip65_reg_t;
typedef uint8_t  hri_nvic_nvicip66_reg_t;
typedef uint8_t  hri_nvic_nvicip67_reg_t;
typedef uint8_t  hri_nvic_nvicip68_reg_t;
typedef uint8_t  hri_nvic_nvicip69_reg_t;
typedef uint8_t  hri_nvic_nvicip6_reg_t;
typedef uint8_t  hri_nvic_nvicip70_reg_t;
typedef uint8_t  hri_nvic_nvicip71_reg_t;
typedef uint8_t  hri_nvic_nvicip72_reg_t;
typedef uint8_t  hri_nvic_nvicip73_reg_t;
typedef uint8_t  hri_nvic_nvicip74_reg_t;
typedef uint8_t  hri_nvic_nvicip75_reg_t;
typedef uint8_t  hri_nvic_nvicip76_reg_t;
typedef uint8_t  hri_nvic_nvicip77_reg_t;
typedef uint8_t  hri_nvic_nvicip78_reg_t;
typedef uint8_t  hri_nvic_nvicip79_reg_t;
typedef uint8_t  hri_nvic_nvicip7_reg_t;
typedef uint8_t  hri_nvic_nvicip80_reg_t;
typedef uint8_t  hri_nvic_nvicip81_reg_t;
typedef uint8_t  hri_nvic_nvicip82_reg_t;
typedef uint8_t  hri_nvic_nvicip83_reg_t;
typedef uint8_t  hri_nvic_nvicip84_reg_t;
typedef uint8_t  hri_nvic_nvicip85_reg_t;
typedef uint8_t  hri_nvic_nvicip86_reg_t;
typedef uint8_t  hri_nvic_nvicip87_reg_t;
typedef uint8_t  hri_nvic_nvicip88_reg_t;
typedef uint8_t  hri_nvic_nvicip89_reg_t;
typedef uint8_t  hri_nvic_nvicip8_reg_t;
typedef uint8_t  hri_nvic_nvicip90_reg_t;
typedef uint8_t  hri_nvic_nvicip91_reg_t;
typedef uint8_t  hri_nvic_nvicip92_reg_t;
typedef uint8_t  hri_nvic_nvicip93_reg_t;
typedef uint8_t  hri_nvic_nvicip94_reg_t;
typedef uint8_t  hri_nvic_nvicip95_reg_t;
typedef uint8_t  hri_nvic_nvicip96_reg_t;
typedef uint8_t  hri_nvic_nvicip97_reg_t;
typedef uint8_t  hri_nvic_nvicip98_reg_t;
typedef uint8_t  hri_nvic_nvicip99_reg_t;
typedef uint8_t  hri_nvic_nvicip9_reg_t;

static inline void hri_nvic_set_NVICISER0_SETENA_bf(const void *const hw, hri_nvic_nviciser0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISER0 |= NVIC_NVICISER0_SETENA(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nviciser0_reg_t hri_nvic_get_NVICISER0_SETENA_bf(const void *const        hw,
                                                                        hri_nvic_nviciser0_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICISER0;
	tmp = (tmp & NVIC_NVICISER0_SETENA(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICISER0_SETENA_bf(const void *const hw, hri_nvic_nviciser0_reg_t data)
{
	uint32_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICISER0;
	tmp &= ~NVIC_NVICISER0_SETENA_Msk;
	tmp |= NVIC_NVICISER0_SETENA(data);
	((Nvic *)hw)->NVICISER0 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICISER0_SETENA_bf(const void *const hw, hri_nvic_nviciser0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISER0 &= ~NVIC_NVICISER0_SETENA(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICISER0_SETENA_bf(const void *const hw, hri_nvic_nviciser0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISER0 ^= NVIC_NVICISER0_SETENA(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nviciser0_reg_t hri_nvic_read_NVICISER0_SETENA_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICISER0;
	tmp = (tmp & NVIC_NVICISER0_SETENA_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICISER0_reg(const void *const hw, hri_nvic_nviciser0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISER0 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nviciser0_reg_t hri_nvic_get_NVICISER0_reg(const void *const hw, hri_nvic_nviciser0_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICISER0;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICISER0_reg(const void *const hw, hri_nvic_nviciser0_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISER0 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICISER0_reg(const void *const hw, hri_nvic_nviciser0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISER0 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICISER0_reg(const void *const hw, hri_nvic_nviciser0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISER0 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nviciser0_reg_t hri_nvic_read_NVICISER0_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICISER0;
}

static inline void hri_nvic_set_NVICISER1_SETENA_bf(const void *const hw, hri_nvic_nviciser1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISER1 |= NVIC_NVICISER1_SETENA(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nviciser1_reg_t hri_nvic_get_NVICISER1_SETENA_bf(const void *const        hw,
                                                                        hri_nvic_nviciser1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICISER1;
	tmp = (tmp & NVIC_NVICISER1_SETENA(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICISER1_SETENA_bf(const void *const hw, hri_nvic_nviciser1_reg_t data)
{
	uint32_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICISER1;
	tmp &= ~NVIC_NVICISER1_SETENA_Msk;
	tmp |= NVIC_NVICISER1_SETENA(data);
	((Nvic *)hw)->NVICISER1 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICISER1_SETENA_bf(const void *const hw, hri_nvic_nviciser1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISER1 &= ~NVIC_NVICISER1_SETENA(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICISER1_SETENA_bf(const void *const hw, hri_nvic_nviciser1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISER1 ^= NVIC_NVICISER1_SETENA(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nviciser1_reg_t hri_nvic_read_NVICISER1_SETENA_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICISER1;
	tmp = (tmp & NVIC_NVICISER1_SETENA_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICISER1_reg(const void *const hw, hri_nvic_nviciser1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISER1 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nviciser1_reg_t hri_nvic_get_NVICISER1_reg(const void *const hw, hri_nvic_nviciser1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICISER1;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICISER1_reg(const void *const hw, hri_nvic_nviciser1_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISER1 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICISER1_reg(const void *const hw, hri_nvic_nviciser1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISER1 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICISER1_reg(const void *const hw, hri_nvic_nviciser1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISER1 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nviciser1_reg_t hri_nvic_read_NVICISER1_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICISER1;
}

static inline void hri_nvic_set_NVICISER2_SETENA_bf(const void *const hw, hri_nvic_nviciser2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISER2 |= NVIC_NVICISER2_SETENA(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nviciser2_reg_t hri_nvic_get_NVICISER2_SETENA_bf(const void *const        hw,
                                                                        hri_nvic_nviciser2_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICISER2;
	tmp = (tmp & NVIC_NVICISER2_SETENA(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICISER2_SETENA_bf(const void *const hw, hri_nvic_nviciser2_reg_t data)
{
	uint32_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICISER2;
	tmp &= ~NVIC_NVICISER2_SETENA_Msk;
	tmp |= NVIC_NVICISER2_SETENA(data);
	((Nvic *)hw)->NVICISER2 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICISER2_SETENA_bf(const void *const hw, hri_nvic_nviciser2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISER2 &= ~NVIC_NVICISER2_SETENA(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICISER2_SETENA_bf(const void *const hw, hri_nvic_nviciser2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISER2 ^= NVIC_NVICISER2_SETENA(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nviciser2_reg_t hri_nvic_read_NVICISER2_SETENA_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICISER2;
	tmp = (tmp & NVIC_NVICISER2_SETENA_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICISER2_reg(const void *const hw, hri_nvic_nviciser2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISER2 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nviciser2_reg_t hri_nvic_get_NVICISER2_reg(const void *const hw, hri_nvic_nviciser2_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICISER2;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICISER2_reg(const void *const hw, hri_nvic_nviciser2_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISER2 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICISER2_reg(const void *const hw, hri_nvic_nviciser2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISER2 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICISER2_reg(const void *const hw, hri_nvic_nviciser2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISER2 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nviciser2_reg_t hri_nvic_read_NVICISER2_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICISER2;
}

static inline void hri_nvic_set_NVICISER3_SETENA_bf(const void *const hw, hri_nvic_nviciser3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISER3 |= NVIC_NVICISER3_SETENA(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nviciser3_reg_t hri_nvic_get_NVICISER3_SETENA_bf(const void *const        hw,
                                                                        hri_nvic_nviciser3_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICISER3;
	tmp = (tmp & NVIC_NVICISER3_SETENA(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICISER3_SETENA_bf(const void *const hw, hri_nvic_nviciser3_reg_t data)
{
	uint32_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICISER3;
	tmp &= ~NVIC_NVICISER3_SETENA_Msk;
	tmp |= NVIC_NVICISER3_SETENA(data);
	((Nvic *)hw)->NVICISER3 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICISER3_SETENA_bf(const void *const hw, hri_nvic_nviciser3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISER3 &= ~NVIC_NVICISER3_SETENA(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICISER3_SETENA_bf(const void *const hw, hri_nvic_nviciser3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISER3 ^= NVIC_NVICISER3_SETENA(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nviciser3_reg_t hri_nvic_read_NVICISER3_SETENA_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICISER3;
	tmp = (tmp & NVIC_NVICISER3_SETENA_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICISER3_reg(const void *const hw, hri_nvic_nviciser3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISER3 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nviciser3_reg_t hri_nvic_get_NVICISER3_reg(const void *const hw, hri_nvic_nviciser3_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICISER3;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICISER3_reg(const void *const hw, hri_nvic_nviciser3_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISER3 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICISER3_reg(const void *const hw, hri_nvic_nviciser3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISER3 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICISER3_reg(const void *const hw, hri_nvic_nviciser3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISER3 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nviciser3_reg_t hri_nvic_read_NVICISER3_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICISER3;
}

static inline void hri_nvic_set_NVICICER0_CLRENA_bf(const void *const hw, hri_nvic_nvicicer0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICER0 |= NVIC_NVICICER0_CLRENA(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicicer0_reg_t hri_nvic_get_NVICICER0_CLRENA_bf(const void *const        hw,
                                                                        hri_nvic_nvicicer0_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICICER0;
	tmp = (tmp & NVIC_NVICICER0_CLRENA(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICICER0_CLRENA_bf(const void *const hw, hri_nvic_nvicicer0_reg_t data)
{
	uint32_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICICER0;
	tmp &= ~NVIC_NVICICER0_CLRENA_Msk;
	tmp |= NVIC_NVICICER0_CLRENA(data);
	((Nvic *)hw)->NVICICER0 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICICER0_CLRENA_bf(const void *const hw, hri_nvic_nvicicer0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICER0 &= ~NVIC_NVICICER0_CLRENA(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICICER0_CLRENA_bf(const void *const hw, hri_nvic_nvicicer0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICER0 ^= NVIC_NVICICER0_CLRENA(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicicer0_reg_t hri_nvic_read_NVICICER0_CLRENA_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICICER0;
	tmp = (tmp & NVIC_NVICICER0_CLRENA_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICICER0_reg(const void *const hw, hri_nvic_nvicicer0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICER0 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicicer0_reg_t hri_nvic_get_NVICICER0_reg(const void *const hw, hri_nvic_nvicicer0_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICICER0;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICICER0_reg(const void *const hw, hri_nvic_nvicicer0_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICER0 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICICER0_reg(const void *const hw, hri_nvic_nvicicer0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICER0 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICICER0_reg(const void *const hw, hri_nvic_nvicicer0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICER0 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicicer0_reg_t hri_nvic_read_NVICICER0_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICICER0;
}

static inline void hri_nvic_set_NVICICER1_CLRENA_bf(const void *const hw, hri_nvic_nvicicer1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICER1 |= NVIC_NVICICER1_CLRENA(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicicer1_reg_t hri_nvic_get_NVICICER1_CLRENA_bf(const void *const        hw,
                                                                        hri_nvic_nvicicer1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICICER1;
	tmp = (tmp & NVIC_NVICICER1_CLRENA(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICICER1_CLRENA_bf(const void *const hw, hri_nvic_nvicicer1_reg_t data)
{
	uint32_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICICER1;
	tmp &= ~NVIC_NVICICER1_CLRENA_Msk;
	tmp |= NVIC_NVICICER1_CLRENA(data);
	((Nvic *)hw)->NVICICER1 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICICER1_CLRENA_bf(const void *const hw, hri_nvic_nvicicer1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICER1 &= ~NVIC_NVICICER1_CLRENA(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICICER1_CLRENA_bf(const void *const hw, hri_nvic_nvicicer1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICER1 ^= NVIC_NVICICER1_CLRENA(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicicer1_reg_t hri_nvic_read_NVICICER1_CLRENA_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICICER1;
	tmp = (tmp & NVIC_NVICICER1_CLRENA_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICICER1_reg(const void *const hw, hri_nvic_nvicicer1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICER1 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicicer1_reg_t hri_nvic_get_NVICICER1_reg(const void *const hw, hri_nvic_nvicicer1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICICER1;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICICER1_reg(const void *const hw, hri_nvic_nvicicer1_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICER1 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICICER1_reg(const void *const hw, hri_nvic_nvicicer1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICER1 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICICER1_reg(const void *const hw, hri_nvic_nvicicer1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICER1 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicicer1_reg_t hri_nvic_read_NVICICER1_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICICER1;
}

static inline void hri_nvic_set_NVICICER2_CLRENA_bf(const void *const hw, hri_nvic_nvicicer2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICER2 |= NVIC_NVICICER2_CLRENA(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicicer2_reg_t hri_nvic_get_NVICICER2_CLRENA_bf(const void *const        hw,
                                                                        hri_nvic_nvicicer2_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICICER2;
	tmp = (tmp & NVIC_NVICICER2_CLRENA(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICICER2_CLRENA_bf(const void *const hw, hri_nvic_nvicicer2_reg_t data)
{
	uint32_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICICER2;
	tmp &= ~NVIC_NVICICER2_CLRENA_Msk;
	tmp |= NVIC_NVICICER2_CLRENA(data);
	((Nvic *)hw)->NVICICER2 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICICER2_CLRENA_bf(const void *const hw, hri_nvic_nvicicer2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICER2 &= ~NVIC_NVICICER2_CLRENA(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICICER2_CLRENA_bf(const void *const hw, hri_nvic_nvicicer2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICER2 ^= NVIC_NVICICER2_CLRENA(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicicer2_reg_t hri_nvic_read_NVICICER2_CLRENA_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICICER2;
	tmp = (tmp & NVIC_NVICICER2_CLRENA_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICICER2_reg(const void *const hw, hri_nvic_nvicicer2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICER2 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicicer2_reg_t hri_nvic_get_NVICICER2_reg(const void *const hw, hri_nvic_nvicicer2_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICICER2;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICICER2_reg(const void *const hw, hri_nvic_nvicicer2_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICER2 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICICER2_reg(const void *const hw, hri_nvic_nvicicer2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICER2 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICICER2_reg(const void *const hw, hri_nvic_nvicicer2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICER2 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicicer2_reg_t hri_nvic_read_NVICICER2_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICICER2;
}

static inline void hri_nvic_set_NVICICER3_CLRENA_bf(const void *const hw, hri_nvic_nvicicer3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICER3 |= NVIC_NVICICER3_CLRENA(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicicer3_reg_t hri_nvic_get_NVICICER3_CLRENA_bf(const void *const        hw,
                                                                        hri_nvic_nvicicer3_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICICER3;
	tmp = (tmp & NVIC_NVICICER3_CLRENA(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICICER3_CLRENA_bf(const void *const hw, hri_nvic_nvicicer3_reg_t data)
{
	uint32_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICICER3;
	tmp &= ~NVIC_NVICICER3_CLRENA_Msk;
	tmp |= NVIC_NVICICER3_CLRENA(data);
	((Nvic *)hw)->NVICICER3 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICICER3_CLRENA_bf(const void *const hw, hri_nvic_nvicicer3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICER3 &= ~NVIC_NVICICER3_CLRENA(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICICER3_CLRENA_bf(const void *const hw, hri_nvic_nvicicer3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICER3 ^= NVIC_NVICICER3_CLRENA(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicicer3_reg_t hri_nvic_read_NVICICER3_CLRENA_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICICER3;
	tmp = (tmp & NVIC_NVICICER3_CLRENA_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICICER3_reg(const void *const hw, hri_nvic_nvicicer3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICER3 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicicer3_reg_t hri_nvic_get_NVICICER3_reg(const void *const hw, hri_nvic_nvicicer3_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICICER3;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICICER3_reg(const void *const hw, hri_nvic_nvicicer3_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICER3 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICICER3_reg(const void *const hw, hri_nvic_nvicicer3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICER3 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICICER3_reg(const void *const hw, hri_nvic_nvicicer3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICER3 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicicer3_reg_t hri_nvic_read_NVICICER3_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICICER3;
}

static inline void hri_nvic_set_NVICISPR0_SETPEND_bf(const void *const hw, hri_nvic_nvicispr0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISPR0 |= NVIC_NVICISPR0_SETPEND(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicispr0_reg_t hri_nvic_get_NVICISPR0_SETPEND_bf(const void *const        hw,
                                                                         hri_nvic_nvicispr0_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICISPR0;
	tmp = (tmp & NVIC_NVICISPR0_SETPEND(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICISPR0_SETPEND_bf(const void *const hw, hri_nvic_nvicispr0_reg_t data)
{
	uint32_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICISPR0;
	tmp &= ~NVIC_NVICISPR0_SETPEND_Msk;
	tmp |= NVIC_NVICISPR0_SETPEND(data);
	((Nvic *)hw)->NVICISPR0 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICISPR0_SETPEND_bf(const void *const hw, hri_nvic_nvicispr0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISPR0 &= ~NVIC_NVICISPR0_SETPEND(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICISPR0_SETPEND_bf(const void *const hw, hri_nvic_nvicispr0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISPR0 ^= NVIC_NVICISPR0_SETPEND(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicispr0_reg_t hri_nvic_read_NVICISPR0_SETPEND_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICISPR0;
	tmp = (tmp & NVIC_NVICISPR0_SETPEND_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICISPR0_reg(const void *const hw, hri_nvic_nvicispr0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISPR0 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicispr0_reg_t hri_nvic_get_NVICISPR0_reg(const void *const hw, hri_nvic_nvicispr0_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICISPR0;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICISPR0_reg(const void *const hw, hri_nvic_nvicispr0_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISPR0 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICISPR0_reg(const void *const hw, hri_nvic_nvicispr0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISPR0 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICISPR0_reg(const void *const hw, hri_nvic_nvicispr0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISPR0 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicispr0_reg_t hri_nvic_read_NVICISPR0_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICISPR0;
}

static inline void hri_nvic_set_NVICISPR1_SETPEND_bf(const void *const hw, hri_nvic_nvicispr1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISPR1 |= NVIC_NVICISPR1_SETPEND(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicispr1_reg_t hri_nvic_get_NVICISPR1_SETPEND_bf(const void *const        hw,
                                                                         hri_nvic_nvicispr1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICISPR1;
	tmp = (tmp & NVIC_NVICISPR1_SETPEND(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICISPR1_SETPEND_bf(const void *const hw, hri_nvic_nvicispr1_reg_t data)
{
	uint32_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICISPR1;
	tmp &= ~NVIC_NVICISPR1_SETPEND_Msk;
	tmp |= NVIC_NVICISPR1_SETPEND(data);
	((Nvic *)hw)->NVICISPR1 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICISPR1_SETPEND_bf(const void *const hw, hri_nvic_nvicispr1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISPR1 &= ~NVIC_NVICISPR1_SETPEND(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICISPR1_SETPEND_bf(const void *const hw, hri_nvic_nvicispr1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISPR1 ^= NVIC_NVICISPR1_SETPEND(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicispr1_reg_t hri_nvic_read_NVICISPR1_SETPEND_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICISPR1;
	tmp = (tmp & NVIC_NVICISPR1_SETPEND_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICISPR1_reg(const void *const hw, hri_nvic_nvicispr1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISPR1 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicispr1_reg_t hri_nvic_get_NVICISPR1_reg(const void *const hw, hri_nvic_nvicispr1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICISPR1;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICISPR1_reg(const void *const hw, hri_nvic_nvicispr1_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISPR1 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICISPR1_reg(const void *const hw, hri_nvic_nvicispr1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISPR1 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICISPR1_reg(const void *const hw, hri_nvic_nvicispr1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISPR1 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicispr1_reg_t hri_nvic_read_NVICISPR1_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICISPR1;
}

static inline void hri_nvic_set_NVICISPR2_SETPEND_bf(const void *const hw, hri_nvic_nvicispr2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISPR2 |= NVIC_NVICISPR2_SETPEND(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicispr2_reg_t hri_nvic_get_NVICISPR2_SETPEND_bf(const void *const        hw,
                                                                         hri_nvic_nvicispr2_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICISPR2;
	tmp = (tmp & NVIC_NVICISPR2_SETPEND(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICISPR2_SETPEND_bf(const void *const hw, hri_nvic_nvicispr2_reg_t data)
{
	uint32_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICISPR2;
	tmp &= ~NVIC_NVICISPR2_SETPEND_Msk;
	tmp |= NVIC_NVICISPR2_SETPEND(data);
	((Nvic *)hw)->NVICISPR2 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICISPR2_SETPEND_bf(const void *const hw, hri_nvic_nvicispr2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISPR2 &= ~NVIC_NVICISPR2_SETPEND(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICISPR2_SETPEND_bf(const void *const hw, hri_nvic_nvicispr2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISPR2 ^= NVIC_NVICISPR2_SETPEND(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicispr2_reg_t hri_nvic_read_NVICISPR2_SETPEND_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICISPR2;
	tmp = (tmp & NVIC_NVICISPR2_SETPEND_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICISPR2_reg(const void *const hw, hri_nvic_nvicispr2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISPR2 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicispr2_reg_t hri_nvic_get_NVICISPR2_reg(const void *const hw, hri_nvic_nvicispr2_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICISPR2;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICISPR2_reg(const void *const hw, hri_nvic_nvicispr2_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISPR2 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICISPR2_reg(const void *const hw, hri_nvic_nvicispr2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISPR2 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICISPR2_reg(const void *const hw, hri_nvic_nvicispr2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISPR2 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicispr2_reg_t hri_nvic_read_NVICISPR2_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICISPR2;
}

static inline void hri_nvic_set_NVICISPR3_SETPEND_bf(const void *const hw, hri_nvic_nvicispr3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISPR3 |= NVIC_NVICISPR3_SETPEND(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicispr3_reg_t hri_nvic_get_NVICISPR3_SETPEND_bf(const void *const        hw,
                                                                         hri_nvic_nvicispr3_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICISPR3;
	tmp = (tmp & NVIC_NVICISPR3_SETPEND(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICISPR3_SETPEND_bf(const void *const hw, hri_nvic_nvicispr3_reg_t data)
{
	uint32_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICISPR3;
	tmp &= ~NVIC_NVICISPR3_SETPEND_Msk;
	tmp |= NVIC_NVICISPR3_SETPEND(data);
	((Nvic *)hw)->NVICISPR3 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICISPR3_SETPEND_bf(const void *const hw, hri_nvic_nvicispr3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISPR3 &= ~NVIC_NVICISPR3_SETPEND(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICISPR3_SETPEND_bf(const void *const hw, hri_nvic_nvicispr3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISPR3 ^= NVIC_NVICISPR3_SETPEND(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicispr3_reg_t hri_nvic_read_NVICISPR3_SETPEND_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICISPR3;
	tmp = (tmp & NVIC_NVICISPR3_SETPEND_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICISPR3_reg(const void *const hw, hri_nvic_nvicispr3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISPR3 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicispr3_reg_t hri_nvic_get_NVICISPR3_reg(const void *const hw, hri_nvic_nvicispr3_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICISPR3;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICISPR3_reg(const void *const hw, hri_nvic_nvicispr3_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISPR3 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICISPR3_reg(const void *const hw, hri_nvic_nvicispr3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISPR3 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICISPR3_reg(const void *const hw, hri_nvic_nvicispr3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICISPR3 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicispr3_reg_t hri_nvic_read_NVICISPR3_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICISPR3;
}

static inline void hri_nvic_set_NVICICPR0_CLRPEND_bf(const void *const hw, hri_nvic_nvicicpr0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICPR0 |= NVIC_NVICICPR0_CLRPEND(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicicpr0_reg_t hri_nvic_get_NVICICPR0_CLRPEND_bf(const void *const        hw,
                                                                         hri_nvic_nvicicpr0_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICICPR0;
	tmp = (tmp & NVIC_NVICICPR0_CLRPEND(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICICPR0_CLRPEND_bf(const void *const hw, hri_nvic_nvicicpr0_reg_t data)
{
	uint32_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICICPR0;
	tmp &= ~NVIC_NVICICPR0_CLRPEND_Msk;
	tmp |= NVIC_NVICICPR0_CLRPEND(data);
	((Nvic *)hw)->NVICICPR0 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICICPR0_CLRPEND_bf(const void *const hw, hri_nvic_nvicicpr0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICPR0 &= ~NVIC_NVICICPR0_CLRPEND(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICICPR0_CLRPEND_bf(const void *const hw, hri_nvic_nvicicpr0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICPR0 ^= NVIC_NVICICPR0_CLRPEND(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicicpr0_reg_t hri_nvic_read_NVICICPR0_CLRPEND_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICICPR0;
	tmp = (tmp & NVIC_NVICICPR0_CLRPEND_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICICPR0_reg(const void *const hw, hri_nvic_nvicicpr0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICPR0 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicicpr0_reg_t hri_nvic_get_NVICICPR0_reg(const void *const hw, hri_nvic_nvicicpr0_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICICPR0;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICICPR0_reg(const void *const hw, hri_nvic_nvicicpr0_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICPR0 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICICPR0_reg(const void *const hw, hri_nvic_nvicicpr0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICPR0 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICICPR0_reg(const void *const hw, hri_nvic_nvicicpr0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICPR0 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicicpr0_reg_t hri_nvic_read_NVICICPR0_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICICPR0;
}

static inline void hri_nvic_set_NVICICPR1_CLRPEND_bf(const void *const hw, hri_nvic_nvicicpr1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICPR1 |= NVIC_NVICICPR1_CLRPEND(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicicpr1_reg_t hri_nvic_get_NVICICPR1_CLRPEND_bf(const void *const        hw,
                                                                         hri_nvic_nvicicpr1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICICPR1;
	tmp = (tmp & NVIC_NVICICPR1_CLRPEND(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICICPR1_CLRPEND_bf(const void *const hw, hri_nvic_nvicicpr1_reg_t data)
{
	uint32_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICICPR1;
	tmp &= ~NVIC_NVICICPR1_CLRPEND_Msk;
	tmp |= NVIC_NVICICPR1_CLRPEND(data);
	((Nvic *)hw)->NVICICPR1 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICICPR1_CLRPEND_bf(const void *const hw, hri_nvic_nvicicpr1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICPR1 &= ~NVIC_NVICICPR1_CLRPEND(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICICPR1_CLRPEND_bf(const void *const hw, hri_nvic_nvicicpr1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICPR1 ^= NVIC_NVICICPR1_CLRPEND(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicicpr1_reg_t hri_nvic_read_NVICICPR1_CLRPEND_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICICPR1;
	tmp = (tmp & NVIC_NVICICPR1_CLRPEND_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICICPR1_reg(const void *const hw, hri_nvic_nvicicpr1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICPR1 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicicpr1_reg_t hri_nvic_get_NVICICPR1_reg(const void *const hw, hri_nvic_nvicicpr1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICICPR1;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICICPR1_reg(const void *const hw, hri_nvic_nvicicpr1_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICPR1 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICICPR1_reg(const void *const hw, hri_nvic_nvicicpr1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICPR1 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICICPR1_reg(const void *const hw, hri_nvic_nvicicpr1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICPR1 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicicpr1_reg_t hri_nvic_read_NVICICPR1_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICICPR1;
}

static inline void hri_nvic_set_NVICICPR2_CLRPEND_bf(const void *const hw, hri_nvic_nvicicpr2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICPR2 |= NVIC_NVICICPR2_CLRPEND(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicicpr2_reg_t hri_nvic_get_NVICICPR2_CLRPEND_bf(const void *const        hw,
                                                                         hri_nvic_nvicicpr2_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICICPR2;
	tmp = (tmp & NVIC_NVICICPR2_CLRPEND(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICICPR2_CLRPEND_bf(const void *const hw, hri_nvic_nvicicpr2_reg_t data)
{
	uint32_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICICPR2;
	tmp &= ~NVIC_NVICICPR2_CLRPEND_Msk;
	tmp |= NVIC_NVICICPR2_CLRPEND(data);
	((Nvic *)hw)->NVICICPR2 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICICPR2_CLRPEND_bf(const void *const hw, hri_nvic_nvicicpr2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICPR2 &= ~NVIC_NVICICPR2_CLRPEND(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICICPR2_CLRPEND_bf(const void *const hw, hri_nvic_nvicicpr2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICPR2 ^= NVIC_NVICICPR2_CLRPEND(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicicpr2_reg_t hri_nvic_read_NVICICPR2_CLRPEND_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICICPR2;
	tmp = (tmp & NVIC_NVICICPR2_CLRPEND_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICICPR2_reg(const void *const hw, hri_nvic_nvicicpr2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICPR2 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicicpr2_reg_t hri_nvic_get_NVICICPR2_reg(const void *const hw, hri_nvic_nvicicpr2_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICICPR2;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICICPR2_reg(const void *const hw, hri_nvic_nvicicpr2_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICPR2 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICICPR2_reg(const void *const hw, hri_nvic_nvicicpr2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICPR2 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICICPR2_reg(const void *const hw, hri_nvic_nvicicpr2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICPR2 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicicpr2_reg_t hri_nvic_read_NVICICPR2_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICICPR2;
}

static inline void hri_nvic_set_NVICICPR3_CLRPEND_bf(const void *const hw, hri_nvic_nvicicpr3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICPR3 |= NVIC_NVICICPR3_CLRPEND(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicicpr3_reg_t hri_nvic_get_NVICICPR3_CLRPEND_bf(const void *const        hw,
                                                                         hri_nvic_nvicicpr3_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICICPR3;
	tmp = (tmp & NVIC_NVICICPR3_CLRPEND(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICICPR3_CLRPEND_bf(const void *const hw, hri_nvic_nvicicpr3_reg_t data)
{
	uint32_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICICPR3;
	tmp &= ~NVIC_NVICICPR3_CLRPEND_Msk;
	tmp |= NVIC_NVICICPR3_CLRPEND(data);
	((Nvic *)hw)->NVICICPR3 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICICPR3_CLRPEND_bf(const void *const hw, hri_nvic_nvicicpr3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICPR3 &= ~NVIC_NVICICPR3_CLRPEND(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICICPR3_CLRPEND_bf(const void *const hw, hri_nvic_nvicicpr3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICPR3 ^= NVIC_NVICICPR3_CLRPEND(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicicpr3_reg_t hri_nvic_read_NVICICPR3_CLRPEND_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICICPR3;
	tmp = (tmp & NVIC_NVICICPR3_CLRPEND_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICICPR3_reg(const void *const hw, hri_nvic_nvicicpr3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICPR3 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicicpr3_reg_t hri_nvic_get_NVICICPR3_reg(const void *const hw, hri_nvic_nvicicpr3_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICICPR3;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICICPR3_reg(const void *const hw, hri_nvic_nvicicpr3_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICPR3 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICICPR3_reg(const void *const hw, hri_nvic_nvicicpr3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICPR3 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICICPR3_reg(const void *const hw, hri_nvic_nvicicpr3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICICPR3 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicicpr3_reg_t hri_nvic_read_NVICICPR3_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICICPR3;
}

static inline void hri_nvic_set_NVICIABR0_ACTIVE_bf(const void *const hw, hri_nvic_nviciabr0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIABR0 |= NVIC_NVICIABR0_ACTIVE(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nviciabr0_reg_t hri_nvic_get_NVICIABR0_ACTIVE_bf(const void *const        hw,
                                                                        hri_nvic_nviciabr0_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICIABR0;
	tmp = (tmp & NVIC_NVICIABR0_ACTIVE(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIABR0_ACTIVE_bf(const void *const hw, hri_nvic_nviciabr0_reg_t data)
{
	uint32_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIABR0;
	tmp &= ~NVIC_NVICIABR0_ACTIVE_Msk;
	tmp |= NVIC_NVICIABR0_ACTIVE(data);
	((Nvic *)hw)->NVICIABR0 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIABR0_ACTIVE_bf(const void *const hw, hri_nvic_nviciabr0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIABR0 &= ~NVIC_NVICIABR0_ACTIVE(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIABR0_ACTIVE_bf(const void *const hw, hri_nvic_nviciabr0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIABR0 ^= NVIC_NVICIABR0_ACTIVE(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nviciabr0_reg_t hri_nvic_read_NVICIABR0_ACTIVE_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICIABR0;
	tmp = (tmp & NVIC_NVICIABR0_ACTIVE_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIABR0_reg(const void *const hw, hri_nvic_nviciabr0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIABR0 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nviciabr0_reg_t hri_nvic_get_NVICIABR0_reg(const void *const hw, hri_nvic_nviciabr0_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICIABR0;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIABR0_reg(const void *const hw, hri_nvic_nviciabr0_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIABR0 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIABR0_reg(const void *const hw, hri_nvic_nviciabr0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIABR0 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIABR0_reg(const void *const hw, hri_nvic_nviciabr0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIABR0 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nviciabr0_reg_t hri_nvic_read_NVICIABR0_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIABR0;
}

static inline void hri_nvic_set_NVICIABR1_ACTIVE_bf(const void *const hw, hri_nvic_nviciabr1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIABR1 |= NVIC_NVICIABR1_ACTIVE(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nviciabr1_reg_t hri_nvic_get_NVICIABR1_ACTIVE_bf(const void *const        hw,
                                                                        hri_nvic_nviciabr1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICIABR1;
	tmp = (tmp & NVIC_NVICIABR1_ACTIVE(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIABR1_ACTIVE_bf(const void *const hw, hri_nvic_nviciabr1_reg_t data)
{
	uint32_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIABR1;
	tmp &= ~NVIC_NVICIABR1_ACTIVE_Msk;
	tmp |= NVIC_NVICIABR1_ACTIVE(data);
	((Nvic *)hw)->NVICIABR1 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIABR1_ACTIVE_bf(const void *const hw, hri_nvic_nviciabr1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIABR1 &= ~NVIC_NVICIABR1_ACTIVE(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIABR1_ACTIVE_bf(const void *const hw, hri_nvic_nviciabr1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIABR1 ^= NVIC_NVICIABR1_ACTIVE(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nviciabr1_reg_t hri_nvic_read_NVICIABR1_ACTIVE_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICIABR1;
	tmp = (tmp & NVIC_NVICIABR1_ACTIVE_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIABR1_reg(const void *const hw, hri_nvic_nviciabr1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIABR1 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nviciabr1_reg_t hri_nvic_get_NVICIABR1_reg(const void *const hw, hri_nvic_nviciabr1_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICIABR1;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIABR1_reg(const void *const hw, hri_nvic_nviciabr1_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIABR1 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIABR1_reg(const void *const hw, hri_nvic_nviciabr1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIABR1 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIABR1_reg(const void *const hw, hri_nvic_nviciabr1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIABR1 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nviciabr1_reg_t hri_nvic_read_NVICIABR1_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIABR1;
}

static inline void hri_nvic_set_NVICIABR2_ACTIVE_bf(const void *const hw, hri_nvic_nviciabr2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIABR2 |= NVIC_NVICIABR2_ACTIVE(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nviciabr2_reg_t hri_nvic_get_NVICIABR2_ACTIVE_bf(const void *const        hw,
                                                                        hri_nvic_nviciabr2_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICIABR2;
	tmp = (tmp & NVIC_NVICIABR2_ACTIVE(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIABR2_ACTIVE_bf(const void *const hw, hri_nvic_nviciabr2_reg_t data)
{
	uint32_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIABR2;
	tmp &= ~NVIC_NVICIABR2_ACTIVE_Msk;
	tmp |= NVIC_NVICIABR2_ACTIVE(data);
	((Nvic *)hw)->NVICIABR2 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIABR2_ACTIVE_bf(const void *const hw, hri_nvic_nviciabr2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIABR2 &= ~NVIC_NVICIABR2_ACTIVE(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIABR2_ACTIVE_bf(const void *const hw, hri_nvic_nviciabr2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIABR2 ^= NVIC_NVICIABR2_ACTIVE(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nviciabr2_reg_t hri_nvic_read_NVICIABR2_ACTIVE_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICIABR2;
	tmp = (tmp & NVIC_NVICIABR2_ACTIVE_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIABR2_reg(const void *const hw, hri_nvic_nviciabr2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIABR2 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nviciabr2_reg_t hri_nvic_get_NVICIABR2_reg(const void *const hw, hri_nvic_nviciabr2_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICIABR2;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIABR2_reg(const void *const hw, hri_nvic_nviciabr2_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIABR2 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIABR2_reg(const void *const hw, hri_nvic_nviciabr2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIABR2 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIABR2_reg(const void *const hw, hri_nvic_nviciabr2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIABR2 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nviciabr2_reg_t hri_nvic_read_NVICIABR2_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIABR2;
}

static inline void hri_nvic_set_NVICIABR3_ACTIVE_bf(const void *const hw, hri_nvic_nviciabr3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIABR3 |= NVIC_NVICIABR3_ACTIVE(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nviciabr3_reg_t hri_nvic_get_NVICIABR3_ACTIVE_bf(const void *const        hw,
                                                                        hri_nvic_nviciabr3_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICIABR3;
	tmp = (tmp & NVIC_NVICIABR3_ACTIVE(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIABR3_ACTIVE_bf(const void *const hw, hri_nvic_nviciabr3_reg_t data)
{
	uint32_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIABR3;
	tmp &= ~NVIC_NVICIABR3_ACTIVE_Msk;
	tmp |= NVIC_NVICIABR3_ACTIVE(data);
	((Nvic *)hw)->NVICIABR3 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIABR3_ACTIVE_bf(const void *const hw, hri_nvic_nviciabr3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIABR3 &= ~NVIC_NVICIABR3_ACTIVE(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIABR3_ACTIVE_bf(const void *const hw, hri_nvic_nviciabr3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIABR3 ^= NVIC_NVICIABR3_ACTIVE(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nviciabr3_reg_t hri_nvic_read_NVICIABR3_ACTIVE_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICIABR3;
	tmp = (tmp & NVIC_NVICIABR3_ACTIVE_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIABR3_reg(const void *const hw, hri_nvic_nviciabr3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIABR3 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nviciabr3_reg_t hri_nvic_get_NVICIABR3_reg(const void *const hw, hri_nvic_nviciabr3_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICIABR3;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIABR3_reg(const void *const hw, hri_nvic_nviciabr3_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIABR3 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIABR3_reg(const void *const hw, hri_nvic_nviciabr3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIABR3 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIABR3_reg(const void *const hw, hri_nvic_nviciabr3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIABR3 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nviciabr3_reg_t hri_nvic_read_NVICIABR3_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIABR3;
}

static inline void hri_nvic_set_NVICIP0_PRI0_bf(const void *const hw, hri_nvic_nvicip0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP0 |= NVIC_NVICIP0_PRI0(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip0_reg_t hri_nvic_get_NVICIP0_PRI0_bf(const void *const hw, hri_nvic_nvicip0_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP0;
	tmp = (tmp & NVIC_NVICIP0_PRI0(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP0_PRI0_bf(const void *const hw, hri_nvic_nvicip0_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP0;
	tmp &= ~NVIC_NVICIP0_PRI0_Msk;
	tmp |= NVIC_NVICIP0_PRI0(data);
	((Nvic *)hw)->NVICIP0 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP0_PRI0_bf(const void *const hw, hri_nvic_nvicip0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP0 &= ~NVIC_NVICIP0_PRI0(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP0_PRI0_bf(const void *const hw, hri_nvic_nvicip0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP0 ^= NVIC_NVICIP0_PRI0(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip0_reg_t hri_nvic_read_NVICIP0_PRI0_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP0;
	tmp = (tmp & NVIC_NVICIP0_PRI0_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP0_reg(const void *const hw, hri_nvic_nvicip0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP0 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip0_reg_t hri_nvic_get_NVICIP0_reg(const void *const hw, hri_nvic_nvicip0_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP0;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP0_reg(const void *const hw, hri_nvic_nvicip0_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP0 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP0_reg(const void *const hw, hri_nvic_nvicip0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP0 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP0_reg(const void *const hw, hri_nvic_nvicip0_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP0 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip0_reg_t hri_nvic_read_NVICIP0_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP0;
}

static inline void hri_nvic_set_NVICIP1_PRI1_bf(const void *const hw, hri_nvic_nvicip1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP1 |= NVIC_NVICIP1_PRI1(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip1_reg_t hri_nvic_get_NVICIP1_PRI1_bf(const void *const hw, hri_nvic_nvicip1_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP1;
	tmp = (tmp & NVIC_NVICIP1_PRI1(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP1_PRI1_bf(const void *const hw, hri_nvic_nvicip1_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP1;
	tmp &= ~NVIC_NVICIP1_PRI1_Msk;
	tmp |= NVIC_NVICIP1_PRI1(data);
	((Nvic *)hw)->NVICIP1 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP1_PRI1_bf(const void *const hw, hri_nvic_nvicip1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP1 &= ~NVIC_NVICIP1_PRI1(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP1_PRI1_bf(const void *const hw, hri_nvic_nvicip1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP1 ^= NVIC_NVICIP1_PRI1(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip1_reg_t hri_nvic_read_NVICIP1_PRI1_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP1;
	tmp = (tmp & NVIC_NVICIP1_PRI1_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP1_reg(const void *const hw, hri_nvic_nvicip1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP1 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip1_reg_t hri_nvic_get_NVICIP1_reg(const void *const hw, hri_nvic_nvicip1_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP1;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP1_reg(const void *const hw, hri_nvic_nvicip1_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP1 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP1_reg(const void *const hw, hri_nvic_nvicip1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP1 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP1_reg(const void *const hw, hri_nvic_nvicip1_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP1 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip1_reg_t hri_nvic_read_NVICIP1_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP1;
}

static inline void hri_nvic_set_NVICIP2_PRI2_bf(const void *const hw, hri_nvic_nvicip2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP2 |= NVIC_NVICIP2_PRI2(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip2_reg_t hri_nvic_get_NVICIP2_PRI2_bf(const void *const hw, hri_nvic_nvicip2_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP2;
	tmp = (tmp & NVIC_NVICIP2_PRI2(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP2_PRI2_bf(const void *const hw, hri_nvic_nvicip2_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP2;
	tmp &= ~NVIC_NVICIP2_PRI2_Msk;
	tmp |= NVIC_NVICIP2_PRI2(data);
	((Nvic *)hw)->NVICIP2 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP2_PRI2_bf(const void *const hw, hri_nvic_nvicip2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP2 &= ~NVIC_NVICIP2_PRI2(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP2_PRI2_bf(const void *const hw, hri_nvic_nvicip2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP2 ^= NVIC_NVICIP2_PRI2(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip2_reg_t hri_nvic_read_NVICIP2_PRI2_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP2;
	tmp = (tmp & NVIC_NVICIP2_PRI2_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP2_reg(const void *const hw, hri_nvic_nvicip2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP2 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip2_reg_t hri_nvic_get_NVICIP2_reg(const void *const hw, hri_nvic_nvicip2_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP2;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP2_reg(const void *const hw, hri_nvic_nvicip2_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP2 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP2_reg(const void *const hw, hri_nvic_nvicip2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP2 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP2_reg(const void *const hw, hri_nvic_nvicip2_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP2 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip2_reg_t hri_nvic_read_NVICIP2_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP2;
}

static inline void hri_nvic_set_NVICIP3_PRI3_bf(const void *const hw, hri_nvic_nvicip3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP3 |= NVIC_NVICIP3_PRI3(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip3_reg_t hri_nvic_get_NVICIP3_PRI3_bf(const void *const hw, hri_nvic_nvicip3_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP3;
	tmp = (tmp & NVIC_NVICIP3_PRI3(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP3_PRI3_bf(const void *const hw, hri_nvic_nvicip3_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP3;
	tmp &= ~NVIC_NVICIP3_PRI3_Msk;
	tmp |= NVIC_NVICIP3_PRI3(data);
	((Nvic *)hw)->NVICIP3 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP3_PRI3_bf(const void *const hw, hri_nvic_nvicip3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP3 &= ~NVIC_NVICIP3_PRI3(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP3_PRI3_bf(const void *const hw, hri_nvic_nvicip3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP3 ^= NVIC_NVICIP3_PRI3(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip3_reg_t hri_nvic_read_NVICIP3_PRI3_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP3;
	tmp = (tmp & NVIC_NVICIP3_PRI3_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP3_reg(const void *const hw, hri_nvic_nvicip3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP3 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip3_reg_t hri_nvic_get_NVICIP3_reg(const void *const hw, hri_nvic_nvicip3_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP3;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP3_reg(const void *const hw, hri_nvic_nvicip3_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP3 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP3_reg(const void *const hw, hri_nvic_nvicip3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP3 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP3_reg(const void *const hw, hri_nvic_nvicip3_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP3 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip3_reg_t hri_nvic_read_NVICIP3_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP3;
}

static inline void hri_nvic_set_NVICIP4_PRI4_bf(const void *const hw, hri_nvic_nvicip4_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP4 |= NVIC_NVICIP4_PRI4(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip4_reg_t hri_nvic_get_NVICIP4_PRI4_bf(const void *const hw, hri_nvic_nvicip4_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP4;
	tmp = (tmp & NVIC_NVICIP4_PRI4(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP4_PRI4_bf(const void *const hw, hri_nvic_nvicip4_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP4;
	tmp &= ~NVIC_NVICIP4_PRI4_Msk;
	tmp |= NVIC_NVICIP4_PRI4(data);
	((Nvic *)hw)->NVICIP4 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP4_PRI4_bf(const void *const hw, hri_nvic_nvicip4_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP4 &= ~NVIC_NVICIP4_PRI4(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP4_PRI4_bf(const void *const hw, hri_nvic_nvicip4_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP4 ^= NVIC_NVICIP4_PRI4(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip4_reg_t hri_nvic_read_NVICIP4_PRI4_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP4;
	tmp = (tmp & NVIC_NVICIP4_PRI4_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP4_reg(const void *const hw, hri_nvic_nvicip4_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP4 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip4_reg_t hri_nvic_get_NVICIP4_reg(const void *const hw, hri_nvic_nvicip4_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP4;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP4_reg(const void *const hw, hri_nvic_nvicip4_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP4 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP4_reg(const void *const hw, hri_nvic_nvicip4_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP4 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP4_reg(const void *const hw, hri_nvic_nvicip4_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP4 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip4_reg_t hri_nvic_read_NVICIP4_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP4;
}

static inline void hri_nvic_set_NVICIP5_PRI5_bf(const void *const hw, hri_nvic_nvicip5_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP5 |= NVIC_NVICIP5_PRI5(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip5_reg_t hri_nvic_get_NVICIP5_PRI5_bf(const void *const hw, hri_nvic_nvicip5_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP5;
	tmp = (tmp & NVIC_NVICIP5_PRI5(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP5_PRI5_bf(const void *const hw, hri_nvic_nvicip5_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP5;
	tmp &= ~NVIC_NVICIP5_PRI5_Msk;
	tmp |= NVIC_NVICIP5_PRI5(data);
	((Nvic *)hw)->NVICIP5 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP5_PRI5_bf(const void *const hw, hri_nvic_nvicip5_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP5 &= ~NVIC_NVICIP5_PRI5(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP5_PRI5_bf(const void *const hw, hri_nvic_nvicip5_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP5 ^= NVIC_NVICIP5_PRI5(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip5_reg_t hri_nvic_read_NVICIP5_PRI5_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP5;
	tmp = (tmp & NVIC_NVICIP5_PRI5_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP5_reg(const void *const hw, hri_nvic_nvicip5_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP5 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip5_reg_t hri_nvic_get_NVICIP5_reg(const void *const hw, hri_nvic_nvicip5_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP5;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP5_reg(const void *const hw, hri_nvic_nvicip5_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP5 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP5_reg(const void *const hw, hri_nvic_nvicip5_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP5 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP5_reg(const void *const hw, hri_nvic_nvicip5_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP5 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip5_reg_t hri_nvic_read_NVICIP5_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP5;
}

static inline void hri_nvic_set_NVICIP6_PRI6_bf(const void *const hw, hri_nvic_nvicip6_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP6 |= NVIC_NVICIP6_PRI6(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip6_reg_t hri_nvic_get_NVICIP6_PRI6_bf(const void *const hw, hri_nvic_nvicip6_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP6;
	tmp = (tmp & NVIC_NVICIP6_PRI6(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP6_PRI6_bf(const void *const hw, hri_nvic_nvicip6_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP6;
	tmp &= ~NVIC_NVICIP6_PRI6_Msk;
	tmp |= NVIC_NVICIP6_PRI6(data);
	((Nvic *)hw)->NVICIP6 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP6_PRI6_bf(const void *const hw, hri_nvic_nvicip6_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP6 &= ~NVIC_NVICIP6_PRI6(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP6_PRI6_bf(const void *const hw, hri_nvic_nvicip6_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP6 ^= NVIC_NVICIP6_PRI6(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip6_reg_t hri_nvic_read_NVICIP6_PRI6_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP6;
	tmp = (tmp & NVIC_NVICIP6_PRI6_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP6_reg(const void *const hw, hri_nvic_nvicip6_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP6 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip6_reg_t hri_nvic_get_NVICIP6_reg(const void *const hw, hri_nvic_nvicip6_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP6;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP6_reg(const void *const hw, hri_nvic_nvicip6_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP6 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP6_reg(const void *const hw, hri_nvic_nvicip6_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP6 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP6_reg(const void *const hw, hri_nvic_nvicip6_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP6 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip6_reg_t hri_nvic_read_NVICIP6_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP6;
}

static inline void hri_nvic_set_NVICIP7_PRI7_bf(const void *const hw, hri_nvic_nvicip7_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP7 |= NVIC_NVICIP7_PRI7(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip7_reg_t hri_nvic_get_NVICIP7_PRI7_bf(const void *const hw, hri_nvic_nvicip7_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP7;
	tmp = (tmp & NVIC_NVICIP7_PRI7(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP7_PRI7_bf(const void *const hw, hri_nvic_nvicip7_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP7;
	tmp &= ~NVIC_NVICIP7_PRI7_Msk;
	tmp |= NVIC_NVICIP7_PRI7(data);
	((Nvic *)hw)->NVICIP7 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP7_PRI7_bf(const void *const hw, hri_nvic_nvicip7_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP7 &= ~NVIC_NVICIP7_PRI7(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP7_PRI7_bf(const void *const hw, hri_nvic_nvicip7_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP7 ^= NVIC_NVICIP7_PRI7(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip7_reg_t hri_nvic_read_NVICIP7_PRI7_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP7;
	tmp = (tmp & NVIC_NVICIP7_PRI7_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP7_reg(const void *const hw, hri_nvic_nvicip7_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP7 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip7_reg_t hri_nvic_get_NVICIP7_reg(const void *const hw, hri_nvic_nvicip7_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP7;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP7_reg(const void *const hw, hri_nvic_nvicip7_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP7 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP7_reg(const void *const hw, hri_nvic_nvicip7_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP7 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP7_reg(const void *const hw, hri_nvic_nvicip7_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP7 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip7_reg_t hri_nvic_read_NVICIP7_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP7;
}

static inline void hri_nvic_set_NVICIP8_PRI8_bf(const void *const hw, hri_nvic_nvicip8_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP8 |= NVIC_NVICIP8_PRI8(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip8_reg_t hri_nvic_get_NVICIP8_PRI8_bf(const void *const hw, hri_nvic_nvicip8_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP8;
	tmp = (tmp & NVIC_NVICIP8_PRI8(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP8_PRI8_bf(const void *const hw, hri_nvic_nvicip8_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP8;
	tmp &= ~NVIC_NVICIP8_PRI8_Msk;
	tmp |= NVIC_NVICIP8_PRI8(data);
	((Nvic *)hw)->NVICIP8 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP8_PRI8_bf(const void *const hw, hri_nvic_nvicip8_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP8 &= ~NVIC_NVICIP8_PRI8(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP8_PRI8_bf(const void *const hw, hri_nvic_nvicip8_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP8 ^= NVIC_NVICIP8_PRI8(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip8_reg_t hri_nvic_read_NVICIP8_PRI8_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP8;
	tmp = (tmp & NVIC_NVICIP8_PRI8_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP8_reg(const void *const hw, hri_nvic_nvicip8_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP8 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip8_reg_t hri_nvic_get_NVICIP8_reg(const void *const hw, hri_nvic_nvicip8_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP8;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP8_reg(const void *const hw, hri_nvic_nvicip8_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP8 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP8_reg(const void *const hw, hri_nvic_nvicip8_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP8 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP8_reg(const void *const hw, hri_nvic_nvicip8_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP8 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip8_reg_t hri_nvic_read_NVICIP8_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP8;
}

static inline void hri_nvic_set_NVICIP9_PRI9_bf(const void *const hw, hri_nvic_nvicip9_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP9 |= NVIC_NVICIP9_PRI9(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip9_reg_t hri_nvic_get_NVICIP9_PRI9_bf(const void *const hw, hri_nvic_nvicip9_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP9;
	tmp = (tmp & NVIC_NVICIP9_PRI9(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP9_PRI9_bf(const void *const hw, hri_nvic_nvicip9_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP9;
	tmp &= ~NVIC_NVICIP9_PRI9_Msk;
	tmp |= NVIC_NVICIP9_PRI9(data);
	((Nvic *)hw)->NVICIP9 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP9_PRI9_bf(const void *const hw, hri_nvic_nvicip9_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP9 &= ~NVIC_NVICIP9_PRI9(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP9_PRI9_bf(const void *const hw, hri_nvic_nvicip9_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP9 ^= NVIC_NVICIP9_PRI9(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip9_reg_t hri_nvic_read_NVICIP9_PRI9_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP9;
	tmp = (tmp & NVIC_NVICIP9_PRI9_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP9_reg(const void *const hw, hri_nvic_nvicip9_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP9 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip9_reg_t hri_nvic_get_NVICIP9_reg(const void *const hw, hri_nvic_nvicip9_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP9;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP9_reg(const void *const hw, hri_nvic_nvicip9_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP9 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP9_reg(const void *const hw, hri_nvic_nvicip9_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP9 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP9_reg(const void *const hw, hri_nvic_nvicip9_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP9 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip9_reg_t hri_nvic_read_NVICIP9_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP9;
}

static inline void hri_nvic_set_NVICIP10_PRI10_bf(const void *const hw, hri_nvic_nvicip10_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP10 |= NVIC_NVICIP10_PRI10(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip10_reg_t hri_nvic_get_NVICIP10_PRI10_bf(const void *const hw, hri_nvic_nvicip10_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP10;
	tmp = (tmp & NVIC_NVICIP10_PRI10(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP10_PRI10_bf(const void *const hw, hri_nvic_nvicip10_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP10;
	tmp &= ~NVIC_NVICIP10_PRI10_Msk;
	tmp |= NVIC_NVICIP10_PRI10(data);
	((Nvic *)hw)->NVICIP10 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP10_PRI10_bf(const void *const hw, hri_nvic_nvicip10_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP10 &= ~NVIC_NVICIP10_PRI10(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP10_PRI10_bf(const void *const hw, hri_nvic_nvicip10_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP10 ^= NVIC_NVICIP10_PRI10(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip10_reg_t hri_nvic_read_NVICIP10_PRI10_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP10;
	tmp = (tmp & NVIC_NVICIP10_PRI10_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP10_reg(const void *const hw, hri_nvic_nvicip10_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP10 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip10_reg_t hri_nvic_get_NVICIP10_reg(const void *const hw, hri_nvic_nvicip10_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP10;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP10_reg(const void *const hw, hri_nvic_nvicip10_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP10 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP10_reg(const void *const hw, hri_nvic_nvicip10_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP10 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP10_reg(const void *const hw, hri_nvic_nvicip10_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP10 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip10_reg_t hri_nvic_read_NVICIP10_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP10;
}

static inline void hri_nvic_set_NVICIP11_PRI11_bf(const void *const hw, hri_nvic_nvicip11_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP11 |= NVIC_NVICIP11_PRI11(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip11_reg_t hri_nvic_get_NVICIP11_PRI11_bf(const void *const hw, hri_nvic_nvicip11_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP11;
	tmp = (tmp & NVIC_NVICIP11_PRI11(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP11_PRI11_bf(const void *const hw, hri_nvic_nvicip11_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP11;
	tmp &= ~NVIC_NVICIP11_PRI11_Msk;
	tmp |= NVIC_NVICIP11_PRI11(data);
	((Nvic *)hw)->NVICIP11 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP11_PRI11_bf(const void *const hw, hri_nvic_nvicip11_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP11 &= ~NVIC_NVICIP11_PRI11(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP11_PRI11_bf(const void *const hw, hri_nvic_nvicip11_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP11 ^= NVIC_NVICIP11_PRI11(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip11_reg_t hri_nvic_read_NVICIP11_PRI11_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP11;
	tmp = (tmp & NVIC_NVICIP11_PRI11_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP11_reg(const void *const hw, hri_nvic_nvicip11_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP11 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip11_reg_t hri_nvic_get_NVICIP11_reg(const void *const hw, hri_nvic_nvicip11_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP11;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP11_reg(const void *const hw, hri_nvic_nvicip11_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP11 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP11_reg(const void *const hw, hri_nvic_nvicip11_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP11 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP11_reg(const void *const hw, hri_nvic_nvicip11_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP11 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip11_reg_t hri_nvic_read_NVICIP11_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP11;
}

static inline void hri_nvic_set_NVICIP12_PRI12_bf(const void *const hw, hri_nvic_nvicip12_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP12 |= NVIC_NVICIP12_PRI12(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip12_reg_t hri_nvic_get_NVICIP12_PRI12_bf(const void *const hw, hri_nvic_nvicip12_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP12;
	tmp = (tmp & NVIC_NVICIP12_PRI12(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP12_PRI12_bf(const void *const hw, hri_nvic_nvicip12_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP12;
	tmp &= ~NVIC_NVICIP12_PRI12_Msk;
	tmp |= NVIC_NVICIP12_PRI12(data);
	((Nvic *)hw)->NVICIP12 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP12_PRI12_bf(const void *const hw, hri_nvic_nvicip12_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP12 &= ~NVIC_NVICIP12_PRI12(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP12_PRI12_bf(const void *const hw, hri_nvic_nvicip12_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP12 ^= NVIC_NVICIP12_PRI12(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip12_reg_t hri_nvic_read_NVICIP12_PRI12_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP12;
	tmp = (tmp & NVIC_NVICIP12_PRI12_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP12_reg(const void *const hw, hri_nvic_nvicip12_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP12 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip12_reg_t hri_nvic_get_NVICIP12_reg(const void *const hw, hri_nvic_nvicip12_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP12;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP12_reg(const void *const hw, hri_nvic_nvicip12_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP12 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP12_reg(const void *const hw, hri_nvic_nvicip12_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP12 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP12_reg(const void *const hw, hri_nvic_nvicip12_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP12 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip12_reg_t hri_nvic_read_NVICIP12_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP12;
}

static inline void hri_nvic_set_NVICIP13_PRI13_bf(const void *const hw, hri_nvic_nvicip13_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP13 |= NVIC_NVICIP13_PRI13(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip13_reg_t hri_nvic_get_NVICIP13_PRI13_bf(const void *const hw, hri_nvic_nvicip13_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP13;
	tmp = (tmp & NVIC_NVICIP13_PRI13(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP13_PRI13_bf(const void *const hw, hri_nvic_nvicip13_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP13;
	tmp &= ~NVIC_NVICIP13_PRI13_Msk;
	tmp |= NVIC_NVICIP13_PRI13(data);
	((Nvic *)hw)->NVICIP13 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP13_PRI13_bf(const void *const hw, hri_nvic_nvicip13_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP13 &= ~NVIC_NVICIP13_PRI13(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP13_PRI13_bf(const void *const hw, hri_nvic_nvicip13_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP13 ^= NVIC_NVICIP13_PRI13(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip13_reg_t hri_nvic_read_NVICIP13_PRI13_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP13;
	tmp = (tmp & NVIC_NVICIP13_PRI13_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP13_reg(const void *const hw, hri_nvic_nvicip13_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP13 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip13_reg_t hri_nvic_get_NVICIP13_reg(const void *const hw, hri_nvic_nvicip13_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP13;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP13_reg(const void *const hw, hri_nvic_nvicip13_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP13 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP13_reg(const void *const hw, hri_nvic_nvicip13_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP13 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP13_reg(const void *const hw, hri_nvic_nvicip13_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP13 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip13_reg_t hri_nvic_read_NVICIP13_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP13;
}

static inline void hri_nvic_set_NVICIP14_PRI14_bf(const void *const hw, hri_nvic_nvicip14_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP14 |= NVIC_NVICIP14_PRI14(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip14_reg_t hri_nvic_get_NVICIP14_PRI14_bf(const void *const hw, hri_nvic_nvicip14_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP14;
	tmp = (tmp & NVIC_NVICIP14_PRI14(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP14_PRI14_bf(const void *const hw, hri_nvic_nvicip14_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP14;
	tmp &= ~NVIC_NVICIP14_PRI14_Msk;
	tmp |= NVIC_NVICIP14_PRI14(data);
	((Nvic *)hw)->NVICIP14 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP14_PRI14_bf(const void *const hw, hri_nvic_nvicip14_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP14 &= ~NVIC_NVICIP14_PRI14(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP14_PRI14_bf(const void *const hw, hri_nvic_nvicip14_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP14 ^= NVIC_NVICIP14_PRI14(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip14_reg_t hri_nvic_read_NVICIP14_PRI14_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP14;
	tmp = (tmp & NVIC_NVICIP14_PRI14_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP14_reg(const void *const hw, hri_nvic_nvicip14_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP14 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip14_reg_t hri_nvic_get_NVICIP14_reg(const void *const hw, hri_nvic_nvicip14_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP14;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP14_reg(const void *const hw, hri_nvic_nvicip14_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP14 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP14_reg(const void *const hw, hri_nvic_nvicip14_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP14 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP14_reg(const void *const hw, hri_nvic_nvicip14_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP14 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip14_reg_t hri_nvic_read_NVICIP14_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP14;
}

static inline void hri_nvic_set_NVICIP15_PRI15_bf(const void *const hw, hri_nvic_nvicip15_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP15 |= NVIC_NVICIP15_PRI15(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip15_reg_t hri_nvic_get_NVICIP15_PRI15_bf(const void *const hw, hri_nvic_nvicip15_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP15;
	tmp = (tmp & NVIC_NVICIP15_PRI15(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP15_PRI15_bf(const void *const hw, hri_nvic_nvicip15_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP15;
	tmp &= ~NVIC_NVICIP15_PRI15_Msk;
	tmp |= NVIC_NVICIP15_PRI15(data);
	((Nvic *)hw)->NVICIP15 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP15_PRI15_bf(const void *const hw, hri_nvic_nvicip15_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP15 &= ~NVIC_NVICIP15_PRI15(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP15_PRI15_bf(const void *const hw, hri_nvic_nvicip15_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP15 ^= NVIC_NVICIP15_PRI15(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip15_reg_t hri_nvic_read_NVICIP15_PRI15_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP15;
	tmp = (tmp & NVIC_NVICIP15_PRI15_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP15_reg(const void *const hw, hri_nvic_nvicip15_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP15 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip15_reg_t hri_nvic_get_NVICIP15_reg(const void *const hw, hri_nvic_nvicip15_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP15;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP15_reg(const void *const hw, hri_nvic_nvicip15_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP15 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP15_reg(const void *const hw, hri_nvic_nvicip15_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP15 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP15_reg(const void *const hw, hri_nvic_nvicip15_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP15 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip15_reg_t hri_nvic_read_NVICIP15_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP15;
}

static inline void hri_nvic_set_NVICIP16_PRI16_bf(const void *const hw, hri_nvic_nvicip16_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP16 |= NVIC_NVICIP16_PRI16(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip16_reg_t hri_nvic_get_NVICIP16_PRI16_bf(const void *const hw, hri_nvic_nvicip16_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP16;
	tmp = (tmp & NVIC_NVICIP16_PRI16(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP16_PRI16_bf(const void *const hw, hri_nvic_nvicip16_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP16;
	tmp &= ~NVIC_NVICIP16_PRI16_Msk;
	tmp |= NVIC_NVICIP16_PRI16(data);
	((Nvic *)hw)->NVICIP16 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP16_PRI16_bf(const void *const hw, hri_nvic_nvicip16_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP16 &= ~NVIC_NVICIP16_PRI16(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP16_PRI16_bf(const void *const hw, hri_nvic_nvicip16_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP16 ^= NVIC_NVICIP16_PRI16(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip16_reg_t hri_nvic_read_NVICIP16_PRI16_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP16;
	tmp = (tmp & NVIC_NVICIP16_PRI16_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP16_reg(const void *const hw, hri_nvic_nvicip16_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP16 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip16_reg_t hri_nvic_get_NVICIP16_reg(const void *const hw, hri_nvic_nvicip16_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP16;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP16_reg(const void *const hw, hri_nvic_nvicip16_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP16 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP16_reg(const void *const hw, hri_nvic_nvicip16_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP16 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP16_reg(const void *const hw, hri_nvic_nvicip16_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP16 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip16_reg_t hri_nvic_read_NVICIP16_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP16;
}

static inline void hri_nvic_set_NVICIP17_PRI17_bf(const void *const hw, hri_nvic_nvicip17_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP17 |= NVIC_NVICIP17_PRI17(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip17_reg_t hri_nvic_get_NVICIP17_PRI17_bf(const void *const hw, hri_nvic_nvicip17_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP17;
	tmp = (tmp & NVIC_NVICIP17_PRI17(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP17_PRI17_bf(const void *const hw, hri_nvic_nvicip17_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP17;
	tmp &= ~NVIC_NVICIP17_PRI17_Msk;
	tmp |= NVIC_NVICIP17_PRI17(data);
	((Nvic *)hw)->NVICIP17 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP17_PRI17_bf(const void *const hw, hri_nvic_nvicip17_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP17 &= ~NVIC_NVICIP17_PRI17(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP17_PRI17_bf(const void *const hw, hri_nvic_nvicip17_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP17 ^= NVIC_NVICIP17_PRI17(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip17_reg_t hri_nvic_read_NVICIP17_PRI17_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP17;
	tmp = (tmp & NVIC_NVICIP17_PRI17_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP17_reg(const void *const hw, hri_nvic_nvicip17_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP17 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip17_reg_t hri_nvic_get_NVICIP17_reg(const void *const hw, hri_nvic_nvicip17_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP17;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP17_reg(const void *const hw, hri_nvic_nvicip17_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP17 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP17_reg(const void *const hw, hri_nvic_nvicip17_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP17 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP17_reg(const void *const hw, hri_nvic_nvicip17_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP17 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip17_reg_t hri_nvic_read_NVICIP17_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP17;
}

static inline void hri_nvic_set_NVICIP18_PRI18_bf(const void *const hw, hri_nvic_nvicip18_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP18 |= NVIC_NVICIP18_PRI18(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip18_reg_t hri_nvic_get_NVICIP18_PRI18_bf(const void *const hw, hri_nvic_nvicip18_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP18;
	tmp = (tmp & NVIC_NVICIP18_PRI18(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP18_PRI18_bf(const void *const hw, hri_nvic_nvicip18_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP18;
	tmp &= ~NVIC_NVICIP18_PRI18_Msk;
	tmp |= NVIC_NVICIP18_PRI18(data);
	((Nvic *)hw)->NVICIP18 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP18_PRI18_bf(const void *const hw, hri_nvic_nvicip18_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP18 &= ~NVIC_NVICIP18_PRI18(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP18_PRI18_bf(const void *const hw, hri_nvic_nvicip18_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP18 ^= NVIC_NVICIP18_PRI18(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip18_reg_t hri_nvic_read_NVICIP18_PRI18_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP18;
	tmp = (tmp & NVIC_NVICIP18_PRI18_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP18_reg(const void *const hw, hri_nvic_nvicip18_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP18 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip18_reg_t hri_nvic_get_NVICIP18_reg(const void *const hw, hri_nvic_nvicip18_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP18;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP18_reg(const void *const hw, hri_nvic_nvicip18_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP18 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP18_reg(const void *const hw, hri_nvic_nvicip18_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP18 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP18_reg(const void *const hw, hri_nvic_nvicip18_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP18 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip18_reg_t hri_nvic_read_NVICIP18_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP18;
}

static inline void hri_nvic_set_NVICIP19_PRI19_bf(const void *const hw, hri_nvic_nvicip19_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP19 |= NVIC_NVICIP19_PRI19(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip19_reg_t hri_nvic_get_NVICIP19_PRI19_bf(const void *const hw, hri_nvic_nvicip19_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP19;
	tmp = (tmp & NVIC_NVICIP19_PRI19(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP19_PRI19_bf(const void *const hw, hri_nvic_nvicip19_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP19;
	tmp &= ~NVIC_NVICIP19_PRI19_Msk;
	tmp |= NVIC_NVICIP19_PRI19(data);
	((Nvic *)hw)->NVICIP19 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP19_PRI19_bf(const void *const hw, hri_nvic_nvicip19_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP19 &= ~NVIC_NVICIP19_PRI19(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP19_PRI19_bf(const void *const hw, hri_nvic_nvicip19_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP19 ^= NVIC_NVICIP19_PRI19(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip19_reg_t hri_nvic_read_NVICIP19_PRI19_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP19;
	tmp = (tmp & NVIC_NVICIP19_PRI19_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP19_reg(const void *const hw, hri_nvic_nvicip19_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP19 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip19_reg_t hri_nvic_get_NVICIP19_reg(const void *const hw, hri_nvic_nvicip19_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP19;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP19_reg(const void *const hw, hri_nvic_nvicip19_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP19 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP19_reg(const void *const hw, hri_nvic_nvicip19_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP19 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP19_reg(const void *const hw, hri_nvic_nvicip19_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP19 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip19_reg_t hri_nvic_read_NVICIP19_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP19;
}

static inline void hri_nvic_set_NVICIP20_PRI20_bf(const void *const hw, hri_nvic_nvicip20_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP20 |= NVIC_NVICIP20_PRI20(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip20_reg_t hri_nvic_get_NVICIP20_PRI20_bf(const void *const hw, hri_nvic_nvicip20_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP20;
	tmp = (tmp & NVIC_NVICIP20_PRI20(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP20_PRI20_bf(const void *const hw, hri_nvic_nvicip20_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP20;
	tmp &= ~NVIC_NVICIP20_PRI20_Msk;
	tmp |= NVIC_NVICIP20_PRI20(data);
	((Nvic *)hw)->NVICIP20 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP20_PRI20_bf(const void *const hw, hri_nvic_nvicip20_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP20 &= ~NVIC_NVICIP20_PRI20(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP20_PRI20_bf(const void *const hw, hri_nvic_nvicip20_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP20 ^= NVIC_NVICIP20_PRI20(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip20_reg_t hri_nvic_read_NVICIP20_PRI20_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP20;
	tmp = (tmp & NVIC_NVICIP20_PRI20_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP20_reg(const void *const hw, hri_nvic_nvicip20_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP20 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip20_reg_t hri_nvic_get_NVICIP20_reg(const void *const hw, hri_nvic_nvicip20_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP20;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP20_reg(const void *const hw, hri_nvic_nvicip20_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP20 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP20_reg(const void *const hw, hri_nvic_nvicip20_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP20 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP20_reg(const void *const hw, hri_nvic_nvicip20_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP20 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip20_reg_t hri_nvic_read_NVICIP20_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP20;
}

static inline void hri_nvic_set_NVICIP21_PRI21_bf(const void *const hw, hri_nvic_nvicip21_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP21 |= NVIC_NVICIP21_PRI21(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip21_reg_t hri_nvic_get_NVICIP21_PRI21_bf(const void *const hw, hri_nvic_nvicip21_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP21;
	tmp = (tmp & NVIC_NVICIP21_PRI21(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP21_PRI21_bf(const void *const hw, hri_nvic_nvicip21_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP21;
	tmp &= ~NVIC_NVICIP21_PRI21_Msk;
	tmp |= NVIC_NVICIP21_PRI21(data);
	((Nvic *)hw)->NVICIP21 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP21_PRI21_bf(const void *const hw, hri_nvic_nvicip21_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP21 &= ~NVIC_NVICIP21_PRI21(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP21_PRI21_bf(const void *const hw, hri_nvic_nvicip21_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP21 ^= NVIC_NVICIP21_PRI21(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip21_reg_t hri_nvic_read_NVICIP21_PRI21_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP21;
	tmp = (tmp & NVIC_NVICIP21_PRI21_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP21_reg(const void *const hw, hri_nvic_nvicip21_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP21 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip21_reg_t hri_nvic_get_NVICIP21_reg(const void *const hw, hri_nvic_nvicip21_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP21;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP21_reg(const void *const hw, hri_nvic_nvicip21_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP21 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP21_reg(const void *const hw, hri_nvic_nvicip21_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP21 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP21_reg(const void *const hw, hri_nvic_nvicip21_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP21 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip21_reg_t hri_nvic_read_NVICIP21_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP21;
}

static inline void hri_nvic_set_NVICIP22_PRI22_bf(const void *const hw, hri_nvic_nvicip22_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP22 |= NVIC_NVICIP22_PRI22(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip22_reg_t hri_nvic_get_NVICIP22_PRI22_bf(const void *const hw, hri_nvic_nvicip22_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP22;
	tmp = (tmp & NVIC_NVICIP22_PRI22(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP22_PRI22_bf(const void *const hw, hri_nvic_nvicip22_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP22;
	tmp &= ~NVIC_NVICIP22_PRI22_Msk;
	tmp |= NVIC_NVICIP22_PRI22(data);
	((Nvic *)hw)->NVICIP22 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP22_PRI22_bf(const void *const hw, hri_nvic_nvicip22_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP22 &= ~NVIC_NVICIP22_PRI22(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP22_PRI22_bf(const void *const hw, hri_nvic_nvicip22_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP22 ^= NVIC_NVICIP22_PRI22(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip22_reg_t hri_nvic_read_NVICIP22_PRI22_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP22;
	tmp = (tmp & NVIC_NVICIP22_PRI22_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP22_reg(const void *const hw, hri_nvic_nvicip22_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP22 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip22_reg_t hri_nvic_get_NVICIP22_reg(const void *const hw, hri_nvic_nvicip22_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP22;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP22_reg(const void *const hw, hri_nvic_nvicip22_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP22 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP22_reg(const void *const hw, hri_nvic_nvicip22_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP22 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP22_reg(const void *const hw, hri_nvic_nvicip22_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP22 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip22_reg_t hri_nvic_read_NVICIP22_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP22;
}

static inline void hri_nvic_set_NVICIP23_PRI23_bf(const void *const hw, hri_nvic_nvicip23_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP23 |= NVIC_NVICIP23_PRI23(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip23_reg_t hri_nvic_get_NVICIP23_PRI23_bf(const void *const hw, hri_nvic_nvicip23_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP23;
	tmp = (tmp & NVIC_NVICIP23_PRI23(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP23_PRI23_bf(const void *const hw, hri_nvic_nvicip23_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP23;
	tmp &= ~NVIC_NVICIP23_PRI23_Msk;
	tmp |= NVIC_NVICIP23_PRI23(data);
	((Nvic *)hw)->NVICIP23 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP23_PRI23_bf(const void *const hw, hri_nvic_nvicip23_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP23 &= ~NVIC_NVICIP23_PRI23(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP23_PRI23_bf(const void *const hw, hri_nvic_nvicip23_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP23 ^= NVIC_NVICIP23_PRI23(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip23_reg_t hri_nvic_read_NVICIP23_PRI23_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP23;
	tmp = (tmp & NVIC_NVICIP23_PRI23_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP23_reg(const void *const hw, hri_nvic_nvicip23_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP23 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip23_reg_t hri_nvic_get_NVICIP23_reg(const void *const hw, hri_nvic_nvicip23_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP23;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP23_reg(const void *const hw, hri_nvic_nvicip23_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP23 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP23_reg(const void *const hw, hri_nvic_nvicip23_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP23 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP23_reg(const void *const hw, hri_nvic_nvicip23_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP23 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip23_reg_t hri_nvic_read_NVICIP23_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP23;
}

static inline void hri_nvic_set_NVICIP24_PRI24_bf(const void *const hw, hri_nvic_nvicip24_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP24 |= NVIC_NVICIP24_PRI24(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip24_reg_t hri_nvic_get_NVICIP24_PRI24_bf(const void *const hw, hri_nvic_nvicip24_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP24;
	tmp = (tmp & NVIC_NVICIP24_PRI24(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP24_PRI24_bf(const void *const hw, hri_nvic_nvicip24_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP24;
	tmp &= ~NVIC_NVICIP24_PRI24_Msk;
	tmp |= NVIC_NVICIP24_PRI24(data);
	((Nvic *)hw)->NVICIP24 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP24_PRI24_bf(const void *const hw, hri_nvic_nvicip24_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP24 &= ~NVIC_NVICIP24_PRI24(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP24_PRI24_bf(const void *const hw, hri_nvic_nvicip24_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP24 ^= NVIC_NVICIP24_PRI24(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip24_reg_t hri_nvic_read_NVICIP24_PRI24_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP24;
	tmp = (tmp & NVIC_NVICIP24_PRI24_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP24_reg(const void *const hw, hri_nvic_nvicip24_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP24 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip24_reg_t hri_nvic_get_NVICIP24_reg(const void *const hw, hri_nvic_nvicip24_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP24;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP24_reg(const void *const hw, hri_nvic_nvicip24_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP24 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP24_reg(const void *const hw, hri_nvic_nvicip24_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP24 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP24_reg(const void *const hw, hri_nvic_nvicip24_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP24 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip24_reg_t hri_nvic_read_NVICIP24_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP24;
}

static inline void hri_nvic_set_NVICIP25_PRI25_bf(const void *const hw, hri_nvic_nvicip25_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP25 |= NVIC_NVICIP25_PRI25(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip25_reg_t hri_nvic_get_NVICIP25_PRI25_bf(const void *const hw, hri_nvic_nvicip25_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP25;
	tmp = (tmp & NVIC_NVICIP25_PRI25(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP25_PRI25_bf(const void *const hw, hri_nvic_nvicip25_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP25;
	tmp &= ~NVIC_NVICIP25_PRI25_Msk;
	tmp |= NVIC_NVICIP25_PRI25(data);
	((Nvic *)hw)->NVICIP25 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP25_PRI25_bf(const void *const hw, hri_nvic_nvicip25_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP25 &= ~NVIC_NVICIP25_PRI25(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP25_PRI25_bf(const void *const hw, hri_nvic_nvicip25_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP25 ^= NVIC_NVICIP25_PRI25(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip25_reg_t hri_nvic_read_NVICIP25_PRI25_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP25;
	tmp = (tmp & NVIC_NVICIP25_PRI25_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP25_reg(const void *const hw, hri_nvic_nvicip25_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP25 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip25_reg_t hri_nvic_get_NVICIP25_reg(const void *const hw, hri_nvic_nvicip25_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP25;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP25_reg(const void *const hw, hri_nvic_nvicip25_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP25 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP25_reg(const void *const hw, hri_nvic_nvicip25_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP25 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP25_reg(const void *const hw, hri_nvic_nvicip25_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP25 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip25_reg_t hri_nvic_read_NVICIP25_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP25;
}

static inline void hri_nvic_set_NVICIP26_PRI26_bf(const void *const hw, hri_nvic_nvicip26_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP26 |= NVIC_NVICIP26_PRI26(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip26_reg_t hri_nvic_get_NVICIP26_PRI26_bf(const void *const hw, hri_nvic_nvicip26_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP26;
	tmp = (tmp & NVIC_NVICIP26_PRI26(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP26_PRI26_bf(const void *const hw, hri_nvic_nvicip26_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP26;
	tmp &= ~NVIC_NVICIP26_PRI26_Msk;
	tmp |= NVIC_NVICIP26_PRI26(data);
	((Nvic *)hw)->NVICIP26 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP26_PRI26_bf(const void *const hw, hri_nvic_nvicip26_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP26 &= ~NVIC_NVICIP26_PRI26(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP26_PRI26_bf(const void *const hw, hri_nvic_nvicip26_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP26 ^= NVIC_NVICIP26_PRI26(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip26_reg_t hri_nvic_read_NVICIP26_PRI26_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP26;
	tmp = (tmp & NVIC_NVICIP26_PRI26_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP26_reg(const void *const hw, hri_nvic_nvicip26_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP26 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip26_reg_t hri_nvic_get_NVICIP26_reg(const void *const hw, hri_nvic_nvicip26_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP26;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP26_reg(const void *const hw, hri_nvic_nvicip26_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP26 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP26_reg(const void *const hw, hri_nvic_nvicip26_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP26 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP26_reg(const void *const hw, hri_nvic_nvicip26_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP26 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip26_reg_t hri_nvic_read_NVICIP26_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP26;
}

static inline void hri_nvic_set_NVICIP27_PRI27_bf(const void *const hw, hri_nvic_nvicip27_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP27 |= NVIC_NVICIP27_PRI27(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip27_reg_t hri_nvic_get_NVICIP27_PRI27_bf(const void *const hw, hri_nvic_nvicip27_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP27;
	tmp = (tmp & NVIC_NVICIP27_PRI27(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP27_PRI27_bf(const void *const hw, hri_nvic_nvicip27_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP27;
	tmp &= ~NVIC_NVICIP27_PRI27_Msk;
	tmp |= NVIC_NVICIP27_PRI27(data);
	((Nvic *)hw)->NVICIP27 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP27_PRI27_bf(const void *const hw, hri_nvic_nvicip27_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP27 &= ~NVIC_NVICIP27_PRI27(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP27_PRI27_bf(const void *const hw, hri_nvic_nvicip27_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP27 ^= NVIC_NVICIP27_PRI27(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip27_reg_t hri_nvic_read_NVICIP27_PRI27_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP27;
	tmp = (tmp & NVIC_NVICIP27_PRI27_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP27_reg(const void *const hw, hri_nvic_nvicip27_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP27 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip27_reg_t hri_nvic_get_NVICIP27_reg(const void *const hw, hri_nvic_nvicip27_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP27;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP27_reg(const void *const hw, hri_nvic_nvicip27_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP27 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP27_reg(const void *const hw, hri_nvic_nvicip27_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP27 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP27_reg(const void *const hw, hri_nvic_nvicip27_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP27 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip27_reg_t hri_nvic_read_NVICIP27_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP27;
}

static inline void hri_nvic_set_NVICIP28_PRI28_bf(const void *const hw, hri_nvic_nvicip28_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP28 |= NVIC_NVICIP28_PRI28(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip28_reg_t hri_nvic_get_NVICIP28_PRI28_bf(const void *const hw, hri_nvic_nvicip28_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP28;
	tmp = (tmp & NVIC_NVICIP28_PRI28(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP28_PRI28_bf(const void *const hw, hri_nvic_nvicip28_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP28;
	tmp &= ~NVIC_NVICIP28_PRI28_Msk;
	tmp |= NVIC_NVICIP28_PRI28(data);
	((Nvic *)hw)->NVICIP28 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP28_PRI28_bf(const void *const hw, hri_nvic_nvicip28_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP28 &= ~NVIC_NVICIP28_PRI28(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP28_PRI28_bf(const void *const hw, hri_nvic_nvicip28_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP28 ^= NVIC_NVICIP28_PRI28(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip28_reg_t hri_nvic_read_NVICIP28_PRI28_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP28;
	tmp = (tmp & NVIC_NVICIP28_PRI28_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP28_reg(const void *const hw, hri_nvic_nvicip28_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP28 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip28_reg_t hri_nvic_get_NVICIP28_reg(const void *const hw, hri_nvic_nvicip28_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP28;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP28_reg(const void *const hw, hri_nvic_nvicip28_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP28 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP28_reg(const void *const hw, hri_nvic_nvicip28_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP28 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP28_reg(const void *const hw, hri_nvic_nvicip28_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP28 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip28_reg_t hri_nvic_read_NVICIP28_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP28;
}

static inline void hri_nvic_set_NVICIP29_PRI29_bf(const void *const hw, hri_nvic_nvicip29_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP29 |= NVIC_NVICIP29_PRI29(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip29_reg_t hri_nvic_get_NVICIP29_PRI29_bf(const void *const hw, hri_nvic_nvicip29_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP29;
	tmp = (tmp & NVIC_NVICIP29_PRI29(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP29_PRI29_bf(const void *const hw, hri_nvic_nvicip29_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP29;
	tmp &= ~NVIC_NVICIP29_PRI29_Msk;
	tmp |= NVIC_NVICIP29_PRI29(data);
	((Nvic *)hw)->NVICIP29 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP29_PRI29_bf(const void *const hw, hri_nvic_nvicip29_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP29 &= ~NVIC_NVICIP29_PRI29(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP29_PRI29_bf(const void *const hw, hri_nvic_nvicip29_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP29 ^= NVIC_NVICIP29_PRI29(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip29_reg_t hri_nvic_read_NVICIP29_PRI29_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP29;
	tmp = (tmp & NVIC_NVICIP29_PRI29_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP29_reg(const void *const hw, hri_nvic_nvicip29_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP29 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip29_reg_t hri_nvic_get_NVICIP29_reg(const void *const hw, hri_nvic_nvicip29_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP29;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP29_reg(const void *const hw, hri_nvic_nvicip29_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP29 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP29_reg(const void *const hw, hri_nvic_nvicip29_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP29 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP29_reg(const void *const hw, hri_nvic_nvicip29_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP29 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip29_reg_t hri_nvic_read_NVICIP29_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP29;
}

static inline void hri_nvic_set_NVICIP30_PRI30_bf(const void *const hw, hri_nvic_nvicip30_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP30 |= NVIC_NVICIP30_PRI30(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip30_reg_t hri_nvic_get_NVICIP30_PRI30_bf(const void *const hw, hri_nvic_nvicip30_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP30;
	tmp = (tmp & NVIC_NVICIP30_PRI30(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP30_PRI30_bf(const void *const hw, hri_nvic_nvicip30_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP30;
	tmp &= ~NVIC_NVICIP30_PRI30_Msk;
	tmp |= NVIC_NVICIP30_PRI30(data);
	((Nvic *)hw)->NVICIP30 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP30_PRI30_bf(const void *const hw, hri_nvic_nvicip30_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP30 &= ~NVIC_NVICIP30_PRI30(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP30_PRI30_bf(const void *const hw, hri_nvic_nvicip30_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP30 ^= NVIC_NVICIP30_PRI30(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip30_reg_t hri_nvic_read_NVICIP30_PRI30_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP30;
	tmp = (tmp & NVIC_NVICIP30_PRI30_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP30_reg(const void *const hw, hri_nvic_nvicip30_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP30 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip30_reg_t hri_nvic_get_NVICIP30_reg(const void *const hw, hri_nvic_nvicip30_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP30;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP30_reg(const void *const hw, hri_nvic_nvicip30_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP30 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP30_reg(const void *const hw, hri_nvic_nvicip30_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP30 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP30_reg(const void *const hw, hri_nvic_nvicip30_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP30 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip30_reg_t hri_nvic_read_NVICIP30_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP30;
}

static inline void hri_nvic_set_NVICIP31_PRI31_bf(const void *const hw, hri_nvic_nvicip31_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP31 |= NVIC_NVICIP31_PRI31(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip31_reg_t hri_nvic_get_NVICIP31_PRI31_bf(const void *const hw, hri_nvic_nvicip31_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP31;
	tmp = (tmp & NVIC_NVICIP31_PRI31(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP31_PRI31_bf(const void *const hw, hri_nvic_nvicip31_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP31;
	tmp &= ~NVIC_NVICIP31_PRI31_Msk;
	tmp |= NVIC_NVICIP31_PRI31(data);
	((Nvic *)hw)->NVICIP31 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP31_PRI31_bf(const void *const hw, hri_nvic_nvicip31_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP31 &= ~NVIC_NVICIP31_PRI31(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP31_PRI31_bf(const void *const hw, hri_nvic_nvicip31_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP31 ^= NVIC_NVICIP31_PRI31(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip31_reg_t hri_nvic_read_NVICIP31_PRI31_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP31;
	tmp = (tmp & NVIC_NVICIP31_PRI31_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP31_reg(const void *const hw, hri_nvic_nvicip31_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP31 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip31_reg_t hri_nvic_get_NVICIP31_reg(const void *const hw, hri_nvic_nvicip31_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP31;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP31_reg(const void *const hw, hri_nvic_nvicip31_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP31 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP31_reg(const void *const hw, hri_nvic_nvicip31_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP31 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP31_reg(const void *const hw, hri_nvic_nvicip31_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP31 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip31_reg_t hri_nvic_read_NVICIP31_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP31;
}

static inline void hri_nvic_set_NVICIP32_PRI32_bf(const void *const hw, hri_nvic_nvicip32_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP32 |= NVIC_NVICIP32_PRI32(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip32_reg_t hri_nvic_get_NVICIP32_PRI32_bf(const void *const hw, hri_nvic_nvicip32_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP32;
	tmp = (tmp & NVIC_NVICIP32_PRI32(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP32_PRI32_bf(const void *const hw, hri_nvic_nvicip32_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP32;
	tmp &= ~NVIC_NVICIP32_PRI32_Msk;
	tmp |= NVIC_NVICIP32_PRI32(data);
	((Nvic *)hw)->NVICIP32 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP32_PRI32_bf(const void *const hw, hri_nvic_nvicip32_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP32 &= ~NVIC_NVICIP32_PRI32(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP32_PRI32_bf(const void *const hw, hri_nvic_nvicip32_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP32 ^= NVIC_NVICIP32_PRI32(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip32_reg_t hri_nvic_read_NVICIP32_PRI32_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP32;
	tmp = (tmp & NVIC_NVICIP32_PRI32_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP32_reg(const void *const hw, hri_nvic_nvicip32_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP32 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip32_reg_t hri_nvic_get_NVICIP32_reg(const void *const hw, hri_nvic_nvicip32_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP32;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP32_reg(const void *const hw, hri_nvic_nvicip32_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP32 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP32_reg(const void *const hw, hri_nvic_nvicip32_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP32 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP32_reg(const void *const hw, hri_nvic_nvicip32_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP32 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip32_reg_t hri_nvic_read_NVICIP32_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP32;
}

static inline void hri_nvic_set_NVICIP33_PRI33_bf(const void *const hw, hri_nvic_nvicip33_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP33 |= NVIC_NVICIP33_PRI33(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip33_reg_t hri_nvic_get_NVICIP33_PRI33_bf(const void *const hw, hri_nvic_nvicip33_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP33;
	tmp = (tmp & NVIC_NVICIP33_PRI33(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP33_PRI33_bf(const void *const hw, hri_nvic_nvicip33_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP33;
	tmp &= ~NVIC_NVICIP33_PRI33_Msk;
	tmp |= NVIC_NVICIP33_PRI33(data);
	((Nvic *)hw)->NVICIP33 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP33_PRI33_bf(const void *const hw, hri_nvic_nvicip33_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP33 &= ~NVIC_NVICIP33_PRI33(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP33_PRI33_bf(const void *const hw, hri_nvic_nvicip33_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP33 ^= NVIC_NVICIP33_PRI33(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip33_reg_t hri_nvic_read_NVICIP33_PRI33_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP33;
	tmp = (tmp & NVIC_NVICIP33_PRI33_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP33_reg(const void *const hw, hri_nvic_nvicip33_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP33 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip33_reg_t hri_nvic_get_NVICIP33_reg(const void *const hw, hri_nvic_nvicip33_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP33;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP33_reg(const void *const hw, hri_nvic_nvicip33_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP33 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP33_reg(const void *const hw, hri_nvic_nvicip33_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP33 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP33_reg(const void *const hw, hri_nvic_nvicip33_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP33 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip33_reg_t hri_nvic_read_NVICIP33_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP33;
}

static inline void hri_nvic_set_NVICIP34_PRI34_bf(const void *const hw, hri_nvic_nvicip34_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP34 |= NVIC_NVICIP34_PRI34(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip34_reg_t hri_nvic_get_NVICIP34_PRI34_bf(const void *const hw, hri_nvic_nvicip34_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP34;
	tmp = (tmp & NVIC_NVICIP34_PRI34(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP34_PRI34_bf(const void *const hw, hri_nvic_nvicip34_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP34;
	tmp &= ~NVIC_NVICIP34_PRI34_Msk;
	tmp |= NVIC_NVICIP34_PRI34(data);
	((Nvic *)hw)->NVICIP34 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP34_PRI34_bf(const void *const hw, hri_nvic_nvicip34_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP34 &= ~NVIC_NVICIP34_PRI34(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP34_PRI34_bf(const void *const hw, hri_nvic_nvicip34_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP34 ^= NVIC_NVICIP34_PRI34(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip34_reg_t hri_nvic_read_NVICIP34_PRI34_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP34;
	tmp = (tmp & NVIC_NVICIP34_PRI34_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP34_reg(const void *const hw, hri_nvic_nvicip34_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP34 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip34_reg_t hri_nvic_get_NVICIP34_reg(const void *const hw, hri_nvic_nvicip34_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP34;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP34_reg(const void *const hw, hri_nvic_nvicip34_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP34 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP34_reg(const void *const hw, hri_nvic_nvicip34_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP34 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP34_reg(const void *const hw, hri_nvic_nvicip34_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP34 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip34_reg_t hri_nvic_read_NVICIP34_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP34;
}

static inline void hri_nvic_set_NVICIP35_PRI35_bf(const void *const hw, hri_nvic_nvicip35_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP35 |= NVIC_NVICIP35_PRI35(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip35_reg_t hri_nvic_get_NVICIP35_PRI35_bf(const void *const hw, hri_nvic_nvicip35_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP35;
	tmp = (tmp & NVIC_NVICIP35_PRI35(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP35_PRI35_bf(const void *const hw, hri_nvic_nvicip35_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP35;
	tmp &= ~NVIC_NVICIP35_PRI35_Msk;
	tmp |= NVIC_NVICIP35_PRI35(data);
	((Nvic *)hw)->NVICIP35 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP35_PRI35_bf(const void *const hw, hri_nvic_nvicip35_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP35 &= ~NVIC_NVICIP35_PRI35(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP35_PRI35_bf(const void *const hw, hri_nvic_nvicip35_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP35 ^= NVIC_NVICIP35_PRI35(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip35_reg_t hri_nvic_read_NVICIP35_PRI35_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP35;
	tmp = (tmp & NVIC_NVICIP35_PRI35_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP35_reg(const void *const hw, hri_nvic_nvicip35_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP35 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip35_reg_t hri_nvic_get_NVICIP35_reg(const void *const hw, hri_nvic_nvicip35_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP35;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP35_reg(const void *const hw, hri_nvic_nvicip35_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP35 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP35_reg(const void *const hw, hri_nvic_nvicip35_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP35 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP35_reg(const void *const hw, hri_nvic_nvicip35_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP35 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip35_reg_t hri_nvic_read_NVICIP35_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP35;
}

static inline void hri_nvic_set_NVICIP36_PRI36_bf(const void *const hw, hri_nvic_nvicip36_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP36 |= NVIC_NVICIP36_PRI36(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip36_reg_t hri_nvic_get_NVICIP36_PRI36_bf(const void *const hw, hri_nvic_nvicip36_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP36;
	tmp = (tmp & NVIC_NVICIP36_PRI36(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP36_PRI36_bf(const void *const hw, hri_nvic_nvicip36_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP36;
	tmp &= ~NVIC_NVICIP36_PRI36_Msk;
	tmp |= NVIC_NVICIP36_PRI36(data);
	((Nvic *)hw)->NVICIP36 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP36_PRI36_bf(const void *const hw, hri_nvic_nvicip36_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP36 &= ~NVIC_NVICIP36_PRI36(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP36_PRI36_bf(const void *const hw, hri_nvic_nvicip36_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP36 ^= NVIC_NVICIP36_PRI36(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip36_reg_t hri_nvic_read_NVICIP36_PRI36_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP36;
	tmp = (tmp & NVIC_NVICIP36_PRI36_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP36_reg(const void *const hw, hri_nvic_nvicip36_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP36 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip36_reg_t hri_nvic_get_NVICIP36_reg(const void *const hw, hri_nvic_nvicip36_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP36;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP36_reg(const void *const hw, hri_nvic_nvicip36_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP36 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP36_reg(const void *const hw, hri_nvic_nvicip36_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP36 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP36_reg(const void *const hw, hri_nvic_nvicip36_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP36 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip36_reg_t hri_nvic_read_NVICIP36_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP36;
}

static inline void hri_nvic_set_NVICIP37_PRI37_bf(const void *const hw, hri_nvic_nvicip37_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP37 |= NVIC_NVICIP37_PRI37(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip37_reg_t hri_nvic_get_NVICIP37_PRI37_bf(const void *const hw, hri_nvic_nvicip37_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP37;
	tmp = (tmp & NVIC_NVICIP37_PRI37(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP37_PRI37_bf(const void *const hw, hri_nvic_nvicip37_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP37;
	tmp &= ~NVIC_NVICIP37_PRI37_Msk;
	tmp |= NVIC_NVICIP37_PRI37(data);
	((Nvic *)hw)->NVICIP37 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP37_PRI37_bf(const void *const hw, hri_nvic_nvicip37_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP37 &= ~NVIC_NVICIP37_PRI37(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP37_PRI37_bf(const void *const hw, hri_nvic_nvicip37_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP37 ^= NVIC_NVICIP37_PRI37(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip37_reg_t hri_nvic_read_NVICIP37_PRI37_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP37;
	tmp = (tmp & NVIC_NVICIP37_PRI37_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP37_reg(const void *const hw, hri_nvic_nvicip37_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP37 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip37_reg_t hri_nvic_get_NVICIP37_reg(const void *const hw, hri_nvic_nvicip37_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP37;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP37_reg(const void *const hw, hri_nvic_nvicip37_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP37 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP37_reg(const void *const hw, hri_nvic_nvicip37_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP37 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP37_reg(const void *const hw, hri_nvic_nvicip37_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP37 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip37_reg_t hri_nvic_read_NVICIP37_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP37;
}

static inline void hri_nvic_set_NVICIP38_PRI38_bf(const void *const hw, hri_nvic_nvicip38_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP38 |= NVIC_NVICIP38_PRI38(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip38_reg_t hri_nvic_get_NVICIP38_PRI38_bf(const void *const hw, hri_nvic_nvicip38_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP38;
	tmp = (tmp & NVIC_NVICIP38_PRI38(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP38_PRI38_bf(const void *const hw, hri_nvic_nvicip38_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP38;
	tmp &= ~NVIC_NVICIP38_PRI38_Msk;
	tmp |= NVIC_NVICIP38_PRI38(data);
	((Nvic *)hw)->NVICIP38 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP38_PRI38_bf(const void *const hw, hri_nvic_nvicip38_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP38 &= ~NVIC_NVICIP38_PRI38(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP38_PRI38_bf(const void *const hw, hri_nvic_nvicip38_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP38 ^= NVIC_NVICIP38_PRI38(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip38_reg_t hri_nvic_read_NVICIP38_PRI38_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP38;
	tmp = (tmp & NVIC_NVICIP38_PRI38_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP38_reg(const void *const hw, hri_nvic_nvicip38_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP38 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip38_reg_t hri_nvic_get_NVICIP38_reg(const void *const hw, hri_nvic_nvicip38_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP38;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP38_reg(const void *const hw, hri_nvic_nvicip38_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP38 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP38_reg(const void *const hw, hri_nvic_nvicip38_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP38 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP38_reg(const void *const hw, hri_nvic_nvicip38_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP38 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip38_reg_t hri_nvic_read_NVICIP38_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP38;
}

static inline void hri_nvic_set_NVICIP39_PRI39_bf(const void *const hw, hri_nvic_nvicip39_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP39 |= NVIC_NVICIP39_PRI39(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip39_reg_t hri_nvic_get_NVICIP39_PRI39_bf(const void *const hw, hri_nvic_nvicip39_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP39;
	tmp = (tmp & NVIC_NVICIP39_PRI39(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP39_PRI39_bf(const void *const hw, hri_nvic_nvicip39_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP39;
	tmp &= ~NVIC_NVICIP39_PRI39_Msk;
	tmp |= NVIC_NVICIP39_PRI39(data);
	((Nvic *)hw)->NVICIP39 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP39_PRI39_bf(const void *const hw, hri_nvic_nvicip39_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP39 &= ~NVIC_NVICIP39_PRI39(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP39_PRI39_bf(const void *const hw, hri_nvic_nvicip39_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP39 ^= NVIC_NVICIP39_PRI39(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip39_reg_t hri_nvic_read_NVICIP39_PRI39_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP39;
	tmp = (tmp & NVIC_NVICIP39_PRI39_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP39_reg(const void *const hw, hri_nvic_nvicip39_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP39 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip39_reg_t hri_nvic_get_NVICIP39_reg(const void *const hw, hri_nvic_nvicip39_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP39;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP39_reg(const void *const hw, hri_nvic_nvicip39_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP39 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP39_reg(const void *const hw, hri_nvic_nvicip39_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP39 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP39_reg(const void *const hw, hri_nvic_nvicip39_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP39 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip39_reg_t hri_nvic_read_NVICIP39_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP39;
}

static inline void hri_nvic_set_NVICIP40_PRI40_bf(const void *const hw, hri_nvic_nvicip40_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP40 |= NVIC_NVICIP40_PRI40(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip40_reg_t hri_nvic_get_NVICIP40_PRI40_bf(const void *const hw, hri_nvic_nvicip40_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP40;
	tmp = (tmp & NVIC_NVICIP40_PRI40(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP40_PRI40_bf(const void *const hw, hri_nvic_nvicip40_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP40;
	tmp &= ~NVIC_NVICIP40_PRI40_Msk;
	tmp |= NVIC_NVICIP40_PRI40(data);
	((Nvic *)hw)->NVICIP40 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP40_PRI40_bf(const void *const hw, hri_nvic_nvicip40_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP40 &= ~NVIC_NVICIP40_PRI40(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP40_PRI40_bf(const void *const hw, hri_nvic_nvicip40_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP40 ^= NVIC_NVICIP40_PRI40(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip40_reg_t hri_nvic_read_NVICIP40_PRI40_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP40;
	tmp = (tmp & NVIC_NVICIP40_PRI40_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP40_reg(const void *const hw, hri_nvic_nvicip40_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP40 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip40_reg_t hri_nvic_get_NVICIP40_reg(const void *const hw, hri_nvic_nvicip40_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP40;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP40_reg(const void *const hw, hri_nvic_nvicip40_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP40 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP40_reg(const void *const hw, hri_nvic_nvicip40_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP40 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP40_reg(const void *const hw, hri_nvic_nvicip40_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP40 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip40_reg_t hri_nvic_read_NVICIP40_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP40;
}

static inline void hri_nvic_set_NVICIP41_PRI41_bf(const void *const hw, hri_nvic_nvicip41_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP41 |= NVIC_NVICIP41_PRI41(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip41_reg_t hri_nvic_get_NVICIP41_PRI41_bf(const void *const hw, hri_nvic_nvicip41_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP41;
	tmp = (tmp & NVIC_NVICIP41_PRI41(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP41_PRI41_bf(const void *const hw, hri_nvic_nvicip41_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP41;
	tmp &= ~NVIC_NVICIP41_PRI41_Msk;
	tmp |= NVIC_NVICIP41_PRI41(data);
	((Nvic *)hw)->NVICIP41 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP41_PRI41_bf(const void *const hw, hri_nvic_nvicip41_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP41 &= ~NVIC_NVICIP41_PRI41(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP41_PRI41_bf(const void *const hw, hri_nvic_nvicip41_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP41 ^= NVIC_NVICIP41_PRI41(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip41_reg_t hri_nvic_read_NVICIP41_PRI41_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP41;
	tmp = (tmp & NVIC_NVICIP41_PRI41_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP41_reg(const void *const hw, hri_nvic_nvicip41_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP41 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip41_reg_t hri_nvic_get_NVICIP41_reg(const void *const hw, hri_nvic_nvicip41_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP41;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP41_reg(const void *const hw, hri_nvic_nvicip41_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP41 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP41_reg(const void *const hw, hri_nvic_nvicip41_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP41 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP41_reg(const void *const hw, hri_nvic_nvicip41_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP41 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip41_reg_t hri_nvic_read_NVICIP41_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP41;
}

static inline void hri_nvic_set_NVICIP42_PRI42_bf(const void *const hw, hri_nvic_nvicip42_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP42 |= NVIC_NVICIP42_PRI42(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip42_reg_t hri_nvic_get_NVICIP42_PRI42_bf(const void *const hw, hri_nvic_nvicip42_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP42;
	tmp = (tmp & NVIC_NVICIP42_PRI42(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP42_PRI42_bf(const void *const hw, hri_nvic_nvicip42_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP42;
	tmp &= ~NVIC_NVICIP42_PRI42_Msk;
	tmp |= NVIC_NVICIP42_PRI42(data);
	((Nvic *)hw)->NVICIP42 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP42_PRI42_bf(const void *const hw, hri_nvic_nvicip42_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP42 &= ~NVIC_NVICIP42_PRI42(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP42_PRI42_bf(const void *const hw, hri_nvic_nvicip42_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP42 ^= NVIC_NVICIP42_PRI42(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip42_reg_t hri_nvic_read_NVICIP42_PRI42_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP42;
	tmp = (tmp & NVIC_NVICIP42_PRI42_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP42_reg(const void *const hw, hri_nvic_nvicip42_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP42 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip42_reg_t hri_nvic_get_NVICIP42_reg(const void *const hw, hri_nvic_nvicip42_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP42;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP42_reg(const void *const hw, hri_nvic_nvicip42_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP42 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP42_reg(const void *const hw, hri_nvic_nvicip42_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP42 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP42_reg(const void *const hw, hri_nvic_nvicip42_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP42 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip42_reg_t hri_nvic_read_NVICIP42_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP42;
}

static inline void hri_nvic_set_NVICIP43_PRI43_bf(const void *const hw, hri_nvic_nvicip43_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP43 |= NVIC_NVICIP43_PRI43(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip43_reg_t hri_nvic_get_NVICIP43_PRI43_bf(const void *const hw, hri_nvic_nvicip43_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP43;
	tmp = (tmp & NVIC_NVICIP43_PRI43(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP43_PRI43_bf(const void *const hw, hri_nvic_nvicip43_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP43;
	tmp &= ~NVIC_NVICIP43_PRI43_Msk;
	tmp |= NVIC_NVICIP43_PRI43(data);
	((Nvic *)hw)->NVICIP43 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP43_PRI43_bf(const void *const hw, hri_nvic_nvicip43_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP43 &= ~NVIC_NVICIP43_PRI43(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP43_PRI43_bf(const void *const hw, hri_nvic_nvicip43_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP43 ^= NVIC_NVICIP43_PRI43(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip43_reg_t hri_nvic_read_NVICIP43_PRI43_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP43;
	tmp = (tmp & NVIC_NVICIP43_PRI43_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP43_reg(const void *const hw, hri_nvic_nvicip43_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP43 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip43_reg_t hri_nvic_get_NVICIP43_reg(const void *const hw, hri_nvic_nvicip43_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP43;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP43_reg(const void *const hw, hri_nvic_nvicip43_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP43 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP43_reg(const void *const hw, hri_nvic_nvicip43_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP43 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP43_reg(const void *const hw, hri_nvic_nvicip43_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP43 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip43_reg_t hri_nvic_read_NVICIP43_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP43;
}

static inline void hri_nvic_set_NVICIP44_PRI44_bf(const void *const hw, hri_nvic_nvicip44_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP44 |= NVIC_NVICIP44_PRI44(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip44_reg_t hri_nvic_get_NVICIP44_PRI44_bf(const void *const hw, hri_nvic_nvicip44_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP44;
	tmp = (tmp & NVIC_NVICIP44_PRI44(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP44_PRI44_bf(const void *const hw, hri_nvic_nvicip44_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP44;
	tmp &= ~NVIC_NVICIP44_PRI44_Msk;
	tmp |= NVIC_NVICIP44_PRI44(data);
	((Nvic *)hw)->NVICIP44 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP44_PRI44_bf(const void *const hw, hri_nvic_nvicip44_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP44 &= ~NVIC_NVICIP44_PRI44(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP44_PRI44_bf(const void *const hw, hri_nvic_nvicip44_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP44 ^= NVIC_NVICIP44_PRI44(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip44_reg_t hri_nvic_read_NVICIP44_PRI44_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP44;
	tmp = (tmp & NVIC_NVICIP44_PRI44_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP44_reg(const void *const hw, hri_nvic_nvicip44_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP44 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip44_reg_t hri_nvic_get_NVICIP44_reg(const void *const hw, hri_nvic_nvicip44_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP44;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP44_reg(const void *const hw, hri_nvic_nvicip44_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP44 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP44_reg(const void *const hw, hri_nvic_nvicip44_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP44 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP44_reg(const void *const hw, hri_nvic_nvicip44_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP44 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip44_reg_t hri_nvic_read_NVICIP44_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP44;
}

static inline void hri_nvic_set_NVICIP45_PRI45_bf(const void *const hw, hri_nvic_nvicip45_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP45 |= NVIC_NVICIP45_PRI45(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip45_reg_t hri_nvic_get_NVICIP45_PRI45_bf(const void *const hw, hri_nvic_nvicip45_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP45;
	tmp = (tmp & NVIC_NVICIP45_PRI45(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP45_PRI45_bf(const void *const hw, hri_nvic_nvicip45_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP45;
	tmp &= ~NVIC_NVICIP45_PRI45_Msk;
	tmp |= NVIC_NVICIP45_PRI45(data);
	((Nvic *)hw)->NVICIP45 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP45_PRI45_bf(const void *const hw, hri_nvic_nvicip45_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP45 &= ~NVIC_NVICIP45_PRI45(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP45_PRI45_bf(const void *const hw, hri_nvic_nvicip45_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP45 ^= NVIC_NVICIP45_PRI45(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip45_reg_t hri_nvic_read_NVICIP45_PRI45_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP45;
	tmp = (tmp & NVIC_NVICIP45_PRI45_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP45_reg(const void *const hw, hri_nvic_nvicip45_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP45 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip45_reg_t hri_nvic_get_NVICIP45_reg(const void *const hw, hri_nvic_nvicip45_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP45;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP45_reg(const void *const hw, hri_nvic_nvicip45_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP45 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP45_reg(const void *const hw, hri_nvic_nvicip45_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP45 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP45_reg(const void *const hw, hri_nvic_nvicip45_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP45 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip45_reg_t hri_nvic_read_NVICIP45_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP45;
}

static inline void hri_nvic_set_NVICIP46_PRI46_bf(const void *const hw, hri_nvic_nvicip46_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP46 |= NVIC_NVICIP46_PRI46(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip46_reg_t hri_nvic_get_NVICIP46_PRI46_bf(const void *const hw, hri_nvic_nvicip46_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP46;
	tmp = (tmp & NVIC_NVICIP46_PRI46(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP46_PRI46_bf(const void *const hw, hri_nvic_nvicip46_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP46;
	tmp &= ~NVIC_NVICIP46_PRI46_Msk;
	tmp |= NVIC_NVICIP46_PRI46(data);
	((Nvic *)hw)->NVICIP46 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP46_PRI46_bf(const void *const hw, hri_nvic_nvicip46_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP46 &= ~NVIC_NVICIP46_PRI46(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP46_PRI46_bf(const void *const hw, hri_nvic_nvicip46_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP46 ^= NVIC_NVICIP46_PRI46(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip46_reg_t hri_nvic_read_NVICIP46_PRI46_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP46;
	tmp = (tmp & NVIC_NVICIP46_PRI46_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP46_reg(const void *const hw, hri_nvic_nvicip46_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP46 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip46_reg_t hri_nvic_get_NVICIP46_reg(const void *const hw, hri_nvic_nvicip46_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP46;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP46_reg(const void *const hw, hri_nvic_nvicip46_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP46 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP46_reg(const void *const hw, hri_nvic_nvicip46_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP46 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP46_reg(const void *const hw, hri_nvic_nvicip46_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP46 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip46_reg_t hri_nvic_read_NVICIP46_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP46;
}

static inline void hri_nvic_set_NVICIP47_PRI47_bf(const void *const hw, hri_nvic_nvicip47_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP47 |= NVIC_NVICIP47_PRI47(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip47_reg_t hri_nvic_get_NVICIP47_PRI47_bf(const void *const hw, hri_nvic_nvicip47_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP47;
	tmp = (tmp & NVIC_NVICIP47_PRI47(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP47_PRI47_bf(const void *const hw, hri_nvic_nvicip47_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP47;
	tmp &= ~NVIC_NVICIP47_PRI47_Msk;
	tmp |= NVIC_NVICIP47_PRI47(data);
	((Nvic *)hw)->NVICIP47 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP47_PRI47_bf(const void *const hw, hri_nvic_nvicip47_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP47 &= ~NVIC_NVICIP47_PRI47(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP47_PRI47_bf(const void *const hw, hri_nvic_nvicip47_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP47 ^= NVIC_NVICIP47_PRI47(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip47_reg_t hri_nvic_read_NVICIP47_PRI47_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP47;
	tmp = (tmp & NVIC_NVICIP47_PRI47_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP47_reg(const void *const hw, hri_nvic_nvicip47_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP47 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip47_reg_t hri_nvic_get_NVICIP47_reg(const void *const hw, hri_nvic_nvicip47_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP47;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP47_reg(const void *const hw, hri_nvic_nvicip47_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP47 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP47_reg(const void *const hw, hri_nvic_nvicip47_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP47 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP47_reg(const void *const hw, hri_nvic_nvicip47_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP47 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip47_reg_t hri_nvic_read_NVICIP47_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP47;
}

static inline void hri_nvic_set_NVICIP48_PRI48_bf(const void *const hw, hri_nvic_nvicip48_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP48 |= NVIC_NVICIP48_PRI48(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip48_reg_t hri_nvic_get_NVICIP48_PRI48_bf(const void *const hw, hri_nvic_nvicip48_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP48;
	tmp = (tmp & NVIC_NVICIP48_PRI48(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP48_PRI48_bf(const void *const hw, hri_nvic_nvicip48_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP48;
	tmp &= ~NVIC_NVICIP48_PRI48_Msk;
	tmp |= NVIC_NVICIP48_PRI48(data);
	((Nvic *)hw)->NVICIP48 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP48_PRI48_bf(const void *const hw, hri_nvic_nvicip48_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP48 &= ~NVIC_NVICIP48_PRI48(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP48_PRI48_bf(const void *const hw, hri_nvic_nvicip48_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP48 ^= NVIC_NVICIP48_PRI48(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip48_reg_t hri_nvic_read_NVICIP48_PRI48_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP48;
	tmp = (tmp & NVIC_NVICIP48_PRI48_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP48_reg(const void *const hw, hri_nvic_nvicip48_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP48 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip48_reg_t hri_nvic_get_NVICIP48_reg(const void *const hw, hri_nvic_nvicip48_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP48;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP48_reg(const void *const hw, hri_nvic_nvicip48_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP48 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP48_reg(const void *const hw, hri_nvic_nvicip48_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP48 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP48_reg(const void *const hw, hri_nvic_nvicip48_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP48 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip48_reg_t hri_nvic_read_NVICIP48_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP48;
}

static inline void hri_nvic_set_NVICIP49_PRI49_bf(const void *const hw, hri_nvic_nvicip49_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP49 |= NVIC_NVICIP49_PRI49(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip49_reg_t hri_nvic_get_NVICIP49_PRI49_bf(const void *const hw, hri_nvic_nvicip49_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP49;
	tmp = (tmp & NVIC_NVICIP49_PRI49(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP49_PRI49_bf(const void *const hw, hri_nvic_nvicip49_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP49;
	tmp &= ~NVIC_NVICIP49_PRI49_Msk;
	tmp |= NVIC_NVICIP49_PRI49(data);
	((Nvic *)hw)->NVICIP49 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP49_PRI49_bf(const void *const hw, hri_nvic_nvicip49_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP49 &= ~NVIC_NVICIP49_PRI49(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP49_PRI49_bf(const void *const hw, hri_nvic_nvicip49_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP49 ^= NVIC_NVICIP49_PRI49(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip49_reg_t hri_nvic_read_NVICIP49_PRI49_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP49;
	tmp = (tmp & NVIC_NVICIP49_PRI49_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP49_reg(const void *const hw, hri_nvic_nvicip49_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP49 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip49_reg_t hri_nvic_get_NVICIP49_reg(const void *const hw, hri_nvic_nvicip49_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP49;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP49_reg(const void *const hw, hri_nvic_nvicip49_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP49 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP49_reg(const void *const hw, hri_nvic_nvicip49_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP49 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP49_reg(const void *const hw, hri_nvic_nvicip49_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP49 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip49_reg_t hri_nvic_read_NVICIP49_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP49;
}

static inline void hri_nvic_set_NVICIP50_PRI50_bf(const void *const hw, hri_nvic_nvicip50_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP50 |= NVIC_NVICIP50_PRI50(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip50_reg_t hri_nvic_get_NVICIP50_PRI50_bf(const void *const hw, hri_nvic_nvicip50_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP50;
	tmp = (tmp & NVIC_NVICIP50_PRI50(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP50_PRI50_bf(const void *const hw, hri_nvic_nvicip50_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP50;
	tmp &= ~NVIC_NVICIP50_PRI50_Msk;
	tmp |= NVIC_NVICIP50_PRI50(data);
	((Nvic *)hw)->NVICIP50 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP50_PRI50_bf(const void *const hw, hri_nvic_nvicip50_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP50 &= ~NVIC_NVICIP50_PRI50(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP50_PRI50_bf(const void *const hw, hri_nvic_nvicip50_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP50 ^= NVIC_NVICIP50_PRI50(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip50_reg_t hri_nvic_read_NVICIP50_PRI50_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP50;
	tmp = (tmp & NVIC_NVICIP50_PRI50_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP50_reg(const void *const hw, hri_nvic_nvicip50_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP50 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip50_reg_t hri_nvic_get_NVICIP50_reg(const void *const hw, hri_nvic_nvicip50_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP50;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP50_reg(const void *const hw, hri_nvic_nvicip50_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP50 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP50_reg(const void *const hw, hri_nvic_nvicip50_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP50 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP50_reg(const void *const hw, hri_nvic_nvicip50_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP50 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip50_reg_t hri_nvic_read_NVICIP50_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP50;
}

static inline void hri_nvic_set_NVICIP51_PRI51_bf(const void *const hw, hri_nvic_nvicip51_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP51 |= NVIC_NVICIP51_PRI51(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip51_reg_t hri_nvic_get_NVICIP51_PRI51_bf(const void *const hw, hri_nvic_nvicip51_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP51;
	tmp = (tmp & NVIC_NVICIP51_PRI51(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP51_PRI51_bf(const void *const hw, hri_nvic_nvicip51_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP51;
	tmp &= ~NVIC_NVICIP51_PRI51_Msk;
	tmp |= NVIC_NVICIP51_PRI51(data);
	((Nvic *)hw)->NVICIP51 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP51_PRI51_bf(const void *const hw, hri_nvic_nvicip51_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP51 &= ~NVIC_NVICIP51_PRI51(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP51_PRI51_bf(const void *const hw, hri_nvic_nvicip51_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP51 ^= NVIC_NVICIP51_PRI51(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip51_reg_t hri_nvic_read_NVICIP51_PRI51_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP51;
	tmp = (tmp & NVIC_NVICIP51_PRI51_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP51_reg(const void *const hw, hri_nvic_nvicip51_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP51 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip51_reg_t hri_nvic_get_NVICIP51_reg(const void *const hw, hri_nvic_nvicip51_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP51;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP51_reg(const void *const hw, hri_nvic_nvicip51_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP51 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP51_reg(const void *const hw, hri_nvic_nvicip51_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP51 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP51_reg(const void *const hw, hri_nvic_nvicip51_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP51 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip51_reg_t hri_nvic_read_NVICIP51_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP51;
}

static inline void hri_nvic_set_NVICIP52_PRI52_bf(const void *const hw, hri_nvic_nvicip52_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP52 |= NVIC_NVICIP52_PRI52(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip52_reg_t hri_nvic_get_NVICIP52_PRI52_bf(const void *const hw, hri_nvic_nvicip52_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP52;
	tmp = (tmp & NVIC_NVICIP52_PRI52(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP52_PRI52_bf(const void *const hw, hri_nvic_nvicip52_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP52;
	tmp &= ~NVIC_NVICIP52_PRI52_Msk;
	tmp |= NVIC_NVICIP52_PRI52(data);
	((Nvic *)hw)->NVICIP52 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP52_PRI52_bf(const void *const hw, hri_nvic_nvicip52_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP52 &= ~NVIC_NVICIP52_PRI52(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP52_PRI52_bf(const void *const hw, hri_nvic_nvicip52_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP52 ^= NVIC_NVICIP52_PRI52(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip52_reg_t hri_nvic_read_NVICIP52_PRI52_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP52;
	tmp = (tmp & NVIC_NVICIP52_PRI52_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP52_reg(const void *const hw, hri_nvic_nvicip52_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP52 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip52_reg_t hri_nvic_get_NVICIP52_reg(const void *const hw, hri_nvic_nvicip52_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP52;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP52_reg(const void *const hw, hri_nvic_nvicip52_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP52 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP52_reg(const void *const hw, hri_nvic_nvicip52_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP52 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP52_reg(const void *const hw, hri_nvic_nvicip52_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP52 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip52_reg_t hri_nvic_read_NVICIP52_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP52;
}

static inline void hri_nvic_set_NVICIP53_PRI53_bf(const void *const hw, hri_nvic_nvicip53_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP53 |= NVIC_NVICIP53_PRI53(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip53_reg_t hri_nvic_get_NVICIP53_PRI53_bf(const void *const hw, hri_nvic_nvicip53_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP53;
	tmp = (tmp & NVIC_NVICIP53_PRI53(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP53_PRI53_bf(const void *const hw, hri_nvic_nvicip53_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP53;
	tmp &= ~NVIC_NVICIP53_PRI53_Msk;
	tmp |= NVIC_NVICIP53_PRI53(data);
	((Nvic *)hw)->NVICIP53 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP53_PRI53_bf(const void *const hw, hri_nvic_nvicip53_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP53 &= ~NVIC_NVICIP53_PRI53(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP53_PRI53_bf(const void *const hw, hri_nvic_nvicip53_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP53 ^= NVIC_NVICIP53_PRI53(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip53_reg_t hri_nvic_read_NVICIP53_PRI53_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP53;
	tmp = (tmp & NVIC_NVICIP53_PRI53_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP53_reg(const void *const hw, hri_nvic_nvicip53_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP53 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip53_reg_t hri_nvic_get_NVICIP53_reg(const void *const hw, hri_nvic_nvicip53_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP53;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP53_reg(const void *const hw, hri_nvic_nvicip53_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP53 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP53_reg(const void *const hw, hri_nvic_nvicip53_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP53 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP53_reg(const void *const hw, hri_nvic_nvicip53_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP53 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip53_reg_t hri_nvic_read_NVICIP53_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP53;
}

static inline void hri_nvic_set_NVICIP54_PRI54_bf(const void *const hw, hri_nvic_nvicip54_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP54 |= NVIC_NVICIP54_PRI54(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip54_reg_t hri_nvic_get_NVICIP54_PRI54_bf(const void *const hw, hri_nvic_nvicip54_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP54;
	tmp = (tmp & NVIC_NVICIP54_PRI54(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP54_PRI54_bf(const void *const hw, hri_nvic_nvicip54_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP54;
	tmp &= ~NVIC_NVICIP54_PRI54_Msk;
	tmp |= NVIC_NVICIP54_PRI54(data);
	((Nvic *)hw)->NVICIP54 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP54_PRI54_bf(const void *const hw, hri_nvic_nvicip54_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP54 &= ~NVIC_NVICIP54_PRI54(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP54_PRI54_bf(const void *const hw, hri_nvic_nvicip54_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP54 ^= NVIC_NVICIP54_PRI54(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip54_reg_t hri_nvic_read_NVICIP54_PRI54_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP54;
	tmp = (tmp & NVIC_NVICIP54_PRI54_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP54_reg(const void *const hw, hri_nvic_nvicip54_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP54 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip54_reg_t hri_nvic_get_NVICIP54_reg(const void *const hw, hri_nvic_nvicip54_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP54;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP54_reg(const void *const hw, hri_nvic_nvicip54_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP54 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP54_reg(const void *const hw, hri_nvic_nvicip54_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP54 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP54_reg(const void *const hw, hri_nvic_nvicip54_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP54 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip54_reg_t hri_nvic_read_NVICIP54_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP54;
}

static inline void hri_nvic_set_NVICIP55_PRI55_bf(const void *const hw, hri_nvic_nvicip55_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP55 |= NVIC_NVICIP55_PRI55(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip55_reg_t hri_nvic_get_NVICIP55_PRI55_bf(const void *const hw, hri_nvic_nvicip55_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP55;
	tmp = (tmp & NVIC_NVICIP55_PRI55(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP55_PRI55_bf(const void *const hw, hri_nvic_nvicip55_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP55;
	tmp &= ~NVIC_NVICIP55_PRI55_Msk;
	tmp |= NVIC_NVICIP55_PRI55(data);
	((Nvic *)hw)->NVICIP55 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP55_PRI55_bf(const void *const hw, hri_nvic_nvicip55_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP55 &= ~NVIC_NVICIP55_PRI55(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP55_PRI55_bf(const void *const hw, hri_nvic_nvicip55_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP55 ^= NVIC_NVICIP55_PRI55(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip55_reg_t hri_nvic_read_NVICIP55_PRI55_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP55;
	tmp = (tmp & NVIC_NVICIP55_PRI55_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP55_reg(const void *const hw, hri_nvic_nvicip55_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP55 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip55_reg_t hri_nvic_get_NVICIP55_reg(const void *const hw, hri_nvic_nvicip55_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP55;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP55_reg(const void *const hw, hri_nvic_nvicip55_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP55 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP55_reg(const void *const hw, hri_nvic_nvicip55_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP55 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP55_reg(const void *const hw, hri_nvic_nvicip55_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP55 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip55_reg_t hri_nvic_read_NVICIP55_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP55;
}

static inline void hri_nvic_set_NVICIP56_PRI56_bf(const void *const hw, hri_nvic_nvicip56_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP56 |= NVIC_NVICIP56_PRI56(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip56_reg_t hri_nvic_get_NVICIP56_PRI56_bf(const void *const hw, hri_nvic_nvicip56_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP56;
	tmp = (tmp & NVIC_NVICIP56_PRI56(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP56_PRI56_bf(const void *const hw, hri_nvic_nvicip56_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP56;
	tmp &= ~NVIC_NVICIP56_PRI56_Msk;
	tmp |= NVIC_NVICIP56_PRI56(data);
	((Nvic *)hw)->NVICIP56 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP56_PRI56_bf(const void *const hw, hri_nvic_nvicip56_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP56 &= ~NVIC_NVICIP56_PRI56(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP56_PRI56_bf(const void *const hw, hri_nvic_nvicip56_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP56 ^= NVIC_NVICIP56_PRI56(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip56_reg_t hri_nvic_read_NVICIP56_PRI56_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP56;
	tmp = (tmp & NVIC_NVICIP56_PRI56_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP56_reg(const void *const hw, hri_nvic_nvicip56_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP56 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip56_reg_t hri_nvic_get_NVICIP56_reg(const void *const hw, hri_nvic_nvicip56_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP56;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP56_reg(const void *const hw, hri_nvic_nvicip56_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP56 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP56_reg(const void *const hw, hri_nvic_nvicip56_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP56 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP56_reg(const void *const hw, hri_nvic_nvicip56_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP56 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip56_reg_t hri_nvic_read_NVICIP56_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP56;
}

static inline void hri_nvic_set_NVICIP57_PRI57_bf(const void *const hw, hri_nvic_nvicip57_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP57 |= NVIC_NVICIP57_PRI57(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip57_reg_t hri_nvic_get_NVICIP57_PRI57_bf(const void *const hw, hri_nvic_nvicip57_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP57;
	tmp = (tmp & NVIC_NVICIP57_PRI57(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP57_PRI57_bf(const void *const hw, hri_nvic_nvicip57_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP57;
	tmp &= ~NVIC_NVICIP57_PRI57_Msk;
	tmp |= NVIC_NVICIP57_PRI57(data);
	((Nvic *)hw)->NVICIP57 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP57_PRI57_bf(const void *const hw, hri_nvic_nvicip57_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP57 &= ~NVIC_NVICIP57_PRI57(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP57_PRI57_bf(const void *const hw, hri_nvic_nvicip57_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP57 ^= NVIC_NVICIP57_PRI57(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip57_reg_t hri_nvic_read_NVICIP57_PRI57_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP57;
	tmp = (tmp & NVIC_NVICIP57_PRI57_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP57_reg(const void *const hw, hri_nvic_nvicip57_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP57 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip57_reg_t hri_nvic_get_NVICIP57_reg(const void *const hw, hri_nvic_nvicip57_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP57;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP57_reg(const void *const hw, hri_nvic_nvicip57_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP57 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP57_reg(const void *const hw, hri_nvic_nvicip57_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP57 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP57_reg(const void *const hw, hri_nvic_nvicip57_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP57 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip57_reg_t hri_nvic_read_NVICIP57_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP57;
}

static inline void hri_nvic_set_NVICIP58_PRI58_bf(const void *const hw, hri_nvic_nvicip58_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP58 |= NVIC_NVICIP58_PRI58(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip58_reg_t hri_nvic_get_NVICIP58_PRI58_bf(const void *const hw, hri_nvic_nvicip58_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP58;
	tmp = (tmp & NVIC_NVICIP58_PRI58(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP58_PRI58_bf(const void *const hw, hri_nvic_nvicip58_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP58;
	tmp &= ~NVIC_NVICIP58_PRI58_Msk;
	tmp |= NVIC_NVICIP58_PRI58(data);
	((Nvic *)hw)->NVICIP58 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP58_PRI58_bf(const void *const hw, hri_nvic_nvicip58_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP58 &= ~NVIC_NVICIP58_PRI58(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP58_PRI58_bf(const void *const hw, hri_nvic_nvicip58_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP58 ^= NVIC_NVICIP58_PRI58(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip58_reg_t hri_nvic_read_NVICIP58_PRI58_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP58;
	tmp = (tmp & NVIC_NVICIP58_PRI58_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP58_reg(const void *const hw, hri_nvic_nvicip58_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP58 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip58_reg_t hri_nvic_get_NVICIP58_reg(const void *const hw, hri_nvic_nvicip58_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP58;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP58_reg(const void *const hw, hri_nvic_nvicip58_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP58 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP58_reg(const void *const hw, hri_nvic_nvicip58_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP58 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP58_reg(const void *const hw, hri_nvic_nvicip58_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP58 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip58_reg_t hri_nvic_read_NVICIP58_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP58;
}

static inline void hri_nvic_set_NVICIP59_PRI59_bf(const void *const hw, hri_nvic_nvicip59_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP59 |= NVIC_NVICIP59_PRI59(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip59_reg_t hri_nvic_get_NVICIP59_PRI59_bf(const void *const hw, hri_nvic_nvicip59_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP59;
	tmp = (tmp & NVIC_NVICIP59_PRI59(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP59_PRI59_bf(const void *const hw, hri_nvic_nvicip59_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP59;
	tmp &= ~NVIC_NVICIP59_PRI59_Msk;
	tmp |= NVIC_NVICIP59_PRI59(data);
	((Nvic *)hw)->NVICIP59 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP59_PRI59_bf(const void *const hw, hri_nvic_nvicip59_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP59 &= ~NVIC_NVICIP59_PRI59(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP59_PRI59_bf(const void *const hw, hri_nvic_nvicip59_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP59 ^= NVIC_NVICIP59_PRI59(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip59_reg_t hri_nvic_read_NVICIP59_PRI59_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP59;
	tmp = (tmp & NVIC_NVICIP59_PRI59_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP59_reg(const void *const hw, hri_nvic_nvicip59_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP59 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip59_reg_t hri_nvic_get_NVICIP59_reg(const void *const hw, hri_nvic_nvicip59_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP59;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP59_reg(const void *const hw, hri_nvic_nvicip59_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP59 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP59_reg(const void *const hw, hri_nvic_nvicip59_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP59 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP59_reg(const void *const hw, hri_nvic_nvicip59_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP59 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip59_reg_t hri_nvic_read_NVICIP59_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP59;
}

static inline void hri_nvic_set_NVICIP60_PRI60_bf(const void *const hw, hri_nvic_nvicip60_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP60 |= NVIC_NVICIP60_PRI60(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip60_reg_t hri_nvic_get_NVICIP60_PRI60_bf(const void *const hw, hri_nvic_nvicip60_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP60;
	tmp = (tmp & NVIC_NVICIP60_PRI60(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP60_PRI60_bf(const void *const hw, hri_nvic_nvicip60_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP60;
	tmp &= ~NVIC_NVICIP60_PRI60_Msk;
	tmp |= NVIC_NVICIP60_PRI60(data);
	((Nvic *)hw)->NVICIP60 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP60_PRI60_bf(const void *const hw, hri_nvic_nvicip60_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP60 &= ~NVIC_NVICIP60_PRI60(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP60_PRI60_bf(const void *const hw, hri_nvic_nvicip60_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP60 ^= NVIC_NVICIP60_PRI60(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip60_reg_t hri_nvic_read_NVICIP60_PRI60_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP60;
	tmp = (tmp & NVIC_NVICIP60_PRI60_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP60_reg(const void *const hw, hri_nvic_nvicip60_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP60 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip60_reg_t hri_nvic_get_NVICIP60_reg(const void *const hw, hri_nvic_nvicip60_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP60;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP60_reg(const void *const hw, hri_nvic_nvicip60_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP60 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP60_reg(const void *const hw, hri_nvic_nvicip60_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP60 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP60_reg(const void *const hw, hri_nvic_nvicip60_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP60 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip60_reg_t hri_nvic_read_NVICIP60_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP60;
}

static inline void hri_nvic_set_NVICIP61_PRI61_bf(const void *const hw, hri_nvic_nvicip61_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP61 |= NVIC_NVICIP61_PRI61(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip61_reg_t hri_nvic_get_NVICIP61_PRI61_bf(const void *const hw, hri_nvic_nvicip61_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP61;
	tmp = (tmp & NVIC_NVICIP61_PRI61(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP61_PRI61_bf(const void *const hw, hri_nvic_nvicip61_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP61;
	tmp &= ~NVIC_NVICIP61_PRI61_Msk;
	tmp |= NVIC_NVICIP61_PRI61(data);
	((Nvic *)hw)->NVICIP61 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP61_PRI61_bf(const void *const hw, hri_nvic_nvicip61_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP61 &= ~NVIC_NVICIP61_PRI61(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP61_PRI61_bf(const void *const hw, hri_nvic_nvicip61_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP61 ^= NVIC_NVICIP61_PRI61(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip61_reg_t hri_nvic_read_NVICIP61_PRI61_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP61;
	tmp = (tmp & NVIC_NVICIP61_PRI61_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP61_reg(const void *const hw, hri_nvic_nvicip61_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP61 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip61_reg_t hri_nvic_get_NVICIP61_reg(const void *const hw, hri_nvic_nvicip61_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP61;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP61_reg(const void *const hw, hri_nvic_nvicip61_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP61 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP61_reg(const void *const hw, hri_nvic_nvicip61_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP61 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP61_reg(const void *const hw, hri_nvic_nvicip61_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP61 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip61_reg_t hri_nvic_read_NVICIP61_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP61;
}

static inline void hri_nvic_set_NVICIP62_PRI62_bf(const void *const hw, hri_nvic_nvicip62_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP62 |= NVIC_NVICIP62_PRI62(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip62_reg_t hri_nvic_get_NVICIP62_PRI62_bf(const void *const hw, hri_nvic_nvicip62_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP62;
	tmp = (tmp & NVIC_NVICIP62_PRI62(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP62_PRI62_bf(const void *const hw, hri_nvic_nvicip62_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP62;
	tmp &= ~NVIC_NVICIP62_PRI62_Msk;
	tmp |= NVIC_NVICIP62_PRI62(data);
	((Nvic *)hw)->NVICIP62 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP62_PRI62_bf(const void *const hw, hri_nvic_nvicip62_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP62 &= ~NVIC_NVICIP62_PRI62(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP62_PRI62_bf(const void *const hw, hri_nvic_nvicip62_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP62 ^= NVIC_NVICIP62_PRI62(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip62_reg_t hri_nvic_read_NVICIP62_PRI62_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP62;
	tmp = (tmp & NVIC_NVICIP62_PRI62_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP62_reg(const void *const hw, hri_nvic_nvicip62_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP62 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip62_reg_t hri_nvic_get_NVICIP62_reg(const void *const hw, hri_nvic_nvicip62_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP62;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP62_reg(const void *const hw, hri_nvic_nvicip62_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP62 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP62_reg(const void *const hw, hri_nvic_nvicip62_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP62 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP62_reg(const void *const hw, hri_nvic_nvicip62_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP62 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip62_reg_t hri_nvic_read_NVICIP62_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP62;
}

static inline void hri_nvic_set_NVICIP63_PRI63_bf(const void *const hw, hri_nvic_nvicip63_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP63 |= NVIC_NVICIP63_PRI63(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip63_reg_t hri_nvic_get_NVICIP63_PRI63_bf(const void *const hw, hri_nvic_nvicip63_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP63;
	tmp = (tmp & NVIC_NVICIP63_PRI63(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP63_PRI63_bf(const void *const hw, hri_nvic_nvicip63_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP63;
	tmp &= ~NVIC_NVICIP63_PRI63_Msk;
	tmp |= NVIC_NVICIP63_PRI63(data);
	((Nvic *)hw)->NVICIP63 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP63_PRI63_bf(const void *const hw, hri_nvic_nvicip63_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP63 &= ~NVIC_NVICIP63_PRI63(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP63_PRI63_bf(const void *const hw, hri_nvic_nvicip63_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP63 ^= NVIC_NVICIP63_PRI63(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip63_reg_t hri_nvic_read_NVICIP63_PRI63_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP63;
	tmp = (tmp & NVIC_NVICIP63_PRI63_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP63_reg(const void *const hw, hri_nvic_nvicip63_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP63 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip63_reg_t hri_nvic_get_NVICIP63_reg(const void *const hw, hri_nvic_nvicip63_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP63;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP63_reg(const void *const hw, hri_nvic_nvicip63_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP63 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP63_reg(const void *const hw, hri_nvic_nvicip63_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP63 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP63_reg(const void *const hw, hri_nvic_nvicip63_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP63 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip63_reg_t hri_nvic_read_NVICIP63_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP63;
}

static inline void hri_nvic_set_NVICIP64_PRI64_bf(const void *const hw, hri_nvic_nvicip64_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP64 |= NVIC_NVICIP64_PRI64(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip64_reg_t hri_nvic_get_NVICIP64_PRI64_bf(const void *const hw, hri_nvic_nvicip64_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP64;
	tmp = (tmp & NVIC_NVICIP64_PRI64(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP64_PRI64_bf(const void *const hw, hri_nvic_nvicip64_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP64;
	tmp &= ~NVIC_NVICIP64_PRI64_Msk;
	tmp |= NVIC_NVICIP64_PRI64(data);
	((Nvic *)hw)->NVICIP64 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP64_PRI64_bf(const void *const hw, hri_nvic_nvicip64_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP64 &= ~NVIC_NVICIP64_PRI64(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP64_PRI64_bf(const void *const hw, hri_nvic_nvicip64_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP64 ^= NVIC_NVICIP64_PRI64(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip64_reg_t hri_nvic_read_NVICIP64_PRI64_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP64;
	tmp = (tmp & NVIC_NVICIP64_PRI64_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP64_reg(const void *const hw, hri_nvic_nvicip64_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP64 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip64_reg_t hri_nvic_get_NVICIP64_reg(const void *const hw, hri_nvic_nvicip64_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP64;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP64_reg(const void *const hw, hri_nvic_nvicip64_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP64 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP64_reg(const void *const hw, hri_nvic_nvicip64_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP64 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP64_reg(const void *const hw, hri_nvic_nvicip64_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP64 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip64_reg_t hri_nvic_read_NVICIP64_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP64;
}

static inline void hri_nvic_set_NVICIP65_PRI65_bf(const void *const hw, hri_nvic_nvicip65_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP65 |= NVIC_NVICIP65_PRI65(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip65_reg_t hri_nvic_get_NVICIP65_PRI65_bf(const void *const hw, hri_nvic_nvicip65_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP65;
	tmp = (tmp & NVIC_NVICIP65_PRI65(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP65_PRI65_bf(const void *const hw, hri_nvic_nvicip65_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP65;
	tmp &= ~NVIC_NVICIP65_PRI65_Msk;
	tmp |= NVIC_NVICIP65_PRI65(data);
	((Nvic *)hw)->NVICIP65 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP65_PRI65_bf(const void *const hw, hri_nvic_nvicip65_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP65 &= ~NVIC_NVICIP65_PRI65(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP65_PRI65_bf(const void *const hw, hri_nvic_nvicip65_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP65 ^= NVIC_NVICIP65_PRI65(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip65_reg_t hri_nvic_read_NVICIP65_PRI65_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP65;
	tmp = (tmp & NVIC_NVICIP65_PRI65_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP65_reg(const void *const hw, hri_nvic_nvicip65_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP65 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip65_reg_t hri_nvic_get_NVICIP65_reg(const void *const hw, hri_nvic_nvicip65_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP65;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP65_reg(const void *const hw, hri_nvic_nvicip65_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP65 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP65_reg(const void *const hw, hri_nvic_nvicip65_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP65 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP65_reg(const void *const hw, hri_nvic_nvicip65_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP65 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip65_reg_t hri_nvic_read_NVICIP65_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP65;
}

static inline void hri_nvic_set_NVICIP66_PRI66_bf(const void *const hw, hri_nvic_nvicip66_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP66 |= NVIC_NVICIP66_PRI66(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip66_reg_t hri_nvic_get_NVICIP66_PRI66_bf(const void *const hw, hri_nvic_nvicip66_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP66;
	tmp = (tmp & NVIC_NVICIP66_PRI66(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP66_PRI66_bf(const void *const hw, hri_nvic_nvicip66_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP66;
	tmp &= ~NVIC_NVICIP66_PRI66_Msk;
	tmp |= NVIC_NVICIP66_PRI66(data);
	((Nvic *)hw)->NVICIP66 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP66_PRI66_bf(const void *const hw, hri_nvic_nvicip66_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP66 &= ~NVIC_NVICIP66_PRI66(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP66_PRI66_bf(const void *const hw, hri_nvic_nvicip66_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP66 ^= NVIC_NVICIP66_PRI66(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip66_reg_t hri_nvic_read_NVICIP66_PRI66_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP66;
	tmp = (tmp & NVIC_NVICIP66_PRI66_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP66_reg(const void *const hw, hri_nvic_nvicip66_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP66 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip66_reg_t hri_nvic_get_NVICIP66_reg(const void *const hw, hri_nvic_nvicip66_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP66;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP66_reg(const void *const hw, hri_nvic_nvicip66_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP66 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP66_reg(const void *const hw, hri_nvic_nvicip66_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP66 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP66_reg(const void *const hw, hri_nvic_nvicip66_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP66 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip66_reg_t hri_nvic_read_NVICIP66_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP66;
}

static inline void hri_nvic_set_NVICIP67_PRI67_bf(const void *const hw, hri_nvic_nvicip67_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP67 |= NVIC_NVICIP67_PRI67(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip67_reg_t hri_nvic_get_NVICIP67_PRI67_bf(const void *const hw, hri_nvic_nvicip67_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP67;
	tmp = (tmp & NVIC_NVICIP67_PRI67(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP67_PRI67_bf(const void *const hw, hri_nvic_nvicip67_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP67;
	tmp &= ~NVIC_NVICIP67_PRI67_Msk;
	tmp |= NVIC_NVICIP67_PRI67(data);
	((Nvic *)hw)->NVICIP67 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP67_PRI67_bf(const void *const hw, hri_nvic_nvicip67_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP67 &= ~NVIC_NVICIP67_PRI67(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP67_PRI67_bf(const void *const hw, hri_nvic_nvicip67_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP67 ^= NVIC_NVICIP67_PRI67(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip67_reg_t hri_nvic_read_NVICIP67_PRI67_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP67;
	tmp = (tmp & NVIC_NVICIP67_PRI67_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP67_reg(const void *const hw, hri_nvic_nvicip67_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP67 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip67_reg_t hri_nvic_get_NVICIP67_reg(const void *const hw, hri_nvic_nvicip67_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP67;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP67_reg(const void *const hw, hri_nvic_nvicip67_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP67 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP67_reg(const void *const hw, hri_nvic_nvicip67_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP67 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP67_reg(const void *const hw, hri_nvic_nvicip67_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP67 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip67_reg_t hri_nvic_read_NVICIP67_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP67;
}

static inline void hri_nvic_set_NVICIP68_PRI68_bf(const void *const hw, hri_nvic_nvicip68_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP68 |= NVIC_NVICIP68_PRI68(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip68_reg_t hri_nvic_get_NVICIP68_PRI68_bf(const void *const hw, hri_nvic_nvicip68_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP68;
	tmp = (tmp & NVIC_NVICIP68_PRI68(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP68_PRI68_bf(const void *const hw, hri_nvic_nvicip68_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP68;
	tmp &= ~NVIC_NVICIP68_PRI68_Msk;
	tmp |= NVIC_NVICIP68_PRI68(data);
	((Nvic *)hw)->NVICIP68 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP68_PRI68_bf(const void *const hw, hri_nvic_nvicip68_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP68 &= ~NVIC_NVICIP68_PRI68(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP68_PRI68_bf(const void *const hw, hri_nvic_nvicip68_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP68 ^= NVIC_NVICIP68_PRI68(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip68_reg_t hri_nvic_read_NVICIP68_PRI68_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP68;
	tmp = (tmp & NVIC_NVICIP68_PRI68_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP68_reg(const void *const hw, hri_nvic_nvicip68_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP68 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip68_reg_t hri_nvic_get_NVICIP68_reg(const void *const hw, hri_nvic_nvicip68_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP68;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP68_reg(const void *const hw, hri_nvic_nvicip68_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP68 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP68_reg(const void *const hw, hri_nvic_nvicip68_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP68 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP68_reg(const void *const hw, hri_nvic_nvicip68_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP68 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip68_reg_t hri_nvic_read_NVICIP68_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP68;
}

static inline void hri_nvic_set_NVICIP69_PRI69_bf(const void *const hw, hri_nvic_nvicip69_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP69 |= NVIC_NVICIP69_PRI69(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip69_reg_t hri_nvic_get_NVICIP69_PRI69_bf(const void *const hw, hri_nvic_nvicip69_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP69;
	tmp = (tmp & NVIC_NVICIP69_PRI69(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP69_PRI69_bf(const void *const hw, hri_nvic_nvicip69_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP69;
	tmp &= ~NVIC_NVICIP69_PRI69_Msk;
	tmp |= NVIC_NVICIP69_PRI69(data);
	((Nvic *)hw)->NVICIP69 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP69_PRI69_bf(const void *const hw, hri_nvic_nvicip69_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP69 &= ~NVIC_NVICIP69_PRI69(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP69_PRI69_bf(const void *const hw, hri_nvic_nvicip69_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP69 ^= NVIC_NVICIP69_PRI69(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip69_reg_t hri_nvic_read_NVICIP69_PRI69_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP69;
	tmp = (tmp & NVIC_NVICIP69_PRI69_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP69_reg(const void *const hw, hri_nvic_nvicip69_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP69 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip69_reg_t hri_nvic_get_NVICIP69_reg(const void *const hw, hri_nvic_nvicip69_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP69;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP69_reg(const void *const hw, hri_nvic_nvicip69_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP69 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP69_reg(const void *const hw, hri_nvic_nvicip69_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP69 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP69_reg(const void *const hw, hri_nvic_nvicip69_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP69 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip69_reg_t hri_nvic_read_NVICIP69_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP69;
}

static inline void hri_nvic_set_NVICIP70_PRI70_bf(const void *const hw, hri_nvic_nvicip70_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP70 |= NVIC_NVICIP70_PRI70(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip70_reg_t hri_nvic_get_NVICIP70_PRI70_bf(const void *const hw, hri_nvic_nvicip70_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP70;
	tmp = (tmp & NVIC_NVICIP70_PRI70(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP70_PRI70_bf(const void *const hw, hri_nvic_nvicip70_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP70;
	tmp &= ~NVIC_NVICIP70_PRI70_Msk;
	tmp |= NVIC_NVICIP70_PRI70(data);
	((Nvic *)hw)->NVICIP70 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP70_PRI70_bf(const void *const hw, hri_nvic_nvicip70_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP70 &= ~NVIC_NVICIP70_PRI70(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP70_PRI70_bf(const void *const hw, hri_nvic_nvicip70_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP70 ^= NVIC_NVICIP70_PRI70(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip70_reg_t hri_nvic_read_NVICIP70_PRI70_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP70;
	tmp = (tmp & NVIC_NVICIP70_PRI70_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP70_reg(const void *const hw, hri_nvic_nvicip70_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP70 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip70_reg_t hri_nvic_get_NVICIP70_reg(const void *const hw, hri_nvic_nvicip70_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP70;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP70_reg(const void *const hw, hri_nvic_nvicip70_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP70 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP70_reg(const void *const hw, hri_nvic_nvicip70_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP70 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP70_reg(const void *const hw, hri_nvic_nvicip70_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP70 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip70_reg_t hri_nvic_read_NVICIP70_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP70;
}

static inline void hri_nvic_set_NVICIP71_PRI71_bf(const void *const hw, hri_nvic_nvicip71_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP71 |= NVIC_NVICIP71_PRI71(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip71_reg_t hri_nvic_get_NVICIP71_PRI71_bf(const void *const hw, hri_nvic_nvicip71_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP71;
	tmp = (tmp & NVIC_NVICIP71_PRI71(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP71_PRI71_bf(const void *const hw, hri_nvic_nvicip71_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP71;
	tmp &= ~NVIC_NVICIP71_PRI71_Msk;
	tmp |= NVIC_NVICIP71_PRI71(data);
	((Nvic *)hw)->NVICIP71 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP71_PRI71_bf(const void *const hw, hri_nvic_nvicip71_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP71 &= ~NVIC_NVICIP71_PRI71(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP71_PRI71_bf(const void *const hw, hri_nvic_nvicip71_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP71 ^= NVIC_NVICIP71_PRI71(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip71_reg_t hri_nvic_read_NVICIP71_PRI71_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP71;
	tmp = (tmp & NVIC_NVICIP71_PRI71_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP71_reg(const void *const hw, hri_nvic_nvicip71_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP71 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip71_reg_t hri_nvic_get_NVICIP71_reg(const void *const hw, hri_nvic_nvicip71_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP71;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP71_reg(const void *const hw, hri_nvic_nvicip71_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP71 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP71_reg(const void *const hw, hri_nvic_nvicip71_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP71 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP71_reg(const void *const hw, hri_nvic_nvicip71_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP71 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip71_reg_t hri_nvic_read_NVICIP71_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP71;
}

static inline void hri_nvic_set_NVICIP72_PRI72_bf(const void *const hw, hri_nvic_nvicip72_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP72 |= NVIC_NVICIP72_PRI72(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip72_reg_t hri_nvic_get_NVICIP72_PRI72_bf(const void *const hw, hri_nvic_nvicip72_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP72;
	tmp = (tmp & NVIC_NVICIP72_PRI72(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP72_PRI72_bf(const void *const hw, hri_nvic_nvicip72_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP72;
	tmp &= ~NVIC_NVICIP72_PRI72_Msk;
	tmp |= NVIC_NVICIP72_PRI72(data);
	((Nvic *)hw)->NVICIP72 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP72_PRI72_bf(const void *const hw, hri_nvic_nvicip72_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP72 &= ~NVIC_NVICIP72_PRI72(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP72_PRI72_bf(const void *const hw, hri_nvic_nvicip72_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP72 ^= NVIC_NVICIP72_PRI72(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip72_reg_t hri_nvic_read_NVICIP72_PRI72_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP72;
	tmp = (tmp & NVIC_NVICIP72_PRI72_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP72_reg(const void *const hw, hri_nvic_nvicip72_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP72 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip72_reg_t hri_nvic_get_NVICIP72_reg(const void *const hw, hri_nvic_nvicip72_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP72;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP72_reg(const void *const hw, hri_nvic_nvicip72_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP72 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP72_reg(const void *const hw, hri_nvic_nvicip72_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP72 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP72_reg(const void *const hw, hri_nvic_nvicip72_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP72 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip72_reg_t hri_nvic_read_NVICIP72_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP72;
}

static inline void hri_nvic_set_NVICIP73_PRI73_bf(const void *const hw, hri_nvic_nvicip73_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP73 |= NVIC_NVICIP73_PRI73(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip73_reg_t hri_nvic_get_NVICIP73_PRI73_bf(const void *const hw, hri_nvic_nvicip73_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP73;
	tmp = (tmp & NVIC_NVICIP73_PRI73(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP73_PRI73_bf(const void *const hw, hri_nvic_nvicip73_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP73;
	tmp &= ~NVIC_NVICIP73_PRI73_Msk;
	tmp |= NVIC_NVICIP73_PRI73(data);
	((Nvic *)hw)->NVICIP73 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP73_PRI73_bf(const void *const hw, hri_nvic_nvicip73_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP73 &= ~NVIC_NVICIP73_PRI73(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP73_PRI73_bf(const void *const hw, hri_nvic_nvicip73_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP73 ^= NVIC_NVICIP73_PRI73(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip73_reg_t hri_nvic_read_NVICIP73_PRI73_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP73;
	tmp = (tmp & NVIC_NVICIP73_PRI73_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP73_reg(const void *const hw, hri_nvic_nvicip73_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP73 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip73_reg_t hri_nvic_get_NVICIP73_reg(const void *const hw, hri_nvic_nvicip73_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP73;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP73_reg(const void *const hw, hri_nvic_nvicip73_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP73 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP73_reg(const void *const hw, hri_nvic_nvicip73_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP73 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP73_reg(const void *const hw, hri_nvic_nvicip73_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP73 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip73_reg_t hri_nvic_read_NVICIP73_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP73;
}

static inline void hri_nvic_set_NVICIP74_PRI74_bf(const void *const hw, hri_nvic_nvicip74_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP74 |= NVIC_NVICIP74_PRI74(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip74_reg_t hri_nvic_get_NVICIP74_PRI74_bf(const void *const hw, hri_nvic_nvicip74_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP74;
	tmp = (tmp & NVIC_NVICIP74_PRI74(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP74_PRI74_bf(const void *const hw, hri_nvic_nvicip74_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP74;
	tmp &= ~NVIC_NVICIP74_PRI74_Msk;
	tmp |= NVIC_NVICIP74_PRI74(data);
	((Nvic *)hw)->NVICIP74 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP74_PRI74_bf(const void *const hw, hri_nvic_nvicip74_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP74 &= ~NVIC_NVICIP74_PRI74(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP74_PRI74_bf(const void *const hw, hri_nvic_nvicip74_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP74 ^= NVIC_NVICIP74_PRI74(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip74_reg_t hri_nvic_read_NVICIP74_PRI74_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP74;
	tmp = (tmp & NVIC_NVICIP74_PRI74_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP74_reg(const void *const hw, hri_nvic_nvicip74_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP74 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip74_reg_t hri_nvic_get_NVICIP74_reg(const void *const hw, hri_nvic_nvicip74_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP74;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP74_reg(const void *const hw, hri_nvic_nvicip74_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP74 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP74_reg(const void *const hw, hri_nvic_nvicip74_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP74 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP74_reg(const void *const hw, hri_nvic_nvicip74_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP74 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip74_reg_t hri_nvic_read_NVICIP74_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP74;
}

static inline void hri_nvic_set_NVICIP75_PRI75_bf(const void *const hw, hri_nvic_nvicip75_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP75 |= NVIC_NVICIP75_PRI75(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip75_reg_t hri_nvic_get_NVICIP75_PRI75_bf(const void *const hw, hri_nvic_nvicip75_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP75;
	tmp = (tmp & NVIC_NVICIP75_PRI75(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP75_PRI75_bf(const void *const hw, hri_nvic_nvicip75_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP75;
	tmp &= ~NVIC_NVICIP75_PRI75_Msk;
	tmp |= NVIC_NVICIP75_PRI75(data);
	((Nvic *)hw)->NVICIP75 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP75_PRI75_bf(const void *const hw, hri_nvic_nvicip75_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP75 &= ~NVIC_NVICIP75_PRI75(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP75_PRI75_bf(const void *const hw, hri_nvic_nvicip75_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP75 ^= NVIC_NVICIP75_PRI75(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip75_reg_t hri_nvic_read_NVICIP75_PRI75_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP75;
	tmp = (tmp & NVIC_NVICIP75_PRI75_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP75_reg(const void *const hw, hri_nvic_nvicip75_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP75 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip75_reg_t hri_nvic_get_NVICIP75_reg(const void *const hw, hri_nvic_nvicip75_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP75;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP75_reg(const void *const hw, hri_nvic_nvicip75_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP75 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP75_reg(const void *const hw, hri_nvic_nvicip75_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP75 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP75_reg(const void *const hw, hri_nvic_nvicip75_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP75 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip75_reg_t hri_nvic_read_NVICIP75_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP75;
}

static inline void hri_nvic_set_NVICIP76_PRI76_bf(const void *const hw, hri_nvic_nvicip76_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP76 |= NVIC_NVICIP76_PRI76(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip76_reg_t hri_nvic_get_NVICIP76_PRI76_bf(const void *const hw, hri_nvic_nvicip76_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP76;
	tmp = (tmp & NVIC_NVICIP76_PRI76(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP76_PRI76_bf(const void *const hw, hri_nvic_nvicip76_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP76;
	tmp &= ~NVIC_NVICIP76_PRI76_Msk;
	tmp |= NVIC_NVICIP76_PRI76(data);
	((Nvic *)hw)->NVICIP76 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP76_PRI76_bf(const void *const hw, hri_nvic_nvicip76_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP76 &= ~NVIC_NVICIP76_PRI76(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP76_PRI76_bf(const void *const hw, hri_nvic_nvicip76_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP76 ^= NVIC_NVICIP76_PRI76(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip76_reg_t hri_nvic_read_NVICIP76_PRI76_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP76;
	tmp = (tmp & NVIC_NVICIP76_PRI76_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP76_reg(const void *const hw, hri_nvic_nvicip76_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP76 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip76_reg_t hri_nvic_get_NVICIP76_reg(const void *const hw, hri_nvic_nvicip76_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP76;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP76_reg(const void *const hw, hri_nvic_nvicip76_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP76 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP76_reg(const void *const hw, hri_nvic_nvicip76_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP76 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP76_reg(const void *const hw, hri_nvic_nvicip76_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP76 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip76_reg_t hri_nvic_read_NVICIP76_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP76;
}

static inline void hri_nvic_set_NVICIP77_PRI77_bf(const void *const hw, hri_nvic_nvicip77_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP77 |= NVIC_NVICIP77_PRI77(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip77_reg_t hri_nvic_get_NVICIP77_PRI77_bf(const void *const hw, hri_nvic_nvicip77_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP77;
	tmp = (tmp & NVIC_NVICIP77_PRI77(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP77_PRI77_bf(const void *const hw, hri_nvic_nvicip77_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP77;
	tmp &= ~NVIC_NVICIP77_PRI77_Msk;
	tmp |= NVIC_NVICIP77_PRI77(data);
	((Nvic *)hw)->NVICIP77 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP77_PRI77_bf(const void *const hw, hri_nvic_nvicip77_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP77 &= ~NVIC_NVICIP77_PRI77(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP77_PRI77_bf(const void *const hw, hri_nvic_nvicip77_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP77 ^= NVIC_NVICIP77_PRI77(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip77_reg_t hri_nvic_read_NVICIP77_PRI77_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP77;
	tmp = (tmp & NVIC_NVICIP77_PRI77_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP77_reg(const void *const hw, hri_nvic_nvicip77_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP77 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip77_reg_t hri_nvic_get_NVICIP77_reg(const void *const hw, hri_nvic_nvicip77_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP77;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP77_reg(const void *const hw, hri_nvic_nvicip77_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP77 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP77_reg(const void *const hw, hri_nvic_nvicip77_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP77 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP77_reg(const void *const hw, hri_nvic_nvicip77_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP77 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip77_reg_t hri_nvic_read_NVICIP77_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP77;
}

static inline void hri_nvic_set_NVICIP78_PRI78_bf(const void *const hw, hri_nvic_nvicip78_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP78 |= NVIC_NVICIP78_PRI78(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip78_reg_t hri_nvic_get_NVICIP78_PRI78_bf(const void *const hw, hri_nvic_nvicip78_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP78;
	tmp = (tmp & NVIC_NVICIP78_PRI78(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP78_PRI78_bf(const void *const hw, hri_nvic_nvicip78_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP78;
	tmp &= ~NVIC_NVICIP78_PRI78_Msk;
	tmp |= NVIC_NVICIP78_PRI78(data);
	((Nvic *)hw)->NVICIP78 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP78_PRI78_bf(const void *const hw, hri_nvic_nvicip78_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP78 &= ~NVIC_NVICIP78_PRI78(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP78_PRI78_bf(const void *const hw, hri_nvic_nvicip78_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP78 ^= NVIC_NVICIP78_PRI78(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip78_reg_t hri_nvic_read_NVICIP78_PRI78_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP78;
	tmp = (tmp & NVIC_NVICIP78_PRI78_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP78_reg(const void *const hw, hri_nvic_nvicip78_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP78 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip78_reg_t hri_nvic_get_NVICIP78_reg(const void *const hw, hri_nvic_nvicip78_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP78;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP78_reg(const void *const hw, hri_nvic_nvicip78_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP78 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP78_reg(const void *const hw, hri_nvic_nvicip78_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP78 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP78_reg(const void *const hw, hri_nvic_nvicip78_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP78 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip78_reg_t hri_nvic_read_NVICIP78_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP78;
}

static inline void hri_nvic_set_NVICIP79_PRI79_bf(const void *const hw, hri_nvic_nvicip79_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP79 |= NVIC_NVICIP79_PRI79(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip79_reg_t hri_nvic_get_NVICIP79_PRI79_bf(const void *const hw, hri_nvic_nvicip79_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP79;
	tmp = (tmp & NVIC_NVICIP79_PRI79(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP79_PRI79_bf(const void *const hw, hri_nvic_nvicip79_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP79;
	tmp &= ~NVIC_NVICIP79_PRI79_Msk;
	tmp |= NVIC_NVICIP79_PRI79(data);
	((Nvic *)hw)->NVICIP79 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP79_PRI79_bf(const void *const hw, hri_nvic_nvicip79_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP79 &= ~NVIC_NVICIP79_PRI79(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP79_PRI79_bf(const void *const hw, hri_nvic_nvicip79_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP79 ^= NVIC_NVICIP79_PRI79(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip79_reg_t hri_nvic_read_NVICIP79_PRI79_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP79;
	tmp = (tmp & NVIC_NVICIP79_PRI79_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP79_reg(const void *const hw, hri_nvic_nvicip79_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP79 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip79_reg_t hri_nvic_get_NVICIP79_reg(const void *const hw, hri_nvic_nvicip79_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP79;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP79_reg(const void *const hw, hri_nvic_nvicip79_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP79 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP79_reg(const void *const hw, hri_nvic_nvicip79_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP79 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP79_reg(const void *const hw, hri_nvic_nvicip79_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP79 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip79_reg_t hri_nvic_read_NVICIP79_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP79;
}

static inline void hri_nvic_set_NVICIP80_PRI80_bf(const void *const hw, hri_nvic_nvicip80_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP80 |= NVIC_NVICIP80_PRI80(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip80_reg_t hri_nvic_get_NVICIP80_PRI80_bf(const void *const hw, hri_nvic_nvicip80_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP80;
	tmp = (tmp & NVIC_NVICIP80_PRI80(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP80_PRI80_bf(const void *const hw, hri_nvic_nvicip80_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP80;
	tmp &= ~NVIC_NVICIP80_PRI80_Msk;
	tmp |= NVIC_NVICIP80_PRI80(data);
	((Nvic *)hw)->NVICIP80 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP80_PRI80_bf(const void *const hw, hri_nvic_nvicip80_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP80 &= ~NVIC_NVICIP80_PRI80(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP80_PRI80_bf(const void *const hw, hri_nvic_nvicip80_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP80 ^= NVIC_NVICIP80_PRI80(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip80_reg_t hri_nvic_read_NVICIP80_PRI80_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP80;
	tmp = (tmp & NVIC_NVICIP80_PRI80_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP80_reg(const void *const hw, hri_nvic_nvicip80_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP80 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip80_reg_t hri_nvic_get_NVICIP80_reg(const void *const hw, hri_nvic_nvicip80_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP80;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP80_reg(const void *const hw, hri_nvic_nvicip80_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP80 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP80_reg(const void *const hw, hri_nvic_nvicip80_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP80 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP80_reg(const void *const hw, hri_nvic_nvicip80_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP80 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip80_reg_t hri_nvic_read_NVICIP80_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP80;
}

static inline void hri_nvic_set_NVICIP81_PRI81_bf(const void *const hw, hri_nvic_nvicip81_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP81 |= NVIC_NVICIP81_PRI81(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip81_reg_t hri_nvic_get_NVICIP81_PRI81_bf(const void *const hw, hri_nvic_nvicip81_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP81;
	tmp = (tmp & NVIC_NVICIP81_PRI81(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP81_PRI81_bf(const void *const hw, hri_nvic_nvicip81_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP81;
	tmp &= ~NVIC_NVICIP81_PRI81_Msk;
	tmp |= NVIC_NVICIP81_PRI81(data);
	((Nvic *)hw)->NVICIP81 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP81_PRI81_bf(const void *const hw, hri_nvic_nvicip81_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP81 &= ~NVIC_NVICIP81_PRI81(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP81_PRI81_bf(const void *const hw, hri_nvic_nvicip81_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP81 ^= NVIC_NVICIP81_PRI81(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip81_reg_t hri_nvic_read_NVICIP81_PRI81_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP81;
	tmp = (tmp & NVIC_NVICIP81_PRI81_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP81_reg(const void *const hw, hri_nvic_nvicip81_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP81 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip81_reg_t hri_nvic_get_NVICIP81_reg(const void *const hw, hri_nvic_nvicip81_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP81;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP81_reg(const void *const hw, hri_nvic_nvicip81_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP81 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP81_reg(const void *const hw, hri_nvic_nvicip81_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP81 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP81_reg(const void *const hw, hri_nvic_nvicip81_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP81 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip81_reg_t hri_nvic_read_NVICIP81_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP81;
}

static inline void hri_nvic_set_NVICIP82_PRI82_bf(const void *const hw, hri_nvic_nvicip82_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP82 |= NVIC_NVICIP82_PRI82(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip82_reg_t hri_nvic_get_NVICIP82_PRI82_bf(const void *const hw, hri_nvic_nvicip82_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP82;
	tmp = (tmp & NVIC_NVICIP82_PRI82(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP82_PRI82_bf(const void *const hw, hri_nvic_nvicip82_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP82;
	tmp &= ~NVIC_NVICIP82_PRI82_Msk;
	tmp |= NVIC_NVICIP82_PRI82(data);
	((Nvic *)hw)->NVICIP82 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP82_PRI82_bf(const void *const hw, hri_nvic_nvicip82_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP82 &= ~NVIC_NVICIP82_PRI82(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP82_PRI82_bf(const void *const hw, hri_nvic_nvicip82_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP82 ^= NVIC_NVICIP82_PRI82(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip82_reg_t hri_nvic_read_NVICIP82_PRI82_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP82;
	tmp = (tmp & NVIC_NVICIP82_PRI82_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP82_reg(const void *const hw, hri_nvic_nvicip82_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP82 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip82_reg_t hri_nvic_get_NVICIP82_reg(const void *const hw, hri_nvic_nvicip82_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP82;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP82_reg(const void *const hw, hri_nvic_nvicip82_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP82 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP82_reg(const void *const hw, hri_nvic_nvicip82_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP82 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP82_reg(const void *const hw, hri_nvic_nvicip82_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP82 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip82_reg_t hri_nvic_read_NVICIP82_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP82;
}

static inline void hri_nvic_set_NVICIP83_PRI83_bf(const void *const hw, hri_nvic_nvicip83_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP83 |= NVIC_NVICIP83_PRI83(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip83_reg_t hri_nvic_get_NVICIP83_PRI83_bf(const void *const hw, hri_nvic_nvicip83_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP83;
	tmp = (tmp & NVIC_NVICIP83_PRI83(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP83_PRI83_bf(const void *const hw, hri_nvic_nvicip83_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP83;
	tmp &= ~NVIC_NVICIP83_PRI83_Msk;
	tmp |= NVIC_NVICIP83_PRI83(data);
	((Nvic *)hw)->NVICIP83 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP83_PRI83_bf(const void *const hw, hri_nvic_nvicip83_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP83 &= ~NVIC_NVICIP83_PRI83(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP83_PRI83_bf(const void *const hw, hri_nvic_nvicip83_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP83 ^= NVIC_NVICIP83_PRI83(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip83_reg_t hri_nvic_read_NVICIP83_PRI83_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP83;
	tmp = (tmp & NVIC_NVICIP83_PRI83_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP83_reg(const void *const hw, hri_nvic_nvicip83_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP83 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip83_reg_t hri_nvic_get_NVICIP83_reg(const void *const hw, hri_nvic_nvicip83_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP83;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP83_reg(const void *const hw, hri_nvic_nvicip83_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP83 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP83_reg(const void *const hw, hri_nvic_nvicip83_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP83 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP83_reg(const void *const hw, hri_nvic_nvicip83_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP83 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip83_reg_t hri_nvic_read_NVICIP83_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP83;
}

static inline void hri_nvic_set_NVICIP84_PRI84_bf(const void *const hw, hri_nvic_nvicip84_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP84 |= NVIC_NVICIP84_PRI84(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip84_reg_t hri_nvic_get_NVICIP84_PRI84_bf(const void *const hw, hri_nvic_nvicip84_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP84;
	tmp = (tmp & NVIC_NVICIP84_PRI84(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP84_PRI84_bf(const void *const hw, hri_nvic_nvicip84_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP84;
	tmp &= ~NVIC_NVICIP84_PRI84_Msk;
	tmp |= NVIC_NVICIP84_PRI84(data);
	((Nvic *)hw)->NVICIP84 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP84_PRI84_bf(const void *const hw, hri_nvic_nvicip84_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP84 &= ~NVIC_NVICIP84_PRI84(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP84_PRI84_bf(const void *const hw, hri_nvic_nvicip84_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP84 ^= NVIC_NVICIP84_PRI84(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip84_reg_t hri_nvic_read_NVICIP84_PRI84_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP84;
	tmp = (tmp & NVIC_NVICIP84_PRI84_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP84_reg(const void *const hw, hri_nvic_nvicip84_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP84 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip84_reg_t hri_nvic_get_NVICIP84_reg(const void *const hw, hri_nvic_nvicip84_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP84;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP84_reg(const void *const hw, hri_nvic_nvicip84_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP84 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP84_reg(const void *const hw, hri_nvic_nvicip84_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP84 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP84_reg(const void *const hw, hri_nvic_nvicip84_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP84 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip84_reg_t hri_nvic_read_NVICIP84_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP84;
}

static inline void hri_nvic_set_NVICIP85_PRI85_bf(const void *const hw, hri_nvic_nvicip85_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP85 |= NVIC_NVICIP85_PRI85(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip85_reg_t hri_nvic_get_NVICIP85_PRI85_bf(const void *const hw, hri_nvic_nvicip85_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP85;
	tmp = (tmp & NVIC_NVICIP85_PRI85(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP85_PRI85_bf(const void *const hw, hri_nvic_nvicip85_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP85;
	tmp &= ~NVIC_NVICIP85_PRI85_Msk;
	tmp |= NVIC_NVICIP85_PRI85(data);
	((Nvic *)hw)->NVICIP85 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP85_PRI85_bf(const void *const hw, hri_nvic_nvicip85_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP85 &= ~NVIC_NVICIP85_PRI85(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP85_PRI85_bf(const void *const hw, hri_nvic_nvicip85_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP85 ^= NVIC_NVICIP85_PRI85(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip85_reg_t hri_nvic_read_NVICIP85_PRI85_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP85;
	tmp = (tmp & NVIC_NVICIP85_PRI85_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP85_reg(const void *const hw, hri_nvic_nvicip85_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP85 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip85_reg_t hri_nvic_get_NVICIP85_reg(const void *const hw, hri_nvic_nvicip85_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP85;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP85_reg(const void *const hw, hri_nvic_nvicip85_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP85 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP85_reg(const void *const hw, hri_nvic_nvicip85_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP85 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP85_reg(const void *const hw, hri_nvic_nvicip85_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP85 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip85_reg_t hri_nvic_read_NVICIP85_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP85;
}

static inline void hri_nvic_set_NVICIP86_PRI86_bf(const void *const hw, hri_nvic_nvicip86_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP86 |= NVIC_NVICIP86_PRI86(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip86_reg_t hri_nvic_get_NVICIP86_PRI86_bf(const void *const hw, hri_nvic_nvicip86_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP86;
	tmp = (tmp & NVIC_NVICIP86_PRI86(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP86_PRI86_bf(const void *const hw, hri_nvic_nvicip86_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP86;
	tmp &= ~NVIC_NVICIP86_PRI86_Msk;
	tmp |= NVIC_NVICIP86_PRI86(data);
	((Nvic *)hw)->NVICIP86 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP86_PRI86_bf(const void *const hw, hri_nvic_nvicip86_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP86 &= ~NVIC_NVICIP86_PRI86(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP86_PRI86_bf(const void *const hw, hri_nvic_nvicip86_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP86 ^= NVIC_NVICIP86_PRI86(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip86_reg_t hri_nvic_read_NVICIP86_PRI86_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP86;
	tmp = (tmp & NVIC_NVICIP86_PRI86_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP86_reg(const void *const hw, hri_nvic_nvicip86_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP86 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip86_reg_t hri_nvic_get_NVICIP86_reg(const void *const hw, hri_nvic_nvicip86_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP86;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP86_reg(const void *const hw, hri_nvic_nvicip86_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP86 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP86_reg(const void *const hw, hri_nvic_nvicip86_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP86 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP86_reg(const void *const hw, hri_nvic_nvicip86_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP86 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip86_reg_t hri_nvic_read_NVICIP86_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP86;
}

static inline void hri_nvic_set_NVICIP87_PRI87_bf(const void *const hw, hri_nvic_nvicip87_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP87 |= NVIC_NVICIP87_PRI87(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip87_reg_t hri_nvic_get_NVICIP87_PRI87_bf(const void *const hw, hri_nvic_nvicip87_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP87;
	tmp = (tmp & NVIC_NVICIP87_PRI87(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP87_PRI87_bf(const void *const hw, hri_nvic_nvicip87_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP87;
	tmp &= ~NVIC_NVICIP87_PRI87_Msk;
	tmp |= NVIC_NVICIP87_PRI87(data);
	((Nvic *)hw)->NVICIP87 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP87_PRI87_bf(const void *const hw, hri_nvic_nvicip87_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP87 &= ~NVIC_NVICIP87_PRI87(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP87_PRI87_bf(const void *const hw, hri_nvic_nvicip87_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP87 ^= NVIC_NVICIP87_PRI87(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip87_reg_t hri_nvic_read_NVICIP87_PRI87_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP87;
	tmp = (tmp & NVIC_NVICIP87_PRI87_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP87_reg(const void *const hw, hri_nvic_nvicip87_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP87 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip87_reg_t hri_nvic_get_NVICIP87_reg(const void *const hw, hri_nvic_nvicip87_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP87;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP87_reg(const void *const hw, hri_nvic_nvicip87_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP87 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP87_reg(const void *const hw, hri_nvic_nvicip87_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP87 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP87_reg(const void *const hw, hri_nvic_nvicip87_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP87 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip87_reg_t hri_nvic_read_NVICIP87_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP87;
}

static inline void hri_nvic_set_NVICIP88_PRI88_bf(const void *const hw, hri_nvic_nvicip88_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP88 |= NVIC_NVICIP88_PRI88(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip88_reg_t hri_nvic_get_NVICIP88_PRI88_bf(const void *const hw, hri_nvic_nvicip88_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP88;
	tmp = (tmp & NVIC_NVICIP88_PRI88(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP88_PRI88_bf(const void *const hw, hri_nvic_nvicip88_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP88;
	tmp &= ~NVIC_NVICIP88_PRI88_Msk;
	tmp |= NVIC_NVICIP88_PRI88(data);
	((Nvic *)hw)->NVICIP88 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP88_PRI88_bf(const void *const hw, hri_nvic_nvicip88_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP88 &= ~NVIC_NVICIP88_PRI88(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP88_PRI88_bf(const void *const hw, hri_nvic_nvicip88_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP88 ^= NVIC_NVICIP88_PRI88(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip88_reg_t hri_nvic_read_NVICIP88_PRI88_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP88;
	tmp = (tmp & NVIC_NVICIP88_PRI88_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP88_reg(const void *const hw, hri_nvic_nvicip88_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP88 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip88_reg_t hri_nvic_get_NVICIP88_reg(const void *const hw, hri_nvic_nvicip88_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP88;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP88_reg(const void *const hw, hri_nvic_nvicip88_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP88 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP88_reg(const void *const hw, hri_nvic_nvicip88_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP88 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP88_reg(const void *const hw, hri_nvic_nvicip88_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP88 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip88_reg_t hri_nvic_read_NVICIP88_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP88;
}

static inline void hri_nvic_set_NVICIP89_PRI89_bf(const void *const hw, hri_nvic_nvicip89_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP89 |= NVIC_NVICIP89_PRI89(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip89_reg_t hri_nvic_get_NVICIP89_PRI89_bf(const void *const hw, hri_nvic_nvicip89_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP89;
	tmp = (tmp & NVIC_NVICIP89_PRI89(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP89_PRI89_bf(const void *const hw, hri_nvic_nvicip89_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP89;
	tmp &= ~NVIC_NVICIP89_PRI89_Msk;
	tmp |= NVIC_NVICIP89_PRI89(data);
	((Nvic *)hw)->NVICIP89 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP89_PRI89_bf(const void *const hw, hri_nvic_nvicip89_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP89 &= ~NVIC_NVICIP89_PRI89(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP89_PRI89_bf(const void *const hw, hri_nvic_nvicip89_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP89 ^= NVIC_NVICIP89_PRI89(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip89_reg_t hri_nvic_read_NVICIP89_PRI89_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP89;
	tmp = (tmp & NVIC_NVICIP89_PRI89_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP89_reg(const void *const hw, hri_nvic_nvicip89_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP89 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip89_reg_t hri_nvic_get_NVICIP89_reg(const void *const hw, hri_nvic_nvicip89_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP89;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP89_reg(const void *const hw, hri_nvic_nvicip89_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP89 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP89_reg(const void *const hw, hri_nvic_nvicip89_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP89 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP89_reg(const void *const hw, hri_nvic_nvicip89_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP89 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip89_reg_t hri_nvic_read_NVICIP89_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP89;
}

static inline void hri_nvic_set_NVICIP90_PRI90_bf(const void *const hw, hri_nvic_nvicip90_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP90 |= NVIC_NVICIP90_PRI90(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip90_reg_t hri_nvic_get_NVICIP90_PRI90_bf(const void *const hw, hri_nvic_nvicip90_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP90;
	tmp = (tmp & NVIC_NVICIP90_PRI90(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP90_PRI90_bf(const void *const hw, hri_nvic_nvicip90_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP90;
	tmp &= ~NVIC_NVICIP90_PRI90_Msk;
	tmp |= NVIC_NVICIP90_PRI90(data);
	((Nvic *)hw)->NVICIP90 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP90_PRI90_bf(const void *const hw, hri_nvic_nvicip90_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP90 &= ~NVIC_NVICIP90_PRI90(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP90_PRI90_bf(const void *const hw, hri_nvic_nvicip90_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP90 ^= NVIC_NVICIP90_PRI90(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip90_reg_t hri_nvic_read_NVICIP90_PRI90_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP90;
	tmp = (tmp & NVIC_NVICIP90_PRI90_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP90_reg(const void *const hw, hri_nvic_nvicip90_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP90 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip90_reg_t hri_nvic_get_NVICIP90_reg(const void *const hw, hri_nvic_nvicip90_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP90;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP90_reg(const void *const hw, hri_nvic_nvicip90_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP90 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP90_reg(const void *const hw, hri_nvic_nvicip90_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP90 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP90_reg(const void *const hw, hri_nvic_nvicip90_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP90 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip90_reg_t hri_nvic_read_NVICIP90_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP90;
}

static inline void hri_nvic_set_NVICIP91_PRI91_bf(const void *const hw, hri_nvic_nvicip91_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP91 |= NVIC_NVICIP91_PRI91(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip91_reg_t hri_nvic_get_NVICIP91_PRI91_bf(const void *const hw, hri_nvic_nvicip91_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP91;
	tmp = (tmp & NVIC_NVICIP91_PRI91(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP91_PRI91_bf(const void *const hw, hri_nvic_nvicip91_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP91;
	tmp &= ~NVIC_NVICIP91_PRI91_Msk;
	tmp |= NVIC_NVICIP91_PRI91(data);
	((Nvic *)hw)->NVICIP91 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP91_PRI91_bf(const void *const hw, hri_nvic_nvicip91_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP91 &= ~NVIC_NVICIP91_PRI91(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP91_PRI91_bf(const void *const hw, hri_nvic_nvicip91_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP91 ^= NVIC_NVICIP91_PRI91(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip91_reg_t hri_nvic_read_NVICIP91_PRI91_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP91;
	tmp = (tmp & NVIC_NVICIP91_PRI91_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP91_reg(const void *const hw, hri_nvic_nvicip91_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP91 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip91_reg_t hri_nvic_get_NVICIP91_reg(const void *const hw, hri_nvic_nvicip91_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP91;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP91_reg(const void *const hw, hri_nvic_nvicip91_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP91 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP91_reg(const void *const hw, hri_nvic_nvicip91_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP91 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP91_reg(const void *const hw, hri_nvic_nvicip91_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP91 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip91_reg_t hri_nvic_read_NVICIP91_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP91;
}

static inline void hri_nvic_set_NVICIP92_PRI92_bf(const void *const hw, hri_nvic_nvicip92_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP92 |= NVIC_NVICIP92_PRI92(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip92_reg_t hri_nvic_get_NVICIP92_PRI92_bf(const void *const hw, hri_nvic_nvicip92_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP92;
	tmp = (tmp & NVIC_NVICIP92_PRI92(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP92_PRI92_bf(const void *const hw, hri_nvic_nvicip92_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP92;
	tmp &= ~NVIC_NVICIP92_PRI92_Msk;
	tmp |= NVIC_NVICIP92_PRI92(data);
	((Nvic *)hw)->NVICIP92 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP92_PRI92_bf(const void *const hw, hri_nvic_nvicip92_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP92 &= ~NVIC_NVICIP92_PRI92(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP92_PRI92_bf(const void *const hw, hri_nvic_nvicip92_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP92 ^= NVIC_NVICIP92_PRI92(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip92_reg_t hri_nvic_read_NVICIP92_PRI92_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP92;
	tmp = (tmp & NVIC_NVICIP92_PRI92_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP92_reg(const void *const hw, hri_nvic_nvicip92_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP92 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip92_reg_t hri_nvic_get_NVICIP92_reg(const void *const hw, hri_nvic_nvicip92_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP92;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP92_reg(const void *const hw, hri_nvic_nvicip92_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP92 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP92_reg(const void *const hw, hri_nvic_nvicip92_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP92 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP92_reg(const void *const hw, hri_nvic_nvicip92_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP92 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip92_reg_t hri_nvic_read_NVICIP92_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP92;
}

static inline void hri_nvic_set_NVICIP93_PRI93_bf(const void *const hw, hri_nvic_nvicip93_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP93 |= NVIC_NVICIP93_PRI93(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip93_reg_t hri_nvic_get_NVICIP93_PRI93_bf(const void *const hw, hri_nvic_nvicip93_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP93;
	tmp = (tmp & NVIC_NVICIP93_PRI93(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP93_PRI93_bf(const void *const hw, hri_nvic_nvicip93_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP93;
	tmp &= ~NVIC_NVICIP93_PRI93_Msk;
	tmp |= NVIC_NVICIP93_PRI93(data);
	((Nvic *)hw)->NVICIP93 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP93_PRI93_bf(const void *const hw, hri_nvic_nvicip93_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP93 &= ~NVIC_NVICIP93_PRI93(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP93_PRI93_bf(const void *const hw, hri_nvic_nvicip93_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP93 ^= NVIC_NVICIP93_PRI93(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip93_reg_t hri_nvic_read_NVICIP93_PRI93_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP93;
	tmp = (tmp & NVIC_NVICIP93_PRI93_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP93_reg(const void *const hw, hri_nvic_nvicip93_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP93 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip93_reg_t hri_nvic_get_NVICIP93_reg(const void *const hw, hri_nvic_nvicip93_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP93;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP93_reg(const void *const hw, hri_nvic_nvicip93_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP93 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP93_reg(const void *const hw, hri_nvic_nvicip93_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP93 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP93_reg(const void *const hw, hri_nvic_nvicip93_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP93 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip93_reg_t hri_nvic_read_NVICIP93_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP93;
}

static inline void hri_nvic_set_NVICIP94_PRI94_bf(const void *const hw, hri_nvic_nvicip94_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP94 |= NVIC_NVICIP94_PRI94(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip94_reg_t hri_nvic_get_NVICIP94_PRI94_bf(const void *const hw, hri_nvic_nvicip94_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP94;
	tmp = (tmp & NVIC_NVICIP94_PRI94(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP94_PRI94_bf(const void *const hw, hri_nvic_nvicip94_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP94;
	tmp &= ~NVIC_NVICIP94_PRI94_Msk;
	tmp |= NVIC_NVICIP94_PRI94(data);
	((Nvic *)hw)->NVICIP94 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP94_PRI94_bf(const void *const hw, hri_nvic_nvicip94_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP94 &= ~NVIC_NVICIP94_PRI94(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP94_PRI94_bf(const void *const hw, hri_nvic_nvicip94_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP94 ^= NVIC_NVICIP94_PRI94(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip94_reg_t hri_nvic_read_NVICIP94_PRI94_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP94;
	tmp = (tmp & NVIC_NVICIP94_PRI94_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP94_reg(const void *const hw, hri_nvic_nvicip94_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP94 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip94_reg_t hri_nvic_get_NVICIP94_reg(const void *const hw, hri_nvic_nvicip94_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP94;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP94_reg(const void *const hw, hri_nvic_nvicip94_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP94 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP94_reg(const void *const hw, hri_nvic_nvicip94_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP94 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP94_reg(const void *const hw, hri_nvic_nvicip94_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP94 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip94_reg_t hri_nvic_read_NVICIP94_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP94;
}

static inline void hri_nvic_set_NVICIP95_PRI95_bf(const void *const hw, hri_nvic_nvicip95_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP95 |= NVIC_NVICIP95_PRI95(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip95_reg_t hri_nvic_get_NVICIP95_PRI95_bf(const void *const hw, hri_nvic_nvicip95_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP95;
	tmp = (tmp & NVIC_NVICIP95_PRI95(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP95_PRI95_bf(const void *const hw, hri_nvic_nvicip95_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP95;
	tmp &= ~NVIC_NVICIP95_PRI95_Msk;
	tmp |= NVIC_NVICIP95_PRI95(data);
	((Nvic *)hw)->NVICIP95 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP95_PRI95_bf(const void *const hw, hri_nvic_nvicip95_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP95 &= ~NVIC_NVICIP95_PRI95(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP95_PRI95_bf(const void *const hw, hri_nvic_nvicip95_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP95 ^= NVIC_NVICIP95_PRI95(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip95_reg_t hri_nvic_read_NVICIP95_PRI95_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP95;
	tmp = (tmp & NVIC_NVICIP95_PRI95_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP95_reg(const void *const hw, hri_nvic_nvicip95_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP95 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip95_reg_t hri_nvic_get_NVICIP95_reg(const void *const hw, hri_nvic_nvicip95_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP95;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP95_reg(const void *const hw, hri_nvic_nvicip95_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP95 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP95_reg(const void *const hw, hri_nvic_nvicip95_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP95 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP95_reg(const void *const hw, hri_nvic_nvicip95_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP95 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip95_reg_t hri_nvic_read_NVICIP95_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP95;
}

static inline void hri_nvic_set_NVICIP96_PRI96_bf(const void *const hw, hri_nvic_nvicip96_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP96 |= NVIC_NVICIP96_PRI96(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip96_reg_t hri_nvic_get_NVICIP96_PRI96_bf(const void *const hw, hri_nvic_nvicip96_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP96;
	tmp = (tmp & NVIC_NVICIP96_PRI96(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP96_PRI96_bf(const void *const hw, hri_nvic_nvicip96_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP96;
	tmp &= ~NVIC_NVICIP96_PRI96_Msk;
	tmp |= NVIC_NVICIP96_PRI96(data);
	((Nvic *)hw)->NVICIP96 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP96_PRI96_bf(const void *const hw, hri_nvic_nvicip96_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP96 &= ~NVIC_NVICIP96_PRI96(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP96_PRI96_bf(const void *const hw, hri_nvic_nvicip96_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP96 ^= NVIC_NVICIP96_PRI96(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip96_reg_t hri_nvic_read_NVICIP96_PRI96_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP96;
	tmp = (tmp & NVIC_NVICIP96_PRI96_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP96_reg(const void *const hw, hri_nvic_nvicip96_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP96 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip96_reg_t hri_nvic_get_NVICIP96_reg(const void *const hw, hri_nvic_nvicip96_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP96;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP96_reg(const void *const hw, hri_nvic_nvicip96_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP96 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP96_reg(const void *const hw, hri_nvic_nvicip96_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP96 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP96_reg(const void *const hw, hri_nvic_nvicip96_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP96 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip96_reg_t hri_nvic_read_NVICIP96_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP96;
}

static inline void hri_nvic_set_NVICIP97_PRI97_bf(const void *const hw, hri_nvic_nvicip97_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP97 |= NVIC_NVICIP97_PRI97(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip97_reg_t hri_nvic_get_NVICIP97_PRI97_bf(const void *const hw, hri_nvic_nvicip97_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP97;
	tmp = (tmp & NVIC_NVICIP97_PRI97(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP97_PRI97_bf(const void *const hw, hri_nvic_nvicip97_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP97;
	tmp &= ~NVIC_NVICIP97_PRI97_Msk;
	tmp |= NVIC_NVICIP97_PRI97(data);
	((Nvic *)hw)->NVICIP97 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP97_PRI97_bf(const void *const hw, hri_nvic_nvicip97_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP97 &= ~NVIC_NVICIP97_PRI97(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP97_PRI97_bf(const void *const hw, hri_nvic_nvicip97_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP97 ^= NVIC_NVICIP97_PRI97(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip97_reg_t hri_nvic_read_NVICIP97_PRI97_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP97;
	tmp = (tmp & NVIC_NVICIP97_PRI97_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP97_reg(const void *const hw, hri_nvic_nvicip97_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP97 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip97_reg_t hri_nvic_get_NVICIP97_reg(const void *const hw, hri_nvic_nvicip97_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP97;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP97_reg(const void *const hw, hri_nvic_nvicip97_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP97 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP97_reg(const void *const hw, hri_nvic_nvicip97_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP97 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP97_reg(const void *const hw, hri_nvic_nvicip97_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP97 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip97_reg_t hri_nvic_read_NVICIP97_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP97;
}

static inline void hri_nvic_set_NVICIP98_PRI98_bf(const void *const hw, hri_nvic_nvicip98_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP98 |= NVIC_NVICIP98_PRI98(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip98_reg_t hri_nvic_get_NVICIP98_PRI98_bf(const void *const hw, hri_nvic_nvicip98_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP98;
	tmp = (tmp & NVIC_NVICIP98_PRI98(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP98_PRI98_bf(const void *const hw, hri_nvic_nvicip98_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP98;
	tmp &= ~NVIC_NVICIP98_PRI98_Msk;
	tmp |= NVIC_NVICIP98_PRI98(data);
	((Nvic *)hw)->NVICIP98 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP98_PRI98_bf(const void *const hw, hri_nvic_nvicip98_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP98 &= ~NVIC_NVICIP98_PRI98(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP98_PRI98_bf(const void *const hw, hri_nvic_nvicip98_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP98 ^= NVIC_NVICIP98_PRI98(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip98_reg_t hri_nvic_read_NVICIP98_PRI98_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP98;
	tmp = (tmp & NVIC_NVICIP98_PRI98_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP98_reg(const void *const hw, hri_nvic_nvicip98_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP98 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip98_reg_t hri_nvic_get_NVICIP98_reg(const void *const hw, hri_nvic_nvicip98_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP98;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP98_reg(const void *const hw, hri_nvic_nvicip98_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP98 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP98_reg(const void *const hw, hri_nvic_nvicip98_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP98 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP98_reg(const void *const hw, hri_nvic_nvicip98_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP98 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip98_reg_t hri_nvic_read_NVICIP98_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP98;
}

static inline void hri_nvic_set_NVICIP99_PRI99_bf(const void *const hw, hri_nvic_nvicip99_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP99 |= NVIC_NVICIP99_PRI99(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip99_reg_t hri_nvic_get_NVICIP99_PRI99_bf(const void *const hw, hri_nvic_nvicip99_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP99;
	tmp = (tmp & NVIC_NVICIP99_PRI99(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP99_PRI99_bf(const void *const hw, hri_nvic_nvicip99_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP99;
	tmp &= ~NVIC_NVICIP99_PRI99_Msk;
	tmp |= NVIC_NVICIP99_PRI99(data);
	((Nvic *)hw)->NVICIP99 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP99_PRI99_bf(const void *const hw, hri_nvic_nvicip99_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP99 &= ~NVIC_NVICIP99_PRI99(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP99_PRI99_bf(const void *const hw, hri_nvic_nvicip99_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP99 ^= NVIC_NVICIP99_PRI99(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip99_reg_t hri_nvic_read_NVICIP99_PRI99_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP99;
	tmp = (tmp & NVIC_NVICIP99_PRI99_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP99_reg(const void *const hw, hri_nvic_nvicip99_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP99 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip99_reg_t hri_nvic_get_NVICIP99_reg(const void *const hw, hri_nvic_nvicip99_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP99;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP99_reg(const void *const hw, hri_nvic_nvicip99_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP99 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP99_reg(const void *const hw, hri_nvic_nvicip99_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP99 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP99_reg(const void *const hw, hri_nvic_nvicip99_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP99 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip99_reg_t hri_nvic_read_NVICIP99_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP99;
}

static inline void hri_nvic_set_NVICIP100_PRI100_bf(const void *const hw, hri_nvic_nvicip100_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP100 |= NVIC_NVICIP100_PRI100(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip100_reg_t hri_nvic_get_NVICIP100_PRI100_bf(const void *const        hw,
                                                                        hri_nvic_nvicip100_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP100;
	tmp = (tmp & NVIC_NVICIP100_PRI100(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP100_PRI100_bf(const void *const hw, hri_nvic_nvicip100_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP100;
	tmp &= ~NVIC_NVICIP100_PRI100_Msk;
	tmp |= NVIC_NVICIP100_PRI100(data);
	((Nvic *)hw)->NVICIP100 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP100_PRI100_bf(const void *const hw, hri_nvic_nvicip100_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP100 &= ~NVIC_NVICIP100_PRI100(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP100_PRI100_bf(const void *const hw, hri_nvic_nvicip100_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP100 ^= NVIC_NVICIP100_PRI100(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip100_reg_t hri_nvic_read_NVICIP100_PRI100_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP100;
	tmp = (tmp & NVIC_NVICIP100_PRI100_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP100_reg(const void *const hw, hri_nvic_nvicip100_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP100 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip100_reg_t hri_nvic_get_NVICIP100_reg(const void *const hw, hri_nvic_nvicip100_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP100;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP100_reg(const void *const hw, hri_nvic_nvicip100_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP100 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP100_reg(const void *const hw, hri_nvic_nvicip100_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP100 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP100_reg(const void *const hw, hri_nvic_nvicip100_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP100 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip100_reg_t hri_nvic_read_NVICIP100_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP100;
}

static inline void hri_nvic_set_NVICIP101_PRI101_bf(const void *const hw, hri_nvic_nvicip101_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP101 |= NVIC_NVICIP101_PRI101(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip101_reg_t hri_nvic_get_NVICIP101_PRI101_bf(const void *const        hw,
                                                                        hri_nvic_nvicip101_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP101;
	tmp = (tmp & NVIC_NVICIP101_PRI101(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP101_PRI101_bf(const void *const hw, hri_nvic_nvicip101_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP101;
	tmp &= ~NVIC_NVICIP101_PRI101_Msk;
	tmp |= NVIC_NVICIP101_PRI101(data);
	((Nvic *)hw)->NVICIP101 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP101_PRI101_bf(const void *const hw, hri_nvic_nvicip101_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP101 &= ~NVIC_NVICIP101_PRI101(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP101_PRI101_bf(const void *const hw, hri_nvic_nvicip101_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP101 ^= NVIC_NVICIP101_PRI101(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip101_reg_t hri_nvic_read_NVICIP101_PRI101_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP101;
	tmp = (tmp & NVIC_NVICIP101_PRI101_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP101_reg(const void *const hw, hri_nvic_nvicip101_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP101 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip101_reg_t hri_nvic_get_NVICIP101_reg(const void *const hw, hri_nvic_nvicip101_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP101;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP101_reg(const void *const hw, hri_nvic_nvicip101_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP101 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP101_reg(const void *const hw, hri_nvic_nvicip101_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP101 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP101_reg(const void *const hw, hri_nvic_nvicip101_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP101 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip101_reg_t hri_nvic_read_NVICIP101_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP101;
}

static inline void hri_nvic_set_NVICIP102_PRI102_bf(const void *const hw, hri_nvic_nvicip102_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP102 |= NVIC_NVICIP102_PRI102(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip102_reg_t hri_nvic_get_NVICIP102_PRI102_bf(const void *const        hw,
                                                                        hri_nvic_nvicip102_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP102;
	tmp = (tmp & NVIC_NVICIP102_PRI102(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP102_PRI102_bf(const void *const hw, hri_nvic_nvicip102_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP102;
	tmp &= ~NVIC_NVICIP102_PRI102_Msk;
	tmp |= NVIC_NVICIP102_PRI102(data);
	((Nvic *)hw)->NVICIP102 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP102_PRI102_bf(const void *const hw, hri_nvic_nvicip102_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP102 &= ~NVIC_NVICIP102_PRI102(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP102_PRI102_bf(const void *const hw, hri_nvic_nvicip102_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP102 ^= NVIC_NVICIP102_PRI102(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip102_reg_t hri_nvic_read_NVICIP102_PRI102_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP102;
	tmp = (tmp & NVIC_NVICIP102_PRI102_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP102_reg(const void *const hw, hri_nvic_nvicip102_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP102 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip102_reg_t hri_nvic_get_NVICIP102_reg(const void *const hw, hri_nvic_nvicip102_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP102;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP102_reg(const void *const hw, hri_nvic_nvicip102_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP102 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP102_reg(const void *const hw, hri_nvic_nvicip102_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP102 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP102_reg(const void *const hw, hri_nvic_nvicip102_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP102 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip102_reg_t hri_nvic_read_NVICIP102_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP102;
}

static inline void hri_nvic_set_NVICIP103_PRI103_bf(const void *const hw, hri_nvic_nvicip103_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP103 |= NVIC_NVICIP103_PRI103(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip103_reg_t hri_nvic_get_NVICIP103_PRI103_bf(const void *const        hw,
                                                                        hri_nvic_nvicip103_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP103;
	tmp = (tmp & NVIC_NVICIP103_PRI103(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP103_PRI103_bf(const void *const hw, hri_nvic_nvicip103_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP103;
	tmp &= ~NVIC_NVICIP103_PRI103_Msk;
	tmp |= NVIC_NVICIP103_PRI103(data);
	((Nvic *)hw)->NVICIP103 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP103_PRI103_bf(const void *const hw, hri_nvic_nvicip103_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP103 &= ~NVIC_NVICIP103_PRI103(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP103_PRI103_bf(const void *const hw, hri_nvic_nvicip103_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP103 ^= NVIC_NVICIP103_PRI103(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip103_reg_t hri_nvic_read_NVICIP103_PRI103_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP103;
	tmp = (tmp & NVIC_NVICIP103_PRI103_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP103_reg(const void *const hw, hri_nvic_nvicip103_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP103 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip103_reg_t hri_nvic_get_NVICIP103_reg(const void *const hw, hri_nvic_nvicip103_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP103;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP103_reg(const void *const hw, hri_nvic_nvicip103_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP103 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP103_reg(const void *const hw, hri_nvic_nvicip103_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP103 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP103_reg(const void *const hw, hri_nvic_nvicip103_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP103 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip103_reg_t hri_nvic_read_NVICIP103_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP103;
}

static inline void hri_nvic_set_NVICIP104_PRI104_bf(const void *const hw, hri_nvic_nvicip104_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP104 |= NVIC_NVICIP104_PRI104(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip104_reg_t hri_nvic_get_NVICIP104_PRI104_bf(const void *const        hw,
                                                                        hri_nvic_nvicip104_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP104;
	tmp = (tmp & NVIC_NVICIP104_PRI104(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP104_PRI104_bf(const void *const hw, hri_nvic_nvicip104_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP104;
	tmp &= ~NVIC_NVICIP104_PRI104_Msk;
	tmp |= NVIC_NVICIP104_PRI104(data);
	((Nvic *)hw)->NVICIP104 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP104_PRI104_bf(const void *const hw, hri_nvic_nvicip104_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP104 &= ~NVIC_NVICIP104_PRI104(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP104_PRI104_bf(const void *const hw, hri_nvic_nvicip104_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP104 ^= NVIC_NVICIP104_PRI104(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip104_reg_t hri_nvic_read_NVICIP104_PRI104_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP104;
	tmp = (tmp & NVIC_NVICIP104_PRI104_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP104_reg(const void *const hw, hri_nvic_nvicip104_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP104 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip104_reg_t hri_nvic_get_NVICIP104_reg(const void *const hw, hri_nvic_nvicip104_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP104;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP104_reg(const void *const hw, hri_nvic_nvicip104_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP104 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP104_reg(const void *const hw, hri_nvic_nvicip104_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP104 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP104_reg(const void *const hw, hri_nvic_nvicip104_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP104 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip104_reg_t hri_nvic_read_NVICIP104_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP104;
}

static inline void hri_nvic_set_NVICIP105_PRI105_bf(const void *const hw, hri_nvic_nvicip105_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP105 |= NVIC_NVICIP105_PRI105(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip105_reg_t hri_nvic_get_NVICIP105_PRI105_bf(const void *const        hw,
                                                                        hri_nvic_nvicip105_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP105;
	tmp = (tmp & NVIC_NVICIP105_PRI105(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICIP105_PRI105_bf(const void *const hw, hri_nvic_nvicip105_reg_t data)
{
	uint8_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICIP105;
	tmp &= ~NVIC_NVICIP105_PRI105_Msk;
	tmp |= NVIC_NVICIP105_PRI105(data);
	((Nvic *)hw)->NVICIP105 = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP105_PRI105_bf(const void *const hw, hri_nvic_nvicip105_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP105 &= ~NVIC_NVICIP105_PRI105(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP105_PRI105_bf(const void *const hw, hri_nvic_nvicip105_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP105 ^= NVIC_NVICIP105_PRI105(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip105_reg_t hri_nvic_read_NVICIP105_PRI105_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP105;
	tmp = (tmp & NVIC_NVICIP105_PRI105_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICIP105_reg(const void *const hw, hri_nvic_nvicip105_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP105 |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip105_reg_t hri_nvic_get_NVICIP105_reg(const void *const hw, hri_nvic_nvicip105_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Nvic *)hw)->NVICIP105;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICIP105_reg(const void *const hw, hri_nvic_nvicip105_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP105 = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICIP105_reg(const void *const hw, hri_nvic_nvicip105_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP105 &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICIP105_reg(const void *const hw, hri_nvic_nvicip105_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICIP105 ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicip105_reg_t hri_nvic_read_NVICIP105_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICIP105;
}

static inline void hri_nvic_set_NVICSTIR_INTID_bf(const void *const hw, hri_nvic_nvicstir_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICSTIR |= NVIC_NVICSTIR_INTID(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicstir_reg_t hri_nvic_get_NVICSTIR_INTID_bf(const void *const hw, hri_nvic_nvicstir_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICSTIR;
	tmp = (tmp & NVIC_NVICSTIR_INTID(mask)) >> 0;
	return tmp;
}

static inline void hri_nvic_write_NVICSTIR_INTID_bf(const void *const hw, hri_nvic_nvicstir_reg_t data)
{
	uint32_t tmp;
	NVIC_CRITICAL_SECTION_ENTER();
	tmp = ((Nvic *)hw)->NVICSTIR;
	tmp &= ~NVIC_NVICSTIR_INTID_Msk;
	tmp |= NVIC_NVICSTIR_INTID(data);
	((Nvic *)hw)->NVICSTIR = tmp;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICSTIR_INTID_bf(const void *const hw, hri_nvic_nvicstir_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICSTIR &= ~NVIC_NVICSTIR_INTID(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICSTIR_INTID_bf(const void *const hw, hri_nvic_nvicstir_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICSTIR ^= NVIC_NVICSTIR_INTID(mask);
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicstir_reg_t hri_nvic_read_NVICSTIR_INTID_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICSTIR;
	tmp = (tmp & NVIC_NVICSTIR_INTID_Msk) >> 0;
	return tmp;
}

static inline void hri_nvic_set_NVICSTIR_reg(const void *const hw, hri_nvic_nvicstir_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICSTIR |= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicstir_reg_t hri_nvic_get_NVICSTIR_reg(const void *const hw, hri_nvic_nvicstir_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Nvic *)hw)->NVICSTIR;
	tmp &= mask;
	return tmp;
}

static inline void hri_nvic_write_NVICSTIR_reg(const void *const hw, hri_nvic_nvicstir_reg_t data)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICSTIR = data;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_clear_NVICSTIR_reg(const void *const hw, hri_nvic_nvicstir_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICSTIR &= ~mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_nvic_toggle_NVICSTIR_reg(const void *const hw, hri_nvic_nvicstir_reg_t mask)
{
	NVIC_CRITICAL_SECTION_ENTER();
	((Nvic *)hw)->NVICSTIR ^= mask;
	NVIC_CRITICAL_SECTION_LEAVE();
}

static inline hri_nvic_nvicstir_reg_t hri_nvic_read_NVICSTIR_reg(const void *const hw)
{
	return ((Nvic *)hw)->NVICSTIR;
}

#ifdef __cplusplus
}
#endif

#endif /* _HRI_NVIC_G55_H_INCLUDED */
#endif /* _SAMG55_NVIC_COMPONENT_ */
