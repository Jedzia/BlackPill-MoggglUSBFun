//
// Created by Jedzia on 30.10.2019.
//

#ifndef SOFTWARE_USB_H
#define SOFTWARE_USB_H

#include <usbd_hid.h>
#include "usb_hid_keys.h"

#define PRESS_REPORT_SIZE 8

void sendKey(char c);
void sendMessage(uint index);

#endif //SOFTWARE_USB_H
