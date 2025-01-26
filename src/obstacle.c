#include "obstacle.h"

void init_obstacle(Physics* physics, float height)
{
    // obstacle->width = width;
    // obstacle->height = height;
    // obstacle->obstacleArt = (Uint32**)malloc(height * sizeof(Uint32*));
    // for(int i = 0 ; i < height ; i++)
    // {
    //     obstacle->obstacleArt[i] = (Uint32**)malloc(width * sizeof(Uint32*));
    // }
    physics->y = height;
    physics->velocityX = 0.0f;
}

void render_obstacle(SDL_Renderer* renderer, Obstacle* obstacle) 
{
    SDL_Rect rect1 = {
        obstacle->x,
        obstacle->y,
        obstacle->width,
        obstacle->height
    };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &rect1);

    
    SDL_Rect rect2 = {
        obstacle->x,
        obstacle->height + obstacle->spacing,
        obstacle->width,
        320 - obstacle->height - obstacle->spacing
    };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &rect2);
}