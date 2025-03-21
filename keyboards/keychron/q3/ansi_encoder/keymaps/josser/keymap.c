/* Copyright 2022 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"

enum custom_keycodes_josser { PAGE_ZOOMIN = SAFE_RANGE, PAGE_ZOOMOUT, PAGE_ZOOMRST };

enum layers { MAC_BASE, MAC_FN, WIN_BASE, WIN_FN, EXT };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [MAC_BASE] = LAYOUT_tkl_f13_ansi(
      KC_ESC,  KC_F1,      KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,      KC_F9,      KC_F10,     KC_F11,  KC_F12,  KC_MUTE,       KC_SNAP,    KC_SIRI,    RGB_MOD,
      KC_GRV,  KC_1,       KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,       KC_9,       KC_0,       KC_MINS, KC_EQL,  KC_BSPC,       KC_INS,     KC_HOME,    KC_PGUP,
      KC_TAB,  KC_Q,       KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,       KC_O,       KC_P,       KC_LBRC, KC_RBRC, KC_BSLS,       KC_DEL,     KC_END,     KC_PGDN,
      KC_CAPS, KC_A,       KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,       KC_L,       KC_SCLN,    KC_QUOT,          KC_ENT,
      KC_LSFT, KC_Z,       KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,    KC_DOT,     KC_SLSH,                      KC_RSFT,                   KC_UP,
      KC_LCTL, KC_LOPTN,   KC_LCMMD,                           KC_SPC,                       KC_RCMMD,   KC_ROPTN,   MO(MAC_FN),       MO(EXT),       KC_LEFT,    KC_DOWN,    KC_RGHT
   ),

   [MAC_FN] = LAYOUT_tkl_f13_ansi(
      _______, KC_BRID,    KC_BRIU, KC_MCTL, KC_LPAD, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY,    KC_MNXT,    KC_MUTE,    KC_VOLD, KC_VOLU, RGB_TOG,       _______,    _______,    RGB_TOG,
      _______, _______,    _______, _______, _______, _______, _______, _______, _______,    _______,    _______,    _______, _______, _______,       _______,    _______,    _______,
      RGB_TOG, RGB_MOD,    RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______,    _______,    _______,    _______, _______, _______,       _______,    _______,    _______,
      _______, RGB_RMOD,   RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______,    _______,    _______,    _______,          _______,
      _______, _______,    _______, _______, _______, _______, NK_TOGG, _______, _______,    _______,    _______,                      _______,                   _______,
      _______, _______,    _______,                            _______,                      _______,    _______,    _______,          _______,       _______,    _______,    _______
   ),

   [WIN_BASE] = LAYOUT_tkl_f13_ansi(
      KC_ESC,  KC_F1,      KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,      KC_F9,      KC_F10,     KC_F11,  KC_F12,  KC_MUTE,       KC_PSCR,    KC_CRTA,    RGB_MOD,
      KC_GRV,  KC_1,       KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,       KC_9,       KC_0,       KC_MINS, KC_EQL,  KC_BSPC,       KC_INS,     KC_HOME,    KC_PGUP,
      KC_TAB,  KC_Q,       KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,       KC_O,       KC_P,       KC_LBRC, KC_RBRC, KC_BSLS,       KC_DEL,     KC_END,     KC_PGDN,
      KC_CAPS, KC_A,       KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,       KC_L,       KC_SCLN,    KC_QUOT,          KC_ENT,
      KC_LSFT, KC_Z,       KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,    KC_DOT,     KC_SLSH,                      KC_RSFT,                   KC_UP,
      KC_LCTL, KC_LWIN,    KC_LALT,                            KC_SPC,                       KC_RALT,    KC_RWIN,    MO(WIN_FN),       MO(EXT),       KC_LEFT,    KC_DOWN,    KC_RGHT
   ),

   [WIN_FN] = LAYOUT_tkl_f13_ansi(
      _______, KC_BRID,    KC_BRIU, KC_TASK, KC_FLXP, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY,    KC_MNXT,    KC_MUTE,    KC_VOLD, KC_VOLU, RGB_TOG,       _______,    _______,    RGB_TOG,
      _______, _______,    _______, _______, _______, _______, _______, _______, _______,    _______,    _______,    _______, _______, _______,       _______,    _______,    _______,
      RGB_TOG, RGB_MOD,    RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______,    _______,    _______,    _______, _______, _______,       _______,    _______,    _______,
      _______, RGB_RMOD,   RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______,    _______,    _______,    _______,          _______,
      _______, _______,    _______, _______, _______, _______, NK_TOGG, _______, _______,    _______,    _______,                      _______,                   _______,
      _______, _______,    _______,                            _______,                      _______,    _______,    _______,          _______,       _______,    _______,    _______
   ),

   [EXT] = LAYOUT_tkl_f13_ansi(
      _______, _______,    _______, _______, _______, _______, _______, _______, _______,    _______,    _______,    _______, _______, PAGE_ZOOMRST,  _______,    _______,    EE_CLR,
      _______, _______,    _______, _______, _______, _______, _______, _______, _______,    _______,    _______,    _______, _______, _______,       _______,    _______,    _______,
      _______, QK_MAKE,    _______, _______, _______, _______, _______, _______, _______,    _______,    _______,    _______, _______, _______,       _______,    _______,    _______,
      _______, _______,    _______, _______, _______, _______, _______, _______, _______,    _______,    _______,    _______,          _______,
      _______, _______,    _______, _______, _______, _______, _______, _______, _______,    _______,    _______,                      _______,                   _______,
      _______, _______,    _______,                            KC_SPC,                       _______,    _______,    _______,          _______,       _______,    _______,    _______
   )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
   [MAC_BASE] = {
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
   },
   [MAC_FN] = {
      ENCODER_CCW_CW(RGB_VAD, RGB_VAI)
   },
   [WIN_BASE] = {
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
   },
   [WIN_FN] = {
      ENCODER_CCW_CW(RGB_VAD, RGB_VAI)
   },
   [EXT] = {
      ENCODER_CCW_CW(PAGE_ZOOMOUT, PAGE_ZOOMIN)
   }
};
#endif // ENCODER_MAP_ENABLE

void housekeeping_task_user(void) {
    housekeeping_task_keychron();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case PAGE_ZOOMIN:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("="));
            }
            break;

        case PAGE_ZOOMOUT:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("-"));
            }
            break;

        case PAGE_ZOOMRST:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("0"));
            }
            break;
    }

    return true;
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (get_highest_layer(layer_state) > 0) {
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED && keymap_key_to_keycode(layer, (keypos_t){col, row}) > KC_TRNS) {
                    rgb_matrix_set_color(index, 5, 30, 68);
                }
            }
        }
    }
    return true;
}
