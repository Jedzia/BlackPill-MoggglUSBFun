//
// Created by Jedzia on 30.10.2019.
//

#include "usb.h"

extern USBD_HandleTypeDef hUsbDeviceFS;
uint8_t press_report[PRESS_REPORT_SIZE] = {0};

struct  keyinfo {
    uint8_t modifier;
    uint8_t keycode;
} keyInfo;

struct keyinfo message[] = {
        KEY_MOD_LSHIFT, KEY_1,
        KEY_MOD_NONE, KEY_SPACE,
        KEY_MOD_LSHIFT, KEY_M,
        KEY_MOD_NONE, KEY_O,
        KEY_MOD_NONE, KEY_G,
        KEY_MOD_NONE, KEY_G,
        KEY_MOD_NONE, KEY_G,
        KEY_MOD_NONE, KEY_L,
        KEY_MOD_NONE, KEY_SPACE,
        KEY_MOD_NONE, KEY_SPACE,
        KEY_MOD_NONE, KEY_SPACE,
        KEY_MOD_NONE, KEY_SPACE,
        KEY_MOD_NONE, KEY_SPACE,
        KEY_MOD_NONE, KEY_SPACE,
        KEY_MOD_NONE, KEY_SPACE,
        KEY_MOD_NONE, KEY_SPACE,
        KEY_MOD_NONE, KEY_SPACE,
        KEY_MOD_NONE, KEY_SPACE,
        KEY_MOD_NONE, KEY_SPACE,
        KEY_MOD_NONE, KEY_SPACE,
        KEY_MOD_NONE, KEY_SPACE,
        KEY_MOD_NONE, KEY_SPACE,
        };

void sendKey(char c) {

}

void sendMessage(uint index) {
    size_t size = sizeof(keyInfo)/sizeof(message[0]);
    index = index % 10;

    press_report[0] = message[index].modifier;
    press_report[2] = message[index].keycode; // send button press
    USBD_HID_SendReport(&hUsbDeviceFS, press_report, PRESS_REPORT_SIZE);
    HAL_Delay(50);

    /*press_report[0] = KEY_MOD_LSHIFT;
    press_report[2] = KEY_J; // send button press
    USBD_HID_SendReport(&hUsbDeviceFS, press_report, PRESS_REPORT_SIZE);
    HAL_Delay(50);*/

}
