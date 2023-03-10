//
// Created by Steve Wheeler on 16/09/2022.
//

#ifndef TOUHOU_RAYLIB_PAUSESTATE_HPP
#define TOUHOU_RAYLIB_PAUSESTATE_HPP

#include "State.hpp"

class PauseState : public State {
private:
    bool shouldPause;
    const std::shared_ptr<State> playState;
public:
    PauseState(const std::shared_ptr<State> &playState1);
    ~PauseState();
    void Update(float deltaTime) override;
    void Draw() override;
    bool CheckCondition() override;
};

#endif //TOUHOU_RAYLIB_PAUSESTATE_HPP
