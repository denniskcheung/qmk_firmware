/* Copyright 2019-2021 iw0rm3r, tiltowait
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

/* This a shortcut to help you visually see your layout.
 * The first section contains "names" for physical keys of the keyboard
 * and defines their position on the board.
 * The second section defines position of the keys on the switch matrix 
 * (where COLUMNS and ROWS crosses). */

#define LAYOUT( \
    K5A,      K5B, K5C, K5D, K5E, K5F, K5G, K5H, K5I, K5J, K5K, K5L, K5M,   K5N, K5O, K5P, \
    \
    K4A, K4B, K4C, K4D, K4E, K4F, K4G, K4H, K4I, K4J, K4K, K4L, K4M, K4N,   K4O, K4P, K4Q, \
    K3A, K3B, K3C, K3D, K3E, K3F, K3G, K3H, K3I, K3J, K3K, K3L, K3M, K3N,   K3O, K3P, K3Q, \
    K2A, K2B, K2C, K2D, K2E, K2F, K2G, K2H, K2I, K2J, K2K, K2L, K2M, K2N,                  \
    K1A, K1B, K1C, K1D, K1E, K1F, K1G, K1H, K1I, K1J, K1K, K1L,      K1M,        K1N,      \
    K0A,      K0B,                K0C,                     K0D,      K0E,   K0F, K0G, K0H  \
) \
{ \
/* 00 */ { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, K1G,   K0C,   K1H,   KC_NO, KC_NO, K1L,   K0G,   K0H,   KC_NO, K0F,   K0D   }, \
/* 01 */ { K0E,   K1M,   K1C,   K1D,   K1E,   K1F,   K2N,   K1I,   K1J,   K1K,   KC_NO, KC_NO, KC_NO, KC_NO, K5P,   KC_NO }, \
/* 02 */ { KC_NO, KC_NO, K2B,   K2C,   K2D,   K2E,   K3N,   K2H,   K2I,   K2J,   K2K,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
/* 03 */ { KC_NO, KC_NO, K3B,   K3C,   K3D,   K3E,   KC_NO, K3H,   K3I,   K3J,   K3K,   KC_NO, KC_NO, KC_NO, KC_NO, K5O   }, \
/* 04 */ { KC_NO, KC_NO, K4B,   K4C,   K4D,   K4E,   K5K,   K4H,   K4I,   K4J,   K4K,   K5L,   K5M,   K3Q,   K3P,   K5N   }, \
/* 05 */ { K0A,   KC_NO, K4A,   K5B,   K5C,   K4F,   K5J,   K4G,   K4M,   K5I,   K4L,   K3O,   K4O,   K4Q,   K4P,   KC_NO }, \
/* 06 */ { KC_NO, K1A,   K3A,   K2A,   K5D,   K3F,   K4N,   K3G,   K3M,   K5H,   K3L,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
/* 07 */ { KC_NO, KC_NO, K5A,   KC_NO, K5E,   K2F,   K5F,   K2G,   K5G,   KC_NO, K2L,   KC_NO, KC_NO, KC_NO, K1N,   K0B   }, \
}
/*         0      1      2      3      4      5      6      7      8      9      A      B      C      D      E      F       */
