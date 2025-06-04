// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LCTL_T(KC_S)
#define HOME_T LSFT_T(KC_T)

// Right-hand home row mods
#define HOME_N RSFT_T(KC_N)
#define HOME_E RCTL_T(KC_E)
#define HOME_I LALT_T(KC_I)
#define HOME_O RGUI_T(KC_O)

// Left hand layers
#define TMB_ESC LT(_MEDIA, KC_ESC)
#define TMB_SPC LT(_NAV, KC_SPC)

// Right hand layers
#define TMB_ENT LT(_SYM, KC_ENT)
#define TMB_BSPC LT(_NUM, KC_BSPC)
#define TMB_DEL LT(_FUN, KC_DEL)

#define TPD_EQL TD(TD_BGAW)

enum custom_layers {
     _BASE,
     _NAV,
     _MEDIA,
     _NUM,
     _SYM,
     _FUN
};

enum custom_keycodes {
   COPY = SAFE_RANGE,
   CUT,
   PASTE,
   UNDO,
   REDO,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   os_variant_t detected_os = detected_host_os();

   switch (keycode)
   {
      case COPY:
         if (record->event.pressed) {
               if (detected_os == OS_MACOS || detected_os == OS_IOS) {
                  register_code(KC_LGUI);
                  register_code(KC_C);
               }
               else {
                  register_code(KC_LCTL);
                  register_code(KC_C);
               }
            }
            else {
               if (detected_os == OS_MACOS || detected_os == OS_IOS) {
                  unregister_code(KC_C);
                  unregister_code(KC_LGUI);
               }
               else {
                  unregister_code(KC_C);
                  unregister_code(KC_LCTL);
               }
            }
            break;

      case CUT:
         if (record->event.pressed) {
            if (detected_os == OS_MACOS || detected_os == OS_IOS) {
               register_code(KC_LGUI);
               register_code(KC_X);
            }
            else {
               register_code(KC_LCTL);
               register_code(KC_X);
            }
         }
         else {
            if (detected_os == OS_MACOS || detected_os == OS_IOS) {
               unregister_code(KC_X);
               unregister_code(KC_LGUI);
            }
            else {
               unregister_code(KC_X);
               unregister_code(KC_LCTL);
            }
         }
         break;

      case PASTE:
         if (record->event.pressed) {
            if (detected_os == OS_MACOS || detected_os == OS_IOS) {
               register_code(KC_LGUI);
               register_code(KC_V);
            }
            else {
               register_code(KC_LCTL);
               register_code(KC_V);
            }
         }
         else {
            if (detected_os == OS_MACOS || detected_os == OS_IOS) {
               unregister_code(KC_V);
               unregister_code(KC_LGUI);
            }
            else {
               unregister_code(KC_V);
               unregister_code(KC_LCTL);
            }
         }
         break;

      case UNDO:
         if (record->event.pressed) {
            if (detected_os == OS_MACOS || detected_os == OS_IOS) {
               register_code(KC_LGUI);
               register_code(KC_Z);
            }
            else {
               register_code(KC_LCTL);
               register_code(KC_Z);
            }
         }
         else {
            if (detected_os == OS_MACOS || detected_os == OS_IOS) {
               unregister_code(KC_Z);
               unregister_code(KC_LGUI);
            }
            else {
               unregister_code(KC_Z);
               unregister_code(KC_LCTL);
            }
         }
         break;

      case REDO:
         if (record->event.pressed) {
               if (detected_os == OS_MACOS || detected_os == OS_IOS) {
                  register_code(KC_LSFT);
                  register_code(KC_LGUI);
                  register_code(KC_Y);
               }
               else {
                  register_code(KC_LCTL);
                  register_code(KC_Y);
               }
            }
            else {
               if (detected_os == OS_MACOS || detected_os == OS_IOS) {
                  unregister_code(KC_Y);
                  unregister_code(KC_LGUI);
                  unregister_code(KC_LSFT);
               }
               else {
                  unregister_code(KC_Y);
                  unregister_code(KC_LCTL);
               }
            }
            break;
         break;
   }
   return true;
};

enum custom_tap_dance {
   TD_BGAW
};

void big_arrow(tap_dance_state_t *state, void *user_data) {
   switch(state->count) {
      case 1:
         SEND_STRING("=");
         break;
      case 2:
         SEND_STRING("=>");
         break;
   }
};

tap_dance_action_t tap_dance_actions[] = {
   [TD_BGAW] = ACTION_TAP_DANCE_FN(big_arrow)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   [_BASE] = LAYOUT(
      //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_NO,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_NO,
      //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_NO,   HOME_A,  HOME_R,  HOME_S,  HOME_T,  KC_G,                               KC_M,    HOME_N,  HOME_E,  HOME_I,  HOME_O,  KC_NO,
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
         KC_NO,   KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_NO,            KC_NO,   KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO,
      //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                        TMB_ESC, TMB_SPC, KC_TAB,                    TMB_ENT, TMB_BSPC,TMB_DEL
                                    // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
   ),

   [_NAV] = LAYOUT(
      //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              REDO,    PASTE,   COPY,    CUT,     UNDO,    KC_NO,
      //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_NO,   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                              KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT, KC_NO,            KC_NUM,  KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,
      //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                        KC_NO,   KC_NO,   KC_NO,                     KC_ENT,  KC_BSPC, KC_DEL
                                    // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
   ),

   [_MEDIA] = LAYOUT(
      //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   RM_NEXT, RM_HUEU, RM_SATU, RM_VALU, KC_NO,
      //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_NO,   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                              KC_NO,   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO,
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT, KC_NO,            RM_TOGG, KC_NO,   RM_PREV, RM_HUED, RM_SATD, RM_VALD, KC_NO,
      //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                        KC_NO,   KC_NO,   KC_NO,                     KC_MSTP, KC_MPLY, KC_MUTE
                                    // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
   ),

   [_NUM] = LAYOUT(
      //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_NO,   KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,                            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_NO,   KC_QUOT, KC_4,    KC_5,    KC_6,    TPD_EQL,                            KC_NO,   KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_NO,
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
         KC_NO,   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, KC_SCLN,          KC_NO,   QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                        KC_DOT,  KC_0,    KC_MINS,                   KC_NO,   KC_NO,   KC_NO
                                    // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
   ),

   [_SYM] = LAYOUT(
      //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_NO,   KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_NO,   KC_DQT,  KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                            KC_NO,   KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_NO,
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
         KC_NO,   KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, KC_COLN,          KC_NO,   QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                        KC_LPRN, KC_RPRN, KC_UNDS,                   KC_NO,   KC_NO,   KC_NO
                                    // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
   ),

   [_FUN] = LAYOUT(
      //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_NO,   KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,                            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_NO,   KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL,                            KC_NO,   KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_NO,
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
         KC_NO,   KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, KC_LGUI,          KC_NO,   QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                        KC_BSPC, KC_SPC,  KC_TAB,                    KC_NO,   KC_NO,   KC_NO
                                    // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
   )
};
