#ifndef MENU_H
#define MENU_H

#include "SDL2/SDL_ttf.h"
class menu
{
    public:
        menu();
        virtual ~menu();
        int displayMenu(SDL_Window* window,SDL_Surface* surface, TTF_Font* font);
        int displayPauseMenu(SDL_Window* window, SDL_Surface* surface, TTF_Font* font);
    protected:

    private:
};


#endif // MENU_H
