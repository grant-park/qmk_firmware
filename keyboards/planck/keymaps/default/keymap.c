#include "planck.h"
#include "mousekey.h"
#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = {
        {KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______, _______,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P},
        {KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______, _______,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN},
        {KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH },
        {KC_ESC,  KC_TAB,  KC_LCTL, M(1),    KC_ENT,  KC_LSFT, KC_RGUI,    KC_SPC,  M(2),    KC_RALT, KC_QUOT, KC_BSPC}
    }, 

    [1] = {
        {KC_GRV , _______, _______, _______, _______, _______, _______, _______, M(4),    KC_UP,   M(5)    ,KC_PLUS},
        {KC_TILD,  _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT,KC_UNDS},
        {KC_BSLS,  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_EQL, KC_MINS},
        {_______, _______, _______, _______, _______, _______, _______,    M(6), M(3),    _______, _______, KC_PIPE}
    },

    [2] = {
        {KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0 },
        {KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN},
        {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, _______,  KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR},
        {KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,  _______, _______, _______, _______}
    },

    [3] = {
        {RESET, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, _______, _______, _______, _______, KC_MS_U, _______, _______},
        {KC_ACL0, KC_ACL1, KC_BTN1, KC_BTN2, KC_BTN3, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______},
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
    }
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch(id) {
        case 1:
            if (record->event.pressed) {
                layer_on(1);
            } else {
                layer_off(1);
            }
            break;
        case 2:
            if (record->event.pressed) {
                layer_on(2);
            } else {
                layer_off(3);
                layer_off(2);
            }
            break;
        case 3:
            if (record->event.pressed) {
                layer_on(3);
            } else {
                layer_off(3);
                layer_off(2);
            }
            break;
        case 4:
            return MACRODOWN( TYPE(KC_9), TYPE(KC_J), END);
            break;
        case 5:
            return MACRODOWN( TYPE(KC_9), TYPE(KC_K), END);
            break;
        case 6:
            return MACRODOWN( DOWN(KC_RGUI), TYPE(KC_SPC), UP(KC_RGUI), END);
            break;

    }
    return MACRO_NONE;
};
