/*!
 * @file GPIO_Config.h
 * @author Demitrias Wilbert 
 * @brief definition to pointer to each pin configuration structure type (PinId_t)
 * @version 0.1
 * @date 2021-07-08
 * 
 * 
*/

#ifndef GPIO_CONFIG_H
#define GPIO_CONFIG_H

#include "main.h"

/*!
 * @struct PinId_t
 * @brief pin configuration structure typedef
 * 
 * @var PinId_t::GPIO_TypeDef 
 *  pointer to the pin GPIO Base
 * @var PinId_t::pinmask
 *  bitmask of the pin
 * @var PinId_t::pin
 *  index of the pin
 * 
*/
typedef struct
{
    GPIO_TypeDef* GPIOx;
    uint16_t pinmask;
    uint16_t pin;
} PinId_t;


/*!
 * @brief 
 * undef the unnecessary GPIOs to save memory
 * e.g: STM32F103C8T6 only has GPIOA, GPIOB, GPIOC, GPIOD
 * so undef the rest
 *
*/


#ifdef GPIOA
extern const PinId_t PIN_PA0;
#define PA0 ((PinId_t*) &PIN_PA0)
extern const PinId_t PIN_PA1;
#define PA1 ((PinId_t*) &PIN_PA1)
extern const PinId_t PIN_PA2;
#define PA2 ((PinId_t*) &PIN_PA2)
extern const PinId_t PIN_PA3;
#define PA3 ((PinId_t*) &PIN_PA3)
extern const PinId_t PIN_PA4;
#define PA4 ((PinId_t*) &PIN_PA4)
extern const PinId_t PIN_PA5;
#define PA5 ((PinId_t*) &PIN_PA5)
extern const PinId_t PIN_PA6;
#define PA6 ((PinId_t*) &PIN_PA6)
extern const PinId_t PIN_PA7;
#define PA7 ((PinId_t*) &PIN_PA7)
extern const PinId_t PIN_PA8;
#define PA8 ((PinId_t*) &PIN_PA8)
extern const PinId_t PIN_PA9;
#define PA9 ((PinId_t*) &PIN_PA9)
extern const PinId_t PIN_PA10;
#define PA10 ((PinId_t*) &PIN_PA10)
extern const PinId_t PIN_PA11;
#define PA11 ((PinId_t*) &PIN_PA11)
extern const PinId_t PIN_PA12;
#define PA12 ((PinId_t*) &PIN_PA12)
extern const PinId_t PIN_PA13;
#define PA13 ((PinId_t*) &PIN_PA13)
extern const PinId_t PIN_PA14;
#define PA14 ((PinId_t*) &PIN_PA14)
extern const PinId_t PIN_PA15;
#define PA15 ((PinId_t*) &PIN_PA15)
#endif // GPIOA

#ifdef GPIOB
extern const PinId_t PIN_PB0;
#define PB0 ((PinId_t*) &PIN_PB0)
extern const PinId_t PIN_PB1;
#define PB1 ((PinId_t*) &PIN_PB1)
extern const PinId_t PIN_PB2;
#define PB2 ((PinId_t*) &PIN_PB2)
extern const PinId_t PIN_PB3;
#define PB3 ((PinId_t*) &PIN_PB3)
extern const PinId_t PIN_PB4;
#define PB4 ((PinId_t*) &PIN_PB4)
extern const PinId_t PIN_PB5;
#define PB5 ((PinId_t*) &PIN_PB5)
extern const PinId_t PIN_PB6;
#define PB6 ((PinId_t*) &PIN_PB6)
extern const PinId_t PIN_PB7;
#define PB7 ((PinId_t*) &PIN_PB7)
extern const PinId_t PIN_PB8;
#define PB8 ((PinId_t*) &PIN_PB8)
extern const PinId_t PIN_PB9;
#define PB9 ((PinId_t*) &PIN_PB9)
extern const PinId_t PIN_PB10;
#define PB10 ((PinId_t*) &PIN_PB10)
extern const PinId_t PIN_PB11;
#define PB11 ((PinId_t*) &PIN_PB11)
extern const PinId_t PIN_PB12;
#define PB12 ((PinId_t*) &PIN_PB12)
extern const PinId_t PIN_PB13;
#define PB13 ((PinId_t*) &PIN_PB13)
extern const PinId_t PIN_PB14;
#define PB14 ((PinId_t*) &PIN_PB14)
extern const PinId_t PIN_PB15;
#define PB15 ((PinId_t*) &PIN_PB15)
#endif // GPIOB

#ifdef GPIOC
extern const PinId_t PIN_PC0;
#define PC0 ((PinId_t*) &PIN_PC0)
extern const PinId_t PIN_PC1;
#define PC1 ((PinId_t*) &PIN_PC1)
extern const PinId_t PIN_PC2;
#define PC2 ((PinId_t*) &PIN_PC2)
extern const PinId_t PIN_PC3;
#define PC3 ((PinId_t*) &PIN_PC3)
extern const PinId_t PIN_PC4;
#define PC4 ((PinId_t*) &PIN_PC4)
extern const PinId_t PIN_PC5;
#define PC5 ((PinId_t*) &PIN_PC5)
extern const PinId_t PIN_PC6;
#define PC6 ((PinId_t*) &PIN_PC6)
extern const PinId_t PIN_PC7;
#define PC7 ((PinId_t*) &PIN_PC7)
extern const PinId_t PIN_PC8;
#define PC8 ((PinId_t*) &PIN_PC8)
extern const PinId_t PIN_PC9;
#define PC9 ((PinId_t*) &PIN_PC9)
extern const PinId_t PIN_PC10;
#define PC10 ((PinId_t*) &PIN_PC10)
extern const PinId_t PIN_PC11;
#define PC11 ((PinId_t*) &PIN_PC11)
extern const PinId_t PIN_PC12;
#define PC12 ((PinId_t*) &PIN_PC12)
extern const PinId_t PIN_PC13;
#define PC13 ((PinId_t*) &PIN_PC13)
extern const PinId_t PIN_PC14;
#define PC14 ((PinId_t*) &PIN_PC14)
extern const PinId_t PIN_PC15;
#define PC15 ((PinId_t*) &PIN_PC15)
#endif // GPIOC

#ifdef GPIOD
extern const PinId_t PIN_PD0;
#define PD0 ((PinId_t*) &PIN_PD0)
extern const PinId_t PIN_PD1;
#define PD1 ((PinId_t*) &PIN_PD1)
extern const PinId_t PIN_PD2;
#define PD2 ((PinId_t*) &PIN_PD2)
extern const PinId_t PIN_PD3;
#define PD3 ((PinId_t*) &PIN_PD3)
extern const PinId_t PIN_PD4;
#define PD4 ((PinId_t*) &PIN_PD4)
extern const PinId_t PIN_PD5;
#define PD5 ((PinId_t*) &PIN_PD5)
extern const PinId_t PIN_PD6;
#define PD6 ((PinId_t*) &PIN_PD6)
extern const PinId_t PIN_PD7;
#define PD7 ((PinId_t*) &PIN_PD7)
extern const PinId_t PIN_PD8;
#define PD8 ((PinId_t*) &PIN_PD8)
extern const PinId_t PIN_PD9;
#define PD9 ((PinId_t*) &PIN_PD9)
extern const PinId_t PIN_PD10;
#define PD10 ((PinId_t*) &PIN_PD10)
extern const PinId_t PIN_PD11;
#define PD11 ((PinId_t*) &PIN_PD11)
extern const PinId_t PIN_PD12;
#define PD12 ((PinId_t*) &PIN_PD12)
extern const PinId_t PIN_PD13;
#define PD13 ((PinId_t*) &PIN_PD13)
extern const PinId_t PIN_PD14;
#define PD14 ((PinId_t*) &PIN_PD14)
extern const PinId_t PIN_PD15;
#define PD15 ((PinId_t*) &PIN_PD15)
#endif // GPIOD

#ifdef GPIOE
extern const PinId_t PIN_PE0;
#define PE0 ((PinId_t*) &PIN_PE0)
extern const PinId_t PIN_PE1;
#define PE1 ((PinId_t*) &PIN_PE1)
extern const PinId_t PIN_PE2;
#define PE2 ((PinId_t*) &PIN_PE2)
extern const PinId_t PIN_PE3;
#define PE3 ((PinId_t*) &PIN_PE3)
extern const PinId_t PIN_PE4;
#define PE4 ((PinId_t*) &PIN_PE4)
extern const PinId_t PIN_PE5;
#define PE5 ((PinId_t*) &PIN_PE5)
extern const PinId_t PIN_PE6;
#define PE6 ((PinId_t*) &PIN_PE6)
extern const PinId_t PIN_PE7;
#define PE7 ((PinId_t*) &PIN_PE7)
extern const PinId_t PIN_PE8;
#define PE8 ((PinId_t*) &PIN_PE8)
extern const PinId_t PIN_PE9;
#define PE9 ((PinId_t*) &PIN_PE9)
extern const PinId_t PIN_PE10;
#define PE10 ((PinId_t*) &PIN_PE10)
extern const PinId_t PIN_PE11;
#define PE11 ((PinId_t*) &PIN_PE11)
extern const PinId_t PIN_PE12;
#define PE12 ((PinId_t*) &PIN_PE12)
extern const PinId_t PIN_PE13;
#define PE13 ((PinId_t*) &PIN_PE13)
extern const PinId_t PIN_PE14;
#define PE14 ((PinId_t*) &PIN_PE14)
extern const PinId_t PIN_PE15;
#define PE15 ((PinId_t*) &PIN_PE15)
#endif // GPIOE

#ifdef GPIOF
extern const PinId_t PIN_PF0;
#define PF0 ((PinId_t*) &PIN_PF0)
extern const PinId_t PIN_PF1;
#define PF1 ((PinId_t*) &PIN_PF1)
extern const PinId_t PIN_PF2;
#define PF2 ((PinId_t*) &PIN_PF2)
extern const PinId_t PIN_PF3;
#define PF3 ((PinId_t*) &PIN_PF3)
extern const PinId_t PIN_PF4;
#define PF4 ((PinId_t*) &PIN_PF4)
extern const PinId_t PIN_PF5;
#define PF5 ((PinId_t*) &PIN_PF5)
extern const PinId_t PIN_PF6;
#define PF6 ((PinId_t*) &PIN_PF6)
extern const PinId_t PIN_PF7;
#define PF7 ((PinId_t*) &PIN_PF7)
extern const PinId_t PIN_PF8;
#define PF8 ((PinId_t*) &PIN_PF8)
extern const PinId_t PIN_PF9;
#define PF9 ((PinId_t*) &PIN_PF9)
extern const PinId_t PIN_PF10;
#define PF10 ((PinId_t*) &PIN_PF10)
extern const PinId_t PIN_PF11;
#define PF11 ((PinId_t*) &PIN_PF11)
extern const PinId_t PIN_PF12;
#define PF12 ((PinId_t*) &PIN_PF12)
extern const PinId_t PIN_PF13;
#define PF13 ((PinId_t*) &PIN_PF13)
extern const PinId_t PIN_PF14;
#define PF14 ((PinId_t*) &PIN_PF14)
extern const PinId_t PIN_PF15;
#define PF15 ((PinId_t*) &PIN_PF15)
#endif // GPIOF

#ifdef GPIOG
extern const PinId_t PIN_PG0;
#define PG0 ((PinId_t*) &PIN_PG0)
extern const PinId_t PIN_PG1;
#define PG1 ((PinId_t*) &PIN_PG1)
extern const PinId_t PIN_PG2;
#define PG2 ((PinId_t*) &PIN_PG2)
extern const PinId_t PIN_PG3;
#define PG3 ((PinId_t*) &PIN_PG3)
extern const PinId_t PIN_PG4;
#define PG4 ((PinId_t*) &PIN_PG4)
extern const PinId_t PIN_PG5;
#define PG5 ((PinId_t*) &PIN_PG5)
extern const PinId_t PIN_PG6;
#define PG6 ((PinId_t*) &PIN_PG6)
extern const PinId_t PIN_PG7;
#define PG7 ((PinId_t*) &PIN_PG7)
extern const PinId_t PIN_PG8;
#define PG8 ((PinId_t*) &PIN_PG8)
extern const PinId_t PIN_PG9;
#define PG9 ((PinId_t*) &PIN_PG9)
extern const PinId_t PIN_PG10;
#define PG10 ((PinId_t*) &PIN_PG10)
extern const PinId_t PIN_PG11;
#define PG11 ((PinId_t*) &PIN_PG11)
extern const PinId_t PIN_PG12;
#define PG12 ((PinId_t*) &PIN_PG12)
extern const PinId_t PIN_PG13;
#define PG13 ((PinId_t*) &PIN_PG13)
extern const PinId_t PIN_PG14;
#define PG14 ((PinId_t*) &PIN_PG14)
extern const PinId_t PIN_PG15;
#define PG15 ((PinId_t*) &PIN_PG15)
#endif // GPIOG

#ifdef GPIOH
extern const PinId_t PIN_PH0;
#define PH0 ((PinId_t*) &PIN_PH0)
extern const PinId_t PIN_PH1;
#define PH1 ((PinId_t*) &PIN_PH1)
extern const PinId_t PIN_PH2;
#define PH2 ((PinId_t*) &PIN_PH2)
extern const PinId_t PIN_PH3;
#define PH3 ((PinId_t*) &PIN_PH3)
extern const PinId_t PIN_PH4;
#define PH4 ((PinId_t*) &PIN_PH4)
extern const PinId_t PIN_PH5;
#define PH5 ((PinId_t*) &PIN_PH5)
extern const PinId_t PIN_PH6;
#define PH6 ((PinId_t*) &PIN_PH6)
extern const PinId_t PIN_PH7;
#define PH7 ((PinId_t*) &PIN_PH7)
extern const PinId_t PIN_PH8;
#define PH8 ((PinId_t*) &PIN_PH8)
extern const PinId_t PIN_PH9;
#define PH9 ((PinId_t*) &PIN_PH9)
extern const PinId_t PIN_PH10;
#define PH10 ((PinId_t*) &PIN_PH10)
extern const PinId_t PIN_PH11;
#define PH11 ((PinId_t*) &PIN_PH11)
extern const PinId_t PIN_PH12;
#define PH12 ((PinId_t*) &PIN_PH12)
extern const PinId_t PIN_PH13;
#define PH13 ((PinId_t*) &PIN_PH13)
extern const PinId_t PIN_PH14;
#define PH14 ((PinId_t*) &PIN_PH14)
extern const PinId_t PIN_PH15;
#define PH15 ((PinId_t*) &PIN_PH15)
#endif // GPIOH

#ifdef GPIOI
extern const PinId_t PIN_PI0;
#define PI0 ((PinId_t*) &PIN_PI0)
extern const PinId_t PIN_PI1;
#define PI1 ((PinId_t*) &PIN_PI1)
extern const PinId_t PIN_PI2;
#define PI2 ((PinId_t*) &PIN_PI2)
extern const PinId_t PIN_PI3;
#define PI3 ((PinId_t*) &PIN_PI3)
extern const PinId_t PIN_PI4;
#define PI4 ((PinId_t*) &PIN_PI4)
extern const PinId_t PIN_PI5;
#define PI5 ((PinId_t*) &PIN_PI5)
extern const PinId_t PIN_PI6;
#define PI6 ((PinId_t*) &PIN_PI6)
extern const PinId_t PIN_PI7;
#define PI7 ((PinId_t*) &PIN_PI7)
extern const PinId_t PIN_PI8;
#define PI8 ((PinId_t*) &PIN_PI8)
extern const PinId_t PIN_PI9;
#define PI9 ((PinId_t*) &PIN_PI9)
extern const PinId_t PIN_PI10;
#define PI10 ((PinId_t*) &PIN_PI10)
extern const PinId_t PIN_PI11;
#define PI11 ((PinId_t*) &PIN_PI11)
extern const PinId_t PIN_PI12;
#define PI12 ((PinId_t*) &PIN_PI12)
extern const PinId_t PIN_PI13;
#define PI13 ((PinId_t*) &PIN_PI13)
extern const PinId_t PIN_PI14;
#define PI14 ((PinId_t*) &PIN_PI14)
extern const PinId_t PIN_PI15;
#define PI15 ((PinId_t*) &PIN_PI15)
#endif // GPIOI

#ifdef GPIOJ
extern const PinId_t PIN_PJ0;
#define PJ0 ((PinId_t*) &PIN_PJ0)
extern const PinId_t PIN_PJ1;
#define PJ1 ((PinId_t*) &PIN_PJ1)
extern const PinId_t PIN_PJ2;
#define PJ2 ((PinId_t*) &PIN_PJ2)
extern const PinId_t PIN_PJ3;
#define PJ3 ((PinId_t*) &PIN_PJ3)
extern const PinId_t PIN_PJ4;
#define PJ4 ((PinId_t*) &PIN_PJ4)
extern const PinId_t PIN_PJ5;
#define PJ5 ((PinId_t*) &PIN_PJ5)
extern const PinId_t PIN_PJ6;
#define PJ6 ((PinId_t*) &PIN_PJ6)
extern const PinId_t PIN_PJ7;
#define PJ7 ((PinId_t*) &PIN_PJ7)
extern const PinId_t PIN_PJ8;
#define PJ8 ((PinId_t*) &PIN_PJ8)
extern const PinId_t PIN_PJ9;
#define PJ9 ((PinId_t*) &PIN_PJ9)
extern const PinId_t PIN_PJ10;
#define PJ10 ((PinId_t*) &PIN_PJ10)
extern const PinId_t PIN_PJ11;
#define PJ11 ((PinId_t*) &PIN_PJ11)
extern const PinId_t PIN_PJ12;
#define PJ12 ((PinId_t*) &PIN_PJ12)
extern const PinId_t PIN_PJ13;
#define PJ13 ((PinId_t*) &PIN_PJ13)
extern const PinId_t PIN_PJ14;
#define PJ14 ((PinId_t*) &PIN_PJ14)
extern const PinId_t PIN_PJ15;
#define PJ15 ((PinId_t*) &PIN_PJ15)
#endif // GPIOJ

#ifdef GPIOK
extern const PinId_t PIN_PK0;
#define PK0 ((PinId_t*) &PIN_PK0)
extern const PinId_t PIN_PK1;
#define PK1 ((PinId_t*) &PIN_PK1)
extern const PinId_t PIN_PK2;
#define PK2 ((PinId_t*) &PIN_PK2)
extern const PinId_t PIN_PK3;
#define PK3 ((PinId_t*) &PIN_PK3)
extern const PinId_t PIN_PK4;
#define PK4 ((PinId_t*) &PIN_PK4)
extern const PinId_t PIN_PK5;
#define PK5 ((PinId_t*) &PIN_PK5)
extern const PinId_t PIN_PK6;
#define PK6 ((PinId_t*) &PIN_PK6)
extern const PinId_t PIN_PK7;
#define PK7 ((PinId_t*) &PIN_PK7)
extern const PinId_t PIN_PK8;
#define PK8 ((PinId_t*) &PIN_PK8)
extern const PinId_t PIN_PK9;
#define PK9 ((PinId_t*) &PIN_PK9)
extern const PinId_t PIN_PK10;
#define PK10 ((PinId_t*) &PIN_PK10)
extern const PinId_t PIN_PK11;
#define PK11 ((PinId_t*) &PIN_PK11)
extern const PinId_t PIN_PK12;
#define PK12 ((PinId_t*) &PIN_PK12)
extern const PinId_t PIN_PK13;
#define PK13 ((PinId_t*) &PIN_PK13)
extern const PinId_t PIN_PK14;
#define PK14 ((PinId_t*) &PIN_PK14)
extern const PinId_t PIN_PK15;
#define PK15 ((PinId_t*) &PIN_PK15)
#endif // GPIOK

/*!
 * @brief		set pin mode with PinId
 * @param		WhichPin		pinId
 * @param		state	High / Low
 */
__STATIC_FORCEINLINE void PinId_Write(const PinId_t* WhichPin, uint32_t state)
{
    ((uint16_t*)&WhichPin->GPIOx->BSRR)[!state] = WhichPin->pinmask;
}

/*!
 * @brief		set pin mode with PinId
 * @param		WhichPin		pinId
 * @return		state	High / Low
 */
__STATIC_FORCEINLINE uint_fast32_t PinId_Read(const PinId_t* WhichPin)
{
    return ((WhichPin->GPIOx->IDR & WhichPin->pinmask) > 0);
}

/*!
 * @brief		set pin mode with PinId
 * @param		WhichPin		pinId
 * @return		state	High / Low
 */
__STATIC_FORCEINLINE void PinId_Toggle(const PinId_t* WhichPin)
{
    WhichPin->GPIOx->ODR ^= WhichPin->pinmask;
}

#endif // GPIO_CONFIG_H
