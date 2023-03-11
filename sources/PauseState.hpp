#pragma once
#include "State.hpp"

class PauseState : public State {
private:
    bool shouldPause;
    const std::shared_ptr<State> previousState;
public:
    PauseState(const std::shared_ptr<State> &previousState1);
    ~PauseState();
    void Update(float deltaTime) override;
    void Draw() override;
    bool CheckCondition() override;
};
