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

void Score::updateScore(SDL_Window* window, SDL_Surface* surface, TTF_Font* font)
{
    SDL_Surface* scoreSurface[2];
    SDL_Color color = {0,30,255};
    const char* current[2];
    current[0] = "Level :";
    current[1] = "Score :";

    SDL_Rect position[2];
    position[0].x = 10;
    position[1].x = 350;
    for(int i = 0; i < 2; ++i)
    {
        position[i].y = 5;
        scoreSurface[i] = TTF_RenderText_Solid(font,current[i],color);
    }
    SDL_BlitSurface(scoreSurface[0],NULL,surface,&position[0]);
    SDL_BlitSurface(scoreSurface[1],NULL,surface,&position[1]);
    SDL_UpdateWindowSurface(window);
}
