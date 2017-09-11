#include "game.h"

Game::Game(const std::string& name, size_t width, size_t height)
: window_{width, height, name}
, isRunning_ { true }
{
    renderer_.attachToWindow(window_.get());
}

void Game::run()
{
    auto last = SDL_GetTicks();
    while (isRunning_) {
        auto now = SDL_GetTicks();
        auto elapsed = now - last;
        last = now;
        interact();
        update(elapsed);
        draw();
    }
}

void Game::interact()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning_ = false;
        }
    }
}

void Game::update(Uint32 elapsed)
{

}

void Game::draw()
{
    renderer_.clear();
    renderer_.show();
}

