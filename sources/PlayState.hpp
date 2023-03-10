//
// Created by Steve Wheeler on 08/09/2022.
//

#ifndef TOUHOU_RAYLIB_PLAYSTATE_HPP
#define TOUHOU_RAYLIB_PLAYSTATE_HPP


#include "State.hpp"
#include "Player.hpp"
#include <string>

class PlayState : public State {
private:
    std::shared_ptr<Player> player;
public:
    PlayState(std::shared_ptr<Player> player);
    ~PlayState();
    void Update(float deltaTime) override;
    void Draw() override;
    bool CheckCondition() override;
};


#endif //TOUHOU_RAYLIB_PLAYSTATE_HPP
