#pragma once
#include "raylib-cpp.hpp"
#include <map>

struct SpriteScale
{
    float w;
    float h;
};

class Animator {
private:
    float framesCounter;
    float framesSpeed;
    float currentFrame;
    std::map<char const*, int> animations;
    raylib::Texture spriteSheet;
    char const* animationState;
    //SpriteScale scale;
public:
    Animator(float w, float h, const char* spriteSheetPath, std::map<char const*, int> animations);
    ~Animator();
    void Draw(Vector2 pos);
    void Update(float deltaTime);
    void Update_State(char const* state);
    Rectangle frameRec;

};