//
//  textureManager.h
//  SDLPlatformer
//
//  Created by Wilson Koder on 26/11/14.
//  Copyright (c) 2014 WilsonKoder. All rights reserved.
//

#ifndef __SDLPlatformer__textureManager__
#define __SDLPlatformer__textureManager__

#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>
#include <map>

class TextureManager {
public:
    bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
    
    SDL_Rect draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip);
    SDL_Rect drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer,
                                       SDL_RendererFlip flip);
    std::map<std::string, SDL_Texture*> mTextureMap;
};


#endif /* defined(__SDLPlatformer__textureManager__) */
