/**
 * \file
 *
 * \brief Instance description for SLCD
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

#ifndef _SAML22_SLCD_INSTANCE_
#define _SAML22_SLCD_INSTANCE_

/* ========== Register definition for SLCD peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_SLCD_CTRLA             (0x42003C00) /**< \brief (SLCD) Control A */
#define REG_SLCD_CTRLB             (0x42003C04) /**< \brief (SLCD) Control B */
#define REG_SLCD_CTRLC             (0x42003C06) /**< \brief (SLCD) Control C */
#define REG_SLCD_CTRLD             (0x42003C08) /**< \brief (SLCD) Control D */
#define REG_SLCD_EVCTRL            (0x42003C0C) /**< \brief (SLCD) Event Control */
#define REG_SLCD_INTENCLR          (0x42003C0D) /**< \brief (SLCD) Interrupt Enable Clear */
#define REG_SLCD_INTENSET          (0x42003C0E) /**< \brief (SLCD) Interrupt Enable Set */
#define REG_SLCD_INTFLAG           (0x42003C0F) /**< \brief (SLCD) Interrupt Flag Status and Clear */
#define REG_SLCD_STATUS            (0x42003C10) /**< \brief (SLCD) Status */
#define REG_SLCD_SYNCBUSY          (0x42003C14) /**< \brief (SLCD) Synchronization Busy */
#define REG_SLCD_FC0               (0x42003C18) /**< \brief (SLCD) Frame Counter 0 Configuration */
#define REG_SLCD_FC1               (0x42003C19) /**< \brief (SLCD) Frame Counter 1 Configuration */
#define REG_SLCD_FC2               (0x42003C1A) /**< \brief (SLCD) Frame Counter 2 Configuration */
#define REG_SLCD_LPENL             (0x42003C1C) /**< \brief (SLCD) LCD Pin Enable Low */
#define REG_SLCD_LPENH             (0x42003C20) /**< \brief (SLCD) LCD Pin Enable High */
#define REG_SLCD_SDATAL0           (0x42003C24) /**< \brief (SLCD) Segments Data Low for COM0 Line */
#define REG_SLCD_SDATAH0           (0x42003C28) /**< \brief (SLCD) Segments Data High for COM0 Line */
#define REG_SLCD_SDATAL1           (0x42003C2C) /**< \brief (SLCD) Segments Data Low for COM1 Line */
#define REG_SLCD_SDATAH1           (0x42003C30) /**< \brief (SLCD) Segments Data High for COM1 Line */
#define REG_SLCD_SDATAL2           (0x42003C34) /**< \brief (SLCD) Segments Data Low for COM2 Line */
#define REG_SLCD_SDATAH2           (0x42003C38) /**< \brief (SLCD) Segments Data High for COM2 Line */
#define REG_SLCD_SDATAL3           (0x42003C3C) /**< \brief (SLCD) Segments Data Low for COM3 Line */
#define REG_SLCD_SDATAH3           (0x42003C40) /**< \brief (SLCD) Segments Data High for COM3 Line */
#define REG_SLCD_SDATAL4           (0x42003C44) /**< \brief (SLCD) Segments Data Low for COM4 Line */
#define REG_SLCD_SDATAH4           (0x42003C48) /**< \brief (SLCD) Segments Data High for COM4 Line */
#define REG_SLCD_SDATAL5           (0x42003C4C) /**< \brief (SLCD) Segments Data Low for COM5 Line */
#define REG_SLCD_SDATAH5           (0x42003C50) /**< \brief (SLCD) Segments Data High for COM5 Line */
#define REG_SLCD_SDATAL6           (0x42003C54) /**< \brief (SLCD) Segments Data Low for COM6 Line */
#define REG_SLCD_SDATAH6           (0x42003C58) /**< \brief (SLCD) Segments Data High for COM6 Line */
#define REG_SLCD_SDATAL7           (0x42003C5C) /**< \brief (SLCD) Segments Data Low for COM7 Line */
#define REG_SLCD_SDATAH7           (0x42003C60) /**< \brief (SLCD) Segments Data High for COM7 Line */
#define REG_SLCD_ISDATA            (0x42003C64) /**< \brief (SLCD) Indirect Segments Data Access */
#define REG_SLCD_BCFG              (0x42003C68) /**< \brief (SLCD) Blink Configuration */
#define REG_SLCD_CSRCFG            (0x42003C6C) /**< \brief (SLCD) Circular Shift Register Configuration */
#define REG_SLCD_CMCFG             (0x42003C70) /**< \brief (SLCD) Character Mapping Configuration */
#define REG_SLCD_ACMCFG            (0x42003C74) /**< \brief (SLCD) Automated Character Mapping Configuration */
#define REG_SLCD_ABMCFG            (0x42003C78) /**< \brief (SLCD) Automated Bit Mapping Configuration */
#define REG_SLCD_CMDATA            (0x42003C7C) /**< \brief (SLCD) Character Mapping Segments Data */
#define REG_SLCD_CMDMASK           (0x42003C80) /**< \brief (SLCD) Character Mapping Segments Data Mask */
#define REG_SLCD_CMINDEX           (0x42003C84) /**< \brief (SLCD) Character Mapping SEG/COM Index */
#else
#define REG_SLCD_CTRLA             (*(RwReg  *)0x42003C00UL) /**< \brief (SLCD) Control A */
#define REG_SLCD_CTRLB             (*(RwReg16*)0x42003C04UL) /**< \brief (SLCD) Control B */
#define REG_SLCD_CTRLC             (*(RwReg16*)0x42003C06UL) /**< \brief (SLCD) Control C */
#define REG_SLCD_CTRLD             (*(RwReg8 *)0x42003C08UL) /**< \brief (SLCD) Control D */
#define REG_SLCD_EVCTRL            (*(RwReg8 *)0x42003C0CUL) /**< \brief (SLCD) Event Control */
#define REG_SLCD_INTENCLR          (*(RwReg8 *)0x42003C0DUL) /**< \brief (SLCD) Interrupt Enable Clear */
#define REG_SLCD_INTENSET          (*(RwReg8 *)0x42003C0EUL) /**< \brief (SLCD) Interrupt Enable Set */
#define REG_SLCD_INTFLAG           (*(RwReg8 *)0x42003C0FUL) /**< \brief (SLCD) Interrupt Flag Status and Clear */
#define REG_SLCD_STATUS            (*(RoReg8 *)0x42003C10UL) /**< \brief (SLCD) Status */
#define REG_SLCD_SYNCBUSY          (*(RoReg  *)0x42003C14UL) /**< \brief (SLCD) Synchronization Busy */
#define REG_SLCD_FC0               (*(RwReg8 *)0x42003C18UL) /**< \brief (SLCD) Frame Counter 0 Configuration */
#define REG_SLCD_FC1               (*(RwReg8 *)0x42003C19UL) /**< \brief (SLCD) Frame Counter 1 Configuration */
#define REG_SLCD_FC2               (*(RwReg8 *)0x42003C1AUL) /**< \brief (SLCD) Frame Counter 2 Configuration */
#define REG_SLCD_LPENL             (*(RwReg  *)0x42003C1CUL) /**< \brief (SLCD) LCD Pin Enable Low */
#define REG_SLCD_LPENH             (*(RwReg  *)0x42003C20UL) /**< \brief (SLCD) LCD Pin Enable High */
#define REG_SLCD_SDATAL0           (*(RwReg  *)0x42003C24UL) /**< \brief (SLCD) Segments Data Low for COM0 Line */
#define REG_SLCD_SDATAH0           (*(RwReg  *)0x42003C28UL) /**< \brief (SLCD) Segments Data High for COM0 Line */
#define REG_SLCD_SDATAL1           (*(RwReg  *)0x42003C2CUL) /**< \brief (SLCD) Segments Data Low for COM1 Line */
#define REG_SLCD_SDATAH1           (*(RwReg  *)0x42003C30UL) /**< \brief (SLCD) Segments Data High for COM1 Line */
#define REG_SLCD_SDATAL2           (*(RwReg  *)0x42003C34UL) /**< \brief (SLCD) Segments Data Low for COM2 Line */
#define REG_SLCD_SDATAH2           (*(RwReg  *)0x42003C38UL) /**< \brief (SLCD) Segments Data High for COM2 Line */
#define REG_SLCD_SDATAL3           (*(RwReg  *)0x42003C3CUL) /**< \brief (SLCD) Segments Data Low for COM3 Line */
#define REG_SLCD_SDATAH3           (*(RwReg  *)0x42003C40UL) /**< \brief (SLCD) Segments Data High for COM3 Line */
#define REG_SLCD_SDATAL4           (*(RwReg  *)0x42003C44UL) /**< \brief (SLCD) Segments Data Low for COM4 Line */
#define REG_SLCD_SDATAH4           (*(RwReg  *)0x42003C48UL) /**< \brief (SLCD) Segments Data High for COM4 Line */
#define REG_SLCD_SDATAL5           (*(RwReg  *)0x42003C4CUL) /**< \brief (SLCD) Segments Data Low for COM5 Line */
#define REG_SLCD_SDATAH5           (*(RwReg  *)0x42003C50UL) /**< \brief (SLCD) Segments Data High for COM5 Line */
#define REG_SLCD_SDATAL6           (*(RwReg  *)0x42003C54UL) /**< \brief (SLCD) Segments Data Low for COM6 Line */
#define REG_SLCD_SDATAH6           (*(RwReg  *)0x42003C58UL) /**< \brief (SLCD) Segments Data High for COM6 Line */
#define REG_SLCD_SDATAL7           (*(RwReg  *)0x42003C5CUL) /**< \brief (SLCD) Segments Data Low for COM7 Line */
#define REG_SLCD_SDATAH7           (*(RwReg  *)0x42003C60UL) /**< \brief (SLCD) Segments Data High for COM7 Line */
#define REG_SLCD_ISDATA            (*(WoReg  *)0x42003C64UL) /**< \brief (SLCD) Indirect Segments Data Access */
#define REG_SLCD_BCFG              (*(RwReg  *)0x42003C68UL) /**< \brief (SLCD) Blink Configuration */
#define REG_SLCD_CSRCFG            (*(RwReg  *)0x42003C6CUL) /**< \brief (SLCD) Circular Shift Register Configuration */
#define REG_SLCD_CMCFG             (*(RwReg8 *)0x42003C70UL) /**< \brief (SLCD) Character Mapping Configuration */
#define REG_SLCD_ACMCFG            (*(RwReg  *)0x42003C74UL) /**< \brief (SLCD) Automated Character Mapping Configuration */
#define REG_SLCD_ABMCFG            (*(RwReg8 *)0x42003C78UL) /**< \brief (SLCD) Automated Bit Mapping Configuration */
#define REG_SLCD_CMDATA            (*(WoReg  *)0x42003C7CUL) /**< \brief (SLCD) Character Mapping Segments Data */
#define REG_SLCD_CMDMASK           (*(RwReg  *)0x42003C80UL) /**< \brief (SLCD) Character Mapping Segments Data Mask */
#define REG_SLCD_CMINDEX           (*(RwReg16*)0x42003C84UL) /**< \brief (SLCD) Character Mapping SEG/COM Index */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance parameters for SLCD peripheral ========== */
#define SLCD_DMAC_ID_ABMDRDY        34      
#define SLCD_DMAC_ID_ACMDRDY        33      
#define SLCD_DMAC_ID_DMU            32      
#define SLCD_MAX_COM                8        // Max number of COM lines (4 or 8)
#define SLCD_MAX_SEG                44       // Max number of SEG lines (24 or 44)
#define SLCD_NB_LP                  52       // Number of LCD pins ([28..64] or [48..64])

#endif /* _SAML22_SLCD_INSTANCE_ */
