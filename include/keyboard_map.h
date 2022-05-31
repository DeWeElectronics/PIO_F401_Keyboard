#ifndef KEYBOARD_MAP_H
#define KEYBOARD_MAP_H

#include "usbd_hid.h"
#include "stdint.h"

#define SHIFT                ((uint16_t)0x0300U)
#define KEY_TYPE_MASK        ((uint16_t)0xff00)

#define KEY_TYPE_MODIF      ((uint16_t)0x0100)
#define KEY_TYPE_NONPRINT   ((uint16_t)0x0200)
#define KEY_TYPE_MEDIA      ((uint16_t)0x8000)

#define KEY_LEFT_CTRL       (KEY_TYPE_MODIF | (uint16_t)0x01)
#define KEY_LEFT_SHIFT      (KEY_TYPE_MODIF | (uint16_t)0x02)
#define KEY_LEFT_ALT        (KEY_TYPE_MODIF | (uint16_t)0x04)
#define KEY_LEFT_GUI        (KEY_TYPE_MODIF | (uint16_t)0x08)
#define KEY_RIGHT_CTRL      (KEY_TYPE_MODIF | (uint16_t)0x10)
#define KEY_RIGHT_SHIFT     (KEY_TYPE_MODIF | (uint16_t)0x20)
#define KEY_RIGHT_ALT       (KEY_TYPE_MODIF | (uint16_t)0x40)
#define KEY_RIGHT_GUI       (KEY_TYPE_MODIF | (uint16_t)0x80)

#define KEY_UP_ARROW        (KEY_TYPE_NONPRINT | (uint16_t)0x0052)
#define KEY_DOWN_ARROW      (KEY_TYPE_NONPRINT | (uint16_t)0x0051)
#define KEY_LEFT_ARROW      (KEY_TYPE_NONPRINT | (uint16_t)0x0050)
#define KEY_RIGHT_ARROW     (KEY_TYPE_NONPRINT | (uint16_t)0x004f)
#define KEY_BACKSPACE       (KEY_TYPE_NONPRINT | (uint16_t)0x002a)
#define KEY_TAB             (KEY_TYPE_NONPRINT | (uint16_t)0x002b)
#define KEY_RETURN          (KEY_TYPE_NONPRINT | (uint16_t)0x0028)
#define KEY_ESC             (KEY_TYPE_NONPRINT | (uint16_t)0x0029)
#define KEY_INSERT          (KEY_TYPE_NONPRINT | (uint16_t)0x0049)
#define KEY_PRTSC           (KEY_TYPE_NONPRINT | (uint16_t)0x0046)
#define KEY_DELETE          (KEY_TYPE_NONPRINT | (uint16_t)0x004c)
#define KEY_PAGE_UP         (KEY_TYPE_NONPRINT | (uint16_t)0x004b)
#define KEY_PAGE_DOWN       (KEY_TYPE_NONPRINT | (uint16_t)0x004e)
#define KEY_HOME            (KEY_TYPE_NONPRINT | (uint16_t)0x004a)
#define KEY_END             (KEY_TYPE_NONPRINT | (uint16_t)0x004d)
#define KEY_CAPS_LOCK       (KEY_TYPE_NONPRINT | (uint16_t)0x0039)
#define KEY_F1              (KEY_TYPE_NONPRINT | (uint16_t)0x003a)
#define KEY_F2              (KEY_TYPE_NONPRINT | (uint16_t)0x003b)
#define KEY_F3              (KEY_TYPE_NONPRINT | (uint16_t)0x003c)
#define KEY_F4              (KEY_TYPE_NONPRINT | (uint16_t)0x003d)
#define KEY_F5              (KEY_TYPE_NONPRINT | (uint16_t)0x003e)
#define KEY_F6              (KEY_TYPE_NONPRINT | (uint16_t)0x003f)
#define KEY_F7              (KEY_TYPE_NONPRINT | (uint16_t)0x0040)
#define KEY_F8              (KEY_TYPE_NONPRINT | (uint16_t)0x0041)
#define KEY_F9              (KEY_TYPE_NONPRINT | (uint16_t)0x0042)
#define KEY_F10             (KEY_TYPE_NONPRINT | (uint16_t)0x0043)
#define KEY_F11             (KEY_TYPE_NONPRINT | (uint16_t)0x0044)
#define KEY_F12             (KEY_TYPE_NONPRINT | (uint16_t)0x0045)
#define KEY_PRTSC           (KEY_TYPE_NONPRINT | (uint16_t)0x0046)
#define KEY_F13             (KEY_TYPE_NONPRINT | (uint16_t)0x0068)
#define KEY_F14             (KEY_TYPE_NONPRINT | (uint16_t)0x0069)
#define KEY_F15             (KEY_TYPE_NONPRINT | (uint16_t)0x006a)
#define KEY_F16             (KEY_TYPE_NONPRINT | (uint16_t)0x006b)
#define KEY_F17             (KEY_TYPE_NONPRINT | (uint16_t)0x006c)
#define KEY_F18             (KEY_TYPE_NONPRINT | (uint16_t)0x006d)
#define KEY_F19             (KEY_TYPE_NONPRINT | (uint16_t)0x006e)
#define KEY_F20             (KEY_TYPE_NONPRINT | (uint16_t)0x006f)
#define KEY_F21             (KEY_TYPE_NONPRINT | (uint16_t)0x0070)
#define KEY_F22             (KEY_TYPE_NONPRINT | (uint16_t)0x0071)
#define KEY_F23             (KEY_TYPE_NONPRINT | (uint16_t)0x0072)
#define KEY_F24             (KEY_TYPE_NONPRINT | (uint16_t)0x0073)

#define KEY_NUM_0           ((uint16_t)0x0062)
#define KEY_NUM_1           ((uint16_t)0x0059)
#define KEY_NUM_2           ((uint16_t)0x005a)
#define KEY_NUM_3           ((uint16_t)0x005b)
#define KEY_NUM_4           ((uint16_t)0x005c)
#define KEY_NUM_5           ((uint16_t)0x005d)
#define KEY_NUM_6           ((uint16_t)0x005e)
#define KEY_NUM_7           ((uint16_t)0x005f)
#define KEY_NUM_8           ((uint16_t)0x0060)
#define KEY_NUM_9           ((uint16_t)0x0061)
#define KEY_NUM_SLASH       ((uint16_t)0x0054)
#define KEY_NUM_ASTERISK    ((uint16_t)0x0055)
#define KEY_NUM_MINUS       ((uint16_t)0x0056)
#define KEY_NUM_PLUS        ((uint16_t)0x0057)
#define KEY_NUM_ENTER       ((uint16_t)0x0058)
#define KEY_NUM_PERIOD      ((uint16_t)0x0063)

#define KEY_MEDIA_NEXT      (KEY_TYPE_MEDIA | (uint16_t)0x00B5) 
#define KEY_MEDIA_PREV      (KEY_TYPE_MEDIA | (uint16_t)0x00B6) 
#define KEY_MEDIA_STOP      (KEY_TYPE_MEDIA | (uint16_t)0x00B7)
#define KEY_MEDIA_EJECT     (KEY_TYPE_MEDIA | (uint16_t)0x00B8)
#define KEY_MEDIA_MUTE      (KEY_TYPE_MEDIA | (uint16_t)0x00E2)
#define KEY_MEDIA_PAUSE     (KEY_TYPE_MEDIA | (uint16_t)0x00CD)
#define KEY_MEDIA_VOLUP     (KEY_TYPE_MEDIA | (uint16_t)0x00E9)
#define KEY_MEDIA_VOLDN     (KEY_TYPE_MEDIA | (uint16_t)0x00EA)

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

extern uint16_t keys[];
extern uint16_t keys_alternate[];


uint32_t USBD_Keyboard_press(KeyboardHID_t* pKeyboardHid, MediaHID_t* pMediaHid, uint16_t k);
uint32_t USBD_Keyboard_release(KeyboardHID_t* pKeyboardHid, MediaHID_t* pMediaHid, uint16_t k);
void USBD_Keyboard_releaseAll(KeyboardHID_t* pKeyboardHid, MediaHID_t* pMediaHid);


#endif //KEYBOARD_MAP_H