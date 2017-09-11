#ifndef WINDOW_H_
#define WINDOW_H_

#include <string>

#include "SDL.h"

class Window
{
    public:
        Window(size_t width, size_t height, 
                const std::string& title);
       ~Window();

       SDL_Window* get() const;
    private:
       std::string title_;
       size_t width_;
       size_t height_;
       SDL_Window* window_;

       void cleanup();
};

#endif // WINDOW_H_

