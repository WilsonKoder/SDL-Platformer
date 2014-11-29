//
//  Player.cpp
//  SDLPlatformer
//
//  Created by Wilson Koder on 26/11/14.
//  Copyright (c) 2014 WilsonKoder. All rights reserved.
//

#include "Player.h"

int Player::moveX(bool left)
{
    if(left == true)
    {
        xPosition -= 1;
        return xPosition;
    }
    else
    {
        xPosition += 1;
        return xPosition;
    }
    return 0;
}