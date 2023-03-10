//
// Created by Steve Wheeler on 07/09/2022.
//

#include "bullet.hpp"

Bullet::Bullet(Vector2 pos, Vector2 vel, int speed)
{
    this->pos = pos;
    this->vel = vel;
    this->speed = speed;
}

Bullet::~Bullet() {}

void Bullet::Update(float deltaTime)
{
    pos.x += vel.x;
    pos.y += vel.y;
}

void Bullet::Draw()
{
    DrawCircle(pos.x, pos.y, 35/2, DARKBLUE);
    DrawCircleGradient(pos.x, pos.y, 60/2, GREEN, SKYBLUE);
    DrawCircleLines(pos.x, pos.y, 80/2, DARKBLUE);
}
