#include "window.h"
#include "entity.h"
#include <stdio.h>

int main(int argc, char *argv[]) 
{
    Window window = {0};   // initializing all members to null

    if(!window_init(&window, "Window", 480, 340))
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

    while(window.isRunning)
    {
        window_handle_events(&window);
        window_clear(&window, 0, 0, 0, 255);

        // rendering logics
        render_art(window.renderer, &entity, 200, 120);
        // update screen
        window_display(&window);
    }

    window_cleanup(&window);
    return 0;
}
