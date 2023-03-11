#include "StateManager.hpp"

StateManager::StateManager() {}

StateManager::~StateManager() {}

void StateManager::PushToStack(const std::shared_ptr<State> &state)
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
    head->Update(deltaTime);
    if (!head->CheckCondition())
    {
        Pop();
        return;
    }
    CheckConditions();
}

void StateManager::CheckConditions()
{
    for (const auto& state : states)
    {
        
        if (state->CheckCondition() && state != this->head)
        {
            PushToStack(state);
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



