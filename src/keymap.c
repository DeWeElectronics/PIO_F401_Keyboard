#include "keymap.h"


const uint32_t keys[] = {
    KEY_ESC,        '1',      '2',      '3',     '4',      '5',      '6',      '7',      '8',      '9',      '0',      '-',        '=',             KEY_BACKSPACE,  '`',
    KEY_TAB,        'q',      'w',      'e',     'r',      't',      'y',      'u',      'i',      'o',      'p',      '[',        ']',             '\\',           KEY_DELETE,
    KEY_CAPS_LOCK,  'a',      's',      'd',     'f',      'g',      'h',      'j',      'k',      'l',      ';',      '\'',       0x00,            KEY_RETURN,     KEY_PAGE_UP,
    KEY_LEFT_SHIFT, 'z',      'x',      'c',     'v',      'b',      'n',      'm',      ',',      '.',      '/',       0x00,      KEY_RIGHT_SHIFT, KEY_UP_ARROW,   KEY_PAGE_DOWN,
    KEY_LEFT_CTRL,  KEY_LEFT_GUI, KEY_LEFT_ALT, 0x00, 0x00, ' ',     0x00,     0x00,     0x00, KEY_RIGHT_ALT, 0x00, KEY_RIGHT_CTRL, KEY_LEFT_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW,
};
 
const uint32_t keys_alternate[] = { 
    0x00, KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10, KEY_F11,         KEY_F12,        KEY_MEDIA_STOP,     KEY_PRTSC, 
    0x00, 0x00,   0x00,   KEY_MEDIA_EMAIL,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,    KEY_MEDIA_PREV,  KEY_MEDIA_NEXT, KEY_MEDIA_MUTE,     KEY_INSERT,
    0x00, 0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,    0x00,            0x00,           KEY_MEDIA_PAUSE,    KEY_HOME,
    0x00, 0x00,   0x00,   KEY_MEDIA_CALC,   0x00,   KEY_MEDIA_WWW_HOME,   0x00,   KEY_CONSUMER_CTL,   0x00,   0x00,   0x00,    0x00,            0x00,           KEY_MEDIA_VOLUP,    KEY_END,
    0x00, 0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,    0x00,            0x00,           KEY_MEDIA_VOLDN,    0x00,
};