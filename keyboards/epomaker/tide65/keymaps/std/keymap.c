// Link's default keyboard layout, for all sorts of fun and games.

#include QMK_KEYBOARD_H
#include "config.h"

// Left-hand home row mods
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define CTL_D LCTL_T(KC_D)
#define SFT_F LSFT_T(KC_F)

// Custom caps/tab key
#define TAB_CAPS LT(0,KC_NO)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT( /* Base layer */
        KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,    KC_MUTE,
        TAB_CAPS,   KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,    KC_DEL,
        MO(1),      GUI_A,      ALT_S,      CTL_D,      SFT_F,      KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    KC_ENT,                 KC_HOME,
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,                KC_UP,      KC_END,
        KC_LCTL,    KC_LGUI,    KC_LALT,LT(2,KC_SPC),LT(2,KC_SPC),LT(2,KC_SPC),LT(2,KC_SPC),KC_RALT,                            C(S(KC_M)),             KC_LEFT,    KC_DOWN,    KC_RGHT
    ),
    [1] = LAYOUT( /* Mouse and programming keys */
        KC_GRV,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_TRNS,    KC_TRNS,
        KC_TRNS,    MS_BTN1,    MS_UP,      MS_BTN2,    KC_LBRC,    KC_TRNS,    KC_TRNS,    KC_RBRC,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_NO,      MS_LEFT,    MS_DOWN,    MS_RGHT,    S(KC_9),    S(KC_LBRC), S(KC_RBRC), S(KC_0),    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                KC_TRNS,
        KC_TRNS, C(G(KC_LEFT)), G(KC_TAB),C(G(KC_RGHT)),KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                KC_TRNS,    QK_BOOT,
        KC_TRNS,    KC_TRNS,    LSG(KC_S),  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,                            KC_TRNS,                KC_TRNS,    KC_TRNS,    KC_TRNS
    ),
    [2] = LAYOUT( /* Navigation and copy/paste */
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_MUTE,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    C(KC_Y),    C(KC_T),    KC_TRNS,    KC_HOME,    KC_UP,      KC_END,     KC_PGUP,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_NO,      C(KC_A),    C(KC_S),    KC_LCTL,    KC_LSFT,    KC_TRNS,    KC_TRNS,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_PGDN,    KC_TRNS,    KC_TRNS,                KC_TRNS,
        KC_TRNS,    C(KC_Z),    C(KC_X),    C(KC_C),    C(KC_V),    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,                            KC_TRNS,                KC_TRNS,    KC_TRNS,    KC_TRNS
    )
};

// knob functionality
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
    [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [2] = { ENCODER_CCW_CW(LCTL(KC_MINUS), C(S(KC_EQUAL))) }
};
#endif

// intercept keycode functionality to add custom hold functions
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TAB_CAPS: // catch and override hold value for tab (make it caps lock)
            if (!record->tap.count && record->event.pressed) {
                tap_code16(KC_CAPS);
            } else if (record->event.pressed) {
                tap_code16(KC_TAB);
            }
            return true;
        default:
            return true;
            
    }
    return true;
};

// set caps lock indicator
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color_all(0,255,0);
    }
    return false;
}

// permissive hold per key settings
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // just enable for ctrl and shift
        case CTL_D:
            return true;
        case SFT_F:
            return true;
        case LT(2,KC_SPC):
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}