#pragma once

#include <SDL2/SDL.h>

#define ART_WIDTH 8
#define ART_HEIGHT 8

typedef struct
{
    Uint32 art[ART_WIDTH][ART_HEIGHT];
}Entity;

void render_art(SDL_Renderer* renderer, Entity* entity, int x, int y);
