#pragma once
#include "State.hpp"
#include "Player.hpp"
#include <string>

class PlayState : public State {
private:
    std::shared_ptr<Player> player;
public:
    bool enabled;
    PlayState(std::shared_ptr<Player> player);
    ~PlayState();
    void Update(float deltaTime) override;
    void Draw() override;
    bool CheckCondition() override;
};
