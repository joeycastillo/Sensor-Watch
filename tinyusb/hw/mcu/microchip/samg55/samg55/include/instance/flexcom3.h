/**
 * \file
 *
 * \brief Instance description for FLEXCOM3
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
#ifndef _SAMG55_FLEXCOM3_INSTANCE_H_
#define _SAMG55_FLEXCOM3_INSTANCE_H_

/* ========== Register definition for FLEXCOM3 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_FLEXCOM3_MR         (0x40018000) /**< (FLEXCOM3) FLEXCOM Mode register */
#define REG_FLEXCOM3_RHR        (0x40018010) /**< (FLEXCOM3) FLEXCOM Receive Holding Register */
#define REG_FLEXCOM3_THR        (0x40018020) /**< (FLEXCOM3) FLEXCOM Transmit Holding Register */

#else

#define REG_FLEXCOM3_MR         (*(__IO uint32_t*)0x40018000U) /**< (FLEXCOM3) FLEXCOM Mode register */
#define REG_FLEXCOM3_RHR        (*(__I  uint32_t*)0x40018010U) /**< (FLEXCOM3) FLEXCOM Receive Holding Register */
#define REG_FLEXCOM3_THR        (*(__IO uint32_t*)0x40018020U) /**< (FLEXCOM3) FLEXCOM Transmit Holding Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for FLEXCOM3 peripheral ========== */
#define FLEXCOM3_INSTANCE_ID                     19        
#define FLEXCOM3_DMAC_ID_TX                      17        
#define FLEXCOM3_DMAC_ID_RX                      0         

#endif /* _SAMG55_FLEXCOM3_INSTANCE_ */
