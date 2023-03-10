//
// Created by Steve Wheeler on 08/09/2022.
//

#ifndef TOUHOU_RAYLIB_STATE_HPP
#define TOUHOU_RAYLIB_STATE_HPP
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


#endif //TOUHOU_RAYLIB_STATE_HPP
