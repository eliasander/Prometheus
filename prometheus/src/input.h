#ifndef PROMENTHEUS_INPUT_H
#define PROMENTHEUS_INPUT_H

#include "core.h"


// KEYBOARD
typedef enum AppKey {
    APP_KEY_NULL            = 0,        // Key: NULL, used for no key pressed

    // Alphanumeric keys
    APP_KEY_APOSTROPHE      = 39,       // Key: '
    APP_KEY_COMMA           = 44,       // Key: ,
    APP_KEY_MINUS           = 45,       // Key: -
    APP_KEY_PERIOD          = 46,       // Key: .
    APP_KEY_SLASH           = 47,       // Key: /
    APP_KEY_ZERO            = 48,       // Key: 0
    APP_KEY_ONE             = 49,       // Key: 1
    APP_KEY_TWO             = 50,       // Key: 2
    APP_KEY_THREE           = 51,       // Key: 3
    APP_KEY_FOUR            = 52,       // Key: 4
    APP_KEY_FIVE            = 53,       // Key: 5
    APP_KEY_SIX             = 54,       // Key: 6
    APP_KEY_SEVEN           = 55,       // Key: 7
    APP_KEY_EIGHT           = 56,       // Key: 8
    APP_KEY_NINE            = 57,       // Key: 9
    APP_KEY_SEMICOLON       = 59,       // Key: ;
    APP_KEY_EQUAL           = 61,       // Key: =
    APP_KEY_A               = 65,       // Key: A | a
    APP_KEY_B               = 66,       // Key: B | b
    APP_KEY_C               = 67,       // Key: C | c
    APP_KEY_D               = 68,       // Key: D | d
    APP_KEY_E               = 69,       // Key: E | e
    APP_KEY_F               = 70,       // Key: F | f
    APP_KEY_G               = 71,       // Key: G | g
    APP_KEY_H               = 72,       // Key: H | h
    APP_KEY_I               = 73,       // Key: I | i
    APP_KEY_J               = 74,       // Key: J | j
    APP_KEY_K               = 75,       // Key: K | k
    APP_KEY_L               = 76,       // Key: L | l
    APP_KEY_M               = 77,       // Key: M | m
    APP_KEY_N               = 78,       // Key: N | n
    APP_KEY_O               = 79,       // Key: O | o
    APP_KEY_P               = 80,       // Key: P | p
    APP_KEY_Q               = 81,       // Key: Q | q
    APP_KEY_R               = 82,       // Key: R | r
    APP_KEY_S               = 83,       // Key: S | s
    APP_KEY_T               = 84,       // Key: T | t
    APP_KEY_U               = 85,       // Key: U | u
    APP_KEY_V               = 86,       // Key: V | v
    APP_KEY_W               = 87,       // Key: W | w
    APP_KEY_X               = 88,       // Key: X | x
    APP_KEY_Y               = 89,       // Key: Y | y
    APP_KEY_Z               = 90,       // Key: Z | z
    APP_KEY_LEFT_BRACKET    = 91,       // Key: [
    APP_KEY_BACKSLASH       = 92,       // Key: '\'
    APP_KEY_RIGHT_BRACKET   = 93,       // Key: ]
    APP_KEY_GRAVE           = 96,       // Key: `
    // Function keys
    APP_KEY_SPACE           = 32,       // Key: Space
    APP_KEY_ESCAPE          = 256,      // Key: Esc
    APP_KEY_ENTER           = 257,      // Key: Enter
    APP_KEY_TAB             = 258,      // Key: Tab
    APP_KEY_BACKSPACE       = 259,      // Key: Backspace
    APP_KEY_INSERT          = 260,      // Key: Ins
    APP_KEY_DELETE          = 261,      // Key: Del
    APP_KEY_RIGHT           = 262,      // Key: Cursor right
    APP_KEY_LEFT            = 263,      // Key: Cursor left
    APP_KEY_DOWN            = 264,      // Key: Cursor down
    APP_KEY_UP              = 265,      // Key: Cursor up
    APP_KEY_PAGE_UP         = 266,      // Key: Page up
    APP_KEY_PAGE_DOWN       = 267,      // Key: Page down
    APP_KEY_HOME            = 268,      // Key: Home
    APP_KEY_END             = 269,      // Key: End
    APP_KEY_CAPS_LOCK       = 280,      // Key: Caps lock
    APP_KEY_SCROLL_LOCK     = 281,      // Key: Scroll down
    APP_KEY_NUM_LOCK        = 282,      // Key: Num lock
    APP_KEY_PRINT_SCREEN    = 283,      // Key: Print screen
    APP_KEY_PAUSE           = 284,      // Key: Pause
    APP_KEY_F1              = 290,      // Key: F1
    APP_KEY_F2              = 291,      // Key: F2
    APP_KEY_F3              = 292,      // Key: F3
    APP_KEY_F4              = 293,      // Key: F4
    APP_KEY_F5              = 294,      // Key: F5
    APP_KEY_F6              = 295,      // Key: F6
    APP_KEY_F7              = 296,      // Key: F7
    APP_KEY_F8              = 297,      // Key: F8
    APP_KEY_F9              = 298,      // Key: F9
    APP_KEY_F10             = 299,      // Key: F10
    APP_KEY_F11             = 300,      // Key: F11
    APP_KEY_F12             = 301,      // Key: F12
    APP_KEY_LEFT_SHIFT      = 340,      // Key: Shift left
    APP_KEY_LEFT_CONTROL    = 341,      // Key: Control left
    APP_KEY_LEFT_ALT        = 342,      // Key: Alt left
    APP_KEY_LEFT_SUPER      = 343,      // Key: Super left
    APP_KEY_RIGHT_SHIFT     = 344,      // Key: Shift right
    APP_KEY_RIGHT_CONTROL   = 345,      // Key: Control right
    APP_KEY_RIGHT_ALT       = 346,      // Key: Alt right
    APP_KEY_RIGHT_SUPER     = 347,      // Key: Super right
    APP_KEY_KB_MENU         = 348,      // Key: KB menu
    // Keypad keys
    APP_KEY_KP_0            = 320,      // Key: Keypad 0
    APP_KEY_KP_1            = 321,      // Key: Keypad 1
    APP_KEY_KP_2            = 322,      // Key: Keypad 2
    APP_KEY_KP_3            = 323,      // Key: Keypad 3
    APP_KEY_KP_4            = 324,      // Key: Keypad 4
    APP_KEY_KP_5            = 325,      // Key: Keypad 5
    APP_KEY_KP_6            = 326,      // Key: Keypad 6
    APP_KEY_KP_7            = 327,      // Key: Keypad 7
    APP_KEY_KP_8            = 328,      // Key: Keypad 8
    APP_KEY_KP_9            = 329,      // Key: Keypad 9
    APP_KEY_KP_DECIMAL      = 330,      // Key: Keypad .
    APP_KEY_KP_DIVIDE       = 331,      // Key: Keypad /
    APP_KEY_KP_MULTIPLY     = 332,      // Key: Keypad *
    APP_KEY_KP_SUBTRACT     = 333,      // Key: Keypad -
    APP_KEY_KP_ADD          = 334,      // Key: Keypad +
    APP_KEY_KP_ENTER        = 335,      // Key: Keypad Enter
    APP_KEY_KP_EQUAL        = 336,      // Key: Keypad =
    // Android key buttons
    APP_KEY_BACK            = 4,        // Key: Android back button
    APP_KEY_MENU            = 5,        // Key: Android menu button
    APP_KEY_VOLUME_UP       = 24,       // Key: Android volume up button
    APP_KEY_VOLUME_DOWN     = 25        // Key: Android volume down button
} AppKey;

bool key_is_pressed(AppKey key);
bool key_is_pressed_repeat(AppKey key);
bool key_is_down(AppKey key);
bool key_is_released(AppKey key);
bool key_is_up(AppKey key);
AppKey key_get_pressed(void);
void key_set_exit(AppKey key);

// MOUSE
typedef enum {
    APP_BUTTON_LEFT    = 0,       // Mouse button left
    APP_BUTTON_RIGHT   = 1,       // Mouse button right
    APP_BUTTON_MIDDLE  = 2,       // Mouse button middle (pressed wheel)
    APP_BUTTON_SIDE    = 3,       // Mouse button side (advanced mouse device)
    APP_BUTTON_EXTRA   = 4,       // Mouse button extra (advanced mouse device)
    APP_BUTTON_FORWARD = 5,       // Mouse button forward (advanced mouse device)
    APP_BUTTON_BACK    = 6,       // Mouse button back (advanced mouse device)
} AppButton;

bool mouse_is_pressed(AppButton button);
bool mouse_is_down(AppButton button);
bool mouse_is_released(AppButton button);
bool mouse_is_up(AppButton button);
Vec2 mouse_pos_get(void);
Vec2 mouse_delta_get(void);
float mouse_wheel_get(void);



#endif