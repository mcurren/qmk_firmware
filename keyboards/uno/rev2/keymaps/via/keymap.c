#include QMK_KEYBOARD_H

enum encoder_names {
	_ENCODER,
};

// define layer count for encoder to loop over
#define LAYER_COUNT 4

// add a layout for each defined layer
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_1
    ),
    [1] = LAYOUT(
        KC_2
    ),
    [2] = LAYOUT(
        KC_3
    ),
    [3] = LAYOUT(
        KC_4
    )
};

// set LED to unique RBG color based on 2 numbers
void uno_calc_color(uint32_t index, uint32_t max) {
    rgblight_sethsv_noeeprom((255/max)*index, 255, 255);
}

// mutable layer counter variable
uint8_t layerIndex = 0;

// set RGB when keyboard boots up
void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    // rgblight_sethsv_noeeprom((255/LAYER_COUNT)*layerIndex, 255, 255);
    uno_calc_color(layerIndex, LAYER_COUNT);
    rgblight_mode_noeeprom(1);
}

// encoder turn switches layers
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == _ENCODER) {
        if (clockwise) {
            layerIndex++;
            layerIndex %= LAYER_COUNT;
        } else {
            layerIndex += LAYER_COUNT;
            layerIndex--;
            layerIndex %= LAYER_COUNT;
        }
        // change current layer/layout
        layer_move(layerIndex);
        // change rgb to visually indicate layer
        // rgblight_sethsv_noeeprom((255/LAYER_COUNT)*layerIndex, 255, 255);
        uno_calc_color(layerIndex, LAYER_COUNT);
        rgblight_mode_noeeprom(1);
    }
}
