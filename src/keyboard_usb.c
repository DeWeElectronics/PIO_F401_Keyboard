#include "keyboard_usb.h"

/*
 * 0x000000XX -> Normal
 * 0x010000XX -> Modifier
 * 0x020000XX -> Normal Non-printing
 * 0x030000XX -> ASCII Shift
 * 0x800000XX -> Media
*/




const uint32_t _asciimap[] =
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
    0x00U,         // DEL
    // MODIFIER
    KEY_LEFT_CTRL,
    KEY_LEFT_SHIFT,
    KEY_LEFT_ALT, 
    KEY_LEFT_GUI, 
    KEY_RIGHT_CTRL, 
    KEY_RIGHT_SHIFT, 
    KEY_RIGHT_ALT, 
    KEY_RIGHT_GUI, 
    // NONPRINT
    KEY_UP_ARROW,
    KEY_DOWN_ARROW,
    KEY_LEFT_ARROW,
    KEY_RIGHT_ARROW,
    KEY_BACKSPACE,
    KEY_TAB,
    KEY_RETURN,
    KEY_ESC,
    KEY_INSERT,
    KEY_PRTSC,
    KEY_DELETE,
    KEY_PAGE_UP,
    KEY_PAGE_DOWN,
    KEY_HOME,
    KEY_END,
    KEY_CAPS_LOCK,
    KEY_NUM_LOCK,

    // F Keys
    KEY_F1, 
    KEY_F2, 
    KEY_F3, 
    KEY_F4, 
    KEY_F5, 
    KEY_F6, 
    KEY_F7, 
    KEY_F8, 
    KEY_F9, 
    KEY_F10, 
    KEY_F11, 
    KEY_F12, 
    KEY_F13, 
    KEY_F14, 
    KEY_F15, 
    KEY_F16, 
    KEY_F17, 
    KEY_F18, 
    KEY_F19, 
    KEY_F20, 
    KEY_F21, 
    KEY_F22, 
    KEY_F23, 
    KEY_F24, 

    // KEYPAD
    KEY_NUM_0,
    KEY_NUM_1,
    KEY_NUM_2,
    KEY_NUM_3,
    KEY_NUM_4,
    KEY_NUM_5,
    KEY_NUM_6,
    KEY_NUM_7,
    KEY_NUM_8,
    KEY_NUM_9,
    KEY_NUM_SLASH,
    KEY_NUM_ASTERISK,
    KEY_NUM_MINUS,
    KEY_NUM_PLUS,
    KEY_NUM_ENTER,
    KEY_NUM_PERIOD,
    KEY_NUM_EQUAL,

    // MEDIA 1
    KEY_MEDIA_NEXT,
    KEY_MEDIA_PREV, 
    KEY_MEDIA_STOP, 
    KEY_MEDIA_PAUSE, 
    KEY_MEDIA_MUTE, 
    KEY_MEDIA_VOLUP, 
    KEY_MEDIA_VOLDN, 
    KEY_MEDIA_WWW_HOME, 
    
    // MEDIA 2
    KEY_FILE_EXPLORER, 
    KEY_MEDIA_CALC, 
    KEY_MEDIA_WWW_BOOKMARKS, 
    KEY_MEDIA_WWW_SEARCH, 
    KEY_MEDIA_WWW_STOP, 
    KEY_MEDIA_WWW_BACK, 
    KEY_CONSUMER_CTL, 
    KEY_MEDIA_EMAIL, 
};

size_t Media_Press(MediaHID_t* pMediaHid, const MediaKeyReport k)
{
    uint16_t k_16 = k;
    // {8, 0} -> 0 | (8U << 8)
    uint16_t mediaKeyReport_16 = pMediaHid->KEYCODE[1] | (pMediaHid->KEYCODE[0] << 8);

    mediaKeyReport_16 |= k_16;
    pMediaHid->KEYCODE[0] = (uint8_t)((mediaKeyReport_16 & 0xFF00) >> 8);
    pMediaHid->KEYCODE[1] = (uint8_t)(mediaKeyReport_16 & 0x00FF);

    return 1;
}

size_t Media_Release(MediaHID_t* pMediaHid, const MediaKeyReport k)
{
    uint16_t k_16 = k;
    uint16_t mediaKeyReport_16 = pMediaHid->KEYCODE[1] | (pMediaHid->KEYCODE[0] << 8);
    
    mediaKeyReport_16 &= ~k_16;
    pMediaHid->KEYCODE[0] = (uint8_t)((mediaKeyReport_16 & 0xFF00) >> 8);
    pMediaHid->KEYCODE[1] = (uint8_t)(mediaKeyReport_16 & 0x00FF);

    return 1;
}

uint32_t USBD_Keyboard_str_press(KeyboardHID_t* pKeyboardHid, MediaHID_t* pMediaHid, uint8_t k) {
    uint32_t val = k;
    if (val >= 128) val = _asciimap[k];
    return USBD_Keyboard_press(pKeyboardHid, pMediaHid, val);
}

uint32_t USBD_Keyboard_str_release(KeyboardHID_t* pKeyboardHid, MediaHID_t* pMediaHid, uint8_t k) {
    uint32_t val = k;
    if (val >= 128) val = _asciimap[k];
    return USBD_Keyboard_release(pKeyboardHid, pMediaHid, (k < 128)? k : _asciimap[k]);
}

uint32_t USBD_Keyboard_press(KeyboardHID_t* pKeyboardHid, MediaHID_t* pMediaHid, uint32_t k)
{
    uint8_t i; uint32_t retVal = k;
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
        Media_Press(pMediaHid, (k & 0xffffUL));
        return k;
    }
    else if ((k & KEY_TYPE_MASK) == KEY_TYPE_KEYPAD)
    { // media
        k = k & 0xffUL;
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

uint32_t USBD_Keyboard_release(KeyboardHID_t* pKeyboardHid, MediaHID_t* pMediaHid, uint32_t k)
{
    uint8_t i; uint32_t retVal = k;
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
        Media_Release(pMediaHid, (k & 0xffffU));
        return k;
    }
    else if ((k & KEY_TYPE_MASK) == KEY_TYPE_KEYPAD)
    { // media
        k = k & 0xffUL;
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
