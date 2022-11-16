/**
 * \file
 *
 * \brief Instance description for EFC
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
#ifndef _SAMG55_EFC_INSTANCE_H_
#define _SAMG55_EFC_INSTANCE_H_

/* ========== Register definition for EFC peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_EEFC_FMR            (0x400E0A00) /**< (EFC) EEFC Flash Mode Register */
#define REG_EEFC_FCR            (0x400E0A04) /**< (EFC) EEFC Flash Command Register */
#define REG_EEFC_FSR            (0x400E0A08) /**< (EFC) EEFC Flash Status Register */
#define REG_EEFC_FRR            (0x400E0A0C) /**< (EFC) EEFC Flash Result Register */
#define REG_EEFC_WPMR           (0x400E0AE4) /**< (EFC) Write Protection Mode Register */

#else

#define REG_EEFC_FMR            (*(__IO uint32_t*)0x400E0A00U) /**< (EFC) EEFC Flash Mode Register */
#define REG_EEFC_FCR            (*(__O  uint32_t*)0x400E0A04U) /**< (EFC) EEFC Flash Command Register */
#define REG_EEFC_FSR            (*(__I  uint32_t*)0x400E0A08U) /**< (EFC) EEFC Flash Status Register */
#define REG_EEFC_FRR            (*(__I  uint32_t*)0x400E0A0CU) /**< (EFC) EEFC Flash Result Register */
#define REG_EEFC_WPMR           (*(__IO uint32_t*)0x400E0AE4U) /**< (EFC) Write Protection Mode Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for EFC peripheral ========== */
#define EFC_FLASH_SIZE                           524288    
#define EFC_INSTANCE_ID                          6         
#define EFC_PAGES_PR_REGION                      16        
#define EFC_PAGE_SIZE                            512       

#endif /* _SAMG55_EFC_INSTANCE_ */
