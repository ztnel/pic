/**
 * @file configuration.h
 * @author your name (you@domain.com)
 * @brief Configuration bits for the PIC16F1788. A description of the bits is provided here:
 * https://microchipdeveloper.com/8bit:emr-configuration-bits
 * @version 0.1
 * @date 2023-05
 *
 * @copyright Copyright © 2023 Christian Sargusingh
 *
 */

#ifndef __CONFIGURATION_H__
#define __CONFIGURATION_H__

#define FCLK 32000000

// FOSC selects the clock source for MCU.
#pragma config FOSC = ECH

/**
 * @brief WDTE allows an MCU RESET to occur if the internal Watchdog Timer rolls over from 0xFF to 0x00 before the MCU can execute a CLRWDT instruction.
 *
 */
#pragma config WDTE = ON
/**
 * @brief The Power-up Time provides a nominal 72 ms delay after a Power-on Reset or a Brown-out Reset to allow Vdd to stabilize. Enabling or disabling this delay is controlled by PWRTE.
 *
 */
#pragma config PWRTE = ON

/**
 * @brief MCLRE controls the function of the MCLR /Vpp pin.
 * 1  	ON	Pin function is MCLR /Vpp with internal weak pull-up enabled
 * 0  	OFF	Pin function is digital input with internal pull-up controlled by WPUx
 */
#pragma config MCLRE = ON

// The entire program memory space can be protected from external reads with CP .
#ifdef __DEBUG
#pragma config CP = OFF
#else
#pragma config CP = ON
#endif

// BOREN allows an MCU RESET to occur if Vdd drops below a preset value. The voltage level precipitating the RESET is determined by the configuration bit BORV.
#pragma config BOREN = ON

// CLKOUTEN allows the OSCx/CLCKOUT pin to output the internal system clock. This allows the PIC16F1xxx system clock to drive other components.
#pragma config CLKOUTEN = OFF

// The internal data EEPROM memory can be protected from external reads with CPD . External programmers are prohibited from reading protected EEPROM. The contents of EEPROM is still available for reads from internal sources.
#ifdef __DEBUG
#pragma config CPD = OFF
#else
#pragma config CPD = ON
#endif

// The internal oscillator's 4 X Phase Lock Loop (PLL) is controlled by a combination of the PLLEN configuration bit and the SPLLEN bit in the OSCON register.
#pragma config PLLEN = ON

/**
 * @brief Low Voltage programming entry mode allows PIC16F1xxx MCUs to be programmed with only Vdd. Using LVP eliminates the need to supply a higher than Vdd voltage on MCLR/Vpp.
 *
 */
#pragma config LVP = ON

// BORV selects one of two pre-set voltage levels as the Brown-out Reset voltage.
#pragma config BORV = HI  // 2.5V (LO 1.9V)

/**
 * @brief The STVREN configuration bit enables or disables a RESET on a stack overflow or underflow.
A stack overflow or underflow always sets the STKOVF or STKUNF bit in the PCON register regardless of STVREN's value.
 *
 */
#ifdef __DEBUG
#pragma config STVREN = OFF
#else
#pragma config STVREN = ON
#endif

/**
 * @brief WRT establishes the address range in which the program memory can be written by the user program.
 * 1 0	BOOT	Address range 0 - 0x1FF write protected 200 h - FFFn write-able
 * 0 1	HALF	Address range 0 - 0x7FF write protected 800 h - FFFn write-able
 */
// #ifdef __DEBUG
// #pragma config WRT = ON
// #else
// #pragma config WRT = BOOT
// #endif

// FCMEN controls the operation of the Fail-Safe Clock Monitor allowing the clock to switch from external to internal in the event of an external clock failure.
#ifdef __DEBUG
#pragma config FCMEN = OFF
#else
#pragma config FCMEN = ON
#endif

// IESO sets the mode for clock switching and two-speed start-up. With IESO enabled the clock source can be controlled by the application program.
#pragma config IESO = OFF

// For devices with an internal LDO regulator, VCAPEN determines which pin is assigned as the Vcap pin.
#pragma config VCAPEN = OFF

#endif  // __CONFIGURATION_H__