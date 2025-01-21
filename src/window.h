#pragma once

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct 
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    int width;
    int height;
    bool isRunning;
    const char* title;

}Window;

bool window_init(Window* window, const char* title, int width, int height);  // initializing window

void window_handle_events(Window* window); // handling window events

void window_clear(Window* window, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha); // clear screen with a color

void window_display(Window* window);   // update window and swap buffers

void window_cleanup(Window* window); // cleaning window resources
