#ifndef GAME_H
#define GAME_H
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "Score.h"
#include "menu.h"
#include "Racket.h"

class Game
{
    public:
        Game();
        virtual ~Game();
        int SCREEN_HEIGHT;
        int SCREEN_WIDTH;
        SDL_Window* window;
        SDL_Surface* surface;
        SDL_Renderer* renderer;
        TTF_Font* font;
        Score s;
        Racket* racket;
        menu mainMenu = menu();

        // INITIALIZE Game
        bool Init();

        void NewGame();

    protected:

    private:
};

#endif // GAME_H
