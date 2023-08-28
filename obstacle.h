#include "raylib.h"
#include "raymath.h"

class obstacle
{
public:
    obstacle(int winWidth, int winHeight);
    void tick(float deltaTime);
    virtual Vector2 getScreenPos();

protected:


private:
    Texture2D orangeFireTexture{LoadTexture("textures/fireTexture/png/orange/loops/burning_loop_1.png")};
    Vector2 firePos{};
    // Rectangle fireRec{};

    int frame{};
    int maxFrames{8};

    int width{};
    int height{};
    float scale{3.0f};

    int winWidth{};
    int winHeight{};

    // animation
    float updateTime{1.f / 16.f};
    Vector2 worldPos{};
    Vector2 worldLastFramePos{};
    float runningTime{};
};
