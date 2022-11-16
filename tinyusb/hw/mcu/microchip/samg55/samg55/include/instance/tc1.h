/**
 * \file
 *
 * \brief Instance description for TC1
 *
 * Copyright (c) 2017 Atmel Corporation, a wholly owned subsidiary of Microchip Technology Inc.
 *
 * \license_start
 *
 * \page License
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * \license_stop
 *
 */

/* file generated from device description version 2017-07-05T18:00:00Z */
#ifndef _SAMG55_TC1_INSTANCE_H_
#define _SAMG55_TC1_INSTANCE_H_

/* ========== Register definition for TC1 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_TC1_CCR0            (0x40014000) /**< (TC1) Channel Control Register (channel = 0) 0 */
#define REG_TC1_CMR0            (0x40014004) /**< (TC1) Channel Mode Register (channel = 0) 0 */
#define REG_TC1_SMMR0           (0x40014008) /**< (TC1) Stepper Motor Mode Register (channel = 0) 0 */
#define REG_TC1_RAB0            (0x4001400C) /**< (TC1) Register AB (channel = 0) 0 */
#define REG_TC1_CV0             (0x40014010) /**< (TC1) Counter Value (channel = 0) 0 */
#define REG_TC1_RA0             (0x40014014) /**< (TC1) Register A (channel = 0) 0 */
#define REG_TC1_RB0             (0x40014018) /**< (TC1) Register B (channel = 0) 0 */
#define REG_TC1_RC0             (0x4001401C) /**< (TC1) Register C (channel = 0) 0 */
#define REG_TC1_SR0             (0x40014020) /**< (TC1) Status Register (channel = 0) 0 */
#define REG_TC1_IER0            (0x40014024) /**< (TC1) Interrupt Enable Register (channel = 0) 0 */
#define REG_TC1_IDR0            (0x40014028) /**< (TC1) Interrupt Disable Register (channel = 0) 0 */
#define REG_TC1_IMR0            (0x4001402C) /**< (TC1) Interrupt Mask Register (channel = 0) 0 */
#define REG_TC1_CCR1            (0x40014040) /**< (TC1) Channel Control Register (channel = 0) 1 */
#define REG_TC1_CMR1            (0x40014044) /**< (TC1) Channel Mode Register (channel = 0) 1 */
#define REG_TC1_SMMR1           (0x40014048) /**< (TC1) Stepper Motor Mode Register (channel = 0) 1 */
#define REG_TC1_RAB1            (0x4001404C) /**< (TC1) Register AB (channel = 0) 1 */
#define REG_TC1_CV1             (0x40014050) /**< (TC1) Counter Value (channel = 0) 1 */
#define REG_TC1_RA1             (0x40014054) /**< (TC1) Register A (channel = 0) 1 */
#define REG_TC1_RB1             (0x40014058) /**< (TC1) Register B (channel = 0) 1 */
#define REG_TC1_RC1             (0x4001405C) /**< (TC1) Register C (channel = 0) 1 */
#define REG_TC1_SR1             (0x40014060) /**< (TC1) Status Register (channel = 0) 1 */
#define REG_TC1_IER1            (0x40014064) /**< (TC1) Interrupt Enable Register (channel = 0) 1 */
#define REG_TC1_IDR1            (0x40014068) /**< (TC1) Interrupt Disable Register (channel = 0) 1 */
#define REG_TC1_IMR1            (0x4001406C) /**< (TC1) Interrupt Mask Register (channel = 0) 1 */
#define REG_TC1_CCR2            (0x40014080) /**< (TC1) Channel Control Register (channel = 0) 2 */
#define REG_TC1_CMR2            (0x40014084) /**< (TC1) Channel Mode Register (channel = 0) 2 */
#define REG_TC1_SMMR2           (0x40014088) /**< (TC1) Stepper Motor Mode Register (channel = 0) 2 */
#define REG_TC1_RAB2            (0x4001408C) /**< (TC1) Register AB (channel = 0) 2 */
#define REG_TC1_CV2             (0x40014090) /**< (TC1) Counter Value (channel = 0) 2 */
#define REG_TC1_RA2             (0x40014094) /**< (TC1) Register A (channel = 0) 2 */
#define REG_TC1_RB2             (0x40014098) /**< (TC1) Register B (channel = 0) 2 */
#define REG_TC1_RC2             (0x4001409C) /**< (TC1) Register C (channel = 0) 2 */
#define REG_TC1_SR2             (0x400140A0) /**< (TC1) Status Register (channel = 0) 2 */
#define REG_TC1_IER2            (0x400140A4) /**< (TC1) Interrupt Enable Register (channel = 0) 2 */
#define REG_TC1_IDR2            (0x400140A8) /**< (TC1) Interrupt Disable Register (channel = 0) 2 */
#define REG_TC1_IMR2            (0x400140AC) /**< (TC1) Interrupt Mask Register (channel = 0) 2 */
#define REG_TC1_BCR             (0x400140C0) /**< (TC1) Block Control Register */
#define REG_TC1_BMR             (0x400140C4) /**< (TC1) Block Mode Register */
#define REG_TC1_WPMR            (0x400140E4) /**< (TC1) Write Protection Mode Register */
#define REG_TC1_RPR0            (0x40014100) /**< (TC1) Receive Pointer Register (pdc = 0) */
#define REG_TC1_RNPR0           (0x40014110) /**< (TC1) Receive Next Pointer Register (pdc = 0) */
#define REG_TC1_RNCR0           (0x40014114) /**< (TC1) Receive Next Counter Register (pdc = 0) */
#define REG_TC1_PTCR0           (0x40014120) /**< (TC1) Transfer Control Register (pdc = 0) */
#define REG_TC1_PTSR0           (0x40014124) /**< (TC1) Transfer Status Register (pdc = 0) */

#else

#define REG_TC1_CCR0            (*(__O  uint32_t*)0x40014000U) /**< (TC1) Channel Control Register (channel = 0) 0 */
#define REG_TC1_CMR0            (*(__IO uint32_t*)0x40014004U) /**< (TC1) Channel Mode Register (channel = 0) 0 */
#define REG_TC1_SMMR0           (*(__IO uint32_t*)0x40014008U) /**< (TC1) Stepper Motor Mode Register (channel = 0) 0 */
#define REG_TC1_RAB0            (*(__I  uint32_t*)0x4001400CU) /**< (TC1) Register AB (channel = 0) 0 */
#define REG_TC1_CV0             (*(__I  uint32_t*)0x40014010U) /**< (TC1) Counter Value (channel = 0) 0 */
#define REG_TC1_RA0             (*(__IO uint32_t*)0x40014014U) /**< (TC1) Register A (channel = 0) 0 */
#define REG_TC1_RB0             (*(__IO uint32_t*)0x40014018U) /**< (TC1) Register B (channel = 0) 0 */
#define REG_TC1_RC0             (*(__IO uint32_t*)0x4001401CU) /**< (TC1) Register C (channel = 0) 0 */
#define REG_TC1_SR0             (*(__I  uint32_t*)0x40014020U) /**< (TC1) Status Register (channel = 0) 0 */
#define REG_TC1_IER0            (*(__O  uint32_t*)0x40014024U) /**< (TC1) Interrupt Enable Register (channel = 0) 0 */
#define REG_TC1_IDR0            (*(__O  uint32_t*)0x40014028U) /**< (TC1) Interrupt Disable Register (channel = 0) 0 */
#define REG_TC1_IMR0            (*(__I  uint32_t*)0x4001402CU) /**< (TC1) Interrupt Mask Register (channel = 0) 0 */
#define REG_TC1_CCR1            (*(__O  uint32_t*)0x40014040U) /**< (TC1) Channel Control Register (channel = 0) 1 */
#define REG_TC1_CMR1            (*(__IO uint32_t*)0x40014044U) /**< (TC1) Channel Mode Register (channel = 0) 1 */
#define REG_TC1_SMMR1           (*(__IO uint32_t*)0x40014048U) /**< (TC1) Stepper Motor Mode Register (channel = 0) 1 */
#define REG_TC1_RAB1            (*(__I  uint32_t*)0x4001404CU) /**< (TC1) Register AB (channel = 0) 1 */
#define REG_TC1_CV1             (*(__I  uint32_t*)0x40014050U) /**< (TC1) Counter Value (channel = 0) 1 */
#define REG_TC1_RA1             (*(__IO uint32_t*)0x40014054U) /**< (TC1) Register A (channel = 0) 1 */
#define REG_TC1_RB1             (*(__IO uint32_t*)0x40014058U) /**< (TC1) Register B (channel = 0) 1 */
#define REG_TC1_RC1             (*(__IO uint32_t*)0x4001405CU) /**< (TC1) Register C (channel = 0) 1 */
#define REG_TC1_SR1             (*(__I  uint32_t*)0x40014060U) /**< (TC1) Status Register (channel = 0) 1 */
#define REG_TC1_IER1            (*(__O  uint32_t*)0x40014064U) /**< (TC1) Interrupt Enable Register (channel = 0) 1 */
#define REG_TC1_IDR1            (*(__O  uint32_t*)0x40014068U) /**< (TC1) Interrupt Disable Register (channel = 0) 1 */
#define REG_TC1_IMR1            (*(__I  uint32_t*)0x4001406CU) /**< (TC1) Interrupt Mask Register (channel = 0) 1 */
#define REG_TC1_CCR2            (*(__O  uint32_t*)0x40014080U) /**< (TC1) Channel Control Register (channel = 0) 2 */
#define REG_TC1_CMR2            (*(__IO uint32_t*)0x40014084U) /**< (TC1) Channel Mode Register (channel = 0) 2 */
#define REG_TC1_SMMR2           (*(__IO uint32_t*)0x40014088U) /**< (TC1) Stepper Motor Mode Register (channel = 0) 2 */
#define REG_TC1_RAB2            (*(__I  uint32_t*)0x4001408CU) /**< (TC1) Register AB (channel = 0) 2 */
#define REG_TC1_CV2             (*(__I  uint32_t*)0x40014090U) /**< (TC1) Counter Value (channel = 0) 2 */
#define REG_TC1_RA2             (*(__IO uint32_t*)0x40014094U) /**< (TC1) Register A (channel = 0) 2 */
#define REG_TC1_RB2             (*(__IO uint32_t*)0x40014098U) /**< (TC1) Register B (channel = 0) 2 */
#define REG_TC1_RC2             (*(__IO uint32_t*)0x4001409CU) /**< (TC1) Register C (channel = 0) 2 */
#define REG_TC1_SR2             (*(__I  uint32_t*)0x400140A0U) /**< (TC1) Status Register (channel = 0) 2 */
#define REG_TC1_IER2            (*(__O  uint32_t*)0x400140A4U) /**< (TC1) Interrupt Enable Register (channel = 0) 2 */
#define REG_TC1_IDR2            (*(__O  uint32_t*)0x400140A8U) /**< (TC1) Interrupt Disable Register (channel = 0) 2 */
#define REG_TC1_IMR2            (*(__I  uint32_t*)0x400140ACU) /**< (TC1) Interrupt Mask Register (channel = 0) 2 */
#define REG_TC1_BCR             (*(__O  uint32_t*)0x400140C0U) /**< (TC1) Block Control Register */
#define REG_TC1_BMR             (*(__IO uint32_t*)0x400140C4U) /**< (TC1) Block Mode Register */
#define REG_TC1_WPMR            (*(__IO uint32_t*)0x400140E4U) /**< (TC1) Write Protection Mode Register */
#define REG_TC1_RPR0            (*(__IO uint32_t*)0x40014100U) /**< (TC1) Receive Pointer Register (pdc = 0) */
#define REG_TC1_RNPR0           (*(__IO uint32_t*)0x40014110U) /**< (TC1) Receive Next Pointer Register (pdc = 0) */
#define REG_TC1_RNCR0           (*(__IO uint32_t*)0x40014114U) /**< (TC1) Receive Next Counter Register (pdc = 0) */
#define REG_TC1_PTCR0           (*(__O  uint32_t*)0x40014120U) /**< (TC1) Transfer Control Register (pdc = 0) */
#define REG_TC1_PTSR0           (*(__I  uint32_t*)0x40014124U) /**< (TC1) Transfer Status Register (pdc = 0) */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for TC1 peripheral ========== */
#define TC1_INSTANCE_ID_CHANNEL1                 27        
#define TC1_INSTANCE_ID_CHANNEL0                 26        
#define TC1_INSTANCE_ID_CHANNEL2                 28        

#endif /* _SAMG55_TC1_INSTANCE_ */
