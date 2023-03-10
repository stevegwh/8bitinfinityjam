//
// Created by Steve Wheeler on 04/09/2022.
//

#ifndef TOUHOU_RAYLIB_STATEMANAGER_HPP
#define TOUHOU_RAYLIB_STATEMANAGER_HPP

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
    void Push(const std::shared_ptr<State> &state);
    void Add(const std::shared_ptr<State> &state);
    void Pop();
};


#endif //TOUHOU_RAYLIB_STATEMANAGER_HPP
