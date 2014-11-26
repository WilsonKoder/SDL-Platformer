//
//  textureManager.cpp
//  SDLPlatformer
//
//  Created by Wilson Koder on 26/11/14.
//  Copyright (c) 2014 WilsonKoder. All rights reserved.
//

#include "textureManager.h"
#include <SDL2_image/SDL_image.h>

std::map<std::string, SDL_Texture*> mTextureMap;

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* pRenderer)
{
    SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
    
    if(pTempSurface == 0)
    {
        return false;
    }
    
    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);
    
    if(pTexture != 0)
    {
        mTextureMap[id] = pTexture;
        return true;
    }
    
    return false;
}

SDL_Rect TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;
    
    srcRect.x = srcRect.y = 0;
    
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    
    destRect.x = x;
    destRect.y = y;
    
    SDL_RenderCopyEx(pRenderer, mTextureMap[id], &srcRect, &destRect, 0, 0, flip);
    
    return destRect;
}

SDL_Rect TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer,
                                   SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;
    
    srcRect.x = width * currentFrame;
    srcRect.y = height * (currentRow - 1);
    
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    
    destRect.x = x;
    destRect.y = y;
    
    SDL_RenderCopyEx(pRenderer, mTextureMap[id], &srcRect, &destRect, 0, 0, flip);
    
    return destRect;

}