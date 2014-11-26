//
//  main.cpp
//  SDLPlatformer
//
//  Created by Wilson Koder on 26/11/14.
//  Copyright (c) 2014 WilsonKoder. All rights reserved.
//

#include <iostream>
#include "game.h"

Game *g_game = new Game();

int main(int argc, const char * argv[])
{
    g_game->init(800, 600, "sup");
    
    while(g_game->isRunning())
    {
        g_game->handleEvents();
        g_game->update();
        g_game->render();
    }
    g_game->clean();
    SDL_Quit();
    return 0;
}
