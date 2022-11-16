/**
 * \file
 *
 * \brief Peripheral I/O description for SAMG55J19
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
#ifndef _SAMG55J19_PIO_H_
#define _SAMG55J19_PIO_H_

/* ========== Peripheral I/O pin numbers ========== */
#define PIN_PA0                     (  0)  /**< Pin Number for PA0 */
#define PIN_PA1                     (  1)  /**< Pin Number for PA1 */
#define PIN_PA2                     (  2)  /**< Pin Number for PA2 */
#define PIN_PA3                     (  3)  /**< Pin Number for PA3 */
#define PIN_PA4                     (  4)  /**< Pin Number for PA4 */
#define PIN_PA5                     (  5)  /**< Pin Number for PA5 */
#define PIN_PA6                     (  6)  /**< Pin Number for PA6 */
#define PIN_PA7                     (  7)  /**< Pin Number for PA7 */
#define PIN_PA8                     (  8)  /**< Pin Number for PA8 */
#define PIN_PA9                     (  9)  /**< Pin Number for PA9 */
#define PIN_PA10                    ( 10)  /**< Pin Number for PA10 */
#define PIN_PA11                    ( 11)  /**< Pin Number for PA11 */
#define PIN_PA12                    ( 12)  /**< Pin Number for PA12 */
#define PIN_PA13                    ( 13)  /**< Pin Number for PA13 */
#define PIN_PA14                    ( 14)  /**< Pin Number for PA14 */
#define PIN_PA15                    ( 15)  /**< Pin Number for PA15 */
#define PIN_PA16                    ( 16)  /**< Pin Number for PA16 */
#define PIN_PA17                    ( 17)  /**< Pin Number for PA17 */
#define PIN_PA18                    ( 18)  /**< Pin Number for PA18 */
#define PIN_PA19                    ( 19)  /**< Pin Number for PA19 */
#define PIN_PA20                    ( 20)  /**< Pin Number for PA20 */
#define PIN_PA21                    ( 21)  /**< Pin Number for PA21 */
#define PIN_PA22                    ( 22)  /**< Pin Number for PA22 */
#define PIN_PA23                    ( 23)  /**< Pin Number for PA23 */
#define PIN_PA24                    ( 24)  /**< Pin Number for PA24 */
#define PIN_PA25                    ( 25)  /**< Pin Number for PA25 */
#define PIN_PA26                    ( 26)  /**< Pin Number for PA26 */
#define PIN_PA27                    ( 27)  /**< Pin Number for PA27 */
#define PIN_PA28                    ( 28)  /**< Pin Number for PA28 */
#define PIN_PA29                    ( 29)  /**< Pin Number for PA29 */
#define PIN_PA30                    ( 30)  /**< Pin Number for PA30 */
#define PIN_PA31                    ( 31)  /**< Pin Number for PA31 */
#define PIN_PB0                     ( 32)  /**< Pin Number for PB0 */
#define PIN_PB1                     ( 33)  /**< Pin Number for PB1 */
#define PIN_PB2                     ( 34)  /**< Pin Number for PB2 */
#define PIN_PB3                     ( 35)  /**< Pin Number for PB3 */
#define PIN_PB4                     ( 36)  /**< Pin Number for PB4 */
#define PIN_PB5                     ( 37)  /**< Pin Number for PB5 */
#define PIN_PB6                     ( 38)  /**< Pin Number for PB6 */
#define PIN_PB7                     ( 39)  /**< Pin Number for PB7 */
#define PIN_PB8                     ( 40)  /**< Pin Number for PB8 */
#define PIN_PB9                     ( 41)  /**< Pin Number for PB9 */
#define PIN_PB10                    ( 42)  /**< Pin Number for PB10 */
#define PIN_PB11                    ( 43)  /**< Pin Number for PB11 */
#define PIN_PB12                    ( 44)  /**< Pin Number for PB12 */
#define PIN_PB13                    ( 45)  /**< Pin Number for PB13 */
#define PIN_PB14                    ( 46)  /**< Pin Number for PB14 */
#define PIN_PB15                    ( 47)  /**< Pin Number for PB15 */


/* ========== Peripheral I/O masks ========== */
#define PIO_PA0                     (_U_(1) << 0) /**< PIO Mask for PA0 */
#define PIO_PA1                     (_U_(1) << 1) /**< PIO Mask for PA1 */
#define PIO_PA2                     (_U_(1) << 2) /**< PIO Mask for PA2 */
#define PIO_PA3                     (_U_(1) << 3) /**< PIO Mask for PA3 */
#define PIO_PA4                     (_U_(1) << 4) /**< PIO Mask for PA4 */
#define PIO_PA5                     (_U_(1) << 5) /**< PIO Mask for PA5 */
#define PIO_PA6                     (_U_(1) << 6) /**< PIO Mask for PA6 */
#define PIO_PA7                     (_U_(1) << 7) /**< PIO Mask for PA7 */
#define PIO_PA8                     (_U_(1) << 8) /**< PIO Mask for PA8 */
#define PIO_PA9                     (_U_(1) << 9) /**< PIO Mask for PA9 */
#define PIO_PA10                    (_U_(1) << 10) /**< PIO Mask for PA10 */
#define PIO_PA11                    (_U_(1) << 11) /**< PIO Mask for PA11 */
#define PIO_PA12                    (_U_(1) << 12) /**< PIO Mask for PA12 */
#define PIO_PA13                    (_U_(1) << 13) /**< PIO Mask for PA13 */
#define PIO_PA14                    (_U_(1) << 14) /**< PIO Mask for PA14 */
#define PIO_PA15                    (_U_(1) << 15) /**< PIO Mask for PA15 */
#define PIO_PA16                    (_U_(1) << 16) /**< PIO Mask for PA16 */
#define PIO_PA17                    (_U_(1) << 17) /**< PIO Mask for PA17 */
#define PIO_PA18                    (_U_(1) << 18) /**< PIO Mask for PA18 */
#define PIO_PA19                    (_U_(1) << 19) /**< PIO Mask for PA19 */
#define PIO_PA20                    (_U_(1) << 20) /**< PIO Mask for PA20 */
#define PIO_PA21                    (_U_(1) << 21) /**< PIO Mask for PA21 */
#define PIO_PA22                    (_U_(1) << 22) /**< PIO Mask for PA22 */
#define PIO_PA23                    (_U_(1) << 23) /**< PIO Mask for PA23 */
#define PIO_PA24                    (_U_(1) << 24) /**< PIO Mask for PA24 */
#define PIO_PA25                    (_U_(1) << 25) /**< PIO Mask for PA25 */
#define PIO_PA26                    (_U_(1) << 26) /**< PIO Mask for PA26 */
#define PIO_PA27                    (_U_(1) << 27) /**< PIO Mask for PA27 */
#define PIO_PA28                    (_U_(1) << 28) /**< PIO Mask for PA28 */
#define PIO_PA29                    (_U_(1) << 29) /**< PIO Mask for PA29 */
#define PIO_PA30                    (_U_(1) << 30) /**< PIO Mask for PA30 */
#define PIO_PA31                    (_U_(1) << 31) /**< PIO Mask for PA31 */
#define PIO_PB0                     (_U_(1) << 0) /**< PIO Mask for PB0 */
#define PIO_PB1                     (_U_(1) << 1) /**< PIO Mask for PB1 */
#define PIO_PB2                     (_U_(1) << 2) /**< PIO Mask for PB2 */
#define PIO_PB3                     (_U_(1) << 3) /**< PIO Mask for PB3 */
#define PIO_PB4                     (_U_(1) << 4) /**< PIO Mask for PB4 */
#define PIO_PB5                     (_U_(1) << 5) /**< PIO Mask for PB5 */
#define PIO_PB6                     (_U_(1) << 6) /**< PIO Mask for PB6 */
#define PIO_PB7                     (_U_(1) << 7) /**< PIO Mask for PB7 */
#define PIO_PB8                     (_U_(1) << 8) /**< PIO Mask for PB8 */
#define PIO_PB9                     (_U_(1) << 9) /**< PIO Mask for PB9 */
#define PIO_PB10                    (_U_(1) << 10) /**< PIO Mask for PB10 */
#define PIO_PB11                    (_U_(1) << 11) /**< PIO Mask for PB11 */
#define PIO_PB12                    (_U_(1) << 12) /**< PIO Mask for PB12 */
#define PIO_PB13                    (_U_(1) << 13) /**< PIO Mask for PB13 */
#define PIO_PB14                    (_U_(1) << 14) /**< PIO Mask for PB14 */
#define PIO_PB15                    (_U_(1) << 15) /**< PIO Mask for PB15 */


/* ========== Peripheral I/O indexes ========== */
#define PIO_PA0_IDX                 (  0)  /**< PIO Index Number for PA0 */
#define PIO_PA1_IDX                 (  1)  /**< PIO Index Number for PA1 */
#define PIO_PA2_IDX                 (  2)  /**< PIO Index Number for PA2 */
#define PIO_PA3_IDX                 (  3)  /**< PIO Index Number for PA3 */
#define PIO_PA4_IDX                 (  4)  /**< PIO Index Number for PA4 */
#define PIO_PA5_IDX                 (  5)  /**< PIO Index Number for PA5 */
#define PIO_PA6_IDX                 (  6)  /**< PIO Index Number for PA6 */
#define PIO_PA7_IDX                 (  7)  /**< PIO Index Number for PA7 */
#define PIO_PA8_IDX                 (  8)  /**< PIO Index Number for PA8 */
#define PIO_PA9_IDX                 (  9)  /**< PIO Index Number for PA9 */
#define PIO_PA10_IDX                ( 10)  /**< PIO Index Number for PA10 */
#define PIO_PA11_IDX                ( 11)  /**< PIO Index Number for PA11 */
#define PIO_PA12_IDX                ( 12)  /**< PIO Index Number for PA12 */
#define PIO_PA13_IDX                ( 13)  /**< PIO Index Number for PA13 */
#define PIO_PA14_IDX                ( 14)  /**< PIO Index Number for PA14 */
#define PIO_PA15_IDX                ( 15)  /**< PIO Index Number for PA15 */
#define PIO_PA16_IDX                ( 16)  /**< PIO Index Number for PA16 */
#define PIO_PA17_IDX                ( 17)  /**< PIO Index Number for PA17 */
#define PIO_PA18_IDX                ( 18)  /**< PIO Index Number for PA18 */
#define PIO_PA19_IDX                ( 19)  /**< PIO Index Number for PA19 */
#define PIO_PA20_IDX                ( 20)  /**< PIO Index Number for PA20 */
#define PIO_PA21_IDX                ( 21)  /**< PIO Index Number for PA21 */
#define PIO_PA22_IDX                ( 22)  /**< PIO Index Number for PA22 */
#define PIO_PA23_IDX                ( 23)  /**< PIO Index Number for PA23 */
#define PIO_PA24_IDX                ( 24)  /**< PIO Index Number for PA24 */
#define PIO_PA25_IDX                ( 25)  /**< PIO Index Number for PA25 */
#define PIO_PA26_IDX                ( 26)  /**< PIO Index Number for PA26 */
#define PIO_PA27_IDX                ( 27)  /**< PIO Index Number for PA27 */
#define PIO_PA28_IDX                ( 28)  /**< PIO Index Number for PA28 */
#define PIO_PA29_IDX                ( 29)  /**< PIO Index Number for PA29 */
#define PIO_PA30_IDX                ( 30)  /**< PIO Index Number for PA30 */
#define PIO_PA31_IDX                ( 31)  /**< PIO Index Number for PA31 */
#define PIO_PB0_IDX                 ( 32)  /**< PIO Index Number for PB0 */
#define PIO_PB1_IDX                 ( 33)  /**< PIO Index Number for PB1 */
#define PIO_PB2_IDX                 ( 34)  /**< PIO Index Number for PB2 */
#define PIO_PB3_IDX                 ( 35)  /**< PIO Index Number for PB3 */
#define PIO_PB4_IDX                 ( 36)  /**< PIO Index Number for PB4 */
#define PIO_PB5_IDX                 ( 37)  /**< PIO Index Number for PB5 */
#define PIO_PB6_IDX                 ( 38)  /**< PIO Index Number for PB6 */
#define PIO_PB7_IDX                 ( 39)  /**< PIO Index Number for PB7 */
#define PIO_PB8_IDX                 ( 40)  /**< PIO Index Number for PB8 */
#define PIO_PB9_IDX                 ( 41)  /**< PIO Index Number for PB9 */
#define PIO_PB10_IDX                ( 42)  /**< PIO Index Number for PB10 */
#define PIO_PB11_IDX                ( 43)  /**< PIO Index Number for PB11 */
#define PIO_PB12_IDX                ( 44)  /**< PIO Index Number for PB12 */
#define PIO_PB13_IDX                ( 45)  /**< PIO Index Number for PB13 */
#define PIO_PB14_IDX                ( 46)  /**< PIO Index Number for PB14 */
#define PIO_PB15_IDX                ( 47)  /**< PIO Index Number for PB15 */

/* ========== PIO definition for ADC peripheral ========== */
#define PIN_PA8B_ADC_ADTRG                         _L_(8)       /**< ADC signal: ADTRG on PA8 mux B*/
#define MUX_PA8B_ADC_ADTRG                         _L_(1)       /**< ADC signal line function value: ADTRG */
#define PIO_PA8B_ADC_ADTRG                         (_UL_(1) << 8)

#define PIN_PA17X1_ADC_AD0                         _L_(17)      /**< ADC signal: AD0 on PA17 mux X1*/
#define PIO_PA17X1_ADC_AD0                         (_UL_(1) << 17)

#define PIN_PA18X1_ADC_AD1                         _L_(18)      /**< ADC signal: AD1 on PA18 mux X1*/
#define PIO_PA18X1_ADC_AD1                         (_UL_(1) << 18)

#define PIN_PA19X1_ADC_AD2                         _L_(19)      /**< ADC signal: AD2 on PA19 mux X1*/
#define PIO_PA19X1_ADC_AD2                         (_UL_(1) << 19)

#define PIN_PA20X1_ADC_AD3                         _L_(20)      /**< ADC signal: AD3 on PA20 mux X1*/
#define PIO_PA20X1_ADC_AD3                         (_UL_(1) << 20)

#define PIN_PB0X1_ADC_AD4                          _L_(32)      /**< ADC signal: AD4 on PB0 mux X1*/
#define PIO_PB0X1_ADC_AD4                          (_UL_(1) << 0)

#define PIN_PB1X1_ADC_AD5                          _L_(33)      /**< ADC signal: AD5 on PB1 mux X1*/
#define PIO_PB1X1_ADC_AD5                          (_UL_(1) << 1)

#define PIN_PB2X1_ADC_AD6                          _L_(34)      /**< ADC signal: AD6 on PB2 mux X1*/
#define PIO_PB2X1_ADC_AD6                          (_UL_(1) << 2)

#define PIN_PB2X1_ADC_WKUP12                       _L_(34)      /**< ADC signal: WKUP12 on PB2 mux X1*/
#define PIO_PB2X1_ADC_WKUP12                       (_UL_(1) << 2)

#define PIN_PB3X1_ADC_AD7                          _L_(35)      /**< ADC signal: AD7 on PB3 mux X1*/
#define PIO_PB3X1_ADC_AD7                          (_UL_(1) << 3)

#define PIN_PB3X1_ADC_WKUP13                       _L_(35)      /**< ADC signal: WKUP13 on PB3 mux X1*/
#define PIO_PB3X1_ADC_WKUP13                       (_UL_(1) << 3)

/* ========== PIO definition for FLEXCOM0 peripheral ========== */
#define PIN_PA9A_FLEXCOM0_RXD                      _L_(9)       /**< FLEXCOM0 signal: RXD on PA9 mux A*/
#define MUX_PA9A_FLEXCOM0_RXD                      _L_(0)       /**< FLEXCOM0 signal line function value: RXD */
#define PIO_PA9A_FLEXCOM0_RXD                      (_UL_(1) << 9)

#define PIN_PA9A_FLEXCOM0_MISO                     _L_(9)       /**< FLEXCOM0 signal: MISO on PA9 mux A*/
#define MUX_PA9A_FLEXCOM0_MISO                     _L_(0)       /**< FLEXCOM0 signal line function value: MISO */
#define PIO_PA9A_FLEXCOM0_MISO                     (_UL_(1) << 9)

#define PIN_PA9A_FLEXCOM0_TWCK                     _L_(9)       /**< FLEXCOM0 signal: TWCK on PA9 mux A*/
#define MUX_PA9A_FLEXCOM0_TWCK                     _L_(0)       /**< FLEXCOM0 signal line function value: TWCK */
#define PIO_PA9A_FLEXCOM0_TWCK                     (_UL_(1) << 9)

#define PIN_PB0A_FLEXCOM0_SCK                      _L_(32)      /**< FLEXCOM0 signal: SCK on PB0 mux A*/
#define MUX_PB0A_FLEXCOM0_SCK                      _L_(0)       /**< FLEXCOM0 signal line function value: SCK */
#define PIO_PB0A_FLEXCOM0_SCK                      (_UL_(1) << 0)

#define PIN_PB0A_FLEXCOM0_SPCK                     _L_(32)      /**< FLEXCOM0 signal: SPCK on PB0 mux A*/
#define MUX_PB0A_FLEXCOM0_SPCK                     _L_(0)       /**< FLEXCOM0 signal line function value: SPCK */
#define PIO_PB0A_FLEXCOM0_SPCK                     (_UL_(1) << 0)

#define PIN_PA25A_FLEXCOM0_NPCS                    _L_(25)      /**< FLEXCOM0 signal: NPCS on PA25 mux A*/
#define MUX_PA25A_FLEXCOM0_NPCS                    _L_(0)       /**< FLEXCOM0 signal line function value: NPCS */
#define PIO_PA25A_FLEXCOM0_NPCS                    (_UL_(1) << 25)

#define PIN_PA25A_FLEXCOM0_CTS                     _L_(25)      /**< FLEXCOM0 signal: CTS on PA25 mux A*/
#define MUX_PA25A_FLEXCOM0_CTS                     _L_(0)       /**< FLEXCOM0 signal line function value: CTS */
#define PIO_PA25A_FLEXCOM0_CTS                     (_UL_(1) << 25)

#define PIN_PA26A_FLEXCOM0_NPCS                    _L_(26)      /**< FLEXCOM0 signal: NPCS on PA26 mux A*/
#define MUX_PA26A_FLEXCOM0_NPCS                    _L_(0)       /**< FLEXCOM0 signal line function value: NPCS */
#define PIO_PA26A_FLEXCOM0_NPCS                    (_UL_(1) << 26)

#define PIN_PA26A_FLEXCOM0_RTS                     _L_(26)      /**< FLEXCOM0 signal: RTS on PA26 mux A*/
#define MUX_PA26A_FLEXCOM0_RTS                     _L_(0)       /**< FLEXCOM0 signal line function value: RTS */
#define PIO_PA26A_FLEXCOM0_RTS                     (_UL_(1) << 26)

#define PIN_PA10A_FLEXCOM0_TXD                     _L_(10)      /**< FLEXCOM0 signal: TXD on PA10 mux A*/
#define MUX_PA10A_FLEXCOM0_TXD                     _L_(0)       /**< FLEXCOM0 signal line function value: TXD */
#define PIO_PA10A_FLEXCOM0_TXD                     (_UL_(1) << 10)

#define PIN_PA10A_FLEXCOM0_MOSI                    _L_(10)      /**< FLEXCOM0 signal: MOSI on PA10 mux A*/
#define MUX_PA10A_FLEXCOM0_MOSI                    _L_(0)       /**< FLEXCOM0 signal line function value: MOSI */
#define PIO_PA10A_FLEXCOM0_MOSI                    (_UL_(1) << 10)

#define PIN_PA10A_FLEXCOM0_TWD                     _L_(10)      /**< FLEXCOM0 signal: TWD on PA10 mux A*/
#define MUX_PA10A_FLEXCOM0_TWD                     _L_(0)       /**< FLEXCOM0 signal line function value: TWD */
#define PIO_PA10A_FLEXCOM0_TWD                     (_UL_(1) << 10)

/* ========== PIO definition for FLEXCOM1 peripheral ========== */
#define PIN_PB2A_FLEXCOM1_RXD                      _L_(34)      /**< FLEXCOM1 signal: RXD on PB2 mux A*/
#define MUX_PB2A_FLEXCOM1_RXD                      _L_(0)       /**< FLEXCOM1 signal line function value: RXD */
#define PIO_PB2A_FLEXCOM1_RXD                      (_UL_(1) << 2)

#define PIN_PB2A_FLEXCOM1_MISO                     _L_(34)      /**< FLEXCOM1 signal: MISO on PB2 mux A*/
#define MUX_PB2A_FLEXCOM1_MISO                     _L_(0)       /**< FLEXCOM1 signal line function value: MISO */
#define PIO_PB2A_FLEXCOM1_MISO                     (_UL_(1) << 2)

#define PIN_PB2A_FLEXCOM1_TWCK                     _L_(34)      /**< FLEXCOM1 signal: TWCK on PB2 mux A*/
#define MUX_PB2A_FLEXCOM1_TWCK                     _L_(0)       /**< FLEXCOM1 signal line function value: TWCK */
#define PIO_PB2A_FLEXCOM1_TWCK                     (_UL_(1) << 2)

#define PIN_PA27A_FLEXCOM1_SCK                     _L_(27)      /**< FLEXCOM1 signal: SCK on PA27 mux A*/
#define MUX_PA27A_FLEXCOM1_SCK                     _L_(0)       /**< FLEXCOM1 signal line function value: SCK */
#define PIO_PA27A_FLEXCOM1_SCK                     (_UL_(1) << 27)

#define PIN_PA27A_FLEXCOM1_SPCK                    _L_(27)      /**< FLEXCOM1 signal: SPCK on PA27 mux A*/
#define MUX_PA27A_FLEXCOM1_SPCK                    _L_(0)       /**< FLEXCOM1 signal line function value: SPCK */
#define PIO_PA27A_FLEXCOM1_SPCK                    (_UL_(1) << 27)

#define PIN_PA28A_FLEXCOM1_NPCS                    _L_(28)      /**< FLEXCOM1 signal: NPCS on PA28 mux A*/
#define MUX_PA28A_FLEXCOM1_NPCS                    _L_(0)       /**< FLEXCOM1 signal line function value: NPCS */
#define PIO_PA28A_FLEXCOM1_NPCS                    (_UL_(1) << 28)

#define PIN_PA28A_FLEXCOM1_CTS                     _L_(28)      /**< FLEXCOM1 signal: CTS on PA28 mux A*/
#define MUX_PA28A_FLEXCOM1_CTS                     _L_(0)       /**< FLEXCOM1 signal line function value: CTS */
#define PIO_PA28A_FLEXCOM1_CTS                     (_UL_(1) << 28)

#define PIN_PA29A_FLEXCOM1_NPCS                    _L_(29)      /**< FLEXCOM1 signal: NPCS on PA29 mux A*/
#define MUX_PA29A_FLEXCOM1_NPCS                    _L_(0)       /**< FLEXCOM1 signal line function value: NPCS */
#define PIO_PA29A_FLEXCOM1_NPCS                    (_UL_(1) << 29)

#define PIN_PA29A_FLEXCOM1_RTS                     _L_(29)      /**< FLEXCOM1 signal: RTS on PA29 mux A*/
#define MUX_PA29A_FLEXCOM1_RTS                     _L_(0)       /**< FLEXCOM1 signal line function value: RTS */
#define PIO_PA29A_FLEXCOM1_RTS                     (_UL_(1) << 29)

#define PIN_PB3A_FLEXCOM1_TXD                      _L_(35)      /**< FLEXCOM1 signal: TXD on PB3 mux A*/
#define MUX_PB3A_FLEXCOM1_TXD                      _L_(0)       /**< FLEXCOM1 signal line function value: TXD */
#define PIO_PB3A_FLEXCOM1_TXD                      (_UL_(1) << 3)

#define PIN_PB3A_FLEXCOM1_MOSI                     _L_(35)      /**< FLEXCOM1 signal: MOSI on PB3 mux A*/
#define MUX_PB3A_FLEXCOM1_MOSI                     _L_(0)       /**< FLEXCOM1 signal line function value: MOSI */
#define PIO_PB3A_FLEXCOM1_MOSI                     (_UL_(1) << 3)

#define PIN_PB3A_FLEXCOM1_TWD                      _L_(35)      /**< FLEXCOM1 signal: TWD on PB3 mux A*/
#define MUX_PB3A_FLEXCOM1_TWD                      _L_(0)       /**< FLEXCOM1 signal line function value: TWD */
#define PIO_PB3A_FLEXCOM1_TWD                      (_UL_(1) << 3)

/* ========== PIO definition for FLEXCOM2 peripheral ========== */
#define PIN_PA5A_FLEXCOM2_RXD                      _L_(5)       /**< FLEXCOM2 signal: RXD on PA5 mux A*/
#define MUX_PA5A_FLEXCOM2_RXD                      _L_(0)       /**< FLEXCOM2 signal line function value: RXD */
#define PIO_PA5A_FLEXCOM2_RXD                      (_UL_(1) << 5)

#define PIN_PA5A_FLEXCOM2_MISO                     _L_(5)       /**< FLEXCOM2 signal: MISO on PA5 mux A*/
#define MUX_PA5A_FLEXCOM2_MISO                     _L_(0)       /**< FLEXCOM2 signal line function value: MISO */
#define PIO_PA5A_FLEXCOM2_MISO                     (_UL_(1) << 5)

#define PIN_PA5A_FLEXCOM2_TWCK                     _L_(5)       /**< FLEXCOM2 signal: TWCK on PA5 mux A*/
#define MUX_PA5A_FLEXCOM2_TWCK                     _L_(0)       /**< FLEXCOM2 signal line function value: TWCK */
#define PIO_PA5A_FLEXCOM2_TWCK                     (_UL_(1) << 5)

#define PIN_PA24B_FLEXCOM2_SCK                     _L_(24)      /**< FLEXCOM2 signal: SCK on PA24 mux B*/
#define MUX_PA24B_FLEXCOM2_SCK                     _L_(1)       /**< FLEXCOM2 signal line function value: SCK */
#define PIO_PA24B_FLEXCOM2_SCK                     (_UL_(1) << 24)

#define PIN_PA15B_FLEXCOM2_SPCK                    _L_(15)      /**< FLEXCOM2 signal: SPCK on PA15 mux B*/
#define MUX_PA15B_FLEXCOM2_SPCK                    _L_(1)       /**< FLEXCOM2 signal line function value: SPCK */
#define PIO_PA15B_FLEXCOM2_SPCK                    (_UL_(1) << 15)

#define PIN_PA15B_FLEXCOM2_SCK                     _L_(15)      /**< FLEXCOM2 signal: SCK on PA15 mux B*/
#define MUX_PA15B_FLEXCOM2_SCK                     _L_(1)       /**< FLEXCOM2 signal line function value: SCK */
#define PIO_PA15B_FLEXCOM2_SCK                     (_UL_(1) << 15)

#define PIN_PA24B_FLEXCOM2_SPCK                    _L_(24)      /**< FLEXCOM2 signal: SPCK on PA24 mux B*/
#define MUX_PA24B_FLEXCOM2_SPCK                    _L_(1)       /**< FLEXCOM2 signal line function value: SPCK */
#define PIO_PA24B_FLEXCOM2_SPCK                    (_UL_(1) << 24)

#define PIN_PA16A_FLEXCOM2_NPCS                    _L_(16)      /**< FLEXCOM2 signal: NPCS on PA16 mux A*/
#define MUX_PA16A_FLEXCOM2_NPCS                    _L_(0)       /**< FLEXCOM2 signal line function value: NPCS */
#define PIO_PA16A_FLEXCOM2_NPCS                    (_UL_(1) << 16)

#define PIN_PA16A_FLEXCOM2_CTS                     _L_(16)      /**< FLEXCOM2 signal: CTS on PA16 mux A*/
#define MUX_PA16A_FLEXCOM2_CTS                     _L_(0)       /**< FLEXCOM2 signal line function value: CTS */
#define PIO_PA16A_FLEXCOM2_CTS                     (_UL_(1) << 16)

#define PIN_PA15A_FLEXCOM2_NPCS                    _L_(15)      /**< FLEXCOM2 signal: NPCS on PA15 mux A*/
#define MUX_PA15A_FLEXCOM2_NPCS                    _L_(0)       /**< FLEXCOM2 signal line function value: NPCS */
#define PIO_PA15A_FLEXCOM2_NPCS                    (_UL_(1) << 15)

#define PIN_PA15A_FLEXCOM2_RTS                     _L_(15)      /**< FLEXCOM2 signal: RTS on PA15 mux A*/
#define MUX_PA15A_FLEXCOM2_RTS                     _L_(0)       /**< FLEXCOM2 signal line function value: RTS */
#define PIO_PA15A_FLEXCOM2_RTS                     (_UL_(1) << 15)

#define PIN_PA6A_FLEXCOM2_TXD                      _L_(6)       /**< FLEXCOM2 signal: TXD on PA6 mux A*/
#define MUX_PA6A_FLEXCOM2_TXD                      _L_(0)       /**< FLEXCOM2 signal line function value: TXD */
#define PIO_PA6A_FLEXCOM2_TXD                      (_UL_(1) << 6)

#define PIN_PA6A_FLEXCOM2_MOSI                     _L_(6)       /**< FLEXCOM2 signal: MOSI on PA6 mux A*/
#define MUX_PA6A_FLEXCOM2_MOSI                     _L_(0)       /**< FLEXCOM2 signal line function value: MOSI */
#define PIO_PA6A_FLEXCOM2_MOSI                     (_UL_(1) << 6)

#define PIN_PA6A_FLEXCOM2_TWD                      _L_(6)       /**< FLEXCOM2 signal: TWD on PA6 mux A*/
#define MUX_PA6A_FLEXCOM2_TWD                      _L_(0)       /**< FLEXCOM2 signal line function value: TWD */
#define PIO_PA6A_FLEXCOM2_TWD                      (_UL_(1) << 6)

/* ========== PIO definition for FLEXCOM3 peripheral ========== */
#define PIN_PA4A_FLEXCOM3_RXD                      _L_(4)       /**< FLEXCOM3 signal: RXD on PA4 mux A*/
#define MUX_PA4A_FLEXCOM3_RXD                      _L_(0)       /**< FLEXCOM3 signal line function value: RXD */
#define PIO_PA4A_FLEXCOM3_RXD                      (_UL_(1) << 4)

#define PIN_PA4A_FLEXCOM3_MISO                     _L_(4)       /**< FLEXCOM3 signal: MISO on PA4 mux A*/
#define MUX_PA4A_FLEXCOM3_MISO                     _L_(0)       /**< FLEXCOM3 signal line function value: MISO */
#define PIO_PA4A_FLEXCOM3_MISO                     (_UL_(1) << 4)

#define PIN_PA4A_FLEXCOM3_TWCK                     _L_(4)       /**< FLEXCOM3 signal: TWCK on PA4 mux A*/
#define MUX_PA4A_FLEXCOM3_TWCK                     _L_(0)       /**< FLEXCOM3 signal line function value: TWCK */
#define PIO_PA4A_FLEXCOM3_TWCK                     (_UL_(1) << 4)

#define PIN_PB13A_FLEXCOM3_SCK                     _L_(45)      /**< FLEXCOM3 signal: SCK on PB13 mux A*/
#define MUX_PB13A_FLEXCOM3_SCK                     _L_(0)       /**< FLEXCOM3 signal line function value: SCK */
#define PIO_PB13A_FLEXCOM3_SCK                     (_UL_(1) << 13)

#define PIN_PB13A_FLEXCOM3_SPCK                    _L_(45)      /**< FLEXCOM3 signal: SPCK on PB13 mux A*/
#define MUX_PB13A_FLEXCOM3_SPCK                    _L_(0)       /**< FLEXCOM3 signal line function value: SPCK */
#define PIO_PB13A_FLEXCOM3_SPCK                    (_UL_(1) << 13)

#define PIN_PB14A_FLEXCOM3_NPCS                    _L_(46)      /**< FLEXCOM3 signal: NPCS on PB14 mux A*/
#define MUX_PB14A_FLEXCOM3_NPCS                    _L_(0)       /**< FLEXCOM3 signal line function value: NPCS */
#define PIO_PB14A_FLEXCOM3_NPCS                    (_UL_(1) << 14)

#define PIN_PB14A_FLEXCOM3_CTS                     _L_(46)      /**< FLEXCOM3 signal: CTS on PB14 mux A*/
#define MUX_PB14A_FLEXCOM3_CTS                     _L_(0)       /**< FLEXCOM3 signal line function value: CTS */
#define PIO_PB14A_FLEXCOM3_CTS                     (_UL_(1) << 14)

#define PIN_PB15A_FLEXCOM3_NPCS                    _L_(47)      /**< FLEXCOM3 signal: NPCS on PB15 mux A*/
#define MUX_PB15A_FLEXCOM3_NPCS                    _L_(0)       /**< FLEXCOM3 signal line function value: NPCS */
#define PIO_PB15A_FLEXCOM3_NPCS                    (_UL_(1) << 15)

#define PIN_PB15A_FLEXCOM3_RTS                     _L_(47)      /**< FLEXCOM3 signal: RTS on PB15 mux A*/
#define MUX_PB15A_FLEXCOM3_RTS                     _L_(0)       /**< FLEXCOM3 signal line function value: RTS */
#define PIO_PB15A_FLEXCOM3_RTS                     (_UL_(1) << 15)

#define PIN_PA3A_FLEXCOM3_TXD                      _L_(3)       /**< FLEXCOM3 signal: TXD on PA3 mux A*/
#define MUX_PA3A_FLEXCOM3_TXD                      _L_(0)       /**< FLEXCOM3 signal line function value: TXD */
#define PIO_PA3A_FLEXCOM3_TXD                      (_UL_(1) << 3)

#define PIN_PA3A_FLEXCOM3_MOSI                     _L_(3)       /**< FLEXCOM3 signal: MOSI on PA3 mux A*/
#define MUX_PA3A_FLEXCOM3_MOSI                     _L_(0)       /**< FLEXCOM3 signal line function value: MOSI */
#define PIO_PA3A_FLEXCOM3_MOSI                     (_UL_(1) << 3)

#define PIN_PA3A_FLEXCOM3_TWD                      _L_(3)       /**< FLEXCOM3 signal: TWD on PA3 mux A*/
#define MUX_PA3A_FLEXCOM3_TWD                      _L_(0)       /**< FLEXCOM3 signal line function value: TWD */
#define PIO_PA3A_FLEXCOM3_TWD                      (_UL_(1) << 3)

/* ========== PIO definition for FLEXCOM4 peripheral ========== */
#define PIN_PB9A_FLEXCOM4_RXD                      _L_(41)      /**< FLEXCOM4 signal: RXD on PB9 mux A*/
#define MUX_PB9A_FLEXCOM4_RXD                      _L_(0)       /**< FLEXCOM4 signal line function value: RXD */
#define PIO_PB9A_FLEXCOM4_RXD                      (_UL_(1) << 9)

#define PIN_PB9A_FLEXCOM4_MISO                     _L_(41)      /**< FLEXCOM4 signal: MISO on PB9 mux A*/
#define MUX_PB9A_FLEXCOM4_MISO                     _L_(0)       /**< FLEXCOM4 signal line function value: MISO */
#define PIO_PB9A_FLEXCOM4_MISO                     (_UL_(1) << 9)

#define PIN_PB9A_FLEXCOM4_TWCK                     _L_(41)      /**< FLEXCOM4 signal: TWCK on PB9 mux A*/
#define MUX_PB9A_FLEXCOM4_TWCK                     _L_(0)       /**< FLEXCOM4 signal line function value: TWCK */
#define PIO_PB9A_FLEXCOM4_TWCK                     (_UL_(1) << 9)

#define PIN_PB11A_FLEXCOM4_RXD                     _L_(43)      /**< FLEXCOM4 signal: RXD on PB11 mux A*/
#define MUX_PB11A_FLEXCOM4_RXD                     _L_(0)       /**< FLEXCOM4 signal line function value: RXD */
#define PIO_PB11A_FLEXCOM4_RXD                     (_UL_(1) << 11)

#define PIN_PB11A_FLEXCOM4_MISO                    _L_(43)      /**< FLEXCOM4 signal: MISO on PB11 mux A*/
#define MUX_PB11A_FLEXCOM4_MISO                    _L_(0)       /**< FLEXCOM4 signal line function value: MISO */
#define PIO_PB11A_FLEXCOM4_MISO                    (_UL_(1) << 11)

#define PIN_PB11A_FLEXCOM4_TWCK                    _L_(43)      /**< FLEXCOM4 signal: TWCK on PB11 mux A*/
#define MUX_PB11A_FLEXCOM4_TWCK                    _L_(0)       /**< FLEXCOM4 signal line function value: TWCK */
#define PIO_PB11A_FLEXCOM4_TWCK                    (_UL_(1) << 11)

#define PIN_PB1A_FLEXCOM4_SCK                      _L_(33)      /**< FLEXCOM4 signal: SCK on PB1 mux A*/
#define MUX_PB1A_FLEXCOM4_SCK                      _L_(0)       /**< FLEXCOM4 signal line function value: SCK */
#define PIO_PB1A_FLEXCOM4_SCK                      (_UL_(1) << 1)

#define PIN_PB1A_FLEXCOM4_SPCK                     _L_(33)      /**< FLEXCOM4 signal: SPCK on PB1 mux A*/
#define MUX_PB1A_FLEXCOM4_SPCK                     _L_(0)       /**< FLEXCOM4 signal line function value: SPCK */
#define PIO_PB1A_FLEXCOM4_SPCK                     (_UL_(1) << 1)

#define PIN_PB8B_FLEXCOM4_NPCS                     _L_(40)      /**< FLEXCOM4 signal: NPCS on PB8 mux B*/
#define MUX_PB8B_FLEXCOM4_NPCS                     _L_(1)       /**< FLEXCOM4 signal line function value: NPCS */
#define PIO_PB8B_FLEXCOM4_NPCS                     (_UL_(1) << 8)

#define PIN_PB8B_FLEXCOM4_CTS                      _L_(40)      /**< FLEXCOM4 signal: CTS on PB8 mux B*/
#define MUX_PB8B_FLEXCOM4_CTS                      _L_(1)       /**< FLEXCOM4 signal line function value: CTS */
#define PIO_PB8B_FLEXCOM4_CTS                      (_UL_(1) << 8)

#define PIN_PB9B_FLEXCOM4_NPCS                     _L_(41)      /**< FLEXCOM4 signal: NPCS on PB9 mux B*/
#define MUX_PB9B_FLEXCOM4_NPCS                     _L_(1)       /**< FLEXCOM4 signal line function value: NPCS */
#define PIO_PB9B_FLEXCOM4_NPCS                     (_UL_(1) << 9)

#define PIN_PB9B_FLEXCOM4_RTS                      _L_(41)      /**< FLEXCOM4 signal: RTS on PB9 mux B*/
#define MUX_PB9B_FLEXCOM4_RTS                      _L_(1)       /**< FLEXCOM4 signal line function value: RTS */
#define PIO_PB9B_FLEXCOM4_RTS                      (_UL_(1) << 9)

#define PIN_PB8A_FLEXCOM4_TXD                      _L_(40)      /**< FLEXCOM4 signal: TXD on PB8 mux A*/
#define MUX_PB8A_FLEXCOM4_TXD                      _L_(0)       /**< FLEXCOM4 signal line function value: TXD */
#define PIO_PB8A_FLEXCOM4_TXD                      (_UL_(1) << 8)

#define PIN_PB8A_FLEXCOM4_MOSI                     _L_(40)      /**< FLEXCOM4 signal: MOSI on PB8 mux A*/
#define MUX_PB8A_FLEXCOM4_MOSI                     _L_(0)       /**< FLEXCOM4 signal line function value: MOSI */
#define PIO_PB8A_FLEXCOM4_MOSI                     (_UL_(1) << 8)

#define PIN_PB8A_FLEXCOM4_TWD                      _L_(40)      /**< FLEXCOM4 signal: TWD on PB8 mux A*/
#define MUX_PB8A_FLEXCOM4_TWD                      _L_(0)       /**< FLEXCOM4 signal line function value: TWD */
#define PIO_PB8A_FLEXCOM4_TWD                      (_UL_(1) << 8)

#define PIN_PB10A_FLEXCOM4_TXD                     _L_(42)      /**< FLEXCOM4 signal: TXD on PB10 mux A*/
#define MUX_PB10A_FLEXCOM4_TXD                     _L_(0)       /**< FLEXCOM4 signal line function value: TXD */
#define PIO_PB10A_FLEXCOM4_TXD                     (_UL_(1) << 10)

#define PIN_PB10A_FLEXCOM4_MOSI                    _L_(42)      /**< FLEXCOM4 signal: MOSI on PB10 mux A*/
#define MUX_PB10A_FLEXCOM4_MOSI                    _L_(0)       /**< FLEXCOM4 signal line function value: MOSI */
#define PIO_PB10A_FLEXCOM4_MOSI                    (_UL_(1) << 10)

#define PIN_PB10A_FLEXCOM4_TWD                     _L_(42)      /**< FLEXCOM4 signal: TWD on PB10 mux A*/
#define MUX_PB10A_FLEXCOM4_TWD                     _L_(0)       /**< FLEXCOM4 signal line function value: TWD */
#define PIO_PB10A_FLEXCOM4_TWD                     (_UL_(1) << 10)

/* ========== PIO definition for FLEXCOM5 peripheral ========== */
#define PIN_PA12A_FLEXCOM5_RXD                     _L_(12)      /**< FLEXCOM5 signal: RXD on PA12 mux A*/
#define MUX_PA12A_FLEXCOM5_RXD                     _L_(0)       /**< FLEXCOM5 signal line function value: RXD */
#define PIO_PA12A_FLEXCOM5_RXD                     (_UL_(1) << 12)

#define PIN_PA12A_FLEXCOM5_MISO                    _L_(12)      /**< FLEXCOM5 signal: MISO on PA12 mux A*/
#define MUX_PA12A_FLEXCOM5_MISO                    _L_(0)       /**< FLEXCOM5 signal line function value: MISO */
#define PIO_PA12A_FLEXCOM5_MISO                    (_UL_(1) << 12)

#define PIN_PA12A_FLEXCOM5_TWCK                    _L_(12)      /**< FLEXCOM5 signal: TWCK on PA12 mux A*/
#define MUX_PA12A_FLEXCOM5_TWCK                    _L_(0)       /**< FLEXCOM5 signal line function value: TWCK */
#define PIO_PA12A_FLEXCOM5_TWCK                    (_UL_(1) << 12)

#define PIN_PA14A_FLEXCOM5_SCK                     _L_(14)      /**< FLEXCOM5 signal: SCK on PA14 mux A*/
#define MUX_PA14A_FLEXCOM5_SCK                     _L_(0)       /**< FLEXCOM5 signal line function value: SCK */
#define PIO_PA14A_FLEXCOM5_SCK                     (_UL_(1) << 14)

#define PIN_PA14A_FLEXCOM5_SPCK                    _L_(14)      /**< FLEXCOM5 signal: SPCK on PA14 mux A*/
#define MUX_PA14A_FLEXCOM5_SPCK                    _L_(0)       /**< FLEXCOM5 signal line function value: SPCK */
#define PIO_PA14A_FLEXCOM5_SPCK                    (_UL_(1) << 14)

#define PIN_PA11A_FLEXCOM5_NPCS                    _L_(11)      /**< FLEXCOM5 signal: NPCS on PA11 mux A*/
#define MUX_PA11A_FLEXCOM5_NPCS                    _L_(0)       /**< FLEXCOM5 signal line function value: NPCS */
#define PIO_PA11A_FLEXCOM5_NPCS                    (_UL_(1) << 11)

#define PIN_PA11A_FLEXCOM5_CTS                     _L_(11)      /**< FLEXCOM5 signal: CTS on PA11 mux A*/
#define MUX_PA11A_FLEXCOM5_CTS                     _L_(0)       /**< FLEXCOM5 signal line function value: CTS */
#define PIO_PA11A_FLEXCOM5_CTS                     (_UL_(1) << 11)

#define PIN_PA5B_FLEXCOM5_NPCS                     _L_(5)       /**< FLEXCOM5 signal: NPCS on PA5 mux B*/
#define MUX_PA5B_FLEXCOM5_NPCS                     _L_(1)       /**< FLEXCOM5 signal line function value: NPCS */
#define PIO_PA5B_FLEXCOM5_NPCS                     (_UL_(1) << 5)

#define PIN_PA5B_FLEXCOM5_RTS                      _L_(5)       /**< FLEXCOM5 signal: RTS on PA5 mux B*/
#define MUX_PA5B_FLEXCOM5_RTS                      _L_(1)       /**< FLEXCOM5 signal line function value: RTS */
#define PIO_PA5B_FLEXCOM5_RTS                      (_UL_(1) << 5)

#define PIN_PB2B_FLEXCOM5_NPCS                     _L_(34)      /**< FLEXCOM5 signal: NPCS on PB2 mux B*/
#define MUX_PB2B_FLEXCOM5_NPCS                     _L_(1)       /**< FLEXCOM5 signal line function value: NPCS */
#define PIO_PB2B_FLEXCOM5_NPCS                     (_UL_(1) << 2)

#define PIN_PB2B_FLEXCOM5_RTS                      _L_(34)      /**< FLEXCOM5 signal: RTS on PB2 mux B*/
#define MUX_PB2B_FLEXCOM5_RTS                      _L_(1)       /**< FLEXCOM5 signal line function value: RTS */
#define PIO_PB2B_FLEXCOM5_RTS                      (_UL_(1) << 2)

#define PIN_PA13A_FLEXCOM5_TXD                     _L_(13)      /**< FLEXCOM5 signal: TXD on PA13 mux A*/
#define MUX_PA13A_FLEXCOM5_TXD                     _L_(0)       /**< FLEXCOM5 signal line function value: TXD */
#define PIO_PA13A_FLEXCOM5_TXD                     (_UL_(1) << 13)

#define PIN_PA13A_FLEXCOM5_MOSI                    _L_(13)      /**< FLEXCOM5 signal: MOSI on PA13 mux A*/
#define MUX_PA13A_FLEXCOM5_MOSI                    _L_(0)       /**< FLEXCOM5 signal line function value: MOSI */
#define PIO_PA13A_FLEXCOM5_MOSI                    (_UL_(1) << 13)

#define PIN_PA13A_FLEXCOM5_TWD                     _L_(13)      /**< FLEXCOM5 signal: TWD on PA13 mux A*/
#define MUX_PA13A_FLEXCOM5_TWD                     _L_(0)       /**< FLEXCOM5 signal line function value: TWD */
#define PIO_PA13A_FLEXCOM5_TWD                     (_UL_(1) << 13)

/* ========== PIO definition for FLEXCOM6 peripheral ========== */
#define PIN_PB1B_FLEXCOM6_RXD                      _L_(33)      /**< FLEXCOM6 signal: RXD on PB1 mux B*/
#define MUX_PB1B_FLEXCOM6_RXD                      _L_(1)       /**< FLEXCOM6 signal line function value: RXD */
#define PIO_PB1B_FLEXCOM6_RXD                      (_UL_(1) << 1)

#define PIN_PB1B_FLEXCOM6_MISO                     _L_(33)      /**< FLEXCOM6 signal: MISO on PB1 mux B*/
#define MUX_PB1B_FLEXCOM6_MISO                     _L_(1)       /**< FLEXCOM6 signal line function value: MISO */
#define PIO_PB1B_FLEXCOM6_MISO                     (_UL_(1) << 1)

#define PIN_PB1B_FLEXCOM6_TWCK                     _L_(33)      /**< FLEXCOM6 signal: TWCK on PB1 mux B*/
#define MUX_PB1B_FLEXCOM6_TWCK                     _L_(1)       /**< FLEXCOM6 signal line function value: TWCK */
#define PIO_PB1B_FLEXCOM6_TWCK                     (_UL_(1) << 1)

#define PIN_PB11B_FLEXCOM6_RXD                     _L_(43)      /**< FLEXCOM6 signal: RXD on PB11 mux B*/
#define MUX_PB11B_FLEXCOM6_RXD                     _L_(1)       /**< FLEXCOM6 signal line function value: RXD */
#define PIO_PB11B_FLEXCOM6_RXD                     (_UL_(1) << 11)

#define PIN_PB11B_FLEXCOM6_MISO                    _L_(43)      /**< FLEXCOM6 signal: MISO on PB11 mux B*/
#define MUX_PB11B_FLEXCOM6_MISO                    _L_(1)       /**< FLEXCOM6 signal line function value: MISO */
#define PIO_PB11B_FLEXCOM6_MISO                    (_UL_(1) << 11)

#define PIN_PB11B_FLEXCOM6_TWCK                    _L_(43)      /**< FLEXCOM6 signal: TWCK on PB11 mux B*/
#define MUX_PB11B_FLEXCOM6_TWCK                    _L_(1)       /**< FLEXCOM6 signal line function value: TWCK */
#define PIO_PB11B_FLEXCOM6_TWCK                    (_UL_(1) << 11)

#define PIN_PB13B_FLEXCOM6_SCK                     _L_(45)      /**< FLEXCOM6 signal: SCK on PB13 mux B*/
#define MUX_PB13B_FLEXCOM6_SCK                     _L_(1)       /**< FLEXCOM6 signal line function value: SCK */
#define PIO_PB13B_FLEXCOM6_SCK                     (_UL_(1) << 13)

#define PIN_PB13B_FLEXCOM6_SPCK                    _L_(45)      /**< FLEXCOM6 signal: SPCK on PB13 mux B*/
#define MUX_PB13B_FLEXCOM6_SPCK                    _L_(1)       /**< FLEXCOM6 signal line function value: SPCK */
#define PIO_PB13B_FLEXCOM6_SPCK                    (_UL_(1) << 13)

#define PIN_PB14B_FLEXCOM6_NPCS                    _L_(46)      /**< FLEXCOM6 signal: NPCS on PB14 mux B*/
#define MUX_PB14B_FLEXCOM6_NPCS                    _L_(1)       /**< FLEXCOM6 signal line function value: NPCS */
#define PIO_PB14B_FLEXCOM6_NPCS                    (_UL_(1) << 14)

#define PIN_PB14B_FLEXCOM6_CTS                     _L_(46)      /**< FLEXCOM6 signal: CTS on PB14 mux B*/
#define MUX_PB14B_FLEXCOM6_CTS                     _L_(1)       /**< FLEXCOM6 signal line function value: CTS */
#define PIO_PB14B_FLEXCOM6_CTS                     (_UL_(1) << 14)

#define PIN_PB15B_FLEXCOM6_NPCS                    _L_(47)      /**< FLEXCOM6 signal: NPCS on PB15 mux B*/
#define MUX_PB15B_FLEXCOM6_NPCS                    _L_(1)       /**< FLEXCOM6 signal line function value: NPCS */
#define PIO_PB15B_FLEXCOM6_NPCS                    (_UL_(1) << 15)

#define PIN_PB15B_FLEXCOM6_RTS                     _L_(47)      /**< FLEXCOM6 signal: RTS on PB15 mux B*/
#define MUX_PB15B_FLEXCOM6_RTS                     _L_(1)       /**< FLEXCOM6 signal line function value: RTS */
#define PIO_PB15B_FLEXCOM6_RTS                     (_UL_(1) << 15)

#define PIN_PB0B_FLEXCOM6_TXD                      _L_(32)      /**< FLEXCOM6 signal: TXD on PB0 mux B*/
#define MUX_PB0B_FLEXCOM6_TXD                      _L_(1)       /**< FLEXCOM6 signal line function value: TXD */
#define PIO_PB0B_FLEXCOM6_TXD                      (_UL_(1) << 0)

#define PIN_PB0B_FLEXCOM6_MOSI                     _L_(32)      /**< FLEXCOM6 signal: MOSI on PB0 mux B*/
#define MUX_PB0B_FLEXCOM6_MOSI                     _L_(1)       /**< FLEXCOM6 signal line function value: MOSI */
#define PIO_PB0B_FLEXCOM6_MOSI                     (_UL_(1) << 0)

#define PIN_PB0B_FLEXCOM6_TWD                      _L_(32)      /**< FLEXCOM6 signal: TWD on PB0 mux B*/
#define MUX_PB0B_FLEXCOM6_TWD                      _L_(1)       /**< FLEXCOM6 signal line function value: TWD */
#define PIO_PB0B_FLEXCOM6_TWD                      (_UL_(1) << 0)

#define PIN_PB10B_FLEXCOM6_TXD                     _L_(42)      /**< FLEXCOM6 signal: TXD on PB10 mux B*/
#define MUX_PB10B_FLEXCOM6_TXD                     _L_(1)       /**< FLEXCOM6 signal line function value: TXD */
#define PIO_PB10B_FLEXCOM6_TXD                     (_UL_(1) << 10)

#define PIN_PB10B_FLEXCOM6_MOSI                    _L_(42)      /**< FLEXCOM6 signal: MOSI on PB10 mux B*/
#define MUX_PB10B_FLEXCOM6_MOSI                    _L_(1)       /**< FLEXCOM6 signal line function value: MOSI */
#define PIO_PB10B_FLEXCOM6_MOSI                    (_UL_(1) << 10)

#define PIN_PB10B_FLEXCOM6_TWD                     _L_(42)      /**< FLEXCOM6 signal: TWD on PB10 mux B*/
#define MUX_PB10B_FLEXCOM6_TWD                     _L_(1)       /**< FLEXCOM6 signal line function value: TWD */
#define PIO_PB10B_FLEXCOM6_TWD                     (_UL_(1) << 10)

/* ========== PIO definition for FLEXCOM7 peripheral ========== */
#define PIN_PA27B_FLEXCOM7_RXD                     _L_(27)      /**< FLEXCOM7 signal: RXD on PA27 mux B*/
#define MUX_PA27B_FLEXCOM7_RXD                     _L_(1)       /**< FLEXCOM7 signal line function value: RXD */
#define PIO_PA27B_FLEXCOM7_RXD                     (_UL_(1) << 27)

#define PIN_PA27B_FLEXCOM7_MISO                    _L_(27)      /**< FLEXCOM7 signal: MISO on PA27 mux B*/
#define MUX_PA27B_FLEXCOM7_MISO                    _L_(1)       /**< FLEXCOM7 signal line function value: MISO */
#define PIO_PA27B_FLEXCOM7_MISO                    (_UL_(1) << 27)

#define PIN_PA27B_FLEXCOM7_TWCK                    _L_(27)      /**< FLEXCOM7 signal: TWCK on PA27 mux B*/
#define MUX_PA27B_FLEXCOM7_TWCK                    _L_(1)       /**< FLEXCOM7 signal line function value: TWCK */
#define PIO_PA27B_FLEXCOM7_TWCK                    (_UL_(1) << 27)

#define PIN_PA29B_FLEXCOM7_SCK                     _L_(29)      /**< FLEXCOM7 signal: SCK on PA29 mux B*/
#define MUX_PA29B_FLEXCOM7_SCK                     _L_(1)       /**< FLEXCOM7 signal line function value: SCK */
#define PIO_PA29B_FLEXCOM7_SCK                     (_UL_(1) << 29)

#define PIN_PA29B_FLEXCOM7_SPCK                    _L_(29)      /**< FLEXCOM7 signal: SPCK on PA29 mux B*/
#define MUX_PA29B_FLEXCOM7_SPCK                    _L_(1)       /**< FLEXCOM7 signal line function value: SPCK */
#define PIO_PA29B_FLEXCOM7_SPCK                    (_UL_(1) << 29)

#define PIN_PA30B_FLEXCOM7_NPCS                    _L_(30)      /**< FLEXCOM7 signal: NPCS on PA30 mux B*/
#define MUX_PA30B_FLEXCOM7_NPCS                    _L_(1)       /**< FLEXCOM7 signal line function value: NPCS */
#define PIO_PA30B_FLEXCOM7_NPCS                    (_UL_(1) << 30)

#define PIN_PA30B_FLEXCOM7_CTS                     _L_(30)      /**< FLEXCOM7 signal: CTS on PA30 mux B*/
#define MUX_PA30B_FLEXCOM7_CTS                     _L_(1)       /**< FLEXCOM7 signal line function value: CTS */
#define PIO_PA30B_FLEXCOM7_CTS                     (_UL_(1) << 30)

#define PIN_PA31B_FLEXCOM7_NPCS                    _L_(31)      /**< FLEXCOM7 signal: NPCS on PA31 mux B*/
#define MUX_PA31B_FLEXCOM7_NPCS                    _L_(1)       /**< FLEXCOM7 signal line function value: NPCS */
#define PIO_PA31B_FLEXCOM7_NPCS                    (_UL_(1) << 31)

#define PIN_PA31B_FLEXCOM7_RTS                     _L_(31)      /**< FLEXCOM7 signal: RTS on PA31 mux B*/
#define MUX_PA31B_FLEXCOM7_RTS                     _L_(1)       /**< FLEXCOM7 signal line function value: RTS */
#define PIO_PA31B_FLEXCOM7_RTS                     (_UL_(1) << 31)

#define PIN_PA28B_FLEXCOM7_TXD                     _L_(28)      /**< FLEXCOM7 signal: TXD on PA28 mux B*/
#define MUX_PA28B_FLEXCOM7_TXD                     _L_(1)       /**< FLEXCOM7 signal line function value: TXD */
#define PIO_PA28B_FLEXCOM7_TXD                     (_UL_(1) << 28)

#define PIN_PA28B_FLEXCOM7_MOSI                    _L_(28)      /**< FLEXCOM7 signal: MOSI on PA28 mux B*/
#define MUX_PA28B_FLEXCOM7_MOSI                    _L_(1)       /**< FLEXCOM7 signal line function value: MOSI */
#define PIO_PA28B_FLEXCOM7_MOSI                    (_UL_(1) << 28)

#define PIN_PA28B_FLEXCOM7_TWD                     _L_(28)      /**< FLEXCOM7 signal: TWD on PA28 mux B*/
#define MUX_PA28B_FLEXCOM7_TWD                     _L_(1)       /**< FLEXCOM7 signal line function value: TWD */
#define PIO_PA28B_FLEXCOM7_TWD                     (_UL_(1) << 28)

/* ========== PIO definition for I2SC0 peripheral ========== */
#define PIN_PA0A_I2SC0_I2SCK0                      _L_(0)       /**< I2SC0 signal: I2SCK0 on PA0 mux A*/
#define MUX_PA0A_I2SC0_I2SCK0                      _L_(0)       /**< I2SC0 signal line function value: I2SCK0 */
#define PIO_PA0A_I2SC0_I2SCK0                      (_UL_(1) << 0)

#define PIN_PA2B_I2SC0_I2SDI0                      _L_(2)       /**< I2SC0 signal: I2SDI0 on PA2 mux B*/
#define MUX_PA2B_I2SC0_I2SDI0                      _L_(1)       /**< I2SC0 signal line function value: I2SDI0 */
#define PIO_PA2B_I2SC0_I2SDI0                      (_UL_(1) << 2)

#define PIN_PA3B_I2SC0_I2SDO0                      _L_(3)       /**< I2SC0 signal: I2SDO0 on PA3 mux B*/
#define MUX_PA3B_I2SC0_I2SDO0                      _L_(1)       /**< I2SC0 signal line function value: I2SDO0 */
#define PIO_PA3B_I2SC0_I2SDO0                      (_UL_(1) << 3)

#define PIN_PA17A_I2SC0_I2SDO0                     _L_(17)      /**< I2SC0 signal: I2SDO0 on PA17 mux A*/
#define MUX_PA17A_I2SC0_I2SDO0                     _L_(0)       /**< I2SC0 signal line function value: I2SDO0 */
#define PIO_PA17A_I2SC0_I2SDO0                     (_UL_(1) << 17)

#define PIN_PA4B_I2SC0_I2SMCK0                     _L_(4)       /**< I2SC0 signal: I2SMCK0 on PA4 mux B*/
#define MUX_PA4B_I2SC0_I2SMCK0                     _L_(1)       /**< I2SC0 signal line function value: I2SMCK0 */
#define PIO_PA4B_I2SC0_I2SMCK0                     (_UL_(1) << 4)

#define PIN_PA18A_I2SC0_I2SMCK0                    _L_(18)      /**< I2SC0 signal: I2SMCK0 on PA18 mux A*/
#define MUX_PA18A_I2SC0_I2SMCK0                    _L_(0)       /**< I2SC0 signal line function value: I2SMCK0 */
#define PIO_PA18A_I2SC0_I2SMCK0                    (_UL_(1) << 18)

#define PIN_PA1A_I2SC0_I2SWS0                      _L_(1)       /**< I2SC0 signal: I2SWS0 on PA1 mux A*/
#define MUX_PA1A_I2SC0_I2SWS0                      _L_(0)       /**< I2SC0 signal line function value: I2SWS0 */
#define PIO_PA1A_I2SC0_I2SWS0                      (_UL_(1) << 1)

/* ========== PIO definition for I2SC1 peripheral ========== */
#define PIN_PA19B_I2SC1_I2SCK1                     _L_(19)      /**< I2SC1 signal: I2SCK1 on PA19 mux B*/
#define MUX_PA19B_I2SC1_I2SCK1                     _L_(1)       /**< I2SC1 signal line function value: I2SCK1 */
#define PIO_PA19B_I2SC1_I2SCK1                     (_UL_(1) << 19)

#define PIN_PA22B_I2SC1_I2SDI1                     _L_(22)      /**< I2SC1 signal: I2SDI1 on PA22 mux B*/
#define MUX_PA22B_I2SC1_I2SDI1                     _L_(1)       /**< I2SC1 signal line function value: I2SDI1 */
#define PIO_PA22B_I2SC1_I2SDI1                     (_UL_(1) << 22)

#define PIN_PA23A_I2SC1_I2SDO1                     _L_(23)      /**< I2SC1 signal: I2SDO1 on PA23 mux A*/
#define MUX_PA23A_I2SC1_I2SDO1                     _L_(0)       /**< I2SC1 signal line function value: I2SDO1 */
#define PIO_PA23A_I2SC1_I2SDO1                     (_UL_(1) << 23)

#define PIN_PA25B_I2SC1_I2SDO1                     _L_(25)      /**< I2SC1 signal: I2SDO1 on PA25 mux B*/
#define MUX_PA25B_I2SC1_I2SDO1                     _L_(1)       /**< I2SC1 signal line function value: I2SDO1 */
#define PIO_PA25B_I2SC1_I2SDO1                     (_UL_(1) << 25)

#define PIN_PA24A_I2SC1_I2SMCK1                    _L_(24)      /**< I2SC1 signal: I2SMCK1 on PA24 mux A*/
#define MUX_PA24A_I2SC1_I2SMCK1                    _L_(0)       /**< I2SC1 signal line function value: I2SMCK1 */
#define PIO_PA24A_I2SC1_I2SMCK1                    (_UL_(1) << 24)

#define PIN_PA26B_I2SC1_I2SMCK1                    _L_(26)      /**< I2SC1 signal: I2SMCK1 on PA26 mux B*/
#define MUX_PA26B_I2SC1_I2SMCK1                    _L_(1)       /**< I2SC1 signal line function value: I2SMCK1 */
#define PIO_PA26B_I2SC1_I2SMCK1                    (_UL_(1) << 26)

#define PIN_PA20B_I2SC1_I2SWS1                     _L_(20)      /**< I2SC1 signal: I2SWS1 on PA20 mux B*/
#define MUX_PA20B_I2SC1_I2SWS1                     _L_(1)       /**< I2SC1 signal line function value: I2SWS1 */
#define PIO_PA20B_I2SC1_I2SWS1                     (_UL_(1) << 20)

/* ========== PIO definition for PDMIC0 peripheral ========== */
#define PIN_PA10B_PDMIC0_PDMIC0_CLK                _L_(10)      /**< PDMIC0 signal: PDMIC0_CLK on PA10 mux B*/
#define MUX_PA10B_PDMIC0_PDMIC0_CLK                _L_(1)       /**< PDMIC0 signal line function value: PDMIC0_CLK */
#define PIO_PA10B_PDMIC0_PDMIC0_CLK                (_UL_(1) << 10)

#define PIN_PA9B_PDMIC0_PDMIC0_DAT                 _L_(9)       /**< PDMIC0 signal: PDMIC0_DAT on PA9 mux B*/
#define MUX_PA9B_PDMIC0_PDMIC0_DAT                 _L_(1)       /**< PDMIC0 signal line function value: PDMIC0_DAT */
#define PIO_PA9B_PDMIC0_PDMIC0_DAT                 (_UL_(1) << 9)

/* ========== PIO definition for PMC peripheral ========== */
#define PIN_PA6B_PMC_PCK0                          _L_(6)       /**< PMC signal: PCK0 on PA6 mux B*/
#define MUX_PA6B_PMC_PCK0                          _L_(1)       /**< PMC signal line function value: PCK0 */
#define PIO_PA6B_PMC_PCK0                          (_UL_(1) << 6)

#define PIN_PA17B_PMC_PCK1                         _L_(17)      /**< PMC signal: PCK1 on PA17 mux B*/
#define MUX_PA17B_PMC_PCK1                         _L_(1)       /**< PMC signal line function value: PCK1 */
#define PIO_PA17B_PMC_PCK1                         (_UL_(1) << 17)

#define PIN_PA21B_PMC_PCK1                         _L_(21)      /**< PMC signal: PCK1 on PA21 mux B*/
#define MUX_PA21B_PMC_PCK1                         _L_(1)       /**< PMC signal line function value: PCK1 */
#define PIO_PA21B_PMC_PCK1                         (_UL_(1) << 21)

#define PIN_PA30A_PMC_PCK1                         _L_(30)      /**< PMC signal: PCK1 on PA30 mux A*/
#define MUX_PA30A_PMC_PCK1                         _L_(0)       /**< PMC signal line function value: PCK1 */
#define PIO_PA30A_PMC_PCK1                         (_UL_(1) << 30)

#define PIN_PA18B_PMC_PCK2                         _L_(18)      /**< PMC signal: PCK2 on PA18 mux B*/
#define MUX_PA18B_PMC_PCK2                         _L_(1)       /**< PMC signal line function value: PCK2 */
#define PIO_PA18B_PMC_PCK2                         (_UL_(1) << 18)

#define PIN_PA31A_PMC_PCK2                         _L_(31)      /**< PMC signal: PCK2 on PA31 mux A*/
#define MUX_PA31A_PMC_PCK2                         _L_(0)       /**< PMC signal line function value: PCK2 */
#define PIO_PA31A_PMC_PCK2                         (_UL_(1) << 31)

#define PIN_PB3B_PMC_PCK2                          _L_(35)      /**< PMC signal: PCK2 on PB3 mux B*/
#define MUX_PB3B_PMC_PCK2                          _L_(1)       /**< PMC signal line function value: PCK2 */
#define PIO_PB3B_PMC_PCK2                          (_UL_(1) << 3)

/* ========== PIO definition for SPI0 peripheral ========== */
#define PIN_PA9A_SPI0_RXD0                         _L_(9)       /**< SPI0 signal: RXD0 on PA9 mux A*/
#define MUX_PA9A_SPI0_RXD0                         _L_(0)       /**< SPI0 signal line function value: RXD0 */
#define PIO_PA9A_SPI0_RXD0                         (_UL_(1) << 9)

#define PIN_PA9A_SPI0_SPI0_MISO                    _L_(9)       /**< SPI0 signal: SPI0_MISO on PA9 mux A*/
#define MUX_PA9A_SPI0_SPI0_MISO                    _L_(0)       /**< SPI0 signal line function value: SPI0_MISO */
#define PIO_PA9A_SPI0_SPI0_MISO                    (_UL_(1) << 9)

#define PIN_PA9A_SPI0_TWCK0                        _L_(9)       /**< SPI0 signal: TWCK0 on PA9 mux A*/
#define MUX_PA9A_SPI0_TWCK0                        _L_(0)       /**< SPI0 signal line function value: TWCK0 */
#define PIO_PA9A_SPI0_TWCK0                        (_UL_(1) << 9)

#define PIN_PB0A_SPI0_SCK0                         _L_(32)      /**< SPI0 signal: SCK0 on PB0 mux A*/
#define MUX_PB0A_SPI0_SCK0                         _L_(0)       /**< SPI0 signal line function value: SCK0 */
#define PIO_PB0A_SPI0_SCK0                         (_UL_(1) << 0)

#define PIN_PB0A_SPI0_SPI0_SPCK                    _L_(32)      /**< SPI0 signal: SPI0_SPCK on PB0 mux A*/
#define MUX_PB0A_SPI0_SPI0_SPCK                    _L_(0)       /**< SPI0 signal line function value: SPI0_SPCK */
#define PIO_PB0A_SPI0_SPI0_SPCK                    (_UL_(1) << 0)

#define PIN_PA25A_SPI0_SPI0_NPCS0                  _L_(25)      /**< SPI0 signal: SPI0_NPCS0 on PA25 mux A*/
#define MUX_PA25A_SPI0_SPI0_NPCS0                  _L_(0)       /**< SPI0 signal line function value: SPI0_NPCS0 */
#define PIO_PA25A_SPI0_SPI0_NPCS0                  (_UL_(1) << 25)

#define PIN_PA25A_SPI0_CTS0                        _L_(25)      /**< SPI0 signal: CTS0 on PA25 mux A*/
#define MUX_PA25A_SPI0_CTS0                        _L_(0)       /**< SPI0 signal line function value: CTS0 */
#define PIO_PA25A_SPI0_CTS0                        (_UL_(1) << 25)

#define PIN_PA26A_SPI0_SPI0_NPCS1                  _L_(26)      /**< SPI0 signal: SPI0_NPCS1 on PA26 mux A*/
#define MUX_PA26A_SPI0_SPI0_NPCS1                  _L_(0)       /**< SPI0 signal line function value: SPI0_NPCS1 */
#define PIO_PA26A_SPI0_SPI0_NPCS1                  (_UL_(1) << 26)

#define PIN_PA26A_SPI0_RTS0                        _L_(26)      /**< SPI0 signal: RTS0 on PA26 mux A*/
#define MUX_PA26A_SPI0_RTS0                        _L_(0)       /**< SPI0 signal line function value: RTS0 */
#define PIO_PA26A_SPI0_RTS0                        (_UL_(1) << 26)

#define PIN_PA10A_SPI0_TXD0                        _L_(10)      /**< SPI0 signal: TXD0 on PA10 mux A*/
#define MUX_PA10A_SPI0_TXD0                        _L_(0)       /**< SPI0 signal line function value: TXD0 */
#define PIO_PA10A_SPI0_TXD0                        (_UL_(1) << 10)

#define PIN_PA10A_SPI0_SPI0_MOSI                   _L_(10)      /**< SPI0 signal: SPI0_MOSI on PA10 mux A*/
#define MUX_PA10A_SPI0_SPI0_MOSI                   _L_(0)       /**< SPI0 signal line function value: SPI0_MOSI */
#define PIO_PA10A_SPI0_SPI0_MOSI                   (_UL_(1) << 10)

#define PIN_PA10A_SPI0_TWD0                        _L_(10)      /**< SPI0 signal: TWD0 on PA10 mux A*/
#define MUX_PA10A_SPI0_TWD0                        _L_(0)       /**< SPI0 signal line function value: TWD0 */
#define PIO_PA10A_SPI0_TWD0                        (_UL_(1) << 10)

/* ========== PIO definition for SPI1 peripheral ========== */
#define PIN_PB2A_SPI1_RXD1                         _L_(34)      /**< SPI1 signal: RXD1 on PB2 mux A*/
#define MUX_PB2A_SPI1_RXD1                         _L_(0)       /**< SPI1 signal line function value: RXD1 */
#define PIO_PB2A_SPI1_RXD1                         (_UL_(1) << 2)

#define PIN_PB2A_SPI1_SPI1_MISO                    _L_(34)      /**< SPI1 signal: SPI1_MISO on PB2 mux A*/
#define MUX_PB2A_SPI1_SPI1_MISO                    _L_(0)       /**< SPI1 signal line function value: SPI1_MISO */
#define PIO_PB2A_SPI1_SPI1_MISO                    (_UL_(1) << 2)

#define PIN_PB2A_SPI1_TWCK1                        _L_(34)      /**< SPI1 signal: TWCK1 on PB2 mux A*/
#define MUX_PB2A_SPI1_TWCK1                        _L_(0)       /**< SPI1 signal line function value: TWCK1 */
#define PIO_PB2A_SPI1_TWCK1                        (_UL_(1) << 2)

#define PIN_PA27A_SPI1_SCK1                        _L_(27)      /**< SPI1 signal: SCK1 on PA27 mux A*/
#define MUX_PA27A_SPI1_SCK1                        _L_(0)       /**< SPI1 signal line function value: SCK1 */
#define PIO_PA27A_SPI1_SCK1                        (_UL_(1) << 27)

#define PIN_PA27A_SPI1_SPI1_SPCK                   _L_(27)      /**< SPI1 signal: SPI1_SPCK on PA27 mux A*/
#define MUX_PA27A_SPI1_SPI1_SPCK                   _L_(0)       /**< SPI1 signal line function value: SPI1_SPCK */
#define PIO_PA27A_SPI1_SPI1_SPCK                   (_UL_(1) << 27)

#define PIN_PA28A_SPI1_SPI1_NPCS0                  _L_(28)      /**< SPI1 signal: SPI1_NPCS0 on PA28 mux A*/
#define MUX_PA28A_SPI1_SPI1_NPCS0                  _L_(0)       /**< SPI1 signal line function value: SPI1_NPCS0 */
#define PIO_PA28A_SPI1_SPI1_NPCS0                  (_UL_(1) << 28)

#define PIN_PA28A_SPI1_CTS1                        _L_(28)      /**< SPI1 signal: CTS1 on PA28 mux A*/
#define MUX_PA28A_SPI1_CTS1                        _L_(0)       /**< SPI1 signal line function value: CTS1 */
#define PIO_PA28A_SPI1_CTS1                        (_UL_(1) << 28)

#define PIN_PA29A_SPI1_SPI1_NPCS1                  _L_(29)      /**< SPI1 signal: SPI1_NPCS1 on PA29 mux A*/
#define MUX_PA29A_SPI1_SPI1_NPCS1                  _L_(0)       /**< SPI1 signal line function value: SPI1_NPCS1 */
#define PIO_PA29A_SPI1_SPI1_NPCS1                  (_UL_(1) << 29)

#define PIN_PA29A_SPI1_RTS1                        _L_(29)      /**< SPI1 signal: RTS1 on PA29 mux A*/
#define MUX_PA29A_SPI1_RTS1                        _L_(0)       /**< SPI1 signal line function value: RTS1 */
#define PIO_PA29A_SPI1_RTS1                        (_UL_(1) << 29)

#define PIN_PB3A_SPI1_TXD1                         _L_(35)      /**< SPI1 signal: TXD1 on PB3 mux A*/
#define MUX_PB3A_SPI1_TXD1                         _L_(0)       /**< SPI1 signal line function value: TXD1 */
#define PIO_PB3A_SPI1_TXD1                         (_UL_(1) << 3)

#define PIN_PB3A_SPI1_SPI1_MOSI                    _L_(35)      /**< SPI1 signal: SPI1_MOSI on PB3 mux A*/
#define MUX_PB3A_SPI1_SPI1_MOSI                    _L_(0)       /**< SPI1 signal line function value: SPI1_MOSI */
#define PIO_PB3A_SPI1_SPI1_MOSI                    (_UL_(1) << 3)

#define PIN_PB3A_SPI1_TWD1                         _L_(35)      /**< SPI1 signal: TWD1 on PB3 mux A*/
#define MUX_PB3A_SPI1_TWD1                         _L_(0)       /**< SPI1 signal line function value: TWD1 */
#define PIO_PB3A_SPI1_TWD1                         (_UL_(1) << 3)

/* ========== PIO definition for SPI2 peripheral ========== */
#define PIN_PA5A_SPI2_RXD2                         _L_(5)       /**< SPI2 signal: RXD2 on PA5 mux A*/
#define MUX_PA5A_SPI2_RXD2                         _L_(0)       /**< SPI2 signal line function value: RXD2 */
#define PIO_PA5A_SPI2_RXD2                         (_UL_(1) << 5)

#define PIN_PA5A_SPI2_SPI2_MISO                    _L_(5)       /**< SPI2 signal: SPI2_MISO on PA5 mux A*/
#define MUX_PA5A_SPI2_SPI2_MISO                    _L_(0)       /**< SPI2 signal line function value: SPI2_MISO */
#define PIO_PA5A_SPI2_SPI2_MISO                    (_UL_(1) << 5)

#define PIN_PA5A_SPI2_TWCK2                        _L_(5)       /**< SPI2 signal: TWCK2 on PA5 mux A*/
#define MUX_PA5A_SPI2_TWCK2                        _L_(0)       /**< SPI2 signal line function value: TWCK2 */
#define PIO_PA5A_SPI2_TWCK2                        (_UL_(1) << 5)

#define PIN_PA15B_SPI2_SCK2                        _L_(15)      /**< SPI2 signal: SCK2 on PA15 mux B*/
#define MUX_PA15B_SPI2_SCK2                        _L_(1)       /**< SPI2 signal line function value: SCK2 */
#define PIO_PA15B_SPI2_SCK2                        (_UL_(1) << 15)

#define PIN_PA15B_SPI2_SPI2_SPCK                   _L_(15)      /**< SPI2 signal: SPI2_SPCK on PA15 mux B*/
#define MUX_PA15B_SPI2_SPI2_SPCK                   _L_(1)       /**< SPI2 signal line function value: SPI2_SPCK */
#define PIO_PA15B_SPI2_SPI2_SPCK                   (_UL_(1) << 15)

#define PIN_PA24B_SPI2_SCK2                        _L_(24)      /**< SPI2 signal: SCK2 on PA24 mux B*/
#define MUX_PA24B_SPI2_SCK2                        _L_(1)       /**< SPI2 signal line function value: SCK2 */
#define PIO_PA24B_SPI2_SCK2                        (_UL_(1) << 24)

#define PIN_PA24B_SPI2_SPI2_SPCK                   _L_(24)      /**< SPI2 signal: SPI2_SPCK on PA24 mux B*/
#define MUX_PA24B_SPI2_SPI2_SPCK                   _L_(1)       /**< SPI2 signal line function value: SPI2_SPCK */
#define PIO_PA24B_SPI2_SPI2_SPCK                   (_UL_(1) << 24)

#define PIN_PA16A_SPI2_SPI2_NPCS0                  _L_(16)      /**< SPI2 signal: SPI2_NPCS0 on PA16 mux A*/
#define MUX_PA16A_SPI2_SPI2_NPCS0                  _L_(0)       /**< SPI2 signal line function value: SPI2_NPCS0 */
#define PIO_PA16A_SPI2_SPI2_NPCS0                  (_UL_(1) << 16)

#define PIN_PA16A_SPI2_CTS2                        _L_(16)      /**< SPI2 signal: CTS2 on PA16 mux A*/
#define MUX_PA16A_SPI2_CTS2                        _L_(0)       /**< SPI2 signal line function value: CTS2 */
#define PIO_PA16A_SPI2_CTS2                        (_UL_(1) << 16)

#define PIN_PA15A_SPI2_SPI2_NPCS1                  _L_(15)      /**< SPI2 signal: SPI2_NPCS1 on PA15 mux A*/
#define MUX_PA15A_SPI2_SPI2_NPCS1                  _L_(0)       /**< SPI2 signal line function value: SPI2_NPCS1 */
#define PIO_PA15A_SPI2_SPI2_NPCS1                  (_UL_(1) << 15)

#define PIN_PA15A_SPI2_RTS2                        _L_(15)      /**< SPI2 signal: RTS2 on PA15 mux A*/
#define MUX_PA15A_SPI2_RTS2                        _L_(0)       /**< SPI2 signal line function value: RTS2 */
#define PIO_PA15A_SPI2_RTS2                        (_UL_(1) << 15)

#define PIN_PA6A_SPI2_TXD2                         _L_(6)       /**< SPI2 signal: TXD2 on PA6 mux A*/
#define MUX_PA6A_SPI2_TXD2                         _L_(0)       /**< SPI2 signal line function value: TXD2 */
#define PIO_PA6A_SPI2_TXD2                         (_UL_(1) << 6)

#define PIN_PA6A_SPI2_SPI2_MOSI                    _L_(6)       /**< SPI2 signal: SPI2_MOSI on PA6 mux A*/
#define MUX_PA6A_SPI2_SPI2_MOSI                    _L_(0)       /**< SPI2 signal line function value: SPI2_MOSI */
#define PIO_PA6A_SPI2_SPI2_MOSI                    (_UL_(1) << 6)

#define PIN_PA6A_SPI2_TWD2                         _L_(6)       /**< SPI2 signal: TWD2 on PA6 mux A*/
#define MUX_PA6A_SPI2_TWD2                         _L_(0)       /**< SPI2 signal line function value: TWD2 */
#define PIO_PA6A_SPI2_TWD2                         (_UL_(1) << 6)

/* ========== PIO definition for SPI3 peripheral ========== */
#define PIN_PA4A_SPI3_RXD3                         _L_(4)       /**< SPI3 signal: RXD3 on PA4 mux A*/
#define MUX_PA4A_SPI3_RXD3                         _L_(0)       /**< SPI3 signal line function value: RXD3 */
#define PIO_PA4A_SPI3_RXD3                         (_UL_(1) << 4)

#define PIN_PA4A_SPI3_SPI3_MISO                    _L_(4)       /**< SPI3 signal: SPI3_MISO on PA4 mux A*/
#define MUX_PA4A_SPI3_SPI3_MISO                    _L_(0)       /**< SPI3 signal line function value: SPI3_MISO */
#define PIO_PA4A_SPI3_SPI3_MISO                    (_UL_(1) << 4)

#define PIN_PA4A_SPI3_TWCK3                        _L_(4)       /**< SPI3 signal: TWCK3 on PA4 mux A*/
#define MUX_PA4A_SPI3_TWCK3                        _L_(0)       /**< SPI3 signal line function value: TWCK3 */
#define PIO_PA4A_SPI3_TWCK3                        (_UL_(1) << 4)

#define PIN_PB13A_SPI3_SCK3                        _L_(45)      /**< SPI3 signal: SCK3 on PB13 mux A*/
#define MUX_PB13A_SPI3_SCK3                        _L_(0)       /**< SPI3 signal line function value: SCK3 */
#define PIO_PB13A_SPI3_SCK3                        (_UL_(1) << 13)

#define PIN_PB13A_SPI3_SPI3_SPCK                   _L_(45)      /**< SPI3 signal: SPI3_SPCK on PB13 mux A*/
#define MUX_PB13A_SPI3_SPI3_SPCK                   _L_(0)       /**< SPI3 signal line function value: SPI3_SPCK */
#define PIO_PB13A_SPI3_SPI3_SPCK                   (_UL_(1) << 13)

#define PIN_PB14A_SPI3_SPI3_NPCS0                  _L_(46)      /**< SPI3 signal: SPI3_NPCS0 on PB14 mux A*/
#define MUX_PB14A_SPI3_SPI3_NPCS0                  _L_(0)       /**< SPI3 signal line function value: SPI3_NPCS0 */
#define PIO_PB14A_SPI3_SPI3_NPCS0                  (_UL_(1) << 14)

#define PIN_PB14A_SPI3_CTS3                        _L_(46)      /**< SPI3 signal: CTS3 on PB14 mux A*/
#define MUX_PB14A_SPI3_CTS3                        _L_(0)       /**< SPI3 signal line function value: CTS3 */
#define PIO_PB14A_SPI3_CTS3                        (_UL_(1) << 14)

#define PIN_PB15A_SPI3_SPI3_NPCS1                  _L_(47)      /**< SPI3 signal: SPI3_NPCS1 on PB15 mux A*/
#define MUX_PB15A_SPI3_SPI3_NPCS1                  _L_(0)       /**< SPI3 signal line function value: SPI3_NPCS1 */
#define PIO_PB15A_SPI3_SPI3_NPCS1                  (_UL_(1) << 15)

#define PIN_PB15A_SPI3_RTS3                        _L_(47)      /**< SPI3 signal: RTS3 on PB15 mux A*/
#define MUX_PB15A_SPI3_RTS3                        _L_(0)       /**< SPI3 signal line function value: RTS3 */
#define PIO_PB15A_SPI3_RTS3                        (_UL_(1) << 15)

#define PIN_PA3A_SPI3_TXD3                         _L_(3)       /**< SPI3 signal: TXD3 on PA3 mux A*/
#define MUX_PA3A_SPI3_TXD3                         _L_(0)       /**< SPI3 signal line function value: TXD3 */
#define PIO_PA3A_SPI3_TXD3                         (_UL_(1) << 3)

#define PIN_PA3A_SPI3_SPI3_MOSI                    _L_(3)       /**< SPI3 signal: SPI3_MOSI on PA3 mux A*/
#define MUX_PA3A_SPI3_SPI3_MOSI                    _L_(0)       /**< SPI3 signal line function value: SPI3_MOSI */
#define PIO_PA3A_SPI3_SPI3_MOSI                    (_UL_(1) << 3)

#define PIN_PA3A_SPI3_TWD3                         _L_(3)       /**< SPI3 signal: TWD3 on PA3 mux A*/
#define MUX_PA3A_SPI3_TWD3                         _L_(0)       /**< SPI3 signal line function value: TWD3 */
#define PIO_PA3A_SPI3_TWD3                         (_UL_(1) << 3)

/* ========== PIO definition for SPI4 peripheral ========== */
#define PIN_PB9A_SPI4_RXD4                         _L_(41)      /**< SPI4 signal: RXD4 on PB9 mux A*/
#define MUX_PB9A_SPI4_RXD4                         _L_(0)       /**< SPI4 signal line function value: RXD4 */
#define PIO_PB9A_SPI4_RXD4                         (_UL_(1) << 9)

#define PIN_PB9A_SPI4_SPI4_MISO                    _L_(41)      /**< SPI4 signal: SPI4_MISO on PB9 mux A*/
#define MUX_PB9A_SPI4_SPI4_MISO                    _L_(0)       /**< SPI4 signal line function value: SPI4_MISO */
#define PIO_PB9A_SPI4_SPI4_MISO                    (_UL_(1) << 9)

#define PIN_PB9A_SPI4_TWCK4                        _L_(41)      /**< SPI4 signal: TWCK4 on PB9 mux A*/
#define MUX_PB9A_SPI4_TWCK4                        _L_(0)       /**< SPI4 signal line function value: TWCK4 */
#define PIO_PB9A_SPI4_TWCK4                        (_UL_(1) << 9)

#define PIN_PB11A_SPI4_RXD4                        _L_(43)      /**< SPI4 signal: RXD4 on PB11 mux A*/
#define MUX_PB11A_SPI4_RXD4                        _L_(0)       /**< SPI4 signal line function value: RXD4 */
#define PIO_PB11A_SPI4_RXD4                        (_UL_(1) << 11)

#define PIN_PB11A_SPI4_SPI4_MISO                   _L_(43)      /**< SPI4 signal: SPI4_MISO on PB11 mux A*/
#define MUX_PB11A_SPI4_SPI4_MISO                   _L_(0)       /**< SPI4 signal line function value: SPI4_MISO */
#define PIO_PB11A_SPI4_SPI4_MISO                   (_UL_(1) << 11)

#define PIN_PB11A_SPI4_TWCK4                       _L_(43)      /**< SPI4 signal: TWCK4 on PB11 mux A*/
#define MUX_PB11A_SPI4_TWCK4                       _L_(0)       /**< SPI4 signal line function value: TWCK4 */
#define PIO_PB11A_SPI4_TWCK4                       (_UL_(1) << 11)

#define PIN_PB1A_SPI4_SCK4                         _L_(33)      /**< SPI4 signal: SCK4 on PB1 mux A*/
#define MUX_PB1A_SPI4_SCK4                         _L_(0)       /**< SPI4 signal line function value: SCK4 */
#define PIO_PB1A_SPI4_SCK4                         (_UL_(1) << 1)

#define PIN_PB1A_SPI4_SPI4_SPCK                    _L_(33)      /**< SPI4 signal: SPI4_SPCK on PB1 mux A*/
#define MUX_PB1A_SPI4_SPI4_SPCK                    _L_(0)       /**< SPI4 signal line function value: SPI4_SPCK */
#define PIO_PB1A_SPI4_SPI4_SPCK                    (_UL_(1) << 1)

#define PIN_PB8B_SPI4_SPI4_NPCS0                   _L_(40)      /**< SPI4 signal: SPI4_NPCS0 on PB8 mux B*/
#define MUX_PB8B_SPI4_SPI4_NPCS0                   _L_(1)       /**< SPI4 signal line function value: SPI4_NPCS0 */
#define PIO_PB8B_SPI4_SPI4_NPCS0                   (_UL_(1) << 8)

#define PIN_PB8B_SPI4_CTS4                         _L_(40)      /**< SPI4 signal: CTS4 on PB8 mux B*/
#define MUX_PB8B_SPI4_CTS4                         _L_(1)       /**< SPI4 signal line function value: CTS4 */
#define PIO_PB8B_SPI4_CTS4                         (_UL_(1) << 8)

#define PIN_PB9B_SPI4_SPI4_NPCS1                   _L_(41)      /**< SPI4 signal: SPI4_NPCS1 on PB9 mux B*/
#define MUX_PB9B_SPI4_SPI4_NPCS1                   _L_(1)       /**< SPI4 signal line function value: SPI4_NPCS1 */
#define PIO_PB9B_SPI4_SPI4_NPCS1                   (_UL_(1) << 9)

#define PIN_PB9B_SPI4_RTS4                         _L_(41)      /**< SPI4 signal: RTS4 on PB9 mux B*/
#define MUX_PB9B_SPI4_RTS4                         _L_(1)       /**< SPI4 signal line function value: RTS4 */
#define PIO_PB9B_SPI4_RTS4                         (_UL_(1) << 9)

#define PIN_PB8A_SPI4_TXD4                         _L_(40)      /**< SPI4 signal: TXD4 on PB8 mux A*/
#define MUX_PB8A_SPI4_TXD4                         _L_(0)       /**< SPI4 signal line function value: TXD4 */
#define PIO_PB8A_SPI4_TXD4                         (_UL_(1) << 8)

#define PIN_PB8A_SPI4_SPI4_MOSI                    _L_(40)      /**< SPI4 signal: SPI4_MOSI on PB8 mux A*/
#define MUX_PB8A_SPI4_SPI4_MOSI                    _L_(0)       /**< SPI4 signal line function value: SPI4_MOSI */
#define PIO_PB8A_SPI4_SPI4_MOSI                    (_UL_(1) << 8)

#define PIN_PB8A_SPI4_TWD4                         _L_(40)      /**< SPI4 signal: TWD4 on PB8 mux A*/
#define MUX_PB8A_SPI4_TWD4                         _L_(0)       /**< SPI4 signal line function value: TWD4 */
#define PIO_PB8A_SPI4_TWD4                         (_UL_(1) << 8)

#define PIN_PB10A_SPI4_TXD4                        _L_(42)      /**< SPI4 signal: TXD4 on PB10 mux A*/
#define MUX_PB10A_SPI4_TXD4                        _L_(0)       /**< SPI4 signal line function value: TXD4 */
#define PIO_PB10A_SPI4_TXD4                        (_UL_(1) << 10)

#define PIN_PB10A_SPI4_SPI4_MOSI                   _L_(42)      /**< SPI4 signal: SPI4_MOSI on PB10 mux A*/
#define MUX_PB10A_SPI4_SPI4_MOSI                   _L_(0)       /**< SPI4 signal line function value: SPI4_MOSI */
#define PIO_PB10A_SPI4_SPI4_MOSI                   (_UL_(1) << 10)

#define PIN_PB10A_SPI4_TWD4                        _L_(42)      /**< SPI4 signal: TWD4 on PB10 mux A*/
#define MUX_PB10A_SPI4_TWD4                        _L_(0)       /**< SPI4 signal line function value: TWD4 */
#define PIO_PB10A_SPI4_TWD4                        (_UL_(1) << 10)

/* ========== PIO definition for SPI5 peripheral ========== */
#define PIN_PA12A_SPI5_RXD5                        _L_(12)      /**< SPI5 signal: RXD5 on PA12 mux A*/
#define MUX_PA12A_SPI5_RXD5                        _L_(0)       /**< SPI5 signal line function value: RXD5 */
#define PIO_PA12A_SPI5_RXD5                        (_UL_(1) << 12)

#define PIN_PA12A_SPI5_SPI5_MISO                   _L_(12)      /**< SPI5 signal: SPI5_MISO on PA12 mux A*/
#define MUX_PA12A_SPI5_SPI5_MISO                   _L_(0)       /**< SPI5 signal line function value: SPI5_MISO */
#define PIO_PA12A_SPI5_SPI5_MISO                   (_UL_(1) << 12)

#define PIN_PA12A_SPI5_TWCK5                       _L_(12)      /**< SPI5 signal: TWCK5 on PA12 mux A*/
#define MUX_PA12A_SPI5_TWCK5                       _L_(0)       /**< SPI5 signal line function value: TWCK5 */
#define PIO_PA12A_SPI5_TWCK5                       (_UL_(1) << 12)

#define PIN_PA14A_SPI5_SCK5                        _L_(14)      /**< SPI5 signal: SCK5 on PA14 mux A*/
#define MUX_PA14A_SPI5_SCK5                        _L_(0)       /**< SPI5 signal line function value: SCK5 */
#define PIO_PA14A_SPI5_SCK5                        (_UL_(1) << 14)

#define PIN_PA14A_SPI5_SPI5_SPCK                   _L_(14)      /**< SPI5 signal: SPI5_SPCK on PA14 mux A*/
#define MUX_PA14A_SPI5_SPI5_SPCK                   _L_(0)       /**< SPI5 signal line function value: SPI5_SPCK */
#define PIO_PA14A_SPI5_SPI5_SPCK                   (_UL_(1) << 14)

#define PIN_PA11A_SPI5_SPI5_NPCS0                  _L_(11)      /**< SPI5 signal: SPI5_NPCS0 on PA11 mux A*/
#define MUX_PA11A_SPI5_SPI5_NPCS0                  _L_(0)       /**< SPI5 signal line function value: SPI5_NPCS0 */
#define PIO_PA11A_SPI5_SPI5_NPCS0                  (_UL_(1) << 11)

#define PIN_PA11A_SPI5_CTS5                        _L_(11)      /**< SPI5 signal: CTS5 on PA11 mux A*/
#define MUX_PA11A_SPI5_CTS5                        _L_(0)       /**< SPI5 signal line function value: CTS5 */
#define PIO_PA11A_SPI5_CTS5                        (_UL_(1) << 11)

#define PIN_PA5B_SPI5_SPI5_NPCS1                   _L_(5)       /**< SPI5 signal: SPI5_NPCS1 on PA5 mux B*/
#define MUX_PA5B_SPI5_SPI5_NPCS1                   _L_(1)       /**< SPI5 signal line function value: SPI5_NPCS1 */
#define PIO_PA5B_SPI5_SPI5_NPCS1                   (_UL_(1) << 5)

#define PIN_PA5B_SPI5_RTS5                         _L_(5)       /**< SPI5 signal: RTS5 on PA5 mux B*/
#define MUX_PA5B_SPI5_RTS5                         _L_(1)       /**< SPI5 signal line function value: RTS5 */
#define PIO_PA5B_SPI5_RTS5                         (_UL_(1) << 5)

#define PIN_PB2B_SPI5_SPI5_NPCS1                   _L_(34)      /**< SPI5 signal: SPI5_NPCS1 on PB2 mux B*/
#define MUX_PB2B_SPI5_SPI5_NPCS1                   _L_(1)       /**< SPI5 signal line function value: SPI5_NPCS1 */
#define PIO_PB2B_SPI5_SPI5_NPCS1                   (_UL_(1) << 2)

#define PIN_PB2B_SPI5_RTS5                         _L_(34)      /**< SPI5 signal: RTS5 on PB2 mux B*/
#define MUX_PB2B_SPI5_RTS5                         _L_(1)       /**< SPI5 signal line function value: RTS5 */
#define PIO_PB2B_SPI5_RTS5                         (_UL_(1) << 2)

#define PIN_PA13A_SPI5_TXD5                        _L_(13)      /**< SPI5 signal: TXD5 on PA13 mux A*/
#define MUX_PA13A_SPI5_TXD5                        _L_(0)       /**< SPI5 signal line function value: TXD5 */
#define PIO_PA13A_SPI5_TXD5                        (_UL_(1) << 13)

#define PIN_PA13A_SPI5_SPI5_MOSI                   _L_(13)      /**< SPI5 signal: SPI5_MOSI on PA13 mux A*/
#define MUX_PA13A_SPI5_SPI5_MOSI                   _L_(0)       /**< SPI5 signal line function value: SPI5_MOSI */
#define PIO_PA13A_SPI5_SPI5_MOSI                   (_UL_(1) << 13)

#define PIN_PA13A_SPI5_TWD5                        _L_(13)      /**< SPI5 signal: TWD5 on PA13 mux A*/
#define MUX_PA13A_SPI5_TWD5                        _L_(0)       /**< SPI5 signal line function value: TWD5 */
#define PIO_PA13A_SPI5_TWD5                        (_UL_(1) << 13)

/* ========== PIO definition for SPI6 peripheral ========== */
#define PIN_PB1B_SPI6_RXD6                         _L_(33)      /**< SPI6 signal: RXD6 on PB1 mux B*/
#define MUX_PB1B_SPI6_RXD6                         _L_(1)       /**< SPI6 signal line function value: RXD6 */
#define PIO_PB1B_SPI6_RXD6                         (_UL_(1) << 1)

#define PIN_PB1B_SPI6_SPI6_MISO                    _L_(33)      /**< SPI6 signal: SPI6_MISO on PB1 mux B*/
#define MUX_PB1B_SPI6_SPI6_MISO                    _L_(1)       /**< SPI6 signal line function value: SPI6_MISO */
#define PIO_PB1B_SPI6_SPI6_MISO                    (_UL_(1) << 1)

#define PIN_PB1B_SPI6_TWCK6                        _L_(33)      /**< SPI6 signal: TWCK6 on PB1 mux B*/
#define MUX_PB1B_SPI6_TWCK6                        _L_(1)       /**< SPI6 signal line function value: TWCK6 */
#define PIO_PB1B_SPI6_TWCK6                        (_UL_(1) << 1)

#define PIN_PB11B_SPI6_RXD6                        _L_(43)      /**< SPI6 signal: RXD6 on PB11 mux B*/
#define MUX_PB11B_SPI6_RXD6                        _L_(1)       /**< SPI6 signal line function value: RXD6 */
#define PIO_PB11B_SPI6_RXD6                        (_UL_(1) << 11)

#define PIN_PB11B_SPI6_SPI6_MISO                   _L_(43)      /**< SPI6 signal: SPI6_MISO on PB11 mux B*/
#define MUX_PB11B_SPI6_SPI6_MISO                   _L_(1)       /**< SPI6 signal line function value: SPI6_MISO */
#define PIO_PB11B_SPI6_SPI6_MISO                   (_UL_(1) << 11)

#define PIN_PB11B_SPI6_TWCK6                       _L_(43)      /**< SPI6 signal: TWCK6 on PB11 mux B*/
#define MUX_PB11B_SPI6_TWCK6                       _L_(1)       /**< SPI6 signal line function value: TWCK6 */
#define PIO_PB11B_SPI6_TWCK6                       (_UL_(1) << 11)

#define PIN_PB13B_SPI6_SCK6                        _L_(45)      /**< SPI6 signal: SCK6 on PB13 mux B*/
#define MUX_PB13B_SPI6_SCK6                        _L_(1)       /**< SPI6 signal line function value: SCK6 */
#define PIO_PB13B_SPI6_SCK6                        (_UL_(1) << 13)

#define PIN_PB13B_SPI6_SPI6_SPCK                   _L_(45)      /**< SPI6 signal: SPI6_SPCK on PB13 mux B*/
#define MUX_PB13B_SPI6_SPI6_SPCK                   _L_(1)       /**< SPI6 signal line function value: SPI6_SPCK */
#define PIO_PB13B_SPI6_SPI6_SPCK                   (_UL_(1) << 13)

#define PIN_PB14B_SPI6_SPI6_NPCS0                  _L_(46)      /**< SPI6 signal: SPI6_NPCS0 on PB14 mux B*/
#define MUX_PB14B_SPI6_SPI6_NPCS0                  _L_(1)       /**< SPI6 signal line function value: SPI6_NPCS0 */
#define PIO_PB14B_SPI6_SPI6_NPCS0                  (_UL_(1) << 14)

#define PIN_PB14B_SPI6_CTS6                        _L_(46)      /**< SPI6 signal: CTS6 on PB14 mux B*/
#define MUX_PB14B_SPI6_CTS6                        _L_(1)       /**< SPI6 signal line function value: CTS6 */
#define PIO_PB14B_SPI6_CTS6                        (_UL_(1) << 14)

#define PIN_PB15B_SPI6_SPI6_NPCS1                  _L_(47)      /**< SPI6 signal: SPI6_NPCS1 on PB15 mux B*/
#define MUX_PB15B_SPI6_SPI6_NPCS1                  _L_(1)       /**< SPI6 signal line function value: SPI6_NPCS1 */
#define PIO_PB15B_SPI6_SPI6_NPCS1                  (_UL_(1) << 15)

#define PIN_PB15B_SPI6_RTS6                        _L_(47)      /**< SPI6 signal: RTS6 on PB15 mux B*/
#define MUX_PB15B_SPI6_RTS6                        _L_(1)       /**< SPI6 signal line function value: RTS6 */
#define PIO_PB15B_SPI6_RTS6                        (_UL_(1) << 15)

#define PIN_PB0B_SPI6_TXD6                         _L_(32)      /**< SPI6 signal: TXD6 on PB0 mux B*/
#define MUX_PB0B_SPI6_TXD6                         _L_(1)       /**< SPI6 signal line function value: TXD6 */
#define PIO_PB0B_SPI6_TXD6                         (_UL_(1) << 0)

#define PIN_PB0B_SPI6_SPI6_MOSI                    _L_(32)      /**< SPI6 signal: SPI6_MOSI on PB0 mux B*/
#define MUX_PB0B_SPI6_SPI6_MOSI                    _L_(1)       /**< SPI6 signal line function value: SPI6_MOSI */
#define PIO_PB0B_SPI6_SPI6_MOSI                    (_UL_(1) << 0)

#define PIN_PB0B_SPI6_TWD6                         _L_(32)      /**< SPI6 signal: TWD6 on PB0 mux B*/
#define MUX_PB0B_SPI6_TWD6                         _L_(1)       /**< SPI6 signal line function value: TWD6 */
#define PIO_PB0B_SPI6_TWD6                         (_UL_(1) << 0)

#define PIN_PB10B_SPI6_TXD6                        _L_(42)      /**< SPI6 signal: TXD6 on PB10 mux B*/
#define MUX_PB10B_SPI6_TXD6                        _L_(1)       /**< SPI6 signal line function value: TXD6 */
#define PIO_PB10B_SPI6_TXD6                        (_UL_(1) << 10)

#define PIN_PB10B_SPI6_SPI6_MOSI                   _L_(42)      /**< SPI6 signal: SPI6_MOSI on PB10 mux B*/
#define MUX_PB10B_SPI6_SPI6_MOSI                   _L_(1)       /**< SPI6 signal line function value: SPI6_MOSI */
#define PIO_PB10B_SPI6_SPI6_MOSI                   (_UL_(1) << 10)

#define PIN_PB10B_SPI6_TWD6                        _L_(42)      /**< SPI6 signal: TWD6 on PB10 mux B*/
#define MUX_PB10B_SPI6_TWD6                        _L_(1)       /**< SPI6 signal line function value: TWD6 */
#define PIO_PB10B_SPI6_TWD6                        (_UL_(1) << 10)

/* ========== PIO definition for SPI7 peripheral ========== */
#define PIN_PA27B_SPI7_RXD7                        _L_(27)      /**< SPI7 signal: RXD7 on PA27 mux B*/
#define MUX_PA27B_SPI7_RXD7                        _L_(1)       /**< SPI7 signal line function value: RXD7 */
#define PIO_PA27B_SPI7_RXD7                        (_UL_(1) << 27)

#define PIN_PA27B_SPI7_SPI7_MISO                   _L_(27)      /**< SPI7 signal: SPI7_MISO on PA27 mux B*/
#define MUX_PA27B_SPI7_SPI7_MISO                   _L_(1)       /**< SPI7 signal line function value: SPI7_MISO */
#define PIO_PA27B_SPI7_SPI7_MISO                   (_UL_(1) << 27)

#define PIN_PA27B_SPI7_TWCK7                       _L_(27)      /**< SPI7 signal: TWCK7 on PA27 mux B*/
#define MUX_PA27B_SPI7_TWCK7                       _L_(1)       /**< SPI7 signal line function value: TWCK7 */
#define PIO_PA27B_SPI7_TWCK7                       (_UL_(1) << 27)

#define PIN_PA29B_SPI7_SCK7                        _L_(29)      /**< SPI7 signal: SCK7 on PA29 mux B*/
#define MUX_PA29B_SPI7_SCK7                        _L_(1)       /**< SPI7 signal line function value: SCK7 */
#define PIO_PA29B_SPI7_SCK7                        (_UL_(1) << 29)

#define PIN_PA29B_SPI7_SPI7_SPCK                   _L_(29)      /**< SPI7 signal: SPI7_SPCK on PA29 mux B*/
#define MUX_PA29B_SPI7_SPI7_SPCK                   _L_(1)       /**< SPI7 signal line function value: SPI7_SPCK */
#define PIO_PA29B_SPI7_SPI7_SPCK                   (_UL_(1) << 29)

#define PIN_PA30B_SPI7_SPI7_NPCS0                  _L_(30)      /**< SPI7 signal: SPI7_NPCS0 on PA30 mux B*/
#define MUX_PA30B_SPI7_SPI7_NPCS0                  _L_(1)       /**< SPI7 signal line function value: SPI7_NPCS0 */
#define PIO_PA30B_SPI7_SPI7_NPCS0                  (_UL_(1) << 30)

#define PIN_PA30B_SPI7_CTS7                        _L_(30)      /**< SPI7 signal: CTS7 on PA30 mux B*/
#define MUX_PA30B_SPI7_CTS7                        _L_(1)       /**< SPI7 signal line function value: CTS7 */
#define PIO_PA30B_SPI7_CTS7                        (_UL_(1) << 30)

#define PIN_PA31B_SPI7_SPI7_NPCS1                  _L_(31)      /**< SPI7 signal: SPI7_NPCS1 on PA31 mux B*/
#define MUX_PA31B_SPI7_SPI7_NPCS1                  _L_(1)       /**< SPI7 signal line function value: SPI7_NPCS1 */
#define PIO_PA31B_SPI7_SPI7_NPCS1                  (_UL_(1) << 31)

#define PIN_PA31B_SPI7_RTS7                        _L_(31)      /**< SPI7 signal: RTS7 on PA31 mux B*/
#define MUX_PA31B_SPI7_RTS7                        _L_(1)       /**< SPI7 signal line function value: RTS7 */
#define PIO_PA31B_SPI7_RTS7                        (_UL_(1) << 31)

#define PIN_PA28B_SPI7_TXD7                        _L_(28)      /**< SPI7 signal: TXD7 on PA28 mux B*/
#define MUX_PA28B_SPI7_TXD7                        _L_(1)       /**< SPI7 signal line function value: TXD7 */
#define PIO_PA28B_SPI7_TXD7                        (_UL_(1) << 28)

#define PIN_PA28B_SPI7_SPI7_MOSI                   _L_(28)      /**< SPI7 signal: SPI7_MOSI on PA28 mux B*/
#define MUX_PA28B_SPI7_SPI7_MOSI                   _L_(1)       /**< SPI7 signal line function value: SPI7_MOSI */
#define PIO_PA28B_SPI7_SPI7_MOSI                   (_UL_(1) << 28)

#define PIN_PA28B_SPI7_TWD7                        _L_(28)      /**< SPI7 signal: TWD7 on PA28 mux B*/
#define MUX_PA28B_SPI7_TWD7                        _L_(1)       /**< SPI7 signal line function value: TWD7 */
#define PIO_PA28B_SPI7_TWD7                        (_UL_(1) << 28)

/* ========== PIO definition for TC0 peripheral ========== */
#define PIN_PA2A_TC0_TCLK0                         _L_(2)       /**< TC0 signal: TCLK0 on PA2 mux A*/
#define MUX_PA2A_TC0_TCLK0                         _L_(0)       /**< TC0 signal line function value: TCLK0 */
#define PIO_PA2A_TC0_TCLK0                         (_UL_(1) << 2)

#define PIN_PA19A_TC0_TCLK1                        _L_(19)      /**< TC0 signal: TCLK1 on PA19 mux A*/
#define MUX_PA19A_TC0_TCLK1                        _L_(0)       /**< TC0 signal line function value: TCLK1 */
#define PIO_PA19A_TC0_TCLK1                        (_UL_(1) << 19)

#define PIN_PA20A_TC0_TCLK2                        _L_(20)      /**< TC0 signal: TCLK2 on PA20 mux A*/
#define MUX_PA20A_TC0_TCLK2                        _L_(0)       /**< TC0 signal line function value: TCLK2 */
#define PIO_PA20A_TC0_TCLK2                        (_UL_(1) << 20)

#define PIN_PA0B_TC0_TIOA0                         _L_(0)       /**< TC0 signal: TIOA0 on PA0 mux B*/
#define MUX_PA0B_TC0_TIOA0                         _L_(1)       /**< TC0 signal line function value: TIOA0 */
#define PIO_PA0B_TC0_TIOA0                         (_UL_(1) << 0)

#define PIN_PA23B_TC0_TIOA1                        _L_(23)      /**< TC0 signal: TIOA1 on PA23 mux B*/
#define MUX_PA23B_TC0_TIOA1                        _L_(1)       /**< TC0 signal line function value: TIOA1 */
#define PIO_PA23B_TC0_TIOA1                        (_UL_(1) << 23)

#define PIN_PA21A_TC0_TIOA2                        _L_(21)      /**< TC0 signal: TIOA2 on PA21 mux A*/
#define MUX_PA21A_TC0_TIOA2                        _L_(0)       /**< TC0 signal line function value: TIOA2 */
#define PIO_PA21A_TC0_TIOA2                        (_UL_(1) << 21)

#define PIN_PA1B_TC0_TIOB0                         _L_(1)       /**< TC0 signal: TIOB0 on PA1 mux B*/
#define MUX_PA1B_TC0_TIOB0                         _L_(1)       /**< TC0 signal line function value: TIOB0 */
#define PIO_PA1B_TC0_TIOB0                         (_UL_(1) << 1)

#define PIN_PA16B_TC0_TIOB1                        _L_(16)      /**< TC0 signal: TIOB1 on PA16 mux B*/
#define MUX_PA16B_TC0_TIOB1                        _L_(1)       /**< TC0 signal line function value: TIOB1 */
#define PIO_PA16B_TC0_TIOB1                        (_UL_(1) << 16)

#define PIN_PA22A_TC0_TIOB2                        _L_(22)      /**< TC0 signal: TIOB2 on PA22 mux A*/
#define MUX_PA22A_TC0_TIOB2                        _L_(0)       /**< TC0 signal line function value: TIOB2 */
#define PIO_PA22A_TC0_TIOB2                        (_UL_(1) << 22)

/* ========== PIO definition for TWI0 peripheral ========== */
#define PIN_PA9A_TWI0_RXD0                         _L_(9)       /**< TWI0 signal: RXD0 on PA9 mux A*/
#define MUX_PA9A_TWI0_RXD0                         _L_(0)       /**< TWI0 signal line function value: RXD0 */
#define PIO_PA9A_TWI0_RXD0                         (_UL_(1) << 9)

#define PIN_PA9A_TWI0_SPI0_MISO                    _L_(9)       /**< TWI0 signal: SPI0_MISO on PA9 mux A*/
#define MUX_PA9A_TWI0_SPI0_MISO                    _L_(0)       /**< TWI0 signal line function value: SPI0_MISO */
#define PIO_PA9A_TWI0_SPI0_MISO                    (_UL_(1) << 9)

#define PIN_PA9A_TWI0_TWCK0                        _L_(9)       /**< TWI0 signal: TWCK0 on PA9 mux A*/
#define MUX_PA9A_TWI0_TWCK0                        _L_(0)       /**< TWI0 signal line function value: TWCK0 */
#define PIO_PA9A_TWI0_TWCK0                        (_UL_(1) << 9)

#define PIN_PA10A_TWI0_TXD0                        _L_(10)      /**< TWI0 signal: TXD0 on PA10 mux A*/
#define MUX_PA10A_TWI0_TXD0                        _L_(0)       /**< TWI0 signal line function value: TXD0 */
#define PIO_PA10A_TWI0_TXD0                        (_UL_(1) << 10)

#define PIN_PA10A_TWI0_SPI0_MOSI                   _L_(10)      /**< TWI0 signal: SPI0_MOSI on PA10 mux A*/
#define MUX_PA10A_TWI0_SPI0_MOSI                   _L_(0)       /**< TWI0 signal line function value: SPI0_MOSI */
#define PIO_PA10A_TWI0_SPI0_MOSI                   (_UL_(1) << 10)

#define PIN_PA10A_TWI0_TWD0                        _L_(10)      /**< TWI0 signal: TWD0 on PA10 mux A*/
#define MUX_PA10A_TWI0_TWD0                        _L_(0)       /**< TWI0 signal line function value: TWD0 */
#define PIO_PA10A_TWI0_TWD0                        (_UL_(1) << 10)

/* ========== PIO definition for TWI1 peripheral ========== */
#define PIN_PB2A_TWI1_RXD1                         _L_(34)      /**< TWI1 signal: RXD1 on PB2 mux A*/
#define MUX_PB2A_TWI1_RXD1                         _L_(0)       /**< TWI1 signal line function value: RXD1 */
#define PIO_PB2A_TWI1_RXD1                         (_UL_(1) << 2)

#define PIN_PB2A_TWI1_SPI1_MISO                    _L_(34)      /**< TWI1 signal: SPI1_MISO on PB2 mux A*/
#define MUX_PB2A_TWI1_SPI1_MISO                    _L_(0)       /**< TWI1 signal line function value: SPI1_MISO */
#define PIO_PB2A_TWI1_SPI1_MISO                    (_UL_(1) << 2)

#define PIN_PB2A_TWI1_TWCK1                        _L_(34)      /**< TWI1 signal: TWCK1 on PB2 mux A*/
#define MUX_PB2A_TWI1_TWCK1                        _L_(0)       /**< TWI1 signal line function value: TWCK1 */
#define PIO_PB2A_TWI1_TWCK1                        (_UL_(1) << 2)

#define PIN_PB3A_TWI1_TXD1                         _L_(35)      /**< TWI1 signal: TXD1 on PB3 mux A*/
#define MUX_PB3A_TWI1_TXD1                         _L_(0)       /**< TWI1 signal line function value: TXD1 */
#define PIO_PB3A_TWI1_TXD1                         (_UL_(1) << 3)

#define PIN_PB3A_TWI1_SPI1_MOSI                    _L_(35)      /**< TWI1 signal: SPI1_MOSI on PB3 mux A*/
#define MUX_PB3A_TWI1_SPI1_MOSI                    _L_(0)       /**< TWI1 signal line function value: SPI1_MOSI */
#define PIO_PB3A_TWI1_SPI1_MOSI                    (_UL_(1) << 3)

#define PIN_PB3A_TWI1_TWD1                         _L_(35)      /**< TWI1 signal: TWD1 on PB3 mux A*/
#define MUX_PB3A_TWI1_TWD1                         _L_(0)       /**< TWI1 signal line function value: TWD1 */
#define PIO_PB3A_TWI1_TWD1                         (_UL_(1) << 3)

/* ========== PIO definition for TWI2 peripheral ========== */
#define PIN_PA5A_TWI2_RXD2                         _L_(5)       /**< TWI2 signal: RXD2 on PA5 mux A*/
#define MUX_PA5A_TWI2_RXD2                         _L_(0)       /**< TWI2 signal line function value: RXD2 */
#define PIO_PA5A_TWI2_RXD2                         (_UL_(1) << 5)

#define PIN_PA5A_TWI2_SPI2_MISO                    _L_(5)       /**< TWI2 signal: SPI2_MISO on PA5 mux A*/
#define MUX_PA5A_TWI2_SPI2_MISO                    _L_(0)       /**< TWI2 signal line function value: SPI2_MISO */
#define PIO_PA5A_TWI2_SPI2_MISO                    (_UL_(1) << 5)

#define PIN_PA5A_TWI2_TWCK2                        _L_(5)       /**< TWI2 signal: TWCK2 on PA5 mux A*/
#define MUX_PA5A_TWI2_TWCK2                        _L_(0)       /**< TWI2 signal line function value: TWCK2 */
#define PIO_PA5A_TWI2_TWCK2                        (_UL_(1) << 5)

#define PIN_PA6A_TWI2_TXD2                         _L_(6)       /**< TWI2 signal: TXD2 on PA6 mux A*/
#define MUX_PA6A_TWI2_TXD2                         _L_(0)       /**< TWI2 signal line function value: TXD2 */
#define PIO_PA6A_TWI2_TXD2                         (_UL_(1) << 6)

#define PIN_PA6A_TWI2_SPI2_MOSI                    _L_(6)       /**< TWI2 signal: SPI2_MOSI on PA6 mux A*/
#define MUX_PA6A_TWI2_SPI2_MOSI                    _L_(0)       /**< TWI2 signal line function value: SPI2_MOSI */
#define PIO_PA6A_TWI2_SPI2_MOSI                    (_UL_(1) << 6)

#define PIN_PA6A_TWI2_TWD2                         _L_(6)       /**< TWI2 signal: TWD2 on PA6 mux A*/
#define MUX_PA6A_TWI2_TWD2                         _L_(0)       /**< TWI2 signal line function value: TWD2 */
#define PIO_PA6A_TWI2_TWD2                         (_UL_(1) << 6)

/* ========== PIO definition for TWI3 peripheral ========== */
#define PIN_PA4A_TWI3_RXD3                         _L_(4)       /**< TWI3 signal: RXD3 on PA4 mux A*/
#define MUX_PA4A_TWI3_RXD3                         _L_(0)       /**< TWI3 signal line function value: RXD3 */
#define PIO_PA4A_TWI3_RXD3                         (_UL_(1) << 4)

#define PIN_PA4A_TWI3_SPI3_MISO                    _L_(4)       /**< TWI3 signal: SPI3_MISO on PA4 mux A*/
#define MUX_PA4A_TWI3_SPI3_MISO                    _L_(0)       /**< TWI3 signal line function value: SPI3_MISO */
#define PIO_PA4A_TWI3_SPI3_MISO                    (_UL_(1) << 4)

#define PIN_PA4A_TWI3_TWCK3                        _L_(4)       /**< TWI3 signal: TWCK3 on PA4 mux A*/
#define MUX_PA4A_TWI3_TWCK3                        _L_(0)       /**< TWI3 signal line function value: TWCK3 */
#define PIO_PA4A_TWI3_TWCK3                        (_UL_(1) << 4)

#define PIN_PA3A_TWI3_TXD3                         _L_(3)       /**< TWI3 signal: TXD3 on PA3 mux A*/
#define MUX_PA3A_TWI3_TXD3                         _L_(0)       /**< TWI3 signal line function value: TXD3 */
#define PIO_PA3A_TWI3_TXD3                         (_UL_(1) << 3)

#define PIN_PA3A_TWI3_SPI3_MOSI                    _L_(3)       /**< TWI3 signal: SPI3_MOSI on PA3 mux A*/
#define MUX_PA3A_TWI3_SPI3_MOSI                    _L_(0)       /**< TWI3 signal line function value: SPI3_MOSI */
#define PIO_PA3A_TWI3_SPI3_MOSI                    (_UL_(1) << 3)

#define PIN_PA3A_TWI3_TWD3                         _L_(3)       /**< TWI3 signal: TWD3 on PA3 mux A*/
#define MUX_PA3A_TWI3_TWD3                         _L_(0)       /**< TWI3 signal line function value: TWD3 */
#define PIO_PA3A_TWI3_TWD3                         (_UL_(1) << 3)

/* ========== PIO definition for TWI4 peripheral ========== */
#define PIN_PB9A_TWI4_RXD4                         _L_(41)      /**< TWI4 signal: RXD4 on PB9 mux A*/
#define MUX_PB9A_TWI4_RXD4                         _L_(0)       /**< TWI4 signal line function value: RXD4 */
#define PIO_PB9A_TWI4_RXD4                         (_UL_(1) << 9)

#define PIN_PB9A_TWI4_SPI4_MISO                    _L_(41)      /**< TWI4 signal: SPI4_MISO on PB9 mux A*/
#define MUX_PB9A_TWI4_SPI4_MISO                    _L_(0)       /**< TWI4 signal line function value: SPI4_MISO */
#define PIO_PB9A_TWI4_SPI4_MISO                    (_UL_(1) << 9)

#define PIN_PB9A_TWI4_TWCK4                        _L_(41)      /**< TWI4 signal: TWCK4 on PB9 mux A*/
#define MUX_PB9A_TWI4_TWCK4                        _L_(0)       /**< TWI4 signal line function value: TWCK4 */
#define PIO_PB9A_TWI4_TWCK4                        (_UL_(1) << 9)

#define PIN_PB11A_TWI4_RXD4                        _L_(43)      /**< TWI4 signal: RXD4 on PB11 mux A*/
#define MUX_PB11A_TWI4_RXD4                        _L_(0)       /**< TWI4 signal line function value: RXD4 */
#define PIO_PB11A_TWI4_RXD4                        (_UL_(1) << 11)

#define PIN_PB11A_TWI4_SPI4_MISO                   _L_(43)      /**< TWI4 signal: SPI4_MISO on PB11 mux A*/
#define MUX_PB11A_TWI4_SPI4_MISO                   _L_(0)       /**< TWI4 signal line function value: SPI4_MISO */
#define PIO_PB11A_TWI4_SPI4_MISO                   (_UL_(1) << 11)

#define PIN_PB11A_TWI4_TWCK4                       _L_(43)      /**< TWI4 signal: TWCK4 on PB11 mux A*/
#define MUX_PB11A_TWI4_TWCK4                       _L_(0)       /**< TWI4 signal line function value: TWCK4 */
#define PIO_PB11A_TWI4_TWCK4                       (_UL_(1) << 11)

#define PIN_PB8A_TWI4_TXD4                         _L_(40)      /**< TWI4 signal: TXD4 on PB8 mux A*/
#define MUX_PB8A_TWI4_TXD4                         _L_(0)       /**< TWI4 signal line function value: TXD4 */
#define PIO_PB8A_TWI4_TXD4                         (_UL_(1) << 8)

#define PIN_PB8A_TWI4_SPI4_MOSI                    _L_(40)      /**< TWI4 signal: SPI4_MOSI on PB8 mux A*/
#define MUX_PB8A_TWI4_SPI4_MOSI                    _L_(0)       /**< TWI4 signal line function value: SPI4_MOSI */
#define PIO_PB8A_TWI4_SPI4_MOSI                    (_UL_(1) << 8)

#define PIN_PB8A_TWI4_TWD4                         _L_(40)      /**< TWI4 signal: TWD4 on PB8 mux A*/
#define MUX_PB8A_TWI4_TWD4                         _L_(0)       /**< TWI4 signal line function value: TWD4 */
#define PIO_PB8A_TWI4_TWD4                         (_UL_(1) << 8)

#define PIN_PB10A_TWI4_TXD4                        _L_(42)      /**< TWI4 signal: TXD4 on PB10 mux A*/
#define MUX_PB10A_TWI4_TXD4                        _L_(0)       /**< TWI4 signal line function value: TXD4 */
#define PIO_PB10A_TWI4_TXD4                        (_UL_(1) << 10)

#define PIN_PB10A_TWI4_SPI4_MOSI                   _L_(42)      /**< TWI4 signal: SPI4_MOSI on PB10 mux A*/
#define MUX_PB10A_TWI4_SPI4_MOSI                   _L_(0)       /**< TWI4 signal line function value: SPI4_MOSI */
#define PIO_PB10A_TWI4_SPI4_MOSI                   (_UL_(1) << 10)

#define PIN_PB10A_TWI4_TWD4                        _L_(42)      /**< TWI4 signal: TWD4 on PB10 mux A*/
#define MUX_PB10A_TWI4_TWD4                        _L_(0)       /**< TWI4 signal line function value: TWD4 */
#define PIO_PB10A_TWI4_TWD4                        (_UL_(1) << 10)

/* ========== PIO definition for TWI5 peripheral ========== */
#define PIN_PA12A_TWI5_RXD5                        _L_(12)      /**< TWI5 signal: RXD5 on PA12 mux A*/
#define MUX_PA12A_TWI5_RXD5                        _L_(0)       /**< TWI5 signal line function value: RXD5 */
#define PIO_PA12A_TWI5_RXD5                        (_UL_(1) << 12)

#define PIN_PA12A_TWI5_SPI5_MISO                   _L_(12)      /**< TWI5 signal: SPI5_MISO on PA12 mux A*/
#define MUX_PA12A_TWI5_SPI5_MISO                   _L_(0)       /**< TWI5 signal line function value: SPI5_MISO */
#define PIO_PA12A_TWI5_SPI5_MISO                   (_UL_(1) << 12)

#define PIN_PA12A_TWI5_TWCK5                       _L_(12)      /**< TWI5 signal: TWCK5 on PA12 mux A*/
#define MUX_PA12A_TWI5_TWCK5                       _L_(0)       /**< TWI5 signal line function value: TWCK5 */
#define PIO_PA12A_TWI5_TWCK5                       (_UL_(1) << 12)

#define PIN_PA13A_TWI5_TXD5                        _L_(13)      /**< TWI5 signal: TXD5 on PA13 mux A*/
#define MUX_PA13A_TWI5_TXD5                        _L_(0)       /**< TWI5 signal line function value: TXD5 */
#define PIO_PA13A_TWI5_TXD5                        (_UL_(1) << 13)

#define PIN_PA13A_TWI5_SPI5_MOSI                   _L_(13)      /**< TWI5 signal: SPI5_MOSI on PA13 mux A*/
#define MUX_PA13A_TWI5_SPI5_MOSI                   _L_(0)       /**< TWI5 signal line function value: SPI5_MOSI */
#define PIO_PA13A_TWI5_SPI5_MOSI                   (_UL_(1) << 13)

#define PIN_PA13A_TWI5_TWD5                        _L_(13)      /**< TWI5 signal: TWD5 on PA13 mux A*/
#define MUX_PA13A_TWI5_TWD5                        _L_(0)       /**< TWI5 signal line function value: TWD5 */
#define PIO_PA13A_TWI5_TWD5                        (_UL_(1) << 13)

/* ========== PIO definition for TWI6 peripheral ========== */
#define PIN_PB1B_TWI6_RXD6                         _L_(33)      /**< TWI6 signal: RXD6 on PB1 mux B*/
#define MUX_PB1B_TWI6_RXD6                         _L_(1)       /**< TWI6 signal line function value: RXD6 */
#define PIO_PB1B_TWI6_RXD6                         (_UL_(1) << 1)

#define PIN_PB1B_TWI6_SPI6_MISO                    _L_(33)      /**< TWI6 signal: SPI6_MISO on PB1 mux B*/
#define MUX_PB1B_TWI6_SPI6_MISO                    _L_(1)       /**< TWI6 signal line function value: SPI6_MISO */
#define PIO_PB1B_TWI6_SPI6_MISO                    (_UL_(1) << 1)

#define PIN_PB1B_TWI6_TWCK6                        _L_(33)      /**< TWI6 signal: TWCK6 on PB1 mux B*/
#define MUX_PB1B_TWI6_TWCK6                        _L_(1)       /**< TWI6 signal line function value: TWCK6 */
#define PIO_PB1B_TWI6_TWCK6                        (_UL_(1) << 1)

#define PIN_PB11B_TWI6_RXD6                        _L_(43)      /**< TWI6 signal: RXD6 on PB11 mux B*/
#define MUX_PB11B_TWI6_RXD6                        _L_(1)       /**< TWI6 signal line function value: RXD6 */
#define PIO_PB11B_TWI6_RXD6                        (_UL_(1) << 11)

#define PIN_PB11B_TWI6_SPI6_MISO                   _L_(43)      /**< TWI6 signal: SPI6_MISO on PB11 mux B*/
#define MUX_PB11B_TWI6_SPI6_MISO                   _L_(1)       /**< TWI6 signal line function value: SPI6_MISO */
#define PIO_PB11B_TWI6_SPI6_MISO                   (_UL_(1) << 11)

#define PIN_PB11B_TWI6_TWCK6                       _L_(43)      /**< TWI6 signal: TWCK6 on PB11 mux B*/
#define MUX_PB11B_TWI6_TWCK6                       _L_(1)       /**< TWI6 signal line function value: TWCK6 */
#define PIO_PB11B_TWI6_TWCK6                       (_UL_(1) << 11)

#define PIN_PB0B_TWI6_TXD6                         _L_(32)      /**< TWI6 signal: TXD6 on PB0 mux B*/
#define MUX_PB0B_TWI6_TXD6                         _L_(1)       /**< TWI6 signal line function value: TXD6 */
#define PIO_PB0B_TWI6_TXD6                         (_UL_(1) << 0)

#define PIN_PB0B_TWI6_SPI6_MOSI                    _L_(32)      /**< TWI6 signal: SPI6_MOSI on PB0 mux B*/
#define MUX_PB0B_TWI6_SPI6_MOSI                    _L_(1)       /**< TWI6 signal line function value: SPI6_MOSI */
#define PIO_PB0B_TWI6_SPI6_MOSI                    (_UL_(1) << 0)

#define PIN_PB0B_TWI6_TWD6                         _L_(32)      /**< TWI6 signal: TWD6 on PB0 mux B*/
#define MUX_PB0B_TWI6_TWD6                         _L_(1)       /**< TWI6 signal line function value: TWD6 */
#define PIO_PB0B_TWI6_TWD6                         (_UL_(1) << 0)

#define PIN_PB10B_TWI6_TXD6                        _L_(42)      /**< TWI6 signal: TXD6 on PB10 mux B*/
#define MUX_PB10B_TWI6_TXD6                        _L_(1)       /**< TWI6 signal line function value: TXD6 */
#define PIO_PB10B_TWI6_TXD6                        (_UL_(1) << 10)

#define PIN_PB10B_TWI6_SPI6_MOSI                   _L_(42)      /**< TWI6 signal: SPI6_MOSI on PB10 mux B*/
#define MUX_PB10B_TWI6_SPI6_MOSI                   _L_(1)       /**< TWI6 signal line function value: SPI6_MOSI */
#define PIO_PB10B_TWI6_SPI6_MOSI                   (_UL_(1) << 10)

#define PIN_PB10B_TWI6_TWD6                        _L_(42)      /**< TWI6 signal: TWD6 on PB10 mux B*/
#define MUX_PB10B_TWI6_TWD6                        _L_(1)       /**< TWI6 signal line function value: TWD6 */
#define PIO_PB10B_TWI6_TWD6                        (_UL_(1) << 10)

/* ========== PIO definition for TWI7 peripheral ========== */
#define PIN_PA27B_TWI7_RXD7                        _L_(27)      /**< TWI7 signal: RXD7 on PA27 mux B*/
#define MUX_PA27B_TWI7_RXD7                        _L_(1)       /**< TWI7 signal line function value: RXD7 */
#define PIO_PA27B_TWI7_RXD7                        (_UL_(1) << 27)

#define PIN_PA27B_TWI7_SPI7_MISO                   _L_(27)      /**< TWI7 signal: SPI7_MISO on PA27 mux B*/
#define MUX_PA27B_TWI7_SPI7_MISO                   _L_(1)       /**< TWI7 signal line function value: SPI7_MISO */
#define PIO_PA27B_TWI7_SPI7_MISO                   (_UL_(1) << 27)

#define PIN_PA27B_TWI7_TWCK7                       _L_(27)      /**< TWI7 signal: TWCK7 on PA27 mux B*/
#define MUX_PA27B_TWI7_TWCK7                       _L_(1)       /**< TWI7 signal line function value: TWCK7 */
#define PIO_PA27B_TWI7_TWCK7                       (_UL_(1) << 27)

#define PIN_PA28B_TWI7_TXD7                        _L_(28)      /**< TWI7 signal: TXD7 on PA28 mux B*/
#define MUX_PA28B_TWI7_TXD7                        _L_(1)       /**< TWI7 signal line function value: TXD7 */
#define PIO_PA28B_TWI7_TXD7                        (_UL_(1) << 28)

#define PIN_PA28B_TWI7_SPI7_MOSI                   _L_(28)      /**< TWI7 signal: SPI7_MOSI on PA28 mux B*/
#define MUX_PA28B_TWI7_SPI7_MOSI                   _L_(1)       /**< TWI7 signal line function value: SPI7_MOSI */
#define PIO_PA28B_TWI7_SPI7_MOSI                   (_UL_(1) << 28)

#define PIN_PA28B_TWI7_TWD7                        _L_(28)      /**< TWI7 signal: TWD7 on PA28 mux B*/
#define MUX_PA28B_TWI7_TWD7                        _L_(1)       /**< TWI7 signal line function value: TWD7 */
#define PIO_PA28B_TWI7_TWD7                        (_UL_(1) << 28)

/* ========== PIO definition for USART0 peripheral ========== */
#define PIN_PA9A_USART0_RXD0                       _L_(9)       /**< USART0 signal: RXD0 on PA9 mux A*/
#define MUX_PA9A_USART0_RXD0                       _L_(0)       /**< USART0 signal line function value: RXD0 */
#define PIO_PA9A_USART0_RXD0                       (_UL_(1) << 9)

#define PIN_PA9A_USART0_SPI0_MISO                  _L_(9)       /**< USART0 signal: SPI0_MISO on PA9 mux A*/
#define MUX_PA9A_USART0_SPI0_MISO                  _L_(0)       /**< USART0 signal line function value: SPI0_MISO */
#define PIO_PA9A_USART0_SPI0_MISO                  (_UL_(1) << 9)

#define PIN_PA9A_USART0_TWCK0                      _L_(9)       /**< USART0 signal: TWCK0 on PA9 mux A*/
#define MUX_PA9A_USART0_TWCK0                      _L_(0)       /**< USART0 signal line function value: TWCK0 */
#define PIO_PA9A_USART0_TWCK0                      (_UL_(1) << 9)

#define PIN_PB0A_USART0_SCK0                       _L_(32)      /**< USART0 signal: SCK0 on PB0 mux A*/
#define MUX_PB0A_USART0_SCK0                       _L_(0)       /**< USART0 signal line function value: SCK0 */
#define PIO_PB0A_USART0_SCK0                       (_UL_(1) << 0)

#define PIN_PB0A_USART0_SPI0_SPCK                  _L_(32)      /**< USART0 signal: SPI0_SPCK on PB0 mux A*/
#define MUX_PB0A_USART0_SPI0_SPCK                  _L_(0)       /**< USART0 signal line function value: SPI0_SPCK */
#define PIO_PB0A_USART0_SPI0_SPCK                  (_UL_(1) << 0)

#define PIN_PA25A_USART0_SPI0_NPCS0                _L_(25)      /**< USART0 signal: SPI0_NPCS0 on PA25 mux A*/
#define MUX_PA25A_USART0_SPI0_NPCS0                _L_(0)       /**< USART0 signal line function value: SPI0_NPCS0 */
#define PIO_PA25A_USART0_SPI0_NPCS0                (_UL_(1) << 25)

#define PIN_PA25A_USART0_CTS0                      _L_(25)      /**< USART0 signal: CTS0 on PA25 mux A*/
#define MUX_PA25A_USART0_CTS0                      _L_(0)       /**< USART0 signal line function value: CTS0 */
#define PIO_PA25A_USART0_CTS0                      (_UL_(1) << 25)

#define PIN_PA26A_USART0_SPI0_NPCS1                _L_(26)      /**< USART0 signal: SPI0_NPCS1 on PA26 mux A*/
#define MUX_PA26A_USART0_SPI0_NPCS1                _L_(0)       /**< USART0 signal line function value: SPI0_NPCS1 */
#define PIO_PA26A_USART0_SPI0_NPCS1                (_UL_(1) << 26)

#define PIN_PA26A_USART0_RTS0                      _L_(26)      /**< USART0 signal: RTS0 on PA26 mux A*/
#define MUX_PA26A_USART0_RTS0                      _L_(0)       /**< USART0 signal line function value: RTS0 */
#define PIO_PA26A_USART0_RTS0                      (_UL_(1) << 26)

#define PIN_PA10A_USART0_TXD0                      _L_(10)      /**< USART0 signal: TXD0 on PA10 mux A*/
#define MUX_PA10A_USART0_TXD0                      _L_(0)       /**< USART0 signal line function value: TXD0 */
#define PIO_PA10A_USART0_TXD0                      (_UL_(1) << 10)

#define PIN_PA10A_USART0_SPI0_MOSI                 _L_(10)      /**< USART0 signal: SPI0_MOSI on PA10 mux A*/
#define MUX_PA10A_USART0_SPI0_MOSI                 _L_(0)       /**< USART0 signal line function value: SPI0_MOSI */
#define PIO_PA10A_USART0_SPI0_MOSI                 (_UL_(1) << 10)

#define PIN_PA10A_USART0_TWD0                      _L_(10)      /**< USART0 signal: TWD0 on PA10 mux A*/
#define MUX_PA10A_USART0_TWD0                      _L_(0)       /**< USART0 signal line function value: TWD0 */
#define PIO_PA10A_USART0_TWD0                      (_UL_(1) << 10)

/* ========== PIO definition for USART1 peripheral ========== */
#define PIN_PB2A_USART1_RXD1                       _L_(34)      /**< USART1 signal: RXD1 on PB2 mux A*/
#define MUX_PB2A_USART1_RXD1                       _L_(0)       /**< USART1 signal line function value: RXD1 */
#define PIO_PB2A_USART1_RXD1                       (_UL_(1) << 2)

#define PIN_PB2A_USART1_SPI1_MISO                  _L_(34)      /**< USART1 signal: SPI1_MISO on PB2 mux A*/
#define MUX_PB2A_USART1_SPI1_MISO                  _L_(0)       /**< USART1 signal line function value: SPI1_MISO */
#define PIO_PB2A_USART1_SPI1_MISO                  (_UL_(1) << 2)

#define PIN_PB2A_USART1_TWCK1                      _L_(34)      /**< USART1 signal: TWCK1 on PB2 mux A*/
#define MUX_PB2A_USART1_TWCK1                      _L_(0)       /**< USART1 signal line function value: TWCK1 */
#define PIO_PB2A_USART1_TWCK1                      (_UL_(1) << 2)

#define PIN_PA27A_USART1_SCK1                      _L_(27)      /**< USART1 signal: SCK1 on PA27 mux A*/
#define MUX_PA27A_USART1_SCK1                      _L_(0)       /**< USART1 signal line function value: SCK1 */
#define PIO_PA27A_USART1_SCK1                      (_UL_(1) << 27)

#define PIN_PA27A_USART1_SPI1_SPCK                 _L_(27)      /**< USART1 signal: SPI1_SPCK on PA27 mux A*/
#define MUX_PA27A_USART1_SPI1_SPCK                 _L_(0)       /**< USART1 signal line function value: SPI1_SPCK */
#define PIO_PA27A_USART1_SPI1_SPCK                 (_UL_(1) << 27)

#define PIN_PA28A_USART1_SPI1_NPCS0                _L_(28)      /**< USART1 signal: SPI1_NPCS0 on PA28 mux A*/
#define MUX_PA28A_USART1_SPI1_NPCS0                _L_(0)       /**< USART1 signal line function value: SPI1_NPCS0 */
#define PIO_PA28A_USART1_SPI1_NPCS0                (_UL_(1) << 28)

#define PIN_PA28A_USART1_CTS1                      _L_(28)      /**< USART1 signal: CTS1 on PA28 mux A*/
#define MUX_PA28A_USART1_CTS1                      _L_(0)       /**< USART1 signal line function value: CTS1 */
#define PIO_PA28A_USART1_CTS1                      (_UL_(1) << 28)

#define PIN_PA29A_USART1_SPI1_NPCS1                _L_(29)      /**< USART1 signal: SPI1_NPCS1 on PA29 mux A*/
#define MUX_PA29A_USART1_SPI1_NPCS1                _L_(0)       /**< USART1 signal line function value: SPI1_NPCS1 */
#define PIO_PA29A_USART1_SPI1_NPCS1                (_UL_(1) << 29)

#define PIN_PA29A_USART1_RTS1                      _L_(29)      /**< USART1 signal: RTS1 on PA29 mux A*/
#define MUX_PA29A_USART1_RTS1                      _L_(0)       /**< USART1 signal line function value: RTS1 */
#define PIO_PA29A_USART1_RTS1                      (_UL_(1) << 29)

#define PIN_PB3A_USART1_TXD1                       _L_(35)      /**< USART1 signal: TXD1 on PB3 mux A*/
#define MUX_PB3A_USART1_TXD1                       _L_(0)       /**< USART1 signal line function value: TXD1 */
#define PIO_PB3A_USART1_TXD1                       (_UL_(1) << 3)

#define PIN_PB3A_USART1_SPI1_MOSI                  _L_(35)      /**< USART1 signal: SPI1_MOSI on PB3 mux A*/
#define MUX_PB3A_USART1_SPI1_MOSI                  _L_(0)       /**< USART1 signal line function value: SPI1_MOSI */
#define PIO_PB3A_USART1_SPI1_MOSI                  (_UL_(1) << 3)

#define PIN_PB3A_USART1_TWD1                       _L_(35)      /**< USART1 signal: TWD1 on PB3 mux A*/
#define MUX_PB3A_USART1_TWD1                       _L_(0)       /**< USART1 signal line function value: TWD1 */
#define PIO_PB3A_USART1_TWD1                       (_UL_(1) << 3)

/* ========== PIO definition for USART2 peripheral ========== */
#define PIN_PA5A_USART2_RXD2                       _L_(5)       /**< USART2 signal: RXD2 on PA5 mux A*/
#define MUX_PA5A_USART2_RXD2                       _L_(0)       /**< USART2 signal line function value: RXD2 */
#define PIO_PA5A_USART2_RXD2                       (_UL_(1) << 5)

#define PIN_PA5A_USART2_SPI2_MISO                  _L_(5)       /**< USART2 signal: SPI2_MISO on PA5 mux A*/
#define MUX_PA5A_USART2_SPI2_MISO                  _L_(0)       /**< USART2 signal line function value: SPI2_MISO */
#define PIO_PA5A_USART2_SPI2_MISO                  (_UL_(1) << 5)

#define PIN_PA5A_USART2_TWCK2                      _L_(5)       /**< USART2 signal: TWCK2 on PA5 mux A*/
#define MUX_PA5A_USART2_TWCK2                      _L_(0)       /**< USART2 signal line function value: TWCK2 */
#define PIO_PA5A_USART2_TWCK2                      (_UL_(1) << 5)

#define PIN_PA15B_USART2_SCK2                      _L_(15)      /**< USART2 signal: SCK2 on PA15 mux B*/
#define MUX_PA15B_USART2_SCK2                      _L_(1)       /**< USART2 signal line function value: SCK2 */
#define PIO_PA15B_USART2_SCK2                      (_UL_(1) << 15)

#define PIN_PA15B_USART2_SPI2_SPCK                 _L_(15)      /**< USART2 signal: SPI2_SPCK on PA15 mux B*/
#define MUX_PA15B_USART2_SPI2_SPCK                 _L_(1)       /**< USART2 signal line function value: SPI2_SPCK */
#define PIO_PA15B_USART2_SPI2_SPCK                 (_UL_(1) << 15)

#define PIN_PA24B_USART2_SCK2                      _L_(24)      /**< USART2 signal: SCK2 on PA24 mux B*/
#define MUX_PA24B_USART2_SCK2                      _L_(1)       /**< USART2 signal line function value: SCK2 */
#define PIO_PA24B_USART2_SCK2                      (_UL_(1) << 24)

#define PIN_PA24B_USART2_SPI2_SPCK                 _L_(24)      /**< USART2 signal: SPI2_SPCK on PA24 mux B*/
#define MUX_PA24B_USART2_SPI2_SPCK                 _L_(1)       /**< USART2 signal line function value: SPI2_SPCK */
#define PIO_PA24B_USART2_SPI2_SPCK                 (_UL_(1) << 24)

#define PIN_PA16A_USART2_SPI2_NPCS0                _L_(16)      /**< USART2 signal: SPI2_NPCS0 on PA16 mux A*/
#define MUX_PA16A_USART2_SPI2_NPCS0                _L_(0)       /**< USART2 signal line function value: SPI2_NPCS0 */
#define PIO_PA16A_USART2_SPI2_NPCS0                (_UL_(1) << 16)

#define PIN_PA16A_USART2_CTS2                      _L_(16)      /**< USART2 signal: CTS2 on PA16 mux A*/
#define MUX_PA16A_USART2_CTS2                      _L_(0)       /**< USART2 signal line function value: CTS2 */
#define PIO_PA16A_USART2_CTS2                      (_UL_(1) << 16)

#define PIN_PA15A_USART2_SPI2_NPCS1                _L_(15)      /**< USART2 signal: SPI2_NPCS1 on PA15 mux A*/
#define MUX_PA15A_USART2_SPI2_NPCS1                _L_(0)       /**< USART2 signal line function value: SPI2_NPCS1 */
#define PIO_PA15A_USART2_SPI2_NPCS1                (_UL_(1) << 15)

#define PIN_PA15A_USART2_RTS2                      _L_(15)      /**< USART2 signal: RTS2 on PA15 mux A*/
#define MUX_PA15A_USART2_RTS2                      _L_(0)       /**< USART2 signal line function value: RTS2 */
#define PIO_PA15A_USART2_RTS2                      (_UL_(1) << 15)

#define PIN_PA6A_USART2_TXD2                       _L_(6)       /**< USART2 signal: TXD2 on PA6 mux A*/
#define MUX_PA6A_USART2_TXD2                       _L_(0)       /**< USART2 signal line function value: TXD2 */
#define PIO_PA6A_USART2_TXD2                       (_UL_(1) << 6)

#define PIN_PA6A_USART2_SPI2_MOSI                  _L_(6)       /**< USART2 signal: SPI2_MOSI on PA6 mux A*/
#define MUX_PA6A_USART2_SPI2_MOSI                  _L_(0)       /**< USART2 signal line function value: SPI2_MOSI */
#define PIO_PA6A_USART2_SPI2_MOSI                  (_UL_(1) << 6)

#define PIN_PA6A_USART2_TWD2                       _L_(6)       /**< USART2 signal: TWD2 on PA6 mux A*/
#define MUX_PA6A_USART2_TWD2                       _L_(0)       /**< USART2 signal line function value: TWD2 */
#define PIO_PA6A_USART2_TWD2                       (_UL_(1) << 6)

/* ========== PIO definition for USART3 peripheral ========== */
#define PIN_PA4A_USART3_RXD3                       _L_(4)       /**< USART3 signal: RXD3 on PA4 mux A*/
#define MUX_PA4A_USART3_RXD3                       _L_(0)       /**< USART3 signal line function value: RXD3 */
#define PIO_PA4A_USART3_RXD3                       (_UL_(1) << 4)

#define PIN_PA4A_USART3_SPI3_MISO                  _L_(4)       /**< USART3 signal: SPI3_MISO on PA4 mux A*/
#define MUX_PA4A_USART3_SPI3_MISO                  _L_(0)       /**< USART3 signal line function value: SPI3_MISO */
#define PIO_PA4A_USART3_SPI3_MISO                  (_UL_(1) << 4)

#define PIN_PA4A_USART3_TWCK3                      _L_(4)       /**< USART3 signal: TWCK3 on PA4 mux A*/
#define MUX_PA4A_USART3_TWCK3                      _L_(0)       /**< USART3 signal line function value: TWCK3 */
#define PIO_PA4A_USART3_TWCK3                      (_UL_(1) << 4)

#define PIN_PB13A_USART3_SCK3                      _L_(45)      /**< USART3 signal: SCK3 on PB13 mux A*/
#define MUX_PB13A_USART3_SCK3                      _L_(0)       /**< USART3 signal line function value: SCK3 */
#define PIO_PB13A_USART3_SCK3                      (_UL_(1) << 13)

#define PIN_PB13A_USART3_SPI3_SPCK                 _L_(45)      /**< USART3 signal: SPI3_SPCK on PB13 mux A*/
#define MUX_PB13A_USART3_SPI3_SPCK                 _L_(0)       /**< USART3 signal line function value: SPI3_SPCK */
#define PIO_PB13A_USART3_SPI3_SPCK                 (_UL_(1) << 13)

#define PIN_PB14A_USART3_SPI3_NPCS0                _L_(46)      /**< USART3 signal: SPI3_NPCS0 on PB14 mux A*/
#define MUX_PB14A_USART3_SPI3_NPCS0                _L_(0)       /**< USART3 signal line function value: SPI3_NPCS0 */
#define PIO_PB14A_USART3_SPI3_NPCS0                (_UL_(1) << 14)

#define PIN_PB14A_USART3_CTS3                      _L_(46)      /**< USART3 signal: CTS3 on PB14 mux A*/
#define MUX_PB14A_USART3_CTS3                      _L_(0)       /**< USART3 signal line function value: CTS3 */
#define PIO_PB14A_USART3_CTS3                      (_UL_(1) << 14)

#define PIN_PB15A_USART3_SPI3_NPCS1                _L_(47)      /**< USART3 signal: SPI3_NPCS1 on PB15 mux A*/
#define MUX_PB15A_USART3_SPI3_NPCS1                _L_(0)       /**< USART3 signal line function value: SPI3_NPCS1 */
#define PIO_PB15A_USART3_SPI3_NPCS1                (_UL_(1) << 15)

#define PIN_PB15A_USART3_RTS3                      _L_(47)      /**< USART3 signal: RTS3 on PB15 mux A*/
#define MUX_PB15A_USART3_RTS3                      _L_(0)       /**< USART3 signal line function value: RTS3 */
#define PIO_PB15A_USART3_RTS3                      (_UL_(1) << 15)

#define PIN_PA3A_USART3_TXD3                       _L_(3)       /**< USART3 signal: TXD3 on PA3 mux A*/
#define MUX_PA3A_USART3_TXD3                       _L_(0)       /**< USART3 signal line function value: TXD3 */
#define PIO_PA3A_USART3_TXD3                       (_UL_(1) << 3)

#define PIN_PA3A_USART3_SPI3_MOSI                  _L_(3)       /**< USART3 signal: SPI3_MOSI on PA3 mux A*/
#define MUX_PA3A_USART3_SPI3_MOSI                  _L_(0)       /**< USART3 signal line function value: SPI3_MOSI */
#define PIO_PA3A_USART3_SPI3_MOSI                  (_UL_(1) << 3)

#define PIN_PA3A_USART3_TWD3                       _L_(3)       /**< USART3 signal: TWD3 on PA3 mux A*/
#define MUX_PA3A_USART3_TWD3                       _L_(0)       /**< USART3 signal line function value: TWD3 */
#define PIO_PA3A_USART3_TWD3                       (_UL_(1) << 3)

/* ========== PIO definition for USART4 peripheral ========== */
#define PIN_PB9A_USART4_RXD4                       _L_(41)      /**< USART4 signal: RXD4 on PB9 mux A*/
#define MUX_PB9A_USART4_RXD4                       _L_(0)       /**< USART4 signal line function value: RXD4 */
#define PIO_PB9A_USART4_RXD4                       (_UL_(1) << 9)

#define PIN_PB9A_USART4_SPI4_MISO                  _L_(41)      /**< USART4 signal: SPI4_MISO on PB9 mux A*/
#define MUX_PB9A_USART4_SPI4_MISO                  _L_(0)       /**< USART4 signal line function value: SPI4_MISO */
#define PIO_PB9A_USART4_SPI4_MISO                  (_UL_(1) << 9)

#define PIN_PB9A_USART4_TWCK4                      _L_(41)      /**< USART4 signal: TWCK4 on PB9 mux A*/
#define MUX_PB9A_USART4_TWCK4                      _L_(0)       /**< USART4 signal line function value: TWCK4 */
#define PIO_PB9A_USART4_TWCK4                      (_UL_(1) << 9)

#define PIN_PB11A_USART4_RXD4                      _L_(43)      /**< USART4 signal: RXD4 on PB11 mux A*/
#define MUX_PB11A_USART4_RXD4                      _L_(0)       /**< USART4 signal line function value: RXD4 */
#define PIO_PB11A_USART4_RXD4                      (_UL_(1) << 11)

#define PIN_PB11A_USART4_SPI4_MISO                 _L_(43)      /**< USART4 signal: SPI4_MISO on PB11 mux A*/
#define MUX_PB11A_USART4_SPI4_MISO                 _L_(0)       /**< USART4 signal line function value: SPI4_MISO */
#define PIO_PB11A_USART4_SPI4_MISO                 (_UL_(1) << 11)

#define PIN_PB11A_USART4_TWCK4                     _L_(43)      /**< USART4 signal: TWCK4 on PB11 mux A*/
#define MUX_PB11A_USART4_TWCK4                     _L_(0)       /**< USART4 signal line function value: TWCK4 */
#define PIO_PB11A_USART4_TWCK4                     (_UL_(1) << 11)

#define PIN_PB1A_USART4_SCK4                       _L_(33)      /**< USART4 signal: SCK4 on PB1 mux A*/
#define MUX_PB1A_USART4_SCK4                       _L_(0)       /**< USART4 signal line function value: SCK4 */
#define PIO_PB1A_USART4_SCK4                       (_UL_(1) << 1)

#define PIN_PB1A_USART4_SPI4_SPCK                  _L_(33)      /**< USART4 signal: SPI4_SPCK on PB1 mux A*/
#define MUX_PB1A_USART4_SPI4_SPCK                  _L_(0)       /**< USART4 signal line function value: SPI4_SPCK */
#define PIO_PB1A_USART4_SPI4_SPCK                  (_UL_(1) << 1)

#define PIN_PB8B_USART4_SPI4_NPCS0                 _L_(40)      /**< USART4 signal: SPI4_NPCS0 on PB8 mux B*/
#define MUX_PB8B_USART4_SPI4_NPCS0                 _L_(1)       /**< USART4 signal line function value: SPI4_NPCS0 */
#define PIO_PB8B_USART4_SPI4_NPCS0                 (_UL_(1) << 8)

#define PIN_PB8B_USART4_CTS4                       _L_(40)      /**< USART4 signal: CTS4 on PB8 mux B*/
#define MUX_PB8B_USART4_CTS4                       _L_(1)       /**< USART4 signal line function value: CTS4 */
#define PIO_PB8B_USART4_CTS4                       (_UL_(1) << 8)

#define PIN_PB9B_USART4_SPI4_NPCS1                 _L_(41)      /**< USART4 signal: SPI4_NPCS1 on PB9 mux B*/
#define MUX_PB9B_USART4_SPI4_NPCS1                 _L_(1)       /**< USART4 signal line function value: SPI4_NPCS1 */
#define PIO_PB9B_USART4_SPI4_NPCS1                 (_UL_(1) << 9)

#define PIN_PB9B_USART4_RTS4                       _L_(41)      /**< USART4 signal: RTS4 on PB9 mux B*/
#define MUX_PB9B_USART4_RTS4                       _L_(1)       /**< USART4 signal line function value: RTS4 */
#define PIO_PB9B_USART4_RTS4                       (_UL_(1) << 9)

#define PIN_PB8A_USART4_TXD4                       _L_(40)      /**< USART4 signal: TXD4 on PB8 mux A*/
#define MUX_PB8A_USART4_TXD4                       _L_(0)       /**< USART4 signal line function value: TXD4 */
#define PIO_PB8A_USART4_TXD4                       (_UL_(1) << 8)

#define PIN_PB8A_USART4_SPI4_MOSI                  _L_(40)      /**< USART4 signal: SPI4_MOSI on PB8 mux A*/
#define MUX_PB8A_USART4_SPI4_MOSI                  _L_(0)       /**< USART4 signal line function value: SPI4_MOSI */
#define PIO_PB8A_USART4_SPI4_MOSI                  (_UL_(1) << 8)

#define PIN_PB8A_USART4_TWD4                       _L_(40)      /**< USART4 signal: TWD4 on PB8 mux A*/
#define MUX_PB8A_USART4_TWD4                       _L_(0)       /**< USART4 signal line function value: TWD4 */
#define PIO_PB8A_USART4_TWD4                       (_UL_(1) << 8)

#define PIN_PB10A_USART4_TXD4                      _L_(42)      /**< USART4 signal: TXD4 on PB10 mux A*/
#define MUX_PB10A_USART4_TXD4                      _L_(0)       /**< USART4 signal line function value: TXD4 */
#define PIO_PB10A_USART4_TXD4                      (_UL_(1) << 10)

#define PIN_PB10A_USART4_SPI4_MOSI                 _L_(42)      /**< USART4 signal: SPI4_MOSI on PB10 mux A*/
#define MUX_PB10A_USART4_SPI4_MOSI                 _L_(0)       /**< USART4 signal line function value: SPI4_MOSI */
#define PIO_PB10A_USART4_SPI4_MOSI                 (_UL_(1) << 10)

#define PIN_PB10A_USART4_TWD4                      _L_(42)      /**< USART4 signal: TWD4 on PB10 mux A*/
#define MUX_PB10A_USART4_TWD4                      _L_(0)       /**< USART4 signal line function value: TWD4 */
#define PIO_PB10A_USART4_TWD4                      (_UL_(1) << 10)

/* ========== PIO definition for USART5 peripheral ========== */
#define PIN_PA12A_USART5_RXD5                      _L_(12)      /**< USART5 signal: RXD5 on PA12 mux A*/
#define MUX_PA12A_USART5_RXD5                      _L_(0)       /**< USART5 signal line function value: RXD5 */
#define PIO_PA12A_USART5_RXD5                      (_UL_(1) << 12)

#define PIN_PA12A_USART5_SPI5_MISO                 _L_(12)      /**< USART5 signal: SPI5_MISO on PA12 mux A*/
#define MUX_PA12A_USART5_SPI5_MISO                 _L_(0)       /**< USART5 signal line function value: SPI5_MISO */
#define PIO_PA12A_USART5_SPI5_MISO                 (_UL_(1) << 12)

#define PIN_PA12A_USART5_TWCK5                     _L_(12)      /**< USART5 signal: TWCK5 on PA12 mux A*/
#define MUX_PA12A_USART5_TWCK5                     _L_(0)       /**< USART5 signal line function value: TWCK5 */
#define PIO_PA12A_USART5_TWCK5                     (_UL_(1) << 12)

#define PIN_PA14A_USART5_SCK5                      _L_(14)      /**< USART5 signal: SCK5 on PA14 mux A*/
#define MUX_PA14A_USART5_SCK5                      _L_(0)       /**< USART5 signal line function value: SCK5 */
#define PIO_PA14A_USART5_SCK5                      (_UL_(1) << 14)

#define PIN_PA14A_USART5_SPI5_SPCK                 _L_(14)      /**< USART5 signal: SPI5_SPCK on PA14 mux A*/
#define MUX_PA14A_USART5_SPI5_SPCK                 _L_(0)       /**< USART5 signal line function value: SPI5_SPCK */
#define PIO_PA14A_USART5_SPI5_SPCK                 (_UL_(1) << 14)

#define PIN_PA11A_USART5_SPI5_NPCS0                _L_(11)      /**< USART5 signal: SPI5_NPCS0 on PA11 mux A*/
#define MUX_PA11A_USART5_SPI5_NPCS0                _L_(0)       /**< USART5 signal line function value: SPI5_NPCS0 */
#define PIO_PA11A_USART5_SPI5_NPCS0                (_UL_(1) << 11)

#define PIN_PA11A_USART5_CTS5                      _L_(11)      /**< USART5 signal: CTS5 on PA11 mux A*/
#define MUX_PA11A_USART5_CTS5                      _L_(0)       /**< USART5 signal line function value: CTS5 */
#define PIO_PA11A_USART5_CTS5                      (_UL_(1) << 11)

#define PIN_PA5B_USART5_SPI5_NPCS1                 _L_(5)       /**< USART5 signal: SPI5_NPCS1 on PA5 mux B*/
#define MUX_PA5B_USART5_SPI5_NPCS1                 _L_(1)       /**< USART5 signal line function value: SPI5_NPCS1 */
#define PIO_PA5B_USART5_SPI5_NPCS1                 (_UL_(1) << 5)

#define PIN_PA5B_USART5_RTS5                       _L_(5)       /**< USART5 signal: RTS5 on PA5 mux B*/
#define MUX_PA5B_USART5_RTS5                       _L_(1)       /**< USART5 signal line function value: RTS5 */
#define PIO_PA5B_USART5_RTS5                       (_UL_(1) << 5)

#define PIN_PB2B_USART5_SPI5_NPCS1                 _L_(34)      /**< USART5 signal: SPI5_NPCS1 on PB2 mux B*/
#define MUX_PB2B_USART5_SPI5_NPCS1                 _L_(1)       /**< USART5 signal line function value: SPI5_NPCS1 */
#define PIO_PB2B_USART5_SPI5_NPCS1                 (_UL_(1) << 2)

#define PIN_PB2B_USART5_RTS5                       _L_(34)      /**< USART5 signal: RTS5 on PB2 mux B*/
#define MUX_PB2B_USART5_RTS5                       _L_(1)       /**< USART5 signal line function value: RTS5 */
#define PIO_PB2B_USART5_RTS5                       (_UL_(1) << 2)

#define PIN_PA13A_USART5_TXD5                      _L_(13)      /**< USART5 signal: TXD5 on PA13 mux A*/
#define MUX_PA13A_USART5_TXD5                      _L_(0)       /**< USART5 signal line function value: TXD5 */
#define PIO_PA13A_USART5_TXD5                      (_UL_(1) << 13)

#define PIN_PA13A_USART5_SPI5_MOSI                 _L_(13)      /**< USART5 signal: SPI5_MOSI on PA13 mux A*/
#define MUX_PA13A_USART5_SPI5_MOSI                 _L_(0)       /**< USART5 signal line function value: SPI5_MOSI */
#define PIO_PA13A_USART5_SPI5_MOSI                 (_UL_(1) << 13)

#define PIN_PA13A_USART5_TWD5                      _L_(13)      /**< USART5 signal: TWD5 on PA13 mux A*/
#define MUX_PA13A_USART5_TWD5                      _L_(0)       /**< USART5 signal line function value: TWD5 */
#define PIO_PA13A_USART5_TWD5                      (_UL_(1) << 13)

/* ========== PIO definition for USART6 peripheral ========== */
#define PIN_PB1B_USART6_RXD6                       _L_(33)      /**< USART6 signal: RXD6 on PB1 mux B*/
#define MUX_PB1B_USART6_RXD6                       _L_(1)       /**< USART6 signal line function value: RXD6 */
#define PIO_PB1B_USART6_RXD6                       (_UL_(1) << 1)

#define PIN_PB1B_USART6_SPI6_MISO                  _L_(33)      /**< USART6 signal: SPI6_MISO on PB1 mux B*/
#define MUX_PB1B_USART6_SPI6_MISO                  _L_(1)       /**< USART6 signal line function value: SPI6_MISO */
#define PIO_PB1B_USART6_SPI6_MISO                  (_UL_(1) << 1)

#define PIN_PB1B_USART6_TWCK6                      _L_(33)      /**< USART6 signal: TWCK6 on PB1 mux B*/
#define MUX_PB1B_USART6_TWCK6                      _L_(1)       /**< USART6 signal line function value: TWCK6 */
#define PIO_PB1B_USART6_TWCK6                      (_UL_(1) << 1)

#define PIN_PB11B_USART6_RXD6                      _L_(43)      /**< USART6 signal: RXD6 on PB11 mux B*/
#define MUX_PB11B_USART6_RXD6                      _L_(1)       /**< USART6 signal line function value: RXD6 */
#define PIO_PB11B_USART6_RXD6                      (_UL_(1) << 11)

#define PIN_PB11B_USART6_SPI6_MISO                 _L_(43)      /**< USART6 signal: SPI6_MISO on PB11 mux B*/
#define MUX_PB11B_USART6_SPI6_MISO                 _L_(1)       /**< USART6 signal line function value: SPI6_MISO */
#define PIO_PB11B_USART6_SPI6_MISO                 (_UL_(1) << 11)

#define PIN_PB11B_USART6_TWCK6                     _L_(43)      /**< USART6 signal: TWCK6 on PB11 mux B*/
#define MUX_PB11B_USART6_TWCK6                     _L_(1)       /**< USART6 signal line function value: TWCK6 */
#define PIO_PB11B_USART6_TWCK6                     (_UL_(1) << 11)

#define PIN_PB13B_USART6_SCK6                      _L_(45)      /**< USART6 signal: SCK6 on PB13 mux B*/
#define MUX_PB13B_USART6_SCK6                      _L_(1)       /**< USART6 signal line function value: SCK6 */
#define PIO_PB13B_USART6_SCK6                      (_UL_(1) << 13)

#define PIN_PB13B_USART6_SPI6_SPCK                 _L_(45)      /**< USART6 signal: SPI6_SPCK on PB13 mux B*/
#define MUX_PB13B_USART6_SPI6_SPCK                 _L_(1)       /**< USART6 signal line function value: SPI6_SPCK */
#define PIO_PB13B_USART6_SPI6_SPCK                 (_UL_(1) << 13)

#define PIN_PB14B_USART6_SPI6_NPCS0                _L_(46)      /**< USART6 signal: SPI6_NPCS0 on PB14 mux B*/
#define MUX_PB14B_USART6_SPI6_NPCS0                _L_(1)       /**< USART6 signal line function value: SPI6_NPCS0 */
#define PIO_PB14B_USART6_SPI6_NPCS0                (_UL_(1) << 14)

#define PIN_PB14B_USART6_CTS6                      _L_(46)      /**< USART6 signal: CTS6 on PB14 mux B*/
#define MUX_PB14B_USART6_CTS6                      _L_(1)       /**< USART6 signal line function value: CTS6 */
#define PIO_PB14B_USART6_CTS6                      (_UL_(1) << 14)

#define PIN_PB15B_USART6_SPI6_NPCS1                _L_(47)      /**< USART6 signal: SPI6_NPCS1 on PB15 mux B*/
#define MUX_PB15B_USART6_SPI6_NPCS1                _L_(1)       /**< USART6 signal line function value: SPI6_NPCS1 */
#define PIO_PB15B_USART6_SPI6_NPCS1                (_UL_(1) << 15)

#define PIN_PB15B_USART6_RTS6                      _L_(47)      /**< USART6 signal: RTS6 on PB15 mux B*/
#define MUX_PB15B_USART6_RTS6                      _L_(1)       /**< USART6 signal line function value: RTS6 */
#define PIO_PB15B_USART6_RTS6                      (_UL_(1) << 15)

#define PIN_PB0B_USART6_TXD6                       _L_(32)      /**< USART6 signal: TXD6 on PB0 mux B*/
#define MUX_PB0B_USART6_TXD6                       _L_(1)       /**< USART6 signal line function value: TXD6 */
#define PIO_PB0B_USART6_TXD6                       (_UL_(1) << 0)

#define PIN_PB0B_USART6_SPI6_MOSI                  _L_(32)      /**< USART6 signal: SPI6_MOSI on PB0 mux B*/
#define MUX_PB0B_USART6_SPI6_MOSI                  _L_(1)       /**< USART6 signal line function value: SPI6_MOSI */
#define PIO_PB0B_USART6_SPI6_MOSI                  (_UL_(1) << 0)

#define PIN_PB0B_USART6_TWD6                       _L_(32)      /**< USART6 signal: TWD6 on PB0 mux B*/
#define MUX_PB0B_USART6_TWD6                       _L_(1)       /**< USART6 signal line function value: TWD6 */
#define PIO_PB0B_USART6_TWD6                       (_UL_(1) << 0)

#define PIN_PB10B_USART6_TXD6                      _L_(42)      /**< USART6 signal: TXD6 on PB10 mux B*/
#define MUX_PB10B_USART6_TXD6                      _L_(1)       /**< USART6 signal line function value: TXD6 */
#define PIO_PB10B_USART6_TXD6                      (_UL_(1) << 10)

#define PIN_PB10B_USART6_SPI6_MOSI                 _L_(42)      /**< USART6 signal: SPI6_MOSI on PB10 mux B*/
#define MUX_PB10B_USART6_SPI6_MOSI                 _L_(1)       /**< USART6 signal line function value: SPI6_MOSI */
#define PIO_PB10B_USART6_SPI6_MOSI                 (_UL_(1) << 10)

#define PIN_PB10B_USART6_TWD6                      _L_(42)      /**< USART6 signal: TWD6 on PB10 mux B*/
#define MUX_PB10B_USART6_TWD6                      _L_(1)       /**< USART6 signal line function value: TWD6 */
#define PIO_PB10B_USART6_TWD6                      (_UL_(1) << 10)

/* ========== PIO definition for USART7 peripheral ========== */
#define PIN_PA27B_USART7_RXD7                      _L_(27)      /**< USART7 signal: RXD7 on PA27 mux B*/
#define MUX_PA27B_USART7_RXD7                      _L_(1)       /**< USART7 signal line function value: RXD7 */
#define PIO_PA27B_USART7_RXD7                      (_UL_(1) << 27)

#define PIN_PA27B_USART7_SPI7_MISO                 _L_(27)      /**< USART7 signal: SPI7_MISO on PA27 mux B*/
#define MUX_PA27B_USART7_SPI7_MISO                 _L_(1)       /**< USART7 signal line function value: SPI7_MISO */
#define PIO_PA27B_USART7_SPI7_MISO                 (_UL_(1) << 27)

#define PIN_PA27B_USART7_TWCK7                     _L_(27)      /**< USART7 signal: TWCK7 on PA27 mux B*/
#define MUX_PA27B_USART7_TWCK7                     _L_(1)       /**< USART7 signal line function value: TWCK7 */
#define PIO_PA27B_USART7_TWCK7                     (_UL_(1) << 27)

#define PIN_PA29B_USART7_SCK7                      _L_(29)      /**< USART7 signal: SCK7 on PA29 mux B*/
#define MUX_PA29B_USART7_SCK7                      _L_(1)       /**< USART7 signal line function value: SCK7 */
#define PIO_PA29B_USART7_SCK7                      (_UL_(1) << 29)

#define PIN_PA29B_USART7_SPI7_SPCK                 _L_(29)      /**< USART7 signal: SPI7_SPCK on PA29 mux B*/
#define MUX_PA29B_USART7_SPI7_SPCK                 _L_(1)       /**< USART7 signal line function value: SPI7_SPCK */
#define PIO_PA29B_USART7_SPI7_SPCK                 (_UL_(1) << 29)

#define PIN_PA30B_USART7_SPI7_NPCS0                _L_(30)      /**< USART7 signal: SPI7_NPCS0 on PA30 mux B*/
#define MUX_PA30B_USART7_SPI7_NPCS0                _L_(1)       /**< USART7 signal line function value: SPI7_NPCS0 */
#define PIO_PA30B_USART7_SPI7_NPCS0                (_UL_(1) << 30)

#define PIN_PA30B_USART7_CTS7                      _L_(30)      /**< USART7 signal: CTS7 on PA30 mux B*/
#define MUX_PA30B_USART7_CTS7                      _L_(1)       /**< USART7 signal line function value: CTS7 */
#define PIO_PA30B_USART7_CTS7                      (_UL_(1) << 30)

#define PIN_PA31B_USART7_SPI7_NPCS1                _L_(31)      /**< USART7 signal: SPI7_NPCS1 on PA31 mux B*/
#define MUX_PA31B_USART7_SPI7_NPCS1                _L_(1)       /**< USART7 signal line function value: SPI7_NPCS1 */
#define PIO_PA31B_USART7_SPI7_NPCS1                (_UL_(1) << 31)

#define PIN_PA31B_USART7_RTS7                      _L_(31)      /**< USART7 signal: RTS7 on PA31 mux B*/
#define MUX_PA31B_USART7_RTS7                      _L_(1)       /**< USART7 signal line function value: RTS7 */
#define PIO_PA31B_USART7_RTS7                      (_UL_(1) << 31)

#define PIN_PA28B_USART7_TXD7                      _L_(28)      /**< USART7 signal: TXD7 on PA28 mux B*/
#define MUX_PA28B_USART7_TXD7                      _L_(1)       /**< USART7 signal line function value: TXD7 */
#define PIO_PA28B_USART7_TXD7                      (_UL_(1) << 28)

#define PIN_PA28B_USART7_SPI7_MOSI                 _L_(28)      /**< USART7 signal: SPI7_MOSI on PA28 mux B*/
#define MUX_PA28B_USART7_SPI7_MOSI                 _L_(1)       /**< USART7 signal line function value: SPI7_MOSI */
#define PIO_PA28B_USART7_SPI7_MOSI                 (_UL_(1) << 28)

#define PIN_PA28B_USART7_TWD7                      _L_(28)      /**< USART7 signal: TWD7 on PA28 mux B*/
#define MUX_PA28B_USART7_TWD7                      _L_(1)       /**< USART7 signal line function value: TWD7 */
#define PIO_PA28B_USART7_TWD7                      (_UL_(1) << 28)


#endif /* _SAMG55J19_PIO_H_ */
