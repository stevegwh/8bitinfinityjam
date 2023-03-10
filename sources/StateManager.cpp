//
// Created by Steve Wheeler on 04/09/2022.
//
#include <stdlib.h>
#include "StateManager.hpp"
#include <iostream>

StateManager::StateManager() {}

StateManager::~StateManager() {}

void StateManager::Push(const std::shared_ptr<State> &state)
{
    if (head != nullptr)
    {
        state->next = head;
    }
    head = state;

}

void StateManager::Pop()
{
    if (head == nullptr || head->next == nullptr) return; // NOTE: Always leaves 1 state in stack.
    //State* tmp = stateManager->head; // not sure if this should be &stateManager->head;
    head = head->next;
    //free(tmp);
}

void StateManager::Update(float deltaTime)
{
    if (!head->CheckCondition())
    {
        Pop();
        return;
    }
    head->Update(deltaTime);
    CheckConditions();
}

void StateManager::CheckConditions()
{
    for (const auto& state : states)
    {
        if (state->CheckCondition() && state != this->head)
        {
            Push(state);
        }
    }

}

void StateManager::Draw()
{
    head->Draw();
}

void StateManager::Add(const std::shared_ptr<State> &state)
{
    states.push_back(state);
}



