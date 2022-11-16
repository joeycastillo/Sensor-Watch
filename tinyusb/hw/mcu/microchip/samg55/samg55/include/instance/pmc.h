/**
 * \file
 *
 * \brief Instance description for PMC
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
#ifndef _SAMG55_PMC_INSTANCE_H_
#define _SAMG55_PMC_INSTANCE_H_

/* ========== Register definition for PMC peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_PMC_SCER            (0x400E0400) /**< (PMC) System Clock Enable Register */
#define REG_PMC_SCDR            (0x400E0404) /**< (PMC) System Clock Disable Register */
#define REG_PMC_SCSR            (0x400E0408) /**< (PMC) System Clock Status Register */
#define REG_PMC_PCER0           (0x400E0410) /**< (PMC) Peripheral Clock Enable Register 0 */
#define REG_PMC_PCDR0           (0x400E0414) /**< (PMC) Peripheral Clock Disable Register 0 */
#define REG_PMC_PCSR0           (0x400E0418) /**< (PMC) Peripheral Clock Status Register 0 */
#define REG_CKGR_MOR            (0x400E0420) /**< (PMC) Main Oscillator Register */
#define REG_CKGR_MCFR           (0x400E0424) /**< (PMC) Main Clock Frequency Register */
#define REG_CKGR_PLLAR          (0x400E0428) /**< (PMC) PLLA Register */
#define REG_CKGR_PLLBR          (0x400E042C) /**< (PMC) PLLB Register */
#define REG_PMC_MCKR            (0x400E0430) /**< (PMC) Master Clock Register */
#define REG_PMC_USB             (0x400E0438) /**< (PMC) USB Clock Register */
#define REG_PMC_PCK             (0x400E0440) /**< (PMC) Programmable Clock 0 Register 0 */
#define REG_PMC_PCK0            (0x400E0440) /**< (PMC) Programmable Clock 0 Register 0 */
#define REG_PMC_PCK1            (0x400E0444) /**< (PMC) Programmable Clock 0 Register 1 */
#define REG_PMC_PCK2            (0x400E0448) /**< (PMC) Programmable Clock 0 Register 2 */
#define REG_PMC_PCK3            (0x400E044C) /**< (PMC) Programmable Clock 0 Register 3 */
#define REG_PMC_PCK4            (0x400E0450) /**< (PMC) Programmable Clock 0 Register 4 */
#define REG_PMC_PCK5            (0x400E0454) /**< (PMC) Programmable Clock 0 Register 5 */
#define REG_PMC_PCK6            (0x400E0458) /**< (PMC) Programmable Clock 0 Register 6 */
#define REG_PMC_PCK7            (0x400E045C) /**< (PMC) Programmable Clock 0 Register 7 */
#define REG_PMC_IER             (0x400E0460) /**< (PMC) Interrupt Enable Register */
#define REG_PMC_IDR             (0x400E0464) /**< (PMC) Interrupt Disable Register */
#define REG_PMC_SR              (0x400E0468) /**< (PMC) Status Register */
#define REG_PMC_IMR             (0x400E046C) /**< (PMC) Interrupt Mask Register */
#define REG_PMC_FSMR            (0x400E0470) /**< (PMC) Fast Startup Mode Register */
#define REG_PMC_FSPR            (0x400E0474) /**< (PMC) Fast Startup Polarity Register */
#define REG_PMC_FOCR            (0x400E0478) /**< (PMC) Fault Output Clear Register */
#define REG_PMC_WPMR            (0x400E04E4) /**< (PMC) Write Protection Mode Register */
#define REG_PMC_WPSR            (0x400E04E8) /**< (PMC) Write Protection Status Register */
#define REG_PMC_PCER1           (0x400E0500) /**< (PMC) Peripheral Clock Enable Register 1 */
#define REG_PMC_PCDR1           (0x400E0504) /**< (PMC) Peripheral Clock Disable Register 1 */
#define REG_PMC_PCSR1           (0x400E0508) /**< (PMC) Peripheral Clock Status Register 1 */
#define REG_PMC_PCR             (0x400E050C) /**< (PMC) Peripheral Control Register */
#define REG_PMC_OCR             (0x400E0510) /**< (PMC) Oscillator Calibration Register */
#define REG_PMC_SLPWK_ER0       (0x400E0514) /**< (PMC) SleepWalking Enable Register 0 */
#define REG_PMC_SLPWK_DR0       (0x400E0518) /**< (PMC) SleepWalking Disable Register 0 */
#define REG_PMC_SLPWK_SR0       (0x400E051C) /**< (PMC) SleepWalking Status Register 0 */
#define REG_PMC_SLPWK_ASR0      (0x400E0520) /**< (PMC) SleepWalking Activity Status Register 0 */
#define REG_PMC_PMMR            (0x400E0530) /**< (PMC) PLL Maximum Multiplier Value Register */

#else

#define REG_PMC_SCER            (*(__O  uint32_t*)0x400E0400U) /**< (PMC) System Clock Enable Register */
#define REG_PMC_SCDR            (*(__O  uint32_t*)0x400E0404U) /**< (PMC) System Clock Disable Register */
#define REG_PMC_SCSR            (*(__I  uint32_t*)0x400E0408U) /**< (PMC) System Clock Status Register */
#define REG_PMC_PCER0           (*(__O  uint32_t*)0x400E0410U) /**< (PMC) Peripheral Clock Enable Register 0 */
#define REG_PMC_PCDR0           (*(__O  uint32_t*)0x400E0414U) /**< (PMC) Peripheral Clock Disable Register 0 */
#define REG_PMC_PCSR0           (*(__I  uint32_t*)0x400E0418U) /**< (PMC) Peripheral Clock Status Register 0 */
#define REG_CKGR_MOR            (*(__IO uint32_t*)0x400E0420U) /**< (PMC) Main Oscillator Register */
#define REG_CKGR_MCFR           (*(__IO uint32_t*)0x400E0424U) /**< (PMC) Main Clock Frequency Register */
#define REG_CKGR_PLLAR          (*(__IO uint32_t*)0x400E0428U) /**< (PMC) PLLA Register */
#define REG_CKGR_PLLBR          (*(__IO uint32_t*)0x400E042CU) /**< (PMC) PLLB Register */
#define REG_PMC_MCKR            (*(__IO uint32_t*)0x400E0430U) /**< (PMC) Master Clock Register */
#define REG_PMC_USB             (*(__IO uint32_t*)0x400E0438U) /**< (PMC) USB Clock Register */
#define REG_PMC_PCK             (*(__IO uint32_t*)0x400E0440U) /**< (PMC) Programmable Clock 0 Register 0 */
#define REG_PMC_PCK0            (*(__IO uint32_t*)0x400E0440U) /**< (PMC) Programmable Clock 0 Register 0 */
#define REG_PMC_PCK1            (*(__IO uint32_t*)0x400E0444U) /**< (PMC) Programmable Clock 0 Register 1 */
#define REG_PMC_PCK2            (*(__IO uint32_t*)0x400E0448U) /**< (PMC) Programmable Clock 0 Register 2 */
#define REG_PMC_PCK3            (*(__IO uint32_t*)0x400E044CU) /**< (PMC) Programmable Clock 0 Register 3 */
#define REG_PMC_PCK4            (*(__IO uint32_t*)0x400E0450U) /**< (PMC) Programmable Clock 0 Register 4 */
#define REG_PMC_PCK5            (*(__IO uint32_t*)0x400E0454U) /**< (PMC) Programmable Clock 0 Register 5 */
#define REG_PMC_PCK6            (*(__IO uint32_t*)0x400E0458U) /**< (PMC) Programmable Clock 0 Register 6 */
#define REG_PMC_PCK7            (*(__IO uint32_t*)0x400E045CU) /**< (PMC) Programmable Clock 0 Register 7 */
#define REG_PMC_IER             (*(__O  uint32_t*)0x400E0460U) /**< (PMC) Interrupt Enable Register */
#define REG_PMC_IDR             (*(__O  uint32_t*)0x400E0464U) /**< (PMC) Interrupt Disable Register */
#define REG_PMC_SR              (*(__I  uint32_t*)0x400E0468U) /**< (PMC) Status Register */
#define REG_PMC_IMR             (*(__I  uint32_t*)0x400E046CU) /**< (PMC) Interrupt Mask Register */
#define REG_PMC_FSMR            (*(__IO uint32_t*)0x400E0470U) /**< (PMC) Fast Startup Mode Register */
#define REG_PMC_FSPR            (*(__IO uint32_t*)0x400E0474U) /**< (PMC) Fast Startup Polarity Register */
#define REG_PMC_FOCR            (*(__O  uint32_t*)0x400E0478U) /**< (PMC) Fault Output Clear Register */
#define REG_PMC_WPMR            (*(__IO uint32_t*)0x400E04E4U) /**< (PMC) Write Protection Mode Register */
#define REG_PMC_WPSR            (*(__I  uint32_t*)0x400E04E8U) /**< (PMC) Write Protection Status Register */
#define REG_PMC_PCER1           (*(__O  uint32_t*)0x400E0500U) /**< (PMC) Peripheral Clock Enable Register 1 */
#define REG_PMC_PCDR1           (*(__O  uint32_t*)0x400E0504U) /**< (PMC) Peripheral Clock Disable Register 1 */
#define REG_PMC_PCSR1           (*(__I  uint32_t*)0x400E0508U) /**< (PMC) Peripheral Clock Status Register 1 */
#define REG_PMC_PCR             (*(__IO uint32_t*)0x400E050CU) /**< (PMC) Peripheral Control Register */
#define REG_PMC_OCR             (*(__IO uint32_t*)0x400E0510U) /**< (PMC) Oscillator Calibration Register */
#define REG_PMC_SLPWK_ER0       (*(__O  uint32_t*)0x400E0514U) /**< (PMC) SleepWalking Enable Register 0 */
#define REG_PMC_SLPWK_DR0       (*(__O  uint32_t*)0x400E0518U) /**< (PMC) SleepWalking Disable Register 0 */
#define REG_PMC_SLPWK_SR0       (*(__I  uint32_t*)0x400E051CU) /**< (PMC) SleepWalking Status Register 0 */
#define REG_PMC_SLPWK_ASR0      (*(__I  uint32_t*)0x400E0520U) /**< (PMC) SleepWalking Activity Status Register 0 */
#define REG_PMC_PMMR            (*(__IO uint32_t*)0x400E0530U) /**< (PMC) PLL Maximum Multiplier Value Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for PMC peripheral ========== */
#define PMC_INSTANCE_ID                          5         

#endif /* _SAMG55_PMC_INSTANCE_ */
