/**
 * \file
 *
 * \brief Component description for CMCC
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
#ifndef _SAMG55_CMCC_COMPONENT_H_
#define _SAMG55_CMCC_COMPONENT_H_
#define _SAMG55_CMCC_COMPONENT_         /**< \deprecated  Backward compatibility for ASF */

/** \addtogroup SAMG_SAMG55 Cortex-M Cache Controller
 *  @{
 */
/* ========================================================================== */
/**  SOFTWARE API DEFINITION FOR CMCC */
/* ========================================================================== */
#ifndef COMPONENT_TYPEDEF_STYLE
  #define COMPONENT_TYPEDEF_STYLE 'R'  /**< Defines default style of typedefs for the component header files ('R' = RFO, 'N' = NTO)*/
#endif

#define CMCC_11108                      /**< (CMCC) Module ID */
#define REV_CMCC F                      /**< (CMCC) Module revision */

/* -------- CMCC_TYPE : (CMCC Offset: 0x00) (R/ 32) Cache Controller Type Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t AP:1;                      /**< bit:      0  Access Port Access Allowed               */
    uint32_t GCLK:1;                    /**< bit:      1  Dynamic Clock Gating Supported           */
    uint32_t RANDP:1;                   /**< bit:      2  Random Selection Policy Supported        */
    uint32_t LRUP:1;                    /**< bit:      3  Least Recently Used Policy Supported     */
    uint32_t RRP:1;                     /**< bit:      4  Random Selection Policy Supported        */
    uint32_t WAYNUM:2;                  /**< bit:   5..6  Number of Ways                           */
    uint32_t LCKDOWN:1;                 /**< bit:      7  Lockdown Supported                       */
    uint32_t CSIZE:3;                   /**< bit:  8..10  Data Cache Size                          */
    uint32_t CLSIZE:3;                  /**< bit: 11..13  Cache LIne Size                          */
    uint32_t :18;                       /**< bit: 14..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} CMCC_TYPE_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define CMCC_TYPE_OFFSET                    (0x00)                                        /**<  (CMCC_TYPE) Cache Controller Type Register  Offset */

#define CMCC_TYPE_AP_Pos                    0                                              /**< (CMCC_TYPE) Access Port Access Allowed Position */
#define CMCC_TYPE_AP_Msk                    (_U_(0x1) << CMCC_TYPE_AP_Pos)                 /**< (CMCC_TYPE) Access Port Access Allowed Mask */
#define CMCC_TYPE_AP                        CMCC_TYPE_AP_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use CMCC_TYPE_AP_Msk instead */
#define CMCC_TYPE_GCLK_Pos                  1                                              /**< (CMCC_TYPE) Dynamic Clock Gating Supported Position */
#define CMCC_TYPE_GCLK_Msk                  (_U_(0x1) << CMCC_TYPE_GCLK_Pos)               /**< (CMCC_TYPE) Dynamic Clock Gating Supported Mask */
#define CMCC_TYPE_GCLK                      CMCC_TYPE_GCLK_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use CMCC_TYPE_GCLK_Msk instead */
#define CMCC_TYPE_RANDP_Pos                 2                                              /**< (CMCC_TYPE) Random Selection Policy Supported Position */
#define CMCC_TYPE_RANDP_Msk                 (_U_(0x1) << CMCC_TYPE_RANDP_Pos)              /**< (CMCC_TYPE) Random Selection Policy Supported Mask */
#define CMCC_TYPE_RANDP                     CMCC_TYPE_RANDP_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use CMCC_TYPE_RANDP_Msk instead */
#define CMCC_TYPE_LRUP_Pos                  3                                              /**< (CMCC_TYPE) Least Recently Used Policy Supported Position */
#define CMCC_TYPE_LRUP_Msk                  (_U_(0x1) << CMCC_TYPE_LRUP_Pos)               /**< (CMCC_TYPE) Least Recently Used Policy Supported Mask */
#define CMCC_TYPE_LRUP                      CMCC_TYPE_LRUP_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use CMCC_TYPE_LRUP_Msk instead */
#define CMCC_TYPE_RRP_Pos                   4                                              /**< (CMCC_TYPE) Random Selection Policy Supported Position */
#define CMCC_TYPE_RRP_Msk                   (_U_(0x1) << CMCC_TYPE_RRP_Pos)                /**< (CMCC_TYPE) Random Selection Policy Supported Mask */
#define CMCC_TYPE_RRP                       CMCC_TYPE_RRP_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use CMCC_TYPE_RRP_Msk instead */
#define CMCC_TYPE_WAYNUM_Pos                5                                              /**< (CMCC_TYPE) Number of Ways Position */
#define CMCC_TYPE_WAYNUM_Msk                (_U_(0x3) << CMCC_TYPE_WAYNUM_Pos)             /**< (CMCC_TYPE) Number of Ways Mask */
#define CMCC_TYPE_WAYNUM(value)             (CMCC_TYPE_WAYNUM_Msk & ((value) << CMCC_TYPE_WAYNUM_Pos))
#define   CMCC_TYPE_WAYNUM_DMAPPED_Val      _U_(0x0)                                       /**< (CMCC_TYPE) Direct Mapped Cache  */
#define   CMCC_TYPE_WAYNUM_ARCH2WAY_Val     _U_(0x1)                                       /**< (CMCC_TYPE) 2-way set associative  */
#define   CMCC_TYPE_WAYNUM_ARCH4WAY_Val     _U_(0x2)                                       /**< (CMCC_TYPE) 4-way set associative  */
#define   CMCC_TYPE_WAYNUM_ARCH8WAY_Val     _U_(0x3)                                       /**< (CMCC_TYPE) 8-way set associative  */
#define CMCC_TYPE_WAYNUM_DMAPPED            (CMCC_TYPE_WAYNUM_DMAPPED_Val << CMCC_TYPE_WAYNUM_Pos)  /**< (CMCC_TYPE) Direct Mapped Cache Position  */
#define CMCC_TYPE_WAYNUM_ARCH2WAY           (CMCC_TYPE_WAYNUM_ARCH2WAY_Val << CMCC_TYPE_WAYNUM_Pos)  /**< (CMCC_TYPE) 2-way set associative Position  */
#define CMCC_TYPE_WAYNUM_ARCH4WAY           (CMCC_TYPE_WAYNUM_ARCH4WAY_Val << CMCC_TYPE_WAYNUM_Pos)  /**< (CMCC_TYPE) 4-way set associative Position  */
#define CMCC_TYPE_WAYNUM_ARCH8WAY           (CMCC_TYPE_WAYNUM_ARCH8WAY_Val << CMCC_TYPE_WAYNUM_Pos)  /**< (CMCC_TYPE) 8-way set associative Position  */
#define CMCC_TYPE_LCKDOWN_Pos               7                                              /**< (CMCC_TYPE) Lockdown Supported Position */
#define CMCC_TYPE_LCKDOWN_Msk               (_U_(0x1) << CMCC_TYPE_LCKDOWN_Pos)            /**< (CMCC_TYPE) Lockdown Supported Mask */
#define CMCC_TYPE_LCKDOWN                   CMCC_TYPE_LCKDOWN_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use CMCC_TYPE_LCKDOWN_Msk instead */
#define CMCC_TYPE_CSIZE_Pos                 8                                              /**< (CMCC_TYPE) Data Cache Size Position */
#define CMCC_TYPE_CSIZE_Msk                 (_U_(0x7) << CMCC_TYPE_CSIZE_Pos)              /**< (CMCC_TYPE) Data Cache Size Mask */
#define CMCC_TYPE_CSIZE(value)              (CMCC_TYPE_CSIZE_Msk & ((value) << CMCC_TYPE_CSIZE_Pos))
#define   CMCC_TYPE_CSIZE_CSIZE_1KB_Val     _U_(0x0)                                       /**< (CMCC_TYPE) Data cache size is 1 Kbyte  */
#define   CMCC_TYPE_CSIZE_CSIZE_2KB_Val     _U_(0x1)                                       /**< (CMCC_TYPE) Data cache size is 2 Kbytes  */
#define   CMCC_TYPE_CSIZE_CSIZE_4KB_Val     _U_(0x2)                                       /**< (CMCC_TYPE) Data cache size is 4 Kbytes  */
#define   CMCC_TYPE_CSIZE_CSIZE_8KB_Val     _U_(0x3)                                       /**< (CMCC_TYPE) Data cache size is 8 Kbytes  */
#define CMCC_TYPE_CSIZE_CSIZE_1KB           (CMCC_TYPE_CSIZE_CSIZE_1KB_Val << CMCC_TYPE_CSIZE_Pos)  /**< (CMCC_TYPE) Data cache size is 1 Kbyte Position  */
#define CMCC_TYPE_CSIZE_CSIZE_2KB           (CMCC_TYPE_CSIZE_CSIZE_2KB_Val << CMCC_TYPE_CSIZE_Pos)  /**< (CMCC_TYPE) Data cache size is 2 Kbytes Position  */
#define CMCC_TYPE_CSIZE_CSIZE_4KB           (CMCC_TYPE_CSIZE_CSIZE_4KB_Val << CMCC_TYPE_CSIZE_Pos)  /**< (CMCC_TYPE) Data cache size is 4 Kbytes Position  */
#define CMCC_TYPE_CSIZE_CSIZE_8KB           (CMCC_TYPE_CSIZE_CSIZE_8KB_Val << CMCC_TYPE_CSIZE_Pos)  /**< (CMCC_TYPE) Data cache size is 8 Kbytes Position  */
#define CMCC_TYPE_CLSIZE_Pos                11                                             /**< (CMCC_TYPE) Cache LIne Size Position */
#define CMCC_TYPE_CLSIZE_Msk                (_U_(0x7) << CMCC_TYPE_CLSIZE_Pos)             /**< (CMCC_TYPE) Cache LIne Size Mask */
#define CMCC_TYPE_CLSIZE(value)             (CMCC_TYPE_CLSIZE_Msk & ((value) << CMCC_TYPE_CLSIZE_Pos))
#define   CMCC_TYPE_CLSIZE_CLSIZE_1KB_Val   _U_(0x0)                                       /**< (CMCC_TYPE) Cache line size is 4 bytes  */
#define   CMCC_TYPE_CLSIZE_CLSIZE_2KB_Val   _U_(0x1)                                       /**< (CMCC_TYPE) Cache line size is 8 bytes  */
#define   CMCC_TYPE_CLSIZE_CLSIZE_4KB_Val   _U_(0x2)                                       /**< (CMCC_TYPE) Cache line size is 16 bytes  */
#define   CMCC_TYPE_CLSIZE_CLSIZE_8KB_Val   _U_(0x3)                                       /**< (CMCC_TYPE) Cache line size is 32 bytes  */
#define CMCC_TYPE_CLSIZE_CLSIZE_1KB         (CMCC_TYPE_CLSIZE_CLSIZE_1KB_Val << CMCC_TYPE_CLSIZE_Pos)  /**< (CMCC_TYPE) Cache line size is 4 bytes Position  */
#define CMCC_TYPE_CLSIZE_CLSIZE_2KB         (CMCC_TYPE_CLSIZE_CLSIZE_2KB_Val << CMCC_TYPE_CLSIZE_Pos)  /**< (CMCC_TYPE) Cache line size is 8 bytes Position  */
#define CMCC_TYPE_CLSIZE_CLSIZE_4KB         (CMCC_TYPE_CLSIZE_CLSIZE_4KB_Val << CMCC_TYPE_CLSIZE_Pos)  /**< (CMCC_TYPE) Cache line size is 16 bytes Position  */
#define CMCC_TYPE_CLSIZE_CLSIZE_8KB         (CMCC_TYPE_CLSIZE_CLSIZE_8KB_Val << CMCC_TYPE_CLSIZE_Pos)  /**< (CMCC_TYPE) Cache line size is 32 bytes Position  */
#define CMCC_TYPE_MASK                      _U_(0x3FFF)                                    /**< \deprecated (CMCC_TYPE) Register MASK  (Use CMCC_TYPE_Msk instead)  */
#define CMCC_TYPE_Msk                       _U_(0x3FFF)                                    /**< (CMCC_TYPE) Register Mask  */


/* -------- CMCC_CFG : (CMCC Offset: 0x04) (R/W 32) Cache Controller Configuration Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t GCLKDIS:1;                 /**< bit:      0  Disable Clock Gating                     */
    uint32_t ICDIS:1;                   /**< bit:      1                                           */
    uint32_t DCDIS:1;                   /**< bit:      2                                           */
    uint32_t :1;                        /**< bit:      3  Reserved */
    uint32_t PRGCSIZE:3;                /**< bit:   4..6                                           */
    uint32_t :25;                       /**< bit:  7..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} CMCC_CFG_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define CMCC_CFG_OFFSET                     (0x04)                                        /**<  (CMCC_CFG) Cache Controller Configuration Register  Offset */

#define CMCC_CFG_GCLKDIS_Pos                0                                              /**< (CMCC_CFG) Disable Clock Gating Position */
#define CMCC_CFG_GCLKDIS_Msk                (_U_(0x1) << CMCC_CFG_GCLKDIS_Pos)             /**< (CMCC_CFG) Disable Clock Gating Mask */
#define CMCC_CFG_GCLKDIS                    CMCC_CFG_GCLKDIS_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use CMCC_CFG_GCLKDIS_Msk instead */
#define CMCC_CFG_ICDIS_Pos                  1                                              /**< (CMCC_CFG)  Position */
#define CMCC_CFG_ICDIS_Msk                  (_U_(0x1) << CMCC_CFG_ICDIS_Pos)               /**< (CMCC_CFG)  Mask */
#define CMCC_CFG_ICDIS                      CMCC_CFG_ICDIS_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use CMCC_CFG_ICDIS_Msk instead */
#define CMCC_CFG_DCDIS_Pos                  2                                              /**< (CMCC_CFG)  Position */
#define CMCC_CFG_DCDIS_Msk                  (_U_(0x1) << CMCC_CFG_DCDIS_Pos)               /**< (CMCC_CFG)  Mask */
#define CMCC_CFG_DCDIS                      CMCC_CFG_DCDIS_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use CMCC_CFG_DCDIS_Msk instead */
#define CMCC_CFG_PRGCSIZE_Pos               4                                              /**< (CMCC_CFG)  Position */
#define CMCC_CFG_PRGCSIZE_Msk               (_U_(0x7) << CMCC_CFG_PRGCSIZE_Pos)            /**< (CMCC_CFG)  Mask */
#define CMCC_CFG_PRGCSIZE(value)            (CMCC_CFG_PRGCSIZE_Msk & ((value) << CMCC_CFG_PRGCSIZE_Pos))
#define CMCC_CFG_MASK                       _U_(0x77)                                      /**< \deprecated (CMCC_CFG) Register MASK  (Use CMCC_CFG_Msk instead)  */
#define CMCC_CFG_Msk                        _U_(0x77)                                      /**< (CMCC_CFG) Register Mask  */


/* -------- CMCC_CTRL : (CMCC Offset: 0x08) (/W 32) Cache Controller Control Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t CEN:1;                     /**< bit:      0  Cache Controller Enable                  */
    uint32_t :31;                       /**< bit:  1..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} CMCC_CTRL_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define CMCC_CTRL_OFFSET                    (0x08)                                        /**<  (CMCC_CTRL) Cache Controller Control Register  Offset */

#define CMCC_CTRL_CEN_Pos                   0                                              /**< (CMCC_CTRL) Cache Controller Enable Position */
#define CMCC_CTRL_CEN_Msk                   (_U_(0x1) << CMCC_CTRL_CEN_Pos)                /**< (CMCC_CTRL) Cache Controller Enable Mask */
#define CMCC_CTRL_CEN                       CMCC_CTRL_CEN_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use CMCC_CTRL_CEN_Msk instead */
#define CMCC_CTRL_MASK                      _U_(0x01)                                      /**< \deprecated (CMCC_CTRL) Register MASK  (Use CMCC_CTRL_Msk instead)  */
#define CMCC_CTRL_Msk                       _U_(0x01)                                      /**< (CMCC_CTRL) Register Mask  */


/* -------- CMCC_SR : (CMCC Offset: 0x0c) (R/ 32) Cache Controller Status Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t CSTS:1;                    /**< bit:      0  Cache Controller Status                  */
    uint32_t :31;                       /**< bit:  1..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} CMCC_SR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define CMCC_SR_OFFSET                      (0x0C)                                        /**<  (CMCC_SR) Cache Controller Status Register  Offset */

#define CMCC_SR_CSTS_Pos                    0                                              /**< (CMCC_SR) Cache Controller Status Position */
#define CMCC_SR_CSTS_Msk                    (_U_(0x1) << CMCC_SR_CSTS_Pos)                 /**< (CMCC_SR) Cache Controller Status Mask */
#define CMCC_SR_CSTS                        CMCC_SR_CSTS_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use CMCC_SR_CSTS_Msk instead */
#define CMCC_SR_MASK                        _U_(0x01)                                      /**< \deprecated (CMCC_SR) Register MASK  (Use CMCC_SR_Msk instead)  */
#define CMCC_SR_Msk                         _U_(0x01)                                      /**< (CMCC_SR) Register Mask  */


/* -------- CMCC_MAINT0 : (CMCC Offset: 0x20) (/W 32) Cache Controller Maintenance Register 0 -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t INVALL:1;                  /**< bit:      0  Cache Controller Invalidate All          */
    uint32_t :31;                       /**< bit:  1..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} CMCC_MAINT0_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define CMCC_MAINT0_OFFSET                  (0x20)                                        /**<  (CMCC_MAINT0) Cache Controller Maintenance Register 0  Offset */

#define CMCC_MAINT0_INVALL_Pos              0                                              /**< (CMCC_MAINT0) Cache Controller Invalidate All Position */
#define CMCC_MAINT0_INVALL_Msk              (_U_(0x1) << CMCC_MAINT0_INVALL_Pos)           /**< (CMCC_MAINT0) Cache Controller Invalidate All Mask */
#define CMCC_MAINT0_INVALL                  CMCC_MAINT0_INVALL_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use CMCC_MAINT0_INVALL_Msk instead */
#define CMCC_MAINT0_MASK                    _U_(0x01)                                      /**< \deprecated (CMCC_MAINT0) Register MASK  (Use CMCC_MAINT0_Msk instead)  */
#define CMCC_MAINT0_Msk                     _U_(0x01)                                      /**< (CMCC_MAINT0) Register Mask  */


/* -------- CMCC_MAINT1 : (CMCC Offset: 0x24) (/W 32) Cache Controller Maintenance Register 1 -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t :4;                        /**< bit:   0..3  Reserved */
    uint32_t INDEX:5;                   /**< bit:   4..8  Invalidate Index                         */
    uint32_t :21;                       /**< bit:  9..29  Reserved */
    uint32_t WAY:2;                     /**< bit: 30..31  Invalidate Way                           */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} CMCC_MAINT1_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define CMCC_MAINT1_OFFSET                  (0x24)                                        /**<  (CMCC_MAINT1) Cache Controller Maintenance Register 1  Offset */

#define CMCC_MAINT1_INDEX_Pos               4                                              /**< (CMCC_MAINT1) Invalidate Index Position */
#define CMCC_MAINT1_INDEX_Msk               (_U_(0x1F) << CMCC_MAINT1_INDEX_Pos)           /**< (CMCC_MAINT1) Invalidate Index Mask */
#define CMCC_MAINT1_INDEX(value)            (CMCC_MAINT1_INDEX_Msk & ((value) << CMCC_MAINT1_INDEX_Pos))
#define CMCC_MAINT1_WAY_Pos                 30                                             /**< (CMCC_MAINT1) Invalidate Way Position */
#define CMCC_MAINT1_WAY_Msk                 (_U_(0x3) << CMCC_MAINT1_WAY_Pos)              /**< (CMCC_MAINT1) Invalidate Way Mask */
#define CMCC_MAINT1_WAY(value)              (CMCC_MAINT1_WAY_Msk & ((value) << CMCC_MAINT1_WAY_Pos))
#define   CMCC_MAINT1_WAY_WAY0_Val          _U_(0x0)                                       /**< (CMCC_MAINT1) Way 0 is selection for index invalidation  */
#define   CMCC_MAINT1_WAY_WAY1_Val          _U_(0x1)                                       /**< (CMCC_MAINT1) Way 1 is selection for index invalidation  */
#define   CMCC_MAINT1_WAY_WAY2_Val          _U_(0x2)                                       /**< (CMCC_MAINT1) Way 2 is selection for index invalidation  */
#define   CMCC_MAINT1_WAY_WAY3_Val          _U_(0x3)                                       /**< (CMCC_MAINT1) Way 3 is selection for index invalidation  */
#define CMCC_MAINT1_WAY_WAY0                (CMCC_MAINT1_WAY_WAY0_Val << CMCC_MAINT1_WAY_Pos)  /**< (CMCC_MAINT1) Way 0 is selection for index invalidation Position  */
#define CMCC_MAINT1_WAY_WAY1                (CMCC_MAINT1_WAY_WAY1_Val << CMCC_MAINT1_WAY_Pos)  /**< (CMCC_MAINT1) Way 1 is selection for index invalidation Position  */
#define CMCC_MAINT1_WAY_WAY2                (CMCC_MAINT1_WAY_WAY2_Val << CMCC_MAINT1_WAY_Pos)  /**< (CMCC_MAINT1) Way 2 is selection for index invalidation Position  */
#define CMCC_MAINT1_WAY_WAY3                (CMCC_MAINT1_WAY_WAY3_Val << CMCC_MAINT1_WAY_Pos)  /**< (CMCC_MAINT1) Way 3 is selection for index invalidation Position  */
#define CMCC_MAINT1_MASK                    _U_(0xC00001F0)                                /**< \deprecated (CMCC_MAINT1) Register MASK  (Use CMCC_MAINT1_Msk instead)  */
#define CMCC_MAINT1_Msk                     _U_(0xC00001F0)                                /**< (CMCC_MAINT1) Register Mask  */


/* -------- CMCC_MCFG : (CMCC Offset: 0x28) (R/W 32) Cache Controller Monitor Configuration Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t MODE:2;                    /**< bit:   0..1  Cache Controller Monitor Counter Mode    */
    uint32_t :30;                       /**< bit:  2..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} CMCC_MCFG_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define CMCC_MCFG_OFFSET                    (0x28)                                        /**<  (CMCC_MCFG) Cache Controller Monitor Configuration Register  Offset */

#define CMCC_MCFG_MODE_Pos                  0                                              /**< (CMCC_MCFG) Cache Controller Monitor Counter Mode Position */
#define CMCC_MCFG_MODE_Msk                  (_U_(0x3) << CMCC_MCFG_MODE_Pos)               /**< (CMCC_MCFG) Cache Controller Monitor Counter Mode Mask */
#define CMCC_MCFG_MODE(value)               (CMCC_MCFG_MODE_Msk & ((value) << CMCC_MCFG_MODE_Pos))
#define   CMCC_MCFG_MODE_CYCLE_COUNT_Val    _U_(0x0)                                       /**< (CMCC_MCFG) Cycle counter  */
#define   CMCC_MCFG_MODE_IHIT_COUNT_Val     _U_(0x1)                                       /**< (CMCC_MCFG) Instruction hit counter  */
#define   CMCC_MCFG_MODE_DHIT_COUNT_Val     _U_(0x2)                                       /**< (CMCC_MCFG) Data hit counter  */
#define CMCC_MCFG_MODE_CYCLE_COUNT          (CMCC_MCFG_MODE_CYCLE_COUNT_Val << CMCC_MCFG_MODE_Pos)  /**< (CMCC_MCFG) Cycle counter Position  */
#define CMCC_MCFG_MODE_IHIT_COUNT           (CMCC_MCFG_MODE_IHIT_COUNT_Val << CMCC_MCFG_MODE_Pos)  /**< (CMCC_MCFG) Instruction hit counter Position  */
#define CMCC_MCFG_MODE_DHIT_COUNT           (CMCC_MCFG_MODE_DHIT_COUNT_Val << CMCC_MCFG_MODE_Pos)  /**< (CMCC_MCFG) Data hit counter Position  */
#define CMCC_MCFG_MASK                      _U_(0x03)                                      /**< \deprecated (CMCC_MCFG) Register MASK  (Use CMCC_MCFG_Msk instead)  */
#define CMCC_MCFG_Msk                       _U_(0x03)                                      /**< (CMCC_MCFG) Register Mask  */


/* -------- CMCC_MEN : (CMCC Offset: 0x2c) (R/W 32) Cache Controller Monitor Enable Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t MENABLE:1;                 /**< bit:      0  Cache Controller Monitor Enable          */
    uint32_t :31;                       /**< bit:  1..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} CMCC_MEN_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define CMCC_MEN_OFFSET                     (0x2C)                                        /**<  (CMCC_MEN) Cache Controller Monitor Enable Register  Offset */

#define CMCC_MEN_MENABLE_Pos                0                                              /**< (CMCC_MEN) Cache Controller Monitor Enable Position */
#define CMCC_MEN_MENABLE_Msk                (_U_(0x1) << CMCC_MEN_MENABLE_Pos)             /**< (CMCC_MEN) Cache Controller Monitor Enable Mask */
#define CMCC_MEN_MENABLE                    CMCC_MEN_MENABLE_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use CMCC_MEN_MENABLE_Msk instead */
#define CMCC_MEN_MASK                       _U_(0x01)                                      /**< \deprecated (CMCC_MEN) Register MASK  (Use CMCC_MEN_Msk instead)  */
#define CMCC_MEN_Msk                        _U_(0x01)                                      /**< (CMCC_MEN) Register Mask  */


/* -------- CMCC_MCTRL : (CMCC Offset: 0x30) (/W 32) Cache Controller Monitor Control Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t SWRST:1;                   /**< bit:      0  Monitor                                  */
    uint32_t :31;                       /**< bit:  1..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} CMCC_MCTRL_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define CMCC_MCTRL_OFFSET                   (0x30)                                        /**<  (CMCC_MCTRL) Cache Controller Monitor Control Register  Offset */

#define CMCC_MCTRL_SWRST_Pos                0                                              /**< (CMCC_MCTRL) Monitor Position */
#define CMCC_MCTRL_SWRST_Msk                (_U_(0x1) << CMCC_MCTRL_SWRST_Pos)             /**< (CMCC_MCTRL) Monitor Mask */
#define CMCC_MCTRL_SWRST                    CMCC_MCTRL_SWRST_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use CMCC_MCTRL_SWRST_Msk instead */
#define CMCC_MCTRL_MASK                     _U_(0x01)                                      /**< \deprecated (CMCC_MCTRL) Register MASK  (Use CMCC_MCTRL_Msk instead)  */
#define CMCC_MCTRL_Msk                      _U_(0x01)                                      /**< (CMCC_MCTRL) Register Mask  */


/* -------- CMCC_MSR : (CMCC Offset: 0x34) (R/ 32) Cache Controller Monitor Status Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t EVENT_CNT:32;              /**< bit:  0..31  Monitor Event Counter                    */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} CMCC_MSR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define CMCC_MSR_OFFSET                     (0x34)                                        /**<  (CMCC_MSR) Cache Controller Monitor Status Register  Offset */

#define CMCC_MSR_EVENT_CNT_Pos              0                                              /**< (CMCC_MSR) Monitor Event Counter Position */
#define CMCC_MSR_EVENT_CNT_Msk              (_U_(0xFFFFFFFF) << CMCC_MSR_EVENT_CNT_Pos)    /**< (CMCC_MSR) Monitor Event Counter Mask */
#define CMCC_MSR_EVENT_CNT(value)           (CMCC_MSR_EVENT_CNT_Msk & ((value) << CMCC_MSR_EVENT_CNT_Pos))
#define CMCC_MSR_MASK                       _U_(0xFFFFFFFF)                                /**< \deprecated (CMCC_MSR) Register MASK  (Use CMCC_MSR_Msk instead)  */
#define CMCC_MSR_Msk                        _U_(0xFFFFFFFF)                                /**< (CMCC_MSR) Register Mask  */


#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'R'
/** \brief CMCC hardware registers */
typedef struct {  
  __I  uint32_t CMCC_TYPE;      /**< (CMCC Offset: 0x00) Cache Controller Type Register */
  __IO uint32_t CMCC_CFG;       /**< (CMCC Offset: 0x04) Cache Controller Configuration Register */
  __O  uint32_t CMCC_CTRL;      /**< (CMCC Offset: 0x08) Cache Controller Control Register */
  __I  uint32_t CMCC_SR;        /**< (CMCC Offset: 0x0C) Cache Controller Status Register */
  RoReg8  Reserved1[0x10];
  __O  uint32_t CMCC_MAINT0;    /**< (CMCC Offset: 0x20) Cache Controller Maintenance Register 0 */
  __O  uint32_t CMCC_MAINT1;    /**< (CMCC Offset: 0x24) Cache Controller Maintenance Register 1 */
  __IO uint32_t CMCC_MCFG;      /**< (CMCC Offset: 0x28) Cache Controller Monitor Configuration Register */
  __IO uint32_t CMCC_MEN;       /**< (CMCC Offset: 0x2C) Cache Controller Monitor Enable Register */
  __O  uint32_t CMCC_MCTRL;     /**< (CMCC Offset: 0x30) Cache Controller Monitor Control Register */
  __I  uint32_t CMCC_MSR;       /**< (CMCC Offset: 0x34) Cache Controller Monitor Status Register */
} Cmcc;

#elif COMPONENT_TYPEDEF_STYLE == 'N'
/** \brief CMCC hardware registers */
typedef struct {  
  __I  CMCC_TYPE_Type                 CMCC_TYPE;      /**< Offset: 0x00 (R/   32) Cache Controller Type Register */
  __IO CMCC_CFG_Type                  CMCC_CFG;       /**< Offset: 0x04 (R/W  32) Cache Controller Configuration Register */
  __O  CMCC_CTRL_Type                 CMCC_CTRL;      /**< Offset: 0x08 ( /W  32) Cache Controller Control Register */
  __I  CMCC_SR_Type                   CMCC_SR;        /**< Offset: 0x0C (R/   32) Cache Controller Status Register */
  __I  uint32_t                       Reserved1[4];
  __O  CMCC_MAINT0_Type               CMCC_MAINT0;    /**< Offset: 0x20 ( /W  32) Cache Controller Maintenance Register 0 */
  __O  CMCC_MAINT1_Type               CMCC_MAINT1;    /**< Offset: 0x24 ( /W  32) Cache Controller Maintenance Register 1 */
  __IO CMCC_MCFG_Type                 CMCC_MCFG;      /**< Offset: 0x28 (R/W  32) Cache Controller Monitor Configuration Register */
  __IO CMCC_MEN_Type                  CMCC_MEN;       /**< Offset: 0x2C (R/W  32) Cache Controller Monitor Enable Register */
  __O  CMCC_MCTRL_Type                CMCC_MCTRL;     /**< Offset: 0x30 ( /W  32) Cache Controller Monitor Control Register */
  __I  CMCC_MSR_Type                  CMCC_MSR;       /**< Offset: 0x34 (R/   32) Cache Controller Monitor Status Register */
} Cmcc;

#else /* COMPONENT_TYPEDEF_STYLE */
#error Unknown component typedef style
#endif /* COMPONENT_TYPEDEF_STYLE */

#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
/** @}  end of Cortex-M Cache Controller */

#endif /* _SAMG55_CMCC_COMPONENT_H_ */
