#include QMK_KEYBOARD_H
#include "keymap_german.h"

enum {
  QWERTZ = 0,
  MOD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QWERTZ] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,_______   ,                        _______ ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,DE_ADIA ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_BSPC ,                          KC_DEL  ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,DE_EQL  ,DE_ODIA ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     DE_UNDS ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_LCTL ,KC_BSPC ,        KC_DEL  ,KC_RCTL ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,DE_SS   ,DE_UDIA ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     KC_LALT ,    KC_SPC  ,KC_LSFT ,        MO(MOD) ,KC_ENT  ,    KC_LGUI ,     _______ ,_______ ,_______  ,_______ 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),
  [MOD] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12  ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     DE_CIRC ,DE_QUOT ,DE_DQUO ,DE_LCBR ,DE_RCBR ,DE_GRV  ,RGB_MOD ,                          QK_BOOT,DE_PERC ,DE_PLUS ,DE_MINS ,DE_ASTR  ,DE_SLSH ,DE_BSLS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     DE_TILD ,DE_EXLM ,DE_DLR  ,DE_LPRN ,DE_RPRN ,DE_AMPR ,RGB_TOG ,                          _______ ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,DE_QUES ,DE_PIPE ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,DE_AT   ,DE_EURO ,DE_LBRC ,DE_RBRC ,_______ ,RGB_M_P ,_______ ,        _______ ,_______ ,DE_HASH ,DE_LABK ,DE_SCLN ,DE_COLN ,DE_RABK ,DE_SECT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______ 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )
};
