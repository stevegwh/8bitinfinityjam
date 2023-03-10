//
// Created by Steve Wheeler on 21/09/2022.
//

#ifndef TOUHOU_RAYLIB_ANIMATOR_HPP
#define TOUHOU_RAYLIB_ANIMATOR_HPP

#include <raylib.h>
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
    Rectangle frameRec;
    Texture2D spriteSheet;
    char const* animationState;
    //SpriteScale scale;
public:
    Animator(float w, float h, Texture2D spriteSheet, std::map<char const*, int> animations);
    ~Animator();
    void Draw(Vector2 pos);
    void Update(float deltaTime);
    void Update_State(char const* state);


};


#endif //TOUHOU_RAYLIB_ANIMATOR_HPP
