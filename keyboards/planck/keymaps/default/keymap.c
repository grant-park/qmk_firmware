#include "planck.h"
#include "mousekey.h"
//#include "outputselect.h"
 

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// Fillers to make layering more clear
#define _______ KC_TRNS
// Tap Dance Declarations
enum {
  TD_LAYER_MOUSE = 0
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  // Tap once for layer, tap twice for mouse
  [TD_LAYER_MOUSE] = ACTION_TAP_DANCE_DOUBLE(M(1),M(2))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// QWERTY
[0] = {
  {KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT },
  {KC_LCTL, KC_LALT, KC_LGUI, M(1),    KC_ENT,  _______, KC_SPC,  M(2),    M(5),    _______, KC_RGUI,  _______}
}, 

// Lower

// CLEAN m3, SYNC m4, SEARCH_PROJ m6, SEARCH_CLASS m7, REFORMAT m8
[1] = {
  {KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS},
  {KC_TILD, M(3),    M(4),    M(6),    M(7),    M(8),    _______, _______, _______, KC_LCBR, KC_RCBR, KC_PIPE},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

// Raise
// tmux horiz pane m9, tmux vert pane 10, tmux m11
[2] = {
  {KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL },
  {KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, KC_LBRC, KC_RBRC, KC_BSLS},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, M(11),   M(9),    M(10)  },
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

// Arrow Keys
[3] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______   , _______}
},

/* Mousekeys */
[4] = {
  {_______, _______, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, _______, _______, KC_MS_U, _______, _______, _______},
  {_______, KC_ACL0, KC_ACL1, KC_BTN1, KC_BTN2, KC_BTN3, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_ACL1, KC_ACL2, _______, _______}
}

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case 1:
      if (record->event.pressed) {
        layer_on(1);
        update_tri_layer(1,2,4);
      } else {
        layer_off(1);
        update_tri_layer(1,2,4);
      }
      break;
    case 2:
      if (record->event.pressed) {
        layer_on(2);
        update_tri_layer(1,2,4);
      } else {
        layer_off(2);
        update_tri_layer(1,2,4);
      }
      break;
    case 3:
      // clean
      if (record->event.pressed) {
          return MACRO(D(LGUI),D(LSFT),T(C),U(LGUI),U(LSFT),END);
      }
      break;
    case 4:
      // sync
      if (record->event.pressed) {
          return MACRO(D(LGUI),D(LALT),T(S),U(LALT),U(LGUI),END);
      }
      break;
    case 5:
      if (record->event.pressed) {
          layer_on(3);
      } else {
          layer_off(3);
      }
      break;
    case 6:
      // search proj
      if (record->event.pressed) {
          return MACRO(D(LGUI),D(LSFT),T(F),U(LGUI),U(LSFT),END);
      }
      break;
    case 7:
      // search class
      if (record->event.pressed) {
          return MACRO(D(LGUI),D(LSFT),T(O),U(LGUI),U(LSFT),END);
      }
      break;
    case 8:
      // reformat 
      if (record->event.pressed) {
	  return MACRO(D(LALT),D(LGUI),T(L),U(LALT),U(LGUI),END);
      }
      break;
    case 9:
      // reformat 
      if (record->event.pressed) {
	  return MACRO(D(LCTL),D(F),U(LCTL),U(F),D(LSFT),T(QUOT),U(LSFT),END);
      }
      break;
    case 10:
      // reformat 
      if (record->event.pressed) {
	  return MACRO(D(LCTL),D(F),U(LCTL),U(F),D(LSFT),T(5),U(LSFT),END);
      }
      break;
    case 11:
      // reformat 
      if (record->event.pressed) {
	  return MACRO(D(LCTL),D(F),U(LCTL),U(F),END);
      }
      break;
  }
  return MACRO_NONE;

};

//void matrix_init_user() {
//  _delay_ms(500); // give time for usb to initialize
//
//  // auto detect output on init
//#ifdef MODULE_ADAFRUIT_BLE
//  uint8_t output = auto_detect_output();
//  if (output == OUTPUT_USB) {
//    set_output(OUTPUT_USB);
//  } else {
//    set_output(OUTPUT_BLUETOOTH);
//  }
//#endif
//}
