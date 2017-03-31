#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"

#define XCODE 0 // Xcode layer
#define ANDR 1 // Android Studio layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap XC: Xcode layer
 * OSM-Hyper = One Shot Modifier (HYPER)
 * ApSwtc = App Switcher (Cmd+Tab, hold down)
 * IndFil = Indent file
 * OpQc = Open quickly
 * CLEAN = Clean project
 * RUN = Run project
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Grv   |   1  |   2  |   3  |   4  |   5  | OSM-Hyper |      |   6  |   7  |   8  |   9  |   0  |   -  |   +=   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |ApSwtc|           | CLEAN|   Y  |   U  |   I  |   O  |   P  |   '"   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | XCODE  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | ANDROID|
 * |--------+------+------+------+------+------| ALT  |           |  RUN |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  //  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |IndFil|GblFnd| OpQc |  Esc | Ctrl |                                       | Left | Down |  Up  | Right |  \| |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Undo | Home |       | Vol-  | Vol+|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |  End |       | PgUp |        |      |
 *                                 | Bksp |  Del |------|       |------|  Enter | Space|
 *                                 |      |      | LGui |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[XCODE] = KEYMAP(  // layer XCODE : Xcode
        // left hand
        KC_GRV,        KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   OSM(MOD_HYPR),
        KC_TAB,        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   M(0),
        TO(XCODE),     KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,       KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_LALT,
        M(8),          M(7),         M(6),     KC_ESC, KC_LCTRL,
                                                     M(5),     KC_HOME,
                                                                     KC_END,
                                                  KC_BSPC, KC_DELT,  KC_LGUI,
        // right hand
        KC_6,       KC_7,      KC_8,        KC_9,       KC_0,      KC_MINS, KC_EQL,
        M(10),        KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_QUOT,
                          KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN, TO(ANDR),
        M(11),        KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,   KC_RSFT,
                                  KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,    KC_BSLS,
        KC_VOLD,        KC_VOLU,
        KC_PGUP,
        KC_PGDN,KC_ENT, KC_SPC
    ),
    /* Keymap ANDR: Android Studio layer
     * OSM-Hyper = One Shot Modifier (HYPER)
     * ApSwtc = App Switcher (Cmd+Tab, hold down)
     * IndFil = Indent file
     * OpQc = Open quickly
     * RUN = Run project
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |  Grv   |   1  |   2  |   3  |   4  |   5  | OSM-Hyper |      |   6  |   7  |   8  |   9  |   0  |   -  |   +=   |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Tab    |   Q  |   W  |   E  |   R  |   T  |ApSwtc|           | TRNS |   Y  |   U  |   I  |   O  |   P  |   '"   |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | XCODE  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | ANDROID|
     * |--------+------+------+------+------+------| ALT  |           |  RUN |------+------+------+------+------+--------|
     * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  //  | RShift |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |IndFil|GblFnd| OpQc |  Esc | Ctrl |                                       | Left | Down |  Up  | Right |  \| |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | Undo | Home |       | Vol-  | Vol+|
     *                                 ,------|------|------|       |------+--------+------.
     *                                 |      |      |  End |       | PgUp |        |      |
     *                                 | Bksp |  Del |------|       |------|  Enter | Space|
     *                                 |      |      | LGui |       | PgDn |        |      |
     *                                 `--------------------'       `----------------------'
     */
    // If it accepts an argument (i.e, is a function), it doesn't need KC_.
    // Otherwise, it needs KC_*
    [ANDR] = KEYMAP(  // layer ANDR : Android Studio
            // left hand
            KC_GRV,        KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   OSM(MOD_HYPR),
            KC_TAB,        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   M(0),
            TO(XCODE),     KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
            KC_LSFT,       KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_LALT,
            M(9),          M(7),         M(6),     KC_ESC, KC_LCTRL,
                                                         M(5),     KC_HOME,
                                                                         KC_END,
                                                      KC_BSPC, KC_DELT,  KC_LGUI,
            // right hand
            KC_6,       KC_7,      KC_8,        KC_9,       KC_0,      KC_MINS, KC_EQL,
            KC_TRNS,        KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_QUOT,
                              KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN, TO(ANDR),
            M(12),        KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,   KC_RSFT,
                                      KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,    KC_BSLS,
            KC_VOLD,        KC_VOLU,
            KC_PGUP,
            KC_PGDN,KC_ENT, KC_SPC
        )
};

const uint16_t PROGMEM fn_actions[] = {
  //  [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_LGUI);
          register_code(KC_TAB);
          unregister_code(KC_TAB);
        } else {
          unregister_code(KC_LGUI);
        }
        break;
        case 1:
        if (record->event.pressed) {
          register_code(KC_LGUI);
          register_code(KC_SPC);
          unregister_code(KC_LGUI);
          unregister_code(KC_SPC);
        }
        break;
        case 2:
        if (record->event.pressed) {
          register_code(KC_LGUI);
          register_code(KC_X);
          unregister_code(KC_LGUI);
          unregister_code(KC_X);
        }
        break;
        case 3:
        if (record->event.pressed) {
          register_code(KC_LGUI);
          register_code(KC_C);
          unregister_code(KC_LGUI);
          unregister_code(KC_C);
        }
        break;
        case 4:
        if (record->event.pressed) {
          register_code(KC_LGUI);
          register_code(KC_V);
          unregister_code(KC_LGUI);
          unregister_code(KC_V);
        }
        break;
        case 5: // Undo
        if (record->event.pressed) {
          register_code(KC_LGUI);
          register_code(KC_Z);
          unregister_code(KC_LGUI);
          unregister_code(KC_Z);
        }
        break;
        case 6: // Open quickly
        if (record->event.pressed) {
          register_code(KC_LGUI);
          register_code(KC_LSFT);
          register_code(KC_O);
          unregister_code(KC_LGUI);
          unregister_code(KC_LSFT);
          unregister_code(KC_O);
        }
        break;
        case 7: // Global find
        if (record->event.pressed) {
          register_code(KC_LGUI);
          register_code(KC_LSFT);
          register_code(KC_F);
          unregister_code(KC_LGUI);
          unregister_code(KC_LSFT);
          unregister_code(KC_F);
        }
        break;
        case 8: // Indent file (Xcode)
        if (record->event.pressed) {
          register_code(KC_LGUI);
          register_code(KC_A);
          unregister_code(KC_LGUI);
          unregister_code(KC_A);
          register_code(KC_LCTRL);
          register_code(KC_I);
          unregister_code(KC_LCTRL);
          unregister_code(KC_I);
        }
        break;
        case 9: // Indent file (Android Studio)
        if (record->event.pressed) {
          register_code(KC_LGUI);
          register_code(KC_LALT);
          register_code(KC_L);
          unregister_code(KC_LGUI);
          unregister_code(KC_LALT);
          unregister_code(KC_L);
        }
        break;
        case 10: // Clean project (Xcode)
        if (record->event.pressed) {
          register_code(KC_LGUI);
          register_code(KC_LSFT);
          register_code(KC_K);
          unregister_code(KC_LGUI);
          unregister_code(KC_LSFT);
          unregister_code(KC_K);
        }
        break;
        case 11: // Run project (Xcode)
        if (record->event.pressed) {
          register_code(KC_LGUI);
          register_code(KC_R);
          unregister_code(KC_LGUI);
          unregister_code(KC_R);
        }
        break;
        case 12: // Run project (Android Studio)
        if (record->event.pressed) {
          register_code(KC_LCTRL);
          register_code(KC_R);
          unregister_code(KC_LCTRL);
          unregister_code(KC_R);
        }
        break;
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
