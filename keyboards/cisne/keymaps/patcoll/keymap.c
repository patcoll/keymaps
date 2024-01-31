#include QMK_KEYBOARD_H
#include "patcoll.h"

#define LAYOUT_wrapper(...) LAYOUT_0(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_wrapper(
  SFT_TAB, _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, CS_BSPC,
  CTL_ESC, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, CTL_SCLN,
  KC_LSFT, _________________QWERTY_L3_________________, KC_NO,   _________________QWERTY_R3_________________, KC_LSFT,
  KC_LGUI, KC_LALT, SFT_SPC,          RSE_ENT, KC_LCTL, KC_HYPR, KC_MEH
),

[_GAMING] = LAYOUT_wrapper(
  _______, _________________GAMING_L1_________________, _________________GAMING_R1_________________, _______,
  _______, _________________GAMING_L2_________________, _________________GAMING_R2_________________, _______,
  _______, _________________GAMING_L3_________________, _______, _________________GAMING_R3_________________, KC_LSFT,
  _______, _______, KC_SPC,           KC_ENT,  _______, _______, _______
),

[_NAV] = LAYOUT_wrapper(
  KC_LSFT, __________________NAV_L1___________________, __________________NAV_R1___________________, _______,
  KC_LCTL, __________________NAV_L2___________________, __________________NAV_R2___________________, _______,
  KC_LSFT, __________________NAV_L3___________________, _______, __________________NAV_R3___________________, _______,
  _______, _______, ALT_TAB,          ALT_TAB, _______, _______, _______
),

[_OSK] = LAYOUT_wrapper(
  _______, __________________OSK_L1___________________, __________________OSK_R1___________________, _______,
  _______, __________________OSK_L2___________________, __________________OSK_R2___________________, _______,
  _______, __________________OSK_L3___________________, _______, __________________OSK_R3___________________, _______,
  _______, _______, _______,          _______, _______, _______, _______
),

[_LOWER] = LAYOUT_wrapper(
  KC_TILDE,_________________LOWER_L1__________________, _________________LOWER_R1__________________, _______,
  _______, _________________LOWER_L2__________________, _________________LOWER_R2__________________, _______,
  _______, _________________LOWER_L3__________________, _______, _________________LOWER_R3__________________, _______,
  _______, _______, _______,          _______, _______, _______, _______
),

[_RAISE] = LAYOUT_wrapper(
  KC_GRV,  _________________RAISE_L1__________________, _________________RAISE_R1__________________, _______,
  _______, _________________RAISE_L2__________________, _________________RAISE_R2__________________, KC_RBRC,
  _______, _________________RAISE_L3__________________, _______, _________________RAISE_R3__________________, _______,
  _______, _______, _______,          _______, _______, _______, _______
),

[_MEDIA] = LAYOUT_wrapper(
  _______, _________________MEDIA_L1__________________, _________________MEDIA_R1__________________, _______,
  _______, _________________MEDIA_L2__________________, _________________MEDIA_R2__________________, _______,
  _______, _________________MEDIA_L3__________________, _______, _________________MEDIA_R3__________________, _______,
  _______, _______, _______,          _______, _______, _______, _______
),

[_MOUSE] = LAYOUT_wrapper(
  _______, _________________MOUSE_L1__________________, _________________MOUSE_R1__________________, _______,
  _______, _________________MOUSE_L2__________________, _________________MOUSE_R2__________________, _______,
  _______, _________________MOUSE_L3__________________, _______, _________________MOUSE_R3__________________, _______,
  KC_BTN1, KC_BTN1, KC_BTN1,          KC_BTN1, KC_BTN2, _______, _______
),
};