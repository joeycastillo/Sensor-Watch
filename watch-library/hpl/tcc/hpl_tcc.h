/**
 * \file
 *
 * \brief SAM Timer/Counter for Control Applications
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
 */

#ifndef _HPL_TCC_V101_BASE_H_INCLUDED
#define _HPL_TCC_V101_BASE_H_INCLUDED

#include <hpl_timer.h>
#include <hpl_pwm.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \addtogroup tcc_group TCC Low Level Driver Helpers
 *
 * \section tcc_helpers_rev Revision History
 * - v0.0.0.1 Initial Commit
 *
 *@{
 */

/**
 * \name HPL functions
 */
//@{

/**
 * \brief Retrieve timer helper functions
 *
 * \return A pointer to set of timer helper functions
 */
struct _timer_hpl_interface *_tcc_get_timer(void);
/**
 * \brief Initialize TCC for PWM
 *
 * This function does low level TCC configuration.
 *
 * \param[in] device The pointer to PWM device instance
 * \param[in] hw The pointer to hardware instance
 *
 * \return Initialization status.
 */
int32_t _tcc_pwm_init(struct _pwm_device *const device, void *const hw);

/**
 * \brief De-initialize TCC for PWM
 *
 * \param[in] device The pointer to TCC device instance
 */
void _tcc_pwm_deinit(struct _pwm_device *const device);

/**
 * \brief Retrieve offset of the given tcc hardware instance
 *
 * \param[in] device The pointer to TCC device instance
 *
 * \return The offset of the given tcc hardware instance
 */
uint8_t _tcc_pwm_get_hardware_offset(const struct _pwm_device *const device);

/**
 * \brief Start PWM
 *
 * \param[in] device The pointer to TCC device instance
 */
void _tcc_start_pwm(struct _pwm_device *const device);

/**
 * \brief Stop PWM
 *
 * \param[in] device The pointer to TCC device instance
 */
void _tcc_stop_pwm(struct _pwm_device *const device);

/**
 * \brief Check if PWM is running
 *
 * \param[in] device The pointer to TCC device instance
 *
 * \return Check status.
 * \retval true The given pwm is running
 * \retval false The given pwm is not running
 */
bool _tcc_is_pwm_enabled(const struct _pwm_device *const device);

/**
 * \brief Set PWM parameter
 * \param[in] device The pointer to TCC device instance
 * \param[in] period Total period of one PWM cycle.
 * \param[in] duty_cycle Period of PWM first half during one cycle.
 */
void _tcc_set_pwm_param(struct _pwm_device *const device, const pwm_period_t period, const pwm_period_t duty_cycle);

/**
 * \brief Get pwm waveform period value
 * \param[in] device The pointer to TCC device instance
 * \return Period value.
 */
pwm_period_t _tcc_pwm_get_period(const struct _pwm_device *const device);

/**
 * \brief Get pwm waveform duty cycle value
 * \param[in] device The pointer to TCC device instance
 * \return Duty cycle value
 */
uint32_t _tcc_pwm_get_duty(const struct _pwm_device *const device);

/**
 * \brief Enable/disable PWM interrupt
 *
 * param[in] device The pointer to PWM device instance
 * param[in] type The type of interrupt to disable/enable if applicable
 * param[in] disable Enable or disable
 */
void _tcc_pwm_set_irq_state(struct _pwm_device *const device, const enum _pwm_callback_type type, const bool disable);

/**
 * \brief Retrieve pwm helper functions
 *
 * \return A pointer to set of pwm helper functions
 */
struct _pwm_hpl_interface *_tcc_get_pwm(void);

//@}
/**@}*/

#ifdef __cplusplus
}
#endif
#endif /* _HPL_TCC_V101_BASE_H_INCLUDED */
