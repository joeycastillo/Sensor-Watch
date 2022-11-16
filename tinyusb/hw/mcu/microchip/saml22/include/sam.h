/**
 * \file
 *
 * \brief Top level header file
 *
 * Copyright (c) 2018 Microchip Technology Inc.
 *
 * \license_start
 *
 * \page License
 *
 * SPDX-License-Identifier: Apache-2.0
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

#ifndef _SAM_
#define _SAM_

#if defined(__SAML22G16A__) || defined(__ATSAML22G16A__)
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
#error Library does not support the specified device
#endif

#endif /* _SAM_ */
