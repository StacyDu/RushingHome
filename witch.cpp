#include "witch.h"
#include "raymath.h"
#include <string>
#include <iostream>


witch::witch(int winWidth, int winHeight) :
    windowWidth(winWidth),
    windowHeight(winHeight)

{
    width = witch_idle.width, 
    height = witch_idle.height/6;
}

Vector2 witch::getBeginScreenPos()
{
    return Vector2{
        static_cast<float>(windowWidth)/3 - scale * width,
        static_cast<float>(windowHeight) - scale * height
    };    
}

bool witch::isOnGround()
{
    return witchPos.y <= 1;
}

void witch::tick(float deltaTime)
{
    if (!isInAir)
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
    }
    
    if (isOnGround())
    {
        velocity = 0;
        isInAir = false;
    }
    else
    {
        velocity -= gravity * deltaTime;
        isInAir = true;
    }

    // move
    if (IsKeyDown(KEY_A)) direction.x -=1;
    if (IsKeyDown(KEY_D)) direction.x +=1;
    // jump
    if (IsKeyPressed(KEY_W) && !isInAir) 
    {
        direction.y -= 1;
        if (witchPos.y < 100)
        {
            velocity += jumpVel;
        } 
    }
    
    witchPos.y += velocity * deltaTime;
    // check direction magnitude
    if (Vector2Length(direction) != 0.0)
    {   
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(direction), speed));
        direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
        witch_texture = witch_run;
    }
    else
    {
        witch_texture = witch_idle;
    }

    direction.x = 0.0;
    direction.y = 0.0;

    Rectangle source{0.f, frame * height, rightLeft * width, height};
    Rectangle dest{getBeginScreenPos().x, getBeginScreenPos().y, scale * width, scale * height};
    DrawTexturePro(witch_texture, source, dest, witchPos, 0.0, WHITE);
    // Debug
    // DrawRectangle(dest.x, dest.y, dest.width, dest.height, BLACK);
    // DrawRectangle(source.x, source.y, 20, 20, RED);
}

void witch::undoMovement()
{
    worldPos = worldLastFramePos;
}

Rectangle witch::getCollisionRec()
{
    return Rectangle{
        getBeginScreenPos().x, 
        getBeginScreenPos().y, 
        scale * width, 
        scale * height
    };
}

