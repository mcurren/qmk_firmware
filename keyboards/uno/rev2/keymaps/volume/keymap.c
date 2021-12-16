#include QMK_KEYBOARD_H

enum uno_keycode
{
  UNO = LGUI(KC_D)
};

// static uint16_t pressTimer = 0xFFFF;
// #define CUSTOM_LONGPRESS 1000

enum encoder_names {
	_ENCODER,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    UNO
  )
};

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == _ENCODER) { /* First encoder */
    if (clockwise) {
      tap_code(KC__VOLUP);
    } else {
      tap_code(KC__VOLDOWN);
    }
  }
}