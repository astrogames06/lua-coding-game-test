#ifndef SHAPES_H
#define SHAPES_H

#include <raylib.h>
#include <sol/sol.hpp>

extern sol::state lua;

// This is for the 2 draws rects functions. One allows for rotation and the other doesnt
// Normal rectangle
void DrawRect(int x, int y, int width, int height, Color color)
{
    DrawRectangle((float)x, (float)y, (float)width, (float)height, color);
}

// Uses rotation
void DrawRect(int x, int y, int width, int height, float rot, Color color)
{
    DrawRectanglePro(
        {(float)x, (float)y, (float)width, (float)height},
        { (float)width / 2, (float)height / 2 }, rot, color
    );
}

void DefineShapesFunctions()
{
    // This defines the 2 draws rects functions. One allows for rotation and the other doesnt
    lua.set_function("draw_rect", sol::overload(
        (void(*)(int, int, int, int, Color))DrawRect,
        (void(*)(int, int, int, int, float, Color))DrawRect
    ));
}

#endif