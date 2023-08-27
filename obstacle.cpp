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
    firePos.y = winHeight - height ;
}

void obstacle::tick(float deltaTime)
{
    float x{};
    x += deltaTime;
    if (x >= 1/8)
    {
        frame++;
        x = 0.0f;
        if (frame > maxFrames) frame = 0;
    }
    
    Rectangle rec{0, 0, width * scale, height * scale};
    DrawTextureRec(orangeFireTexture, rec, firePos, WHITE);

}
