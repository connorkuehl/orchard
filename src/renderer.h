#ifndef RENDERER_H_
#define RENDERER_H_

#include "SDL.h"

#include "idrawable.h"

class Renderer
{
    public:
        Renderer();
       ~Renderer();

       void attachToWindow(SDL_Window* window);
       void draw(IDrawable& drawable);
       void clear();
       void show();
       SDL_Renderer* get();
    private:
       SDL_Renderer* renderer_;

       void cleanup();
};

#endif // RENDERER_H_

