/**
 * \file
 *
 * \brief Instance description for TC0
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
#ifndef _SAMG55_TC0_INSTANCE_H_
#define _SAMG55_TC0_INSTANCE_H_

/* ========== Register definition for TC0 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_TC0_CCR0            (0x40010000) /**< (TC0) Channel Control Register (channel = 0) 0 */
#define REG_TC0_CMR0            (0x40010004) /**< (TC0) Channel Mode Register (channel = 0) 0 */
#define REG_TC0_SMMR0           (0x40010008) /**< (TC0) Stepper Motor Mode Register (channel = 0) 0 */
#define REG_TC0_RAB0            (0x4001000C) /**< (TC0) Register AB (channel = 0) 0 */
#define REG_TC0_CV0             (0x40010010) /**< (TC0) Counter Value (channel = 0) 0 */
#define REG_TC0_RA0             (0x40010014) /**< (TC0) Register A (channel = 0) 0 */
#define REG_TC0_RB0             (0x40010018) /**< (TC0) Register B (channel = 0) 0 */
#define REG_TC0_RC0             (0x4001001C) /**< (TC0) Register C (channel = 0) 0 */
#define REG_TC0_SR0             (0x40010020) /**< (TC0) Status Register (channel = 0) 0 */
#define REG_TC0_IER0            (0x40010024) /**< (TC0) Interrupt Enable Register (channel = 0) 0 */
#define REG_TC0_IDR0            (0x40010028) /**< (TC0) Interrupt Disable Register (channel = 0) 0 */
#define REG_TC0_IMR0            (0x4001002C) /**< (TC0) Interrupt Mask Register (channel = 0) 0 */
#define REG_TC0_CCR1            (0x40010040) /**< (TC0) Channel Control Register (channel = 0) 1 */
#define REG_TC0_CMR1            (0x40010044) /**< (TC0) Channel Mode Register (channel = 0) 1 */
#define REG_TC0_SMMR1           (0x40010048) /**< (TC0) Stepper Motor Mode Register (channel = 0) 1 */
#define REG_TC0_RAB1            (0x4001004C) /**< (TC0) Register AB (channel = 0) 1 */
#define REG_TC0_CV1             (0x40010050) /**< (TC0) Counter Value (channel = 0) 1 */
#define REG_TC0_RA1             (0x40010054) /**< (TC0) Register A (channel = 0) 1 */
#define REG_TC0_RB1             (0x40010058) /**< (TC0) Register B (channel = 0) 1 */
#define REG_TC0_RC1             (0x4001005C) /**< (TC0) Register C (channel = 0) 1 */
#define REG_TC0_SR1             (0x40010060) /**< (TC0) Status Register (channel = 0) 1 */
#define REG_TC0_IER1            (0x40010064) /**< (TC0) Interrupt Enable Register (channel = 0) 1 */
#define REG_TC0_IDR1            (0x40010068) /**< (TC0) Interrupt Disable Register (channel = 0) 1 */
#define REG_TC0_IMR1            (0x4001006C) /**< (TC0) Interrupt Mask Register (channel = 0) 1 */
#define REG_TC0_CCR2            (0x40010080) /**< (TC0) Channel Control Register (channel = 0) 2 */
#define REG_TC0_CMR2            (0x40010084) /**< (TC0) Channel Mode Register (channel = 0) 2 */
#define REG_TC0_SMMR2           (0x40010088) /**< (TC0) Stepper Motor Mode Register (channel = 0) 2 */
#define REG_TC0_RAB2            (0x4001008C) /**< (TC0) Register AB (channel = 0) 2 */
#define REG_TC0_CV2             (0x40010090) /**< (TC0) Counter Value (channel = 0) 2 */
#define REG_TC0_RA2             (0x40010094) /**< (TC0) Register A (channel = 0) 2 */
#define REG_TC0_RB2             (0x40010098) /**< (TC0) Register B (channel = 0) 2 */
#define REG_TC0_RC2             (0x4001009C) /**< (TC0) Register C (channel = 0) 2 */
#define REG_TC0_SR2             (0x400100A0) /**< (TC0) Status Register (channel = 0) 2 */
#define REG_TC0_IER2            (0x400100A4) /**< (TC0) Interrupt Enable Register (channel = 0) 2 */
#define REG_TC0_IDR2            (0x400100A8) /**< (TC0) Interrupt Disable Register (channel = 0) 2 */
#define REG_TC0_IMR2            (0x400100AC) /**< (TC0) Interrupt Mask Register (channel = 0) 2 */
#define REG_TC0_BCR             (0x400100C0) /**< (TC0) Block Control Register */
#define REG_TC0_BMR             (0x400100C4) /**< (TC0) Block Mode Register */
#define REG_TC0_WPMR            (0x400100E4) /**< (TC0) Write Protection Mode Register */
#define REG_TC0_RPR0            (0x40010100) /**< (TC0) Receive Pointer Register (pdc = 0) */
#define REG_TC0_RNPR0           (0x40010110) /**< (TC0) Receive Next Pointer Register (pdc = 0) */
#define REG_TC0_RNCR0           (0x40010114) /**< (TC0) Receive Next Counter Register (pdc = 0) */
#define REG_TC0_PTCR0           (0x40010120) /**< (TC0) Transfer Control Register (pdc = 0) */
#define REG_TC0_PTSR0           (0x40010124) /**< (TC0) Transfer Status Register (pdc = 0) */

#else

#define REG_TC0_CCR0            (*(__O  uint32_t*)0x40010000U) /**< (TC0) Channel Control Register (channel = 0) 0 */
#define REG_TC0_CMR0            (*(__IO uint32_t*)0x40010004U) /**< (TC0) Channel Mode Register (channel = 0) 0 */
#define REG_TC0_SMMR0           (*(__IO uint32_t*)0x40010008U) /**< (TC0) Stepper Motor Mode Register (channel = 0) 0 */
#define REG_TC0_RAB0            (*(__I  uint32_t*)0x4001000CU) /**< (TC0) Register AB (channel = 0) 0 */
#define REG_TC0_CV0             (*(__I  uint32_t*)0x40010010U) /**< (TC0) Counter Value (channel = 0) 0 */
#define REG_TC0_RA0             (*(__IO uint32_t*)0x40010014U) /**< (TC0) Register A (channel = 0) 0 */
#define REG_TC0_RB0             (*(__IO uint32_t*)0x40010018U) /**< (TC0) Register B (channel = 0) 0 */
#define REG_TC0_RC0             (*(__IO uint32_t*)0x4001001CU) /**< (TC0) Register C (channel = 0) 0 */
#define REG_TC0_SR0             (*(__I  uint32_t*)0x40010020U) /**< (TC0) Status Register (channel = 0) 0 */
#define REG_TC0_IER0            (*(__O  uint32_t*)0x40010024U) /**< (TC0) Interrupt Enable Register (channel = 0) 0 */
#define REG_TC0_IDR0            (*(__O  uint32_t*)0x40010028U) /**< (TC0) Interrupt Disable Register (channel = 0) 0 */
#define REG_TC0_IMR0            (*(__I  uint32_t*)0x4001002CU) /**< (TC0) Interrupt Mask Register (channel = 0) 0 */
#define REG_TC0_CCR1            (*(__O  uint32_t*)0x40010040U) /**< (TC0) Channel Control Register (channel = 0) 1 */
#define REG_TC0_CMR1            (*(__IO uint32_t*)0x40010044U) /**< (TC0) Channel Mode Register (channel = 0) 1 */
#define REG_TC0_SMMR1           (*(__IO uint32_t*)0x40010048U) /**< (TC0) Stepper Motor Mode Register (channel = 0) 1 */
#define REG_TC0_RAB1            (*(__I  uint32_t*)0x4001004CU) /**< (TC0) Register AB (channel = 0) 1 */
#define REG_TC0_CV1             (*(__I  uint32_t*)0x40010050U) /**< (TC0) Counter Value (channel = 0) 1 */
#define REG_TC0_RA1             (*(__IO uint32_t*)0x40010054U) /**< (TC0) Register A (channel = 0) 1 */
#define REG_TC0_RB1             (*(__IO uint32_t*)0x40010058U) /**< (TC0) Register B (channel = 0) 1 */
#define REG_TC0_RC1             (*(__IO uint32_t*)0x4001005CU) /**< (TC0) Register C (channel = 0) 1 */
#define REG_TC0_SR1             (*(__I  uint32_t*)0x40010060U) /**< (TC0) Status Register (channel = 0) 1 */
#define REG_TC0_IER1            (*(__O  uint32_t*)0x40010064U) /**< (TC0) Interrupt Enable Register (channel = 0) 1 */
#define REG_TC0_IDR1            (*(__O  uint32_t*)0x40010068U) /**< (TC0) Interrupt Disable Register (channel = 0) 1 */
#define REG_TC0_IMR1            (*(__I  uint32_t*)0x4001006CU) /**< (TC0) Interrupt Mask Register (channel = 0) 1 */
#define REG_TC0_CCR2            (*(__O  uint32_t*)0x40010080U) /**< (TC0) Channel Control Register (channel = 0) 2 */
#define REG_TC0_CMR2            (*(__IO uint32_t*)0x40010084U) /**< (TC0) Channel Mode Register (channel = 0) 2 */
#define REG_TC0_SMMR2           (*(__IO uint32_t*)0x40010088U) /**< (TC0) Stepper Motor Mode Register (channel = 0) 2 */
#define REG_TC0_RAB2            (*(__I  uint32_t*)0x4001008CU) /**< (TC0) Register AB (channel = 0) 2 */
#define REG_TC0_CV2             (*(__I  uint32_t*)0x40010090U) /**< (TC0) Counter Value (channel = 0) 2 */
#define REG_TC0_RA2             (*(__IO uint32_t*)0x40010094U) /**< (TC0) Register A (channel = 0) 2 */
#define REG_TC0_RB2             (*(__IO uint32_t*)0x40010098U) /**< (TC0) Register B (channel = 0) 2 */
#define REG_TC0_RC2             (*(__IO uint32_t*)0x4001009CU) /**< (TC0) Register C (channel = 0) 2 */
#define REG_TC0_SR2             (*(__I  uint32_t*)0x400100A0U) /**< (TC0) Status Register (channel = 0) 2 */
#define REG_TC0_IER2            (*(__O  uint32_t*)0x400100A4U) /**< (TC0) Interrupt Enable Register (channel = 0) 2 */
#define REG_TC0_IDR2            (*(__O  uint32_t*)0x400100A8U) /**< (TC0) Interrupt Disable Register (channel = 0) 2 */
#define REG_TC0_IMR2            (*(__I  uint32_t*)0x400100ACU) /**< (TC0) Interrupt Mask Register (channel = 0) 2 */
#define REG_TC0_BCR             (*(__O  uint32_t*)0x400100C0U) /**< (TC0) Block Control Register */
#define REG_TC0_BMR             (*(__IO uint32_t*)0x400100C4U) /**< (TC0) Block Mode Register */
#define REG_TC0_WPMR            (*(__IO uint32_t*)0x400100E4U) /**< (TC0) Write Protection Mode Register */
#define REG_TC0_RPR0            (*(__IO uint32_t*)0x40010100U) /**< (TC0) Receive Pointer Register (pdc = 0) */
#define REG_TC0_RNPR0           (*(__IO uint32_t*)0x40010110U) /**< (TC0) Receive Next Pointer Register (pdc = 0) */
#define REG_TC0_RNCR0           (*(__IO uint32_t*)0x40010114U) /**< (TC0) Receive Next Counter Register (pdc = 0) */
#define REG_TC0_PTCR0           (*(__O  uint32_t*)0x40010120U) /**< (TC0) Transfer Control Register (pdc = 0) */
#define REG_TC0_PTSR0           (*(__I  uint32_t*)0x40010124U) /**< (TC0) Transfer Status Register (pdc = 0) */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for TC0 peripheral ========== */
#define TC0_INSTANCE_ID_CHANNEL1                 24        
#define TC0_INSTANCE_ID_CHANNEL0                 23        
#define TC0_INSTANCE_ID_CHANNEL2                 25        
#define TC0_DMAC_ID_RX                           14        

#endif /* _SAMG55_TC0_INSTANCE_ */
