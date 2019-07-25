#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_jp.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols and media keys
#define META 2 // Meta and Macro keys
#define LEFT 3 // Left hand keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ^     |   1  |   2  |   3  |   4  |   5  | ESC  |           |  Grv |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |Enter |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   @    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ctrl   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |: * / C |
 * |--------+------+------+------+------+------| Hyper|           |   B  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |¥ _ / S |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|   "  | ESC  | LGui |  ALT |                                       |   [  |   ]  |   |  |  ?¥  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,--------------.
 *                                        | App  |ESC   |       | LEFT | RIGHT  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |Enter |       | UP   | Back   |      |
 *                                 | Space|Backsp|------|       |------| Space  |Enter |
 *                                 |      |ace   | DEL  |       | DOWN | SW(L1) |SW(L3)|
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        JP_CIRC,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_ESC,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_ENT,
        KC_LCTL,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   ALL_T(KC_NO),
        LT(SYMB,KC_GRV),S(KC_2),      KC_ESC, KC_LGUI,KC_LALT,
                                                    KC_APP,   KC_ESC,
                                                              KC_ENT,
                                   LT(LEFT,KC_SPC), KC_BSPC,  KC_DEL,
        // right hand
        KC_GRV,      KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
        TG(SYMB),    KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             JP_AT,
                     KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,          CTL_T(JP_COLN),
        KC_B,        KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          SFT_T(JP_BSLS),
                             JP_LBRC,JP_RBRC,S(JP_YEN),JP_YEN,       LT(SYMB, KC_NO),
             KC_LEFT,        KC_RGHT,
             KC_UP,
             KC_DOWN,LT(SYMB, KC_BSPC), LT(META, KC_ENT)
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   F1   |  F2  |  F3  |  F4  |  F5  | F6   |      |           |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |   F12  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |      |      |Ms Up |      |      |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ctrl   |      |MsLeft|MsDown|MsRght|      |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |      |      |      |      |      |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | LGui | LAlt |                                       |   0  |      |   .  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |WhLeft|WhRght|       |HOME  |END   |
 *                                 ,------|------|------|       |------+------+------.
 *                                 | Ms   | Ms   |WhUp  |       |PgUp  |      |      |
 *                                 | Left | Right|------|       |------|      |      |
 *                                 | Click| Click|WhDown|       |PgDw  |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_TRNS,
       KC_TAB , KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_LCTL, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_LGUI, KC_LALT,
                                           KC_WH_L, KC_WH_R,
                                                    KC_WH_U,
                                  KC_BTN1, KC_BTN2, KC_WH_D,
       // right hand
       KC_F6,   KC_F7,   KC_F8,  KC_F9,   KC_F10,  KC_F11,  KC_F12,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_0,   KC_NO,   KC_DOT,  KC_EQL,  KC_TRNS,
       KC_HOME, KC_END,
       KC_PGUP,
       KC_PGDN, KC_TRNS, KC_TRNS
),
/* Keymap 2: Meta and Macro keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           | RESET|      |      |      |      |      |B Space |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |Up    |END   |      |      |      |           |      |      |Ins   |PrntSc|      |Pause |  {     |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Enter   |HOME  |Down  |Right |      |  H   |------|           |------|Left  |Down  |Up    |Right |  {   |  }     |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |MHEN  |HENK  |KANA  |      |      |      |           |      |      |M(1)  |Past  |Copy  |      |Shift   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |Win+L |      |      |      | DEL  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |CTL   |      |
 *                                 |      |      |------|       |------|SHIFT |      |
 *                                 |      |      |      |       |TASK  |DEL   |      |
 *                                 `--------------------'       `--------------------'
 */
// META
[META] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_UP,   KC_END,  KC_TRNS, KC_TRNS, KC_TRNS,
       KC_ENT , KC_HOME, KC_DOWN, KC_RGHT, KC_MYCM, KC_H,
       KC_TRNS, KC_MHEN, KC_HENK, KC_KANA, KC_CALC, KC_MAIL, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       RESET,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC,
       KC_TRNS,  KC_TRNS, KC_INS,  KC_PSCR, KC_TRNS, KC_PAUS, S(JP_LBRC),
                 KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, S(JP_LBRC), S(JP_RBRC),
       KC_TRNS,  KC_TRNS, M(1),    S(KC_INS),  LCTL(KC_INS), KC_TRNS, KC_RSFT,
                          LGUI(KC_L), KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       S(LCTL(KC_ESC)), LALT(LCTL(KC_DEL)), KC_TRNS
),
// LEFT
[LEFT] = LAYOUT_ergodox(
       JP_CIRC,  KC_MINS, KC_0,    KC_9,    KC_8,    KC_7,    KC_6,
       JP_AT,   KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,    KC_TRNS,
       JP_COLN, KC_SCLN, KC_L,    KC_K,    KC_J,    KC_H,
       JP_BSLS, KC_SLSH, KC_DOT,  KC_COMM, KC_M,    KC_N,    KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_TRNS,
                 KC_TRNS, KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
          break;
        case 1:
          if (record->event.pressed) {
            ergodox_right_led_2_on();
            return MACRO(D(LSFT), T(END), U(LSFT), D(LCTL), T(C), U(LCTL), END);
          }
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case SYMB:
            ergodox_right_led_1_on();
            break;
        case META:
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }

};

