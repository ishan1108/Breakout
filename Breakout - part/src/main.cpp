#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "Game.h"



int main(int argc, char* args[]){

    Game* game = new Game();

    if(game->Init())
    {
        game->NewGame();
    }

    delete game;
    return 0;
}
