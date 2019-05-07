#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _______ KC_TRNS
#define USEDKEY KC_TRNS
#define GUI(X) MT(MOD_LGUI, X)
#define ALT(X) MT(MOD_LALT, X)
#define SFT(X) MT(MOD_LSFT, X)
#define CTL(X) MT(MOD_LCTL, X)
#define L(X,Y) LT(M(X), Y)
#define LONGPRESS_DELAY 150

enum layer {
    // Layers
    PRIMARY,
    RAISE,
    LOWER,
    MOUSE,
    ARROWS,
    MIDDLE,
    DESKTOP,

    // Symbols
    UNDS,
    DQT,

    // Vim
    VUP,
    VDOWN,
    VLEFT,
    VRIGHT,
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
    FIND_REPLACE,
    SEARCH_CLASS,
    REFORMAT,
    OPTIMIZE_IMPORTS,
    STEP_OVER,
    STEP_INTO,
    STEP_OUT,
    RESUME,

    // ChunkWM
    CHUNK_INC_L,
    CHUNK_INC_D,
    CHUNK_INC_U,
    CHUNK_INC_R,
    CHUNK_DEC_L,
    CHUNK_DEC_D,
    CHUNK_DEC_U,
    CHUNK_DEC_R,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [PRIMARY] = LAYOUT(
        KC_Q,      KC_W,          KC_E,           KC_R,            KC_T,            KC_Y,            KC_U,            KC_I,           KC_O,    KC_P, \
        KC_A,      L(MOUSE,KC_S), L(MIDDLE,KC_D), GUI(KC_F),       CTL(KC_G),       CTL(KC_H),       GUI(KC_J),       L(MIDDLE,KC_K), KC_L,    L(ARROWS,KC_SCLN), \
        M(UNDS),   KC_X,          KC_C,           L(DESKTOP,KC_V), ALT(KC_B),       ALT(KC_N),       L(DESKTOP,KC_M), KC_COMM,        KC_DOT,  SFT(KC_BSLS) , \
                   _______,       _______,        _______,         L(LOWER,KC_ENT), L(RAISE,KC_SPC), _______,         _______,        _______, \
                   _______,       _______,        _______,         _______,         _______,         _______,         _______,        _______
    ), 
    [LOWER] = LAYOUT(
        LSFT(KC_Q), LSFT(KC_W), LSFT(KC_E), LSFT(KC_R), LSFT(KC_T), LSFT(KC_Y), LSFT(KC_U), LSFT(KC_I),    LSFT(KC_O),   LSFT(KC_P), \
        LSFT(KC_A), LSFT(KC_S), LSFT(KC_D), LSFT(KC_F), LSFT(KC_G), LSFT(KC_H), LSFT(KC_J), LSFT(KC_K),    LSFT(KC_L),   LSFT(KC_SCLN), \
        LSFT(KC_Z), LSFT(KC_X), LSFT(KC_C), LSFT(KC_V), LSFT(KC_B), LSFT(KC_N), LSFT(KC_M), LSFT(KC_COMM), LSFT(KC_DOT), LSFT(KC_SLSH), \
                    _______,    _______,    _______,    USEDKEY,    KC_BSPC,    _______,    _______,       _______, \
                    _______,    _______,    _______,    _______,    _______,    _______,    _______,       _______
    ),
    [RAISE] = LAYOUT(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, \
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, \
        KC_ESC,  KC_TAB,  KC_PPLS, KC_EQL,  KC_Z,    KC_MINS, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR , \
                 _______, _______, _______, KC_ESC,  USEDKEY, _______, _______, _______, \
                 _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [MIDDLE] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   _______, _______,  _______,  _______,   _______,   M(DQT), \
        KC_TILD, KC_F4,   KC_F5,   KC_F6,   _______, M(VLEFT), M(VDOWN), M(VUP),    M(VRIGHT), KC_QUOT, \
        KC_PIPE, KC_F7,   KC_F8,   KC_F9,   _______, _______,  M(FLEFT), M(FRIGHT), _______,   KC_SLSH, \
                 _______, _______, _______, _______, _______,  _______,  _______,   _______, \
                 _______, _______, _______, _______, _______,  _______,  _______,   _______
    ),
    [MOUSE] = LAYOUT(
        RESET,   KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, _______, _______,    KC_MS_UP,   _______,     _______, \
        KC_ACL0, KC_ACL1, KC_BTN1, KC_BTN2, KC_BTN3, _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _______, \
        _______, _______, _______, _______, _______, _______, _______,    _______,    _______,     _______, \
                 _______, _______, _______, _______, _______, _______,    _______,    _______, \
                 _______, _______, _______, _______, _______, _______,    _______,    _______
    ),
    [ARROWS] = LAYOUT(
        M(VQUIT), M(VSAVE),      _______,         _______,         _______,     _______,             _______,   KC_UP,        _______,       _______, \
        M(CLEAN), M(SYNC),       M(SEARCH_PROJ),  M(SEARCH_CLASS), M(REFORMAT), M(OPTIMIZE_IMPORTS), KC_LEFT,   KC_DOWN,      KC_RIGHT,      USEDKEY, \
        _______,  M(VQUIT_SAVE), M(FIND_REPLACE), _______,         _______,     _______,             M(RESUME), M(STEP_OVER), M(STEP_INTO),  M(STEP_OUT), \
                  _______,       _______,         _______,         _______,     _______,             _______,   _______,      _______, \
                  _______,       _______,         _______,         _______,     _______,             _______,   _______,      _______
    ),
    [DESKTOP] = LAYOUT(
        LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5), LGUI(KC_6),     LGUI(KC_7),     LGUI(KC_8),     LGUI(KC_9),     LGUI(KC_0), \
        KC_VOLD,    KC_VOLU,    KC_MUTE,    KC_MPRV,    KC_MNXT,    M(CHUNK_INC_L), M(CHUNK_INC_D), M(CHUNK_INC_U), M(CHUNK_INC_R), _______, \
        KC_SLCK,    KC_PAUS,    KC_MPLY,    _______,    _______,    M(CHUNK_DEC_L), M(CHUNK_DEC_D), M(CHUNK_DEC_U), M(CHUNK_DEC_R), _______, \
                    _______,    _______,    _______,    _______,    _______,        _______,        _______,        _______, \
                    _______,    _______,    _______,    _______,    _______,        _______,        _______,        _______
    )
};

static uint16_t key_timer;
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch(id) {
        // Symbols
	    case UNDS:
	        if (record->event.pressed) {
                key_timer = timer_read();
                register_code(KC_LSFT);
            } else {
                if (timer_elapsed(key_timer) > LONGPRESS_DELAY) {
                    unregister_code(KC_LSFT);
                } else {
                    unregister_code(KC_LSFT);
	    	        return MACRO(D(LSFT),T(MINS),U(LSFT),END);
                }
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
                //return MACRO(D(LCTL),D(LSFT),T(TAB),U(LCTL),U(LSFT),END);
                return MACRO(D(LGUI),D(LSFT),T(LBRC),U(LGUI),U(LSFT),END);
            }
            break;
        case FRIGHT:
	        if (record->event.pressed) {
                //return MACRO(D(LCTL),T(TAB),U(LCTL),END);
                return MACRO(D(LGUI),D(LSFT),T(RBRC),U(LGUI),U(LSFT),END);
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
	    case FIND_REPLACE:
	        if (record->event.pressed) {
	    	    return MACRO(D(LGUI),D(LSFT),T(R),U(LGUI),U(LSFT),END);
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
	    case STEP_OVER:
	        if (record->event.pressed) {
	    	    return MACRO(D(LSFT),D(LALT),T(T),U(LALT),U(LSFT),END);
	        }
	        break;
	    case STEP_INTO:
	        if (record->event.pressed) {
	    	    return MACRO(D(LSFT),D(LALT),T(E),U(LALT),U(LSFT),END);
	        }
	        break;
	    case STEP_OUT:
	        if (record->event.pressed) {
	    	    return MACRO(D(LSFT),D(LALT),T(Q),U(LALT),U(LSFT),END);
	        }
	        break;
	    case RESUME:
	        if (record->event.pressed) {
	    	    return MACRO(D(LSFT),D(LALT),T(R),U(LALT),U(LSFT),END);
	        }
	        break;

        // ChunkWM
	    case CHUNK_DEC_L:
	        if (record->event.pressed) {
	    	    return MACRO(D(LGUI),D(LSFT),T(A),U(LGUI),U(LSFT),END);
	        }
	        break;
	    case CHUNK_DEC_D:
	        if (record->event.pressed) {
	    	    return MACRO(D(LGUI),D(LSFT),T(S),U(LGUI),U(LSFT),END);
	        }
	        break;
	    case CHUNK_DEC_U:
	        if (record->event.pressed) {
	    	    return MACRO(D(LGUI),D(LSFT),T(W),U(LGUI),U(LSFT),END);
	        }
	        break;
	    case CHUNK_DEC_R:
	        if (record->event.pressed) {
	    	    return MACRO(D(LGUI),D(LSFT),T(D),U(LGUI),U(LSFT),END);
	        }
	        break;
	    case CHUNK_INC_L:
	        if (record->event.pressed) {
	    	    return MACRO(D(LALT),D(LSFT),T(A),U(LALT),U(LSFT),END);
	        }
	        break;
	    case CHUNK_INC_D:
	        if (record->event.pressed) {
	    	    return MACRO(D(LALT),D(LSFT),T(S),U(LALT),U(LSFT),END);
	        }
	        break;
	    case CHUNK_INC_U:
	        if (record->event.pressed) {
	    	    return MACRO(D(LALT),D(LSFT),T(W),U(LALT),U(LSFT),END);
	        }
	        break;
	    case CHUNK_INC_R:
	        if (record->event.pressed) {
	    	    return MACRO(D(LALT),D(LSFT),T(D),U(LALT),U(LSFT),END);
	        }
	        break;
    }
    return MACRO_NONE;
};
