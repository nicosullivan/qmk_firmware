// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum chimera_ortho_layers {
  _QWERTY,
  _CAPS,
  _NUMPAD,
  _SYMBOLS,
  _MACROS,
  _NAV
};

#define KC_NMPD TG(_NUMPAD)
#define KC_SYMB TG(_SYMBOLS)
#define KC_SPFN LT(_NAV,KC_EQL)
#define KC_SCTL MT(MOD_LCTL, KC_LBRC)
#define KC_SCTR MT(MOD_LCTL, KC_RBRC)
#define KC_SPLT MT(MOD_LALT, KC_MINS)
#define KC_SPRT MT(MOD_LALT, KC_4)
#define KC_GBRC MT(MOD_RGUI, KC_1)
#define KC_GQOT MT(MOD_LGUI, KC_QUOT)
#define KC_MESC LT(_MACROS, KC_ESC)
#define KC_CAD LALT(LCTL(KC_DEL))
#define KC_LOCK LGUI(KC_L)

#define LONGPRESS_DELAY 150

enum custom_keycodes {
  KC_INCL = SAFE_RANGE,
  KC_PULL,
  KC_PUSH,
  KC_SCAP,
  KC_SCOF,
  KC_PUSHUP,
  KC_DCSHELL,
  KC_DCBUILD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
     KC_MESC, KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,KC_SCTL,      KC_SCTR, KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_QUOT,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     KC_TAB , KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,KC_SPLT,      KC_SPRT, KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_ENT ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     KC_LSPO, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,KC_SPFN,      KC_GBRC, KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSPC,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
                                     KC_NMPD,KC_SPC ,                      KC_BSPC,KC_SYMB
  // \------------------------------+-------+-------+------/       \------+-------+-------+------------------------------/
  ),

  [_CAPS] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
     _______,_______,_______,_______,_______,_______,_______,      _______,_______,_______,_______,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     _______,_______,_______,_______,_______,_______,KC_UNDS,      _______,_______,_______,_______,_______,KC_COLN,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     KC_SCOF,_______,_______,_______,_______,_______,_______,      _______,_______,_______,_______,_______,_______,KC_SCOF,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
                                     _______,_______,                      _______,_______
  // \------------------------------+-------+-------+------/       \------+-------+-------+------------------------------/
  ),

  [_NUMPAD] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
     _______,_______,KC_COLN,_______,_______,_______,_______,      _______,_______, KC_7  , KC_8  , KC_9  ,KC_ASTR,KC_MINS,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     _______,_______,KC_DOT ,_______,_______,_______,_______,      _______,_______, KC_4  , KC_5  , KC_6  ,KC_PLUS,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     _______,_______,_______,_______,_______,_______,_______,      _______,_______, KC_1  , KC_2  , KC_3  ,KC_SLSH,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
                                     _______,_______,                      _______, KC_0
  // \------------------------------+-------+-------+------/       \------+-------+-------+------------------------------/
  ),

  [_SYMBOLS] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
     _______,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,_______,      _______,KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_BSLS,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     _______, KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,_______,      _______,KC_TILD,KC_COLN,KC_UNDS,KC_LCBR,KC_RCBR,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     _______, KC_F6 , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,_______,      _______,KC_GRV ,KC_SCLN,KC_MINS,KC_LBRC,KC_RBRC,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
                                     KC_PIPE,_______,                      _______,_______
  // \------------------------------+-------+-------+------/       \------+-------+-------+------------------------------/
  ),

  [_NAV] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
     _______,_______,_______,_______,_______,_______,_______,      _______,_______,_______, KC_UP ,_______,KC_PSCR,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     _______,_______,_______,_______,_______,_______,_______,      _______,_______,KC_LEFT,KC_DOWN,KC_RGHT,_______,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     _______,_______,_______,_______,_______,_______,_______,      _______,_______,KC_PGUP,KC_PGDN,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
                                     _______,KC_DEL ,                      _______,_______
  // \------------------------------+-------+-------+------/       \------+-------+-------+------------------------------/
  ),

  [_MACROS] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
     _______,_______,_______,_______,_______,_______,_______,      _______,_______,_______,KC_INCL,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     _______,_______,KC_DCSHELL,KC_CAD ,_______,_______,_______,      _______,_______,_______,_______,KC_LOCK,_______,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     KC_SCAP,_______,_______,_______,_______,KC_DCBUILD,_______,      _______,_______,_______,KC_PULL,KC_PUSH,KC_PUSHUP,KC_SCAP,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
                                     _______,_______,                      _______,_______
  // \------------------------------+-------+-------+------/       \------+-------+-------+------------------------------/
  )

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    /* include some kind of library or header */
    case KC_INCL:
      if (record->event.pressed) {
        SEND_STRING("#include <>" SS_TAP(X_LEFT));
      }
      return false;
    case KC_PULL:
      if (record->event.pressed) {
        SEND_STRING("git pull" SS_TAP(X_ENTER));
      }
      return false;
    case KC_PUSH:
      if (record->event.pressed){
        SEND_STRING("git push" SS_TAP(X_ENTER));
      }
      return false;
    case KC_SCAP:
      if (record->event.pressed){
        layer_on(_CAPS);
        register_code(KC_CAPSLOCK);
        unregister_code(KC_CAPSLOCK);
      }
      return false;
    case KC_SCOF:
      if (record->event.pressed){
        layer_off(_CAPS);
        register_code(KC_CAPSLOCK);
        unregister_code(KC_CAPSLOCK);
      }
      return false;
    case KC_PUSHUP:
      if (record->event.pressed){
        SEND_STRING("git push -u origin $(git symbolic-ref --short HEAD)" SS_TAP(X_ENTER));
      }
      return false;
    case KC_DCSHELL:
      if (record->event.pressed){
        SEND_STRING("docker-compose exec $COMPOSE_DEFAULT_SERVICE sh" SS_TAP(X_ENTER));
      }
      return false;
    case KC_DCBUILD:
      if (record->event.pressed){
        SEND_STRING("time docker-compose build" SS_TAP(X_ENTER));
      }
  }
  return true;
};


void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    switch (layer) {
      case _QWERTY:
        set_led_green;
        break;
      case _CAPS:
        set_led_white;
        break;
      case _NUMPAD:
        set_led_blue;
        break;
      case _SYMBOLS:
        set_led_red;
        break;
      case _NAV:
        set_led_magenta;
        break;
      case _MACROS:
        set_led_cyan;
        break;
      default:
        set_led_green;
        break;
    }
};
