/**
 * \file
 *
 * \brief Instance description for MATRIX
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
#ifndef _SAMG55_MATRIX_INSTANCE_H_
#define _SAMG55_MATRIX_INSTANCE_H_

/* ========== Register definition for MATRIX peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_MATRIX_MCFG         (0x400E0200) /**< (MATRIX) Master Configuration Register 0 */
#define REG_MATRIX_MCFG0        (0x400E0200) /**< (MATRIX) Master Configuration Register 0 */
#define REG_MATRIX_MCFG1        (0x400E0204) /**< (MATRIX) Master Configuration Register 1 */
#define REG_MATRIX_MCFG2        (0x400E0208) /**< (MATRIX) Master Configuration Register 2 */
#define REG_MATRIX_SCFG         (0x400E0240) /**< (MATRIX) Slave Configuration Register 0 */
#define REG_MATRIX_SCFG0        (0x400E0240) /**< (MATRIX) Slave Configuration Register 0 */
#define REG_MATRIX_SCFG1        (0x400E0244) /**< (MATRIX) Slave Configuration Register 1 */
#define REG_MATRIX_SCFG2        (0x400E0248) /**< (MATRIX) Slave Configuration Register 2 */
#define REG_MATRIX_SCFG3        (0x400E024C) /**< (MATRIX) Slave Configuration Register 3 */
#define REG_MATRIX_PRAS0        (0x400E0280) /**< (MATRIX) Priority Register A for Slave 0 */
#define REG_MATRIX_PRAS1        (0x400E0288) /**< (MATRIX) Priority Register A for Slave 1 */
#define REG_MATRIX_PRAS2        (0x400E0290) /**< (MATRIX) Priority Register A for Slave 2 */
#define REG_MATRIX_PRAS3        (0x400E0298) /**< (MATRIX) Priority Register A for Slave 3 */
#define REG_CCFG_SYSIO          (0x400E0314) /**< (MATRIX) System I/O Configuration Register */
#define REG_CCFG_DYNCKG         (0x400E0318) /**< (MATRIX) Dynamic Clock Gating Register */
#define REG_CCFG_I2SCLKSEL      (0x400E031C) /**< (MATRIX) I2S Clock Source Selection Register */
#define REG_CCFG_USBMR          (0x400E0320) /**< (MATRIX) USB Management Register */
#define REG_MATRIX_WPMR         (0x400E03E4) /**< (MATRIX) Write Protection Mode Register */
#define REG_MATRIX_WPSR         (0x400E03E8) /**< (MATRIX) Write Protection Status Register */

#else

#define REG_MATRIX_MCFG         (*(__IO uint32_t*)0x400E0200U) /**< (MATRIX) Master Configuration Register 0 */
#define REG_MATRIX_MCFG0        (*(__IO uint32_t*)0x400E0200U) /**< (MATRIX) Master Configuration Register 0 */
#define REG_MATRIX_MCFG1        (*(__IO uint32_t*)0x400E0204U) /**< (MATRIX) Master Configuration Register 1 */
#define REG_MATRIX_MCFG2        (*(__IO uint32_t*)0x400E0208U) /**< (MATRIX) Master Configuration Register 2 */
#define REG_MATRIX_SCFG         (*(__IO uint32_t*)0x400E0240U) /**< (MATRIX) Slave Configuration Register 0 */
#define REG_MATRIX_SCFG0        (*(__IO uint32_t*)0x400E0240U) /**< (MATRIX) Slave Configuration Register 0 */
#define REG_MATRIX_SCFG1        (*(__IO uint32_t*)0x400E0244U) /**< (MATRIX) Slave Configuration Register 1 */
#define REG_MATRIX_SCFG2        (*(__IO uint32_t*)0x400E0248U) /**< (MATRIX) Slave Configuration Register 2 */
#define REG_MATRIX_SCFG3        (*(__IO uint32_t*)0x400E024CU) /**< (MATRIX) Slave Configuration Register 3 */
#define REG_MATRIX_PRAS0        (*(__IO uint32_t*)0x400E0280U) /**< (MATRIX) Priority Register A for Slave 0 */
#define REG_MATRIX_PRAS1        (*(__IO uint32_t*)0x400E0288U) /**< (MATRIX) Priority Register A for Slave 1 */
#define REG_MATRIX_PRAS2        (*(__IO uint32_t*)0x400E0290U) /**< (MATRIX) Priority Register A for Slave 2 */
#define REG_MATRIX_PRAS3        (*(__IO uint32_t*)0x400E0298U) /**< (MATRIX) Priority Register A for Slave 3 */
#define REG_CCFG_SYSIO          (*(__IO uint32_t*)0x400E0314U) /**< (MATRIX) System I/O Configuration Register */
#define REG_CCFG_DYNCKG         (*(__IO uint32_t*)0x400E0318U) /**< (MATRIX) Dynamic Clock Gating Register */
#define REG_CCFG_I2SCLKSEL      (*(__IO uint32_t*)0x400E031CU) /**< (MATRIX) I2S Clock Source Selection Register */
#define REG_CCFG_USBMR          (*(__IO uint32_t*)0x400E0320U) /**< (MATRIX) USB Management Register */
#define REG_MATRIX_WPMR         (*(__IO uint32_t*)0x400E03E4U) /**< (MATRIX) Write Protection Mode Register */
#define REG_MATRIX_WPSR         (*(__I  uint32_t*)0x400E03E8U) /**< (MATRIX) Write Protection Status Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAMG55_MATRIX_INSTANCE_ */
