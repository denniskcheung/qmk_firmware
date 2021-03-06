/* Copyright 2021 Koobaczech
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

/*
 * This layout covers all of the possible build layouts. Also, any
 * built layouts will work without having to change anything.
*/

#pragma once

#include "quantum.h"

#define LAYOUT_all( \
  k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, \
  k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
  k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
  k30, k31, k32, k33, k34, k35, k36 \
){ \
  { k00,  k01,  k02,  k03,  k04,  k05,  k06,  k07,    k08,    k09,    k0a,    k0b,    k0c},    \
  { k10,  k11,  k12,  k13,  k14,  k15,  k16,  k17,    k18,    k19,    k1a,    k1b,    KC_NO},  \
  { k20,  k21,  k22,  k23,  k24,  k25,  k26,  k27,    k28,    k29,    k2a,    k2b,    KC_NO},  \
  { k30,  k31,  k32,  k33,  k34,  k35,  k36,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO}   \
}
