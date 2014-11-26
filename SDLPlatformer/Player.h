//
//  Player.h
//  SDLPlatformer
//
//  Created by Wilson Koder on 26/11/14.
//  Copyright (c) 2014 WilsonKoder. All rights reserved.
//

#ifndef __SDLPlatformer__Player__
#define __SDLPlatformer__Player__

#include <stdio.h>

class Player
{
public:
    int moveX(bool left);
private:
    int xPosition;
};

#endif /* defined(__SDLPlatformer__Player__) */
