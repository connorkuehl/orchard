#include <iostream>

#include "window.h"

Window::Window(size_t width, size_t height, const std::string& title)
: title_ { title }
, width_ { width }
, height_ { height }
, window_ { nullptr }
{
    window_ = SDL_CreateWindow(
            title_.c_str(),
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            width_, height_,
            SDL_WINDOW_SHOWN
            );
    if (!window_) {
        std::clog << "ERROR! SDL failed to create the game window: "
            << SDL_GetError() << std::endl;
    }
}

Window::~Window()
{
    cleanup();
}

void Window::cleanup()
{
    if (window_) {
        SDL_DestroyWindow(window_);
    }
}

