/* Copyright 2020 Jay Greco
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "remote_kb.h"
#include "bitc_led.h"

// custom keycodes
enum custom_keycodes {
    MAGNET_THIRD_LEFT,
    MAGNET_THIRD_MIDDLE,
    MAGNET_THIRD_RIGHT,
};


// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//     case MAGNET_THIRD_LEFT:
//         if (record->event.pressed) {
//             // when keycode MAGNET_THIRD_LEFT is pressed
//             SS_DOWN(X_LCTL);
//             SS_DOWN(X_LALT);
//             SEND_STRING("d");
//         } else {
//             // when keycode MAGNET_THIRD_LEFT is released
//             SS_UP(X_LCTL);
//             SS_UP(X_LALT);
//         }
//         break;
//     case MAGNET_THIRD_MIDDLE:
//         if (record->event.pressed) {
//             // when keycode MAGNET_THIRD_MIDDLE is pressed
//             SEND_STRING(SS_LALT(SS_LCTL("f")));
//         } else {
//             // when keycode MAGNET_THIRD_MIDDLE is released
//         }
//         break;
//     case MAGNET_THIRD_RIGHT:
//         if (record->event.pressed) {
//             // when keycode MAGNET_THIRD_RIGHT is pressed
//             SEND_STRING(SS_LALT(SS_LCTL("g")));
//         } else {
//             // when keycode MAGNET_THIRD_RIGHT is released
//         }
//         break;
//     }
//     return true;
// };

// // custom combos
// enum combos {
//   MAGNET_TWO_THIRDS_LEFT,
//   MAGNET_TWO_THIRDS_RIGHT,
// };

// const uint16_t PROGMEM magnet_2_3_left_combo[] = {MAGNET_THIRD_MIDDLE, MAGNET_THIRD_LEFT, COMBO_END};
// const uint16_t PROGMEM magnet_2_3_right_combo[] = {MAGNET_THIRD_MIDDLE, MAGNET_THIRD_RIGHT, COMBO_END};

// combo_t key_combos[COMBO_COUNT] = {
//   [MAGNET_TWO_THIRDS_LEFT] = COMBO_ACTION(magnet_2_3_left_combo),
//   [MAGNET_TWO_THIRDS_RIGHT] = COMBO_ACTION(magnet_2_3_right_combo),
// };

// void process_combo_event(uint16_t combo_index, bool pressed) {
//   switch(combo_index) {
//     case MAGNET_TWO_THIRDS_LEFT:
//       if (pressed) {
//         tap_code16(LCTL(LALT(KC_E)));
//       }
//       break;
//     case MAGNET_TWO_THIRDS_RIGHT:
//       if (pressed) {
//         tap_code16(LCTL(LALT(KC_T)));
//       }
//       break;
//   }
// }

// layers
#define _BASE     0
#define _VIA1     1
#define _VIA2     2
#define _VIA3     3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
            MO(1), MO(2), MO(3), \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_TRNS, KC_TRNS, MAGNET_THIRD_RIGHT, \
    KC_TRNS, KC_TRNS, KC_TRNS, MAGNET_THIRD_MIDDLE, \
    KC_TRNS, KC_TRNS, KC_TRNS, MAGNET_THIRD_LEFT  \
    ),

    [_VIA1] = LAYOUT(
            KC_TRNS, KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS  \
    ),

    [_VIA2] = LAYOUT(
            KC_TRNS, KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS  \
    ),

    [_VIA3] = LAYOUT(
            KC_TRNS, KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS  \
    ),
};

// rotary encoders
void encoder_update_user(uint8_t index, bool clockwise) {
  /* With an if statement we can check which encoder was turned. */
  if (index == 0) { /* First encoder */
    /* And with another if statement we can check the direction. */
    if (clockwise) {
      tap_code(KC_F19);
    } else {
      /* And likewise for the other direction, this time Page Down is pressed. */
      tap_code(KC_F20);
    }
  } else if (index == 1) { /* Second encoder */
    /* NOTE: this encoder needs to be manually reversed */
    if (clockwise) {
      tap_code(KC_F22);
    } else {
      tap_code(KC_F21);
    }
  } else if (index == 2) { /* Third encoder */
    /* NOTE: this encoder cannot be used with OLED enabled!!!! */
    /* NOTE: this encoder needs to be manually reversed */
    if (clockwise) {
      tap_code(KC_F24);
    } else {
      tap_code(KC_F23);
    }
  } else if (index == 3) { /* Fourth encoder */
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  }
}

// lighting layer variables
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 8, HSV_YELLOW});
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 8, HSV_CYAN});
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 8, HSV_BLUE});
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layer1_layer,    // Overrides base layer
    my_layer2_layer,    // Overrides other layers
    my_layer3_layer     // Overrides other layers
);

// Enable the LED layers
void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

// assign the rgb layers
layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _VIA1));
    rgblight_set_layer_state(1, layer_state_cmp(state, _VIA2));
    rgblight_set_layer_state(2, layer_state_cmp(state, _VIA3));
    return state;
}

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     process_record_remote_kb(keycode, record);
//     return true;
// }

// void matrix_scan_user(void) {
//     matrix_scan_remote_kb();
// }

void matrix_init_user(void) {
    // matrix_init_remote_kb();
    set_bitc_LED(LED_OFF);
}

// #include "qmk_oled.c" // OLED not compatible with 4 encoders

// void oled_init_user(void) { // << doesn't work
//     render_logo();
//     fade_display();
// }
