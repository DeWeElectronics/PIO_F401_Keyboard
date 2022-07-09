#include "keymap.h"


const uint32_t keys[] = {
    KEY_ESC,        '1',      '2',      '3',     '4',      '5',      '6',      '7',      '8',      '9',      '0',      '-',        '=',             KEY_BACKSPACE,  '`',
    KEY_TAB,        'q',      'w',      'e',     'r',      't',      'y',      'u',      'i',      'o',      'p',      '[',        ']',             '\\',           KEY_DELETE,
    KEY_CAPS_LOCK,  'a',      's',      'd',     'f',      'g',      'h',      'j',      'k',      'l',      ';',      '\'',       0x00,            KEY_RETURN,     KEY_PAGE_UP,
    KEY_LEFT_SHIFT, 'z',      'x',      'c',     'v',      'b',      'n',      'm',      ',',      '.',      '/',       0x00,      KEY_RIGHT_SHIFT, KEY_UP_ARROW,   KEY_PAGE_DOWN,
    KEY_LEFT_CTRL,  KEY_LEFT_GUI, KEY_LEFT_ALT, 0x00, 0x00, ' ',     0x00,     0x00,     0x00, KEY_RIGHT_ALT, 0x00, KEY_RIGHT_CTRL, KEY_LEFT_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW,
};

/*
 * when pressing FN key:
 * F1 to F12: 
 *     FN + '1' -> F1
 *     FN + '2' -> F2
 *     FN + '3' -> F3
 *     FN + '4' -> F4
 *     FN + '5' -> F5
 *     FN + '6' -> F6
 *     FN + '7' -> F7
 *     FN + '8' -> F8
 *     FN + '9' -> F9
 *     FN + '0' -> F10
 *     FN + '-' -> F11
 *     FN + '=' -> F12
 * Controls:
 *     FN + '`' (backtick) -> PRINT_SCREEN
 *     FN + DELETE         -> INSERT
 *     FN + PAGE UP        -> HOME
 *     FN + PAGE DOWN      -> END
 * Media Control:
 *     FN + backspace      -> MEDIA STOP
 *     FN + '[' -> MEDIA PREVIOUS
 *     FN + ']' -> MEDIA NEXT
 *     FN + '\' -> MEDIA MUTE
 *     FN + ENTER -> MEDIA PAUSE
 *     FN + UP ARROW -> MEDIA VOLUME UP
 *     FN + DOWN ARROW -> MEDIA VOLUME DOWN
 *     FN + 'E' -> Open Email
 *     FN + 'C' -> Open Calculator
 *     FN + 'B' -> Open Browser
 *     FN + 'M' -> Open Consumer Control (Music)
 */
 
const uint32_t keys_alternate[] = { 
    0x00, KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10, KEY_F11,         KEY_F12,        KEY_MEDIA_STOP,     KEY_PRTSC, 
    0x00, 0x00,   0x00,   KEY_MEDIA_EMAIL,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,    KEY_MEDIA_PREV,  KEY_MEDIA_NEXT, KEY_MEDIA_MUTE,     KEY_INSERT,
    0x00, 0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,    0x00,            0x00,           KEY_MEDIA_PAUSE,    KEY_HOME,
    0x00, 0x00,   0x00,   KEY_MEDIA_CALC,   0x00,   KEY_MEDIA_WWW_HOME,   0x00,   KEY_CONSUMER_CTL,   0x00,   0x00,   0x00,    0x00,            0x00,           KEY_MEDIA_VOLUP,    KEY_END,
    0x00, 0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,    0x00,            0x00,           KEY_MEDIA_VOLDN,    0x00,
};
