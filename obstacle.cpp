#include "obstacle.h"
#include "raymath.h"
#include "raylib.h"
#include <string>
#include <iostream>

obstacle::obstacle(int winWidth, int winHeight) :
    winWidth(winWidth),
    winHeight(winHeight)
{
    width = orangeFireTexture.width/8;
    height = orangeFireTexture.height;
}

void obstacle::tick(float deltaTime)
{
    worldLastFramePos = worldPos;
    // animation
    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        //fireRec.x = frame * fireRec.width;
        runningTime = 0.0f;
        frame++;
        if (frame > maxFrames) frame = 0;
    } 

    // moving
    if(IsKeyDown(KEY_A))
    {
        firePos.x -= 70 * deltaTime; 
    }
    if(IsKeyDown(KEY_W) && IsKeyDown(KEY_A))
    {
        firePos.x -= 35 * deltaTime; 
    }    

    if(IsKeyDown(KEY_D))
    {
        firePos.x += 70 * deltaTime; 
    }
    if(IsKeyDown(KEY_W) && IsKeyDown(KEY_D))
    {
        firePos.x += 35 * deltaTime; 
    }
     

    Rectangle source{frame * width, 0.f, width, height};
    Rectangle dest{getScreenPos().x, getScreenPos().y, scale * width, scale * height};
    DrawTexturePro(orangeFireTexture, source, dest, firePos, 0.0, WHITE);
    ///DrawTextureEx(orangeFireTexture, firePos, 0.0, scale, WHITE);
    
}

Vector2 obstacle::getScreenPos()
{
    return Vector2{
        300, 
        winHeight - height * scale - 20
    };      
}

