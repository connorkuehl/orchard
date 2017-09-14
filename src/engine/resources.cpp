#include "resources.h"

void Resources::load(ILoadable &loadable)
{
    loadable.load(*this);
}

sf::Texture& Resources::loadTexture(const std::string &filePath)
{
    auto exists = textures_.find(filePath);
    if (exists != textures_.end()) {
        return exists->second;
    }

    sf::Texture tex;
    tex.loadFromFile(filePath);
    auto texture = textures_.insert(std::make_pair(filePath, tex));
    return texture.first->second;
}
