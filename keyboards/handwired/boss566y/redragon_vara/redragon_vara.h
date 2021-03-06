/* Copyright 2020 boss566y
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

#define LAYOUT_fullsize_ansi( \
    K00,      K02, K03, K04, K05,   K07, K08, K09, K0A,    K6A, K69, K68, K67,  K66, K65, K64,                      \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K7A, K79, K78,       K76, K75, K74,  K73, K72, K71, K70, \
    K20,   K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K8A, K89, K87,     K86, K85, K84,  K83, K82, K81, K90, \
    K30,    K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K9A, K98,                         K93, K92, K91,      \
    K40,       K42, K43, K44, K45, K46, K47, K48, K49, K4A, KAA, KA8,                KA5,       KA3, KA2, KA1, KB0, \
    K50,  K51,  K53,              K56,                K5A,  KBA,  KB9,  KB7,    KB6, KB5, KB4,  KB3,      KB1       \
) { \
    { K00,   KC_NO, K02,   K03,   K04,   K05,   KC_NO, K07,   K08,   K09,   K0A   }, \
    { K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,   K1A   }, \
    { K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,   K2A   }, \
    { K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A   }, \
    { K40,   KC_NO, K42,   K43,   K44,   K45,   K46,   K47,   K48,   K49,   K4A   }, \
    { K50,   K51,   KC_NO, K53,   KC_NO, KC_NO, K56,   KC_NO, KC_NO, KC_NO, K5A   }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, K64,   K65,   K66,   K67,   K68,   K69,   K6A   }, \
    { K70,   K71,   K72,   K73,   K74,   K75,   K76,   KC_NO, K78,   K79,   K7A   }, \
    { KC_NO, K81,   K82,   K83,   K84,   K85,   K86,   K87,   KC_NO, K89,   K8A   }, \
    { K90,   K91,   K92,   K93,   KC_NO, KC_NO, KC_NO, KC_NO, K98,   KC_NO, K9A   }, \
    { KC_NO, KA1,   KA2,   KA3,   KC_NO, KA5,   KC_NO, KC_NO, KA8,   KC_NO, KAA   }, \
    { KB0,   KB1,   KC_NO, KB3,   KB4,   KB5,   KB6,   KB7,   KC_NO, KB9,   KBA   }, \
}
