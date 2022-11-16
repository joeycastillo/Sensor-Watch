/**
 * \file
 *
 * \brief Component description for MATRIX
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
#ifndef _SAMG55_MATRIX_COMPONENT_H_
#define _SAMG55_MATRIX_COMPONENT_H_
#define _SAMG55_MATRIX_COMPONENT_         /**< \deprecated  Backward compatibility for ASF */

/** \addtogroup SAMG_SAMG55 AHB Bus Matrix
 *  @{
 */
/* ========================================================================== */
/**  SOFTWARE API DEFINITION FOR MATRIX */
/* ========================================================================== */
#ifndef COMPONENT_TYPEDEF_STYLE
  #define COMPONENT_TYPEDEF_STYLE 'R'  /**< Defines default style of typedefs for the component header files ('R' = RFO, 'N' = NTO)*/
#endif

#define MATRIX_11049                      /**< (MATRIX) Module ID */
#define REV_MATRIX F                      /**< (MATRIX) Module revision */

/* -------- MATRIX_MCFG : (MATRIX Offset: 0x00) (R/W 32) Master Configuration Register 0 -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t ULBT:3;                    /**< bit:   0..2  Undefined Length Burst Type              */
    uint32_t :29;                       /**< bit:  3..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} MATRIX_MCFG_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define MATRIX_MCFG_OFFSET                  (0x00)                                        /**<  (MATRIX_MCFG) Master Configuration Register 0  Offset */

#define MATRIX_MCFG_ULBT_Pos                0                                              /**< (MATRIX_MCFG) Undefined Length Burst Type Position */
#define MATRIX_MCFG_ULBT_Msk                (_U_(0x7) << MATRIX_MCFG_ULBT_Pos)             /**< (MATRIX_MCFG) Undefined Length Burst Type Mask */
#define MATRIX_MCFG_ULBT(value)             (MATRIX_MCFG_ULBT_Msk & ((value) << MATRIX_MCFG_ULBT_Pos))
#define   MATRIX_MCFG_ULBT_UNLIMITED_Val    _U_(0x0)                                       /**< (MATRIX_MCFG) No predicted end of burst is generated and therefore INCR bursts coming from this master cannot be broken.  */
#define   MATRIX_MCFG_ULBT_SINGLE_Val       _U_(0x1)                                       /**< (MATRIX_MCFG) The undefined length burst is treated as a succession of single access allowing rearbitration at each beat of the INCR burst.  */
#define   MATRIX_MCFG_ULBT_4_BEAT_Val       _U_(0x2)                                       /**< (MATRIX_MCFG) The undefined length burst is split into a 4-beat bursts allowing rearbitration at each 4-beat burst end.  */
#define   MATRIX_MCFG_ULBT_8_BEAT_Val       _U_(0x3)                                       /**< (MATRIX_MCFG) The undefined length burst is split into 8-beat bursts allowing rearbitration at each 8-beat burst end.  */
#define   MATRIX_MCFG_ULBT_16_BEAT_Val      _U_(0x4)                                       /**< (MATRIX_MCFG) The undefined length burst is split into 16-beat bursts allowing rearbitration at each 16-beat burst end.  */
#define MATRIX_MCFG_ULBT_UNLIMITED          (MATRIX_MCFG_ULBT_UNLIMITED_Val << MATRIX_MCFG_ULBT_Pos)  /**< (MATRIX_MCFG) No predicted end of burst is generated and therefore INCR bursts coming from this master cannot be broken. Position  */
#define MATRIX_MCFG_ULBT_SINGLE             (MATRIX_MCFG_ULBT_SINGLE_Val << MATRIX_MCFG_ULBT_Pos)  /**< (MATRIX_MCFG) The undefined length burst is treated as a succession of single access allowing rearbitration at each beat of the INCR burst. Position  */
#define MATRIX_MCFG_ULBT_4_BEAT             (MATRIX_MCFG_ULBT_4_BEAT_Val << MATRIX_MCFG_ULBT_Pos)  /**< (MATRIX_MCFG) The undefined length burst is split into a 4-beat bursts allowing rearbitration at each 4-beat burst end. Position  */
#define MATRIX_MCFG_ULBT_8_BEAT             (MATRIX_MCFG_ULBT_8_BEAT_Val << MATRIX_MCFG_ULBT_Pos)  /**< (MATRIX_MCFG) The undefined length burst is split into 8-beat bursts allowing rearbitration at each 8-beat burst end. Position  */
#define MATRIX_MCFG_ULBT_16_BEAT            (MATRIX_MCFG_ULBT_16_BEAT_Val << MATRIX_MCFG_ULBT_Pos)  /**< (MATRIX_MCFG) The undefined length burst is split into 16-beat bursts allowing rearbitration at each 16-beat burst end. Position  */
#define MATRIX_MCFG_MASK                    _U_(0x07)                                      /**< \deprecated (MATRIX_MCFG) Register MASK  (Use MATRIX_MCFG_Msk instead)  */
#define MATRIX_MCFG_Msk                     _U_(0x07)                                      /**< (MATRIX_MCFG) Register Mask  */


/* -------- MATRIX_SCFG : (MATRIX Offset: 0x40) (R/W 32) Slave Configuration Register 0 -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t SLOT_CYCLE:8;              /**< bit:   0..7  Maximum Number of Allowed Cycles for a Burst */
    uint32_t :8;                        /**< bit:  8..15  Reserved */
    uint32_t DEFMSTR_TYPE:2;            /**< bit: 16..17  Default Master Type                      */
    uint32_t FIXED_DEFMSTR:3;           /**< bit: 18..20  Fixed Default Master                     */
    uint32_t :11;                       /**< bit: 21..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} MATRIX_SCFG_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define MATRIX_SCFG_OFFSET                  (0x40)                                        /**<  (MATRIX_SCFG) Slave Configuration Register 0  Offset */

#define MATRIX_SCFG_SLOT_CYCLE_Pos          0                                              /**< (MATRIX_SCFG) Maximum Number of Allowed Cycles for a Burst Position */
#define MATRIX_SCFG_SLOT_CYCLE_Msk          (_U_(0xFF) << MATRIX_SCFG_SLOT_CYCLE_Pos)      /**< (MATRIX_SCFG) Maximum Number of Allowed Cycles for a Burst Mask */
#define MATRIX_SCFG_SLOT_CYCLE(value)       (MATRIX_SCFG_SLOT_CYCLE_Msk & ((value) << MATRIX_SCFG_SLOT_CYCLE_Pos))
#define MATRIX_SCFG_DEFMSTR_TYPE_Pos        16                                             /**< (MATRIX_SCFG) Default Master Type Position */
#define MATRIX_SCFG_DEFMSTR_TYPE_Msk        (_U_(0x3) << MATRIX_SCFG_DEFMSTR_TYPE_Pos)     /**< (MATRIX_SCFG) Default Master Type Mask */
#define MATRIX_SCFG_DEFMSTR_TYPE(value)     (MATRIX_SCFG_DEFMSTR_TYPE_Msk & ((value) << MATRIX_SCFG_DEFMSTR_TYPE_Pos))
#define   MATRIX_SCFG_DEFMSTR_TYPE_NO_DEFAULT_Val _U_(0x0)                                       /**< (MATRIX_SCFG) At the end of current slave access, if no other master request is pending, the slave is disconnected from all masters.This results in having a one cycle latency for the first access of a burst transfer or for a single access.  */
#define   MATRIX_SCFG_DEFMSTR_TYPE_LAST_Val _U_(0x1)                                       /**< (MATRIX_SCFG) At the end of current slave access, if no other master request is pending, the slave stays connected to the last master having accessed it.This results in not having the one cycle latency when the last master tries to access the slave again.  */
#define   MATRIX_SCFG_DEFMSTR_TYPE_FIXED_Val _U_(0x2)                                       /**< (MATRIX_SCFG) At the end of the current slave access, if no other master request is pending, the slave connects to the fixed master the number that has been written in the FIXED_DEFMSTR field.This results in not having the one cycle latency when the fixed master tries to access the slave again.  */
#define MATRIX_SCFG_DEFMSTR_TYPE_NO_DEFAULT (MATRIX_SCFG_DEFMSTR_TYPE_NO_DEFAULT_Val << MATRIX_SCFG_DEFMSTR_TYPE_Pos)  /**< (MATRIX_SCFG) At the end of current slave access, if no other master request is pending, the slave is disconnected from all masters.This results in having a one cycle latency for the first access of a burst transfer or for a single access. Position  */
#define MATRIX_SCFG_DEFMSTR_TYPE_LAST       (MATRIX_SCFG_DEFMSTR_TYPE_LAST_Val << MATRIX_SCFG_DEFMSTR_TYPE_Pos)  /**< (MATRIX_SCFG) At the end of current slave access, if no other master request is pending, the slave stays connected to the last master having accessed it.This results in not having the one cycle latency when the last master tries to access the slave again. Position  */
#define MATRIX_SCFG_DEFMSTR_TYPE_FIXED      (MATRIX_SCFG_DEFMSTR_TYPE_FIXED_Val << MATRIX_SCFG_DEFMSTR_TYPE_Pos)  /**< (MATRIX_SCFG) At the end of the current slave access, if no other master request is pending, the slave connects to the fixed master the number that has been written in the FIXED_DEFMSTR field.This results in not having the one cycle latency when the fixed master tries to access the slave again. Position  */
#define MATRIX_SCFG_FIXED_DEFMSTR_Pos       18                                             /**< (MATRIX_SCFG) Fixed Default Master Position */
#define MATRIX_SCFG_FIXED_DEFMSTR_Msk       (_U_(0x7) << MATRIX_SCFG_FIXED_DEFMSTR_Pos)    /**< (MATRIX_SCFG) Fixed Default Master Mask */
#define MATRIX_SCFG_FIXED_DEFMSTR(value)    (MATRIX_SCFG_FIXED_DEFMSTR_Msk & ((value) << MATRIX_SCFG_FIXED_DEFMSTR_Pos))
#define MATRIX_SCFG_MASK                    _U_(0x1F00FF)                                  /**< \deprecated (MATRIX_SCFG) Register MASK  (Use MATRIX_SCFG_Msk instead)  */
#define MATRIX_SCFG_Msk                     _U_(0x1F00FF)                                  /**< (MATRIX_SCFG) Register Mask  */


/* -------- MATRIX_PRAS0 : (MATRIX Offset: 0x80) (R/W 32) Priority Register A for Slave 0 -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t M0PR:2;                    /**< bit:   0..1  Master 0 Priority                        */
    uint32_t :2;                        /**< bit:   2..3  Reserved */
    uint32_t M1PR:2;                    /**< bit:   4..5  Master 1 Priority                        */
    uint32_t :2;                        /**< bit:   6..7  Reserved */
    uint32_t M2PR:2;                    /**< bit:   8..9  Master 2 Priority                        */
    uint32_t :2;                        /**< bit: 10..11  Reserved */
    uint32_t M3PR:2;                    /**< bit: 12..13  Master 3 Priority                        */
    uint32_t :18;                       /**< bit: 14..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} MATRIX_PRAS0_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define MATRIX_PRAS0_OFFSET                 (0x80)                                        /**<  (MATRIX_PRAS0) Priority Register A for Slave 0  Offset */

#define MATRIX_PRAS0_M0PR_Pos               0                                              /**< (MATRIX_PRAS0) Master 0 Priority Position */
#define MATRIX_PRAS0_M0PR_Msk               (_U_(0x3) << MATRIX_PRAS0_M0PR_Pos)            /**< (MATRIX_PRAS0) Master 0 Priority Mask */
#define MATRIX_PRAS0_M0PR(value)            (MATRIX_PRAS0_M0PR_Msk & ((value) << MATRIX_PRAS0_M0PR_Pos))
#define MATRIX_PRAS0_M1PR_Pos               4                                              /**< (MATRIX_PRAS0) Master 1 Priority Position */
#define MATRIX_PRAS0_M1PR_Msk               (_U_(0x3) << MATRIX_PRAS0_M1PR_Pos)            /**< (MATRIX_PRAS0) Master 1 Priority Mask */
#define MATRIX_PRAS0_M1PR(value)            (MATRIX_PRAS0_M1PR_Msk & ((value) << MATRIX_PRAS0_M1PR_Pos))
#define MATRIX_PRAS0_M2PR_Pos               8                                              /**< (MATRIX_PRAS0) Master 2 Priority Position */
#define MATRIX_PRAS0_M2PR_Msk               (_U_(0x3) << MATRIX_PRAS0_M2PR_Pos)            /**< (MATRIX_PRAS0) Master 2 Priority Mask */
#define MATRIX_PRAS0_M2PR(value)            (MATRIX_PRAS0_M2PR_Msk & ((value) << MATRIX_PRAS0_M2PR_Pos))
#define MATRIX_PRAS0_M3PR_Pos               12                                             /**< (MATRIX_PRAS0) Master 3 Priority Position */
#define MATRIX_PRAS0_M3PR_Msk               (_U_(0x3) << MATRIX_PRAS0_M3PR_Pos)            /**< (MATRIX_PRAS0) Master 3 Priority Mask */
#define MATRIX_PRAS0_M3PR(value)            (MATRIX_PRAS0_M3PR_Msk & ((value) << MATRIX_PRAS0_M3PR_Pos))
#define MATRIX_PRAS0_MASK                   _U_(0x3333)                                    /**< \deprecated (MATRIX_PRAS0) Register MASK  (Use MATRIX_PRAS0_Msk instead)  */
#define MATRIX_PRAS0_Msk                    _U_(0x3333)                                    /**< (MATRIX_PRAS0) Register Mask  */


/* -------- MATRIX_PRAS1 : (MATRIX Offset: 0x88) (R/W 32) Priority Register A for Slave 1 -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t M0PR:2;                    /**< bit:   0..1  Master 0 Priority                        */
    uint32_t :2;                        /**< bit:   2..3  Reserved */
    uint32_t M1PR:2;                    /**< bit:   4..5  Master 1 Priority                        */
    uint32_t :2;                        /**< bit:   6..7  Reserved */
    uint32_t M2PR:2;                    /**< bit:   8..9  Master 2 Priority                        */
    uint32_t :2;                        /**< bit: 10..11  Reserved */
    uint32_t M3PR:2;                    /**< bit: 12..13  Master 3 Priority                        */
    uint32_t :18;                       /**< bit: 14..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} MATRIX_PRAS1_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define MATRIX_PRAS1_OFFSET                 (0x88)                                        /**<  (MATRIX_PRAS1) Priority Register A for Slave 1  Offset */

#define MATRIX_PRAS1_M0PR_Pos               0                                              /**< (MATRIX_PRAS1) Master 0 Priority Position */
#define MATRIX_PRAS1_M0PR_Msk               (_U_(0x3) << MATRIX_PRAS1_M0PR_Pos)            /**< (MATRIX_PRAS1) Master 0 Priority Mask */
#define MATRIX_PRAS1_M0PR(value)            (MATRIX_PRAS1_M0PR_Msk & ((value) << MATRIX_PRAS1_M0PR_Pos))
#define MATRIX_PRAS1_M1PR_Pos               4                                              /**< (MATRIX_PRAS1) Master 1 Priority Position */
#define MATRIX_PRAS1_M1PR_Msk               (_U_(0x3) << MATRIX_PRAS1_M1PR_Pos)            /**< (MATRIX_PRAS1) Master 1 Priority Mask */
#define MATRIX_PRAS1_M1PR(value)            (MATRIX_PRAS1_M1PR_Msk & ((value) << MATRIX_PRAS1_M1PR_Pos))
#define MATRIX_PRAS1_M2PR_Pos               8                                              /**< (MATRIX_PRAS1) Master 2 Priority Position */
#define MATRIX_PRAS1_M2PR_Msk               (_U_(0x3) << MATRIX_PRAS1_M2PR_Pos)            /**< (MATRIX_PRAS1) Master 2 Priority Mask */
#define MATRIX_PRAS1_M2PR(value)            (MATRIX_PRAS1_M2PR_Msk & ((value) << MATRIX_PRAS1_M2PR_Pos))
#define MATRIX_PRAS1_M3PR_Pos               12                                             /**< (MATRIX_PRAS1) Master 3 Priority Position */
#define MATRIX_PRAS1_M3PR_Msk               (_U_(0x3) << MATRIX_PRAS1_M3PR_Pos)            /**< (MATRIX_PRAS1) Master 3 Priority Mask */
#define MATRIX_PRAS1_M3PR(value)            (MATRIX_PRAS1_M3PR_Msk & ((value) << MATRIX_PRAS1_M3PR_Pos))
#define MATRIX_PRAS1_MASK                   _U_(0x3333)                                    /**< \deprecated (MATRIX_PRAS1) Register MASK  (Use MATRIX_PRAS1_Msk instead)  */
#define MATRIX_PRAS1_Msk                    _U_(0x3333)                                    /**< (MATRIX_PRAS1) Register Mask  */


/* -------- MATRIX_PRAS2 : (MATRIX Offset: 0x90) (R/W 32) Priority Register A for Slave 2 -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t M0PR:2;                    /**< bit:   0..1  Master 0 Priority                        */
    uint32_t :2;                        /**< bit:   2..3  Reserved */
    uint32_t M1PR:2;                    /**< bit:   4..5  Master 1 Priority                        */
    uint32_t :2;                        /**< bit:   6..7  Reserved */
    uint32_t M2PR:2;                    /**< bit:   8..9  Master 2 Priority                        */
    uint32_t :2;                        /**< bit: 10..11  Reserved */
    uint32_t M3PR:2;                    /**< bit: 12..13  Master 3 Priority                        */
    uint32_t :18;                       /**< bit: 14..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} MATRIX_PRAS2_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define MATRIX_PRAS2_OFFSET                 (0x90)                                        /**<  (MATRIX_PRAS2) Priority Register A for Slave 2  Offset */

#define MATRIX_PRAS2_M0PR_Pos               0                                              /**< (MATRIX_PRAS2) Master 0 Priority Position */
#define MATRIX_PRAS2_M0PR_Msk               (_U_(0x3) << MATRIX_PRAS2_M0PR_Pos)            /**< (MATRIX_PRAS2) Master 0 Priority Mask */
#define MATRIX_PRAS2_M0PR(value)            (MATRIX_PRAS2_M0PR_Msk & ((value) << MATRIX_PRAS2_M0PR_Pos))
#define MATRIX_PRAS2_M1PR_Pos               4                                              /**< (MATRIX_PRAS2) Master 1 Priority Position */
#define MATRIX_PRAS2_M1PR_Msk               (_U_(0x3) << MATRIX_PRAS2_M1PR_Pos)            /**< (MATRIX_PRAS2) Master 1 Priority Mask */
#define MATRIX_PRAS2_M1PR(value)            (MATRIX_PRAS2_M1PR_Msk & ((value) << MATRIX_PRAS2_M1PR_Pos))
#define MATRIX_PRAS2_M2PR_Pos               8                                              /**< (MATRIX_PRAS2) Master 2 Priority Position */
#define MATRIX_PRAS2_M2PR_Msk               (_U_(0x3) << MATRIX_PRAS2_M2PR_Pos)            /**< (MATRIX_PRAS2) Master 2 Priority Mask */
#define MATRIX_PRAS2_M2PR(value)            (MATRIX_PRAS2_M2PR_Msk & ((value) << MATRIX_PRAS2_M2PR_Pos))
#define MATRIX_PRAS2_M3PR_Pos               12                                             /**< (MATRIX_PRAS2) Master 3 Priority Position */
#define MATRIX_PRAS2_M3PR_Msk               (_U_(0x3) << MATRIX_PRAS2_M3PR_Pos)            /**< (MATRIX_PRAS2) Master 3 Priority Mask */
#define MATRIX_PRAS2_M3PR(value)            (MATRIX_PRAS2_M3PR_Msk & ((value) << MATRIX_PRAS2_M3PR_Pos))
#define MATRIX_PRAS2_MASK                   _U_(0x3333)                                    /**< \deprecated (MATRIX_PRAS2) Register MASK  (Use MATRIX_PRAS2_Msk instead)  */
#define MATRIX_PRAS2_Msk                    _U_(0x3333)                                    /**< (MATRIX_PRAS2) Register Mask  */


/* -------- MATRIX_PRAS3 : (MATRIX Offset: 0x98) (R/W 32) Priority Register A for Slave 3 -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t M0PR:2;                    /**< bit:   0..1  Master 0 Priority                        */
    uint32_t :2;                        /**< bit:   2..3  Reserved */
    uint32_t M1PR:2;                    /**< bit:   4..5  Master 1 Priority                        */
    uint32_t :2;                        /**< bit:   6..7  Reserved */
    uint32_t M2PR:2;                    /**< bit:   8..9  Master 2 Priority                        */
    uint32_t :2;                        /**< bit: 10..11  Reserved */
    uint32_t M3PR:2;                    /**< bit: 12..13  Master 3 Priority                        */
    uint32_t :18;                       /**< bit: 14..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} MATRIX_PRAS3_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define MATRIX_PRAS3_OFFSET                 (0x98)                                        /**<  (MATRIX_PRAS3) Priority Register A for Slave 3  Offset */

#define MATRIX_PRAS3_M0PR_Pos               0                                              /**< (MATRIX_PRAS3) Master 0 Priority Position */
#define MATRIX_PRAS3_M0PR_Msk               (_U_(0x3) << MATRIX_PRAS3_M0PR_Pos)            /**< (MATRIX_PRAS3) Master 0 Priority Mask */
#define MATRIX_PRAS3_M0PR(value)            (MATRIX_PRAS3_M0PR_Msk & ((value) << MATRIX_PRAS3_M0PR_Pos))
#define MATRIX_PRAS3_M1PR_Pos               4                                              /**< (MATRIX_PRAS3) Master 1 Priority Position */
#define MATRIX_PRAS3_M1PR_Msk               (_U_(0x3) << MATRIX_PRAS3_M1PR_Pos)            /**< (MATRIX_PRAS3) Master 1 Priority Mask */
#define MATRIX_PRAS3_M1PR(value)            (MATRIX_PRAS3_M1PR_Msk & ((value) << MATRIX_PRAS3_M1PR_Pos))
#define MATRIX_PRAS3_M2PR_Pos               8                                              /**< (MATRIX_PRAS3) Master 2 Priority Position */
#define MATRIX_PRAS3_M2PR_Msk               (_U_(0x3) << MATRIX_PRAS3_M2PR_Pos)            /**< (MATRIX_PRAS3) Master 2 Priority Mask */
#define MATRIX_PRAS3_M2PR(value)            (MATRIX_PRAS3_M2PR_Msk & ((value) << MATRIX_PRAS3_M2PR_Pos))
#define MATRIX_PRAS3_M3PR_Pos               12                                             /**< (MATRIX_PRAS3) Master 3 Priority Position */
#define MATRIX_PRAS3_M3PR_Msk               (_U_(0x3) << MATRIX_PRAS3_M3PR_Pos)            /**< (MATRIX_PRAS3) Master 3 Priority Mask */
#define MATRIX_PRAS3_M3PR(value)            (MATRIX_PRAS3_M3PR_Msk & ((value) << MATRIX_PRAS3_M3PR_Pos))
#define MATRIX_PRAS3_MASK                   _U_(0x3333)                                    /**< \deprecated (MATRIX_PRAS3) Register MASK  (Use MATRIX_PRAS3_Msk instead)  */
#define MATRIX_PRAS3_Msk                    _U_(0x3333)                                    /**< (MATRIX_PRAS3) Register Mask  */


/* -------- CCFG_SYSIO : (MATRIX Offset: 0x114) (R/W 32) System I/O Configuration Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t :4;                        /**< bit:   0..3  Reserved */
    uint32_t SYSIO4:1;                  /**< bit:      4  PB4 or TDI Assignment                    */
    uint32_t SYSIO5:1;                  /**< bit:      5  PB5 or TDO/TRACESWO Assignment           */
    uint32_t SYSIO6:1;                  /**< bit:      6  PB6 or TMS/SWDIO Assignment              */
    uint32_t SYSIO7:1;                  /**< bit:      7  PB7 or TCK/SWCLK Assignment              */
    uint32_t :2;                        /**< bit:   8..9  Reserved */
    uint32_t SYSIO10:1;                 /**< bit:     10  PA21 or DM Assignment                    */
    uint32_t SYSIO11:1;                 /**< bit:     11  PA22 or DP Assignment                    */
    uint32_t SYSIO12:1;                 /**< bit:     12  PB12 or ERASE Assignment                 */
    uint32_t :19;                       /**< bit: 13..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  struct {
    uint32_t :4;                        /**< bit:   0..3  Reserved */
    uint32_t SYSIO:7;                   /**< bit:  4..10  PBx2 or ERASE Assignment                 */
    uint32_t :21;                       /**< bit: 11..31 Reserved */
  } vec;                                /**< Structure used for vec  access  */
  uint32_t reg;                         /**< Type used for register access */
} CCFG_SYSIO_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define CCFG_SYSIO_OFFSET                   (0x114)                                       /**<  (CCFG_SYSIO) System I/O Configuration Register  Offset */

#define CCFG_SYSIO_SYSIO4_Pos               4                                              /**< (CCFG_SYSIO) PB4 or TDI Assignment Position */
#define CCFG_SYSIO_SYSIO4_Msk               (_U_(0x1) << CCFG_SYSIO_SYSIO4_Pos)            /**< (CCFG_SYSIO) PB4 or TDI Assignment Mask */
#define CCFG_SYSIO_SYSIO4                   CCFG_SYSIO_SYSIO4_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use CCFG_SYSIO_SYSIO4_Msk instead */
#define CCFG_SYSIO_SYSIO5_Pos               5                                              /**< (CCFG_SYSIO) PB5 or TDO/TRACESWO Assignment Position */
#define CCFG_SYSIO_SYSIO5_Msk               (_U_(0x1) << CCFG_SYSIO_SYSIO5_Pos)            /**< (CCFG_SYSIO) PB5 or TDO/TRACESWO Assignment Mask */
#define CCFG_SYSIO_SYSIO5                   CCFG_SYSIO_SYSIO5_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use CCFG_SYSIO_SYSIO5_Msk instead */
#define CCFG_SYSIO_SYSIO6_Pos               6                                              /**< (CCFG_SYSIO) PB6 or TMS/SWDIO Assignment Position */
#define CCFG_SYSIO_SYSIO6_Msk               (_U_(0x1) << CCFG_SYSIO_SYSIO6_Pos)            /**< (CCFG_SYSIO) PB6 or TMS/SWDIO Assignment Mask */
#define CCFG_SYSIO_SYSIO6                   CCFG_SYSIO_SYSIO6_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use CCFG_SYSIO_SYSIO6_Msk instead */
#define CCFG_SYSIO_SYSIO7_Pos               7                                              /**< (CCFG_SYSIO) PB7 or TCK/SWCLK Assignment Position */
#define CCFG_SYSIO_SYSIO7_Msk               (_U_(0x1) << CCFG_SYSIO_SYSIO7_Pos)            /**< (CCFG_SYSIO) PB7 or TCK/SWCLK Assignment Mask */
#define CCFG_SYSIO_SYSIO7                   CCFG_SYSIO_SYSIO7_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use CCFG_SYSIO_SYSIO7_Msk instead */
#define CCFG_SYSIO_SYSIO10_Pos              10                                             /**< (CCFG_SYSIO) PA21 or DM Assignment Position */
#define CCFG_SYSIO_SYSIO10_Msk              (_U_(0x1) << CCFG_SYSIO_SYSIO10_Pos)           /**< (CCFG_SYSIO) PA21 or DM Assignment Mask */
#define CCFG_SYSIO_SYSIO10                  CCFG_SYSIO_SYSIO10_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use CCFG_SYSIO_SYSIO10_Msk instead */
#define CCFG_SYSIO_SYSIO11_Pos              11                                             /**< (CCFG_SYSIO) PA22 or DP Assignment Position */
#define CCFG_SYSIO_SYSIO11_Msk              (_U_(0x1) << CCFG_SYSIO_SYSIO11_Pos)           /**< (CCFG_SYSIO) PA22 or DP Assignment Mask */
#define CCFG_SYSIO_SYSIO11                  CCFG_SYSIO_SYSIO11_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use CCFG_SYSIO_SYSIO11_Msk instead */
#define CCFG_SYSIO_SYSIO12_Pos              12                                             /**< (CCFG_SYSIO) PB12 or ERASE Assignment Position */
#define CCFG_SYSIO_SYSIO12_Msk              (_U_(0x1) << CCFG_SYSIO_SYSIO12_Pos)           /**< (CCFG_SYSIO) PB12 or ERASE Assignment Mask */
#define CCFG_SYSIO_SYSIO12                  CCFG_SYSIO_SYSIO12_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use CCFG_SYSIO_SYSIO12_Msk instead */
#define CCFG_SYSIO_MASK                     _U_(0x1CF0)                                    /**< \deprecated (CCFG_SYSIO) Register MASK  (Use CCFG_SYSIO_Msk instead)  */
#define CCFG_SYSIO_Msk                      _U_(0x1CF0)                                    /**< (CCFG_SYSIO) Register Mask  */

#define CCFG_SYSIO_SYSIO_Pos                4                                              /**< (CCFG_SYSIO Position) PBx2 or ERASE Assignment */
#define CCFG_SYSIO_SYSIO_Msk                (_U_(0x7F) << CCFG_SYSIO_SYSIO_Pos)            /**< (CCFG_SYSIO Mask) SYSIO */
#define CCFG_SYSIO_SYSIO(value)             (CCFG_SYSIO_SYSIO_Msk & ((value) << CCFG_SYSIO_SYSIO_Pos))  

/* -------- CCFG_DYNCKG : (MATRIX Offset: 0x118) (R/W 32) Dynamic Clock Gating Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t MATCKG:1;                  /**< bit:      0  MATRIX Dynamic Clock Gating              */
    uint32_t BRIDCKG:1;                 /**< bit:      1  Bridge Dynamic Clock Gating Enable       */
    uint32_t EFCCKG:1;                  /**< bit:      2  EFC Dynamic Clock Gating Enable          */
    uint32_t :29;                       /**< bit:  3..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} CCFG_DYNCKG_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define CCFG_DYNCKG_OFFSET                  (0x118)                                       /**<  (CCFG_DYNCKG) Dynamic Clock Gating Register  Offset */

#define CCFG_DYNCKG_MATCKG_Pos              0                                              /**< (CCFG_DYNCKG) MATRIX Dynamic Clock Gating Position */
#define CCFG_DYNCKG_MATCKG_Msk              (_U_(0x1) << CCFG_DYNCKG_MATCKG_Pos)           /**< (CCFG_DYNCKG) MATRIX Dynamic Clock Gating Mask */
#define CCFG_DYNCKG_MATCKG                  CCFG_DYNCKG_MATCKG_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use CCFG_DYNCKG_MATCKG_Msk instead */
#define CCFG_DYNCKG_BRIDCKG_Pos             1                                              /**< (CCFG_DYNCKG) Bridge Dynamic Clock Gating Enable Position */
#define CCFG_DYNCKG_BRIDCKG_Msk             (_U_(0x1) << CCFG_DYNCKG_BRIDCKG_Pos)          /**< (CCFG_DYNCKG) Bridge Dynamic Clock Gating Enable Mask */
#define CCFG_DYNCKG_BRIDCKG                 CCFG_DYNCKG_BRIDCKG_Msk                        /**< \deprecated Old style mask definition for 1 bit bitfield. Use CCFG_DYNCKG_BRIDCKG_Msk instead */
#define CCFG_DYNCKG_EFCCKG_Pos              2                                              /**< (CCFG_DYNCKG) EFC Dynamic Clock Gating Enable Position */
#define CCFG_DYNCKG_EFCCKG_Msk              (_U_(0x1) << CCFG_DYNCKG_EFCCKG_Pos)           /**< (CCFG_DYNCKG) EFC Dynamic Clock Gating Enable Mask */
#define CCFG_DYNCKG_EFCCKG                  CCFG_DYNCKG_EFCCKG_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use CCFG_DYNCKG_EFCCKG_Msk instead */
#define CCFG_DYNCKG_MASK                    _U_(0x07)                                      /**< \deprecated (CCFG_DYNCKG) Register MASK  (Use CCFG_DYNCKG_Msk instead)  */
#define CCFG_DYNCKG_Msk                     _U_(0x07)                                      /**< (CCFG_DYNCKG) Register Mask  */


/* -------- CCFG_I2SCLKSEL : (MATRIX Offset: 0x11c) (R/W 32) I2S Clock Source Selection Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t CLKSEL0:1;                 /**< bit:      0  I2S0 Clock Source                        */
    uint32_t CLKSEL1:1;                 /**< bit:      1  I2S1 Clock Source                        */
    uint32_t :30;                       /**< bit:  2..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  struct {
    uint32_t CLKSEL:2;                  /**< bit:   0..1  I2Sx Clock Source                        */
    uint32_t :30;                       /**< bit:  2..31 Reserved */
  } vec;                                /**< Structure used for vec  access  */
  uint32_t reg;                         /**< Type used for register access */
} CCFG_I2SCLKSEL_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define CCFG_I2SCLKSEL_OFFSET               (0x11C)                                       /**<  (CCFG_I2SCLKSEL) I2S Clock Source Selection Register  Offset */

#define CCFG_I2SCLKSEL_CLKSEL0_Pos          0                                              /**< (CCFG_I2SCLKSEL) I2S0 Clock Source Position */
#define CCFG_I2SCLKSEL_CLKSEL0_Msk          (_U_(0x1) << CCFG_I2SCLKSEL_CLKSEL0_Pos)       /**< (CCFG_I2SCLKSEL) I2S0 Clock Source Mask */
#define CCFG_I2SCLKSEL_CLKSEL0              CCFG_I2SCLKSEL_CLKSEL0_Msk                     /**< \deprecated Old style mask definition for 1 bit bitfield. Use CCFG_I2SCLKSEL_CLKSEL0_Msk instead */
#define CCFG_I2SCLKSEL_CLKSEL1_Pos          1                                              /**< (CCFG_I2SCLKSEL) I2S1 Clock Source Position */
#define CCFG_I2SCLKSEL_CLKSEL1_Msk          (_U_(0x1) << CCFG_I2SCLKSEL_CLKSEL1_Pos)       /**< (CCFG_I2SCLKSEL) I2S1 Clock Source Mask */
#define CCFG_I2SCLKSEL_CLKSEL1              CCFG_I2SCLKSEL_CLKSEL1_Msk                     /**< \deprecated Old style mask definition for 1 bit bitfield. Use CCFG_I2SCLKSEL_CLKSEL1_Msk instead */
#define CCFG_I2SCLKSEL_MASK                 _U_(0x03)                                      /**< \deprecated (CCFG_I2SCLKSEL) Register MASK  (Use CCFG_I2SCLKSEL_Msk instead)  */
#define CCFG_I2SCLKSEL_Msk                  _U_(0x03)                                      /**< (CCFG_I2SCLKSEL) Register Mask  */

#define CCFG_I2SCLKSEL_CLKSEL_Pos           0                                              /**< (CCFG_I2SCLKSEL Position) I2Sx Clock Source */
#define CCFG_I2SCLKSEL_CLKSEL_Msk           (_U_(0x3) << CCFG_I2SCLKSEL_CLKSEL_Pos)        /**< (CCFG_I2SCLKSEL Mask) CLKSEL */
#define CCFG_I2SCLKSEL_CLKSEL(value)        (CCFG_I2SCLKSEL_CLKSEL_Msk & ((value) << CCFG_I2SCLKSEL_CLKSEL_Pos))  

/* -------- CCFG_USBMR : (MATRIX Offset: 0x120) (R/W 32) USB Management Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t USBMODE:1;                 /**< bit:      0  USB Mode Selection                       */
    uint32_t USBHTSSC:1;                /**< bit:      1  USB Transceiver Suspend Software Control */
    uint32_t USBHTSC:1;                 /**< bit:      2  USB Host Transceiver Suspend Control     */
    uint32_t :29;                       /**< bit:  3..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} CCFG_USBMR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define CCFG_USBMR_OFFSET                   (0x120)                                       /**<  (CCFG_USBMR) USB Management Register  Offset */

#define CCFG_USBMR_USBMODE_Pos              0                                              /**< (CCFG_USBMR) USB Mode Selection Position */
#define CCFG_USBMR_USBMODE_Msk              (_U_(0x1) << CCFG_USBMR_USBMODE_Pos)           /**< (CCFG_USBMR) USB Mode Selection Mask */
#define CCFG_USBMR_USBMODE                  CCFG_USBMR_USBMODE_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use CCFG_USBMR_USBMODE_Msk instead */
#define CCFG_USBMR_USBHTSSC_Pos             1                                              /**< (CCFG_USBMR) USB Transceiver Suspend Software Control Position */
#define CCFG_USBMR_USBHTSSC_Msk             (_U_(0x1) << CCFG_USBMR_USBHTSSC_Pos)          /**< (CCFG_USBMR) USB Transceiver Suspend Software Control Mask */
#define CCFG_USBMR_USBHTSSC                 CCFG_USBMR_USBHTSSC_Msk                        /**< \deprecated Old style mask definition for 1 bit bitfield. Use CCFG_USBMR_USBHTSSC_Msk instead */
#define CCFG_USBMR_USBHTSC_Pos              2                                              /**< (CCFG_USBMR) USB Host Transceiver Suspend Control Position */
#define CCFG_USBMR_USBHTSC_Msk              (_U_(0x1) << CCFG_USBMR_USBHTSC_Pos)           /**< (CCFG_USBMR) USB Host Transceiver Suspend Control Mask */
#define CCFG_USBMR_USBHTSC                  CCFG_USBMR_USBHTSC_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use CCFG_USBMR_USBHTSC_Msk instead */
#define CCFG_USBMR_MASK                     _U_(0x07)                                      /**< \deprecated (CCFG_USBMR) Register MASK  (Use CCFG_USBMR_Msk instead)  */
#define CCFG_USBMR_Msk                      _U_(0x07)                                      /**< (CCFG_USBMR) Register Mask  */


/* -------- MATRIX_WPMR : (MATRIX Offset: 0x1e4) (R/W 32) Write Protection Mode Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t WPEN:1;                    /**< bit:      0  Write Protection Enable                  */
    uint32_t :7;                        /**< bit:   1..7  Reserved */
    uint32_t WPKEY:24;                  /**< bit:  8..31  Write Protection Key                     */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} MATRIX_WPMR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define MATRIX_WPMR_OFFSET                  (0x1E4)                                       /**<  (MATRIX_WPMR) Write Protection Mode Register  Offset */

#define MATRIX_WPMR_WPEN_Pos                0                                              /**< (MATRIX_WPMR) Write Protection Enable Position */
#define MATRIX_WPMR_WPEN_Msk                (_U_(0x1) << MATRIX_WPMR_WPEN_Pos)             /**< (MATRIX_WPMR) Write Protection Enable Mask */
#define MATRIX_WPMR_WPEN                    MATRIX_WPMR_WPEN_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use MATRIX_WPMR_WPEN_Msk instead */
#define MATRIX_WPMR_WPKEY_Pos               8                                              /**< (MATRIX_WPMR) Write Protection Key Position */
#define MATRIX_WPMR_WPKEY_Msk               (_U_(0xFFFFFF) << MATRIX_WPMR_WPKEY_Pos)       /**< (MATRIX_WPMR) Write Protection Key Mask */
#define MATRIX_WPMR_WPKEY(value)            (MATRIX_WPMR_WPKEY_Msk & ((value) << MATRIX_WPMR_WPKEY_Pos))
#define   MATRIX_WPMR_WPKEY_PASSWD_Val      _U_(0x4D4154)                                  /**< (MATRIX_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit. Always reads as 0.  */
#define MATRIX_WPMR_WPKEY_PASSWD            (MATRIX_WPMR_WPKEY_PASSWD_Val << MATRIX_WPMR_WPKEY_Pos)  /**< (MATRIX_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit. Always reads as 0. Position  */
#define MATRIX_WPMR_MASK                    _U_(0xFFFFFF01)                                /**< \deprecated (MATRIX_WPMR) Register MASK  (Use MATRIX_WPMR_Msk instead)  */
#define MATRIX_WPMR_Msk                     _U_(0xFFFFFF01)                                /**< (MATRIX_WPMR) Register Mask  */


/* -------- MATRIX_WPSR : (MATRIX Offset: 0x1e8) (R/ 32) Write Protection Status Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t WPVS:1;                    /**< bit:      0  Write Protection Violation Status        */
    uint32_t :7;                        /**< bit:   1..7  Reserved */
    uint32_t WPVSRC:16;                 /**< bit:  8..23  Write Protection Violation Source        */
    uint32_t :8;                        /**< bit: 24..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} MATRIX_WPSR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define MATRIX_WPSR_OFFSET                  (0x1E8)                                       /**<  (MATRIX_WPSR) Write Protection Status Register  Offset */

#define MATRIX_WPSR_WPVS_Pos                0                                              /**< (MATRIX_WPSR) Write Protection Violation Status Position */
#define MATRIX_WPSR_WPVS_Msk                (_U_(0x1) << MATRIX_WPSR_WPVS_Pos)             /**< (MATRIX_WPSR) Write Protection Violation Status Mask */
#define MATRIX_WPSR_WPVS                    MATRIX_WPSR_WPVS_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use MATRIX_WPSR_WPVS_Msk instead */
#define MATRIX_WPSR_WPVSRC_Pos              8                                              /**< (MATRIX_WPSR) Write Protection Violation Source Position */
#define MATRIX_WPSR_WPVSRC_Msk              (_U_(0xFFFF) << MATRIX_WPSR_WPVSRC_Pos)        /**< (MATRIX_WPSR) Write Protection Violation Source Mask */
#define MATRIX_WPSR_WPVSRC(value)           (MATRIX_WPSR_WPVSRC_Msk & ((value) << MATRIX_WPSR_WPVSRC_Pos))
#define MATRIX_WPSR_MASK                    _U_(0xFFFF01)                                  /**< \deprecated (MATRIX_WPSR) Register MASK  (Use MATRIX_WPSR_Msk instead)  */
#define MATRIX_WPSR_Msk                     _U_(0xFFFF01)                                  /**< (MATRIX_WPSR) Register Mask  */


#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'R'
/** \brief MATRIX hardware registers */
typedef struct {  
  __IO uint32_t MATRIX_MCFG[3]; /**< (MATRIX Offset: 0x00) Master Configuration Register 0 */
  RoReg8  Reserved1[0x34];
  __IO uint32_t MATRIX_SCFG[4]; /**< (MATRIX Offset: 0x40) Slave Configuration Register 0 */
  RoReg8  Reserved2[0x30];
  __IO uint32_t MATRIX_PRAS0;   /**< (MATRIX Offset: 0x80) Priority Register A for Slave 0 */
  RoReg8  Reserved3[0x4];
  __IO uint32_t MATRIX_PRAS1;   /**< (MATRIX Offset: 0x88) Priority Register A for Slave 1 */
  RoReg8  Reserved4[0x4];
  __IO uint32_t MATRIX_PRAS2;   /**< (MATRIX Offset: 0x90) Priority Register A for Slave 2 */
  RoReg8  Reserved5[0x4];
  __IO uint32_t MATRIX_PRAS3;   /**< (MATRIX Offset: 0x98) Priority Register A for Slave 3 */
  RoReg8  Reserved6[0x78];
  __IO uint32_t CCFG_SYSIO;     /**< (MATRIX Offset: 0x114) System I/O Configuration Register */
  __IO uint32_t CCFG_DYNCKG;    /**< (MATRIX Offset: 0x118) Dynamic Clock Gating Register */
  __IO uint32_t CCFG_I2SCLKSEL; /**< (MATRIX Offset: 0x11C) I2S Clock Source Selection Register */
  __IO uint32_t CCFG_USBMR;     /**< (MATRIX Offset: 0x120) USB Management Register */
  RoReg8  Reserved7[0xC0];
  __IO uint32_t MATRIX_WPMR;    /**< (MATRIX Offset: 0x1E4) Write Protection Mode Register */
  __I  uint32_t MATRIX_WPSR;    /**< (MATRIX Offset: 0x1E8) Write Protection Status Register */
} Matrix;

#elif COMPONENT_TYPEDEF_STYLE == 'N'
/** \brief MATRIX hardware registers */
typedef struct {  
  __IO MATRIX_MCFG_Type               MATRIX_MCFG[3]; /**< Offset: 0x00 (R/W  32) Master Configuration Register 0 */
  __I  uint32_t                       Reserved1[13];
  __IO MATRIX_SCFG_Type               MATRIX_SCFG[4]; /**< Offset: 0x40 (R/W  32) Slave Configuration Register 0 */
  __I  uint32_t                       Reserved2[12];
  __IO MATRIX_PRAS0_Type              MATRIX_PRAS0;   /**< Offset: 0x80 (R/W  32) Priority Register A for Slave 0 */
  __I  uint32_t                       Reserved3[1];
  __IO MATRIX_PRAS1_Type              MATRIX_PRAS1;   /**< Offset: 0x88 (R/W  32) Priority Register A for Slave 1 */
  __I  uint32_t                       Reserved4[1];
  __IO MATRIX_PRAS2_Type              MATRIX_PRAS2;   /**< Offset: 0x90 (R/W  32) Priority Register A for Slave 2 */
  __I  uint32_t                       Reserved5[1];
  __IO MATRIX_PRAS3_Type              MATRIX_PRAS3;   /**< Offset: 0x98 (R/W  32) Priority Register A for Slave 3 */
  __I  uint32_t                       Reserved6[30];
  __IO CCFG_SYSIO_Type                CCFG_SYSIO;     /**< Offset: 0x114 (R/W  32) System I/O Configuration Register */
  __IO CCFG_DYNCKG_Type               CCFG_DYNCKG;    /**< Offset: 0x118 (R/W  32) Dynamic Clock Gating Register */
  __IO CCFG_I2SCLKSEL_Type            CCFG_I2SCLKSEL; /**< Offset: 0x11C (R/W  32) I2S Clock Source Selection Register */
  __IO CCFG_USBMR_Type                CCFG_USBMR;     /**< Offset: 0x120 (R/W  32) USB Management Register */
  __I  uint32_t                       Reserved7[48];
  __IO MATRIX_WPMR_Type               MATRIX_WPMR;    /**< Offset: 0x1E4 (R/W  32) Write Protection Mode Register */
  __I  MATRIX_WPSR_Type               MATRIX_WPSR;    /**< Offset: 0x1E8 (R/   32) Write Protection Status Register */
} Matrix;

#else /* COMPONENT_TYPEDEF_STYLE */
#error Unknown component typedef style
#endif /* COMPONENT_TYPEDEF_STYLE */

#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
/** @}  end of AHB Bus Matrix */

#endif /* _SAMG55_MATRIX_COMPONENT_H_ */
