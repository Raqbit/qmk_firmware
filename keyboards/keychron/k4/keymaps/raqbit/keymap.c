/*
Copyright 2020 Dimitris Mantzouranis

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "../../quantum/quantum.h"
#include "strings.h"

#include QMK_KEYBOARD_H

enum custom_keycodes {
    RAQ_OUTLOOK = SAFE_RANGE,
    RAQ_GMAIL,
    RAQ_DSC_LUL,
    RAQ_LIGHTS_OFF,
    RAQ_LIGHTS_EVENING,
    RAQ_LIGHTS_WORK,
};

enum unicode_names {
    THUMBSUP,
};

const uint32_t PROGMEM unicode_map[] = {
    [THUMBSUP]  = 0x1F44D,  // 👍
};


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _BASE = 0,
    _FL,
    _DE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/*				+--------------------------------------------------------------------------+-------------------+
				| ESC | F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10| F11| F12|HOME|END|PGUP|PGDN| DEL| RGB|
				+--------------------------------------------------------------------------+----|----|----|----+				
 				|  ~  |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = | BACKSP |NLCK|  / |  * |  - |
 				+--------------------------------------------------------------------------+----|----|----|----+
 				|  TAB  |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [ |  ] |   \  |  7 |  8 |  9 |    |
 				+--------------------------------------------------------------------------+----|----|----|  + +
 				| CAPSLCK |  A |  S |  D |  F |  G |  H |  J |  K |  L |  ; |  ' |  RETURN |  4 |  5 |  6 |    |
 				+--------------------------------------------------------------------------+----|----|----|----+
 				| LSHIFT   |  Z |  X |  C |  V |  B |  N |  M |  , |  . |  / | RSHIFT | UP |  1 |  2 |  3 |    |
 				+--------------------------------------------------------------------------+----|----|----| ENT+
 				|LCTRL| LGUI|  LALT|            SPACE            | RALT| FN|RCTRL| LFT| DWN| RGT|  0 |  . |    |
 				+--------------------------------------------------------------------------+-------------------+
*/ 				
    /*  Row:        0          1          2          3        4        5        6         7        8        9          10         11         12         13         14         15         16         17         18     */
    [_BASE] = { {   KC_ESC,    KC_F1,     KC_F2,     KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,     KC_F10,    KC_F11,    KC_F12,    KC_HOME,   KC_END,    KC_PGUP,   KC_PGDN,   KC_DEL,    RGB_MOD },
                {   KC_GRV,    KC_1,      KC_2,      KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,      KC_0,      KC_MINS,   KC_EQL,    KC_BSPC,   KC_NO,     KC_NLCK,   KC_PSLS,   KC_PAST,   KC_PMNS },
                {   KC_TAB,    KC_Q,      KC_W,      KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,      KC_P,      KC_LBRC,   KC_RBRC,   KC_BSLS,   KC_NO,     KC_P7,     KC_P8,     KC_P9,     KC_PPLS },
                {   KC_CAPS,   KC_A,      KC_S,      KC_D,    KC_F,    KC_G,    KC_H,     KC_J,    KC_K,    KC_L,      KC_SCLN,   KC_QUOT,   KC_NO,     KC_ENT,    KC_NO,     KC_P4,     KC_P5,     KC_P6,     KC_NO   },
                {   KC_LSFT,   KC_NO,     KC_Z,      KC_X,    KC_C,    KC_V,    KC_B,     KC_N,    KC_M,    KC_COMM,   KC_DOT,    KC_SLSH,   KC_NO,     KC_RSFT,   KC_UP,     KC_P1,     KC_P2,     KC_P3,     KC_PENT },
                {   KC_LCTL,   KC_LGUI,   KC_LALT,   KC_NO,   KC_NO,   KC_NO,   KC_SPC,   KC_NO,   KC_NO,   KC_NO,     KC_RALT,   MO(_FL),   KC_RCTL,   KC_LEFT,   KC_DOWN,   KC_RGHT,   KC_P0,     KC_PDOT,   KC_NO   }
              },

/*		  +--------------------------------------------------------------------------+-------------------+
				| RST |SLCK|PAUS|    |BRLR|BRIN|MPRV| PLY|MNXT|MUTE|VLDN|VLUP|    |   |PSCR|    |    | SLP| TOG|
				+--------------------------------------------------------------------------+----|----|----|----+				
 				|     |    |    |    |    |    |    |    |    |    |    |    |    |        |    |    |    | HUE|
 				+--------------------------------------------------------------------------+----|----|----|----+
 				|       |    |    |    |    | 👍 |    |    |    |OUTL|    |    |    |      |    |    |    |    |
 				+--------------------------------------------------------------------------+----|----|----| SPD+
 				|         |    |    | DCE|    |GML |    |    |    |    |    |    |         |    |    |    |    |
 				+--------------------------------------------------------------------------+----|----|----|----+
				|          |    |    |    |    |    |    |    |    |    |    |        |    |Loff|Leve|Lwrk|    |
 				+--------------------------------------------------------------------------+----|----|----| SAT+
 				|     | LALT|  LGUI|                             |     |   |     |    |    |    |    |    |    |
 				+--------------------------------------------------------------------------+-------------------+
*/ 				
    /*  Row:        0          1          2          3        4        5        6         7        8        9          10         11         12         13         14         15         16         17         18     */
    [_FL] =   { {   RESET,  KC_SLCK,  KC_PAUS,   KC_APP,  _______,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC__MUTE, KC__VOLDOWN, KC__VOLUP,  _______,  KC_PSCR,  _______,  _______,  KC_SLEP,  RGB_TOG },
                {   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,     _______,   _______,  _______,    KC_NO,  _______,  _______,  _______,  RGB_HUI },
                {   _______,  _______,  _______,  _______,  _______,  X(THUMBSUP),  _______,  _______,  _______,  RAQ_OUTLOOK,   _______,     _______,   _______,  _______,    KC_NO,  _______,  _______,  _______,  RGB_SPI },
                {   _______,  _______,  _______,  MO(_DE),  _______,  RAQ_GMAIL,  _______,  _______,  _______,  _______,   _______,     _______,     KC_NO,  _______,    KC_NO,  _______,  _______,  _______,    KC_NO },
                {   _______,    KC_NO,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,     _______,     KC_NO,  _______,  _______,  RAQ_LIGHTS_OFF,  RAQ_LIGHTS_EVENING,  RAQ_LIGHTS_WORK,  RGB_SAI },
                {   _______,  KC_LALT,  KC_LGUI,    KC_NO,    KC_NO,    KC_NO,  _______,    KC_NO,    KC_NO,    KC_NO,   _______,     MO(_FL),   _______,  _______,  _______,  _______,  _______,  _______,    KC_NO }
              },

/*				+--------------------------------------------------------------------------+-------------------+
				|     |    |    |    |    |    |    |    |    |    |    |    |    |   |    |    |    |    |    |
				+--------------------------------------------------------------------------+----|----|----|----+				
 				|     |    |    |    |    |    |    |    |    |    |    |    |    |        |    |    |    |    |
 				+--------------------------------------------------------------------------+----|----|----|----+
 				|       |    |    |    |    |    |    |    |    |    |    |    |    |      |    |    |    |    |
 				+--------------------------------------------------------------------------+----|----|----|    +
 				|         |    |    |    |    |    |    |    |    |lul |    |    |         |    |    |    |    |
 				+--------------------------------------------------------------------------+----|----|----|----+
 				|          |    |    |    |    |    |    |    |    |    |    |        |    |    |    |    |    |
 				+--------------------------------------------------------------------------+----|----|----|    +
 				|     |    |     |                             |     |   |     |    |    |    |    |    |    |
 				+--------------------------------------------------------------------------+-------------------+
*/ 				
    /*  Row:        0          1          2          3        4        5        6         7        8        9          10         11         12         13         14         15         16         17         18     */
    [_DE] =   { {   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______ },
                {   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,     _______,   _______,  _______,    KC_NO,  _______,  _______,  _______,  _______ },
                {   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,     _______,   _______,  _______,    KC_NO,  _______,  _______,  _______,  _______ },
                {   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RAQ_DSC_LUL,   _______,     _______,     KC_NO,  _______,    KC_NO,  _______,  _______,  _______,    KC_NO },
                {   _______,  KC_NO,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,     _______,     KC_NO,  _______,  _______,  _______,  _______,  _______,  _______ },
                {   _______,  _______,  _______,  KC_NO,    KC_NO,    KC_NO,  _______,    KC_NO,    KC_NO,    KC_NO,   _______,     MO(_FL),   _______,  _______,  _______,  _______,  _______,  _______,    KC_NO }
              }  

};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case RAQ_OUTLOOK:
        if (!record->event.pressed) {
          SEND_STRING(STRING_OUTLOOK);
        }
        break;
    case RAQ_GMAIL:
        if (!record->event.pressed) {
          SEND_STRING(STRING_GMAIL);
        }
        break;
    case RAQ_DSC_LUL:
        if (!record->event.pressed) {
          SEND_STRING(STRING_DISCORD_EMOTE_LUL);
        }
        break;
    case RAQ_LIGHTS_OFF:
        if(record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_F16));
        } else {
          SEND_STRING(SS_UP(X_LGUI) SS_UP(X_F16));
        }
        break;
    case RAQ_LIGHTS_EVENING:
        if(record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_F17));
        } else {
          SEND_STRING(SS_UP(X_LGUI) SS_UP(X_F17));
        }
        break;
    case RAQ_LIGHTS_WORK:
        if(record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_F18));
        } else {
          SEND_STRING(SS_UP(X_LGUI) SS_UP(X_F18));
        }
        break;
    }
    return true;
};

void dip_switch_update_user(uint8_t index, bool active){
  switch(index){
    case 0:
      if(active){ //BT mode
// do stuff
      }
      else{ //Cable mode
// do stuff
      }
      break;
    case 1:
      if(active){ // Win/Android mode
// do stuff
      }
      else{ // Mac/iOS mode
// do stuff
      }
      break;
  }
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  // debug_enable=true;
  // debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
