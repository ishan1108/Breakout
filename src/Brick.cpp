#include "Brick.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

Bricks::Bricks(SDL_Renderer* renderer)
{
    brickSurface = IMG_Load("bricks.png");
    brickTexture = SDL_CreateTextureFromSurface(renderer,brickSurface);
    SDL_FreeSurface(brickSurface);
}
