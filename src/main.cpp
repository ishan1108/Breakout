#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "menu.h"

const int SCREEN_HEIGHT = 640;
const int SCREEN_WIDTH = 480;

int main(int argc, char* args[]){
    // SDL Window
    SDL_Window* window = NULL;

    // SDL Surface
    SDL_Surface* surface = NULL;

    // Error handling if SDL or TTF is not initialized
    if(SDL_Init(SDL_INIT_VIDEO) <0 || TTF_Init() < 0)
    {
	std::cout <<"SDL could not be initialized" << std::endl;
	return 0;
    }

    // Creating a window of size screen height and width
    window = SDL_CreateWindow("Breakout",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              SCREEN_WIDTH,
                              SCREEN_HEIGHT,
                              SDL_WINDOW_SHOWN);

    // Surface of window
    surface = SDL_GetWindowSurface(window);
    // Loading the font from the file
    TTF_Font* font = TTF_OpenFont("./fonts/SIXTY.TTF", 35);
    if(!font){
        std::cout << "TTF_Openfont error" << TTF_GetError();
        return 0;
    }
    menu mainMenu = menu();
    bool gameRunning = 0;
    int i = mainMenu.displayMenu(window,surface,font);

    if(i == 2)
    {
        std::cout << "Exit";
        SDL_Quit();
    }

    else if(i == 0)
    {
        gameRunning = 1;
    }

    else if(i == 1)
    {
        std::cout << "Hello 1";
        SDL_Quit();
    }

    while(gameRunning)
    {
        std::cout << "Reached in gameRunning";
        int i = mainMenu.displayPauseMenu(window, surface,font);
        break;
    }

    SDL_Quit();
    return 0;
}
