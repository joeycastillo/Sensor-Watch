/**
 * \file
 *
 * \brief Instance description for PTC
 *
 * Copyright (c) 2018 Microchip Technology Inc.
 *
 * \asf_license_start
 *
 * \page License
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the Licence at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * \asf_license_stop
 *
 */

#ifndef _SAML22_PTC_INSTANCE_
#define _SAML22_PTC_INSTANCE_

/* ========== Instance parameters for PTC peripheral ========== */
#define PTC_DMAC_ID_EOC             37       // Index of DMA EOC trigger
#define PTC_DMAC_ID_SEQ             38       // Index of DMA SEQ trigger
#define PTC_DMAC_ID_WCOMP           39       // Index of DMA WCOMP trigger
#define PTC_GCLK_ID                 27       // Index of Generic Clock
#define PTC_LINES_MSB               31      
#define PTC_LINES_NUM               32       // Number of PTC lines
#define PTC_Y_LINES_MSB             23      
#define PTC_Y_LINES_NUM             24       // Number of Y lines

#endif /* _SAML22_PTC_INSTANCE_ */
