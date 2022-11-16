/**
 * \file
 *
 * \brief Instance description for SPI7
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
#ifndef _SAMG55_SPI7_INSTANCE_H_
#define _SAMG55_SPI7_INSTANCE_H_

/* ========== Register definition for SPI7 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_SPI7_CR             (0x40034400) /**< (SPI7) SPI Control Register */
#define REG_SPI7_MR             (0x40034404) /**< (SPI7) SPI Mode Register */
#define REG_SPI7_RDR            (0x40034408) /**< (SPI7) SPI Receive Data Register */
#define REG_SPI7_TDR            (0x4003440C) /**< (SPI7) SPI Transmit Data Register */
#define REG_SPI7_SR             (0x40034410) /**< (SPI7) SPI Status Register */
#define REG_SPI7_IER            (0x40034414) /**< (SPI7) SPI Interrupt Enable Register */
#define REG_SPI7_IDR            (0x40034418) /**< (SPI7) SPI Interrupt Disable Register */
#define REG_SPI7_IMR            (0x4003441C) /**< (SPI7) SPI Interrupt Mask Register */
#define REG_SPI7_CSR            (0x40034430) /**< (SPI7) SPI Chip Select Register 0 */
#define REG_SPI7_CSR0           (0x40034430) /**< (SPI7) SPI Chip Select Register 0 */
#define REG_SPI7_CSR1           (0x40034434) /**< (SPI7) SPI Chip Select Register 1 */
#define REG_SPI7_CMPR           (0x40034448) /**< (SPI7) SPI Comparison Register */
#define REG_SPI7_WPMR           (0x400344E4) /**< (SPI7) SPI Write Protection Mode Register */
#define REG_SPI7_WPSR           (0x400344E8) /**< (SPI7) SPI Write Protection Status Register */
#define REG_SPI7_RPR            (0x40034500) /**< (SPI7) Receive Pointer Register */
#define REG_SPI7_RCR            (0x40034504) /**< (SPI7) Receive Counter Register */
#define REG_SPI7_TPR            (0x40034508) /**< (SPI7) Transmit Pointer Register */
#define REG_SPI7_TCR            (0x4003450C) /**< (SPI7) Transmit Counter Register */
#define REG_SPI7_RNPR           (0x40034510) /**< (SPI7) Receive Next Pointer Register */
#define REG_SPI7_RNCR           (0x40034514) /**< (SPI7) Receive Next Counter Register */
#define REG_SPI7_TNPR           (0x40034518) /**< (SPI7) Transmit Next Pointer Register */
#define REG_SPI7_TNCR           (0x4003451C) /**< (SPI7) Transmit Next Counter Register */
#define REG_SPI7_PTCR           (0x40034520) /**< (SPI7) Transfer Control Register */
#define REG_SPI7_PTSR           (0x40034524) /**< (SPI7) Transfer Status Register */

#else

#define REG_SPI7_CR             (*(__O  uint32_t*)0x40034400U) /**< (SPI7) SPI Control Register */
#define REG_SPI7_MR             (*(__IO uint32_t*)0x40034404U) /**< (SPI7) SPI Mode Register */
#define REG_SPI7_RDR            (*(__I  uint32_t*)0x40034408U) /**< (SPI7) SPI Receive Data Register */
#define REG_SPI7_TDR            (*(__O  uint32_t*)0x4003440CU) /**< (SPI7) SPI Transmit Data Register */
#define REG_SPI7_SR             (*(__I  uint32_t*)0x40034410U) /**< (SPI7) SPI Status Register */
#define REG_SPI7_IER            (*(__O  uint32_t*)0x40034414U) /**< (SPI7) SPI Interrupt Enable Register */
#define REG_SPI7_IDR            (*(__O  uint32_t*)0x40034418U) /**< (SPI7) SPI Interrupt Disable Register */
#define REG_SPI7_IMR            (*(__I  uint32_t*)0x4003441CU) /**< (SPI7) SPI Interrupt Mask Register */
#define REG_SPI7_CSR            (*(__IO uint32_t*)0x40034430U) /**< (SPI7) SPI Chip Select Register 0 */
#define REG_SPI7_CSR0           (*(__IO uint32_t*)0x40034430U) /**< (SPI7) SPI Chip Select Register 0 */
#define REG_SPI7_CSR1           (*(__IO uint32_t*)0x40034434U) /**< (SPI7) SPI Chip Select Register 1 */
#define REG_SPI7_CMPR           (*(__IO uint32_t*)0x40034448U) /**< (SPI7) SPI Comparison Register */
#define REG_SPI7_WPMR           (*(__IO uint32_t*)0x400344E4U) /**< (SPI7) SPI Write Protection Mode Register */
#define REG_SPI7_WPSR           (*(__I  uint32_t*)0x400344E8U) /**< (SPI7) SPI Write Protection Status Register */
#define REG_SPI7_RPR            (*(__IO uint32_t*)0x40034500U) /**< (SPI7) Receive Pointer Register */
#define REG_SPI7_RCR            (*(__IO uint32_t*)0x40034504U) /**< (SPI7) Receive Counter Register */
#define REG_SPI7_TPR            (*(__IO uint32_t*)0x40034508U) /**< (SPI7) Transmit Pointer Register */
#define REG_SPI7_TCR            (*(__IO uint32_t*)0x4003450CU) /**< (SPI7) Transmit Counter Register */
#define REG_SPI7_RNPR           (*(__IO uint32_t*)0x40034510U) /**< (SPI7) Receive Next Pointer Register */
#define REG_SPI7_RNCR           (*(__IO uint32_t*)0x40034514U) /**< (SPI7) Receive Next Counter Register */
#define REG_SPI7_TNPR           (*(__IO uint32_t*)0x40034518U) /**< (SPI7) Transmit Next Pointer Register */
#define REG_SPI7_TNCR           (*(__IO uint32_t*)0x4003451CU) /**< (SPI7) Transmit Next Counter Register */
#define REG_SPI7_PTCR           (*(__O  uint32_t*)0x40034520U) /**< (SPI7) Transfer Control Register */
#define REG_SPI7_PTSR           (*(__I  uint32_t*)0x40034524U) /**< (SPI7) Transfer Status Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for SPI7 peripheral ========== */
#define SPI7_DMAC_ID_TX                          29        
#define SPI7_DMAC_ID_RX                          16        

#endif /* _SAMG55_SPI7_INSTANCE_ */
