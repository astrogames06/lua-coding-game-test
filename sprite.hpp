#ifndef SPRITE_H
#define SPRITE_H

#include <raylib.h>
#include <sol/sol.hpp>

#include "utils.hpp"

extern sol::state lua;

struct Sprite
{
public:
    std::string name;
    int x;
    int y;
    int original_x;
    int original_y;
    bool is_added = false;

    Sprite(const std::string& name, int x, int y)
        : name(name), x(x), y(y)
    {
        this->original_x = x;
        this->original_y = y;
    }

    friend Sprite* CreateSprite(const std::string&, int, int);
};
std::vector<Sprite*> sprites;

Sprite* CreateSprite(const std::string& name, int x, int y)
{
    std::vector<Sprite*>::iterator sprite_it = std::find_if(sprites.begin(), sprites.end(),
        [&](Sprite* other)
        {
            return other->name == name;
        }
    );
    Sprite* sprite = *sprite_it;
    if (sprite != nullptr)
    {
        std::string alert_msg = "Sprite Name " + name + " Is Already Taken. Code Might Break!";
        js_alert(alert_msg.c_str());

        return nullptr;
    }

    Sprite* s = new Sprite(name, x, y);
    s->is_added = true;
    sprites.push_back(s);
    return s;
}
Sprite* GetSprite(const std::string& name)
{
    std::vector<Sprite*>::iterator sprite_it = std::find_if(sprites.begin(), sprites.end(),
        [&](Sprite* other)
        {
            return other->name == name;
        }
    );
    Sprite* sprite = *sprite_it;

    if (sprite_it == sprites.end())
        return nullptr; // Returns null if can't find sprite

    return sprite;
}

void DefineLuaSpriteFunctions()
{
    lua.set_function("CreateSprite", CreateSprite);
    lua.set_function("GetSprite", GetSprite);
}

void DefineLuaSpriteGlobals()
{
    lua.new_usertype<Sprite>("Sprite",
        sol::constructors<Sprite(const std::string&, int, int)>(),

        "name", &Sprite::name,
        "x", &Sprite::x,
        "y", &Sprite::y
    );
}

#endif