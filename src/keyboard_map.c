#include "keyboard_map.h"

/*
 * 0x00XX -> Normal
 * 0x01XX -> Modifier
 * 0x02XX -> Normal Non-printing
 * 0x03XX -> ASCII Shift
 * 0x80XX -> Media
*/

const uint16_t _asciimap[128] =
{
    0x00U, // NUL
    0x00U, // SOH
    0x00U, // STX
    0x00U, // ETX
    0x00U, // EOT
    0x00U, // ENQ
    0x00U, // ACK
    0x00U, // BEL
    0x2aU, // BS	Backspace
    0x2bU, // TAB	Tab
    0x28U, // LF	Enter
    0x00U, // VT
    0x00U, // FF
    0x00U, // CR
    0x00U, // SO
    0x00U, // SI
    0x00U, // DEL
    0x00U, // DC1
    0x00U, // DC2
    0x00U, // DC3
    0x00U, // DC4
    0x00U, // NAK
    0x00U, // SYN
    0x00U, // ETB
    0x00U, // CAN
    0x00U, // EM
    0x00U, // SUB
    0x00U, // ESC
    0x00U, // FS
    0x00U, // GS
    0x00U, // RS
    0x00U, // US
    0x2cU,         //  ' '
    0x1eU | SHIFT, // !
    0x34U | SHIFT, // "
    0x20U | SHIFT, // #
    0x21U | SHIFT, // $
    0x22U | SHIFT, // %
    0x24U | SHIFT, // &
    0x34U,         // '
    0x26U | SHIFT, // (
    0x27U | SHIFT, // )
    0x25U | SHIFT, // *
    0x2eU | SHIFT, // +
    0x36U,         // ,
    0x2dU,         // -
    0x37U,         // .
    0x38U,         // /
    0x27U,         // 0
    0x1eU,         // 1
    0x1fU,         // 2
    0x20U,         // 3
    0x21U,         // 4
    0x22U,         // 5
    0x23U,         // 6
    0x24U,         // 7
    0x25U,         // 8
    0x26U,         // 9
    0x33U | SHIFT, // :
    0x33U,         // ;
    0x36U | SHIFT, // <
    0x2eU,         // =
    0x37U | SHIFT, // >
    0x38U | SHIFT, // ?
    0x1fU | SHIFT, // @
    0x04U | SHIFT, // A
    0x05U | SHIFT, // B
    0x06U | SHIFT, // C
    0x07U | SHIFT, // D
    0x08U | SHIFT, // E
    0x09U | SHIFT, // F
    0x0aU | SHIFT, // G
    0x0bU | SHIFT, // H
    0x0cU | SHIFT, // I
    0x0dU | SHIFT, // J
    0x0eU | SHIFT, // K
    0x0fU | SHIFT, // L
    0x10U | SHIFT, // M
    0x11U | SHIFT, // N
    0x12U | SHIFT, // O
    0x13U | SHIFT, // P
    0x14U | SHIFT, // Q
    0x15U | SHIFT, // R
    0x16U | SHIFT, // S
    0x17U | SHIFT, // T
    0x18U | SHIFT, // U
    0x19U | SHIFT, // V
    0x1aU | SHIFT, // W
    0x1bU | SHIFT, // X
    0x1cU | SHIFT, // Y
    0x1dU | SHIFT, // Z
    0x2fU,         // [
    0x31U,         // bslash
    0x30U,         // ]
    0x23U | SHIFT, // ^
    0x2dU | SHIFT, // _
    0x35U,         // `
    0x04U,         // a
    0x05U,         // b
    0x06U,         // c
    0x07U,         // d
    0x08U,         // e
    0x09U,         // f
    0x0aU,         // g
    0x0bU,         // h
    0x0cU,         // i
    0x0dU,         // j
    0x0eU,         // k
    0x0fU,         // l
    0x10U,         // m
    0x11U,         // n
    0x12U,         // o
    0x13U,         // p
    0x14U,         // q
    0x15U,         // r
    0x16U,         // s
    0x17U,         // t
    0x18U,         // u
    0x19U,         // v
    0x1aU,         // w
    0x1bU,         // x
    0x1cU,         // y
    0x1dU,         // z
    0x2fU | SHIFT, // {
    0x31U | SHIFT, // |
    0x30U | SHIFT, // }
    0x35U | SHIFT, // ~
    0x00U             // DEL
};

uint16_t keys[] = {
    KEY_ESC,        '1',      '2',      '3',     '4',      '5',      '6',      '7',      '8',      '9',      '0',      '-',        '=',             KEY_BACKSPACE,  '`',
    KEY_TAB,        'q',      'w',      'e',     'r',      't',      'y',      'u',      'i',      'o',      'p',      '[',        ']',             '\\',           KEY_DELETE,
    KEY_CAPS_LOCK,  'a',      's',      'd',     'f',      'g',      'h',      'j',      'k',      'l',      ';',      '\'',       0x00,            KEY_RETURN,     KEY_PAGE_UP,
    KEY_LEFT_SHIFT, 'z',      'x',      'c',     'v',      'b',      'n',      'm',      ',',      '.',      '/',       0x00,      KEY_RIGHT_SHIFT, KEY_UP_ARROW,   KEY_PAGE_DOWN,
    KEY_LEFT_CTRL,  KEY_LEFT_GUI, KEY_LEFT_ALT, 0x00, 0x00, ' ',     0x00,     0x00,     0x00, KEY_RIGHT_ALT, 0x00, KEY_RIGHT_CTRL, KEY_LEFT_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW,
};
 
uint16_t keys_alternate[] = { 
    0x00, KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10, KEY_F11,         KEY_F12,        KEY_MEDIA_STOP,     KEY_PRTSC, 
    0x00, 0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,    KEY_MEDIA_PREV,  KEY_MEDIA_NEXT, KEY_MEDIA_MUTE,     KEY_INSERT,
    0x00, 0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,    0x00,            0x00,           KEY_MEDIA_PAUSE,    KEY_HOME,
    0x00, 0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,    0x00,            0x00,           KEY_MEDIA_VOLUP,    KEY_END,
    0x00, 0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,    0x00,            0x00,           KEY_MEDIA_VOLDN,    0x00,
};

uint32_t USBD_Keyboard_press(KeyboardHID_t* pKeyboardHid, MediaHID_t* pMediaHid, uint16_t k)
{
    uint8_t i; uint16_t retVal = k;
    if ((k & KEY_TYPE_MASK) == KEY_TYPE_MODIF)
    { // it's a modifier key
        pKeyboardHid->MODIFIER |= (k & 0xff);
        return retVal;
    }
    else if ((k & KEY_TYPE_MASK) == KEY_TYPE_NONPRINT)
    { // normal non-printing
        k &= 0xFFU;
    }
    else if ((k & KEY_TYPE_MASK) == SHIFT)
    { // ascii
        k = _asciimap[k & 0xffU];
        pKeyboardHid->MODIFIER |= (KEY_LEFT_SHIFT & 0xff);
    }
    else if ((k & KEY_TYPE_MASK) == 0x0U)
    { // ascii
        k = _asciimap[k & 0xffU];
        if ((k & KEY_TYPE_MASK) == SHIFT)
            pKeyboardHid->MODIFIER |= (KEY_LEFT_SHIFT & 0xff);
    }
    else if ((k & KEY_TYPE_MASK) == KEY_TYPE_MEDIA)
    { // media
        if(pMediaHid->KEYCODE[0] == 0)
            pMediaHid->KEYCODE[0] = k & 0xffU;
        return k;
    }
    else if (!k)
        return 0;

    for (i = 0; i < 6; i++)
    {
        if (pKeyboardHid->KEYCODE[i] == 0x00)
        {
            pKeyboardHid->KEYCODE[i] = (uint8_t)k;
            return retVal;
        }
    }
    return 0;
}

uint32_t USBD_Keyboard_release(KeyboardHID_t* pKeyboardHid, MediaHID_t* pMediaHid, uint16_t k)
{
    uint8_t i; uint16_t retVal = k;
    if ((k & KEY_TYPE_MASK) == KEY_TYPE_MODIF)
    { // it's a modifier key
        pKeyboardHid->MODIFIER &= ~(k & 0xff);
        return retVal;
    }
    else if ((k & KEY_TYPE_MASK) == KEY_TYPE_NONPRINT)
    { // normal non-printing
        k &= 0xFFU;
    }
    else if ((k & KEY_TYPE_MASK) == SHIFT)
    { // ascii
        k = _asciimap[k & 0xffU];
        pKeyboardHid->MODIFIER &= ~(KEY_LEFT_SHIFT & 0xff);
    }
    else if ((k & KEY_TYPE_MASK) == 0x0U)
    { // ascii
        k = _asciimap[k & 0xffU];
        if ((k & KEY_TYPE_MASK) == SHIFT)
            pKeyboardHid->MODIFIER &= ~(KEY_LEFT_SHIFT & 0xff);
    }
    else if ((k & KEY_TYPE_MASK) == KEY_TYPE_MEDIA)
    { // media
        if(pMediaHid->KEYCODE[0] == (k & 0xffU))
            pMediaHid->KEYCODE[0] = 0;
        return k;
    }
    else if (!k)
        return 0;

    for (i = 0; i < 6; i++)
    {
        if (pKeyboardHid->KEYCODE[i] == k)
        {
            pKeyboardHid->KEYCODE[i] = 0;
            return retVal;
        }
    }
    return 0;
}

void USBD_Keyboard_releaseAll(KeyboardHID_t* pKeyboardHid, MediaHID_t* pMediaHid)
{
    pMediaHid->KEYCODE[0] = 0;
    pMediaHid->KEYCODE[1] = 0;
    pKeyboardHid->KEYCODE[0] = 0;
    pKeyboardHid->KEYCODE[1] = 0;
    pKeyboardHid->KEYCODE[2] = 0;
    pKeyboardHid->KEYCODE[3] = 0;
    pKeyboardHid->KEYCODE[4] = 0;
    pKeyboardHid->KEYCODE[5] = 0;
    pKeyboardHid->MODIFIER = 0;
}
