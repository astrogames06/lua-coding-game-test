#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <sol/sol.hpp>

#include "shapes.hpp"
#include "colors.hpp"
#include "keys.hpp"

void DefineLuaFunctions()
{
    DefineShapesFunctions();
    DefineKeyFunctions();
}

void DefineLuaGlobals()
{
    DefineLuaColors();
    DefineKeyGlobals();
}

#endif