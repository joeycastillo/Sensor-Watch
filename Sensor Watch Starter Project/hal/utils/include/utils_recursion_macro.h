/**
 * \file
 *
 * \brief Recursion macro.
 *
 * Copyright (c) 2014-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */

#ifndef _UTILS_RECURSION_MACRO_H
#define _UTILS_RECURSION_MACRO_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * \brief Macro recursion
 *
 * \param[in] macro Macro to be repeated recursively
 * \param[in] arg A recursive threshold, building on this to decline by times
 *                defined with parameter n
 * \param[in] n The number of repetitious calls to macro
 */
#define RECURSION_MACRO(macro, arg, n) RECURSION_MACRO_I(macro, arg, n)

/*
 * \brief Second level is needed to get integer literal from "n" if it is
 *        defined as macro
 */
#define RECURSION_MACRO_I(macro, arg, n) RECURSION##n(macro, arg)

#define RECURSION0(macro, arg)
#define RECURSION1(macro, arg) RECURSION0(macro, DEC_VALUE(arg)) macro(arg, 0)
#define RECURSION2(macro, arg) RECURSION1(macro, DEC_VALUE(arg)) macro(arg, 1)
#define RECURSION3(macro, arg) RECURSION2(macro, DEC_VALUE(arg)) macro(arg, 2)
#define RECURSION4(macro, arg) RECURSION3(macro, DEC_VALUE(arg)) macro(arg, 3)
#define RECURSION5(macro, arg) RECURSION4(macro, DEC_VALUE(arg)) macro(arg, 4)

#ifdef __cplusplus
}
#endif

#include <utils_decrement_macro.h>
#endif /* _UTILS_RECURSION_MACRO_H */
