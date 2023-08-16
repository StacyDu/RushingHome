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
        // adding delta time (time since last frame)
        const float deltaTime{GetFrameTime()};

        BeginDrawing();
        ClearBackground(WHITE);

        if (IsKeyDown(KEY_D))
        {
            bgX -= 20 * deltaTime;
            if (bgX <= -background.width * 2)
            {
                bgX = 0.0;
            };
            // scroll midground
            mgX -= 40 * deltaTime;
            if (mgX <= -midground.width * 2)
            {
                mgX = 0.0;
            };
            // scroll farground
            fgX -= 80 * deltaTime;
            if (fgX <= -foreground.width * 2)
            {
                fgX = 0.0;
            };
        }
        else if (IsKeyDown(KEY_A))
        {
            bgX += 20 * deltaTime;
            if (bgX >= background.width * 2)
            {
                bgX = 0.0;
            };
            // scroll midground
            mgX += 40 * deltaTime;
            if (mgX >= midground.width * 2)
            {
                mgX = 0.0;
            };
            // scroll farground
            fgX += 80 * deltaTime;
            if (fgX >= foreground.width * 2)
            {
                fgX = 0.0;
            };           
        }

        Vector2 bgPos{bgX, 0.0};
        DrawTextureEx(background, bgPos, 0.0, 2, WHITE);
        Vector2 bg2Pos{bgX + background.width * 2, 0.0};
        DrawTextureEx(background, bg2Pos, 0.0, 2.0, WHITE);
        Vector2 bg3Pos{bgX - background.width * 2, 0.0};
        DrawTextureEx(background, bg3Pos, 0.0, 2.0, WHITE);

        Vector2 mgPos{mgX, 0.0};
        DrawTextureEx(midground, mgPos, 0.0, 2, WHITE);
        Vector2 mg2Pos{mgX + background.width * 2, 0.0};
        DrawTextureEx(midground, mg2Pos, 0.0, 2.0, WHITE);
        Vector2 mg3Pos{mgX - background.width * 2, 0.0};
        DrawTextureEx(midground, mg3Pos, 0.0, 2.0, WHITE); 

        Vector2 fgPos{fgX, 0.0};
        DrawTextureEx(foreground, fgPos, 0.0, 2, WHITE);
        Vector2 fg2Pos{fgX + background.width * 2, 0.0};
        DrawTextureEx(foreground, fg2Pos, 0.0, 2.0, WHITE);
        Vector2 fg3Pos{fgX - background.width * 2, 0.0};
        DrawTextureEx(foreground, fg3Pos, 0.0, 2.0, WHITE);        

        blueWitch.tick(deltaTime);

        EndDrawing();
    }
    CloseWindow();
};