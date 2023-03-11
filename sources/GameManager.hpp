#pragma once

#include <memory>
#include "StateManager.hpp"
#include "Player.hpp"
#include "MainMenuState.hpp"

class GameManager
{
private:
    std::shared_ptr<StateManager> stateManager;
    std::shared_ptr<Player> player;
    std::shared_ptr<MainMenuState> menuState;
public:
    GameManager();
    //GameManager(GameManager const&) = delete;
    //void operator=(GameManager const&) = delete;
//    static std::shared_ptr<GameManager> GetInstance()
//    {
//        static std::shared_ptr<GameManager> instance;
//        return instance;
//    }
    ~GameManager();
    void Draw();
    void Update(float deltaTime);
};
