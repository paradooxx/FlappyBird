#pragma once

#include <SDL2/SDL.h>

typedef struct
{
    SDL_Renderer* sdlRenderer;
    int cellSize;
}Renderer;

void render_rectangle(Renderer* renderer, Uint32** art, int artWidth, int artHeight, int x, int y);
