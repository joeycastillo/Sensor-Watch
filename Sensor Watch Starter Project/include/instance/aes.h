/**
 * \file
 *
 * \brief Instance description for AES
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

#ifndef _SAML22_AES_INSTANCE_
#define _SAML22_AES_INSTANCE_

/* ========== Register definition for AES peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_AES_CTRLA              (0x42004000U) /**< \brief (AES) Control A */
#define REG_AES_CTRLB              (0x42004004U) /**< \brief (AES) Control B */
#define REG_AES_INTENCLR           (0x42004005U) /**< \brief (AES) Interrupt Enable Clear */
#define REG_AES_INTENSET           (0x42004006U) /**< \brief (AES) Interrupt Enable Set */
#define REG_AES_INTFLAG            (0x42004007U) /**< \brief (AES) Interrupt Flag Status */
#define REG_AES_DATABUFPTR         (0x42004008U) /**< \brief (AES) Data buffer pointer */
#define REG_AES_DBGCTRL            (0x42004009U) /**< \brief (AES) Debug control */
#define REG_AES_KEYWORD0           (0x4200400CU) /**< \brief (AES) Keyword 0 */
#define REG_AES_KEYWORD1           (0x42004010U) /**< \brief (AES) Keyword 1 */
#define REG_AES_KEYWORD2           (0x42004014U) /**< \brief (AES) Keyword 2 */
#define REG_AES_KEYWORD3           (0x42004018U) /**< \brief (AES) Keyword 3 */
#define REG_AES_KEYWORD4           (0x4200401CU) /**< \brief (AES) Keyword 4 */
#define REG_AES_KEYWORD5           (0x42004020U) /**< \brief (AES) Keyword 5 */
#define REG_AES_KEYWORD6           (0x42004024U) /**< \brief (AES) Keyword 6 */
#define REG_AES_KEYWORD7           (0x42004028U) /**< \brief (AES) Keyword 7 */
#define REG_AES_INDATA             (0x42004038U) /**< \brief (AES) Indata */
#define REG_AES_INTVECTV0          (0x4200403CU) /**< \brief (AES) Initialisation Vector 0 */
#define REG_AES_INTVECTV1          (0x42004040U) /**< \brief (AES) Initialisation Vector 1 */
#define REG_AES_INTVECTV2          (0x42004044U) /**< \brief (AES) Initialisation Vector 2 */
#define REG_AES_INTVECTV3          (0x42004048U) /**< \brief (AES) Initialisation Vector 3 */
#define REG_AES_HASHKEY0           (0x4200405CU) /**< \brief (AES) Hash key 0 */
#define REG_AES_HASHKEY1           (0x42004060U) /**< \brief (AES) Hash key 1 */
#define REG_AES_HASHKEY2           (0x42004064U) /**< \brief (AES) Hash key 2 */
#define REG_AES_HASHKEY3           (0x42004068U) /**< \brief (AES) Hash key 3 */
#define REG_AES_GHASH0             (0x4200406CU) /**< \brief (AES) Galois Hash 0 */
#define REG_AES_GHASH1             (0x42004070U) /**< \brief (AES) Galois Hash 1 */
#define REG_AES_GHASH2             (0x42004074U) /**< \brief (AES) Galois Hash 2 */
#define REG_AES_GHASH3             (0x42004078U) /**< \brief (AES) Galois Hash 3 */
#define REG_AES_CIPLEN             (0x42004080U) /**< \brief (AES) Cipher Length */
#define REG_AES_RANDSEED           (0x42004084U) /**< \brief (AES) Random Seed */
#else
#define REG_AES_CTRLA              (*(RwReg  *)0x42004000U) /**< \brief (AES) Control A */
#define REG_AES_CTRLB              (*(RwReg8 *)0x42004004U) /**< \brief (AES) Control B */
#define REG_AES_INTENCLR           (*(RwReg8 *)0x42004005U) /**< \brief (AES) Interrupt Enable Clear */
#define REG_AES_INTENSET           (*(RwReg8 *)0x42004006U) /**< \brief (AES) Interrupt Enable Set */
#define REG_AES_INTFLAG            (*(RwReg8 *)0x42004007U) /**< \brief (AES) Interrupt Flag Status */
#define REG_AES_DATABUFPTR         (*(RwReg8 *)0x42004008U) /**< \brief (AES) Data buffer pointer */
#define REG_AES_DBGCTRL            (*(WoReg8 *)0x42004009U) /**< \brief (AES) Debug control */
#define REG_AES_KEYWORD0           (*(WoReg  *)0x4200400CU) /**< \brief (AES) Keyword 0 */
#define REG_AES_KEYWORD1           (*(WoReg  *)0x42004010U) /**< \brief (AES) Keyword 1 */
#define REG_AES_KEYWORD2           (*(WoReg  *)0x42004014U) /**< \brief (AES) Keyword 2 */
#define REG_AES_KEYWORD3           (*(WoReg  *)0x42004018U) /**< \brief (AES) Keyword 3 */
#define REG_AES_KEYWORD4           (*(WoReg  *)0x4200401CU) /**< \brief (AES) Keyword 4 */
#define REG_AES_KEYWORD5           (*(WoReg  *)0x42004020U) /**< \brief (AES) Keyword 5 */
#define REG_AES_KEYWORD6           (*(WoReg  *)0x42004024U) /**< \brief (AES) Keyword 6 */
#define REG_AES_KEYWORD7           (*(WoReg  *)0x42004028U) /**< \brief (AES) Keyword 7 */
#define REG_AES_INDATA             (*(RwReg  *)0x42004038U) /**< \brief (AES) Indata */
#define REG_AES_INTVECTV0          (*(WoReg  *)0x4200403CU) /**< \brief (AES) Initialisation Vector 0 */
#define REG_AES_INTVECTV1          (*(WoReg  *)0x42004040U) /**< \brief (AES) Initialisation Vector 1 */
#define REG_AES_INTVECTV2          (*(WoReg  *)0x42004044U) /**< \brief (AES) Initialisation Vector 2 */
#define REG_AES_INTVECTV3          (*(WoReg  *)0x42004048U) /**< \brief (AES) Initialisation Vector 3 */
#define REG_AES_HASHKEY0           (*(RwReg  *)0x4200405CU) /**< \brief (AES) Hash key 0 */
#define REG_AES_HASHKEY1           (*(RwReg  *)0x42004060U) /**< \brief (AES) Hash key 1 */
#define REG_AES_HASHKEY2           (*(RwReg  *)0x42004064U) /**< \brief (AES) Hash key 2 */
#define REG_AES_HASHKEY3           (*(RwReg  *)0x42004068U) /**< \brief (AES) Hash key 3 */
#define REG_AES_GHASH0             (*(RwReg  *)0x4200406CU) /**< \brief (AES) Galois Hash 0 */
#define REG_AES_GHASH1             (*(RwReg  *)0x42004070U) /**< \brief (AES) Galois Hash 1 */
#define REG_AES_GHASH2             (*(RwReg  *)0x42004074U) /**< \brief (AES) Galois Hash 2 */
#define REG_AES_GHASH3             (*(RwReg  *)0x42004078U) /**< \brief (AES) Galois Hash 3 */
#define REG_AES_CIPLEN             (*(RwReg  *)0x42004080U) /**< \brief (AES) Cipher Length */
#define REG_AES_RANDSEED           (*(RwReg  *)0x42004084U) /**< \brief (AES) Random Seed */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance parameters for AES peripheral ========== */
#define AES_DMAC_ID_RD              36       // DMA DATA Read trigger
#define AES_DMAC_ID_WR              35       // DMA DATA Write trigger

#endif /* _SAML22_AES_INSTANCE_ */
