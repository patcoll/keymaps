#include "patcoll.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_wrapper(
  KC_ESC,  ________________NUMBER_LEFT________________, ________________NUMBER_RIGHT_______________, KC_DEL,
  KC_TAB,  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_BSPC,
  CTL_ESC, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, KC_QUOT,
  KC_LSFT, _________________QWERTY_L3_________________, KC_N,    KC_M,    KC_COMM, KC_UP,   KC_LSFT,
  KC_LCTL, KC_LGUI, KC_LALT, SFT_SPC,                   RSE_ENT, __QWERTY_R4_ARROW_KEYS__
),

[_GAMING] = LAYOUT_wrapper(
  _______, ___________________BLANK___________________, ___________________BLANK___________________, _______,
  _______, _________________GAMING_L1_________________, _________________GAMING_R1_________________, _______,
  _______, _________________GAMING_L2_________________, _________________GAMING_R2_________________, _______,
  _______, _________________GAMING_L3_________________, _________________GAMING_R3_________________,
  _______, _______, _______, KC_SPC,                    KC_ENT, __GAMING_R4_ARROW_KEYS__
),

[_NAV] = LAYOUT_wrapper(
  _______, ___________________BLANK___________________, ___________________BLANK___________________, _______,
  _______, __________________NAV_L1___________________, __________________NAV_R1___________________, CS_BSPC,
  KC_LCTL, __________________NAV_L2___________________, __________________NAV_R2___________________, KC_BSLS,
  KC_LSFT, __________________NAV_L3___________________, __________________NAV_R3___________________,
  _______, _______, _______, ALT_TAB,                   ALT_TAB, __NAV_R4_ARROW_KEYS___
),

[_OSK] = LAYOUT_wrapper(
  _______, ___________________BLANK___________________, ___________________BLANK___________________, _______,
  _______, __________________OSK_L1___________________, __________________OSK_R1___________________, _______,
  _______, __________________OSK_L2___________________, __________________OSK_R2___________________, _______,
  _______, __________________OSK_L3___________________, __________________OSK_R3___________________,
  _______, _______, _______, _______,                   _______, __OSK_R4_ARROW_KEYS___
),

[_RAISE] = LAYOUT_wrapper(
  _______, ___________________BLANK___________________, ___________________BLANK___________________, _______,
  KC_GRV,  _________________RAISE_L1__________________, _________________RAISE_R1__________________, _______,
  _______, _________________RAISE_L2__________________, _________________RAISE_R2__________________, KC_BSLS,
  _______, _________________RAISE_L3__________________, _________________RAISE_R3__________________,
  _______, _______, _______, _______,                   _______, __RAISE_R3_ARROW_KEYS__
),

[_MEDIA] = LAYOUT_wrapper(
  _______, ___________________BLANK___________________, ___________________BLANK___________________, _______,
  _______, _________________MEDIA_L1__________________, _________________MEDIA_R1__________________, _______,
  _______, _________________MEDIA_L2__________________, _________________MEDIA_R2__________________, _______,
  _______, _________________MEDIA_L3__________________, _________________MEDIA_R3__________________,
  _______, _______, _______, _______,                   _______, __MEDIA_R3_ARROW_KEYS__
),

[_MOUSE] = LAYOUT_wrapper(
  _______, ___________________BLANK___________________, ___________________BLANK___________________, _______,
  _______, _________________MOUSE_L1__________________, _________________MOUSE_R1__________________, KC_PSCR,
  _______, _________________MOUSE_L2__________________, _________________MOUSE_R2__________________, _______,
  _______, _________________MOUSE_L3__________________, _________________MOUSE_R3__________________,
  _______, KC_BTN1, KC_BTN1, KC_BTN1,                   KC_BTN1, __MOUSE_R3_ARROW_KEYS__
),
};

/* #<{(| Copyright 2020 LAZYDESIGNERS */
/*  * */
/*  * This program is free software: you can redistribute it and/or modify */
/*  * it under the terms of the GNU General Public License as published by */
/*  * the Free Software Foundation, either version 2 of the License, or */
/*  * (at your option) any later version. */
/*  * */
/*  * This program is distributed in the hope that it will be useful, */
/*  * but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*  * GNU General Public License for more details. */
/*  * */
/*  * You should have received a copy of the GNU General Public License */
/*  * along with this program.  If not, see <http://www.gnu.org/licenses/>. */
/*  |)}># */
/* #include QMK_KEYBOARD_H */
/*  */
/* #define LT2_TAB LT(2, KC_TAB) */
/* #define LT1_SPC LT(1, KC_SPC) */
/*  */
/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { */
/*     [0] = LAYOUT( */
/*         KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, */
/*         KC_GRV,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, */
/*         LT2_TAB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, */
/*         KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_UP,   MO(2), */
/*         KC_LCTL,   KC_LALT, KC_LGUI, LT1_SPC,          KC_SPC,           KC_LEFT, KC_DOWN, KC_RGHT */
/*     ), */
/*     [1] = LAYOUT( */
/*         QK_BOOT,     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  QK_BOOT, */
/*         KC_TILD,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS, */
/*         KC_NO,     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,  KC_SCLN, KC_SLSH, */
/*         KC_NO,     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_NO,   KC_NO,   KC_NO,   KC_DOT,  KC_NO, */
/*         RGB_TOG,   RGB_MOD, KC_NO,   KC_NO,            KC_NO,            KC_NO,   KC_NO,   KC_QUOT */
/*     ), */
/*     [2] = LAYOUT( */
/*         KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, */
/*         KC_NO,     KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, */
/*         KC_NO,     KC_NO,   KC_NO,   KC_DEL,  KC_NO,   KC_NO,   KC_LCBR, KC_RCBR, KC_UNDS, KC_PLUS, KC_COLN, KC_QUES, */
/*         KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_LABK, KC_RABK, KC_NO, */
/*         KC_NO,     KC_NO,   KC_NO,   KC_NO,            KC_NO,            KC_NO,   KC_NO,   KC_DQUO */
/*     ), */
/* }; */
