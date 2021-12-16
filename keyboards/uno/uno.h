/* Copyright 2020 Snipeye
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
#pragma once

#include "quantum.h"

#ifdef KEYBOARD_uno_rev1
    #include "rev1/rev1.h"
#elif KEYBOARD_uno_rev2
    #include "rev2/rev2.h"
#endif

#include "via.h" // only for EEPROM address
#define EEPROM_ENABLED_ENCODER_MODES (VIA_EEPROM_CUSTOM_CONFIG_ADDR)

enum encoder_modes {
  ENC_MODE_VOLUME,
  ENC_MODE_BRIGHTNESS,
  ENC_MODE_CUSTOM0,
  ENC_MODE_CUSTOM1,
  ENC_MODE_CUSTOM2,
};

enum custom_encoder_behavior {
  ENC_CUSTOM_CW = 0,
  ENC_CUSTOM_CCW,
  ENC_CUSTOM_PRESS
};

// Encoder Behavior
extern uint8_t encoder_value;
extern uint8_t encoder_mode;
extern uint8_t enabled_encoder_modes;

void pre_encoder_mode_change(void);
void post_encoder_mode_change(void);
void change_encoder_mode(bool negative);
uint16_t handle_encoder_clockwise(void);
uint16_t handle_encoder_ccw(void);
uint16_t handle_encoder_press(void);
uint16_t retrieve_custom_encoder_config(uint8_t encoder_idx, uint8_t behavior);
void set_custom_encoder_config(uint8_t encoder_idx, uint8_t behavior, uint16_t new_code);
