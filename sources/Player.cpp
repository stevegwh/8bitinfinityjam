//
// Created by Steve Wheeler on 04/09/2022.
//

#include "Player.hpp"

Player::Player(Vector2 pos)
{
    //texture = LoadTexture(ASSETS_PATH"reimu.png");
    this->pos = pos;

    auto spriteSheet = LoadTexture(ASSETS_PATH"reimu-spritesheet.png");
    std::map<char const*, int> animations;
    animations.emplace("still", 0);
    animations.emplace("left", 1);
    animations.emplace("right", 2);
    this->animator = std::make_shared<Animator>((float)64, (float)105, spriteSheet, animations);


}

Player::~Player()
{
    //UnloadTexture(texture);
    // Destroy animator?
}

void Player::FireBullet()
{
    std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>((Vector2) { pos.x + 32, pos.y },
                                           (Vector2) { 0, -5 }, 5);

    bullets.push_back(bullet);
}

void Player::CheckInput()
{

    if (IsKeyDown(KEY_RIGHT))
    {
        pos.x += PLAYER_SPEED;
        //animationState = "right";
        animator->Update_State("right");

    }
    else if (IsKeyDown(KEY_LEFT))
    {
        pos.x -= PLAYER_SPEED;
        //animationState = "left";
        animator->Update_State("left");
    }
    else
    {
        //animationState = "still";
        animator->Update_State("still");
    }

    if (IsKeyDown(KEY_UP))
    {
        pos.y -= PLAYER_SPEED;
    } else if (IsKeyDown(KEY_DOWN))
    {
        pos.y += PLAYER_SPEED;
    }

    if (IsKeyDown(KEY_Z))
    {
        FireBullet();
    }
}

void Player::Update(float deltaTime)
{
    CheckInput();
    for (const auto& bullet : bullets)
    {
        bullet->Update(deltaTime);
    }

    this->animator->Update(deltaTime);
}

void Player::Draw()
{

    for (const auto& bullet : bullets)
    {
        bullet->Draw();
    }

    //DrawTexture(texture, pos.x, pos.y, WHITE);

    this->animator->Draw(pos);

    //DrawTextureRec(spriteSheet, frameRec, pos, WHITE);

}