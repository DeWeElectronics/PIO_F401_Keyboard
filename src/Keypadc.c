/*!
 * @file Keypadc.c
 * @author Demitrias Wilbert 
 * @brief 4x4 Keypad driver implementation
 * @version 0.1
 * @date 2021-07-08
 * 
*/

#include "Keypadc.h"
// add to keypad's circular buffer
static void add2buf(CircBuf_t* pBuf, uint8_t ch)
{
    if(pBuf->BufHead == pBuf->BufTail)
    {
        if(!pBuf->BufWritten)
        {
            pBuf->buf[pBuf->BufHead] = ch;
            pBuf->BufHead = (pBuf->BufHead + 1) % BUF_SIZE;
        }
        if(pBuf->BufWritten == BUF_SIZE)
        {
            pBuf->buf[pBuf->BufHead] = ch;
            pBuf->BufHead = (pBuf->BufHead + 1) % BUF_SIZE;
            pBuf->BufTail = (pBuf->BufTail + 1) % BUF_SIZE;
        }
    }
    else
    {
        pBuf->buf[pBuf->BufHead] = ch;
        pBuf->BufHead = (pBuf->BufHead + 1) % BUF_SIZE;
    }
    pBuf->BufWritten = (pBuf->BufWritten < BUF_SIZE)? pBuf->BufWritten + 1 : pBuf->BufWritten;

}

static uint8_t buf_getchar(CircBuf_t* pBuf)
{
    if(pBuf->BufWritten == 0) return 0;
    pBuf->BufWritten--;
    uint8_t tmp = pBuf->buf[pBuf->BufTail];
    pBuf->BufTail = ((pBuf->BufTail + 1) % BUF_SIZE);
    return tmp;
}

static void flushBuf(CircBuf_t* pBuf)
{
    pBuf->BufHead = 0;
    pBuf->BufTail = 0;
    pBuf->BufWritten = 0;
}


Keypad_t Keypad(uint8_t* aKeyMap, PinId_t** aRow, PinId_t** aCol, uint8_t nRow, uint8_t nCol)
{
    Keypad_t temp;
    flushBuf(&temp.InputBuf);
    temp.continuous = 0;
    temp.scan_enable = 1;
    temp.user_keymap = aKeyMap;
    temp.row = aRow;
    temp.col = aCol;
    temp.row_size = nRow;
    temp.col_size = nCol;
    temp.longpressTick = 15;

    // configure row pin as OUTPUT, LOW (to enable the use of GPIO Interrupt mode)
    for (uint8_t i = 0; i < temp.row_size; i++)
    {
        PIN_OUTPUT_LOW(temp.row[i]);
    }

    // configure column pin as INPUT, PULLUP (to enable the use of GPIO Falling edge Interrupt mode)
    for (uint8_t i = 0; i < temp.col_size; i++)
        PIN_INPUT_PULLUP(temp.col[i]);
    return temp;
}

static void add(Keypad_t* pKeypad, uint8_t i, uint8_t j)
{
    // only add to buffer if the key was just pressed (wasn't pressed in the last scan)
    // except if the key was in continuous mode
    // increment key timer. if already at maximum then keep it there
    uint8_t* key_timer = &(pKeypad->timers[pKeypad->col_size * i + j]);
    *key_timer = (*key_timer < pKeypad->longpressTick)? ((*key_timer) + 1) : pKeypad->longpressTick;

    if (*key_timer == 1)
    {
        // if key state is low (not pressed in the previous scan)
        // add to buffer
        add2buf(&pKeypad->InputBuf, pKeypad->user_keymap[pKeypad->col_size * i + j]);
        return;
    }

    switch(pKeypad->continuous)
    {
        case CONTINUOUS_DISABLE: return;
        case CONTINUOUS_DEFAULT: 
        {
            if(*key_timer == pKeypad->longpressTick)
                add2buf(&pKeypad->InputBuf, pKeypad->user_keymap[(pKeypad->col_size * i + j)]);
            return;
        }
        case CONTINUOUS_ALWAYS:
        {
            add2buf(&pKeypad->InputBuf, pKeypad->user_keymap[(pKeypad->col_size * i + j)]);
            return;
        }
    }
}

uint8_t Keypad_getchar(Keypad_t* pKeypad)
{
    return buf_getchar(&pKeypad->InputBuf);
}

void Keypad_FlushBuf(Keypad_t* pKeypad)
{
    flushBuf(&pKeypad->InputBuf);
}

static void clear(Keypad_t* pKeypad, uint8_t i, uint8_t j)
{
    // clear the key state
    pKeypad->timers[(pKeypad->col_size * i + j)] = 0;
}

uint32_t Keypad_scan(Keypad_t* pKeypad)
{
    if(pKeypad->scan_enable == 0)
        return 0;
    static uint8_t i = 0;
    uint32_t retval = 0;
    for (i = 0; i < pKeypad->row_size; i++)
    {
        // set row pin i as output and pull down
        // set the rest of the row pins as input and pull up
        PIN_OUTPUT_LOW(pKeypad->row[i]);
        // some delay
        for (volatile uint32_t DELAY = 0; DELAY < 500; DELAY++)
            ;

        // loop through the columns j (pins 0-3)
        for (uint8_t j = 0; j < pKeypad->col_size; j++)
        {
            // if this pin is LOW, we know that this Key is pressed
            if (!PIN_READ(pKeypad->col[j]))
            {
                // append this row-column combination to the buffer
                add(pKeypad, i, j);
                retval += 1;
            }
            else
                clear(pKeypad, i, j);
        }
        // set back to INPUT, PULLUP
        PIN_INPUT_PULLUP(pKeypad->row[i]);
    }
    return retval;
}
