#include "centromere.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum telophase_layers
{
	_QWERTY,
	_LOWER,
	_RAISE,
	_ADJUST,
    _MOUSECURSOR,
    _SHIFTY,
    _ARROWS
};

enum centromere_keycodes
{
  LOWER = SAFE_RANGE,
  RAISE,
  ADJUST
};

enum macro_keycodes {
  VIMUP,
  VIMDOWN,
  VIMLEFT,
  VIMRIGHT,
  DQT,
  UNDS,
  PLUS,
  LBRC,
  RBRC,
  FOX_LEFT,
  FOX_RIGHT
};

// Fillers to make layering more clear
#define XXXXXXX KC_NO
#define _______ KC_TRNS

#define mouse(X) LT(MO(_MOUSECURSOR), X)
#define arrows(X) LT(MO(_ARROWS), X)
#define lower(X) LT(MO(_LOWER), X)
#define raise(X) LT(MO(_RAISE), X)
#define shifty(X) LT(MO(_SHIFTY), X)

#define lgui(X) MT(MOD_LGUI, X)
#define lalt(X) MT(MOD_LALT, X)
#define lctl(X) MT(MOD_LCTL, X)
#define lsft(X) MT(MOD_LSFT, X)

#define sh(X) LSFT(X)
#define md(X) LGUI(LSFT(LALT(X)))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = {
	{KC_DQT,  KC_Q,       KC_W,          KC_E,           KC_R,       KC_T,       XXXXXXX, XXXXXXX, KC_Y,       KC_U,       KC_I,          KC_O,    KC_P,            KC_QUOT},
	{KC_LPRN, KC_A,       mouse(KC_S),   lower(KC_D),    lgui(KC_F), lctl(KC_G), XXXXXXX, XXXXXXX, lctl(KC_H), lgui(KC_J), KC_K,          KC_L,    arrows(KC_SCLN), KC_RPRN},
	{KC_LCBR, lsft(KC_Z), KC_X,          KC_C,           KC_V,       lalt(KC_B), XXXXXXX, XXXXXXX, lalt(KC_N), KC_M,       KC_COMM,       KC_DOT,  lsft(KC_BSLS),   KC_RCBR},
    {XXXXXXX, XXXXXXX,    lower(KC_EQL), shifty(KC_ENT), KC_2,       M(PLUS),    XXXXXXX, XXXXXXX, KC_MINS,    KC_3,       raise(KC_SPC), M(UNDS), XXXXXXX,         XXXXXXX},
	{XXXXXXX, XXXXXXX,    XXXXXXX,       XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,       XXXXXXX, XXXXXXX,         XXXXXXX }
}, 

[_LOWER] = {
  {_______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, _______,    _______,     _______,      _______,     _______, _______},
  {_______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, M(VIMLEFT), M(VIMDOWN),  M(VIMUP),     M(VIMRIGHT), _______, _______},
  {_______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, _______,    M(FOX_LEFT), M(FOX_RIGHT), _______,     _______, _______},
  {XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, _______,    _______,     _______,      _______,     XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,     XXXXXXX,      XXXXXXX,     XXXXXXX, XXXXXXX}
}, 

[_RAISE] = {
  {_______, KC_1,    KC_2,          KC_3,    KC_4,    KC_5,    XXXXXXX, XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______},
  {_______, KC_EXLM, KC_AT,         KC_HASH, KC_DLR,  KC_PERC, XXXXXXX, XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______},
  {_______, KC_QUOT, KC_TAB,        KC_TILD, KC_SLSH, KC_PIPE, XXXXXXX, XXXXXXX, KC_GRV,  KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______},
  {XXXXXXX, XXXXXXX, RCTL(KC_SLSH), KC_ESC,  _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
},

[_MOUSECURSOR] = {
  {_______, _______, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R,  XXXXXXX, XXXXXXX, _______, KC_WH_L, KC_MS_U, KC_WH_R, _______, _______},
  {_______, KC_ACL0, _______, KC_BTN1, KC_BTN2, KC_BTN3,  XXXXXXX, XXXXXXX, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______},
  {_______, _______, _______, _______, _______, _______,  XXXXXXX, XXXXXXX, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5, _______, _______},
  {XXXXXXX, XXXXXXX, _______, _______, _______, _______,  XXXXXXX, XXXXXXX, _______, _______, KC_BTN1, _______, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
},

[_ARROWS] = {
  {_______, _______, _______, _______, _______, _______,  XXXXXXX, XXXXXXX, _______, _______, KC_UP,   _______, _______, _______},
  {_______, _______, _______, _______, _______, _______,  XXXXXXX, XXXXXXX, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______},
  {_______, _______, _______, _______, _______, _______,  XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______},
  {XXXXXXX, XXXXXXX, _______, _______, _______, _______,  XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
},

[_SHIFTY] = {
  {_______, sh(KC_Q), sh(KC_W), sh(KC_E), sh(KC_R), sh(KC_T), XXXXXXX,   XXXXXXX, sh(KC_Y), sh(KC_U), sh(KC_I),    sh(KC_O),   sh(KC_P),    _______},
  {_______, sh(KC_A), sh(KC_S), sh(KC_D), sh(KC_F), sh(KC_G), XXXXXXX,   XXXXXXX, sh(KC_H), sh(KC_J), sh(KC_K),    sh(KC_L),   sh(KC_SCLN), KC_QUOT},
  {_______, sh(KC_Z), sh(KC_X), sh(KC_C), sh(KC_V), sh(KC_B), XXXXXXX,   XXXXXXX, sh(KC_N), sh(KC_M), sh(KC_COMM), sh(KC_DOT), sh(KC_SLSH), _______},
  {XXXXXXX, XXXXXXX,  _______,  _______,  _______,  RESET,    XXXXXXX,   XXXXXXX, KC_MINS,  _______,  KC_BSPC,     M(UNDS),    XXXXXXX,     XXXXXXX},
  {XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,    XXXXXXX,     XXXXXXX}
},

// [_RAISE] = {
//   {_______, _______, _______, _______, _______, _______   XXXXXXX,   XXXXXXX, _______, _______, _______, _______, _______, _______},
//   {_______, _______, _______, _______, _______, _______,  XXXXXXX,   XXXXXXX, _______, _______, _______, _______, _______, _______},
//   {_______, _______, _______, _______, _______, _______,  XXXXXXX,   XXXXXXX, _______, _______, _______, _______, _______, _______},
//   {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,  XXXXXXX,   XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX},
//   {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
// },


[_ADJUST] = {
  {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    XXXXXXX,   XXXXXXX,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12 },
  {_______, RESET  , _______, _______, _______, _______,  XXXXXXX,   XXXXXXX, _______, _______, _______, _______, _______,   KC_DEL },
  {_______, _______, _______, AU_ON,   AU_OFF,  _______,  XXXXXXX,   XXXXXXX, _______, _______,  _______, _______,  _______, _______},
  {_______, _______, _______, _______, _______, _______,  XXXXXXX,   XXXXXXX, _______, _______, _______,  KC_HOME, XXXXXXX, XXXXXXX  },
  {_______, _______, _______, _______, _______, _______,  XXXXXXX,   XXXXXXX,_______, _______, _______, _______, _______, _______   }
},


};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;

    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;

    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

/*
 * Macro definition
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {  
        case FOX_LEFT:
            if (record->event.pressed) {
        	   return MACRO(D(LCTL),D(LSFT),T(TAB),U(LCTL),U(LSFT),END);
            }
            return false;
            break;
        case FOX_RIGHT:
            if (record->event.pressed) {
        	  return MACRO(D(LCTL),T(TAB),U(LCTL),END);
            }
            return false;
            break;
        case VIMUP:
            if (record->event.pressed) {
                return MACRO( T(9), T(K), END);
            }
            return false;
            break;
        case VIMDOWN:
            if (record->event.pressed) {
                return MACRO( T(9), T(J), END);
            }
            return false;
            break;
        case VIMLEFT:
            if (record->event.pressed) {
                return MACRO( T(2), T(0), T(H), END);
            }
            return false;
            break;
        case VIMRIGHT:
            if (record->event.pressed) {
                return MACRO( T(2), T(0), T(L), END);
            }
            return false;
            break;
        case DQT:
            if (record->event.pressed) {
                return MACRO(D(LSFT),T(QUOT),U(LSFT),END);
            }
            return false;
            break;
        case UNDS:
            if (record->event.pressed) {
                return MACRO(D(LSFT),T(MINS),U(LSFT),END);
            }
            return false;
            break;
        case PLUS:
            if (record->event.pressed) {
                return MACRO(D(LSFT),T(EQL),U(LSFT),END);
            }
            return false;
            break;
        case LBRC:
            if (record->event.pressed) {
        	    // lbrc 
        	    return MACRO(D(LSFT),T(LBRC),U(LSFT),END);
            }
            return false;
            break;
        case RBRC:
            if (record->event.pressed) {
        	    // rbrc 
        	    return MACRO(D(LSFT),T(RBRC),U(LSFT),END);
            }
            return false;
            break;
    }
    return MACRO_NONE;
}

void matrix_scan_user(void) {
		return;
};
