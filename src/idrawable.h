#ifndef IDRAWABLE_H_
#define IDRAWABLE_H_

#include "SDL.h"

class IDrawable
{
    public:
        virtual ~IDrawable() {}
        virtual void draw(SDL_Renderer* renderer) const = 0;
};

#endif // IDRAWABLE_H_

