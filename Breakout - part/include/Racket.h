#ifndef RACKET_H
#define RACKET_H

#include "SDL2/SDL.h"

class Racket
{
    public:
        Racket(SDL_Renderer* renderer);
        virtual ~Racket();
        void renderRacket(SDL_Renderer* renderer);
        SDL_Surface* racketSurface;

    protected:

    private:
        SDL_Texture* racketTexture;
};

#endif // RACKET_H
