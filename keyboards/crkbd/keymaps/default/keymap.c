#include QMK_KEYBOARD_H


extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _______ KC_TRNS
#define USEDKEY KC_TRNS
#define GUI(X) MT(MOD_LGUI, X)
#define ALT(X) MT(MOD_LALT, X)
#define SFT(X) MT(MOD_LSFT, X)
#define CTL(X) MT(MOD_LCTL, X)
#define L(X,Y) LT(M(X), Y)
#define RH(X0, X1, X2, X3, X4, X5) {X5, X4, X3, X2, X1, X0}

enum custom_keycodes {
  QWERTY,
  SYMBOLS,
  RAISE,
  LOWER,
  MIDDLE,
  ARROWS,
  MOUSE,
  BACKLIT,

  // macros
  VUP,
  VDOWN,
  VLEFT,
  VRIGHT,
  VQUIT,
  VSAVE,
  VQUIT_SAVE,
  FLEFT,
  FRIGHT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QWERTY] = {
	  {KC_ESC,    KC_Q,    KC_W,           KC_E,            KC_R,      KC_T        },
	  {KC_TAB,    KC_A,    L(MOUSE, KC_S), L(MIDDLE, KC_D), GUI(KC_F), CTL(KC_G)   },
	  {KC_MINS,   KC_Z,    KC_X,           KC_C,            KC_V,      KC_B        },
	  {XXXXXXX,   XXXXXXX, XXXXXXX,        _______,         KC_LALT,   SFT(KC_ENT) },

	  RH( KC_Y,               KC_U,       KC_I,      KC_O,    KC_P,               KC_BSPC   ),
          RH( CTL(KC_H),          GUI(KC_J),  KC_K,      KC_L,    L(ARROWS, KC_SCLN), KC_QUOT   ),
          RH( KC_N,               KC_M,       KC_COMM,   KC_DOT,  KC_SLSH,            KC_BSLS   ),
          RH( L(SYMBOLS, KC_SPC), KC_RALT,    _______,   XXXXXXX, XXXXXXX,            XXXXXXX   )
  },

  [SYMBOLS] = {
	  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,      KC_5},
      	  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,    KC_PERC},
      	  {_______, _______, _______, KC_PPLS, KC_EQL,    _______},
      	  {XXXXXXX, XXXXXXX, XXXXXXX, KC_LGUI, MO(LOWER), KC_SPC},

	  RH( KC_6,    KC_7,      KC_8,     KC_9,    KC_0,     KC_BSPC  ),
	  RH( KC_CIRC, KC_AMPR,   KC_ASTR,  KC_LPRN, KC_RPRN,  _______  ),
	  RH( _______, KC_LBRC,   KC_RBRC,  KC_LCBR, KC_RCBR,  _______  ),
	  RH( KC_ENT,  MO(RAISE), KC_RALT,  XXXXXXX, XXXXXXX,  XXXXXXX  )
  },

  [ARROWS] = {
	  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},                      
      	  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},                       
      	  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},                      
      	  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},

	  RH( XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX),                      
      	  RH( XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX),                       
      	  RH( XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),                      
      	  RH( XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX)
  },

  [MOUSE] = {
	  {RESET,   XXXXXXX, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R},                      
      	  {XXXXXXX, KC_ACL0, XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN3},                       
      	  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},                      
      	  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},

	  RH( XXXXXXX, XXXXXXX,    KC_MS_UP,   XXXXXXX,     XXXXXXX, XXXXXXX),                      
      	  RH( XXXXXXX, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, XXXXXXX, XXXXXXX),                       
      	  RH( XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX, XXXXXXX),                      
      	  RH( XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX, XXXXXXX)
  },

  [RAISE] = {
	  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},                      
      	  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},                       
      	  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},                      
      	  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},

	  RH( XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),                      
      	  RH( XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),                       
      	  RH( XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),                      
      	  RH( XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX)
  },

  [LOWER] = {
	  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},                      
      	  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},                       
      	  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},                      
      	  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},

	  RH( XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),                      
      	  RH( XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),                       
      	  RH( XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),                      
      	  RH( XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX)
  },

  [MIDDLE] = {
	  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},                      
      	  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},                       
      	  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},                      
      	  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},

          RH( XXXXXXX,  XXXXXXX,    XXXXXXX,    XXXXXXX,   XXXXXXX, XXXXXXX ),
	  RH( M(VLEFT), M(VDOWN),   M(VUP),     M(VRIGHT), XXXXXXX, XXXXXXX ),
          RH( XXXXXXX,  M(FLEFT),   M(FRIGHT),  XXXXXXX,   XXXXXXX, XXXXXXX ),
          RH( XXXXXXX,  XXXXXXX,    XXXXXXX,    XXXXXXX,   XXXXXXX, XXXXXXX )
  }
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void matrix_init_user(void) {
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(id, record);
#endif
    // set_timelog();
  }

  switch (id) {
    case VUP:
      if (record->event.pressed) {
	return MACRO(T(9), T(K), END);
      }
      break;
    case VDOWN:
      if (record->event.pressed) {
	return MACRO(T(9), T(J), END);
      }
      break;
    case VLEFT:
      if (record->event.pressed) {
	return MACRO(T(9), T(H), END);
      }
      break;
    case VRIGHT:
      if (record->event.pressed) {
	return MACRO(T(9), T(L), END);
      }
      break;
    case VQUIT:
      if (record->event.pressed) {
	return MACRO(D(LSFT),T(SCLN), U(LSFT), T(Q), D(LSFT),T(1), U(LSFT), T(ENT), END);
      }
      break;
    case VSAVE:
      if (record->event.pressed) {
	return MACRO(D(LSFT),T(SCLN), U(LSFT), T(W), T(ENT), END);
      }
      break;
    case VQUIT_SAVE:
      if (record->event.pressed) {
	return MACRO(D(LSFT),T(SCLN), U(LSFT), T(X), T(ENT), END);
      }
      break;
    case FLEFT:
      if (record->event.pressed) {
	return MACRO(D(LCTL), D(LSFT), T(TAB), U(LCTL), U(LSFT), END);
      }
      break;
    case FRIGHT:
      if (record->event.pressed) {
	return MACRO(D(LCTL),T(TAB), U(LCTL), END);
      }
      break;
  }
  return MACRO_NONE;
}
