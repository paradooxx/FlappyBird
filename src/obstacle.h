#pragma once

#include <SDL2/SDL.h>
#include "entity.h"

#define OBSTACLE_HEIGHT 320
#define OBSTACLE_WIDTH 60

typedef struct {
    float x, y;
    int width, height;
    int spacing;
} Obstacle;

void init_obstacle(Physics* physics, float height);

void render_obstacle(SDL_Renderer* renderer, Obstacle* obstacle);

void move_obstacle(Obstacle* ob, float moveSpeed);

bool check_collision(Obstacle* obstacle, Physics* entityPhysics, int entityWidth, int entityHeight);