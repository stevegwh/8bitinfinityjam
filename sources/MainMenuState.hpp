#pragma once
#include "State.hpp"
#include "PlayState.hpp"

struct MenuButton;


class MainMenuState  : public State {
private:
    //MenuButton* startButton;
    std::unique_ptr<MenuButton> startButton;
    std::unique_ptr<MenuButton> exitButton;
    std::shared_ptr<PlayState> playState;
public:
    MainMenuState(const std::shared_ptr<PlayState> &playState1);
    ~MainMenuState();
    void Update(float deltaTime) override;
    void Draw() override;
    bool CheckCondition() override;
};


