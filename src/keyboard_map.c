#include "keyboard_map.h"

/*
 * 0x00XX -> Normal
 * 0x01XX -> Modifier
 * 0x02XX -> Normal Non-printing
 * 0x03XX -> ASCII Shift
 * 0x80XX -> Media
*/

#define SHIFT 0x0300U
const uint16_t _asciimap[128] =
{
    0x00, // NUL
    0x00, // SOH
    0x00, // STX
    0x00, // ETX
    0x00, // EOT
    0x00, // ENQ
    0x00, // ACK
    0x00, // BEL
    0x2a, // BS	Backspace
    0x2b, // TAB	Tab
    0x28, // LF	Enter
    0x00, // VT
    0x00, // FF
    0x00, // CR
    0x00, // SO
    0x00, // SI
    0x00, // DEL
    0x00, // DC1
    0x00, // DC2
    0x00, // DC3
    0x00, // DC4
    0x00, // NAK
    0x00, // SYN
    0x00, // ETB
    0x00, // CAN
    0x00, // EM
    0x00, // SUB
    0x00, // ESC
    0x00, // FS
    0x00, // GS
    0x00, // RS
    0x00, // US
    0x2c,         //  ' '
    0x1e | SHIFT, // !
    0x34 | SHIFT, // "
    0x20 | SHIFT, // #
    0x21 | SHIFT, // $
    0x22 | SHIFT, // %
    0x24 | SHIFT, // &
    0x34,         // '
    0x26 | SHIFT, // (
    0x27 | SHIFT, // )
    0x25 | SHIFT, // *
    0x2e | SHIFT, // +
    0x36,         // ,
    0x2d,         // -
    0x37,         // .
    0x38,         // /
    0x27,         // 0
    0x1e,         // 1
    0x1f,         // 2
    0x20,         // 3
    0x21,         // 4
    0x22,         // 5
    0x23,         // 6
    0x24,         // 7
    0x25,         // 8
    0x26,         // 9
    0x33 | SHIFT, // :
    0x33,         // ;
    0x36 | SHIFT, // <
    0x2e,         // =
    0x37 | SHIFT, // >
    0x38 | SHIFT, // ?
    0x1f | SHIFT, // @
    0x04 | SHIFT, // A
    0x05 | SHIFT, // B
    0x06 | SHIFT, // C
    0x07 | SHIFT, // D
    0x08 | SHIFT, // E
    0x09 | SHIFT, // F
    0x0a | SHIFT, // G
    0x0b | SHIFT, // H
    0x0c | SHIFT, // I
    0x0d | SHIFT, // J
    0x0e | SHIFT, // K
    0x0f | SHIFT, // L
    0x10 | SHIFT, // M
    0x11 | SHIFT, // N
    0x12 | SHIFT, // O
    0x13 | SHIFT, // P
    0x14 | SHIFT, // Q
    0x15 | SHIFT, // R
    0x16 | SHIFT, // S
    0x17 | SHIFT, // T
    0x18 | SHIFT, // U
    0x19 | SHIFT, // V
    0x1a | SHIFT, // W
    0x1b | SHIFT, // X
    0x1c | SHIFT, // Y
    0x1d | SHIFT, // Z
    0x2f,         // [
    0x31,         // bslash
    0x30,         // ]
    0x23 | SHIFT, // ^
    0x2d | SHIFT, // _
    0x35,         // `
    0x04,         // a
    0x05,         // b
    0x06,         // c
    0x07,         // d
    0x08,         // e
    0x09,         // f
    0x0a,         // g
    0x0b,         // h
    0x0c,         // i
    0x0d,         // j
    0x0e,         // k
    0x0f,         // l
    0x10,         // m
    0x11,         // n
    0x12,         // o
    0x13,         // p
    0x14,         // q
    0x15,         // r
    0x16,         // s
    0x17,         // t
    0x18,         // u
    0x19,         // v
    0x1a,         // w
    0x1b,         // x
    0x1c,         // y
    0x1d,         // z
    0x2f | SHIFT, // {
    0x31 | SHIFT, // |
    0x30 | SHIFT, // }
    0x35 | SHIFT, // ~
    0             // DEL
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
    if ((k & 0xff00) == 0x100)
    { // it's a modifier key
        pKeyboardHid->MODIFIER |= (k & 0xff);
        return retVal;
    }
    else if ((k & 0xff00) == 0x200)
    { // normal non-printing
        k &= 0xFFU;
    }
    else if ((k & 0xff00) == 0x0300U)
    { // ascii
        k = _asciimap[k & 0xffU];
        pKeyboardHid->MODIFIER |= (KEY_LEFT_SHIFT & 0xff);
    }
    else if ((k & 0xff00) == 0x0U)
    { // ascii
        k = _asciimap[k & 0xffU];
        if ((k & 0xff00) == SHIFT)
            pKeyboardHid->MODIFIER |= (KEY_LEFT_SHIFT & 0xff);
    }
    else if ((k & 0xff00) == 0x8000)
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
    if ((k & 0xff00) == 0x100)
    { // it's a modifier key
        pKeyboardHid->MODIFIER &= ~(k & 0xff);
        return retVal;
    }
    else if ((k & 0xff00) == 0x200)
    { // normal non-printing
        k &= 0xFFU;
    }
    else if ((k & 0xff00) == 0x0300U)
    { // ascii
        k = _asciimap[k & 0xffU];
        pKeyboardHid->MODIFIER &= ~(KEY_LEFT_SHIFT & 0xff);
    }
    else if ((k & 0xff00) == 0x0U)
    { // ascii
        k = _asciimap[k & 0xffU];
        if ((k & 0xff00) == SHIFT)
            pKeyboardHid->MODIFIER &= ~(KEY_LEFT_SHIFT & 0xff);
    }
    else if ((k & 0xff00) == 0x8000)
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
