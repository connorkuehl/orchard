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

void Renderer::attachToWindow(SDL_Window& window)
{
    renderer_ = SDL_CreateRenderer(
            &window, 
            -1, 
            SDL_RENDERER_ACCELERATED |
            SDL_RENDERER_PRESENTVSYNC
            );
}

void Renderer::clear()
{
    SDL_RenderClear(renderer_);
}

void Renderer::show()
{
    SDL_RenderPresent(renderer_);
}

