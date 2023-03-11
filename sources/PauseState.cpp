#include "PauseState.hpp"
#include <raylib.h>

PauseState::PauseState(const std::shared_ptr<State> &previousState1)
        : previousState(previousState1), shouldPause(false){
}

PauseState::~PauseState()
{

}

void PauseState::Update(float deltaTime)
{

}

void PauseState::Draw()
{
    previousState->Draw();
}

bool PauseState::CheckCondition()
{
    if (IsKeyReleased(KEY_P))
    {
        shouldPause = !shouldPause;
    }
    return shouldPause;
}
