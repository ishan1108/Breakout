#include "Racket.h"
#include "SDL2/SDL_image.h"
#include <iostream>
#define RACKET_HEIGHT 32
#define RACKET_WIDTH 128

Racket::Racket(SDL_Renderer* renderer)
{
    racketSurface = IMG_Load("./assets/Racket.png");
    if(!racketSurface)
    {
        std::cout << IMG_GetError();
        SDL_Quit();
    }
    racketTexture = SDL_CreateTextureFromSurface(renderer, racketSurface);
    SDL_FreeSurface(racketSurface);
}

Racket::~Racket()
{
    //dtor
    SDL_DestroyTexture(racketTexture);
}

void Racket::renderRacket(SDL_Renderer* renderer)
{
    SDL_Rect racket;
    racket.x = 50;
    racket.y = 5;
    racket.h = RACKET_HEIGHT;
    racket.w = RACKET_WIDTH;
    SDL_RenderCopy(renderer,racketTexture,0,&racket);
}
