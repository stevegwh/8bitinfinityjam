#pragma once
#include <memory>
#include <vector>
#include "State.hpp"

class StateManager {
private:
    std::vector<std::shared_ptr<State>> states;
    void CheckConditions();
public:
    std::shared_ptr<State> head;
    StateManager();
    ~StateManager();
    void Update(float deltaTime);
    void Draw();
    void PushToStack(const std::shared_ptr<State> &state);
    void Add(const std::shared_ptr<State> &state);
    void Pop();
};

