#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "menu.h"

const int SCREEN_HEIGHT = 640;
const int SCREEN_WIDTH = 480;

int main(int argc, char* argv[]){

    TTF_Init();
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Breakout",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SCREEN_WIDTH,
                                          SCREEN_HEIGHT,
                                          SDL_WINDOW_SHOWN);

    SDL_Surface* surface = SDL_GetWindowSurface(window);

    TTF_Font* font = TTF_OpenFont("SIXTY.ttf", 15);

    menu mainMenu = menu();
    mainMenu.displayMenu(surface,font);

    return 0;
}
