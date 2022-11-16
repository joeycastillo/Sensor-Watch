/**
 * \file
 *
 * \brief Instance description for CMCC
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
#ifndef _SAMG55_CMCC_INSTANCE_H_
#define _SAMG55_CMCC_INSTANCE_H_

/* ========== Register definition for CMCC peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_CMCC_TYPE           (0x4003C000) /**< (CMCC) Cache Controller Type Register */
#define REG_CMCC_CFG            (0x4003C004) /**< (CMCC) Cache Controller Configuration Register */
#define REG_CMCC_CTRL           (0x4003C008) /**< (CMCC) Cache Controller Control Register */
#define REG_CMCC_SR             (0x4003C00C) /**< (CMCC) Cache Controller Status Register */
#define REG_CMCC_MAINT0         (0x4003C020) /**< (CMCC) Cache Controller Maintenance Register 0 */
#define REG_CMCC_MAINT1         (0x4003C024) /**< (CMCC) Cache Controller Maintenance Register 1 */
#define REG_CMCC_MCFG           (0x4003C028) /**< (CMCC) Cache Controller Monitor Configuration Register */
#define REG_CMCC_MEN            (0x4003C02C) /**< (CMCC) Cache Controller Monitor Enable Register */
#define REG_CMCC_MCTRL          (0x4003C030) /**< (CMCC) Cache Controller Monitor Control Register */
#define REG_CMCC_MSR            (0x4003C034) /**< (CMCC) Cache Controller Monitor Status Register */

#else

#define REG_CMCC_TYPE           (*(__I  uint32_t*)0x4003C000U) /**< (CMCC) Cache Controller Type Register */
#define REG_CMCC_CFG            (*(__IO uint32_t*)0x4003C004U) /**< (CMCC) Cache Controller Configuration Register */
#define REG_CMCC_CTRL           (*(__O  uint32_t*)0x4003C008U) /**< (CMCC) Cache Controller Control Register */
#define REG_CMCC_SR             (*(__I  uint32_t*)0x4003C00CU) /**< (CMCC) Cache Controller Status Register */
#define REG_CMCC_MAINT0         (*(__O  uint32_t*)0x4003C020U) /**< (CMCC) Cache Controller Maintenance Register 0 */
#define REG_CMCC_MAINT1         (*(__O  uint32_t*)0x4003C024U) /**< (CMCC) Cache Controller Maintenance Register 1 */
#define REG_CMCC_MCFG           (*(__IO uint32_t*)0x4003C028U) /**< (CMCC) Cache Controller Monitor Configuration Register */
#define REG_CMCC_MEN            (*(__IO uint32_t*)0x4003C02CU) /**< (CMCC) Cache Controller Monitor Enable Register */
#define REG_CMCC_MCTRL          (*(__O  uint32_t*)0x4003C030U) /**< (CMCC) Cache Controller Monitor Control Register */
#define REG_CMCC_MSR            (*(__I  uint32_t*)0x4003C034U) /**< (CMCC) Cache Controller Monitor Status Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAMG55_CMCC_INSTANCE_ */
