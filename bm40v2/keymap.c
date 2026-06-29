#include QMK_KEYBOARD_H

/* Definición de capas */
enum custom_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _DIRECTION
};

/* Custom Keycodes para tus Smart Keys */
enum custom_keycodes {
    S_BRC = SAFE_RANGE,  // []
    S_PAR,               // ()
    S_CUR,               // {}
    M_ASIG,              // Macro para =>
    M_ARRO,              // Macro para ->
    M_DD,                //Macro para dd(); 
};

/* Aliases para las capas */
#define TL_LOWR MO(_LOWER)
#define TL_UPPR MO(_RAISE)
#define VS_JOIN LCTL(KC_LSFT) // Para el atajo de VS Code: Ctrl + Shift

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Layer 0: QWERTY
     * ,-----------------------------------------------------------------------------------.
     * | Esc  |  Q   |  W   |  E   |  R   |  T   |  Y   |  U   |  I   |  O   |  P   | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Tab  |  A   |  S   |  D   |  F   |  G   |  H   |  J   |  K   |  L   |  ;   |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |Shift |  Z   |  X   |  C   |  V   |  B   |  N   |  M   |  ,   |  .   |  /   |  "   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl | Menu | GUI  |  Alt |Lower |    Space    |Raise | Del  |Shift |Home  |  End |
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_ortho_4x12_1x2uC(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    LT(_DIRECTION, KC_F), KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
        KC_LCTL, KC_APP,  KC_LGUI, KC_LALT, TL_LOWR, KC_SPC,  TL_UPPR, KC_DEL,  KC_LSFT, KC_HOME, KC_END
    ),

/* Layer 1: LOWER (Símbolos + Macros Laravel + VS Code)
     * ,-----------------------------------------------------------------------------------.
     * |      |  /   |   \  |  []  |  =>  |   `  |   ^  |   -  |  _   |   ~  | Del  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |Caps  |  =   |  $   |  ()  |  ->  | PrtSc|  %   |  <   |  >   |   * |      | Enter|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  #   |  @   |  {}  | dd  |  C+S  |      |  &   |  |   |   !  |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_ortho_4x12_1x2uC(
        KC_NO,   KC_SLSH, KC_BSLS, S_BRC,   M_ASIG,  KC_GRV,  KC_CIRC, KC_MINS, KC_UNDS, KC_TILD, KC_DEL,  KC_BSPC,
        KC_CAPS, KC_EQL,  KC_DLR,  S_PAR,   M_ARRO,  KC_PSCR, KC_PERC, KC_LT,   KC_GT,   KC_ASTR, KC_NO,   KC_ENT,
        KC_NO,   KC_HASH, KC_AT,   S_CUR,   M_DD, VS_JOIN,   KC_NO,   KC_AMPR, KC_PIPE, KC_EXLM, KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),

    /* Layer 2: RAISE (números / funciones)
     * ,-----------------------------------------------------------------------------------.
     * |      |      |  F3  |  F4  | F9   |   .  |   +  |  1   |  2   |  3   |  -   | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |  F2  |  F5  | F12  |   ,  |   :  |  4   |  5   |  6   |  * | Enter|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |  F1  |  F11 |      |      |   /  |  7   |  8   |  9   |  =   | Del  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |Lower |   Space     |Raise |  0   |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_ortho_4x12_1x2uC(
        KC_NO,   KC_NO,   KC_F3,   KC_F4,   KC_F9,   KC_DOT,  KC_PLUS, KC_1,    KC_2,    KC_3,    KC_MINS, KC_BSPC,
        KC_NO,   KC_NO,   KC_F2,   KC_F5,   KC_F12,  KC_COMM, KC_COLN, KC_4,    KC_5,    KC_6,    KC_ASTR, KC_ENT,
        KC_NO,   KC_NO,   KC_F1,   KC_F11,  KC_NO,   KC_NO,   KC_SLSH, KC_7,    KC_8,    KC_9,    KC_EQL,  KC_DEL,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_0,    KC_NO,   KC_NO,   KC_NO
    ),

    /* Layer 3: ADJUST (RGB / Mouse) (Mantener Lower + Rise)
     * ,-----------------------------------------------------------------------------------.
     * |Br+   |Mode+ | Hue+ | Sat+ |Spd+  | Br-  |      |ClickL|Mouse↑|ClickR|      | Mute |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |Br-   |Mode- | Hue- | Sat- |Spd-  | Br+  |      |Mouse←|Mouse↓|Mouse→|      |Vol-  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |Vol+  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | RGB  |      |      |      |Lower |   Space     |Raise |      |      |Reset |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_ortho_4x12_1x2uC(
        RGB_VAI, RGB_MOD, RGB_HUI, RGB_SAI, RGB_SPI, KC_BRID, KC_NO,   MS_BTN1, MS_UP,   MS_BTN2, KC_NO,   KC_MUTE,
        RGB_VAD, RGB_RMOD,RGB_HUD, RGB_SAD, RGB_SPD, KC_BRIU, KC_NO,   MS_LEFT, MS_DOWN, MS_RGHT, KC_NO,   KC_VOLD,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_VOLU,
        RGB_TOG, KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   QK_BOOT, KC_NO
    ),

    /* Layer 4: Dirección (Mantener F)
     * ,-----------------------------------------------------------------------------------.
     * |      |      |PgUp  | Home |      |      |PgDn  | End  | Top  |      |      | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |Shift | Ctrl |  F   |      |      | Left | Down |Right |      |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |Lower |   Space     |Raise |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_DIRECTION] = LAYOUT_ortho_4x12_1x2uC(
        KC_NO,   KC_NO,   KC_PGUP, KC_HOME, KC_NO,   KC_NO,   KC_PGDN, KC_END,  KC_UP,   KC_NO,   KC_NO,   KC_BSPC,
        KC_NO,   KC_NO,   KC_LSFT, KC_LCTL, KC_NO,   KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,   KC_ENT,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),
};

/* Lógica para activar la capa ADJUST al presionar LOWER + RAISE */
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

/* Lógica de Smart Keys y Macros */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case S_BRC:
                SEND_STRING("[]" SS_TAP(X_LEFT));
                return false;
            case S_PAR:
                SEND_STRING("()" SS_TAP(X_LEFT));
                return false;
            case S_CUR:
                SEND_STRING("{}" SS_TAP(X_LEFT));
                return false;
            case M_ASIG:
                SEND_STRING("=> "); // Espacio opcional al final para limpieza
                return false;
            case M_ARRO:
                SEND_STRING("->");
                return false;
            case M_DD:
                SEND_STRING("dd();" SS_TAP(X_LEFT) SS_TAP(X_LEFT)); // dd(); y mete el cursor al centro usando SS_TAP
                return false;    
        }
    }
    return true;
}