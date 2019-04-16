/* Copyright 2018 Milton Griffin
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

// Keyboard Layers
#define _QW 0
#define _FN 1

#define JA_CLON KC_QUOT  // : and +
#define JA_AT   KC_LBRC  // @ and `
#define JA_HAT  KC_EQL   // ^ and ~
#define JA_ENUN KC_RO    // \ and _ (EN mark and UNder score)
#define JA_ENVL KC_JYEN  // \ and | (EN mark and Vertical Line)
#define JA_LBRC KC_RBRC  // [ and {
#define JA_RBRC KC_BSLS  // ] and }

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ^      | 1      | 2      | 3      | 4      | 5      | [      |        | ]      | 6      | 7      | 8      | 9      | 0      |  -     |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | HOME   |        | PG UP  | Y      | U      | I      | O      | P      |  @     |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | LCTRL  | A      | S      | D      | F      | G      | END    | DEL    | PG DOWN| H      | J      | K      | L      | ;      | :* /C  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | LEFT   | UP     | RIGHT  | N      | M      | ,      | .      | /      | ¥_ / S |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        | LGUI   | LALT   | FN     | SPACE  | BACKSP | DOWN   | ESC    | Enter  | FN     | RALT   | GRV    |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
    JA_HAT,  KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    JA_LBRC, XXXXXXX, JA_RBRC, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,    KC_HOME, XXXXXXX, KC_PGUP, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    JA_AT, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,     KC_G,    KC_END , KC_DEL,  KC_PGDN, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, CTL_T(JA_CLON),  \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,    KC_LEFT, KC_UP,   KC_RGHT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_T(JA_ENUN), \
    XXXXXXX, XXXXXXX, KC_LGUI, KC_LALT, MO(_FN),  KC_SPC,  KC_BSPC, KC_DOWN, KC_ESC,  KC_ENT,  MO(_FN), KC_RALT, KC_GRV,  XXXXXXX, XXXXXXX  \
 ),

/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | CALC   | RGB TG | RGB MD | RGB HD | RGB HI | P7     | P8     | P9     | -      |        |        | PR SCR | SCR LK | PAUSE  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        | RGB RMD| RGB SD | RGB SI | P4     | P5     | P6     | +      |        | RESET  |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        | RGB VD | RGB VI | P1     | P2     | P3     | PENT   |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        | FN     |        | P0     |        | P.     | PENT   | FN     |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_FN] = LAYOUT_ortho_5x15( /* FUNCTION */
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_NLCK, KC_SLSH, KC_ASTR, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
    _______, KC_CALC, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, KC_P7,   KC_P8,   KC_P9,   KC_MINS, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, \
    _______, _______, KC_MNXT, RGB_RMOD,RGB_SAD, RGB_SAI, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, _______, RESET,   _______, _______, _______, \
    _______, _______, _______, _______, RGB_VAD, RGB_VAI, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, MO(_FN) ,_______, KC_P0,   _______, KC_PDOT, KC_PENT, MO(_FN), _______, _______, _______, _______  \
 ),
};
