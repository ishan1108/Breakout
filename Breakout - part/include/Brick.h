#ifndef BRICK_H
#define BRICK_H

#include "SDL2/SDL_image.h"

#define BRICKS_ROWS 10
#define BRICKS_COLUMNS 10
#define BRICK_WIDTH 48
#define BRICK_HEIGHT 20

class Brick
{
    public:
        int color;
        int isPresent;
};
class Bricks
{
    public:
        Bricks(SDL_Renderer* renderer);
        ~Bricks();
        SDL_Surface* brickSurface;
        Brick allBricks[BRICKS_COLUMNS][BRICKS_ROWS];

    protected:

    private:
        SDL_Texture* brickTexture;
};


#endif // BRICK_H
