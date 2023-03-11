#include "Animator.hpp"

Animator::Animator(float w, float h, const char* spriteSheetPath, std::map<char const*, int> animations)
{
    animationState = 0;
    currentFrame = 0;
    framesCounter = 0;
    framesSpeed = 6;
    this->spriteSheet = LoadTexture(spriteSheetPath);
    //this->spriteSheet = raylib::Texture(spriteSheetPath);
    this->animations = animations;
    frameRec = { 0.0f, 0.0f, w,h };
}

Animator::~Animator()
{
    UnloadTexture(spriteSheet);
}

void Animator::Update(float deltaTime)
{
    framesCounter++;

    if (framesCounter >= (60/framesSpeed))
    {
        framesCounter = 0;
        currentFrame++;

        if (currentFrame > 3) currentFrame = 0;

        frameRec.x = (float)currentFrame*frameRec.width;
        frameRec.y = (float)animations[animationState]*frameRec.height;
    }
}

void Animator::Update_State(char const* state)
{
    animationState = state;
}

void Animator::Draw(Vector2 pos)
{
    //spriteSheet.Draw(frameRec, pos);
    DrawTextureRec(spriteSheet, frameRec, pos, WHITE);
}