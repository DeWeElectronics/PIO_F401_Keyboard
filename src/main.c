/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under Ultimate Liberty license
 * SLA0044, the "License"; You may not use this file except in compliance with
 * the License. You may obtain a copy of the License at:
 *                             www.st.com/SLA0044
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usb_device.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "GPIO_Config.h"
#include "keyboard_usb.h"
#include "keymap.h"
#include "stdlib.h"
#include "string.h"
#include "text.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim3;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM3_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

#define TIMEOUT_MS 100
#define TIMEOUT_MAX 500

extern USBD_HandleTypeDef hUsbDeviceFS;

// #define ENABLE_AUTOTYPER

#define USBD_Keyboard_State() (((volatile USBD_HID_HandleTypeDef*)hUsbDeviceFS.pClassData)->state)

#define COLS 15U
#define ROWS 5U

PinId_t* colPins[COLS] = {
    PA0, PA1, PA2, PA3, PA4,
    PA5, PA6, PA7, PB0, PB9,
    PB8, PB15, PB14, PB5, PB4};

PinId_t* rowPins[ROWS] = {
    PA8,
    PA9,
    PA10,
    PA15,
    PB3,
};

#define HID_NORMAL_ID 1U
#define HID_MEDIA_ID 2U
#define FN_KEY 70U

void keyboard_init(PinId_t** p_rows, PinId_t** p_cols, uint16_t n_rows, uint16_t n_cols) {
    
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();

    for (uint16_t i = 0; i < n_cols; i++) {
        GPIO_InitTypeDef tmp = {0};
        tmp.Pin = p_cols[i]->pinmask;
        tmp.Mode = GPIO_MODE_INPUT;
        tmp.Pull = GPIO_PULLUP;
        tmp.Alternate = 0U;
        HAL_GPIO_Init(p_cols[i]->GPIOx, &tmp);
    }

    for (uint16_t i = 0; i < n_rows; i++) {
        PinId_Write(p_rows[i], 1);
        GPIO_InitTypeDef tmp = {0};
        tmp.Pin = p_rows[i]->pinmask;
        tmp.Mode = GPIO_MODE_OUTPUT_PP;
        tmp.Pull = GPIO_NOPULL;
        tmp.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        tmp.Alternate = 0U;
        HAL_GPIO_Init(p_rows[i]->GPIOx, &tmp);
    }
}

void keyboard_transmit(uint8_t* data, size_t size) {
    while (USBD_Keyboard_State() != HID_IDLE)
        ;
    USBD_HID_SendReport(&hUsbDeviceFS, data, size);
}

KeyboardHID_t myHID = {HID_NORMAL_ID};
MediaHID_t myMedia = {HID_MEDIA_ID};
uint8_t Pressed[ROWS * COLS] = {0};
uint32_t keyTimer[ROWS * COLS] = {0};
#define ENABLE_AUTOTYPER
#ifdef ENABLE_AUTOTYPER
uint8_t autoPress[ROWS * COLS] = {0};
#endif //ENABLE_AUTOTYPER

void keyboardService() {
    static uint32_t update = 0;
    static uint32_t alternate = 0;
    static uint32_t autotype = 0;
    static uint32_t clean = 0;
    static uint8_t autotypeActivate = 0;
    static uint32_t textPos = 0;
    static uint32_t npressed = 0;

    // scan matrix
    for (uint32_t i = 0; i < ROWS; i++) {
        PinId_Write(rowPins[i], 0);
        volatile uint32_t j = 0;
        for (; j < 10; j++)
            ;
        for (j = 0; j < COLS; j++) {
            uint32_t pos = i * COLS + j;
            uint32_t col_pressed = !PinId_Read(colPins[j]);
            uint32_t thisTick = HAL_GetTick();

            // set/unset alternate mode
            if (pos == FN_KEY) {
                alternate = col_pressed;
                continue;
            }

            if (col_pressed) {
                // autotype mode toggle on press (press and release alt key and column 14 of each row simultaneously)
                if (j == 14) {
                    autotypeActivate |= (1U << i);
                    if ((autotypeActivate == 0x1f) && (alternate == 1)) {
                        if (autotype == 0U) autotype = 2U;
                        else if (autotype == 3U) autotype = 1U;
                    }
                }

                // if alternate mode is on and alternate key is defined
                uint8_t key = (alternate && keys_alternate[pos][0] != 0) ? 
                                (uint8_t)keys_alternate[pos][0] : (uint8_t)keys[pos][0];

#ifdef ENABLE_AUTOTYPER
                if(keys_alternate[pos][0] == 0 && alternate) {
                    switch(autoPress[pos]) {
                        case 0: autoPress[pos] = 2; break;
                        case 3: autoPress[pos] = 1; break;
                        default: break;
                    }
                }
#endif // ENABLE_AUTOTYPER

                // press key
                // if key of 'pos' is free and not in debounce timeout
                // if (Pressed[pos] == 0 && TimeOut[pos] == 0) {
                if (Pressed[pos] == 0 && (thisTick - keyTimer[pos] >= TIMEOUT_MS)) {
                    uint32_t keycode = 0UL;
                    if ((keycode = USBD_Keyboard_str_press(&myHID, &myMedia, key))) {
                        update |= ((keycode & KEY_TYPE_MASK) == KEY_TYPE_MEDIA) ? 8U : 4U; // update HID Type
                        update |= 1U;                                                  // update pressed flag
                        Pressed[pos] = key;                                            // assign key to pressed array
                        npressed++;
                    }
                }
#ifdef ENABLE_AUTOTYPER
                if ((autoPress[pos] == 3) && (Pressed[pos] != 0) && (thisTick - keyTimer[pos] >= TIMEOUT_MAX)) {
                    uint32_t keycode = 0UL;
                    if ((keycode = USBD_Keyboard_str_release(&myHID, &myMedia, Pressed[pos]))) {
                        // update HID Type
                        update |= ((keycode & KEY_TYPE_MASK) == KEY_TYPE_MEDIA) ? 8U : 4U;
                        update |= 2U;              // update release flag
                        Pressed[pos] = 0;          // unassign key from pressed array
                        // TimeOut[pos] = TIMEOUT_MS; // set debounce timeout
                        npressed--;
                    }
                    keyTimer[pos] = thisTick - TIMEOUT_MAX + 50;
                }
#endif // ENABLE_AUTOTYPER
            } 
            if(!col_pressed) {
                // autotype mode toggle on release (press and release alt key and column 14 of each row simultaneously)
                if (j == 14) {
                    autotypeActivate &= ~(1U << i);
                    if (autotypeActivate == 0) {
                        int prevautotype = autotype;
                        if (autotype == 2U) autotype = 3U;
                        else if (autotype == 1U) autotype = 0U;
                        if (prevautotype != autotype) 
                            { clean = 1; textPos = 0; }
                    }
                }

#ifdef ENABLE_AUTOTYPER
                switch(autoPress[pos]) {
                    case 2: autoPress[pos] = 3; break;
                    case 1: autoPress[pos] = 0; break;
                    default: break;
                }
#endif // ENABLE_AUTOTYPER
                
                // release key
                if (Pressed[pos] != 0) { // if key[pos] is pressed
                    uint32_t keycode = 0UL;
                    if ((keycode = USBD_Keyboard_str_release(&myHID, &myMedia, Pressed[pos]))) {
                        // update HID Type
                        update |= ((keycode & KEY_TYPE_MASK) == KEY_TYPE_MEDIA) ? 8U : 4U;
                        update |= 2U;              // update release flag
                        Pressed[pos] = 0;          // unassign key from pressed array
                        npressed--;
                    }
                    keyTimer[pos] = thisTick;
                }
                // keep the max difference of keyTimer and thisTick at TIMEOUT_MS (to avoid overflow)
                keyTimer[pos] = (thisTick - keyTimer[pos] > TIMEOUT_MS)? 
                                    (thisTick - TIMEOUT_MS) : keyTimer[pos];
            }
            keyTimer[pos] = (thisTick - keyTimer[pos] > TIMEOUT_MAX)? 
                                (thisTick - TIMEOUT_MAX) : keyTimer[pos];
        }
        PinId_Write(rowPins[i], 1);
    }

#ifdef ENABLE_AUTOTYPER
    if (autoPress[0] == 3)
        clean = 1;
#endif // ENABLE_AUTOTYPER
    
    static uint32_t autotypeTimer = 0;
    if (autotype == 3) {    // autotype long press
        if ((HAL_GetTick() - autotypeTimer >= 500) && npressed > 0) {
            update |= 1U;
            autotypeTimer = HAL_GetTick() - (500);
        } else if (npressed == 0) {
            autotypeTimer = HAL_GetTick();
            textPos %= size_txt;
        }
    }

    // send report
    if (update & 3U) {
        if (clean) { // clean output
#ifdef ENABLE_AUTOTYPER
            memset(autoPress, 0, sizeof(autoPress));
#endif // ENABLE_AUTOTYPER
            uint8_t tmp[9] = {HID_NORMAL_ID, 0, 0, 0, 0, 0, 0, 0, 0};
            uint8_t tmp1[3] = {HID_MEDIA_ID, 0, 0};
            keyboard_transmit((uint8_t*)tmp, 9);
            keyboard_transmit((uint8_t*)tmp1, 3);
            clean = 0;
        }
        if (((update & 1U) == 1U) && autotype == 3) { // autotype mode
            // new HID instance
            KeyboardHID_t autotypeHID = {HID_NORMAL_ID, 0, 0, {0, 0, 0, 0, 0, 0}};
            MediaHID_t autotypeMedia = {HID_MEDIA_ID, {0, 0}};
            // press
            if (textPos < size_txt) {
                uint32_t type = USBD_Keyboard_str_press(&autotypeHID, &autotypeMedia, txt[textPos++]);
                type = (type & KEY_TYPE_MASK) == KEY_TYPE_MEDIA;
                if (type) {
                    keyboard_transmit((uint8_t*)&autotypeMedia, sizeof(autotypeMedia));
                    // release
                    USBD_Keyboard_releaseAll(&autotypeHID, &autotypeMedia);
                    keyboard_transmit((uint8_t*)&autotypeMedia, sizeof(autotypeMedia));
                } else {
                    keyboard_transmit((uint8_t*)&autotypeHID, sizeof(autotypeHID));
                    // release
                    USBD_Keyboard_releaseAll(&autotypeHID, &autotypeMedia);
                    keyboard_transmit((uint8_t*)&autotypeHID, sizeof(autotypeHID));
                }
            }
        } else if (autotype == 0) { // normal mode
            if (update & 8U) {
                myMedia.ID = HID_MEDIA_ID;
                keyboard_transmit((uint8_t*)&myMedia, sizeof(myMedia));
            }
            if (update & 4U) {
                myHID.ID = HID_NORMAL_ID;
                keyboard_transmit((uint8_t*)&myHID, sizeof(myHID));
            }
        }
        update = 0;
    }
}

volatile uint32_t LED_toggle = 0U;

void USBD_HID_GetReport(uint8_t* OutData, int len) {
    if (OutData[0] == 0x01) {
        PinId_Write(PC14, OutData[1] & 1U);
        PinId_Write(PC15, OutData[1] & 2U);
    }
}

void __attribute__((optimize("-O0"))) HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim) {

    if (htim == &htim3) {
        PinId_Write(PC13, !(!(USBD_Keyboard_State() == HID_IDLE) || PinId_Read(PC13)));
        // PinId_Write(PC13, !((USBD_Keyboard_State() == HID_IDLE) && PinId_Read(PC13)));
        // if (USBD_Keyboard_State() == HID_IDLE)
        //     PinId_Toggle(PC13);
    }
    // NVIC_DisableIRQ(TIM3_IRQn);
    // keyboardService();
    // NVIC_EnableIRQ(TIM3_IRQn);
}

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int __attribute__((optimize("-O0"))) main(void) {
    /* USER CODE BEGIN 1 */

    /* USER CODE END 1 */

    /* MCU Configuration--------------------------------------------------------*/

    /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
    HAL_Init();

    /* USER CODE BEGIN Init */

    /* USER CODE END Init */

    /* Configure the system clock */
    SystemClock_Config();

    /* USER CODE BEGIN SysInit */

    NVIC_SetPriority(OTG_FS_IRQn, 6);
    NVIC_SetPriority(TIM3_IRQn, 67);
    /* USER CODE END SysInit */

    /* Initialize all configured peripherals */
    MX_GPIO_Init();
    MX_TIM3_Init();
    HAL_Delay(50);
    MX_USB_DEVICE_Init();
    HAL_Delay(50);
    /* USER CODE BEGIN 2 */
    keyboard_init(rowPins, colPins, ROWS, COLS);
    TIM3->PSC = (84000000 / 10000) - 1;
    TIM3->ARR = (10000 / 1) - 1;
    // NVIC_SetPriority(OTG_FS_IRQn, 6);
    // NVIC_SetPriority(TIM3_IRQn, 67);
    HAL_TIM_Base_Start_IT(&htim3);

    while (USBD_Keyboard_State() != HID_IDLE)
        ;
    LED_toggle = 1U;

    /* USER CODE END 2 */

    /* Infinite loop */
    /* USER CODE BEGIN WHILE */
    while (1) {
        /* USER CODE END WHILE */

        /* USER CODE BEGIN 3 */
        static uint32_t lastScan = 0UL;
        if (lastScan != HAL_GetTick()) {
            lastScan = HAL_GetTick();
            keyboardService();
        }
    }
    /* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void) {
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    /** Configure the main internal regulator output voltage
     */
    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);
    /** Initializes the RCC Oscillators according to the specified parameters
     * in the RCC_OscInitTypeDef structure.
     */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLM = 25;
    RCC_OscInitStruct.PLL.PLLN = 336;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
    RCC_OscInitStruct.PLL.PLLQ = 7;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
        Error_Handler();
    }
    /** Initializes the CPU, AHB and APB buses clocks
     */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK) {
        Error_Handler();
    }
}

/**
 * @brief TIM3 Initialization Function
 * @param None
 * @retval None
 */
static void MX_TIM3_Init(void) {

    /* USER CODE BEGIN TIM3_Init 0 */

    /* USER CODE END TIM3_Init 0 */

    TIM_ClockConfigTypeDef sClockSourceConfig = {0};
    TIM_MasterConfigTypeDef sMasterConfig = {0};

    /* USER CODE BEGIN TIM3_Init 1 */

    /* USER CODE END TIM3_Init 1 */
    htim3.Instance = TIM3;
    htim3.Init.Prescaler = (84000000 / 1000000) - 1;
    htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim3.Init.Period = (1000000 / 1000) - 1;
    htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    if (HAL_TIM_Base_Init(&htim3) != HAL_OK) {
        Error_Handler();
    }
    sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
    if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK) {
        Error_Handler();
    }
    sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
    sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
    if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK) {
        Error_Handler();
    }
    /* USER CODE BEGIN TIM3_Init 2 */

    /* USER CODE END TIM3_Init 2 */
}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOH_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();

    /*Configure GPIO pin Output Level */
    // HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_15, GPIO_PIN_SET);

    /*Configure GPIO pin Output Level */
    // HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);

    /*Configure GPIO pins : PA0 PA1 PA2 PA3
                             PA4 PA5 PA6 PA7 */
    // GPIO_InitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7;
    // GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    // GPIO_InitStruct.Pull = GPIO_PULLUP;
    // HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /*Configure GPIO pins : PB0 PB4 PB5 PB6
                             PB7 PB8 PB9 */
    // GPIO_InitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9;
    // GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    // GPIO_InitStruct.Pull = GPIO_PULLUP;
    // HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /*Configure GPIO pins : PA8 PA9 PA10 PA15 */
    // GPIO_InitStruct.Pin = GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_15;
    // GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    // GPIO_InitStruct.Pull = GPIO_NOPULL;
    // GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    // HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /*Configure GPIO pin : PB3 */
    // GPIO_InitStruct.Pin = GPIO_PIN_3;
    // GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    // GPIO_InitStruct.Pull = GPIO_NOPULL;
    // GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    // HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /*Configure GPIO pin : PC13 */
    GPIO_InitStruct.Pin = GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void) {
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */
    __disable_irq();
    while (1) {
    }
    /* USER CODE END Error_Handler_Debug */
}

#ifdef USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t* file, uint32_t line) {
    /* USER CODE BEGIN 6 */
    /* User can add his own implementation to report the file name and line number,
       ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
    /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
