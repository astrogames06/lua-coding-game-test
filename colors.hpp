#ifndef COLORS_H
#define COLORS_H

#include <raylib.h>
#include <sol/sol.hpp>

extern sol::state lua;

void DefineLuaColors()
{
    lua["LIGHTGRAY"]  = Color{ 200, 200, 200, 255 };
    lua["GRAY"]       = Color{ 130, 130, 130, 255 };
    lua["DARKGRAY"]   = Color{ 80, 80, 80, 255 };
    lua["YELLOW"]     = Color{ 253, 249, 0, 255 };
    lua["GOLD"]       = Color{ 255, 203, 0, 255 };
    lua["ORANGE"]     = Color{ 255, 161, 0, 255 };
    lua["PINK"]       = Color{ 255, 109, 194, 255 };
    lua["RED"]        = Color{ 230, 41, 55, 255 };
    lua["MAROON"]     = Color{ 190, 33, 55, 255 };
    lua["GREEN"]      = Color{ 0, 228, 48, 255 };
    lua["LIME"]       = Color{ 0, 158, 47, 255 };
    lua["DARKGREEN"]  = Color{ 0, 117, 44, 255 };
    lua["SKYBLUE"]    = Color{ 102, 191, 255, 255 };
    lua["BLUE"]       = Color{ 0, 121, 241, 255 };
    lua["DARKBLUE"]   = Color{ 0, 82, 172, 255 };
    lua["PURPLE"]     = Color{ 200, 122, 255, 255 };
    lua["VIOLET"]     = Color{ 135, 60, 190, 255 };
    lua["DARKPURPLE"] = Color{ 112, 31, 126, 255 };
    lua["BEIGE"]      = Color{ 211, 176, 131, 255 };
    lua["BROWN"]      = Color{ 127, 106, 79, 255 };
    lua["DARKBROWN"]  = Color{ 76, 63, 47, 255 };
    lua["WHITE"]      = Color{ 255, 255, 255, 255 };
    lua["BLACK"]      = Color{ 0, 0, 0, 255 };
    lua["BLANK"]      = Color{ 0, 0, 0, 0 };
    lua["MAGENTA"]    = Color{ 255, 0, 255, 255 };
    lua["RAYWHITE"]   = Color{ 245, 245, 245, 255 };
}

#endif