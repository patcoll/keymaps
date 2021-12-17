#include "patcoll.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_wrapper(
  SFT_TAB, _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, CS_BSPC,
  CTL_ESC, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, SFT_QUOT,
  KC_LSFT, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, KC_LSFT,
  _______, KC_LCTL, KC_LGUI, KC_LALT, SFT_SPC, SFT_SPC, RSE_ENT, RSE_ENT, KC_LCTL, __QWERTY_R4_NORMAL_KEYS_
),

[_NAV] = LAYOUT_wrapper(
  _______, __________________NAV_L1___________________, __________________NAV_R1___________________, _______,
  _______, __________________NAV_L2___________________, __________________NAV_R2___________________, _______,
  _______, __________________NAV_L3___________________, __________________NAV_R3___________________, _______,
  _______, _______, _______, _______, _______, _______, ALT_TAB, ALT_TAB, _______, _______, _______, _______
),

[_LOWER] = LAYOUT_wrapper(
  _______, _________________LOWER_L1__________________, _________________LOWER_R1__________________, _______,
  _______, _________________LOWER_L2__________________, _________________LOWER_R2__________________, _______,
  _______, _________________LOWER_L3__________________, _________________LOWER_R3__________________, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT_wrapper(
  _______, _________________RAISE_L1__________________, _________________RAISE_R1__________________, _______,
  _______, _________________RAISE_L2__________________, _________________RAISE_R2__________________, _______,
  _______, _________________RAISE_L3__________________, _________________RAISE_R3__________________, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_MEDIA] = LAYOUT_wrapper(
  _______, _________________MEDIA_L1__________________, _________________MEDIA_R1__________________, _______,
  _______, _________________MEDIA_L2__________________, _________________MEDIA_R2__________________, _______,
  _______, _________________MEDIA_L3__________________, _________________MEDIA_R3__________________, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_MOUSE] = LAYOUT_wrapper(
  _______, _________________MOUSE_L1__________________, _________________MOUSE_R1__________________, _______,
  _______, _________________MOUSE_L2__________________, _________________MOUSE_R2__________________, _______,
  _______, _________________MOUSE_L3__________________, _________________MOUSE_R3__________________, _______,
  _______, _______, _______, _______, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN2, _______, _______, _______
),
};