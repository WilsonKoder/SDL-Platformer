//
//  game.cpp
//  SDLPlatformer
//
//  Created by Wilson Koder on 26/11/14.
//  Copyright (c) 2014 WilsonKoder. All rights reserved.
//

#include "game.h"
#include "Player.h"
#include <iostream>
#include "textureManager.h"


TextureManager *tm = new TextureManager();
Player *player = new Player();

SDL_Window* g_pWindow;
SDL_Renderer* g_pRenderer;

int playerXPos = 10;

bool runLeft = false;
bool runRight = false;

int currentFrame;

bool Game::init(int width, int height, std::string title)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
        g_pWindow = SDL_CreateWindow("Platformer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
        
        if (g_pWindow != 0)
        {
            std::cout << "successfully created window" << std::endl;
            
            g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
            
            if(g_pRenderer != 0)
            {
                std::cout << "successfully created renderer" << std::endl;
                std::cout << "init success, loading images" << std::endl;
                
                SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
                
                tm->load("/Users/WilsonKoder/C++P/projects/SDLPlatformer/SDLPlatformer/Images/floor.png", "floor", g_pRenderer);
                tm->load("/Users/WilsonKoder/C++P/projects/SDLPlatformer/SDLPlatformer/Images/cloud.png", "cloud", g_pRenderer);
                tm->load("/Users/WilsonKoder/C++P/projects/SDLPlatformer/SDLPlatformer/Images/sky.png", "sky", g_pRenderer);
                tm->load("/Users/WilsonKoder/C++P/projects/SDLPlatformer/SDLPlatformer/Images/Spaceman_sheet.png", "spaceman", g_pRenderer);
                
                cloud1Pos = 10;
                
                running = true;
                
                return true;
            }
            else
            {
                std::cout << "couldn't create renderer" << std::endl;
                return false;
            }
        }
        else
        {
            std::cout << "couldn't create window" << std::endl;
            return false;
        }
    }
    
    return false;
}

void Game::handleEvents()
{
    SDL_Event event;
    
    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
        {
            running = false;
        }
        else if(event.type == SDL_KEYDOWN)
        {
            if(event.key.keysym.sym == SDLK_d)
            {
                runRight = true;
            }
            else if(event.key.keysym.sym == SDLK_a)
            {
                runLeft = true;
            }
        }
        else if(event.type == SDL_KEYUP)
        {
            if(event.key.keysym.sym == SDLK_d)
            {
                runRight = false;
            }
            else if(event.key.keysym.sym == SDLK_a)
            {
                runLeft = false;
            }
        }
    }
}

void Game::update()
{
    ++cloud1Pos;
    if(cloud1Pos > (800 + 384))
    {
        cloud1Pos = 0 - 384;
    }
    
    currentFrame = int((SDL_GetTicks() / 100 % 6));

    if(runLeft)
    {
        playerXPos = player->moveX(true);
    }
    else if(runRight)
    {
        playerXPos = player->moveX(false);
    }
}

void Game::render()
{
    SDL_RenderClear(g_pRenderer);
    tm->draw("sky", 0, 0, 800, 600, g_pRenderer, SDL_FLIP_NONE);
    tm->draw("floor", 0, 536, 800, 64, g_pRenderer, SDL_FLIP_NONE);
    tm->draw("cloud", cloud1Pos, 20, 384, 288, g_pRenderer, SDL_FLIP_NONE);
    tm->draw("cloud", cloud1Pos - 300, 70, 384, 288, g_pRenderer, SDL_FLIP_NONE);
    tm->draw("cloud", cloud1Pos - 350, -25, 384, 288, g_pRenderer, SDL_FLIP_NONE);
    if(!runRight && !runLeft)
    {
        tm->draw("spaceman", playerXPos, 480, 52, 57, g_pRenderer, SDL_FLIP_NONE);
    }
    else if(runRight)
    {
        tm->drawFrame("spaceman", playerXPos, 475, 50, 59, 2, currentFrame, g_pRenderer, SDL_FLIP_NONE);
    }
    else if(runLeft)
    {
        tm->drawFrame("spaceman", playerXPos, 475, 50, 59, 2, currentFrame, g_pRenderer, SDL_FLIP_HORIZONTAL);
    }
    SDL_RenderPresent(g_pRenderer);
}

bool Game::isRunning()
{
    return running;
}

void Game::clean()
{
    std::cout << "clean up time" << std::endl;
    SDL_DestroyWindow(g_pWindow);
    SDL_DestroyRenderer(g_pRenderer);
}
