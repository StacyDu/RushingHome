#include "raylib.h"
#include "raymath.h"
#include "witch.h"
#include <string>



int main ()
{
    // init window
    const int windowWidth{684};
    const int windowHeight{684};
    InitWindow(windowWidth, windowHeight, "Running Home Game");

    witch blueWitch(windowWidth, windowHeight);

SetTargetFPS(60);
while(!WindowShouldClose())
{
    BeginDrawing();
    ClearBackground(WHITE);

    blueWitch.tick(GetFrameTime());

    EndDrawing();
}
    CloseWindow();
};