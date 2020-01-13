#include "planck.h"
#define _______ KC_TRNS
#define XXXXXXX KC_TRNS
#define USEDKEY KC_TRNS
#define GUI(X) MT(MOD_LGUI, X)
#define ALT(X) MT(MOD_LALT, X)
#define SFT(X) MT(MOD_LSFT, X)
#define CTL(X) MT(MOD_LCTL, X)
#define L(X,Y) LT(M(X), Y)
#define JET(X) LCTL(LALT(X))

enum planck_keycodes {
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
	[PRIMARY] = {
		{KC_Q,      KC_W,          KC_E,           KC_R,          KC_T,        XXXXXXX, XXXXXXX, KC_Y,            KC_U,           KC_I,           KC_O,    KC_P},
		{KC_A,      L(MOUSE,KC_S), L(MIDDLE,KC_D), GUI(KC_F),     CTL(KC_G),   XXXXXXX, XXXXXXX, CTL(KC_H),       GUI(KC_J),      L(MIDDLE,KC_K), KC_L,    L(ARROWS,KC_SCLN)},
		{SFT(KC_Z), KC_X,          KC_C,           L(LOWER,KC_V), ALT(KC_B),   XXXXXXX, XXXXXXX, ALT(KC_N),       L(LOWER, KC_M), KC_COMM,        KC_DOT,  SFT(KC_SLSH)},
		{KC_ESC,    KC_TAB,        KC_MINS,        XXXXXXX,       SFT(KC_ENT), XXXXXXX, XXXXXXX, L(RAISE,KC_SPC), MO(DESKTOP),    KC_BSLS,        KC_QUOT, KC_BSPC}
	}, 
	[RAISE] = {
		{KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0},
		{KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX, XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN},
		{XXXXXXX, XXXXXXX, KC_PPLS, KC_EQL,  XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR},
		{KC_GRV,  KC_TILD, KC_EQL,  XXXXXXX, KC_ESC,  XXXXXXX, XXXXXXX, USEDKEY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
	},
	[LOWER] = {
		{JET(KC_Q),   JET(KC_W),   JET(KC_E),    JET(KC_R), JET(KC_T),   XXXXXXX, XXXXXXX, JET(KC_Y),   JET(KC_U), JET(KC_I),    JET(KC_O),    JET(KC_P)},
		{JET(KC_A),   JET(KC_S),   JET(KC_D),    JET(KC_F), JET(KC_G),   XXXXXXX, XXXXXXX, JET(KC_H),   JET(KC_J), JET(KC_K),    JET(KC_L),    JET(KC_SCLN)},
		{JET(KC_Z),   JET(KC_X),   JET(KC_C),    JET(KC_V), JET(KC_B),   XXXXXXX, XXXXXXX, JET(KC_N),   JET(KC_M), JET(KC_COMM), JET(KC_DOT),  JET(KC_SLSH)},
		{JET(KC_ESC), JET(KC_TAB), JET(KC_MINS), XXXXXXX,   JET(KC_ENT), XXXXXXX, XXXXXXX, JET(KC_SPC), XXXXXXX,   JET(KC_BSLS), JET(KC_QUOT), JET(KC_BSPC)}
	},
	[MIDDLE] = {
		{XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______,  _______,  _______,   _______,   XXXXXXX},
		{XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, M(VLEFT), M(VDOWN), M(VUP),    M(VRIGHT), XXXXXXX},
		{XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______,  M(FLEFT), M(FRIGHT), _______,   XXXXXXX},
		{XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______,  XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX}
	},
	[MOUSE] = {
		{RESET,   KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, XXXXXXX, XXXXXXX, _______, _______,    KC_MS_UP,   _______,     _______},
		{KC_ACL0, _______, KC_BTN1, KC_BTN2, KC_BTN3, XXXXXXX, XXXXXXX, _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _______},
		{_______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______,    _______,    _______,     _______},
		{XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX}
	},
	[ARROWS] = {
		{KC_F1,  KC_F2,  KC_F3,  KC_F4,   KC_F5,   XXXXXXX, XXXXXXX, _______, _______, KC_UP,   _______,  _______},
		{KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10,  XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, USEDKEY}, 
		{KC_F11, KC_F12, KC_F13, KC_F14,  KC_F15,  XXXXXXX, XXXXXXX, _______, _______, _______, _______,  _______},
		{KC_F16, KC_F17, KC_F18, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX}
	},
	[DESKTOP] = {
		{LALT(KC_1), LALT(KC_2), LALT(KC_3), LALT(KC_4), LALT(KC_5),  XXXXXXX, XXXXXXX, LALT(KC_6), LALT(KC_7), LALT(KC_8), LALT(KC_9), LALT(KC_0)},
		{KC_VOLD,    KC_VOLU,    KC_MUTE,    KC_MPRV,    KC_MNXT,     XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______},
		{KC_SLCK,    KC_PAUS,    KC_MPLY,    _______,    _______,     XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______},
		{XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,     XXXXXXX, XXXXXXX, _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX}
	}
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

