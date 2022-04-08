#ifndef KEYBOARD_MAP_H
#define KEYBOARD_MAP_H

#include "usbd_hid.h"
#include "stdint.h"

#define KEY_LEFT_CTRL ((uint16_t)0x101)
#define KEY_LEFT_SHIFT ((uint16_t)0x102)
#define KEY_LEFT_ALT ((uint16_t)0x104)
#define KEY_LEFT_GUI ((uint16_t)0x108)
#define KEY_RIGHT_CTRL ((uint16_t)0x110)
#define KEY_RIGHT_SHIFT ((uint16_t)0x120)
#define KEY_RIGHT_ALT ((uint16_t)0x140)
#define KEY_RIGHT_GUI ((uint16_t)0x180)

#define KEY_UP_ARROW ((uint16_t)0x0252)
#define KEY_DOWN_ARROW ((uint16_t)0x0251)
#define KEY_LEFT_ARROW ((uint16_t)0x0250)
#define KEY_RIGHT_ARROW ((uint16_t)0x024f)
#define KEY_BACKSPACE ((uint16_t)0x022a)
#define KEY_TAB ((uint16_t)0x022b)
#define KEY_RETURN ((uint16_t)0x0228)
#define KEY_ESC ((uint16_t)0x0229)
#define KEY_INSERT ((uint16_t)0x0249)
#define KEY_PRTSC ((uint16_t)0x0246)
#define KEY_DELETE ((uint16_t)0x024c)
#define KEY_PAGE_UP ((uint16_t)0x024b)
#define KEY_PAGE_DOWN ((uint16_t)0x024e)
#define KEY_HOME ((uint16_t)0x024a)
#define KEY_END ((uint16_t)0x024d)
#define KEY_CAPS_LOCK ((uint16_t)0x0239)
#define KEY_F1 ((uint16_t)0x023a)
#define KEY_F2 ((uint16_t)0x023b)
#define KEY_F3 ((uint16_t)0x023c)
#define KEY_F4 ((uint16_t)0x023d)
#define KEY_F5 ((uint16_t)0x023e)
#define KEY_F6 ((uint16_t)0x023f)
#define KEY_F7 ((uint16_t)0x0240)
#define KEY_F8 ((uint16_t)0x0241)
#define KEY_F9 ((uint16_t)0x0242)
#define KEY_F10 ((uint16_t)0x0243)
#define KEY_F11 ((uint16_t)0x0244)
#define KEY_F12 ((uint16_t)0x0245)
#define KEY_PRTSC ((uint16_t)0x0246)
#define KEY_F13 ((uint16_t)0x0268)
#define KEY_F14 ((uint16_t)0x0269)
#define KEY_F15 ((uint16_t)0x026a)
#define KEY_F16 ((uint16_t)0x026b)
#define KEY_F17 ((uint16_t)0x026c)
#define KEY_F18 ((uint16_t)0x026d)
#define KEY_F19 ((uint16_t)0x026e)
#define KEY_F20 ((uint16_t)0x026f)
#define KEY_F21 ((uint16_t)0x0270)
#define KEY_F22 ((uint16_t)0x0271)
#define KEY_F23 ((uint16_t)0x0272)
#define KEY_F24 ((uint16_t)0x0273)
#define KEY_NUM_0 ((uint16_t)0x62)
#define KEY_NUM_1 ((uint16_t)0x59)
#define KEY_NUM_2 ((uint16_t)0x5a)
#define KEY_NUM_3 ((uint16_t)0x5b)
#define KEY_NUM_4 ((uint16_t)0x5c)
#define KEY_NUM_5 ((uint16_t)0x5d)
#define KEY_NUM_6 ((uint16_t)0x5e)
#define KEY_NUM_7 ((uint16_t)0x5f)
#define KEY_NUM_8 ((uint16_t)0x60)
#define KEY_NUM_9 ((uint16_t)0x61)
#define KEY_NUM_SLASH ((uint16_t)0x54)
#define KEY_NUM_ASTERISK ((uint16_t)0x55)
#define KEY_NUM_MINUS ((uint16_t)0x56)
#define KEY_NUM_PLUS ((uint16_t)0x57)
#define KEY_NUM_ENTER ((uint16_t)0x58)
#define KEY_NUM_PERIOD ((uint16_t)0x63)

#define KEY_MEDIA_NEXT ((uint16_t)0x80B5) 
#define KEY_MEDIA_PREV ((uint16_t)0x80B6) 
#define KEY_MEDIA_STOP ((uint16_t)0x80B7)
#define KEY_MEDIA_EJECT ((uint16_t)0x80B8)
#define KEY_MEDIA_MUTE ((uint16_t)0x80E2)
#define KEY_MEDIA_PAUSE ((uint16_t)0x80CD)
#define KEY_MEDIA_VOLUP ((uint16_t)0x80E9)
#define KEY_MEDIA_VOLDN ((uint16_t)0x80EA)

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