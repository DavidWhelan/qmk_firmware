// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

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
               SEND_STRING(SS_LCMD("c"));
            }
            else {
               SEND_STRING(SS_LCTL("c"));
            }
         }
         break;

         case CUT:
         if (record->event.pressed) {
            if (detected_os == OS_MACOS || detected_os == OS_IOS) {
               SEND_STRING(SS_LCMD("x"));
            }
            else {
               SEND_STRING(SS_LCTL("x"));
            }
         }
         break;

         case PASTE:
         if (record->event.pressed) {
            if (detected_os == OS_MACOS || detected_os == OS_IOS) {
               SEND_STRING(SS_LCMD("v"));
            }
            else {
               SEND_STRING(SS_LCTL("v"));
            }
         }
         break;

         case UNDO:
         if (record->event.pressed) {
            if (detected_os == OS_MACOS || detected_os == OS_IOS) {
               SEND_STRING(SS_LCMD("z"));
            }
            else {
               SEND_STRING(SS_LCTL("z"));
            }
         }
         break;

         case REDO:
         if (record->event.pressed) {
            if (detected_os == OS_MACOS || detected_os == OS_IOS) {
               SEND_STRING(SS_LCMD("y"));
            }
            else {
               SEND_STRING(SS_LCTL("y"));
            }
         }
         break;
   }
   return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
   //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_LALT, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_RALT,
   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_LCTL, LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), (KC_G),         KC_M, RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O), KC_RCTL,
   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_HOME,          KC_END,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
   //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
      LT(_MEDIA, KC_ESC), LT(_NAV, KC_SPC), KC_TAB,                           LT(_SYM, KC_ENT), LT(_NUM, KC_BSPC), LT(_FUN, KC_DEL)
  ),

  [_NAV] = LAYOUT(
      //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
         QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
      //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_LALT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              REDO,    PASTE,   COPY,    CUT,     UNDO,    KC_RALT,
      //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_LCTL, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_RCTL,
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
         KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT, KC_NO,            KC_NUM,  KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_RSFT,
      //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                        KC_NO,   KC_NO,   KC_NO,                     KC_ENT,  KC_BSPC, KC_DEL
                                    // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
   ),

   [_MEDIA] = LAYOUT(
      //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
         QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
      //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_LALT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   RM_NEXT, RM_HUEU, RM_SATU, RM_VALU, KC_RALT,
      //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_LCTL, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_RCTL,
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
         KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT, KC_NO,            RM_TOGG, KC_NO,   RM_PREV, RM_HUED, RM_SATD, RM_VALD, KC_RSFT,
      //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                        KC_NO,   KC_NO,   KC_NO,                     KC_MSTP, KC_MPLY, KC_MUTE
                                    // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
   ),

   [_NUM] = LAYOUT(
      //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
         QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
      //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_LALT, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,                            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RALT,
      //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_LCTL, KC_QUOT, KC_4,    KC_5,    KC_6,    KC_EQL,                             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RCTL,
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
         KC_LSFT, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, KC_SCLN,          KC_NO,   QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RSFT,
      //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                        KC_DOT,  KC_0,    KC_MINS,                   KC_NO,   KC_NO,   KC_NO
                                    // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
   ),

   [_SYM] = LAYOUT(
      //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
         QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
      //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_LALT, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RALT,
      //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_LCTL, KC_DQT,  KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RCTL,
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
         KC_LSFT, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, KC_COLN,          KC_NO,   QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RSFT,
      //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                        KC_LPRN, KC_RPRN, KC_UNDS,                   KC_NO,   KC_NO,   KC_NO
                                    // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
   ),

   [_FUN] = LAYOUT(
      //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
         QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
      //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_LALT, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,                            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RALT,
      //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_LCTL, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL,                            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RCTL,
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
         KC_LSFT, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, KC_LGUI,          KC_NO,   QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RSFT,
      //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                        KC_BSPC, KC_SPC,  KC_TAB,                    KC_NO,   KC_NO,   KC_NO
                                    // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
   )
};
