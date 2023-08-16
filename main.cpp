#include "raylib.h"
#include "raymath.h"
#include "witch.h"
#include <string>


int main ()
{
    // init window
    const int windowWidth{640};
    const int windowHeight{360};
    InitWindow(windowWidth, windowHeight, "Running Home Game");

    witch blueWitch(windowWidth, windowHeight);
    Vector2 ground{windowWidth, windowHeight - 10};

    // background
    Texture2D background = LoadTexture("textures/oak_woods_v1.0/background/background_layer_1.png");
    float bgX{};
    Texture2D midground = LoadTexture("textures/oak_woods_v1.0/background/background_layer_2.png");
    float mgX{};
    Texture2D foreground = LoadTexture("textures/oak_woods_v1.0/background/background_layer_3.png");
    float fgX{};

SetTargetFPS(60);
while(!WindowShouldClose())
{
    BeginDrawing();
    ClearBackground(WHITE);

    Vector2 bgPos{0.0, 0.0};
    DrawTextureEx(background, bgPos, 0.0, 2, WHITE);     
    Vector2 mgPos{0.0, 0.0};
    DrawTextureEx(midground, mgPos, 0.0, 2, WHITE); 
    Vector2 fgPos{0.0, 0.0};
    DrawTextureEx(foreground, fgPos, 0.0, 2, WHITE);      

    blueWitch.tick(GetFrameTime());

    EndDrawing();
}
    CloseWindow();
};