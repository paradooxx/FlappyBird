#include "renderer.h"

void render_rectangle(Renderer* renderer, Uint32** art, int artWidth, int artHeight, int x, int y)
{
    for(int i = 0 ; i < artHeight ; i++)
    {
        for (int j = 0; j < artWidth; j++)
        {
            Uint32 color = art[i][j];
            Uint8 r = (color >> 24) & 0xFF;
            Uint8 g = (color >> 16) & 0xFF;
            Uint8 b = (color >> 8) & 0xFF;

            SDL_SetRenderDrawColor(renderer->sdlRenderer, r, g, b, SDL_ALPHA_OPAQUE);
            SDL_Rect rectangle = 
            {
                x + j * renderer->cellSize,
                y + i * renderer->cellSize,
                renderer->cellSize,
                renderer->cellSize
            };
            // SDL_RenderFillRect(renderer->sdlRenderer, &rectangle);

            if (SDL_RenderFillRect(renderer->sdlRenderer, &rectangle) < 0) {
                printf("Failed to render rect: %s\n", SDL_GetError());
            }
        }

    }
}