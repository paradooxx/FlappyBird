#include "window.h"
#include "entity.h"
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

    Entity entity = {
        .art = {
            {0xFFFF0000, 0xFFFF0000, 0xFFFF0000, 0xFFFF0000, 0xFFFF0000, 0xFFFF0000, 0xFFFF0000, 0xFFFF0000}, // Red
            {0xFFFFA500, 0xFFFFA500, 0xFFFFA500, 0xFFFFA500, 0xFFFFA500, 0xFFFFA500, 0xFFFFA500, 0xFFFFA500}, // Orange
            {0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00}, // Yellow
            {0xFF008000, 0xFF008000, 0xFF008000, 0xFF008000, 0xFF008000, 0xFF008000, 0xFF008000, 0xFF008000}, // Green
            {0xFF0000FF, 0xFF0000FF, 0xFF0000FF, 0xFF0000FF, 0xFF0000FF, 0xFF0000FF, 0xFF0000FF, 0xFF0000FF}, // Blue
            {0xFF4B0082, 0xFF4B0082, 0xFF4B0082, 0xFF4B0082, 0xFF4B0082, 0xFF4B0082, 0xFF4B0082, 0xFF4B0082}, // Indigo
            {0xFFEE82EE, 0xFFEE82EE, 0xFFEE82EE, 0xFFEE82EE, 0xFFEE82EE, 0xFFEE82EE, 0xFFEE82EE, 0xFFEE82EE}, // Violet
            {0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000}  // Black
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
        render_art(window.renderer, &entity, physics.x, physics.y);
        // update screen
        window_display(&window);
    }

    window_cleanup(&window);
    return 0;
}
