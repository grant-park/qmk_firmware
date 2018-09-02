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
    // Layers
    PRIMARY,
    RAISE,
    LOWER,
    MOUSE,
    ARROWS,
    MIDDLE,
    DESKTOP_SWITCH,

    // Symbols
    UNDS,
    DQT,

    // Vim
    VUP,
    VDOWN,
    VLEFT,
    VRIGHT,
    VSEARCH_REPLACE,
    VQUIT,
    VSAVE,
    VQUIT_SAVE,

    // Firefox
    FLEFT,
    FRIGHT,

    // IntelliJ
    CLEAN,
    SYNC,
    SEARCH_PROJ,
    SEARCH_CLASS,
    REFORMAT,
    OPTIMIZE_IMPORTS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [PRIMARY] = {
        {KC_Q,      KC_W,          KC_E,           KC_R,                   KC_T,            XXXXXXX, XXXXXXX, KC_Y,            KC_U,                   KC_I,           KC_O,    KC_P},
        {KC_A,      L(MOUSE,KC_S), L(MIDDLE,KC_D), GUI(KC_F),              CTL(KC_G),       XXXXXXX, XXXXXXX, CTL(KC_H),       GUI(KC_J),              L(MIDDLE,KC_K), KC_L,    L(ARROWS,KC_SCLN)},
        {M(UNDS),   KC_X,          KC_C,           L(DESKTOP_SWITCH,KC_V), ALT(KC_B),       XXXXXXX, XXXXXXX, ALT(KC_N),       L(DESKTOP_SWITCH,KC_M), KC_COMM,        KC_DOT,  SFT(KC_BSLS)},
        {XXXXXXX,   XXXXXXX,       XXXXXXX,        XXXXXXX,                L(LOWER,KC_ENT), XXXXXXX, XXXXXXX, L(RAISE,KC_SPC), XXXXXXX,                XXXXXXX,        XXXXXXX, XXXXXXX}
    }, 
    [LOWER] = {
        {LSFT(KC_Q), LSFT(KC_W), LSFT(KC_E), LSFT(KC_R), LSFT(KC_T), XXXXXXX, XXXXXXX, LSFT(KC_Y), LSFT(KC_U), LSFT(KC_I),    LSFT(KC_O),   LSFT(KC_P)},
        {LSFT(KC_A), LSFT(KC_S), LSFT(KC_D), LSFT(KC_F), LSFT(KC_G), XXXXXXX, XXXXXXX, LSFT(KC_H), LSFT(KC_J), LSFT(KC_K),    LSFT(KC_L),   LSFT(KC_SCLN)},
        {LSFT(KC_Z), LSFT(KC_X), LSFT(KC_C), LSFT(KC_V), LSFT(KC_B), XXXXXXX, XXXXXXX, LSFT(KC_N), LSFT(KC_M), LSFT(KC_COMM), LSFT(KC_DOT), LSFT(KC_SLSH)},
        {XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    USEDKEY,    XXXXXXX, XXXXXXX, KC_BSPC,    XXXXXXX,    XXXXXXX,       XXXXXXX,      XXXXXXX}
    },
    [RAISE] = {
        {KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0},
        {KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX, XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN},
        {KC_ESC,  KC_TAB,  KC_PPLS, KC_EQL,  KC_Z,    XXXXXXX, XXXXXXX, KC_MINS, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR},
        {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ESC,  XXXXXXX, XXXXXXX, USEDKEY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
    },
    [MIDDLE] = {
        {KC_GRV,  KC_F1,   KC_F2,   KC_F3,    _______, XXXXXXX, XXXXXXX, _______,  _______,  _______,   _______,   M(DQT)},
        {KC_TILD, KC_F4,   KC_F5,   KC_F6,    _______, XXXXXXX, XXXXXXX, M(VLEFT), M(VDOWN), M(VUP),    M(VRIGHT), KC_QUOT},
        {KC_PIPE, KC_F7,   KC_F8,   KC_F9,    _______, XXXXXXX, XXXXXXX, _______,  M(FLEFT), M(FRIGHT), _______,   KC_SLSH},
        {XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______,  XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX}
    },
    [MOUSE] = {
        {RESET,   KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, XXXXXXX, XXXXXXX, _______, _______,    KC_MS_UP,   _______,     _______},
        {KC_ACL0, KC_ACL1, KC_BTN1, KC_BTN2, KC_BTN3, XXXXXXX, XXXXXXX, _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _______},
        {KC_VOLD, _______, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______,    _______,    _______,     _______},
        {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX}
    },
    [ARROWS] = {
        {M(VQUIT),           M(VSAVE),      _______,        _______,         _______,     XXXXXXX, XXXXXXX, _______,             _______, KC_UP,   _______,  _______},
        {M(CLEAN),           M(SYNC),       M(SEARCH_PROJ), M(SEARCH_CLASS), M(REFORMAT), XXXXXXX, XXXXXXX, M(OPTIMIZE_IMPORTS), KC_LEFT, KC_DOWN, KC_RIGHT, USEDKEY}, 
        {M(VSEARCH_REPLACE), M(VQUIT_SAVE), _______,        _______,         _______,     XXXXXXX, XXXXXXX, _______,             _______, _______, _______,  _______},
        {XXXXXXX,            XXXXXXX,       XXXXXXX,        XXXXXXX,         _______,     XXXXXXX, XXXXXXX, _______,             XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX}
    },
    [DESKTOP_SWITCH] = {
        {LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5),  XXXXXXX, XXXXXXX, LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), LGUI(KC_0)},
        {_______,    _______,    _______,    _______,    _______,     XXXXXXX, XXXXXXX, _______,    _______,    _______,    _______,    _______},
        {_______,    _______,    _______,    _______,    _______,     XXXXXXX, XXXXXXX, _______,    _______,    _______,    _______,    _______},
        {XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,     XXXXXXX, XXXXXXX, _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX}
    }
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch(id) {
        // Symbols
	    case UNDS:
	        if (record->event.pressed) {
	    	    return MACRO(D(LSFT),T(MINS),U(LSFT),END);
	        }
	        break;
	    case DQT:
	        if (record->event.pressed) {
	    	    return MACRO(D(LSFT),T(QUOT),U(LSFT),END);
	        }
	        break;

        // Vim
        case VUP:
	        if (record->event.pressed) {
                return MACRO( T(9), T(K), END);
            }
            break;
        case VDOWN:
	        if (record->event.pressed) {
                return MACRO( T(9), T(J), END);
            }
            break;
        case VLEFT:
	        if (record->event.pressed) {
                return MACRO( T(9), T(H), END);
            }
            break;
        case VRIGHT:
	        if (record->event.pressed) {
                return MACRO( T(9), T(L), END);
            }
            break;
	    case VSEARCH_REPLACE:
	        if (record->event.pressed) {
	    	    return MACRO(T(S),T(SLSH),T(BSLS),D(LSFT),T(PERC),U(LSFT),D(LSFT),T(V),U(LSFT),END);
	        }
	        break;
	    case VQUIT:
	        if (record->event.pressed) {
	    	    return MACRO(D(LSFT),T(SCLN),U(LSFT),T(Q),T(ENT),END);
	        }
	        break;
	    case VSAVE:
	        if (record->event.pressed) {
	    	    return MACRO(D(LSFT),T(SCLN),U(LSFT),T(W),T(ENT),END);
	        }
	        break;
	    case VQUIT_SAVE:
	        if (record->event.pressed) {
	    	    return MACRO(D(LSFT),T(SCLN),U(LSFT),T(X),T(ENT),END);
	        }
	        break;
    
        // Firefox
        case FLEFT:
	        if (record->event.pressed) {
                return MACRO(D(LCTL),T(TAB),U(LCTL),END);
            }
            break;
        case FRIGHT:
	        if (record->event.pressed) {
                return MACRO(D(LCTL),D(LSFT),T(TAB),U(LCTL),U(LSFT),END);
            }
            break;

        // IntelliJ
	    case CLEAN:
	        if (record->event.pressed) {
	    	    return MACRO(D(LGUI),D(LSFT),T(C),U(LGUI),U(LSFT),END);
	        }
	        break;
	    case SYNC:
	        if (record->event.pressed) {
	    	    return MACRO(D(LGUI),D(LALT),T(S),U(LALT),U(LGUI),END);
	        }
	        break;
	    case SEARCH_PROJ:
	        if (record->event.pressed) {
	    	    return MACRO(D(LGUI),D(LSFT),T(F),U(LGUI),U(LSFT),END);
	        }
	        break;
	    case SEARCH_CLASS:
	        if (record->event.pressed) {
	    	    return MACRO(D(LGUI),D(LSFT),T(O),U(LGUI),U(LSFT),END);
	        }
	        break;
	    case REFORMAT:
	        if (record->event.pressed) {
	    	    return MACRO(D(LALT),D(LGUI),T(L),U(LALT),U(LGUI),END);
	        }
	        break;
	    case OPTIMIZE_IMPORTS:
	        if (record->event.pressed) {
	    	    return MACRO(D(LCTL),D(LALT),T(O),U(LALT),U(LCTL),END);
	        }
	        break;
    }
    return MACRO_NONE;
};
