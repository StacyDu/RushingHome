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

    // move
    if (IsKeyDown(KEY_A)) velocity.x -=1;
    if (IsKeyDown(KEY_D)) velocity.x +=1;

    // falling
    if (IsKeyDown(KEY_S)) 
    {
        velocity.y += gravity;
        witchPos.y -= velocity.y + deltaTime;
    }
    // jumping
    if (IsKeyDown(KEY_SPACE) && !isInAir)
    {
        velocity.y -= jumpVel;
        witchPos.y += velocity.y + deltaTime;
        isInAir = true;
    }

    // check direction magnitude
    if (Vector2Length(velocity) != 0.0)
    {
        // set worldPos = worldPos + direction    
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(velocity), speed));
        velocity.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
        witch_texture = witch_run;
    }
  
    Rectangle source{0.f, frame * height, rightLeft * width, height};
    Rectangle dest{getScreenPos().x, getScreenPos().y, scale * width, scale * height};
    DrawTexturePro(witch_texture, source, dest, witchPos, 0.0, WHITE);

    if (witchPos.y < worldPos.y || witchPos.x > worldPos.x)
    {
        isInAir = false;
        velocity.x = 0.0;
        velocity.y = 0.0;
        witch_texture = witch_idle;
    }

}

Vector2 witch::getScreenPos()
{
    return Vector2{
        static_cast<float>(windowWidth)/2.0f - scale * width,
        static_cast<float>(windowHeight) - scale * (2.0f * height)
    };
}
