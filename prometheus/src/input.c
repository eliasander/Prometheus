#include <raylib.h>
#include "input.h"

// KEYBOARD
static KeyboardKey MapToRaylibKey(AppKey key) {
    switch (key) {
        case APP_KEY_NULL:          return KEY_NULL;
        
        // Alphanumeric keys
        case APP_KEY_APOSTROPHE:    return KEY_APOSTROPHE;
        case APP_KEY_COMMA:         return KEY_COMMA;
        case APP_KEY_MINUS:         return KEY_MINUS;
        case APP_KEY_PERIOD:        return KEY_PERIOD;
        case APP_KEY_SLASH:         return KEY_SLASH;
        case APP_KEY_ZERO:          return KEY_ZERO;
        case APP_KEY_ONE:           return KEY_ONE;
        case APP_KEY_TWO:           return KEY_TWO;
        case APP_KEY_THREE:         return KEY_THREE;
        case APP_KEY_FOUR:          return KEY_FOUR;
        case APP_KEY_FIVE:          return KEY_FIVE;
        case APP_KEY_SIX:           return KEY_SIX;
        case APP_KEY_SEVEN:         return KEY_SEVEN;
        case APP_KEY_EIGHT:         return KEY_EIGHT;
        case APP_KEY_NINE:          return KEY_NINE;
        case APP_KEY_SEMICOLON:     return KEY_SEMICOLON;
        case APP_KEY_EQUAL:         return KEY_EQUAL;
        case APP_KEY_A:             return KEY_A;
        case APP_KEY_B:             return KEY_B;
        case APP_KEY_C:             return KEY_C;
        case APP_KEY_D:             return KEY_D;
        case APP_KEY_E:             return KEY_E;
        case APP_KEY_F:             return KEY_F;
        case APP_KEY_G:             return KEY_G;
        case APP_KEY_H:             return KEY_H;
        case APP_KEY_I:             return KEY_I;
        case APP_KEY_J:             return KEY_J;
        case APP_KEY_K:             return KEY_K;
        case APP_KEY_L:             return KEY_L;
        case APP_KEY_M:             return KEY_M;
        case APP_KEY_N:             return KEY_N;
        case APP_KEY_O:             return KEY_O;
        case APP_KEY_P:             return KEY_P;
        case APP_KEY_Q:             return KEY_Q;
        case APP_KEY_R:             return KEY_R;
        case APP_KEY_S:             return KEY_S;
        case APP_KEY_T:             return KEY_T;
        case APP_KEY_U:             return KEY_U;
        case APP_KEY_V:             return KEY_V;
        case APP_KEY_W:             return KEY_W;
        case APP_KEY_X:             return KEY_X;
        case APP_KEY_Y:             return KEY_Y;
        case APP_KEY_Z:             return KEY_Z;
        case APP_KEY_LEFT_BRACKET:  return KEY_LEFT_BRACKET;
        case APP_KEY_BACKSLASH:     return KEY_BACKSLASH;
        case APP_KEY_RIGHT_BRACKET: return KEY_RIGHT_BRACKET;
        case APP_KEY_GRAVE:         return KEY_GRAVE;

        // Function keys
        case APP_KEY_SPACE:         return KEY_SPACE;
        case APP_KEY_ESCAPE:        return KEY_ESCAPE;
        case APP_KEY_ENTER:         return KEY_ENTER;
        case APP_KEY_TAB:           return KEY_TAB;
        case APP_KEY_BACKSPACE:     return KEY_BACKSPACE;
        case APP_KEY_INSERT:        return KEY_INSERT;
        case APP_KEY_DELETE:        return KEY_DELETE;
        case APP_KEY_RIGHT:         return KEY_RIGHT;
        case APP_KEY_LEFT:          return KEY_LEFT;
        case APP_KEY_DOWN:          return KEY_DOWN;
        case APP_KEY_UP:            return KEY_UP;
        case APP_KEY_PAGE_UP:       return KEY_PAGE_UP;
        case APP_KEY_PAGE_DOWN:     return KEY_PAGE_DOWN;
        case APP_KEY_HOME:          return KEY_HOME;
        case APP_KEY_END:           return KEY_END;
        case APP_KEY_CAPS_LOCK:     return KEY_CAPS_LOCK;
        case APP_KEY_SCROLL_LOCK:   return KEY_SCROLL_LOCK;
        case APP_KEY_NUM_LOCK:      return KEY_NUM_LOCK;
        case APP_KEY_PRINT_SCREEN:  return KEY_PRINT_SCREEN;
        case APP_KEY_PAUSE:         return KEY_PAUSE;
        case APP_KEY_F1:            return KEY_F1;
        case APP_KEY_F2:            return KEY_F2;
        case APP_KEY_F3:            return KEY_F3;
        case APP_KEY_F4:            return KEY_F4;
        case APP_KEY_F5:            return KEY_F5;
        case APP_KEY_F6:            return KEY_F6;
        case APP_KEY_F7:            return KEY_F7;
        case APP_KEY_F8:            return KEY_F8;
        case APP_KEY_F9:            return KEY_F9;
        case APP_KEY_F10:           return KEY_F10;
        case APP_KEY_F11:           return KEY_F11;
        case APP_KEY_F12:           return KEY_F12;
        case APP_KEY_LEFT_SHIFT:    return KEY_LEFT_SHIFT;
        case APP_KEY_LEFT_CONTROL:  return KEY_LEFT_CONTROL;
        case APP_KEY_LEFT_ALT:      return KEY_LEFT_ALT;
        case APP_KEY_LEFT_SUPER:    return KEY_LEFT_SUPER;
        case APP_KEY_RIGHT_SHIFT:   return KEY_RIGHT_SHIFT;
        case APP_KEY_RIGHT_CONTROL: return KEY_RIGHT_CONTROL;
        case APP_KEY_RIGHT_ALT:     return KEY_RIGHT_ALT;
        case APP_KEY_RIGHT_SUPER:   return KEY_RIGHT_SUPER;
        case APP_KEY_KB_MENU:       return KEY_KB_MENU;

        // Keypad keys
        case APP_KEY_KP_0:          return KEY_KP_0;
        case APP_KEY_KP_1:          return KEY_KP_1;
        case APP_KEY_KP_2:          return KEY_KP_2;
        case APP_KEY_KP_3:          return KEY_KP_3;
        case APP_KEY_KP_4:          return KEY_KP_4;
        case APP_KEY_KP_5:          return KEY_KP_5;
        case APP_KEY_KP_6:          return KEY_KP_6;
        case APP_KEY_KP_7:          return KEY_KP_7;
        case APP_KEY_KP_8:          return KEY_KP_8;
        case APP_KEY_KP_9:          return KEY_KP_9;
        case APP_KEY_KP_DECIMAL:    return KEY_KP_DECIMAL;
        case APP_KEY_KP_DIVIDE:     return KEY_KP_DIVIDE;
        case APP_KEY_KP_MULTIPLY:   return KEY_KP_MULTIPLY;
        case APP_KEY_KP_SUBTRACT:   return KEY_KP_SUBTRACT;
        case APP_KEY_KP_ADD:        return KEY_KP_ADD;
        case APP_KEY_KP_ENTER:      return KEY_KP_ENTER;
        case APP_KEY_KP_EQUAL:      return KEY_KP_EQUAL;

        // Android key buttons
        case APP_KEY_BACK:          return KEY_BACK;
        case APP_KEY_MENU:          return KEY_MENU;
        case APP_KEY_VOLUME_UP:     return KEY_VOLUME_UP;
        case APP_KEY_VOLUME_DOWN:   return KEY_VOLUME_DOWN;

        default:                    return KEY_NULL;
    }
}


bool key_is_pressed(AppKey key) {
    return IsKeyPressed(MapToRaylibKey(key));
}
bool key_is_pressed_repeat(AppKey key) {
    return IsKeyPressedRepeat(MapToRaylibKey(key));
}
bool key_is_down(AppKey key) {
    return IsKeyDown(MapToRaylibKey(key));
}
bool key_is_released(AppKey key) {
    return IsKeyReleased(MapToRaylibKey(key));
}
bool key_is_up(AppKey key ){
    return IsKeyUp(MapToRaylibKey(key));
}
AppKey key_get_pressed(void) {
    return GetKeyPressed();
}
void key_set_exit(AppKey key) {
    SetExitKey(MapToRaylibKey(key));
}




// MOUSE
static MouseButton MapToRaylibButton(AppButton button) {
    switch (button) {
        case APP_BUTTON_LEFT:       return MOUSE_BUTTON_LEFT;
        case APP_BUTTON_RIGHT:      return MOUSE_BUTTON_RIGHT;
        case APP_BUTTON_MIDDLE:     return MOUSE_BUTTON_MIDDLE;
        case APP_BUTTON_SIDE:       return MOUSE_BUTTON_SIDE;
        case APP_BUTTON_EXTRA:      return MOUSE_BUTTON_EXTRA;
        case APP_BUTTON_FORWARD:    return MOUSE_BUTTON_FORWARD;
        case APP_BUTTON_BACK:       return MOUSE_BUTTON_BACK;
    }
}


bool mouse_is_pressed(AppButton button) {
    return IsMouseButtonPressed(MapToRaylibButton(button));
}

bool mouse_is_down(AppButton button) {
    return IsMouseButtonDown(button);
}

bool mouse_is_released(AppButton button) {
    return IsMouseButtonReleased(button);
}

bool mouse_is_up(AppButton button) {
    return IsMouseButtonUp(button);
}

Vec2 mouse_pos_get(void) {
    Vector2 mousePos = GetMousePosition();
    return (Vec2){
        mousePos.x,
        mousePos.y
    };
}

Vec2 mouse_delta_get(void) {
    Vector2 mouseDelta = GetMouseDelta();
    return (Vec2){
        mouseDelta.x,
        mouseDelta.y
    };
}

float mouse_wheel_get(void){
    return GetMouseWheelMove();
}
