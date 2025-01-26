#pragma once

#include <SDL2/SDL.h>
#include <stdbool.h>

#define ART_WIDTH 8
#define ART_HEIGHT 8

typedef struct
{
    Uint32 art[ART_WIDTH][ART_HEIGHT];
}Entity;

typedef struct
{
    bool jump;
}Movement;

typedef struct
{
    float x;
    float y;
    float velocityX;
    float velocityY;
    bool isJumping;
}Physics;

struct Window;

void init_entity(Physics* physics, float height);

void render_bird(SDL_Renderer* renderer, Entity* entity, int x, int y);

void move_entity(int* x, int* y, int* speedX, int* speedY, int screenWidth, int screenHeight);

void jump_entity(Physics* physics, Movement* movement, float groundLevel, float skyLevel);