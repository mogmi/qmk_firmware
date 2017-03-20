#include "planck.h"
#include "backlight.h"
#include "keymap_extras/keymap_nordic.h"
#include "sv.h"

#define WORKMAN 0
#define LOWER 2
#define RAISE 3

#define K_CMD KC_RGUI

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [WORKMAN] = {
    {KC_TAB,  KC_Q,    KC_D,   KC_R,    KC_W,    KC_B,                KC_J,              KC_F,   KC_U,    KC_P,   SV_OE,   SV_AA},
    {KC_BSPC, KC_A,    KC_S,   KC_H,    KC_T,    KC_G,                KC_Y,              KC_N,   KC_E,    KC_O,   KC_I,    SV_AE},
    {M(0),    KC_Z,    KC_X,   KC_M,    KC_C,    KC_V,                KC_K,              KC_L,   KC_COMM, KC_DOT, KC_SLSH, KC_ENT},
    {KC_LCTL, KC_LALT, KC_DEL, K_CMD,   KC_LSFT, LT(LOWER, KC_BSPC),  LT(RAISE, KC_SPC), KC_ESC, KC_UP,   KC_DOWN,KC_LEFT, KC_RGHT}
  },
  [RAISE] = {
    {KC_TRNS, KC_PERC, NO_CIRC, NO_LESS, NO_LBRC, NO_PLUS, NO_MINS, NO_RBRC, NO_GRTR, NO_EQL,  NO_DLR,  NO_PND},
    {KC_TRNS, KC_HASH, NO_QUO2, NO_LCBR, NO_LPRN, NO_ASTR, NO_SLSH, NO_RPRN, NO_RCBR, NO_APOS, NO_UNDS, NO_EURO},
    {KC_TRNS, SV_BSLS, NO_COLN, KC_EXLM, NO_AMP,  NO_AT,   NO_TILD, SV_PIPE, NO_QUES, NO_SCLN, NO_ACUT, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
  },
  [LOWER] = {
    {KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
    {KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL,  KC_TRNS},
    {KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
  }
};

const uint16_t PROGMEM fn_actions[] = {};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            backlight_step();
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
