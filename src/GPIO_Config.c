/*!
 * @file GPIO_Config.c
 * @author Demitrias Wilbert
 * @brief definition of each pin configuration structure type (PinId_t)
 * @version 0.1
 * @date 2021-07-08
 * 
 * 
*/

#include "GPIO_Config.h"

#ifdef GPIOA
const PinId_t PIN_PA0 = {GPIOA, (1 << 0), 0};
const PinId_t PIN_PA1 = {GPIOA, (1 << 1), 1};
const PinId_t PIN_PA2 = {GPIOA, (1 << 2), 2};
const PinId_t PIN_PA3 = {GPIOA, (1 << 3), 3};
const PinId_t PIN_PA4 = {GPIOA, (1 << 4), 4};
const PinId_t PIN_PA5 = {GPIOA, (1 << 5), 5};
const PinId_t PIN_PA6 = {GPIOA, (1 << 6), 6};
const PinId_t PIN_PA7 = {GPIOA, (1 << 7), 7};
const PinId_t PIN_PA8 = {GPIOA, (1 << 8), 8};
const PinId_t PIN_PA9 = {GPIOA, (1 << 9), 9};
const PinId_t PIN_PA10 = {GPIOA, (1 << 10), 10};
const PinId_t PIN_PA11 = {GPIOA, (1 << 11), 11};
const PinId_t PIN_PA12 = {GPIOA, (1 << 12), 12};
const PinId_t PIN_PA13 = {GPIOA, (1 << 13), 13};
const PinId_t PIN_PA14 = {GPIOA, (1 << 14), 14};
const PinId_t PIN_PA15 = {GPIOA, (1 << 15), 15};
#endif // GPIOA

#ifdef GPIOB
const PinId_t PIN_PB0 = {GPIOB, (1 << 0), 0};
const PinId_t PIN_PB1 = {GPIOB, (1 << 1), 1};
const PinId_t PIN_PB2 = {GPIOB, (1 << 2), 2};
const PinId_t PIN_PB3 = {GPIOB, (1 << 3), 3};
const PinId_t PIN_PB4 = {GPIOB, (1 << 4), 4};
const PinId_t PIN_PB5 = {GPIOB, (1 << 5), 5};
const PinId_t PIN_PB6 = {GPIOB, (1 << 6), 6};
const PinId_t PIN_PB7 = {GPIOB, (1 << 7), 7};
const PinId_t PIN_PB8 = {GPIOB, (1 << 8), 8};
const PinId_t PIN_PB9 = {GPIOB, (1 << 9), 9};
const PinId_t PIN_PB10 = {GPIOB, (1 << 10), 10};
const PinId_t PIN_PB11 = {GPIOB, (1 << 11), 11};
const PinId_t PIN_PB12 = {GPIOB, (1 << 12), 12};
const PinId_t PIN_PB13 = {GPIOB, (1 << 13), 13};
const PinId_t PIN_PB14 = {GPIOB, (1 << 14), 14};
const PinId_t PIN_PB15 = {GPIOB, (1 << 15), 15};
#endif // GPIOB

#ifdef GPIOC
const PinId_t PIN_PC0 = {GPIOC, (1 << 0), 0};
const PinId_t PIN_PC1 = {GPIOC, (1 << 1), 1};
const PinId_t PIN_PC2 = {GPIOC, (1 << 2), 2};
const PinId_t PIN_PC3 = {GPIOC, (1 << 3), 3};
const PinId_t PIN_PC4 = {GPIOC, (1 << 4), 4};
const PinId_t PIN_PC5 = {GPIOC, (1 << 5), 5};
const PinId_t PIN_PC6 = {GPIOC, (1 << 6), 6};
const PinId_t PIN_PC7 = {GPIOC, (1 << 7), 7};
const PinId_t PIN_PC8 = {GPIOC, (1 << 8), 8};
const PinId_t PIN_PC9 = {GPIOC, (1 << 9), 9};
const PinId_t PIN_PC10 = {GPIOC, (1 << 10), 10};
const PinId_t PIN_PC11 = {GPIOC, (1 << 11), 11};
const PinId_t PIN_PC12 = {GPIOC, (1 << 12), 12};
const PinId_t PIN_PC13 = {GPIOC, (1 << 13), 13};
const PinId_t PIN_PC14 = {GPIOC, (1 << 14), 14};
const PinId_t PIN_PC15 = {GPIOC, (1 << 15), 15};
#endif // GPIOC

#ifdef GPIOD
const PinId_t PIN_PD0 = {GPIOD, (1 << 0), 0};
const PinId_t PIN_PD1 = {GPIOD, (1 << 1), 1};
const PinId_t PIN_PD2 = {GPIOD, (1 << 2), 2};
const PinId_t PIN_PD3 = {GPIOD, (1 << 3), 3};
const PinId_t PIN_PD4 = {GPIOD, (1 << 4), 4};
const PinId_t PIN_PD5 = {GPIOD, (1 << 5), 5};
const PinId_t PIN_PD6 = {GPIOD, (1 << 6), 6};
const PinId_t PIN_PD7 = {GPIOD, (1 << 7), 7};
const PinId_t PIN_PD8 = {GPIOD, (1 << 8), 8};
const PinId_t PIN_PD9 = {GPIOD, (1 << 9), 9};
const PinId_t PIN_PD10 = {GPIOD, (1 << 10), 10};
const PinId_t PIN_PD11 = {GPIOD, (1 << 11), 11};
const PinId_t PIN_PD12 = {GPIOD, (1 << 12), 12};
const PinId_t PIN_PD13 = {GPIOD, (1 << 13), 13};
const PinId_t PIN_PD14 = {GPIOD, (1 << 14), 14};
const PinId_t PIN_PD15 = {GPIOD, (1 << 15), 15};
#endif // GPIOD

#ifdef GPIOE
const PinId_t PIN_PE0 = {GPIOE, (1 << 0), 0};
const PinId_t PIN_PE1 = {GPIOE, (1 << 1), 1};
const PinId_t PIN_PE2 = {GPIOE, (1 << 2), 2};
const PinId_t PIN_PE3 = {GPIOE, (1 << 3), 3};
const PinId_t PIN_PE4 = {GPIOE, (1 << 4), 4};
const PinId_t PIN_PE5 = {GPIOE, (1 << 5), 5};
const PinId_t PIN_PE6 = {GPIOE, (1 << 6), 6};
const PinId_t PIN_PE7 = {GPIOE, (1 << 7), 7};
const PinId_t PIN_PE8 = {GPIOE, (1 << 8), 8};
const PinId_t PIN_PE9 = {GPIOE, (1 << 9), 9};
const PinId_t PIN_PE10 = {GPIOE, (1 << 10), 10};
const PinId_t PIN_PE11 = {GPIOE, (1 << 11), 11};
const PinId_t PIN_PE12 = {GPIOE, (1 << 12), 12};
const PinId_t PIN_PE13 = {GPIOE, (1 << 13), 13};
const PinId_t PIN_PE14 = {GPIOE, (1 << 14), 14};
const PinId_t PIN_PE15 = {GPIOE, (1 << 15), 15};
#endif // GPIOE

#ifdef GPIOF
const PinId_t PIN_PF0 = {GPIOF, (1 << 0), 0};
const PinId_t PIN_PF1 = {GPIOF, (1 << 1), 1};
const PinId_t PIN_PF2 = {GPIOF, (1 << 2), 2};
const PinId_t PIN_PF3 = {GPIOF, (1 << 3), 3};
const PinId_t PIN_PF4 = {GPIOF, (1 << 4), 4};
const PinId_t PIN_PF5 = {GPIOF, (1 << 5), 5};
const PinId_t PIN_PF6 = {GPIOF, (1 << 6), 6};
const PinId_t PIN_PF7 = {GPIOF, (1 << 7), 7};
const PinId_t PIN_PF8 = {GPIOF, (1 << 8), 8};
const PinId_t PIN_PF9 = {GPIOF, (1 << 9), 9};
const PinId_t PIN_PF10 = {GPIOF, (1 << 10), 10};
const PinId_t PIN_PF11 = {GPIOF, (1 << 11), 11};
const PinId_t PIN_PF12 = {GPIOF, (1 << 12), 12};
const PinId_t PIN_PF13 = {GPIOF, (1 << 13), 13};
const PinId_t PIN_PF14 = {GPIOF, (1 << 14), 14};
const PinId_t PIN_PF15 = {GPIOF, (1 << 15), 15};
#endif // GPIOF

#ifdef GPIOG
const PinId_t PIN_PG0 = {GPIOG, (1 << 0), 0};
const PinId_t PIN_PG1 = {GPIOG, (1 << 1), 1};
const PinId_t PIN_PG2 = {GPIOG, (1 << 2), 2};
const PinId_t PIN_PG3 = {GPIOG, (1 << 3), 3};
const PinId_t PIN_PG4 = {GPIOG, (1 << 4), 4};
const PinId_t PIN_PG5 = {GPIOG, (1 << 5), 5};
const PinId_t PIN_PG6 = {GPIOG, (1 << 6), 6};
const PinId_t PIN_PG7 = {GPIOG, (1 << 7), 7};
const PinId_t PIN_PG8 = {GPIOG, (1 << 8), 8};
const PinId_t PIN_PG9 = {GPIOG, (1 << 9), 9};
const PinId_t PIN_PG10 = {GPIOG, (1 << 10), 10};
const PinId_t PIN_PG11 = {GPIOG, (1 << 11), 11};
const PinId_t PIN_PG12 = {GPIOG, (1 << 12), 12};
const PinId_t PIN_PG13 = {GPIOG, (1 << 13), 13};
const PinId_t PIN_PG14 = {GPIOG, (1 << 14), 14};
const PinId_t PIN_PG15 = {GPIOG, (1 << 15), 15};
#endif // GPIOG

#ifdef GPIOH
const PinId_t PIN_PH0 = {GPIOH, (1 << 0), 0};
const PinId_t PIN_PH1 = {GPIOH, (1 << 1), 1};
const PinId_t PIN_PH2 = {GPIOH, (1 << 2), 2};
const PinId_t PIN_PH3 = {GPIOH, (1 << 3), 3};
const PinId_t PIN_PH4 = {GPIOH, (1 << 4), 4};
const PinId_t PIN_PH5 = {GPIOH, (1 << 5), 5};
const PinId_t PIN_PH6 = {GPIOH, (1 << 6), 6};
const PinId_t PIN_PH7 = {GPIOH, (1 << 7), 7};
const PinId_t PIN_PH8 = {GPIOH, (1 << 8), 8};
const PinId_t PIN_PH9 = {GPIOH, (1 << 9), 9};
const PinId_t PIN_PH10 = {GPIOH, (1 << 10), 10};
const PinId_t PIN_PH11 = {GPIOH, (1 << 11), 11};
const PinId_t PIN_PH12 = {GPIOH, (1 << 12), 12};
const PinId_t PIN_PH13 = {GPIOH, (1 << 13), 13};
const PinId_t PIN_PH14 = {GPIOH, (1 << 14), 14};
const PinId_t PIN_PH15 = {GPIOH, (1 << 15), 15};
#endif // GPIOH

#ifdef GPIOI
const PinId_t PIN_PI0 = {GPIOI, (1 << 0), 0};
const PinId_t PIN_PI1 = {GPIOI, (1 << 1), 1};
const PinId_t PIN_PI2 = {GPIOI, (1 << 2), 2};
const PinId_t PIN_PI3 = {GPIOI, (1 << 3), 3};
const PinId_t PIN_PI4 = {GPIOI, (1 << 4), 4};
const PinId_t PIN_PI5 = {GPIOI, (1 << 5), 5};
const PinId_t PIN_PI6 = {GPIOI, (1 << 6), 6};
const PinId_t PIN_PI7 = {GPIOI, (1 << 7), 7};
const PinId_t PIN_PI8 = {GPIOI, (1 << 8), 8};
const PinId_t PIN_PI9 = {GPIOI, (1 << 9), 9};
const PinId_t PIN_PI10 = {GPIOI, (1 << 10), 10};
const PinId_t PIN_PI11 = {GPIOI, (1 << 11), 11};
const PinId_t PIN_PI12 = {GPIOI, (1 << 12), 12};
const PinId_t PIN_PI13 = {GPIOI, (1 << 13), 13};
const PinId_t PIN_PI14 = {GPIOI, (1 << 14), 14};
const PinId_t PIN_PI15 = {GPIOI, (1 << 15), 15};
#endif // GPIOI

#ifdef GPIOJ
const PinId_t PIN_PJ0 = {GPIOJ, (1 << 0), 0};
const PinId_t PIN_PJ1 = {GPIOJ, (1 << 1), 1};
const PinId_t PIN_PJ2 = {GPIOJ, (1 << 2), 2};
const PinId_t PIN_PJ3 = {GPIOJ, (1 << 3), 3};
const PinId_t PIN_PJ4 = {GPIOJ, (1 << 4), 4};
const PinId_t PIN_PJ5 = {GPIOJ, (1 << 5), 5};
const PinId_t PIN_PJ6 = {GPIOJ, (1 << 6), 6};
const PinId_t PIN_PJ7 = {GPIOJ, (1 << 7), 7};
const PinId_t PIN_PJ8 = {GPIOJ, (1 << 8), 8};
const PinId_t PIN_PJ9 = {GPIOJ, (1 << 9), 9};
const PinId_t PIN_PJ10 = {GPIOJ, (1 << 10), 10};
const PinId_t PIN_PJ11 = {GPIOJ, (1 << 11), 11};
const PinId_t PIN_PJ12 = {GPIOJ, (1 << 12), 12};
const PinId_t PIN_PJ13 = {GPIOJ, (1 << 13), 13};
const PinId_t PIN_PJ14 = {GPIOJ, (1 << 14), 14};
const PinId_t PIN_PJ15 = {GPIOJ, (1 << 15), 15};
#endif // GPIOJ

#ifdef GPIOK
const PinId_t PIN_PK0 = {GPIOK, (1 << 0), 0};
const PinId_t PIN_PK1 = {GPIOK, (1 << 1), 1};
const PinId_t PIN_PK2 = {GPIOK, (1 << 2), 2};
const PinId_t PIN_PK3 = {GPIOK, (1 << 3), 3};
const PinId_t PIN_PK4 = {GPIOK, (1 << 4), 4};
const PinId_t PIN_PK5 = {GPIOK, (1 << 5), 5};
const PinId_t PIN_PK6 = {GPIOK, (1 << 6), 6};
const PinId_t PIN_PK7 = {GPIOK, (1 << 7), 7};
const PinId_t PIN_PK8 = {GPIOK, (1 << 8), 8};
const PinId_t PIN_PK9 = {GPIOK, (1 << 9), 9};
const PinId_t PIN_PK10 = {GPIOK, (1 << 10), 10};
const PinId_t PIN_PK11 = {GPIOK, (1 << 11), 11};
const PinId_t PIN_PK12 = {GPIOK, (1 << 12), 12};
const PinId_t PIN_PK13 = {GPIOK, (1 << 13), 13};
const PinId_t PIN_PK14 = {GPIOK, (1 << 14), 14};
const PinId_t PIN_PK15 = {GPIOK, (1 << 15), 15};
#endif // GPIOK

