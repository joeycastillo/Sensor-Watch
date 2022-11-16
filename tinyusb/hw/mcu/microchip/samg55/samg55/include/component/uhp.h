/**
 * \file
 *
 * \brief Component description for UHP
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
#ifndef _SAMG55_UHP_COMPONENT_H_
#define _SAMG55_UHP_COMPONENT_H_
#define _SAMG55_UHP_COMPONENT_         /**< \deprecated  Backward compatibility for ASF */

/** \addtogroup SAMG_SAMG55 USB Host Port
 *  @{
 */
/* ========================================================================== */
/**  SOFTWARE API DEFINITION FOR UHP */
/* ========================================================================== */
#ifndef COMPONENT_TYPEDEF_STYLE
  #define COMPONENT_TYPEDEF_STYLE 'R'  /**< Defines default style of typedefs for the component header files ('R' = RFO, 'N' = NTO)*/
#endif

#define UHP_6127                       /**< (UHP) Module ID */
#define REV_UHP G                      /**< (UHP) Module revision */

/* -------- UHP_HCREVISION : (UHP Offset: 0x00) (R/ 32) OHCI Revision Number Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t REV:8;                     /**< bit:   0..7  OHCI revision number                     */
    uint32_t :24;                       /**< bit:  8..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_HCREVISION_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_HCREVISION_OFFSET               (0x00)                                        /**<  (UHP_HCREVISION) OHCI Revision Number Register  Offset */

#define UHP_HCREVISION_REV_Pos              0                                              /**< (UHP_HCREVISION) OHCI revision number Position */
#define UHP_HCREVISION_REV_Msk              (_U_(0xFF) << UHP_HCREVISION_REV_Pos)          /**< (UHP_HCREVISION) OHCI revision number Mask */
#define UHP_HCREVISION_REV(value)           (UHP_HCREVISION_REV_Msk & ((value) << UHP_HCREVISION_REV_Pos))
#define UHP_HCREVISION_MASK                 _U_(0xFF)                                      /**< \deprecated (UHP_HCREVISION) Register MASK  (Use UHP_HCREVISION_Msk instead)  */
#define UHP_HCREVISION_Msk                  _U_(0xFF)                                      /**< (UHP_HCREVISION) Register Mask  */


/* -------- UHP_HCCONTROL : (UHP Offset: 0x04) (R/W 32) HC Operating Mode Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t CBSR:2;                    /**< bit:   0..1  Control/bulk service ratio               */
    uint32_t PLE:1;                     /**< bit:      2  Periodic list enable                     */
    uint32_t IE:1;                      /**< bit:      3  Isochronous enable                       */
    uint32_t CLE:1;                     /**< bit:      4  Control list enable                      */
    uint32_t BLE:1;                     /**< bit:      5  Bulk list enable                         */
    uint32_t HCFS:2;                    /**< bit:   6..7  Host controller functional state         */
    uint32_t IR:1;                      /**< bit:      8  Interrupt routing                        */
    uint32_t RWC:1;                     /**< bit:      9  Remote wake-up connected                 */
    uint32_t RWE:1;                     /**< bit:     10  Remote wake-up enable                    */
    uint32_t :21;                       /**< bit: 11..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_HCCONTROL_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_HCCONTROL_OFFSET                (0x04)                                        /**<  (UHP_HCCONTROL) HC Operating Mode Register  Offset */

#define UHP_HCCONTROL_CBSR_Pos              0                                              /**< (UHP_HCCONTROL) Control/bulk service ratio Position */
#define UHP_HCCONTROL_CBSR_Msk              (_U_(0x3) << UHP_HCCONTROL_CBSR_Pos)           /**< (UHP_HCCONTROL) Control/bulk service ratio Mask */
#define UHP_HCCONTROL_CBSR(value)           (UHP_HCCONTROL_CBSR_Msk & ((value) << UHP_HCCONTROL_CBSR_Pos))
#define UHP_HCCONTROL_PLE_Pos               2                                              /**< (UHP_HCCONTROL) Periodic list enable Position */
#define UHP_HCCONTROL_PLE_Msk               (_U_(0x1) << UHP_HCCONTROL_PLE_Pos)            /**< (UHP_HCCONTROL) Periodic list enable Mask */
#define UHP_HCCONTROL_PLE                   UHP_HCCONTROL_PLE_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCCONTROL_PLE_Msk instead */
#define UHP_HCCONTROL_IE_Pos                3                                              /**< (UHP_HCCONTROL) Isochronous enable Position */
#define UHP_HCCONTROL_IE_Msk                (_U_(0x1) << UHP_HCCONTROL_IE_Pos)             /**< (UHP_HCCONTROL) Isochronous enable Mask */
#define UHP_HCCONTROL_IE                    UHP_HCCONTROL_IE_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCCONTROL_IE_Msk instead */
#define UHP_HCCONTROL_CLE_Pos               4                                              /**< (UHP_HCCONTROL) Control list enable Position */
#define UHP_HCCONTROL_CLE_Msk               (_U_(0x1) << UHP_HCCONTROL_CLE_Pos)            /**< (UHP_HCCONTROL) Control list enable Mask */
#define UHP_HCCONTROL_CLE                   UHP_HCCONTROL_CLE_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCCONTROL_CLE_Msk instead */
#define UHP_HCCONTROL_BLE_Pos               5                                              /**< (UHP_HCCONTROL) Bulk list enable Position */
#define UHP_HCCONTROL_BLE_Msk               (_U_(0x1) << UHP_HCCONTROL_BLE_Pos)            /**< (UHP_HCCONTROL) Bulk list enable Mask */
#define UHP_HCCONTROL_BLE                   UHP_HCCONTROL_BLE_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCCONTROL_BLE_Msk instead */
#define UHP_HCCONTROL_HCFS_Pos              6                                              /**< (UHP_HCCONTROL) Host controller functional state Position */
#define UHP_HCCONTROL_HCFS_Msk              (_U_(0x3) << UHP_HCCONTROL_HCFS_Pos)           /**< (UHP_HCCONTROL) Host controller functional state Mask */
#define UHP_HCCONTROL_HCFS(value)           (UHP_HCCONTROL_HCFS_Msk & ((value) << UHP_HCCONTROL_HCFS_Pos))
#define UHP_HCCONTROL_IR_Pos                8                                              /**< (UHP_HCCONTROL) Interrupt routing Position */
#define UHP_HCCONTROL_IR_Msk                (_U_(0x1) << UHP_HCCONTROL_IR_Pos)             /**< (UHP_HCCONTROL) Interrupt routing Mask */
#define UHP_HCCONTROL_IR                    UHP_HCCONTROL_IR_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCCONTROL_IR_Msk instead */
#define UHP_HCCONTROL_RWC_Pos               9                                              /**< (UHP_HCCONTROL) Remote wake-up connected Position */
#define UHP_HCCONTROL_RWC_Msk               (_U_(0x1) << UHP_HCCONTROL_RWC_Pos)            /**< (UHP_HCCONTROL) Remote wake-up connected Mask */
#define UHP_HCCONTROL_RWC                   UHP_HCCONTROL_RWC_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCCONTROL_RWC_Msk instead */
#define UHP_HCCONTROL_RWE_Pos               10                                             /**< (UHP_HCCONTROL) Remote wake-up enable Position */
#define UHP_HCCONTROL_RWE_Msk               (_U_(0x1) << UHP_HCCONTROL_RWE_Pos)            /**< (UHP_HCCONTROL) Remote wake-up enable Mask */
#define UHP_HCCONTROL_RWE                   UHP_HCCONTROL_RWE_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCCONTROL_RWE_Msk instead */
#define UHP_HCCONTROL_MASK                  _U_(0x7FF)                                     /**< \deprecated (UHP_HCCONTROL) Register MASK  (Use UHP_HCCONTROL_Msk instead)  */
#define UHP_HCCONTROL_Msk                   _U_(0x7FF)                                     /**< (UHP_HCCONTROL) Register Mask  */


/* -------- UHP_HCCOMMANDSTATUS : (UHP Offset: 0x08) (R/W 32) HC Command and Status Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t HCR:1;                     /**< bit:      0  Host controller reset (read/write)       */
    uint32_t CLF:1;                     /**< bit:      1  Control list filled (read/write)         */
    uint32_t BLF:1;                     /**< bit:      2  Bulk list filled (read/write)            */
    uint32_t OCR:1;                     /**< bit:      3  Ownership change request (read/write)    */
    uint32_t :12;                       /**< bit:  4..15  Reserved */
    uint32_t SOC:2;                     /**< bit: 16..17  Scheduling overrun count (read-only)     */
    uint32_t :14;                       /**< bit: 18..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_HCCOMMANDSTATUS_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_HCCOMMANDSTATUS_OFFSET          (0x08)                                        /**<  (UHP_HCCOMMANDSTATUS) HC Command and Status Register  Offset */

#define UHP_HCCOMMANDSTATUS_HCR_Pos         0                                              /**< (UHP_HCCOMMANDSTATUS) Host controller reset (read/write) Position */
#define UHP_HCCOMMANDSTATUS_HCR_Msk         (_U_(0x1) << UHP_HCCOMMANDSTATUS_HCR_Pos)      /**< (UHP_HCCOMMANDSTATUS) Host controller reset (read/write) Mask */
#define UHP_HCCOMMANDSTATUS_HCR             UHP_HCCOMMANDSTATUS_HCR_Msk                    /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCCOMMANDSTATUS_HCR_Msk instead */
#define UHP_HCCOMMANDSTATUS_CLF_Pos         1                                              /**< (UHP_HCCOMMANDSTATUS) Control list filled (read/write) Position */
#define UHP_HCCOMMANDSTATUS_CLF_Msk         (_U_(0x1) << UHP_HCCOMMANDSTATUS_CLF_Pos)      /**< (UHP_HCCOMMANDSTATUS) Control list filled (read/write) Mask */
#define UHP_HCCOMMANDSTATUS_CLF             UHP_HCCOMMANDSTATUS_CLF_Msk                    /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCCOMMANDSTATUS_CLF_Msk instead */
#define UHP_HCCOMMANDSTATUS_BLF_Pos         2                                              /**< (UHP_HCCOMMANDSTATUS) Bulk list filled (read/write) Position */
#define UHP_HCCOMMANDSTATUS_BLF_Msk         (_U_(0x1) << UHP_HCCOMMANDSTATUS_BLF_Pos)      /**< (UHP_HCCOMMANDSTATUS) Bulk list filled (read/write) Mask */
#define UHP_HCCOMMANDSTATUS_BLF             UHP_HCCOMMANDSTATUS_BLF_Msk                    /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCCOMMANDSTATUS_BLF_Msk instead */
#define UHP_HCCOMMANDSTATUS_OCR_Pos         3                                              /**< (UHP_HCCOMMANDSTATUS) Ownership change request (read/write) Position */
#define UHP_HCCOMMANDSTATUS_OCR_Msk         (_U_(0x1) << UHP_HCCOMMANDSTATUS_OCR_Pos)      /**< (UHP_HCCOMMANDSTATUS) Ownership change request (read/write) Mask */
#define UHP_HCCOMMANDSTATUS_OCR             UHP_HCCOMMANDSTATUS_OCR_Msk                    /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCCOMMANDSTATUS_OCR_Msk instead */
#define UHP_HCCOMMANDSTATUS_SOC_Pos         16                                             /**< (UHP_HCCOMMANDSTATUS) Scheduling overrun count (read-only) Position */
#define UHP_HCCOMMANDSTATUS_SOC_Msk         (_U_(0x3) << UHP_HCCOMMANDSTATUS_SOC_Pos)      /**< (UHP_HCCOMMANDSTATUS) Scheduling overrun count (read-only) Mask */
#define UHP_HCCOMMANDSTATUS_SOC(value)      (UHP_HCCOMMANDSTATUS_SOC_Msk & ((value) << UHP_HCCOMMANDSTATUS_SOC_Pos))
#define UHP_HCCOMMANDSTATUS_MASK            _U_(0x3000F)                                   /**< \deprecated (UHP_HCCOMMANDSTATUS) Register MASK  (Use UHP_HCCOMMANDSTATUS_Msk instead)  */
#define UHP_HCCOMMANDSTATUS_Msk             _U_(0x3000F)                                   /**< (UHP_HCCOMMANDSTATUS) Register Mask  */


/* -------- UHP_HCINTERRUPTSTATUS : (UHP Offset: 0x0c) (R/W 32) HC Interrupt and Status Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t SO:1;                      /**< bit:      0  Scheduling overrun (read/write, write '1' to clear) */
    uint32_t WDH:1;                     /**< bit:      1  Write done head (read/write, write '1' to clear) */
    uint32_t SF:1;                      /**< bit:      2  Start of frame (read/write, write '1' to clear) */
    uint32_t RD:1;                      /**< bit:      3  Resume detected (read/write, write '1' to clear) */
    uint32_t UE:1;                      /**< bit:      4  Unrecoverable error (read/write, write '1' to clear) */
    uint32_t FNO:1;                     /**< bit:      5  Frame number overflow (read/write, write '1' to clear) */
    uint32_t RHSC:1;                    /**< bit:      6  Root hub status change (read/write, write '1' to clear) */
    uint32_t :23;                       /**< bit:  7..29  Reserved */
    uint32_t OC:1;                      /**< bit:     30  Ownership change (read-only)             */
    uint32_t :1;                        /**< bit:     31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_HCINTERRUPTSTATUS_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_HCINTERRUPTSTATUS_OFFSET        (0x0C)                                        /**<  (UHP_HCINTERRUPTSTATUS) HC Interrupt and Status Register  Offset */

#define UHP_HCINTERRUPTSTATUS_SO_Pos        0                                              /**< (UHP_HCINTERRUPTSTATUS) Scheduling overrun (read/write, write '1' to clear) Position */
#define UHP_HCINTERRUPTSTATUS_SO_Msk        (_U_(0x1) << UHP_HCINTERRUPTSTATUS_SO_Pos)     /**< (UHP_HCINTERRUPTSTATUS) Scheduling overrun (read/write, write '1' to clear) Mask */
#define UHP_HCINTERRUPTSTATUS_SO            UHP_HCINTERRUPTSTATUS_SO_Msk                   /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCINTERRUPTSTATUS_SO_Msk instead */
#define UHP_HCINTERRUPTSTATUS_WDH_Pos       1                                              /**< (UHP_HCINTERRUPTSTATUS) Write done head (read/write, write '1' to clear) Position */
#define UHP_HCINTERRUPTSTATUS_WDH_Msk       (_U_(0x1) << UHP_HCINTERRUPTSTATUS_WDH_Pos)    /**< (UHP_HCINTERRUPTSTATUS) Write done head (read/write, write '1' to clear) Mask */
#define UHP_HCINTERRUPTSTATUS_WDH           UHP_HCINTERRUPTSTATUS_WDH_Msk                  /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCINTERRUPTSTATUS_WDH_Msk instead */
#define UHP_HCINTERRUPTSTATUS_SF_Pos        2                                              /**< (UHP_HCINTERRUPTSTATUS) Start of frame (read/write, write '1' to clear) Position */
#define UHP_HCINTERRUPTSTATUS_SF_Msk        (_U_(0x1) << UHP_HCINTERRUPTSTATUS_SF_Pos)     /**< (UHP_HCINTERRUPTSTATUS) Start of frame (read/write, write '1' to clear) Mask */
#define UHP_HCINTERRUPTSTATUS_SF            UHP_HCINTERRUPTSTATUS_SF_Msk                   /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCINTERRUPTSTATUS_SF_Msk instead */
#define UHP_HCINTERRUPTSTATUS_RD_Pos        3                                              /**< (UHP_HCINTERRUPTSTATUS) Resume detected (read/write, write '1' to clear) Position */
#define UHP_HCINTERRUPTSTATUS_RD_Msk        (_U_(0x1) << UHP_HCINTERRUPTSTATUS_RD_Pos)     /**< (UHP_HCINTERRUPTSTATUS) Resume detected (read/write, write '1' to clear) Mask */
#define UHP_HCINTERRUPTSTATUS_RD            UHP_HCINTERRUPTSTATUS_RD_Msk                   /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCINTERRUPTSTATUS_RD_Msk instead */
#define UHP_HCINTERRUPTSTATUS_UE_Pos        4                                              /**< (UHP_HCINTERRUPTSTATUS) Unrecoverable error (read/write, write '1' to clear) Position */
#define UHP_HCINTERRUPTSTATUS_UE_Msk        (_U_(0x1) << UHP_HCINTERRUPTSTATUS_UE_Pos)     /**< (UHP_HCINTERRUPTSTATUS) Unrecoverable error (read/write, write '1' to clear) Mask */
#define UHP_HCINTERRUPTSTATUS_UE            UHP_HCINTERRUPTSTATUS_UE_Msk                   /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCINTERRUPTSTATUS_UE_Msk instead */
#define UHP_HCINTERRUPTSTATUS_FNO_Pos       5                                              /**< (UHP_HCINTERRUPTSTATUS) Frame number overflow (read/write, write '1' to clear) Position */
#define UHP_HCINTERRUPTSTATUS_FNO_Msk       (_U_(0x1) << UHP_HCINTERRUPTSTATUS_FNO_Pos)    /**< (UHP_HCINTERRUPTSTATUS) Frame number overflow (read/write, write '1' to clear) Mask */
#define UHP_HCINTERRUPTSTATUS_FNO           UHP_HCINTERRUPTSTATUS_FNO_Msk                  /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCINTERRUPTSTATUS_FNO_Msk instead */
#define UHP_HCINTERRUPTSTATUS_RHSC_Pos      6                                              /**< (UHP_HCINTERRUPTSTATUS) Root hub status change (read/write, write '1' to clear) Position */
#define UHP_HCINTERRUPTSTATUS_RHSC_Msk      (_U_(0x1) << UHP_HCINTERRUPTSTATUS_RHSC_Pos)   /**< (UHP_HCINTERRUPTSTATUS) Root hub status change (read/write, write '1' to clear) Mask */
#define UHP_HCINTERRUPTSTATUS_RHSC          UHP_HCINTERRUPTSTATUS_RHSC_Msk                 /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCINTERRUPTSTATUS_RHSC_Msk instead */
#define UHP_HCINTERRUPTSTATUS_OC_Pos        30                                             /**< (UHP_HCINTERRUPTSTATUS) Ownership change (read-only) Position */
#define UHP_HCINTERRUPTSTATUS_OC_Msk        (_U_(0x1) << UHP_HCINTERRUPTSTATUS_OC_Pos)     /**< (UHP_HCINTERRUPTSTATUS) Ownership change (read-only) Mask */
#define UHP_HCINTERRUPTSTATUS_OC            UHP_HCINTERRUPTSTATUS_OC_Msk                   /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCINTERRUPTSTATUS_OC_Msk instead */
#define UHP_HCINTERRUPTSTATUS_MASK          _U_(0x4000007F)                                /**< \deprecated (UHP_HCINTERRUPTSTATUS) Register MASK  (Use UHP_HCINTERRUPTSTATUS_Msk instead)  */
#define UHP_HCINTERRUPTSTATUS_Msk           _U_(0x4000007F)                                /**< (UHP_HCINTERRUPTSTATUS) Register Mask  */


/* -------- UHP_HCINTERRUPTENABLE : (UHP Offset: 0x10) (R/W 32) HC Interrupt Enable Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t SO:1;                      /**< bit:      0  Scheduling overrun (read/write, write '1' to set) */
    uint32_t WDH:1;                     /**< bit:      1  Write done head (read/write, write '1' to set) */
    uint32_t SF:1;                      /**< bit:      2  Start of frame (read/write, write '1' to set) */
    uint32_t RD:1;                      /**< bit:      3  Resume detected (read/write, write '1' to set) */
    uint32_t UE:1;                      /**< bit:      4  Unrecoverable error (read/write, write '1' to set) */
    uint32_t FNO:1;                     /**< bit:      5  Frame number overflow (read/write, write '1' to set) */
    uint32_t RHSC:1;                    /**< bit:      6  Root hub status change (read/write, write '1' to set) */
    uint32_t :23;                       /**< bit:  7..29  Reserved */
    uint32_t OC:1;                      /**< bit:     30  Ownership change (read-only)             */
    uint32_t MIE:1;                     /**< bit:     31  Master interrupt enable (read/write, write '1' to set) */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_HCINTERRUPTENABLE_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_HCINTERRUPTENABLE_OFFSET        (0x10)                                        /**<  (UHP_HCINTERRUPTENABLE) HC Interrupt Enable Register  Offset */

#define UHP_HCINTERRUPTENABLE_SO_Pos        0                                              /**< (UHP_HCINTERRUPTENABLE) Scheduling overrun (read/write, write '1' to set) Position */
#define UHP_HCINTERRUPTENABLE_SO_Msk        (_U_(0x1) << UHP_HCINTERRUPTENABLE_SO_Pos)     /**< (UHP_HCINTERRUPTENABLE) Scheduling overrun (read/write, write '1' to set) Mask */
#define UHP_HCINTERRUPTENABLE_SO            UHP_HCINTERRUPTENABLE_SO_Msk                   /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCINTERRUPTENABLE_SO_Msk instead */
#define UHP_HCINTERRUPTENABLE_WDH_Pos       1                                              /**< (UHP_HCINTERRUPTENABLE) Write done head (read/write, write '1' to set) Position */
#define UHP_HCINTERRUPTENABLE_WDH_Msk       (_U_(0x1) << UHP_HCINTERRUPTENABLE_WDH_Pos)    /**< (UHP_HCINTERRUPTENABLE) Write done head (read/write, write '1' to set) Mask */
#define UHP_HCINTERRUPTENABLE_WDH           UHP_HCINTERRUPTENABLE_WDH_Msk                  /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCINTERRUPTENABLE_WDH_Msk instead */
#define UHP_HCINTERRUPTENABLE_SF_Pos        2                                              /**< (UHP_HCINTERRUPTENABLE) Start of frame (read/write, write '1' to set) Position */
#define UHP_HCINTERRUPTENABLE_SF_Msk        (_U_(0x1) << UHP_HCINTERRUPTENABLE_SF_Pos)     /**< (UHP_HCINTERRUPTENABLE) Start of frame (read/write, write '1' to set) Mask */
#define UHP_HCINTERRUPTENABLE_SF            UHP_HCINTERRUPTENABLE_SF_Msk                   /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCINTERRUPTENABLE_SF_Msk instead */
#define UHP_HCINTERRUPTENABLE_RD_Pos        3                                              /**< (UHP_HCINTERRUPTENABLE) Resume detected (read/write, write '1' to set) Position */
#define UHP_HCINTERRUPTENABLE_RD_Msk        (_U_(0x1) << UHP_HCINTERRUPTENABLE_RD_Pos)     /**< (UHP_HCINTERRUPTENABLE) Resume detected (read/write, write '1' to set) Mask */
#define UHP_HCINTERRUPTENABLE_RD            UHP_HCINTERRUPTENABLE_RD_Msk                   /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCINTERRUPTENABLE_RD_Msk instead */
#define UHP_HCINTERRUPTENABLE_UE_Pos        4                                              /**< (UHP_HCINTERRUPTENABLE) Unrecoverable error (read/write, write '1' to set) Position */
#define UHP_HCINTERRUPTENABLE_UE_Msk        (_U_(0x1) << UHP_HCINTERRUPTENABLE_UE_Pos)     /**< (UHP_HCINTERRUPTENABLE) Unrecoverable error (read/write, write '1' to set) Mask */
#define UHP_HCINTERRUPTENABLE_UE            UHP_HCINTERRUPTENABLE_UE_Msk                   /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCINTERRUPTENABLE_UE_Msk instead */
#define UHP_HCINTERRUPTENABLE_FNO_Pos       5                                              /**< (UHP_HCINTERRUPTENABLE) Frame number overflow (read/write, write '1' to set) Position */
#define UHP_HCINTERRUPTENABLE_FNO_Msk       (_U_(0x1) << UHP_HCINTERRUPTENABLE_FNO_Pos)    /**< (UHP_HCINTERRUPTENABLE) Frame number overflow (read/write, write '1' to set) Mask */
#define UHP_HCINTERRUPTENABLE_FNO           UHP_HCINTERRUPTENABLE_FNO_Msk                  /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCINTERRUPTENABLE_FNO_Msk instead */
#define UHP_HCINTERRUPTENABLE_RHSC_Pos      6                                              /**< (UHP_HCINTERRUPTENABLE) Root hub status change (read/write, write '1' to set) Position */
#define UHP_HCINTERRUPTENABLE_RHSC_Msk      (_U_(0x1) << UHP_HCINTERRUPTENABLE_RHSC_Pos)   /**< (UHP_HCINTERRUPTENABLE) Root hub status change (read/write, write '1' to set) Mask */
#define UHP_HCINTERRUPTENABLE_RHSC          UHP_HCINTERRUPTENABLE_RHSC_Msk                 /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCINTERRUPTENABLE_RHSC_Msk instead */
#define UHP_HCINTERRUPTENABLE_OC_Pos        30                                             /**< (UHP_HCINTERRUPTENABLE) Ownership change (read-only) Position */
#define UHP_HCINTERRUPTENABLE_OC_Msk        (_U_(0x1) << UHP_HCINTERRUPTENABLE_OC_Pos)     /**< (UHP_HCINTERRUPTENABLE) Ownership change (read-only) Mask */
#define UHP_HCINTERRUPTENABLE_OC            UHP_HCINTERRUPTENABLE_OC_Msk                   /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCINTERRUPTENABLE_OC_Msk instead */
#define UHP_HCINTERRUPTENABLE_MIE_Pos       31                                             /**< (UHP_HCINTERRUPTENABLE) Master interrupt enable (read/write, write '1' to set) Position */
#define UHP_HCINTERRUPTENABLE_MIE_Msk       (_U_(0x1) << UHP_HCINTERRUPTENABLE_MIE_Pos)    /**< (UHP_HCINTERRUPTENABLE) Master interrupt enable (read/write, write '1' to set) Mask */
#define UHP_HCINTERRUPTENABLE_MIE           UHP_HCINTERRUPTENABLE_MIE_Msk                  /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCINTERRUPTENABLE_MIE_Msk instead */
#define UHP_HCINTERRUPTENABLE_MASK          _U_(0xC000007F)                                /**< \deprecated (UHP_HCINTERRUPTENABLE) Register MASK  (Use UHP_HCINTERRUPTENABLE_Msk instead)  */
#define UHP_HCINTERRUPTENABLE_Msk           _U_(0xC000007F)                                /**< (UHP_HCINTERRUPTENABLE) Register Mask  */


/* -------- UHP_HCINTERRUPTDISABLE : (UHP Offset: 0x14) (R/W 32) HC Interrupt Disable Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t SO:1;                      /**< bit:      0  Scheduling overrun (read/write)          */
    uint32_t WDH:1;                     /**< bit:      1  Write done head (read/write)             */
    uint32_t SF:1;                      /**< bit:      2  Start of frame (read/write)              */
    uint32_t RD:1;                      /**< bit:      3  Resume detected (read/write)             */
    uint32_t UE:1;                      /**< bit:      4  Unrecoverable error (read/write)         */
    uint32_t FNO:1;                     /**< bit:      5  Frame number overflow (read/write)       */
    uint32_t RHSC:1;                    /**< bit:      6  Root hub status change (read/write)      */
    uint32_t :23;                       /**< bit:  7..29  Reserved */
    uint32_t OC:1;                      /**< bit:     30  Ownership change (read-only)             */
    uint32_t MIE:1;                     /**< bit:     31  Master interrupt enable (read/write)     */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_HCINTERRUPTDISABLE_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_HCINTERRUPTDISABLE_OFFSET       (0x14)                                        /**<  (UHP_HCINTERRUPTDISABLE) HC Interrupt Disable Register  Offset */

#define UHP_HCINTERRUPTDISABLE_SO_Pos       0                                              /**< (UHP_HCINTERRUPTDISABLE) Scheduling overrun (read/write) Position */
#define UHP_HCINTERRUPTDISABLE_SO_Msk       (_U_(0x1) << UHP_HCINTERRUPTDISABLE_SO_Pos)    /**< (UHP_HCINTERRUPTDISABLE) Scheduling overrun (read/write) Mask */
#define UHP_HCINTERRUPTDISABLE_SO           UHP_HCINTERRUPTDISABLE_SO_Msk                  /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCINTERRUPTDISABLE_SO_Msk instead */
#define UHP_HCINTERRUPTDISABLE_WDH_Pos      1                                              /**< (UHP_HCINTERRUPTDISABLE) Write done head (read/write) Position */
#define UHP_HCINTERRUPTDISABLE_WDH_Msk      (_U_(0x1) << UHP_HCINTERRUPTDISABLE_WDH_Pos)   /**< (UHP_HCINTERRUPTDISABLE) Write done head (read/write) Mask */
#define UHP_HCINTERRUPTDISABLE_WDH          UHP_HCINTERRUPTDISABLE_WDH_Msk                 /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCINTERRUPTDISABLE_WDH_Msk instead */
#define UHP_HCINTERRUPTDISABLE_SF_Pos       2                                              /**< (UHP_HCINTERRUPTDISABLE) Start of frame (read/write) Position */
#define UHP_HCINTERRUPTDISABLE_SF_Msk       (_U_(0x1) << UHP_HCINTERRUPTDISABLE_SF_Pos)    /**< (UHP_HCINTERRUPTDISABLE) Start of frame (read/write) Mask */
#define UHP_HCINTERRUPTDISABLE_SF           UHP_HCINTERRUPTDISABLE_SF_Msk                  /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCINTERRUPTDISABLE_SF_Msk instead */
#define UHP_HCINTERRUPTDISABLE_RD_Pos       3                                              /**< (UHP_HCINTERRUPTDISABLE) Resume detected (read/write) Position */
#define UHP_HCINTERRUPTDISABLE_RD_Msk       (_U_(0x1) << UHP_HCINTERRUPTDISABLE_RD_Pos)    /**< (UHP_HCINTERRUPTDISABLE) Resume detected (read/write) Mask */
#define UHP_HCINTERRUPTDISABLE_RD           UHP_HCINTERRUPTDISABLE_RD_Msk                  /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCINTERRUPTDISABLE_RD_Msk instead */
#define UHP_HCINTERRUPTDISABLE_UE_Pos       4                                              /**< (UHP_HCINTERRUPTDISABLE) Unrecoverable error (read/write) Position */
#define UHP_HCINTERRUPTDISABLE_UE_Msk       (_U_(0x1) << UHP_HCINTERRUPTDISABLE_UE_Pos)    /**< (UHP_HCINTERRUPTDISABLE) Unrecoverable error (read/write) Mask */
#define UHP_HCINTERRUPTDISABLE_UE           UHP_HCINTERRUPTDISABLE_UE_Msk                  /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCINTERRUPTDISABLE_UE_Msk instead */
#define UHP_HCINTERRUPTDISABLE_FNO_Pos      5                                              /**< (UHP_HCINTERRUPTDISABLE) Frame number overflow (read/write) Position */
#define UHP_HCINTERRUPTDISABLE_FNO_Msk      (_U_(0x1) << UHP_HCINTERRUPTDISABLE_FNO_Pos)   /**< (UHP_HCINTERRUPTDISABLE) Frame number overflow (read/write) Mask */
#define UHP_HCINTERRUPTDISABLE_FNO          UHP_HCINTERRUPTDISABLE_FNO_Msk                 /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCINTERRUPTDISABLE_FNO_Msk instead */
#define UHP_HCINTERRUPTDISABLE_RHSC_Pos     6                                              /**< (UHP_HCINTERRUPTDISABLE) Root hub status change (read/write) Position */
#define UHP_HCINTERRUPTDISABLE_RHSC_Msk     (_U_(0x1) << UHP_HCINTERRUPTDISABLE_RHSC_Pos)  /**< (UHP_HCINTERRUPTDISABLE) Root hub status change (read/write) Mask */
#define UHP_HCINTERRUPTDISABLE_RHSC         UHP_HCINTERRUPTDISABLE_RHSC_Msk                /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCINTERRUPTDISABLE_RHSC_Msk instead */
#define UHP_HCINTERRUPTDISABLE_OC_Pos       30                                             /**< (UHP_HCINTERRUPTDISABLE) Ownership change (read-only) Position */
#define UHP_HCINTERRUPTDISABLE_OC_Msk       (_U_(0x1) << UHP_HCINTERRUPTDISABLE_OC_Pos)    /**< (UHP_HCINTERRUPTDISABLE) Ownership change (read-only) Mask */
#define UHP_HCINTERRUPTDISABLE_OC           UHP_HCINTERRUPTDISABLE_OC_Msk                  /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCINTERRUPTDISABLE_OC_Msk instead */
#define UHP_HCINTERRUPTDISABLE_MIE_Pos      31                                             /**< (UHP_HCINTERRUPTDISABLE) Master interrupt enable (read/write) Position */
#define UHP_HCINTERRUPTDISABLE_MIE_Msk      (_U_(0x1) << UHP_HCINTERRUPTDISABLE_MIE_Pos)   /**< (UHP_HCINTERRUPTDISABLE) Master interrupt enable (read/write) Mask */
#define UHP_HCINTERRUPTDISABLE_MIE          UHP_HCINTERRUPTDISABLE_MIE_Msk                 /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCINTERRUPTDISABLE_MIE_Msk instead */
#define UHP_HCINTERRUPTDISABLE_MASK         _U_(0xC000007F)                                /**< \deprecated (UHP_HCINTERRUPTDISABLE) Register MASK  (Use UHP_HCINTERRUPTDISABLE_Msk instead)  */
#define UHP_HCINTERRUPTDISABLE_Msk          _U_(0xC000007F)                                /**< (UHP_HCINTERRUPTDISABLE) Register Mask  */


/* -------- UHP_HCHCCA : (UHP Offset: 0x18) (R/W 32) HC HCCA Address Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t :8;                        /**< bit:   0..7  Reserved */
    uint32_t HCCA:24;                   /**< bit:  8..31  Physical address of the beginning of the HCCA */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_HCHCCA_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_HCHCCA_OFFSET                   (0x18)                                        /**<  (UHP_HCHCCA) HC HCCA Address Register  Offset */

#define UHP_HCHCCA_HCCA_Pos                 8                                              /**< (UHP_HCHCCA) Physical address of the beginning of the HCCA Position */
#define UHP_HCHCCA_HCCA_Msk                 (_U_(0xFFFFFF) << UHP_HCHCCA_HCCA_Pos)         /**< (UHP_HCHCCA) Physical address of the beginning of the HCCA Mask */
#define UHP_HCHCCA_HCCA(value)              (UHP_HCHCCA_HCCA_Msk & ((value) << UHP_HCHCCA_HCCA_Pos))
#define UHP_HCHCCA_MASK                     _U_(0xFFFFFF00)                                /**< \deprecated (UHP_HCHCCA) Register MASK  (Use UHP_HCHCCA_Msk instead)  */
#define UHP_HCHCCA_Msk                      _U_(0xFFFFFF00)                                /**< (UHP_HCHCCA) Register Mask  */


/* -------- UHP_HCPERIODCURRENTED : (UHP Offset: 0x1c) (R/ 32) HC Current Periodic Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t :4;                        /**< bit:   0..3  Reserved */
    uint32_t PCED:28;                   /**< bit:  4..31  Physical address of the current ED on the periodic ED list */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_HCPERIODCURRENTED_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_HCPERIODCURRENTED_OFFSET        (0x1C)                                        /**<  (UHP_HCPERIODCURRENTED) HC Current Periodic Register  Offset */

#define UHP_HCPERIODCURRENTED_PCED_Pos      4                                              /**< (UHP_HCPERIODCURRENTED) Physical address of the current ED on the periodic ED list Position */
#define UHP_HCPERIODCURRENTED_PCED_Msk      (_U_(0xFFFFFFF) << UHP_HCPERIODCURRENTED_PCED_Pos)  /**< (UHP_HCPERIODCURRENTED) Physical address of the current ED on the periodic ED list Mask */
#define UHP_HCPERIODCURRENTED_PCED(value)   (UHP_HCPERIODCURRENTED_PCED_Msk & ((value) << UHP_HCPERIODCURRENTED_PCED_Pos))
#define UHP_HCPERIODCURRENTED_MASK          _U_(0xFFFFFFF0)                                /**< \deprecated (UHP_HCPERIODCURRENTED) Register MASK  (Use UHP_HCPERIODCURRENTED_Msk instead)  */
#define UHP_HCPERIODCURRENTED_Msk           _U_(0xFFFFFFF0)                                /**< (UHP_HCPERIODCURRENTED) Register Mask  */


/* -------- UHP_HCCONTROLHEADED : (UHP Offset: 0x20) (R/W 32) HC Head Control Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t :4;                        /**< bit:   0..3  Reserved */
    uint32_t CHED:28;                   /**< bit:  4..31  Physical address of the head ED on the control ED list */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_HCCONTROLHEADED_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_HCCONTROLHEADED_OFFSET          (0x20)                                        /**<  (UHP_HCCONTROLHEADED) HC Head Control Register  Offset */

#define UHP_HCCONTROLHEADED_CHED_Pos        4                                              /**< (UHP_HCCONTROLHEADED) Physical address of the head ED on the control ED list Position */
#define UHP_HCCONTROLHEADED_CHED_Msk        (_U_(0xFFFFFFF) << UHP_HCCONTROLHEADED_CHED_Pos)  /**< (UHP_HCCONTROLHEADED) Physical address of the head ED on the control ED list Mask */
#define UHP_HCCONTROLHEADED_CHED(value)     (UHP_HCCONTROLHEADED_CHED_Msk & ((value) << UHP_HCCONTROLHEADED_CHED_Pos))
#define UHP_HCCONTROLHEADED_MASK            _U_(0xFFFFFFF0)                                /**< \deprecated (UHP_HCCONTROLHEADED) Register MASK  (Use UHP_HCCONTROLHEADED_Msk instead)  */
#define UHP_HCCONTROLHEADED_Msk             _U_(0xFFFFFFF0)                                /**< (UHP_HCCONTROLHEADED) Register Mask  */


/* -------- UHP_HCCONTROLCURRENTED : (UHP Offset: 0x24) (R/W 32) HC Current Control Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t :4;                        /**< bit:   0..3  Reserved */
    uint32_t CCED:28;                   /**< bit:  4..31  Physical address of the current ED on the control ED list */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_HCCONTROLCURRENTED_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_HCCONTROLCURRENTED_OFFSET       (0x24)                                        /**<  (UHP_HCCONTROLCURRENTED) HC Current Control Register  Offset */

#define UHP_HCCONTROLCURRENTED_CCED_Pos     4                                              /**< (UHP_HCCONTROLCURRENTED) Physical address of the current ED on the control ED list Position */
#define UHP_HCCONTROLCURRENTED_CCED_Msk     (_U_(0xFFFFFFF) << UHP_HCCONTROLCURRENTED_CCED_Pos)  /**< (UHP_HCCONTROLCURRENTED) Physical address of the current ED on the control ED list Mask */
#define UHP_HCCONTROLCURRENTED_CCED(value)  (UHP_HCCONTROLCURRENTED_CCED_Msk & ((value) << UHP_HCCONTROLCURRENTED_CCED_Pos))
#define UHP_HCCONTROLCURRENTED_MASK         _U_(0xFFFFFFF0)                                /**< \deprecated (UHP_HCCONTROLCURRENTED) Register MASK  (Use UHP_HCCONTROLCURRENTED_Msk instead)  */
#define UHP_HCCONTROLCURRENTED_Msk          _U_(0xFFFFFFF0)                                /**< (UHP_HCCONTROLCURRENTED) Register Mask  */


/* -------- UHP_HCBULKHEADED : (UHP Offset: 0x28) (R/W 32) HC Head Bulk Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t :4;                        /**< bit:   0..3  Reserved */
    uint32_t BHED:28;                   /**< bit:  4..31  Physical address of the head ED on the bulk ED list */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_HCBULKHEADED_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_HCBULKHEADED_OFFSET             (0x28)                                        /**<  (UHP_HCBULKHEADED) HC Head Bulk Register  Offset */

#define UHP_HCBULKHEADED_BHED_Pos           4                                              /**< (UHP_HCBULKHEADED) Physical address of the head ED on the bulk ED list Position */
#define UHP_HCBULKHEADED_BHED_Msk           (_U_(0xFFFFFFF) << UHP_HCBULKHEADED_BHED_Pos)  /**< (UHP_HCBULKHEADED) Physical address of the head ED on the bulk ED list Mask */
#define UHP_HCBULKHEADED_BHED(value)        (UHP_HCBULKHEADED_BHED_Msk & ((value) << UHP_HCBULKHEADED_BHED_Pos))
#define UHP_HCBULKHEADED_MASK               _U_(0xFFFFFFF0)                                /**< \deprecated (UHP_HCBULKHEADED) Register MASK  (Use UHP_HCBULKHEADED_Msk instead)  */
#define UHP_HCBULKHEADED_Msk                _U_(0xFFFFFFF0)                                /**< (UHP_HCBULKHEADED) Register Mask  */


/* -------- UHP_HCBULKCURRENTED : (UHP Offset: 0x2c) (R/W 32) HC Current Bulk Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t :4;                        /**< bit:   0..3  Reserved */
    uint32_t BCED:28;                   /**< bit:  4..31  Physical address of the current ED on the bulk ED list */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_HCBULKCURRENTED_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_HCBULKCURRENTED_OFFSET          (0x2C)                                        /**<  (UHP_HCBULKCURRENTED) HC Current Bulk Register  Offset */

#define UHP_HCBULKCURRENTED_BCED_Pos        4                                              /**< (UHP_HCBULKCURRENTED) Physical address of the current ED on the bulk ED list Position */
#define UHP_HCBULKCURRENTED_BCED_Msk        (_U_(0xFFFFFFF) << UHP_HCBULKCURRENTED_BCED_Pos)  /**< (UHP_HCBULKCURRENTED) Physical address of the current ED on the bulk ED list Mask */
#define UHP_HCBULKCURRENTED_BCED(value)     (UHP_HCBULKCURRENTED_BCED_Msk & ((value) << UHP_HCBULKCURRENTED_BCED_Pos))
#define UHP_HCBULKCURRENTED_MASK            _U_(0xFFFFFFF0)                                /**< \deprecated (UHP_HCBULKCURRENTED) Register MASK  (Use UHP_HCBULKCURRENTED_Msk instead)  */
#define UHP_HCBULKCURRENTED_Msk             _U_(0xFFFFFFF0)                                /**< (UHP_HCBULKCURRENTED) Register Mask  */


/* -------- UHP_HCDONEHEAD : (UHP Offset: 0x30) (R/ 32) HC Head Done Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t :4;                        /**< bit:   0..3  Reserved */
    uint32_t DH:28;                     /**< bit:  4..31  Physical address of the last TD that has added to the done queue */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_HCDONEHEAD_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_HCDONEHEAD_OFFSET               (0x30)                                        /**<  (UHP_HCDONEHEAD) HC Head Done Register  Offset */

#define UHP_HCDONEHEAD_DH_Pos               4                                              /**< (UHP_HCDONEHEAD) Physical address of the last TD that has added to the done queue Position */
#define UHP_HCDONEHEAD_DH_Msk               (_U_(0xFFFFFFF) << UHP_HCDONEHEAD_DH_Pos)      /**< (UHP_HCDONEHEAD) Physical address of the last TD that has added to the done queue Mask */
#define UHP_HCDONEHEAD_DH(value)            (UHP_HCDONEHEAD_DH_Msk & ((value) << UHP_HCDONEHEAD_DH_Pos))
#define UHP_HCDONEHEAD_MASK                 _U_(0xFFFFFFF0)                                /**< \deprecated (UHP_HCDONEHEAD) Register MASK  (Use UHP_HCDONEHEAD_Msk instead)  */
#define UHP_HCDONEHEAD_Msk                  _U_(0xFFFFFFF0)                                /**< (UHP_HCDONEHEAD) Register Mask  */


/* -------- UHP_HCFMINTERVAL : (UHP Offset: 0x34) (R/W 32) HC Frame Interval Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t FRAMEINTERVAL:14;          /**< bit:  0..13  Frame interval                           */
    uint32_t :2;                        /**< bit: 14..15  Reserved */
    uint32_t FSMPS:15;                  /**< bit: 16..30  Largest data packet                      */
    uint32_t FIT:1;                     /**< bit:     31  Frame interval toggle                    */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_HCFMINTERVAL_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_HCFMINTERVAL_OFFSET             (0x34)                                        /**<  (UHP_HCFMINTERVAL) HC Frame Interval Register  Offset */

#define UHP_HCFMINTERVAL_FRAMEINTERVAL_Pos  0                                              /**< (UHP_HCFMINTERVAL) Frame interval Position */
#define UHP_HCFMINTERVAL_FRAMEINTERVAL_Msk  (_U_(0x3FFF) << UHP_HCFMINTERVAL_FRAMEINTERVAL_Pos)  /**< (UHP_HCFMINTERVAL) Frame interval Mask */
#define UHP_HCFMINTERVAL_FRAMEINTERVAL(value) (UHP_HCFMINTERVAL_FRAMEINTERVAL_Msk & ((value) << UHP_HCFMINTERVAL_FRAMEINTERVAL_Pos))
#define UHP_HCFMINTERVAL_FSMPS_Pos          16                                             /**< (UHP_HCFMINTERVAL) Largest data packet Position */
#define UHP_HCFMINTERVAL_FSMPS_Msk          (_U_(0x7FFF) << UHP_HCFMINTERVAL_FSMPS_Pos)    /**< (UHP_HCFMINTERVAL) Largest data packet Mask */
#define UHP_HCFMINTERVAL_FSMPS(value)       (UHP_HCFMINTERVAL_FSMPS_Msk & ((value) << UHP_HCFMINTERVAL_FSMPS_Pos))
#define UHP_HCFMINTERVAL_FIT_Pos            31                                             /**< (UHP_HCFMINTERVAL) Frame interval toggle Position */
#define UHP_HCFMINTERVAL_FIT_Msk            (_U_(0x1) << UHP_HCFMINTERVAL_FIT_Pos)         /**< (UHP_HCFMINTERVAL) Frame interval toggle Mask */
#define UHP_HCFMINTERVAL_FIT                UHP_HCFMINTERVAL_FIT_Msk                       /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCFMINTERVAL_FIT_Msk instead */
#define UHP_HCFMINTERVAL_MASK               _U_(0xFFFF3FFF)                                /**< \deprecated (UHP_HCFMINTERVAL) Register MASK  (Use UHP_HCFMINTERVAL_Msk instead)  */
#define UHP_HCFMINTERVAL_Msk                _U_(0xFFFF3FFF)                                /**< (UHP_HCFMINTERVAL) Register Mask  */


/* -------- UHP_HCFMREMAINING : (UHP Offset: 0x38) (R/ 32) HC Frame Remaining Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t FR:14;                     /**< bit:  0..13  Frame remaining                          */
    uint32_t :17;                       /**< bit: 14..30  Reserved */
    uint32_t FRT:1;                     /**< bit:     31  Frame remaining toggle                   */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_HCFMREMAINING_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_HCFMREMAINING_OFFSET            (0x38)                                        /**<  (UHP_HCFMREMAINING) HC Frame Remaining Register  Offset */

#define UHP_HCFMREMAINING_FR_Pos            0                                              /**< (UHP_HCFMREMAINING) Frame remaining Position */
#define UHP_HCFMREMAINING_FR_Msk            (_U_(0x3FFF) << UHP_HCFMREMAINING_FR_Pos)      /**< (UHP_HCFMREMAINING) Frame remaining Mask */
#define UHP_HCFMREMAINING_FR(value)         (UHP_HCFMREMAINING_FR_Msk & ((value) << UHP_HCFMREMAINING_FR_Pos))
#define UHP_HCFMREMAINING_FRT_Pos           31                                             /**< (UHP_HCFMREMAINING) Frame remaining toggle Position */
#define UHP_HCFMREMAINING_FRT_Msk           (_U_(0x1) << UHP_HCFMREMAINING_FRT_Pos)        /**< (UHP_HCFMREMAINING) Frame remaining toggle Mask */
#define UHP_HCFMREMAINING_FRT               UHP_HCFMREMAINING_FRT_Msk                      /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCFMREMAINING_FRT_Msk instead */
#define UHP_HCFMREMAINING_MASK              _U_(0x80003FFF)                                /**< \deprecated (UHP_HCFMREMAINING) Register MASK  (Use UHP_HCFMREMAINING_Msk instead)  */
#define UHP_HCFMREMAINING_Msk               _U_(0x80003FFF)                                /**< (UHP_HCFMREMAINING) Register Mask  */


/* -------- UHP_HCFMNUMBER : (UHP Offset: 0x3c) (R/ 32) HC Frame Number Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t FN:16;                     /**< bit:  0..15  Frame number                             */
    uint32_t :16;                       /**< bit: 16..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_HCFMNUMBER_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_HCFMNUMBER_OFFSET               (0x3C)                                        /**<  (UHP_HCFMNUMBER) HC Frame Number Register  Offset */

#define UHP_HCFMNUMBER_FN_Pos               0                                              /**< (UHP_HCFMNUMBER) Frame number Position */
#define UHP_HCFMNUMBER_FN_Msk               (_U_(0xFFFF) << UHP_HCFMNUMBER_FN_Pos)         /**< (UHP_HCFMNUMBER) Frame number Mask */
#define UHP_HCFMNUMBER_FN(value)            (UHP_HCFMNUMBER_FN_Msk & ((value) << UHP_HCFMNUMBER_FN_Pos))
#define UHP_HCFMNUMBER_MASK                 _U_(0xFFFF)                                    /**< \deprecated (UHP_HCFMNUMBER) Register MASK  (Use UHP_HCFMNUMBER_Msk instead)  */
#define UHP_HCFMNUMBER_Msk                  _U_(0xFFFF)                                    /**< (UHP_HCFMNUMBER) Register Mask  */


/* -------- UHP_HCPERIODICSTART : (UHP Offset: 0x40) (R/W 32) HC Periodic Start Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t PS:14;                     /**< bit:  0..13  Periodic start                           */
    uint32_t :18;                       /**< bit: 14..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_HCPERIODICSTART_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_HCPERIODICSTART_OFFSET          (0x40)                                        /**<  (UHP_HCPERIODICSTART) HC Periodic Start Register  Offset */

#define UHP_HCPERIODICSTART_PS_Pos          0                                              /**< (UHP_HCPERIODICSTART) Periodic start Position */
#define UHP_HCPERIODICSTART_PS_Msk          (_U_(0x3FFF) << UHP_HCPERIODICSTART_PS_Pos)    /**< (UHP_HCPERIODICSTART) Periodic start Mask */
#define UHP_HCPERIODICSTART_PS(value)       (UHP_HCPERIODICSTART_PS_Msk & ((value) << UHP_HCPERIODICSTART_PS_Pos))
#define UHP_HCPERIODICSTART_MASK            _U_(0x3FFF)                                    /**< \deprecated (UHP_HCPERIODICSTART) Register MASK  (Use UHP_HCPERIODICSTART_Msk instead)  */
#define UHP_HCPERIODICSTART_Msk             _U_(0x3FFF)                                    /**< (UHP_HCPERIODICSTART) Register Mask  */


/* -------- UHP_HCLSTHRESHOLD : (UHP Offset: 0x44) (R/W 32) HC Low-Speed Threshold Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t LST:14;                    /**< bit:  0..13  Low-speed threshold                      */
    uint32_t :18;                       /**< bit: 14..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_HCLSTHRESHOLD_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_HCLSTHRESHOLD_OFFSET            (0x44)                                        /**<  (UHP_HCLSTHRESHOLD) HC Low-Speed Threshold Register  Offset */

#define UHP_HCLSTHRESHOLD_LST_Pos           0                                              /**< (UHP_HCLSTHRESHOLD) Low-speed threshold Position */
#define UHP_HCLSTHRESHOLD_LST_Msk           (_U_(0x3FFF) << UHP_HCLSTHRESHOLD_LST_Pos)     /**< (UHP_HCLSTHRESHOLD) Low-speed threshold Mask */
#define UHP_HCLSTHRESHOLD_LST(value)        (UHP_HCLSTHRESHOLD_LST_Msk & ((value) << UHP_HCLSTHRESHOLD_LST_Pos))
#define UHP_HCLSTHRESHOLD_MASK              _U_(0x3FFF)                                    /**< \deprecated (UHP_HCLSTHRESHOLD) Register MASK  (Use UHP_HCLSTHRESHOLD_Msk instead)  */
#define UHP_HCLSTHRESHOLD_Msk               _U_(0x3FFF)                                    /**< (UHP_HCLSTHRESHOLD) Register Mask  */


/* -------- UHP_HCRHDESCRIPTORA : (UHP Offset: 0x48) (R/W 32) HC Root Hub A Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t NDP:8;                     /**< bit:   0..7  Number of downstream ports (read-only)   */
    uint32_t PSM:1;                     /**< bit:      8  Power switching mode (read/write)        */
    uint32_t NPS:1;                     /**< bit:      9  No power switching (read/write)          */
    uint32_t DT:1;                      /**< bit:     10  Device type (read-only)                  */
    uint32_t OCPM:1;                    /**< bit:     11  Overcurrent protection mode (read/write) */
    uint32_t NOCP:1;                    /**< bit:     12  No overcurrent protection (read/write)   */
    uint32_t :11;                       /**< bit: 13..23  Reserved */
    uint32_t POTPG:8;                   /**< bit: 24..31  Power-on to power-good time (read/write) */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_HCRHDESCRIPTORA_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_HCRHDESCRIPTORA_OFFSET          (0x48)                                        /**<  (UHP_HCRHDESCRIPTORA) HC Root Hub A Register  Offset */

#define UHP_HCRHDESCRIPTORA_NDP_Pos         0                                              /**< (UHP_HCRHDESCRIPTORA) Number of downstream ports (read-only) Position */
#define UHP_HCRHDESCRIPTORA_NDP_Msk         (_U_(0xFF) << UHP_HCRHDESCRIPTORA_NDP_Pos)     /**< (UHP_HCRHDESCRIPTORA) Number of downstream ports (read-only) Mask */
#define UHP_HCRHDESCRIPTORA_NDP(value)      (UHP_HCRHDESCRIPTORA_NDP_Msk & ((value) << UHP_HCRHDESCRIPTORA_NDP_Pos))
#define UHP_HCRHDESCRIPTORA_PSM_Pos         8                                              /**< (UHP_HCRHDESCRIPTORA) Power switching mode (read/write) Position */
#define UHP_HCRHDESCRIPTORA_PSM_Msk         (_U_(0x1) << UHP_HCRHDESCRIPTORA_PSM_Pos)      /**< (UHP_HCRHDESCRIPTORA) Power switching mode (read/write) Mask */
#define UHP_HCRHDESCRIPTORA_PSM             UHP_HCRHDESCRIPTORA_PSM_Msk                    /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORA_PSM_Msk instead */
#define UHP_HCRHDESCRIPTORA_NPS_Pos         9                                              /**< (UHP_HCRHDESCRIPTORA) No power switching (read/write) Position */
#define UHP_HCRHDESCRIPTORA_NPS_Msk         (_U_(0x1) << UHP_HCRHDESCRIPTORA_NPS_Pos)      /**< (UHP_HCRHDESCRIPTORA) No power switching (read/write) Mask */
#define UHP_HCRHDESCRIPTORA_NPS             UHP_HCRHDESCRIPTORA_NPS_Msk                    /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORA_NPS_Msk instead */
#define UHP_HCRHDESCRIPTORA_DT_Pos          10                                             /**< (UHP_HCRHDESCRIPTORA) Device type (read-only) Position */
#define UHP_HCRHDESCRIPTORA_DT_Msk          (_U_(0x1) << UHP_HCRHDESCRIPTORA_DT_Pos)       /**< (UHP_HCRHDESCRIPTORA) Device type (read-only) Mask */
#define UHP_HCRHDESCRIPTORA_DT              UHP_HCRHDESCRIPTORA_DT_Msk                     /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORA_DT_Msk instead */
#define UHP_HCRHDESCRIPTORA_OCPM_Pos        11                                             /**< (UHP_HCRHDESCRIPTORA) Overcurrent protection mode (read/write) Position */
#define UHP_HCRHDESCRIPTORA_OCPM_Msk        (_U_(0x1) << UHP_HCRHDESCRIPTORA_OCPM_Pos)     /**< (UHP_HCRHDESCRIPTORA) Overcurrent protection mode (read/write) Mask */
#define UHP_HCRHDESCRIPTORA_OCPM            UHP_HCRHDESCRIPTORA_OCPM_Msk                   /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORA_OCPM_Msk instead */
#define UHP_HCRHDESCRIPTORA_NOCP_Pos        12                                             /**< (UHP_HCRHDESCRIPTORA) No overcurrent protection (read/write) Position */
#define UHP_HCRHDESCRIPTORA_NOCP_Msk        (_U_(0x1) << UHP_HCRHDESCRIPTORA_NOCP_Pos)     /**< (UHP_HCRHDESCRIPTORA) No overcurrent protection (read/write) Mask */
#define UHP_HCRHDESCRIPTORA_NOCP            UHP_HCRHDESCRIPTORA_NOCP_Msk                   /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORA_NOCP_Msk instead */
#define UHP_HCRHDESCRIPTORA_POTPG_Pos       24                                             /**< (UHP_HCRHDESCRIPTORA) Power-on to power-good time (read/write) Position */
#define UHP_HCRHDESCRIPTORA_POTPG_Msk       (_U_(0xFF) << UHP_HCRHDESCRIPTORA_POTPG_Pos)   /**< (UHP_HCRHDESCRIPTORA) Power-on to power-good time (read/write) Mask */
#define UHP_HCRHDESCRIPTORA_POTPG(value)    (UHP_HCRHDESCRIPTORA_POTPG_Msk & ((value) << UHP_HCRHDESCRIPTORA_POTPG_Pos))
#define UHP_HCRHDESCRIPTORA_MASK            _U_(0xFF001FFF)                                /**< \deprecated (UHP_HCRHDESCRIPTORA) Register MASK  (Use UHP_HCRHDESCRIPTORA_Msk instead)  */
#define UHP_HCRHDESCRIPTORA_Msk             _U_(0xFF001FFF)                                /**< (UHP_HCRHDESCRIPTORA) Register Mask  */


/* -------- UHP_HCRHDESCRIPTORB : (UHP Offset: 0x4c) (R/W 32) HC Root Hub B Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t DR0:1;                     /**< bit:      0                                           */
    uint32_t DR1:1;                     /**< bit:      1                                           */
    uint32_t DR2:1;                     /**< bit:      2                                           */
    uint32_t DR3:1;                     /**< bit:      3                                           */
    uint32_t DR4:1;                     /**< bit:      4                                           */
    uint32_t DR5:1;                     /**< bit:      5                                           */
    uint32_t DR6:1;                     /**< bit:      6                                           */
    uint32_t DR7:1;                     /**< bit:      7                                           */
    uint32_t DR8:1;                     /**< bit:      8                                           */
    uint32_t DR9:1;                     /**< bit:      9                                           */
    uint32_t DR10:1;                    /**< bit:     10                                           */
    uint32_t DR11:1;                    /**< bit:     11                                           */
    uint32_t DR12:1;                    /**< bit:     12                                           */
    uint32_t DR13:1;                    /**< bit:     13                                           */
    uint32_t DR14:1;                    /**< bit:     14                                           */
    uint32_t DR15:1;                    /**< bit:     15                                           */
    uint32_t PPCM0:1;                   /**< bit:     16                                           */
    uint32_t PPCM1:1;                   /**< bit:     17                                           */
    uint32_t PPCM2:1;                   /**< bit:     18                                           */
    uint32_t PPCM3:1;                   /**< bit:     19                                           */
    uint32_t PPCM4:1;                   /**< bit:     20                                           */
    uint32_t PPCM5:1;                   /**< bit:     21                                           */
    uint32_t PPCM6:1;                   /**< bit:     22                                           */
    uint32_t PPCM7:1;                   /**< bit:     23                                           */
    uint32_t PPCM8:1;                   /**< bit:     24                                           */
    uint32_t PPCM9:1;                   /**< bit:     25                                           */
    uint32_t PPCM10:1;                  /**< bit:     26                                           */
    uint32_t PPCM11:1;                  /**< bit:     27                                           */
    uint32_t PPCM12:1;                  /**< bit:     28                                           */
    uint32_t PPCM13:1;                  /**< bit:     29                                           */
    uint32_t PPCM14:1;                  /**< bit:     30                                           */
    uint32_t PPCM15:1;                  /**< bit:     31                                           */
  } bit;                                /**< Structure used for bit  access */
  struct {
    uint32_t DR:16;                     /**< bit:  0..15                                           */
    uint32_t PPCM:16;                   /**< bit: 16..31                                           */
  } vec;                                /**< Structure used for vec  access  */
  uint32_t reg;                         /**< Type used for register access */
} UHP_HCRHDESCRIPTORB_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_HCRHDESCRIPTORB_OFFSET          (0x4C)                                        /**<  (UHP_HCRHDESCRIPTORB) HC Root Hub B Register  Offset */

#define UHP_HCRHDESCRIPTORB_DR0_Pos         0                                              /**< (UHP_HCRHDESCRIPTORB)  Position */
#define UHP_HCRHDESCRIPTORB_DR0_Msk         (_U_(0x1) << UHP_HCRHDESCRIPTORB_DR0_Pos)      /**< (UHP_HCRHDESCRIPTORB)  Mask */
#define UHP_HCRHDESCRIPTORB_DR0             UHP_HCRHDESCRIPTORB_DR0_Msk                    /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORB_DR0_Msk instead */
#define UHP_HCRHDESCRIPTORB_DR1_Pos         1                                              /**< (UHP_HCRHDESCRIPTORB)  Position */
#define UHP_HCRHDESCRIPTORB_DR1_Msk         (_U_(0x1) << UHP_HCRHDESCRIPTORB_DR1_Pos)      /**< (UHP_HCRHDESCRIPTORB)  Mask */
#define UHP_HCRHDESCRIPTORB_DR1             UHP_HCRHDESCRIPTORB_DR1_Msk                    /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORB_DR1_Msk instead */
#define UHP_HCRHDESCRIPTORB_DR2_Pos         2                                              /**< (UHP_HCRHDESCRIPTORB)  Position */
#define UHP_HCRHDESCRIPTORB_DR2_Msk         (_U_(0x1) << UHP_HCRHDESCRIPTORB_DR2_Pos)      /**< (UHP_HCRHDESCRIPTORB)  Mask */
#define UHP_HCRHDESCRIPTORB_DR2             UHP_HCRHDESCRIPTORB_DR2_Msk                    /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORB_DR2_Msk instead */
#define UHP_HCRHDESCRIPTORB_DR3_Pos         3                                              /**< (UHP_HCRHDESCRIPTORB)  Position */
#define UHP_HCRHDESCRIPTORB_DR3_Msk         (_U_(0x1) << UHP_HCRHDESCRIPTORB_DR3_Pos)      /**< (UHP_HCRHDESCRIPTORB)  Mask */
#define UHP_HCRHDESCRIPTORB_DR3             UHP_HCRHDESCRIPTORB_DR3_Msk                    /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORB_DR3_Msk instead */
#define UHP_HCRHDESCRIPTORB_DR4_Pos         4                                              /**< (UHP_HCRHDESCRIPTORB)  Position */
#define UHP_HCRHDESCRIPTORB_DR4_Msk         (_U_(0x1) << UHP_HCRHDESCRIPTORB_DR4_Pos)      /**< (UHP_HCRHDESCRIPTORB)  Mask */
#define UHP_HCRHDESCRIPTORB_DR4             UHP_HCRHDESCRIPTORB_DR4_Msk                    /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORB_DR4_Msk instead */
#define UHP_HCRHDESCRIPTORB_DR5_Pos         5                                              /**< (UHP_HCRHDESCRIPTORB)  Position */
#define UHP_HCRHDESCRIPTORB_DR5_Msk         (_U_(0x1) << UHP_HCRHDESCRIPTORB_DR5_Pos)      /**< (UHP_HCRHDESCRIPTORB)  Mask */
#define UHP_HCRHDESCRIPTORB_DR5             UHP_HCRHDESCRIPTORB_DR5_Msk                    /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORB_DR5_Msk instead */
#define UHP_HCRHDESCRIPTORB_DR6_Pos         6                                              /**< (UHP_HCRHDESCRIPTORB)  Position */
#define UHP_HCRHDESCRIPTORB_DR6_Msk         (_U_(0x1) << UHP_HCRHDESCRIPTORB_DR6_Pos)      /**< (UHP_HCRHDESCRIPTORB)  Mask */
#define UHP_HCRHDESCRIPTORB_DR6             UHP_HCRHDESCRIPTORB_DR6_Msk                    /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORB_DR6_Msk instead */
#define UHP_HCRHDESCRIPTORB_DR7_Pos         7                                              /**< (UHP_HCRHDESCRIPTORB)  Position */
#define UHP_HCRHDESCRIPTORB_DR7_Msk         (_U_(0x1) << UHP_HCRHDESCRIPTORB_DR7_Pos)      /**< (UHP_HCRHDESCRIPTORB)  Mask */
#define UHP_HCRHDESCRIPTORB_DR7             UHP_HCRHDESCRIPTORB_DR7_Msk                    /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORB_DR7_Msk instead */
#define UHP_HCRHDESCRIPTORB_DR8_Pos         8                                              /**< (UHP_HCRHDESCRIPTORB)  Position */
#define UHP_HCRHDESCRIPTORB_DR8_Msk         (_U_(0x1) << UHP_HCRHDESCRIPTORB_DR8_Pos)      /**< (UHP_HCRHDESCRIPTORB)  Mask */
#define UHP_HCRHDESCRIPTORB_DR8             UHP_HCRHDESCRIPTORB_DR8_Msk                    /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORB_DR8_Msk instead */
#define UHP_HCRHDESCRIPTORB_DR9_Pos         9                                              /**< (UHP_HCRHDESCRIPTORB)  Position */
#define UHP_HCRHDESCRIPTORB_DR9_Msk         (_U_(0x1) << UHP_HCRHDESCRIPTORB_DR9_Pos)      /**< (UHP_HCRHDESCRIPTORB)  Mask */
#define UHP_HCRHDESCRIPTORB_DR9             UHP_HCRHDESCRIPTORB_DR9_Msk                    /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORB_DR9_Msk instead */
#define UHP_HCRHDESCRIPTORB_DR10_Pos        10                                             /**< (UHP_HCRHDESCRIPTORB)  Position */
#define UHP_HCRHDESCRIPTORB_DR10_Msk        (_U_(0x1) << UHP_HCRHDESCRIPTORB_DR10_Pos)     /**< (UHP_HCRHDESCRIPTORB)  Mask */
#define UHP_HCRHDESCRIPTORB_DR10            UHP_HCRHDESCRIPTORB_DR10_Msk                   /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORB_DR10_Msk instead */
#define UHP_HCRHDESCRIPTORB_DR11_Pos        11                                             /**< (UHP_HCRHDESCRIPTORB)  Position */
#define UHP_HCRHDESCRIPTORB_DR11_Msk        (_U_(0x1) << UHP_HCRHDESCRIPTORB_DR11_Pos)     /**< (UHP_HCRHDESCRIPTORB)  Mask */
#define UHP_HCRHDESCRIPTORB_DR11            UHP_HCRHDESCRIPTORB_DR11_Msk                   /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORB_DR11_Msk instead */
#define UHP_HCRHDESCRIPTORB_DR12_Pos        12                                             /**< (UHP_HCRHDESCRIPTORB)  Position */
#define UHP_HCRHDESCRIPTORB_DR12_Msk        (_U_(0x1) << UHP_HCRHDESCRIPTORB_DR12_Pos)     /**< (UHP_HCRHDESCRIPTORB)  Mask */
#define UHP_HCRHDESCRIPTORB_DR12            UHP_HCRHDESCRIPTORB_DR12_Msk                   /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORB_DR12_Msk instead */
#define UHP_HCRHDESCRIPTORB_DR13_Pos        13                                             /**< (UHP_HCRHDESCRIPTORB)  Position */
#define UHP_HCRHDESCRIPTORB_DR13_Msk        (_U_(0x1) << UHP_HCRHDESCRIPTORB_DR13_Pos)     /**< (UHP_HCRHDESCRIPTORB)  Mask */
#define UHP_HCRHDESCRIPTORB_DR13            UHP_HCRHDESCRIPTORB_DR13_Msk                   /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORB_DR13_Msk instead */
#define UHP_HCRHDESCRIPTORB_DR14_Pos        14                                             /**< (UHP_HCRHDESCRIPTORB)  Position */
#define UHP_HCRHDESCRIPTORB_DR14_Msk        (_U_(0x1) << UHP_HCRHDESCRIPTORB_DR14_Pos)     /**< (UHP_HCRHDESCRIPTORB)  Mask */
#define UHP_HCRHDESCRIPTORB_DR14            UHP_HCRHDESCRIPTORB_DR14_Msk                   /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORB_DR14_Msk instead */
#define UHP_HCRHDESCRIPTORB_DR15_Pos        15                                             /**< (UHP_HCRHDESCRIPTORB)  Position */
#define UHP_HCRHDESCRIPTORB_DR15_Msk        (_U_(0x1) << UHP_HCRHDESCRIPTORB_DR15_Pos)     /**< (UHP_HCRHDESCRIPTORB)  Mask */
#define UHP_HCRHDESCRIPTORB_DR15            UHP_HCRHDESCRIPTORB_DR15_Msk                   /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORB_DR15_Msk instead */
#define UHP_HCRHDESCRIPTORB_PPCM0_Pos       16                                             /**< (UHP_HCRHDESCRIPTORB)  Position */
#define UHP_HCRHDESCRIPTORB_PPCM0_Msk       (_U_(0x1) << UHP_HCRHDESCRIPTORB_PPCM0_Pos)    /**< (UHP_HCRHDESCRIPTORB)  Mask */
#define UHP_HCRHDESCRIPTORB_PPCM0           UHP_HCRHDESCRIPTORB_PPCM0_Msk                  /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORB_PPCM0_Msk instead */
#define UHP_HCRHDESCRIPTORB_PPCM1_Pos       17                                             /**< (UHP_HCRHDESCRIPTORB)  Position */
#define UHP_HCRHDESCRIPTORB_PPCM1_Msk       (_U_(0x1) << UHP_HCRHDESCRIPTORB_PPCM1_Pos)    /**< (UHP_HCRHDESCRIPTORB)  Mask */
#define UHP_HCRHDESCRIPTORB_PPCM1           UHP_HCRHDESCRIPTORB_PPCM1_Msk                  /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORB_PPCM1_Msk instead */
#define UHP_HCRHDESCRIPTORB_PPCM2_Pos       18                                             /**< (UHP_HCRHDESCRIPTORB)  Position */
#define UHP_HCRHDESCRIPTORB_PPCM2_Msk       (_U_(0x1) << UHP_HCRHDESCRIPTORB_PPCM2_Pos)    /**< (UHP_HCRHDESCRIPTORB)  Mask */
#define UHP_HCRHDESCRIPTORB_PPCM2           UHP_HCRHDESCRIPTORB_PPCM2_Msk                  /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORB_PPCM2_Msk instead */
#define UHP_HCRHDESCRIPTORB_PPCM3_Pos       19                                             /**< (UHP_HCRHDESCRIPTORB)  Position */
#define UHP_HCRHDESCRIPTORB_PPCM3_Msk       (_U_(0x1) << UHP_HCRHDESCRIPTORB_PPCM3_Pos)    /**< (UHP_HCRHDESCRIPTORB)  Mask */
#define UHP_HCRHDESCRIPTORB_PPCM3           UHP_HCRHDESCRIPTORB_PPCM3_Msk                  /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORB_PPCM3_Msk instead */
#define UHP_HCRHDESCRIPTORB_PPCM4_Pos       20                                             /**< (UHP_HCRHDESCRIPTORB)  Position */
#define UHP_HCRHDESCRIPTORB_PPCM4_Msk       (_U_(0x1) << UHP_HCRHDESCRIPTORB_PPCM4_Pos)    /**< (UHP_HCRHDESCRIPTORB)  Mask */
#define UHP_HCRHDESCRIPTORB_PPCM4           UHP_HCRHDESCRIPTORB_PPCM4_Msk                  /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORB_PPCM4_Msk instead */
#define UHP_HCRHDESCRIPTORB_PPCM5_Pos       21                                             /**< (UHP_HCRHDESCRIPTORB)  Position */
#define UHP_HCRHDESCRIPTORB_PPCM5_Msk       (_U_(0x1) << UHP_HCRHDESCRIPTORB_PPCM5_Pos)    /**< (UHP_HCRHDESCRIPTORB)  Mask */
#define UHP_HCRHDESCRIPTORB_PPCM5           UHP_HCRHDESCRIPTORB_PPCM5_Msk                  /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORB_PPCM5_Msk instead */
#define UHP_HCRHDESCRIPTORB_PPCM6_Pos       22                                             /**< (UHP_HCRHDESCRIPTORB)  Position */
#define UHP_HCRHDESCRIPTORB_PPCM6_Msk       (_U_(0x1) << UHP_HCRHDESCRIPTORB_PPCM6_Pos)    /**< (UHP_HCRHDESCRIPTORB)  Mask */
#define UHP_HCRHDESCRIPTORB_PPCM6           UHP_HCRHDESCRIPTORB_PPCM6_Msk                  /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORB_PPCM6_Msk instead */
#define UHP_HCRHDESCRIPTORB_PPCM7_Pos       23                                             /**< (UHP_HCRHDESCRIPTORB)  Position */
#define UHP_HCRHDESCRIPTORB_PPCM7_Msk       (_U_(0x1) << UHP_HCRHDESCRIPTORB_PPCM7_Pos)    /**< (UHP_HCRHDESCRIPTORB)  Mask */
#define UHP_HCRHDESCRIPTORB_PPCM7           UHP_HCRHDESCRIPTORB_PPCM7_Msk                  /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORB_PPCM7_Msk instead */
#define UHP_HCRHDESCRIPTORB_PPCM8_Pos       24                                             /**< (UHP_HCRHDESCRIPTORB)  Position */
#define UHP_HCRHDESCRIPTORB_PPCM8_Msk       (_U_(0x1) << UHP_HCRHDESCRIPTORB_PPCM8_Pos)    /**< (UHP_HCRHDESCRIPTORB)  Mask */
#define UHP_HCRHDESCRIPTORB_PPCM8           UHP_HCRHDESCRIPTORB_PPCM8_Msk                  /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORB_PPCM8_Msk instead */
#define UHP_HCRHDESCRIPTORB_PPCM9_Pos       25                                             /**< (UHP_HCRHDESCRIPTORB)  Position */
#define UHP_HCRHDESCRIPTORB_PPCM9_Msk       (_U_(0x1) << UHP_HCRHDESCRIPTORB_PPCM9_Pos)    /**< (UHP_HCRHDESCRIPTORB)  Mask */
#define UHP_HCRHDESCRIPTORB_PPCM9           UHP_HCRHDESCRIPTORB_PPCM9_Msk                  /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORB_PPCM9_Msk instead */
#define UHP_HCRHDESCRIPTORB_PPCM10_Pos      26                                             /**< (UHP_HCRHDESCRIPTORB)  Position */
#define UHP_HCRHDESCRIPTORB_PPCM10_Msk      (_U_(0x1) << UHP_HCRHDESCRIPTORB_PPCM10_Pos)   /**< (UHP_HCRHDESCRIPTORB)  Mask */
#define UHP_HCRHDESCRIPTORB_PPCM10          UHP_HCRHDESCRIPTORB_PPCM10_Msk                 /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORB_PPCM10_Msk instead */
#define UHP_HCRHDESCRIPTORB_PPCM11_Pos      27                                             /**< (UHP_HCRHDESCRIPTORB)  Position */
#define UHP_HCRHDESCRIPTORB_PPCM11_Msk      (_U_(0x1) << UHP_HCRHDESCRIPTORB_PPCM11_Pos)   /**< (UHP_HCRHDESCRIPTORB)  Mask */
#define UHP_HCRHDESCRIPTORB_PPCM11          UHP_HCRHDESCRIPTORB_PPCM11_Msk                 /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORB_PPCM11_Msk instead */
#define UHP_HCRHDESCRIPTORB_PPCM12_Pos      28                                             /**< (UHP_HCRHDESCRIPTORB)  Position */
#define UHP_HCRHDESCRIPTORB_PPCM12_Msk      (_U_(0x1) << UHP_HCRHDESCRIPTORB_PPCM12_Pos)   /**< (UHP_HCRHDESCRIPTORB)  Mask */
#define UHP_HCRHDESCRIPTORB_PPCM12          UHP_HCRHDESCRIPTORB_PPCM12_Msk                 /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORB_PPCM12_Msk instead */
#define UHP_HCRHDESCRIPTORB_PPCM13_Pos      29                                             /**< (UHP_HCRHDESCRIPTORB)  Position */
#define UHP_HCRHDESCRIPTORB_PPCM13_Msk      (_U_(0x1) << UHP_HCRHDESCRIPTORB_PPCM13_Pos)   /**< (UHP_HCRHDESCRIPTORB)  Mask */
#define UHP_HCRHDESCRIPTORB_PPCM13          UHP_HCRHDESCRIPTORB_PPCM13_Msk                 /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORB_PPCM13_Msk instead */
#define UHP_HCRHDESCRIPTORB_PPCM14_Pos      30                                             /**< (UHP_HCRHDESCRIPTORB)  Position */
#define UHP_HCRHDESCRIPTORB_PPCM14_Msk      (_U_(0x1) << UHP_HCRHDESCRIPTORB_PPCM14_Pos)   /**< (UHP_HCRHDESCRIPTORB)  Mask */
#define UHP_HCRHDESCRIPTORB_PPCM14          UHP_HCRHDESCRIPTORB_PPCM14_Msk                 /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORB_PPCM14_Msk instead */
#define UHP_HCRHDESCRIPTORB_PPCM15_Pos      31                                             /**< (UHP_HCRHDESCRIPTORB)  Position */
#define UHP_HCRHDESCRIPTORB_PPCM15_Msk      (_U_(0x1) << UHP_HCRHDESCRIPTORB_PPCM15_Pos)   /**< (UHP_HCRHDESCRIPTORB)  Mask */
#define UHP_HCRHDESCRIPTORB_PPCM15          UHP_HCRHDESCRIPTORB_PPCM15_Msk                 /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHDESCRIPTORB_PPCM15_Msk instead */
#define UHP_HCRHDESCRIPTORB_MASK            _U_(0xFFFFFFFF)                                /**< \deprecated (UHP_HCRHDESCRIPTORB) Register MASK  (Use UHP_HCRHDESCRIPTORB_Msk instead)  */
#define UHP_HCRHDESCRIPTORB_Msk             _U_(0xFFFFFFFF)                                /**< (UHP_HCRHDESCRIPTORB) Register Mask  */

#define UHP_HCRHDESCRIPTORB_DR_Pos          0                                              /**< (UHP_HCRHDESCRIPTORB Position)  */
#define UHP_HCRHDESCRIPTORB_DR_Msk          (_U_(0xFFFF) << UHP_HCRHDESCRIPTORB_DR_Pos)    /**< (UHP_HCRHDESCRIPTORB Mask) DR */
#define UHP_HCRHDESCRIPTORB_DR(value)       (UHP_HCRHDESCRIPTORB_DR_Msk & ((value) << UHP_HCRHDESCRIPTORB_DR_Pos))  
#define UHP_HCRHDESCRIPTORB_PPCM_Pos        16                                             /**< (UHP_HCRHDESCRIPTORB Position)  */
#define UHP_HCRHDESCRIPTORB_PPCM_Msk        (_U_(0xFFFF) << UHP_HCRHDESCRIPTORB_PPCM_Pos)  /**< (UHP_HCRHDESCRIPTORB Mask) PPCM */
#define UHP_HCRHDESCRIPTORB_PPCM(value)     (UHP_HCRHDESCRIPTORB_PPCM_Msk & ((value) << UHP_HCRHDESCRIPTORB_PPCM_Pos))  

/* -------- UHP_HCRHSTATUS : (UHP Offset: 0x50) (R/W 32) HC Root Hub Status Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t LPS:1;                     /**< bit:      0  Local power status (read/write)          */
    uint32_t OCI:1;                     /**< bit:      1  Overcurrent indicator (read-only)        */
    uint32_t :13;                       /**< bit:  2..14  Reserved */
    uint32_t DRWE:1;                    /**< bit:     15  Device remote wake-up enable (read/write) */
    uint32_t LPSC:1;                    /**< bit:     16  Local power status change (read/write)   */
    uint32_t OCIC:1;                    /**< bit:     17  Overcurrent indication change (read/write) */
    uint32_t :13;                       /**< bit: 18..30  Reserved */
    uint32_t CRWE:1;                    /**< bit:     31  Clear remote wake-up enable (read/write) */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_HCRHSTATUS_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_HCRHSTATUS_OFFSET               (0x50)                                        /**<  (UHP_HCRHSTATUS) HC Root Hub Status Register  Offset */

#define UHP_HCRHSTATUS_LPS_Pos              0                                              /**< (UHP_HCRHSTATUS) Local power status (read/write) Position */
#define UHP_HCRHSTATUS_LPS_Msk              (_U_(0x1) << UHP_HCRHSTATUS_LPS_Pos)           /**< (UHP_HCRHSTATUS) Local power status (read/write) Mask */
#define UHP_HCRHSTATUS_LPS                  UHP_HCRHSTATUS_LPS_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHSTATUS_LPS_Msk instead */
#define UHP_HCRHSTATUS_OCI_Pos              1                                              /**< (UHP_HCRHSTATUS) Overcurrent indicator (read-only) Position */
#define UHP_HCRHSTATUS_OCI_Msk              (_U_(0x1) << UHP_HCRHSTATUS_OCI_Pos)           /**< (UHP_HCRHSTATUS) Overcurrent indicator (read-only) Mask */
#define UHP_HCRHSTATUS_OCI                  UHP_HCRHSTATUS_OCI_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHSTATUS_OCI_Msk instead */
#define UHP_HCRHSTATUS_DRWE_Pos             15                                             /**< (UHP_HCRHSTATUS) Device remote wake-up enable (read/write) Position */
#define UHP_HCRHSTATUS_DRWE_Msk             (_U_(0x1) << UHP_HCRHSTATUS_DRWE_Pos)          /**< (UHP_HCRHSTATUS) Device remote wake-up enable (read/write) Mask */
#define UHP_HCRHSTATUS_DRWE                 UHP_HCRHSTATUS_DRWE_Msk                        /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHSTATUS_DRWE_Msk instead */
#define UHP_HCRHSTATUS_LPSC_Pos             16                                             /**< (UHP_HCRHSTATUS) Local power status change (read/write) Position */
#define UHP_HCRHSTATUS_LPSC_Msk             (_U_(0x1) << UHP_HCRHSTATUS_LPSC_Pos)          /**< (UHP_HCRHSTATUS) Local power status change (read/write) Mask */
#define UHP_HCRHSTATUS_LPSC                 UHP_HCRHSTATUS_LPSC_Msk                        /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHSTATUS_LPSC_Msk instead */
#define UHP_HCRHSTATUS_OCIC_Pos             17                                             /**< (UHP_HCRHSTATUS) Overcurrent indication change (read/write) Position */
#define UHP_HCRHSTATUS_OCIC_Msk             (_U_(0x1) << UHP_HCRHSTATUS_OCIC_Pos)          /**< (UHP_HCRHSTATUS) Overcurrent indication change (read/write) Mask */
#define UHP_HCRHSTATUS_OCIC                 UHP_HCRHSTATUS_OCIC_Msk                        /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHSTATUS_OCIC_Msk instead */
#define UHP_HCRHSTATUS_CRWE_Pos             31                                             /**< (UHP_HCRHSTATUS) Clear remote wake-up enable (read/write) Position */
#define UHP_HCRHSTATUS_CRWE_Msk             (_U_(0x1) << UHP_HCRHSTATUS_CRWE_Pos)          /**< (UHP_HCRHSTATUS) Clear remote wake-up enable (read/write) Mask */
#define UHP_HCRHSTATUS_CRWE                 UHP_HCRHSTATUS_CRWE_Msk                        /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHSTATUS_CRWE_Msk instead */
#define UHP_HCRHSTATUS_MASK                 _U_(0x80038003)                                /**< \deprecated (UHP_HCRHSTATUS) Register MASK  (Use UHP_HCRHSTATUS_Msk instead)  */
#define UHP_HCRHSTATUS_Msk                  _U_(0x80038003)                                /**< (UHP_HCRHSTATUS) Register Mask  */


/* -------- UHP_HCRHPORTSTATUS : (UHP Offset: 0x54) (R/W 32) HC Port 1 Status and Control Register 0 -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t CCS_CPE:1;                 /**< bit:      0                                           */
    uint32_t PES_SPE:1;                 /**< bit:      1                                           */
    uint32_t PSS_SPS:1;                 /**< bit:      2                                           */
    uint32_t POCI_CSS:1;                /**< bit:      3                                           */
    uint32_t PRS_SPR:1;                 /**< bit:      4                                           */
    uint32_t :3;                        /**< bit:   5..7  Reserved */
    uint32_t PPS_SPP:1;                 /**< bit:      8                                           */
    uint32_t LSDA_CPP:1;                /**< bit:      9                                           */
    uint32_t :6;                        /**< bit: 10..15  Reserved */
    uint32_t CSC:1;                     /**< bit:     16  Port 1 connect status change (read/write, write '1' to clear) */
    uint32_t PESC:1;                    /**< bit:     17  Port 1 enable status change (read/write, write '1' to clear) */
    uint32_t PSSC:1;                    /**< bit:     18  Port 1 suspend status change (read/write, write '1' to clear) */
    uint32_t OCIC:1;                    /**< bit:     19  Port 1 overcurrent indicator change (read/write) */
    uint32_t PRSC:1;                    /**< bit:     20  Port 1 reset status change (read/write, write '1' to clear) */
    uint32_t :11;                       /**< bit: 21..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UHP_HCRHPORTSTATUS_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UHP_HCRHPORTSTATUS_OFFSET           (0x54)                                        /**<  (UHP_HCRHPORTSTATUS) HC Port 1 Status and Control Register 0  Offset */

#define UHP_HCRHPORTSTATUS_CCS_CPE_Pos      0                                              /**< (UHP_HCRHPORTSTATUS)  Position */
#define UHP_HCRHPORTSTATUS_CCS_CPE_Msk      (_U_(0x1) << UHP_HCRHPORTSTATUS_CCS_CPE_Pos)   /**< (UHP_HCRHPORTSTATUS)  Mask */
#define UHP_HCRHPORTSTATUS_CCS_CPE          UHP_HCRHPORTSTATUS_CCS_CPE_Msk                 /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHPORTSTATUS_CCS_CPE_Msk instead */
#define UHP_HCRHPORTSTATUS_PES_SPE_Pos      1                                              /**< (UHP_HCRHPORTSTATUS)  Position */
#define UHP_HCRHPORTSTATUS_PES_SPE_Msk      (_U_(0x1) << UHP_HCRHPORTSTATUS_PES_SPE_Pos)   /**< (UHP_HCRHPORTSTATUS)  Mask */
#define UHP_HCRHPORTSTATUS_PES_SPE          UHP_HCRHPORTSTATUS_PES_SPE_Msk                 /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHPORTSTATUS_PES_SPE_Msk instead */
#define UHP_HCRHPORTSTATUS_PSS_SPS_Pos      2                                              /**< (UHP_HCRHPORTSTATUS)  Position */
#define UHP_HCRHPORTSTATUS_PSS_SPS_Msk      (_U_(0x1) << UHP_HCRHPORTSTATUS_PSS_SPS_Pos)   /**< (UHP_HCRHPORTSTATUS)  Mask */
#define UHP_HCRHPORTSTATUS_PSS_SPS          UHP_HCRHPORTSTATUS_PSS_SPS_Msk                 /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHPORTSTATUS_PSS_SPS_Msk instead */
#define UHP_HCRHPORTSTATUS_POCI_CSS_Pos     3                                              /**< (UHP_HCRHPORTSTATUS)  Position */
#define UHP_HCRHPORTSTATUS_POCI_CSS_Msk     (_U_(0x1) << UHP_HCRHPORTSTATUS_POCI_CSS_Pos)  /**< (UHP_HCRHPORTSTATUS)  Mask */
#define UHP_HCRHPORTSTATUS_POCI_CSS         UHP_HCRHPORTSTATUS_POCI_CSS_Msk                /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHPORTSTATUS_POCI_CSS_Msk instead */
#define UHP_HCRHPORTSTATUS_PRS_SPR_Pos      4                                              /**< (UHP_HCRHPORTSTATUS)  Position */
#define UHP_HCRHPORTSTATUS_PRS_SPR_Msk      (_U_(0x1) << UHP_HCRHPORTSTATUS_PRS_SPR_Pos)   /**< (UHP_HCRHPORTSTATUS)  Mask */
#define UHP_HCRHPORTSTATUS_PRS_SPR          UHP_HCRHPORTSTATUS_PRS_SPR_Msk                 /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHPORTSTATUS_PRS_SPR_Msk instead */
#define UHP_HCRHPORTSTATUS_PPS_SPP_Pos      8                                              /**< (UHP_HCRHPORTSTATUS)  Position */
#define UHP_HCRHPORTSTATUS_PPS_SPP_Msk      (_U_(0x1) << UHP_HCRHPORTSTATUS_PPS_SPP_Pos)   /**< (UHP_HCRHPORTSTATUS)  Mask */
#define UHP_HCRHPORTSTATUS_PPS_SPP          UHP_HCRHPORTSTATUS_PPS_SPP_Msk                 /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHPORTSTATUS_PPS_SPP_Msk instead */
#define UHP_HCRHPORTSTATUS_LSDA_CPP_Pos     9                                              /**< (UHP_HCRHPORTSTATUS)  Position */
#define UHP_HCRHPORTSTATUS_LSDA_CPP_Msk     (_U_(0x1) << UHP_HCRHPORTSTATUS_LSDA_CPP_Pos)  /**< (UHP_HCRHPORTSTATUS)  Mask */
#define UHP_HCRHPORTSTATUS_LSDA_CPP         UHP_HCRHPORTSTATUS_LSDA_CPP_Msk                /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHPORTSTATUS_LSDA_CPP_Msk instead */
#define UHP_HCRHPORTSTATUS_CSC_Pos          16                                             /**< (UHP_HCRHPORTSTATUS) Port 1 connect status change (read/write, write '1' to clear) Position */
#define UHP_HCRHPORTSTATUS_CSC_Msk          (_U_(0x1) << UHP_HCRHPORTSTATUS_CSC_Pos)       /**< (UHP_HCRHPORTSTATUS) Port 1 connect status change (read/write, write '1' to clear) Mask */
#define UHP_HCRHPORTSTATUS_CSC              UHP_HCRHPORTSTATUS_CSC_Msk                     /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHPORTSTATUS_CSC_Msk instead */
#define UHP_HCRHPORTSTATUS_PESC_Pos         17                                             /**< (UHP_HCRHPORTSTATUS) Port 1 enable status change (read/write, write '1' to clear) Position */
#define UHP_HCRHPORTSTATUS_PESC_Msk         (_U_(0x1) << UHP_HCRHPORTSTATUS_PESC_Pos)      /**< (UHP_HCRHPORTSTATUS) Port 1 enable status change (read/write, write '1' to clear) Mask */
#define UHP_HCRHPORTSTATUS_PESC             UHP_HCRHPORTSTATUS_PESC_Msk                    /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHPORTSTATUS_PESC_Msk instead */
#define UHP_HCRHPORTSTATUS_PSSC_Pos         18                                             /**< (UHP_HCRHPORTSTATUS) Port 1 suspend status change (read/write, write '1' to clear) Position */
#define UHP_HCRHPORTSTATUS_PSSC_Msk         (_U_(0x1) << UHP_HCRHPORTSTATUS_PSSC_Pos)      /**< (UHP_HCRHPORTSTATUS) Port 1 suspend status change (read/write, write '1' to clear) Mask */
#define UHP_HCRHPORTSTATUS_PSSC             UHP_HCRHPORTSTATUS_PSSC_Msk                    /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHPORTSTATUS_PSSC_Msk instead */
#define UHP_HCRHPORTSTATUS_OCIC_Pos         19                                             /**< (UHP_HCRHPORTSTATUS) Port 1 overcurrent indicator change (read/write) Position */
#define UHP_HCRHPORTSTATUS_OCIC_Msk         (_U_(0x1) << UHP_HCRHPORTSTATUS_OCIC_Pos)      /**< (UHP_HCRHPORTSTATUS) Port 1 overcurrent indicator change (read/write) Mask */
#define UHP_HCRHPORTSTATUS_OCIC             UHP_HCRHPORTSTATUS_OCIC_Msk                    /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHPORTSTATUS_OCIC_Msk instead */
#define UHP_HCRHPORTSTATUS_PRSC_Pos         20                                             /**< (UHP_HCRHPORTSTATUS) Port 1 reset status change (read/write, write '1' to clear) Position */
#define UHP_HCRHPORTSTATUS_PRSC_Msk         (_U_(0x1) << UHP_HCRHPORTSTATUS_PRSC_Pos)      /**< (UHP_HCRHPORTSTATUS) Port 1 reset status change (read/write, write '1' to clear) Mask */
#define UHP_HCRHPORTSTATUS_PRSC             UHP_HCRHPORTSTATUS_PRSC_Msk                    /**< \deprecated Old style mask definition for 1 bit bitfield. Use UHP_HCRHPORTSTATUS_PRSC_Msk instead */
#define UHP_HCRHPORTSTATUS_MASK             _U_(0x1F031F)                                  /**< \deprecated (UHP_HCRHPORTSTATUS) Register MASK  (Use UHP_HCRHPORTSTATUS_Msk instead)  */
#define UHP_HCRHPORTSTATUS_Msk              _U_(0x1F031F)                                  /**< (UHP_HCRHPORTSTATUS) Register Mask  */


#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'R'
/** \brief UHP hardware registers */
typedef struct {  
  __I  uint32_t UHP_HCREVISION; /**< (UHP Offset: 0x00) OHCI Revision Number Register */
  __IO uint32_t UHP_HCCONTROL;  /**< (UHP Offset: 0x04) HC Operating Mode Register */
  __IO uint32_t UHP_HCCOMMANDSTATUS; /**< (UHP Offset: 0x08) HC Command and Status Register */
  __IO uint32_t UHP_HCINTERRUPTSTATUS; /**< (UHP Offset: 0x0C) HC Interrupt and Status Register */
  __IO uint32_t UHP_HCINTERRUPTENABLE; /**< (UHP Offset: 0x10) HC Interrupt Enable Register */
  __IO uint32_t UHP_HCINTERRUPTDISABLE; /**< (UHP Offset: 0x14) HC Interrupt Disable Register */
  __IO uint32_t UHP_HCHCCA;     /**< (UHP Offset: 0x18) HC HCCA Address Register */
  __I  uint32_t UHP_HCPERIODCURRENTED; /**< (UHP Offset: 0x1C) HC Current Periodic Register */
  __IO uint32_t UHP_HCCONTROLHEADED; /**< (UHP Offset: 0x20) HC Head Control Register */
  __IO uint32_t UHP_HCCONTROLCURRENTED; /**< (UHP Offset: 0x24) HC Current Control Register */
  __IO uint32_t UHP_HCBULKHEADED; /**< (UHP Offset: 0x28) HC Head Bulk Register */
  __IO uint32_t UHP_HCBULKCURRENTED; /**< (UHP Offset: 0x2C) HC Current Bulk Register */
  __I  uint32_t UHP_HCDONEHEAD; /**< (UHP Offset: 0x30) HC Head Done Register */
  __IO uint32_t UHP_HCFMINTERVAL; /**< (UHP Offset: 0x34) HC Frame Interval Register */
  __I  uint32_t UHP_HCFMREMAINING; /**< (UHP Offset: 0x38) HC Frame Remaining Register */
  __I  uint32_t UHP_HCFMNUMBER; /**< (UHP Offset: 0x3C) HC Frame Number Register */
  __IO uint32_t UHP_HCPERIODICSTART; /**< (UHP Offset: 0x40) HC Periodic Start Register */
  __IO uint32_t UHP_HCLSTHRESHOLD; /**< (UHP Offset: 0x44) HC Low-Speed Threshold Register */
  __IO uint32_t UHP_HCRHDESCRIPTORA; /**< (UHP Offset: 0x48) HC Root Hub A Register */
  __IO uint32_t UHP_HCRHDESCRIPTORB; /**< (UHP Offset: 0x4C) HC Root Hub B Register */
  __IO uint32_t UHP_HCRHSTATUS; /**< (UHP Offset: 0x50) HC Root Hub Status Register */
  __IO uint32_t UHP_HCRHPORTSTATUS[2]; /**< (UHP Offset: 0x54) HC Port 1 Status and Control Register 0 */
} Uhp;

#elif COMPONENT_TYPEDEF_STYLE == 'N'
/** \brief UHP hardware registers */
typedef struct {  
  __I  UHP_HCREVISION_Type            UHP_HCREVISION; /**< Offset: 0x00 (R/   32) OHCI Revision Number Register */
  __IO UHP_HCCONTROL_Type             UHP_HCCONTROL;  /**< Offset: 0x04 (R/W  32) HC Operating Mode Register */
  __IO UHP_HCCOMMANDSTATUS_Type       UHP_HCCOMMANDSTATUS; /**< Offset: 0x08 (R/W  32) HC Command and Status Register */
  __IO UHP_HCINTERRUPTSTATUS_Type     UHP_HCINTERRUPTSTATUS; /**< Offset: 0x0C (R/W  32) HC Interrupt and Status Register */
  __IO UHP_HCINTERRUPTENABLE_Type     UHP_HCINTERRUPTENABLE; /**< Offset: 0x10 (R/W  32) HC Interrupt Enable Register */
  __IO UHP_HCINTERRUPTDISABLE_Type    UHP_HCINTERRUPTDISABLE; /**< Offset: 0x14 (R/W  32) HC Interrupt Disable Register */
  __IO UHP_HCHCCA_Type                UHP_HCHCCA;     /**< Offset: 0x18 (R/W  32) HC HCCA Address Register */
  __I  UHP_HCPERIODCURRENTED_Type     UHP_HCPERIODCURRENTED; /**< Offset: 0x1C (R/   32) HC Current Periodic Register */
  __IO UHP_HCCONTROLHEADED_Type       UHP_HCCONTROLHEADED; /**< Offset: 0x20 (R/W  32) HC Head Control Register */
  __IO UHP_HCCONTROLCURRENTED_Type    UHP_HCCONTROLCURRENTED; /**< Offset: 0x24 (R/W  32) HC Current Control Register */
  __IO UHP_HCBULKHEADED_Type          UHP_HCBULKHEADED; /**< Offset: 0x28 (R/W  32) HC Head Bulk Register */
  __IO UHP_HCBULKCURRENTED_Type       UHP_HCBULKCURRENTED; /**< Offset: 0x2C (R/W  32) HC Current Bulk Register */
  __I  UHP_HCDONEHEAD_Type            UHP_HCDONEHEAD; /**< Offset: 0x30 (R/   32) HC Head Done Register */
  __IO UHP_HCFMINTERVAL_Type          UHP_HCFMINTERVAL; /**< Offset: 0x34 (R/W  32) HC Frame Interval Register */
  __I  UHP_HCFMREMAINING_Type         UHP_HCFMREMAINING; /**< Offset: 0x38 (R/   32) HC Frame Remaining Register */
  __I  UHP_HCFMNUMBER_Type            UHP_HCFMNUMBER; /**< Offset: 0x3C (R/   32) HC Frame Number Register */
  __IO UHP_HCPERIODICSTART_Type       UHP_HCPERIODICSTART; /**< Offset: 0x40 (R/W  32) HC Periodic Start Register */
  __IO UHP_HCLSTHRESHOLD_Type         UHP_HCLSTHRESHOLD; /**< Offset: 0x44 (R/W  32) HC Low-Speed Threshold Register */
  __IO UHP_HCRHDESCRIPTORA_Type       UHP_HCRHDESCRIPTORA; /**< Offset: 0x48 (R/W  32) HC Root Hub A Register */
  __IO UHP_HCRHDESCRIPTORB_Type       UHP_HCRHDESCRIPTORB; /**< Offset: 0x4C (R/W  32) HC Root Hub B Register */
  __IO UHP_HCRHSTATUS_Type            UHP_HCRHSTATUS; /**< Offset: 0x50 (R/W  32) HC Root Hub Status Register */
  __IO UHP_HCRHPORTSTATUS_Type        UHP_HCRHPORTSTATUS[2]; /**< Offset: 0x54 (R/W  32) HC Port 1 Status and Control Register 0 */
} Uhp;

#else /* COMPONENT_TYPEDEF_STYLE */
#error Unknown component typedef style
#endif /* COMPONENT_TYPEDEF_STYLE */

#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
/** @}  end of USB Host Port */

#endif /* _SAMG55_UHP_COMPONENT_H_ */
