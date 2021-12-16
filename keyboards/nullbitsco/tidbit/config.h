#pragma once

#include "config_common.h"

/* Used to set slave for remote KB if VUSB detect doesn't work. */
// #define KEYBOARD_SLAVE

/* USB Device descriptor parameter */
#define VENDOR_ID       0x6E61
#define PRODUCT_ID      0x6061
#define DEVICE_VER      0x0001
#define MANUFACTURER    nullbits
#define PRODUCT         TIDBIT
#define DESCRIPTION     QMK keyboard firmware
/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 4

/* key matrix pins */
#define MATRIX_ROW_PINS { B1, E6, D7, C6, D4 }
#define MATRIX_COL_PINS { F4, F5, F6, F7 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

/* Optional SMT LED pins */
#define RGB_DI_PIN B6
#define RGBLED_NUM 8
#define RGBLIGHT_ANIMATIONS

/* Additional optional encoder pins */

// #define ENCODERS_PAD_A { D1, D0 } //Can only be used if I2C is not used - encoder #3 spot
// #define ENCODERS_PAD_B { D3, D2 } //Can only be used if serial (exp) is not used - encoder #4 spot

/* for mac sleep issues */
#define NO_USB_STARTUP_CHECK

// #define OLED_FONT_H "font.c"
// #define OLED_FONT_WIDTH 15
// #define OLED_FONT_HEIGHT 23
// #define OLED_FONT_START 32
// #define OLED_FONT_END 224
