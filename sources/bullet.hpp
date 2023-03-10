//
// Created by Steve Wheeler on 07/09/2022.
//

#ifndef TOUHOU_RAYLIB_BULLET_HPP
#define TOUHOU_RAYLIB_BULLET_HPP

#include <raylib.h>

class Bullet {
private:
    Vector2 pos;
    Vector2 vel;
    Texture2D spriteSheet;
    int speed;

public:
    Bullet(Vector2 pos, Vector2 vel, int speed);
    ~Bullet();
    void Draw();
    void Update(float deltaTime);
    void CheckCollisions();
};

#endif //TOUHOU_RAYLIB_BULLET_HPP
