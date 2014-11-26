//
//  game.h
//  SDLPlatformer
//
//  Created by Wilson Koder on 26/11/14.
//  Copyright (c) 2014 WilsonKoder. All rights reserved.
//

#ifndef __SDLPlatformer__game__
#define __SDLPlatformer__game__

#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>

class Game
{
public:
    
    bool init(int width, int height, std::string title);
    void handleEvents();
    void update();
    void render();
    bool isRunning();
    void clean();
    
    int cloud1Pos;
private:
    bool running;

};

#endif /* defined(__SDLPlatformer__game__) */
