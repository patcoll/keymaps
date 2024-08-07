#include "patcoll.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_wrapper(
  _________________QWERTY_L1_________________, KC_MUTE, _________________QWERTY_R1_________________,
  _________________QWERTY_L2_________________,          _________________QWERTY_R2_________________,
  _________________QWERTY_L3_________________,          _________________QWERTY_R3_________________,
  KC_LALT, SFT_SPC, RSE_ENT, KC_LCTL
),

[_GAMING] = LAYOUT_wrapper(
  _________________GAMING_L1_________________, _______, _________________GAMING_R1_________________,
  _________________GAMING_L2_________________,          _________________GAMING_R2_________________,
  _________________GAMING_L3_________________,          _________________GAMING_R3_________________,
  KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC
),

[_NAV] = LAYOUT_wrapper(
  __________________NAV_L1___________________, _______, __________________NAV_R1___________________,
  __________________NAV_L2___________________,          __________________NAV_R2___________________,
  __________________NAV_L3___________________,          __________________NAV_R3___________________,
  _______, ALT_TAB, ALT_TAB, _______
),

[_OSK] = LAYOUT_wrapper(
  __________________OSK_L1___________________, _______, __________________OSK_R1___________________,
  __________________OSK_L2___________________,          __________________OSK_R2___________________,
  __________________OSK_L3___________________,          __________________OSK_R3___________________,
  _______, _______, _______, _______
),

[_RAISE] = LAYOUT_wrapper(
  _________________RAISE_L1__________________, _______, _________________RAISE_R1__________________,
  _________________RAISE_L2__________________,          _________________RAISE_R2__________________,
  _________________RAISE_L3__________________,          _________________RAISE_R3__________________,
  _______, _______, _______, _______
),

[_MEDIA] = LAYOUT_wrapper(
  _________________MEDIA_L1__________________, _______, _________________MEDIA_R1__________________,
  _________________MEDIA_L2__________________,          _________________MEDIA_R2__________________,
  _________________MEDIA_L3__________________,          _________________MEDIA_R3__________________,
  _______, _______, _______, _______
),

[_MOUSE] = LAYOUT_wrapper(
  _________________MOUSE_L1__________________, _______, _________________MOUSE_R1__________________,
  _________________MOUSE_L2__________________,          _________________MOUSE_R2__________________,
  _________________MOUSE_L3__________________,          _________________MOUSE_R3__________________,
  KC_NO,   KC_BTN1, KC_BTN1, KC_BTN2
),
};
