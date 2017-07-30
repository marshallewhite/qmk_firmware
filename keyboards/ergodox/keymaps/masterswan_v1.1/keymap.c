#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"

#define PRG 0 // Programming layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Programming layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Grv   |   1  |   2  |   3  |   4  |   5  | KC_NO |      |   6  |   7  |   8  |   9  |   0  |   -  |   +=   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |KC_NO|           | KC_NO|   Y  |   U  |   I  |   O  |   P  |   '"   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | KC_NO  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | KC_NO|
 * |--------+------+------+------+------+------| ALT  |           |  KC_NO |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |KC_NO|KC_NO| KC_NO |  Esc | Ctrl |                                       | Left | Down |  Up  | Right |  \| |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | KC_NO | Home |       |  [   |   ]  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |  End |       |  (   |        |      |
 *                                 | Bksp |  Del |------|       |------|  Enter | Space|
 *                                 |      |      | LGui |       |  )   |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
    [PRG] = KEYMAP(  // layer PRG: default
        // left hand
        KC_GRV,        KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_NO,
        KC_TAB,        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_NO,
        KC_NO,     KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,       KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_LALT,
        KC_NO,         KC_NO,        KC_NO,     KC_ESC, KC_LCTRL,
                                                     KC_NO,     KC_HOME,
                                                                     KC_END,
                                                  KC_BSPC, KC_DELT,  KC_LGUI,
        // right hand
        KC_6,       KC_7,      KC_8,        KC_9,       KC_0,      KC_MINS, KC_EQL,
        KC_NO,        KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_QUOT,
                          KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN, KC_NO,
        KC_NO,        KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,   KC_RSFT,
                                  KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,    KC_BSLS,
        KC_LBRC,        KC_RBRC,
        KC_LPRN,
        KC_RPRN,KC_ENT, KC_SPC
    ),
};

const uint16_t PROGMEM fn_actions[] = {
    
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
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
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
