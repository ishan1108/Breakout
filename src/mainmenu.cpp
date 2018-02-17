#include "menu.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "string"

menu::menu()
{

}

menu::~menu()
{
    //dtor
}

int menu::displayMenu(SDL_Surface* window, TTF_Font* font){

    Uint32 time;
    int x,y;
    const int OPTIONS = 3;
    const char* MENU_OPTIONS[OPTIONS] = {"Play","Settings","Exit"};
    SDL_Surface* MENU_ITEMS[OPTIONS];
    bool isSelected[OPTIONS] = {0,0,0};
    SDL_Color color[2] = {{255,0,0},{0,255,0}};

    SDL_Rect position[OPTIONS];
    position[0].x = 200;
    position[0].y = 100;
    position[1].x = 300;
    position[1].y = 100;
    position[2].x = 400;
    position[2].y = 100;

    MENU_ITEMS[0] = TTF_RenderText_Solid(font,MENU_OPTIONS[0],color[0]);
    SDL_BlitSurface(MENU_ITEMS[0],NULL,window,NULL);
    SDL_FreeSurface(MENU_ITEMS[0]);
    return 0;

}
