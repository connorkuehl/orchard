#include <iostream>

#include "SDL_image.h"

#include "resources.h"

Resources::Resources(SDL_Renderer& renderer)
: renderer_ { &renderer }
{
}

Resources::~Resources()
{
    for (auto t : textures_) {
        SDL_DestroyTexture(t.second);
    }
}

void Resources::load(ILoadable& loadable)
{
    loadable.load(*this);
}

SDL_Texture* Resources::loadTexture(const std::string& filePath)
{
    auto exists = textures_.find(filePath);
    if (exists != textures_.end()) {
        return exists->second;
    }

    auto surface = IMG_Load(filePath.c_str());
    if (!surface) {
        std::clog << "ERROR! Failed to load " << filePath
            << ": " << IMG_GetError() << std::endl;
        return nullptr;
    }

    auto tex = SDL_CreateTextureFromSurface(renderer_, surface);
    if (!tex) {
        std::clog << "ERROR! Failed to create texture: "
            << SDL_GetError() << std::endl;
    }

    textures_.insert(std::make_pair(filePath, tex));

    return tex;
}

