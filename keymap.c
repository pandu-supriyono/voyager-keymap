#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

bool is_cmd_tab_active = false;
uint16_t cmd_tab_timer = 0;

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  CMD_TAB,
  CMD_SHIFT_TAB,
};



#define DUAL_FUNC_0 LT(5, KC_F4)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    LT(4, KC_MINUS),KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           LT(4, KC_EQUAL),
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,        
    ALL_T(KC_ESCAPE),KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        ALL_T(KC_QUOTE),
    KC_LEFT_SHIFT,  MT(MOD_LCTL, KC_Z),MT(MOD_LALT, KC_X),KC_C,           KC_V,           MT(MOD_LGUI, KC_B),                                MT(MOD_RGUI, KC_N),KC_M,           KC_COMMA,       MT(MOD_RALT, KC_DOT),MT(MOD_RCTL, KC_SLASH),KC_RIGHT_SHIFT, 
                                                    KC_BSPC,        LT(1, KC_DELETE),                                LT(1, KC_ENTER),KC_SPACE
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_F10,         KC_F11,         KC_F12,         KC_TRANSPARENT,                                 LGUI(LSFT(KC_4)),KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_F7,          KC_F8,          KC_F9,          KC_TRANSPARENT,                                 KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,  KC_TRANSPARENT,
    LGUI(KC_GRAVE), KC_TRANSPARENT, KC_F4,          KC_F5,          KC_F6,          KC_TRANSPARENT,                                 KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       CMD_SHIFT_TAB,  CMD_TAB,
    LGUI(KC_LBRC),  LGUI(KC_RBRC),  KC_F1,          KC_F2,          KC_F3,          KC_TRANSPARENT,                                 KC_PAGE_UP,     KC_PGDN,        KC_HOME,        KC_END,         LGUI(LSFT(KC_LBRC)),LGUI(LSFT(KC_RBRC)),
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_LEFT_ALT,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, DUAL_FUNC_0,    
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_ESCAPE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_J,          KC_K,           KC_L,           KC_SCLN,        KC_QUOTE,       
    KC_TRANSPARENT, KC_Z,           KC_X,           KC_TRANSPARENT, KC_TRANSPARENT, KC_B,                                           KC_N,           KC_TRANSPARENT, KC_TRANSPARENT, KC_DOT,         KC_SLASH,       KC_TRANSPARENT, 
                                                    KC_SPACE,       KC_LEFT_CTRL,                                   KC_TRANSPARENT, KC_BSPC
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F12,         
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_GRAVE,       KC_EXLM,        KC_DLR,         KC_LCBR,        KC_RCBR,        KC_HASH,                                        KC_7,           KC_8,           KC_9,           KC_MINUS,       KC_SLASH,       KC_F12,         
    KC_TRANSPARENT, KC_CIRC,        KC_AMPR,        KC_LPRN,        KC_RPRN,        KC_ASTR,                                        KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_ASTR,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_AT,          KC_LBRC,        KC_RBRC,        KC_PERC,                                        KC_1,           KC_2,           KC_3,           KC_DOT,         KC_EQUAL,       KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_0
  ),
};


const uint16_t PROGMEM combo0[] = { KC_0, KC_BSLS, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, TG(2)),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(4, KC_MINUS):
            return TAPPING_TERM -10;
        case KC_TAB:
            return TAPPING_TERM -55;
        case ALL_T(KC_ESCAPE):
            return TAPPING_TERM -10;
        case MT(MOD_LCTL, KC_Z):
            return TAPPING_TERM -10;
        case MT(MOD_LALT, KC_X):
            return TAPPING_TERM -10;
        case MT(MOD_LGUI, KC_B):
            return TAPPING_TERM -10;
        case LT(1, KC_DELETE):
            return TAPPING_TERM -10;
        case LT(4, KC_EQUAL):
            return TAPPING_TERM -10;
        case KC_BSLS:
            return TAPPING_TERM -55;
        case ALL_T(KC_QUOTE):
            return TAPPING_TERM -10;
        case MT(MOD_RGUI, KC_N):
            return TAPPING_TERM -10;
        case MT(MOD_RALT, KC_DOT):
            return TAPPING_TERM -10;
        case MT(MOD_RCTL, KC_SLASH):
            return TAPPING_TERM -10;
        default:
            return TAPPING_TERM;
    }
}


extern rgb_config_t rgb_matrix_config;

RGB hsv_to_rgb_with_value(HSV hsv) {
  RGB rgb = hsv_to_rgb( hsv );
  float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
  return (RGB){ f * rgb.r, f * rgb.g, f * rgb.b };
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255} },

    [1] = { {0,0,0}, {0,0,0}, {86,255,255}, {86,255,255}, {86,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,255}, {86,255,255}, {86,255,255}, {0,0,0}, {255,218,204}, {0,0,0}, {86,255,255}, {86,255,255}, {86,255,255}, {0,0,0}, {255,218,204}, {255,218,204}, {86,255,255}, {86,255,255}, {86,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {40,233,255}, {40,233,255}, {40,233,255}, {0,0,0}, {40,233,255}, {40,233,255}, {40,233,255}, {40,233,255}, {40,233,255}, {0,0,0}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {255,218,204}, {255,218,204}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {255,218,204}, {255,218,204}, {74,255,255}, {0,0,0} },

    [2] = { {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {74,255,255}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {74,255,255}, {74,255,255}, {74,255,255}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245} },

    [3] = { {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [4] = { {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {252,255,232}, {252,255,232}, {131,255,255}, {0,0,0}, {131,255,255}, {131,255,255}, {41,255,255}, {41,255,255}, {131,255,255}, {0,0,0}, {0,0,0}, {131,255,255}, {188,255,255}, {188,255,255}, {131,255,255}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {131,255,255}, {131,255,255}, {74,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {131,255,255}, {131,255,255}, {0,0,0}, {219,255,255}, {219,255,255}, {219,255,255}, {131,255,255}, {131,255,255}, {0,0,0}, {0,0,0}, {219,255,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb_with_value(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (!keyboard_config.disable_layer_led) { 
    switch (biton32(layer_state)) {
      case 0:
        set_layer_color(0);
        break;
      case 1:
        set_layer_color(1);
        break;
      case 2:
        set_layer_color(2);
        break;
      case 3:
        set_layer_color(3);
        break;
      case 4:
        set_layer_color(4);
        break;
     default:
        if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
          rgb_matrix_set_color_all(0, 0, 0);
        }
    }
  } else {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
      rgb_matrix_set_color_all(0, 0, 0);
    }
  }

  return true;
}




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QK_MODS ... QK_MODS_MAX:
    // Mouse and consumer keys (volume, media) with modifiers work inconsistently across operating systems,
    // this makes sure that modifiers are always applied to the key that was pressed.
    if (IS_CONSUMER_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
      if (record->event.pressed) {
        add_mods(QK_MODS_GET_MODS(keycode));
        send_keyboard_report();
        wait_ms(2);
        register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
        return false;
      } else {
        wait_ms(2);
        del_mods(QK_MODS_GET_MODS(keycode));
      }
    }
    break;

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_EQUAL);
        } else {
          unregister_code16(KC_EQUAL);
        }
      } else {
        if (record->event.pressed) {
          layer_move(0);
        } else {
          layer_move(0);
        }  
      }  
      return false;
    case CMD_TAB:
      if (record->event.pressed) {
        if (!is_cmd_tab_active) {
          is_cmd_tab_active = true;
          register_code(KC_LGUI);
        }
        cmd_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      return false;
    case CMD_SHIFT_TAB:
      if (record->event.pressed) {
        if (!is_cmd_tab_active) {
          is_cmd_tab_active = true;
          register_code(KC_LGUI);
        }
        cmd_tab_timer = timer_read();
        register_code(KC_LSFT);
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
        unregister_code(KC_LSFT);
      }
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

void matrix_scan_user(void) {
  if (is_cmd_tab_active) {
    if (timer_elapsed(cmd_tab_timer) > 500) {
      unregister_code(KC_LGUI);
      is_cmd_tab_active = false;
    }
  }
}
