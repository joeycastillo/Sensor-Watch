/**
 * \file
 *
 * \brief Component description for RTT
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
#ifndef _SAMG55_RTT_COMPONENT_H_
#define _SAMG55_RTT_COMPONENT_H_
#define _SAMG55_RTT_COMPONENT_         /**< \deprecated  Backward compatibility for ASF */

/** \addtogroup SAMG_SAMG55 Real-time Timer
 *  @{
 */
/* ========================================================================== */
/**  SOFTWARE API DEFINITION FOR RTT */
/* ========================================================================== */
#ifndef COMPONENT_TYPEDEF_STYLE
  #define COMPONENT_TYPEDEF_STYLE 'R'  /**< Defines default style of typedefs for the component header files ('R' = RFO, 'N' = NTO)*/
#endif

#define RTT_6081                       /**< (RTT) Module ID */
#define REV_RTT M                      /**< (RTT) Module revision */

/* -------- RTT_MR : (RTT Offset: 0x00) (R/W 32) Mode Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RTPRES:16;                 /**< bit:  0..15  Real-time Timer Prescaler Value          */
    uint32_t ALMIEN:1;                  /**< bit:     16  Alarm Interrupt Enable                   */
    uint32_t RTTINCIEN:1;               /**< bit:     17  Real-time Timer Increment Interrupt Enable */
    uint32_t RTTRST:1;                  /**< bit:     18  Real-time Timer Restart                  */
    uint32_t :1;                        /**< bit:     19  Reserved */
    uint32_t RTTDIS:1;                  /**< bit:     20  Real-time Timer Disable                  */
    uint32_t INC2AEN:1;                 /**< bit:     21  RTTINC2 Alarm Enable                     */
    uint32_t EVAEN:1;                   /**< bit:     22  Trigger Event Alarm Enable               */
    uint32_t :1;                        /**< bit:     23  Reserved */
    uint32_t RTC1HZ:1;                  /**< bit:     24  Real-Time Clock 1Hz Clock Selection      */
    uint32_t :7;                        /**< bit: 25..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} RTT_MR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define RTT_MR_OFFSET                       (0x00)                                        /**<  (RTT_MR) Mode Register  Offset */

#define RTT_MR_RTPRES_Pos                   0                                              /**< (RTT_MR) Real-time Timer Prescaler Value Position */
#define RTT_MR_RTPRES_Msk                   (_U_(0xFFFF) << RTT_MR_RTPRES_Pos)             /**< (RTT_MR) Real-time Timer Prescaler Value Mask */
#define RTT_MR_RTPRES(value)                (RTT_MR_RTPRES_Msk & ((value) << RTT_MR_RTPRES_Pos))
#define RTT_MR_ALMIEN_Pos                   16                                             /**< (RTT_MR) Alarm Interrupt Enable Position */
#define RTT_MR_ALMIEN_Msk                   (_U_(0x1) << RTT_MR_ALMIEN_Pos)                /**< (RTT_MR) Alarm Interrupt Enable Mask */
#define RTT_MR_ALMIEN                       RTT_MR_ALMIEN_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use RTT_MR_ALMIEN_Msk instead */
#define RTT_MR_RTTINCIEN_Pos                17                                             /**< (RTT_MR) Real-time Timer Increment Interrupt Enable Position */
#define RTT_MR_RTTINCIEN_Msk                (_U_(0x1) << RTT_MR_RTTINCIEN_Pos)             /**< (RTT_MR) Real-time Timer Increment Interrupt Enable Mask */
#define RTT_MR_RTTINCIEN                    RTT_MR_RTTINCIEN_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use RTT_MR_RTTINCIEN_Msk instead */
#define RTT_MR_RTTRST_Pos                   18                                             /**< (RTT_MR) Real-time Timer Restart Position */
#define RTT_MR_RTTRST_Msk                   (_U_(0x1) << RTT_MR_RTTRST_Pos)                /**< (RTT_MR) Real-time Timer Restart Mask */
#define RTT_MR_RTTRST                       RTT_MR_RTTRST_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use RTT_MR_RTTRST_Msk instead */
#define RTT_MR_RTTDIS_Pos                   20                                             /**< (RTT_MR) Real-time Timer Disable Position */
#define RTT_MR_RTTDIS_Msk                   (_U_(0x1) << RTT_MR_RTTDIS_Pos)                /**< (RTT_MR) Real-time Timer Disable Mask */
#define RTT_MR_RTTDIS                       RTT_MR_RTTDIS_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use RTT_MR_RTTDIS_Msk instead */
#define RTT_MR_INC2AEN_Pos                  21                                             /**< (RTT_MR) RTTINC2 Alarm Enable Position */
#define RTT_MR_INC2AEN_Msk                  (_U_(0x1) << RTT_MR_INC2AEN_Pos)               /**< (RTT_MR) RTTINC2 Alarm Enable Mask */
#define RTT_MR_INC2AEN                      RTT_MR_INC2AEN_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use RTT_MR_INC2AEN_Msk instead */
#define RTT_MR_EVAEN_Pos                    22                                             /**< (RTT_MR) Trigger Event Alarm Enable Position */
#define RTT_MR_EVAEN_Msk                    (_U_(0x1) << RTT_MR_EVAEN_Pos)                 /**< (RTT_MR) Trigger Event Alarm Enable Mask */
#define RTT_MR_EVAEN                        RTT_MR_EVAEN_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use RTT_MR_EVAEN_Msk instead */
#define RTT_MR_RTC1HZ_Pos                   24                                             /**< (RTT_MR) Real-Time Clock 1Hz Clock Selection Position */
#define RTT_MR_RTC1HZ_Msk                   (_U_(0x1) << RTT_MR_RTC1HZ_Pos)                /**< (RTT_MR) Real-Time Clock 1Hz Clock Selection Mask */
#define RTT_MR_RTC1HZ                       RTT_MR_RTC1HZ_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use RTT_MR_RTC1HZ_Msk instead */
#define RTT_MR_MASK                         _U_(0x177FFFF)                                 /**< \deprecated (RTT_MR) Register MASK  (Use RTT_MR_Msk instead)  */
#define RTT_MR_Msk                          _U_(0x177FFFF)                                 /**< (RTT_MR) Register Mask  */


/* -------- RTT_AR : (RTT Offset: 0x04) (R/W 32) Alarm Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t ALMV:32;                   /**< bit:  0..31  Alarm Value                              */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} RTT_AR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define RTT_AR_OFFSET                       (0x04)                                        /**<  (RTT_AR) Alarm Register  Offset */

#define RTT_AR_ALMV_Pos                     0                                              /**< (RTT_AR) Alarm Value Position */
#define RTT_AR_ALMV_Msk                     (_U_(0xFFFFFFFF) << RTT_AR_ALMV_Pos)           /**< (RTT_AR) Alarm Value Mask */
#define RTT_AR_ALMV(value)                  (RTT_AR_ALMV_Msk & ((value) << RTT_AR_ALMV_Pos))
#define RTT_AR_MASK                         _U_(0xFFFFFFFF)                                /**< \deprecated (RTT_AR) Register MASK  (Use RTT_AR_Msk instead)  */
#define RTT_AR_Msk                          _U_(0xFFFFFFFF)                                /**< (RTT_AR) Register Mask  */


/* -------- RTT_VR : (RTT Offset: 0x08) (R/ 32) Value Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t CRTV:32;                   /**< bit:  0..31  Current Real-time Value                  */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} RTT_VR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define RTT_VR_OFFSET                       (0x08)                                        /**<  (RTT_VR) Value Register  Offset */

#define RTT_VR_CRTV_Pos                     0                                              /**< (RTT_VR) Current Real-time Value Position */
#define RTT_VR_CRTV_Msk                     (_U_(0xFFFFFFFF) << RTT_VR_CRTV_Pos)           /**< (RTT_VR) Current Real-time Value Mask */
#define RTT_VR_CRTV(value)                  (RTT_VR_CRTV_Msk & ((value) << RTT_VR_CRTV_Pos))
#define RTT_VR_MASK                         _U_(0xFFFFFFFF)                                /**< \deprecated (RTT_VR) Register MASK  (Use RTT_VR_Msk instead)  */
#define RTT_VR_Msk                          _U_(0xFFFFFFFF)                                /**< (RTT_VR) Register Mask  */


/* -------- RTT_SR : (RTT Offset: 0x0c) (R/ 32) Status Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t ALMS:1;                    /**< bit:      0  Real-time Alarm Status (cleared on read) */
    uint32_t RTTINC:1;                  /**< bit:      1  Prescaler Roll-over Status (cleared on read) */
    uint32_t RTTINC2:1;                 /**< bit:      2  Predefined Number of Prescaler Roll-over Status (cleared on read) */
    uint32_t :29;                       /**< bit:  3..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} RTT_SR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define RTT_SR_OFFSET                       (0x0C)                                        /**<  (RTT_SR) Status Register  Offset */

#define RTT_SR_ALMS_Pos                     0                                              /**< (RTT_SR) Real-time Alarm Status (cleared on read) Position */
#define RTT_SR_ALMS_Msk                     (_U_(0x1) << RTT_SR_ALMS_Pos)                  /**< (RTT_SR) Real-time Alarm Status (cleared on read) Mask */
#define RTT_SR_ALMS                         RTT_SR_ALMS_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use RTT_SR_ALMS_Msk instead */
#define RTT_SR_RTTINC_Pos                   1                                              /**< (RTT_SR) Prescaler Roll-over Status (cleared on read) Position */
#define RTT_SR_RTTINC_Msk                   (_U_(0x1) << RTT_SR_RTTINC_Pos)                /**< (RTT_SR) Prescaler Roll-over Status (cleared on read) Mask */
#define RTT_SR_RTTINC                       RTT_SR_RTTINC_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use RTT_SR_RTTINC_Msk instead */
#define RTT_SR_RTTINC2_Pos                  2                                              /**< (RTT_SR) Predefined Number of Prescaler Roll-over Status (cleared on read) Position */
#define RTT_SR_RTTINC2_Msk                  (_U_(0x1) << RTT_SR_RTTINC2_Pos)               /**< (RTT_SR) Predefined Number of Prescaler Roll-over Status (cleared on read) Mask */
#define RTT_SR_RTTINC2                      RTT_SR_RTTINC2_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use RTT_SR_RTTINC2_Msk instead */
#define RTT_SR_MASK                         _U_(0x07)                                      /**< \deprecated (RTT_SR) Register MASK  (Use RTT_SR_Msk instead)  */
#define RTT_SR_Msk                          _U_(0x07)                                      /**< (RTT_SR) Register Mask  */


/* -------- RTT_MODR : (RTT Offset: 0x10) (R/W 32) Modulo Selection Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t SELINC2:3;                 /**< bit:   0..2  Selection of the 32-bit Counter Modulo to generate RTTINC2 flag */
    uint32_t :5;                        /**< bit:   3..7  Reserved */
    uint32_t SELTRGEV:3;                /**< bit:  8..10  Selection of the 32-bit Counter Modulo to generate the trigger event */
    uint32_t :21;                       /**< bit: 11..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} RTT_MODR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define RTT_MODR_OFFSET                     (0x10)                                        /**<  (RTT_MODR) Modulo Selection Register  Offset */

#define RTT_MODR_SELINC2_Pos                0                                              /**< (RTT_MODR) Selection of the 32-bit Counter Modulo to generate RTTINC2 flag Position */
#define RTT_MODR_SELINC2_Msk                (_U_(0x7) << RTT_MODR_SELINC2_Pos)             /**< (RTT_MODR) Selection of the 32-bit Counter Modulo to generate RTTINC2 flag Mask */
#define RTT_MODR_SELINC2(value)             (RTT_MODR_SELINC2_Msk & ((value) << RTT_MODR_SELINC2_Pos))
#define   RTT_MODR_SELINC2_NO_RTTINC2_Val   _U_(0x0)                                       /**< (RTT_MODR) The RTTINC2 flag never rises  */
#define   RTT_MODR_SELINC2_MOD64_Val        _U_(0x1)                                       /**< (RTT_MODR) The RTTINC2 flag is set when CRTV modulo 64 equals 0  */
#define   RTT_MODR_SELINC2_MOD128_Val       _U_(0x2)                                       /**< (RTT_MODR) The RTTINC2 flag is set when CRTV modulo 128 equals 0  */
#define   RTT_MODR_SELINC2_MOD256_Val       _U_(0x3)                                       /**< (RTT_MODR) The RTTINC2 flag is set when CRTV modulo 256 equals 0  */
#define   RTT_MODR_SELINC2_MOD512_Val       _U_(0x4)                                       /**< (RTT_MODR) The RTTINC2 flag is set when CRTV modulo 512 equals 0  */
#define   RTT_MODR_SELINC2_MOD1024_Val      _U_(0x5)                                       /**< (RTT_MODR) The RTTINC2 flag is set when CRTV modulo 1024 equals 0.Example: If RTPRES=32 then RTTINC2 flag rises once per second if the slow clock is 32.768 kHz.  */
#define   RTT_MODR_SELINC2_MOD2048_Val      _U_(0x6)                                       /**< (RTT_MODR) The RTTINC2 flag is set when CRTV modulo 2048 equals 0  */
#define   RTT_MODR_SELINC2_MOD4096_Val      _U_(0x7)                                       /**< (RTT_MODR) The RTTINC2 flag is set when CRTV modulo 4096 equals 0  */
#define RTT_MODR_SELINC2_NO_RTTINC2         (RTT_MODR_SELINC2_NO_RTTINC2_Val << RTT_MODR_SELINC2_Pos)  /**< (RTT_MODR) The RTTINC2 flag never rises Position  */
#define RTT_MODR_SELINC2_MOD64              (RTT_MODR_SELINC2_MOD64_Val << RTT_MODR_SELINC2_Pos)  /**< (RTT_MODR) The RTTINC2 flag is set when CRTV modulo 64 equals 0 Position  */
#define RTT_MODR_SELINC2_MOD128             (RTT_MODR_SELINC2_MOD128_Val << RTT_MODR_SELINC2_Pos)  /**< (RTT_MODR) The RTTINC2 flag is set when CRTV modulo 128 equals 0 Position  */
#define RTT_MODR_SELINC2_MOD256             (RTT_MODR_SELINC2_MOD256_Val << RTT_MODR_SELINC2_Pos)  /**< (RTT_MODR) The RTTINC2 flag is set when CRTV modulo 256 equals 0 Position  */
#define RTT_MODR_SELINC2_MOD512             (RTT_MODR_SELINC2_MOD512_Val << RTT_MODR_SELINC2_Pos)  /**< (RTT_MODR) The RTTINC2 flag is set when CRTV modulo 512 equals 0 Position  */
#define RTT_MODR_SELINC2_MOD1024            (RTT_MODR_SELINC2_MOD1024_Val << RTT_MODR_SELINC2_Pos)  /**< (RTT_MODR) The RTTINC2 flag is set when CRTV modulo 1024 equals 0.Example: If RTPRES=32 then RTTINC2 flag rises once per second if the slow clock is 32.768 kHz. Position  */
#define RTT_MODR_SELINC2_MOD2048            (RTT_MODR_SELINC2_MOD2048_Val << RTT_MODR_SELINC2_Pos)  /**< (RTT_MODR) The RTTINC2 flag is set when CRTV modulo 2048 equals 0 Position  */
#define RTT_MODR_SELINC2_MOD4096            (RTT_MODR_SELINC2_MOD4096_Val << RTT_MODR_SELINC2_Pos)  /**< (RTT_MODR) The RTTINC2 flag is set when CRTV modulo 4096 equals 0 Position  */
#define RTT_MODR_SELTRGEV_Pos               8                                              /**< (RTT_MODR) Selection of the 32-bit Counter Modulo to generate the trigger event Position */
#define RTT_MODR_SELTRGEV_Msk               (_U_(0x7) << RTT_MODR_SELTRGEV_Pos)            /**< (RTT_MODR) Selection of the 32-bit Counter Modulo to generate the trigger event Mask */
#define RTT_MODR_SELTRGEV(value)            (RTT_MODR_SELTRGEV_Msk & ((value) << RTT_MODR_SELTRGEV_Pos))
#define   RTT_MODR_SELTRGEV_NO_EVENT_Val    _U_(0x0)                                       /**< (RTT_MODR) No event generated  */
#define   RTT_MODR_SELTRGEV_MOD2_Val        _U_(0x1)                                       /**< (RTT_MODR) Event occurs when CRTV modulo 2 equals 0  */
#define   RTT_MODR_SELTRGEV_MOD4_Val        _U_(0x2)                                       /**< (RTT_MODR) Event occurs when CRTV modulo 4 equals 0  */
#define   RTT_MODR_SELTRGEV_MOD8_Val        _U_(0x3)                                       /**< (RTT_MODR) Event occurs when CRTV modulo 8 equals 0  */
#define   RTT_MODR_SELTRGEV_MOD16_Val       _U_(0x4)                                       /**< (RTT_MODR) Event occurs when CRTV modulo 16 equals 0  */
#define   RTT_MODR_SELTRGEV_MOD32_Val       _U_(0x5)                                       /**< (RTT_MODR) Event occurs when CRTV modulo 32 equals 0  */
#define   RTT_MODR_SELTRGEV_MOD64_Val       _U_(0x6)                                       /**< (RTT_MODR) Event occurs when CRTV modulo 64 equals 0  */
#define   RTT_MODR_SELTRGEV_MOD128_Val      _U_(0x7)                                       /**< (RTT_MODR) Event occurs when CRTV modulo 128 equals 0  */
#define RTT_MODR_SELTRGEV_NO_EVENT          (RTT_MODR_SELTRGEV_NO_EVENT_Val << RTT_MODR_SELTRGEV_Pos)  /**< (RTT_MODR) No event generated Position  */
#define RTT_MODR_SELTRGEV_MOD2              (RTT_MODR_SELTRGEV_MOD2_Val << RTT_MODR_SELTRGEV_Pos)  /**< (RTT_MODR) Event occurs when CRTV modulo 2 equals 0 Position  */
#define RTT_MODR_SELTRGEV_MOD4              (RTT_MODR_SELTRGEV_MOD4_Val << RTT_MODR_SELTRGEV_Pos)  /**< (RTT_MODR) Event occurs when CRTV modulo 4 equals 0 Position  */
#define RTT_MODR_SELTRGEV_MOD8              (RTT_MODR_SELTRGEV_MOD8_Val << RTT_MODR_SELTRGEV_Pos)  /**< (RTT_MODR) Event occurs when CRTV modulo 8 equals 0 Position  */
#define RTT_MODR_SELTRGEV_MOD16             (RTT_MODR_SELTRGEV_MOD16_Val << RTT_MODR_SELTRGEV_Pos)  /**< (RTT_MODR) Event occurs when CRTV modulo 16 equals 0 Position  */
#define RTT_MODR_SELTRGEV_MOD32             (RTT_MODR_SELTRGEV_MOD32_Val << RTT_MODR_SELTRGEV_Pos)  /**< (RTT_MODR) Event occurs when CRTV modulo 32 equals 0 Position  */
#define RTT_MODR_SELTRGEV_MOD64             (RTT_MODR_SELTRGEV_MOD64_Val << RTT_MODR_SELTRGEV_Pos)  /**< (RTT_MODR) Event occurs when CRTV modulo 64 equals 0 Position  */
#define RTT_MODR_SELTRGEV_MOD128            (RTT_MODR_SELTRGEV_MOD128_Val << RTT_MODR_SELTRGEV_Pos)  /**< (RTT_MODR) Event occurs when CRTV modulo 128 equals 0 Position  */
#define RTT_MODR_MASK                       _U_(0x707)                                     /**< \deprecated (RTT_MODR) Register MASK  (Use RTT_MODR_Msk instead)  */
#define RTT_MODR_Msk                        _U_(0x707)                                     /**< (RTT_MODR) Register Mask  */


#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'R'
/** \brief RTT hardware registers */
typedef struct {  
  __IO uint32_t RTT_MR;         /**< (RTT Offset: 0x00) Mode Register */
  __IO uint32_t RTT_AR;         /**< (RTT Offset: 0x04) Alarm Register */
  __I  uint32_t RTT_VR;         /**< (RTT Offset: 0x08) Value Register */
  __I  uint32_t RTT_SR;         /**< (RTT Offset: 0x0C) Status Register */
  __IO uint32_t RTT_MODR;       /**< (RTT Offset: 0x10) Modulo Selection Register */
} Rtt;

#elif COMPONENT_TYPEDEF_STYLE == 'N'
/** \brief RTT hardware registers */
typedef struct {  
  __IO RTT_MR_Type                    RTT_MR;         /**< Offset: 0x00 (R/W  32) Mode Register */
  __IO RTT_AR_Type                    RTT_AR;         /**< Offset: 0x04 (R/W  32) Alarm Register */
  __I  RTT_VR_Type                    RTT_VR;         /**< Offset: 0x08 (R/   32) Value Register */
  __I  RTT_SR_Type                    RTT_SR;         /**< Offset: 0x0C (R/   32) Status Register */
  __IO RTT_MODR_Type                  RTT_MODR;       /**< Offset: 0x10 (R/W  32) Modulo Selection Register */
} Rtt;

#else /* COMPONENT_TYPEDEF_STYLE */
#error Unknown component typedef style
#endif /* COMPONENT_TYPEDEF_STYLE */

#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
/** @}  end of Real-time Timer */

#endif /* _SAMG55_RTT_COMPONENT_H_ */
