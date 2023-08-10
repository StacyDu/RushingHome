#include "raylib.h"
#include "raymath.h"

class witch
{
public:
    witch(int winWidth, int winHeight);
    void tick(float deltaTime);
    virtual Vector2 getScreenPos();

protected:

private:
    float scale = 4.0;
    Texture2D witch_idle{LoadTexture("textures/Blue_witch/B_witch_idle.png")};
    Texture2D witch_run{LoadTexture("textures/Blue_witch/B_witch_run.png")};
    Vector2 witchPos{};
    Vector2 worldPos{};
    Vector2 worldLastFramePos{};

    int frame{};
    int maxFrames{6};

    // animation
    // 1: facing right, -1: facing left
    float rightLeft{1.f};
    float runningTime{};
    float updateTime{1.f/12.f};
    Vector2 velocity{};
    float speed{5.0f};

    int windowWidth{};
    int windowHeight{};

    float width{};
    float height{};

};