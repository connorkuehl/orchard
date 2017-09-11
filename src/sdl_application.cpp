#include <iostream>

#include "SDL.h"

#include "sdl_application.h"

SdlApplication::SdlApplication()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::clog << "ERROR! SDL failed to initialize: "
            << SDL_GetError() << std::endl;
    }
}

SdlApplication::~SdlApplication()
{
    SDL_Quit();
}

