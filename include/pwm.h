/**
 * @file pwm.h
 * @author Christian Sargusingh
 * @brief
 * @version 0.1
 * @date 2023-05
 *
 * @copyright Copyright © 2023 Christian Sargusingh
 *
 */

#ifndef __PWM_H__
#define __PWM_H__

#include <stdint.h>

typedef uint8_t pwm_status_t;

#define PWM_OK (pwm_status_t)0
#define PWM_FAIL (pwm_status_t)1

// 25.3 PWM Overview

void pwm_init(uint8_t period, uint16_t duty);
pwm_status_t pwm_enable(void);
pwm_status_t pwm_disable(void);
pwm_status_t pwm_set_duty(uint16_t duty);

#endif  // __PWM_H__
