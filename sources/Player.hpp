//
// Created by Steve Wheeler on 04/09/2022.
//

#ifndef TOUHOU_RAYLIB_PLAYER_HPP
#define TOUHOU_RAYLIB_PLAYER_HPP
#define PLAYER_SPEED (2);
#include <raylib.h>
#include <vector>
#include <memory>
#include <map>
#include "bullet.hpp"
#include "Animator.hpp"

class Player
{
private:
    std::shared_ptr<Animator> animator;

    Vector2 pos;
    //Texture2D texture;
    void CheckInput();
    void FireBullet();
    std::vector<std::shared_ptr<Bullet>> bullets;
public:
    Player(Vector2 pos);
    ~Player();
    void Draw();
    void Update(float deltaTime);
};

#endif //TOUHOU_RAYLIB_PLAYER_HPP
