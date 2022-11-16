/**
 * \file
 *
 * \brief Header file for ATSAMG55G19
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
#ifndef _SAMG55G19_H_
#define _SAMG55G19_H_

/** \addtogroup SAMG55G19_definitions SAMG55G19 definitions
  This file defines all structures and symbols for SAMG55G19:
    - registers and bitfields
    - peripheral base address
    - peripheral ID
    - PIO definitions
 *  @{
 */

#ifdef __cplusplus
 extern "C" {
#endif

/** \defgroup Atmel_glob_defs Atmel Global Defines

    <strong>IO Type Qualifiers</strong> are used
    \li to specify the access to peripheral variables.
    \li for automatic generation of peripheral register debug information.

    \remark
    CMSIS core has a syntax that differs from this using i.e. __I, __O, or __IO followed by 'uint<size>_t' respective types.
    Default the header files will follow the CMSIS core syntax.
 *  @{
 */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#include <stdint.h>

/* IO definitions (access restrictions to peripheral registers) */
#ifndef __cplusplus
typedef volatile const uint32_t RoReg;   /**< Read only 32-bit register (volatile const unsigned int) */
typedef volatile const uint16_t RoReg16; /**< Read only 16-bit register (volatile const unsigned int) */
typedef volatile const uint8_t  RoReg8;  /**< Read only  8-bit register (volatile const unsigned int) */
#else
typedef volatile       uint32_t RoReg;   /**< Read only 32-bit register (volatile const unsigned int) */
typedef volatile       uint16_t RoReg16; /**< Read only 16-bit register (volatile const unsigned int) */
typedef volatile       uint8_t  RoReg8;  /**< Read only  8-bit register (volatile const unsigned int) */
#endif
typedef volatile       uint32_t WoReg;   /**< Write only 32-bit register (volatile unsigned int) */
typedef volatile       uint16_t WoReg16; /**< Write only 16-bit register (volatile unsigned int) */
typedef volatile       uint32_t WoReg8;  /**< Write only  8-bit register (volatile unsigned int) */
typedef volatile       uint32_t RwReg;   /**< Read-Write 32-bit register (volatile unsigned int) */
typedef volatile       uint16_t RwReg16; /**< Read-Write 16-bit register (volatile unsigned int) */
typedef volatile       uint8_t  RwReg8;  /**< Read-Write  8-bit register (volatile unsigned int) */

#define CAST(type, value) ((type *)(value)) /**< Pointer Type Conversion Macro for C/C++ */
#define REG_ACCESS(type, address) (*(type*)(address)) /**< C code: Register value */
#else /* Assembler */
#define CAST(type, value) (value) /**< Pointer Type Conversion Macro for Assembler */
#define REG_ACCESS(type, address) (address) /**< Assembly code: Register address */
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#if !defined(SKIP_INTEGER_LITERALS)

#if defined(_U_) || defined(_L_) || defined(_UL_)
  #error "Integer Literals macros already defined elsewhere"
#endif

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* Macros that deal with adding suffixes to integer literal constants for C/C++ */
#define _U_(x) x ## U    /**< C code: Unsigned integer literal constant value */
#define _L_(x) x ## L    /**< C code: Long integer literal constant value */
#define _UL_(x) x ## UL  /**< C code: Unsigned Long integer literal constant value */

#else /* Assembler */

#define _U_(x) x    /**< Assembler: Unsigned integer literal constant value */
#define _L_(x) x    /**< Assembler: Long integer literal constant value */
#define _UL_(x) x   /**< Assembler: Unsigned Long integer literal constant value */
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#endif /* SKIP_INTEGER_LITERALS */
/** @}  end of Atmel Global Defines */

/** \addtogroup SAMG55G19_cmsis CMSIS Definitions
 *  @{
 */
/* ************************************************************************** */
/*   CMSIS DEFINITIONS FOR SAMG55G19 */
/* ************************************************************************** */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** Interrupt Number Definition */
typedef enum IRQn
{
/******  CORTEX-M4 Processor Exceptions Numbers ******************************/
  Reset_IRQn                = -15, /**< 1   Reset Vector, invoked on Power up and warm reset  */
  NonMaskableInt_IRQn       = -14, /**< 2   Non maskable Interrupt, cannot be stopped or preempted  */
  HardFault_IRQn            = -13, /**< 3   Hard Fault, all classes of Fault     */
  MemoryManagement_IRQn     = -12, /**< 4   Memory Management, MPU mismatch, including Access Violation and No Match  */
  BusFault_IRQn             = -11, /**< 5   Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault  */
  UsageFault_IRQn           = -10, /**< 6   Usage Fault, i.e. Undef Instruction, Illegal State Transition  */
  SVCall_IRQn               = -5 , /**< 11  System Service Call via SVC instruction  */
  DebugMonitor_IRQn         = -4 , /**< 12  Debug Monitor                        */
  PendSV_IRQn               = -2 , /**< 14  Pendable request for system service  */
  SysTick_IRQn              = -1 , /**< 15  System Tick Timer                    */
/******  SAMG55G19 specific Interrupt Numbers ***********************************/
  SUPC_IRQn                 = 0  , /**< 0   SAMG55G19 Supply Controller (SUPC)  */
  RSTC_IRQn                 = 1  , /**< 1   SAMG55G19 Reset Controller (RSTC)   */
  RTC_IRQn                  = 2  , /**< 2   SAMG55G19 Real-time Clock (RTC)     */
  RTT_IRQn                  = 3  , /**< 3   SAMG55G19 Real-time Timer (RTT)     */
  WDT_IRQn                  = 4  , /**< 4   SAMG55G19 Watchdog Timer (WDT)      */
  PMC_IRQn                  = 5  , /**< 5   SAMG55G19 Power Management Controller (PMC) */
  EFC_IRQn                  = 6  , /**< 6   SAMG55G19 Embedded Flash Controller (EFC) */
  FLEXCOM7_IRQn             = 7  , /**< 7   SAMG55G19 Flexible Serial Communication (FLEXCOM7) */
  FLEXCOM0_IRQn             = 8  , /**< 8   SAMG55G19 Flexible Serial Communication (FLEXCOM0) */
  FLEXCOM1_IRQn             = 9  , /**< 9   SAMG55G19 Flexible Serial Communication (FLEXCOM1) */
  PIOA_IRQn                 = 11 , /**< 11  SAMG55G19 Parallel Input/Output Controller (PIOA) */
  PIOB_IRQn                 = 12 , /**< 12  SAMG55G19 Parallel Input/Output Controller (PIOB) */
  PDMIC0_IRQn               = 13 , /**< 13  SAMG55G19 Pulse Density Modulation Interface Controller (PDMIC0) */
  FLEXCOM2_IRQn             = 14 , /**< 14  SAMG55G19 Flexible Serial Communication (FLEXCOM2) */
  MEM2MEM_IRQn              = 15 , /**< 15  SAMG55G19 Memory to Memory (MEM2MEM) */
  I2SC0_IRQn                = 16 , /**< 16  SAMG55G19 Inter-IC Sound Controller (I2SC0) */
  I2SC1_IRQn                = 17 , /**< 17  SAMG55G19 Inter-IC Sound Controller (I2SC1) */
  PDMIC1_IRQn               = 18 , /**< 18  SAMG55G19 Pulse Density Modulation Interface Controller (PDMIC1) */
  FLEXCOM3_IRQn             = 19 , /**< 19  SAMG55G19 Flexible Serial Communication (FLEXCOM3) */
  FLEXCOM4_IRQn             = 20 , /**< 20  SAMG55G19 Flexible Serial Communication (FLEXCOM4) */
  FLEXCOM5_IRQn             = 21 , /**< 21  SAMG55G19 Flexible Serial Communication (FLEXCOM5) */
  FLEXCOM6_IRQn             = 22 , /**< 22  SAMG55G19 Flexible Serial Communication (FLEXCOM6) */
  TC0_IRQn                  = 23 , /**< 23  SAMG55G19 Timer Counter (TC0)       */
  TC1_IRQn                  = 24 , /**< 24  SAMG55G19 Timer Counter (TC0)       */
  TC2_IRQn                  = 25 , /**< 25  SAMG55G19 Timer Counter (TC0)       */
  TC3_IRQn                  = 26 , /**< 26  SAMG55G19 Timer Counter (TC1)       */
  TC4_IRQn                  = 27 , /**< 27  SAMG55G19 Timer Counter (TC1)       */
  TC5_IRQn                  = 28 , /**< 28  SAMG55G19 Timer Counter (TC1)       */
  ADC_IRQn                  = 29 , /**< 29  SAMG55G19 Analog-to-Digital Converter (ADC) */
  UHP_IRQn                  = 47 , /**< 47  SAMG55G19 USB Host Port (UHP)       */
  UDP_IRQn                  = 48 , /**< 48  SAMG55G19 USB Device Port (UDP)     */
  CRCCU_IRQn                = 49 , /**< 49  SAMG55G19 Cyclic Redundancy Check Calculation Unit (CRCCU) */

  PERIPH_COUNT_IRQn        = 50  /**< Number of peripheral IDs */
} IRQn_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef struct _DeviceVectors
{
  /* Stack pointer */
  void* pvStack;
  /* Cortex-M handlers */
  void* pfnReset_Handler;                        /* -15 Reset Vector, invoked on Power up and warm reset  */
  void* pfnNonMaskableInt_Handler;               /* -14 Non maskable Interrupt, cannot be stopped or preempted  */
  void* pfnHardFault_Handler;                    /* -13 Hard Fault, all classes of Fault     */
  void* pfnMemoryManagement_Handler;             /* -12 Memory Management, MPU mismatch, including Access Violation and No Match  */
  void* pfnBusFault_Handler;                     /* -11 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault  */
  void* pfnUsageFault_Handler;                   /* -10 Usage Fault, i.e. Undef Instruction, Illegal State Transition  */
  void* pvReservedC9;
  void* pvReservedC8;
  void* pvReservedC7;
  void* pvReservedC6;
  void* pfnSVCall_Handler;                       /*  -5 System Service Call via SVC instruction  */
  void* pfnDebugMonitor_Handler;                 /*  -4 Debug Monitor                        */
  void* pvReservedC3;
  void* pfnPendSV_Handler;                       /*  -2 Pendable request for system service  */
  void* pfnSysTick_Handler;                      /*  -1 System Tick Timer                    */

  /* Peripheral handlers */
  void* pfnSUPC_Handler;                         /* 0   SAMG55G19 Supply Controller (SUPC) */
  void* pfnRSTC_Handler;                         /* 1   SAMG55G19 Reset Controller (RSTC) */
  void* pfnRTC_Handler;                          /* 2   SAMG55G19 Real-time Clock (RTC) */
  void* pfnRTT_Handler;                          /* 3   SAMG55G19 Real-time Timer (RTT) */
  void* pfnWDT_Handler;                          /* 4   SAMG55G19 Watchdog Timer (WDT) */
  void* pfnPMC_Handler;                          /* 5   SAMG55G19 Power Management Controller (PMC) */
  void* pfnEFC_Handler;                          /* 6   SAMG55G19 Embedded Flash Controller (EFC) */
  void* pfnFLEXCOM7_Handler;                     /* 7   SAMG55G19 Flexible Serial Communication (FLEXCOM7) */
  void* pfnFLEXCOM0_Handler;                     /* 8   SAMG55G19 Flexible Serial Communication (FLEXCOM0) */
  void* pfnFLEXCOM1_Handler;                     /* 9   SAMG55G19 Flexible Serial Communication (FLEXCOM1) */
  void* pvReserved10;
  void* pfnPIOA_Handler;                         /* 11  SAMG55G19 Parallel Input/Output Controller (PIOA) */
  void* pfnPIOB_Handler;                         /* 12  SAMG55G19 Parallel Input/Output Controller (PIOB) */
  void* pfnPDMIC0_Handler;                       /* 13  SAMG55G19 Pulse Density Modulation Interface Controller (PDMIC0) */
  void* pfnFLEXCOM2_Handler;                     /* 14  SAMG55G19 Flexible Serial Communication (FLEXCOM2) */
  void* pfnMEM2MEM_Handler;                      /* 15  SAMG55G19 Memory to Memory (MEM2MEM) */
  void* pfnI2SC0_Handler;                        /* 16  SAMG55G19 Inter-IC Sound Controller (I2SC0) */
  void* pfnI2SC1_Handler;                        /* 17  SAMG55G19 Inter-IC Sound Controller (I2SC1) */
  void* pfnPDMIC1_Handler;                       /* 18  SAMG55G19 Pulse Density Modulation Interface Controller (PDMIC1) */
  void* pfnFLEXCOM3_Handler;                     /* 19  SAMG55G19 Flexible Serial Communication (FLEXCOM3) */
  void* pfnFLEXCOM4_Handler;                     /* 20  SAMG55G19 Flexible Serial Communication (FLEXCOM4) */
  void* pfnFLEXCOM5_Handler;                     /* 21  SAMG55G19 Flexible Serial Communication (FLEXCOM5) */
  void* pfnFLEXCOM6_Handler;                     /* 22  SAMG55G19 Flexible Serial Communication (FLEXCOM6) */
  void* pfnTC0_Handler;                          /* 23  SAMG55G19 Timer Counter (TC0)  */
  void* pfnTC1_Handler;                          /* 24  SAMG55G19 Timer Counter (TC0)  */
  void* pfnTC2_Handler;                          /* 25  SAMG55G19 Timer Counter (TC0)  */
  void* pfnTC3_Handler;                          /* 26  SAMG55G19 Timer Counter (TC1)  */
  void* pfnTC4_Handler;                          /* 27  SAMG55G19 Timer Counter (TC1)  */
  void* pfnTC5_Handler;                          /* 28  SAMG55G19 Timer Counter (TC1)  */
  void* pfnADC_Handler;                          /* 29  SAMG55G19 Analog-to-Digital Converter (ADC) */
  void* pvReserved30;
  void* pvReserved31;
  void* pvReserved32;
  void* pvReserved33;
  void* pvReserved34;
  void* pvReserved35;
  void* pvReserved36;
  void* pvReserved37;
  void* pvReserved38;
  void* pvReserved39;
  void* pvReserved40;
  void* pvReserved41;
  void* pvReserved42;
  void* pvReserved43;
  void* pvReserved44;
  void* pvReserved45;
  void* pvReserved46;
  void* pfnUHP_Handler;                          /* 47  SAMG55G19 USB Host Port (UHP)  */
  void* pfnUDP_Handler;                          /* 48  SAMG55G19 USB Device Port (UDP) */
  void* pfnCRCCU_Handler;                        /* 49  SAMG55G19 Cyclic Redundancy Check Calculation Unit (CRCCU) */
} DeviceVectors;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if !defined DONT_USE_PREDEFINED_CORE_HANDLERS

/* CORTEX-M4 core handlers */
void Reset_Handler                 ( void );
void NonMaskableInt_Handler        ( void );
void HardFault_Handler             ( void );
void MemoryManagement_Handler      ( void );
void BusFault_Handler              ( void );
void UsageFault_Handler            ( void );
void SVCall_Handler                ( void );
void DebugMonitor_Handler          ( void );
void PendSV_Handler                ( void );
void SysTick_Handler               ( void );
#endif /* DONT_USE_PREDEFINED_CORE_HANDLERS */

#if !defined DONT_USE_PREDEFINED_PERIPHERALS_HANDLERS

/* Peripherals handlers */
void ADC_Handler                   ( void );
void CRCCU_Handler                 ( void );
void EFC_Handler                   ( void );
void FLEXCOM0_Handler              ( void );
void FLEXCOM1_Handler              ( void );
void FLEXCOM2_Handler              ( void );
void FLEXCOM3_Handler              ( void );
void FLEXCOM4_Handler              ( void );
void FLEXCOM5_Handler              ( void );
void FLEXCOM6_Handler              ( void );
void FLEXCOM7_Handler              ( void );
void I2SC0_Handler                 ( void );
void I2SC1_Handler                 ( void );
void MEM2MEM_Handler               ( void );
void PDMIC0_Handler                ( void );
void PDMIC1_Handler                ( void );
void PIOA_Handler                  ( void );
void PIOB_Handler                  ( void );
void PMC_Handler                   ( void );
void RSTC_Handler                  ( void );
void RTC_Handler                   ( void );
void RTT_Handler                   ( void );
void SUPC_Handler                  ( void );
void TC0_Handler                   ( void );
void TC1_Handler                   ( void );
void TC2_Handler                   ( void );
void TC3_Handler                   ( void );
void TC4_Handler                   ( void );
void TC5_Handler                   ( void );
void UDP_Handler                   ( void );
void UHP_Handler                   ( void );
void WDT_Handler                   ( void );
#endif /* DONT_USE_PREDEFINED_PERIPHERALS_HANDLERS */
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */


/*
 * \brief Configuration of the CORTEX-M4 Processor and Core Peripherals
 */

#define __CM4_REV                 0x0001 /**< CM4 Core Revision                                                         */
#define __NVIC_PRIO_BITS               4 /**< Number of Bits used for Priority Levels                                   */
#define __Vendor_SysTickConfig         0 /**< Set to 1 if different SysTick Config is used                              */
#define __MPU_PRESENT                  1 /**< MPU present or not                                                        */
#define __VTOR_PRESENT                 1 /**< Vector Table Offset Register present or not                               */
#define __FPU_PRESENT                  1 /**< FPU present or not                                                        */
#define LITTLE_ENDIAN                  1
#define __ARCH_ARM                     1
#define __ARCH_ARM_CORTEX_M            1
#define __DEVICE_IS_SAM                1

/*
 * \brief CMSIS includes
 */
#include <core_cm4.h>
#if !defined DONT_USE_CMSIS_INIT
#include "system_samg55.h"
#endif /* DONT_USE_CMSIS_INIT */

/** @}  end of SAMG55G19_cmsis CMSIS Definitions */

/** \defgroup SAMG55G19_api Peripheral Software API
 *  @{
 */

/* ************************************************************************** */
/**  SOFTWARE PERIPHERAL API DEFINITION FOR SAMG55G19 */
/* ************************************************************************** */
#include "component/adc.h"
#include "component/chipid.h"
#include "component/cmcc.h"
#include "component/crccu.h"
#include "component/efc.h"
#include "component/flexcom.h"
#include "component/gpbr.h"
#include "component/i2sc.h"
#include "component/matrix.h"
#include "component/mem2mem.h"
#include "component/pdc.h"
#include "component/pdmic.h"
#include "component/pio.h"
#include "component/pmc.h"
#include "component/rstc.h"
#include "component/rtc.h"
#include "component/rtt.h"
#include "component/spi.h"
#include "component/supc.h"
#include "component/tc.h"
#include "component/twi.h"
#include "component/udp.h"
#include "component/uhp.h"
#include "component/usart.h"
#include "component/wdt.h"
/** @}  end of Peripheral Software API */

/** \defgroup SAMG55G19_reg Registers Access Definitions
 *  @{
 */

/* ************************************************************************** */
/*   REGISTER ACCESS DEFINITIONS FOR SAMG55G19 */
/* ************************************************************************** */
#include "instance/adc.h"
#include "instance/chipid.h"
#include "instance/cmcc.h"
#include "instance/crccu.h"
#include "instance/efc.h"
#include "instance/flexcom0.h"
#include "instance/flexcom1.h"
#include "instance/flexcom2.h"
#include "instance/flexcom3.h"
#include "instance/flexcom4.h"
#include "instance/flexcom5.h"
#include "instance/flexcom6.h"
#include "instance/flexcom7.h"
#include "instance/gpbr.h"
#include "instance/i2sc0.h"
#include "instance/i2sc1.h"
#include "instance/matrix.h"
#include "instance/mem2mem.h"
#include "instance/pdmic0.h"
#include "instance/pdmic1.h"
#include "instance/pioa.h"
#include "instance/piob.h"
#include "instance/pmc.h"
#include "instance/rstc.h"
#include "instance/rtc.h"
#include "instance/rtt.h"
#include "instance/spi0.h"
#include "instance/spi1.h"
#include "instance/spi2.h"
#include "instance/spi3.h"
#include "instance/spi4.h"
#include "instance/spi5.h"
#include "instance/spi6.h"
#include "instance/supc.h"
#include "instance/tc0.h"
#include "instance/tc1.h"
#include "instance/twi0.h"
#include "instance/twi1.h"
#include "instance/twi2.h"
#include "instance/twi3.h"
#include "instance/twi4.h"
#include "instance/twi5.h"
#include "instance/twi6.h"
#include "instance/udp.h"
#include "instance/uhp.h"
#include "instance/usart0.h"
#include "instance/usart1.h"
#include "instance/usart2.h"
#include "instance/usart3.h"
#include "instance/usart4.h"
#include "instance/usart5.h"
#include "instance/usart6.h"
#include "instance/wdt.h"
/** @}  end of Registers Access Definitions */

/** \addtogroup SAMG55G19_id Peripheral Ids Definitions
 *  @{
 */

/* ************************************************************************** */
/*  PERIPHERAL ID DEFINITIONS FOR SAMG55G19 */
/* ************************************************************************** */
#define ID_SUPC         (  0) /**< \brief Supply Controller (SUPC) */
#define ID_RSTC         (  1) /**< \brief Reset Controller (RSTC) */
#define ID_RTC          (  2) /**< \brief Real-time Clock (RTC) */
#define ID_RTT          (  3) /**< \brief Real-time Timer (RTT) */
#define ID_WDT          (  4) /**< \brief Watchdog Timer (WDT) */
#define ID_PMC          (  5) /**< \brief Power Management Controller (PMC) */
#define ID_EFC          (  6) /**< \brief Embedded Flash Controller (EFC) */
#define ID_FLEXCOM7     (  7) /**< \brief Flexible Serial Communication (FLEXCOM7) */
#define ID_FLEXCOM0     (  8) /**< \brief Flexible Serial Communication (FLEXCOM0) */
#define ID_FLEXCOM1     (  9) /**< \brief Flexible Serial Communication (FLEXCOM1) */
#define ID_PIOA         ( 11) /**< \brief Parallel Input/Output Controller (PIOA) */
#define ID_PIOB         ( 12) /**< \brief Parallel Input/Output Controller (PIOB) */
#define ID_PDMIC0       ( 13) /**< \brief Pulse Density Modulation Interface Controller (PDMIC0) */
#define ID_FLEXCOM2     ( 14) /**< \brief Flexible Serial Communication (FLEXCOM2) */
#define ID_MEM2MEM      ( 15) /**< \brief Memory to Memory (MEM2MEM) */
#define ID_I2SC0        ( 16) /**< \brief Inter-IC Sound Controller (I2SC0) */
#define ID_I2SC1        ( 17) /**< \brief Inter-IC Sound Controller (I2SC1) */
#define ID_PDMIC1       ( 18) /**< \brief Pulse Density Modulation Interface Controller (PDMIC1) */
#define ID_FLEXCOM3     ( 19) /**< \brief Flexible Serial Communication (FLEXCOM3) */
#define ID_FLEXCOM4     ( 20) /**< \brief Flexible Serial Communication (FLEXCOM4) */
#define ID_FLEXCOM5     ( 21) /**< \brief Flexible Serial Communication (FLEXCOM5) */
#define ID_FLEXCOM6     ( 22) /**< \brief Flexible Serial Communication (FLEXCOM6) */
#define ID_TC0_CHANNEL0 ( 23) /**< \brief Timer Counter (TC0_CHANNEL0) */
#define ID_TC0_CHANNEL1 ( 24) /**< \brief Timer Counter (TC0_CHANNEL1) */
#define ID_TC0_CHANNEL2 ( 25) /**< \brief Timer Counter (TC0_CHANNEL2) */
#define ID_TC1_CHANNEL0 ( 26) /**< \brief Timer Counter (TC1_CHANNEL0) */
#define ID_TC1_CHANNEL1 ( 27) /**< \brief Timer Counter (TC1_CHANNEL1) */
#define ID_TC1_CHANNEL2 ( 28) /**< \brief Timer Counter (TC1_CHANNEL2) */
#define ID_ADC          ( 29) /**< \brief Analog-to-Digital Converter (ADC) */
#define ID_UHP          ( 47) /**< \brief USB Host Port (UHP) */
#define ID_UDP          ( 48) /**< \brief USB Device Port (UDP) */
#define ID_CRCCU        ( 49) /**< \brief Cyclic Redundancy Check Calculation Unit (CRCCU) */

#define ID_PERIPH_COUNT ( 50) /**< \brief Number of peripheral IDs */
/** @}  end of Peripheral Ids Definitions */

/** \addtogroup SAMG55G19_base Peripheral Base Address Definitions
 *  @{
 */

/* ************************************************************************** */
/*   BASE ADDRESS DEFINITIONS FOR SAMG55G19 */
/* ************************************************************************** */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#define ADC                    (0x40038000)                   /**< \brief (ADC       ) Base Address */
#define CHIPID                 (0x400E0740)                   /**< \brief (CHIPID    ) Base Address */
#define CMCC                   (0x4003C000)                   /**< \brief (CMCC      ) Base Address */
#define CRCCU                  (0x40048000)                   /**< \brief (CRCCU     ) Base Address */
#define EFC                    (0x400E0A00)                   /**< \brief (EFC       ) Base Address */
#define FLEXCOM0               (0x4000C000)                   /**< \brief (FLEXCOM0  ) Base Address */
#define FLEXCOM1               (0x40020000)                   /**< \brief (FLEXCOM1  ) Base Address */
#define FLEXCOM2               (0x40024000)                   /**< \brief (FLEXCOM2  ) Base Address */
#define FLEXCOM3               (0x40018000)                   /**< \brief (FLEXCOM3  ) Base Address */
#define FLEXCOM4               (0x4001C000)                   /**< \brief (FLEXCOM4  ) Base Address */
#define FLEXCOM5               (0x40008000)                   /**< \brief (FLEXCOM5  ) Base Address */
#define FLEXCOM6               (0x40040000)                   /**< \brief (FLEXCOM6  ) Base Address */
#define FLEXCOM7               (0x40034000)                   /**< \brief (FLEXCOM7  ) Base Address */
#define GPBR                   (0x400E1490)                   /**< \brief (GPBR      ) Base Address */
#define I2SC0                  (0x40000000)                   /**< \brief (I2SC0     ) Base Address */
#define I2SC1                  (0x40004000)                   /**< \brief (I2SC1     ) Base Address */
#define MATRIX                 (0x400E0200)                   /**< \brief (MATRIX    ) Base Address */
#define MEM2MEM                (0x40028000)                   /**< \brief (MEM2MEM   ) Base Address */
#define PDMIC0                 (0x4002C000)                   /**< \brief (PDMIC0    ) Base Address */
#define PDMIC1                 (0x40030000)                   /**< \brief (PDMIC1    ) Base Address */
#define PIOA                   (0x400E0E00)                   /**< \brief (PIOA      ) Base Address */
#define PIOB                   (0x400E1000)                   /**< \brief (PIOB      ) Base Address */
#define PMC                    (0x400E0400)                   /**< \brief (PMC       ) Base Address */
#define RSTC                   (0x400E1400)                   /**< \brief (RSTC      ) Base Address */
#define RTC                    (0x400E1460)                   /**< \brief (RTC       ) Base Address */
#define RTT                    (0x400E1430)                   /**< \brief (RTT       ) Base Address */
#define SPI0                   (0x4000C400)                   /**< \brief (SPI0      ) Base Address */
#define SPI1                   (0x40020400)                   /**< \brief (SPI1      ) Base Address */
#define SPI2                   (0x40024400)                   /**< \brief (SPI2      ) Base Address */
#define SPI3                   (0x40018400)                   /**< \brief (SPI3      ) Base Address */
#define SPI4                   (0x4001C400)                   /**< \brief (SPI4      ) Base Address */
#define SPI5                   (0x40008400)                   /**< \brief (SPI5      ) Base Address */
#define SPI6                   (0x40040400)                   /**< \brief (SPI6      ) Base Address */
#define SUPC                   (0x400E1410)                   /**< \brief (SUPC      ) Base Address */
#define TC0                    (0x40010000)                   /**< \brief (TC0       ) Base Address */
#define TC1                    (0x40014000)                   /**< \brief (TC1       ) Base Address */
#define TWI0                   (0x4000C600)                   /**< \brief (TWI0      ) Base Address */
#define TWI1                   (0x40020600)                   /**< \brief (TWI1      ) Base Address */
#define TWI2                   (0x40024600)                   /**< \brief (TWI2      ) Base Address */
#define TWI3                   (0x40018600)                   /**< \brief (TWI3      ) Base Address */
#define TWI4                   (0x4001C600)                   /**< \brief (TWI4      ) Base Address */
#define TWI5                   (0x40008600)                   /**< \brief (TWI5      ) Base Address */
#define TWI6                   (0x40040600)                   /**< \brief (TWI6      ) Base Address */
#define UDP                    (0x40044000)                   /**< \brief (UDP       ) Base Address */
#define UHP                    (0x4004C000)                   /**< \brief (UHP       ) Base Address */
#define USART0                 (0x4000C200)                   /**< \brief (USART0    ) Base Address */
#define USART1                 (0x40020200)                   /**< \brief (USART1    ) Base Address */
#define USART2                 (0x40024200)                   /**< \brief (USART2    ) Base Address */
#define USART3                 (0x40018200)                   /**< \brief (USART3    ) Base Address */
#define USART4                 (0x4001C200)                   /**< \brief (USART4    ) Base Address */
#define USART5                 (0x40008200)                   /**< \brief (USART5    ) Base Address */
#define USART6                 (0x40040200)                   /**< \brief (USART6    ) Base Address */
#define WDT                    (0x400E1450)                   /**< \brief (WDT       ) Base Address */

#else /* For C/C++ compiler */

#define ADC                    ((Adc *)0x40038000U)           /**< \brief (ADC       ) Base Address */
#define ADC_INST_NUM           1                              /**< \brief (ADC       ) Number of instances */
#define ADC_INSTS              { ADC }                        /**< \brief (ADC       ) Instances List */

#define CHIPID                 ((Chipid *)0x400E0740U)        /**< \brief (CHIPID    ) Base Address */
#define CHIPID_INST_NUM        1                              /**< \brief (CHIPID    ) Number of instances */
#define CHIPID_INSTS           { CHIPID }                     /**< \brief (CHIPID    ) Instances List */

#define CMCC                   ((Cmcc *)0x4003C000U)          /**< \brief (CMCC      ) Base Address */
#define CMCC_INST_NUM          1                              /**< \brief (CMCC      ) Number of instances */
#define CMCC_INSTS             { CMCC }                       /**< \brief (CMCC      ) Instances List */

#define CRCCU                  ((Crccu *)0x40048000U)         /**< \brief (CRCCU     ) Base Address */
#define CRCCU_INST_NUM         1                              /**< \brief (CRCCU     ) Number of instances */
#define CRCCU_INSTS            { CRCCU }                      /**< \brief (CRCCU     ) Instances List */

#define EFC                    ((Efc *)0x400E0A00U)           /**< \brief (EFC       ) Base Address */
#define EFC_INST_NUM           1                              /**< \brief (EFC       ) Number of instances */
#define EFC_INSTS              { EFC }                        /**< \brief (EFC       ) Instances List */

#define FLEXCOM0               ((Flexcom *)0x4000C000U)       /**< \brief (FLEXCOM0  ) Base Address */
#define FLEXCOM1               ((Flexcom *)0x40020000U)       /**< \brief (FLEXCOM1  ) Base Address */
#define FLEXCOM2               ((Flexcom *)0x40024000U)       /**< \brief (FLEXCOM2  ) Base Address */
#define FLEXCOM3               ((Flexcom *)0x40018000U)       /**< \brief (FLEXCOM3  ) Base Address */
#define FLEXCOM4               ((Flexcom *)0x4001C000U)       /**< \brief (FLEXCOM4  ) Base Address */
#define FLEXCOM5               ((Flexcom *)0x40008000U)       /**< \brief (FLEXCOM5  ) Base Address */
#define FLEXCOM6               ((Flexcom *)0x40040000U)       /**< \brief (FLEXCOM6  ) Base Address */
#define FLEXCOM7               ((Flexcom *)0x40034000U)       /**< \brief (FLEXCOM7  ) Base Address */
#define FLEXCOM_INST_NUM       8                              /**< \brief (FLEXCOM   ) Number of instances */
#define FLEXCOM_INSTS          { FLEXCOM0, FLEXCOM1, FLEXCOM2, FLEXCOM3, FLEXCOM4, FLEXCOM5, FLEXCOM6, FLEXCOM7 } /**< \brief (FLEXCOM   ) Instances List */

#define GPBR                   ((Gpbr *)0x400E1490U)          /**< \brief (GPBR      ) Base Address */
#define GPBR_INST_NUM          1                              /**< \brief (GPBR      ) Number of instances */
#define GPBR_INSTS             { GPBR }                       /**< \brief (GPBR      ) Instances List */

#define I2SC0                  ((I2sc *)0x40000000U)          /**< \brief (I2SC0     ) Base Address */
#define I2SC1                  ((I2sc *)0x40004000U)          /**< \brief (I2SC1     ) Base Address */
#define I2SC_INST_NUM          2                              /**< \brief (I2SC      ) Number of instances */
#define I2SC_INSTS             { I2SC0, I2SC1 }               /**< \brief (I2SC      ) Instances List */

#define MATRIX                 ((Matrix *)0x400E0200U)        /**< \brief (MATRIX    ) Base Address */
#define MATRIX_INST_NUM        1                              /**< \brief (MATRIX    ) Number of instances */
#define MATRIX_INSTS           { MATRIX }                     /**< \brief (MATRIX    ) Instances List */

#define MEM2MEM                ((Mem2mem *)0x40028000U)       /**< \brief (MEM2MEM   ) Base Address */
#define MEM2MEM_INST_NUM       1                              /**< \brief (MEM2MEM   ) Number of instances */
#define MEM2MEM_INSTS          { MEM2MEM }                    /**< \brief (MEM2MEM   ) Instances List */

#define PDMIC0                 ((Pdmic *)0x4002C000U)         /**< \brief (PDMIC0    ) Base Address */
#define PDMIC1                 ((Pdmic *)0x40030000U)         /**< \brief (PDMIC1    ) Base Address */
#define PDMIC_INST_NUM         2                              /**< \brief (PDMIC     ) Number of instances */
#define PDMIC_INSTS            { PDMIC0, PDMIC1 }             /**< \brief (PDMIC     ) Instances List */

#define PIOA                   ((Pio *)0x400E0E00U)           /**< \brief (PIOA      ) Base Address */
#define PIOB                   ((Pio *)0x400E1000U)           /**< \brief (PIOB      ) Base Address */
#define PIO_INST_NUM           2                              /**< \brief (PIO       ) Number of instances */
#define PIO_INSTS              { PIOA, PIOB }                 /**< \brief (PIO       ) Instances List */

#define PMC                    ((Pmc *)0x400E0400U)           /**< \brief (PMC       ) Base Address */
#define PMC_INST_NUM           1                              /**< \brief (PMC       ) Number of instances */
#define PMC_INSTS              { PMC }                        /**< \brief (PMC       ) Instances List */

#define RSTC                   ((Rstc *)0x400E1400U)          /**< \brief (RSTC      ) Base Address */
#define RSTC_INST_NUM          1                              /**< \brief (RSTC      ) Number of instances */
#define RSTC_INSTS             { RSTC }                       /**< \brief (RSTC      ) Instances List */

#define RTC                    ((Rtc *)0x400E1460U)           /**< \brief (RTC       ) Base Address */
#define RTC_INST_NUM           1                              /**< \brief (RTC       ) Number of instances */
#define RTC_INSTS              { RTC }                        /**< \brief (RTC       ) Instances List */

#define RTT                    ((Rtt *)0x400E1430U)           /**< \brief (RTT       ) Base Address */
#define RTT_INST_NUM           1                              /**< \brief (RTT       ) Number of instances */
#define RTT_INSTS              { RTT }                        /**< \brief (RTT       ) Instances List */

#define SPI0                   ((Spi *)0x4000C400U)           /**< \brief (SPI0      ) Base Address */
#define SPI1                   ((Spi *)0x40020400U)           /**< \brief (SPI1      ) Base Address */
#define SPI2                   ((Spi *)0x40024400U)           /**< \brief (SPI2      ) Base Address */
#define SPI3                   ((Spi *)0x40018400U)           /**< \brief (SPI3      ) Base Address */
#define SPI4                   ((Spi *)0x4001C400U)           /**< \brief (SPI4      ) Base Address */
#define SPI5                   ((Spi *)0x40008400U)           /**< \brief (SPI5      ) Base Address */
#define SPI6                   ((Spi *)0x40040400U)           /**< \brief (SPI6      ) Base Address */
#define SPI_INST_NUM           7                              /**< \brief (SPI       ) Number of instances */
#define SPI_INSTS              { SPI0, SPI1, SPI2, SPI3, SPI4, SPI5, SPI6 } /**< \brief (SPI       ) Instances List */

#define SUPC                   ((Supc *)0x400E1410U)          /**< \brief (SUPC      ) Base Address */
#define SUPC_INST_NUM          1                              /**< \brief (SUPC      ) Number of instances */
#define SUPC_INSTS             { SUPC }                       /**< \brief (SUPC      ) Instances List */

#define TC0                    ((Tc *)0x40010000U)            /**< \brief (TC0       ) Base Address */
#define TC1                    ((Tc *)0x40014000U)            /**< \brief (TC1       ) Base Address */
#define TC_INST_NUM            2                              /**< \brief (TC        ) Number of instances */
#define TC_INSTS               { TC0, TC1 }                   /**< \brief (TC        ) Instances List */

#define TWI0                   ((Twi *)0x4000C600U)           /**< \brief (TWI0      ) Base Address */
#define TWI1                   ((Twi *)0x40020600U)           /**< \brief (TWI1      ) Base Address */
#define TWI2                   ((Twi *)0x40024600U)           /**< \brief (TWI2      ) Base Address */
#define TWI3                   ((Twi *)0x40018600U)           /**< \brief (TWI3      ) Base Address */
#define TWI4                   ((Twi *)0x4001C600U)           /**< \brief (TWI4      ) Base Address */
#define TWI5                   ((Twi *)0x40008600U)           /**< \brief (TWI5      ) Base Address */
#define TWI6                   ((Twi *)0x40040600U)           /**< \brief (TWI6      ) Base Address */
#define TWI_INST_NUM           7                              /**< \brief (TWI       ) Number of instances */
#define TWI_INSTS              { TWI0, TWI1, TWI2, TWI3, TWI4, TWI5, TWI6 } /**< \brief (TWI       ) Instances List */

#define UDP                    ((Udp *)0x40044000U)           /**< \brief (UDP       ) Base Address */
#define UDP_INST_NUM           1                              /**< \brief (UDP       ) Number of instances */
#define UDP_INSTS              { UDP }                        /**< \brief (UDP       ) Instances List */

#define UHP                    ((Uhp *)0x4004C000U)           /**< \brief (UHP       ) Base Address */
#define UHP_INST_NUM           1                              /**< \brief (UHP       ) Number of instances */
#define UHP_INSTS              { UHP }                        /**< \brief (UHP       ) Instances List */

#define USART0                 ((Usart *)0x4000C200U)         /**< \brief (USART0    ) Base Address */
#define USART1                 ((Usart *)0x40020200U)         /**< \brief (USART1    ) Base Address */
#define USART2                 ((Usart *)0x40024200U)         /**< \brief (USART2    ) Base Address */
#define USART3                 ((Usart *)0x40018200U)         /**< \brief (USART3    ) Base Address */
#define USART4                 ((Usart *)0x4001C200U)         /**< \brief (USART4    ) Base Address */
#define USART5                 ((Usart *)0x40008200U)         /**< \brief (USART5    ) Base Address */
#define USART6                 ((Usart *)0x40040200U)         /**< \brief (USART6    ) Base Address */
#define USART_INST_NUM         7                              /**< \brief (USART     ) Number of instances */
#define USART_INSTS            { USART0, USART1, USART2, USART3, USART4, USART5, USART6 } /**< \brief (USART     ) Instances List */

#define WDT                    ((Wdt *)0x400E1450U)           /**< \brief (WDT       ) Base Address */
#define WDT_INST_NUM           1                              /**< \brief (WDT       ) Number of instances */
#define WDT_INSTS              { WDT }                        /**< \brief (WDT       ) Instances List */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
/** @}  end of Peripheral Base Address Definitions */

/** \addtogroup SAMG55G19_pio Peripheral Pio Definitions
 *  @{
 */

/* ************************************************************************** */
/*   PIO DEFINITIONS FOR SAMG55G19*/
/* ************************************************************************** */
#include "pio/samg55g19.h"
/** @}  end of Peripheral Pio Definitions */

/* ************************************************************************** */
/*   MEMORY MAPPING DEFINITIONS FOR SAMG55G19*/
/* ************************************************************************** */

#define PERIPHERALS_SIZE         _U_(0x20000000)       /* 524288kB Memory segment type: io */
#define SYSTEM_SIZE              _U_(0x10000000)       /* 262144kB Memory segment type: io */
#define IFLASH_SIZE              _U_(0x00080000)       /*  512kB Memory segment type: flash */
#define IFLASH_PAGE_SIZE         _U_(       512)
#define IFLASH_NB_OF_PAGES       _U_(      1024)

#define IROM_SIZE                _U_(0x00400000)       /* 4096kB Memory segment type: rom */
#define IRAM_SIZE                _U_(0x00028000)       /*  160kB Memory segment type: ram */
#define CMCC_SIZE                _U_(0x00004000)       /*   16kB Memory segment type: other */

#define PERIPHERALS_ADDR         _U_(0x40000000)       /**< PERIPHERALS base address (type: io)*/
#define SYSTEM_ADDR              _U_(0xe0000000)       /**< SYSTEM base address (type: io)*/
#define IFLASH_ADDR              _U_(0x00400000)       /**< IFLASH base address (type: flash)*/
#define IROM_ADDR                _U_(0x00800000)       /**< IROM base address (type: rom)*/
#define IRAM_ADDR                _U_(0x20000000)       /**< IRAM base address (type: ram)*/
#define CMCC_ADDR                _U_(0x1fc00000)       /**< CMCC base address (type: other)*/

/* ************************************************************************** */
/**  DEVICE SIGNATURES FOR SAMG55G19 */
/* ************************************************************************** */
#define JTAGID                   _UL_(0X05B3E03F)
#define CHIP_JTAGID              _UL_(0X05B3E03F)
#define CHIP_CIDR                _UL_(0X24470AE0)
#define CHIP_EXID                _UL_(0X00000000)

/* ************************************************************************** */
/**  ELECTRICAL DEFINITIONS FOR SAMG55G19 */
/* ************************************************************************** */
#define CHIP_FREQ_SLCK_RC_MIN          _UL_(20000)     
#define CHIP_FREQ_SLCK_RC              _UL_(32000)     /**< \brief Typical Slow Clock Internal RC frequency*/
#define CHIP_FREQ_SLCK_RC_MAX          _UL_(44000)     
#define CHIP_FREQ_MAINCK_RC_8MHZ       _UL_(8000000)   
#define CHIP_FREQ_MAINCK_RC_16MHZ      _UL_(16000000)  
#define CHIP_FREQ_MAINCK_RC_24MHZ      _UL_(24000000)  
#define CHIP_FREQ_CPU_MAX              _UL_(120000000) 
#define CHIP_FREQ_XTAL_32K             _UL_(32768)     
#define CHIP_FLASH_WRITE_WAIT_STATE    _UL_(8)         /**< \brief Embedded Flash Write Wait State*/
#define CHIP_FREQ_FWS_0                _UL_(14000000)  /**< \brief Maximum operating frequency when FWS is 0*/
#define CHIP_FREQ_FWS_1                _UL_(28000000)  /**< \brief Maximum operating frequency when FWS is 1*/
#define CHIP_FREQ_FWS_2                _UL_(42000000)  /**< \brief Maximum operating frequency when FWS is 2*/
#define CHIP_FREQ_FWS_3                _UL_(56000000)  /**< \brief Maximum operating frequency when FWS is 3*/
#define CHIP_FREQ_FWS_4                _UL_(70000000)  /**< \brief Maximum operating frequency when FWS is 4*/
#define CHIP_FREQ_FWS_5                _UL_(84000000)  /**< \brief Maximum operating frequency when FWS is 5*/
#define CHIP_FREQ_FWS_6                _UL_(96000000)  /**< \brief Maximum operating frequency when FWS is 6*/
#define CHIP_FREQ_FWS_7                _UL_(108000000) /**< \brief Maximum operating frequency when FWS is 7*/
#define CHIP_FREQ_FWS_8                _UL_(120000000) /**< \brief Maximum operating frequency when FWS is 8*/
#define CHIP_FREQ_FWS_NUMBER           _UL_(9)         /**< \brief Number of FWS ranges*/

#ifdef __cplusplus
}
#endif

/** @}  end of SAMG55G19 definitions */


#endif /* _SAMG55G19_H_ */
