//
// Created by Steve Wheeler on 08/09/2022.
//

#include "PlayState.hpp"
#include <iostream>

PlayState::PlayState(std::shared_ptr<Player> player)
{
    this->player = player;
}

PlayState::~PlayState()
{

}

void PlayState::Update(float deltaTime)
{
    //std::cout << message << std::endl;
    player->Update(1);
}

void PlayState::Draw()
{
    player->Draw();
}

bool PlayState::CheckCondition()
{
    return true;
}
