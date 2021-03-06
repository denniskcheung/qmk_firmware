#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //,---------------------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     KC_TAB,               KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,          KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINUS,
  //|---------------------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     MT(MOD_LCTL, KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LCBR,          KC_RCBR, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //|---------------------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_LSFT,              KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_NO,            KC_NO,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  //|---------------------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     ADJUST,               ADJUST,  KC_LALT,  KC_LGUI,           LOWER,   KC_SPC,           KC_BSPC, RAISE,            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  //`---------------------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),

  [_LOWER] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,          _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,          _______,  KC_Y, KC_UNDS, KC_PLUS,  KC_LCBR, KC_RCBR, KC_PIPE,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_CAPS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______,          _______,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______,          _______, _______,          _______, RAISE,           _______, _______,  _______, _______
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),


  [_RAISE] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,          _______,  KC_6,    KC_7,    KC_8,    KC_9, KC_0,    KC_DEL,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,          _______,  KC_Y,    KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,          _______,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______,          _______, _______,          _______, RAISE,            _______, _______, _______, _______
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),

  [_ADJUST] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,            KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, QK_BOOT,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______,          _______, _______,          _______, RAISE,            _______, _______, _______, _______
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  )

};







bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
