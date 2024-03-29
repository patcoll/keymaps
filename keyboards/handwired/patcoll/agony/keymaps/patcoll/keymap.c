#include "patcoll.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_wrapper(
  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
  _________________QWERTY_L2_________________, _________QWERTY_R2_FOUR________,
  _________________QWERTY_L3_________________, KC_N,    KC_M,
  KC_LALT,  SFT_SPC,                  RSE_ENT, KC_LCTL
),

[_NAV] = LAYOUT_wrapper(
  __________________NAV_L1___________________, __________________NAV_R1___________________,
  __________________NAV_L2___________________, _____________NAV_R2_FOUR__________,
  __________________NAV_L3___________________, KC_MEH, KC_HYPR,
  _______, ALT_TAB,                   ALT_TAB, _______
),

[_OSK] = LAYOUT_wrapper(
  __________________OSK_L1___________________, __________________OSK_R1___________________,
  __________________OSK_L2___________________, _____________OSK_R2_FOUR__________,
  __________________OSK_L3___________________, _______, _______,
  _______, _______,                   _______,  _______
),

[_LOWER] = LAYOUT_wrapper(
  _________________LOWER_L1__________________, _________________LOWER_R1__________________,
  _________________LOWER_L2__________________, __________LOWER_R2_FOUR___________,
  _________________LOWER_L3__________________, __LOWER_R3_TWO__,
  _______, _______,                   _______,  _______
),

[_RAISE] = LAYOUT_wrapper(
  _________________RAISE_L1__________________, _________________RAISE_R1__________________,
  _________________RAISE_L2__________________, __________RAISE_R2_FOUR___________,
  _________________RAISE_L3__________________, __RAISE_R3_TWO__,
  _______, _______,                   _______,  _______
),

[_MEDIA] = LAYOUT_wrapper(
  _________________MEDIA_L1__________________, _________________MEDIA_R1__________________,
  _________________MEDIA_L2__________________, __________MEDIA_R2_FOUR___________,
  _________________MEDIA_L3__________________, __MEDIA_R3_TWO__,
  _______, _______,                   _______,  _______
),

[_MOUSE] = LAYOUT_wrapper(
  _________________MOUSE_L1__________________, _________________MOUSE_R1__________________,
  _________________MOUSE_L2__________________, __________MOUSE_R2_FOUR___________,
  _________________MOUSE_L3__________________, KC_BTN1, KC_BTN2,
  _______, KC_BTN1,                   KC_BTN1, KC_BTN2
),
};
