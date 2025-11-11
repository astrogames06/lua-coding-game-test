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

sol::state lua;
sol::function game;

const int WIDTH = 850;
const int HEIGHT = 450;
Vector2 pos;

void Move(int x, int y)
{
    pos.x += x;
    pos.y += y;
}
void BONG(int x, int y)
{
	DrawRectangle(x, y, 50, 50, BLUE);
}

void setup_lua()
{
	// open some common libraries
	lua.open_libraries(sol::lib::base, sol::lib::package);
	lua.script("print('LUA SCRIPT RAN')");
	lua.set_function("move_plr", Move);
	lua.set_function("BONG", BONG);
}
void set_game()
{
	if (lua["run_game"].valid()) {
		game = lua["run_game"];
	} else {
		std::cout << "Lua function run_game not defined!" << std::endl;
	}
}
bool ran_lua = false;
bool running = false;
bool lua_is_running() { return running; }
void run_lua(const std::string& code)
{
    sol::protected_function_result result = lua.safe_script(code, &sol::script_pass_on_error);
    
    if (!result.valid())
    {
        sol::error err = result;
        std::cout << "Lua error caught: " << err.what() << std::endl;
    }

	running = !running;
	ran_lua = true;
}
EMSCRIPTEN_BINDINGS(module_bindings)
{
	emscripten::function("LuaIsRunning", &lua_is_running);
    emscripten::function("RunLua", &run_lua);
	emscripten::function("SetGame", &set_game);
}

void UpdateDrawFrame();

int main() {
	std::cout << "=== opening a state ===" << std::endl;

    InitWindow(WIDTH, HEIGHT, "raylib [core] example - basic window");
	setup_lua();

	#if defined(PLATFORM_WEB)
    	emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
	#else
		SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
		//--------------------------------------------------------------------------------------

		// Main game loop
		while (!WindowShouldClose())    // Detect window close button or ESC key
		{
			UpdateDrawFrame();
		}
	#endif

	CloseWindow();

    return 0;
}


void UpdateDrawFrame()
{
	BeginDrawing();
	
	ClearBackground(RAYWHITE);
	if (ran_lua && running)
	{
		if (game.valid())
		{
			sol::protected_function_result result = game();
			if (!result.valid()) {
				sol::error err = result;
				std::cout << "Lua error: " << err.what() << std::endl;
			}
		} else {
			std::cout << "Lua function run_game not defined!\n";
		}
	}

    DrawRectangleV(pos, {50, 50}, RED);

	DrawText("Raylib Game template!", 100, 100, 20, BLACK);

	if (GuiButton({200, 200, 100, 30}, "#32# PRESS ME NOW!"))
	{
		std::cout << "Pressed!\n";
	}

	DrawFPS(20, HEIGHT-20);
	EndDrawing();
}