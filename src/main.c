#include "window.h"
#include "entity.h"
#include "obstacle.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 320

#define MIN_SPACING_BETN_OBSTACLES 60
#define MAX_SPACING_BETN_OBSTACLES 180
#define MIN_OBSTACLE_HEIGHT 50
#define MAX_OBSTACLE_HEIGHT 140

int get_random_int(int min, int max, int gap)
{
    int range = (max - min) / gap + 1;
    int randomIndex = rand() % range;
    return min + randomIndex * gap;
}

int main(int argc, char *argv[]) 
{
    srand(time(NULL));
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

    Obstacle obstacle[3] = 
    {
        {
            .x = 350,
            .y = 0,    
            .width = 40,
            .height = get_random_int(MIN_OBSTACLE_HEIGHT, MAX_OBSTACLE_HEIGHT, 10),
            .spacing = get_random_int(MIN_SPACING_BETN_OBSTACLES, MAX_SPACING_BETN_OBSTACLES, 10)
        },
        {    
            .x = 550,
            .y = 0,    
            .width = 40,
            .height = get_random_int(MIN_OBSTACLE_HEIGHT, MAX_OBSTACLE_HEIGHT, 10),
            .spacing = get_random_int(MIN_SPACING_BETN_OBSTACLES, MAX_SPACING_BETN_OBSTACLES, 10)
        },
        {
            .x = 700,
            .y = 0,    
            .width = 40,
            .height = get_random_int(MIN_OBSTACLE_HEIGHT, MAX_OBSTACLE_HEIGHT, 10),
            .spacing = get_random_int(MIN_SPACING_BETN_OBSTACLES, MAX_SPACING_BETN_OBSTACLES, 10)
        }
    };

    Movement movement = {false};
    Physics physics = 
    {
        .x = 100,
        .y = 100,
        .velocityX = 0,
        .velocityY = 0,
        .isJumping = false,
    };

    float groundLevel = SCREEN_HEIGHT - (ART_HEIGHT * 3);
    float skyLevel = 0.0f;

    init_entity(&physics, (float)SCREEN_HEIGHT);

    while(window.isRunning)
    {
        window_handle_events(&window, &movement);
        window_clear(&window, 0, 0, 0, 255);
        
        render_bird(window.renderer, &entity, physics.x, physics.y);
        jump_entity(&physics, &movement, groundLevel, skyLevel);

        for(int i = 0 ; i < 3 ; i++)
        {
            render_obstacle(window.renderer, &obstacle[i]);
            move_obstacle(&obstacle[i], 0.5f);
        }

        if(check_collision(&obstacle, &physics, ART_WIDTH * 3, 3 * ART_HEIGHT))
        {
            printf("Collided\n");
            window.isRunning = false; 
        }
        // update screen
        window_display(&window);
    }

    window_cleanup(&window);
    return 0;
}