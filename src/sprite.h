#ifndef SPRITE_H_
#define SPRITE_H_

#include "SDL.h"

#include "idrawable.h"

class Sprite : public virtual IDrawable
{
    public:
        Sprite(int width, int height, int x = 0, int y = 0);

        void setImage(SDL_Texture* texture, int x = 0, int y = 0);
        void draw(SDL_Renderer* renderer) const override;
    private:
        SDL_Rect transform_;
        SDL_Texture* texture_;
        SDL_Rect textureRegion_;
        float scale_;
};

#endif // SPRITE_H_

