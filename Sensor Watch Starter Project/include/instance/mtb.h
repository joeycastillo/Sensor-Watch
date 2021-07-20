/**
 * \file
 *
 * \brief Instance description for MTB
 *
 * Copyright (c) 2018 Microchip Technology Inc.
 *
 * \asf_license_start
 *
 * \page License
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the Licence at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * \asf_license_stop
 *
 */

#ifndef _SAML22_MTB_INSTANCE_
#define _SAML22_MTB_INSTANCE_

/* ========== Register definition for MTB peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_MTB_POSITION           (0x4100A000) /**< \brief (MTB) MTB Position */
#define REG_MTB_MASTER             (0x4100A004) /**< \brief (MTB) MTB Master */
#define REG_MTB_FLOW               (0x4100A008) /**< \brief (MTB) MTB Flow */
#define REG_MTB_BASE               (0x4100A00C) /**< \brief (MTB) MTB Base */
#define REG_MTB_ITCTRL             (0x4100AF00) /**< \brief (MTB) MTB Integration Mode Control */
#define REG_MTB_CLAIMSET           (0x4100AFA0) /**< \brief (MTB) MTB Claim Set */
#define REG_MTB_CLAIMCLR           (0x4100AFA4) /**< \brief (MTB) MTB Claim Clear */
#define REG_MTB_LOCKACCESS         (0x4100AFB0) /**< \brief (MTB) MTB Lock Access */
#define REG_MTB_LOCKSTATUS         (0x4100AFB4) /**< \brief (MTB) MTB Lock Status */
#define REG_MTB_AUTHSTATUS         (0x4100AFB8) /**< \brief (MTB) MTB Authentication Status */
#define REG_MTB_DEVARCH            (0x4100AFBC) /**< \brief (MTB) MTB Device Architecture */
#define REG_MTB_DEVID              (0x4100AFC8) /**< \brief (MTB) MTB Device Configuration */
#define REG_MTB_DEVTYPE            (0x4100AFCC) /**< \brief (MTB) MTB Device Type */
#define REG_MTB_PID4               (0x4100AFD0) /**< \brief (MTB) Peripheral Identification 4 */
#define REG_MTB_PID5               (0x4100AFD4) /**< \brief (MTB) Peripheral Identification 5 */
#define REG_MTB_PID6               (0x4100AFD8) /**< \brief (MTB) Peripheral Identification 6 */
#define REG_MTB_PID7               (0x4100AFDC) /**< \brief (MTB) Peripheral Identification 7 */
#define REG_MTB_PID0               (0x4100AFE0) /**< \brief (MTB) Peripheral Identification 0 */
#define REG_MTB_PID1               (0x4100AFE4) /**< \brief (MTB) Peripheral Identification 1 */
#define REG_MTB_PID2               (0x4100AFE8) /**< \brief (MTB) Peripheral Identification 2 */
#define REG_MTB_PID3               (0x4100AFEC) /**< \brief (MTB) Peripheral Identification 3 */
#define REG_MTB_CID0               (0x4100AFF0) /**< \brief (MTB) Component Identification 0 */
#define REG_MTB_CID1               (0x4100AFF4) /**< \brief (MTB) Component Identification 1 */
#define REG_MTB_CID2               (0x4100AFF8) /**< \brief (MTB) Component Identification 2 */
#define REG_MTB_CID3               (0x4100AFFC) /**< \brief (MTB) Component Identification 3 */
#else
#define REG_MTB_POSITION           (*(RwReg  *)0x4100A000UL) /**< \brief (MTB) MTB Position */
#define REG_MTB_MASTER             (*(RwReg  *)0x4100A004UL) /**< \brief (MTB) MTB Master */
#define REG_MTB_FLOW               (*(RwReg  *)0x4100A008UL) /**< \brief (MTB) MTB Flow */
#define REG_MTB_BASE               (*(RoReg  *)0x4100A00CUL) /**< \brief (MTB) MTB Base */
#define REG_MTB_ITCTRL             (*(RwReg  *)0x4100AF00UL) /**< \brief (MTB) MTB Integration Mode Control */
#define REG_MTB_CLAIMSET           (*(RwReg  *)0x4100AFA0UL) /**< \brief (MTB) MTB Claim Set */
#define REG_MTB_CLAIMCLR           (*(RwReg  *)0x4100AFA4UL) /**< \brief (MTB) MTB Claim Clear */
#define REG_MTB_LOCKACCESS         (*(RwReg  *)0x4100AFB0UL) /**< \brief (MTB) MTB Lock Access */
#define REG_MTB_LOCKSTATUS         (*(RoReg  *)0x4100AFB4UL) /**< \brief (MTB) MTB Lock Status */
#define REG_MTB_AUTHSTATUS         (*(RoReg  *)0x4100AFB8UL) /**< \brief (MTB) MTB Authentication Status */
#define REG_MTB_DEVARCH            (*(RoReg  *)0x4100AFBCUL) /**< \brief (MTB) MTB Device Architecture */
#define REG_MTB_DEVID              (*(RoReg  *)0x4100AFC8UL) /**< \brief (MTB) MTB Device Configuration */
#define REG_MTB_DEVTYPE            (*(RoReg  *)0x4100AFCCUL) /**< \brief (MTB) MTB Device Type */
#define REG_MTB_PID4               (*(RoReg  *)0x4100AFD0UL) /**< \brief (MTB) Peripheral Identification 4 */
#define REG_MTB_PID5               (*(RoReg  *)0x4100AFD4UL) /**< \brief (MTB) Peripheral Identification 5 */
#define REG_MTB_PID6               (*(RoReg  *)0x4100AFD8UL) /**< \brief (MTB) Peripheral Identification 6 */
#define REG_MTB_PID7               (*(RoReg  *)0x4100AFDCUL) /**< \brief (MTB) Peripheral Identification 7 */
#define REG_MTB_PID0               (*(RoReg  *)0x4100AFE0UL) /**< \brief (MTB) Peripheral Identification 0 */
#define REG_MTB_PID1               (*(RoReg  *)0x4100AFE4UL) /**< \brief (MTB) Peripheral Identification 1 */
#define REG_MTB_PID2               (*(RoReg  *)0x4100AFE8UL) /**< \brief (MTB) Peripheral Identification 2 */
#define REG_MTB_PID3               (*(RoReg  *)0x4100AFECUL) /**< \brief (MTB) Peripheral Identification 3 */
#define REG_MTB_CID0               (*(RoReg  *)0x4100AFF0UL) /**< \brief (MTB) Component Identification 0 */
#define REG_MTB_CID1               (*(RoReg  *)0x4100AFF4UL) /**< \brief (MTB) Component Identification 1 */
#define REG_MTB_CID2               (*(RoReg  *)0x4100AFF8UL) /**< \brief (MTB) Component Identification 2 */
#define REG_MTB_CID3               (*(RoReg  *)0x4100AFFCUL) /**< \brief (MTB) Component Identification 3 */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */


#endif /* _SAML22_MTB_INSTANCE_ */
