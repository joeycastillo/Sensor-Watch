/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef ATMEL_START_PINS_H_INCLUDED
#define ATMEL_START_PINS_H_INCLUDED

#include <hal_gpio.h>

// SAML22 has 9 pin functions

#define GPIO_PIN_FUNCTION_A 0
#define GPIO_PIN_FUNCTION_B 1
#define GPIO_PIN_FUNCTION_C 2
#define GPIO_PIN_FUNCTION_D 3
#define GPIO_PIN_FUNCTION_E 4
#define GPIO_PIN_FUNCTION_F 5
#define GPIO_PIN_FUNCTION_G 6
#define GPIO_PIN_FUNCTION_H 7
#define GPIO_PIN_FUNCTION_I 8

#define VBUS_DET GPIO(GPIO_PORTA, 2)
#define SEG1 GPIO(GPIO_PORTA, 4)
#define SEG2 GPIO(GPIO_PORTA, 5)
#define SEG3 GPIO(GPIO_PORTA, 6)
#define SEG4 GPIO(GPIO_PORTA, 7)
#define SEG5 GPIO(GPIO_PORTA, 8)
#define SEG6 GPIO(GPIO_PORTA, 9)
#define SEG7 GPIO(GPIO_PORTA, 10)
#define SEG8 GPIO(GPIO_PORTA, 11)
#define SEG14 GPIO(GPIO_PORTA, 12)
#define SEG15 GPIO(GPIO_PORTA, 13)
#define SEG16 GPIO(GPIO_PORTA, 14)
#define SEG17 GPIO(GPIO_PORTA, 15)
#define SEG18 GPIO(GPIO_PORTA, 16)
#define SEG19 GPIO(GPIO_PORTA, 17)
#define SEG20 GPIO(GPIO_PORTA, 18)
#define SEG21 GPIO(GPIO_PORTA, 19)
#define RED GPIO(GPIO_PORTA, 20)
#define GREEN GPIO(GPIO_PORTA, 21)
#define BTN_LIGHT GPIO(GPIO_PORTA, 22)
#define BTN_MODE GPIO(GPIO_PORTA, 23)
#define BUZZER GPIO(GPIO_PORTA, 27)
#define A0 GPIO(GPIO_PORTB, 4)
#define A1 GPIO(GPIO_PORTB, 1)
#define A2 GPIO(GPIO_PORTB, 2)
#define A3 GPIO(GPIO_PORTB, 3)
#define A4 GPIO(GPIO_PORTB, 0)
#define D0 GPIO(GPIO_PORTB, 3)
#define D1 GPIO(GPIO_PORTB, 0)
#define BTN_ALARM GPIO(GPIO_PORTA, 2)
#define COM0 GPIO(GPIO_PORTB, 6)
#define COM1 GPIO(GPIO_PORTB, 7)
#define COM2 GPIO(GPIO_PORTB, 8)
#define SEG0 GPIO(GPIO_PORTB, 9)
#define SEG9 GPIO(GPIO_PORTB, 11)
#define SEG10 GPIO(GPIO_PORTB, 12)
#define SEG11 GPIO(GPIO_PORTB, 13)
#define SEG12 GPIO(GPIO_PORTB, 14)
#define SEG13 GPIO(GPIO_PORTB, 15)
#define SEG22 GPIO(GPIO_PORTB, 16)
#define SEG23 GPIO(GPIO_PORTB, 17)
#define SDA GPIO(GPIO_PORTB, 30)
#define SCL GPIO(GPIO_PORTB, 31)

#endif // ATMEL_START_PINS_H_INCLUDED
