#include "patcoll.h"
#ifdef COMBO_ENABLE
#include "g/keymap_combo.h"
#endif

bool is_win_switch_active = false;
bool is_alt_tab_active = false;
bool is_tab_switch_active = false;
#ifdef ENCODER_ENABLE
bool is_alt_tab_enc_active = false;
uint16_t alt_tab_enc_timer = 0;
#endif

void matrix_scan_user(void) {
  // End fancy nav switching if the NAV layer has been deactivated.
  if (is_win_switch_active && !IS_LAYER_ON(_NAV)) {
    unregister_code(KC_LGUI);
    is_win_switch_active = false;
  }
  if (is_alt_tab_active && !IS_LAYER_ON(_NAV)) {
    unregister_code(KC_LALT);
    is_alt_tab_active = false;
  }
  if (is_tab_switch_active && !IS_LAYER_ON(_NAV)) {
    unregister_code(KC_LCTL);
    is_tab_switch_active = false;
  }
# ifdef ENCODER_ENABLE
  if (is_alt_tab_enc_active) {
    if (timer_elapsed(alt_tab_enc_timer) > 750) {
      unregister_code(KC_LALT);
      is_alt_tab_enc_active = false;
    }
  }
# endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    if (keycode >= EX_PIPE && keycode <= EX_SEAR) {
      switch (keycode) {
        case EX_PIPE:
          SEND_STRING("|>");
          break;
        case EX_ARR:
          SEND_STRING("->");
          break;
        case EX_PAR:
          SEND_STRING("()");
          break;
        case EX_INSP:
          SEND_STRING("IO.inspect(");
          break;
        case EX_SEAR:
          SEND_STRING("elixir phoenix ");
          break;
      }
      return false;
    }

    switch (keycode) {
      // Super Alt-Tab
      case ALT_TAB:
      case SALTTAB:
        if (is_win_switch_active) {
          is_win_switch_active = false;
          unregister_code(KC_LGUI);
        }
        if (is_tab_switch_active) {
          is_tab_switch_active = false;
          unregister_code(KC_LCTL);
        }
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        keycode == ALT_TAB ? tap_code16(KC_TAB) : tap_code16(S(KC_TAB));
        return false;
    }
  }

  return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Shift
    case SFT_SPC:
    case SFT_ENT:
    case SFT_A:
    /* case SFT_E: */
    case SFT_V:
    /* case SFT_SCLN: */
    /* case SFT_QUOT: */
      return TAPPING_TERM - 12;
    case SFT_Z:
    case SFT_DOT:
    case SFT_M:
    case SFT_SLSH:
      return TAPPING_TERM - 20;
    default:
      return TAPPING_TERM;
  }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Shift
    case SFT_Z:
    case SFT_A:
    /* case SFT_E: */
    case SFT_V:
    case SFT_SPC:
    case SFT_ENT:
    case SFT_SCLN:
    case SFT_QUOT:
    case SFT_SLSH:
    case SFT_DOT:
    case SFT_M:
      return true;
    default:
      return false;
  }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    /* case LT(1, KC_BSPC): */
    /*   // Immediately select the hold action when another key is pressed. */
    /*   return true; */
    default:
      // Do not select the hold action when another key is pressed.
      return false;
  }
}
