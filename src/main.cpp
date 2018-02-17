#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "menu.h"

const int SCREEN_HEIGHT = 640;
const int SCREEN_WIDTH = 480;

int main(int argc, char* args[]){
    SDL_Window* window = NULL;
    SDL_Surface* surface = NULL;

    if(SDL_Init(SDL_INIT_VIDEO) <0 || TTF_Init() < 0)
    {
	std::cout <<"SDL could not be initialized" << std::endl;
	return 0;
    }
    TTF_Init();
    window = SDL_CreateWindow("Breakout",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SCREEN_WIDTH,
                                          SCREEN_HEIGHT,
                                          SDL_WINDOW_SHOWN);

    surface = SDL_GetWindowSurface(window);

    TTF_Font* font = TTF_OpenFont("../fonts/SIXTY.TTF", 15);
    if(!font){
        std::cout << "TTF_Openfont error : %s\n", TTF_GetError();
        return 0;
    }
    menu mainMenu = menu();

    while(1){
	mainMenu.displayMenu(surface,font);
    }
    SDL_Quit();
    return 0;
}
