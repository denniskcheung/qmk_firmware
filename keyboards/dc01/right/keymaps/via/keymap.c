/* Copyright 2018 Yiancar
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_all( /* Base */
            KC_7,   KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
    KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
    KC_H,   KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
    KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH,          KC_RSFT, MO(1),
    KC_SPC,    KC_SPC,     KC_RALT, KC_RGUI,      KC_RGUI,    KC_RCTL),

[1] = LAYOUT_all( /* FN */
              KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,   KC_DEL,
    KC_TRNS,  KC_TRNS,  KC_PSCR,  KC_SCRL,  KC_PAUS,  KC_UP,    KC_TRNS,  KC_BSPC,
    KC_PAST,  KC_PSLS,  KC_HOME,  KC_PGUP,  KC_LEFT,  KC_RGHT,  KC_TRNS,  KC_PENT,
    KC_PPLS,  KC_PMNS,  KC_END,   KC_PGDN,  KC_DOWN,            KC_TRNS,  KC_TRNS,
    KC_TRNS,    KC_TRNS,     KC_TRNS, KC_TRNS,     KC_TRNS,             KC_TRNS),

[2] = LAYOUT_all( /* Empty for Dynamic keymap */
              KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,
    KC_TRNS,    KC_TRNS,     KC_TRNS, KC_TRNS,     KC_TRNS,             KC_TRNS),

[3] = LAYOUT_all( /* Empty for Dynamic keymap */
              KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,
    KC_TRNS,    KC_TRNS,     KC_TRNS, KC_TRNS,     KC_TRNS,             KC_TRNS)
};
