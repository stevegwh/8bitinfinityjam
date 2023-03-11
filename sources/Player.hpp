#pragma once
#define PLAYER_SPEED (2);
#include "raylib-cpp.hpp"
#include <vector>
#include <memory>
#include <map>
#include "Animator.hpp"

class Player
{
private:
    std::shared_ptr<Animator> animator;

    Vector2 pos;
public:
    Player(Vector2 pos);
    ~Player();
    void Draw();
    void Update(float deltaTime);
};