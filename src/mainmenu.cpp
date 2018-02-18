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

int menu::displayMenu(SDL_Window* window, SDL_Surface* surface, TTF_Font* font){

    Uint32 time;
    int x,y;
    const int OPTIONS = 3;
    const char* MENU_OPTIONS[OPTIONS] = {"Play","Settings","Exit"};
    SDL_Surface* MENU_ITEMS[OPTIONS];
    bool isSelected[OPTIONS] = {0,0,0};
    SDL_Color color[2] = {{255,0,0},{0,255,0}};

    SDL_Rect position[OPTIONS];
    position[0].x = 200;
    position[0].y = 250;
    position[1].x = 200;
    position[1].y = 300;
    position[2].x = 200;
    position[2].y = 350;

    MENU_ITEMS[0] = TTF_RenderText_Solid(font,MENU_OPTIONS[0],color[0]);
    MENU_ITEMS[1] = TTF_RenderText_Solid(font,MENU_OPTIONS[1],color[1]);
    MENU_ITEMS[2] = TTF_RenderText_Solid(font,MENU_OPTIONS[2],color[2]);

    SDL_FillRect(surface,&surface->clip_rect,SDL_MapRGB(surface->format, 0x00,0x00,0x00));
    SDL_Event e;

    while(1)
    {
        time = SDL_GetTicks();
        while(SDL_PollEvent(&e))
        {
            switch(e.type)
            {
                case SDL_QUIT:
                    for(int i = 0; i< OPTIONS;++i)
                    {
                        SDL_FreeSurface(MENU_ITEMS[i]);
                    }
                return 2;

                case SDL_MOUSEMOTION:
                    x = e.motion.x;
                    y = e.motion.y;
                    for(int i = 0; i < OPTIONS; ++i)
                    {
                        if(x >= position[i].x && x <= position[i].x + position[i].w
                        && y >= position[i].y && y <= position[i].y + position[i].h)
                        {
                            if(!isSelected[i])
                            {
                                isSelected[i] = 1;
                                SDL_FreeSurface(MENU_ITEMS[i]);
                                MENU_ITEMS[i] = TTF_RenderText_Solid(font,MENU_OPTIONS[i], color[1]);
                            }
                        }
                        else
                        {
                            if(isSelected)
                            {
                                isSelected[i] = 0;
                                SDL_FreeSurface(MENU_ITEMS[i]);
                                MENU_ITEMS[i] = TTF_RenderText_Solid(font,MENU_OPTIONS[i], color[0]);
                            }
                        }
                    }
                break;
                case SDL_MOUSEBUTTONDOWN:
                    x = e.button.x;
                    y = e.button.y;
                    for(int i = 0; i < OPTIONS; ++i)
                    {
                        if(x >= position[i].x && x <= position[i].x + position[i].w
                        && y >= position[i].y && y <= position[i].y + position[i].h)
                        {
                            for(int j = 0; j < OPTIONS;++j)
                            {
                                SDL_FreeSurface(MENU_ITEMS[j]);
                            }
                            return i;
                        }
                    break;
                    }
                case SDL_KEYDOWN:
                    if(e.key.keysym.sym==SDLK_ESCAPE)
                    {
                        for(int i = 0; i < OPTIONS;++i)
                            {
                                SDL_FreeSurface(MENU_ITEMS[i]);
                            }
                        return 0;
                    }
            }
        }
        for(int i = 0; i < OPTIONS;++i)
        {
            SDL_BlitSurface(MENU_ITEMS[i], NULL, surface, &position[i]);
        }

        SDL_UpdateWindowSurface(window);
        if(1000/30 > (SDL_GetTicks() - time))
        {
            SDL_Delay(1000/30 - (SDL_GetTicks() - time));
        }
    }

    return 0;

}
