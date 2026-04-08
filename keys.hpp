#ifndef KEYS_H
#define KEYS_H

#include <raylib.h>
#include <sol/sol.hpp>

extern sol::state lua;

void DefineKeyFunctions()
{
    lua.set_function("key_pressed", IsKeyPressed);
    lua.set_function("key_pressed_repeat", IsKeyPressedRepeat);
    lua.set_function("key_down", IsKeyDown);
    lua.set_function("key_up", IsKeyUp);
    lua.set_function("key_released", IsKeyReleased);
}

// All the key global variables
void DefineKeyGlobals()
{
    lua["KEY_NULL"] = KEY_NULL;

    lua["KEY_APOSTROPHE"] = KEY_APOSTROPHE;
    lua["KEY_COMMA"] = KEY_COMMA;
    lua["KEY_MINUS"] = KEY_MINUS;
    lua["KEY_PERIOD"] = KEY_PERIOD;
    lua["KEY_SLASH"] = KEY_SLASH;

    lua["KEY_ZERO"] = KEY_ZERO;
    lua["KEY_ONE"] = KEY_ONE;
    lua["KEY_TWO"] = KEY_TWO;
    lua["KEY_THREE"] = KEY_THREE;
    lua["KEY_FOUR"] = KEY_FOUR;
    lua["KEY_FIVE"] = KEY_FIVE;
    lua["KEY_SIX"] = KEY_SIX;
    lua["KEY_SEVEN"] = KEY_SEVEN;
    lua["KEY_EIGHT"] = KEY_EIGHT;
    lua["KEY_NINE"] = KEY_NINE;

    lua["KEY_SEMICOLON"] = KEY_SEMICOLON;
    lua["KEY_EQUAL"] = KEY_EQUAL;

    lua["KEY_A"] = KEY_A;
    lua["KEY_B"] = KEY_B;
    lua["KEY_C"] = KEY_C;
    lua["KEY_D"] = KEY_D;
    lua["KEY_E"] = KEY_E;
    lua["KEY_F"] = KEY_F;
    lua["KEY_G"] = KEY_G;
    lua["KEY_H"] = KEY_H;
    lua["KEY_I"] = KEY_I;
    lua["KEY_J"] = KEY_J;
    lua["KEY_K"] = KEY_K;
    lua["KEY_L"] = KEY_L;
    lua["KEY_M"] = KEY_M;
    lua["KEY_N"] = KEY_N;
    lua["KEY_O"] = KEY_O;
    lua["KEY_P"] = KEY_P;
    lua["KEY_Q"] = KEY_Q;
    lua["KEY_R"] = KEY_R;
    lua["KEY_S"] = KEY_S;
    lua["KEY_T"] = KEY_T;
    lua["KEY_U"] = KEY_U;
    lua["KEY_V"] = KEY_V;
    lua["KEY_W"] = KEY_W;
    lua["KEY_X"] = KEY_X;
    lua["KEY_Y"] = KEY_Y;
    lua["KEY_Z"] = KEY_Z;

    lua["KEY_LEFT_BRACKET"] = KEY_LEFT_BRACKET;
    lua["KEY_BACKSLASH"] = KEY_BACKSLASH;
    lua["KEY_RIGHT_BRACKET"] = KEY_RIGHT_BRACKET;
    lua["KEY_GRAVE"] = KEY_GRAVE;

    lua["KEY_SPACE"] = KEY_SPACE;
    lua["KEY_ESCAPE"] = KEY_ESCAPE;
    lua["KEY_ENTER"] = KEY_ENTER;
    lua["KEY_TAB"] = KEY_TAB;
    lua["KEY_BACKSPACE"] = KEY_BACKSPACE;
    lua["KEY_INSERT"] = KEY_INSERT;
    lua["KEY_DELETE"] = KEY_DELETE;

    lua["KEY_RIGHT"] = KEY_RIGHT;
    lua["KEY_LEFT"] = KEY_LEFT;
    lua["KEY_DOWN"] = KEY_DOWN;
    lua["KEY_UP"] = KEY_UP;

    lua["KEY_PAGE_UP"] = KEY_PAGE_UP;
    lua["KEY_PAGE_DOWN"] = KEY_PAGE_DOWN;
    lua["KEY_HOME"] = KEY_HOME;
    lua["KEY_END"] = KEY_END;

    lua["KEY_CAPS_LOCK"] = KEY_CAPS_LOCK;
    lua["KEY_SCROLL_LOCK"] = KEY_SCROLL_LOCK;
    lua["KEY_NUM_LOCK"] = KEY_NUM_LOCK;

    lua["KEY_PRINT_SCREEN"] = KEY_PRINT_SCREEN;
    lua["KEY_PAUSE"] = KEY_PAUSE;

    lua["KEY_F1"] = KEY_F1;
    lua["KEY_F2"] = KEY_F2;
    lua["KEY_F3"] = KEY_F3;
    lua["KEY_F4"] = KEY_F4;
    lua["KEY_F5"] = KEY_F5;
    lua["KEY_F6"] = KEY_F6;
    lua["KEY_F7"] = KEY_F7;
    lua["KEY_F8"] = KEY_F8;
    lua["KEY_F9"] = KEY_F9;
    lua["KEY_F10"] = KEY_F10;
    lua["KEY_F11"] = KEY_F11;
    lua["KEY_F12"] = KEY_F12;

    lua["KEY_LEFT_SHIFT"] = KEY_LEFT_SHIFT;
    lua["KEY_LEFT_CONTROL"] = KEY_LEFT_CONTROL;
    lua["KEY_LEFT_ALT"] = KEY_LEFT_ALT;
    lua["KEY_LEFT_SUPER"] = KEY_LEFT_SUPER;

    lua["KEY_RIGHT_SHIFT"] = KEY_RIGHT_SHIFT;
    lua["KEY_RIGHT_CONTROL"] = KEY_RIGHT_CONTROL;
    lua["KEY_RIGHT_ALT"] = KEY_RIGHT_ALT;
    lua["KEY_RIGHT_SUPER"] = KEY_RIGHT_SUPER;

    lua["KEY_KB_MENU"] = KEY_KB_MENU;

    lua["KEY_KP_0"] = KEY_KP_0;
    lua["KEY_KP_1"] = KEY_KP_1;
    lua["KEY_KP_2"] = KEY_KP_2;
    lua["KEY_KP_3"] = KEY_KP_3;
    lua["KEY_KP_4"] = KEY_KP_4;
    lua["KEY_KP_5"] = KEY_KP_5;
    lua["KEY_KP_6"] = KEY_KP_6;
    lua["KEY_KP_7"] = KEY_KP_7;
    lua["KEY_KP_8"] = KEY_KP_8;
    lua["KEY_KP_9"] = KEY_KP_9;

    lua["KEY_KP_DECIMAL"] = KEY_KP_DECIMAL;
    lua["KEY_KP_DIVIDE"] = KEY_KP_DIVIDE;
    lua["KEY_KP_MULTIPLY"] = KEY_KP_MULTIPLY;
    lua["KEY_KP_SUBTRACT"] = KEY_KP_SUBTRACT;
    lua["KEY_KP_ADD"] = KEY_KP_ADD;
    lua["KEY_KP_ENTER"] = KEY_KP_ENTER;
    lua["KEY_KP_EQUAL"] = KEY_KP_EQUAL;
}

#endif