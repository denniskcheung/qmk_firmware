/*
Copyright 2022 <felix@fjlaboratories.com>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "quantum.h"

/*
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐      ┌───────┐
 * │00 │01 │02 │03 │04 │05 │06 │07 │08 │09 │0A │0B │0C │0D │2D │      │0D     │ 2u Backspace
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤      └───────┘
 * │10   │11 │12 │13 │14 │15 │16 │17 │18 │19 │1A │1B │1C │1D   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 * │20    │21 │22 │23 │24 │25 │26 │27 │28 │29 │2A │2B │2C      │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤   ┌──────────┐
 * │30      │32 │33 │34 │35 │36 │37 │38 │39 │3A │3B │3C    │3D │   │3C        │ 2.75u RShift
 * ├─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴───┴──┬────┴┬───┬─┴───┤   └──────────┘
 * │40   │   │42   │47                         │4B   │   │4D   │ WKL
 * └─────┘   └─────┴───────────────────────────┴─────┘   └─────┘
 */

#define LAYOUT_60_ansi_wkl( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2C, \
    K30,      K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,      K3C, \
    K40,      K42,                     K47,                K4B,      K4D  \
) { \
    { K00, K01,   K02, K03,   K04,     K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C,   K0D   }, \
    { K10, K11,   K12, K13,   K14,     K15,   K16,   K17,   K18,   K19,   K1A,   K1B,   K1C,   K1D   }, \
    { K20, K21,   K22, K23,   K24,     K25,   K26,   K27,   K28,   K29,   K2A,   K2B,   K2C,   KC_NO }, \
    { K30, KC_NO, K32, K33,   K34,     K35,   K36,   K37,   K38,   K39,   K3A,   K3B,   K3C,   KC_NO }, \
    { K40, KC_NO, K42, KC_NO, KC_NO,   KC_NO, KC_NO, K47,   KC_NO, KC_NO, KC_NO, K4B,   KC_NO, K4D   }  \
}

#define LAYOUT_60_ansi_wkl_split_bs_rshift( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K2D, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2C, \
    K30,      K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, \
    K40,      K42,                     K47,                K4B,      K4D  \
) { \
    { K00, K01,   K02, K03,   K04,     K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C,   K0D }, \
    { K10, K11,   K12, K13,   K14,     K15,   K16,   K17,   K18,   K19,   K1A,   K1B,   K1C,   K1D }, \
    { K20, K21,   K22, K23,   K24,     K25,   K26,   K27,   K28,   K29,   K2A,   K2B,   K2C,   K2D }, \
    { K30, KC_NO, K32, K33,   K34,     K35,   K36,   K37,   K38,   K39,   K3A,   K3B,   K3C,   K3D }, \
    { K40, KC_NO, K42, KC_NO, KC_NO,   KC_NO, KC_NO, K47,   KC_NO, KC_NO, KC_NO, K4B,   KC_NO, K4D }  \
}
