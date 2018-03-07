#include "Game.h"
#include "menu.h"
#include "Score.h"
#include "Racket.h"
#include <iostream>


Game::Game()
{
    window = NULL;
    renderer = NULL;
    surface = NULL;
    mainMenu = menu();
    font = NULL;
    SCREEN_HEIGHT = 640;
    SCREEN_WIDTH = 480;
}

Game::~Game()
{
    //dtor
}

bool Game::Init()
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    if(SDL_Init(SDL_INIT_VIDEO) <0 || TTF_Init() < 0)
    {
        std::cout <<"SDL could not be initialized" << std::endl;
        return 0;
    }
    window = SDL_CreateWindow("Breakout",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              SCREEN_WIDTH,
                              SCREEN_HEIGHT,
                              SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    // Surface of window
    surface = SDL_GetWindowSurface(window);
    // Loading the font from the file
    font = TTF_OpenFont("./fonts/SIXTY.TTF", 35);

    return true;
}

void Game::NewGame()
{
    bool gameRunning = 0;
    int i = mainMenu.displayMenu(window,surface,font);

    if(i == 0)          gameRunning = 1;

    else if(i == 1)     mainMenu.displaySettingsMenu(window,surface,font);

    else if(i == 2)     SDL_Quit();
    racket = new Racket(renderer);
    s = new Score();

    if(gameRunning)
    {
        Render();
        SDL_Delay(5000);
    }

    SDL_Quit();

}

void Game::Render()
{
    SDL_RenderClear(renderer);

    racket->renderRacket(renderer);
    s->updateScore(renderer,font);

    SDL_RenderPresent(renderer);
}
