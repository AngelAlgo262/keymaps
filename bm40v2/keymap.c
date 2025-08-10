/* Copyright 2020 tominabox1
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
#include QMK_KEYBOARD_H

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _ACENTOS
};

enum custom_keycodes {
  A_ACUTE = SAFE_RANGE,
  E_ACUTE,
  I_ACUTE,
  O_ACUTE,
  U_ACUTE,
  N_TILDE
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define NA XXXXXXX
#define  ACENTOS LT(_ACENTOS, KC_TAB)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case A_ACUTE:
            if (record->event.pressed) SEND_STRING(SS_TAP(X_QUOT) "a");
            return false;
        case E_ACUTE:
            if (record->event.pressed) SEND_STRING(SS_TAP(X_QUOT) "e");
            return false;
        case I_ACUTE:
            if (record->event.pressed) SEND_STRING(SS_TAP(X_QUOT) "i");
            return false;
        case O_ACUTE:
            if (record->event.pressed) SEND_STRING(SS_TAP(X_QUOT) "o");
            return false;
        case U_ACUTE:
            if (record->event.pressed) SEND_STRING(SS_TAP(X_QUOT) "u");
            return false;
        case N_TILDE:
            if (record->event.pressed) SEND_STRING(SS_TAP(X_RALT) "n");
            return false;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |Bksp  |
 * |-----------------------------------------------------------------------------------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  | :  ; |Enter |
 * |-----------------------------------------------------------------------------------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | ' "  |
 * |-----------------------------------------------------------------------------------|
 * | CTRL | MENU | GUI  | Alt  |Lower |    Space    |Raise | Del  | CTRL | Home | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_mit(
    KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    ACENTOS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
    KC_LCTL,  KC_MENU, KC_LGUI, KC_LALT, LOWER,       KC_SPC,       RAISE,   KC_DEL,  KC_RCTL, KC_HOME, KC_END
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  |   |   %  |   \  |   [  |   ]  |   `  |  NA  |  NA  | TOP  | NA   |  NA  |Bksp  |
 * |-----------------------------------------------------------------------------------|
 * | #    |   =  |   $  |   (  |   )  |PriScr|  NA  | LEFT | DOWN |RIGHT |  NA  |  *   |
 * |-----------------------------------------------------------------------------------|
 * | ~    |   !  |   @  |   {  |   }  |  &   |  NA  |  NA  |  NA  |  NA  |  NA  | NA   |
 * |-----------------------------------------------------------------------------------|
 * | NA   |   _  |   <  |   >  |Lower |    Space    |Raise |  NA  |  NA  |  NA  | NA   |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_mit(
    KC_PIPE, KC_PERC, KC_BSLS, KC_LBRC, KC_RBRC, KC_GRV,  NA,      NA,       KC_UP,   NA,      NA,      KC_BSPC,
    KC_HASH, KC_EQL,  KC_DLR,  KC_LPRN, KC_RPRN, KC_PSCR, NA,      KC_LEFT,  KC_DOWN, KC_RGHT, NA,      KC_ASTR,
    KC_TILD, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_AMPR, NA,      NA,       NA,      NA,      NA,      NA,
    NA,      KC_UNDS, KC_LT,   KC_GT,   _______,    _______,       _______,  NA,      NA,      NA,      NA
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  NA  |  NA  |  F1  |  F4  |  F11 |PagDwn|PagUp |  1!  |  2@  |  3#  |  +   | Bksp |
 * |-----------------------------------------------------------------------------------|
 * |Shift |  NA  |  F2  |  F5  |  F12 |  NA  |  NA  |  4$  |  5%  |  6^  |  *   |Enter |
 * |-----------------------------------------------------------------------------------|
 * |  NA  |  NA  |  F3  |  F9  |  NA  |  NA  |  NA  |  7&  |  8*  |  9(  |  /   |  =   |
 * |-----------------------------------------------------------------------------------|
 * |Caps  |  NA  |  NA  |  NA  |Lower |   Space     |Raise |  0)  |  .>  | Del  |  -   |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_mit(
    NA,      NA,    KC_F1,   KC_F4,   KC_F11,  KC_PGUP, KC_PGDN, KC_1,    KC_2,    KC_3,    KC_PLUS, KC_BSPC,
    KC_LSFT, NA,    KC_F2,   KC_F5,   KC_F12,  NA,      NA,      KC_4,    KC_5,    KC_6,    KC_ASTR, KC_ENT,
    NA,      NA,    KC_F3,   KC_F9,   NA,      NA,      NA,      KC_7,    KC_8,    KC_9,    KC_SLSH, KC_EQL,
    KC_CAPS, NA,    NA,      NA,      _______,    _______,       _______, KC_0,    KC_DOT,  KC_DEL,  KC_MINS
),

/* Acentos
* ,-----------------------------------------------------------------------------------.
 * | NA   |  NA   |  NA  |E_ACUTE|  NA |  NA  |  NA  |U_ACUTE|I_ACUTE|O_ACUTE|NA | NA  |
 * |-----------------------------------------------------------------------------------|
 * | NA   |A_ACUTE|  NA  |  NA  |  NA  |  NA  |  NA  |  NA  |  NA  |  NA  | NA   | NA  |
 * |-----------------------------------------------------------------------------------|
 * | NA   |  NA  |  NA   |  NA  |  NA  |  NA  |N_TILDE| NA  |  NA  |  NA  | NA   | NA  |
 * |-----------------------------------------------------------------------------------|
 * | NA   |  NA  |  NA   |  NA  |Lower |    Space    |Raise |  NA  |  NA |  NA   | NA  |
 * `-----------------------------------------------------------------------------------'
 */
[_ACENTOS] = LAYOUT_planck_mit(
    NA, NA,      NA, E_ACUTE, NA,      NA,    NA,      U_ACUTE,   I_ACUTE, O_ACUTE, NA, NA,
    NA, A_ACUTE, NA, NA,      NA,      NA,    NA,      NA,        NA,      NA,      NA, NA,
    NA, NA,      NA, NA,      NA,      NA,    N_TILDE, NA,        NA,      NA,      NA, NA,
    NA, NA,      NA, NA,      _______,   _______,      _______,   NA,      NA,      NA, NA
),

/* Adjust (Lower - Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |BRGTH+|Mode+ | Hue+ | Sat+ |Speed+|BrScr+| NA   |ClickL|Mouse↑|ClickR|  NA  |Reset |
 * |-----------------------------------------------------------------------------------|
 * |BRGTH-|Mode- | Hue- | Sat- |Speed-|BrScr-| NA   |Mouse←|Mouse↓|Mouse→|  NA  |Mute  |
 * |-----------------------------------------------------------------------------------|
 * | NA   | NA   | NA   |  NA  |  NA  |  NA  | NA   |  NA  |  NA  |  NA  |  NA  |Vol-  |
 * |-----------------------------------------------------------------------------------|
 * | RGB  | NA   | NA   |  NA  |  NA  |     NA      |  NA  |  NA  |  NA  |  NA  |Vol+  |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_mit(
    RGB_VAI, RGB_MOD, RGB_HUI, RGB_SAI, RGB_SPI, KC_PGUP,   NA, KC_BTN1, KC_MS_U, KC_BTN2, NA, QK_BOOT,
    RGB_VAD, RGB_RMOD,RGB_HUD, RGB_SAD, RGB_SPD, KC_PGDN,   NA, KC_MS_L, KC_MS_D, KC_MS_R, NA, KC_MUTE,
    NA,      NA,      NA,      NA,      NA,      NA,        NA, NA,      NA,      NA,      NA, KC_VOLD,
    RGB_TOG, NA,      NA,      NA,      NA,      NA,        NA, NA,      NA,      NA,          KC_VOLU
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

