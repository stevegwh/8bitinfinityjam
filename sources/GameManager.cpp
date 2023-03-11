#include "GameManager.hpp"
#include "PauseState.hpp"
#include "PlayState.hpp"

GameManager::GameManager()
{
    stateManager = std::make_shared<StateManager>();
    player = std::make_shared<Player>((Vector2) { 0, 0 });
    std::shared_ptr<PlayState> playState = std::make_shared<PlayState>(player);
    std::shared_ptr<PauseState> pauseState = std::make_shared<PauseState>(playState);
    std::shared_ptr<MainMenuState> menuState = std::make_shared<MainMenuState>(playState);
    

    stateManager->Add(pauseState);
    stateManager->Add(playState);
    // Don't add Main Menu to the lists of conditions to check
    //stateManager->Add(menuState);
    stateManager->PushToStack(menuState);
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
