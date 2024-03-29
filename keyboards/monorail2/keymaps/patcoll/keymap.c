#include "patcoll.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_wrapper(
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
  SFT_TAB, _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, CS_BSPC,
  CTL_ESC, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, SFT_QUOT,
  KC_LSFT, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, SFT_SLSH,
  KC_LCTL, KC_LGUI, KC_LALT, SFT_SPC, SFT_SPC,          RSE_ENT, KC_LCTL, __QWERTY_R4_NORMAL_KEYS_
),

[_GAMING] = LAYOUT_wrapper(
  _______, _______, _______,_______, _______, _______,
  _______, _________________GAMING_L1_________________, _________________GAMING_R1_________________, _______,
  _______, _________________GAMING_L2_________________, _________________GAMING_R2_________________, _______,
  _______, _________________GAMING_L3_________________, _________________GAMING_R3_________________, KC_LSFT,
  _______, _______, _______, KC_SPC,  KC_SPC,           KC_ENT,  _______, __GAMING_R4_NORMAL_KEYS_
),

[_NAV] = LAYOUT_wrapper(
  _______, _______, _______,_______, _______, _______,
  KC_LSFT, __________________NAV_L1___________________, __________________NAV_R1___________________, CS_BSPC,
  KC_LCTL, __________________NAV_L2___________________, __________________NAV_R2___________________, KC_BSLS,
  KC_LSFT, __________________NAV_L3___________________, __________________NAV_R3___________________, _______,
  _______, _______, _______, ALT_TAB, ALT_TAB,          ALT_TAB, _______, __NAV_R4_ARROW_KEYS___
),

[_OSK] = LAYOUT_wrapper(
  _______, _______, _______,_______, _______, _______,
  _______, __________________OSK_L1___________________, __________________OSK_R1___________________, _______,
  _______, __________________OSK_L2___________________, __________________OSK_R2___________________, _______,
  _______, __________________OSK_L3___________________, __________________OSK_R3___________________, _______,
  _______, _______, _______, _______, _______,          _______, _______, __OSK_R4_ARROW_KEYS___
),

[_LOWER] = LAYOUT_wrapper(
  _______, _______, _______,_______, _______, _______,
  KC_TILDE,_________________LOWER_L1__________________, _________________LOWER_R1__________________, _______,
  _______, _________________LOWER_L2__________________, _________________LOWER_R2__________________, KC_PIPE,
  _______, _________________LOWER_L3__________________, _________________LOWER_R3__________________, _______,
  _______, _______, _______, _______, _______,          _______, _______, __LOWER_R4_ARROW_KEYS__
),

[_RAISE] = LAYOUT_wrapper(
  _______, _______, _______,_______, _______, _______,
  KC_GRV,  _________________RAISE_L1__________________, _________________RAISE_R1__________________, _______,
  _______, _________________RAISE_L2__________________, _________________RAISE_R2__________________, KC_BSLS,
  _______, _________________RAISE_L3__________________, _________________RAISE_R3__________________, _______,
  _______, _______, _______, _______, _______,          _______, _______, __RAISE_R3_ARROW_KEYS__
),

[_MEDIA] = LAYOUT_wrapper(
  _______, _______, _______,_______, _______, _______,
  _______, _________________MEDIA_L1__________________, _________________MEDIA_R1__________________, _______,
  _______, _________________MEDIA_L2__________________, _________________MEDIA_R2__________________, _______,
  _______, _________________MEDIA_L3__________________, _________________MEDIA_R3__________________, _______,
  _______, _______, _______, _______, _______,          _______, _______, __MEDIA_R3_ARROW_KEYS__
),

[_MOUSE] = LAYOUT_wrapper(
  _______, _______, _______,_______, _______, _______,
  _______, _________________MOUSE_L1__________________, _________________MOUSE_R1__________________, KC_PSCR,
  _______, _________________MOUSE_L2__________________, _________________MOUSE_R2__________________, _______,
  _______, _________________MOUSE_L3__________________, _________________MOUSE_R3__________________, _______,
  _______, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1,          KC_BTN1, KC_BTN2, __MOUSE_R3_ARROW_KEYS__
),
};

bool led_update_keymap(led_t led_state) {
  setPinOutput(LED0_PIN);
  setPinOutput(LED1_PIN);
  setPinOutput(LED2_PIN);

  writePin(LED0_PIN, 0);
  writePin(LED1_PIN, 0);
  writePin(LED2_PIN, 0);

  return true;
}
