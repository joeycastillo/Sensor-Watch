/**
 * \file
 *
 * \brief Instance description for UHP
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
#ifndef _SAMG55_UHP_INSTANCE_H_
#define _SAMG55_UHP_INSTANCE_H_

/* ========== Register definition for UHP peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_UHP_HCREVISION      (0x4004C000) /**< (UHP) OHCI Revision Number Register */
#define REG_UHP_HCCONTROL       (0x4004C004) /**< (UHP) HC Operating Mode Register */
#define REG_UHP_HCCOMMANDSTATUS (0x4004C008) /**< (UHP) HC Command and Status Register */
#define REG_UHP_HCINTERRUPTSTATUS (0x4004C00C) /**< (UHP) HC Interrupt and Status Register */
#define REG_UHP_HCINTERRUPTENABLE (0x4004C010) /**< (UHP) HC Interrupt Enable Register */
#define REG_UHP_HCINTERRUPTDISABLE (0x4004C014) /**< (UHP) HC Interrupt Disable Register */
#define REG_UHP_HCHCCA          (0x4004C018) /**< (UHP) HC HCCA Address Register */
#define REG_UHP_HCPERIODCURRENTED (0x4004C01C) /**< (UHP) HC Current Periodic Register */
#define REG_UHP_HCCONTROLHEADED (0x4004C020) /**< (UHP) HC Head Control Register */
#define REG_UHP_HCCONTROLCURRENTED (0x4004C024) /**< (UHP) HC Current Control Register */
#define REG_UHP_HCBULKHEADED    (0x4004C028) /**< (UHP) HC Head Bulk Register */
#define REG_UHP_HCBULKCURRENTED (0x4004C02C) /**< (UHP) HC Current Bulk Register */
#define REG_UHP_HCDONEHEAD      (0x4004C030) /**< (UHP) HC Head Done Register */
#define REG_UHP_HCFMINTERVAL    (0x4004C034) /**< (UHP) HC Frame Interval Register */
#define REG_UHP_HCFMREMAINING   (0x4004C038) /**< (UHP) HC Frame Remaining Register */
#define REG_UHP_HCFMNUMBER      (0x4004C03C) /**< (UHP) HC Frame Number Register */
#define REG_UHP_HCPERIODICSTART (0x4004C040) /**< (UHP) HC Periodic Start Register */
#define REG_UHP_HCLSTHRESHOLD   (0x4004C044) /**< (UHP) HC Low-Speed Threshold Register */
#define REG_UHP_HCRHDESCRIPTORA (0x4004C048) /**< (UHP) HC Root Hub A Register */
#define REG_UHP_HCRHDESCRIPTORB (0x4004C04C) /**< (UHP) HC Root Hub B Register */
#define REG_UHP_HCRHSTATUS      (0x4004C050) /**< (UHP) HC Root Hub Status Register */
#define REG_UHP_HCRHPORTSTATUS  (0x4004C054) /**< (UHP) HC Port 1 Status and Control Register 0 */
#define REG_UHP_HCRHPORTSTATUS0 (0x4004C054) /**< (UHP) HC Port 1 Status and Control Register 0 */
#define REG_UHP_HCRHPORTSTATUS1 (0x4004C058) /**< (UHP) HC Port 1 Status and Control Register 1 */

#else

#define REG_UHP_HCREVISION      (*(__I  uint32_t*)0x4004C000U) /**< (UHP) OHCI Revision Number Register */
#define REG_UHP_HCCONTROL       (*(__IO uint32_t*)0x4004C004U) /**< (UHP) HC Operating Mode Register */
#define REG_UHP_HCCOMMANDSTATUS (*(__IO uint32_t*)0x4004C008U) /**< (UHP) HC Command and Status Register */
#define REG_UHP_HCINTERRUPTSTATUS (*(__IO uint32_t*)0x4004C00CU) /**< (UHP) HC Interrupt and Status Register */
#define REG_UHP_HCINTERRUPTENABLE (*(__IO uint32_t*)0x4004C010U) /**< (UHP) HC Interrupt Enable Register */
#define REG_UHP_HCINTERRUPTDISABLE (*(__IO uint32_t*)0x4004C014U) /**< (UHP) HC Interrupt Disable Register */
#define REG_UHP_HCHCCA          (*(__IO uint32_t*)0x4004C018U) /**< (UHP) HC HCCA Address Register */
#define REG_UHP_HCPERIODCURRENTED (*(__I  uint32_t*)0x4004C01CU) /**< (UHP) HC Current Periodic Register */
#define REG_UHP_HCCONTROLHEADED (*(__IO uint32_t*)0x4004C020U) /**< (UHP) HC Head Control Register */
#define REG_UHP_HCCONTROLCURRENTED (*(__IO uint32_t*)0x4004C024U) /**< (UHP) HC Current Control Register */
#define REG_UHP_HCBULKHEADED    (*(__IO uint32_t*)0x4004C028U) /**< (UHP) HC Head Bulk Register */
#define REG_UHP_HCBULKCURRENTED (*(__IO uint32_t*)0x4004C02CU) /**< (UHP) HC Current Bulk Register */
#define REG_UHP_HCDONEHEAD      (*(__I  uint32_t*)0x4004C030U) /**< (UHP) HC Head Done Register */
#define REG_UHP_HCFMINTERVAL    (*(__IO uint32_t*)0x4004C034U) /**< (UHP) HC Frame Interval Register */
#define REG_UHP_HCFMREMAINING   (*(__I  uint32_t*)0x4004C038U) /**< (UHP) HC Frame Remaining Register */
#define REG_UHP_HCFMNUMBER      (*(__I  uint32_t*)0x4004C03CU) /**< (UHP) HC Frame Number Register */
#define REG_UHP_HCPERIODICSTART (*(__IO uint32_t*)0x4004C040U) /**< (UHP) HC Periodic Start Register */
#define REG_UHP_HCLSTHRESHOLD   (*(__IO uint32_t*)0x4004C044U) /**< (UHP) HC Low-Speed Threshold Register */
#define REG_UHP_HCRHDESCRIPTORA (*(__IO uint32_t*)0x4004C048U) /**< (UHP) HC Root Hub A Register */
#define REG_UHP_HCRHDESCRIPTORB (*(__IO uint32_t*)0x4004C04CU) /**< (UHP) HC Root Hub B Register */
#define REG_UHP_HCRHSTATUS      (*(__IO uint32_t*)0x4004C050U) /**< (UHP) HC Root Hub Status Register */
#define REG_UHP_HCRHPORTSTATUS  (*(__IO uint32_t*)0x4004C054U) /**< (UHP) HC Port 1 Status and Control Register 0 */
#define REG_UHP_HCRHPORTSTATUS0 (*(__IO uint32_t*)0x4004C054U) /**< (UHP) HC Port 1 Status and Control Register 0 */
#define REG_UHP_HCRHPORTSTATUS1 (*(__IO uint32_t*)0x4004C058U) /**< (UHP) HC Port 1 Status and Control Register 1 */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for UHP peripheral ========== */
#define UHP_INSTANCE_ID                          47        

#endif /* _SAMG55_UHP_INSTANCE_ */
