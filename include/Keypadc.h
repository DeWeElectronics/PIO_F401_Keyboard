/*!
 * @file Keypadc.h
 * @author Demitrias Wilbert 
 * @brief 4x4 keypad driver header
 * @version 0.1
 * @date 2021-07-08
 * 
*/

#define buffersize 16

#include "GPIO_Config.h"
#include <string.h>

/*!
 * @brief function that configures a pin to INPUT, PULLUP
 * @param PIN pointer to a PinId
 * @retval none
*/
__STATIC_FORCEINLINE void PIN_INPUT_PULLUP(PinId_t* PIN)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    memset(&GPIO_InitStruct, 0, sizeof(GPIO_InitTypeDef));
    GPIO_InitStruct.Pin = PIN->pinmask;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = 0U;
    HAL_GPIO_Init(PIN->GPIOx, &GPIO_InitStruct);
}

/*!
 * @brief function that configures a pin to OUTPUT, LOW
 * @param PIN pointer to a PinId
 * @retval none
*/
__STATIC_FORCEINLINE void PIN_OUTPUT_LOW(PinId_t* PIN)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    memset(&GPIO_InitStruct, 0, sizeof(GPIO_InitTypeDef));
    PinId_Write(PIN, 0U);
    GPIO_InitStruct.Pin = PIN->pinmask;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(PIN->GPIOx, &GPIO_InitStruct);
}

/*!
 * @brief function that reads the state of the pin
 * @retval 1 if HIGH, 0 if LOW
 * 
*/
#define PIN_READ(PIN) PinId_Read(PIN)

// buffer size
#define BUF_SIZE 16
/**
 * @brief Circular buffer for input 
 * 
 */
typedef struct
{
    volatile uint8_t buf[BUF_SIZE];
    volatile uint8_t BufHead;
    volatile uint8_t BufTail;
    volatile uint8_t BufWritten;
} CircBuf_t;


// clang-format off
/**
 * @brief continuous modes
 * 
 */
typedef enum
{
    CONTINUOUS_DISABLE = 0,         /** 
                                     * register only on the start of key press 
                                     * e.g : A ..............................
                                    **/
    CONTINUOUS_DEFAULT,             /** 
                                     * register only on the start of key press, and continuously after {Keypad_t::longpresstick} scans 
                                     * e.g : A ...............AAAAAAAAAAAAAAAA
                                    **/
    CONTINUOUS_ALWAYS,              /** 
                                     * continuously register key as long as it is pressed 
                                     * e.g: AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
                                    **/
}CONTINUOUS_t;

// clang-format on

/*!
 * @brief Keypad struct
 *
 */
typedef struct
{
    // key map
    uint8_t* user_keymap;
    // input buffer
    CircBuf_t InputBuf;
    // row pins
    PinId_t** row;
    // column pins
    PinId_t** col;

    uint8_t row_size;
    uint8_t col_size;
    uint8_t timers[BUF_SIZE];
    uint16_t longpressTick;
    uint8_t scan_enable;

    // enable continuous mode
    uint8_t continuous;

} Keypad_t;

/*!
 * @brief get pressed char from user keymap
 *
 * @param pKeypad pointer to keypad handler struct
 * @retval characters registered. if none, returns 0
 */
uint8_t Keypad_getchar(Keypad_t* pKeypad);

/*!
 * @brief flush the input buffer
 *
 * @param pKeypad pointer to keypad handler struct
 * @retval none
 */
void Keypad_FlushBuf(Keypad_t* pKeypad);

/*!
 * @brief check for any registered key
 *
 * @param pKeypad pointer to keypad handler struct
 * @retval number of keys pressed
 */
uint32_t Keypad_scan(Keypad_t* pKeypad);

/*!
 * @brief Constructor
 *
 * @param aKeyMap   pointer to array of keys
 * @param aRow      pointer to array of row pins
 * @param aCol      pointer to array of column pins
 * @param nRow      row size
 * @param nCol      column size
 * @retval Keypad_t object
 */
Keypad_t Keypad(uint8_t* aKeyMap, PinId_t** aRow, PinId_t** aCol, uint8_t nRow, uint8_t nCol);