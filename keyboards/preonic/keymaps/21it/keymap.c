/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  EM_SRG,
  EM_LEN,
  EM_FLP,
  EM_FIN,
  EM_FIX
};

enum unicode_names {
    // Small Spanish letters
    AC_SA,
    AC_SE,
    AC_SI,
    AC_SO,
    AC_SU,
    TI_SN,
    DI_SU,
    // Capital Spanish letters
    AC_CA,
    AC_CE,
    AC_CI,
    AC_CO,
    AC_CU,
    TI_CN,
    DI_CU,
    // Ohter Spanish symbols
    REV_Q,
    REV_E
};

const uint32_t PROGMEM unicode_map[] = {
    // Small Spanish letters
    [AC_SA] = 0x00E1, // á
    [AC_SE] = 0x00E9, // é
    [AC_SI] = 0x00ED, // í
    [AC_SO] = 0x00F3, // ó
    [AC_SU] = 0x00FA, // ú
    [TI_SN] = 0x00F1, // ñ
    [DI_SU] = 0x00FC, // ü
    // Capital Spanish letters
    [AC_CA] = 0x00C1, // Á
    [AC_CE] = 0x00C9, // É
    [AC_CI] = 0x00CD, // Í
    [AC_CO] = 0x00D3, // Ó
    [AC_CU] = 0x00DA, // Ú
    [TI_CN] = 0x00D1, // Ñ
    [DI_CU] = 0x00DC, // Ü
    // Ohter Spanish symbols
    [REV_Q] = 0x00BF, // ¿
    [REV_E] = 0x00A1  // ¡
};

#define AC_A XP(AC_SA, AC_CA)
#define AC_E XP(AC_SE, AC_CE)
#define AC_I XP(AC_SI, AC_CI)
#define AC_O XP(AC_SO, AC_CO)
#define AC_U XP(AC_SU, AC_CU)
#define TI_N XP(TI_SN, TI_CN)
#define DI_U XP(DI_SU, DI_CU)
#define ES_Q XP(REV_Q, REV_Q)
#define ES_E XP(REV_E, REV_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Lower|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  |Raise | Alt  |Space |Space |Space |Space |AltGr | GUI  |Adjust|  =   |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  LOWER,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  KC_LCTL, KC_LGUI, RAISE,   KC_LALT, KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_ALGR, KC_RGUI, ADJUST,  KC_EQL
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |   -  |   =  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Ins  | Del  |   [  |   ]  |   `  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      | Left | Down | Up   | Rght |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      | Home | PgDn | PgUp | End  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  _______,
  _______, _______, _______, _______, _______, _______, _______, KC_INS,  KC_DEL,  KC_LBRC, KC_RBRC, KC_GRV,
  _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |   ¡  |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |   é  |      |      |   ü  |   ú  |   í  |   ó  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   á  |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |   ñ  |      |      |      |   ¿  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
  _______, ES_E,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, AC_E,    _______, _______, DI_U,    AC_U,    AC_I,    AC_O,    _______, _______,
  _______, AC_A,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, TI_N,    _______, _______, _______, ES_Q,    _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 *
 * F-keys, media and mouse controls, emoji, settings, modes.
 *
 */
[_ADJUST] = LAYOUT_preonic_grid(
  MU_TOG,  KC_BRID, KC_BRIU, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, EM_SRG,
  _______, KC_F1  , KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_BTN4, KC_BTN1, KC_BTN2, KC_BTN3, EM_FIN,  EM_LEN,
  _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, EM_FIX,  EM_FLP,
  _______, KC_F11,  KC_F12,  KC_PSCR, KC_SCRL, KC_PAUS, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case ADJUST:
          if (record->event.pressed) {
            layer_on(_ADJUST);
          } else {
            layer_off(_ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef RGBLIGHT_ENABLE
              rgblight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
        case EM_SRG:
          if (record->event.pressed) {
            send_unicode_string("¯\\_(ツ)_/¯");
          }
          break;
        case EM_LEN:
          if (record->event.pressed) {
            send_unicode_string("( ͡° ͜ʖ ͡°)");
          }
          break;
        case EM_FLP:
          if (record->event.pressed) {
            send_unicode_string("(╯°□°）╯︵ ┻━┻");
          }
          break;
        case EM_FIN:
          if (record->event.pressed) {
            send_unicode_string("°◡°");
          }
          break;
        case EM_FIX:
          if (record->event.pressed) {
            send_unicode_string("┬─┬ ノ( ゜-゜ノ)");
          }
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
