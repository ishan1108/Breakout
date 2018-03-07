#include "Score.h"
#include <string>
#include <iostream>

Score::Score()
{
    score = 0;
    level = 0;
}

Score::~Score()
{

}

void Score::updateScore(SDL_Renderer* renderer, TTF_Font* font)
{
    SDL_Surface* scoreSurface[2];
    SDL_Color color = {0,30,255};
    const char* current[2];
    current[0] = "Level :";
    current[1] = "Score :" + ;
    SDL_Texture* scoreTexture[2];
    SDL_Rect position[2];
    position[0].x = 10;
    position[1].x = 300;
    for(int i = 0; i < 2; ++i)
    {
        position[i].y = 5;
        scoreSurface[i] = TTF_RenderText_Solid(font,current[i],color);
        scoreTexture[i] = SDL_CreateTextureFromSurface(renderer,scoreSurface[i]);
    }
    SDL_RenderCopy(renderer,scoreTexture[0],NULL,&position[0]);
    SDL_RenderCopy(renderer,scoreTexture[1],NULL,&position[1]);
}
