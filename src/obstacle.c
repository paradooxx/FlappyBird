#include "obstacle.h"
#include "entity.h"

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

void render_obstacle(SDL_Renderer* renderer, Obstacle* obstacle, int x, int y)
{
    for(int i = 0 ; i < obstacle->height ; i++)
    {
        for (int j = 0; j < obstacle->width; j++)
        {
            Uint32 color = obstacle->obstacleArt[i][j];
            Uint8 r = (color >> 24) & 0xFF;
            Uint8 g = (color >> 16) & 0xFF;
            Uint8 b = (color >> 8) & 0xFF;

            SDL_SetRenderDrawColor(renderer, r, g, b, SDL_ALPHA_OPAQUE);
            SDL_Rect rectangle = 
            {
                x + j * 10,
                y + i * 10,
                10,
                10
            };
            SDL_RenderFillRect(renderer, &rectangle);
        }
        
    }
}

void free_obstacle(Obstacle* obstacle)
{
    for(int i = 0 ; i < obstacle->height ; i++)
    {
        free(obstacle->obstacleArt[i]);
    }
    free(obstacle->obstacleArt);
    obstacle->obstacleArt = NULL;
}