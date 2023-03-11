#pragma once
#include <memory>


class State {
public:
//    State();
//    ~State();
    virtual bool CheckCondition() = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void Draw() = 0;
    std::shared_ptr<State> next;
};