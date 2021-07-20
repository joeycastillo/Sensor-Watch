/**
 * \file
 *
 * \brief Top header file for SAML22
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

#ifndef _SAML22_
#define _SAML22_

/**
 * \defgroup SAML22_definitions SAML22 Device Definitions
 * \brief SAML22 CMSIS Definitions.
 */

#if   defined(__SAML22G16A__) || defined(__ATSAML22G16A__)
  #include "saml22g16a.h"
#elif defined(__SAML22G17A__) || defined(__ATSAML22G17A__)
  #include "saml22g17a.h"
#elif defined(__SAML22G18A__) || defined(__ATSAML22G18A__)
  #include "saml22g18a.h"
#elif defined(__SAML22J16A__) || defined(__ATSAML22J16A__)
  #include "saml22j16a.h"
#elif defined(__SAML22J17A__) || defined(__ATSAML22J17A__)
  #include "saml22j17a.h"
#elif defined(__SAML22J18A__) || defined(__ATSAML22J18A__)
  #include "saml22j18a.h"
#elif defined(__SAML22N16A__) || defined(__ATSAML22N16A__)
  #include "saml22n16a.h"
#elif defined(__SAML22N17A__) || defined(__ATSAML22N17A__)
  #include "saml22n17a.h"
#elif defined(__SAML22N18A__) || defined(__ATSAML22N18A__)
  #include "saml22n18a.h"
#else
  #error Library does not support the specified device.
#endif

#endif /* _SAML22_ */
