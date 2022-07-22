#ifndef KEYBOARD_MAP_H
#define KEYBOARD_MAP_H

#include "usbd_hid.h"
#include "stdint.h"

#define SHIFT                ((uint32_t)0x03000000UL)
#define KEY_TYPE_MASK        ((uint32_t)0xffff0000UL)

#define KEY_TYPE_MODIF      ((uint32_t)0x01000000UL)
#define KEY_TYPE_NONPRINT   ((uint32_t)0x02000000UL)
#define KEY_TYPE_KEYPAD     ((uint32_t)0x04000000UL)
#define KEY_TYPE_MEDIA      ((uint32_t)0x80000000UL)

#define KEY_LEFT_CTRL       (KEY_TYPE_MODIF | (uint32_t)0x01UL)
#define KEY_LEFT_SHIFT      (KEY_TYPE_MODIF | (uint32_t)0x02UL)
#define KEY_LEFT_ALT        (KEY_TYPE_MODIF | (uint32_t)0x04UL)
#define KEY_LEFT_GUI        (KEY_TYPE_MODIF | (uint32_t)0x08UL)
#define KEY_RIGHT_CTRL      (KEY_TYPE_MODIF | (uint32_t)0x10UL)
#define KEY_RIGHT_SHIFT     (KEY_TYPE_MODIF | (uint32_t)0x20UL)
#define KEY_RIGHT_ALT       (KEY_TYPE_MODIF | (uint32_t)0x40UL)
#define KEY_RIGHT_GUI       (KEY_TYPE_MODIF | (uint32_t)0x80UL)

#define KEY_UP_ARROW        (KEY_TYPE_NONPRINT | (uint32_t)0x0052UL)
#define KEY_DOWN_ARROW      (KEY_TYPE_NONPRINT | (uint32_t)0x0051UL)
#define KEY_LEFT_ARROW      (KEY_TYPE_NONPRINT | (uint32_t)0x0050UL)
#define KEY_RIGHT_ARROW     (KEY_TYPE_NONPRINT | (uint32_t)0x004fUL)
#define KEY_BACKSPACE       (KEY_TYPE_NONPRINT | (uint32_t)0x002aUL)
#define KEY_TAB             (KEY_TYPE_NONPRINT | (uint32_t)0x002bUL)
#define KEY_RETURN          (KEY_TYPE_NONPRINT | (uint32_t)0x0028UL)
#define KEY_ESC             (KEY_TYPE_NONPRINT | (uint32_t)0x0029UL)
#define KEY_INSERT          (KEY_TYPE_NONPRINT | (uint32_t)0x0049UL)
#define KEY_PRTSC           (KEY_TYPE_NONPRINT | (uint32_t)0x0046UL)
#define KEY_DELETE          (KEY_TYPE_NONPRINT | (uint32_t)0x004cUL)
#define KEY_PAGE_UP         (KEY_TYPE_NONPRINT | (uint32_t)0x004bUL)
#define KEY_PAGE_DOWN       (KEY_TYPE_NONPRINT | (uint32_t)0x004eUL)
#define KEY_HOME            (KEY_TYPE_NONPRINT | (uint32_t)0x004aUL)
#define KEY_END             (KEY_TYPE_NONPRINT | (uint32_t)0x004dUL)
#define KEY_CAPS_LOCK       (KEY_TYPE_NONPRINT | (uint32_t)0x0039UL)
#define KEY_NUM_LOCK        (KEY_TYPE_NONPRINT | (uint32_t)0x0053UL)

#define KEY_F1              (KEY_TYPE_NONPRINT | (uint32_t)0x003aUL)
#define KEY_F2              (KEY_TYPE_NONPRINT | (uint32_t)0x003bUL)
#define KEY_F3              (KEY_TYPE_NONPRINT | (uint32_t)0x003cUL)
#define KEY_F4              (KEY_TYPE_NONPRINT | (uint32_t)0x003dUL)
#define KEY_F5              (KEY_TYPE_NONPRINT | (uint32_t)0x003eUL)
#define KEY_F6              (KEY_TYPE_NONPRINT | (uint32_t)0x003fUL)
#define KEY_F7              (KEY_TYPE_NONPRINT | (uint32_t)0x0040UL)
#define KEY_F8              (KEY_TYPE_NONPRINT | (uint32_t)0x0041UL)
#define KEY_F9              (KEY_TYPE_NONPRINT | (uint32_t)0x0042UL)
#define KEY_F10             (KEY_TYPE_NONPRINT | (uint32_t)0x0043UL)
#define KEY_F11             (KEY_TYPE_NONPRINT | (uint32_t)0x0044UL)
#define KEY_F12             (KEY_TYPE_NONPRINT | (uint32_t)0x0045UL)
#define KEY_PRTSC           (KEY_TYPE_NONPRINT | (uint32_t)0x0046UL)
#define KEY_F13             (KEY_TYPE_NONPRINT | (uint32_t)0x0068UL)
#define KEY_F14             (KEY_TYPE_NONPRINT | (uint32_t)0x0069UL)
#define KEY_F15             (KEY_TYPE_NONPRINT | (uint32_t)0x006aUL)
#define KEY_F16             (KEY_TYPE_NONPRINT | (uint32_t)0x006bUL)
#define KEY_F17             (KEY_TYPE_NONPRINT | (uint32_t)0x006cUL)
#define KEY_F18             (KEY_TYPE_NONPRINT | (uint32_t)0x006dUL)
#define KEY_F19             (KEY_TYPE_NONPRINT | (uint32_t)0x006eUL)
#define KEY_F20             (KEY_TYPE_NONPRINT | (uint32_t)0x006fUL)
#define KEY_F21             (KEY_TYPE_NONPRINT | (uint32_t)0x0070UL)
#define KEY_F22             (KEY_TYPE_NONPRINT | (uint32_t)0x0071UL)
#define KEY_F23             (KEY_TYPE_NONPRINT | (uint32_t)0x0072UL)
#define KEY_F24             (KEY_TYPE_NONPRINT | (uint32_t)0x0073UL)

#define KEY_NUM_0           (KEY_TYPE_KEYPAD | (uint32_t)0x0062UL)
#define KEY_NUM_1           (KEY_TYPE_KEYPAD | (uint32_t)0x0059UL)
#define KEY_NUM_2           (KEY_TYPE_KEYPAD | (uint32_t)0x005aUL)
#define KEY_NUM_3           (KEY_TYPE_KEYPAD | (uint32_t)0x005bUL)
#define KEY_NUM_4           (KEY_TYPE_KEYPAD | (uint32_t)0x005cUL)
#define KEY_NUM_5           (KEY_TYPE_KEYPAD | (uint32_t)0x005dUL)
#define KEY_NUM_6           (KEY_TYPE_KEYPAD | (uint32_t)0x005eUL)
#define KEY_NUM_7           (KEY_TYPE_KEYPAD | (uint32_t)0x005fUL)
#define KEY_NUM_8           (KEY_TYPE_KEYPAD | (uint32_t)0x0060UL)
#define KEY_NUM_9           (KEY_TYPE_KEYPAD | (uint32_t)0x0061UL)
#define KEY_NUM_SLASH       (KEY_TYPE_KEYPAD | (uint32_t)0x0054UL)
#define KEY_NUM_ASTERISK    (KEY_TYPE_KEYPAD | (uint32_t)0x0055UL)
#define KEY_NUM_MINUS       (KEY_TYPE_KEYPAD | (uint32_t)0x0056UL)
#define KEY_NUM_PLUS        (KEY_TYPE_KEYPAD | (uint32_t)0x0057UL)
#define KEY_NUM_ENTER       (KEY_TYPE_KEYPAD | (uint32_t)0x0058UL)
#define KEY_NUM_PERIOD      (KEY_TYPE_KEYPAD | (uint32_t)0x0063UL)
#define KEY_NUM_EQUAL       (KEY_TYPE_KEYPAD | (uint32_t)0x0067UL)


typedef uint32_t MediaKeyReport;

#define KEY_MEDIA_NEXT              (KEY_TYPE_MEDIA | (MediaKeyReport) 0x0100UL)
#define KEY_MEDIA_PREV              (KEY_TYPE_MEDIA | (MediaKeyReport) 0x0200UL)
#define KEY_MEDIA_STOP              (KEY_TYPE_MEDIA | (MediaKeyReport) 0x0400UL)
#define KEY_MEDIA_PAUSE             (KEY_TYPE_MEDIA | (MediaKeyReport) 0x0800UL)
#define KEY_MEDIA_MUTE              (KEY_TYPE_MEDIA | (MediaKeyReport) 0x1000UL)
#define KEY_MEDIA_VOLUP             (KEY_TYPE_MEDIA | (MediaKeyReport) 0x2000UL)
#define KEY_MEDIA_VOLDN             (KEY_TYPE_MEDIA | (MediaKeyReport) 0x4000UL)
#define KEY_MEDIA_WWW_HOME          (KEY_TYPE_MEDIA | (MediaKeyReport) 0x8000UL)

#define KEY_FILE_EXPLORER           (KEY_TYPE_MEDIA | (MediaKeyReport) 0x0001UL)
#define KEY_MEDIA_CALC              (KEY_TYPE_MEDIA | (MediaKeyReport) 0x0002UL)
#define KEY_MEDIA_WWW_BOOKMARKS     (KEY_TYPE_MEDIA | (MediaKeyReport) 0x0004UL)
#define KEY_MEDIA_WWW_SEARCH        (KEY_TYPE_MEDIA | (MediaKeyReport) 0x0008UL)
#define KEY_MEDIA_WWW_STOP          (KEY_TYPE_MEDIA | (MediaKeyReport) 0x0010UL)
#define KEY_MEDIA_WWW_BACK          (KEY_TYPE_MEDIA | (MediaKeyReport) 0x0020UL)
#define KEY_CONSUMER_CTL            (KEY_TYPE_MEDIA | (MediaKeyReport) 0x0040UL)
#define KEY_MEDIA_EMAIL             (KEY_TYPE_MEDIA | (MediaKeyReport) 0x0080UL)

#define STR_LEFT_CTRL "\x80"
#define STR_LEFT_SHIFT "\x81"
#define STR_LEFT_ALT "\x82"
#define STR_LEFT_GUI "\x83"
#define STR_RIGHT_CTRL "\x84"
#define STR_RIGHT_SHIFT "\x85"
#define STR_RIGHT_ALT "\x86"
#define STR_RIGHT_GUI "\x87"
#define STR_UP_ARROW "\x88"
#define STR_DOWN_ARROW "\x89"
#define STR_LEFT_ARROW "\x8a"
#define STR_RIGHT_ARROW "\x8b"
#define STR_BACKSPACE "\x8c"
#define STR_TAB "\x8d"
#define STR_RETURN "\x8e"
#define STR_ESC "\x8f"
#define STR_INSERT "\x90"
#define STR_PRTSC "\x91"
#define STR_DELETE "\x92"
#define STR_PAGE_UP "\x93"
#define STR_PAGE_DOWN "\x94"
#define STR_HOME "\x95"
#define STR_END "\x96"
#define STR_CAPS_LOCK "\x97"
#define STR_NUM_LOCK "\x98"
#define STR_F1 "\x99"
#define STR_F2 "\x9a"
#define STR_F3 "\x9b"
#define STR_F4 "\x9c"
#define STR_F5 "\x9d"
#define STR_F6 "\x9e"
#define STR_F7 "\x9f"
#define STR_F8 "\xa0"
#define STR_F9 "\xa1"
#define STR_F10 "\xa2"
#define STR_F11 "\xa3"
#define STR_F12 "\xa4"
#define STR_F13 "\xa5"
#define STR_F14 "\xa6"
#define STR_F15 "\xa7"
#define STR_F16 "\xa8"
#define STR_F17 "\xa9"
#define STR_F18 "\xaa"
#define STR_F19 "\xab"
#define STR_F20 "\xac"
#define STR_F21 "\xad"
#define STR_F22 "\xae"
#define STR_F23 "\xaf"
#define STR_F24 "\xb0"
#define STR_NUM_0 "\xb1"
#define STR_NUM_1 "\xb2"
#define STR_NUM_2 "\xb3"
#define STR_NUM_3 "\xb4"
#define STR_NUM_4 "\xb5"
#define STR_NUM_5 "\xb6"
#define STR_NUM_6 "\xb7"
#define STR_NUM_7 "\xb8"
#define STR_NUM_8 "\xb9"
#define STR_NUM_9 "\xba"
#define STR_NUM_SLASH "\xbb"
#define STR_NUM_ASTERISK "\xbc"
#define STR_NUM_MINUS "\xbd"
#define STR_NUM_PLUS "\xbe"
#define STR_NUM_ENTER "\xbf"
#define STR_NUM_PERIOD "\xc0"
#define STR_NUM_EQUAL "\xc1"
#define STR_MEDIA_NEXT "\xc2"
#define STR_MEDIA_PREV "\xc3"
#define STR_MEDIA_STOP "\xc4"
#define STR_MEDIA_PAUSE "\xc5"
#define STR_MEDIA_MUTE "\xc6"
#define STR_MEDIA_VOLUP "\xc7"
#define STR_MEDIA_VOLDN "\xc8"
#define STR_MEDIA_WWW_HOME "\xc9"
#define STR_FILE_EXPLORER "\xca"
#define STR_MEDIA_CALC "\xcb"
#define STR_MEDIA_WWW_BOOKMARKS "\xcc"
#define STR_MEDIA_WWW_SEARCH "\xcd"
#define STR_MEDIA_WWW_STOP "\xce"
#define STR_MEDIA_WWW_BACK "\xcf"
#define STR_CONSUMER_CTL "\xd0"
#define STR_MEDIA_EMAIL "\xd1"


typedef struct
{
    uint8_t ID;
    uint8_t MODIFIER;
    uint8_t RESERVED;
    uint8_t KEYCODE[6];
} KeyboardHID_t;

typedef struct
{
    uint8_t ID;
    uint8_t KEYCODE[2];
} MediaHID_t;

uint32_t USBD_Keyboard_press(KeyboardHID_t* pKeyboardHid, MediaHID_t* pMediaHid, uint32_t k);
uint32_t USBD_Keyboard_release(KeyboardHID_t* pKeyboardHid, MediaHID_t* pMediaHid, uint32_t k);
void USBD_Keyboard_releaseAll(KeyboardHID_t* pKeyboardHid, MediaHID_t* pMediaHid);

size_t Media_Press(MediaHID_t* pMediaHid, const MediaKeyReport k);
size_t Media_Release(MediaHID_t* pMediaHid, const MediaKeyReport k);

uint32_t USBD_Keyboard_str_press(KeyboardHID_t* pKeyboardHid, MediaHID_t* pMediaHid, uint8_t k);
uint32_t USBD_Keyboard_str_release(KeyboardHID_t* pKeyboardHid, MediaHID_t* pMediaHid, uint8_t k);

#endif //KEYBOARD_MAP_H