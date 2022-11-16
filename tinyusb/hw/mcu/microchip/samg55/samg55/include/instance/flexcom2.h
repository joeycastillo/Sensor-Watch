/**
 * \file
 *
 * \brief Instance description for FLEXCOM2
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
#ifndef _SAMG55_FLEXCOM2_INSTANCE_H_
#define _SAMG55_FLEXCOM2_INSTANCE_H_

/* ========== Register definition for FLEXCOM2 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_FLEXCOM2_MR         (0x40024000) /**< (FLEXCOM2) FLEXCOM Mode register */
#define REG_FLEXCOM2_RHR        (0x40024010) /**< (FLEXCOM2) FLEXCOM Receive Holding Register */
#define REG_FLEXCOM2_THR        (0x40024020) /**< (FLEXCOM2) FLEXCOM Transmit Holding Register */

#else

#define REG_FLEXCOM2_MR         (*(__IO uint32_t*)0x40024000U) /**< (FLEXCOM2) FLEXCOM Mode register */
#define REG_FLEXCOM2_RHR        (*(__I  uint32_t*)0x40024010U) /**< (FLEXCOM2) FLEXCOM Receive Holding Register */
#define REG_FLEXCOM2_THR        (*(__IO uint32_t*)0x40024020U) /**< (FLEXCOM2) FLEXCOM Transmit Holding Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for FLEXCOM2 peripheral ========== */
#define FLEXCOM2_INSTANCE_ID                     14        
#define FLEXCOM2_DMAC_ID_TX                      22        
#define FLEXCOM2_DMAC_ID_RX                      8         

#endif /* _SAMG55_FLEXCOM2_INSTANCE_ */
