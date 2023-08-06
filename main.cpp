#include "raylib.h"
#include "raymath.h"
#include <string>

int main ()
{

// init window
    const int windowWidth{384};
    const int windowHeight{384};
    InitWindow(windowWidth, windowHeight, "Running Home Game");

while(!WindowShouldClose())
{
    BeginDrawing();
    ClearBackground(WHITE);

    EndDrawing();
}

    CloseWindow();
};