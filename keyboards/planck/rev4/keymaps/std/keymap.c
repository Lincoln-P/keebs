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

#ifdef AUDIO_ENABLE
#include "muse.h"
#endif

enum planck_layers {
  _QWERTY,
  _CANARY,
  _NAV,
  _SYM,
  _NUM
};

enum planck_keycodes {

};

// tap-hold keycodes
#define EscSYM LT(_SYM,KC_ESC)
#define SpcNAV LT(_NAV,KC_SPC)
#define EntSFT LT(0,KC_NO) // custom Enter/Shift implementation
#define NUM TT(_NUM)

// persistant default layer setting
#define QWERTY PDF(_QWERTY)
#define CANARY PDF(_CANARY)

// multi-desktop shortcuts
#define PDSK LCG(KC_LEFT) // previous desktop
#define NDSK LCG(KC_RGHT) // next desktop

// screen capture
#define SCPT LSG(KC_S)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,----------------------------------.     ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |     |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|     |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |     |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|     |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |     |   N  |   M  |   ,  |   .  |   /  |
 * '--------------------+------+------|     +------+------+--------------------'
 *                      |EscSYM|SpcNAV|     |EntSFT|  NUM |
 *                      `-------------'     `-------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   _______, _______,  KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   _______, _______,  KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,   _______, _______,  KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,
    _______, _______, _______, EscSYM, SpcNAV, _______, _______,  EntSFT, NUM,    _______, _______, _______
),

/* CANARY
 * ,----------------------------------.      ,----------------------------------.
 * |   W  |   L  |   Y  |   P  |   B  |      |   Z  |   F  |   O  |   U  |   '  |
 * |------+------+------+------+------+      |------+------+------+------+------|
 * |   C  |   R  |   S  |   T  |   G  |      |   M  |   N  |   E  |   I  |   A  |
 * |------+------+------+------+------+      |------+------+------+------+------|
 * |   Q  |   J  |   V  |   D  |   K  |      |   X  |   H  |   /  |   ,  |   .  |
 * `--------------------+------+------+      |------+------+--------------------'
 *                      |EscSYM|SpcNAV|      |EntSFT|  NUM |
 *                      `-------------'      `-------------'
 */
[_CANARY] = LAYOUT_planck_grid(
    KC_W,    KC_L,    KC_Y,    KC_P,    KC_B,   _______, _______,  KC_Z,   KC_F,    KC_O,    KC_U,    KC_QUOT,
    KC_C,    KC_R,    KC_S,    KC_T,    KC_G,   _______, _______,  KC_M,   KC_N,    KC_E,    KC_I,    KC_A,
    KC_Q,    KC_J,    KC_V,    KC_D,    KC_K,   _______, _______,  KC_X,   KC_H,    KC_SLSH, KC_COMM, KC_DOT,
    _______, _______, _______, EscSYM,  SpcNAV, _______, _______,  EntSFT, NUM,     _______, _______, _______
),

/* NAV
 * ,----------------------------------.      ,----------------------------------.
 * | CAPS | SCPT | STAB | TAB  | CUT  |      | UNDO | HOME |  UP  | END  | PGUP |
 * |------+------+------+------+------+      +------+------+------+------+------|
 * | WIN  | RALT | CTRL | SHFT | COPY |      | REDO | LEFT | DOWN | RGHT | PGDN |
 * |------+------+------+------+------+      +------+------+------+------+------|
 * |      |PDSKTP|LDSKTP|NDSKTP| PSTE |      |      |      |      |      |      |
 * `--------------------+------+------+      +------+------+--------------------'
 *                      |      | ---- |      |      |      |
 *                      `-------------'      `-------------'
 */
[_NAV] = LAYOUT_planck_grid(
    KS_CAPS, SCPT,      S(KC_TAB),KC_TAB,  C(KC_X),  _______, _______, C(KC_Z), KC_HOME, KC_UP,   KC_END,  KC_PGUP,
    KC_GUI,  C(KC_LALT),KC_LCTL,  KC_LSFT, C(KC_C),  _______, _______, C(KC_Y), KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
    _______, PDSK,      G(KC_TAB),NDSK,    C(KC_V),  _______, _______, _______, _______, _______, _______, _______,
    _______, _______,   _______,  _______, _______,  _______, _______, _______, _______, _______, _______, _______
),

/* SYM
 * ,----------------------------------.      ,----------------------------------.
 * |  !   |  @   |  #   |  $   |  %   |      |  ^   |  &   |  *   |  \   |  |   |
 * |------+------+------+------+------+      +------+------+------+------+------|
 * |  :   |  {   |  [   |  (   |  <   |      |   >  |  )   |  ]   |  }   |  ;   |
 * |------+------+------+------+------+      +------+------+------+------+------|
 * |      |  `   |  ~   |  _   |      |      |      |  =   |      |      |      |
 * `--------------------+------+------+      +------+------+--------------------'
 *                      | ---- |      |      |      |      |
 *                      `-------------'      `-------------'
 */
[_SYM] = LAYOUT_planck_grid(
    S(KC_1),   S(KC_2),   S(KC_3),  S(KC_4),    S(KC_5),   _______, _______, S(KC_6),  S(KC_7), S(KC_8), KC_BSLS,   S(KC_BSLS),
    S(KC_SCLN),S(KC_LBRC),KC_LBRC,  S(KC_9),    S(KC_COMM),_______, _______, S(KC_DOT),S(KC_0), KC_RBRC, S(KC_RBRC),KC_SCLN,
    _______,   KC_GRV,    S(KC_GRV),S(KC_MINS), _______,   _______, _______, KC_EQL,   _______, _______, _______,   _______,
    _______,   _______,   _______,  _______,    _______,   _______, _______, _______,  _______, _______, _______,   _______
),

/* NUM (tap-toggle)
 * ,----------------------------------.      ,----------------------------------.
 * |  F12 |  F7  |  F8  |  F9  |      |      |  +   |  7   |  8   |  9   |  *   |
 * |------+------+------+------+------+      +------+------+------+------+------|
 * |  F11 |  F4  |  F5  |  F6  |      |      |  .   |  4   |  5   |  6   |  /   |
 * |------+------+------+------+------+      +------+------+------+------+------|
 * |  F10 |  F1  |  F2  |  F3  |      |      |  -   |  1   |  2   |  3   |  =   |
 * `--------------------+------+------+      +------+------+--------------------'
 *                      |      | SPC  |      |  0   | NUM  |
 *                      `-------------'      `-------------'
 */
[_NUM] = LAYOUT_planck_grid(
    S(KC_1),   S(KC_2),   S(KC_3), S(KC_4),    S(KC_5),   _______, _______, S(KC_EQL),KC_7,    KC_8,    KC_9,    S(KC_8),
    S(KC_SCLN),S(KC_LBRC),KC_LBRC, S(KC_9),    S(KC_COMM),_______, _______, KC_DOT,   KC_4,    KC_5,    KC_6,    KC_SLSH,
    _______,   _______,   _______, S(KC_MINS), _______,   _______, _______, KC_MINS,  KC_1,    KC_2,    KC_3,    KC_EQL,
    _______,   _______,   _______, _______,    _______,   _______, _______, NUM,      _______, _______, _______, _______
)

};