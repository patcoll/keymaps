#include "patcoll.h"

bool scroll_pressed = false;

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_wrapper(
  _________________QWERTY_L1_________________, KC_VOLU, _________________QWERTY_R1_________________,
  _________________QWERTY_L2_________________, KC_VOLD, _________________QWERTY_R2_________________,
  _________________QWERTY_L3_________________,          _________________QWERTY_R3_________________,
  _______, KC_LALT, SFT_SPC, RSE_ENT, KC_LCTL, _______
),

[_GAMING] = LAYOUT_wrapper(
  _________________GAMING_L1_________________, _______, _________________GAMING_R1_________________,
  _________________GAMING_L2_________________, _______, _________________GAMING_R2_________________,
  _________________GAMING_L3_________________,          _________________GAMING_R3_________________,
  _______, KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  _______
),

[_NAV] = LAYOUT_wrapper(
  __________________NAV_L1___________________, _______, __________________NAV_R1___________________,
  __________________NAV_L2___________________, _______, __________________NAV_R2___________________,
  __________________NAV_L3___________________,          __________________NAV_R3___________________,
  _______, ALT_TAB, ALT_TAB, ALT_TAB, ALT_TAB, _______
),

[_OSK] = LAYOUT_wrapper(
  __________________OSK_L1___________________, _______, __________________OSK_R1___________________,
  __________________OSK_L2___________________, _______, __________________OSK_R2___________________,
  __________________OSK_L3___________________,          __________________OSK_R3___________________,
  _______, _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT_wrapper(
  _________________RAISE_L1__________________, _______, _________________RAISE_R1__________________,
  _________________RAISE_L2__________________, _______, _________________RAISE_R2__________________,
  _________________RAISE_L3__________________,          _________________RAISE_R3__________________,
  _______, _______, _______, _______, _______, _______
),

[_MEDIA] = LAYOUT_wrapper(
  _________________MEDIA_L1__________________, KC_VOLU, _________________MEDIA_R1__________________,
  _________________MEDIA_L2__________________, KC_VOLD, _________________MEDIA_R2__________________,
  _________________MEDIA_L3__________________,          _________________MEDIA_R3__________________,
  _______, _______, _______, _______, _______, _______
),

[_MOUSE] = LAYOUT_wrapper(
  _________________MOUSE_L1__________________, _______, _________________MOUSE_R1__________________,
  _________________MOUSE_L2__________________, _______, _________________MOUSE_R2__________________,
  _________________MOUSE_L3__________________,          _________________MOUSE_R3__________________,
  _______, KC_NO,   KC_BTN1, KC_BTN1, KC_BTN2, _______
),
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MOUSESCROLL:
      if (record->event.pressed) {
        scroll_pressed = true;
        layer_on(_MOUSE);
      } else {
        scroll_pressed = false;
        layer_off(_MOUSE);
      }
      return false;
    default:
      return true; // Process all other keycodes normally
  }
}
