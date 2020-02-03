/* Copyright 2019 kamonanban
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
#include "keymap_jp.h"

// Defines the keycodes used by our macros in process_record_user
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define KC_KANJI KC_GRV

#define KC_LOWER LOWER
#define KC_RAISE RAISE
#define KC_RST   RESET


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,---------------------------------------------------------------------.,---------------------------------------------------------------------.
       JP_CIRC,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,   KC_UP,    KC_LEFT,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,  KC_MINS,\
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
        KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T, KC_DOWN,    KC_RGHT,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,    JP_AT,\
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       KC_LCTL,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G, KC_HOME,     KC_END,     KC_H,     KC_J,     KC_K,     KC_L,  KC_SCLN,  JP_COLN,\
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                          KC_N,     KC_M,  KC_COMM,   KC_DOT,  KC_SLSH,  JP_BSLS,\
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       KC_LGUI,  _______,  KC_LALT,   KC_SPC,  KC_BSPC,  JP_LBRC,    LOWER,     RAISE,  JP_RBRC,   KC_ESC,   KC_ENT,  KC_RALT,  _______, KC_GRV \
  //`---------+----------/\-------+---------+---------+---------+---------/\---------+---------+---------+---------+---------/\--------+----------'
  ),

  [_LOWER] = LAYOUT( \
  //,---------------------------------------------------------------------.,---------------------------------------------------------------------.
       KC_TILD,  KC_EXLM,    KC_AT,  KC_HASH,   KC_DLR,  KC_PERC, _______,    _______,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  JP_CIRC,\
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       _______,  KC_EXLM,  KC_PGUP,  KC_HASH,   KC_DLR,  KC_PERC, _______,    _______,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DEL,\
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       _______,  KC_HOME,KC_PGDOWN,   KC_END,  _______,  _______, KC_PGUP,  KC_PGDOWN,  _______,  _______,  KC_COMM,   KC_DOT,  KC_SLSH,  LSFT(KC_JYEN),\
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       _______,  _______,  _______,  _______,  _______,  _______,                       _______,  _______,S(KC_NUHS),S(KC_NUBS),_______,  _______,\
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______, _______ \
  //`---------+----------/\-------+---------+---------+---------+---------/\---------+---------+---------+---------+---------/\--------+----------'
 ),

  [_RAISE] = LAYOUT( \
  //,---------------------------------------------------------------------.,---------------------------------------------------------------------.
        KC_GRV,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,  _______,   _______,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0, KC_DEL,\
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
        KC_GRV,     KC_1,    KC_UP,     KC_3,     KC_4,     KC_5,  _______,   _______,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0, KC_BSPC,\
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______, KC_BSLS,\
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       _______,  _______,  _______,  _______,  _______,  _______,                       _______,  _______,  _______,  _______,  _______, _______,\
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______, _______ \
  //`---------+----------/\-------+---------+---------+---------+---------/\---------+---------+---------+---------+---------/\--------+----------'
  ),

  [_ADJUST] = LAYOUT( \
  //,---------------------------------------------------------------------.,---------------------------------------------------------------------.
         KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,  _______,   _______,    KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11, KC_F12,\
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       _______,    RESET,  RGB_TOG,  RGB_MOD,  RGB_HUD,  RGB_HUI,  _______,   _______,  RGB_SAD,  RGB_SAI,  RGB_VAD,  RGB_VAI,  _______, KC_BSPC,\
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       _______,  _______,  _______,    AU_ON,   AU_OFF,  AG_NORM,  _______,   _______,  AG_SWAP,  _______,  BL_TOGG,  BL_STEP,  _______, _______,\
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       _______,  _______,  _______,  _______,  _______,  _______,                       _______,  _______,  _______,  _______,  _______, _______,\
  //|---------+---------+---------+---------+---------+---------+---------|\---------+---------+---------+---------+---------+---------+---------|
       _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______, _______ \
  //`---------+----------/\-------+---------+---------+---------+---------/\---------+---------+---------+---------+---------/\--------+----------'
  )
};
void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

static inline void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
switch (keycode) {
case LOWER:
  if (record->event.pressed) {
    layer_on(_LOWER);
    update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
  } else {
    layer_off(_LOWER);
    update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
  }
  return false;
  break;
case RAISE:
  if (record->event.pressed) {
    layer_on(_RAISE);
    update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
  } else {
    layer_off(_RAISE);
    update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
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
  }
  return true;
}
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
