#include QMK_KEYBOARD_H


enum uno_keycode
{
  UNO = SAFE_RANGE
};

static uint16_t pressTimer = 0xFFFF;
#define CUSTOM_LONGPRESS 1000

enum encoder_names {
	_ENCODER,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    UNO
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case UNO:
      if (record->event.pressed) {
        pressTimer = timer_read();
      } else {
        uint16_t timeElapsed = timer_elapsed(pressTimer);
        if (timeElapsed < CUSTOM_LONGPRESS) {
          register_code(KC_LALT);
          tap_code(KC_A);
          unregister_code(KC_LALT);
        } else {
          tap_code(KC_MUTE);
        }
      }
    break;
  }
  return false;
}

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == _ENCODER) { /* First encoder */
    if (clockwise) {
      tap_code(KC_AUDIO_VOL_UP);
    } else {
      tap_code(KC_AUDIO_VOL_DOWN);
    }
  }
}
