/**
 * @file pwm.c
 * @author Christian Sargusingh
 * @brief PWM driver for PORTB0 using CCP1. PWM CCP operation uses TIMER2.
 * @version 0.1
 * @date 2023-05
 *
 * @copyright Copyright © 2023 Christian Sargusingh
 *
 */

#include "pwm.h"

#include <xc.h>

#include "configuration.h"

#define TMR2_PRESCALER 1

/**
 * @brief
 */

/**
 * @brief Initialize PWM : 25.3.2 setup for pwm operation
 *
 * @param period
 * @param duty
 */
void pwm_init(uint8_t period, uint16_t duty) {
  APFCON1bits.CCP1SEL = 1;  // set CCP1 to drive pin RB0
  TRISBbits.TRISB0 = 1;
  T2CONbits.T2CKPS = 0x0;  // prescaler 1
  PR2 = (period / 4 * (1 / FCLK) * TMR2_PRESCALER) + 1;
  CCP1CONbits.CCP1M = 0xc;  // pwm mode
  pwm_set_duty(duty);
}

/**
 * @brief Enable pwm timers and output. Wait for a full duty cycle to be latched.
 *
 * @return pwm_status_t
 */
pwm_status_t pwm_enable(void) {
  PIR1bits.TMR2IF = 0;
  // start timer
  T2CONbits.TMR2ON = 1;
  // wait to send a complete duty cycle and period on the first PWM output
  // The duty cycle value is not latched into CCPRxH until after the period completes
  while (!PIR1bits.TMR2IF)
    ;
  // enable pwm output pin
  TRISBbits.TRISB0 = 0;
  return PWM_OK;
}

/**
 * @brief Disable pwm output and timer.
 *
 * @return pwm_status_t
 */
pwm_status_t pwm_disable(void) {
  // stop timer
  T2CONbits.TMR2ON = 0;
  // disable output
  TRISBbits.TRISB0 = 1;
  return PWM_OK;
};

/**
 * @brief Set pwm pulse width. Maximum 10 bit resolution.
 *
 * @param duty pulse width in timer ticks
 * @return pwm_status_t
 */
pwm_status_t pwm_set_duty(uint16_t duty) {
  duty &= 0x3ff;
  CCPR1L = (uint8_t)(duty & 0x3fc);
  CCP1CONbits.DC1B = (duty & 0x3);
  return PWM_OK;
};
