#include "window.h"
#include "entity.h"
#include "renderer.h"
#include <stdio.h>

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 320

int main(int argc, char *argv[]) 
{
    Window window = {0};   // initializing all members to null

    if(!window_init(&window, "Flappy", SCREEN_WIDTH, SCREEN_HEIGHT))
    {
        printf("Windows not initialized");
        return 1;
    }

    SDL_Renderer* sdlRenderer = SDL_CreateRenderer(window.window, -1, SDL_RENDERER_ACCELERATED);
    Renderer renderer = {sdlRenderer, 10};

    Entity entity = {0};

    int artWidth = 8;
    int artHeight = 8;
    entity.art = (Uint32**)malloc(artHeight * sizeof(Uint32*));
    for (int i = 0; i < artHeight; i++) 
    {
        entity.art[i] = (Uint32*)malloc(artWidth * sizeof(Uint32));
        for (int j = 0; j < artWidth; j++) 
        {
            entity.art[i][j] = 0xFF0000FF; //  blue for testing
        }
    };

    Movement movement = {false};
    Physics physics = 
    {
        .x = SCREEN_WIDTH / 2 - (ART_WIDTH * 10) / 2,
        .y = SCREEN_HEIGHT - (ART_HEIGHT * 10),
        .velocityX = 0,
        .velocityY = 0,
        .isJumping = false,
    };
    float groundLevel = SCREEN_HEIGHT - (ART_HEIGHT * 10);
    float skyLevel = 0.0f;

    init_entity(&physics, (float)SCREEN_HEIGHT);

    while(window.isRunning)
    {
        window_handle_events(&window, &movement);
        window_clear(&window, 0, 0, 0, 255);

        // rendering logics
        // move_entity(&x, &y, &speedX, &speedY, SCREEN_WIDTH, SCREEN_HEIGHT);
        jump_entity(&physics, &movement, groundLevel, skyLevel);
        render_rectangle(&renderer, &entity.art, artWidth, artHeight, physics.x, physics.y);
        // update screen
        window_display(&window);
    }

    window_cleanup(&window);
    return 0;
}
