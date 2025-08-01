#include "patcoll.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_wrapper(
  SFT_TAB, _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_BSPC, _______,
  CTL_ESC, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,          _______,
  KC_LSFT, _________________QWERTY_L3_________________, _________________QWERTY_R3_ARROWS__________,          _______,
  KC_LGUI, KC_LALT, SFT_SPC, SFT_SPC,                   RSE_ENT, KC_LCTL, __QWERTY_R4_ARROW_KEYS__
),

[_GAMING] = LAYOUT_wrapper(
  _______, _________________GAMING_L1_________________, _________________GAMING_R1_________________, _______, _______,
  _______, _________________GAMING_L2_________________, _________________GAMING_R2_________________,          _______,
  _______, _________________GAMING_L3_________________, _________________GAMING_R3_ARROWS__________,          _______,
  _______, _______, KC_SPC,  KC_SPC,                    KC_SPC,  _______, __GAMING_R4_ARROW_KEYS__
),

[_NAV] = LAYOUT_wrapper(
  KC_LSFT, __________________NAV_L1___________________, __________________NAV_R1___________________, _______, _______,
  KC_LCTL, __________________NAV_L2___________________, __________________NAV_R2___________________,          _______,
  KC_LSFT, __________________NAV_L3___________________, __________________NAV_R3___________________,          _______,
  _______, _______, ALT_TAB, ALT_TAB,                   ALT_TAB, _______, __NAV_R4_ARROW_KEYS___
),

[_OSK] = LAYOUT_wrapper(
  _______, __________________OSK_L1___________________, __________________OSK_R1___________________, _______, _______,
  _______, __________________OSK_L2___________________, __________________OSK_R2___________________,          _______,
  _______, __________________OSK_L3___________________, __________________OSK_R3___________________,          _______,
  _______, _______, _______, _______,                   _______, _______, __OSK_R4_ARROW_KEYS___
),

[_RAISE] = LAYOUT_wrapper(
  _______, _________________RAISE_L1__________________, _________________RAISE_R1__________________, _______, _______,
  _______, _________________RAISE_L2__________________, _________________RAISE_R2__________________,          _______,
  _______, _________________RAISE_L3__________________, _________________RAISE_R3__________________,          _______,
  _______, _______, _______, _______,                   _______, _______, __RAISE_R3_ARROW_KEYS__
),

[_MEDIA] = LAYOUT_wrapper(
  _______, _________________MEDIA_L1__________________, _________________MEDIA_R1__________________, _______, _______,
  _______, _________________MEDIA_L2__________________, _________________MEDIA_R2__________________,          _______,
  _______, _________________MEDIA_L3__________________, _________________MEDIA_R3__________________,          _______,
  _______, _______, _______, _______,                   _______, _______, __MEDIA_R3_ARROW_KEYS__
),

[_MOUSE] = LAYOUT_wrapper(
  _______, _________________MOUSE_L1__________________, _________________MOUSE_R1__________________, _______, _______,
  _______, _________________MOUSE_L2__________________, _________________MOUSE_R2__________________,          _______,
  _______, _________________MOUSE_L3__________________, _________________MOUSE_R3__________________,          _______,
  _______, _______, KC_BTN1, KC_BTN1,                   KC_BTN1, KC_BTN2, __MOUSE_R3_ARROW_KEYS__
),
};

// /* Encoder */
// const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
//     [0] = { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO)   },
//     [1] = { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO)   },
//     [2] = { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO)   },
//     [3] = { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO)   },
//     [4] = { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO)   }
// };
