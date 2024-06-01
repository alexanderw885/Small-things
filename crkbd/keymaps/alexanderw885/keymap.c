/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H

// Custom key codes
enum my_keycodes {
    QUEX = SAFE_RANGE, // ! and ?
    MINWIN,     // Minimizes active window
    ZOOM_IN,    // ctrl +
    ZOOM_OUT,   // ctrl -
    I_LOOP,     // Pastes increasing for loop with int i
    J_LOOP,     // Pastes increasing for loop with int j
};


/*
Layers:
[0]=Dvorak
[1]=Qwerty
[2]=Games
[3]=Layer select
[4]=Math
[5]=Movement+symbols
[6]=Functions

TODO:



BONUS: split movement and symbols into 2 layers

double tap lctrl to open qwerty+lctrl   HARD TO DO, MADE SAD VERSION
add math symbols                        DONE, MAY REVISE OVER TIME
figure out symbol layer                 DONE, MAY REVISE OVER TIME
maybe more on function layer            IT'S GOT MORE THINGS NOW!
RSFT-BSPC = DEL                         DONE!
*/

#define LThumb MT(MOD_LSFT|MOD_LCTL|MOD_LGUI, KC_SPC)  

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Dvorak
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, KC_SCLN,  KC_COMM,  KC_DOT,  KC_P,  KC_Y,                         KC_F,    KC_G,    KC_C,    KC_R,   KC_L,   KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_TAB,  KC_A,     KC_O,     KC_E,    KC_U,  KC_I,                       KC_D,    KC_H,    KC_T,    KC_N,   KC_S,    QUEX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LCTL, KC_QUOT,   KC_Q,   KC_J,   KC_K,     KC_X,                         KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,   KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              KC_LALT,   LT(4, KC_ENTER),  LThumb,     RSFT_T(KC_SPC),   LT(5, KC_BSPC), KC_RGUI
                                      //`--------------------------'  `--------------------------'

  ),
    // Qwerty
    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                       KC_N,    KC_M,  KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                KC_LALT,   LT(4, KC_ENTER),  LThumb,   RSFT_T(KC_SPC),   LT(5, KC_BSPC), KC_RGUI
                                      //`--------------------------'  `--------------------------'

  ),

    // Games (qwerty on left, arrow on right)
    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                     XXXXXXX, XXXXXXX,  KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      XXXXXXX, KC_LEFT,  KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                     XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,   KC_SPC,  MO(4),   KC_SPC,   LT(5, KC_ENTER), KC_RGUI
                                      //`--------------------------'  `--------------------------'

  ),
    // Layer select
    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       DF(0),   DF(1), DF(2), XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______, XXXXXXX,    XXXXXXX, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
    // Math
    [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_DEL, KC_GRAVE,  KC_LT,   KC_GT, KC_LCBR,  KC_RCBR,                      KC_ASTR,   KC_7,   KC_8,    KC_9,   KC_PLUS, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_I, KC_LCTL, KC_UNDS, KC_CIRC, KC_LPRN, KC_RPRN,                      KC_SLSH,  KC_4,   KC_5,    KC_6,   KC_MINS, KC_EQL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
LM(1, MOD_LCTL), KC_PERC, KC_HASH, KC_DLR, KC_LBRC, KC_RBRC,                     KC_0,    KC_1,   KC_2,    KC_3,   KC_DOT,  KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, _______,  KC_SPC,     MT(MOD_RSFT, KC_SPC),   LT(6, KC_ENTER), KC_I
                                      //`--------------------------'  `--------------------------'
  ),
    // Movement and symbols
    [5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     XXXXXXX, XXXXXXX,  KC_HOME,  KC_UP,  KC_END, KC_PGUP,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CW_TOGG, KC_LCTL, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN,                     XXXXXXX, KC_SLSH, KC_ASTR, KC_TILD, KC_UNDS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MINWIN,                      KC_RSFT,  KC_AT,  KC_AMPR, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(6),  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),
    // Functions
    [6] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_RBT, XXXXXXX,  J_LOOP,  I_LOOP, KC_VOLU, ZOOM_IN,                       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, ZOOM_OUT,                      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX, KC_MPLY, MINWIN,                      C(KC_1), C(KC_2), C(KC_3), C(KC_4), C(KC_5), C(KC_6),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),
  // IF YOU ADD MORE LAYERS, REMOVE LAYERSTATE FROM CONFIG.H!!!!!!!!!
};



// My lovely block of key combos
const uint16_t PROGMEM layer_combo[] = {KC_LALT, KC_RGUI, COMBO_END};
const uint16_t PROGMEM and_combo[] = {MT(MOD_LSFT|MOD_LCTL|MOD_LGUI, KC_SPC), KC_A, KC_N, COMBO_END};
const uint16_t PROGMEM at_combo[] = {MT(MOD_LSFT|MOD_LCTL|MOD_LGUI, KC_SPC), KC_A, KC_T, COMBO_END};
const uint16_t PROGMEM slsh_combo[] = {KC_Z,   KC_BSLS, COMBO_END};
const uint16_t PROGMEM LH_move[] = {LT(4, KC_ENTER),  LThumb, COMBO_END};
const uint16_t PROGMEM RH_num[] = {RSFT_T(KC_SPC),   LT(5, KC_BSPC), COMBO_END};
combo_t key_combos[] = {
    COMBO(layer_combo, OSL(3)),
    COMBO(and_combo, KC_AMPR),
    COMBO(at_combo, KC_AT),
    COMBO(slsh_combo, KC_SLSH),
    COMBO(LH_move, MO(5)),
    COMBO(RH_num, MO(4)),
};


// Keypress loop, happens with every press.
// This is where custom key logic goes
uint8_t mod_state; // Stores mod state, good if many mods are pressed

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    mod_state = get_mods();
    switch (keycode) {

    // Creates a key that returns "!" by itself, "!" with shift
    case QUEX:
        // Adds "?" capabilites
        if (mod_state == MOD_BIT(KC_RSFT)) {
            if(record->event.pressed) {
                // No need to register Shift, it's already held
                register_code(KC_SLSH);
            } else {
                unregister_code(KC_SLSH);
            }
        // Adds "!" capabilites
        } else {
            if(record->event.pressed) {
                // Note that Shift is needed here, so it is added when QUEX is pressed, and removed when released
                register_code(KC_LSFT);
                register_code(KC_1);
                } else {
                unregister_code(KC_1);
                unregister_code(KC_LSFT);
                unregister_code(KC_SLSH); // SLSH is unregistered here to avoid key getting stuck
            }
        }
    return true;

    // Remaps Windows Powertoys crop-and-lock to win-ctrl-shft-c
    case KC_C:
        if(record->event.pressed){
            if(mod_state == (MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LGUI))){
                tap_code16(KC_T);
                return false; // Returns false so that C is not counted as pressed
            }
        }
    return true;

    // Remaps Windows Powertoys always-on-top to win-ctrl-shft-t
    case KC_T:
        if(mod_state == (MOD_BIT(KC_LCTL) | MOD_BIT(KC_LGUI) | MOD_BIT(KC_LSFT))){
            if(record->event.pressed){
                unregister_code(KC_LSFT);
            }else{
                register_code(KC_LSFT);
                
            }
        return true;
        }
    return true;

    // Minimizes active window on keypress
    case MINWIN:
        if(record->event.pressed){
            // There's no shortcut for this, so first alt+space brings down a dropdown menu
            tap_code16(A(KC_SPC));
            // Press and release N to minimize the window
            _delay_ms(50); // In case the window doesn't always minimize, adding delay increases consistency
            tap_code(KC_N);
        }
    return true;

    // Zooms browser in
    case ZOOM_IN:
        if (record->event.pressed){
            register_code(KC_LCTL);
            register_code(KC_PPLS);
        } else{
            unregister_code(KC_LCTL);
            unregister_code(KC_PPLS);
        }
    return true;

    // Zooms browser out
    case ZOOM_OUT:
        if (record->event.pressed){
            register_code(KC_LCTL);
            register_code(KC_MINS);
        } else{
            unregister_code(KC_LCTL);
            unregister_code(KC_MINS);
        }
    return true;
    
    // Replaces SHFT-BSPC with DEL
    case KC_BSPC:
        if(mod_state==MOD_BIT(KC_RSFT)){
            if(record->event.pressed){
                register_code(KC_DEL);
                return false;
            }
        }
        // Outside of if statement to ensure delete is released upon releasing the key
        if(!record->event.pressed){
            unregister_code(KC_DEL);
        }
    return true;


    // Prints incrementing for loop with variable i, moves cursor to i<x statement
    // Tried calling one function from both loop keys, but it saved space to make the print function separate for each
    case I_LOOP:
        if(record->event.pressed){
            send_string("for(int i=0; i<; i++)");

            int i = 0;
            while(i != 6){
                tap_code16(KC_LEFT);
                i++;
            }
        }
    return true;

    // Prints incrementing for loop with variable j, moves cursor to i<x statement
    case J_LOOP:
        if(record->event.pressed){
            send_string("for(int j=0; j<; j++)");

            int j = 0;
            while(j != 6){
                tap_code16(KC_LEFT);
                j++;
            }
        }
    return true;
    
    
    // More cases go here!
    }
    return true;
};

// Saving space, remove if using magic keycodes
#ifndef MAGIC_ENABLE
uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}
#endif
#ifndef MAGIC_ENABLE
uint8_t mod_config(uint8_t mod) {
    return mod;
}
#endif