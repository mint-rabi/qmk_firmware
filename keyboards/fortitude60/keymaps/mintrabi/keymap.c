#include QMK_KEYBOARD_H
#include "eeconfig.h"
#include "keymap_jp.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16
#define _DEBUG 3

enum custom_keycodes
{
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  IDEDBG,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// Intellij Debug Keycode
#define I_S_OV KC_F8 //StepOver
#define I_S_OU LSFT(KC_F8) //StepOut
#define I_S_IN KC_F7 //StepIn
#define I_S_CN KC_F9 //continue

// Visual Studio Code Debug Keycode
#define V_S_OV KC_F10 //StepOver
#define V_S_OU LSFT(KC_F11) //StepOut
#define V_S_IN KC_F11 //StepIn
#define V_S_CN KC_F5 //continue


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |   ^  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |   -  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |  @   |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |:* /C |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   [  |   ]  |   N  |   M  |   ,  |   .  |   /  |¥_ / S|
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |  GUI | Alt  |Lower |Space | Bksp | Esc  |Enter |Raise |  Alt |  Grv |
 *               `---------------------------------------------------------------------'
 */
    [_QWERTY] = LAYOUT(
        JP_CIRC, KC_1,    KC_2,    KC_3,    KC_4,  KC_5,                     KC_6,   KC_7,  KC_8,    KC_9,   KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,                     KC_Y,   KC_U,  KC_I,    KC_O,   KC_P,    JP_AT,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,  KC_G,                     KC_H,   KC_J,  KC_K,    KC_L,   KC_SCLN, CTL_T(JP_COLN),
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   JP_LBRC, JP_RBRC, KC_N,   KC_M,  KC_COMM, KC_DOT, KC_SLSH, SFT_T(JP_BSLS),
                          KC_LGUI, KC_LALT, LOWER, KC_SPC, KC_BSPC, KC_ESC,  KC_ENT, RAISE, KC_RALT, KC_GRV),

    /* Lower
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |   ^  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |AltTab|   !  | PgUp |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      | HOME | PgDwn|  END |  F4  |  F5  |             |  F6  |   _  |   +  |      |   \  |  |   |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |      |      |  F12 |ISO ~ |ISO | |      |      |      |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |      |      |      |      |      |      |      |      |      |      |
 *               `---------------------------------------------------------------------'
 */
    [_LOWER] = LAYOUT(
        KC_TILD,      KC_EXLM, KC_AT,     KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, JP_CIRC,
        LALT(KC_TAB), KC_EXLM, KC_PGUP,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_DEL,
        _______,      KC_HOME, KC_PGDOWN, KC_END,  KC_F4,   KC_F5,                     KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, LSFT(KC_JYEN),
        _______,      KC_F7,   KC_F8,     KC_F9,   KC_F10,  KC_F11,  _______, _______, KC_F12,  S(KC_NUHS), S(KC_NUBS), _______, _______, _______,
                               _______,   _______, _______, _______, _______, _______, _______, _______,    _______,    _______),

    /* Raise
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |   `  |   1  |  Up  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      | Left | Down | Right|  F4  |  F5  |             |  F6  |   -  |   =  |   [  |   ]  |  |   |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |      |      |  F12 |ISO # |ISO / |      |      |      |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |      |      |      |      |      |      |      |      |      |      |
 *               `---------------------------------------------------------------------'
 */
    [_RAISE] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        KC_GRV,  KC_1,    KC_UP,   KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_F4,   KC_F5,                     KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, _______, KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______,
                          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    /* Adjust (Lower + Raise)
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      | Reset|RGB Tg|RGB Md|Hue Up|Hue Dn|             |Sat Up|Sat Dn|Val Up|Val Dn|      | Bksp |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|             |AGswap|      |BL TOG|BL STP|      |      |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |DEBUG |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |      |      |      |      |      |      |      |      |      |      |
 *               `---------------------------------------------------------------------'
 */
    [_ADJUST] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,                   RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, KC_BSPC,
        _______, _______, _______, AU_ON  , AU_OFF , AG_NORM,                   AG_SWAP, _______, BL_TOGG, BL_STEP, _______, _______,
        IDEDBG , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    /* Debug
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      | Reset|RGB Tg|RGB Md|Hue Up|Hue Dn|             |Sat Up|Sat Dn|Val Up|Val Dn|      | Bksp |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|             |AGswap|      |BL TOG|BL STP|      |      |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |Qwerty|      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |      |      |      |      |      |      |      |      |      |      |
 *               `---------------------------------------------------------------------'
 */
    [_DEBUG] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, V_S_OV,  V_S_OU,  V_S_IN,  V_S_CN,  _______,                   _______, _______, _______, _______, _______, _______,
        _______, I_S_OV , I_S_OU , I_S_IN , I_S_CN , _______,                   _______, _______, _______, _______, _______, _______,
        QWERTY,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                          _______, _______, LOWER  , _______, _______, _______, _______, RAISE  , _______, _______)};

uint32_t layer_state_set_user(uint32_t state)
{
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
  {
  case QWERTY:
    if (record->event.pressed)
    {
      set_single_persistent_default_layer(_QWERTY);
    }
    return false;
    break;
  case IDEDBG:
    if (record->event.pressed)
    {
      set_single_persistent_default_layer(_DEBUG);
    }
    return false;
    break;
  }
  return true;
}
