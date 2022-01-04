#include "patcoll.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_wrapper(
  KC_GRV,  ________________NUMBER_LEFT________________, ________________NUMBER_RIGHT_______________, KC_MINS, KC_EQL,  KC_BSPC, KC_PGUP,
  SFT_TAB, _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_LBRC, KC_RBRC, KC_BSLS, KC_PGDN,
  CTL_ESC, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, SFT_QUOT,KC_ENT,
  KC_LSFT, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, KC_RSFT,          KC_UP,
  KC_LCTL, KC_LGUI, KC_LALT, SFT_SPC,                                     KC_RALT, KC_RGUI, KC_HYPR,          KC_LEFT, KC_DOWN, KC_RGHT
),

[_NAV] = LAYOUT_wrapper(
  _______, _________________FUNC_LEFT_________________, _________________FUNC_RIGHT________________, _______, _______, _______, _______,
  KC_LSFT, __________________NAV_L1___________________, __________________NAV_R1___________________, _______, _______, _______, _______,
  KC_LCTL, __________________NAV_L2___________________, __________________NAV_R2___________________, _______, _______,
  _______, __________________NAV_L3___________________, __________________NAV_R3___________________, _______,          _______,
  _______, _______, _______, ALT_TAB,                                     _______, _______, _______,          _______, _______, _______
),

[_LOWER] = LAYOUT_wrapper(
  _______, _______________SYMBOLS_LEFT________________, _______________SYMBOLS_RIGHT_______________, _______, _______, _______, _______,
  KC_TILD, _________________LOWER_L1__________________, _________________LOWER_R1__________________, _______, _______, _______, _______,
  _______, _________________LOWER_L2__________________, _________________LOWER_R2__________________, _______, _______,
  _______, _________________LOWER_L3__________________, _________________LOWER_R3__________________, _______,          _______,
  _______, _______, _______, _______,                                     _______, _______, _______,          _______, _______, _______
),

[_RAISE] = LAYOUT_wrapper(
  _______, ________________NUMBER_LEFT________________, ________________NUMBER_RIGHT_______________, _______, _______, _______, _______,
  KC_GRV,  _________________RAISE_L1__________________, _________________RAISE_R1__________________, _______, _______, _______, _______,
  _______, _________________RAISE_L2__________________, _________________RAISE_R2__________________, _______, _______,
  _______, _________________RAISE_L3__________________, _________________RAISE_R3__________________, _______,          _______,
  _______, _______, _______, _______,                                     _______, _______, _______,          _______, _______, _______
),

[_MEDIA] = LAYOUT_wrapper(
  _______, ___________________BLANK___________________, ___________________BLANK___________________, _______, _______, _______, _______,
  _______, _________________MEDIA_L1__________________, _________________MEDIA_R1__________________, _______, _______, _______, _______,
  _______, _________________MEDIA_L2__________________, _________________MEDIA_R2__________________, _______, _______,
  _______, _________________MEDIA_L3__________________, _________________MEDIA_R3__________________, _______,          _______,
  _______, _______, _______, _______,                                     _______, _______, _______,          _______, _______, _______
),

[_MOUSE] = LAYOUT_wrapper(
  _______, ___________________BLANK___________________, ___________________BLANK___________________, _______, _______, _______, _______,
  _______, _________________MOUSE_L1__________________, _________________MOUSE_R1__________________, _______, _______, _______, _______,
  _______, _________________MOUSE_L2__________________, _________________MOUSE_R2__________________, _______, _______,
  _______, _________________MOUSE_L3__________________, _________________MOUSE_R3__________________, _______,          _______,
  _______, _______, KC_BTN1, KC_BTN1,                                     KC_BTN2, _______, _______,          _______, _______, _______
),
};
