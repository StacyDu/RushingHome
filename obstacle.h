#include "raylib.h"
#include "raymath.h"

class obstacle
{
public:
    obstacle(int winWidth, int winHeight);
    void tick(float deltaTime);

protected:


private:
    Texture2D orangeFireTexture{LoadTexture("textures/fireTexture/png/orange/loops/burning_loop_1.png")};
    Vector2 firePos{};
    Rectangle fireRec{};

    int frame{};
    int maxFrames{8};

    int width{};
    int height{};
    float scale{5.0f};

    int winWidth{};
    int winHeight{};

};
