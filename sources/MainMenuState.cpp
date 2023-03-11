//
// Created by Steve on 11/03/2023.
//

#include <iostream>
#include "MainMenuState.hpp"
#include "raylib.h"
#include "PlayState.hpp"

struct MenuButton
{
    Vector2 pos;
    int w;
    int h;
    Texture sprite;
    
    void OnClick(const std::shared_ptr<PlayState> &playState)
    {
        playState->enabled = true;
    }

    void OnClick()
    {
        
    }
    

    MenuButton(Vector2 pos, int width, int height, char const* spritePath)
    {
        this->pos = pos;
        w = width;
        h = height;
        sprite = LoadTexture(spritePath);
    }
};

MainMenuState::MainMenuState(const std::shared_ptr<PlayState> &playState1) 
{
    startButton = std::make_unique<MenuButton>((Vector2){ 300, 200 }, 128, 64, 
                                               ASSETS_PATH"startbutton.png");
    exitButton = std::make_unique<MenuButton>((Vector2){ 300, 350 }, 128, 64, 
                                              ASSETS_PATH"exitbutton.png");
    playState = playState1;
}

MainMenuState::~MainMenuState() 
{
    UnloadTexture(startButton->sprite);
    UnloadTexture(exitButton->sprite);
}

void MainMenuState::Update(float deltaTime) 
{
    
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        std::cout << (playState->enabled) << std::endl;
        Vector2 mouse = GetMousePosition();

        if (mouse.x >= startButton->pos.x && mouse.x <= startButton->pos.x + startButton->w &&
            mouse.y >= startButton->pos.y && mouse.y <= startButton->pos.y + startButton->h )
        {
            startButton->OnClick(playState);
        }

        if (mouse.x >= exitButton->pos.x && mouse.x <= exitButton->pos.x + exitButton->w &&
            mouse.y >= exitButton->pos.y && mouse.y <= exitButton->pos.y + exitButton->h )
        {
            //exitButton->OnClick();
        }
    }

}

void MainMenuState::Draw() 
{
    DrawTexture(startButton->sprite, startButton->pos.x, startButton->pos.y, WHITE);
    DrawTexture(exitButton->sprite, exitButton->pos.x, exitButton->pos.y, WHITE);
}

bool MainMenuState::CheckCondition() 
{
    return true;
}
