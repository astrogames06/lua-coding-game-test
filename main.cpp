#include <raylib.h>
#include <raymath.h>
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>
#include <sol/sol.hpp>

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdlib>

#define PLATFORM_WEB
#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
    #include <emscripten/bind.h>
#endif

#include "lua_definition.hpp"
#include "sprite.hpp"

sol::state lua;
sol::function lua_game_loop_init;
sol::function lua_game_loop_update;
sol::function lua_game_loop_draw;

const int WIDTH = 850;
const int HEIGHT = 450;

bool ran_lua = false;
bool running = false;
bool LuaIsRunning() { return running; }

void SetUpLua()
{
	lua.open_libraries(sol::lib::base, sol::lib::package);

	sol::protected_function_result result =
		lua.safe_script("print('LUA SCRIPT RAN')", sol::script_pass_on_error);

	if (!result.valid())
	{
		sol::error err = result;
		std::cout << "Lua init error caught: " << err.what() << std::endl;
	}

	// Where the lua functions should be set
	DefineLuaFunctions();
	DefineLuaGlobals();
}

void SetLuaGameLoop()
{
	if (lua["_init"].valid()) {
		lua_game_loop_init = lua["_init"];
	} else {
		std::cout << "Lua function '_init' not found on first go!" << std::endl;
	}

	if (lua["_update"].valid()) {
		lua_game_loop_update = lua["_update"];
	} else {
		std::cout << "Lua function '_update' not found on first go!" << std::endl;
	}

	if (lua["_draw"].valid()) {
		lua_game_loop_draw = lua["_draw"];
	} else {
		std::cout << "Lua function '_draw' not found on first go!" << std::endl;
	}

	// Run Init Function
	if (ran_lua && running)
	{
		if (lua_game_loop_init.valid())
		{
			sol::protected_function_result result = lua_game_loop_init();

			if (!result.valid()) {
				sol::error err = result;
				std::cout << "Lua error: " << err.what() << std::endl;
			}
		} else {
			std::cout << "Lua function '_init' not defined!\n";
		}
	}
}

void RunLuaCode(const std::string& code)
{
	sol::protected_function_result result = lua.safe_script(code, sol::script_pass_on_error);

	if (!result.valid())
	{
		sol::error err = result;
		std::cout << "Lua error caught: " << err.what() << std::endl;
	}

	running = !running;
	ran_lua = true;
}

void RestartGame()
{
	SetUpLua();
	for (int i = 0; i < sprites.size(); i++)
	{
		Sprite* sprite = sprites[i];
		sprite->x = sprite->original_x;
		sprite->y = sprite->original_y;

		if (sprite->is_added)
		{
			sprites.erase(sprites.begin() + i);
		}
	}
}

EMSCRIPTEN_BINDINGS(module_bindings)
{
	emscripten::function("cpp_lua_is_running", &LuaIsRunning);
	emscripten::function("cpp_run_lua_code", &RunLuaCode);
	emscripten::function("cpp_set_lua_game_loop", &SetLuaGameLoop);
	emscripten::function("cpp_restart_game", &RestartGame);
}

void UpdateDrawFrame();

Texture player_tex;
int main() {
	std::cout << "=== opening a state ===" << std::endl;

    InitWindow(WIDTH, HEIGHT, "raylib [core] example - basic window");
	SetUpLua();

	Sprite player = Sprite("player", 50, 50);
	player_tex = LoadTexture("images/player.png");
	sprites.push_back(&player);

	#if defined(PLATFORM_WEB)
    	emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
	#else
		SetTargetFPS(60);

		while (!WindowShouldClose())
		{
			UpdateDrawFrame();
		}
	#endif

	CloseWindow();

    return 0;
}

void UpdateDrawFrame()
{
	if (ran_lua && running)
	{
		if (lua_game_loop_update.valid())
		{
			sol::protected_function_result result = lua_game_loop_update();

			if (!result.valid()) {
				sol::error err = result;
				std::cout << "Lua error: " << err.what() << std::endl;
			}
		} else {
			std::cout << "Lua function '_update' not defined!\n";
		}
	}

	BeginDrawing();

	ClearBackground(RAYWHITE);

	if (ran_lua && running)
	{
		if (lua_game_loop_draw.valid())
		{
			sol::protected_function_result result = lua_game_loop_draw();

			if (!result.valid()) {
				sol::error err = result;
				std::cout << "Lua error: " << err.what() << std::endl;
			}
		} else {
			std::cout << "Lua function '_draw' not defined!\n";
		}
	}

	for (Sprite* sprite : sprites)
	{
		DrawTexture(player_tex, sprite->x, sprite->y, WHITE);
	}

	if (GuiButton({200, 200, 100, 30}, "#32# PRESS ME NOW!"))
	{
		std::cout << "Pressed!\n";
	}

	DrawFPS(20, HEIGHT-20);
	EndDrawing();
}