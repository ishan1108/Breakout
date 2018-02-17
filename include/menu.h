#ifndef MENU_H
#define MENU_H

#include "SDL2/SDL_ttf.h"
class menu
{
    public:
        menu();
        virtual ~menu();
        int displayMenu(SDL_Surface* window, TTF_Font* font);
    protected:

    private:
};


#endif // MENU_H
