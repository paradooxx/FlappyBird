#include "entity.h"
#include "window.h"

void render_art(SDL_Renderer* renderer, Entity* entity, int x, int y)
{
    for(int i = 0 ; i < ART_HEIGHT ; i++)
    {
        for(int j = 0 ; j < ART_WIDTH ; j++)
        {
            Uint32 color = entity->art[i][j];
            Uint8 r = (color >> 24) & 0xFF;
            Uint8 g = (color >> 16) & 0xFF;
            Uint8 b = (color >> 8) & 0xFF;

            SDL_SetRenderDrawColor(renderer, r, g, b, SDL_ALPHA_OPAQUE);
            SDL_Rect rectangle = 
            {
                x + j * 2,
                y + i * 2,
                10,
                10
            };
            SDL_RenderFillRect(renderer, &rectangle);
        }
    }
}

void init_entity(Physics* physics, float height)
{
    physics->y = height / 4.0f;
    physics->velocityY = 0.0f;
}

void move_entity(int* x, int* y, int* speedX, int* speedY, int screenWidth, int screenHeight) 
{
    *x += *speedX;
    *y += *speedY;

    // checking for collisions with screen edges and bounce back
    if (*x <= 0 || *x + ART_WIDTH * 10 >= screenWidth) {
        *speedX = -*speedX; // reverse direction on X-axis
    }

    if (*y <= 0 || *y + ART_HEIGHT * 10 >= screenHeight) {
        *speedY = -*speedY; // reverse direction on Y-axis
    }
}

void jump_entity(Physics* physics, Movement* movement, float groundLevel, float skyLevel)
{
    float gravity = 0.1f;
    float jumpStrength = -3.0f;

    // set in the sdl event
    if(movement->jump && physics->velocityY >= 0)
    {
        physics->velocityY = jumpStrength;  
        movement->jump = false;
    }

    // applying gravity
    physics->velocityY += gravity;
    physics->y += physics->velocityY;

    // checking ground collision
    if (physics->y >= groundLevel) 
    {
        physics->y = groundLevel;
        physics->velocityY = 0;
    }

    // checking ground collision
    if (physics->y <= skyLevel) 
    {
        physics->y = skyLevel;
        physics->velocityY = 0;
    }
}