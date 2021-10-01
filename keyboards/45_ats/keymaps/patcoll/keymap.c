#include "patcoll.h"

#define LAYOUT_wrapper(...) LAYOUT_split_space(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_wrapper(
  SFT_TAB, _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_BSPC, KC_BSPC, KC_BSPC,
  CTL_ESC, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, SFT_QUOT,         KC_PGUP,
  KC_LSFT, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, KC_UP,            KC_PGDN,
  KC_LCTL, KC_LGUI, KC_LALT, SFT_SPC,                   RSE_ENT, KC_LCTL, KC_HYPR, __QWERTY_R3_ARROW_KEYS__
),

[_NAV] = LAYOUT_wrapper(
  KC_LSFT, __________________NAV_L1___________________, __________________NAV_R1___________________, CS_BSPC, _______, _______,
  KC_LCTL, __________________NAV_L2___________________, __________________NAV_R2___________________, KC_BSLS,          _______,
  KC_LSFT, __________________NAV_L3___________________, __________________NAV_R3___________________, _______,          _______,
  _______, _______, _______, _______,                   ALT_TAB, _______, _______, __NAV_R4_ARROW_KEYS___
),

[_LOWER] = LAYOUT_wrapper(
  KC_TILDE,_________________LOWER_L1__________________, _________________LOWER_R1__________________, _______, _______, _______,
  _______, _________________LOWER_L2__________________, _________________LOWER_R2__________________, KC_PIPE,          _______,
  _______, _________________LOWER_L3__________________, _________________LOWER_R3__________________, _______,          _______,
  _______, _______, _______, _______,                   _______, _______, _______, __LOWER_R4_ARROW_KEYS__
),

[_RAISE] = LAYOUT_wrapper(
  KC_GRV,  _________________RAISE_L1__________________, _________________RAISE_R1__________________, _______, _______, _______,
  _______, _________________RAISE_L2__________________, _________________RAISE_R2__________________, KC_BSLS,          _______,
  _______, _________________RAISE_L3__________________, _________________RAISE_R3__________________, _______,          _______,
  _______, _______, _______, _______,                   _______, _______, _______, __RAISE_R3_ARROW_KEYS__
),

[_MEDIA] = LAYOUT_wrapper(
  _______, _________________MEDIA_L1__________________, _________________MEDIA_R1__________________, _______, _______, _______,
  _______, _________________MEDIA_L2__________________, _________________MEDIA_R2__________________, _______,          _______,
  _______, _________________MEDIA_L3__________________, _________________MEDIA_R3__________________, _______,          _______,
  _______, _______, _______, _______,                   _______, _______, _______, __MEDIA_R3_ARROW_KEYS__
),

[_MOUSE] = LAYOUT_wrapper(
  _______, _________________MOUSE_L1__________________, _________________MOUSE_R1__________________, KC_PSCR, _______, _______,
  _______, _________________MOUSE_L2__________________, _________________MOUSE_R2__________________, _______,          _______,
  _______, _________________MOUSE_L3__________________, _________________MOUSE_R3__________________, _______,          _______,
  _______, KC_BTN1, KC_BTN1, KC_BTN1,                   KC_BTN1, KC_BTN2, _______, __MOUSE_R3_ARROW_KEYS__
),
};
