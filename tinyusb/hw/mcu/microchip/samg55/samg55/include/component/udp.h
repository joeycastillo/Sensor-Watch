/**
 * \file
 *
 * \brief Component description for UDP
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
#ifndef _SAMG55_UDP_COMPONENT_H_
#define _SAMG55_UDP_COMPONENT_H_
#define _SAMG55_UDP_COMPONENT_         /**< \deprecated  Backward compatibility for ASF */

/** \addtogroup SAMG_SAMG55 USB Device Port
 *  @{
 */
/* ========================================================================== */
/**  SOFTWARE API DEFINITION FOR UDP */
/* ========================================================================== */
#ifndef COMPONENT_TYPEDEF_STYLE
  #define COMPONENT_TYPEDEF_STYLE 'R'  /**< Defines default style of typedefs for the component header files ('R' = RFO, 'N' = NTO)*/
#endif

#define UDP_6083                       /**< (UDP) Module ID */
#define REV_UDP Y                      /**< (UDP) Module revision */

/* -------- UDP_FRM_NUM : (UDP Offset: 0x00) (R/ 32) Frame Number Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t FRM_NUM:11;                /**< bit:  0..10  Frame Number as Defined in the Packet Field Formats */
    uint32_t :5;                        /**< bit: 11..15  Reserved */
    uint32_t FRM_ERR:1;                 /**< bit:     16  Frame Error                              */
    uint32_t FRM_OK:1;                  /**< bit:     17  Frame OK                                 */
    uint32_t :14;                       /**< bit: 18..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UDP_FRM_NUM_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UDP_FRM_NUM_OFFSET                  (0x00)                                        /**<  (UDP_FRM_NUM) Frame Number Register  Offset */

#define UDP_FRM_NUM_FRM_NUM_Pos             0                                              /**< (UDP_FRM_NUM) Frame Number as Defined in the Packet Field Formats Position */
#define UDP_FRM_NUM_FRM_NUM_Msk             (_U_(0x7FF) << UDP_FRM_NUM_FRM_NUM_Pos)        /**< (UDP_FRM_NUM) Frame Number as Defined in the Packet Field Formats Mask */
#define UDP_FRM_NUM_FRM_NUM(value)          (UDP_FRM_NUM_FRM_NUM_Msk & ((value) << UDP_FRM_NUM_FRM_NUM_Pos))
#define UDP_FRM_NUM_FRM_ERR_Pos             16                                             /**< (UDP_FRM_NUM) Frame Error Position */
#define UDP_FRM_NUM_FRM_ERR_Msk             (_U_(0x1) << UDP_FRM_NUM_FRM_ERR_Pos)          /**< (UDP_FRM_NUM) Frame Error Mask */
#define UDP_FRM_NUM_FRM_ERR                 UDP_FRM_NUM_FRM_ERR_Msk                        /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_FRM_NUM_FRM_ERR_Msk instead */
#define UDP_FRM_NUM_FRM_OK_Pos              17                                             /**< (UDP_FRM_NUM) Frame OK Position */
#define UDP_FRM_NUM_FRM_OK_Msk              (_U_(0x1) << UDP_FRM_NUM_FRM_OK_Pos)           /**< (UDP_FRM_NUM) Frame OK Mask */
#define UDP_FRM_NUM_FRM_OK                  UDP_FRM_NUM_FRM_OK_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_FRM_NUM_FRM_OK_Msk instead */
#define UDP_FRM_NUM_MASK                    _U_(0x307FF)                                   /**< \deprecated (UDP_FRM_NUM) Register MASK  (Use UDP_FRM_NUM_Msk instead)  */
#define UDP_FRM_NUM_Msk                     _U_(0x307FF)                                   /**< (UDP_FRM_NUM) Register Mask  */


/* -------- UDP_GLB_STAT : (UDP Offset: 0x04) (R/W 32) Global State Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t FADDEN:1;                  /**< bit:      0  Function Address Enable                  */
    uint32_t CONFG:1;                   /**< bit:      1  Configured                               */
    uint32_t ESR:1;                     /**< bit:      2  Enable Send Resume                       */
    uint32_t RSMINPR:1;                 /**< bit:      3                                           */
    uint32_t RMWUPE:1;                  /**< bit:      4  Remote Wakeup Enable                     */
    uint32_t :27;                       /**< bit:  5..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UDP_GLB_STAT_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UDP_GLB_STAT_OFFSET                 (0x04)                                        /**<  (UDP_GLB_STAT) Global State Register  Offset */

#define UDP_GLB_STAT_FADDEN_Pos             0                                              /**< (UDP_GLB_STAT) Function Address Enable Position */
#define UDP_GLB_STAT_FADDEN_Msk             (_U_(0x1) << UDP_GLB_STAT_FADDEN_Pos)          /**< (UDP_GLB_STAT) Function Address Enable Mask */
#define UDP_GLB_STAT_FADDEN                 UDP_GLB_STAT_FADDEN_Msk                        /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_GLB_STAT_FADDEN_Msk instead */
#define UDP_GLB_STAT_CONFG_Pos              1                                              /**< (UDP_GLB_STAT) Configured Position */
#define UDP_GLB_STAT_CONFG_Msk              (_U_(0x1) << UDP_GLB_STAT_CONFG_Pos)           /**< (UDP_GLB_STAT) Configured Mask */
#define UDP_GLB_STAT_CONFG                  UDP_GLB_STAT_CONFG_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_GLB_STAT_CONFG_Msk instead */
#define UDP_GLB_STAT_ESR_Pos                2                                              /**< (UDP_GLB_STAT) Enable Send Resume Position */
#define UDP_GLB_STAT_ESR_Msk                (_U_(0x1) << UDP_GLB_STAT_ESR_Pos)             /**< (UDP_GLB_STAT) Enable Send Resume Mask */
#define UDP_GLB_STAT_ESR                    UDP_GLB_STAT_ESR_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_GLB_STAT_ESR_Msk instead */
#define UDP_GLB_STAT_RSMINPR_Pos            3                                              /**< (UDP_GLB_STAT)  Position */
#define UDP_GLB_STAT_RSMINPR_Msk            (_U_(0x1) << UDP_GLB_STAT_RSMINPR_Pos)         /**< (UDP_GLB_STAT)  Mask */
#define UDP_GLB_STAT_RSMINPR                UDP_GLB_STAT_RSMINPR_Msk                       /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_GLB_STAT_RSMINPR_Msk instead */
#define UDP_GLB_STAT_RMWUPE_Pos             4                                              /**< (UDP_GLB_STAT) Remote Wakeup Enable Position */
#define UDP_GLB_STAT_RMWUPE_Msk             (_U_(0x1) << UDP_GLB_STAT_RMWUPE_Pos)          /**< (UDP_GLB_STAT) Remote Wakeup Enable Mask */
#define UDP_GLB_STAT_RMWUPE                 UDP_GLB_STAT_RMWUPE_Msk                        /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_GLB_STAT_RMWUPE_Msk instead */
#define UDP_GLB_STAT_MASK                   _U_(0x1F)                                      /**< \deprecated (UDP_GLB_STAT) Register MASK  (Use UDP_GLB_STAT_Msk instead)  */
#define UDP_GLB_STAT_Msk                    _U_(0x1F)                                      /**< (UDP_GLB_STAT) Register Mask  */


/* -------- UDP_FADDR : (UDP Offset: 0x08) (R/W 32) Function Address Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t FADD:7;                    /**< bit:   0..6  Function Address Value                   */
    uint32_t :1;                        /**< bit:      7  Reserved */
    uint32_t FEN:1;                     /**< bit:      8  Function Enable                          */
    uint32_t :23;                       /**< bit:  9..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UDP_FADDR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UDP_FADDR_OFFSET                    (0x08)                                        /**<  (UDP_FADDR) Function Address Register  Offset */

#define UDP_FADDR_FADD_Pos                  0                                              /**< (UDP_FADDR) Function Address Value Position */
#define UDP_FADDR_FADD_Msk                  (_U_(0x7F) << UDP_FADDR_FADD_Pos)              /**< (UDP_FADDR) Function Address Value Mask */
#define UDP_FADDR_FADD(value)               (UDP_FADDR_FADD_Msk & ((value) << UDP_FADDR_FADD_Pos))
#define UDP_FADDR_FEN_Pos                   8                                              /**< (UDP_FADDR) Function Enable Position */
#define UDP_FADDR_FEN_Msk                   (_U_(0x1) << UDP_FADDR_FEN_Pos)                /**< (UDP_FADDR) Function Enable Mask */
#define UDP_FADDR_FEN                       UDP_FADDR_FEN_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_FADDR_FEN_Msk instead */
#define UDP_FADDR_MASK                      _U_(0x17F)                                     /**< \deprecated (UDP_FADDR) Register MASK  (Use UDP_FADDR_Msk instead)  */
#define UDP_FADDR_Msk                       _U_(0x17F)                                     /**< (UDP_FADDR) Register Mask  */


/* -------- UDP_IER : (UDP Offset: 0x10) (/W 32) Interrupt Enable Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t EP0INT:1;                  /**< bit:      0  Enable Endpoint 0 Interrupt              */
    uint32_t EP1INT:1;                  /**< bit:      1  Enable Endpoint 1 Interrupt              */
    uint32_t EP2INT:1;                  /**< bit:      2  Enable Endpoint 2Interrupt               */
    uint32_t EP3INT:1;                  /**< bit:      3  Enable Endpoint 3 Interrupt              */
    uint32_t EP4INT:1;                  /**< bit:      4  Enable Endpoint 4 Interrupt              */
    uint32_t EP5INT:1;                  /**< bit:      5  Enable Endpoint 5 Interrupt              */
    uint32_t :2;                        /**< bit:   6..7  Reserved */
    uint32_t RXSUSP:1;                  /**< bit:      8  Enable UDP Suspend Interrupt             */
    uint32_t RXRSM:1;                   /**< bit:      9  Enable UDP Resume Interrupt              */
    uint32_t EXTRSM:1;                  /**< bit:     10                                           */
    uint32_t SOFINT:1;                  /**< bit:     11  Enable Start Of Frame Interrupt          */
    uint32_t :1;                        /**< bit:     12  Reserved */
    uint32_t WAKEUP:1;                  /**< bit:     13  Enable UDP Bus Wakeup Interrupt          */
    uint32_t :18;                       /**< bit: 14..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UDP_IER_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UDP_IER_OFFSET                      (0x10)                                        /**<  (UDP_IER) Interrupt Enable Register  Offset */

#define UDP_IER_EP0INT_Pos                  0                                              /**< (UDP_IER) Enable Endpoint 0 Interrupt Position */
#define UDP_IER_EP0INT_Msk                  (_U_(0x1) << UDP_IER_EP0INT_Pos)               /**< (UDP_IER) Enable Endpoint 0 Interrupt Mask */
#define UDP_IER_EP0INT                      UDP_IER_EP0INT_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_IER_EP0INT_Msk instead */
#define UDP_IER_EP1INT_Pos                  1                                              /**< (UDP_IER) Enable Endpoint 1 Interrupt Position */
#define UDP_IER_EP1INT_Msk                  (_U_(0x1) << UDP_IER_EP1INT_Pos)               /**< (UDP_IER) Enable Endpoint 1 Interrupt Mask */
#define UDP_IER_EP1INT                      UDP_IER_EP1INT_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_IER_EP1INT_Msk instead */
#define UDP_IER_EP2INT_Pos                  2                                              /**< (UDP_IER) Enable Endpoint 2Interrupt Position */
#define UDP_IER_EP2INT_Msk                  (_U_(0x1) << UDP_IER_EP2INT_Pos)               /**< (UDP_IER) Enable Endpoint 2Interrupt Mask */
#define UDP_IER_EP2INT                      UDP_IER_EP2INT_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_IER_EP2INT_Msk instead */
#define UDP_IER_EP3INT_Pos                  3                                              /**< (UDP_IER) Enable Endpoint 3 Interrupt Position */
#define UDP_IER_EP3INT_Msk                  (_U_(0x1) << UDP_IER_EP3INT_Pos)               /**< (UDP_IER) Enable Endpoint 3 Interrupt Mask */
#define UDP_IER_EP3INT                      UDP_IER_EP3INT_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_IER_EP3INT_Msk instead */
#define UDP_IER_EP4INT_Pos                  4                                              /**< (UDP_IER) Enable Endpoint 4 Interrupt Position */
#define UDP_IER_EP4INT_Msk                  (_U_(0x1) << UDP_IER_EP4INT_Pos)               /**< (UDP_IER) Enable Endpoint 4 Interrupt Mask */
#define UDP_IER_EP4INT                      UDP_IER_EP4INT_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_IER_EP4INT_Msk instead */
#define UDP_IER_EP5INT_Pos                  5                                              /**< (UDP_IER) Enable Endpoint 5 Interrupt Position */
#define UDP_IER_EP5INT_Msk                  (_U_(0x1) << UDP_IER_EP5INT_Pos)               /**< (UDP_IER) Enable Endpoint 5 Interrupt Mask */
#define UDP_IER_EP5INT                      UDP_IER_EP5INT_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_IER_EP5INT_Msk instead */
#define UDP_IER_RXSUSP_Pos                  8                                              /**< (UDP_IER) Enable UDP Suspend Interrupt Position */
#define UDP_IER_RXSUSP_Msk                  (_U_(0x1) << UDP_IER_RXSUSP_Pos)               /**< (UDP_IER) Enable UDP Suspend Interrupt Mask */
#define UDP_IER_RXSUSP                      UDP_IER_RXSUSP_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_IER_RXSUSP_Msk instead */
#define UDP_IER_RXRSM_Pos                   9                                              /**< (UDP_IER) Enable UDP Resume Interrupt Position */
#define UDP_IER_RXRSM_Msk                   (_U_(0x1) << UDP_IER_RXRSM_Pos)                /**< (UDP_IER) Enable UDP Resume Interrupt Mask */
#define UDP_IER_RXRSM                       UDP_IER_RXRSM_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_IER_RXRSM_Msk instead */
#define UDP_IER_EXTRSM_Pos                  10                                             /**< (UDP_IER)  Position */
#define UDP_IER_EXTRSM_Msk                  (_U_(0x1) << UDP_IER_EXTRSM_Pos)               /**< (UDP_IER)  Mask */
#define UDP_IER_EXTRSM                      UDP_IER_EXTRSM_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_IER_EXTRSM_Msk instead */
#define UDP_IER_SOFINT_Pos                  11                                             /**< (UDP_IER) Enable Start Of Frame Interrupt Position */
#define UDP_IER_SOFINT_Msk                  (_U_(0x1) << UDP_IER_SOFINT_Pos)               /**< (UDP_IER) Enable Start Of Frame Interrupt Mask */
#define UDP_IER_SOFINT                      UDP_IER_SOFINT_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_IER_SOFINT_Msk instead */
#define UDP_IER_WAKEUP_Pos                  13                                             /**< (UDP_IER) Enable UDP Bus Wakeup Interrupt Position */
#define UDP_IER_WAKEUP_Msk                  (_U_(0x1) << UDP_IER_WAKEUP_Pos)               /**< (UDP_IER) Enable UDP Bus Wakeup Interrupt Mask */
#define UDP_IER_WAKEUP                      UDP_IER_WAKEUP_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_IER_WAKEUP_Msk instead */
#define UDP_IER_MASK                        _U_(0x2F3F)                                    /**< \deprecated (UDP_IER) Register MASK  (Use UDP_IER_Msk instead)  */
#define UDP_IER_Msk                         _U_(0x2F3F)                                    /**< (UDP_IER) Register Mask  */


/* -------- UDP_IDR : (UDP Offset: 0x14) (/W 32) Interrupt Disable Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t EP0INT:1;                  /**< bit:      0  Disable Endpoint 0 Interrupt             */
    uint32_t EP1INT:1;                  /**< bit:      1  Disable Endpoint 1 Interrupt             */
    uint32_t EP2INT:1;                  /**< bit:      2  Disable Endpoint 2 Interrupt             */
    uint32_t EP3INT:1;                  /**< bit:      3  Disable Endpoint 3 Interrupt             */
    uint32_t EP4INT:1;                  /**< bit:      4  Disable Endpoint 4 Interrupt             */
    uint32_t EP5INT:1;                  /**< bit:      5  Disable Endpoint 5 Interrupt             */
    uint32_t :2;                        /**< bit:   6..7  Reserved */
    uint32_t RXSUSP:1;                  /**< bit:      8  Disable UDP Suspend Interrupt            */
    uint32_t RXRSM:1;                   /**< bit:      9  Disable UDP Resume Interrupt             */
    uint32_t EXTRSM:1;                  /**< bit:     10                                           */
    uint32_t SOFINT:1;                  /**< bit:     11  Disable Start Of Frame Interrupt         */
    uint32_t :1;                        /**< bit:     12  Reserved */
    uint32_t WAKEUP:1;                  /**< bit:     13  Disable USB Bus Interrupt                */
    uint32_t :18;                       /**< bit: 14..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UDP_IDR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UDP_IDR_OFFSET                      (0x14)                                        /**<  (UDP_IDR) Interrupt Disable Register  Offset */

#define UDP_IDR_EP0INT_Pos                  0                                              /**< (UDP_IDR) Disable Endpoint 0 Interrupt Position */
#define UDP_IDR_EP0INT_Msk                  (_U_(0x1) << UDP_IDR_EP0INT_Pos)               /**< (UDP_IDR) Disable Endpoint 0 Interrupt Mask */
#define UDP_IDR_EP0INT                      UDP_IDR_EP0INT_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_IDR_EP0INT_Msk instead */
#define UDP_IDR_EP1INT_Pos                  1                                              /**< (UDP_IDR) Disable Endpoint 1 Interrupt Position */
#define UDP_IDR_EP1INT_Msk                  (_U_(0x1) << UDP_IDR_EP1INT_Pos)               /**< (UDP_IDR) Disable Endpoint 1 Interrupt Mask */
#define UDP_IDR_EP1INT                      UDP_IDR_EP1INT_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_IDR_EP1INT_Msk instead */
#define UDP_IDR_EP2INT_Pos                  2                                              /**< (UDP_IDR) Disable Endpoint 2 Interrupt Position */
#define UDP_IDR_EP2INT_Msk                  (_U_(0x1) << UDP_IDR_EP2INT_Pos)               /**< (UDP_IDR) Disable Endpoint 2 Interrupt Mask */
#define UDP_IDR_EP2INT                      UDP_IDR_EP2INT_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_IDR_EP2INT_Msk instead */
#define UDP_IDR_EP3INT_Pos                  3                                              /**< (UDP_IDR) Disable Endpoint 3 Interrupt Position */
#define UDP_IDR_EP3INT_Msk                  (_U_(0x1) << UDP_IDR_EP3INT_Pos)               /**< (UDP_IDR) Disable Endpoint 3 Interrupt Mask */
#define UDP_IDR_EP3INT                      UDP_IDR_EP3INT_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_IDR_EP3INT_Msk instead */
#define UDP_IDR_EP4INT_Pos                  4                                              /**< (UDP_IDR) Disable Endpoint 4 Interrupt Position */
#define UDP_IDR_EP4INT_Msk                  (_U_(0x1) << UDP_IDR_EP4INT_Pos)               /**< (UDP_IDR) Disable Endpoint 4 Interrupt Mask */
#define UDP_IDR_EP4INT                      UDP_IDR_EP4INT_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_IDR_EP4INT_Msk instead */
#define UDP_IDR_EP5INT_Pos                  5                                              /**< (UDP_IDR) Disable Endpoint 5 Interrupt Position */
#define UDP_IDR_EP5INT_Msk                  (_U_(0x1) << UDP_IDR_EP5INT_Pos)               /**< (UDP_IDR) Disable Endpoint 5 Interrupt Mask */
#define UDP_IDR_EP5INT                      UDP_IDR_EP5INT_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_IDR_EP5INT_Msk instead */
#define UDP_IDR_RXSUSP_Pos                  8                                              /**< (UDP_IDR) Disable UDP Suspend Interrupt Position */
#define UDP_IDR_RXSUSP_Msk                  (_U_(0x1) << UDP_IDR_RXSUSP_Pos)               /**< (UDP_IDR) Disable UDP Suspend Interrupt Mask */
#define UDP_IDR_RXSUSP                      UDP_IDR_RXSUSP_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_IDR_RXSUSP_Msk instead */
#define UDP_IDR_RXRSM_Pos                   9                                              /**< (UDP_IDR) Disable UDP Resume Interrupt Position */
#define UDP_IDR_RXRSM_Msk                   (_U_(0x1) << UDP_IDR_RXRSM_Pos)                /**< (UDP_IDR) Disable UDP Resume Interrupt Mask */
#define UDP_IDR_RXRSM                       UDP_IDR_RXRSM_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_IDR_RXRSM_Msk instead */
#define UDP_IDR_EXTRSM_Pos                  10                                             /**< (UDP_IDR)  Position */
#define UDP_IDR_EXTRSM_Msk                  (_U_(0x1) << UDP_IDR_EXTRSM_Pos)               /**< (UDP_IDR)  Mask */
#define UDP_IDR_EXTRSM                      UDP_IDR_EXTRSM_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_IDR_EXTRSM_Msk instead */
#define UDP_IDR_SOFINT_Pos                  11                                             /**< (UDP_IDR) Disable Start Of Frame Interrupt Position */
#define UDP_IDR_SOFINT_Msk                  (_U_(0x1) << UDP_IDR_SOFINT_Pos)               /**< (UDP_IDR) Disable Start Of Frame Interrupt Mask */
#define UDP_IDR_SOFINT                      UDP_IDR_SOFINT_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_IDR_SOFINT_Msk instead */
#define UDP_IDR_WAKEUP_Pos                  13                                             /**< (UDP_IDR) Disable USB Bus Interrupt Position */
#define UDP_IDR_WAKEUP_Msk                  (_U_(0x1) << UDP_IDR_WAKEUP_Pos)               /**< (UDP_IDR) Disable USB Bus Interrupt Mask */
#define UDP_IDR_WAKEUP                      UDP_IDR_WAKEUP_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_IDR_WAKEUP_Msk instead */
#define UDP_IDR_MASK                        _U_(0x2F3F)                                    /**< \deprecated (UDP_IDR) Register MASK  (Use UDP_IDR_Msk instead)  */
#define UDP_IDR_Msk                         _U_(0x2F3F)                                    /**< (UDP_IDR) Register Mask  */


/* -------- UDP_IMR : (UDP Offset: 0x18) (R/ 32) Interrupt Mask Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t EP0INT:1;                  /**< bit:      0  Mask Endpoint 0 Interrupt                */
    uint32_t EP1INT:1;                  /**< bit:      1  Mask Endpoint 1 Interrupt                */
    uint32_t EP2INT:1;                  /**< bit:      2  Mask Endpoint 2 Interrupt                */
    uint32_t EP3INT:1;                  /**< bit:      3  Mask Endpoint 3 Interrupt                */
    uint32_t EP4INT:1;                  /**< bit:      4  Mask Endpoint 4 Interrupt                */
    uint32_t EP5INT:1;                  /**< bit:      5  Mask Endpoint 5 Interrupt                */
    uint32_t :2;                        /**< bit:   6..7  Reserved */
    uint32_t RXSUSP:1;                  /**< bit:      8  Mask UDP Suspend Interrupt               */
    uint32_t RXRSM:1;                   /**< bit:      9  Mask UDP Resume Interrupt.               */
    uint32_t EXTRSM:1;                  /**< bit:     10                                           */
    uint32_t SOFINT:1;                  /**< bit:     11  Mask Start Of Frame Interrupt            */
    uint32_t BIT12:1;                   /**< bit:     12  UDP_IMR Bit 12                           */
    uint32_t WAKEUP:1;                  /**< bit:     13  USB Bus Wakeup Interrupt                 */
    uint32_t :18;                       /**< bit: 14..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UDP_IMR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UDP_IMR_OFFSET                      (0x18)                                        /**<  (UDP_IMR) Interrupt Mask Register  Offset */

#define UDP_IMR_EP0INT_Pos                  0                                              /**< (UDP_IMR) Mask Endpoint 0 Interrupt Position */
#define UDP_IMR_EP0INT_Msk                  (_U_(0x1) << UDP_IMR_EP0INT_Pos)               /**< (UDP_IMR) Mask Endpoint 0 Interrupt Mask */
#define UDP_IMR_EP0INT                      UDP_IMR_EP0INT_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_IMR_EP0INT_Msk instead */
#define UDP_IMR_EP1INT_Pos                  1                                              /**< (UDP_IMR) Mask Endpoint 1 Interrupt Position */
#define UDP_IMR_EP1INT_Msk                  (_U_(0x1) << UDP_IMR_EP1INT_Pos)               /**< (UDP_IMR) Mask Endpoint 1 Interrupt Mask */
#define UDP_IMR_EP1INT                      UDP_IMR_EP1INT_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_IMR_EP1INT_Msk instead */
#define UDP_IMR_EP2INT_Pos                  2                                              /**< (UDP_IMR) Mask Endpoint 2 Interrupt Position */
#define UDP_IMR_EP2INT_Msk                  (_U_(0x1) << UDP_IMR_EP2INT_Pos)               /**< (UDP_IMR) Mask Endpoint 2 Interrupt Mask */
#define UDP_IMR_EP2INT                      UDP_IMR_EP2INT_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_IMR_EP2INT_Msk instead */
#define UDP_IMR_EP3INT_Pos                  3                                              /**< (UDP_IMR) Mask Endpoint 3 Interrupt Position */
#define UDP_IMR_EP3INT_Msk                  (_U_(0x1) << UDP_IMR_EP3INT_Pos)               /**< (UDP_IMR) Mask Endpoint 3 Interrupt Mask */
#define UDP_IMR_EP3INT                      UDP_IMR_EP3INT_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_IMR_EP3INT_Msk instead */
#define UDP_IMR_EP4INT_Pos                  4                                              /**< (UDP_IMR) Mask Endpoint 4 Interrupt Position */
#define UDP_IMR_EP4INT_Msk                  (_U_(0x1) << UDP_IMR_EP4INT_Pos)               /**< (UDP_IMR) Mask Endpoint 4 Interrupt Mask */
#define UDP_IMR_EP4INT                      UDP_IMR_EP4INT_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_IMR_EP4INT_Msk instead */
#define UDP_IMR_EP5INT_Pos                  5                                              /**< (UDP_IMR) Mask Endpoint 5 Interrupt Position */
#define UDP_IMR_EP5INT_Msk                  (_U_(0x1) << UDP_IMR_EP5INT_Pos)               /**< (UDP_IMR) Mask Endpoint 5 Interrupt Mask */
#define UDP_IMR_EP5INT                      UDP_IMR_EP5INT_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_IMR_EP5INT_Msk instead */
#define UDP_IMR_RXSUSP_Pos                  8                                              /**< (UDP_IMR) Mask UDP Suspend Interrupt Position */
#define UDP_IMR_RXSUSP_Msk                  (_U_(0x1) << UDP_IMR_RXSUSP_Pos)               /**< (UDP_IMR) Mask UDP Suspend Interrupt Mask */
#define UDP_IMR_RXSUSP                      UDP_IMR_RXSUSP_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_IMR_RXSUSP_Msk instead */
#define UDP_IMR_RXRSM_Pos                   9                                              /**< (UDP_IMR) Mask UDP Resume Interrupt. Position */
#define UDP_IMR_RXRSM_Msk                   (_U_(0x1) << UDP_IMR_RXRSM_Pos)                /**< (UDP_IMR) Mask UDP Resume Interrupt. Mask */
#define UDP_IMR_RXRSM                       UDP_IMR_RXRSM_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_IMR_RXRSM_Msk instead */
#define UDP_IMR_EXTRSM_Pos                  10                                             /**< (UDP_IMR)  Position */
#define UDP_IMR_EXTRSM_Msk                  (_U_(0x1) << UDP_IMR_EXTRSM_Pos)               /**< (UDP_IMR)  Mask */
#define UDP_IMR_EXTRSM                      UDP_IMR_EXTRSM_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_IMR_EXTRSM_Msk instead */
#define UDP_IMR_SOFINT_Pos                  11                                             /**< (UDP_IMR) Mask Start Of Frame Interrupt Position */
#define UDP_IMR_SOFINT_Msk                  (_U_(0x1) << UDP_IMR_SOFINT_Pos)               /**< (UDP_IMR) Mask Start Of Frame Interrupt Mask */
#define UDP_IMR_SOFINT                      UDP_IMR_SOFINT_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_IMR_SOFINT_Msk instead */
#define UDP_IMR_BIT12_Pos                   12                                             /**< (UDP_IMR) UDP_IMR Bit 12 Position */
#define UDP_IMR_BIT12_Msk                   (_U_(0x1) << UDP_IMR_BIT12_Pos)                /**< (UDP_IMR) UDP_IMR Bit 12 Mask */
#define UDP_IMR_BIT12                       UDP_IMR_BIT12_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_IMR_BIT12_Msk instead */
#define UDP_IMR_WAKEUP_Pos                  13                                             /**< (UDP_IMR) USB Bus Wakeup Interrupt Position */
#define UDP_IMR_WAKEUP_Msk                  (_U_(0x1) << UDP_IMR_WAKEUP_Pos)               /**< (UDP_IMR) USB Bus Wakeup Interrupt Mask */
#define UDP_IMR_WAKEUP                      UDP_IMR_WAKEUP_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_IMR_WAKEUP_Msk instead */
#define UDP_IMR_MASK                        _U_(0x3F3F)                                    /**< \deprecated (UDP_IMR) Register MASK  (Use UDP_IMR_Msk instead)  */
#define UDP_IMR_Msk                         _U_(0x3F3F)                                    /**< (UDP_IMR) Register Mask  */


/* -------- UDP_ISR : (UDP Offset: 0x1c) (R/ 32) Interrupt Status Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t EP0INT:1;                  /**< bit:      0  Endpoint 0 Interrupt Status              */
    uint32_t EP1INT:1;                  /**< bit:      1  Endpoint 1 Interrupt Status              */
    uint32_t EP2INT:1;                  /**< bit:      2  Endpoint 2 Interrupt Status              */
    uint32_t EP3INT:1;                  /**< bit:      3  Endpoint 3 Interrupt Status              */
    uint32_t EP4INT:1;                  /**< bit:      4  Endpoint 4 Interrupt Status              */
    uint32_t EP5INT:1;                  /**< bit:      5  Endpoint 5 Interrupt Status              */
    uint32_t :2;                        /**< bit:   6..7  Reserved */
    uint32_t RXSUSP:1;                  /**< bit:      8  UDP Suspend Interrupt Status             */
    uint32_t RXRSM:1;                   /**< bit:      9  UDP Resume Interrupt Status              */
    uint32_t EXTRSM:1;                  /**< bit:     10                                           */
    uint32_t SOFINT:1;                  /**< bit:     11  Start of Frame Interrupt Status          */
    uint32_t ENDBUSRES:1;               /**< bit:     12  End of BUS Reset Interrupt Status        */
    uint32_t WAKEUP:1;                  /**< bit:     13  UDP Resume Interrupt Status              */
    uint32_t :18;                       /**< bit: 14..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UDP_ISR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UDP_ISR_OFFSET                      (0x1C)                                        /**<  (UDP_ISR) Interrupt Status Register  Offset */

#define UDP_ISR_EP0INT_Pos                  0                                              /**< (UDP_ISR) Endpoint 0 Interrupt Status Position */
#define UDP_ISR_EP0INT_Msk                  (_U_(0x1) << UDP_ISR_EP0INT_Pos)               /**< (UDP_ISR) Endpoint 0 Interrupt Status Mask */
#define UDP_ISR_EP0INT                      UDP_ISR_EP0INT_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_ISR_EP0INT_Msk instead */
#define UDP_ISR_EP1INT_Pos                  1                                              /**< (UDP_ISR) Endpoint 1 Interrupt Status Position */
#define UDP_ISR_EP1INT_Msk                  (_U_(0x1) << UDP_ISR_EP1INT_Pos)               /**< (UDP_ISR) Endpoint 1 Interrupt Status Mask */
#define UDP_ISR_EP1INT                      UDP_ISR_EP1INT_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_ISR_EP1INT_Msk instead */
#define UDP_ISR_EP2INT_Pos                  2                                              /**< (UDP_ISR) Endpoint 2 Interrupt Status Position */
#define UDP_ISR_EP2INT_Msk                  (_U_(0x1) << UDP_ISR_EP2INT_Pos)               /**< (UDP_ISR) Endpoint 2 Interrupt Status Mask */
#define UDP_ISR_EP2INT                      UDP_ISR_EP2INT_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_ISR_EP2INT_Msk instead */
#define UDP_ISR_EP3INT_Pos                  3                                              /**< (UDP_ISR) Endpoint 3 Interrupt Status Position */
#define UDP_ISR_EP3INT_Msk                  (_U_(0x1) << UDP_ISR_EP3INT_Pos)               /**< (UDP_ISR) Endpoint 3 Interrupt Status Mask */
#define UDP_ISR_EP3INT                      UDP_ISR_EP3INT_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_ISR_EP3INT_Msk instead */
#define UDP_ISR_EP4INT_Pos                  4                                              /**< (UDP_ISR) Endpoint 4 Interrupt Status Position */
#define UDP_ISR_EP4INT_Msk                  (_U_(0x1) << UDP_ISR_EP4INT_Pos)               /**< (UDP_ISR) Endpoint 4 Interrupt Status Mask */
#define UDP_ISR_EP4INT                      UDP_ISR_EP4INT_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_ISR_EP4INT_Msk instead */
#define UDP_ISR_EP5INT_Pos                  5                                              /**< (UDP_ISR) Endpoint 5 Interrupt Status Position */
#define UDP_ISR_EP5INT_Msk                  (_U_(0x1) << UDP_ISR_EP5INT_Pos)               /**< (UDP_ISR) Endpoint 5 Interrupt Status Mask */
#define UDP_ISR_EP5INT                      UDP_ISR_EP5INT_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_ISR_EP5INT_Msk instead */
#define UDP_ISR_RXSUSP_Pos                  8                                              /**< (UDP_ISR) UDP Suspend Interrupt Status Position */
#define UDP_ISR_RXSUSP_Msk                  (_U_(0x1) << UDP_ISR_RXSUSP_Pos)               /**< (UDP_ISR) UDP Suspend Interrupt Status Mask */
#define UDP_ISR_RXSUSP                      UDP_ISR_RXSUSP_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_ISR_RXSUSP_Msk instead */
#define UDP_ISR_RXRSM_Pos                   9                                              /**< (UDP_ISR) UDP Resume Interrupt Status Position */
#define UDP_ISR_RXRSM_Msk                   (_U_(0x1) << UDP_ISR_RXRSM_Pos)                /**< (UDP_ISR) UDP Resume Interrupt Status Mask */
#define UDP_ISR_RXRSM                       UDP_ISR_RXRSM_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_ISR_RXRSM_Msk instead */
#define UDP_ISR_EXTRSM_Pos                  10                                             /**< (UDP_ISR)  Position */
#define UDP_ISR_EXTRSM_Msk                  (_U_(0x1) << UDP_ISR_EXTRSM_Pos)               /**< (UDP_ISR)  Mask */
#define UDP_ISR_EXTRSM                      UDP_ISR_EXTRSM_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_ISR_EXTRSM_Msk instead */
#define UDP_ISR_SOFINT_Pos                  11                                             /**< (UDP_ISR) Start of Frame Interrupt Status Position */
#define UDP_ISR_SOFINT_Msk                  (_U_(0x1) << UDP_ISR_SOFINT_Pos)               /**< (UDP_ISR) Start of Frame Interrupt Status Mask */
#define UDP_ISR_SOFINT                      UDP_ISR_SOFINT_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_ISR_SOFINT_Msk instead */
#define UDP_ISR_ENDBUSRES_Pos               12                                             /**< (UDP_ISR) End of BUS Reset Interrupt Status Position */
#define UDP_ISR_ENDBUSRES_Msk               (_U_(0x1) << UDP_ISR_ENDBUSRES_Pos)            /**< (UDP_ISR) End of BUS Reset Interrupt Status Mask */
#define UDP_ISR_ENDBUSRES                   UDP_ISR_ENDBUSRES_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_ISR_ENDBUSRES_Msk instead */
#define UDP_ISR_WAKEUP_Pos                  13                                             /**< (UDP_ISR) UDP Resume Interrupt Status Position */
#define UDP_ISR_WAKEUP_Msk                  (_U_(0x1) << UDP_ISR_WAKEUP_Pos)               /**< (UDP_ISR) UDP Resume Interrupt Status Mask */
#define UDP_ISR_WAKEUP                      UDP_ISR_WAKEUP_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_ISR_WAKEUP_Msk instead */
#define UDP_ISR_MASK                        _U_(0x3F3F)                                    /**< \deprecated (UDP_ISR) Register MASK  (Use UDP_ISR_Msk instead)  */
#define UDP_ISR_Msk                         _U_(0x3F3F)                                    /**< (UDP_ISR) Register Mask  */


/* -------- UDP_ICR : (UDP Offset: 0x20) (/W 32) Interrupt Clear Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t :8;                        /**< bit:   0..7  Reserved */
    uint32_t RXSUSP:1;                  /**< bit:      8  Clear UDP Suspend Interrupt              */
    uint32_t RXRSM:1;                   /**< bit:      9  Clear UDP Resume Interrupt               */
    uint32_t EXTRSM:1;                  /**< bit:     10                                           */
    uint32_t SOFINT:1;                  /**< bit:     11  Clear Start Of Frame Interrupt           */
    uint32_t ENDBUSRES:1;               /**< bit:     12  Clear End of Bus Reset Interrupt         */
    uint32_t WAKEUP:1;                  /**< bit:     13  Clear Wakeup Interrupt                   */
    uint32_t :18;                       /**< bit: 14..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UDP_ICR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UDP_ICR_OFFSET                      (0x20)                                        /**<  (UDP_ICR) Interrupt Clear Register  Offset */

#define UDP_ICR_RXSUSP_Pos                  8                                              /**< (UDP_ICR) Clear UDP Suspend Interrupt Position */
#define UDP_ICR_RXSUSP_Msk                  (_U_(0x1) << UDP_ICR_RXSUSP_Pos)               /**< (UDP_ICR) Clear UDP Suspend Interrupt Mask */
#define UDP_ICR_RXSUSP                      UDP_ICR_RXSUSP_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_ICR_RXSUSP_Msk instead */
#define UDP_ICR_RXRSM_Pos                   9                                              /**< (UDP_ICR) Clear UDP Resume Interrupt Position */
#define UDP_ICR_RXRSM_Msk                   (_U_(0x1) << UDP_ICR_RXRSM_Pos)                /**< (UDP_ICR) Clear UDP Resume Interrupt Mask */
#define UDP_ICR_RXRSM                       UDP_ICR_RXRSM_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_ICR_RXRSM_Msk instead */
#define UDP_ICR_EXTRSM_Pos                  10                                             /**< (UDP_ICR)  Position */
#define UDP_ICR_EXTRSM_Msk                  (_U_(0x1) << UDP_ICR_EXTRSM_Pos)               /**< (UDP_ICR)  Mask */
#define UDP_ICR_EXTRSM                      UDP_ICR_EXTRSM_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_ICR_EXTRSM_Msk instead */
#define UDP_ICR_SOFINT_Pos                  11                                             /**< (UDP_ICR) Clear Start Of Frame Interrupt Position */
#define UDP_ICR_SOFINT_Msk                  (_U_(0x1) << UDP_ICR_SOFINT_Pos)               /**< (UDP_ICR) Clear Start Of Frame Interrupt Mask */
#define UDP_ICR_SOFINT                      UDP_ICR_SOFINT_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_ICR_SOFINT_Msk instead */
#define UDP_ICR_ENDBUSRES_Pos               12                                             /**< (UDP_ICR) Clear End of Bus Reset Interrupt Position */
#define UDP_ICR_ENDBUSRES_Msk               (_U_(0x1) << UDP_ICR_ENDBUSRES_Pos)            /**< (UDP_ICR) Clear End of Bus Reset Interrupt Mask */
#define UDP_ICR_ENDBUSRES                   UDP_ICR_ENDBUSRES_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_ICR_ENDBUSRES_Msk instead */
#define UDP_ICR_WAKEUP_Pos                  13                                             /**< (UDP_ICR) Clear Wakeup Interrupt Position */
#define UDP_ICR_WAKEUP_Msk                  (_U_(0x1) << UDP_ICR_WAKEUP_Pos)               /**< (UDP_ICR) Clear Wakeup Interrupt Mask */
#define UDP_ICR_WAKEUP                      UDP_ICR_WAKEUP_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_ICR_WAKEUP_Msk instead */
#define UDP_ICR_MASK                        _U_(0x3F00)                                    /**< \deprecated (UDP_ICR) Register MASK  (Use UDP_ICR_Msk instead)  */
#define UDP_ICR_Msk                         _U_(0x3F00)                                    /**< (UDP_ICR) Register Mask  */


/* -------- UDP_RST_EP : (UDP Offset: 0x28) (R/W 32) Reset Endpoint Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t EP0:1;                     /**< bit:      0  Reset Endpoint 0                         */
    uint32_t EP1:1;                     /**< bit:      1  Reset Endpoint 1                         */
    uint32_t EP2:1;                     /**< bit:      2  Reset Endpoint 2                         */
    uint32_t EP3:1;                     /**< bit:      3  Reset Endpoint 3                         */
    uint32_t EP4:1;                     /**< bit:      4  Reset Endpoint 4                         */
    uint32_t EP5:1;                     /**< bit:      5  Reset Endpoint 5                         */
    uint32_t :26;                       /**< bit:  6..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  struct {
    uint32_t EP:6;                      /**< bit:   0..5  Reset Endpoint 5                         */
    uint32_t :26;                       /**< bit:  6..31 Reserved */
  } vec;                                /**< Structure used for vec  access  */
  uint32_t reg;                         /**< Type used for register access */
} UDP_RST_EP_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UDP_RST_EP_OFFSET                   (0x28)                                        /**<  (UDP_RST_EP) Reset Endpoint Register  Offset */

#define UDP_RST_EP_EP0_Pos                  0                                              /**< (UDP_RST_EP) Reset Endpoint 0 Position */
#define UDP_RST_EP_EP0_Msk                  (_U_(0x1) << UDP_RST_EP_EP0_Pos)               /**< (UDP_RST_EP) Reset Endpoint 0 Mask */
#define UDP_RST_EP_EP0                      UDP_RST_EP_EP0_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_RST_EP_EP0_Msk instead */
#define UDP_RST_EP_EP1_Pos                  1                                              /**< (UDP_RST_EP) Reset Endpoint 1 Position */
#define UDP_RST_EP_EP1_Msk                  (_U_(0x1) << UDP_RST_EP_EP1_Pos)               /**< (UDP_RST_EP) Reset Endpoint 1 Mask */
#define UDP_RST_EP_EP1                      UDP_RST_EP_EP1_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_RST_EP_EP1_Msk instead */
#define UDP_RST_EP_EP2_Pos                  2                                              /**< (UDP_RST_EP) Reset Endpoint 2 Position */
#define UDP_RST_EP_EP2_Msk                  (_U_(0x1) << UDP_RST_EP_EP2_Pos)               /**< (UDP_RST_EP) Reset Endpoint 2 Mask */
#define UDP_RST_EP_EP2                      UDP_RST_EP_EP2_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_RST_EP_EP2_Msk instead */
#define UDP_RST_EP_EP3_Pos                  3                                              /**< (UDP_RST_EP) Reset Endpoint 3 Position */
#define UDP_RST_EP_EP3_Msk                  (_U_(0x1) << UDP_RST_EP_EP3_Pos)               /**< (UDP_RST_EP) Reset Endpoint 3 Mask */
#define UDP_RST_EP_EP3                      UDP_RST_EP_EP3_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_RST_EP_EP3_Msk instead */
#define UDP_RST_EP_EP4_Pos                  4                                              /**< (UDP_RST_EP) Reset Endpoint 4 Position */
#define UDP_RST_EP_EP4_Msk                  (_U_(0x1) << UDP_RST_EP_EP4_Pos)               /**< (UDP_RST_EP) Reset Endpoint 4 Mask */
#define UDP_RST_EP_EP4                      UDP_RST_EP_EP4_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_RST_EP_EP4_Msk instead */
#define UDP_RST_EP_EP5_Pos                  5                                              /**< (UDP_RST_EP) Reset Endpoint 5 Position */
#define UDP_RST_EP_EP5_Msk                  (_U_(0x1) << UDP_RST_EP_EP5_Pos)               /**< (UDP_RST_EP) Reset Endpoint 5 Mask */
#define UDP_RST_EP_EP5                      UDP_RST_EP_EP5_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_RST_EP_EP5_Msk instead */
#define UDP_RST_EP_MASK                     _U_(0x3F)                                      /**< \deprecated (UDP_RST_EP) Register MASK  (Use UDP_RST_EP_Msk instead)  */
#define UDP_RST_EP_Msk                      _U_(0x3F)                                      /**< (UDP_RST_EP) Register Mask  */

#define UDP_RST_EP_EP_Pos                   0                                              /**< (UDP_RST_EP Position) Reset Endpoint 5 */
#define UDP_RST_EP_EP_Msk                   (_U_(0x3F) << UDP_RST_EP_EP_Pos)               /**< (UDP_RST_EP Mask) EP */
#define UDP_RST_EP_EP(value)                (UDP_RST_EP_EP_Msk & ((value) << UDP_RST_EP_EP_Pos))  

/* -------- UDP_CSR : (UDP Offset: 0x30) (R/W 32) Endpoint Control and Status Register 0 -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t TXCOMP:1;                  /**< bit:      0  Generates an IN Packet with Data Previously Written in the DPR */
    uint32_t RX_DATA_BK0:1;             /**< bit:      1  Receive Data Bank 0                      */
    uint32_t RXSETUP:1;                 /**< bit:      2  Received Setup                           */
    uint32_t STALLSENT:1;               /**< bit:      3  Stall Sent                               */
    uint32_t TXPKTRDY:1;                /**< bit:      4  Transmit Packet Ready                    */
    uint32_t FORCESTALL:1;              /**< bit:      5  Force Stall (used by Control, Bulk and Isochronous Endpoints) */
    uint32_t RX_DATA_BK1:1;             /**< bit:      6  Receive Data Bank 1 (only used by endpoints with ping-pong attributes) */
    uint32_t DIR:1;                     /**< bit:      7  Transfer Direction (only available for control endpoints) (Read/Write) */
    uint32_t EPTYPE:3;                  /**< bit:  8..10  Endpoint Type (Read/Write)               */
    uint32_t DTGLE:1;                   /**< bit:     11  Data Toggle (Read-only)                  */
    uint32_t :3;                        /**< bit: 12..14  Reserved */
    uint32_t EPEDS:1;                   /**< bit:     15  Endpoint Enable Disable                  */
    uint32_t RXBYTECNT:11;              /**< bit: 16..26  Number of Bytes Available in the FIFO (Read-only) */
    uint32_t :5;                        /**< bit: 27..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UDP_CSR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UDP_CSR_OFFSET                      (0x30)                                        /**<  (UDP_CSR) Endpoint Control and Status Register 0  Offset */

#define UDP_CSR_TXCOMP_Pos                  0                                              /**< (UDP_CSR) Generates an IN Packet with Data Previously Written in the DPR Position */
#define UDP_CSR_TXCOMP_Msk                  (_U_(0x1) << UDP_CSR_TXCOMP_Pos)               /**< (UDP_CSR) Generates an IN Packet with Data Previously Written in the DPR Mask */
#define UDP_CSR_TXCOMP                      UDP_CSR_TXCOMP_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_CSR_TXCOMP_Msk instead */
#define UDP_CSR_RX_DATA_BK0_Pos             1                                              /**< (UDP_CSR) Receive Data Bank 0 Position */
#define UDP_CSR_RX_DATA_BK0_Msk             (_U_(0x1) << UDP_CSR_RX_DATA_BK0_Pos)          /**< (UDP_CSR) Receive Data Bank 0 Mask */
#define UDP_CSR_RX_DATA_BK0                 UDP_CSR_RX_DATA_BK0_Msk                        /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_CSR_RX_DATA_BK0_Msk instead */
#define UDP_CSR_RXSETUP_Pos                 2                                              /**< (UDP_CSR) Received Setup Position */
#define UDP_CSR_RXSETUP_Msk                 (_U_(0x1) << UDP_CSR_RXSETUP_Pos)              /**< (UDP_CSR) Received Setup Mask */
#define UDP_CSR_RXSETUP                     UDP_CSR_RXSETUP_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_CSR_RXSETUP_Msk instead */
#define UDP_CSR_STALLSENT_Pos               3                                              /**< (UDP_CSR) Stall Sent Position */
#define UDP_CSR_STALLSENT_Msk               (_U_(0x1) << UDP_CSR_STALLSENT_Pos)            /**< (UDP_CSR) Stall Sent Mask */
#define UDP_CSR_STALLSENT                   UDP_CSR_STALLSENT_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_CSR_STALLSENT_Msk instead */
#define UDP_CSR_TXPKTRDY_Pos                4                                              /**< (UDP_CSR) Transmit Packet Ready Position */
#define UDP_CSR_TXPKTRDY_Msk                (_U_(0x1) << UDP_CSR_TXPKTRDY_Pos)             /**< (UDP_CSR) Transmit Packet Ready Mask */
#define UDP_CSR_TXPKTRDY                    UDP_CSR_TXPKTRDY_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_CSR_TXPKTRDY_Msk instead */
#define UDP_CSR_FORCESTALL_Pos              5                                              /**< (UDP_CSR) Force Stall (used by Control, Bulk and Isochronous Endpoints) Position */
#define UDP_CSR_FORCESTALL_Msk              (_U_(0x1) << UDP_CSR_FORCESTALL_Pos)           /**< (UDP_CSR) Force Stall (used by Control, Bulk and Isochronous Endpoints) Mask */
#define UDP_CSR_FORCESTALL                  UDP_CSR_FORCESTALL_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_CSR_FORCESTALL_Msk instead */
#define UDP_CSR_RX_DATA_BK1_Pos             6                                              /**< (UDP_CSR) Receive Data Bank 1 (only used by endpoints with ping-pong attributes) Position */
#define UDP_CSR_RX_DATA_BK1_Msk             (_U_(0x1) << UDP_CSR_RX_DATA_BK1_Pos)          /**< (UDP_CSR) Receive Data Bank 1 (only used by endpoints with ping-pong attributes) Mask */
#define UDP_CSR_RX_DATA_BK1                 UDP_CSR_RX_DATA_BK1_Msk                        /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_CSR_RX_DATA_BK1_Msk instead */
#define UDP_CSR_DIR_Pos                     7                                              /**< (UDP_CSR) Transfer Direction (only available for control endpoints) (Read/Write) Position */
#define UDP_CSR_DIR_Msk                     (_U_(0x1) << UDP_CSR_DIR_Pos)                  /**< (UDP_CSR) Transfer Direction (only available for control endpoints) (Read/Write) Mask */
#define UDP_CSR_DIR                         UDP_CSR_DIR_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_CSR_DIR_Msk instead */
#define UDP_CSR_EPTYPE_Pos                  8                                              /**< (UDP_CSR) Endpoint Type (Read/Write) Position */
#define UDP_CSR_EPTYPE_Msk                  (_U_(0x7) << UDP_CSR_EPTYPE_Pos)               /**< (UDP_CSR) Endpoint Type (Read/Write) Mask */
#define UDP_CSR_EPTYPE(value)               (UDP_CSR_EPTYPE_Msk & ((value) << UDP_CSR_EPTYPE_Pos))
#define   UDP_CSR_EPTYPE_CTRL_Val           _U_(0x0)                                       /**< (UDP_CSR) Control  */
#define   UDP_CSR_EPTYPE_ISO_OUT_Val        _U_(0x1)                                       /**< (UDP_CSR) Isochronous OUT  */
#define   UDP_CSR_EPTYPE_BULK_OUT_Val       _U_(0x2)                                       /**< (UDP_CSR) Bulk OUT  */
#define   UDP_CSR_EPTYPE_INT_OUT_Val        _U_(0x3)                                       /**< (UDP_CSR) Interrupt OUT  */
#define   UDP_CSR_EPTYPE_ISO_IN_Val         _U_(0x5)                                       /**< (UDP_CSR) Isochronous IN  */
#define   UDP_CSR_EPTYPE_BULK_IN_Val        _U_(0x6)                                       /**< (UDP_CSR) Bulk IN  */
#define   UDP_CSR_EPTYPE_INT_IN_Val         _U_(0x7)                                       /**< (UDP_CSR) Interrupt IN  */
#define UDP_CSR_EPTYPE_CTRL                 (UDP_CSR_EPTYPE_CTRL_Val << UDP_CSR_EPTYPE_Pos)  /**< (UDP_CSR) Control Position  */
#define UDP_CSR_EPTYPE_ISO_OUT              (UDP_CSR_EPTYPE_ISO_OUT_Val << UDP_CSR_EPTYPE_Pos)  /**< (UDP_CSR) Isochronous OUT Position  */
#define UDP_CSR_EPTYPE_BULK_OUT             (UDP_CSR_EPTYPE_BULK_OUT_Val << UDP_CSR_EPTYPE_Pos)  /**< (UDP_CSR) Bulk OUT Position  */
#define UDP_CSR_EPTYPE_INT_OUT              (UDP_CSR_EPTYPE_INT_OUT_Val << UDP_CSR_EPTYPE_Pos)  /**< (UDP_CSR) Interrupt OUT Position  */
#define UDP_CSR_EPTYPE_ISO_IN               (UDP_CSR_EPTYPE_ISO_IN_Val << UDP_CSR_EPTYPE_Pos)  /**< (UDP_CSR) Isochronous IN Position  */
#define UDP_CSR_EPTYPE_BULK_IN              (UDP_CSR_EPTYPE_BULK_IN_Val << UDP_CSR_EPTYPE_Pos)  /**< (UDP_CSR) Bulk IN Position  */
#define UDP_CSR_EPTYPE_INT_IN               (UDP_CSR_EPTYPE_INT_IN_Val << UDP_CSR_EPTYPE_Pos)  /**< (UDP_CSR) Interrupt IN Position  */
#define UDP_CSR_DTGLE_Pos                   11                                             /**< (UDP_CSR) Data Toggle (Read-only) Position */
#define UDP_CSR_DTGLE_Msk                   (_U_(0x1) << UDP_CSR_DTGLE_Pos)                /**< (UDP_CSR) Data Toggle (Read-only) Mask */
#define UDP_CSR_DTGLE                       UDP_CSR_DTGLE_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_CSR_DTGLE_Msk instead */
#define UDP_CSR_EPEDS_Pos                   15                                             /**< (UDP_CSR) Endpoint Enable Disable Position */
#define UDP_CSR_EPEDS_Msk                   (_U_(0x1) << UDP_CSR_EPEDS_Pos)                /**< (UDP_CSR) Endpoint Enable Disable Mask */
#define UDP_CSR_EPEDS                       UDP_CSR_EPEDS_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_CSR_EPEDS_Msk instead */
#define UDP_CSR_RXBYTECNT_Pos               16                                             /**< (UDP_CSR) Number of Bytes Available in the FIFO (Read-only) Position */
#define UDP_CSR_RXBYTECNT_Msk               (_U_(0x7FF) << UDP_CSR_RXBYTECNT_Pos)          /**< (UDP_CSR) Number of Bytes Available in the FIFO (Read-only) Mask */
#define UDP_CSR_RXBYTECNT(value)            (UDP_CSR_RXBYTECNT_Msk & ((value) << UDP_CSR_RXBYTECNT_Pos))
#define UDP_CSR_MASK                        _U_(0x7FF8FFF)                                 /**< \deprecated (UDP_CSR) Register MASK  (Use UDP_CSR_Msk instead)  */
#define UDP_CSR_Msk                         _U_(0x7FF8FFF)                                 /**< (UDP_CSR) Register Mask  */


/* -------- UDP_FDR : (UDP Offset: 0x50) (R/W 32) Endpoint FIFO Data Register 0 -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t FIFO_DATA:8;               /**< bit:   0..7  FIFO Data Value                          */
    uint32_t :24;                       /**< bit:  8..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UDP_FDR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UDP_FDR_OFFSET                      (0x50)                                        /**<  (UDP_FDR) Endpoint FIFO Data Register 0  Offset */

#define UDP_FDR_FIFO_DATA_Pos               0                                              /**< (UDP_FDR) FIFO Data Value Position */
#define UDP_FDR_FIFO_DATA_Msk               (_U_(0xFF) << UDP_FDR_FIFO_DATA_Pos)           /**< (UDP_FDR) FIFO Data Value Mask */
#define UDP_FDR_FIFO_DATA(value)            (UDP_FDR_FIFO_DATA_Msk & ((value) << UDP_FDR_FIFO_DATA_Pos))
#define UDP_FDR_MASK                        _U_(0xFF)                                      /**< \deprecated (UDP_FDR) Register MASK  (Use UDP_FDR_Msk instead)  */
#define UDP_FDR_Msk                         _U_(0xFF)                                      /**< (UDP_FDR) Register Mask  */


/* -------- UDP_TXVC : (UDP Offset: 0x74) (R/W 32) Transceiver Control Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t :8;                        /**< bit:   0..7  Reserved */
    uint32_t TXVDIS:1;                  /**< bit:      8  Transceiver Disable                      */
    uint32_t PUON:1;                    /**< bit:      9  Pull-up On                               */
    uint32_t :22;                       /**< bit: 10..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} UDP_TXVC_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define UDP_TXVC_OFFSET                     (0x74)                                        /**<  (UDP_TXVC) Transceiver Control Register  Offset */

#define UDP_TXVC_TXVDIS_Pos                 8                                              /**< (UDP_TXVC) Transceiver Disable Position */
#define UDP_TXVC_TXVDIS_Msk                 (_U_(0x1) << UDP_TXVC_TXVDIS_Pos)              /**< (UDP_TXVC) Transceiver Disable Mask */
#define UDP_TXVC_TXVDIS                     UDP_TXVC_TXVDIS_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_TXVC_TXVDIS_Msk instead */
#define UDP_TXVC_PUON_Pos                   9                                              /**< (UDP_TXVC) Pull-up On Position */
#define UDP_TXVC_PUON_Msk                   (_U_(0x1) << UDP_TXVC_PUON_Pos)                /**< (UDP_TXVC) Pull-up On Mask */
#define UDP_TXVC_PUON                       UDP_TXVC_PUON_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use UDP_TXVC_PUON_Msk instead */
#define UDP_TXVC_MASK                       _U_(0x300)                                     /**< \deprecated (UDP_TXVC) Register MASK  (Use UDP_TXVC_Msk instead)  */
#define UDP_TXVC_Msk                        _U_(0x300)                                     /**< (UDP_TXVC) Register Mask  */


#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'R'
/** \brief UDP hardware registers */
typedef struct {  
  __I  uint32_t UDP_FRM_NUM;    /**< (UDP Offset: 0x00) Frame Number Register */
  __IO uint32_t UDP_GLB_STAT;   /**< (UDP Offset: 0x04) Global State Register */
  __IO uint32_t UDP_FADDR;      /**< (UDP Offset: 0x08) Function Address Register */
  RoReg8  Reserved1[0x4];
  __O  uint32_t UDP_IER;        /**< (UDP Offset: 0x10) Interrupt Enable Register */
  __O  uint32_t UDP_IDR;        /**< (UDP Offset: 0x14) Interrupt Disable Register */
  __I  uint32_t UDP_IMR;        /**< (UDP Offset: 0x18) Interrupt Mask Register */
  __I  uint32_t UDP_ISR;        /**< (UDP Offset: 0x1C) Interrupt Status Register */
  __O  uint32_t UDP_ICR;        /**< (UDP Offset: 0x20) Interrupt Clear Register */
  RoReg8  Reserved2[0x4];
  __IO uint32_t UDP_RST_EP;     /**< (UDP Offset: 0x28) Reset Endpoint Register */
  RoReg8  Reserved3[0x4];
  __IO uint32_t UDP_CSR[6];     /**< (UDP Offset: 0x30) Endpoint Control and Status Register 0 */
  RoReg8  Reserved4[0x8];
  __IO uint32_t UDP_FDR[6];     /**< (UDP Offset: 0x50) Endpoint FIFO Data Register 0 */
  RoReg8  Reserved5[0xC];
  __IO uint32_t UDP_TXVC;       /**< (UDP Offset: 0x74) Transceiver Control Register */
} Udp;

#elif COMPONENT_TYPEDEF_STYLE == 'N'
/** \brief UDP hardware registers */
typedef struct {  
  __I  UDP_FRM_NUM_Type               UDP_FRM_NUM;    /**< Offset: 0x00 (R/   32) Frame Number Register */
  __IO UDP_GLB_STAT_Type              UDP_GLB_STAT;   /**< Offset: 0x04 (R/W  32) Global State Register */
  __IO UDP_FADDR_Type                 UDP_FADDR;      /**< Offset: 0x08 (R/W  32) Function Address Register */
  __I  uint32_t                       Reserved1[1];
  __O  UDP_IER_Type                   UDP_IER;        /**< Offset: 0x10 ( /W  32) Interrupt Enable Register */
  __O  UDP_IDR_Type                   UDP_IDR;        /**< Offset: 0x14 ( /W  32) Interrupt Disable Register */
  __I  UDP_IMR_Type                   UDP_IMR;        /**< Offset: 0x18 (R/   32) Interrupt Mask Register */
  __I  UDP_ISR_Type                   UDP_ISR;        /**< Offset: 0x1C (R/   32) Interrupt Status Register */
  __O  UDP_ICR_Type                   UDP_ICR;        /**< Offset: 0x20 ( /W  32) Interrupt Clear Register */
  __I  uint32_t                       Reserved2[1];
  __IO UDP_RST_EP_Type                UDP_RST_EP;     /**< Offset: 0x28 (R/W  32) Reset Endpoint Register */
  __I  uint32_t                       Reserved3[1];
  __IO UDP_CSR_Type                   UDP_CSR[6];     /**< Offset: 0x30 (R/W  32) Endpoint Control and Status Register 0 */
  __I  uint32_t                       Reserved4[2];
  __IO UDP_FDR_Type                   UDP_FDR[6];     /**< Offset: 0x50 (R/W  32) Endpoint FIFO Data Register 0 */
  __I  uint32_t                       Reserved5[3];
  __IO UDP_TXVC_Type                  UDP_TXVC;       /**< Offset: 0x74 (R/W  32) Transceiver Control Register */
} Udp;

#else /* COMPONENT_TYPEDEF_STYLE */
#error Unknown component typedef style
#endif /* COMPONENT_TYPEDEF_STYLE */

#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
/** @}  end of USB Device Port */

#endif /* _SAMG55_UDP_COMPONENT_H_ */
