#include "window.h"
#include "entity.h"
#include "obstacle.h"
#include <stdio.h>

bool window_init(Window* win, const char* title, int width, int height)
{
    win->width = width;
    win->height = height;
    win->title = title;
    win->isRunning = true;

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    win->window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );

    if(win->window == NULL)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    // creating renderer
    win->renderer = SDL_CreateRenderer(
        win->window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    // creating renderer
    if(win->renderer == NULL)
    {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(win->window);
        SDL_Quit();
        return false;
    }

    return true;
}

void window_handle_events(Window* win, Movement* movement)
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                win->isRunning = false;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        win->isRunning = false;
                        break;
                    case SDLK_SPACE:  // Jump key
                        if (!movement->jump) 
                        {  // Prevent repeated jumping
                            movement->jump = true;
                        }
                }
                break;
            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                    case SDLK_SPACE:
                        movement->jump = false;
                        break;
                }
                break;
        }
    }
}

void window_clear(Window* window, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha)
{
    SDL_SetRenderDrawColor(window->renderer, red, green, blue, alpha);
    SDL_RenderClear(window->renderer);
}

void window_display(Window* win)
{
    SDL_RenderPresent(win->renderer);
}

void window_cleanup(Window* win)
{
    SDL_DestroyRenderer(win->renderer);
    SDL_DestroyWindow(win->window);
    SDL_Quit();
}