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
#include "text.h"
#include "GPIO_Config.h"
#include "keyboard_map.h"
#include "string.h"
// #include "keyboard_map.h"
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

#define TIMEOUT_MS 20

extern USBD_HandleTypeDef hUsbDeviceFS;

volatile HID_StateTypeDef USBD_Keyboard_State()
{
    return ((volatile USBD_HID_HandleTypeDef*)hUsbDeviceFS.pClassData)->state;
}

PinId_t* colPins[15] = {
    PA0, PA1, PA2, PA3, PA4,
    PA5, PA6, PA7, PB0, PB9,
    PB8, PB15, PB14, PB5, PB4};

PinId_t* rowPins[5] = {
    PA8,
    PA9,
    PA10,
    PA15,
    PB3,
};

KeyboardHID_t myHID = {1};
MediaHID_t myMedia = {2};
uint16_t Pressed[75] = {0};
uint16_t TimeOut[75] = {0};

void keyboardService()
{
    static int update = 0;
    static int alternate = 0;
    static int shit = 0;
    static int clean = 0;
    static uint8_t shitActivate = 0;
    static int textPos = 0;
    for(int i = 0; i < 5; i++)
    {
        PinId_Write(rowPins[i], 0);
        volatile uint32_t j = 0;
        for(; j < 10; j++)
            ;
        for(j = 0; j < 15; j++)
        {
            uint32_t pos = i * 15 + j;
            if(!PinId_Read(colPins[j]))
            {
                if(pos == 70) 
                {
                    alternate = 1; continue;
                }
                if(j == 14)
                {
                    shitActivate |= (1U << i);
                    if((shitActivate == 0x1f) && (alternate == 1))
                    {
                        if(shit == 0U) shit = 2U;
                        else if(shit == 3U) shit = 1U;
                    }
                }
                
                uint16_t key = keys[pos];
                if(alternate && keys_alternate[pos] != 0)
                {
                    key = keys_alternate[pos];
                }
                if(Pressed[pos] == 0 && TimeOut[pos] == 0)
                {
                    if(USBD_Keyboard_press(&myHID, &myMedia, key) == key)
                    {
                        update |= ((key & 0xff00) == 0x8000)? 8U : 4U;
                        Pressed[pos] = key;
                        update |= 1U;
                    }
                }
            }
            else
            {
                if(pos == 70) 
                {
                    alternate = 0; continue;
                }
                
                if(j == 14)
                {
                    shitActivate &= ~(1U << i);
                    if(shitActivate == 0)
                    {
                        int prevShit = shit;
                        if(shit == 2U) shit = 3U;
                        else if(shit == 1U) shit = 0U;
                        if(prevShit != shit)
                            {clean = 1; textPos = 0;}
                    }
                }

                TimeOut[pos] = TimeOut[pos] > 0? (TimeOut[pos] - 1) : 0;
                if(Pressed[pos] != 0)
                {
                    if(USBD_Keyboard_release(&myHID, &myMedia, Pressed[pos]) == Pressed[pos])
                    {
                        update |= ((Pressed[pos] & 0xff00) == 0x8000)? 8U : 4U;
                        Pressed[pos] = 0;
                        update |= 2U;
                        TimeOut[pos] = TIMEOUT_MS;
                    }
                }
            }
        }
        PinId_Write(rowPins[i], 1);
    }
    
    if(update & 3U)
    {
        if(clean)
        {
            uint8_t tmp[9] = {1, 0, 0, 0, 0, 0, 0, 0, 0};
            USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t*)tmp, 9);
            while(((volatile USBD_HID_HandleTypeDef*)hUsbDeviceFS.pClassData)->state != HID_IDLE)
                    ;
            uint8_t tmp1[3] = {2, 0, 0};
            USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t*)tmp1, 3);
            while(((volatile USBD_HID_HandleTypeDef*)hUsbDeviceFS.pClassData)->state != HID_IDLE)
                    ;
            clean = 0;
        }
        if(((update & 1U) == 1U) && shit == 3)
        {
            KeyboardHID_t shitHID = {1, 0, 0, {0, 0, 0, 0, 0, 0}};
            MediaHID_t shitMedia = {2, {0, 0}};
            USBD_Keyboard_press(&shitHID, &shitMedia, txt[textPos]);
            textPos = (textPos + 1) % size_txt; 
            USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t*)&shitHID, sizeof(shitHID));
            while(((volatile USBD_HID_HandleTypeDef*)hUsbDeviceFS.pClassData)->state != HID_IDLE)
                    ;
            USBD_Keyboard_releaseAll(&shitHID, &shitMedia);
            USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t*)&shitHID, sizeof(shitHID));
            while(((volatile USBD_HID_HandleTypeDef*)hUsbDeviceFS.pClassData)->state != HID_IDLE)
                    ;
        }
        else if (shit == 0)
        {
            if(update & 8U)
            {
                myMedia.ID = 2;
                if(myMedia.KEYCODE[0] == 0xe9)
                    GPIOC->ODR ^= (1U << 13U);
                USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t*)&myMedia, sizeof(myMedia));
                while(((volatile USBD_HID_HandleTypeDef*)hUsbDeviceFS.pClassData)->state != HID_IDLE)
                        ;
            }
            if(update & 4U)
            {
                myHID.ID = 1;
                USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t*)&myHID, sizeof(myHID));
                while(((volatile USBD_HID_HandleTypeDef*)hUsbDeviceFS.pClassData)->state != HID_IDLE)
                        ;
            }
        }
        update = 0;
    }
}

void __attribute__((optimize("-O0"))) HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim) 
{
    // if(htim == &htim3)
    // NVIC_DisableIRQ(TIM3_IRQn);
    // keyboardService();
    // NVIC_EnableIRQ(TIM3_IRQn);
}


/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int __attribute__((optimize("-O0"))) main(void)
{
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
    MX_USB_DEVICE_Init();
    /* USER CODE BEGIN 2 */
    TIM3->PSC = (84000000 / 1000000) - 1;
    TIM3->ARR = (1000000 / 1000) - 1;
    NVIC_SetPriority(OTG_FS_IRQn, 6);
    NVIC_SetPriority(TIM3_IRQn, 67);
    HAL_TIM_Base_Start_IT(&htim3);

    /* USER CODE END 2 */

    /* Infinite loop */
    /* USER CODE BEGIN WHILE */
    while (1)
    {
        /* USER CODE END WHILE */

        /* USER CODE BEGIN 3 */
        keyboardService();
        HAL_Delay(0);
    }
    /* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void)
{
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
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        Error_Handler();
    }
    /** Initializes the CPU, AHB and APB buses clocks
     */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
    {
        Error_Handler();
    }
}

/**
 * @brief TIM3 Initialization Function
 * @param None
 * @retval None
 */
static void MX_TIM3_Init(void)
{

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
    if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
    {
        Error_Handler();
    }
    sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
    if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
    {
        Error_Handler();
    }
    sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
    sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
    if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
    {
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
static void MX_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOH_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_15, GPIO_PIN_SET);

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);

    /*Configure GPIO pins : PA0 PA1 PA2 PA3
                             PA4 PA5 PA6 PA7 */
    GPIO_InitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /*Configure GPIO pins : PB0 PB4 PB5 PB6
                             PB7 PB8 PB9 */
    GPIO_InitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_14 | GPIO_PIN_15 | GPIO_PIN_8 | GPIO_PIN_9;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /*Configure GPIO pins : PA8 PA9 PA10 PA15 */
    GPIO_InitStruct.Pin = GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_15;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /*Configure GPIO pin : PB3 */
    GPIO_InitStruct.Pin = GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /*Configure GPIO pin : PC13 */
    GPIO_InitStruct.Pin = GPIO_PIN_13;
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
void Error_Handler(void)
{
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */
    __disable_irq();
    while (1)
    {
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
void assert_failed(uint8_t* file, uint32_t line)
{
    /* USER CODE BEGIN 6 */
    /* User can add his own implementation to report the file name and line number,
       ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
    /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
