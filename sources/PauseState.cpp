//
// Created by Steve Wheeler on 16/09/2022.
//

#include "PauseState.hpp"
#include <raylib.h>

PauseState::PauseState(const std::shared_ptr<State> &playState1)
        : playState(playState1), shouldPause(false){
}

PauseState::~PauseState()
{

}

void PauseState::Update(float deltaTime)
{

}

void PauseState::Draw()
{
    playState->Draw();
}

bool PauseState::CheckCondition()
{
    if (IsKeyPressed(KEY_P))
    {
        shouldPause = !shouldPause;
    }
    return shouldPause;
}
