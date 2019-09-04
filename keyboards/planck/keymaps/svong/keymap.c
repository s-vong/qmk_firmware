/* Copyright 2015-2017 Jack Humbert
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

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _VIM,
  _NUM,
  _PGRM,
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
};

#define VIM MO(_VIM)
#define NUM MO(_NUM)
#define PGRM MO(_PGRM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | WIN  | Alt  | VIM  | NUM  |SPACE | PGRM |      |PG HM |PG DWN|PG UP |PG END|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB, KC_Q   ,   KC_W,  KC_E ,  KC_R ,  KC_T ,  KC_Y ,   KC_U,   KC_I,   KC_O,   KC_P,KC_BSPC,
    KC_ESC, KC_A   ,   KC_S,  KC_D ,  KC_F ,  KC_G ,  KC_H ,   KC_J,   KC_K,   KC_L,KC_SCLN,KC_QUOT,
    KC_LSFT,KC_Z   ,   KC_X,  KC_C ,  KC_V ,  KC_B ,  KC_N ,   KC_M,KC_COMM, KC_DOT,KC_SLSH,KC_ENT ,
    KC_LCTL,KC_LGUI,KC_LALT,  VIM  ,  NUM  , KC_SPC,  PGRM ,XXXXXXX,KC_HOME,KC_PGDN,KC_PGUP,KC_END
),

/* VIM
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |      |      | End  |      |      |CTL-C | CTL-Z|      |RETURN|CTL-P | Bk   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |      |      | DEL  |      | HOME | Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      | DEL  |      |      |      |      |      |      |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Win  | Alt  | VIM  |  NUM |Space | PGRM |      | PG HM|PG DWN|PG UP |PG END|
 * `-----------------------------------------------------------------------------------'
 */
[_VIM] = LAYOUT_planck_grid(
    KC_TAB ,XXXXXXX,XXXXXXX, KC_END,XXXXXXX, XXXXXXX, C(KC_C), C(KC_Z), XXXXXXX, KC_ENT,C(KC_P), KC_BSPC,
    KC_ESC ,XXXXXXX,XXXXXXX, KC_DEL,XXXXXXX, KC_HOME, KC_LEFT, KC_DOWN, KC_UP ,KC_RGHT,XXXXXXX, XXXXXXX,
    KC_LSFT,XXXXXXX, KC_DEL,XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, KC_ENT , 
    KC_LCTL,KC_LGUI,KC_LALT,  VIM  ,  NUM  , KC_SPC ,  PGRM  , XXXXXXX,KC_HOME,KC_PGDN,KC_PGUP, KC_END
),

/* NUM 
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |  F1  |  F2  |  F3  |  F4  |      |   $  |   7  |   8  |   9  |   /  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |  F5  |  F6  |  F7  |  F8  |      |   %  |   4  |   5  |   6  |   *  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|  F9  |  F10 |  F11 |  F12 |      |   #  |   1  |   2  |   3  |   -  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | WIN  | Alt  | VIM  | NUM  | Space| PGRM |   0  |   0  |   .  |   +  |      |      
 * `-----------------------------------------------------------------------------------'
 */
[_NUM] = LAYOUT_planck_grid(
    KC_TAB , KC_F1,  KC_F2,  KC_F3,  KC_F4,XXXXXXX, KC_DLR,  KC_7,   KC_8,   KC_9,  KC_PSLS,XXXXXXX,
    KC_ESC , KC_F5,  KC_F6,  KC_F7,  KC_F8,XXXXXXX, KC_PERC, KC_4,   KC_5,   KC_6,  KC_PAST,KC_PENT,
    KC_LSFT, KC_F9, KC_F10, KC_F11, KC_F12,XXXXXXX, KC_HASH, KC_1,   KC_2,   KC_3,  KC_PMNS,XXXXXXX,
    KC_LCTL,KC_LGUI,KC_LALT,  VIM ,  NUM  ,KC_SPC , PGRM   , KC_0,   KC_0,KC_PDOT,  KC_PPLS,XXXXXXX 
),

/* PGRM 
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   `  |      |      |      |      |      |      |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Caps |      |      |      |      |      |      |      |   =  |      |      |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | WIN  | Alt  | VIM  | NUM  |SPACE | PGRM |      |PG HM |PG DWN|PG UP |PG END|
 * `-----------------------------------------------------------------------------------'
 */
[_PGRM] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    KC_GRV,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    KC_CLCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_EQL , XXXXXXX, XXXXXXX, KC_BSLS,
    KC_LCTL, KC_LGUI, KC_LALT,  VIM   ,  NUM   , KC_SPC ,  PGRM  , XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _PGRM, _NUM, _VIM);
}
