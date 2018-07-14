<<<<<<< HEAD
/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _PLOVER,
  _ADJUST
=======
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
>>>>>>> ff58bedf1d4b580447a0cb24e4336a267c4cdf3c
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
  {M(6),    KC_LCTL, KC_LALT, KC_LGUI, M(1),    KC_ENT,  KC_SPC,  M(2),    KC_RGUI, _______, M(5),    M(6)}
}, 

// Lower
[1] = {
  {KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS},
  {KC_TILD, KC_F1,   KC_F2,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, _______, KC_LCBR, KC_RCBR, KC_PIPE},
  {MI_ON,   MI_OFF,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______  , BL_DEC,  BL_INC,  _______, _______, _______, _______, _______, KC_J,    KC_9,    KC_K,    _______}
},

// Raise
[2] = {
  {KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL },
  {KC_GRV,  _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
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
},

<<<<<<< HEAD
/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_PLOVER] = {
  {KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   },
  {XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC},
  {XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   DEBUG,    RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL },
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  PLOVER,  _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
=======
/* Ambi Mousekeys */
[5] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {KC_WH_L, KC_WH_U, KC_MS_U, KC_WH_D, KC_WH_R, _______, _______, KC_WH_L, KC_WH_U, KC_MS_U, KC_WH_D, KC_WH_R},
  {_______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______},
  {_______, KC_BTN3, KC_BTN1, KC_BTN2, KC_ACL0, _______, _______, KC_ACL0, KC_BTN1, KC_BTN2, KC_BTN3, _______}
>>>>>>> ff58bedf1d4b580447a0cb24e4336a267c4cdf3c
}

};

<<<<<<< HEAD
#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
=======
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
>>>>>>> ff58bedf1d4b580447a0cb24e4336a267c4cdf3c
      }
      break;
    case 2:
      if (record->event.pressed) {
<<<<<<< HEAD
        set_single_persistent_default_layer(_COLEMAK);
=======
        layer_on(2);
        update_tri_layer(1,2,4);
      } else {
        layer_off(2);
        update_tri_layer(1,2,4);
>>>>>>> ff58bedf1d4b580447a0cb24e4336a267c4cdf3c
      }
      break;
    case 3:
      if (record->event.pressed) {
<<<<<<< HEAD
        set_single_persistent_default_layer(_DVORAK);
=======
          return MACRO(D(LCTL),T(LEFT),U(LCTL),END);
>>>>>>> ff58bedf1d4b580447a0cb24e4336a267c4cdf3c
      }
      break;
    case 4:
      if (record->event.pressed) {
          return MACRO(D(LCTL),T(RGHT),U(LCTL),END);
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
      if (record->event.pressed) {
<<<<<<< HEAD
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        PORTE &= ~(1<<6);
      } else {
        unregister_code(KC_RSFT);
        PORTE |= (1<<6);
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
=======
          layer_on(5);
      } else {
          layer_off(5);
>>>>>>> ff58bedf1d4b580447a0cb24e4336a267c4cdf3c
      }
      break;
    // layer 7
    case 7: 
      if (record->event.pressed) {
<<<<<<< HEAD
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
=======
          layer_on(7);
      } else {
          layer_off(7);
>>>>>>> ff58bedf1d4b580447a0cb24e4336a267c4cdf3c
      }
  }
<<<<<<< HEAD
  return true;
}
=======
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
>>>>>>> ff58bedf1d4b580447a0cb24e4336a267c4cdf3c
