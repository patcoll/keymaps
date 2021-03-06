#include QMK_KEYBOARD_H
#include "patcoll.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_wrapper(
  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
  _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
  _________QWERTY_L3_FOUR________,    SFT_SPC, RSE_B,   KC_N,    SFT_M
),

[_NAV] = LAYOUT_wrapper(
  __________________NAV_L1___________________, __________________NAV_R1___________________,
  __________________NAV_L2___________________, __________________NAV_R2___________________,
  ___________NAV_L3_FOUR____________, _______, KC_PGDN, KC_PGUP, KC_HYPR
),

[_LOWER] = LAYOUT_wrapper(
  _________________LOWER_L1__________________, _________________LOWER_R1__________________,
  _________________LOWER_L2__________________, _________________LOWER_R2__________________,
  __________LOWER_L3_FOUR___________, _______, __LOWER_R3_TWO__, _______
),

[_RAISE] = LAYOUT_wrapper(
  _________________RAISE_L1__________________, _________________RAISE_R1__________________,
  _________________RAISE_L2__________________, _________________RAISE_R2__________________,
  __________RAISE_L3_FOUR___________, _______, __RAISE_R3_TWO__, _______
),

[_MEDIA] = LAYOUT_wrapper(
  _________________MEDIA_L1__________________, _________________MEDIA_R1__________________,
  _________________MEDIA_L2__________________, _________________MEDIA_R2__________________,
  __________MEDIA_L3_FOUR___________, _______, KC_VOLD, KC_VOLU, KC_MPLY
),

[_MOUSE] = LAYOUT_wrapper(
  _________________MOUSE_L1__________________, _________________MOUSE_R1__________________,
  _________________MOUSE_L2__________________, _________________MOUSE_R2__________________,
  __________MOUSE_L3_FOUR___________, KC_BTN1, KC_WH_D, KC_WH_U, _______
),
};
