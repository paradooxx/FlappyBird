#pragma once

#include <SDL2/SDL.h>

typedef struct
{
    // for art
    Uint32** obstacleArt;
    int width;
    int height;

    // for movement
    int changey1;
    int changey2;

}Obstacle;

void init_obstacle(Obstacle* obstacle, int width, int height);

void render_obstacle(SDL_Renderer* renderer, Obstacle* obstacle, int x, int y);

void free_obstacle(Obstacle* obstacle);