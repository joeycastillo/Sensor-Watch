/**
 * \file
 *
 * \brief Instance description for SPI2
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
#ifndef _SAMG55_SPI2_INSTANCE_H_
#define _SAMG55_SPI2_INSTANCE_H_

/* ========== Register definition for SPI2 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_SPI2_CR             (0x40024400) /**< (SPI2) SPI Control Register */
#define REG_SPI2_MR             (0x40024404) /**< (SPI2) SPI Mode Register */
#define REG_SPI2_RDR            (0x40024408) /**< (SPI2) SPI Receive Data Register */
#define REG_SPI2_TDR            (0x4002440C) /**< (SPI2) SPI Transmit Data Register */
#define REG_SPI2_SR             (0x40024410) /**< (SPI2) SPI Status Register */
#define REG_SPI2_IER            (0x40024414) /**< (SPI2) SPI Interrupt Enable Register */
#define REG_SPI2_IDR            (0x40024418) /**< (SPI2) SPI Interrupt Disable Register */
#define REG_SPI2_IMR            (0x4002441C) /**< (SPI2) SPI Interrupt Mask Register */
#define REG_SPI2_CSR            (0x40024430) /**< (SPI2) SPI Chip Select Register 0 */
#define REG_SPI2_CSR0           (0x40024430) /**< (SPI2) SPI Chip Select Register 0 */
#define REG_SPI2_CSR1           (0x40024434) /**< (SPI2) SPI Chip Select Register 1 */
#define REG_SPI2_CMPR           (0x40024448) /**< (SPI2) SPI Comparison Register */
#define REG_SPI2_WPMR           (0x400244E4) /**< (SPI2) SPI Write Protection Mode Register */
#define REG_SPI2_WPSR           (0x400244E8) /**< (SPI2) SPI Write Protection Status Register */
#define REG_SPI2_RPR            (0x40024500) /**< (SPI2) Receive Pointer Register */
#define REG_SPI2_RCR            (0x40024504) /**< (SPI2) Receive Counter Register */
#define REG_SPI2_TPR            (0x40024508) /**< (SPI2) Transmit Pointer Register */
#define REG_SPI2_TCR            (0x4002450C) /**< (SPI2) Transmit Counter Register */
#define REG_SPI2_RNPR           (0x40024510) /**< (SPI2) Receive Next Pointer Register */
#define REG_SPI2_RNCR           (0x40024514) /**< (SPI2) Receive Next Counter Register */
#define REG_SPI2_TNPR           (0x40024518) /**< (SPI2) Transmit Next Pointer Register */
#define REG_SPI2_TNCR           (0x4002451C) /**< (SPI2) Transmit Next Counter Register */
#define REG_SPI2_PTCR           (0x40024520) /**< (SPI2) Transfer Control Register */
#define REG_SPI2_PTSR           (0x40024524) /**< (SPI2) Transfer Status Register */

#else

#define REG_SPI2_CR             (*(__O  uint32_t*)0x40024400U) /**< (SPI2) SPI Control Register */
#define REG_SPI2_MR             (*(__IO uint32_t*)0x40024404U) /**< (SPI2) SPI Mode Register */
#define REG_SPI2_RDR            (*(__I  uint32_t*)0x40024408U) /**< (SPI2) SPI Receive Data Register */
#define REG_SPI2_TDR            (*(__O  uint32_t*)0x4002440CU) /**< (SPI2) SPI Transmit Data Register */
#define REG_SPI2_SR             (*(__I  uint32_t*)0x40024410U) /**< (SPI2) SPI Status Register */
#define REG_SPI2_IER            (*(__O  uint32_t*)0x40024414U) /**< (SPI2) SPI Interrupt Enable Register */
#define REG_SPI2_IDR            (*(__O  uint32_t*)0x40024418U) /**< (SPI2) SPI Interrupt Disable Register */
#define REG_SPI2_IMR            (*(__I  uint32_t*)0x4002441CU) /**< (SPI2) SPI Interrupt Mask Register */
#define REG_SPI2_CSR            (*(__IO uint32_t*)0x40024430U) /**< (SPI2) SPI Chip Select Register 0 */
#define REG_SPI2_CSR0           (*(__IO uint32_t*)0x40024430U) /**< (SPI2) SPI Chip Select Register 0 */
#define REG_SPI2_CSR1           (*(__IO uint32_t*)0x40024434U) /**< (SPI2) SPI Chip Select Register 1 */
#define REG_SPI2_CMPR           (*(__IO uint32_t*)0x40024448U) /**< (SPI2) SPI Comparison Register */
#define REG_SPI2_WPMR           (*(__IO uint32_t*)0x400244E4U) /**< (SPI2) SPI Write Protection Mode Register */
#define REG_SPI2_WPSR           (*(__I  uint32_t*)0x400244E8U) /**< (SPI2) SPI Write Protection Status Register */
#define REG_SPI2_RPR            (*(__IO uint32_t*)0x40024500U) /**< (SPI2) Receive Pointer Register */
#define REG_SPI2_RCR            (*(__IO uint32_t*)0x40024504U) /**< (SPI2) Receive Counter Register */
#define REG_SPI2_TPR            (*(__IO uint32_t*)0x40024508U) /**< (SPI2) Transmit Pointer Register */
#define REG_SPI2_TCR            (*(__IO uint32_t*)0x4002450CU) /**< (SPI2) Transmit Counter Register */
#define REG_SPI2_RNPR           (*(__IO uint32_t*)0x40024510U) /**< (SPI2) Receive Next Pointer Register */
#define REG_SPI2_RNCR           (*(__IO uint32_t*)0x40024514U) /**< (SPI2) Receive Next Counter Register */
#define REG_SPI2_TNPR           (*(__IO uint32_t*)0x40024518U) /**< (SPI2) Transmit Next Pointer Register */
#define REG_SPI2_TNCR           (*(__IO uint32_t*)0x4002451CU) /**< (SPI2) Transmit Next Counter Register */
#define REG_SPI2_PTCR           (*(__O  uint32_t*)0x40024520U) /**< (SPI2) Transfer Control Register */
#define REG_SPI2_PTSR           (*(__I  uint32_t*)0x40024524U) /**< (SPI2) Transfer Status Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for SPI2 peripheral ========== */
#define SPI2_DMAC_ID_TX                          22        
#define SPI2_DMAC_ID_RX                          8         

#endif /* _SAMG55_SPI2_INSTANCE_ */
