#ifndef RENDERER_H_
#define RENDERER_H_

#include "SDL.h"

class Renderer
{
    public:
        Renderer();
       ~Renderer();

       void attachToWindow(SDL_Window& window);
       void clear();
       void show();
    private:
       SDL_Renderer* renderer_;

       void cleanup();
};

#endif // RENDERER_H_

