/* Copyright 2021 qpockets
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

#define XXX KC_NO

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT_default( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k50, k51, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k60, k61, \
	k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k70, k71, \
	k30, k31, k32,           k35,      k37,      k39, k80, k81  \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k50, k51, }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k60, k61, }, \
	{ k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k70, k71, }, \
	{ k30, k31, k32, XXX, XXX, k35, XXX, k37, XXX, k39, k80, k81, } \
}

#define LAYOUT_625_bar( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k50, k51, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k60, k61, \
	k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k70, k71, \
	k30, k31, k32,                k36,           k39,      k81  \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k50, k51, }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k60, k61, }, \
	{ k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k70, k71, }, \
	{ k30, k31, k32, XXX, XXX, XXX, k36, XXX, XXX, k39, XXX, k81, } \
}

#define LAYOUT_2u_bars( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k50, k51, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k60, k61, \
	k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k70, k71, \
	k30, k31, k32,      k34, k35,      k37, k38, k39,      k81  \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k50, k51, }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k60, k61, }, \
	{ k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k70, k71, }, \
	{ k30, k31, k32, XXX, k34, k35, XXX, k37, k38, k39, XXX, k81, } \
}
