#include <iostream>

#include "renderer.h"

Renderer::Renderer()
: renderer_ { nullptr }
{

}

Renderer::~Renderer()
{
    cleanup();
}

void Renderer::cleanup()
{
    if (renderer_) {
        SDL_DestroyRenderer(renderer_);
    }
}

void Renderer::attachToWindow(SDL_Window* window)
{
    renderer_ = SDL_CreateRenderer(
            window, 
            -1, 
            SDL_RENDERER_ACCELERATED |
            SDL_RENDERER_PRESENTVSYNC
            );
    if (!renderer_) {
        std::clog << "ERROR! SDL failed to create renderer: "
            << SDL_GetError() << std::endl;
    }
}

void Renderer::draw(IDrawable& drawable)
{
    drawable.draw(renderer_);
}

void Renderer::clear()
{
    SDL_RenderClear(renderer_);
}

void Renderer::show()
{
    SDL_RenderPresent(renderer_);
}

SDL_Renderer* Renderer::get()
{
    return renderer_;
}

