#include "sprite.h"

Sprite::Sprite(int width, int height, int x, int y)
: transform_{x, y, width, height}
, texture_{nullptr}
, textureRegion_{0, 0, width, height}
, scale_{1.0f}
{
}

void Sprite::setImage(SDL_Texture* texture, int x, int y)
{
    texture_ = texture;
    textureRegion_.x = x;
    textureRegion_.y = y;
}

void Sprite::draw(SDL_Renderer* renderer) const
{
    SDL_RenderCopy(renderer, texture_, &textureRegion_, &transform_);
}

