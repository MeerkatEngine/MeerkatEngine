#pragma once
#include "EngineCore.h"
#include "SDL2/SDL.h"

typedef struct {
    char *filename;
    SDL_Surface *surface;
    SDL_Texture *texture;
    SDL_RendererFlip flip;
} GraphicsImageComponent;

void *cd_graphics_image_create();
void cd_graphics_image_destroy(void *cd);

Component *c_graphics_image_create();
