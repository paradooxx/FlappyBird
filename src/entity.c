#include "entity.h"

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
                x + j * 10,
                y + i * 10,
                10,
                10
            };
            SDL_RenderFillRect(renderer, &rectangle);
        }
    }
}