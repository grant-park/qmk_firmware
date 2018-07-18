#include "hadron.h"
#include "bootloader.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "LUFA/Drivers/Peripheral/TWI.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#ifdef USE_I2C
#include "i2c.h"
#endif
#ifdef SSD1306OLED
#include "ssd1306.h"
#endif
extern keymap_config_t keymap_config;

//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _LATEX 5
#define _CODE 6
#define _GAME 7
#define _MOUSECURSOR 8
#define _SHIFTY 9
#define _ARROWS 10
#define _ADJUST 16

#define _CLEAN 20
#define _SYNC 22
#define _SEARCH_PROJ 24
#define _SEARCH_CLASS 26
#define _REFORMAT 28
#define _HORIZ 30
#define _VERT 32
#define _TMUX 34

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  GAME,
  LOWER,
  RAISE,
  MOUSECURSOR,
  BACKLIT,
  RGBLED_TOGGLE,
  RGBLED_STEP_MODE,
  RGBLED_INCREASE_HUE,
  RGBLED_DECREASE_HUE,
  RGBLED_INCREASE_SAT,
  RGBLED_DECREASE_SAT,
  RGBLED_INCREASE_VAL,
  RGBLED_DECREASE_VAL,
  ARROWS,
  CLEAN,
  SYNC,
  SEARCH_PROJ,
  SEARCH_CLASS,
  REFORMAT,
  OPTIMPORTS,
  HORIZ,
  VERT,
  TMUX,
  LATEX,
  CODE,
  SHIFTY
};

enum macro_keycodes {
  KC_DEMOMACRO,
  KC_CLEAN,
  KC_SYNC,
  KC_SEARCH_PROJ,
  KC_SEARCH_CLASS,
  KC_REFORMAT,
  KC_OPTIMPORTS,
  KC_HORIZ,
  KC_VERT,
  KC_TMUX,
  VIMUP,
  VIMDOWN,
  VIMLEFT,
  VIMRIGHT,
  SEARCHP,
  SEARCHC,
  OPTIMIZE,
  SEARCHREPLACE,
  DQT,
  UNDS,
  PLUS,
  LBRC,
  RBRC,
  FOX_LEFT,
  FOX_RIGHT,
  WORKUP,
  WORKDOWN
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
// Custom macros
#define CTL_ESC     CTL_T(KC_ESC)               // Tap for Esc, hold for Ctrl
#define CTL_TTAB    CTL_T(KC_TAB)               // Tap for Esc, hold for Ctrl
#define CTL_ENT     CTL_T(KC_ENT)               // Tap for Enter, hold for Ctrl
#define SFT_ENT     SFT_T(KC_ENT)               // Tap for Enter, hold for Shift
// Requires KC_TRNS/_______ for the trigger key in the destination layer
#define LT_MC(kc)   LT(_MOUSECURSOR, kc)        // L-ayer T-ap M-ouse C-ursor
#define LT_RAI(kc)  LT(_RAISE, kc)              // L-ayer T-ap to Raise
#define DEMOMACRO   M(KC_DEMOMACRO)            // Sample for macros
#define CLEAN       M(KC_CLEAN)
#define SYNC        M(KC_SYNC)
#define SEARCH_PROJ M(KC_SEARCH_PROJ)
#define SEARCH_CLASS M(KC_SEARCH_CLASS)
#define REFORMAT    M(KC_REFORMAT)
#define OPTIMPORTS  M(KC_OPTIMPORTS)
#define HORIZ       M(KC_HORIZ) 
#define VERT        M(KC_VERT)
#define TMUX        M(KC_TMUX)

#define latex(X) LSFT(LCTL(LALT(X)))
#define code(X) LGUI(LCTL(LALT(X)))
#define mouse(X) LT(MO(_MOUSECURSOR), X)
#define lower(X) LT(MO(_LOWER), X)
#define raise(X) LT(MO(_RAISE), X)
#define lgui(X) MT(MOD_LGUI, X)
#define lalt(X) MT(MOD_LALT, X)
#define lctl(X) MT(MOD_LCTL, X)
#define lsft(X) MT(MOD_LSFT, X)

#define tex(X) LT(MO(_LATEX), X)
#define codify(X) LT(MO(_CODE), X)
#define arrows(X) LT(MO(_ARROWS), X)

#define sh(X) LSFT(X)
#define shifty(X) LT(MO(_SHIFTY), X)
#define md(X) LGUI(LSFT(LALT(X)))
#define lcalt(x) MT(MOD_LCTL | MOD_LALT, x)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT( 
  _______,    LCTL(KC_1), LCTL(KC_2),   LCTL(KC_3),   LCTL(KC_4),     LCTL(KC_5),           LCTL(KC_6), LCTL(KC_7), LCTL(KC_8),          LCTL(KC_9),    LCTL(KC_0),  RGB_TOG,\
  KC_DQT,     KC_Q,       KC_W,         KC_E,         KC_R,           KC_T,                 RGB_TOG,    RGB_MOD,    _______,             KC_Y,          KC_U,        KC_I,        KC_O,         KC_P,             KC_QUOT, \
  KC_LPRN,    KC_A,       mouse(KC_S),  lower(KC_D),  lgui(KC_F),     lctl(KC_G),           KC_MPRV,    KC_MPLY,    KC_MNXT,             lctl(KC_H),    lgui(KC_J),  tex(KC_K),   codify(KC_L), arrows(KC_SCLN),  KC_RPRN, \
  KC_LCBR,    lsft(KC_Z), KC_X,         KC_C,         lcalt(KC_V),    lalt(KC_B),           KC_F1,      KC_F2,      TG(MO(_GAME)),       lalt(KC_N),    lcalt(KC_M), KC_COMM,     KC_DOT,       lsft(KC_BSLS),    KC_RCBR, \
  KC_LBRC,    KC_LBRC,    KC_LALT,      M(PLUS),      lower(KC_EQL),  shifty(KC_ENT),       KC_VOLD,    KC_MUTE,    KC_VOLU,             raise(KC_SPC), M(UNDS),     KC_MINS,     KC_SLSH,      KC_RBRC,          KC_RBRC \
),
[_GAME] = LAYOUT( 
  KC_1,         KC_2,       KC_3,         KC_4,           KC_5,         KC_6,      KC_7,       KC_8,          KC_9,    KC_0,        RGB_TOG,  RGB_TOG, \
  KC_Y,         KC_Q,       KC_W,         KC_E,         KC_R,           KC_T,         RGB_TOG,   RGB_MOD,    _______,       KC_Y,    KC_U,        KC_I,        KC_O,         KC_P,             KC_QUOT, \
  KC_H,         KC_A,       KC_S,         KC_D,         KC_F,           KC_G,         KC_MPRV,   KC_MPLY,    KC_MNXT,       KC_H,    KC_J,        KC_K,        KC_L,         KC_SCLN,          KC_RPRN, \
  KC_N,         KC_Z,       KC_X,         KC_C,         KC_V,           KC_B,         KC_E,      KC_R,       _______,       KC_N,    KC_M,        KC_COMM,     KC_DOT,       KC_BSLS,          KC_RCBR, \
  KC_U,         KC_J,       KC_M,         KC_V,         KC_EQL,         KC_ENT,       KC_VOLD,   KC_MUTE,    KC_VOLU,       KC_SPC,  M(UNDS),     KC_MINS,     KC_SLSH,      KC_RBRC,          TG(MO(_GAME)) \
),
[_LOWER] = LAYOUT( 
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,     _______,    _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,    M(WORKUP),   M(WORKDOWN),  _______,      _______,    _______,\
  KC_TILD, _______, _______, _______, _______, _______, _______, _______, _______,  M(VIMLEFT), M(VIMDOWN), M(VIMUP),  M(VIMRIGHT),  _______,    _______, \
  KC_PIPE, _______, _______, _______, _______, _______, _______, _______, _______,  _______,    M(FOX_LEFT), M(FOX_RIGHT),   _______,     _______,    _______,\
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,     _______,    _______,   _______,     _______,    _______\
),
[_RAISE] = LAYOUT( 
  _______, _______,  _______,  _______, _______,     _______,      _______, _______, _______, _______, _______, _______, \
  _______, KC_1,    KC_2,      KC_3,    KC_4,        KC_5,         _______, _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  _______, KC_EXLM, KC_AT,     KC_HASH, KC_DLR,      KC_PERC,      _______, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
  _______, KC_QUOT, KC_TAB,    sh(KC_GRV), KC_SLSH,     KC_PIPE,      _______, _______, _______, KC_GRV, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______, \
  _______, _______, _______,   _______, RCTL(KC_SLSH),     KC_ESC,       _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),
[_MOUSECURSOR] = LAYOUT( 
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, _______, _______, _______, _______, KC_WH_L, KC_MS_U, KC_WH_R, _______,_______, \
  _______, KC_ACL0, _______, KC_BTN1, KC_BTN2, KC_BTN3, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN1, _______, _______, _______, _______, _______  \
),
[_ADJUST] = LAYOUT( 
  RESET,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, KC_MS_U,   KC_F10,  KC_F11,  KC_F12, \
  _______, _______, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, _______, _______, KC_DEL,    RGB_SAD, KC_MS_L, KC_MS_U,  KC_MS_R,  _______, _______,    \
  _______, KC_ACL0, KC_ACL1, KC_BTN1, KC_BTN2, KC_BTN3, _______,  _______,  _______, _______, KC_MS_L, KC_MS_D,  KC_MS_R,  _______, _______,  \
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   BL_INC,  BL_STEP, BL_TOGG,   MI_OFF,  _______, _______,  _______,  _______, BL_DEC,     \
  _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,  _______,  _______, _______    \
),
[_ARROWS] = LAYOUT( 
  _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, _______, \
  _______, KC_F1,  KC_F2, KC_F3, KC_F4, KC_F5, _______, _______, KC_DEL,    _______, _______, KC_UP,   _______, _______, _______,\
  _______, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, _______,  _______,  _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,\
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   BL_INC,  BL_STEP, BL_TOGG,   MI_OFF,  _______, _______, _______, _______, BL_DEC, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______\
),
[_LATEX] = LAYOUT( 
  _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
  _______, latex(KC_Q), latex(KC_W), latex(KC_E), latex(KC_R), latex(KC_T), latex(KC_P7), latex(KC_P8), latex(KC_P9), latex(KC_Y), latex(KC_U), latex(KC_I),    latex(KC_O),   latex(KC_P),    _______, \
  _______, latex(KC_A), latex(KC_S), latex(KC_D), latex(KC_F), latex(KC_G), latex(KC_P4), latex(KC_P5), latex(KC_P6), latex(KC_H), latex(KC_J), latex(KC_K),    latex(KC_L),   latex(KC_SCLN), _______, \
  _______,latex(KC_Z),  latex(KC_X), latex(KC_C), latex(KC_V), latex(KC_B), latex(KC_P1), latex(KC_P2), latex(KC_P3), latex(KC_N), latex(KC_M), latex(KC_COMM), latex(KC_DOT), latex(KC_SLSH), _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______\
),
[_CODE] = LAYOUT( 
  _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
  _______,  code(KC_Q), code(KC_W), code(KC_E), code(KC_R), code(KC_T), code(KC_P7), code(KC_P8), code(KC_P9), code(KC_Y), code(KC_U), code(KC_I),    code(KC_O),   code(KC_P),    _______, \
  _______,  code(KC_A), code(KC_S), code(KC_D), code(KC_F), code(KC_G), code(KC_P4), code(KC_P5), code(KC_P6), code(KC_H), code(KC_J), code(KC_K),    code(KC_L),   code(KC_SCLN), _______, \
  _______,  code(KC_Z), code(KC_X), code(KC_C), code(KC_V), code(KC_B), code(KC_P1), code(KC_P2), code(KC_P3), code(KC_N), code(KC_M), code(KC_COMM), code(KC_DOT), code(KC_SLSH), _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______\
),
[_SHIFTY] = LAYOUT( 
  _______, _______,  _______,   _______,   _______,        _______,   _______,     _______,     _______,      _______,  _______,  _______, \
  _______, sh(KC_Q), sh(KC_W),  sh(KC_E),  sh(KC_R),       sh(KC_T),  sh(KC_P7),   sh(KC_P8),   sh(KC_P9),    sh(KC_Y), sh(KC_U), sh(KC_I),    sh(KC_O),   sh(KC_P),    _______, \
  _______, sh(KC_A), sh(KC_S),  sh(KC_D),  sh(KC_F),       sh(KC_G),  sh(KC_P4),   sh(KC_P5),   sh(KC_P6),    sh(KC_H), sh(KC_J), sh(KC_K),    sh(KC_L),   sh(KC_SCLN), KC_QUOT, \
  _______, sh(KC_Z), sh(KC_X),  sh(KC_C),  sh(KC_V),       sh(KC_B),  sh(KC_P1),   sh(KC_P2),   sh(KC_P3),    sh(KC_N), sh(KC_M), sh(KC_COMM), sh(KC_DOT), sh(KC_SLSH), _______, \
  _______, _______,  _______,   M(PLUS),   lower(KC_EQL),  _______,   RESET,       _______,      _______,     KC_BSPC,  M(UNDS),  KC_MINS,     KC_SLSH,    _______,     _______ \
)
};


// define variables for reactive RGB
bool RGB_INIT = false;
bool TOG_STATUS = false;
int RGB_current_mode;

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    rgblight_mode(RGB_current_mode);
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
          //not sure how to have keyboard check mode and set it to a variable, so my work around
          //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (RGB_INIT) {} else {
          RGB_current_mode = rgblight_config.mode;
          RGB_INIT = true;
        }
        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_STATUS = !TOG_STATUS;
          rgblight_mode(16);
        }
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        rgblight_mode(RGB_current_mode);   // revert RGB to initial mode prior to RGB mode change
        TOG_STATUS = false;
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        //not sure how to have keyboard check mode and set it to a variable, so my work around
        //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (RGB_INIT) {} else {
          RGB_current_mode = rgblight_config.mode;
          RGB_INIT = true;
        }
        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_STATUS = !TOG_STATUS;
          rgblight_mode(15);
        }
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        rgblight_mode(RGB_current_mode);  // revert RGB to initial mode prior to RGB mode change
        layer_off(_RAISE);
        TOG_STATUS = false;
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
    case RGB_MOD:
      //led operations - RGB mode change now updates the RGB_current_mode to allow the right RGB mode to be set after reactive keys are released
      if (record->event.pressed) {
        rgblight_mode(RGB_current_mode);
        rgblight_step();
        RGB_current_mode = rgblight_config.mode;
      }
      return false;
      break;
    case ARROWS:
      if (record->event.pressed) {
        if (RGB_INIT) {} else {
          RGB_current_mode = rgblight_config.mode;
          RGB_INIT = true;
        }
        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_STATUS = !TOG_STATUS;
          rgblight_mode(15);
        }
        layer_on(_ARROWS);
      } else {
        rgblight_mode(RGB_current_mode);  // revert RGB to initial mode prior to RGB mode change
        layer_off(_ARROWS);
        TOG_STATUS = false;
      }
      return false;
      break;
  }
  return true;
}

void matrix_init_user(void) {
  #ifdef USE_I2C
    i2c_master_init();
  #ifdef SSD1306OLED
  // calls code for the SSD1306 OLED
        _delay_ms(400);
        TWI_Init(TWI_BIT_PRESCALE_1, TWI_BITLENGTH_FROM_FREQ(1, 800000));
        iota_gfx_init();   // turns on the display
  #endif
  #endif
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

void matrix_scan_user(void) {
    #ifdef SSD1306OLED
     iota_gfx_task();  // this is what updates the display continuously
    #endif
}

/*
 * Macro definition
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    if (!eeconfig_is_enabled()) {
      eeconfig_init();
    }

    switch (id) {  
      case KC_DEMOMACRO:
        if (record->event.pressed){
          return MACRO (I(1), T(H),T(E),T(L), T(L), T(O), T(SPACE), T(W), T(O), T(R), T(L), T(D),  END);
        }  
    case KC_CLEAN:
      if (record->event.pressed) {
          return MACRO(D(LGUI),D(LSFT),T(C),U(LGUI),U(LSFT),END);
      }
      break;
    case KC_SYNC:
      if (record->event.pressed) {
         return MACRO(D(LGUI),D(LALT),T(S),U(LALT),U(LGUI),END);
      }
      break;
    case KC_SEARCH_PROJ:
      if (record->event.pressed) {
        return MACRO(D(LGUI),D(LSFT),T(F),U(LGUI),U(LSFT),END);
      }
      break;
    case KC_SEARCH_CLASS:
      if (record->event.pressed) {
         return MACRO(D(LGUI),D(LSFT),T(O),U(LGUI),U(LSFT),END);
      }
      break;
    case KC_REFORMAT:
      if (record->event.pressed) {
         return MACRO(D(LALT),D(LGUI),T(L),U(LALT),U(LGUI),END);
      }
      break;
    case KC_OPTIMPORTS:
      if (record->event.pressed) {
         return MACRO(D(LCTL),D(LALT),T(O),U(LCTL),U(LALT),END);
      }
      break;
    case FOX_LEFT:
        if (record->event.pressed) {
    	   return MACRO(D(LCTL),D(LSFT),T(TAB),U(LCTL),U(LSFT),END);
        }
        break;
    case FOX_RIGHT:
        if (record->event.pressed) {
    	  return MACRO(D(LCTL),T(TAB),U(LCTL),END);
        }
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
    case WORKUP:
        if (record->event.pressed) {
            return MACRO( D(LGUI), D(LALT), T(LEFT), U(LALT), U(LGUI), END);
        }
        return false;
        break;
    case WORKDOWN:
        if (record->event.pressed) {
            return MACRO( D(LGUI), D(LALT), T(RGHT), U(LALT), U(LGUI), END);
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
        break;
    case RBRC:
        if (record->event.pressed) {
    	// rbrc 
    	return MACRO(D(LSFT),T(RBRC),U(LSFT),END);
        }
        break;
    }
    return MACRO_NONE;
}

void matrix_update(struct CharacterMatrix *dest,
                          const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

//assign the right code to your layers for OLED display
#define L_BASE 0
#define L_LOWER 8
#define L_RAISE 16
#define L_FNLAYER 64
#define L_NUMLAY 128
#define L_NLOWER 136
#define L_NFNLAYER 192
#define L_MOUSECURSOR 256
#define L_ADJUST 65560

void iota_gfx_task_user(void) {
#if DEBUG_TO_SCREEN
  if (debug_enable) {
    return;
  }
#endif

  struct CharacterMatrix matrix;

  matrix_clear(&matrix);
  matrix_write_P(&matrix, PSTR("USB: "));
#ifdef PROTOCOL_LUFA
  switch (USB_DeviceState) {
    case DEVICE_STATE_Unattached:
      matrix_write_P(&matrix, PSTR("Unattached"));
      break;
    case DEVICE_STATE_Suspended:
      matrix_write_P(&matrix, PSTR("Suspended"));
      break;
    case DEVICE_STATE_Configured:
      matrix_write_P(&matrix, PSTR("Connected"));
      break;
    case DEVICE_STATE_Powered:
      matrix_write_P(&matrix, PSTR("Powered"));
      break;
    case DEVICE_STATE_Default:
      matrix_write_P(&matrix, PSTR("Default"));
      break;
    case DEVICE_STATE_Addressed:
      matrix_write_P(&matrix, PSTR("Addressed"));
      break;
    default:
      matrix_write_P(&matrix, PSTR("Invalid"));
  }
#endif

// Define layers here, Have not worked out how to have text displayed for each layer. Copy down the number you see and add a case for it below

  char buf[40];
  snprintf(buf,sizeof(buf), "Undef-%ld", layer_state);
  matrix_write_P(&matrix, PSTR("\n\nLayer: "));
    switch (layer_state) {
        case L_BASE:
           matrix_write_P(&matrix, PSTR("Default"));
           break;
        case L_RAISE:
           matrix_write_P(&matrix, PSTR("Raise"));
           break;
        case L_LOWER:
           matrix_write_P(&matrix, PSTR("Lower"));
           break;
        case L_ADJUST:
           matrix_write_P(&matrix, PSTR("ADJUST"));
           break;
        default:
           matrix_write(&matrix, buf);
 }
  
  // Host Keyboard LED Status
  char led[40];
    snprintf(led, sizeof(led), "\n%s  %s  %s",
            (host_keyboard_leds() & (1<<USB_LED_NUM_LOCK)) ? "NUMLOCK" : "       ",
            (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) ? "CAPS" : "    ",
            (host_keyboard_leds() & (1<<USB_LED_SCROLL_LOCK)) ? "SCLK" : "    ");
  matrix_write(&matrix, led);
  matrix_update(&display, &matrix);
}

