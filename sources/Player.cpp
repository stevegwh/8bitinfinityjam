#include "Player.hpp"

Player::Player(Vector2 pos)
{
    //texture = LoadTexture(ASSETS_PATH"reimu.png");
    this->pos = pos;

    //raylib::Texture spriteSheet(ASSETS_PATH"reimu-spritesheet.png");
    std::map<char const*, int> animations;
    animations.emplace("still", 0);
    animations.emplace("left", 1);
    animations.emplace("right", 2);
    this->animator = std::make_shared<Animator>((float)64, (float)105, ASSETS_PATH"reimu-spritesheet.png", animations);
}

Player::~Player()
{
    //UnloadTexture(texture);
    // Destroy animator?
}

void Player::Update(float deltaTime)
{
    Vector2 mouse = GetMousePosition();
    pos.x = mouse.x - this->animator->frameRec.width/2;
    pos.y = mouse.y - this->animator->frameRec.height/2;
    this->animator->Update(deltaTime);
}

void Player::Draw()
{
    
    //DrawTexture(texture, pos.x, pos.y, WHITE);

    this->animator->Draw(pos);

    //DrawTextureRec(spriteSheet, frameRec, pos, WHITE);

}