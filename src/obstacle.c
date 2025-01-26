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

void move_obstacle(Obstacle* ob, float moveSpeed)
{
    ob->x -= moveSpeed;
}

bool check_collision(Obstacle* obstacle, Physics* entityPhysics, int entityWidth, int entityHeight)
{
    int rect2y = obstacle->height + obstacle->spacing;
    int rect2height = 320 - obstacle->height - obstacle->spacing;

    bool x_overlap1 = (entityPhysics->x + entityWidth) >= obstacle->x &&
                (entityPhysics->x + entityWidth) < (obstacle->x + obstacle->width) ;

    bool x_overlap2 = entityPhysics->x  >= obstacle->x &&
                entityPhysics->x < (obstacle->x + obstacle->width);

    bool y_overlap1 =  entityPhysics->y <= (obstacle->y + obstacle->height) &&
                entityPhysics->y > obstacle->y;

    bool y_overlap2 = (entityPhysics->y + entityHeight) >= rect2y &&
                (entityPhysics->y + entityHeight) < (rect2y + rect2height) ;  


    bool collision_case1 = x_overlap1 && y_overlap1;
    bool collision_case2 = x_overlap1 && y_overlap2;
    bool collision_case3 = x_overlap2 && y_overlap1;
    bool collision_case4 = x_overlap2 && y_overlap2;

    return collision_case1 || collision_case2 || collision_case3 || collision_case4;
}

