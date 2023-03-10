#include <raylib.h>
#include "GameManager.hpp"

constexpr int SCREEN_WIDTH = 480;
constexpr int SCREEN_HEIGHT = 640;
constexpr char const* WINDOW_TITLE= "Raylib in CPP!";

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(60);

    GameManager gameManager;

    while (!WindowShouldClose())
    {

        gameManager.Update(10.0f);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        gameManager.Draw();
        EndDrawing();
    }
    CloseWindow();

    return 0;
}