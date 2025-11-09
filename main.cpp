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

void run_lua(const std::string& code)
{
    sol::protected_function_result result = lua.safe_script(code, &sol::script_pass_on_error);
    
    if (!result.valid())
    {
        sol::error err = result;
        std::cout << "Lua error caught: " << err.what() << std::endl;
    }
}
EMSCRIPTEN_BINDINGS(module_bindings)
{
    emscripten::function("RunLua", &run_lua);
}


const int WIDTH = 850;
const int HEIGHT = 450;
Vector2 pos;

void Move(int x, int y)
{
    pos.x += x;
    pos.y += y;
}

void UpdateDrawFrame();

int main() {
	std::cout << "=== opening a state ===" << std::endl;

	// open some common libraries
	lua.open_libraries(sol::lib::base, sol::lib::package);
	lua.script("print('bark bark bark!')");
    lua.set_function("move", Move);

    InitWindow(WIDTH, HEIGHT, "raylib [core] example - basic window");

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

    DrawRectangleV(pos, {50, 50}, RED);

	DrawText("Raylib Game template!", 100, 100, 20, BLACK);

	if (GuiButton({200, 200, 100, 30}, "#32# PRESS ME NOW!"))
	{
		std::cout << "Pressed!\n";
	}

	EndDrawing();
}