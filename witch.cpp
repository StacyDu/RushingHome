#include "witch.h"
#include "raymath.h"


witch::witch(int winWidth, int winHeight) :
    windowWidth(winWidth),
    windowHeight(winHeight)

{
    width = witch_idle.width, 
    height = witch_idle.height/6;
}

void witch::tick(float deltaTime)
{
    worldLastFramePos = worldPos;
    // animation
    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        frame++;
        runningTime = 0.0f;
        if (frame > maxFrames) frame = 0;
    }
 
    if (IsKeyDown(KEY_A)) velocity.x -=1;
    if (IsKeyDown(KEY_D)) velocity.x +=1;
    if (IsKeyDown(KEY_SPACE)) velocity.y -=1;

    // check direction magnitude
    if (Vector2Length(velocity) != 0.0)
    {
        // set worldPos = worldPos + direction    
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(velocity), speed));
        velocity.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
        witch_idle = witch_run;
    }
    else
    {
        witch_idle = witch_idle;
    }
    velocity = {};

    Rectangle source{0.f, frame * height, rightLeft * width, height};
    Rectangle dest{getScreenPos().x, getScreenPos().y, scale * width, scale * height};
    DrawTexturePro(witch_idle, source, dest, witchPos, 0.0, WHITE);
}

Vector2 witch::getScreenPos()
{
    return Vector2{
        static_cast<float>(windowWidth)/2.0f - scale * width,
        static_cast<float>(windowHeight) - scale * (2.0f * height)
    };
}


