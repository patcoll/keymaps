#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_7u_space(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, KC_BSPC, KC_DEL,
        KC_HOME, KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT,           KC_PGUP,
        KC_END,  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RSFT,          KC_PGDN,
        MO(_FN), KC_LCTL, KC_LGUI,                            KC_SPC,                             KC_RALT, KC_RCTL, KC_MUTE
    ),

    [_FN] = LAYOUT_7u_space(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,  KC_DEL,  _______,
        _______, KC_TILD, _______, _______, _______, _______, _______, _______, KC_SCLN, KC_QUOT, KC_BSLS, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_SLSH, KC_LBRC, KC_RBRC, KC_UP,            _______,
        _______, _______, _______,                            _______,                            KC_LEFT, KC_DOWN, KC_RGHT
    )

};
