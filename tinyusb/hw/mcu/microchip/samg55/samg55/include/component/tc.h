/**
 * \file
 *
 * \brief Component description for TC
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
#ifndef _SAMG55_TC_COMPONENT_H_
#define _SAMG55_TC_COMPONENT_H_
#define _SAMG55_TC_COMPONENT_         /**< \deprecated  Backward compatibility for ASF */

/** \addtogroup SAMG_SAMG55 Timer Counter
 *  @{
 */
/* ========================================================================== */
/**  SOFTWARE API DEFINITION FOR TC */
/* ========================================================================== */
#ifndef COMPONENT_TYPEDEF_STYLE
  #define COMPONENT_TYPEDEF_STYLE 'R'  /**< Defines default style of typedefs for the component header files ('R' = RFO, 'N' = NTO)*/
#endif

#define TC_6082                       /**< (TC) Module ID */
#define REV_TC ZB                     /**< (TC) Module revision */

/* -------- TC_CCR : (TC Offset: 0x00) (/W 32) Channel Control Register (channel = 0) -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t CLKEN:1;                   /**< bit:      0  Counter Clock Enable Command             */
    uint32_t CLKDIS:1;                  /**< bit:      1  Counter Clock Disable Command            */
    uint32_t SWTRG:1;                   /**< bit:      2  Software Trigger Command                 */
    uint32_t :29;                       /**< bit:  3..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} TC_CCR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define TC_CCR_OFFSET                       (0x00)                                        /**<  (TC_CCR) Channel Control Register (channel = 0)  Offset */

#define TC_CCR_CLKEN_Pos                    0                                              /**< (TC_CCR) Counter Clock Enable Command Position */
#define TC_CCR_CLKEN_Msk                    (_U_(0x1) << TC_CCR_CLKEN_Pos)                 /**< (TC_CCR) Counter Clock Enable Command Mask */
#define TC_CCR_CLKEN                        TC_CCR_CLKEN_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_CCR_CLKEN_Msk instead */
#define TC_CCR_CLKDIS_Pos                   1                                              /**< (TC_CCR) Counter Clock Disable Command Position */
#define TC_CCR_CLKDIS_Msk                   (_U_(0x1) << TC_CCR_CLKDIS_Pos)                /**< (TC_CCR) Counter Clock Disable Command Mask */
#define TC_CCR_CLKDIS                       TC_CCR_CLKDIS_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_CCR_CLKDIS_Msk instead */
#define TC_CCR_SWTRG_Pos                    2                                              /**< (TC_CCR) Software Trigger Command Position */
#define TC_CCR_SWTRG_Msk                    (_U_(0x1) << TC_CCR_SWTRG_Pos)                 /**< (TC_CCR) Software Trigger Command Mask */
#define TC_CCR_SWTRG                        TC_CCR_SWTRG_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_CCR_SWTRG_Msk instead */
#define TC_CCR_MASK                         _U_(0x07)                                      /**< \deprecated (TC_CCR) Register MASK  (Use TC_CCR_Msk instead)  */
#define TC_CCR_Msk                          _U_(0x07)                                      /**< (TC_CCR) Register Mask  */


/* -------- TC_CMR : (TC Offset: 0x04) (R/W 32) Channel Mode Register (channel = 0) -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t TCCLKS:3;                  /**< bit:   0..2  Clock Selection                          */
    uint32_t CLKI:1;                    /**< bit:      3  Clock Invert                             */
    uint32_t BURST:2;                   /**< bit:   4..5  Burst Signal Selection                   */
    uint32_t LDBSTOP:1;                 /**< bit:      6  Counter Clock Stopped with RB Loading    */
    uint32_t LDBDIS:1;                  /**< bit:      7  Counter Clock Disable with RB Loading    */
    uint32_t ETRGEDG:2;                 /**< bit:   8..9  External Trigger Edge Selection          */
    uint32_t ABETRG:1;                  /**< bit:     10  TIOA or TIOB External Trigger Selection  */
    uint32_t :3;                        /**< bit: 11..13  Reserved */
    uint32_t CPCTRG:1;                  /**< bit:     14  RC Compare Trigger Enable                */
    uint32_t WAVE:1;                    /**< bit:     15  Waveform Mode                            */
    uint32_t LDRA:2;                    /**< bit: 16..17  RA Loading Edge Selection                */
    uint32_t LDRB:2;                    /**< bit: 18..19  RB Loading Edge Selection                */
    uint32_t SBSMPLR:3;                 /**< bit: 20..22  Loading Edge Subsampling Ratio           */
    uint32_t :9;                        /**< bit: 23..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} TC_CMR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define TC_CMR_OFFSET                       (0x04)                                        /**<  (TC_CMR) Channel Mode Register (channel = 0)  Offset */

#define TC_CMR_TCCLKS_Pos                   0                                              /**< (TC_CMR) Clock Selection Position */
#define TC_CMR_TCCLKS_Msk                   (_U_(0x7) << TC_CMR_TCCLKS_Pos)                /**< (TC_CMR) Clock Selection Mask */
#define TC_CMR_TCCLKS(value)                (TC_CMR_TCCLKS_Msk & ((value) << TC_CMR_TCCLKS_Pos))
#define   TC_CMR_TCCLKS_TIMER_CLOCK1_Val    _U_(0x0)                                       /**< (TC_CMR) Clock selected: internal TIMER_CLOCK1 clock signal (from PMC)  */
#define   TC_CMR_TCCLKS_TIMER_CLOCK2_Val    _U_(0x1)                                       /**< (TC_CMR) Clock selected: internal TIMER_CLOCK2 clock signal (from PMC)  */
#define   TC_CMR_TCCLKS_TIMER_CLOCK3_Val    _U_(0x2)                                       /**< (TC_CMR) Clock selected: internal TIMER_CLOCK3 clock signal (from PMC)  */
#define   TC_CMR_TCCLKS_TIMER_CLOCK4_Val    _U_(0x3)                                       /**< (TC_CMR) Clock selected: internal TIMER_CLOCK4 clock signal (from PMC)  */
#define   TC_CMR_TCCLKS_TIMER_CLOCK5_Val    _U_(0x4)                                       /**< (TC_CMR) Clock selected: internal TIMER_CLOCK5 clock signal (from PMC)  */
#define   TC_CMR_TCCLKS_XC0_Val             _U_(0x5)                                       /**< (TC_CMR) Clock selected: XC0  */
#define   TC_CMR_TCCLKS_XC1_Val             _U_(0x6)                                       /**< (TC_CMR) Clock selected: XC1  */
#define   TC_CMR_TCCLKS_XC2_Val             _U_(0x7)                                       /**< (TC_CMR) Clock selected: XC2  */
#define TC_CMR_TCCLKS_TIMER_CLOCK1          (TC_CMR_TCCLKS_TIMER_CLOCK1_Val << TC_CMR_TCCLKS_Pos)  /**< (TC_CMR) Clock selected: internal TIMER_CLOCK1 clock signal (from PMC) Position  */
#define TC_CMR_TCCLKS_TIMER_CLOCK2          (TC_CMR_TCCLKS_TIMER_CLOCK2_Val << TC_CMR_TCCLKS_Pos)  /**< (TC_CMR) Clock selected: internal TIMER_CLOCK2 clock signal (from PMC) Position  */
#define TC_CMR_TCCLKS_TIMER_CLOCK3          (TC_CMR_TCCLKS_TIMER_CLOCK3_Val << TC_CMR_TCCLKS_Pos)  /**< (TC_CMR) Clock selected: internal TIMER_CLOCK3 clock signal (from PMC) Position  */
#define TC_CMR_TCCLKS_TIMER_CLOCK4          (TC_CMR_TCCLKS_TIMER_CLOCK4_Val << TC_CMR_TCCLKS_Pos)  /**< (TC_CMR) Clock selected: internal TIMER_CLOCK4 clock signal (from PMC) Position  */
#define TC_CMR_TCCLKS_TIMER_CLOCK5          (TC_CMR_TCCLKS_TIMER_CLOCK5_Val << TC_CMR_TCCLKS_Pos)  /**< (TC_CMR) Clock selected: internal TIMER_CLOCK5 clock signal (from PMC) Position  */
#define TC_CMR_TCCLKS_XC0                   (TC_CMR_TCCLKS_XC0_Val << TC_CMR_TCCLKS_Pos)   /**< (TC_CMR) Clock selected: XC0 Position  */
#define TC_CMR_TCCLKS_XC1                   (TC_CMR_TCCLKS_XC1_Val << TC_CMR_TCCLKS_Pos)   /**< (TC_CMR) Clock selected: XC1 Position  */
#define TC_CMR_TCCLKS_XC2                   (TC_CMR_TCCLKS_XC2_Val << TC_CMR_TCCLKS_Pos)   /**< (TC_CMR) Clock selected: XC2 Position  */
#define TC_CMR_CLKI_Pos                     3                                              /**< (TC_CMR) Clock Invert Position */
#define TC_CMR_CLKI_Msk                     (_U_(0x1) << TC_CMR_CLKI_Pos)                  /**< (TC_CMR) Clock Invert Mask */
#define TC_CMR_CLKI                         TC_CMR_CLKI_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_CMR_CLKI_Msk instead */
#define TC_CMR_BURST_Pos                    4                                              /**< (TC_CMR) Burst Signal Selection Position */
#define TC_CMR_BURST_Msk                    (_U_(0x3) << TC_CMR_BURST_Pos)                 /**< (TC_CMR) Burst Signal Selection Mask */
#define TC_CMR_BURST(value)                 (TC_CMR_BURST_Msk & ((value) << TC_CMR_BURST_Pos))
#define   TC_CMR_BURST_NONE_Val             _U_(0x0)                                       /**< (TC_CMR) The clock is not gated by an external signal.  */
#define   TC_CMR_BURST_XC0_Val              _U_(0x1)                                       /**< (TC_CMR) XC0 is ANDed with the selected clock.  */
#define   TC_CMR_BURST_XC1_Val              _U_(0x2)                                       /**< (TC_CMR) XC1 is ANDed with the selected clock.  */
#define   TC_CMR_BURST_XC2_Val              _U_(0x3)                                       /**< (TC_CMR) XC2 is ANDed with the selected clock.  */
#define TC_CMR_BURST_NONE                   (TC_CMR_BURST_NONE_Val << TC_CMR_BURST_Pos)    /**< (TC_CMR) The clock is not gated by an external signal. Position  */
#define TC_CMR_BURST_XC0                    (TC_CMR_BURST_XC0_Val << TC_CMR_BURST_Pos)     /**< (TC_CMR) XC0 is ANDed with the selected clock. Position  */
#define TC_CMR_BURST_XC1                    (TC_CMR_BURST_XC1_Val << TC_CMR_BURST_Pos)     /**< (TC_CMR) XC1 is ANDed with the selected clock. Position  */
#define TC_CMR_BURST_XC2                    (TC_CMR_BURST_XC2_Val << TC_CMR_BURST_Pos)     /**< (TC_CMR) XC2 is ANDed with the selected clock. Position  */
#define TC_CMR_LDBSTOP_Pos                  6                                              /**< (TC_CMR) Counter Clock Stopped with RB Loading Position */
#define TC_CMR_LDBSTOP_Msk                  (_U_(0x1) << TC_CMR_LDBSTOP_Pos)               /**< (TC_CMR) Counter Clock Stopped with RB Loading Mask */
#define TC_CMR_LDBSTOP                      TC_CMR_LDBSTOP_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_CMR_LDBSTOP_Msk instead */
#define TC_CMR_LDBDIS_Pos                   7                                              /**< (TC_CMR) Counter Clock Disable with RB Loading Position */
#define TC_CMR_LDBDIS_Msk                   (_U_(0x1) << TC_CMR_LDBDIS_Pos)                /**< (TC_CMR) Counter Clock Disable with RB Loading Mask */
#define TC_CMR_LDBDIS                       TC_CMR_LDBDIS_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_CMR_LDBDIS_Msk instead */
#define TC_CMR_ETRGEDG_Pos                  8                                              /**< (TC_CMR) External Trigger Edge Selection Position */
#define TC_CMR_ETRGEDG_Msk                  (_U_(0x3) << TC_CMR_ETRGEDG_Pos)               /**< (TC_CMR) External Trigger Edge Selection Mask */
#define TC_CMR_ETRGEDG(value)               (TC_CMR_ETRGEDG_Msk & ((value) << TC_CMR_ETRGEDG_Pos))
#define   TC_CMR_ETRGEDG_NONE_Val           _U_(0x0)                                       /**< (TC_CMR) The clock is not gated by an external signal.  */
#define   TC_CMR_ETRGEDG_RISING_Val         _U_(0x1)                                       /**< (TC_CMR) Rising edge  */
#define   TC_CMR_ETRGEDG_FALLING_Val        _U_(0x2)                                       /**< (TC_CMR) Falling edge  */
#define   TC_CMR_ETRGEDG_EDGE_Val           _U_(0x3)                                       /**< (TC_CMR) Each edge  */
#define TC_CMR_ETRGEDG_NONE                 (TC_CMR_ETRGEDG_NONE_Val << TC_CMR_ETRGEDG_Pos)  /**< (TC_CMR) The clock is not gated by an external signal. Position  */
#define TC_CMR_ETRGEDG_RISING               (TC_CMR_ETRGEDG_RISING_Val << TC_CMR_ETRGEDG_Pos)  /**< (TC_CMR) Rising edge Position  */
#define TC_CMR_ETRGEDG_FALLING              (TC_CMR_ETRGEDG_FALLING_Val << TC_CMR_ETRGEDG_Pos)  /**< (TC_CMR) Falling edge Position  */
#define TC_CMR_ETRGEDG_EDGE                 (TC_CMR_ETRGEDG_EDGE_Val << TC_CMR_ETRGEDG_Pos)  /**< (TC_CMR) Each edge Position  */
#define TC_CMR_ABETRG_Pos                   10                                             /**< (TC_CMR) TIOA or TIOB External Trigger Selection Position */
#define TC_CMR_ABETRG_Msk                   (_U_(0x1) << TC_CMR_ABETRG_Pos)                /**< (TC_CMR) TIOA or TIOB External Trigger Selection Mask */
#define TC_CMR_ABETRG                       TC_CMR_ABETRG_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_CMR_ABETRG_Msk instead */
#define TC_CMR_CPCTRG_Pos                   14                                             /**< (TC_CMR) RC Compare Trigger Enable Position */
#define TC_CMR_CPCTRG_Msk                   (_U_(0x1) << TC_CMR_CPCTRG_Pos)                /**< (TC_CMR) RC Compare Trigger Enable Mask */
#define TC_CMR_CPCTRG                       TC_CMR_CPCTRG_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_CMR_CPCTRG_Msk instead */
#define TC_CMR_WAVE_Pos                     15                                             /**< (TC_CMR) Waveform Mode Position */
#define TC_CMR_WAVE_Msk                     (_U_(0x1) << TC_CMR_WAVE_Pos)                  /**< (TC_CMR) Waveform Mode Mask */
#define TC_CMR_WAVE                         TC_CMR_WAVE_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_CMR_WAVE_Msk instead */
#define TC_CMR_LDRA_Pos                     16                                             /**< (TC_CMR) RA Loading Edge Selection Position */
#define TC_CMR_LDRA_Msk                     (_U_(0x3) << TC_CMR_LDRA_Pos)                  /**< (TC_CMR) RA Loading Edge Selection Mask */
#define TC_CMR_LDRA(value)                  (TC_CMR_LDRA_Msk & ((value) << TC_CMR_LDRA_Pos))
#define   TC_CMR_LDRA_NONE_Val              _U_(0x0)                                       /**< (TC_CMR) None  */
#define   TC_CMR_LDRA_RISING_Val            _U_(0x1)                                       /**< (TC_CMR) Rising edge of TIOA  */
#define   TC_CMR_LDRA_FALLING_Val           _U_(0x2)                                       /**< (TC_CMR) Falling edge of TIOA  */
#define   TC_CMR_LDRA_EDGE_Val              _U_(0x3)                                       /**< (TC_CMR) Each edge of TIOA  */
#define TC_CMR_LDRA_NONE                    (TC_CMR_LDRA_NONE_Val << TC_CMR_LDRA_Pos)      /**< (TC_CMR) None Position  */
#define TC_CMR_LDRA_RISING                  (TC_CMR_LDRA_RISING_Val << TC_CMR_LDRA_Pos)    /**< (TC_CMR) Rising edge of TIOA Position  */
#define TC_CMR_LDRA_FALLING                 (TC_CMR_LDRA_FALLING_Val << TC_CMR_LDRA_Pos)   /**< (TC_CMR) Falling edge of TIOA Position  */
#define TC_CMR_LDRA_EDGE                    (TC_CMR_LDRA_EDGE_Val << TC_CMR_LDRA_Pos)      /**< (TC_CMR) Each edge of TIOA Position  */
#define TC_CMR_LDRB_Pos                     18                                             /**< (TC_CMR) RB Loading Edge Selection Position */
#define TC_CMR_LDRB_Msk                     (_U_(0x3) << TC_CMR_LDRB_Pos)                  /**< (TC_CMR) RB Loading Edge Selection Mask */
#define TC_CMR_LDRB(value)                  (TC_CMR_LDRB_Msk & ((value) << TC_CMR_LDRB_Pos))
#define   TC_CMR_LDRB_NONE_Val              _U_(0x0)                                       /**< (TC_CMR) None  */
#define   TC_CMR_LDRB_RISING_Val            _U_(0x1)                                       /**< (TC_CMR) Rising edge of TIOA  */
#define   TC_CMR_LDRB_FALLING_Val           _U_(0x2)                                       /**< (TC_CMR) Falling edge of TIOA  */
#define   TC_CMR_LDRB_EDGE_Val              _U_(0x3)                                       /**< (TC_CMR) Each edge of TIOA  */
#define TC_CMR_LDRB_NONE                    (TC_CMR_LDRB_NONE_Val << TC_CMR_LDRB_Pos)      /**< (TC_CMR) None Position  */
#define TC_CMR_LDRB_RISING                  (TC_CMR_LDRB_RISING_Val << TC_CMR_LDRB_Pos)    /**< (TC_CMR) Rising edge of TIOA Position  */
#define TC_CMR_LDRB_FALLING                 (TC_CMR_LDRB_FALLING_Val << TC_CMR_LDRB_Pos)   /**< (TC_CMR) Falling edge of TIOA Position  */
#define TC_CMR_LDRB_EDGE                    (TC_CMR_LDRB_EDGE_Val << TC_CMR_LDRB_Pos)      /**< (TC_CMR) Each edge of TIOA Position  */
#define TC_CMR_SBSMPLR_Pos                  20                                             /**< (TC_CMR) Loading Edge Subsampling Ratio Position */
#define TC_CMR_SBSMPLR_Msk                  (_U_(0x7) << TC_CMR_SBSMPLR_Pos)               /**< (TC_CMR) Loading Edge Subsampling Ratio Mask */
#define TC_CMR_SBSMPLR(value)               (TC_CMR_SBSMPLR_Msk & ((value) << TC_CMR_SBSMPLR_Pos))
#define   TC_CMR_SBSMPLR_ONE_Val            _U_(0x0)                                       /**< (TC_CMR) Load a Capture Register each selected edge  */
#define   TC_CMR_SBSMPLR_HALF_Val           _U_(0x1)                                       /**< (TC_CMR) Load a Capture Register every 2 selected edges  */
#define   TC_CMR_SBSMPLR_FOURTH_Val         _U_(0x2)                                       /**< (TC_CMR) Load a Capture Register every 4 selected edges  */
#define   TC_CMR_SBSMPLR_EIGHTH_Val         _U_(0x3)                                       /**< (TC_CMR) Load a Capture Register every 8 selected edges  */
#define   TC_CMR_SBSMPLR_SIXTEENTH_Val      _U_(0x4)                                       /**< (TC_CMR) Load a Capture Register every 16 selected edges  */
#define TC_CMR_SBSMPLR_ONE                  (TC_CMR_SBSMPLR_ONE_Val << TC_CMR_SBSMPLR_Pos)  /**< (TC_CMR) Load a Capture Register each selected edge Position  */
#define TC_CMR_SBSMPLR_HALF                 (TC_CMR_SBSMPLR_HALF_Val << TC_CMR_SBSMPLR_Pos)  /**< (TC_CMR) Load a Capture Register every 2 selected edges Position  */
#define TC_CMR_SBSMPLR_FOURTH               (TC_CMR_SBSMPLR_FOURTH_Val << TC_CMR_SBSMPLR_Pos)  /**< (TC_CMR) Load a Capture Register every 4 selected edges Position  */
#define TC_CMR_SBSMPLR_EIGHTH               (TC_CMR_SBSMPLR_EIGHTH_Val << TC_CMR_SBSMPLR_Pos)  /**< (TC_CMR) Load a Capture Register every 8 selected edges Position  */
#define TC_CMR_SBSMPLR_SIXTEENTH            (TC_CMR_SBSMPLR_SIXTEENTH_Val << TC_CMR_SBSMPLR_Pos)  /**< (TC_CMR) Load a Capture Register every 16 selected edges Position  */
#define TC_CMR_MASK                         _U_(0x7FC7FF)                                  /**< \deprecated (TC_CMR) Register MASK  (Use TC_CMR_Msk instead)  */
#define TC_CMR_Msk                          _U_(0x7FC7FF)                                  /**< (TC_CMR) Register Mask  */


/* -------- TC_SMMR : (TC Offset: 0x08) (R/W 32) Stepper Motor Mode Register (channel = 0) -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t GCEN:1;                    /**< bit:      0  Gray Count Enable                        */
    uint32_t DOWN:1;                    /**< bit:      1  Down Count                               */
    uint32_t :30;                       /**< bit:  2..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} TC_SMMR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define TC_SMMR_OFFSET                      (0x08)                                        /**<  (TC_SMMR) Stepper Motor Mode Register (channel = 0)  Offset */

#define TC_SMMR_GCEN_Pos                    0                                              /**< (TC_SMMR) Gray Count Enable Position */
#define TC_SMMR_GCEN_Msk                    (_U_(0x1) << TC_SMMR_GCEN_Pos)                 /**< (TC_SMMR) Gray Count Enable Mask */
#define TC_SMMR_GCEN                        TC_SMMR_GCEN_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_SMMR_GCEN_Msk instead */
#define TC_SMMR_DOWN_Pos                    1                                              /**< (TC_SMMR) Down Count Position */
#define TC_SMMR_DOWN_Msk                    (_U_(0x1) << TC_SMMR_DOWN_Pos)                 /**< (TC_SMMR) Down Count Mask */
#define TC_SMMR_DOWN                        TC_SMMR_DOWN_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_SMMR_DOWN_Msk instead */
#define TC_SMMR_MASK                        _U_(0x03)                                      /**< \deprecated (TC_SMMR) Register MASK  (Use TC_SMMR_Msk instead)  */
#define TC_SMMR_Msk                         _U_(0x03)                                      /**< (TC_SMMR) Register Mask  */


/* -------- TC_RAB : (TC Offset: 0x0c) (R/ 32) Register AB (channel = 0) -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RAB:32;                    /**< bit:  0..31  Register A or Register B                 */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} TC_RAB_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define TC_RAB_OFFSET                       (0x0C)                                        /**<  (TC_RAB) Register AB (channel = 0)  Offset */

#define TC_RAB_RAB_Pos                      0                                              /**< (TC_RAB) Register A or Register B Position */
#define TC_RAB_RAB_Msk                      (_U_(0xFFFFFFFF) << TC_RAB_RAB_Pos)            /**< (TC_RAB) Register A or Register B Mask */
#define TC_RAB_RAB(value)                   (TC_RAB_RAB_Msk & ((value) << TC_RAB_RAB_Pos))
#define TC_RAB_MASK                         _U_(0xFFFFFFFF)                                /**< \deprecated (TC_RAB) Register MASK  (Use TC_RAB_Msk instead)  */
#define TC_RAB_Msk                          _U_(0xFFFFFFFF)                                /**< (TC_RAB) Register Mask  */


/* -------- TC_CV : (TC Offset: 0x10) (R/ 32) Counter Value (channel = 0) -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t CV:32;                     /**< bit:  0..31  Counter Value                            */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} TC_CV_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define TC_CV_OFFSET                        (0x10)                                        /**<  (TC_CV) Counter Value (channel = 0)  Offset */

#define TC_CV_CV_Pos                        0                                              /**< (TC_CV) Counter Value Position */
#define TC_CV_CV_Msk                        (_U_(0xFFFFFFFF) << TC_CV_CV_Pos)              /**< (TC_CV) Counter Value Mask */
#define TC_CV_CV(value)                     (TC_CV_CV_Msk & ((value) << TC_CV_CV_Pos))   
#define TC_CV_MASK                          _U_(0xFFFFFFFF)                                /**< \deprecated (TC_CV) Register MASK  (Use TC_CV_Msk instead)  */
#define TC_CV_Msk                           _U_(0xFFFFFFFF)                                /**< (TC_CV) Register Mask  */


/* -------- TC_RA : (TC Offset: 0x14) (R/W 32) Register A (channel = 0) -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RA:32;                     /**< bit:  0..31  Register A                               */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} TC_RA_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define TC_RA_OFFSET                        (0x14)                                        /**<  (TC_RA) Register A (channel = 0)  Offset */

#define TC_RA_RA_Pos                        0                                              /**< (TC_RA) Register A Position */
#define TC_RA_RA_Msk                        (_U_(0xFFFFFFFF) << TC_RA_RA_Pos)              /**< (TC_RA) Register A Mask */
#define TC_RA_RA(value)                     (TC_RA_RA_Msk & ((value) << TC_RA_RA_Pos))   
#define TC_RA_MASK                          _U_(0xFFFFFFFF)                                /**< \deprecated (TC_RA) Register MASK  (Use TC_RA_Msk instead)  */
#define TC_RA_Msk                           _U_(0xFFFFFFFF)                                /**< (TC_RA) Register Mask  */


/* -------- TC_RB : (TC Offset: 0x18) (R/W 32) Register B (channel = 0) -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RB:32;                     /**< bit:  0..31  Register B                               */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} TC_RB_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define TC_RB_OFFSET                        (0x18)                                        /**<  (TC_RB) Register B (channel = 0)  Offset */

#define TC_RB_RB_Pos                        0                                              /**< (TC_RB) Register B Position */
#define TC_RB_RB_Msk                        (_U_(0xFFFFFFFF) << TC_RB_RB_Pos)              /**< (TC_RB) Register B Mask */
#define TC_RB_RB(value)                     (TC_RB_RB_Msk & ((value) << TC_RB_RB_Pos))   
#define TC_RB_MASK                          _U_(0xFFFFFFFF)                                /**< \deprecated (TC_RB) Register MASK  (Use TC_RB_Msk instead)  */
#define TC_RB_Msk                           _U_(0xFFFFFFFF)                                /**< (TC_RB) Register Mask  */


/* -------- TC_RC : (TC Offset: 0x1c) (R/W 32) Register C (channel = 0) -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RC:32;                     /**< bit:  0..31  Register C                               */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} TC_RC_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define TC_RC_OFFSET                        (0x1C)                                        /**<  (TC_RC) Register C (channel = 0)  Offset */

#define TC_RC_RC_Pos                        0                                              /**< (TC_RC) Register C Position */
#define TC_RC_RC_Msk                        (_U_(0xFFFFFFFF) << TC_RC_RC_Pos)              /**< (TC_RC) Register C Mask */
#define TC_RC_RC(value)                     (TC_RC_RC_Msk & ((value) << TC_RC_RC_Pos))   
#define TC_RC_MASK                          _U_(0xFFFFFFFF)                                /**< \deprecated (TC_RC) Register MASK  (Use TC_RC_Msk instead)  */
#define TC_RC_Msk                           _U_(0xFFFFFFFF)                                /**< (TC_RC) Register Mask  */


/* -------- TC_SR : (TC Offset: 0x20) (R/ 32) Status Register (channel = 0) -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t COVFS:1;                   /**< bit:      0  Counter Overflow Status (cleared on read) */
    uint32_t LOVRS:1;                   /**< bit:      1  Load Overrun Status (cleared on read)    */
    uint32_t CPAS:1;                    /**< bit:      2  RA Compare Status (cleared on read)      */
    uint32_t CPBS:1;                    /**< bit:      3  RB Compare Status (cleared on read)      */
    uint32_t CPCS:1;                    /**< bit:      4  RC Compare Status (cleared on read)      */
    uint32_t LDRAS:1;                   /**< bit:      5  RA Loading Status (cleared on read)      */
    uint32_t LDRBS:1;                   /**< bit:      6  RB Loading Status (cleared on read)      */
    uint32_t ETRGS:1;                   /**< bit:      7  External Trigger Status (cleared on read) */
    uint32_t ENDRX:1;                   /**< bit:      8  End of Receiver Transfer (cleared by writing TC_RCR or TC_RNCR) */
    uint32_t RXBUFF:1;                  /**< bit:      9  Reception Buffer Full (cleared by writing TC_RCR or TC_RNCR) */
    uint32_t :6;                        /**< bit: 10..15  Reserved */
    uint32_t CLKSTA:1;                  /**< bit:     16  Clock Enabling Status                    */
    uint32_t MTIOA:1;                   /**< bit:     17  TIOA Mirror                              */
    uint32_t MTIOB:1;                   /**< bit:     18  TIOB Mirror                              */
    uint32_t :13;                       /**< bit: 19..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} TC_SR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define TC_SR_OFFSET                        (0x20)                                        /**<  (TC_SR) Status Register (channel = 0)  Offset */

#define TC_SR_COVFS_Pos                     0                                              /**< (TC_SR) Counter Overflow Status (cleared on read) Position */
#define TC_SR_COVFS_Msk                     (_U_(0x1) << TC_SR_COVFS_Pos)                  /**< (TC_SR) Counter Overflow Status (cleared on read) Mask */
#define TC_SR_COVFS                         TC_SR_COVFS_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_SR_COVFS_Msk instead */
#define TC_SR_LOVRS_Pos                     1                                              /**< (TC_SR) Load Overrun Status (cleared on read) Position */
#define TC_SR_LOVRS_Msk                     (_U_(0x1) << TC_SR_LOVRS_Pos)                  /**< (TC_SR) Load Overrun Status (cleared on read) Mask */
#define TC_SR_LOVRS                         TC_SR_LOVRS_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_SR_LOVRS_Msk instead */
#define TC_SR_CPAS_Pos                      2                                              /**< (TC_SR) RA Compare Status (cleared on read) Position */
#define TC_SR_CPAS_Msk                      (_U_(0x1) << TC_SR_CPAS_Pos)                   /**< (TC_SR) RA Compare Status (cleared on read) Mask */
#define TC_SR_CPAS                          TC_SR_CPAS_Msk                                 /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_SR_CPAS_Msk instead */
#define TC_SR_CPBS_Pos                      3                                              /**< (TC_SR) RB Compare Status (cleared on read) Position */
#define TC_SR_CPBS_Msk                      (_U_(0x1) << TC_SR_CPBS_Pos)                   /**< (TC_SR) RB Compare Status (cleared on read) Mask */
#define TC_SR_CPBS                          TC_SR_CPBS_Msk                                 /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_SR_CPBS_Msk instead */
#define TC_SR_CPCS_Pos                      4                                              /**< (TC_SR) RC Compare Status (cleared on read) Position */
#define TC_SR_CPCS_Msk                      (_U_(0x1) << TC_SR_CPCS_Pos)                   /**< (TC_SR) RC Compare Status (cleared on read) Mask */
#define TC_SR_CPCS                          TC_SR_CPCS_Msk                                 /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_SR_CPCS_Msk instead */
#define TC_SR_LDRAS_Pos                     5                                              /**< (TC_SR) RA Loading Status (cleared on read) Position */
#define TC_SR_LDRAS_Msk                     (_U_(0x1) << TC_SR_LDRAS_Pos)                  /**< (TC_SR) RA Loading Status (cleared on read) Mask */
#define TC_SR_LDRAS                         TC_SR_LDRAS_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_SR_LDRAS_Msk instead */
#define TC_SR_LDRBS_Pos                     6                                              /**< (TC_SR) RB Loading Status (cleared on read) Position */
#define TC_SR_LDRBS_Msk                     (_U_(0x1) << TC_SR_LDRBS_Pos)                  /**< (TC_SR) RB Loading Status (cleared on read) Mask */
#define TC_SR_LDRBS                         TC_SR_LDRBS_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_SR_LDRBS_Msk instead */
#define TC_SR_ETRGS_Pos                     7                                              /**< (TC_SR) External Trigger Status (cleared on read) Position */
#define TC_SR_ETRGS_Msk                     (_U_(0x1) << TC_SR_ETRGS_Pos)                  /**< (TC_SR) External Trigger Status (cleared on read) Mask */
#define TC_SR_ETRGS                         TC_SR_ETRGS_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_SR_ETRGS_Msk instead */
#define TC_SR_ENDRX_Pos                     8                                              /**< (TC_SR) End of Receiver Transfer (cleared by writing TC_RCR or TC_RNCR) Position */
#define TC_SR_ENDRX_Msk                     (_U_(0x1) << TC_SR_ENDRX_Pos)                  /**< (TC_SR) End of Receiver Transfer (cleared by writing TC_RCR or TC_RNCR) Mask */
#define TC_SR_ENDRX                         TC_SR_ENDRX_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_SR_ENDRX_Msk instead */
#define TC_SR_RXBUFF_Pos                    9                                              /**< (TC_SR) Reception Buffer Full (cleared by writing TC_RCR or TC_RNCR) Position */
#define TC_SR_RXBUFF_Msk                    (_U_(0x1) << TC_SR_RXBUFF_Pos)                 /**< (TC_SR) Reception Buffer Full (cleared by writing TC_RCR or TC_RNCR) Mask */
#define TC_SR_RXBUFF                        TC_SR_RXBUFF_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_SR_RXBUFF_Msk instead */
#define TC_SR_CLKSTA_Pos                    16                                             /**< (TC_SR) Clock Enabling Status Position */
#define TC_SR_CLKSTA_Msk                    (_U_(0x1) << TC_SR_CLKSTA_Pos)                 /**< (TC_SR) Clock Enabling Status Mask */
#define TC_SR_CLKSTA                        TC_SR_CLKSTA_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_SR_CLKSTA_Msk instead */
#define TC_SR_MTIOA_Pos                     17                                             /**< (TC_SR) TIOA Mirror Position */
#define TC_SR_MTIOA_Msk                     (_U_(0x1) << TC_SR_MTIOA_Pos)                  /**< (TC_SR) TIOA Mirror Mask */
#define TC_SR_MTIOA                         TC_SR_MTIOA_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_SR_MTIOA_Msk instead */
#define TC_SR_MTIOB_Pos                     18                                             /**< (TC_SR) TIOB Mirror Position */
#define TC_SR_MTIOB_Msk                     (_U_(0x1) << TC_SR_MTIOB_Pos)                  /**< (TC_SR) TIOB Mirror Mask */
#define TC_SR_MTIOB                         TC_SR_MTIOB_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_SR_MTIOB_Msk instead */
#define TC_SR_MASK                          _U_(0x703FF)                                   /**< \deprecated (TC_SR) Register MASK  (Use TC_SR_Msk instead)  */
#define TC_SR_Msk                           _U_(0x703FF)                                   /**< (TC_SR) Register Mask  */


/* -------- TC_IER : (TC Offset: 0x24) (/W 32) Interrupt Enable Register (channel = 0) -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t COVFS:1;                   /**< bit:      0  Counter Overflow                         */
    uint32_t LOVRS:1;                   /**< bit:      1  Load Overrun                             */
    uint32_t CPAS:1;                    /**< bit:      2  RA Compare                               */
    uint32_t CPBS:1;                    /**< bit:      3  RB Compare                               */
    uint32_t CPCS:1;                    /**< bit:      4  RC Compare                               */
    uint32_t LDRAS:1;                   /**< bit:      5  RA Loading                               */
    uint32_t LDRBS:1;                   /**< bit:      6  RB Loading                               */
    uint32_t ETRGS:1;                   /**< bit:      7  External Trigger                         */
    uint32_t ENDRX:1;                   /**< bit:      8  End of Receiver Transfer                 */
    uint32_t RXBUFF:1;                  /**< bit:      9  Reception Buffer Full                    */
    uint32_t :22;                       /**< bit: 10..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} TC_IER_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define TC_IER_OFFSET                       (0x24)                                        /**<  (TC_IER) Interrupt Enable Register (channel = 0)  Offset */

#define TC_IER_COVFS_Pos                    0                                              /**< (TC_IER) Counter Overflow Position */
#define TC_IER_COVFS_Msk                    (_U_(0x1) << TC_IER_COVFS_Pos)                 /**< (TC_IER) Counter Overflow Mask */
#define TC_IER_COVFS                        TC_IER_COVFS_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_IER_COVFS_Msk instead */
#define TC_IER_LOVRS_Pos                    1                                              /**< (TC_IER) Load Overrun Position */
#define TC_IER_LOVRS_Msk                    (_U_(0x1) << TC_IER_LOVRS_Pos)                 /**< (TC_IER) Load Overrun Mask */
#define TC_IER_LOVRS                        TC_IER_LOVRS_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_IER_LOVRS_Msk instead */
#define TC_IER_CPAS_Pos                     2                                              /**< (TC_IER) RA Compare Position */
#define TC_IER_CPAS_Msk                     (_U_(0x1) << TC_IER_CPAS_Pos)                  /**< (TC_IER) RA Compare Mask */
#define TC_IER_CPAS                         TC_IER_CPAS_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_IER_CPAS_Msk instead */
#define TC_IER_CPBS_Pos                     3                                              /**< (TC_IER) RB Compare Position */
#define TC_IER_CPBS_Msk                     (_U_(0x1) << TC_IER_CPBS_Pos)                  /**< (TC_IER) RB Compare Mask */
#define TC_IER_CPBS                         TC_IER_CPBS_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_IER_CPBS_Msk instead */
#define TC_IER_CPCS_Pos                     4                                              /**< (TC_IER) RC Compare Position */
#define TC_IER_CPCS_Msk                     (_U_(0x1) << TC_IER_CPCS_Pos)                  /**< (TC_IER) RC Compare Mask */
#define TC_IER_CPCS                         TC_IER_CPCS_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_IER_CPCS_Msk instead */
#define TC_IER_LDRAS_Pos                    5                                              /**< (TC_IER) RA Loading Position */
#define TC_IER_LDRAS_Msk                    (_U_(0x1) << TC_IER_LDRAS_Pos)                 /**< (TC_IER) RA Loading Mask */
#define TC_IER_LDRAS                        TC_IER_LDRAS_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_IER_LDRAS_Msk instead */
#define TC_IER_LDRBS_Pos                    6                                              /**< (TC_IER) RB Loading Position */
#define TC_IER_LDRBS_Msk                    (_U_(0x1) << TC_IER_LDRBS_Pos)                 /**< (TC_IER) RB Loading Mask */
#define TC_IER_LDRBS                        TC_IER_LDRBS_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_IER_LDRBS_Msk instead */
#define TC_IER_ETRGS_Pos                    7                                              /**< (TC_IER) External Trigger Position */
#define TC_IER_ETRGS_Msk                    (_U_(0x1) << TC_IER_ETRGS_Pos)                 /**< (TC_IER) External Trigger Mask */
#define TC_IER_ETRGS                        TC_IER_ETRGS_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_IER_ETRGS_Msk instead */
#define TC_IER_ENDRX_Pos                    8                                              /**< (TC_IER) End of Receiver Transfer Position */
#define TC_IER_ENDRX_Msk                    (_U_(0x1) << TC_IER_ENDRX_Pos)                 /**< (TC_IER) End of Receiver Transfer Mask */
#define TC_IER_ENDRX                        TC_IER_ENDRX_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_IER_ENDRX_Msk instead */
#define TC_IER_RXBUFF_Pos                   9                                              /**< (TC_IER) Reception Buffer Full Position */
#define TC_IER_RXBUFF_Msk                   (_U_(0x1) << TC_IER_RXBUFF_Pos)                /**< (TC_IER) Reception Buffer Full Mask */
#define TC_IER_RXBUFF                       TC_IER_RXBUFF_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_IER_RXBUFF_Msk instead */
#define TC_IER_MASK                         _U_(0x3FF)                                     /**< \deprecated (TC_IER) Register MASK  (Use TC_IER_Msk instead)  */
#define TC_IER_Msk                          _U_(0x3FF)                                     /**< (TC_IER) Register Mask  */


/* -------- TC_IDR : (TC Offset: 0x28) (/W 32) Interrupt Disable Register (channel = 0) -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t COVFS:1;                   /**< bit:      0  Counter Overflow                         */
    uint32_t LOVRS:1;                   /**< bit:      1  Load Overrun                             */
    uint32_t CPAS:1;                    /**< bit:      2  RA Compare                               */
    uint32_t CPBS:1;                    /**< bit:      3  RB Compare                               */
    uint32_t CPCS:1;                    /**< bit:      4  RC Compare                               */
    uint32_t LDRAS:1;                   /**< bit:      5  RA Loading                               */
    uint32_t LDRBS:1;                   /**< bit:      6  RB Loading                               */
    uint32_t ETRGS:1;                   /**< bit:      7  External Trigger                         */
    uint32_t ENDRX:1;                   /**< bit:      8  End of Receiver Transfer                 */
    uint32_t RXBUFF:1;                  /**< bit:      9  Reception Buffer Full                    */
    uint32_t :22;                       /**< bit: 10..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} TC_IDR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define TC_IDR_OFFSET                       (0x28)                                        /**<  (TC_IDR) Interrupt Disable Register (channel = 0)  Offset */

#define TC_IDR_COVFS_Pos                    0                                              /**< (TC_IDR) Counter Overflow Position */
#define TC_IDR_COVFS_Msk                    (_U_(0x1) << TC_IDR_COVFS_Pos)                 /**< (TC_IDR) Counter Overflow Mask */
#define TC_IDR_COVFS                        TC_IDR_COVFS_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_IDR_COVFS_Msk instead */
#define TC_IDR_LOVRS_Pos                    1                                              /**< (TC_IDR) Load Overrun Position */
#define TC_IDR_LOVRS_Msk                    (_U_(0x1) << TC_IDR_LOVRS_Pos)                 /**< (TC_IDR) Load Overrun Mask */
#define TC_IDR_LOVRS                        TC_IDR_LOVRS_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_IDR_LOVRS_Msk instead */
#define TC_IDR_CPAS_Pos                     2                                              /**< (TC_IDR) RA Compare Position */
#define TC_IDR_CPAS_Msk                     (_U_(0x1) << TC_IDR_CPAS_Pos)                  /**< (TC_IDR) RA Compare Mask */
#define TC_IDR_CPAS                         TC_IDR_CPAS_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_IDR_CPAS_Msk instead */
#define TC_IDR_CPBS_Pos                     3                                              /**< (TC_IDR) RB Compare Position */
#define TC_IDR_CPBS_Msk                     (_U_(0x1) << TC_IDR_CPBS_Pos)                  /**< (TC_IDR) RB Compare Mask */
#define TC_IDR_CPBS                         TC_IDR_CPBS_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_IDR_CPBS_Msk instead */
#define TC_IDR_CPCS_Pos                     4                                              /**< (TC_IDR) RC Compare Position */
#define TC_IDR_CPCS_Msk                     (_U_(0x1) << TC_IDR_CPCS_Pos)                  /**< (TC_IDR) RC Compare Mask */
#define TC_IDR_CPCS                         TC_IDR_CPCS_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_IDR_CPCS_Msk instead */
#define TC_IDR_LDRAS_Pos                    5                                              /**< (TC_IDR) RA Loading Position */
#define TC_IDR_LDRAS_Msk                    (_U_(0x1) << TC_IDR_LDRAS_Pos)                 /**< (TC_IDR) RA Loading Mask */
#define TC_IDR_LDRAS                        TC_IDR_LDRAS_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_IDR_LDRAS_Msk instead */
#define TC_IDR_LDRBS_Pos                    6                                              /**< (TC_IDR) RB Loading Position */
#define TC_IDR_LDRBS_Msk                    (_U_(0x1) << TC_IDR_LDRBS_Pos)                 /**< (TC_IDR) RB Loading Mask */
#define TC_IDR_LDRBS                        TC_IDR_LDRBS_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_IDR_LDRBS_Msk instead */
#define TC_IDR_ETRGS_Pos                    7                                              /**< (TC_IDR) External Trigger Position */
#define TC_IDR_ETRGS_Msk                    (_U_(0x1) << TC_IDR_ETRGS_Pos)                 /**< (TC_IDR) External Trigger Mask */
#define TC_IDR_ETRGS                        TC_IDR_ETRGS_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_IDR_ETRGS_Msk instead */
#define TC_IDR_ENDRX_Pos                    8                                              /**< (TC_IDR) End of Receiver Transfer Position */
#define TC_IDR_ENDRX_Msk                    (_U_(0x1) << TC_IDR_ENDRX_Pos)                 /**< (TC_IDR) End of Receiver Transfer Mask */
#define TC_IDR_ENDRX                        TC_IDR_ENDRX_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_IDR_ENDRX_Msk instead */
#define TC_IDR_RXBUFF_Pos                   9                                              /**< (TC_IDR) Reception Buffer Full Position */
#define TC_IDR_RXBUFF_Msk                   (_U_(0x1) << TC_IDR_RXBUFF_Pos)                /**< (TC_IDR) Reception Buffer Full Mask */
#define TC_IDR_RXBUFF                       TC_IDR_RXBUFF_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_IDR_RXBUFF_Msk instead */
#define TC_IDR_MASK                         _U_(0x3FF)                                     /**< \deprecated (TC_IDR) Register MASK  (Use TC_IDR_Msk instead)  */
#define TC_IDR_Msk                          _U_(0x3FF)                                     /**< (TC_IDR) Register Mask  */


/* -------- TC_IMR : (TC Offset: 0x2c) (R/ 32) Interrupt Mask Register (channel = 0) -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t COVFS:1;                   /**< bit:      0  Counter Overflow                         */
    uint32_t LOVRS:1;                   /**< bit:      1  Load Overrun                             */
    uint32_t CPAS:1;                    /**< bit:      2  RA Compare                               */
    uint32_t CPBS:1;                    /**< bit:      3  RB Compare                               */
    uint32_t CPCS:1;                    /**< bit:      4  RC Compare                               */
    uint32_t LDRAS:1;                   /**< bit:      5  RA Loading                               */
    uint32_t LDRBS:1;                   /**< bit:      6  RB Loading                               */
    uint32_t ETRGS:1;                   /**< bit:      7  External Trigger                         */
    uint32_t ENDRX:1;                   /**< bit:      8  End of Receiver Transfer                 */
    uint32_t RXBUFF:1;                  /**< bit:      9  Reception Buffer Full                    */
    uint32_t :22;                       /**< bit: 10..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} TC_IMR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define TC_IMR_OFFSET                       (0x2C)                                        /**<  (TC_IMR) Interrupt Mask Register (channel = 0)  Offset */

#define TC_IMR_COVFS_Pos                    0                                              /**< (TC_IMR) Counter Overflow Position */
#define TC_IMR_COVFS_Msk                    (_U_(0x1) << TC_IMR_COVFS_Pos)                 /**< (TC_IMR) Counter Overflow Mask */
#define TC_IMR_COVFS                        TC_IMR_COVFS_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_IMR_COVFS_Msk instead */
#define TC_IMR_LOVRS_Pos                    1                                              /**< (TC_IMR) Load Overrun Position */
#define TC_IMR_LOVRS_Msk                    (_U_(0x1) << TC_IMR_LOVRS_Pos)                 /**< (TC_IMR) Load Overrun Mask */
#define TC_IMR_LOVRS                        TC_IMR_LOVRS_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_IMR_LOVRS_Msk instead */
#define TC_IMR_CPAS_Pos                     2                                              /**< (TC_IMR) RA Compare Position */
#define TC_IMR_CPAS_Msk                     (_U_(0x1) << TC_IMR_CPAS_Pos)                  /**< (TC_IMR) RA Compare Mask */
#define TC_IMR_CPAS                         TC_IMR_CPAS_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_IMR_CPAS_Msk instead */
#define TC_IMR_CPBS_Pos                     3                                              /**< (TC_IMR) RB Compare Position */
#define TC_IMR_CPBS_Msk                     (_U_(0x1) << TC_IMR_CPBS_Pos)                  /**< (TC_IMR) RB Compare Mask */
#define TC_IMR_CPBS                         TC_IMR_CPBS_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_IMR_CPBS_Msk instead */
#define TC_IMR_CPCS_Pos                     4                                              /**< (TC_IMR) RC Compare Position */
#define TC_IMR_CPCS_Msk                     (_U_(0x1) << TC_IMR_CPCS_Pos)                  /**< (TC_IMR) RC Compare Mask */
#define TC_IMR_CPCS                         TC_IMR_CPCS_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_IMR_CPCS_Msk instead */
#define TC_IMR_LDRAS_Pos                    5                                              /**< (TC_IMR) RA Loading Position */
#define TC_IMR_LDRAS_Msk                    (_U_(0x1) << TC_IMR_LDRAS_Pos)                 /**< (TC_IMR) RA Loading Mask */
#define TC_IMR_LDRAS                        TC_IMR_LDRAS_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_IMR_LDRAS_Msk instead */
#define TC_IMR_LDRBS_Pos                    6                                              /**< (TC_IMR) RB Loading Position */
#define TC_IMR_LDRBS_Msk                    (_U_(0x1) << TC_IMR_LDRBS_Pos)                 /**< (TC_IMR) RB Loading Mask */
#define TC_IMR_LDRBS                        TC_IMR_LDRBS_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_IMR_LDRBS_Msk instead */
#define TC_IMR_ETRGS_Pos                    7                                              /**< (TC_IMR) External Trigger Position */
#define TC_IMR_ETRGS_Msk                    (_U_(0x1) << TC_IMR_ETRGS_Pos)                 /**< (TC_IMR) External Trigger Mask */
#define TC_IMR_ETRGS                        TC_IMR_ETRGS_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_IMR_ETRGS_Msk instead */
#define TC_IMR_ENDRX_Pos                    8                                              /**< (TC_IMR) End of Receiver Transfer Position */
#define TC_IMR_ENDRX_Msk                    (_U_(0x1) << TC_IMR_ENDRX_Pos)                 /**< (TC_IMR) End of Receiver Transfer Mask */
#define TC_IMR_ENDRX                        TC_IMR_ENDRX_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_IMR_ENDRX_Msk instead */
#define TC_IMR_RXBUFF_Pos                   9                                              /**< (TC_IMR) Reception Buffer Full Position */
#define TC_IMR_RXBUFF_Msk                   (_U_(0x1) << TC_IMR_RXBUFF_Pos)                /**< (TC_IMR) Reception Buffer Full Mask */
#define TC_IMR_RXBUFF                       TC_IMR_RXBUFF_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_IMR_RXBUFF_Msk instead */
#define TC_IMR_MASK                         _U_(0x3FF)                                     /**< \deprecated (TC_IMR) Register MASK  (Use TC_IMR_Msk instead)  */
#define TC_IMR_Msk                          _U_(0x3FF)                                     /**< (TC_IMR) Register Mask  */


/* -------- TC_BCR : (TC Offset: 0xc0) (/W 32) Block Control Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t SYNC:1;                    /**< bit:      0  Synchro Command                          */
    uint32_t :31;                       /**< bit:  1..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} TC_BCR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define TC_BCR_OFFSET                       (0xC0)                                        /**<  (TC_BCR) Block Control Register  Offset */

#define TC_BCR_SYNC_Pos                     0                                              /**< (TC_BCR) Synchro Command Position */
#define TC_BCR_SYNC_Msk                     (_U_(0x1) << TC_BCR_SYNC_Pos)                  /**< (TC_BCR) Synchro Command Mask */
#define TC_BCR_SYNC                         TC_BCR_SYNC_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_BCR_SYNC_Msk instead */
#define TC_BCR_MASK                         _U_(0x01)                                      /**< \deprecated (TC_BCR) Register MASK  (Use TC_BCR_Msk instead)  */
#define TC_BCR_Msk                          _U_(0x01)                                      /**< (TC_BCR) Register Mask  */


/* -------- TC_BMR : (TC Offset: 0xc4) (R/W 32) Block Mode Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t TC0XC0S:2;                 /**< bit:   0..1  External Clock Signal 0 Selection        */
    uint32_t TC1XC1S:2;                 /**< bit:   2..3  External Clock Signal 1 Selection        */
    uint32_t TC2XC2S:2;                 /**< bit:   4..5  External Clock Signal 2 Selection        */
    uint32_t :26;                       /**< bit:  6..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} TC_BMR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define TC_BMR_OFFSET                       (0xC4)                                        /**<  (TC_BMR) Block Mode Register  Offset */

#define TC_BMR_TC0XC0S_Pos                  0                                              /**< (TC_BMR) External Clock Signal 0 Selection Position */
#define TC_BMR_TC0XC0S_Msk                  (_U_(0x3) << TC_BMR_TC0XC0S_Pos)               /**< (TC_BMR) External Clock Signal 0 Selection Mask */
#define TC_BMR_TC0XC0S(value)               (TC_BMR_TC0XC0S_Msk & ((value) << TC_BMR_TC0XC0S_Pos))
#define   TC_BMR_TC0XC0S_TCLK0_Val          _U_(0x0)                                       /**< (TC_BMR) Signal connected to XC0: TCLK0  */
#define   TC_BMR_TC0XC0S_TIOA1_Val          _U_(0x2)                                       /**< (TC_BMR) Signal connected to XC0: TIOA1  */
#define   TC_BMR_TC0XC0S_TIOA2_Val          _U_(0x3)                                       /**< (TC_BMR) Signal connected to XC0: TIOA2  */
#define TC_BMR_TC0XC0S_TCLK0                (TC_BMR_TC0XC0S_TCLK0_Val << TC_BMR_TC0XC0S_Pos)  /**< (TC_BMR) Signal connected to XC0: TCLK0 Position  */
#define TC_BMR_TC0XC0S_TIOA1                (TC_BMR_TC0XC0S_TIOA1_Val << TC_BMR_TC0XC0S_Pos)  /**< (TC_BMR) Signal connected to XC0: TIOA1 Position  */
#define TC_BMR_TC0XC0S_TIOA2                (TC_BMR_TC0XC0S_TIOA2_Val << TC_BMR_TC0XC0S_Pos)  /**< (TC_BMR) Signal connected to XC0: TIOA2 Position  */
#define TC_BMR_TC1XC1S_Pos                  2                                              /**< (TC_BMR) External Clock Signal 1 Selection Position */
#define TC_BMR_TC1XC1S_Msk                  (_U_(0x3) << TC_BMR_TC1XC1S_Pos)               /**< (TC_BMR) External Clock Signal 1 Selection Mask */
#define TC_BMR_TC1XC1S(value)               (TC_BMR_TC1XC1S_Msk & ((value) << TC_BMR_TC1XC1S_Pos))
#define   TC_BMR_TC1XC1S_TCLK1_Val          _U_(0x0)                                       /**< (TC_BMR) Signal connected to XC1: TCLK1  */
#define   TC_BMR_TC1XC1S_TIOA0_Val          _U_(0x2)                                       /**< (TC_BMR) Signal connected to XC1: TIOA0  */
#define   TC_BMR_TC1XC1S_TIOA2_Val          _U_(0x3)                                       /**< (TC_BMR) Signal connected to XC1: TIOA2  */
#define TC_BMR_TC1XC1S_TCLK1                (TC_BMR_TC1XC1S_TCLK1_Val << TC_BMR_TC1XC1S_Pos)  /**< (TC_BMR) Signal connected to XC1: TCLK1 Position  */
#define TC_BMR_TC1XC1S_TIOA0                (TC_BMR_TC1XC1S_TIOA0_Val << TC_BMR_TC1XC1S_Pos)  /**< (TC_BMR) Signal connected to XC1: TIOA0 Position  */
#define TC_BMR_TC1XC1S_TIOA2                (TC_BMR_TC1XC1S_TIOA2_Val << TC_BMR_TC1XC1S_Pos)  /**< (TC_BMR) Signal connected to XC1: TIOA2 Position  */
#define TC_BMR_TC2XC2S_Pos                  4                                              /**< (TC_BMR) External Clock Signal 2 Selection Position */
#define TC_BMR_TC2XC2S_Msk                  (_U_(0x3) << TC_BMR_TC2XC2S_Pos)               /**< (TC_BMR) External Clock Signal 2 Selection Mask */
#define TC_BMR_TC2XC2S(value)               (TC_BMR_TC2XC2S_Msk & ((value) << TC_BMR_TC2XC2S_Pos))
#define   TC_BMR_TC2XC2S_TCLK2_Val          _U_(0x0)                                       /**< (TC_BMR) Signal connected to XC2: TCLK2  */
#define   TC_BMR_TC2XC2S_TIOA0_Val          _U_(0x2)                                       /**< (TC_BMR) Signal connected to XC2: TIOA0  */
#define   TC_BMR_TC2XC2S_TIOA1_Val          _U_(0x3)                                       /**< (TC_BMR) Signal connected to XC2: TIOA1  */
#define TC_BMR_TC2XC2S_TCLK2                (TC_BMR_TC2XC2S_TCLK2_Val << TC_BMR_TC2XC2S_Pos)  /**< (TC_BMR) Signal connected to XC2: TCLK2 Position  */
#define TC_BMR_TC2XC2S_TIOA0                (TC_BMR_TC2XC2S_TIOA0_Val << TC_BMR_TC2XC2S_Pos)  /**< (TC_BMR) Signal connected to XC2: TIOA0 Position  */
#define TC_BMR_TC2XC2S_TIOA1                (TC_BMR_TC2XC2S_TIOA1_Val << TC_BMR_TC2XC2S_Pos)  /**< (TC_BMR) Signal connected to XC2: TIOA1 Position  */
#define TC_BMR_MASK                         _U_(0x3F)                                      /**< \deprecated (TC_BMR) Register MASK  (Use TC_BMR_Msk instead)  */
#define TC_BMR_Msk                          _U_(0x3F)                                      /**< (TC_BMR) Register Mask  */


/* -------- TC_WPMR : (TC Offset: 0xe4) (R/W 32) Write Protection Mode Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t WPEN:1;                    /**< bit:      0  Write Protection Enable                  */
    uint32_t :7;                        /**< bit:   1..7  Reserved */
    uint32_t WPKEY:24;                  /**< bit:  8..31  Write Protection Key                     */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} TC_WPMR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define TC_WPMR_OFFSET                      (0xE4)                                        /**<  (TC_WPMR) Write Protection Mode Register  Offset */

#define TC_WPMR_WPEN_Pos                    0                                              /**< (TC_WPMR) Write Protection Enable Position */
#define TC_WPMR_WPEN_Msk                    (_U_(0x1) << TC_WPMR_WPEN_Pos)                 /**< (TC_WPMR) Write Protection Enable Mask */
#define TC_WPMR_WPEN                        TC_WPMR_WPEN_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_WPMR_WPEN_Msk instead */
#define TC_WPMR_WPKEY_Pos                   8                                              /**< (TC_WPMR) Write Protection Key Position */
#define TC_WPMR_WPKEY_Msk                   (_U_(0xFFFFFF) << TC_WPMR_WPKEY_Pos)           /**< (TC_WPMR) Write Protection Key Mask */
#define TC_WPMR_WPKEY(value)                (TC_WPMR_WPKEY_Msk & ((value) << TC_WPMR_WPKEY_Pos))
#define   TC_WPMR_WPKEY_PASSWD_Val          _U_(0x54494D)                                  /**< (TC_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit.Always reads as 0.  */
#define TC_WPMR_WPKEY_PASSWD                (TC_WPMR_WPKEY_PASSWD_Val << TC_WPMR_WPKEY_Pos)  /**< (TC_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit.Always reads as 0. Position  */
#define TC_WPMR_MASK                        _U_(0xFFFFFF01)                                /**< \deprecated (TC_WPMR) Register MASK  (Use TC_WPMR_Msk instead)  */
#define TC_WPMR_Msk                         _U_(0xFFFFFF01)                                /**< (TC_WPMR) Register Mask  */


/* -------- TC_RPR0 : (TC Offset: 0x100) (R/W 32) Receive Pointer Register (pdc = 0) -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXPTR:32;                  /**< bit:  0..31  Receive Pointer Register                 */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} TC_RPR0_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define TC_RPR0_OFFSET                      (0x100)                                       /**<  (TC_RPR0) Receive Pointer Register (pdc = 0)  Offset */

#define TC_RPR0_RXPTR_Pos                   0                                              /**< (TC_RPR0) Receive Pointer Register Position */
#define TC_RPR0_RXPTR_Msk                   (_U_(0xFFFFFFFF) << TC_RPR0_RXPTR_Pos)         /**< (TC_RPR0) Receive Pointer Register Mask */
#define TC_RPR0_RXPTR(value)                (TC_RPR0_RXPTR_Msk & ((value) << TC_RPR0_RXPTR_Pos))
#define TC_RPR0_MASK                        _U_(0xFFFFFFFF)                                /**< \deprecated (TC_RPR0) Register MASK  (Use TC_RPR0_Msk instead)  */
#define TC_RPR0_Msk                         _U_(0xFFFFFFFF)                                /**< (TC_RPR0) Register Mask  */


/* -------- TC_RNPR0 : (TC Offset: 0x110) (R/W 32) Receive Next Pointer Register (pdc = 0) -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXNPTR:32;                 /**< bit:  0..31  Receive Next Pointer                     */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} TC_RNPR0_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define TC_RNPR0_OFFSET                     (0x110)                                       /**<  (TC_RNPR0) Receive Next Pointer Register (pdc = 0)  Offset */

#define TC_RNPR0_RXNPTR_Pos                 0                                              /**< (TC_RNPR0) Receive Next Pointer Position */
#define TC_RNPR0_RXNPTR_Msk                 (_U_(0xFFFFFFFF) << TC_RNPR0_RXNPTR_Pos)       /**< (TC_RNPR0) Receive Next Pointer Mask */
#define TC_RNPR0_RXNPTR(value)              (TC_RNPR0_RXNPTR_Msk & ((value) << TC_RNPR0_RXNPTR_Pos))
#define TC_RNPR0_MASK                       _U_(0xFFFFFFFF)                                /**< \deprecated (TC_RNPR0) Register MASK  (Use TC_RNPR0_Msk instead)  */
#define TC_RNPR0_Msk                        _U_(0xFFFFFFFF)                                /**< (TC_RNPR0) Register Mask  */


/* -------- TC_RNCR0 : (TC Offset: 0x114) (R/W 32) Receive Next Counter Register (pdc = 0) -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXNCTR:16;                 /**< bit:  0..15  Receive Next Counter                     */
    uint32_t :16;                       /**< bit: 16..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} TC_RNCR0_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define TC_RNCR0_OFFSET                     (0x114)                                       /**<  (TC_RNCR0) Receive Next Counter Register (pdc = 0)  Offset */

#define TC_RNCR0_RXNCTR_Pos                 0                                              /**< (TC_RNCR0) Receive Next Counter Position */
#define TC_RNCR0_RXNCTR_Msk                 (_U_(0xFFFF) << TC_RNCR0_RXNCTR_Pos)           /**< (TC_RNCR0) Receive Next Counter Mask */
#define TC_RNCR0_RXNCTR(value)              (TC_RNCR0_RXNCTR_Msk & ((value) << TC_RNCR0_RXNCTR_Pos))
#define TC_RNCR0_MASK                       _U_(0xFFFF)                                    /**< \deprecated (TC_RNCR0) Register MASK  (Use TC_RNCR0_Msk instead)  */
#define TC_RNCR0_Msk                        _U_(0xFFFF)                                    /**< (TC_RNCR0) Register Mask  */


/* -------- TC_PTCR0 : (TC Offset: 0x120) (/W 32) Transfer Control Register (pdc = 0) -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXTEN:1;                   /**< bit:      0  Receiver Transfer Enable                 */
    uint32_t RXTDIS:1;                  /**< bit:      1  Receiver Transfer Disable                */
    uint32_t :6;                        /**< bit:   2..7  Reserved */
    uint32_t TXTEN:1;                   /**< bit:      8  Transmitter Transfer Enable              */
    uint32_t TXTDIS:1;                  /**< bit:      9  Transmitter Transfer Disable             */
    uint32_t :6;                        /**< bit: 10..15  Reserved */
    uint32_t RXCBEN:1;                  /**< bit:     16  Receiver Circular Buffer Enable          */
    uint32_t RXCBDIS:1;                 /**< bit:     17  Receiver Circular Buffer Disable         */
    uint32_t TXCBEN:1;                  /**< bit:     18  Transmitter Circular Buffer Enable       */
    uint32_t TXCBDIS:1;                 /**< bit:     19  Transmitter Circular Buffer Disable      */
    uint32_t :4;                        /**< bit: 20..23  Reserved */
    uint32_t ERRCLR:1;                  /**< bit:     24  Transfer Bus Error Clear                 */
    uint32_t :7;                        /**< bit: 25..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} TC_PTCR0_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define TC_PTCR0_OFFSET                     (0x120)                                       /**<  (TC_PTCR0) Transfer Control Register (pdc = 0)  Offset */

#define TC_PTCR0_RXTEN_Pos                  0                                              /**< (TC_PTCR0) Receiver Transfer Enable Position */
#define TC_PTCR0_RXTEN_Msk                  (_U_(0x1) << TC_PTCR0_RXTEN_Pos)               /**< (TC_PTCR0) Receiver Transfer Enable Mask */
#define TC_PTCR0_RXTEN                      TC_PTCR0_RXTEN_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_PTCR0_RXTEN_Msk instead */
#define TC_PTCR0_RXTDIS_Pos                 1                                              /**< (TC_PTCR0) Receiver Transfer Disable Position */
#define TC_PTCR0_RXTDIS_Msk                 (_U_(0x1) << TC_PTCR0_RXTDIS_Pos)              /**< (TC_PTCR0) Receiver Transfer Disable Mask */
#define TC_PTCR0_RXTDIS                     TC_PTCR0_RXTDIS_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_PTCR0_RXTDIS_Msk instead */
#define TC_PTCR0_TXTEN_Pos                  8                                              /**< (TC_PTCR0) Transmitter Transfer Enable Position */
#define TC_PTCR0_TXTEN_Msk                  (_U_(0x1) << TC_PTCR0_TXTEN_Pos)               /**< (TC_PTCR0) Transmitter Transfer Enable Mask */
#define TC_PTCR0_TXTEN                      TC_PTCR0_TXTEN_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_PTCR0_TXTEN_Msk instead */
#define TC_PTCR0_TXTDIS_Pos                 9                                              /**< (TC_PTCR0) Transmitter Transfer Disable Position */
#define TC_PTCR0_TXTDIS_Msk                 (_U_(0x1) << TC_PTCR0_TXTDIS_Pos)              /**< (TC_PTCR0) Transmitter Transfer Disable Mask */
#define TC_PTCR0_TXTDIS                     TC_PTCR0_TXTDIS_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_PTCR0_TXTDIS_Msk instead */
#define TC_PTCR0_RXCBEN_Pos                 16                                             /**< (TC_PTCR0) Receiver Circular Buffer Enable Position */
#define TC_PTCR0_RXCBEN_Msk                 (_U_(0x1) << TC_PTCR0_RXCBEN_Pos)              /**< (TC_PTCR0) Receiver Circular Buffer Enable Mask */
#define TC_PTCR0_RXCBEN                     TC_PTCR0_RXCBEN_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_PTCR0_RXCBEN_Msk instead */
#define TC_PTCR0_RXCBDIS_Pos                17                                             /**< (TC_PTCR0) Receiver Circular Buffer Disable Position */
#define TC_PTCR0_RXCBDIS_Msk                (_U_(0x1) << TC_PTCR0_RXCBDIS_Pos)             /**< (TC_PTCR0) Receiver Circular Buffer Disable Mask */
#define TC_PTCR0_RXCBDIS                    TC_PTCR0_RXCBDIS_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_PTCR0_RXCBDIS_Msk instead */
#define TC_PTCR0_TXCBEN_Pos                 18                                             /**< (TC_PTCR0) Transmitter Circular Buffer Enable Position */
#define TC_PTCR0_TXCBEN_Msk                 (_U_(0x1) << TC_PTCR0_TXCBEN_Pos)              /**< (TC_PTCR0) Transmitter Circular Buffer Enable Mask */
#define TC_PTCR0_TXCBEN                     TC_PTCR0_TXCBEN_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_PTCR0_TXCBEN_Msk instead */
#define TC_PTCR0_TXCBDIS_Pos                19                                             /**< (TC_PTCR0) Transmitter Circular Buffer Disable Position */
#define TC_PTCR0_TXCBDIS_Msk                (_U_(0x1) << TC_PTCR0_TXCBDIS_Pos)             /**< (TC_PTCR0) Transmitter Circular Buffer Disable Mask */
#define TC_PTCR0_TXCBDIS                    TC_PTCR0_TXCBDIS_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_PTCR0_TXCBDIS_Msk instead */
#define TC_PTCR0_ERRCLR_Pos                 24                                             /**< (TC_PTCR0) Transfer Bus Error Clear Position */
#define TC_PTCR0_ERRCLR_Msk                 (_U_(0x1) << TC_PTCR0_ERRCLR_Pos)              /**< (TC_PTCR0) Transfer Bus Error Clear Mask */
#define TC_PTCR0_ERRCLR                     TC_PTCR0_ERRCLR_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_PTCR0_ERRCLR_Msk instead */
#define TC_PTCR0_MASK                       _U_(0x10F0303)                                 /**< \deprecated (TC_PTCR0) Register MASK  (Use TC_PTCR0_Msk instead)  */
#define TC_PTCR0_Msk                        _U_(0x10F0303)                                 /**< (TC_PTCR0) Register Mask  */


/* -------- TC_PTSR0 : (TC Offset: 0x124) (R/ 32) Transfer Status Register (pdc = 0) -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXTEN:1;                   /**< bit:      0  Receiver Transfer Enable                 */
    uint32_t :7;                        /**< bit:   1..7  Reserved */
    uint32_t TXTEN:1;                   /**< bit:      8  Transmitter Transfer Enable              */
    uint32_t :7;                        /**< bit:  9..15  Reserved */
    uint32_t RXCBEN:1;                  /**< bit:     16  Receiver Circular Buffer Enable          */
    uint32_t :1;                        /**< bit:     17  Reserved */
    uint32_t TXCBEN:1;                  /**< bit:     18  Transmitter Circular Buffer Enable       */
    uint32_t :5;                        /**< bit: 19..23  Reserved */
    uint32_t ERR:1;                     /**< bit:     24  Transfer Bus Error                       */
    uint32_t :7;                        /**< bit: 25..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} TC_PTSR0_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define TC_PTSR0_OFFSET                     (0x124)                                       /**<  (TC_PTSR0) Transfer Status Register (pdc = 0)  Offset */

#define TC_PTSR0_RXTEN_Pos                  0                                              /**< (TC_PTSR0) Receiver Transfer Enable Position */
#define TC_PTSR0_RXTEN_Msk                  (_U_(0x1) << TC_PTSR0_RXTEN_Pos)               /**< (TC_PTSR0) Receiver Transfer Enable Mask */
#define TC_PTSR0_RXTEN                      TC_PTSR0_RXTEN_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_PTSR0_RXTEN_Msk instead */
#define TC_PTSR0_TXTEN_Pos                  8                                              /**< (TC_PTSR0) Transmitter Transfer Enable Position */
#define TC_PTSR0_TXTEN_Msk                  (_U_(0x1) << TC_PTSR0_TXTEN_Pos)               /**< (TC_PTSR0) Transmitter Transfer Enable Mask */
#define TC_PTSR0_TXTEN                      TC_PTSR0_TXTEN_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_PTSR0_TXTEN_Msk instead */
#define TC_PTSR0_RXCBEN_Pos                 16                                             /**< (TC_PTSR0) Receiver Circular Buffer Enable Position */
#define TC_PTSR0_RXCBEN_Msk                 (_U_(0x1) << TC_PTSR0_RXCBEN_Pos)              /**< (TC_PTSR0) Receiver Circular Buffer Enable Mask */
#define TC_PTSR0_RXCBEN                     TC_PTSR0_RXCBEN_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_PTSR0_RXCBEN_Msk instead */
#define TC_PTSR0_TXCBEN_Pos                 18                                             /**< (TC_PTSR0) Transmitter Circular Buffer Enable Position */
#define TC_PTSR0_TXCBEN_Msk                 (_U_(0x1) << TC_PTSR0_TXCBEN_Pos)              /**< (TC_PTSR0) Transmitter Circular Buffer Enable Mask */
#define TC_PTSR0_TXCBEN                     TC_PTSR0_TXCBEN_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_PTSR0_TXCBEN_Msk instead */
#define TC_PTSR0_ERR_Pos                    24                                             /**< (TC_PTSR0) Transfer Bus Error Position */
#define TC_PTSR0_ERR_Msk                    (_U_(0x1) << TC_PTSR0_ERR_Pos)                 /**< (TC_PTSR0) Transfer Bus Error Mask */
#define TC_PTSR0_ERR                        TC_PTSR0_ERR_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use TC_PTSR0_ERR_Msk instead */
#define TC_PTSR0_MASK                       _U_(0x1050101)                                 /**< \deprecated (TC_PTSR0) Register MASK  (Use TC_PTSR0_Msk instead)  */
#define TC_PTSR0_Msk                        _U_(0x1050101)                                 /**< (TC_PTSR0) Register Mask  */


#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'R'
/** \brief TC_CHANNEL hardware registers */
typedef struct {  
  __O  uint32_t TC_CCR;         /**< (TC_CHANNEL Offset: 0x00) Channel Control Register (channel = 0) */
  __IO uint32_t TC_CMR;         /**< (TC_CHANNEL Offset: 0x04) Channel Mode Register (channel = 0) */
  __IO uint32_t TC_SMMR;        /**< (TC_CHANNEL Offset: 0x08) Stepper Motor Mode Register (channel = 0) */
  __I  uint32_t TC_RAB;         /**< (TC_CHANNEL Offset: 0x0C) Register AB (channel = 0) */
  __I  uint32_t TC_CV;          /**< (TC_CHANNEL Offset: 0x10) Counter Value (channel = 0) */
  __IO uint32_t TC_RA;          /**< (TC_CHANNEL Offset: 0x14) Register A (channel = 0) */
  __IO uint32_t TC_RB;          /**< (TC_CHANNEL Offset: 0x18) Register B (channel = 0) */
  __IO uint32_t TC_RC;          /**< (TC_CHANNEL Offset: 0x1C) Register C (channel = 0) */
  __I  uint32_t TC_SR;          /**< (TC_CHANNEL Offset: 0x20) Status Register (channel = 0) */
  __O  uint32_t TC_IER;         /**< (TC_CHANNEL Offset: 0x24) Interrupt Enable Register (channel = 0) */
  __O  uint32_t TC_IDR;         /**< (TC_CHANNEL Offset: 0x28) Interrupt Disable Register (channel = 0) */
  __I  uint32_t TC_IMR;         /**< (TC_CHANNEL Offset: 0x2C) Interrupt Mask Register (channel = 0) */
       RoReg8                         Reserved1[0x10];
} TcChannel;

#define TCCHANNEL_NUMBER 3
/** \brief TC hardware registers */
typedef struct {  
       TcChannel TC_CHANNEL[TCCHANNEL_NUMBER]; /**< Offset: 0x00 Channel Control Register (channel = 0) */
  __O  uint32_t TC_BCR;         /**< (TC Offset: 0xC0) Block Control Register */
  __IO uint32_t TC_BMR;         /**< (TC Offset: 0xC4) Block Mode Register */
  RoReg8  Reserved1[0x1C];
  __IO uint32_t TC_WPMR;        /**< (TC Offset: 0xE4) Write Protection Mode Register */
  RoReg8  Reserved2[0x18];
  __IO uint32_t TC_RPR0;        /**< (TC Offset: 0x100) Receive Pointer Register (pdc = 0) */
  RoReg8  Reserved3[0xC];
  __IO uint32_t TC_RNPR0;       /**< (TC Offset: 0x110) Receive Next Pointer Register (pdc = 0) */
  __IO uint32_t TC_RNCR0;       /**< (TC Offset: 0x114) Receive Next Counter Register (pdc = 0) */
  RoReg8  Reserved4[0x8];
  __O  uint32_t TC_PTCR0;       /**< (TC Offset: 0x120) Transfer Control Register (pdc = 0) */
  __I  uint32_t TC_PTSR0;       /**< (TC Offset: 0x124) Transfer Status Register (pdc = 0) */
} Tc;

#elif COMPONENT_TYPEDEF_STYLE == 'N'
/** \brief TC_CHANNEL hardware registers */
typedef struct {  
  __O  TC_CCR_Type                    TC_CCR;         /**< Offset: 0x00 ( /W  32) Channel Control Register (channel = 0) */
  __IO TC_CMR_Type                    TC_CMR;         /**< Offset: 0x04 (R/W  32) Channel Mode Register (channel = 0) */
  __IO TC_SMMR_Type                   TC_SMMR;        /**< Offset: 0x08 (R/W  32) Stepper Motor Mode Register (channel = 0) */
  __I  TC_RAB_Type                    TC_RAB;         /**< Offset: 0x0C (R/   32) Register AB (channel = 0) */
  __I  TC_CV_Type                     TC_CV;          /**< Offset: 0x10 (R/   32) Counter Value (channel = 0) */
  __IO TC_RA_Type                     TC_RA;          /**< Offset: 0x14 (R/W  32) Register A (channel = 0) */
  __IO TC_RB_Type                     TC_RB;          /**< Offset: 0x18 (R/W  32) Register B (channel = 0) */
  __IO TC_RC_Type                     TC_RC;          /**< Offset: 0x1C (R/W  32) Register C (channel = 0) */
  __I  TC_SR_Type                     TC_SR;          /**< Offset: 0x20 (R/   32) Status Register (channel = 0) */
  __O  TC_IER_Type                    TC_IER;         /**< Offset: 0x24 ( /W  32) Interrupt Enable Register (channel = 0) */
  __O  TC_IDR_Type                    TC_IDR;         /**< Offset: 0x28 ( /W  32) Interrupt Disable Register (channel = 0) */
  __I  TC_IMR_Type                    TC_IMR;         /**< Offset: 0x2C (R/   32) Interrupt Mask Register (channel = 0) */
       RoReg8                         Reserved1[0x10];
} TcChannel;

/** \brief TC hardware registers */
typedef struct {  
       TcChannel                      TC_CHANNEL[3];  /**< Offset: 0x00 Channel Control Register (channel = 0) */
  __O  TC_BCR_Type                    TC_BCR;         /**< Offset: 0xC0 ( /W  32) Block Control Register */
  __IO TC_BMR_Type                    TC_BMR;         /**< Offset: 0xC4 (R/W  32) Block Mode Register */
  __I  uint32_t                       Reserved1[7];
  __IO TC_WPMR_Type                   TC_WPMR;        /**< Offset: 0xE4 (R/W  32) Write Protection Mode Register */
  __I  uint32_t                       Reserved2[6];
  __IO TC_RPR0_Type                   TC_RPR0;        /**< Offset: 0x100 (R/W  32) Receive Pointer Register (pdc = 0) */
  __I  uint32_t                       Reserved3[3];
  __IO TC_RNPR0_Type                  TC_RNPR0;       /**< Offset: 0x110 (R/W  32) Receive Next Pointer Register (pdc = 0) */
  __IO TC_RNCR0_Type                  TC_RNCR0;       /**< Offset: 0x114 (R/W  32) Receive Next Counter Register (pdc = 0) */
  __I  uint32_t                       Reserved4[2];
  __O  TC_PTCR0_Type                  TC_PTCR0;       /**< Offset: 0x120 ( /W  32) Transfer Control Register (pdc = 0) */
  __I  TC_PTSR0_Type                  TC_PTSR0;       /**< Offset: 0x124 (R/   32) Transfer Status Register (pdc = 0) */
} Tc;

#else /* COMPONENT_TYPEDEF_STYLE */
#error Unknown component typedef style
#endif /* COMPONENT_TYPEDEF_STYLE */

#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
/** @}  end of Timer Counter */

#endif /* _SAMG55_TC_COMPONENT_H_ */
