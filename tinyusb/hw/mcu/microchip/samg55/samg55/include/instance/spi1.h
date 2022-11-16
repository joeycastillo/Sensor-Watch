/**
 * \file
 *
 * \brief Instance description for SPI1
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
#ifndef _SAMG55_SPI1_INSTANCE_H_
#define _SAMG55_SPI1_INSTANCE_H_

/* ========== Register definition for SPI1 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_SPI1_CR             (0x40020400) /**< (SPI1) SPI Control Register */
#define REG_SPI1_MR             (0x40020404) /**< (SPI1) SPI Mode Register */
#define REG_SPI1_RDR            (0x40020408) /**< (SPI1) SPI Receive Data Register */
#define REG_SPI1_TDR            (0x4002040C) /**< (SPI1) SPI Transmit Data Register */
#define REG_SPI1_SR             (0x40020410) /**< (SPI1) SPI Status Register */
#define REG_SPI1_IER            (0x40020414) /**< (SPI1) SPI Interrupt Enable Register */
#define REG_SPI1_IDR            (0x40020418) /**< (SPI1) SPI Interrupt Disable Register */
#define REG_SPI1_IMR            (0x4002041C) /**< (SPI1) SPI Interrupt Mask Register */
#define REG_SPI1_CSR            (0x40020430) /**< (SPI1) SPI Chip Select Register 0 */
#define REG_SPI1_CSR0           (0x40020430) /**< (SPI1) SPI Chip Select Register 0 */
#define REG_SPI1_CSR1           (0x40020434) /**< (SPI1) SPI Chip Select Register 1 */
#define REG_SPI1_CMPR           (0x40020448) /**< (SPI1) SPI Comparison Register */
#define REG_SPI1_WPMR           (0x400204E4) /**< (SPI1) SPI Write Protection Mode Register */
#define REG_SPI1_WPSR           (0x400204E8) /**< (SPI1) SPI Write Protection Status Register */
#define REG_SPI1_RPR            (0x40020500) /**< (SPI1) Receive Pointer Register */
#define REG_SPI1_RCR            (0x40020504) /**< (SPI1) Receive Counter Register */
#define REG_SPI1_TPR            (0x40020508) /**< (SPI1) Transmit Pointer Register */
#define REG_SPI1_TCR            (0x4002050C) /**< (SPI1) Transmit Counter Register */
#define REG_SPI1_RNPR           (0x40020510) /**< (SPI1) Receive Next Pointer Register */
#define REG_SPI1_RNCR           (0x40020514) /**< (SPI1) Receive Next Counter Register */
#define REG_SPI1_TNPR           (0x40020518) /**< (SPI1) Transmit Next Pointer Register */
#define REG_SPI1_TNCR           (0x4002051C) /**< (SPI1) Transmit Next Counter Register */
#define REG_SPI1_PTCR           (0x40020520) /**< (SPI1) Transfer Control Register */
#define REG_SPI1_PTSR           (0x40020524) /**< (SPI1) Transfer Status Register */

#else

#define REG_SPI1_CR             (*(__O  uint32_t*)0x40020400U) /**< (SPI1) SPI Control Register */
#define REG_SPI1_MR             (*(__IO uint32_t*)0x40020404U) /**< (SPI1) SPI Mode Register */
#define REG_SPI1_RDR            (*(__I  uint32_t*)0x40020408U) /**< (SPI1) SPI Receive Data Register */
#define REG_SPI1_TDR            (*(__O  uint32_t*)0x4002040CU) /**< (SPI1) SPI Transmit Data Register */
#define REG_SPI1_SR             (*(__I  uint32_t*)0x40020410U) /**< (SPI1) SPI Status Register */
#define REG_SPI1_IER            (*(__O  uint32_t*)0x40020414U) /**< (SPI1) SPI Interrupt Enable Register */
#define REG_SPI1_IDR            (*(__O  uint32_t*)0x40020418U) /**< (SPI1) SPI Interrupt Disable Register */
#define REG_SPI1_IMR            (*(__I  uint32_t*)0x4002041CU) /**< (SPI1) SPI Interrupt Mask Register */
#define REG_SPI1_CSR            (*(__IO uint32_t*)0x40020430U) /**< (SPI1) SPI Chip Select Register 0 */
#define REG_SPI1_CSR0           (*(__IO uint32_t*)0x40020430U) /**< (SPI1) SPI Chip Select Register 0 */
#define REG_SPI1_CSR1           (*(__IO uint32_t*)0x40020434U) /**< (SPI1) SPI Chip Select Register 1 */
#define REG_SPI1_CMPR           (*(__IO uint32_t*)0x40020448U) /**< (SPI1) SPI Comparison Register */
#define REG_SPI1_WPMR           (*(__IO uint32_t*)0x400204E4U) /**< (SPI1) SPI Write Protection Mode Register */
#define REG_SPI1_WPSR           (*(__I  uint32_t*)0x400204E8U) /**< (SPI1) SPI Write Protection Status Register */
#define REG_SPI1_RPR            (*(__IO uint32_t*)0x40020500U) /**< (SPI1) Receive Pointer Register */
#define REG_SPI1_RCR            (*(__IO uint32_t*)0x40020504U) /**< (SPI1) Receive Counter Register */
#define REG_SPI1_TPR            (*(__IO uint32_t*)0x40020508U) /**< (SPI1) Transmit Pointer Register */
#define REG_SPI1_TCR            (*(__IO uint32_t*)0x4002050CU) /**< (SPI1) Transmit Counter Register */
#define REG_SPI1_RNPR           (*(__IO uint32_t*)0x40020510U) /**< (SPI1) Receive Next Pointer Register */
#define REG_SPI1_RNCR           (*(__IO uint32_t*)0x40020514U) /**< (SPI1) Receive Next Counter Register */
#define REG_SPI1_TNPR           (*(__IO uint32_t*)0x40020518U) /**< (SPI1) Transmit Next Pointer Register */
#define REG_SPI1_TNCR           (*(__IO uint32_t*)0x4002051CU) /**< (SPI1) Transmit Next Counter Register */
#define REG_SPI1_PTCR           (*(__O  uint32_t*)0x40020520U) /**< (SPI1) Transfer Control Register */
#define REG_SPI1_PTSR           (*(__I  uint32_t*)0x40020524U) /**< (SPI1) Transfer Status Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for SPI1 peripheral ========== */
#define SPI1_DMAC_ID_TX                          23        
#define SPI1_DMAC_ID_RX                          9         

#endif /* _SAMG55_SPI1_INSTANCE_ */
