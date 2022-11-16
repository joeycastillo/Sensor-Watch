/**
 * \file
 *
 * \brief Instance description for ADC
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
#ifndef _SAMG55_ADC_INSTANCE_H_
#define _SAMG55_ADC_INSTANCE_H_

/* ========== Register definition for ADC peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_ADC_CR              (0x40038000) /**< (ADC) Control Register */
#define REG_ADC_MR              (0x40038004) /**< (ADC) Mode Register */
#define REG_ADC_SEQR1           (0x40038008) /**< (ADC) Channel Sequence Register 1 */
#define REG_ADC_CHER            (0x40038010) /**< (ADC) Channel Enable Register */
#define REG_ADC_CHDR            (0x40038014) /**< (ADC) Channel Disable Register */
#define REG_ADC_CHSR            (0x40038018) /**< (ADC) Channel Status Register */
#define REG_ADC_LCDR            (0x40038020) /**< (ADC) Last Converted Data Register */
#define REG_ADC_IER             (0x40038024) /**< (ADC) Interrupt Enable Register */
#define REG_ADC_IDR             (0x40038028) /**< (ADC) Interrupt Disable Register */
#define REG_ADC_IMR             (0x4003802C) /**< (ADC) Interrupt Mask Register */
#define REG_ADC_ISR             (0x40038030) /**< (ADC) Interrupt Status Register */
#define REG_ADC_LCTMR           (0x40038034) /**< (ADC) Last Channel Trigger Mode Register */
#define REG_ADC_LCCWR           (0x40038038) /**< (ADC) Last Channel Compare Window Register */
#define REG_ADC_OVER            (0x4003803C) /**< (ADC) Overrun Status Register */
#define REG_ADC_EMR             (0x40038040) /**< (ADC) Extended Mode Register */
#define REG_ADC_CWR             (0x40038044) /**< (ADC) Compare Window Register */
#define REG_ADC_COR             (0x4003804C) /**< (ADC) Channel Offset Register */
#define REG_ADC_CDR             (0x40038050) /**< (ADC) Channel Data Register 0 */
#define REG_ADC_CDR0            (0x40038050) /**< (ADC) Channel Data Register 0 */
#define REG_ADC_CDR1            (0x40038054) /**< (ADC) Channel Data Register 1 */
#define REG_ADC_CDR2            (0x40038058) /**< (ADC) Channel Data Register 2 */
#define REG_ADC_CDR3            (0x4003805C) /**< (ADC) Channel Data Register 3 */
#define REG_ADC_CDR4            (0x40038060) /**< (ADC) Channel Data Register 4 */
#define REG_ADC_CDR5            (0x40038064) /**< (ADC) Channel Data Register 5 */
#define REG_ADC_CDR6            (0x40038068) /**< (ADC) Channel Data Register 6 */
#define REG_ADC_CDR7            (0x4003806C) /**< (ADC) Channel Data Register 7 */
#define REG_ADC_ACR             (0x40038094) /**< (ADC) Analog Control Register */
#define REG_ADC_WPMR            (0x400380E4) /**< (ADC) Write Protection Mode Register */
#define REG_ADC_WPSR            (0x400380E8) /**< (ADC) Write Protection Status Register */
#define REG_ADC_RPR             (0x40038100) /**< (ADC) Receive Pointer Register */
#define REG_ADC_RCR             (0x40038104) /**< (ADC) Receive Counter Register */
#define REG_ADC_RNPR            (0x40038110) /**< (ADC) Receive Next Pointer Register */
#define REG_ADC_RNCR            (0x40038114) /**< (ADC) Receive Next Counter Register */
#define REG_ADC_PTCR            (0x40038120) /**< (ADC) Transfer Control Register */
#define REG_ADC_PTSR            (0x40038124) /**< (ADC) Transfer Status Register */

#else

#define REG_ADC_CR              (*(__O  uint32_t*)0x40038000U) /**< (ADC) Control Register */
#define REG_ADC_MR              (*(__IO uint32_t*)0x40038004U) /**< (ADC) Mode Register */
#define REG_ADC_SEQR1           (*(__IO uint32_t*)0x40038008U) /**< (ADC) Channel Sequence Register 1 */
#define REG_ADC_CHER            (*(__O  uint32_t*)0x40038010U) /**< (ADC) Channel Enable Register */
#define REG_ADC_CHDR            (*(__O  uint32_t*)0x40038014U) /**< (ADC) Channel Disable Register */
#define REG_ADC_CHSR            (*(__I  uint32_t*)0x40038018U) /**< (ADC) Channel Status Register */
#define REG_ADC_LCDR            (*(__I  uint32_t*)0x40038020U) /**< (ADC) Last Converted Data Register */
#define REG_ADC_IER             (*(__O  uint32_t*)0x40038024U) /**< (ADC) Interrupt Enable Register */
#define REG_ADC_IDR             (*(__O  uint32_t*)0x40038028U) /**< (ADC) Interrupt Disable Register */
#define REG_ADC_IMR             (*(__I  uint32_t*)0x4003802CU) /**< (ADC) Interrupt Mask Register */
#define REG_ADC_ISR             (*(__I  uint32_t*)0x40038030U) /**< (ADC) Interrupt Status Register */
#define REG_ADC_LCTMR           (*(__IO uint32_t*)0x40038034U) /**< (ADC) Last Channel Trigger Mode Register */
#define REG_ADC_LCCWR           (*(__IO uint32_t*)0x40038038U) /**< (ADC) Last Channel Compare Window Register */
#define REG_ADC_OVER            (*(__I  uint32_t*)0x4003803CU) /**< (ADC) Overrun Status Register */
#define REG_ADC_EMR             (*(__IO uint32_t*)0x40038040U) /**< (ADC) Extended Mode Register */
#define REG_ADC_CWR             (*(__IO uint32_t*)0x40038044U) /**< (ADC) Compare Window Register */
#define REG_ADC_COR             (*(__IO uint32_t*)0x4003804CU) /**< (ADC) Channel Offset Register */
#define REG_ADC_CDR             (*(__I  uint32_t*)0x40038050U) /**< (ADC) Channel Data Register 0 */
#define REG_ADC_CDR0            (*(__I  uint32_t*)0x40038050U) /**< (ADC) Channel Data Register 0 */
#define REG_ADC_CDR1            (*(__I  uint32_t*)0x40038054U) /**< (ADC) Channel Data Register 1 */
#define REG_ADC_CDR2            (*(__I  uint32_t*)0x40038058U) /**< (ADC) Channel Data Register 2 */
#define REG_ADC_CDR3            (*(__I  uint32_t*)0x4003805CU) /**< (ADC) Channel Data Register 3 */
#define REG_ADC_CDR4            (*(__I  uint32_t*)0x40038060U) /**< (ADC) Channel Data Register 4 */
#define REG_ADC_CDR5            (*(__I  uint32_t*)0x40038064U) /**< (ADC) Channel Data Register 5 */
#define REG_ADC_CDR6            (*(__I  uint32_t*)0x40038068U) /**< (ADC) Channel Data Register 6 */
#define REG_ADC_CDR7            (*(__I  uint32_t*)0x4003806CU) /**< (ADC) Channel Data Register 7 */
#define REG_ADC_ACR             (*(__IO uint32_t*)0x40038094U) /**< (ADC) Analog Control Register */
#define REG_ADC_WPMR            (*(__IO uint32_t*)0x400380E4U) /**< (ADC) Write Protection Mode Register */
#define REG_ADC_WPSR            (*(__I  uint32_t*)0x400380E8U) /**< (ADC) Write Protection Status Register */
#define REG_ADC_RPR             (*(__IO uint32_t*)0x40038100U) /**< (ADC) Receive Pointer Register */
#define REG_ADC_RCR             (*(__IO uint32_t*)0x40038104U) /**< (ADC) Receive Counter Register */
#define REG_ADC_RNPR            (*(__IO uint32_t*)0x40038110U) /**< (ADC) Receive Next Pointer Register */
#define REG_ADC_RNCR            (*(__IO uint32_t*)0x40038114U) /**< (ADC) Receive Next Counter Register */
#define REG_ADC_PTCR            (*(__O  uint32_t*)0x40038120U) /**< (ADC) Transfer Control Register */
#define REG_ADC_PTSR            (*(__I  uint32_t*)0x40038124U) /**< (ADC) Transfer Status Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for ADC peripheral ========== */
#define ADC_INSTANCE_ID                          29        
#define ADC_DMAC_ID_RX                           6         

#endif /* _SAMG55_ADC_INSTANCE_ */
