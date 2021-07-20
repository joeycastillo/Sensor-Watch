/**
 * \file
 *
 * \brief Instance description for SLCD
 *
 * Copyright (c) 2015 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

#ifndef _SAML22_SLCD_INSTANCE_
#define _SAML22_SLCD_INSTANCE_

/* ========== Register definition for SLCD peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_SLCD_CTRLA             (0x42003C00U) /**< \brief (SLCD) Control A */
#define REG_SLCD_CTRLB             (0x42003C04U) /**< \brief (SLCD) Control B */
#define REG_SLCD_CTRLC             (0x42003C06U) /**< \brief (SLCD) Control C */
#define REG_SLCD_CTRLD             (0x42003C08U) /**< \brief (SLCD) Control D */
#define REG_SLCD_EVCTRL            (0x42003C0CU) /**< \brief (SLCD) Event Control */
#define REG_SLCD_INTENCLR          (0x42003C0DU) /**< \brief (SLCD) Interrupt Enable Clear */
#define REG_SLCD_INTENSET          (0x42003C0EU) /**< \brief (SLCD) Interrupt Enable Set */
#define REG_SLCD_INTFLAG           (0x42003C0FU) /**< \brief (SLCD) Interrupt Flag Status and Clear */
#define REG_SLCD_STATUS            (0x42003C10U) /**< \brief (SLCD) Status */
#define REG_SLCD_SYNCBUSY          (0x42003C14U) /**< \brief (SLCD) Synchronization Busy */
#define REG_SLCD_FC0               (0x42003C18U) /**< \brief (SLCD) Frame Counter 0 Configuration */
#define REG_SLCD_FC1               (0x42003C19U) /**< \brief (SLCD) Frame Counter 1 Configuration */
#define REG_SLCD_FC2               (0x42003C1AU) /**< \brief (SLCD) Frame Counter 2 Configuration */
#define REG_SLCD_LPENL             (0x42003C1CU) /**< \brief (SLCD) LCD Pin Enable Low */
#define REG_SLCD_LPENH             (0x42003C20U) /**< \brief (SLCD) LCD Pin Enable High */
#define REG_SLCD_SDATAL0           (0x42003C24U) /**< \brief (SLCD) Segments Data Low for COM0 Line */
#define REG_SLCD_SDATAH0           (0x42003C28U) /**< \brief (SLCD) Segments Data High for COM0 Line */
#define REG_SLCD_SDATAL1           (0x42003C2CU) /**< \brief (SLCD) Segments Data Low for COM1 Line */
#define REG_SLCD_SDATAH1           (0x42003C30U) /**< \brief (SLCD) Segments Data High for COM1 Line */
#define REG_SLCD_SDATAL2           (0x42003C34U) /**< \brief (SLCD) Segments Data Low for COM2 Line */
#define REG_SLCD_SDATAH2           (0x42003C38U) /**< \brief (SLCD) Segments Data High for COM2 Line */
#define REG_SLCD_SDATAL3           (0x42003C3CU) /**< \brief (SLCD) Segments Data Low for COM3 Line */
#define REG_SLCD_SDATAH3           (0x42003C40U) /**< \brief (SLCD) Segments Data High for COM3 Line */
#define REG_SLCD_SDATAL4           (0x42003C44U) /**< \brief (SLCD) Segments Data Low for COM4 Line */
#define REG_SLCD_SDATAH4           (0x42003C48U) /**< \brief (SLCD) Segments Data High for COM4 Line */
#define REG_SLCD_SDATAL5           (0x42003C4CU) /**< \brief (SLCD) Segments Data Low for COM5 Line */
#define REG_SLCD_SDATAH5           (0x42003C50U) /**< \brief (SLCD) Segments Data High for COM5 Line */
#define REG_SLCD_SDATAL6           (0x42003C54U) /**< \brief (SLCD) Segments Data Low for COM6 Line */
#define REG_SLCD_SDATAH6           (0x42003C58U) /**< \brief (SLCD) Segments Data High for COM6 Line */
#define REG_SLCD_SDATAL7           (0x42003C5CU) /**< \brief (SLCD) Segments Data Low for COM7 Line */
#define REG_SLCD_SDATAH7           (0x42003C60U) /**< \brief (SLCD) Segments Data High for COM7 Line */
#define REG_SLCD_ISDATA            (0x42003C64U) /**< \brief (SLCD) Indirect Segments Data Access */
#define REG_SLCD_BCFG              (0x42003C68U) /**< \brief (SLCD) Blink Configuration */
#define REG_SLCD_CSRCFG            (0x42003C6CU) /**< \brief (SLCD) Circular Shift Register Configuration */
#define REG_SLCD_CMCFG             (0x42003C70U) /**< \brief (SLCD) Character Mapping Configuration */
#define REG_SLCD_ACMCFG            (0x42003C74U) /**< \brief (SLCD) Automated Character Mapping Configuration */
#define REG_SLCD_ABMCFG            (0x42003C78U) /**< \brief (SLCD) Automated Bit Mapping Configuration */
#define REG_SLCD_CMDATA            (0x42003C7CU) /**< \brief (SLCD) Character Mapping Segments Data */
#define REG_SLCD_CMDMASK           (0x42003C80U) /**< \brief (SLCD) Character Mapping Segments Data Mask */
#define REG_SLCD_CMINDEX           (0x42003C84U) /**< \brief (SLCD) Character Mapping SEG/COM Index */
#else
#define REG_SLCD_CTRLA             (*(RwReg  *)0x42003C00U) /**< \brief (SLCD) Control A */
#define REG_SLCD_CTRLB             (*(RwReg16*)0x42003C04U) /**< \brief (SLCD) Control B */
#define REG_SLCD_CTRLC             (*(RwReg16*)0x42003C06U) /**< \brief (SLCD) Control C */
#define REG_SLCD_CTRLD             (*(RwReg8 *)0x42003C08U) /**< \brief (SLCD) Control D */
#define REG_SLCD_EVCTRL            (*(RwReg8 *)0x42003C0CU) /**< \brief (SLCD) Event Control */
#define REG_SLCD_INTENCLR          (*(RwReg8 *)0x42003C0DU) /**< \brief (SLCD) Interrupt Enable Clear */
#define REG_SLCD_INTENSET          (*(RwReg8 *)0x42003C0EU) /**< \brief (SLCD) Interrupt Enable Set */
#define REG_SLCD_INTFLAG           (*(RwReg8 *)0x42003C0FU) /**< \brief (SLCD) Interrupt Flag Status and Clear */
#define REG_SLCD_STATUS            (*(RoReg8 *)0x42003C10U) /**< \brief (SLCD) Status */
#define REG_SLCD_SYNCBUSY          (*(RoReg  *)0x42003C14U) /**< \brief (SLCD) Synchronization Busy */
#define REG_SLCD_FC0               (*(RwReg8 *)0x42003C18U) /**< \brief (SLCD) Frame Counter 0 Configuration */
#define REG_SLCD_FC1               (*(RwReg8 *)0x42003C19U) /**< \brief (SLCD) Frame Counter 1 Configuration */
#define REG_SLCD_FC2               (*(RwReg8 *)0x42003C1AU) /**< \brief (SLCD) Frame Counter 2 Configuration */
#define REG_SLCD_LPENL             (*(RwReg  *)0x42003C1CU) /**< \brief (SLCD) LCD Pin Enable Low */
#define REG_SLCD_LPENH             (*(RwReg  *)0x42003C20U) /**< \brief (SLCD) LCD Pin Enable High */
#define REG_SLCD_SDATAL0           (*(RwReg  *)0x42003C24U) /**< \brief (SLCD) Segments Data Low for COM0 Line */
#define REG_SLCD_SDATAH0           (*(RwReg  *)0x42003C28U) /**< \brief (SLCD) Segments Data High for COM0 Line */
#define REG_SLCD_SDATAL1           (*(RwReg  *)0x42003C2CU) /**< \brief (SLCD) Segments Data Low for COM1 Line */
#define REG_SLCD_SDATAH1           (*(RwReg  *)0x42003C30U) /**< \brief (SLCD) Segments Data High for COM1 Line */
#define REG_SLCD_SDATAL2           (*(RwReg  *)0x42003C34U) /**< \brief (SLCD) Segments Data Low for COM2 Line */
#define REG_SLCD_SDATAH2           (*(RwReg  *)0x42003C38U) /**< \brief (SLCD) Segments Data High for COM2 Line */
#define REG_SLCD_SDATAL3           (*(RwReg  *)0x42003C3CU) /**< \brief (SLCD) Segments Data Low for COM3 Line */
#define REG_SLCD_SDATAH3           (*(RwReg  *)0x42003C40U) /**< \brief (SLCD) Segments Data High for COM3 Line */
#define REG_SLCD_SDATAL4           (*(RwReg  *)0x42003C44U) /**< \brief (SLCD) Segments Data Low for COM4 Line */
#define REG_SLCD_SDATAH4           (*(RwReg  *)0x42003C48U) /**< \brief (SLCD) Segments Data High for COM4 Line */
#define REG_SLCD_SDATAL5           (*(RwReg  *)0x42003C4CU) /**< \brief (SLCD) Segments Data Low for COM5 Line */
#define REG_SLCD_SDATAH5           (*(RwReg  *)0x42003C50U) /**< \brief (SLCD) Segments Data High for COM5 Line */
#define REG_SLCD_SDATAL6           (*(RwReg  *)0x42003C54U) /**< \brief (SLCD) Segments Data Low for COM6 Line */
#define REG_SLCD_SDATAH6           (*(RwReg  *)0x42003C58U) /**< \brief (SLCD) Segments Data High for COM6 Line */
#define REG_SLCD_SDATAL7           (*(RwReg  *)0x42003C5CU) /**< \brief (SLCD) Segments Data Low for COM7 Line */
#define REG_SLCD_SDATAH7           (*(RwReg  *)0x42003C60U) /**< \brief (SLCD) Segments Data High for COM7 Line */
#define REG_SLCD_ISDATA            (*(WoReg  *)0x42003C64U) /**< \brief (SLCD) Indirect Segments Data Access */
#define REG_SLCD_BCFG              (*(RwReg  *)0x42003C68U) /**< \brief (SLCD) Blink Configuration */
#define REG_SLCD_CSRCFG            (*(RwReg  *)0x42003C6CU) /**< \brief (SLCD) Circular Shift Register Configuration */
#define REG_SLCD_CMCFG             (*(RwReg8 *)0x42003C70U) /**< \brief (SLCD) Character Mapping Configuration */
#define REG_SLCD_ACMCFG            (*(RwReg  *)0x42003C74U) /**< \brief (SLCD) Automated Character Mapping Configuration */
#define REG_SLCD_ABMCFG            (*(RwReg8 *)0x42003C78U) /**< \brief (SLCD) Automated Bit Mapping Configuration */
#define REG_SLCD_CMDATA            (*(WoReg  *)0x42003C7CU) /**< \brief (SLCD) Character Mapping Segments Data */
#define REG_SLCD_CMDMASK           (*(RwReg  *)0x42003C80U) /**< \brief (SLCD) Character Mapping Segments Data Mask */
#define REG_SLCD_CMINDEX           (*(RwReg16*)0x42003C84U) /**< \brief (SLCD) Character Mapping SEG/COM Index */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance parameters for SLCD peripheral ========== */
#define SLCD_DMAC_ID_ABMDRDY        34      
#define SLCD_DMAC_ID_ACMDRDY        33      
#define SLCD_DMAC_ID_DMU            32      
#define SLCD_MAX_COM                8        // Max number of COM lines (4 or 8)
#define SLCD_MAX_SEG                44       // Max number of SEG lines (24 or 44)
#define SLCD_NB_LP                  52       // Number of LCD pins ([28..64] or [48..64])

#endif /* _SAML22_SLCD_INSTANCE_ */
