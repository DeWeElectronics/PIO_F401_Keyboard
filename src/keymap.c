#include "keymap.h"


const char* keys[] = {
    STR_ESC,        "1",      "2",      "3",     "4",      "5",      "6",      "7",      "8",      "9",      "0",      "-",        "=",             STR_BACKSPACE,  "`",
    STR_TAB,        "q",      "w",      "e",     "r",      "t",      "y",      "u",      "i",      "o",      "p",      "[",        "]",             "\\",           STR_DELETE,
    STR_CAPS_LOCK,  "a",      "s",      "d",     "f",      "g",      "h",      "j",      "k",      "l",      ";",      "\'",       "\0",            STR_RETURN,     STR_PAGE_UP,
    STR_LEFT_SHIFT, "z",      "x",      "c",     "v",      "b",      "n",      "m",      ",",      ".",      "/",       "\0",      STR_RIGHT_SHIFT, STR_UP_ARROW,   STR_PAGE_DOWN,
    STR_LEFT_CTRL,  STR_LEFT_GUI, STR_LEFT_ALT, "\0", "\0", " ",     "\0",     "\0",     "\0", STR_RIGHT_ALT, "\0", STR_RIGHT_CTRL, STR_LEFT_ARROW, STR_DOWN_ARROW, STR_RIGHT_ARROW,
};

/*
 * when pressing FN STR:
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
 *     FN + backspace  -> MEDIA STOP
 *     FN + '['        -> MEDIA PREVIOUS
 *     FN + ']'        -> MEDIA NEXT
 *     FN + '\'        -> MEDIA MUTE
 *     FN + ENTER      -> MEDIA PAUSE
 *     FN + UP ARROW   -> MEDIA VOLUME UP
 *     FN + DOWN ARROW -> MEDIA VOLUME DOWN
 *     FN + 'E'        -> Open Email
 *     FN + 'C'        -> Open Calculator
 *     FN + 'B'        -> Open Browser
 *     FN + 'M'        -> Open Consumer Control (Music)
 */
 
const char* keys_alternate[] = { 
    "\0", STR_F1, STR_F2, STR_F3, STR_F4, STR_F5, STR_F6, STR_F7, STR_F8, STR_F9, STR_F10, STR_F11,         STR_F12,        STR_MEDIA_STOP,     STR_PRTSC, 
    "\0", "\0",   "\0",   STR_MEDIA_EMAIL,   "\0",   "\0",   "\0",   "\0",   "\0",   "\0",   "\0",    STR_MEDIA_PREV,  STR_MEDIA_NEXT, STR_MEDIA_MUTE,     STR_INSERT,
    "\0", "\0",   "\0",   "\0",   "\0",   "\0",   "\0",   "\0",   "\0",   "\0",   "\0",    "\0",            "\0",           STR_MEDIA_PAUSE,    STR_HOME,
    "\0", "\0",   "\0",   STR_MEDIA_CALC,   "\0",   STR_MEDIA_WWW_HOME,   "\0",   STR_CONSUMER_CTL,   "\0",   "\0",   "\0",    "\0",            "\0",           STR_MEDIA_VOLUP,    STR_END,
    "\0", "\0",   "\0",   "\0",   "\0",   "\0",   "\0",   "\0",   "\0",   "\0",   "\0",    "\0",            "\0",           STR_MEDIA_VOLDN,    "\0",
};
