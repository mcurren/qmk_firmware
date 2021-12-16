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
// #include "remote_kb.h"
#include "bitc_led.h"

#define _BASE     0
#define _VIA1     1
#define _VIA2     2
#define _VIA3     3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
        KC_F1,   KC_F2, KC_F3, \
  KC_7, KC_8,     KC_9, KC_PSLS, \
  KC_4, KC_5,     KC_6, KC_PAST, \
  KC_1, KC_2,     KC_3, KC_PMNS, \
  KC_0, KC_DOT, KC_ENT, KC_PPLS  \
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

void encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
}

void matrix_init_user(void) {
    // matrix_init_remote_kb();
    set_bitc_LED(LED_OFF);
}

#include "qmk_oled.c"

// void oled_init_user(void) { // << doesn't work
//     render_logo();
//     fade_display();
// }
