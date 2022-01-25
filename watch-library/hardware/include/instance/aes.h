/**
 * \file
 *
 * \brief Instance description for AES
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

#ifndef _SAML22_AES_INSTANCE_
#define _SAML22_AES_INSTANCE_

/* ========== Register definition for AES peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_AES_CTRLA              (0x42004000) /**< \brief (AES) Control A */
#define REG_AES_CTRLB              (0x42004004) /**< \brief (AES) Control B */
#define REG_AES_INTENCLR           (0x42004005) /**< \brief (AES) Interrupt Enable Clear */
#define REG_AES_INTENSET           (0x42004006) /**< \brief (AES) Interrupt Enable Set */
#define REG_AES_INTFLAG            (0x42004007) /**< \brief (AES) Interrupt Flag Status */
#define REG_AES_DATABUFPTR         (0x42004008) /**< \brief (AES) Data buffer pointer */
#define REG_AES_DBGCTRL            (0x42004009) /**< \brief (AES) Debug control */
#define REG_AES_KEYWORD0           (0x4200400C) /**< \brief (AES) Keyword 0 */
#define REG_AES_KEYWORD1           (0x42004010) /**< \brief (AES) Keyword 1 */
#define REG_AES_KEYWORD2           (0x42004014) /**< \brief (AES) Keyword 2 */
#define REG_AES_KEYWORD3           (0x42004018) /**< \brief (AES) Keyword 3 */
#define REG_AES_KEYWORD4           (0x4200401C) /**< \brief (AES) Keyword 4 */
#define REG_AES_KEYWORD5           (0x42004020) /**< \brief (AES) Keyword 5 */
#define REG_AES_KEYWORD6           (0x42004024) /**< \brief (AES) Keyword 6 */
#define REG_AES_KEYWORD7           (0x42004028) /**< \brief (AES) Keyword 7 */
#define REG_AES_INDATA             (0x42004038) /**< \brief (AES) Indata */
#define REG_AES_INTVECTV0          (0x4200403C) /**< \brief (AES) Initialisation Vector 0 */
#define REG_AES_INTVECTV1          (0x42004040) /**< \brief (AES) Initialisation Vector 1 */
#define REG_AES_INTVECTV2          (0x42004044) /**< \brief (AES) Initialisation Vector 2 */
#define REG_AES_INTVECTV3          (0x42004048) /**< \brief (AES) Initialisation Vector 3 */
#define REG_AES_HASHKEY0           (0x4200405C) /**< \brief (AES) Hash key 0 */
#define REG_AES_HASHKEY1           (0x42004060) /**< \brief (AES) Hash key 1 */
#define REG_AES_HASHKEY2           (0x42004064) /**< \brief (AES) Hash key 2 */
#define REG_AES_HASHKEY3           (0x42004068) /**< \brief (AES) Hash key 3 */
#define REG_AES_GHASH0             (0x4200406C) /**< \brief (AES) Galois Hash 0 */
#define REG_AES_GHASH1             (0x42004070) /**< \brief (AES) Galois Hash 1 */
#define REG_AES_GHASH2             (0x42004074) /**< \brief (AES) Galois Hash 2 */
#define REG_AES_GHASH3             (0x42004078) /**< \brief (AES) Galois Hash 3 */
#define REG_AES_CIPLEN             (0x42004080) /**< \brief (AES) Cipher Length */
#define REG_AES_RANDSEED           (0x42004084) /**< \brief (AES) Random Seed */
#else
#define REG_AES_CTRLA              (*(RwReg  *)0x42004000UL) /**< \brief (AES) Control A */
#define REG_AES_CTRLB              (*(RwReg8 *)0x42004004UL) /**< \brief (AES) Control B */
#define REG_AES_INTENCLR           (*(RwReg8 *)0x42004005UL) /**< \brief (AES) Interrupt Enable Clear */
#define REG_AES_INTENSET           (*(RwReg8 *)0x42004006UL) /**< \brief (AES) Interrupt Enable Set */
#define REG_AES_INTFLAG            (*(RwReg8 *)0x42004007UL) /**< \brief (AES) Interrupt Flag Status */
#define REG_AES_DATABUFPTR         (*(RwReg8 *)0x42004008UL) /**< \brief (AES) Data buffer pointer */
#define REG_AES_DBGCTRL            (*(WoReg8 *)0x42004009UL) /**< \brief (AES) Debug control */
#define REG_AES_KEYWORD0           (*(WoReg  *)0x4200400CUL) /**< \brief (AES) Keyword 0 */
#define REG_AES_KEYWORD1           (*(WoReg  *)0x42004010UL) /**< \brief (AES) Keyword 1 */
#define REG_AES_KEYWORD2           (*(WoReg  *)0x42004014UL) /**< \brief (AES) Keyword 2 */
#define REG_AES_KEYWORD3           (*(WoReg  *)0x42004018UL) /**< \brief (AES) Keyword 3 */
#define REG_AES_KEYWORD4           (*(WoReg  *)0x4200401CUL) /**< \brief (AES) Keyword 4 */
#define REG_AES_KEYWORD5           (*(WoReg  *)0x42004020UL) /**< \brief (AES) Keyword 5 */
#define REG_AES_KEYWORD6           (*(WoReg  *)0x42004024UL) /**< \brief (AES) Keyword 6 */
#define REG_AES_KEYWORD7           (*(WoReg  *)0x42004028UL) /**< \brief (AES) Keyword 7 */
#define REG_AES_INDATA             (*(RwReg  *)0x42004038UL) /**< \brief (AES) Indata */
#define REG_AES_INTVECTV0          (*(WoReg  *)0x4200403CUL) /**< \brief (AES) Initialisation Vector 0 */
#define REG_AES_INTVECTV1          (*(WoReg  *)0x42004040UL) /**< \brief (AES) Initialisation Vector 1 */
#define REG_AES_INTVECTV2          (*(WoReg  *)0x42004044UL) /**< \brief (AES) Initialisation Vector 2 */
#define REG_AES_INTVECTV3          (*(WoReg  *)0x42004048UL) /**< \brief (AES) Initialisation Vector 3 */
#define REG_AES_HASHKEY0           (*(RwReg  *)0x4200405CUL) /**< \brief (AES) Hash key 0 */
#define REG_AES_HASHKEY1           (*(RwReg  *)0x42004060UL) /**< \brief (AES) Hash key 1 */
#define REG_AES_HASHKEY2           (*(RwReg  *)0x42004064UL) /**< \brief (AES) Hash key 2 */
#define REG_AES_HASHKEY3           (*(RwReg  *)0x42004068UL) /**< \brief (AES) Hash key 3 */
#define REG_AES_GHASH0             (*(RwReg  *)0x4200406CUL) /**< \brief (AES) Galois Hash 0 */
#define REG_AES_GHASH1             (*(RwReg  *)0x42004070UL) /**< \brief (AES) Galois Hash 1 */
#define REG_AES_GHASH2             (*(RwReg  *)0x42004074UL) /**< \brief (AES) Galois Hash 2 */
#define REG_AES_GHASH3             (*(RwReg  *)0x42004078UL) /**< \brief (AES) Galois Hash 3 */
#define REG_AES_CIPLEN             (*(RwReg  *)0x42004080UL) /**< \brief (AES) Cipher Length */
#define REG_AES_RANDSEED           (*(RwReg  *)0x42004084UL) /**< \brief (AES) Random Seed */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance parameters for AES peripheral ========== */
#define AES_DMAC_ID_RD              36       // DMA DATA Read trigger
#define AES_DMAC_ID_WR              35       // DMA DATA Write trigger

#endif /* _SAML22_AES_INSTANCE_ */
