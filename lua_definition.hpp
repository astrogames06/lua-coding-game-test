#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <sol/sol.hpp>

#include "sprite.hpp"
#include "shapes.hpp"
#include "colors.hpp"
#include "keys.hpp"

void DefineLuaFunctions()
{
    DefineLuaSpriteFunctions();
    DefineShapesFunctions();
    DefineKeyFunctions();
}

void DefineLuaGlobals()
{
    DefineLuaSpriteGlobals();
    DefineLuaColors();
    DefineKeyGlobals();
}

#endif