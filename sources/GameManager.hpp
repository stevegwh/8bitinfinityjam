//
// Created by Steve Wheeler on 14/09/2022.
//

#ifndef TOUHOU_RAYLIB_GAMEMANAGER_HPP
#define TOUHOU_RAYLIB_GAMEMANAGER_HPP

#include <memory>
#include "StateManager.hpp"
#include <iostream>
#include "Player.hpp"

class GameManager
{
private:
    std::shared_ptr<StateManager> stateManager;
    std::shared_ptr<Player> player;
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
    void GetPowerup();
    void Draw();
    void Update(float deltaTime);
};

#endif //TOUHOU_RAYLIB_GAMEMANAGER_HPP
