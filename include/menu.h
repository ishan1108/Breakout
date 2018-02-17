#ifndef MENU_H
#define MENU_H

#include "SDL_ttf.h"
class menu
{
    public:
        menu();
        virtual ~menu();
        int displayMenu(SDL_Surface* window, TTF_Font* fonts);
    protected:

    private:
};


#endif // MENU_H
