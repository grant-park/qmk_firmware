#include "planck.h"
#define _______ KC_TRNS
#define XXXXXXX KC_TRNS
#define USEDKEY KC_TRNS
#define GUI(X) MT(MOD_LGUI, X)
#define ALT(X) MT(MOD_LALT, X)
#define SFT(X) MT(MOD_LSFT, X)
#define CTL(X) MT(MOD_LCTL, X)
#define L(X,Y) LT(M(X), Y)

enum planck_keycodes {
    // LAYERS
    PRIMARY,
    RAISE,
    LOWER,
    MOUSE,
    ARROWS,

    // MACROS
    UNDS,
    DQT,
    LBRC,
    RBRC,
    LPRN,
    RPRN,
    VLEFT,
    VRIGHT,
    VSEARCH_REPLACE,
    FLEFT,
    FRIGHT,
    CLEAN,
    SYNC,
    SEARCH_PROJ,
    SEARCH_CLASS,
    REFORMAT,
    OPTIMIZE_IMPORTS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [PRIMARY] = {
        {KC_Q,      KC_W,      KC_E,       KC_R,       KC_T,        XXXXXXX, XXXXXXX, KC_Y,        KC_U,      KC_I,      KC_O,    KC_P    },
        {KC_A,      L(3,KC_S), L(1,KC_D),  GUI(KC_F),  CTL(KC_G),   XXXXXXX, XXXXXXX, CTL(KC_H),   GUI(KC_J), L(1,KC_K), KC_L,    L(7,KC_SCLN) },
        {M(15),     KC_X,      KC_C,       L(9,KC_V),  ALT(KC_B),   XXXXXXX, XXXXXXX, ALT(KC_N),   L(9,KC_M), KC_COMM,   KC_DOT,  SFT(KC_BSLS) },
        {XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    L(8,KC_ENT), XXXXXXX, XXXXXXX, L(2,KC_SPC), XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX }
    }, 

    [1] = {
        {KC_GRV,  KC_F1,   KC_F2,   KC_F3,   _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______, M(16)},
        {KC_TILD, KC_F4,   KC_F5,   KC_F6,   _______, XXXXXXX, XXXXXXX, M(21),   M(4),    M(5),    M(22),   KC_QUOT},
        {KC_PIPE, KC_F7,   KC_F8,   KC_F9,   _______, XXXXXXX, XXXXXXX, _______, M(23),   M(24),   _______, KC_SLSH},
        {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
    },

    [2] = {
        {KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0 },
        {KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX, XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN},
        {KC_ESC,  KC_TAB,  KC_PPLS, KC_EQL,  KC_Z,    XXXXXXX, XXXXXXX, KC_MINS, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR},
        {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ESC,  XXXXXXX, XXXXXXX, USEDKEY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
    },

    [3] = {
        {RESET,   KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, XXXXXXX, XXXXXXX, _______, _______,    KC_MS_UP,   _______,     _______},
        {KC_ACL0, KC_ACL1, KC_BTN1, KC_BTN2, KC_BTN3, XXXXXXX, XXXXXXX, _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _______},
        {KC_VOLD, _______, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______,    _______,    _______,     _______},
        {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX}
    },

    [7] = {
        {_______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, KC_UP,   _______,  _______},
        {M(8)   , M(9)   , M(10)  , M(11)  , M(12)  , XXXXXXX, XXXXXXX, M(13),   KC_LEFT, KC_DOWN, KC_RIGHT, USEDKEY},
        {_______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______,  _______},
        {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX}
    },

    [8] = {
        {LSFT(KC_Q), LSFT(KC_W), LSFT(KC_E), LSFT(KC_R), LSFT(KC_T), XXXXXXX, XXXXXXX, LSFT(KC_Y), LSFT(KC_U), LSFT(KC_I),    LSFT(KC_O),   LSFT(KC_P)},
        {LSFT(KC_A), LSFT(KC_S), LSFT(KC_D), LSFT(KC_F), LSFT(KC_G), XXXXXXX, XXXXXXX, LSFT(KC_H), LSFT(KC_J), LSFT(KC_K),    LSFT(KC_L),   LSFT(KC_SCLN)},
        {LSFT(KC_Z), LSFT(KC_X), LSFT(KC_C), LSFT(KC_V), LSFT(KC_B), XXXXXXX, XXXXXXX, LSFT(KC_N), LSFT(KC_M), LSFT(KC_COMM), LSFT(KC_DOT), LSFT(KC_SLSH)},
        {XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    USEDKEY,    XXXXXXX, XXXXXXX, KC_BSPC,    XXXXXXX,    XXXXXXX,       XXXXXXX,      XXXXXXX}
    },

    [9] = {
        {LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5),  XXXXXXX, XXXXXXX, LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), LGUI(KC_0) },
        {_______,    _______,    _______,    _______,    _______,     XXXXXXX, XXXXXXX, _______,    _______,    _______,    _______,    _______},
        {_______,    _______,    _______,    _______,    _______,     XXXXXXX, XXXXXXX, _______,    _______,    _______,    _______,    _______},
        {XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,     XXXXXXX, XXXXXXX, _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX}
    }
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch(id) {
        case 1:
            if (record->event.pressed) {
                layer_on(1);
            } else {
                layer_off(3);
                layer_off(1);
            }
            break;
        case 2:
            if (record->event.pressed) {
                layer_off(3);
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
            }
            break;
        case 4:
	        if (record->event.pressed) {
            return MACRO( T(9), T(J), END);
            }
            break;
        case 5:
	        if (record->event.pressed) {
            return MACRO( T(9), T(K), END);
            }
            break;
        case 6:
	        if (record->event.pressed) {
            return MACRO( D(RGUI), T(SPC), U(RGUI), END);
            }
            break;
        case 7:
            if (record->event.pressed) {
                layer_on(7);
            } else {
                layer_off(7);
            }
            break;
	    case 8:
	        if (record->event.pressed) {
	    	// clean
	    	return MACRO(D(LGUI),D(LSFT),T(C),U(LGUI),U(LSFT),END);
	        }
	        break;
	    case 9:
	        if (record->event.pressed) {
	    	// sync
	    	return MACRO(D(LGUI),D(LALT),T(S),U(LALT),U(LGUI),END);
	        }
	        break;
	    case 10:
	        if (record->event.pressed) {
	    	// search proj
	    	return MACRO(D(LGUI),D(LSFT),T(F),U(LGUI),U(LSFT),END);
	        }
	        break;
	    case 11:
	        if (record->event.pressed) {
	    	// search class
	    	return MACRO(D(LGUI),D(LSFT),T(O),U(LGUI),U(LSFT),END);
	        }
	        break;
	    case 12:
	        if (record->event.pressed) {
	    	// reformat
	    	return MACRO(D(LALT),D(LGUI),T(L),U(LALT),U(LGUI),END);
	        }
	        break;
	    case 13:
	        if (record->event.pressed) {
	    	// optimize imports
	    	return MACRO(D(LCTL),D(LALT),T(O),U(LALT),U(LCTL),END);
	        }
	        break;
	    case 14:
	        if (record->event.pressed) {
	    	// vim search replace
	    	return MACRO(T(S),T(SLSH),T(BSLS),D(LSFT),T(PERC),U(LSFT),D(LSFT),T(V),U(LSFT),END);
	        }
	        break;
	    case 15:
	        if (record->event.pressed) {
	    	// unds 
	    	return MACRO(D(LSFT),T(MINS),U(LSFT),END);
	        }
	        break;
	    case 16:
	        if (record->event.pressed) {
	    	// dqt 
	    	return MACRO(D(LSFT),T(QUOT),U(LSFT),END);
	        }
	        break;
	    case 17:
	        if (record->event.pressed) {
	    	// lbrc 
	    	return MACRO(D(LSFT),T(LBRC),U(LSFT),END);
	        }
	        break;
	    case 18:
	        if (record->event.pressed) {
	    	// rbrc 
	    	return MACRO(D(LSFT),T(RBRC),U(LSFT),END);
	        }
	        break;
	    case 19:
	        if (record->event.pressed) {
	    	// lprn 
	    	return MACRO(D(LSFT),T(9),U(LSFT),END);
	        }
	        break;
	    case 20:
	        if (record->event.pressed) {
	    	// rprn 
	    	return MACRO(D(LSFT),T(0),U(LSFT),END);
	        }
	        break;
        case 21:
            // vim left 9
	        if (record->event.pressed) {
            return MACRO( T(9), T(H), END);
            }
            break;
        case 22:
            // vim right 9
	        if (record->event.pressed) {
            return MACRO( T(9), T(L), END);
            }
            break;
        case 23:
            // FOX-RIGHT
	        if (record->event.pressed) {
            return MACRO(D(LCTL),D(LSFT),T(TAB),U(LCTL),U(LSFT),END);
            }
            break;
        case 24:
            // FOX-LEFT
	        if (record->event.pressed) {
            return MACRO(D(LCTL),T(TAB),U(LCTL),END);
            }
            break;
        }
        return MACRO_NONE;
};
