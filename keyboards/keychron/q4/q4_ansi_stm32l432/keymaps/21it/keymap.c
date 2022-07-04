/* Copyright 2021 @ Keychron (https://www.keychron.com)
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
#include "test.h"

enum layers {
    MAC_BASE,
    WIN_BASE,
    _FN1,
    _FN2,
    _FN3
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

enum custom_keycodes {
    KC_MISSION_CONTROL = SAFE_RANGE,
    KC_LAUNCHPAD,
    KC_LOPTN,
    KC_ROPTN,
    KC_LCMMD,
    KC_RCMMD,
    KC_TASK_VIEW,
    KC_FILE_EXPLORER,
    KC_SCREEN_SHOT
};

#define KC_MCTL KC_MISSION_CONTROL
#define KC_LPAD KC_LAUNCHPAD
#define KC_TASK KC_TASK_VIEW
#define KC_FLXP KC_FILE_EXPLORER
#define KC_SNAP KC_SCREEN_SHOT

typedef struct PACKED {
    uint8_t len;
    uint8_t keycode[3];
} key_combination_t;

key_combination_t key_comb_list[3] = {
    {2, {KC_LWIN, KC_TAB}},
    {2, {KC_LWIN, KC_E}},
    {3, {KC_LSFT, KC_LCMD, KC_4}}
};

static uint8_t mac_keycode[4] = { KC_LOPT, KC_ROPT, KC_LCMD, KC_RCMD };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_61(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT,
        KC_LCTL, KC_LOPTN,KC_LCMMD,                           KC_SPC,                             KC_RCMMD, MO(_FN1), MO(_FN3), KC_RCTL),

    [WIN_BASE] = LAYOUT_ansi_61(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        MO(_FN1),KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_ENT,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT,  MO(_FN2), MO(_FN3), KC_RCTL),

    [_FN1] = LAYOUT_ansi_61(
        MO(_FN3),_______, _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,   _______,  _______,  _______,
        MO(_FN2),_______, _______, _______, _______, _______, _______, KC_INS,  KC_DEL,  KC_LBRC, KC_RBRC,  _______,  _______,  KC_GRV,
        _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______,  _______,            _______,
        _______,          _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,   _______,            _______,
        _______, _______, _______,                            _______,                            _______,  _______,  _______,  _______),

    [_FN2] = LAYOUT_ansi_61(
        _______, ES_E,    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,
        _______, _______, _______, AC_E,    _______, _______, DI_U,    AC_U,    AC_I,    AC_O,    _______,  _______,  _______,  _______,
        _______, AC_A,    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______,
        _______,          _______, _______, _______, _______, _______, TI_N,    _______, _______, _______,  ES_Q,               _______,
        _______, _______, _______,                            _______,                            _______,  _______,  _______,  _______),

    [_FN3] = LAYOUT_ansi_61(
        KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,
        RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______,  _______,  _______,  _______,
        _______, RGB_RMOD,RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______,  _______,            _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______,
        _______, _______, _______,                            _______,                            _______,  _______,  _______,  _______)
};

bool dip_switch_update_user(uint8_t index, bool active) {
    system_switch_state_report(index, active);
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MISSION_CONTROL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LAUNCHPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LOPTN:
        case KC_ROPTN:
        case KC_LCMMD:
        case KC_RCMMD:
            if (record->event.pressed) {
                register_code(mac_keycode[keycode - KC_LOPTN]);
            } else {
                unregister_code(mac_keycode[keycode - KC_LOPTN]);
            }
            return false;  // Skip all further processing of this key
        case KC_TASK:
        case KC_FLXP:
        case KC_SNAP:
            if (record->event.pressed) {
                for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK].len; i++) {
                    register_code(key_comb_list[keycode - KC_TASK].keycode[i]);
                }
            } else {
                for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK].len; i++) {
                    unregister_code(key_comb_list[keycode - KC_TASK].keycode[i]);
                }
            }
            return false;  // Skip all further processing of this key
        default:
            return true;  // Process all other keycodes normally
    }
}
