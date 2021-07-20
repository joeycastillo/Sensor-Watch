/**
 * \file
 *
 * \brief Instance description for TAL
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

#ifndef _SAML22_TAL_INSTANCE_
#define _SAML22_TAL_INSTANCE_

/* ========== Register definition for TAL peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_TAL_CTRLA              (0x40003000U) /**< \brief (TAL) Control A */
#define REG_TAL_RSTCTRL            (0x40003004U) /**< \brief (TAL) Reset Control */
#define REG_TAL_EXTCTRL            (0x40003005U) /**< \brief (TAL) External Break Control */
#define REG_TAL_EVCTRL             (0x40003006U) /**< \brief (TAL) Event Control */
#define REG_TAL_INTENCLR           (0x40003008U) /**< \brief (TAL) Interrupt Enable Clear */
#define REG_TAL_INTENSET           (0x40003009U) /**< \brief (TAL) Interrupt Enable Set */
#define REG_TAL_INTFLAG            (0x4000300AU) /**< \brief (TAL) Interrupt Flag Status and Clear */
#define REG_TAL_GLOBMASK           (0x4000300BU) /**< \brief (TAL) Global Break Requests Mask */
#define REG_TAL_HALT               (0x4000300CU) /**< \brief (TAL) Debug Halt Request */
#define REG_TAL_RESTART            (0x4000300DU) /**< \brief (TAL) Debug Restart Request */
#define REG_TAL_BRKSTATUS          (0x4000300EU) /**< \brief (TAL) Break Request Status */
#define REG_TAL_CTICTRLA0          (0x40003010U) /**< \brief (TAL) Cross-Trigger Interface 0 Control A */
#define REG_TAL_CTIMASK0           (0x40003011U) /**< \brief (TAL) Cross-Trigger Interface 0 Mask */
#define REG_TAL_CTICTRLA1          (0x40003012U) /**< \brief (TAL) Cross-Trigger Interface 1 Control A */
#define REG_TAL_CTIMASK1           (0x40003013U) /**< \brief (TAL) Cross-Trigger Interface 1 Mask */
#define REG_TAL_CTICTRLA2          (0x40003014U) /**< \brief (TAL) Cross-Trigger Interface 2 Control A */
#define REG_TAL_CTIMASK2           (0x40003015U) /**< \brief (TAL) Cross-Trigger Interface 2 Mask */
#define REG_TAL_INTSTATUS0         (0x40003020U) /**< \brief (TAL) Interrupt 0 Status */
#define REG_TAL_INTSTATUS1         (0x40003021U) /**< \brief (TAL) Interrupt 1 Status */
#define REG_TAL_INTSTATUS2         (0x40003022U) /**< \brief (TAL) Interrupt 2 Status */
#define REG_TAL_INTSTATUS3         (0x40003023U) /**< \brief (TAL) Interrupt 3 Status */
#define REG_TAL_INTSTATUS4         (0x40003024U) /**< \brief (TAL) Interrupt 4 Status */
#define REG_TAL_INTSTATUS5         (0x40003025U) /**< \brief (TAL) Interrupt 5 Status */
#define REG_TAL_INTSTATUS6         (0x40003026U) /**< \brief (TAL) Interrupt 6 Status */
#define REG_TAL_INTSTATUS7         (0x40003027U) /**< \brief (TAL) Interrupt 7 Status */
#define REG_TAL_INTSTATUS8         (0x40003028U) /**< \brief (TAL) Interrupt 8 Status */
#define REG_TAL_INTSTATUS9         (0x40003029U) /**< \brief (TAL) Interrupt 9 Status */
#define REG_TAL_INTSTATUS10        (0x4000302AU) /**< \brief (TAL) Interrupt 10 Status */
#define REG_TAL_INTSTATUS11        (0x4000302BU) /**< \brief (TAL) Interrupt 11 Status */
#define REG_TAL_INTSTATUS12        (0x4000302CU) /**< \brief (TAL) Interrupt 12 Status */
#define REG_TAL_INTSTATUS13        (0x4000302DU) /**< \brief (TAL) Interrupt 13 Status */
#define REG_TAL_INTSTATUS14        (0x4000302EU) /**< \brief (TAL) Interrupt 14 Status */
#define REG_TAL_INTSTATUS15        (0x4000302FU) /**< \brief (TAL) Interrupt 15 Status */
#define REG_TAL_INTSTATUS16        (0x40003030U) /**< \brief (TAL) Interrupt 16 Status */
#define REG_TAL_INTSTATUS17        (0x40003031U) /**< \brief (TAL) Interrupt 17 Status */
#define REG_TAL_INTSTATUS18        (0x40003032U) /**< \brief (TAL) Interrupt 18 Status */
#define REG_TAL_INTSTATUS19        (0x40003033U) /**< \brief (TAL) Interrupt 19 Status */
#define REG_TAL_INTSTATUS20        (0x40003034U) /**< \brief (TAL) Interrupt 20 Status */
#define REG_TAL_INTSTATUS21        (0x40003035U) /**< \brief (TAL) Interrupt 21 Status */
#define REG_TAL_INTSTATUS22        (0x40003036U) /**< \brief (TAL) Interrupt 22 Status */
#define REG_TAL_INTSTATUS23        (0x40003037U) /**< \brief (TAL) Interrupt 23 Status */
#define REG_TAL_INTSTATUS24        (0x40003038U) /**< \brief (TAL) Interrupt 24 Status */
#define REG_TAL_INTSTATUS25        (0x40003039U) /**< \brief (TAL) Interrupt 25 Status */
#define REG_TAL_DMACPUSEL0         (0x40003040U) /**< \brief (TAL) DMA Channel Interrupts CPU Select 0 */
#define REG_TAL_EVCPUSEL0          (0x40003048U) /**< \brief (TAL) EVSYS Channel Interrupts CPU Select 0 */
#define REG_TAL_EICCPUSEL0         (0x40003050U) /**< \brief (TAL) EIC External Interrupts CPU Select 0 */
#define REG_TAL_INTCPUSEL0         (0x40003058U) /**< \brief (TAL) Interrupts CPU Select 0 */
#define REG_TAL_INTCPUSEL1         (0x4000305CU) /**< \brief (TAL) Interrupts CPU Select 1 */
#define REG_TAL_IRQTRIG            (0x40003060U) /**< \brief (TAL) Interrupt Trigger */
#define REG_TAL_CPUIRQS0           (0x40003064U) /**< \brief (TAL) Interrupt Status for CPU 0 */
#else
#define REG_TAL_CTRLA              (*(RwReg8 *)0x40003000U) /**< \brief (TAL) Control A */
#define REG_TAL_RSTCTRL            (*(RwReg8 *)0x40003004U) /**< \brief (TAL) Reset Control */
#define REG_TAL_EXTCTRL            (*(RwReg8 *)0x40003005U) /**< \brief (TAL) External Break Control */
#define REG_TAL_EVCTRL             (*(RwReg8 *)0x40003006U) /**< \brief (TAL) Event Control */
#define REG_TAL_INTENCLR           (*(RwReg8 *)0x40003008U) /**< \brief (TAL) Interrupt Enable Clear */
#define REG_TAL_INTENSET           (*(RwReg8 *)0x40003009U) /**< \brief (TAL) Interrupt Enable Set */
#define REG_TAL_INTFLAG            (*(RwReg8 *)0x4000300AU) /**< \brief (TAL) Interrupt Flag Status and Clear */
#define REG_TAL_GLOBMASK           (*(RwReg8 *)0x4000300BU) /**< \brief (TAL) Global Break Requests Mask */
#define REG_TAL_HALT               (*(WoReg8 *)0x4000300CU) /**< \brief (TAL) Debug Halt Request */
#define REG_TAL_RESTART            (*(WoReg8 *)0x4000300DU) /**< \brief (TAL) Debug Restart Request */
#define REG_TAL_BRKSTATUS          (*(RoReg16*)0x4000300EU) /**< \brief (TAL) Break Request Status */
#define REG_TAL_CTICTRLA0          (*(RwReg8 *)0x40003010U) /**< \brief (TAL) Cross-Trigger Interface 0 Control A */
#define REG_TAL_CTIMASK0           (*(RwReg8 *)0x40003011U) /**< \brief (TAL) Cross-Trigger Interface 0 Mask */
#define REG_TAL_CTICTRLA1          (*(RwReg8 *)0x40003012U) /**< \brief (TAL) Cross-Trigger Interface 1 Control A */
#define REG_TAL_CTIMASK1           (*(RwReg8 *)0x40003013U) /**< \brief (TAL) Cross-Trigger Interface 1 Mask */
#define REG_TAL_CTICTRLA2          (*(RwReg8 *)0x40003014U) /**< \brief (TAL) Cross-Trigger Interface 2 Control A */
#define REG_TAL_CTIMASK2           (*(RwReg8 *)0x40003015U) /**< \brief (TAL) Cross-Trigger Interface 2 Mask */
#define REG_TAL_INTSTATUS0         (*(RoReg8 *)0x40003020U) /**< \brief (TAL) Interrupt 0 Status */
#define REG_TAL_INTSTATUS1         (*(RoReg8 *)0x40003021U) /**< \brief (TAL) Interrupt 1 Status */
#define REG_TAL_INTSTATUS2         (*(RoReg8 *)0x40003022U) /**< \brief (TAL) Interrupt 2 Status */
#define REG_TAL_INTSTATUS3         (*(RoReg8 *)0x40003023U) /**< \brief (TAL) Interrupt 3 Status */
#define REG_TAL_INTSTATUS4         (*(RoReg8 *)0x40003024U) /**< \brief (TAL) Interrupt 4 Status */
#define REG_TAL_INTSTATUS5         (*(RoReg8 *)0x40003025U) /**< \brief (TAL) Interrupt 5 Status */
#define REG_TAL_INTSTATUS6         (*(RoReg8 *)0x40003026U) /**< \brief (TAL) Interrupt 6 Status */
#define REG_TAL_INTSTATUS7         (*(RoReg8 *)0x40003027U) /**< \brief (TAL) Interrupt 7 Status */
#define REG_TAL_INTSTATUS8         (*(RoReg8 *)0x40003028U) /**< \brief (TAL) Interrupt 8 Status */
#define REG_TAL_INTSTATUS9         (*(RoReg8 *)0x40003029U) /**< \brief (TAL) Interrupt 9 Status */
#define REG_TAL_INTSTATUS10        (*(RoReg8 *)0x4000302AU) /**< \brief (TAL) Interrupt 10 Status */
#define REG_TAL_INTSTATUS11        (*(RoReg8 *)0x4000302BU) /**< \brief (TAL) Interrupt 11 Status */
#define REG_TAL_INTSTATUS12        (*(RoReg8 *)0x4000302CU) /**< \brief (TAL) Interrupt 12 Status */
#define REG_TAL_INTSTATUS13        (*(RoReg8 *)0x4000302DU) /**< \brief (TAL) Interrupt 13 Status */
#define REG_TAL_INTSTATUS14        (*(RoReg8 *)0x4000302EU) /**< \brief (TAL) Interrupt 14 Status */
#define REG_TAL_INTSTATUS15        (*(RoReg8 *)0x4000302FU) /**< \brief (TAL) Interrupt 15 Status */
#define REG_TAL_INTSTATUS16        (*(RoReg8 *)0x40003030U) /**< \brief (TAL) Interrupt 16 Status */
#define REG_TAL_INTSTATUS17        (*(RoReg8 *)0x40003031U) /**< \brief (TAL) Interrupt 17 Status */
#define REG_TAL_INTSTATUS18        (*(RoReg8 *)0x40003032U) /**< \brief (TAL) Interrupt 18 Status */
#define REG_TAL_INTSTATUS19        (*(RoReg8 *)0x40003033U) /**< \brief (TAL) Interrupt 19 Status */
#define REG_TAL_INTSTATUS20        (*(RoReg8 *)0x40003034U) /**< \brief (TAL) Interrupt 20 Status */
#define REG_TAL_INTSTATUS21        (*(RoReg8 *)0x40003035U) /**< \brief (TAL) Interrupt 21 Status */
#define REG_TAL_INTSTATUS22        (*(RoReg8 *)0x40003036U) /**< \brief (TAL) Interrupt 22 Status */
#define REG_TAL_INTSTATUS23        (*(RoReg8 *)0x40003037U) /**< \brief (TAL) Interrupt 23 Status */
#define REG_TAL_INTSTATUS24        (*(RoReg8 *)0x40003038U) /**< \brief (TAL) Interrupt 24 Status */
#define REG_TAL_INTSTATUS25        (*(RoReg8 *)0x40003039U) /**< \brief (TAL) Interrupt 25 Status */
#define REG_TAL_DMACPUSEL0         (*(RwReg  *)0x40003040U) /**< \brief (TAL) DMA Channel Interrupts CPU Select 0 */
#define REG_TAL_EVCPUSEL0          (*(RwReg  *)0x40003048U) /**< \brief (TAL) EVSYS Channel Interrupts CPU Select 0 */
#define REG_TAL_EICCPUSEL0         (*(RwReg  *)0x40003050U) /**< \brief (TAL) EIC External Interrupts CPU Select 0 */
#define REG_TAL_INTCPUSEL0         (*(RwReg  *)0x40003058U) /**< \brief (TAL) Interrupts CPU Select 0 */
#define REG_TAL_INTCPUSEL1         (*(RwReg  *)0x4000305CU) /**< \brief (TAL) Interrupts CPU Select 1 */
#define REG_TAL_IRQTRIG            (*(RwReg16*)0x40003060U) /**< \brief (TAL) Interrupt Trigger */
#define REG_TAL_CPUIRQS0           (*(RoReg  *)0x40003064U) /**< \brief (TAL) Interrupt Status for CPU 0 */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance parameters for TAL peripheral ========== */
#define TAL_CPU_NUM                 1        // Number of CPUs
#define TAL_CTI_NUM                 3        // Number of Cross-Trigger Interfaces
#define TAL_DMA_CH_NUM              16       // Number of DMAC Channels
#define TAL_EV_CH_NUM               8        // Number of EVSYS Channels
#define TAL_EXTINT_NUM              16       // Number of EIC External Interrrupts
#define TAL_INT_NUM                 26       // Number of Interrupt Requests

#endif /* _SAML22_TAL_INSTANCE_ */
