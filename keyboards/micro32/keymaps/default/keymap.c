#include "micro32.h"

#define _______ KC_TRNS
#define USEDKEY KC_TRNS
#define GUI(X) MT(MOD_LGUI, X)
#define ALT(X) MT(MOD_LALT, X)
#define SFT(X) MT(MOD_LSFT, X)
#define CTL(X) MT(MOD_LCTL, X)
#define L(X,Y) LT(M(X), Y)
#define JET(X) LCTL(LALT(X))

enum micro32_keycodes {
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
	VSEARCH_REPLACE,
	VQUIT,
	VSAVE,
	VQUIT_SAVE,

	// Firefox
	FLEFT,
	FRIGHT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [PRIMARY] = KEYMAP(
        KC_Q,    KC_W,          KC_E,           KC_R,            KC_T,            KC_Y,      KC_U,            KC_I,           KC_O,   KC_P,              \
        KC_A,    L(MOUSE,KC_S), L(MIDDLE,KC_D), GUI(KC_F),       CTL(KC_G),       CTL(KC_H), GUI(KC_J),       L(MIDDLE,KC_K), KC_L,   L(ARROWS,KC_SCLN), \
        M(UNDS), KC_X,          KC_C,           L(DESKTOP,KC_V), ALT(KC_B),       ALT(KC_N), L(DESKTOP,KC_M), KC_COMM,        KC_DOT, SFT(KC_SLSH),      \
                                                                 L(LOWER,KC_ENT), L(RAISE,KC_SPC)
    ), 
    [LOWER] = KEYMAP(
        LSFT(KC_Q), LSFT(KC_W), LSFT(KC_E), LSFT(KC_R), LSFT(KC_T), LSFT(KC_Y), LSFT(KC_U), LSFT(KC_I),    LSFT(KC_O),   LSFT(KC_P),    \
        LSFT(KC_A), LSFT(KC_S), LSFT(KC_D), LSFT(KC_F), LSFT(KC_G), LSFT(KC_H), LSFT(KC_J), LSFT(KC_K),    LSFT(KC_L),   LSFT(KC_SCLN), \
        LSFT(KC_Z), LSFT(KC_X), LSFT(KC_C), LSFT(KC_V), LSFT(KC_B), LSFT(KC_N), LSFT(KC_M), LSFT(KC_COMM), LSFT(KC_DOT), LSFT(KC_SLSH), \
                                                        USEDKEY,    KC_BSPC
    ),
    [RAISE] = KEYMAP(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    \
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, \
        KC_ESC,  KC_TAB,  KC_PPLS, KC_EQL,  KC_Z,    KC_MINS, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, \
                                            KC_ESC,  USEDKEY
    ),
    [MIDDLE] = KEYMAP(
        KC_GRV,  KC_F1, KC_F2, KC_F3, _______, _______,  _______,  _______,   _______,   M(DQT),  \
        KC_TILD, KC_F4, KC_F5, KC_F6, _______, M(VLEFT), M(VDOWN), M(VUP),    M(VRIGHT), KC_QUOT, \
        KC_PIPE, KC_F7, KC_F8, KC_F9, _______, _______,  M(FLEFT), M(FRIGHT), _______,   KC_BSLS, \
                                      _______, _______
    ),
    [MOUSE] = KEYMAP(
        RESET,   KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, _______, _______,    KC_MS_UP,   _______,     _______, \
        KC_ACL0, KC_ACL1, KC_BTN1, KC_BTN2, KC_BTN3, _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _______, \
        KC_VOLD, _______, _______, _______, _______, _______, _______,    _______,    _______,     _______, \
                                            _______, _______
    ),
    [ARROWS] = KEYMAP(
        KC_F1,  KC_F2,  KC_F3,   KC_F4,   KC_F5, _______, _______, KC_UP,   _______,  _______,           \
        KC_F6,  KC_F7,  KC_F8,   KC_F9,   KC_F10,_______, KC_LEFT, KC_DOWN, KC_RIGHT, USEDKEY,           \
        KC_F11, KC_F12, _______, _______, _______,        _______, _______, _______,  _______, _______,  \
                                                                   _______,     _______
    ),
    [DESKTOP] = KEYMAP(
        LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), LGUI(KC_0), \
        KC_VOLD,    KC_VOLU,    KC_MUTE,    KC_MPRV,    KC_MNXT,    _______,    _______,    _______,    _______,    _______,    \
        KC_SLCK,    KC_PAUS,    KC_MPLY,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    \
                                                        _______,    _______
    )
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	switch(id) {
		// Symbols
		case UNDS:
			if (record->event.pressed) {
				register_code(KC_LSFT);
			} else {
				unregister_code(KC_LSFT);
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
				return MACRO(D(LCTL),D(LSFT),T(TAB),U(LCTL),U(LSFT),END);
			}
			break;
		case FRIGHT:
			if (record->event.pressed) {
				return MACRO(D(LCTL),T(TAB),U(LCTL),END);
			}
			break;
	}
	return MACRO_NONE;
};
