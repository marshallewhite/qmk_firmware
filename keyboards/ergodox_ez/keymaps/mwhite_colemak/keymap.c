#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define QWRT 3 // qwerty layer

enum {
  TD_N_COLN = 0
};
    
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 * OSM-Hyper = One Shot Modifier (HYPER)
 * Spotlight = Cmd+Space
 * ApSwtc = App Switcher (Cmd+Tab, hold down)
 * ,-----------------------------------------------------.        ,--------------------------------------------------.
 * |  Caps  |   1  |   2  |   3  |   4  |   5  |OSM-Hyper|        | Play |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+------|---------'        |------+------+------+------+------+------+--------|
 * |MDIAShft|   Q  |   W  |   F  |   P  |   G  |Option|           | Next |   J  |   L  |   U  |   Y  |   ;  |   =    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |SYMBShft|   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |  N/: |   E  |   I  |   O  |   \    |
 * |--------+------+------+------+------+------|Spot  |           | Prev |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |Light |           |      |   K  |   M  |   ,  |   .  |//Ctrl|   '    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |ApSwtc| LCtrl| Left | Right| LGui |                                       | Left | Down |  Up  | Right| Undo |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,--------------.       ,--------------.
 *                                        |Sh/Esc|   Up  |      | Cut  |Ctrl/Tab|
 *                                 ,------|------|-------|      |------+--------+------.
 *                                 |      |      |  Down |      | Copy |        |      |
 *                                 | Bksp |  Del |-------|      |------|  Enter | Space|
 *                                 |      |      |  LGui |      | Paste|        |      |
 *                                 `---------------------'      `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_CAPS,        KC_1,       KC_2,   KC_3,   KC_4,   KC_5,   OSM(MOD_HYPR),
        MO(MDIA),       KC_Q,       KC_W,   KC_F,   KC_P,   KC_G,   KC_LALT,
        MO(SYMB),       KC_A,       KC_R,   KC_S,   KC_T,   KC_D,
        KC_LSFT,        KC_Z,       KC_X,   KC_C,   KC_V,   KC_B,   M(1),
        M(0),           KC_LCTRL,   KC_LEFT,KC_RGHT,KC_LGUI,
                                                     SFT_T(KC_ESC), KC_UP,
                                                                      KC_DOWN,
                                                     KC_BSPC,  KC_DEL,KC_LGUI,
        // right hand
             KC_MPLY,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
             KC_MNXT,    KC_J,   KC_L,   KC_U,   KC_Y,   KC_SCLN,          KC_EQL,
                          KC_H,   TD(TD_N_COLN),   KC_E,   KC_I,   KC_O,             KC_BSLS,
             KC_MPRV,KC_K,   KC_M,   KC_COMM,KC_DOT, CTL_T(KC_SLSH),       KC_QUOT,
                                  KC_LEFT,KC_DOWN,KC_UP,KC_RGHT,          M(5),
             M(2),      CTL_T(KC_TAB),
            M(3),
             M(4),    KC_ENT, KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |  ~QWRT |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_FN2,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_TRNS,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      | Play |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolDn |VolUp | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |Brwser|Brwser|
 *                                 |      |      |------|       |------| Back | Fwd  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_MPLY, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_WBAK, KC_WFWD
),


    /* Keymap 3: QWERTY
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Tab    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|  LGui  |
     * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
     * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~BASE|
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
     *                                 ,------|------|------|       |------+--------+------.
     *                                 |      |      | Home |       | PgUp |        |      |
     *                                 | Bksp |  Del |------|       |------| Enter  |Space |
     *                                 |      |      | End  |       | PgDn |        |      |
     *                                 `--------------------'       `----------------------'
     */
    [QWRT] = KEYMAP(
                    // left hand
                    KC_EQL,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_LEFT,
                    KC_TAB,        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   TG(SYMB),
                    KC_BSPC,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
                    KC_LSFT,        CTL_T(KC_Z),  KC_X,   KC_C,   KC_V,   KC_B,   ALL_T(KC_NO),
                    LT(SYMB,KC_GRV),KC_QUOT,      LALT(KC_LSFT),  KC_LEFT,KC_RGHT,
                                                                    ALT_T(KC_APP),  KC_LGUI,
                                                                                    KC_HOME,
                                                                        KC_BSPC,KC_DEL,KC_END,
                    
                    // right hand
                    KC_RGHT,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
                    TG(SYMB),       KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_BSLS,
                    KC_H,   KC_J,   KC_K,   KC_L,   LT(MDIA, KC_SCLN),KC_LGUI,
                    MEH_T(KC_NO),KC_N,   KC_M,   KC_COMM,KC_DOT, CTL_T(KC_SLSH),   KC_RSFT,
                    KC_UP,  KC_DOWN,KC_LBRC,KC_RBRC,          KC_FN1,
                    KC_LALT,        CTL_T(KC_ESC),
                    KC_PGUP,
                    KC_PGDN,KC_ENT, KC_SPC
                    ),

};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(BASE),               // FN1 - Momentary Base Layer
    [2] = ACTION_LAYER_TAP_TOGGLE(QWRT)                // FN2 - Momentary QWERTY Layer
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
        case 5:
        if (record->event.pressed) {
          register_code(KC_LGUI);
          register_code(KC_Z);
          unregister_code(KC_LGUI);
          unregister_code(KC_Z);
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

qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for n, twice for colon
  [TD_N_COLN]  = ACTION_TAP_DANCE_DOUBLE(KC_N, KC_COLN)
};


