//
// Created by Steve Wheeler on 14/09/2022.
//

#include "GameManager.hpp"
#include "PauseState.hpp"
#include "PlayState.hpp"

GameManager::GameManager()
{
    stateManager = std::make_shared<StateManager>();
    player = std::make_shared<Player>((Vector2) { 0, 0 });
    std::shared_ptr<PlayState> playState = std::make_shared<PlayState>(player);
    std::shared_ptr<PauseState> pauseState = std::make_shared<PauseState>(playState);

    //stateManager->Add(playState);

    // Do not add PlayState to states list, as it is the default state.
    stateManager->Add(pauseState);
    stateManager->Push(playState);
}

GameManager::~GameManager() {}


void GameManager::Update(float deltaTime)
{
    stateManager->Update(deltaTime);
}

void GameManager::Draw()
{
    stateManager->head->Draw();
}
