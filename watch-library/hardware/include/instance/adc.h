/**
 * \file
 *
 * \brief Instance description for ADC
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

#ifndef _SAML22_ADC_INSTANCE_
#define _SAML22_ADC_INSTANCE_

/* ========== Register definition for ADC peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_ADC_CTRLA              (0x42003000) /**< \brief (ADC) Control A */
#define REG_ADC_CTRLB              (0x42003001) /**< \brief (ADC) Control B */
#define REG_ADC_REFCTRL            (0x42003002) /**< \brief (ADC) Reference Control */
#define REG_ADC_EVCTRL             (0x42003003) /**< \brief (ADC) Event Control */
#define REG_ADC_INTENCLR           (0x42003004) /**< \brief (ADC) Interrupt Enable Clear */
#define REG_ADC_INTENSET           (0x42003005) /**< \brief (ADC) Interrupt Enable Set */
#define REG_ADC_INTFLAG            (0x42003006) /**< \brief (ADC) Interrupt Flag Status and Clear */
#define REG_ADC_SEQSTATUS          (0x42003007) /**< \brief (ADC) Sequence Status */
#define REG_ADC_INPUTCTRL          (0x42003008) /**< \brief (ADC) Input Control */
#define REG_ADC_CTRLC              (0x4200300A) /**< \brief (ADC) Control C */
#define REG_ADC_AVGCTRL            (0x4200300C) /**< \brief (ADC) Average Control */
#define REG_ADC_SAMPCTRL           (0x4200300D) /**< \brief (ADC) Sample Time Control */
#define REG_ADC_WINLT              (0x4200300E) /**< \brief (ADC) Window Monitor Lower Threshold */
#define REG_ADC_WINUT              (0x42003010) /**< \brief (ADC) Window Monitor Upper Threshold */
#define REG_ADC_GAINCORR           (0x42003012) /**< \brief (ADC) Gain Correction */
#define REG_ADC_OFFSETCORR         (0x42003014) /**< \brief (ADC) Offset Correction */
#define REG_ADC_SWTRIG             (0x42003018) /**< \brief (ADC) Software Trigger */
#define REG_ADC_DBGCTRL            (0x4200301C) /**< \brief (ADC) Debug Control */
#define REG_ADC_SYNCBUSY           (0x42003020) /**< \brief (ADC) Synchronization Busy */
#define REG_ADC_RESULT             (0x42003024) /**< \brief (ADC) Result */
#define REG_ADC_SEQCTRL            (0x42003028) /**< \brief (ADC) Sequence Control */
#define REG_ADC_CALIB              (0x4200302C) /**< \brief (ADC) Calibration */
#else
#define REG_ADC_CTRLA              (*(RwReg8 *)0x42003000UL) /**< \brief (ADC) Control A */
#define REG_ADC_CTRLB              (*(RwReg8 *)0x42003001UL) /**< \brief (ADC) Control B */
#define REG_ADC_REFCTRL            (*(RwReg8 *)0x42003002UL) /**< \brief (ADC) Reference Control */
#define REG_ADC_EVCTRL             (*(RwReg8 *)0x42003003UL) /**< \brief (ADC) Event Control */
#define REG_ADC_INTENCLR           (*(RwReg8 *)0x42003004UL) /**< \brief (ADC) Interrupt Enable Clear */
#define REG_ADC_INTENSET           (*(RwReg8 *)0x42003005UL) /**< \brief (ADC) Interrupt Enable Set */
#define REG_ADC_INTFLAG            (*(RwReg8 *)0x42003006UL) /**< \brief (ADC) Interrupt Flag Status and Clear */
#define REG_ADC_SEQSTATUS          (*(RoReg8 *)0x42003007UL) /**< \brief (ADC) Sequence Status */
#define REG_ADC_INPUTCTRL          (*(RwReg16*)0x42003008UL) /**< \brief (ADC) Input Control */
#define REG_ADC_CTRLC              (*(RwReg16*)0x4200300AUL) /**< \brief (ADC) Control C */
#define REG_ADC_AVGCTRL            (*(RwReg8 *)0x4200300CUL) /**< \brief (ADC) Average Control */
#define REG_ADC_SAMPCTRL           (*(RwReg8 *)0x4200300DUL) /**< \brief (ADC) Sample Time Control */
#define REG_ADC_WINLT              (*(RwReg16*)0x4200300EUL) /**< \brief (ADC) Window Monitor Lower Threshold */
#define REG_ADC_WINUT              (*(RwReg16*)0x42003010UL) /**< \brief (ADC) Window Monitor Upper Threshold */
#define REG_ADC_GAINCORR           (*(RwReg16*)0x42003012UL) /**< \brief (ADC) Gain Correction */
#define REG_ADC_OFFSETCORR         (*(RwReg16*)0x42003014UL) /**< \brief (ADC) Offset Correction */
#define REG_ADC_SWTRIG             (*(RwReg8 *)0x42003018UL) /**< \brief (ADC) Software Trigger */
#define REG_ADC_DBGCTRL            (*(RwReg8 *)0x4200301CUL) /**< \brief (ADC) Debug Control */
#define REG_ADC_SYNCBUSY           (*(RoReg16*)0x42003020UL) /**< \brief (ADC) Synchronization Busy */
#define REG_ADC_RESULT             (*(RoReg16*)0x42003024UL) /**< \brief (ADC) Result */
#define REG_ADC_SEQCTRL            (*(RwReg  *)0x42003028UL) /**< \brief (ADC) Sequence Control */
#define REG_ADC_CALIB              (*(RwReg16*)0x4200302CUL) /**< \brief (ADC) Calibration */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance parameters for ADC peripheral ========== */
#define ADC_DMAC_ID_RESRDY          31       // index of DMA RESRDY trigger
#define ADC_EXTCHANNEL_MSB          19       // Number of external channels
#define ADC_GCLK_ID                 25       // index of Generic Clock
#define ADC_INT_CH30                2        // Select OPAMP or CTAT on Channel 30
#define ADC_MASTER_SLAVE_MODE       0        // ADC Master/Slave Mode

#endif /* _SAML22_ADC_INSTANCE_ */
