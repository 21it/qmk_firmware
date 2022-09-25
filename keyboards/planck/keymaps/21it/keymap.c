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

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
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
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Lower|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Raise| Alt  |Space |Space |Space |Space |AltGr |Adjust| GUI  | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    LOWER,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_LCTL, KC_LGUI, RAISE,   KC_LALT, KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_ALGR, ADJUST,  KC_RGUI, KC_RCTL
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      | Ins  | Left | Down | Up   | Rght |   [  |   ]  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      | Del  | Home | PgDn | PgUp | End  |   -  |   =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | Tab  | Tab  |      |      |   \  |   `  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, _______, _______, _______, _______, KC_INS,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_LBRC, KC_RBRC,
    _______, _______, _______, _______, _______, KC_DEL,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_MINS, KC_EQL,
    _______, _______, _______, _______, KC_TAB,  KC_TAB,  _______, _______, KC_BSLS, KC_GRV,  _______, _______
),

/* Raise
 *
 * F-keys, media controls, emoji, settings, modes.
 *
 */

[_RAISE] = LAYOUT_planck_grid(
    MU_TOG,  KC_BRID, KC_BRIU, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,
    _______, RGB_HUD, RGB_HUI, _______, _______, _______, RGB_SAD, RGB_MOD, RGB_SAI, RGB_TOG, RGB_VAD, RGB_VAI,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 *
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|Voice-|Voice+|Mus on|Musoff|      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  _______, _______, _______, _______,  _______, _______, _______,
    _______, RESET,   MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

/* Español
 * ,-----------------------------------------------------------------------------------.
 * |      |   ¡  |      |   é  |      |      |   ü  |   ú  |   í  |   ó  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   á  |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |   ñ  |      |      |      |   ¿  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
// [_ESP] = LAYOUT_planck_grid(
//     _______, ES_E,    _______, AC_E,    _______, _______, DI_U,    AC_U,    AC_I,    AC_O,    _______, _______,
//     _______, AC_A,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//     _______, _______, _______, _______, _______, _______, TI_N,    _______, _______, _______, ES_Q,    _______,
//     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
// ),

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
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
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
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

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
