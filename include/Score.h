#ifndef SCORE_H
#define SCORE_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"

class Score
{
    public:
        Score();
        ~Score();
        int score;
        int level;
        void updateScore(SDL_Window* window, SDL_Surface* surface, TTF_Font* font);

    protected:

    private:
};

#endif // SCORE_H
